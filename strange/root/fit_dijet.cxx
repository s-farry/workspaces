#ifndef __CINT__
#include <iostream>
#include <sstream>
#include <iomanip>
#include <TTree.h>
#include <TCut.h>
#include <TMath.h>
#include <TObjArray.h>
#include <math.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TEntryList.h>
#include <TParameter.h>
#include <RooRealVar.h>
#include <RooArgSet.h>
#include <RooDataHist.h>
#include <RooHistPdf.h>
#include <RooAddPdf.h>
#include <RooPlot.h>

using namespace std;
using namespace RooFit;
#endif
void fit_dijet(){
  
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  
  TFile* f = new TFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015.root");
  TFile* g = new TFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_sig.root");
  TFile* h = new TFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_bkg.root");

  TH1F* data = (TH1F*)f->Get("BDT");

  TObjArray* toFit = new TObjArray();
  toFit->Add((TH1F*)g->Get("BDT"));
  toFit->Add((TH1F*)h->Get("BDT"));

  RooRealVar x("BDT","BDT", data->GetBinLowEdge(1), data->GetXaxis()->GetBinUpEdge(data->GetNbinsX() + 1));
  //x.printValue(std::cout);
  //x.printExtras(std::cout);


  RooDataHist datahist("data","data",RooArgSet(x), data);

  TH1F* mc0 = (TH1F*)toFit->At(0);
  RooDataHist hist0(mc0->GetName(), mc0->GetName(), x, mc0);
  RooHistPdf pdfhist0("pdfhist0", toFit->At(0)->GetName(), x, hist0);

  TH1F* mc1 = (TH1F*)toFit->At(1);
  RooDataHist hist1(mc1->GetName(), mc1->GetName(), x, mc1);
  RooRealVar var0("var0", "sig",0.5, 0,1);
  RooHistPdf pdfhist1("pdfhist1", toFit->At(1)->GetName(), x, hist1);

  RooArgList rooyields_mc(var0);
  RooArgList roohistpdfs_mc(pdfhist0, pdfhist1);

  RooAddPdf model("model","model", roohistpdfs_mc, rooyields_mc);
  model.fitTo(datahist);
  RooArgSet* params = model.getParameters(x);
  params->Print("v");


  //Int_t ci = 500;
  //TColor col(ci,255/255.0,204/255.0,51/255.0);
  //Int_t ci2 = 501;
  //TColor col2(ci2,153/255.0,51/255.0,204/255.0);

  TCanvas* c1 = new TCanvas();
  RooPlot* frame = x.frame();
  datahist.plotOn(frame);
  //model.plotOn(frame, LineColor(kRed));
  //model.plotOn(frame, RooFit::Components("pdfhist0"), RooFit::LineColor(kGreen), RooFit::LineStyle(kDashed));
  //model.plotOn(frame, RooFit::Components("pdfhist1"), RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));
  model.plotOn(frame, RooFit::Name("background"), RooFit::FillColor(kOrange-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  model.plotOn(frame, RooFit::Name("signal"), RooFit::Components("pdfhist0"), RooFit::FillColor(kViolet-1), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  datahist.plotOn(frame);

  TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9);
  legend->AddEntry(frame->findObject("signal"), "strange jets", "F");
  legend->AddEntry(frame->findObject("background"), "other jets", "F");

  frame->Draw();
  legend->Draw("same");
  c1->Print("dijet.pdf");
  cout<<"Signal Fraction is : "<<var0.getVal()<<" +/- "<<var0.getError()<<endl;


  return;
}
#ifndef __CINT__
int main(){
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  fit_dijet();
  return 0;
}
#endif
