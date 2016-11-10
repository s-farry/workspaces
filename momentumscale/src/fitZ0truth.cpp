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

std::pair<double, double> fit_mass(RooDataSet* ds, string oFile, string cut, string massvar = "Z_M"){
  RooRealVar m( massvar.c_str(), massvar.c_str(), 60., 120. );
  RooPlot* plot = m.frame();

  // Breit Wigner - Z Lineshape
  RooRealVar m0( "m0", "m0", 0 );
  RooRealVar width( "width", "width", 1.5, 0, 5 );
  RooBreitWigner bw( "gauss", "gauss", m, m0, width );

  // Crystal-Ball - Detector response + FSR
  RooRealVar mean( "mean", "mean", 90.3, 70, 110 );
  RooRealVar sigma( "sigma", "sigma", 0.5, 0, 5);
  RooRealVar alpha( "alpha", "alpha", 2.2, 0.01, 5 );
  RooRealVar n( "n", "n", 1, 0.01, 80 );
  RooCBShape cb( "cb", "cb", m, mean, sigma, alpha, n );

  //exponential - DY component + background
  RooRealVar lambda("lambda", "slope", -2e-2, -30., 0.);
  RooExponential expo("expo", "exponential PDF", m, lambda);


  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 50.5);
  m.setMax("cache", 129.5);

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

  // return as pair with value and error of mean
  std::pair<double, double> a(mean.getVal(), mean.getError());
  return a;

}


TObjArray* get_mass_v_vars(RooDataSet* ds){
  //mass variable
  RooRealVar m( "Z_M", "Z_M", 60., 120. );
  //other variables needed to make dataset
  int nvars = 4;
  string vars[] = { "mup_eta", "mum_eta", "mup_phi", "mum_phi"};
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
    vector<RooDataSet*> datasets   ;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream cut;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      cut  <<var<<">"<<binlo<<" && "<<var<<"<"<<binhi;
      //add dataset with specific cuts
      datasets.push_back((RooDataSet*)ds->reduce(cut.str().c_str()));
      
    }
    //make mass histogram
    TH1F* hist   = new TH1F(("mass_v_"+var+"_truth").c_str()   , ("mass_v_"+var+"_truth").c_str()   , bins, lo, hi);
    //calculate latex version of variable if possible
    string latexvar;
    if (var.find("eta") != std::string::npos) latexvar = "#eta";
    else if (var.find("phi") != std::string::npos ) latexvar = "#phi";
    else latexvar = var;
    for (int i = 0 ; i < bins ; ++i) {
      ostringstream s1;
      s1<<var<<"_truth_"<<i;
      double binlo = lo + i*((hi - lo)/bins);
      double binhi = lo + (i+1)*((hi-lo)/bins);
      //cut to be presented on plot
      ostringstream label;
      label<<binlo<<" < "<<latexvar<<" < "<<binhi;
      std::pair<double, double> result = fit_mass(datasets.at(i), s1.str(), label.str());
      hist->SetBinContent(i+1, result.first);
      hist->SetBinError(i+1, result.second);
    }
    
    TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
    hist->SetXTitle(latexvar.c_str());
    hist->SetYTitle("Fitted Z0 Mass");
    hist->Draw("e1");
    canv->SaveAs(("mass_v_"+var+"_truth.pdf").c_str());

    hists->Add(hist);
  }

  return hists;

}


TObjArray* get_mass_v_vars(TTree* t){

  TCut cut("mum_pt > 20 && mup_pt > 20 && mup_eta > 2.0 && mup_eta < 4.5 && mum_eta > 2.0 && mum_eta < 4.5 && Z_M > 60 && Z_M < 120");

  //mass variable
  RooRealVar m( "Z_M", "Z_M", 60., 120. );
  //other variables needed to make dataset
  RooRealVar pt1 ("mup_pt"  , "mup_pt"   , 20, 1000000);
  RooRealVar pt2 ("mum_pt"  , "mum_pt"  , 20, 1000000);
  RooRealVar eta1("mup_eta" , "mup_eta"  , 2, 4.5);
  RooRealVar eta2("mum_eta" , "mum_eta" , 2, 4.5);
  RooRealVar phi1("mup_phi" , "mup_phi"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("mum_phi" , "mum_phi" , -TMath::Pi(), TMath::Pi());

  RooDataSet* ds  = new RooDataSet("ds", "ds", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*t), RooFit::Cut(cut.GetTitle()));
  TObjArray* hists = get_mass_v_vars(ds);
  return hists;

}

int main(int argc, char* argv[]){
  if (argc != 3 && argc != 1) return 0;

  TH1::AddDirectory(false);
  gROOT->ProcessLine(".x /user2/sfarry/WJet/root/lhcbStyle.C");

  if (argc == 1){
    TFile* file0 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/zmumu.pythia.root");
    TTree* t = (TTree*)file0->Get("Zjet");
    TObjArray* hists = get_mass_v_vars(t);
    TFile* f = new TFile("output.root","RECREATE");
    hists->Write();
    f->Close();

  }
  else if (argc == 3){
    char* input = argv[1];
    char* output = argv[2];
    TFile* f = TFile::Open(input, "READ");
    TTree* t = (TTree*)f->Get("Zjet");
  
    TObjArray *hists = 0;
    if ( t ) {
      hists = get_mass_v_vars(t);
    }
    if (hists){
      TFile* g = TFile::Open(output, "RECREATE");
      hists->Write();
      g->Close();
    }
  }
  return 0;
}
