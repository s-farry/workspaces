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
void fit_2dbdt(){
  
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  
  TFile* f = new TFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015.root");
  TFile* g = new TFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_strange.root");
  TFile* h = new TFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_quark_etaw.root");
  TFile* i = new TFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_gluon.root");

  TH2F* data = (TH2F*)f->Get("strange_bdt10_gluon_bdt10");

  TObjArray* toFit = new TObjArray();
  toFit->Add((TH2F*)g->Get("strange_bdt10_gluon_bdt10"));
  toFit->Add((TH2F*)h->Get("strange_bdt10_gluon_bdt10"));
  toFit->Add((TH2F*)i->Get("strange_bdt10_gluon_bdt10"));

  RooRealVar x("BDT0","BDT0", data->GetXaxis()->GetBinLowEdge(1), data->GetXaxis()->GetBinUpEdge(data->GetNbinsX() + 1));
  RooRealVar y("BDT1","BDT1", data->GetYaxis()->GetBinLowEdge(1), data->GetYaxis()->GetBinUpEdge(data->GetNbinsY() + 1));
  //x.printValue(std::cout);
  //x.printExtras(std::cout);

  cout<<"var set up"<<endl;

  RooDataHist datahist("data","data",RooArgSet(x,y), data);

  TH2F* mc0 = (TH2F*)toFit->At(0);
  RooDataHist hist0(mc0->GetName(), mc0->GetName(), RooArgList(x,y), mc0);
  RooHistPdf pdfhist0("pdfhist0", toFit->At(0)->GetName(), RooArgList(x,y), hist0);

  TH2F* mc1 = (TH2F*)toFit->At(1);
  RooDataHist hist1(mc1->GetName(), mc1->GetName(), RooArgList(x,y),mc1);
  RooRealVar var0("var0", "sig",0.33, 0,1);
  RooHistPdf pdfhist1("pdfhist1", toFit->At(1)->GetName(), RooArgList(x,y),hist1);

  TH2F* mc2 = (TH2F*)toFit->At(2);
  RooDataHist hist2(mc2->GetName(), mc2->GetName(), RooArgList(x,y),mc2);
  RooRealVar var1("var1", "sig2",0.33, 0,1);
  RooHistPdf pdfhist2("pdfhist2", toFit->At(2)->GetName(), RooArgList(x,y),hist2);

  RooArgList rooyields_mc(var0, var1);
  RooArgList roohistpdfs_mc(pdfhist0, pdfhist1, pdfhist2);

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
  model.plotOn(frame, RooFit::Name("gluon"), RooFit::FillColor(kOrange-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  model.plotOn(frame, RooFit::DrawOption("L"), RooFit::LineWidth(3), RooFit::LineColor(1));
  model.plotOn(frame, RooFit::Name("quark"), RooFit::Components("pdfhist0,pdfhist1"), RooFit::FillColor(kViolet-1), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  model.plotOn(frame, RooFit::Components("pdfhist0,pdfhist1"), RooFit::DrawOption("L"), RooFit::LineColor(1), RooFit::LineWidth(3));
  model.plotOn(frame, RooFit::Name("strange"), RooFit::Components("pdfhist0"), RooFit::FillColor(kYellow-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  model.plotOn(frame, RooFit::Components("pdfhist0"), RooFit::DrawOption("L"), RooFit::LineWidth(3), RooFit::LineColor(1));
  datahist.plotOn(frame);

  TLegend* legend = new TLegend(0.65, 0.7, 0.9, 0.9);
  legend->AddEntry(frame->findObject("gluon"), "gluon jets", "FL");
  legend->AddEntry(frame->findObject("quark"), "quark jets", "F");
  legend->AddEntry(frame->findObject("strange"), "strange jets", "F");

  TLegend* legend2 = new TLegend(0.17, 0.7, 0.47, 0.9);
  legend2->AddEntry(frame->findObject("gluon"), "gluon jets", "FL");
  legend2->AddEntry(frame->findObject("quark"), "quark jets", "FL");
  legend2->AddEntry(frame->findObject("strange"), "strange jets", "FL");
  legend2->SetFillStyle(0);

  frame->Draw();
  legend->Draw("same");
  c1->Print("testfit.pdf");

  TCanvas* c2 = new TCanvas();
  RooPlot* frame2 = y.frame();
  datahist.plotOn(frame2);
  //model.plotOn(frame, LineColor(kRed));
  //model.plotOn(frame2, RooFit::Components("pdfhist0"), RooFit::LineColor(kGreen), RooFit::LineStyle(kDashed));
  //model.plotOn(frame2, RooFit::Components("pdfhist1"), RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));
  //model.plotOn(frame2, RooFit::Components("pdfhist2"), RooFit::LineColor(kYellow-2), RooFit::LineStyle(kDashed));
  model.plotOn(frame2, RooFit::Name("gluon"), RooFit::FillColor(kOrange-2), RooFit::DrawOption("FL"));
  model.plotOn(frame2, RooFit::FillColor(kOrange-2), RooFit::DrawOption("L"), RooFit::LineWidth(3), RooFit::LineColor(1), RooFit::LineStyle(1));
  model.plotOn(frame2, RooFit::Name("quark"), RooFit::Components("pdfhist0,pdfhist1"), RooFit::FillColor(kViolet-1), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  model.plotOn(frame2, RooFit::Components("pdfhist0,pdfhist1"), RooFit::DrawOption("L"), RooFit::LineWidth(3), RooFit::LineColor(1));
  model.plotOn(frame2, RooFit::Name("strange"), RooFit::Components("pdfhist0"), RooFit::FillColor(kYellow-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  model.plotOn(frame2, RooFit::Components("pdfhist0"), RooFit::FillColor(kYellow-2), RooFit::DrawOption("L"), RooFit::LineWidth(3), RooFit::LineColor(1));
  datahist.plotOn(frame2);

  frame2->GetYaxis()->SetRangeUser(0, 6000);
  frame2->Draw();
  legend2->Draw("same");
  c2->Print("testfit2.pdf");
  cout<<"Signal Fraction is : "<<var0.getVal()<<" +/- "<<var0.getError()<<" "<<var1.getVal()<<" +/- "<<var1.getError()<<endl;


  /// compare some other variables

  TH1F* data_ptj    = (TH1F*)f->Get("ptj");
  TH1F* strange_ptj = (TH1F*)g->Get("ptj");
  TH1F* quark_ptj   = (TH1F*)h->Get("ptj");
  TH1F* gluon_ptj   = (TH1F*)i->Get("ptj");

  strange_ptj->Scale(data->Integral()*var0.getVal()/((TH2F*)toFit->At(0))->Integral());
  quark_ptj->Scale(data->Integral()*var1.getVal()/((TH2F*)toFit->At(1))->Integral());
  gluon_ptj->Scale(data->Integral()*(1 - var0.getVal() - var1.getVal())/((TH2F*)toFit->At(2))->Integral());

  strange_ptj->SetFillColor(kYellow-2);
  quark_ptj->SetFillColor(kViolet-1);
  gluon_ptj->SetFillColor(kOrange-2);

  THStack* stack = new THStack();
  stack->Add(strange_ptj);
  stack->Add(quark_ptj);
  stack->Add(gluon_ptj);

  TCanvas c3;
  stack->Draw("h");
  stack->GetXaxis()->SetTitle("p_{T}(jet) [GeV]");
  stack->GetYaxis()->SetTitle("Events");
  data_ptj->Draw("e1same");
  legend->Draw();
  c3.Print("test.pdf");
  c3.SetLogy();
  c3.Print("testb.pdf");



  TH1F* data_etaj    = (TH1F*)f->Get("etaj");
  TH1F* strange_etaj = (TH1F*)g->Get("etaj");
  TH1F* quark_etaj   = (TH1F*)h->Get("etaj");
  TH1F* gluon_etaj   = (TH1F*)i->Get("etaj");

  strange_etaj->Scale(data->Integral()*var0.getVal()/((TH2F*)toFit->At(0))->Integral());
  quark_etaj->Scale(data->Integral()*var1.getVal()/((TH2F*)toFit->At(1))->Integral());
  gluon_etaj->Scale(data->Integral()*(1 - var0.getVal() - var1.getVal())/((TH2F*)toFit->At(2))->Integral());

  strange_etaj->SetFillColor(kYellow-2);
  quark_etaj->SetFillColor(kViolet-1);
  gluon_etaj->SetFillColor(kOrange-2);

  THStack* stack2 = new THStack();
  stack2->Add(strange_etaj);
  stack2->Add(quark_etaj);
  stack2->Add(gluon_etaj);

  TCanvas c4;
  stack2->Draw("hist");
  stack2->GetXaxis()->SetTitle("#eta(jet)");
  stack2->GetYaxis()->SetTitle("Events");
  data_etaj->Draw("e1same");
  legend->Draw();
  c4.Print("test2.pdf");
  c4.SetLogy();
  data_etaj->GetYaxis()->SetRangeUser(1, 1000);
  c4.Update();
  c4.Print("test2b.pdf");


  TH1F* data_jet_width    = (TH1F*)f->Get("wj");
  TH1F* strange_jet_width = (TH1F*)g->Get("wj");
  TH1F* quark_jet_width   = (TH1F*)h->Get("wj");
  TH1F* gluon_jet_width   = (TH1F*)i->Get("wj");

  strange_jet_width->Scale(data->Integral()*var0.getVal()/((TH2F*)toFit->At(0))->Integral());
  quark_jet_width->Scale(data->Integral()*var1.getVal()/((TH2F*)toFit->At(1))->Integral());
  gluon_jet_width->Scale(data->Integral()*(1 - var0.getVal() - var1.getVal())/((TH2F*)toFit->At(2))->Integral());

  strange_jet_width->SetFillColor(kYellow-2);
  quark_jet_width->SetFillColor(kViolet-1);
  gluon_jet_width->SetFillColor(kOrange-2);

  THStack* stack3 = new THStack();
  stack3->Add(strange_jet_width);
  stack3->Add(quark_jet_width);
  stack3->Add(gluon_jet_width);

  TCanvas c5;
  stack3->Draw("hist");
  stack3->GetXaxis()->SetTitle("Jet Width");
  stack3->GetYaxis()->SetTitle("Events");
  data_jet_width->Draw("e1same");
  legend->Draw();
  c5.Print("test3.pdf");
  c5.SetLogy();
  data_jet_width->GetYaxis()->SetRangeUser(1, 1000);
  c5.Update();
  c5.Print("test3b.pdf");




  return;
}
#ifndef __CINT__
int main(){
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  fit_2dbdt();
  return 0;
}
#endif
