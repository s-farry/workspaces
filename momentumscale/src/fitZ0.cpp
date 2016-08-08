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

#include "Fitter.h"

using namespace std;
using namespace RooFit;
/*
vector<std::pair<double, double> > fit_mass(RooDataSet* ds, string oFile, string cut, string massvar = "Z0_M"){
  RooRealVar m( massvar.c_str(), massvar.c_str(), 60000., 120000. );
  RooPlot* plot = m.frame();

  // Breit Wigner - Z Lineshape
  RooRealVar m0( "m0", "m0", 0 );
  RooRealVar width( "width", "width", 1500, 0, 5000 );
  RooBreitWigner bw( "gauss", "gauss", m, m0, width );

  // Crystal-Ball - Detector response + FSR
  RooRealVar mean( "mean", "mean", 90300, 70000, 110000 );
  RooRealVar sigma( "sigma", "sigma", 500, 0, 5000);
  RooRealVar alpha( "alpha", "alpha", 2.2, 0.01, 5 );
  RooRealVar n( "n", "n", 0.48, 0.01, 80 );
  RooCBShape cb( "cb", "cb", m, mean, sigma, alpha, n );

  //exponential - DY component + background
  RooRealVar lambda("lambda", "slope", -2e-5, -30., 0.);
  RooExponential expo("expo", "exponential PDF", m, lambda);


  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 50500);
  m.setMax("cache", 129500);

  //convolve PDFs
  RooFFTConvPdf pdf( "pdf", "pdf", m, cb, bw );

  //Background fraction
  RooRealVar b("b", "background", 0.7, 0, 1);

  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(pdf, expo), RooArgList(b));

  //sum.fitTo(*ds, RooFit::Extended());
  sum.fitTo(*ds);

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
  canv->SaveAs( ("BWxCB_"+oFile+".pdf").c_str() );

  std::vector< std::pair<double, double> > parms;
  // return as pair with value and error of mean
  parms.push_back(std::pair<double, double>(mean.getVal()  , mean.getError()));
  parms.push_back(std::pair<double, double>(sigma.getVal() , sigma.getError()));
  return parms;

}


TObjArray* get_mass_v_vars(RooDataSet* dsUp, RooDataSet* dsDown){
  //mass variable
  RooRealVar m( "Z0_M", "Z0_M", 60000., 120000. );
  //other variables needed to make dataset
  int nvars = 4;
  string vars[] = { "muplus_ETA", "muminus_ETA", "muplus_PHI", "muminus_PHI"};
  double los[]  = { 2.0, 2.0, -TMath::Pi(), -TMath::Pi() };
  double his[]  = { 4.5, 4.5, TMath::Pi(), TMath::Pi()   };
  int binss[]   = { 10, 10, 10, 10 };

  TObjArray* hists = new TObjArray();

  //fit_mass(ds, "", "");

  for (int i = 0 ; i < nvars ; ++i){
    string var = vars[i] ;
    double lo  = los[i]  ;
    double hi  = his[i]  ;
    int bins   = binss[i];
    vector<RooDataSet*> magup_datasets   ;
    vector<RooDataSet*> magdown_datasets ;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream cutup, cutdown;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      cutup  <<var<<">"<<binlo<<" && "<<var<<"<"<<binhi;
      //add dataset with specific cuts
      magup_datasets.push_back((RooDataSet*)dsUp->reduce(cutup.str().c_str()));
      magdown_datasets.push_back((RooDataSet*)dsDown->reduce(cutup.str().c_str()));
      
    }
    //make mass histogram
    TH1F* magup_hist   = new TH1F(("mass_v_"+var+"_magup").c_str()   , ("mass_v_"+var+"_magup").c_str()   , bins, lo, hi);
    TH1F* magdown_hist = new TH1F(("mass_v_"+var+"_magdown").c_str() , ("mass_v_"+var+"_magdown").c_str() , bins, lo, hi);
    TH1F* magup_width   = new TH1F(("width_v_"+var+"_magup").c_str()   , ("width_v_"+var+"_magup").c_str()   , bins, lo, hi);
    TH1F* magdown_width = new TH1F(("width_v_"+var+"_magdown").c_str() , ("width_v_"+var+"_magdown").c_str() , bins, lo, hi);
    //calculate latex version of variable if possible
    string latexvar;
    if (var.find("ETA") != std::string::npos) latexvar = "#eta";
    else if (var.find("PHI") != std::string::npos ) latexvar = "#phi";
    else latexvar = var;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream s1, s2;
      s1<<var<<"_magup_"<<i;
      s2<<var<<"_magdown_"<<i;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      //cut to be presented on plot
      ostringstream label;
      label<<binlo<<" < "<<latexvar<<" < "<<binhi;
      std::vector<std::pair<double, double> > magup_result = fit_mass(magup_datasets.at(i), s1.str(), label.str());
      std::vector<std::pair<double, double> > magdown_result = fit_mass(magdown_datasets.at(i), s2.str(), label.str());
      magup_hist->SetBinContent(i+1, magup_result.at(0).first);
      magup_hist->SetBinError(i+1, magup_result.at(0).second);
      magdown_hist->SetBinContent(i+1, magdown_result.at(0).first);
      magdown_hist->SetBinError(i+1, magdown_result.at(0).second);

      magup_width->SetBinContent(i+1, magup_result.at(1).first);
      magup_width->SetBinError(i+1, magup_result.at(1).second);
      magdown_width->SetBinContent(i+1, magdown_result.at(1).first);
      magdown_width->SetBinError(i+1, magdown_result.at(1).second);
      
    }
    
    TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
    magup_hist->SetXTitle(latexvar.c_str());
    magup_hist->SetYTitle("Fitted Z0 Mass");
    magdown_hist->SetMarkerColor(2);
    magdown_hist->SetMarkerStyle(2);
    magup_hist->Draw("e1");
    magdown_hist->Draw("e1same");
    canv->SaveAs(("mass_v_"+var+".pdf").c_str());

    hists->Add(magup_hist);
    hists->Add(magdown_hist);

    hists->Add(magup_width);
    hists->Add(magdown_width);
  }


  return hists;

}


TObjArray* get_mass_v_vars(TTree* t){

  TCut cut("muminus_PT > 20000 && muplus_PT > 20000 && muplus_ETA > 2.0 && muplus_ETA < 4.5 && muminus_ETA > 2.0 && muminus_ETA < 4.5 && Z0_M > 60000 && Z0_M < 120000");

  //mass variable
  RooRealVar m( "Z0_M", "Z0_M", 60000., 120000. );
  //other variables needed to make dataset
  RooRealVar pt1("muplus_PT"   , "muplus_PT"   , 20000, 1000000);
  RooRealVar pt2("muminus_PT"  , "muminus_PT"  , 20000, 1000000);
  RooRealVar eta1("muplus_ETA" , "muplus_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_ETA", "muminus_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_PHI" , "muplus_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_PHI", "muminus_PHI" , -TMath::Pi(), TMath::Pi());
  RooRealVar polarity("Polarity", "Polarity", -2, 2);

  TFile f("temp.root","RECREATE");
  TTree* upTree   = (TTree*)t->CopyTree("Polarity > 0");
  TTree* downTree = (TTree*)t->CopyTree("Polarity < 0");

  

  cout<<"Number of entries in trees: "<<t->GetEntries()<<" "<<upTree->GetEntries()<<" "<<downTree->GetEntries()<<endl;

  RooDataSet* dsUp  = new RooDataSet("dsUp", "dsUp", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*upTree), RooFit::Cut(cut.GetTitle()));
  RooDataSet* dsDwn = new RooDataSet("dsDwn", "dsDwn", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*downTree), RooFit::Cut(cut.GetTitle()));
  cout<<"Number of entries in datasets: "<<dsUp->sumEntries()<<" "<<dsDwn->sumEntries()<<endl;
  TObjArray* hists = get_mass_v_vars(dsUp, dsDwn);
  return hists;

}
TObjArray* get_mass_v_vars(TTree* t, TTree* u){

  TCut cut("muminus_PT > 20000 && muplus_PT > 20000 && muplus_ETA > 2.0 && muplus_ETA < 4.5 && muminus_ETA > 2.0 && muminus_ETA < 4.5 && Z0_M > 60000 && Z0_M < 120000");

  //mass variable
  RooRealVar m( "Z0_M", "Z0_M", 60000., 120000. );
  //other variables needed to make dataset
  RooRealVar pt1("muplus_PT"   , "muplus_PT"   , 20000, 1000000);
  RooRealVar pt2("muminus_PT"  , "muminus_PT"  , 20000, 1000000);
  RooRealVar eta1("muplus_ETA" , "muplus_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_ETA", "muminus_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_PHI" , "muplus_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_PHI", "muminus_PHI" , -TMath::Pi(), TMath::Pi());
  RooRealVar polarity("Polarity", "Polarity", -2, 2);

  RooDataSet* dsUp  = new RooDataSet("dsUp", "dsUp", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*t), RooFit::Cut(cut.GetTitle()));
  RooDataSet* dsDwn = new RooDataSet("dsDwn", "dsDwn", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*u), RooFit::Cut(cut.GetTitle()));
  cout<<"Number of entries in datasets: "<<dsUp->sumEntries()<<" "<<dsDwn->sumEntries()<<endl;
  TObjArray* hists = get_mass_v_vars(dsUp, dsDwn);
  return hists;

}
TObjArray* get_refit_mass_v_vars(RooDataSet* dsUp, RooDataSet* dsDown){

  //As previous function with refit
  //should be merged
  RooRealVar m( "Z0_Refit_M", "Z0_Refit_M", 60000., 120000. );
  RooRealVar eta1("muplus_Refit_ETA" , "muplus_Refit_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_Refit_ETA", "muminus_Refit_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_Refit_PHI" , "muplus_Refit_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_Refit_PHI", "muminus_Refit_PHI" , -TMath::Pi(), TMath::Pi());

  int nvars = 4;
  string vars[] = {"muplus_Refit_ETA", "muminus_Refit_ETA", "muplus_Refit_PHI", "muminus_Refit_PHI"};
  double los[] = {2.0, 2.0, -TMath::Pi(), -TMath::Pi()};
  double his[] = {4.5, 4.5, TMath::Pi(), TMath::Pi()};
  int binss[] = {10, 10, 10, 10};

  TObjArray* hists = new TObjArray();

  for (int i = 0 ; i < nvars ; ++i){
    string var = vars[i];
    double lo  = los[i];
    double hi  = his[i];
    int bins   = binss[i];
    vector<RooDataSet*> magup_datasets;
    vector<RooDataSet*> magdown_datasets;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream cutup, cutdown;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      cutup  <<var<<">"<<binlo<<" && "<<var<<"<"<<binhi ;
      cutdown<<var<<">"<<binlo<<" && "<<var<<"<"<<binhi;
      //add dataset with specific cuts
      magup_datasets.push_back((RooDataSet*)dsUp->reduce(cutup.str().c_str()));
      magdown_datasets.push_back((RooDataSet*)dsDown->reduce(cutdown.str().c_str()));
      
    }

    TH1F* magup_hist   = new TH1F(("mass_v_"+var+"_refit_magup").c_str()  , ("mass_v_"+var+"_refit_magup").c_str(), bins, lo, hi);
    TH1F* magdown_hist = new TH1F(("mass_v_"+var+"_refit_magdown").c_str(), ("mass_v_"+var+"_refit_magdown").c_str(), bins, lo, hi);

    TH1F* magup_width   = new TH1F(("width_v_"+var+"_refit_magup").c_str()   , ("width_v_"+var+"_refit_magup").c_str()   , bins, lo, hi);
    TH1F* magdown_width = new TH1F(("width_v_"+var+"_refit_magdown").c_str() , ("width_v_"+var+"_refit_magdown").c_str() , bins, lo, hi);

    string latexvar;
    if (var.find("ETA") != std::string::npos) latexvar = "#eta";
    else if (var.find("PHI") != std::string::npos ) latexvar = "#phi";
    else latexvar = var;
    for (int i = 0 ; i < bins ; ++i) {

      ostringstream s1, s2;
      s1<<var<<"_refit_magup_"<<i;
      s2<<var<<"_refit_magdown_"<<i;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      //cut to be presented on plot
      ostringstream label;
      label<<binlo<<" < "<<latexvar<<" < "<<binhi;
      std::vector< std::pair<double, double> > magup_result = fit_mass(magup_datasets.at(i), s1.str(), label.str(), "Z0_Refit_M");
      std::vector< std::pair<double, double> > magdown_result = fit_mass(magdown_datasets.at(i), s1.str(), label.str(), "Z0_Refit_M");
      magup_hist->SetBinContent   (i+1, magup_result.at(0).first);
      magup_hist->SetBinError     (i+1, magup_result.at(0).second);
      magdown_hist->SetBinContent (i+1, magdown_result.at(0).first);
      magdown_hist->SetBinError   (i+1, magdown_result.at(0).second);

      magup_width->SetBinContent  (i+1, magup_result.at(1).first);
      magup_width->SetBinError    (i+1, magup_result.at(1).second);
      magdown_width->SetBinContent(i+1, magdown_result.at(1).first);
      magdown_width->SetBinError  (i+1, magdown_result.at(1).second);

    }
    
    TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
    magup_hist->SetXTitle(latexvar.c_str());
    magup_hist->SetYTitle("Fitted Z0 Mass");
    magdown_hist->SetLineColor(2);
    magdown_hist->SetMarkerColor(2);
    magdown_hist->SetMarkerStyle(20);
    magup_hist->Draw("e1");
    magdown_hist->Draw("e1same");
    canv->SaveAs(("mass_v_"+var+"_refit.pdf").c_str());
    hists->Add(magup_hist);
    hists->Add(magdown_hist);
    hists->Add(magup_width);
    hists->Add(magdown_width);
  }

  return hists;

}



TObjArray* get_refit_mass_v_vars(TTree* t){

  // As previous function with refit
  // should be merged

  TCut cut("muminus_Refit_PT > 20000 && muplus_Refit_PT > 20000 && muplus_Refit_ETA > 2.0 && muplus_Refit_ETA < 4.5 && muminus_Refit_ETA > 2.0 && muminus_Refit_ETA < 4.5 && Z0_Refit_M > 60000 && Z0_Refit_M < 120000");

  RooRealVar m( "Z0_Refit_M", "Z0_Refit_M", 60000., 120000. );

  RooRealVar pt1("muplus_Refit_PT"   , "muplus_Refit_PT"   , 20000, 1000000);
  RooRealVar pt2("muminus_Refit_PT"  , "muminus_Refit_PT"  , 20000, 1000000);
  RooRealVar eta1("muplus_Refit_ETA" , "muplus_Refit_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_Refit_ETA", "muminus_Refit_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_Refit_PHI" , "muplus_Refit_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_Refit_PHI", "muminus_Refit_PHI" , -TMath::Pi(), TMath::Pi());
  RooRealVar polarity("Polarity", "Polarity", -2, 2);

  TFile* g = new TFile("temp.root", "RECREATE");
  TTree* upTree  = (TTree*)t->CopyTree("Polarity > 0");
  TTree* dwnTree = (TTree*)t->CopyTree("Polarity < 0");


  RooDataSet* dsUp = new RooDataSet("dsUp", "dsUp", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2, polarity), RooFit::Import(*upTree), RooFit::Cut(cut.GetTitle()));
  RooDataSet* dsDwn = new RooDataSet("dsDwn", "dsDwn", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2, polarity), RooFit::Import(*dwnTree), RooFit::Cut(cut.GetTitle()));


  return get_refit_mass_v_vars(dsUp, dsDwn);
}

TObjArray* get_refit_mass_v_vars(TTree* t, TTree* u){

  // As previous function with refit
  // should be merged

  TCut cut("muminus_Refit_PT > 20000 && muplus_Refit_PT > 20000 && muplus_Refit_ETA > 2.0 && muplus_Refit_ETA < 4.5 && muminus_Refit_ETA > 2.0 && muminus_Refit_ETA < 4.5 && Z0_Refit_M > 60000 && Z0_Refit_M < 120000");

  RooRealVar m( "Z0_Refit_M", "Z0_Refit_M", 60000., 120000. );

  RooRealVar pt1("muplus_Refit_PT"   , "muplus_Refit_PT"   , 20000, 1000000);
  RooRealVar pt2("muminus_Refit_PT"  , "muminus_Refit_PT"  , 20000, 1000000);
  RooRealVar eta1("muplus_Refit_ETA" , "muplus_Refit_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_Refit_ETA", "muminus_Refit_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_Refit_PHI" , "muplus_Refit_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_Refit_PHI", "muminus_Refit_PHI" , -TMath::Pi(), TMath::Pi());
  RooRealVar polarity("Polarity", "Polarity", -2, 2);

  RooDataSet* dsUp = new RooDataSet("dsUp", "dsUp", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2, polarity), RooFit::Import(*t), RooFit::Cut(cut.GetTitle()));
  RooDataSet* dsDwn = new RooDataSet("dsDwn", "dsDwn", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2, polarity), RooFit::Import(*u), RooFit::Cut(cut.GetTitle()));

  return get_refit_mass_v_vars(dsUp, dsDwn);
}

int main(int argc, char* argv[]){
  if (argc != 3 && argc != 1 && argc != 4) return 0;
  



  TH1::AddDirectory(false);
  gROOT->ProcessLine(".x /user2/sfarry/WJet/root/lhcbStyle.C");

  if (argc == 1){
    TFile* file0 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/ZMuMu.Refit.2015.root");
    TTree* t = (TTree*)file0->Get("ZMuMu/DecayTree");
    TObjArray* hists = get_mass_v_vars(t);
    TObjArray* refit_hists = get_refit_mass_v_vars(t);
    TFile* f = new TFile("test.root","RECREATE");
    hists->Write();
    refit_hists->Write();
    f->Close();

  }
  else if (argc == 3){
    char* input = argv[1];
    char* output = argv[2];
    TFile* f = TFile::Open(input, "READ");
    RooDataSet* dsUp = (RooDataSet*)f->Get("dataup");
    RooDataSet* dsDown = (RooDataSet*)f->Get("datadown");
    TTree* t = (TTree*)f->Get("ZMuMu/DecayTree");
    TObjArray* branches = t->GetListOfBranches();
    bool has_refit = false;
    for (int i = 0 ; i < branches->GetEntries() ; ++i){
      TBranch* branch = (TBranch*)branches->At(i);
      string name = branch->GetName();
      //if (strncmp((name, "boson", 5) == 0){
      if (name.find("boson") == 0){
	std::string replace = name.replace(0, 5, "Z0");
	branch->SetNameTitle(replace.c_str(), replace.c_str());
      }
      if (name.find("Refit") != std::string::npos) has_refit = true;

    }
  
    TObjArray *hists = 0;
    TObjArray *refit_hists = 0;
    if ( dsUp && dsDown ) {
      hists = get_mass_v_vars(dsUp, dsDown);
      refit_hists = get_refit_mass_v_vars(dsUp, dsDown);
    }
    else if ( t ) {
      hists = get_mass_v_vars(t);
      if (has_refit) refit_hists = get_refit_mass_v_vars(t);
    }
    if (hists){
      TFile* g = TFile::Open(output, "RECREATE");
      hists->Write();
      if (refit_hists) refit_hists->Write();
      g->Close();
    }
  }
  else if (argc == 4){
    char* inputUp   = argv[1];
    char* inputDown = argv[2];
    char* output    = argv[3];
    TFile* f = TFile::Open(inputUp, "READ");
    TFile* g = TFile::Open(inputDown, "READ");
    TTree* t = (TTree*)f->Get("ZMuMu/DecayTree");
    TTree* u = (TTree*)g->Get("ZMuMu/DecayTree");

    cout<<t<<" "<<u<<endl;

    cout<<"okay so far"<<endl;

    TObjArray* branches = t->GetListOfBranches();
    cout<<"got list of branches"<<endl;
    bool has_refit = false;
    for (int i = 0 ; i < branches->GetEntries() ; ++i){
      TBranch* branch = (TBranch*)branches->At(i);
      string name = branch->GetName();
      //if (strncmp((name, "boson", 5) == 0){
      if (name.find("boson") == 0){
	std::string replace = name.replace(0, 5, "Z0");
	branch->SetNameTitle(replace.c_str(), replace.c_str());
      }
      if (name.find("Refit") != std::string::npos) has_refit = true;

    }
    branches = u->GetListOfBranches();
    for (int i = 0 ; i < branches->GetEntries() ; ++i){
      TBranch* branch = (TBranch*)branches->At(i);
      string name = branch->GetName();
      //if (strncmp((name, "boson", 5) == 0){
      if (name.find("boson") == 0){
	std::string replace = name.replace(0, 5, "Z0");
	branch->SetNameTitle(replace.c_str(), replace.c_str());
      }
      if (name.find("Refit") != std::string::npos) has_refit = true;

    }

    cout<<"renamed branches"<<endl;
  
    TObjArray *hists = 0;
    TObjArray *refit_hists = 0;
    if ( t && u ) {
      hists = get_mass_v_vars(t, u);
      if (has_refit) refit_hists = get_refit_mass_v_vars(t, u);
    }
    if (hists){
      TFile* g = TFile::Open(output, "RECREATE");
      hists->Write();
      if (refit_hists) refit_hists->Write();
      g->Close();
    }
  }
  return 0;
}
*/
int main(int argc, char* argv[]){
  if (argc != 3 && argc != 1 && argc != 4) return 0;
  

  TH1::AddDirectory(false);
  gROOT->ProcessLine(".x /user2/sfarry/Analyses/WJet/root/lhcbStyle.C");

  Fitter z0_2015;
  z0_2015.fitvar="Z0_M";
  z0_2015.fitmodel = Fitter::z0;
  z0_2015.lo = 60000.;
  z0_2015.hi = 120000;
  z0_2015.vars    = {"muplus_ETA", "muminus_ETA", "muplus_PHI", "muminus_PHI"};
  z0_2015.los     =  {2.0, 2.0, -TMath::Pi(), -TMath::Pi() };
  z0_2015.his     =  {4.5, 4.5,  TMath::Pi(),  TMath::Pi() };
  z0_2015.bins    = { 10, 10, 10, 10 };
  z0_2015.vars2d  = { {"muplus_ETA", "muplus_PHI"}, {"muminus_ETA", "muminus_PHI"} };
  z0_2015.los2d   =  { {2.0, -TMath::Pi()}, {2.0, -TMath::Pi()} };
  z0_2015.his2d   =  { {4.5,  TMath::Pi()}, {4.5,  TMath::Pi()} };
  z0_2015.bins2d  = { {5, 5}, {5, 5} };

  Fitter z0_2015_refit;
  z0_2015_refit.fitvar="Z0_Refit_M";
  z0_2015_refit.fitmodel = Fitter::z0;
  z0_2015_refit.lo = 60000.;
  z0_2015_refit.hi = 120000;
  z0_2015_refit.vars   = {"muplus_Refit_ETA", "muminus_Refit_ETA", "muplus_Refit_PHI", "muminus_Refit_PHI"};
  z0_2015_refit.los    = {2.0, 2.0, -TMath::Pi(), -TMath::Pi()};
  z0_2015_refit.his    = {4.5, 4.5,  TMath::Pi(),  TMath::Pi()};
  z0_2015_refit.bins   = {10, 10, 10, 10};
  z0_2015_refit.vars2d = { {"muplus_Refit_ETA", "muplus_Refit_PHI"}, {"muminus_Refit_ETA", "muminus_Refit_PHI"} };
  z0_2015_refit.los2d  = { {2.0, -TMath::Pi()}, {2.0, -TMath::Pi()} };
  z0_2015_refit.his2d  = { {4.5,  TMath::Pi()}, {4.5,  TMath::Pi()} };
  z0_2015_refit.bins2d = { {5, 5}, {5, 5} };

  string input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/ZMuMu.Refit.2015.root";
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
    hists = z0_2015.get_mass_v_vars(dsUp, dsDown);
    refit_hists = z0_2015_refit.get_mass_v_vars(dsUp_Refit, dsDown_Refit);
  }
  if (hists){
    TFile* g = TFile::Open(output.c_str(), "RECREATE");
    hists->Write();
    if (refit_hists) refit_hists->Write();
    g->Close();
  }
  
  return 0;
}
