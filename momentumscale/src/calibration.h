#include <iostream>
#include <TTree.h>
#include <TCut.h>
#include <TObjArray.h>
#include <TGraphAsymmErrors.h>
#include <TH1F.h>
#include <TH2F.h>
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
  results fit_z0_mass(RooDataSet* ds);
  results fit_jpsi_mass(RooDataSet* ds);

 private:
  //range for tests
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
  double getchi2();

  //for fitting
  TH2F* get_fitted_means();

  //initialise dataset
  void fill_hists(TTree* t);
  //update dataset with current paramaterisation
  void update_hists();

  vector<vector<TH1F*> > m_hists;
  vector<vector<TH1F*> > m_current_hists;

  //the parameters we want to determine
  TH2F* m_a1_params;
  TH2F* m_a2_params;
  double m_b1;
  double m_b2;

  //What we should compare the mass to
  TH2F* m_expectation;

  //keep fit parameters
  //only mean allowed to vary after first fit
  std::map<string, TH2F*> m_z0_params;

  TTree* m_tree;

};
