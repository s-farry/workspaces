#include <iostream>
#include <sstream>
#include <iomanip>
#include <TTree.h>
#include <TCut.h>
#include <TMath.h>
#include <TObjArray.h>
#include <math.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TF1.h>
#include <TMVA/Tools.h>
#include <TMVA/Reader.h>
#include <TRandom3.h>
#include <TEntryList.h>
#include <TH1.h>
#include <TMinuit.h>
#include <TParameter.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TLeaf.h>
#include <calibration.h>
#include "Minuit2/Minuit2Minimizer.h"
#include "Math/Functor.h"
#include <ctime>


template<class T>
class LeafValueGetter
{
public:
  LeafValueGetter(TTree* tree, const TString& fieldname, bool reportIfMissing = true) 
  {
    m_leaf = tree->GetLeaf(fieldname) ;
    if( !m_leaf) {
      if( reportIfMissing )
	std::cout << "WARNING: cannot find leaf \'" << fieldname << "\'" << std::endl ;
    } else {
      tree->SetBranchStatus(fieldname,true) ;
    }
  } 
  T get() const { 
    T val(0) ;
    if(m_leaf) val = *(static_cast<T*>(m_leaf->GetValuePointer())) ;
    return val ;
  }
  T operator()() const { return get() ; }
  bool exists() const { return m_leaf!=0 ; }
private:
  TLeaf* m_leaf ;
} ;

class DecayTreeParticle
{
public:
  DecayTreeParticle(TTree* tree, const TString& name) 
    : 
    m_px(tree, name + "_PX"),
    m_py(tree, name + "_PY"),
    m_pz(tree, name + "_PZ"),
    m_pt(tree, name + "_PT"),
    m_E(tree, name + "_PE"),
    m_m(tree, name + "_M"),
    m_eta(tree, name + "_ETA"),
    m_PIDK(tree, name + "_PIDK",false),
    m_cloneDist(tree, name + "_TRACK_CloneDist",false),
    //m_isolation(tree, name + "_cpt_0.50"),
    //m_merr(tree, name + "_MMERR"),
    m_ID(tree, name + "_ID"),
    m_polarity(tree, "Polarity"){}
  
  bool exists() { return m_px.exists() ; }
  TLorentzVector p4() const { return TLorentzVector(m_px(),m_py(),m_pz(),m_E()) ; }
  TLorentzVector p4(double mass) const {
    TLorentzVector rc ;
    rc.SetVectM( TVector3( m_px(),m_py(),m_pz() ), mass) ;
    return rc ;
  }
  int charge() const { 
    //m_ID() >0 ? 1 : -1 ; 
    int q=0 ;
    switch(m_ID()) {
    case 13:
    case -321:
    case -221:
      q=-1; break;
    default:
      q=1 ;
    }
    return q;
  }
  double M() const { return m_m() ; }
  //double Merr() const { return m_merr(); }

  TLorentzVector p4corrected(TH2F* a_params, double b_param) const {
    TLorentzVector mom = p4() ;
    double m = mom.M() ;
    double tx = mom.X() / mom.Z() ;
    double ty = mom.Y() / mom.Z() ;
    //double q = charge() ; 
    //think q should be constant as same factors will be used for opposite charge/polarity
    double q = 1.0;
    //double nx = std::sqrt( (1 + tx*tx )/(1 + tx*tx + ty*ty) ) ;
    //double pxz = nx * mom.P() ;
    double p = mom.P();
    double phi = mom.Phi() ;
    double eta = mom.Eta();
    double a = a_params->GetBinContent(a_params->FindBin(phi, eta));
    double b = b_param;
    double newp   = p * b /(1+ (p*a/q)) ;
    mom.SetX( newp * tx / std::sqrt((1 + tx*tx + ty*ty) ) );
    mom.SetY( newp * ty / std::sqrt((1 + tx*tx + ty*ty) ) );
    mom.SetZ( newp * 1 / std::sqrt((1 + tx*tx + ty*ty) ) ) ;
    mom.SetE( std::sqrt(m*m + newp*newp ) ) ;
    return mom ;
  }

  int pid() const { return m_ID() ; }
  // let's make up something
  bool isKaon() const { return std::abs(pid()) == 321  ; }
  bool isPion() const { return std::abs(pid()) == 211  ; }
  double dLL() const { return isKaon() ? m_PIDK() : 0 ; }
  double cloneDist() const { return  m_cloneDist() ; }
  double tx() const { return m_px()/m_pz() ; }
  double ty() const { return m_py()/m_pz() ; }
  double qop() const { return charge()/std::sqrt( std::sqr(m_px()) + std::sqr(m_py()) + std::sqr(m_pz())) ; }
  double pt() const { return  m_pt() ; }
  //double isolation() const { return m_isolation() ; }
  double eta() const { return m_eta() ; }
  int polarity() const { return m_polarity() ; }

  bool isClone( const DecayTreeParticle& rhs ) const {
    double dtx = tx() - rhs.tx() ; 
    double dty = ty() - rhs.ty() ;
    double dqop = qop() - rhs.qop() ; 
    bool veloclone = std::abs(dtx) < 0.0004 && std::abs(dty) < 0.0002 ;
    bool longclone = std::abs(dtx) < 0.005 && std::abs(dty) < 0.005 && std::abs(dqop)<1e-6 ;
    return veloclone || longclone ; 
  }
  
  
private:
  LeafValueGetter<Double_t> m_px ;
  LeafValueGetter<Double_t> m_py ;
  LeafValueGetter<Double_t> m_pz ;
  LeafValueGetter<Double_t> m_pt ;
  LeafValueGetter<Double_t> m_E ;
  LeafValueGetter<Double_t> m_m ;
  LeafValueGetter<Double_t> m_eta ;
  LeafValueGetter<Double_t> m_PIDK ; 
  LeafValueGetter<Double_t> m_cloneDist ;
  //LeafValueGetter<Double_t> m_isolation ;
  //LeafValueGetter<Double_t> m_merr ;
  LeafValueGetter<Int_t> m_ID ;
  LeafValueGetter<Short_t> m_polarity ;

} ;



