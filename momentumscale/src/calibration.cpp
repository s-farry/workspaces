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
#include <TFitResult.h>
#include <TLine.h>
#include "Math/RootFinder.h"


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

  TLorentzVector p4corrected(TH2D* a_params, double b_param) const {
    TLorentzVector mom = p4() ;
    double m = mom.M() ;
    double tx = mom.X() / mom.Z() ;
    double ty = mom.Y() / mom.Z() ;
    double q = charge() ; 
    //think q should be constant as same factors will be used for opposite charge/polarity
    //double q = 1.0;
    //double nx = std::sqrt( (1 + tx*tx )/(1 + tx*tx + ty*ty) ) ;
    //double pxz = nx * mom.P() ;
    double p = mom.P();
    double phi = mom.Phi() ;
    double eta = mom.Eta();
    double a = a_params->GetBinContent(a_params->FindBin(phi, eta));
    double b = b_param;
    double newp   = p * b /(1+ (p*a*m_polarity()/q)) ;
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



calibration::calibration(string name, TH2F* expectation){
  m_name = name;
  m_a_init       =  0.00  ;
  m_a_step       =  0.000005;
  m_a_lolimit    = -0.000001   ;
  m_a_uplimit    =  0.000001   ;

  m_b_init      =  1.00  ;
  m_b_step      =  0.03 ;
  m_b_lolimit   =  0.9  ;
  m_b_uplimit   =  1.1  ;

  m_precision = 0.001;
  m_tolerance = 0.1;

  m_nphibins = 12;
  m_netabins = 1;
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

  m_a1_params = new TH2D("a1_params", "a1_params",
			 m_nphibins, -TMath::Pi(), TMath::Pi(),
			 m_netabins, 2.0, 4.5);
  m_a2_params = new TH2D("a2_params", "a2_params",
			 m_nphibins, -TMath::Pi(), TMath::Pi(),
			 m_netabins, 2.0, 4.5);
  m_b1 = 1.0;
  m_b2 = 1.0;

  m_a1_init_vals = new TH2D("a1_init_vals", "a1_init_val",
			    m_nphibins, m_philo, m_phihi,
			    m_netabins, m_etalo, m_etahi);
  m_a2_init_vals = new TH2D("a2_init_vals", "a2_init_val",
			    m_nphibins, m_philo, m_phihi,
			    m_netabins, m_etalo, m_etahi);

  m_pprof = new TProfile2D("p", "p",
			   m_nphibins, m_philo, m_phihi,
			   m_netabins, m_etalo, m_etahi);
  m_txprof = new TProfile2D("tx", "tx",
			    m_nphibins, m_philo, m_phihi,
			    m_netabins, m_etalo, m_etahi);
  m_typrof = new TProfile2D("ty", "ty",
			    m_nphibins, m_philo, m_phihi,
			    m_netabins, m_etalo, m_etahi);
  m_pxprof = new TProfile2D("px", "px",
			    m_nphibins, m_philo, m_phihi,
			    m_netabins, m_etalo, m_etahi);
  m_pyprof = new TProfile2D("py", "py",
			    m_nphibins, m_philo, m_phihi,
			    m_netabins, m_etalo, m_etahi);
  m_pzprof = new TProfile2D("pz", "pz",
			    m_nphibins, m_philo, m_phihi,
			    m_netabins, m_etalo, m_etahi);
  m_pxOpprof = new TProfile2D("pxOp", "pxOp",
			      m_nphibins, m_philo, m_phihi,
			      m_netabins, m_etalo, m_etahi);
  m_pyOpprof = new TProfile2D("pyOp", "pyOp",
			      m_nphibins, m_philo, m_phihi,
			      m_netabins, m_etalo, m_etahi);
  m_pzOpprof = new TProfile2D("pzOp", "pzOp",
			      m_nphibins, m_philo, m_phihi,
			      m_netabins, m_etalo, m_etahi);
  m_ptprof = new TProfile2D("pt", "pt",
			     m_nphibins, m_philo, m_phihi,
			     m_netabins, m_etalo, m_etahi);

  
  
  m_curv_const_1 = vector<double>(m_netabins, -1);
  m_curv_const_2 = vector<double>(m_netabins, -1);
  
  m_z0_params_magup["width"] = new TH2F("width_magup", "width",
					m_nphibins, -TMath::Pi(), TMath::Pi(),
					m_netabins, 2.0, 4.5);
  m_z0_params_magup["sigma"] = new TH2F("sigma_magup", "sigma",
					m_nphibins, -TMath::Pi(), TMath::Pi(),
					m_netabins, 2.0, 4.5);
  m_z0_params_magup["alpha"] = new TH2F("alpha_magup", "alpha",
					m_nphibins, -TMath::Pi(), TMath::Pi(),
					m_netabins, 2.0, 4.5);
  m_z0_params_magup["n"]     = new TH2F("n_magup", "n",
					m_nphibins, -TMath::Pi(), TMath::Pi(),
					m_netabins, 2.0, 4.5);
  m_z0_params_magup["lambda"] = new TH2F("lambda_magup", "lambda",
					 m_nphibins, -TMath::Pi(), TMath::Pi(),
					 m_netabins, 2.0, 4.5);
  m_z0_params_magup["s"]     = new TH2F("s_magup", "s",
					m_nphibins, -TMath::Pi(), TMath::Pi(),
					m_netabins, 2.0, 4.5);
  m_z0_params_magup["mean"]  = new TH2F("mean_magup", "mean",
					m_nphibins, -TMath::Pi(), TMath::Pi(),
					m_netabins, 2.0, 4.5);

  
  m_z0_params_magdown["width"] = new TH2F("width_magdown", "width",
				  m_nphibins, -TMath::Pi(), TMath::Pi(),
				  m_netabins, 2.0, 4.5);
  m_z0_params_magdown["sigma"] = new TH2F("sigma_magdown", "sigma",
				  m_nphibins, -TMath::Pi(), TMath::Pi(),
				  m_netabins, 2.0, 4.5);
  m_z0_params_magdown["alpha"] = new TH2F("alpha_magdown", "alpha",
				  m_nphibins, -TMath::Pi(), TMath::Pi(),
				  m_netabins, 2.0, 4.5);
  m_z0_params_magdown["n"]     = new TH2F("n_magdown", "n",
				  m_nphibins, -TMath::Pi(), TMath::Pi(),
				  m_netabins, 2.0, 4.5);
  m_z0_params_magdown["lambda"] = new TH2F("lambda_magdown", "lambda",
				  m_nphibins, -TMath::Pi(), TMath::Pi(),
				  m_netabins, 2.0, 4.5);
  m_z0_params_magdown["s"]     = new TH2F("s_magdown", "s",
				  m_nphibins, -TMath::Pi(), TMath::Pi(),
				  m_netabins, 2.0, 4.5);
  m_z0_params_magdown["mean"]     = new TH2F("mean_magdown", "mean",
				  m_nphibins, -TMath::Pi(), TMath::Pi(),
				  m_netabins, 2.0, 4.5);


  m_expectation = 0;

  double z0_m_pdg = 91.1876;

  //m_expectation = expectation;

  if (m_expectation == 0){
    m_expectation   = new TH2F("expectation", "expectation",
			       m_nphibins, -TMath::Pi(), TMath::Pi(),
			       m_netabins, 2.0, 4.5);
    
    for (int i = 0 ; i < m_nphibins; ++i){
      for (int j = 0 ; j < m_netabins; ++j){
	m_expectation->SetBinContent(i+1,j+1, z0_m_pdg);
	m_expectation->SetBinError(i+1,j+1, z0_m_pdg*0.001);
      }
    }
  }

}

results calibration::fit_z0_mass(int idx1, int idx2, int polarity, bool refit){
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


  // choose which parameter file to use
  std::map<string, TH2F*> params = m_z0_params_magup;
  if(polarity != 1) params = m_z0_params_magdown;

  if (refit){
    //fix all parameters except mass when refitting
    width.setVal(params["width"]->GetBinContent(idx1+1, idx2+1));
    width.setConstant();
    sigma.setVal(params["sigma"]->GetBinContent(idx1+1, idx2+1));
    sigma.setConstant();
    alpha.setVal(params["alpha"]->GetBinContent(idx1+1, idx2+1));
    alpha.setConstant();
    n.setVal(params["n"]->GetBinContent(idx1+1, idx2+1));
    n.setConstant();
    lambda.setVal(params["lambda"]->GetBinContent(idx1+1, idx2+1));
    lambda.setConstant();
    s.setVal(params["s"]->GetBinContent(idx1+1, idx2+1));
    s.setConstant();
    mean.setVal(params["mean"]->GetBinContent(idx1+1, idx2+1));
  }
  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(pdf, expo), RooArgList(s));
  TH1F* hist = 0;
  if (polarity == 1) hist = m_current_hists_magup.at(idx1).at(idx2);
  else hist = m_current_hists_magdown.at(idx1).at(idx2);


  RooDataHist dh("dh", "dh", m, Import(*hist));
  
  sum.fitTo(dh, PrintEvalErrors(-1));

  TCanvas c1;
  RooPlot* frame = m.frame();
  dh.plotOn(frame);
  sum.plotOn(frame);
  sum.paramOn(frame);
  frame->Draw();
  ostringstream ss;
  ss<<"/user2/sfarry/workspaces/momentumscale/figures/minimisation_"<<polarity<<"_"<<idx1<<"_"<<idx2<<".pdf";
  c1.Print(ss.str().c_str());

  if (!refit){
    if (polarity == 1){
      //if this is the first fit, set the parameters for use from now on
      m_z0_params_magup["width"]->SetBinContent(idx1+1, idx2+1, width.getVal());
      m_z0_params_magup["width"]->SetBinError(idx1+1, idx2+1, width.getError());
      m_z0_params_magup["sigma"]->SetBinContent(idx1+1, idx2+1, sigma.getVal());
      m_z0_params_magup["sigma"]->SetBinError(idx1+1, idx2+1, sigma.getError());
      m_z0_params_magup["alpha"]->SetBinContent(idx1+1, idx2+1, alpha.getVal());
      m_z0_params_magup["alpha"]->SetBinError(idx1+1, idx2+1, alpha.getError());
      m_z0_params_magup["n"]->SetBinContent(idx1+1, idx2+1, n.getVal());
      m_z0_params_magup["n"]->SetBinError(idx1+1, idx2+1, n.getError());
      m_z0_params_magup["lambda"]->SetBinContent(idx1+1, idx2+1, lambda.getVal());
      m_z0_params_magup["lambda"]->SetBinError(idx1+1, idx2+1, lambda.getError());
      m_z0_params_magup["s"]->SetBinContent(idx1+1, idx2+1, s.getVal());
      m_z0_params_magup["s"]->SetBinError(idx1+1, idx2+1, s.getError());
    }
    else{
      m_z0_params_magdown["width"]->SetBinContent(idx1+1, idx2+1, width.getVal());
      m_z0_params_magdown["width"]->SetBinError(idx1+1, idx2+1, width.getError());
      m_z0_params_magdown["sigma"]->SetBinContent(idx1+1, idx2+1, sigma.getVal());
      m_z0_params_magdown["sigma"]->SetBinError(idx1+1, idx2+1, sigma.getError());
      m_z0_params_magdown["alpha"]->SetBinContent(idx1+1, idx2+1, alpha.getVal());
      m_z0_params_magdown["alpha"]->SetBinError(idx1+1, idx2+1, alpha.getError());
      m_z0_params_magdown["n"]->SetBinContent(idx1+1, idx2+1, n.getVal());
      m_z0_params_magdown["n"]->SetBinError(idx1+1, idx2+1, n.getError());
      m_z0_params_magdown["lambda"]->SetBinContent(idx1+1, idx2+1, lambda.getVal());
      m_z0_params_magdown["lambda"]->SetBinError(idx1+1, idx2+1, lambda.getError());
      m_z0_params_magdown["s"]->SetBinContent(idx1+1, idx2+1, s.getVal());
      m_z0_params_magdown["s"]->SetBinError(idx1+1, idx2+1, s.getError());

    }
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

  m_z0_init_mean_magup = ((TH2F*)m_z0_params_magup["mean"]->Clone("z0_init_mean_magup"));
  m_z0_init_mean_magdown = ((TH2F*)m_z0_params_magdown["mean"]->Clone("z0_init_mean_magdown"));

  ROOT::Minuit2::Minuit2Minimizer fitter;
  ROOT::Math::Functor function(this, &calibration::curvature_metric,m_nphibins*m_netabins);

  fitter.SetPrintLevel(3);
  fitter.SetMaxFunctionCalls(20000); //increase number of function calls
  fitter.SetStrategy(1); //0 - fast as possible as there are many variables, 1 - default


  int totbins = m_nphibins*m_netabins;

  for (int i = 0 ; i < m_nphibins; ++i){
    for (int j = 0 ; j < m_netabins; ++j){
      int bin = i * m_netabins + j;
      ostringstream s;
      s<<"a1_"<<bin;
      fitter.SetLimitedVariable(bin,s.str().c_str(), m_a1_init_vals->GetBinContent(i+1,j+1), m_a_step, m_a_lolimit, m_a_uplimit);
    }
  }
  /*
  for (int i = 0 ; i < m_nphibins; ++i){
    for (int j = 0 ; j < m_netabins; ++j){
      int bin = i * m_netabins + j;
      ostringstream s;
      s<<"a2_"<<bin;
      fitter.SetLimitedVariable(totbins + bin,s.str().c_str(), m_a2_init_vals->GetBinContent(i+1,j+1), m_a_step, m_a_lolimit, m_a_uplimit);
    }
    }*/

  //fitter.SetLimitedVariable(2*totbins,"b1",m_b_init, m_b_step, m_b_lolimit, m_b_uplimit); 
  //fitter.SetLimitedVariable(2*totbins+1,"b2",m_b_init, m_b_step, m_b_lolimit, m_b_uplimit); 
  fitter.SetFunction(function);
  //fitter.SetPrecision(m_precision);
  fitter.SetTolerance(m_tolerance);
  fitter.Minimize();


  cout<<"First Minimisation (curvature bias) complete"<<endl;

  ROOT::Minuit2::Minuit2Minimizer fitter2;
  ROOT::Math::Functor function2(this, &calibration::momentumscale_metric,2);
  
  fitter2.SetLimitedVariable(0,"b1",m_b_init, m_b_step, m_b_lolimit, m_b_uplimit); 
  fitter2.SetLimitedVariable(1,"b2",m_b_init, m_b_step, m_b_lolimit, m_b_uplimit); 
  fitter2.SetFunction(function2);
  //fitter.SetPrecision(m_precision);
  fitter2.SetTolerance(m_tolerance);
  fitter2.Minimize();

  cout<<"Second Minimisation (momentum scale)"<<endl;
  
  int stop_s = clock();
  cout<<"time taken to minimise: "<<(stop_s - start_s)/double(CLOCKS_PER_SEC)<<" seconds"<<endl;
}


double calibration::metric(const double* params){
  //transfer to parameters to member variables in order to calculate chi2
  for (int i = 0 ; i < m_nphibins ; ++i){
    for (int j = 0 ; j < m_netabins ; ++j){
      //cout<<"Setting bin parameters to "<<params[i*m_netabins+j]<<" "<<params[m_nphibins*m_netabins + i*m_netabins+j]<<endl;
      m_a1_params->SetBinContent(i+1, j+1, params[i*m_netabins + j ]);
      //m_a2_params->SetBinContent(i+1, j+1, params[m_nphibins*m_netabins + i*m_netabins + j ]);
      //cout<<"Getting bin parameters "<<m_a1_params->GetBinContent(i+1, j+1)<<endl;

    }
  }
  m_b1 = params[2*m_nphibins*m_netabins];
  m_b2 = params[2*m_nphibins*m_netabins+1];
  //update all histograms with new parameters
  update_hists();
  //refit histograms to get new mean
  get_fitted_means(true);
  
  return getchi2();
}

double calibration::curvature_metric(const double* params){
  //transfer to parameters to member variables in order to calculate chi2
  for (int i = 0 ; i < m_nphibins ; ++i){
    for (int j = 0 ; j < m_netabins ; ++j){
      //cout<<"Setting bin parameters to "<<params[i*m_netabins+j]<<" "<<params[m_nphibins*m_netabins + i*m_netabins+j]<<endl;
      m_a1_params->SetBinContent(i+1, j+1, params[i*m_netabins + j ]);
      //m_a2_params->SetBinContent(i+1, j+1, params[m_nphibins*m_netabins + i*m_netabins + j ]);
      //cout<<"Getting bin parameters "<<m_a1_params->GetBinContent(i+1, j+1)<<endl;

    }
  }
  //update all histograms with new parameters
  update_hists();
  //refit histograms to get new mean
  get_fitted_means(true);
  
  return get_curvature_chi2();
}

double calibration::momentumscale_metric(const double* params){
  //transfer to parameters to member variables in order to calculate chi2
  m_b1 = params[0];
  m_b2 = params[1];
  //update all histograms with new parameters
  update_hists();
  //refit histograms to get new mean
  get_fitted_means(true);
  
  return getchi2();
}

double calibration::getchi2(){
  //minimise the chi2 agreement between fitted mean and expectation
  //double chi2ndof = m_z0_params_magdown["mean"]->Chi2Test(m_expectation, "CHI2/NDF");
  //chi2ndof += m_z0_params_magup["mean"]->Chi2Test(m_expectation, "CHI2/NDF");
  double chi2ndof = get_chi2(m_z0_params_magdown["mean"], m_expectation);
  chi2ndof += get_chi2(m_z0_params_magup["mean"], m_expectation);
  cout<<"chi2ndof: "<<chi2ndof<<endl;
  cout<<m_b1<<" "<<m_b2<<endl;
  /*m_a1_params->GetBinContent(1,1)<<" "<<m_a1_params->GetBinContent(2,1)<<
    m_a1_params->GetBinContent(3,1)<<" "<<m_a1_params->GetBinContent(4,1)<<
    m_a1_params->GetBinContent(5,1)<<" "<<m_a1_params->GetBinContent(6,1)<<
    m_a1_params->GetBinContent(7,1)<<" "<<m_a1_params->GetBinContent(8,1)<<
    m_a1_params->GetBinContent(9,1)<<" "<<m_a1_params->GetBinContent(10,1)<<
    m_a1_params->GetBinContent(11,1)<<" "<<m_a1_params->GetBinContent(12,1)<<
    " "<<m_b1<<" "<<m_b2<<endl;*/
  return chi2ndof;
}
double calibration::get_curvature_chi2(){
  //minimise the chi2 agreement between fitted mean and straight line in bins of phi
  double chi2 = 0.0;
  for (int i = 0 ; i < m_netabins ; ++i){
    //TF1* magup_f1   = new TF1("magup_f1", "pol0", m_philo, m_phihi);
    //TF1* magdown_f1 = new TF1("magdown_f1", "pol0", m_philo, m_phihi);
    
    TH1D* phi_magdown_hist = (TH1D*)m_z0_params_magdown["mean"]->ProjectionX("phi_magdown_hist",i+1,i+1);
    TH1D* phi_magup_hist   = (TH1D*)m_z0_params_magup["mean"]->ProjectionX("phi_magup_hist",i+1,i+1);

    //TFitResultPtr r1 = phi_magdown_hist->Fit("magdown_f1", "QS");
    //TFitResultPtr r2 = phi_magup_hist->Fit("magup_f1"  , "QS");

    TFitResultPtr r1, r2;
    //TH1D* ref1 = (TH1D*)phi_magdown_hist->Clone("ref1");
    //TH1D* ref2 = (TH1D*)phi_magup_hist->Clone("ref2");
    
    if (m_curv_const_1.at(i) == -1 && m_curv_const_2.at(i) == -1){
      r1 = phi_magdown_hist->Fit("pol0", "QS");
      r2 = phi_magup_hist->Fit("pol0"  , "QS");
      m_curv_const_1.at(i) = r1->Parameter(0);
      m_curv_const_2.at(i) = r2->Parameter(0);
    }

    //for (int i = 0 ; i < ref1->GetNbinsX() ; ++ i){
    //  ref1->SetBinContent(i, m_curv_const_1);
    //  ref2->SetBinContent(i, m_curv_const_2);
    //}

    //chi2 += phi_magdown_hist->Chi2Test(ref1, "CHI2/NDF");
    //chi2 += phi_magup_hist->Chi2Test(ref2, "CHI2/NDF");

    chi2 += get_chi2(phi_magdown_hist, m_curv_const_1.at(i), 0);
    chi2 += get_chi2(phi_magup_hist, m_curv_const_2.at(i), 0);

    //r1->Chi2()/r1->Ndf();
    //chi2 += r2->Chi2()/r2->Ndf();

    phi_magdown_hist->Delete();
    phi_magup_hist->Delete();
    //ref1->Delete();
    //ref2->Delete();
    
  }
  cout<<"chi2: "<<chi2<<endl;
  cout<<m_a1_params->GetBinContent(1,1)<<" "<<m_a1_params->GetBinContent(2,1)<<" "<<
    m_a1_params->GetBinContent(3,1)<<" "<<m_a1_params->GetBinContent(4,1)<<" "<<
    m_a1_params->GetBinContent(5,1)<<" "<<m_a1_params->GetBinContent(6,1)<<endl;
  cout<<m_a2_params->GetBinContent(1,1)<<" "<<m_a1_params->GetBinContent(2,1)<<" "<<
    m_a2_params->GetBinContent(3,1)<<" "<<m_a2_params->GetBinContent(4,1)<<" "<<
    m_a2_params->GetBinContent(5,1)<<" "<<m_a2_params->GetBinContent(6,1)<<endl;
  
  /*m_a1_params->GetBinContent(7,1)<<" "<<m_a1_params->GetBinContent(8,1)<<
    m_a1_params->GetBinContent(9,1)<<" "<<m_a1_params->GetBinContent(10,1)<<
    m_a1_params->GetBinContent(11,1)<<" "<<m_a1_params->GetBinContent(12,1)<<*/
  
  return chi2;
}

void calibration::update_hists(){
  //clear hists
  for(unsigned int i = 0 ; i < m_current_hists_magup.size() ; ++i){
    for (unsigned int j = 0 ; j < m_current_hists_magup.at(i).size() ; ++j){
      m_current_hists_magup.at(i).at(j)->Reset();
    }
  }
  for(unsigned int i = 0 ; i < m_current_hists_magdown.size() ; ++i){
    for (unsigned int j = 0 ; j < m_current_hists_magdown.at(i).size() ; ++j){
      m_current_hists_magdown.at(i).at(j)->Reset();
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
	if (Z0.polarity() == 1)	m_current_hists_magup.at(phibin-1).at(etabin-1)->Fill(corrmassGeV);
	else	m_current_hists_magdown.at(phibin-1).at(etabin-1)->Fill(corrmassGeV);
      }
  }
  std::cout << "|\n" << std::flush;
}

void calibration::fill_hists(TTree* t){
  m_tree = t;
  m_tree->SetBranchStatus("*",0);
  for (int i = 0 ; i < m_nphibins ; ++i){
    std::vector<TH1F*> etahists_magup, etahists_magdown;
    std::vector<TH1F*> etahists_magup_current, etahists_magdown_current;
    for (int j = 0 ; j < m_netabins ; ++j){
      ostringstream a, b,c,d;
      a<<"mass_magup_"<<i<<"_"<<j;
      b<<"mass_magup_"<<i<<"_"<<j<<"_current";
      c<<"mass_magdown_"<<i<<"_"<<j;
      d<<"mass_magdown_"<<i<<"_"<<j<<"_current";
      etahists_magup.push_back(new TH1F(a.str().c_str(), "mass hist", 100, 60, 120));
      etahists_magup_current.push_back(new TH1F(b.str().c_str(), "mass hist", 100, 60, 120));
      etahists_magdown.push_back(new TH1F(c.str().c_str(), "mass hist", 100, 60, 120));
      etahists_magdown_current.push_back(new TH1F(d.str().c_str(), "mass hist", 100, 60, 120));
    }
    m_hists_magup.push_back(etahists_magup);
    m_current_hists_magup.push_back(etahists_magup_current);
    m_hists_magdown.push_back(etahists_magdown);
    m_current_hists_magdown.push_back(etahists_magdown_current);
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
	if (Z0.polarity() == 1){
	  m_hists_magup.at(phibin-1).at(etabin-1)->Fill(massGeV);
	  m_current_hists_magup.at(phibin-1).at(etabin-1)->Fill(massGeV);
	}
	else{
	  m_hists_magdown.at(phibin-1).at(etabin-1)->Fill(massGeV);
	  m_current_hists_magdown.at(phibin-1).at(etabin-1)->Fill(massGeV);
	}
	m_pprof->Fill(p4p.Phi(), p4p.Eta(), p4p.P());
	m_txprof->Fill(p4p.Phi(), p4p.Eta(), p4p.Px()/p4p.Pz());
	m_typrof->Fill(p4p.Phi(), p4p.Eta(), p4p.Py()/p4p.Pz());
	m_pxprof->Fill(p4p.Phi(), p4p.Eta(), abs(p4p.Px()));
	m_pyprof->Fill(p4p.Phi(), p4p.Eta(), abs(p4p.Py()));
	m_pzprof->Fill(p4p.Phi(), p4p.Eta(), p4p.Pz());

	m_pxOpprof->Fill(p4p.Phi(), p4p.Eta(), p4p.Px()/p4p.P());
	m_pyOpprof->Fill(p4p.Phi(), p4p.Eta(), p4p.Py()/p4p.P());
	m_pzOpprof->Fill(p4p.Phi(), p4p.Eta(), p4p.Pz()/p4p.P());
	m_ptprof->Fill(p4p.Phi(), p4p.Eta(), p4p.Pt());

	/*
	m_pprof->Fill(p4p.Phi(), p4p.Eta(), p4m.P());
	m_txprof->Fill(p4p.Phi(), p4p.Eta(), p4m.Px()/p4m.Pz());
	m_typrof->Fill(p4p.Phi(), p4p.Eta(), p4m.Py()/p4m.Pz());
	m_pxprof->Fill(p4p.Phi(), p4p.Eta(), p4m.Px());
	m_pyprof->Fill(p4p.Phi(), p4p.Eta(), p4m.Py());
	m_pzprof->Fill(p4p.Phi(), p4p.Eta(), p4m.Py());
	*/
	
      }
  }
  std::cout << "|\n" << std::flush;
}

