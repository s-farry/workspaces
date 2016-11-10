#include <TTree.h>
//#include <TChain.h>
#include <TFile.h>
#include <TLeaf.h>
#include <TLorentzVector.h>
//#include <TRegexp.h>
//#include <vector>
//#include <iostream>
//#include <set>
//#include <cmath>
//#include <TProfile.h>
#include <TProfile2D.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TStyle.h>
#include <TLine.h>
#include <TLegend.h>
#include <TText.h>
#include <Math/SMatrix.h>
#include <Math/SVector.h>
//#include <string>
#include <sstream>

using namespace std;

enum { nphibins = 24 } ;

TH1F curvaturecalibh1[2] = {TH1F("curvaturecalibposh1","",nphibins,-TMath::Pi(),TMath::Pi()),
			    TH1F("curvaturecalibnegh1","",nphibins,-TMath::Pi(),TMath::Pi()) } ;

int calibiter=0 ;

typedef ROOT::Math::SVector<double,2*nphibins> Parameters ;
typedef ROOT::Math::SMatrix<double,2*nphibins,2*nphibins,ROOT::Math::MatRepSym<double,2*nphibins> > Covariance ;

typedef ROOT::Math::SVector<double,nphibins> HalfParameters ;
typedef ROOT::Math::SMatrix<double,nphibins,nphibins,ROOT::Math::MatRepSym<double,nphibins> > HalfCovariance ;

namespace std {
  template<class T> T sqr(const T& t) { return t*t ; }
}

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
    m_merr(tree, name + "_MMERR"),
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
  double Merr() const { return m_merr(); }

  TLorentzVector p4corrected() const {
    TLorentzVector mom = p4() ;
    double m = mom.M() ;
    double tx = mom.X() / mom.Z() ;
    double ty = mom.Y() / mom.Z() ;
    double q = charge() ; 
    double nx = std::sqrt( (1 + tx*tx )/(1 + tx*tx + ty*ty) ) ;
    double pxz = nx * mom.P() ;
    double qopxz = q / pxz ;
    //qopxz += (curvbias + (pscale * (ty>0? 1 : -1) ) ) ;
    double phi = mom.Phi() ;
    int index = q>0 ? 0 : 1 ;
    qopxz += curvaturecalibh1[index].GetBinContent( curvaturecalibh1[index].GetXaxis()->FindBin( phi ) ) ;
    double newpxz = q / qopxz ;
    double newp   = newpxz / nx ;
    
    //newp *= (1 + pscale * sin( mom.Phi() ) * q ) ;
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
  LeafValueGetter<Double_t> m_merr ;
  LeafValueGetter<Int_t> m_ID ;
  LeafValueGetter<Short_t> m_polarity ;

} ;

