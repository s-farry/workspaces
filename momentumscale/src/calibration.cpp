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
    m_isolation(tree, name + "_cpt_0.50"),
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
  double isolation() const { return m_isolation() ; }
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
  LeafValueGetter<Double_t> m_isolation ;
  //LeafValueGetter<Double_t> m_merr ;
  LeafValueGetter<Int_t> m_ID ;
  LeafValueGetter<Short_t> m_polarity ;

} ;



calibration::calibration(string name){
  m_name = name;
  m_a_init       =  0.00  ;
  m_a_step       =  0.00001;
  m_a_lolimit    = -0.001   ;
  m_a_uplimit    =  0.001   ;

  m_b_init      =  1.00  ;
  m_b_step      =  0.001;
  m_b_lolimit   =  0.9   ;
  m_b_uplimit   =  1.1   ;

  m_precision = 0.01;
  m_tolerance = 0.01;

  m_nphibins = 6;
  m_netabins = 2;
  m_philo = -TMath::Pi();
  m_phihi = TMath::Pi();
  m_etalo = 2.0;
  m_etahi = 4.5;

  //m_a1_params = new TH2F("a1_params", "a1_params",
  //			 m_nphibins, m_philo, m_phihi,
  //			 m_netabins, m_etalo, m_etahi);
  //m_a2_params = new TH2F("a2_params", "a2_params",
  //			 m_nphibins, m_philo, m_phihi,
  //			 m_netabins, m_etalo, m_etahi);

  m_a1_params = new TH2F("a1_params", "a1_params",
			 6, -TMath::Pi(), TMath::Pi(),
			 2, 2.0, 4.5);
  m_a2_params = new TH2F("a2_params", "a2_params",
			 6, -TMath::Pi(), TMath::Pi(),
			 2, 2.0, 4.5);
  m_b1 = 1.0;
  m_b2 = 1.0;

  
  m_z0_params["width"] = new TH2F("width", "width",
				  6, -TMath::Pi(), TMath::Pi(),
				  2, 2.0, 4.5);
  m_z0_params["sigma"] = new TH2F("sigma", "sigma",
				  6, -TMath::Pi(), TMath::Pi(),
				  2, 2.0, 4.5);
  m_z0_params["alpha"] = new TH2F("alpha", "alpha",
				  6, -TMath::Pi(), TMath::Pi(),
				  2, 2.0, 4.5);
  m_z0_params["n"]     = new TH2F("n", "n",
				  6, -TMath::Pi(), TMath::Pi(),
				  2, 2.0, 4.5);
  m_z0_params["lambda"] = new TH2F("lambda", "lambda",
				  6, -TMath::Pi(), TMath::Pi(),
				  2, 2.0, 4.5);
  m_z0_params["s"]     = new TH2F("s", "s",
				  6, -TMath::Pi(), TMath::Pi(),
				  2, 2.0, 4.5);
  m_z0_params["mean"]     = new TH2F("mean", "mean",
				  6, -TMath::Pi(), TMath::Pi(),
				  2, 2.0, 4.5);

  m_expectation   = new TH2F("expectation", "expectation",
			     6, -TMath::Pi(), TMath::Pi(),
			     2, 2.0, 4.5);

  double z0_m_pdg = 91.1876;

  for (int i = 0 ; i < m_nphibins; ++i){
    for (int j = 0 ; j < m_netabins; ++j){
      m_expectation->SetBinContent(i+1,j+1, z0_m_pdg);
    }
  }

}

