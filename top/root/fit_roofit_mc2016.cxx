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
void fit_roofit_mc2016(){
  
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  
  TFile* f = new TFile("/user2/sfarry/workspaces/top/tuples/e_trk_mc2016.root");
  TFile* g = new TFile("/user2/sfarry/workspaces/top/tuples/e_trk_wid_mc2016.root");
  TFile* h = new TFile("/user2/sfarry/workspaces/top/tuples/e_trk_antiiso_mc2016.root");

  TFile* i = new TFile("/user2/sfarry/workspaces/top/tuples/egm_trk_mc2016.root");
  TFile* j = new TFile("/user2/sfarry/workspaces/top/tuples/egm_trk_antiiso_mc2016.root");

  TH1F* etrk_data = (TH1F*)f->Get("tag_pt");
  TH1F* egm_data  = (TH1F*)i->Get("tag_pt");

  RooRealVar x("PT","PT", etrk_data->GetBinLowEdge(1), etrk_data->GetXaxis()->GetBinUpEdge(etrk_data->GetNbinsX() + 1));
  //x.printValue(std::cout);
  //x.printExtras(std::cout);

  RooDataHist etrk_datahist("etrk_data","etrk_data",RooArgSet(x), etrk_data);
  RooDataHist egm_datahist ("egm_data" ,"egm_data" ,RooArgSet(x), egm_data);

  TH1F* mc0 = (TH1F*)g->Get("tag_pt");
  RooDataHist hist0(mc0->GetName(), mc0->GetName(), x, mc0);
  RooHistPdf pdfhist0("pdfhist0", mc0->GetName(), x, hist0);

  TH1F* mc1 = (TH1F*)h->Get("tag_pt");
  RooDataHist hist1(mc1->GetName(), mc1->GetName(), x, mc1);
  RooHistPdf pdfhist1("pdfhist1", mc1->GetName(), x, hist1);

  TH1F* mc2 = (TH1F*)j->Get("tag_pt");
  RooDataHist hist2(mc1->GetName(), mc1->GetName(), x, mc1);
  RooHistPdf pdfhist2("pdfhist2", mc1->GetName(), x, hist1);

  RooRealVar var0("var0", "sig",0.5, 0,1);
  RooRealVar var1("var1", "sig",0.5, 0,1);

  RooArgList etrk_yields(var0);
  RooArgList egm_yields(var1);
  RooArgList etrk_hists(pdfhist0, pdfhist1);
  RooArgList egm_hists(pdfhist0, pdfhist2);

  RooAddPdf etrk_model("etrk_model","etrk_model", etrk_hists, etrk_yields);
  etrk_model.fitTo(etrk_datahist);
  RooArgSet* params = etrk_model.getParameters(x);
  params->Print("v");


  TCanvas* c1 = new TCanvas();
  RooPlot* frame = x.frame();
  etrk_datahist.plotOn(frame);
  etrk_model.plotOn(frame, RooFit::Name("zee"), RooFit::FillColor(kOrange-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  etrk_model.plotOn(frame, RooFit::Name("qcd"), RooFit::Components("pdfhist1"), RooFit::FillColor(kViolet-1), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  etrk_datahist.plotOn(frame);

  TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9);
  legend->AddEntry(frame->findObject("zee"), "Z#rightarrowee", "F");
  legend->AddEntry(frame->findObject("qcd"), "background", "F");

  frame->Draw();
  legend->Draw("same");
  c1->Print("/user2/sfarry/workspaces/top/figures/etrk_mc2016_fit.pdf");



  RooAddPdf egm_model("egm_model","egm_model", egm_hists, egm_yields);
  egm_model.fitTo(egm_datahist);
  RooArgSet* params2 = egm_model.getParameters(x);
  params2->Print("v");


  TCanvas* c2 = new TCanvas();
  RooPlot* frame2 = x.frame();
  egm_datahist.plotOn(frame2);
  egm_model.plotOn(frame2, RooFit::Name("zee"), RooFit::FillColor(kOrange-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  egm_model.plotOn(frame2, RooFit::Name("qcd"), RooFit::Components("pdfhist2"), RooFit::FillColor(kViolet-1), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  egm_datahist.plotOn(frame2);

  frame2->Draw();
  legend->Draw("same");
  c2->Print("/user2/sfarry/workspaces/top/figures/egm_mc2016_fit.pdf");


  


  //double Netrk = var0.getVal() * etrk_data->Integral();
  //double Negm  = var1.getVal() * egm_data->Integral();
  double Netrk = 1.0 * etrk_data->Integral();
  double Negm  = 1.0 * egm_data->Integral();
  double eff   = Netrk / (Negm + Netrk);

  double Netrk_err = var0.getError() * etrk_data->Integral();
  double Negm_err  = var1.getError() * egm_data->Integral();
  double eff_err   = eff * sqrt(pow(Netrk_err / Netrk,2) + pow(Negm_err / Negm,2));


  cout<<"Signal Fractions are : "<<var0.getVal()<<" +/- "<<var0.getError()<<" "<<var1.getVal()<<" +/- "<<var1.getError()<<endl;
  cout<<"Number of signal events are: "<<Netrk<<" +/- "<<Netrk_err<<" "<<Negm<<" +/- "<<Negm_err<<endl;

  cout<<"Efficiency is "<<eff<<" +/- "<<eff_err<<endl;

  



  return;
}
#ifndef __CINT__
int main(){
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  fit_roofit_mc2016();
  return 0;
}
#endif