results fit_z0_mass(TH1F* hist){
  RooRealVar m( "Z0_M", "Z0 Mass", 60, 120 );

  // Breit Wigner - Z Lineshape
  RooRealVar m0( "m0", "m0", 0 );
  RooRealVar width( "width", "width", 3.5, 0, 5 );
  RooBreitWigner bw( "gauss", "gauss", m, m0, width );

  // Crystal-Ball - Detector response + FSR
  RooRealVar mean( "mean", "mean", 90.3, 70.0, 110.0 );
  RooRealVar sigma( "sigma", "sigma", 1.5, 0, 5);
  RooRealVar alpha( "alpha", "alpha", 2.2, 0.01, 5 );
  RooRealVar n( "n", "n", 0.48, 0.01, 80 );
  RooCBShape cb( "cb", "cb", m, mean, sigma, alpha, n );

  //exponential - DY component + background
  RooRealVar lambda("lambda", "slope", -1e-6, -30., 0.);
  RooExponential expo("expo", "exponential PDF", m, lambda);

  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 50.5);
  m.setMax("cache", 129.5);

  //convolve PDFs
  RooFFTConvPdf pdf( "pdf", "pdf", m, cb, bw );

  //Background fraction
  RooRealVar s("s", "signal", 0.8, 0, 1);


  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(pdf, expo), RooArgList(s));
  RooDataHist dh("dh", "dh", m, Import(*hist));
  
  sum.fitTo(dh, PrintEvalErrors(-1));


  TCanvas c1;
  RooPlot* frame = m.frame();
  dh.plotOn(frame);
  sum.plotOn(frame);
  sum.paramOn(frame, RooFit::Layout(0.10, 0.4, 0.9));
  frame->Draw();
  ostringstream ss;
  ss<<hist->GetName()<<"_fitted.pdf";
  c1.Print(ss.str().c_str());

  results parms;
  // return as pair with value and error of mean
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError());
  parms["sigma"] = std::pair<double, double>(sigma.getVal() , sigma.getError());
  return parms;

}

vector<vector<TH1F*>> get_hists(TTree* t, TH2F* outHist){
  t->SetBranchStatus("*",0);
  int nphibins = outHist->GetXaxis()->GetNbins();
  int netabins = outHist->GetYaxis()->GetNbins();

  std::vector< vector<TH1F*> > hists;

  for (int i = 0 ; i < nphibins ; ++i){
    std::vector<TH1F*> etahists;
    for (int j = 0 ; j < netabins ; ++j){
      ostringstream a;
      a<<"mass_"<<i<<"_"<<j;
      etahists.push_back(new TH1F(a.str().c_str(), "mass hist", 100, 60, 120));
    }
    hists.push_back(etahists);
  }


  DecayTreeParticle MuP(t, "muplus");
  DecayTreeParticle MuM(t, "muminus");
  DecayTreeParticle Z0(t, "boson");
  for(int iev=0; iev<t->GetEntries(); ++iev) {
    // print a counter
      if(((iev+1)%100000)==0) std::cout << (iev+1)/100000 << std::flush ;
      else if(((iev+1)%10000)==0) std::cout << "|" << std::flush ;
      // read the event
      t->GetEntry(iev) ;
      if( 
	  Z0.M() > 60000 && Z0.M() < 120000  &&
	  //Z0.Merr() < 2000 &&
	  MuP.eta() > 2.0 && MuP.eta() < 4.5
	  && MuM.eta() > 2.0 && MuM.eta() < 4.5
	  ) {
	
	TLorentzVector p4p = MuP.p4() ;
	TLorentzVector p4m = MuM.p4() ;
	TLorentzVector p4sum = p4p + p4m ;
	double mass = p4sum.M() ;
	double massGeV = mass/1000 ;
	double phibin = outHist->GetXaxis()->FindBin(p4p.Phi());
	double etabin = outHist->GetYaxis()->FindBin(p4p.Eta());
	hists.at(phibin-1).at(etabin-1)->Fill(massGeV);
      }
  }
  return hists;
}

void get_fitted_means(std::vector< std::vector<TH1F*> > hists, TH2F* outHist){
  int nphibins = hists.size();
  int netabins = hists.at(0).size();
  for (int i = 0 ; i < nphibins ; ++i){
    for ( int j = 0 ; j < netabins ; ++j){
      results magup_fit = fit_z0_mass(hists.at(i).at(j));
      outHist->SetBinContent(i+1, j+1, magup_fit["mean"].first);
      outHist->SetBinError(i+1, j+1, magup_fit["mean"].second);
    }
  }
}

int main(){
  RooMsgService::instance().setSilentMode(true);
  RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

  TFile* f = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/ZMuMu.Zg_mumu.MC2015.root");
  TTree* t = (TTree*)f->Get("ZMuMu/DecayTree");
  int nphibins = 12;
  int netabins = 1;
  double philo = -TMath::Pi();
  double phihi = TMath::Pi();
  double etalo = 2.0;
  double etahi = 4.5;

  TH2F* means = new TH2F("means", "means", nphibins, philo, phihi, netabins, etalo, etahi);
  vector<vector<TH1F*> > hists = get_hists(t, means);
  get_fitted_means(hists, means); 

  TFile* g = new TFile("/user2/sfarry/workspaces/momentumscale/tuples/zmumu_mc2015_calibration.root", "RECREATE");
  means->Write("Means");
  g->Close();
  

}
