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
void fit_roofit_egm(){
  
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  
  TFile* f = new TFile("/user2/sfarry/workspaces/top/tuples/egm_trk.root");
  TFile* g = new TFile("/user2/sfarry/workspaces/top/tuples/e_trk_wid.root");
  TFile* h = new TFile("/user2/sfarry/workspaces/top/tuples/egm_trk_antiiso.root");

  TH1F* data = (TH1F*)f->Get("tag_pt");

  TObjArray* toFit = new TObjArray();
  toFit->Add((TH1F*)g->Get("tag_pt"));
  toFit->Add((TH1F*)h->Get("tag_pt"));

  RooRealVar x("PT","PT", data->GetBinLowEdge(1), data->GetXaxis()->GetBinUpEdge(data->GetNbinsX() + 1));
  //x.printValue(std::cout);
  //x.printExtras(std::cout);

  cout<<"var set up"<<endl;

  RooDataHist datahist("data","data",RooArgSet(x), data);

  TH1F* mc0 = (TH1F*)toFit->At(0);
  RooDataHist hist0(mc0->GetName(), mc0->GetName(), x, mc0);
  RooHistPdf pdfhist0("pdfhist0", toFit->At(0)->GetName(), x, hist0);

  TH1F* mc1 = (TH1F*)toFit->At(1);
  RooDataHist hist1(mc1->GetName(), mc1->GetName(), x, mc1);
  RooRealVar var0("var0", "sig",0.33, 0,1);
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
  model.plotOn(frame, RooFit::Name("zee"), RooFit::FillColor(kOrange-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  model.plotOn(frame, RooFit::Name("qcd"), RooFit::Components("pdfhist1"), RooFit::FillColor(kViolet-1), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  datahist.plotOn(frame);

  TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9);
  legend->AddEntry(frame->findObject("zee"), "Z#rightarrowee", "F");
  legend->AddEntry(frame->findObject("qcd"), "background", "F");

  frame->Draw();
  legend->Draw("same");
  c1->Print("testfit.pdf");
  cout<<"Signal Fraction is : "<<var0.getVal()<<" +/- "<<var0.getError()<<endl;
  cout<<"Number of signal events is: "<<var0.getVal() * data->Integral()<<endl;


  return;
}
#ifndef __CINT__
int main(){
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  fit_roofit_egm();
  return 0;
}
#endif