void calibration::save(const char* output){
  TFile* f = new TFile(output, "RECREATE");

  TObjArray* magup_hists = new TObjArray();
  TObjArray* magdown_hists = new TObjArray();
  TObjArray* magup_hists_final = new TObjArray();
  TObjArray* magdown_hists_final = new TObjArray();

  for (int i = 0 ; i < m_nphibins ; ++i){
    for (int j = 0 ; j < m_netabins ; ++j){
      magup_hists->Add(m_hists_magup.at(i).at(j));
      magdown_hists->Add(m_hists_magdown.at(i).at(j));
      magup_hists_final->Add(m_current_hists_magup.at(i).at(j));
      magdown_hists_final->Add(m_current_hists_magup.at(i).at(j));
    }
  }

  magup_hists->Write("MagUpHists",1);
  magdown_hists->Write("MagDownHists",1);
  magup_hists_final->Write("MagUpHists_final",1);
  magdown_hists_final->Write("MagDownHists_final",1);

  m_z0_init_mean_magup->Write(); // mean mass before calibration
  m_z0_params_magup["mean"]->Write(); // mass after calibration
  m_z0_init_mean_magdown->Write(); // mean mass before calibration
  m_z0_params_magdown["mean"]->Write(); // mass after calibration
  if (m_a1_params && m_a2_params){
    m_a1_params->Write(); //parameter set a1 (curvature bias)
    m_a2_params->Write(); //parameter set a2 (curvature bias)
  }
  TParameter<double>("b1", m_b1).Write(); //b1 (momentum scale)
  TParameter<double>("b2", m_b2).Write(); //b2 (momentum scale)
  f->Close();
}


