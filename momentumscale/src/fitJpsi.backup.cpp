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


using namespace std;
using namespace RooFit;

std::pair<double, double> fit_mass(RooDataSet* ds, string oFile, string cut, string massvar = "J_psi_1S_M"){
  RooRealVar m( massvar.c_str(), massvar.c_str(), 3040., 3140. );
  RooPlot* plot = m.frame();

  // Gaussian
  RooRealVar m0( "m0", "m0", 0 );
  RooRealVar width( "width", "width", 5, 0, 5000 );
  RooGaussian gauss( "gauss", "gauss", m, m0, width );

  // Crystal-Ball
  RooRealVar mean( "mean", "mean", 3096, 2700, 3300 );
  RooRealVar sigma( "sigma", "sigma", 17, 0, 1000);
  RooRealVar alpha( "alpha", "alpha", 1.4, 0.01, 5 );
  RooRealVar n( "n", "n", 6, 0.01, 80 );
  RooCBShape cb( "cb", "cb", m, mean, sigma, alpha, n );

  //exponential - combinatorics + background
  RooRealVar lambda("lambda", "slope", -2e-2, -30., 10.);
  RooExponential expo("expo", "exponential PDF", m, lambda);

  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 2500);
  m.setMax("cache", 3500);

  RooFFTConvPdf pdf( "pdf", "pdf", m, cb, gauss );

  //Background fraction
  RooRealVar b("b", "background", 0.8, 0, 1);

  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(pdf, expo), RooArgList(b));

  sum.fitTo(*ds, "qr");


  //Make mass plot
  TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
  plot -> GetXaxis() -> SetTitle( "M_{#mu#mu} [GeV]" );
  plot -> GetYaxis() -> SetTitleOffset( 1.5 );
  ds->plotOn( plot );
  sum.plotOn(plot);

  //print chi2 on plot and add tpavetext
  ostringstream sstream;
  sstream<<"#chi^{2}/nDoF = "<<plot->chiSquare();
  TPaveText* p = new TPaveText(0.15, 0.7, 0.5, 0.9, "NDC");
  p->SetFillStyle(0);
  p->SetBorderSize(0.0);
  plot->addObject(p);
  p->AddText(cut.c_str());
  p->AddText(sstream.str().c_str());
  plot->Draw();
  p->Draw();
  canv->SaveAs( ("jpsi_M_"+oFile+".pdf").c_str() );

  // return as pair with value and error of mean
  std::pair<double, double> a(mean.getVal(), mean.getError());
  return a;

}