results calibration::fit_z0_mass(int idx1, int idx2, bool refit){
  RooRealVar m( "Z0_M", "Z0 Mass", 60, 120 );

  // Breit Wigner - Z Lineshape
  RooRealVar m0( "m0", "m0", 0 );
  RooRealVar width( "width", "width", 3.5, 0, 5 );
  RooBreitWigner bw( "gauss", "gauss", m, m0, width );

  // Crystal-Ball - Detector response + FSR
  RooRealVar mean( "mean", "mean", 90.3, 70, 110 );
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

  if (refit){
    //fix all parameters except mass
    width.setVal(m_z0_params["width"]->GetBinContent(idx1+1, idx2+1));
    width.setConstant();
    sigma.setVal(m_z0_params["sigma"]->GetBinContent(idx1+1, idx2+1));
    sigma.setConstant();
    alpha.setVal(m_z0_params["alpha"]->GetBinContent(idx1+1, idx2+1));
    alpha.setConstant();
    n.setVal(m_z0_params["n"]->GetBinContent(idx1+1, idx2+1));
    n.setConstant();
    lambda.setVal(m_z0_params["lambda"]->GetBinContent(idx1+1, idx2+1));
    lambda.setConstant();
    s.setVal(m_z0_params["s"]->GetBinContent(idx1+1, idx2+1));
    s.setConstant();
    mean.setVal(m_z0_params["mean"]->GetBinContent(idx1+1, idx2+1));
  }
  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(pdf, expo), RooArgList(s));
  RooDataHist dh("dh", "dh", m, Import(*(m_current_hists.at(idx1).at(idx2))));
  
  sum.fitTo(dh);

  TCanvas c1;
  RooPlot* frame = m.frame();
  dh.plotOn(frame);
  sum.plotOn(frame);
  frame->Draw();
  ostringstream ss;
  ss<<"test_"<<idx1<<"_"<<idx2<<".pdf";
  c1.Print(ss.str().c_str());

  if (!refit){
    //if this is the first fit, set the parameters for use from now on
    m_z0_params["width"]->SetBinContent(idx1+1, idx2+1, width.getVal());
    m_z0_params["width"]->SetBinError(idx1+1, idx2+1, width.getError());
    m_z0_params["sigma"]->SetBinContent(idx1+1, idx2+1, sigma.getVal());
    m_z0_params["sigma"]->SetBinError(idx1+1, idx2+1, sigma.getError());
    m_z0_params["alpha"]->SetBinContent(idx1+1, idx2+1, alpha.getVal());
    m_z0_params["alpha"]->SetBinError(idx1+1, idx2+1, alpha.getError());
    m_z0_params["n"]->SetBinContent(idx1+1, idx2+1, n.getVal());
    m_z0_params["n"]->SetBinError(idx1+1, idx2+1, n.getError());
    m_z0_params["lambda"]->SetBinContent(idx1+1, idx2+1, lambda.getVal());
    m_z0_params["lambda"]->SetBinError(idx1+1, idx2+1, lambda.getError());
    m_z0_params["s"]->SetBinContent(idx1+1, idx2+1, s.getVal());
    m_z0_params["s"]->SetBinError(idx1+1, idx2+1, s.getError());
  }


  results parms;
  // return as pair with value and error of mean
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError());
  parms["sigma"] = std::pair<double, double>(sigma.getVal() , sigma.getError());
  return parms;

}


results calibration::fit_jpsi_mass(TH1F* h ){
  RooRealVar m("J_psi_1S_M", "Jpsi Mass", 2700,3300 );
  //code stolen from 2015 analysis
  
  RooRealVar mean("mean","",3096.0,2700,3300);
  RooRealVar sigma1("sigma1","",6.,5,20);
  RooFormulaVar sigma2("sigma2","25.7+1.0*sigma1",RooArgSet(sigma1));
  RooRealVar n("n","",1.);
  RooFormulaVar a2("a2","2.066+0.0085*sigma2-0.00011*sigma2*sigma2",RooArgSet(sigma2));
  RooFormulaVar a1("a1","2.066+0.0085*sigma1-0.00011*sigma1*sigma1",RooArgSet(sigma1));
  RooCBShape sig2("CB2","",m,mean,sigma2,a2,n);
  RooCBShape sig1("CB1","",m,mean,sigma1,a1,n);

  RooRealVar fr("fr","",0.96);
  RooAddPdf sig("sig","sig", RooArgList(sig1,sig2),RooArgList(fr));

  RooRealVar taub("taub","taub",-0.0001, -1.,1.); 
  RooExponential bkg("bkg","exp",m,taub);

  int Ntot = h->Integral();

  RooRealVar Nsig("Nsig","",Ntot/2.,0.,Ntot);
  RooRealVar Nbkg("Nbkg","",Ntot/2.,0.,Ntot);
  
  RooAddPdf model("model","model", RooArgList(sig,bkg),RooArgList(Nsig,Nbkg));

  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 2500);
  m.setMax("cache", 3500);

  //Signal fraction
  RooRealVar s("s", "signal", 0.65, 0, 1);

  RooDataHist dh("dh", "dh", m, Import(*h));
  model.fitTo(dh);

  results parms;
  // return as pair with value and error of mean
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError());
  parms["sigma"] = std::pair<double, double>(sigma1.getVal() , sigma1.getError());
  return parms;
}

