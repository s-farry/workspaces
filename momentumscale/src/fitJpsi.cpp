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

  Fitter jpsi_2015;
  jpsi_2015.fitvar="J_psi_1S_M";
  jpsi_2015.fitmodel = Fitter::jpsi;
  jpsi_2015.lo = 3020.;
  jpsi_2015.hi = 3160;
  //jpsi_2015.vars    = {"muplus_ETA", "muminus_ETA", "muplus_PHI", "muminus_PHI"};
  //jpsi_2015.los     =  {2.0, 2.0, -TMath::Pi(), -TMath::Pi() };
  //jpsi_2015.his     =  {4.5, 4.5,  TMath::Pi(),  TMath::Pi() };
  //jpsi_2015.bins    = { 20, 20, 20, 20 };
  //jpsi_2015.vars2d  = { {"muplus_ETA", "muplus_PHI"}, {"muminus_ETA", "muminus_PHI"} };
  //jpsi_2015.los2d   =  { {2.0, -TMath::Pi()}, {2.0, -TMath::Pi()} };
  //jpsi_2015.his2d   =  { {4.5,  TMath::Pi()}, {4.5,  TMath::Pi()} };
  //jpsi_2015.bins2d  = { {10, 10}, {10, 10} };
  
  Fitter jpsi_2015_refit;
  jpsi_2015_refit.fitvar="J_psi_1S_Refit_M";
  jpsi_2015_refit.fitmodel = Fitter::jpsi;
  jpsi_2015_refit.lo = 3020.;
  jpsi_2015_refit.hi = 3160;
  //jpsi_2015_refit.vars   = {"muplus_Refit_ETA", "muminus_Refit_ETA", "muplus_Refit_PHI", "muminus_Refit_PHI"};
  //jpsi_2015_refit.los    = {2.0, 2.0, -TMath::Pi(), -TMath::Pi()};
  //jpsi_2015_refit.his    = {4.5, 4.5,  TMath::Pi(),  TMath::Pi()};
  //jpsi_2015_refit.bins   = {20, 20, 20, 20};
  //jpsi_2015_refit.vars2d = { {"muplus_Refit_ETA", "muplus_Refit_PHI"}, {"muminus_Refit_ETA", "muminus_Refit_PHI"} };
  //jpsi_2015_refit.los2d  = { {2.0, -TMath::Pi()}, {2.0, -TMath::Pi()} };
  //jpsi_2015_refit.his2d  = { {4.5,  TMath::Pi()}, {4.5,  TMath::Pi()} };
  //jpsi_2015_refit.bins2d = { {10, 10}, {10, 10} };
  
  string input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/Jpsi.2015.root";
  string output = "output.root";

  if (argc > 1){
    input = argv[1];
  }
  if (argc > 2){
    output = argv[2];
  }
  
  TFile* f = TFile::Open(input.c_str(), "READ");
  RooDataSet* dsUp   = (RooDataSet*)f->Get("dsUp");
  RooDataSet* dsDown = (RooDataSet*)f->Get("dsDown");
  RooDataSet* dsUp_Refit   = (RooDataSet*)f->Get("dsUp_Refit");
  RooDataSet* dsDown_Refit = (RooDataSet*)f->Get("dsDown_Refit");
  TObjArray *hists = 0;
  TObjArray *refit_hists = 0;
  if ( dsUp && dsDown && dsUp_Refit && dsDown_Refit ) {
    hists = jpsi_2015.get_mass_v_vars(dsUp);
    refit_hists = jpsi_2015_refit.get_mass_v_vars(dsUp_Refit);
  }
  if (hists){
    TFile* g = TFile::Open(output.c_str(), "RECREATE");
    hists->Write();
    if (refit_hists) refit_hists->Write();
    g->Close();
  }
  return 0;
}