void calibration::get_fitted_means(bool refit){
  for (int i = 0 ; i < m_nphibins ; ++i){
    for ( int j = 0 ; j < m_netabins ; ++j){
      results magup_fit = fit_z0_mass(i,j, 1, refit);
      m_z0_params_magup["mean"]->SetBinContent(i+1, j+1, magup_fit["mean"].first);
      m_z0_params_magup["mean"]->SetBinError(i+1, j+1, magup_fit["mean"].second);
      results magdown_fit = fit_z0_mass(i,j, 0, refit);
      m_z0_params_magdown["mean"]->SetBinContent(i+1, j+1, magdown_fit["mean"].first);
      m_z0_params_magdown["mean"]->SetBinError(i+1, j+1, magdown_fit["mean"].second);
    }
  }

  TCanvas* c1 = new TCanvas();
  for (int i = 0 ; i < m_netabins ; ++i){
    TH1D* magup   = (TH1D*)m_z0_params_magup["mean"]->ProjectionX("magup", i+1, i+1);
    TH1D* magdown = (TH1D*)m_z0_params_magdown["mean"]->ProjectionX("magdown", i+1, i+1);
    magup->SetLineColor(2);
    magdown->SetLineColor(4);
    magup->GetYaxis()->SetRangeUser(85,95);
    magup->Draw();
    magdown->Draw("same");
    if (m_curv_const_1.at(i) != -1 && m_curv_const_2.at(i) != -1){
      TLine* l1 = new TLine(-TMath::Pi(), m_curv_const_1.at(i), TMath::Pi(), m_curv_const_1.at(i));
      l1->SetLineColor(4);
      TLine* l2 = new TLine(-TMath::Pi(), m_curv_const_2.at(i), TMath::Pi(), m_curv_const_2.at(i));
      l2->SetLineColor(2);
      l1->Draw("same");
      l2->Draw("same");
    }
    ostringstream s;
    s<<"/user2/sfarry/workspaces/momentumscale/figures/mass_v_phi_"<<i;
    if (!refit) s<<"_original";
    s<<".pdf";

    c1->Print(s.str().c_str());
    magup->Delete();
    magdown->Delete();
  }

}

