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
#include "Fitter.h"

using namespace std;
using namespace RooFit;

int main(int argc, char* argv[]){
  if (argc != 3 && argc!= 2 && argc != 1 && argc != 4) return 0;
  

  TH1::AddDirectory(false);
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");

  Fitter eta_2016;
  eta_2016.fitvar="m2";
  eta_2016.fitmodel = Fitter::etagamma;
  eta_2016.binned = true;
  eta_2016.fitbins = 1000.0;
  eta_2016.vars    = {"gamma_pt", "gamma_eta"};
  eta_2016.los     =  {200, 2.0};
  eta_2016.his     =  {2000, 4.2};
  eta_2016.bins    = { 6, 9 };
  //eta_2016.vars    = {"gamma_pt"};
  //eta_2016.los     =  {0};
  //eta_2016.his     =  {2000};
  //eta_2016.bins    = { 5 };
  eta_2016.lo = 500.;
  eta_2016.hi = 600;
  //alter bin edges
  double pt_edges[] = {200, 240, 300, 400, 600 ,1000, 2000};
  double eta_edges[] = {2.0, 2.5, 3.0, 3.2, 3.45, 3.7, 3.85,4.0, 4.2, 5.0};
  eta_2016.edges[0] = pt_edges;
  eta_2016.edges[1] = eta_edges;
  eta_2016.vars2d   = {{"gamma_pt", "gamma_eta"}};
  eta_2016.los2d    = {{0, 2.0}};
  eta_2016.his2d    = {{2000, 5.0}};
  eta_2016.bins2d   = {{ 6 , 9 }};
  eta_2016.edges2d[0]  = {pt_edges, eta_edges};
  eta_2016.location = "/user2/sfarry/workspaces/energyflow/figs";

  string input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/Jpsi.2015.root";
  string output = "/user2/sfarry/workspaces/energyflow/tuples/output.root";

  if (argc > 1){
    input = argv[1];
  }
  if (argc > 2){
    output = argv[2];
    eta_2016.location = "/user2/sfarry/workspaces/energyflow/figs/"+output;
    output = "/user2/sfarry/workspaces/energyflow/tuples/"+output;
  }
  
  TFile* f = TFile::Open(input.c_str(), "READ");
  RooDataSet* ds  = (RooDataSet*)f->Get("ds2");
  RooDataSet* ds_reduced = (RooDataSet*)ds->reduce("gamma_p > 2000 && gamma_eta > 2.0 && gamma_eta < 5.0");
  TObjArray *hists = 0, *histsb = 0, *histsc = 0;
  if ( ds) {
    hists = eta_2016.get_mass_v_vars(ds_reduced, "");
    //eta_2016.fitmodel=Fitter::bjpsikst_polynomial;
    //histsb = eta_2016.get_mass_v_vars(ds, "polynomial");
    //eta_2016.fitmodel=Fitter::bjpsikst_novosibirsk;
    //histsc = eta_2016.get_mass_v_vars(ds, "novosibirsk");
  }
  TFile* g = TFile::Open((output+".root").c_str(), "RECREATE");
  if (hists)  hists->Write();
  //if (histsb) histsb->Write();
  //if (histsc) histsc->Write();
  g->Close();
  return 0;
}
