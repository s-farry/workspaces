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
  if (argc != 3 && argc!= 2 && argc != 1 && argc != 4) return 0;
  

  TH1::AddDirectory(false);
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");

  Fitter bjpsik_2015;
  bjpsik_2015.fitvar="m";
  bjpsik_2015.fitmodel = Fitter::bjpsik;
  bjpsik_2015.lo = 5225.;
  bjpsik_2015.hi = 5350.;

  Fitter bjpsikst_2015;
  bjpsikst_2015.fitvar="m2";
  bjpsikst_2015.fitmodel = Fitter::bjpsikst;
  bjpsikst_2015.vars    = {"gamma1_pt", "gamma2_pt"};
  bjpsikst_2015.los     =  {300, 300};
  bjpsikst_2015.his     =  {2000, 2000};
  bjpsikst_2015.bins    = { 2, 2 };
  bjpsikst_2015.lo = 5000.;
  //bjpsikst_2015.hi = 5600.;
  bjpsikst_2015.hi = 5450;
  //alter bin edges
  double edges[] = {300, 650, 2000};
  bjpsikst_2015.edges[0] = edges;
  bjpsikst_2015.edges[1] = edges;
  bjpsikst_2015.vars2d   = {{"gamma1_pt", "gamma2_pt"}};
  bjpsikst_2015.los2d    = {{300, 300}};
  bjpsikst_2015.his2d    = {{2000, 2000}};
  bjpsikst_2015.bins2d   = {{ 2 , 2 }};
  bjpsikst_2015.edges2d[0]  = {edges, edges};

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
  TObjArray *hists = 0, *histsb = 0, *histsc = 0, *hists2 = 0, *hists2b = 0, *hists2c = 0;
  if ( ds) {
    hists = bjpsik_2015.get_mass_v_vars(ds);
    bjpsik_2015.fitmodel=Fitter::bjpsik_polynomial;
    histsb = bjpsik_2015.get_mass_v_vars(ds, "polynomial");
    bjpsik_2015.fitmodel=Fitter::bjpsik_novosibirsk;
    histsc = bjpsik_2015.get_mass_v_vars(ds, "novosibirsk");

  }
  if ( ds2) {
    hists2 = bjpsikst_2015.get_mass_v_vars(ds2, "");
    bjpsikst_2015.fitmodel=Fitter::bjpsikst_polynomial;
    hists2b = bjpsikst_2015.get_mass_v_vars(ds2, "polynomial");
    bjpsikst_2015.fitmodel=Fitter::bjpsikst_novosibirsk;
    hists2c = bjpsikst_2015.get_mass_v_vars(ds2, "novosibirsk");
  }
  TFile* g = TFile::Open(output.c_str(), "RECREATE");
  if (hists)hists->Write();
  if (histsb) histsb->Write();
  if (histsc) histsc->Write();
  if (hists2)hists2->Write();
  if (hists2b)hists2b->Write();
  if (hists2c) hists2c->Write();
  g->Close();
  return 0;
}