double calibration::get_chi2(TH2F* a, TH2F* b){
  double chi2 = 0;
  for (int i = 0 ; i < a->GetXaxis()->GetNbins(); ++i){
    for (int j = 0 ; j < a->GetYaxis()->GetNbins(); ++j){
      chi2 += pow(a->GetBinContent(i+1, j+1) - b->GetBinContent(i+1,j+1),2)/
	(pow(a->GetBinError(i+1,j+1),2)+pow(b->GetBinError(i+1,j+1),2));
    }
  }
  return chi2;
}
double calibration::get_chi2(TH1D* a, double val, double valerr){
  double chi2 = 0;
  for (int i = 0 ; i < a->GetXaxis()->GetNbins(); ++i){
    chi2 += pow(a->GetBinContent(i+1) - val,2)/
      (pow(a->GetBinError(i+1),2)+valerr*valerr);
  }
  return chi2;
}


void calibration::get_curvature_init_vals(){
  for (int i = 0 ; i < m_a1_params->GetXaxis()->GetNbins() ; ++i){
    for (int j = 0 ; j < m_a1_params->GetYaxis()->GetNbins() ; ++j){
      m_Mrec = m_z0_params_magup["mean"]->GetBinContent(i+1, j+1)*1000.0;
      m_Mtrue = m_curv_const_2.at(j)*1000.0;

      m_p = m_pprof->GetBinContent(i+1,j+1);
      m_tx = m_txprof->GetBinContent(i+1,j+1);
      m_ty = m_typrof->GetBinContent(i+1,j+1);

      m_px = m_pxprof->GetBinContent(i+1,j+1);
      m_py = m_pyprof->GetBinContent(i+1,j+1);
      m_pz = m_pzprof->GetBinContent(i+1,j+1);

      m_pxOp = m_pxOpprof->GetBinContent(i+1,j+1);
      m_pyOp = m_pyOpprof->GetBinContent(i+1,j+1);
      m_pzOp = m_pzOpprof->GetBinContent(i+1,j+1);

      m_pt   = m_ptprof->GetBinContent(i+1,j+1);
      
      // RootFinder with Base Functions
      ROOT::Math::Functor1D f1D(this, &calibration::fcalc);
      
      // Create the Integrator
      ROOT::Math::RootFinder rfb(ROOT::Math::RootFinder::kBRENT);
      rfb.SetFunction(f1D, -5e-7, 5e-7); 
      bool solved = rfb.Solve(1000, 1e-11, 1e-11);
      //cout << "i: "<<i<<" j: "<<j<<" solved: "<<solved<<" "<<m_M<<" "<<m_m<<" "<<fcalc(0.0)<<" "<<fcalc(rfb.Root())<<" "<<rfb.Root() << endl;
      
      m_a1_init_vals->SetBinContent(i+1,j+1, rfb.Root());
      m_a1_params->SetBinContent(i+1,j+1, rfb.Root());

    }
  }
}