void calibration::minimise(){
  int start_s = clock();

  get_fitted_means();

  ROOT::Minuit2::Minuit2Minimizer fitter;
  ROOT::Math::Functor function(this, &calibration::metric,2*m_nphibins*m_netabins+2);
  
  int totbins = m_nphibins*m_netabins;

  for (int i = 0 ; i < totbins; ++i){
    ostringstream s;
    s<<"a1_"<<i;
    fitter.SetLimitedVariable(i,s.str().c_str(), m_a_init, m_a_step, m_a_lolimit, m_a_uplimit);
  }
  for (int i = 0 ; i < totbins; ++i){
    ostringstream s;
    s<<"a2_"<<i;
    fitter.SetLimitedVariable(i+totbins,s.str().c_str(), m_a_init, m_a_step, m_a_lolimit, m_a_uplimit);
  }

  fitter.SetLimitedVariable(2*totbins,"b1",m_b_init, m_b_step, m_b_lolimit, m_b_uplimit); 
  fitter.SetLimitedVariable(2*totbins+1,"b2",m_b_init, m_b_step, m_b_lolimit, m_b_uplimit); 
  fitter.SetFunction(function);
  fitter.SetPrecision(m_precision);
  fitter.SetTolerance(m_tolerance);
  fitter.Minimize();
  int stop_s = clock();
  cout<<"time taken to minimise: "<<(stop_s - start_s)/double(CLOCKS_PER_SEC)<<" seconds"<<endl;
}


double calibration::metric(const double* params){
  //transfer to parameters to member variables in order to calculate chi2
  for (int i = 0 ; i < m_nphibins ; ++i){
    for (int j = 0 ; j < m_netabins ; ++j){
      m_a1_params->SetBinContent(i+1, j+1, params[i*m_netabins + j ]);
      m_a2_params->SetBinContent(i+1, j+1, params[m_nphibins*m_netabins + i*m_netabins + j ]);
    }
  }
  m_b1 = params[2*m_nphibins*m_netabins];
  m_b2 = params[2*m_nphibins*m_netabins+1];
  return getchi2();
}

double calibration::getchi2(){
  //update all histograms with new parameters
  update_hists();
  //refit histograms to get new mean
  get_fitted_means(true);
  m_z0_init_mean = ((TH2F*)m_z0_params["mean"]->Clone("z0_init_mean"));
  //minimise the chi2 agreement between fitted mean and expectation
  double chi2ndof = m_z0_params["mean"]->Chi2Test(m_expectation, "CHI2/NDF");
  return chi2ndof;
}

void calibration::update_hists(){
  //clear hists
  for(unsigned int i = 0 ; i < m_current_hists.size() ; ++i){
    for (unsigned int j = 0 ; j < m_current_hists.at(i).size() ; ++j){
      m_current_hists.at(i).at(j)->Reset();
    }
  }

  m_tree->SetBranchStatus("*",0);
  DecayTreeParticle MuP(m_tree, "muplus");
  DecayTreeParticle MuM(m_tree, "muminus");
  DecayTreeParticle Z0(m_tree, "Z0");
  for(int iev=0; iev<m_tree->GetEntries(); ++iev) {
    // print a counter
      if(((iev+1)%100000)==0) std::cout << (iev+1)/100000 << std::flush ;
      else if(((iev+1)%10000)==0) std::cout << "|" << std::flush ;
      // read the event
      m_tree->GetEntry(iev) ;
      if( 
	  Z0.M() > 60000 && Z0.M() < 120000  &&
	  //Z0.Merr() < 2000 &&
	  MuP.eta() > 2.0 && MuP.eta() < 4.5
	  && MuM.eta() > 2.0 && MuM.eta() < 4.5
	  ) {
	
	TLorentzVector p4p_corr, p4m_corr;

	if (Z0.polarity() == 1){
	  p4p_corr = MuP.p4corrected(m_a1_params, m_b1) ;
	  p4m_corr = MuM.p4corrected(m_a1_params, m_b2) ;
	}
	else{
	  p4p_corr = MuP.p4corrected(m_a1_params, m_b2) ;
	  p4m_corr = MuM.p4corrected(m_a1_params, m_b1) ;
	}
	TLorentzVector p4sum_corr = p4p_corr + p4m_corr ;

	if (p4p_corr.Eta() < 2 || p4p_corr.Eta() > 4.5) continue;
	
	double phibin = m_a1_params->GetXaxis()->FindBin(p4p_corr.Phi());
	double etabin = m_a1_params->GetYaxis()->FindBin(p4p_corr.Eta());
	double corrmass = p4sum_corr.M() ;
	double corrmassGeV = corrmass/1000 ;
	m_current_hists.at(phibin-1).at(etabin-1)->Fill(corrmassGeV);
      }
  }
}

