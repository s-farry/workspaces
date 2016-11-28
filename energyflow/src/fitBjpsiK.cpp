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
  bjpsik_2015.location = "/user2/sfarry/workspaces/energyflow/figs";

  string input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/Jpsi.2015.root";
  string output = "/user2/sfarry/workspaces/energyflow/tuples/output.root";

  if (argc > 1){
    input = argv[1];
  }
  if (argc > 2){
    output = argv[2];
    bjpsik_2015.location = "figs/"+output;
    output = "/user2/sfarry/workspaces/energyflow/tuples/"+output;
  }
  
  

  TFile* f = TFile::Open(input.c_str(), "READ");
  RooDataSet* ds   = (RooDataSet*)f->Get("ds");
  TObjArray *hists = 0, *histsb = 0, *histsc = 0;
  if ( ds) {
    hists = bjpsik_2015.get_mass_v_vars(ds);
    bjpsik_2015.fitmodel=Fitter::bjpsik_polynomial;
    histsb = bjpsik_2015.get_mass_v_vars(ds, "polynomial");
    bjpsik_2015.fitmodel=Fitter::bjpsik_novosibirsk;
    histsc = bjpsik_2015.get_mass_v_vars(ds, "novosibirsk");

  }
  TFile* g = TFile::Open((output+".root").c_str(), "RECREATE");
  if (hists)hists->Write();
  if (histsb) histsb->Write();
  if (histsc) histsc->Write();
  g->Close();
  return 0;
}
