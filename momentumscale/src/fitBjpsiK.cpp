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
#include "Fitter.h"

using namespace std;
using namespace RooFit;

int main(int argc, char* argv[]){
  if (argc != 3 && argc != 1 && argc != 4) return 0;
  

  TH1::AddDirectory(false);
  gROOT->ProcessLine(".x /user2/sfarry/Analyses/WJet/root/lhcbStyle.C");

  Fitter bjpsik_2015;
  bjpsik_2015.fitvar="m";
  bjpsik_2015.fitmodel = Fitter::bjpsik;
  bjpsik_2015.lo = 5200.;
  bjpsik_2015.hi = 5350.;

  Fitter bjpsikst_2015;
  bjpsikst_2015.fitvar="m2";
  bjpsikst_2015.fitmodel = Fitter::bjpsik;
  bjpsikst_2015.lo = 5200.;
  bjpsikst_2015.hi = 5350.;
  
  string input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/Jpsi.2015.root";
  string output = "output.root";

  if (argc > 1){
    input = argv[1];
  }
  if (argc > 2){
    output = argv[2];
  }
  
  TFile* f = TFile::Open(input.c_str(), "READ");
  RooDataSet* ds   = (RooDataSet*)f->Get("ds");
  RooDataSet* ds2  = (RooDataSet*)f->Get("ds2");
  TObjArray *hists = 0, *hists2 = 0;
  if ( ds) {
    hists = bjpsik_2015.get_mass_v_vars(ds);
  }
  if ( ds2) {
    hists2 = bjpsikst_2015.get_mass_v_vars(ds2);
  }
  if (hists && hists2){
    TFile* g = TFile::Open(output.c_str(), "RECREATE");
    hists->Write();
    hists2->Write();
    g->Close();
  }
  return 0;
}