//void createdataset( TTree* tree )
void processevents(TTree* tree, int niter=5,
		   bool splitcharge = true,
		   bool simplemethod=false,
		   //string output,
		   //double masswindow=8000.,
		   int pol = 1.0,
		   bool is2012 = false,
		   bool isMC = false,
		   TH1F* mczmassvsetapos = NULL,
		   TH1F* mczmassvsetaneg = NULL,
		   TProfile2D* etaposneg = NULL)
{
  std::cout << "HERE Processing events, isMC " << isMC << " is2012 " << is2012 << std::endl;

  bool isZ0 = true;

  if (tree->GetBranch("J_psi_1S_M")) isZ0 = false;

  const double Z0mass  = isZ0 ? 90700.0 : 3096.916;//90987.0 ; 
  //const double Z0mass  = 91187.6 ; // nominal z0 mass
  const double Z0width = isZ0 ? 2595.2 : 1.0  ; // nominal Z0 width
  //const double sigmaM = 3000. ; // combination of width and measurement error
  //const double sigmaM2 = sigmaM*sigmaM ;
  const double masswindow = isZ0 ? 8000. : 1000 ; // window around nominal z mass used for calibration
  cout<<"mass window will be "<<masswindow<<endl;
  const double mmin = (Z0mass - masswindow)/1000 ;
  const double mmax = (Z0mass + masswindow)/1000 ;

  gStyle->SetOptStat(0) ;
  gStyle->SetOptFit(1) ;
  gStyle->SetMarkerStyle(20) ;
  gStyle->SetMarkerSize(0.5) ;

  //  TFile* fout = new TFile("Bd2JpsiKSLL_MCbig_dataset.root","RECREATE") ;
  tree->SetBranchStatus("*",0) ;

  string head = isZ0 ? "Z0" : "J_psi_1S";

  DecayTreeParticle MuP( tree, "muplus" ) ;
  DecayTreeParticle MuM( tree, "muminus" ) ;
  DecayTreeParticle Z0( tree, head ) ;
  
  int nevents = tree->GetEntries() ;
  //nevents = 500;
  std::cout << "Number of events to process: " << nevents << std::endl ;
  
  TProfile* pra = new TProfile("massvsmomdif","",20,-500,500,80,100) ;
  TProfile* prb = new TProfile("massvsmomdifcorr","after",20,-500,500,80,100) ;
  TH1F* mh1a = new TH1F("mh1a","",100,70,110) ;
  TH1F* mh1b = new TH1F("mh1b","",100,70,110) ;


  const double pi = TMath::Pi() ;
  TProfile* phipospra = new TProfile("massvsphipospr","",nphibins,-pi,pi,mmin,mmax) ;
  TProfile* phiposprb = new TProfile("massvsphiposcorrpr","after",nphibins,-pi,pi,mmin,mmax) ;
  TProfile* phinegpra = new TProfile("massvsphinegpr","",nphibins,-pi,pi,mmin,mmax) ;
  TProfile* phinegprb = new TProfile("massvsphinegcorrpr","after",nphibins,-pi,pi,mmin,mmax) ;

  TProfile* etapospra = new TProfile("etapospra","",20,2,4.5,mmin,mmax) ;
  TProfile* etaposprb = new TProfile("etaposprb","after",20,2,4.5,mmin,mmax) ;
  TProfile* etanegpra = new TProfile("etanegpra","",20,2,4.5,mmin,mmax) ;
  TProfile* etanegprb = new TProfile("etanegprb","after",20,2,4.5,mmin,mmax) ;
  
  TProfile2D* etaposnegpra = new TProfile2D("etaposnegpra","",20,2.0,4.5,20,2.0,4.5,mmin,mmax);
  TProfile2D* etaposnegprb = new TProfile2D("etaposnegprb","",20,2.0,4.5,20,2.0,4.5,mmin,mmax);


  TProfile* momvsphipospr =  new TProfile("momvsphipospr","",nphibins,-pi,pi) ;
  TProfile* momvsphinegpr =  new TProfile("momvsphinegpr","",nphibins,-pi,pi) ;

  TProfile* momsumpra = new TProfile("momsumpra","",20,400,2000,mmin,mmax) ;
  TProfile* momsumprb = new TProfile("momsumprb","",20,400,2000,mmin,mmax) ;

  TProfile* massvscosthetastarpra = new TProfile("massvscosthetastarpra","",nphibins,-1,1,mmin,mmax) ;
  TProfile* massvscosthetastarprb = new TProfile("massvscosthetastarprb","",nphibins,-1,1,mmin,mmax) ;
  massvscosthetastarpra->GetXaxis()->SetTitle("cos(theta*)") ;
  massvscosthetastarpra->GetYaxis()->SetTitle("average mass [GeV]") ;
  massvscosthetastarpra->SetMinimum(89) ;
  massvscosthetastarpra->SetMaximum(93) ;
  
  TH1* phiposh1 = new TH1F("phiposh1","",nphibins,-pi,pi) ;
  TH1* phinegh1 = new TH1F("phinegh1","",nphibins,-pi,pi) ;

  TH1* mmerrh1 = new TH1F("mmerr","",100,0,3000) ;

  // let's for now use SMatrix. TMatrix is better (since you can vary
  // the number of bins), but I never quite manage to do the
  // symmetrizing correctly.

  Covariance test;
  test(0,0) = 1.0;

  for(int iter=0 ; iter<niter; ++iter) {
    //typedef ROOT::Math::SVector<double,2*nphibins> Parameters ;
    //typedef ROOT::Math::SMatrix<double,2*nphibins,2*nphibins,ROOT::Math::MatRepSym<double,2*nphibins> > Covariance ;

    Parameters halfdchi2dpar ;
    Covariance halfd2chi2dpar2 ;
    phiposprb->Reset() ;
    phinegprb->Reset() ;
    momvsphipospr->Reset() ;
    momvsphinegpr->Reset() ;

    std::cout << "HERE 4, nevents = " << nevents << std::endl;

    for(int iev=0; iev<nevents; ++iev) {
      // print a counter
      if(((iev+1)%100000)==0) std::cout << (iev+1)/100000 << std::flush ;
      else if(((iev+1)%10000)==0) std::cout << "|" << std::flush ;
      // read the event
      tree->GetEntry(iev) ;
      bool passPol = (Z0.polarity() == pol);
      if (isMC) passPol = true;
      //std::cout << "HERE , polarity = "<< pol << " Z0.polarity " << Z0.polarity() << " MuP.polarity "<< MuP.polarity() <<std::endl;
      //EventInfo eventinfo(runnr(),eventnr(),iev) ;
      if( //MuP.isolation()>0.9 && MuM.isolation()>0.9 &&
	  Z0.M() > 60000 && Z0.M() < 120000  &&
	  Z0.Merr() < 2000
	  && passPol
	  && MuP.eta() > 2.0 && MuP.eta() < 4.5
	  && MuM.eta() > 2.0 && MuM.eta() < 4.5
	  ) {
	
	TLorentzVector p4p = MuP.p4() ;
	TLorentzVector p4m = MuM.p4() ;
	TLorentzVector p4p_corr = MuP.p4corrected() ;
	TLorentzVector p4m_corr = MuM.p4corrected() ;
	TLorentzVector p4sum = p4p + p4m ;
	TLorentzVector p4sum_corr = p4p_corr + p4m_corr ;
	double mass = p4sum.M() ;
	double massGeV = mass/1000 ;
	double corrmass = p4sum_corr.M() ;
	double corrmassGeV = corrmass/1000 ;

	// std::cout << "Mass: "
	// 	      << Z0.M() << " " << (p4p+p4m).M() << std::endl ;
	double Z0mass_alt = Z0mass;
	
	if (mczmassvsetapos && mczmassvsetaneg){
	  double avgzmasspos = mczmassvsetapos->GetBinContent( mczmassvsetapos->GetXaxis()->FindBin( p4p.Eta() ) ) ;
	  double avgzmassneg = mczmassvsetaneg->GetBinContent( mczmassvsetaneg->GetXaxis()->FindBin( p4m.Eta() ) ) ; 
	  Z0mass_alt = 1000.0 * ( (avgzmasspos + avgzmassneg) /2.0) ; // take average, also put it into MeV
	}

	if (mczmassvsetapos && mczmassvsetaneg && etaposneg){
	  double avgzmass = etaposneg->GetBinContent( etaposneg->GetXaxis()->FindBin( p4p.Eta() ), etaposneg->GetYaxis()->FindBin( p4m.Eta() ));
	  //if (fabs(avgzmass - 91.0) > 2.0 ) cout << "average z mass " << avgzmass << " eta+ " << p4p.Eta() << " eta- " << p4m.Eta() << " Z0 mass alt " << Z0mass_alt << endl;
	  if (fabs(avgzmass - 91.0) > 2.0 ) avgzmass = Z0mass_alt / 1000.0;
	  //if (avgzmass < 1.0) cout << "before " << Z0mass_alt << " after " << 1000.0 * avgzmass << " == 0 " << (avgzmass == 0.0) << endl;
	  Z0mass_alt = (avgzmass == 0.0)? Z0mass_alt : 1000.0 * avgzmass;
	  
	  // global shifts... shift data only - doesn't work
	  //double shift = 0.0;
	  //if (!isMC){
	  //  shift = (is2012)? -750.0 : -1160.0; 
	  //cout << "not isMC shift " << shift << ", " << Z0mass_alt << endl;
	  //}
	  //Z0mass_alt += shift;
	}

	//cout << "pos eta " << p4p.Eta() << " from bin " << mczmassvsetapos->GetXaxis()->FindBin( p4p.Eta() ) << " with average mass " << avgzmasspos << endl;
	//cout << "neg eta " << p4m.Eta() << " from bin " << mczmassvsetaneg->GetXaxis()->FindBin( p4m.Eta() ) << " with average mass " << avgzmassneg << endl;
	
	//cout << "using Zmass " << Z0mass_alt << " original was " << Z0mass << endl;

	double momdiff = p4p.P() - p4m.P() ;
	double momsum = (p4p + p4m).P() ;
	//pra->Fill(momdiff/1000, Z0.M()/1000) ;
	if(iter==niter-1) {
	  pra->Fill(momdiff/1000, (p4p+p4m).M()/1000) ;
	  prb->Fill(momdiff/1000, (p4p_corr+p4m_corr).M()/1000) ;
	  mh1a->Fill( (p4p+p4m).M()/1000) ;
	  mh1b->Fill( (p4p_corr+p4m_corr).M()/1000) ;
	}

	const double phipos = p4p.Phi() ;
	const double phineg = p4m.Phi() ;

	// compute phi*: angle of positive muon with z axis in Z0 rest frame
	TLorentzVector p4pprime_corr = p4p_corr ;
	p4pprime_corr.Boost( - p4sum_corr.BoostVector() ) ;
	double costhetastar = p4pprime_corr.Pz() / p4pprime_corr.P() ;
	//std::cout << "energy before/after boost: " << p4p_corr.E() << " " << p4pprime_corr.E() << std::endl ;

	double massresidual = (p4p_corr+p4m_corr).M() - Z0mass_alt ;
	if ( fabs(massresidual) < masswindow ) {

	  // these are needed for the calibration with the 'simple' method
	  phiposprb->Fill(phipos, (p4p_corr+p4m_corr).M()/1000) ;
	  phinegprb->Fill(phineg, (p4p_corr+p4m_corr).M()/1000) ;
	  momvsphipospr->Fill(phipos,p4p_corr.P()) ;
	  momvsphinegpr->Fill(phineg,p4m_corr.P()) ;
	  
	  if(iter==niter-1) {
	    mmerrh1->Fill( Z0.Merr() ) ;
	    phipospra->Fill(phipos,(p4p+p4m).M()/1000) ; 
	    phinegpra->Fill(phineg,(p4p+p4m).M()/1000) ;
	    
	    cout<<"filling with: "<<phipos<<" "<<phipos<<" "<<(p4p_corr + p4m_corr).M()<<endl;

	    phiposh1->Fill(phipos) ;
	    phinegh1->Fill(phineg) ;
	    
	    momsumpra->Fill(momsum/1000, (p4p+p4m).M()/1000) ;
	    momsumprb->Fill(momsum/1000, (p4p_corr+p4m_corr).M()/1000) ;
	    etapospra->Fill(p4p.Eta(), (p4p+p4m).M()/1000) ;
	    etaposprb->Fill(p4p.Eta(), (p4p_corr+p4m_corr).M()/1000) ;
	    etanegpra->Fill(p4m.Eta(), (p4p+p4m).M()/1000) ;
	    etanegprb->Fill(p4m.Eta(), (p4p_corr+p4m_corr).M()/1000) ;

	    etaposnegpra->Fill(p4p.Eta(), p4m.Eta(), (p4p+p4m).M()/1000);
	    etaposnegprb->Fill(p4p_corr.Eta(), p4m_corr.Eta(), (p4p_corr+p4m_corr).M()/1000);

	    massvscosthetastarpra->Fill( costhetastar, massGeV) ;
	    massvscosthetastarprb->Fill( costhetastar, corrmassGeV) ;
	  }
	  // the result does not depend on the choice of the resolution
	  // in the chi2. however, introducing it in the formulas makes
	  // it easier to understand dimensions and gives the chi2
	  // change a reasonably value.
	  int binpos = curvaturecalibh1[0].GetXaxis()->FindBin( phipos ) -1 ;
	  int binneg = curvaturecalibh1[0].GetXaxis()->FindBin( phineg ) -1 + nphibins ;
	  double ppos = p4p_corr.P() ;
	  double pneg = p4m_corr.P() ;
	  //chi2 += massresidual*massresidual/sigmaM2 ;
	  //halfdchi2dpar(binpos) += -0.5 * massresidual * ppos * Z0mass/sigmaM2 ;
	  //halfdchi2dpar(binneg) += +0.5 * massresidual * pneg * Z0mass/sigmaM2 ;
	  //halfd2chi2dpar2(binpos,binpos) +=  0.25 * Z0mass*Z0mass/sigmaM2 * ppos * ppos ;
	  //halfd2chi2dpar2(binneg,binneg) +=  0.25 * Z0mass*Z0mass/sigmaM2 * pneg * pneg ;
	  //halfd2chi2dpar2(binneg,binpos) += -0.5  * Z0mass*Z0mass/sigmaM2 * ppos * pneg ;
	  // this leads to a bit better scale
	  double sigmaM2 = std::sqr(Z0.Merr()) + std::sqr(Z0width) ; 
	  halfdchi2dpar(binpos) += -0.5 * massresidual * ppos / Z0mass_alt / sigmaM2 ;
	  halfdchi2dpar(binneg) += +0.5 * massresidual * pneg / Z0mass_alt / sigmaM2 ;
	  halfd2chi2dpar2(binpos,binpos) +=  0.25 * ppos * ppos / sigmaM2 ;
	  halfd2chi2dpar2(binneg,binneg) +=  0.25 * pneg * pneg / sigmaM2 ;
	  // it's a symmetric matrix so the other element (binpos,binneg) goes automatically
	  halfd2chi2dpar2(binneg,binpos) += -0.25 * ppos * pneg / sigmaM2;
	}
      }
    }
    std::cout << std::endl ;
    std::cout << " simple method " << simplemethod << std::endl ;
    
    if( ! simplemethod ) {
      Covariance cov ; 
      Parameters delta ;
      if( splitcharge ) {
	cov = halfd2chi2dpar2 ;
	int OK = cov.InvertChol() ;
	if(!OK) std::cout << "Inversion error!" << std::endl ;
	delta = - cov * halfdchi2dpar ;
      } else {
	// a bit of a strange short cut, but easiest to implement

	HalfCovariance covhalf = halfd2chi2dpar2.Sub<HalfCovariance>(0,0) + halfd2chi2dpar2.Sub<HalfCovariance>(nphibins,nphibins) ;
	int OK = covhalf.InvertChol() ;
	if(!OK) std::cout << "Inversion error!" << std::endl ;
	HalfParameters halfdchi2dparhalf = halfdchi2dpar.Sub<HalfParameters>(0) + halfdchi2dpar.Sub<HalfParameters>(nphibins) ;
	HalfParameters deltahalf = - covhalf * halfdchi2dparhalf ;
	for(int ibin=0;ibin<nphibins; ++ibin) {
	  delta(ibin) = delta(ibin+nphibins) = deltahalf(ibin) ;
	  // fill only the diagonal
	  cov(ibin,ibin) = cov(ibin+nphibins,ibin+nphibins) = covhalf(ibin,ibin) ;
	}
      }
      for(int ibin=0;ibin<nphibins; ++ibin) {
	double curpos = curvaturecalibh1[0].GetBinContent(ibin+1) ;
	curvaturecalibh1[0].SetBinContent(ibin+1, curpos + delta(ibin) ) ;
	double curneg = curvaturecalibh1[1].GetBinContent(ibin+1) ;
	curvaturecalibh1[1].SetBinContent(ibin+1, curneg + delta(ibin+nphibins) ) ;
	// let's compute errors as well. this is where we need to reintroduce proper scale
	double poserr = std::sqrt( cov(ibin,ibin) ) / Z0mass ;
	curvaturecalibh1[0].SetBinError(ibin+1, poserr ) ;
	double negerr = std::sqrt( cov(ibin+nphibins,ibin+nphibins) ) / Z0mass ;
	curvaturecalibh1[1].SetBinError(ibin+1, negerr ) ;
      } 
    
      // need to reintroduce a scale here that we removed above:
      // shit: is there no dot product in SMatrix?
      //double deltachi2 = (delta * halfdchi2dpar) * Z0mass*Z0mass/sigmaM2 ;
      double deltachi2(0) ;
      for(int ibin=0;ibin<2*nphibins; ++ibin) 
	deltachi2 += delta(ibin)*halfdchi2dpar(ibin) * Z0mass*Z0mass ;
      std::cout << "iter, deltachi2: " << iter << "," << deltachi2 << std::endl ;
    } else {
      for(int ibin=0;ibin<nphibins; ++ibin) {
	// positive
	{
	  double cur = curvaturecalibh1[0].GetBinContent(ibin+1) ;
	  double avmass = phiposprb->GetBinContent(ibin+1) * 1000 ;
          double avmom  = momvsphipospr->GetBinContent(ibin+1) ;
          double delta  = +2* (avmass/Z0mass - 1) / avmom ;
	  curvaturecalibh1[0].SetBinContent(ibin+1, cur + delta ) ;
	}
	// negative
	{
	  double cur = curvaturecalibh1[1].GetBinContent(ibin+1) ;
	  double avmass = phinegprb->GetBinContent(ibin+1) * 1000 ;
          double avmom  = momvsphinegpr->GetBinContent(ibin+1) ;
          double delta  = -2* (avmass/Z0mass - 1) / avmom ;
	  curvaturecalibh1[1].SetBinContent(ibin+1, cur + delta ) ;
	}
      }
    }

    if(!splitcharge) {
      for(int i=1; i<=nphibins; ++i) {
	double av = 0.5*(curvaturecalibh1[0].GetBinContent(i) + curvaturecalibh1[1].GetBinContent(i)) ;
	curvaturecalibh1[0].SetBinContent(i,av) ;
	curvaturecalibh1[1].SetBinContent(i,av) ;
      }
    }
    ++calibiter ;
  }

  int splitcharge_int = (splitcharge)? 1 : 0;
  int simplemethod_int = (simplemethod)? 1 : 0;
  string pol_str = (pol > 0)? "up" : "do";
  if (is2012) pol_str += "_2012";
  std::stringstream outname;
  std::string prefix = (isMC)? "Curvature_MC_" : "Curvature_";
  outname << prefix << niter << "_" << splitcharge_int << "_" << simplemethod_int << "_" << masswindow << "_" << pol_str << ".root"; 
  std::string outputFileName = outname.str();

  TFile *fout = new TFile(outputFileName.c_str(),"RECREATE");

  TCanvas* fig1 = new TCanvas("fig1","fig1",700,350) ;
  fig1->Divide(2,1) ;
  fig1->cd(1) ;
  phipospra->GetXaxis()->SetTitle("phi") ;
  phipospra->GetYaxis()->SetTitle("average dimuon mass") ;
  phinegpra->GetXaxis()->SetTitle("phi") ;
  phinegpra->GetYaxis()->SetTitle("average dimuon mass") ;
  phipospra->SetMaximum(93) ;
  phipospra->SetMinimum(89) ;
  TH1* h1 = phipospra->DrawCopy() ;
  TH1* h1b = phinegpra->DrawCopy("same") ;
  h1b->SetLineColor(2) ;
  h1b->SetMarkerColor(2) ;

  fout->cd();
  phipospra->Write();
  phinegpra->Write();

  fig1->cd(2) ;
  etapospra->GetXaxis()->SetTitle("eta") ;
  etapospra->GetYaxis()->SetTitle("average dimuon mass") ;
  etanegpra->GetXaxis()->SetTitle("eta") ;
  etanegpra->GetYaxis()->SetTitle("average dimuon mass") ;
  etapospra->SetMaximum(93) ;
  etapospra->SetMinimum(89) ;
  h1 = etapospra->DrawCopy() ;
  h1b = etanegpra->DrawCopy("same") ;
  h1b->SetLineColor(2) ;
  h1b->SetMarkerColor(2) ;

  fout->cd();
  etapospra->Write();
  etanegpra->Write();

  etaposnegpra->Write();
  etaposnegprb->Write();


  fig1->Print("fig1.eps") ;

  TCanvas* fig2 = new TCanvas("fig2","",700,350) ;
  fig2->Divide(2,1) ;
 
  fig2->cd(1) ;
  pra->SetMinimum(90) ;
  pra->SetMaximum(92) ;
  pra->Fit("pol1") ;
  prb->SetLineColor(9) ;
  prb->SetMarkerColor(9) ;
  prb->Fit("pol1") ;
  pra->GetFunction("pol1")->SetLineStyle(2) ;
  prb->GetFunction("pol1")->SetLineStyle(2) ;
  prb->GetFunction("pol1")->SetLineColor(9) ;
  pra->Draw() ;
  prb->Draw("same") ;
  pra->GetXaxis()->SetTitle("p(muplus) - p(muminus)") ;
  pra->GetYaxis()->SetTitle("average dimuon mass") ;

  fout->cd();
  pra->Write();
  prb->Write();


  fig2->cd(2) ;
  momsumpra->Draw() ;
  momsumpra->SetMinimum(90) ;
  momsumpra->SetMaximum(92) ;
  momsumprb->Draw("same") ;
  momsumprb->SetLineColor(9) ;
  momsumprb->SetMarkerColor(9) ;
  momsumpra->GetXaxis()->SetTitle("dimuon momentum") ;
  momsumpra->GetYaxis()->SetTitle("average dimuon mass") ;

  fout->cd();
  momsumpra->Write();
  momsumprb->Write();


  fig2->Print("fig2.eps") ;


  TCanvas* fig3 =new TCanvas("fig3","",700,500) ;
  fig3->Divide(2,2) ;
  fig3->cd(1) ;
  phipospra->Draw() ;
  phipospra->SetMinimum(89) ;
  phipospra->SetMaximum(93) ;
  phiposprb->Draw("same") ;
  phiposprb->SetLineColor(9) ;
  phiposprb->SetMarkerColor(9) ;
  fig3->cd(2) ;
  phinegpra->Draw() ;
  phinegpra->SetMinimum(89) ;
  phinegpra->SetMaximum(93) ;
  phinegprb->Draw("same") ;
  phinegprb->SetLineColor(9) ;
  phinegprb->SetMarkerColor(9) ;
  fig3->cd(3) ;
  etapospra->Draw() ;
  etapospra->SetMinimum(89) ;
  etapospra->SetMaximum(93) ;
  etaposprb->Draw("same") ;
  etaposprb->SetLineColor(9) ;
  etaposprb->SetMarkerColor(9) ;
  fig3->cd(4) ;
  etanegpra->Draw() ;
  etanegpra->SetMinimum(89) ;
  etanegpra->SetMaximum(93) ;
  etanegprb->Draw("same") ;
  etanegprb->SetLineColor(9) ;
  etanegprb->SetMarkerColor(9) ;

  phipospra->SetTitle("positive muon") ;
  phinegpra->SetTitle("negative muon") ;
  //etapospra->SetTitle("positive muon") ;
  //etanegpra->SetTitle("negative muon") ;

  // the pra are already written above
  fout->cd();
  phiposprb->Write();
  phinegprb->Write();
  etaposprb->Write();
  etanegprb->Write();


  fig3->Print("massvsetaphi_after.eps") ;

  TCanvas* c1 =new TCanvas("c1","",300,300) ;
  c1->Divide(2,2) ;
  int ipad=0 ;
  c1->cd(++ipad) ;
  momvsphipospr->Draw() ;
  c1->cd(++ipad) ;
  momvsphinegpr->Draw() ;

  fout->cd();
  momvsphipospr->Write();
  momvsphinegpr->Write();

  //TH1* h1costhetaa = (dynamic_cast<TH1*>(gDirectory->Get("massvscosthetastarpra")))->DrawCopy() ;
  //TH1* h1costhetab = (dynamic_cast<TH1*>(gDirectory->Get("massvscosthetastarprb")))->DrawCopy("same") ;
  massvscosthetastarpra->Write();
  massvscosthetastarprb->Write();

  
  TCanvas* c4 = new TCanvas("fig","",700,350) ;
  c4->Divide(2,1) ;
  c4->cd(1) ;
  curvaturecalibh1[1].SetLineColor(2) ;
  curvaturecalibh1[1].SetMarkerColor(2) ;
  curvaturecalibh1[0].SetMinimum(-1e-7) ;
  curvaturecalibh1[0].SetMaximum(+1e-7) ;
  curvaturecalibh1[0].GetXaxis()->SetTitle("phi") ;
  curvaturecalibh1[0].GetYaxis()->SetTitle("curvature bias [1/MeV]") ;
  curvaturecalibh1[0].DrawCopy() ;
  curvaturecalibh1[1].DrawCopy("same") ;

  fout->cd();
  curvaturecalibh1[0].Write();
  curvaturecalibh1[1].Write();

  c4->cd(2) ;
  mh1b->SetLineColor(9) ;
  mh1b->SetMarkerColor(9) ;
  mh1b->Draw() ;
  mh1a->Draw("same") ;
  mh1b->GetXaxis()->SetTitle("dimuon invariant mass [GeV]") ;
  TLine line ;
  line.SetLineStyle(2) ;
  line.SetLineColor(17) ;
  line.DrawLine(Z0mass/1000,0,Z0mass/1000,1.1*mh1b->GetMaximum()) ;
 
  fout->cd();
  mh1a->Write();
  mh1b->Write();


  mmerrh1->Write();

  c4->Print("curvaturecalibration.eps") ;
  std::cout << "Writing to output file " << outputFileName.c_str() << std::endl;
  fout->Write();

  fout->Close();

}