double calibration::f(double Mrec, double Mtrue, double c, double px, double py, double pz, double p) {
  
  // Mtrue - Mrec = dm
  //therefore find root of Mrec - Mtrue + dm

   double f_result;
   //f_result = Mrec - Mtrue -sqrt(4*pow(fabs(px), 2) + 4*pow(fabs(py), 2)) + sqrt(pow(sqrt(pow(fabs(px/(c*p - 1)), 2) + pow(fabs(py/(c*p - 1)), 2) + pow(fabs(pz/(c*p - 1)), 2)) + sqrt(pow(fabs(px/(c*p + 1)), 2) + pow(fabs(py/(c*p + 1)), 2) + pow(fabs(pz/(c*p + 1)), 2)), 2) - pow(fabs(px/(c*p + 1) + px/(c*p - 1)), 2) - pow(fabs(py/(c*p + 1) + py/(c*p - 1)), 2) - pow(fabs(pz/(c*p + 1) - pz/(c*p - 1)), 2));
   f_result = Mrec - Mtrue -sqrt(4*pow(fabs(px), 2) + 4*pow(fabs(py), 2)) + sqrt(pow(sqrt(pow(fabs(px/(c*p - 1)), 2) + pow(fabs(py/(c*p - 1)), 2) + pow(fabs(pz/(c*p - 1)), 2)) + sqrt(pow(fabs(px/(c*p + 1)), 2) + pow(fabs(py/(c*p + 1)), 2) + pow(fabs(pz/(c*p + 1)), 2)), 2) - pow(fabs(px/(c*p + 1) + px/(c*p - 1)), 2) - pow(fabs(py/(c*p + 1) + py/(c*p - 1)), 2) - pow(fabs(pz/(c*p + 1) - pz/(c*p - 1)), 2));
   return f_result;

}