TObjArray* get_mass_v_vars(RooDataSet* ds){
  //mass variable
  RooRealVar m( "J_psi_1S_M", "J_psi_1S_M", 3040.0, 3140. );
  //other variables needed to make dataset
  RooRealVar eta1("muplus_ETA" , "muplus_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_ETA", "muminus_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_PHI" , "muplus_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_PHI", "muminus_PHI" , -TMath::Pi(), TMath::Pi());

  int nvars = 2;
  //string vars[] = {"muplus_ETA", "muminus_ETA", "muplus_PHI", "muminus_PHI"};
  //double los[]  = {2.0, 2.0, -TMath::Pi(), -TMath::Pi()};
  //double his[]  = {4.5, 4.5, TMath::Pi(), TMath::Pi()};
  //int binss[]   = {10, 10, 10, 10};
  string vars[] = {"muplus_PHI", "muminus_PHI"};
  double los[]  = {-TMath::Pi(), -TMath::Pi()};
  double his[]  = { TMath::Pi(), TMath::Pi()};
  int binss[]   = { 10, 10};


  TObjArray* hists = new TObjArray();


  cout<<"got the dataset"<<endl;
  for (int i = 0 ; i < nvars ; ++i){
    string var = vars[i];
    double lo  = los[i];
    double hi  = his[i];
    int bins   = binss[i];
    cout<<"got all vars "<<i<<endl;
    vector<RooDataSet*> datasets;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream fine_cut;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      fine_cut<<var<<">"<<binlo<<" && "<<var<<"<"<<binhi;
      //add dataset with specific cuts
      datasets.push_back((RooDataSet*)ds->reduce(fine_cut.str().c_str()));
      
    }
    //make mass histogram
    TH1F* hist = new TH1F(("mass_v_"+var).c_str(), ("mass_v_"+var).c_str(), bins, lo, hi);
    //calculate latex version of variable if possible
    string latexvar;
    if (var.find("ETA") != std::string::npos) latexvar = "#eta";
    else if (var.find("PHI") != std::string::npos ) latexvar = "#phi";
    else latexvar = var;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream s;
      s<<var<<"_"<<i;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      //cut to be presented on plot
      ostringstream display_cut;
      display_cut<<binlo<<" < "<<latexvar<<" < "<<binhi;
      std::pair<double, double> result = fit_mass(datasets.at(i), s.str(), display_cut.str());
      hist->SetBinContent(i+1, result.first);
      hist->SetBinError(i+1, result.second);
      
    }
    
    TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
    hist->SetXTitle(latexvar.c_str());
    hist->SetYTitle("Fitted Jpsi Mass");
    hist->Draw("e1");
    canv->SaveAs(("jpsi_mass_v_"+var+".pdf").c_str());
    hists->Add(hist);
  }
  return hists;
}

TObjArray* get_mass_v_vars(TTree* t){
  //mass variable
  RooRealVar m( "J_psi_1S_M", "J_psi_1S_M", 3040.0, 3140. );
  //other variables needed to make dataset
  RooRealVar pt1("muplus_PT"   , "muplus_PT"   , 0, 1000000);
  RooRealVar pt2("muminus_PT"  , "muminus_PT"  , 0, 1000000);
  RooRealVar eta1("muplus_ETA" , "muplus_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_ETA", "muminus_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_PHI" , "muplus_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_PHI", "muminus_PHI" , -TMath::Pi(), TMath::Pi());
  RooRealVar run("runNumber", "runNumber", 0, 200000);

  RooDataSet* ds = new RooDataSet("ds", "ds", RooArgSet(m, phi1, phi2), RooFit::Import(*t), RooFit::Cut("runNumber < 163000"));

  return get_mass_v_vars(ds);

  

}
TObjArray* get_refit_mass_v_vars(RooDataSet* ds){
  RooRealVar m( "Z0_Refit_M", "Z0_Refit_M", 60000., 120000. );

  RooRealVar eta1("muplus_Refit_ETA" , "muplus_Refit_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_Refit_ETA", "muminus_Refit_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_Refit_PHI" , "muplus_Refit_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_Refit_PHI", "muminus_Refit_PHI" , -TMath::Pi(), TMath::Pi());

  int nvars = 4;
  string vars[] = {"muplus_Refit_ETA", "muminus_Refit_ETA", "muplus_Refit_PHI", "muminus_Refit_PHI"};
  double los[]  = {2.0, 2.0, -TMath::Pi(), -TMath::Pi()};
  double his[]  = {4.5, 4.5, TMath::Pi(), TMath::Pi()};
  int binss[]   = {10, 10, 10, 10};

  TObjArray* hists = new TObjArray();

  cout<<"got the dataset"<<endl;

  for (int i = 0 ; i < nvars ; ++i){
    string var = vars[i];
    double lo  = los[i];
    double hi  = his[i];
    int bins   = binss[i];
    vector<RooDataSet*> datasets;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream name, fine_cut;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      fine_cut<<var<<">"<<binlo<<" && "<<var<<"<"<<binhi;
      datasets.push_back((RooDataSet*)ds->reduce(fine_cut.str().c_str()));
      
    }
    TH1F* hist = new TH1F(("mass_v_"+var).c_str(), ("mass_v_"+var).c_str(), bins, lo, hi);
    string latexvar;
    if (var.find("ETA") != std::string::npos) latexvar = "#eta";
    else if (var.find("PHI") != std::string::npos ) latexvar = "#phi";
    else latexvar = var;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream s;
      s<<var<<"_Refit_"<<i;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      ostringstream display_cut;
      display_cut<<binlo<<" < "<<latexvar<<" < "<<binhi;
      std::pair<double, double> result = fit_mass(datasets.at(i), s.str(), display_cut.str(), "J_psi_1S_Refit_M");
      hist->SetBinContent(i+1, result.first);
      hist->SetBinError(i+1, result.second);
      

    }
    
    TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
    hist->SetXTitle(latexvar.c_str());
    hist->SetYTitle("Fitted Z0 Mass");
    hist->Draw("e1");
    canv->SaveAs(("mass_v_"+var+"_refit.pdf").c_str());
    hists->Add(hist);
  }

  return hists;

}