void run(const char* input, const char* output, const char* mcinput = "/user2/jprice/PythonPlotting/AFB/Wouter_MC.root") {

  // to run without split charge on MC...
  TFile* MCfile = new TFile(mcinput, "read");

  TProfile2D* etaposneg_11 = (TProfile2D*) MCfile->Get("etaposnegpra_2011");//("etaposnegpra_data_2011_MU");
  TProfile2D* etaposneg_12 = (TProfile2D*) MCfile->Get("etaposnegpra_2012");//("etaposnegpra_data_2012_MD");

  TH1F* mczmassvseta_pos_11 = (TH1F*) MCfile->Get("etapospra_2011");
  TH1F* mczmassvseta_neg_11 = (TH1F*) MCfile->Get("etanegpra_2011");
  TH1F* mczmassvseta_pos_12 = (TH1F*) MCfile->Get("etapospra_2012");
  TH1F* mczmassvseta_neg_12 = (TH1F*) MCfile->Get("etanegpra_2012");
  
  //TFile* f1 = new TFile("/user2/jprice/LHCb/afb/outputRootFiles/Unfolded_corr/shower_NNPDF_sthw2_2200_2012_SKIM_out.root", "read");
  bool isZ0 = true;
  TFile* f1 = TFile::Open(input);
  TTree *t1 = (TTree *)f1->Get("ZMuMu/DecayTree");
  if (!t1) {
    isZ0 = false;
    t1 = (TTree*)f1->Get("JpsiTuple/DecayTree");
  }
  if ( isZ0 )  processevents(t1, 10, true, false, 1.0, false, true);
  else  processevents(t1, 10, true, false, 1.0, false, true, mczmassvseta_pos_11, mczmassvseta_neg_11, etaposneg_11);
      

  //TFile* f6 = new TFile("/hepstore/jprice/LHCb/0820/mergedNtuples/ZMuMu_pythia8_Zmumu_MDonly.root", "read");
  //TTree *t6 = (TTree *)f6->Get("ZMuMu/DecayTree");
  //processevents(t6, 10, true, false, 8000., -1.0, false, true, mczmassvseta_pos_11, mczmassvseta_neg_11, etaposneg_11);


}

int main(int argc, char *argv[]) {
  if (argc == 3) run(argv[1], argv[2]);
  else cout<<"usage : curbias.o [input] [output]"<<endl;



}

// root -l
// .L Wouter_modified.cxx+
// run_all()