void calibration::fill_hists(TTree* t){
  m_tree = t;
  m_tree->SetBranchStatus("*",0);
  for (int i = 0 ; i < m_nphibins ; ++i){
    std::vector<TH1F*> etahists;
    std::vector<TH1F*> etahists_current;
    for (int j = 0 ; j < m_netabins ; ++j){
      ostringstream a, b;
      a<<"masshist_"<<i<<"_"<<j;
      b<<"masshist_"<<i<<"_"<<j<<"_current";
      etahists.push_back(new TH1F(a.str().c_str(), "mass hist", 100, 60, 120));
      etahists_current.push_back(new TH1F(b.str().c_str(), "mass hist", 100, 60, 120));
    }
    m_hists.push_back(etahists);
    m_current_hists.push_back(etahists_current);
  }


  DecayTreeParticle MuP(m_tree, "muplus");
  DecayTreeParticle MuM(m_tree, "muminus");
  DecayTreeParticle Z0(m_tree, "Z0");
  for(int iev=0; iev<m_tree->GetEntries(); ++iev) {
    // print a counter
      if(((iev+1)%100000)==0) std::cout << (iev+1)/100000 << std::flush ;
      else if(((iev+1)%10000)==0) std::cout << "|" << std::flush ;
      // read the event
      m_tree->GetEntry(iev) ;
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
	double phibin = m_a1_params->GetXaxis()->FindBin(p4p.Phi());
	double etabin = m_a1_params->GetYaxis()->FindBin(p4p.Eta());
	m_hists.at(phibin-1).at(etabin-1)->Fill(massGeV);
	m_current_hists.at(phibin-1).at(etabin-1)->Fill(massGeV);
      }
  }
}

void calibration::save(const char* output){
  TFile* f = new TFile(output, "RECREATE");

  for (int i = 0 ; i < m_nphibins ; ++i){
    for (int j = 0 ; j < m_netabins ; ++j){
      m_hists.at(i).at(j)->Write();
      m_current_hists.at(i).at(j)->Write();
    }
  }

  m_z0_init_mean->Write(); // mean mass before calibration
  m_z0_params["mean"]->Write(); // mass after calibration
  m_a1_params->Write(); //parameter set a1 (curvature bias)
  m_a2_params->Write(); //parameter set a2 (curvature bias)
  TParameter<double>("b1", m_b1).Write(); //b1 (momentum scale)
  TParameter<double>("b2", m_b2).Write(); //b2 (momentum scale)
  f->Close();
}


void calibration::get_fitted_means(bool refit){
  for (int i = 0 ; i < m_nphibins ; ++i){
    for ( int j = 0 ; j < m_netabins ; ++j){
      results fit = fit_z0_mass(i,j, refit);
      m_z0_params["mean"]->SetBinContent(i+1, j+1, fit["mean"].first);
      m_z0_params["mean"]->SetBinError(i+1, j+1, fit["mean"].second);
    }
  }
}

int main(){
  TFile* f = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/ZMuMu.Refit.2015.root");
  TTree* t = (TTree*)f->Get("ZMuMu/DecayTree");
  calibration a("momentumscale");
  a.fill_hists(t);
  a.minimise();
  a.save("output.root");
}