TObjArray* get_refit_mass_v_vars(TTree* t){

  //As previous function with refit
  //should be merged

  TCut cut("muminus_Refit_PT > 20000 && muplus_Refit_PT > 20000 && muplus_Refit_ETA > 2.0 && muplus_Refit_ETA < 4.5 && muminus_Refit_ETA > 2.0 && muminus_Refit_ETA < 4.5 && Z0_Refit_M > 60000 && Z0_Refit_M < 120000");

  RooRealVar m( "Z0_Refit_M", "Z0_Refit_M", 60000., 120000. );

  RooRealVar pt1("muplus_Refit_PT"   , "muplus_Refit_PT"   , 20000, 1000000);
  RooRealVar pt2("muminus_Refit_PT"  , "muminus_Refit_PT"  , 20000, 1000000);
  RooRealVar eta1("muplus_Refit_ETA" , "muplus_Refit_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_Refit_ETA", "muminus_Refit_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_Refit_PHI" , "muplus_Refit_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_Refit_PHI", "muminus_Refit_PHI" , -TMath::Pi(), TMath::Pi());

  RooDataSet* ds = new RooDataSet("ds", "ds", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*t), RooFit::Cut(cut.GetTitle()));
  return get_refit_mass_v_vars(ds);

}

int main(int argc, char* argv[]){
  if (argc != 3 && argc != 1) {
    cout<<"check arguments"<<endl;
    return 0;
  }
  
  gROOT->ProcessLine(".x /user2/sfarry/WJet/root/lhcbStyle.C");

  if (argc == 1){
    TFile* file0 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/Jpsi.2015.root");
    TTree* t = (TTree*)file0->Get("JpsiTuple/DecayTree");
    cout<<"got tree"<<endl;
    TObjArray* hists = get_mass_v_vars(t);
    cout<<"got standard hists"<<endl;
    TObjArray* refit_hists = get_refit_mass_v_vars(t);
    cout<<"got refit hists"<<endl;
    TFile* f = new TFile("jpsi_test.root","RECREATE");
    hists->Write();
    refit_hists->Write();
    f->Close();

  }
  else if (argc == 3){
    char* input = argv[1];
    char* output = argv[2];
    TFile* f = TFile::Open(input, "READ");
    TTree* t = (TTree*)f->Get("JpsiTuple/DecayTree");
    RooDataSet* ds = (RooDataSet*)f->Get("ds");
    RooDataSet* ds2 = (RooDataSet*)f->Get("ds2");
    TObjArray *hists, *refit_hists;
    if (ds && ds2){
      hists = get_mass_v_vars(ds);
      refit_hists = get_refit_mass_v_vars(ds2);
    }
    else{
      hists = get_mass_v_vars(t);
      refit_hists = get_refit_mass_v_vars(t);
    }
    TFile* g = TFile::Open(output, "RECREATE");
    hists->Write();
    refit_hists->Write();
    g->Close();
    return 0;
  }

}
