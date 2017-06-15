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

  Fitter bjpsikst_2015;
  //bjpsikst_2015.binned = true;
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
  bjpsikst_2015.location = "/user2/sfarry/workspaces/energyflow/figs";

  string input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/Jpsi.2015.root";
  string output = "/user2/sfarry/workspaces/energyflow/tuples/output.root";

  if (argc > 1){
    input = argv[1];
  }
  if (argc > 2){
    output = argv[2];
    bjpsikst_2015.location = "/user2/sfarry/workspaces/energyflow/figs/"+output;
    output = "/user2/sfarry/workspaces/energyflow/tuples/"+output;
  }
  
  TFile* f = TFile::Open(input.c_str(), "READ");
  RooDataSet* ds  = (RooDataSet*)f->Get("ds2");
  TObjArray *hists = 0, *histsb = 0, *histsc = 0;
  if ( ds) {
    hists = bjpsikst_2015.get_mass_v_vars(ds, "");
    bjpsikst_2015.fitmodel=Fitter::bjpsikst_polynomial;
    histsb = bjpsikst_2015.get_mass_v_vars(ds, "polynomial");
    bjpsikst_2015.fitmodel=Fitter::bjpsikst_novosibirsk;
    histsc = bjpsikst_2015.get_mass_v_vars(ds, "novosibirsk");
  }
  TFile* g = TFile::Open((output+".root").c_str(), "RECREATE");
  if (hists)  hists->Write();
  if (histsb) histsb->Write();
  if (histsc) histsc->Write();
  g->Close();
  return 0;
}