double calibration::fcalc(double c) {
  //cout<<"masses: "<<m_M<<" "<<m_m<<endl;
  //cout<<m_M<<" "<<m_m<<" "<<c<<" "<<m_p<<" "<<m_tx<<" "<<m_ty<<" and c: "<<c<<endl;
  //cout<<c<<" to return: "<<f(m_M, m_m, c, m_p, m_tx, m_ty)<<endl;
  return f(m_Mrec, m_Mtrue, c, m_px, m_px, m_py, m_p);
}



int main(){

  //formula for initial values
  // a = (M/m' - 1)*(1/(p1-p2-p1*p2)) = (1-M/m')/(p1*p2) where m' is expected mass and M is measured

  RooMsgService::instance().setSilentMode(true);
  RooMsgService::instance().setGlobalKillBelow(RooFit::WARNING);

  TFile* f = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/ZMuMu.Refit.2015.root");
  TTree* t = (TTree*)f->Get("ZMuMu/DecayTree");
  TFile* g = new TFile("/user2/sfarry/workspaces/momentumscale/tuples/zmumu_mc2015_calibration.root");
  calibration a("momentumscale", (TH2F*)g->Get("Means"));
  a.fill_hists(t);
  a.get_fitted_means(false);
  a.get_curvature_chi2();
  //a.get_curvature_init_vals();
  //a.update_hists();
  //a.get_fitted_means(true);
  a.minimise();
  a.save("/user2/sfarry/workspaces/momentumscale/tuples/zmumu_2015_calibration.root");
}
