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


using namespace std;
using namespace RooFit;

typedef std::map<string, std::pair<double, double> > results;

class Fitter {
public:
  string fitvar;
  double lo;
  double hi;
  string location;

  int nvars;
  //string vars[];
  //double los[] ;
  //double his[] ;
  //int binss[]  ;

  enum fit_t{z0, jpsi, bjpsik, bjpsikst, bjpsik_poly, bjpsik_novosibirsk, bjpsikst_novosibirsk, bjpsikst_polynomial, bjpsik_polynomial};

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

  TObjArray* get_mass_v_vars(RooDataSet* ds, string label = "");
  //TObjArray* get_mass_v_vars(RooDataSet* dsUp, RooDataSet* dsDown);
  TObjArray* get_mass_v_vars(TTree* t);
  TObjArray* get_mass_v_vars(TTree* t, TTree* u);


  results fit_jpsi_mass(RooDataSet* ds, string oFile,
			string cut);
  results fit_z0_mass(RooDataSet* ds, string oFile,
		      string cut);
  results fit_bjpsik_mass(RooDataSet* ds, string oFile,
			  string cut, bool kstar = false );
  results fit_bjpsik_mass_polynomial(RooDataSet* ds, string oFile,
				     string cut, bool kstar = false );
  results fit_bjpsik_mass_novosibirsk(RooDataSet* ds, string oFile,
				     string cut, bool kstar = false );
  

};
