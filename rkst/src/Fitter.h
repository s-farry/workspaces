#include <TTree.h>
#include <TChain.h>
#include <TFile.h>
#include <TLeaf.h>
#include <TLorentzVector.h>
#include <TRegexp.h>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TStyle.h>
#include <TLine.h>
#include <TLegend.h>
#include <TText.h>
#include <TCut.h>
#include <TROOT.h>
#include <Math/SMatrix.h>
#include <Math/SVector.h>
#include <string>
#include <sstream>
#include <TPaveText.h>

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
#include "RooGenericPdf.h"
#include "RooNovosibirsk.h"
#include "RooChebychev.h"
#include "RooDataHist.h"



using namespace std;
using namespace RooFit;

typedef std::map<string, std::pair<double, double> > results;

class Fitter {
public:
  Fitter();
  string fitvar;
  double lo;
  double hi;
  string location;
  bool binned;

  int fitbins;
  int nvars;
  enum fit_t{jpsi};

  fit_t fitmodel;

  std::vector<string> vars;
  std::vector<double> los ;
  std::vector<double> his ;
  std::vector<int> bins   ;

  //optional - add bin edges
  std::map<int, double*> edges;
  std::map<int, std::pair<double*, double*> > edges2d;

  int nvars2d;
  std::vector< std::vector<string> > vars2d;
  std::vector< std::vector<double> > los2d ;
  std::vector< std::vector<double> > his2d ;
  std::vector< std::vector<int> >  bins2d ;

  TObjArray* do_fit(RooDataSet* ds, string pass, string label = "");
  results fit_jpsi_mass(RooDataSet* ds_tot, string oFile,
			string pass, string cut );

};
