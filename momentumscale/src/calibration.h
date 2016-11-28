#include <iostream>
#include <TTree.h>
#include <TCut.h>
#include <TObjArray.h>
#include <TGraphAsymmErrors.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile2D.h>
#include <TRandom3.h>
#include "Minuit2/Minuit2Minimizer.h"
//#include "Math/Functor.h"

#include "RooFit.h"
#include "RooRealVar.h"
#include "RooBreitWigner.h"
#include "RooCBShape.h"
#include "RooFFTConvPdf.h"
#include "RooPlot.h"
#include "RooGaussian.h"
#include "RooExponential.h"
#include "RooArgSet.h"
#include "RooAddPdf.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooFitResult.h"


using namespace std;
using namespace RooFit;

namespace std {
  template<class T> T sqr(const T& t) { return t*t ; }
}

typedef std::map<string, std::pair<double, double> > results;

class calibration {
 public:
  calibration();
  calibration(string name, TH2F* expectation = 0);
  results fit_z0_mass(int idx1, int idx2, int polarity, bool refit = false);
  results fit_jpsi_mass(TH1F* h);
  void fill_hists(TTree* t);
  void save(const char* output);
  void update_hists();
  void get_fitted_means(bool refit=false);
  void minimise();
  void fill_curvature_init_vals();
  void fill_momscale_init_vals();

  //the parameters we want to determine
  TH2D* m_a1_params;
  TH2D* m_a2_params;
  double m_b1;
  double m_b2;

  TH2D* m_a1_init_vals;
  TH2D* m_a2_init_vals;

  TProfile2D* m_pprof;
  TProfile2D* m_txprof;
  TProfile2D* m_typrof;
  TProfile2D* m_pxprof;
  TProfile2D* m_pyprof;
  TProfile2D* m_pzprof;
  TProfile2D* m_pxOpprof;
  TProfile2D* m_pyOpprof;
  TProfile2D* m_pzOpprof;
  TProfile2D* m_ptprof;
  
  void get_curvature_init_vals();
  double f(double M, double m, double c, double p1, double tx1, double ty1, double p);
  double fcalc(double c);

  double get_curvature_chi2();

  

 private:
  //range for tests
  string m_name;
  int m_nphibins;
  int m_philo;
  int m_phihi;
  int m_netabins;
  int m_etalo;
  int m_etahi;
  
  //parameters for minimisation
  double m_a_init;
  double m_a_step;
  double m_a_lolimit;
  double m_a_uplimit;
  double m_b_init;
  double m_b_step;
  double m_b_lolimit;
  double m_b_uplimit;
  double m_precision;
  double m_tolerance;

  //functions for minimisation
  double metric(const double *params);
  double curvature_metric(const double *params);
  double momentumscale_metric(const double *params);
  
  double getchi2();
  
  vector<double> m_curv_const_1;
  vector<double> m_curv_const_2;

  double get_chi2(TH2F* a, TH2F* b);
  double get_chi2(TH1D* a, double val, double valerr);

  //global variables for function finding
  double m_Mrec;
  double m_Mtrue;
  double m_p;
  double m_tx;
  double m_ty;
  double m_px;
  double m_py;
  double m_pz;
  double m_pxOp;
  double m_pyOp;
  double m_pzOp;
  double m_pt;
  
  //for fitting
  //void get_fitted_means(bool refit=false);

  //initialise dataset
  //void fill_hists(TTree* t);
  //update dataset with current paramaterisation
  //void update_hists();

  vector<vector<TH1F*> > m_hists_magup;
  vector<vector<TH1F*> > m_current_hists_magup;

  vector<vector<TH1F*> > m_hists_magdown;
  vector<vector<TH1F*> > m_current_hists_magdown;

  //the parameters we want to determine
  //TH2F* m_a1_params;
  //TH2F* m_a2_params;
  //double m_b1;
  //double m_b2;

  //What we should compare the mass to
  TH2F* m_expectation;

  //keep fit parameters
  //only mean allowed to vary after first fit
  std::map<string, TH2F*> m_z0_params_magup;
  std::map<string, TH2F*> m_z0_params_magdown;
  TH2F* m_z0_init_mean_magup   ;
  TH2F* m_z0_init_mean_magdown ;

  TTree* m_tree;

};
