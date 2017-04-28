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
void fit_tagging_2016(){
  
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  
  TFile* f = new TFile("/user2/sfarry/workspaces/top/tuples/j_untagged.root");
  TFile* g = new TFile("/user2/sfarry/workspaces/top/tuples/j_tagged.root");
  TFile* h = new TFile("/user2/sfarry/workspaces/top/tuples/b_j_untagged.root");
  TFile* hh = new TFile("/user2/sfarry/workspaces/top/tuples/b_j_tagged.root");
  TFile* i = new TFile("/user2/sfarry/workspaces/top/tuples/c_j_untagged.root");
  TFile* j = new TFile("/user2/sfarry/workspaces/top/tuples/l_j_untagged.root");

  TH1F* ipchisq_tot  = (TH1F*)f->Get("avipchi2");
  TH1F* ipchisq_pass = (TH1F*)g->Get("avipchi2");
  TH1F* ipchisq_b    = (TH1F*)h->Get("avipchi2");
  TH1F* ipchisq_b_tagged    = (TH1F*)hh->Get("avipchi2");
  TH1F* ipchisq_c    = (TH1F*)i->Get("avipchi2");
  TH1F* ipchisq_l    = (TH1F*)j->Get("avipchi2");

  RooRealVar x("ipchisq","log_{10}#chi_{ip}^{2}", ipchisq_tot->GetBinLowEdge(1), ipchisq_tot->GetXaxis()->GetBinUpEdge(ipchisq_tot->GetNbinsX() + 1));
  //x.printValue(std::cout);
  //x.printExtras(std::cout);

  RooDataHist tot_datahist("ipchisq_tot","ipchisq_tot",RooArgSet(x), ipchisq_tot);
  RooDataHist pass_datahist ("ipchisq_pass" ,"ipchisq_pass" ,RooArgSet(x), ipchisq_pass);

  RooDataHist hist0(ipchisq_b->GetName(), ipchisq_b->GetName(), x, ipchisq_b);
  RooHistPdf pdfhist0("pdfhist0", ipchisq_b->GetName(), x, hist0);
  RooDataHist hist1(ipchisq_c->GetName(), ipchisq_c->GetName(), x, ipchisq_c);
  RooHistPdf pdfhist1("pdfhist1", ipchisq_c->GetName(), x, hist1);
  RooDataHist hist2(ipchisq_l->GetName(), ipchisq_l->GetName(), x, ipchisq_l);
  RooHistPdf pdfhist2("pdfhist2", ipchisq_l->GetName(), x, hist2);
  RooDataHist hist3(ipchisq_b_tagged->GetName(), ipchisq_b_tagged->GetName(), x, ipchisq_b_tagged);
  RooHistPdf pdfhist3("pdfhist3", ipchisq_b_tagged->GetName(), x, hist3);
  RooDataHist hist4(ipchisq_c->GetName(), ipchisq_c->GetName(), x, ipchisq_c);
  RooHistPdf pdfhist4("pdfhist4", ipchisq_c->GetName(), x, hist4);
  RooDataHist hist5(ipchisq_l->GetName(), ipchisq_l->GetName(), x, ipchisq_l);
  RooHistPdf pdfhist5("pdfhist5", ipchisq_l->GetName(), x, hist5);

  double Ntot = tot_datahist.sumEntries();
  double Npass = pass_datahist.sumEntries();

  RooRealVar var0("var0", "Ntot_beauty",0.2*Ntot, 0,Ntot);
  RooRealVar var1("var1", "Ntot_charm",0.5*Ntot, 0,Ntot);
  RooRealVar var2("var2", "Ntot_light",0.3*Ntot, 0,Ntot);

  RooRealVar var3("var3", "Npass_beauty",0.2*Npass, 0,Npass);
  RooRealVar var4("var4", "Npass_charm",0.5*Npass, 0,Npass);
  RooRealVar var5("var5", "Npass_light",0.3*Npass, 0,Npass);

  RooArgList tot_yields(var0, var1, var2);
  RooArgList tot_hists(pdfhist0, pdfhist1, pdfhist2);

  RooArgList pass_yields(var3, var4, var5);
  RooArgList pass_hists(pdfhist3, pdfhist4, pdfhist5);

  RooAddPdf tot_model("tot_model","tot_model", tot_hists, tot_yields);
  tot_model.fitTo(tot_datahist);
  RooArgSet* params = tot_model.getParameters(x);
  params->Print("v");

  RooAddPdf pass_model("pass_model","pass_model", pass_hists, pass_yields);
  pass_model.fitTo(pass_datahist);
  RooArgSet* pass_params = pass_model.getParameters(x);
  pass_params->Print("v");


  TCanvas* c1 = new TCanvas();
  RooPlot* frame = x.frame();
  tot_datahist.plotOn(frame);
  tot_model.plotOn(frame, RooFit::Name("beauty"), RooFit::FillColor(kOrange-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  tot_model.plotOn(frame, RooFit::Name("charm"), RooFit::Components("pdfhist1,pdfhist2"), RooFit::FillColor(kViolet-1), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  tot_model.plotOn(frame, RooFit::Name("light"), RooFit::Components("pdfhist2"), RooFit::FillColor(kRed), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  tot_datahist.plotOn(frame);

  TLegend* legend = new TLegend(0.2, 0.7, 0.5, 0.9);
  legend->SetFillStyle(0);
  legend->AddEntry(frame->findObject("beauty"), "beauty", "F");
  legend->AddEntry(frame->findObject("charm"), "charm", "F");
  legend->AddEntry(frame->findObject("light"), "light", "F");

  frame->Draw();
  legend->Draw("same");
  c1->Print("/user2/sfarry/workspaces/top/figures/tagging_tot.pdf");

  cout<<var0.getVal()<<endl;

  TCanvas* c2 = new TCanvas();
  RooPlot* frame2 = x.frame();
  pass_datahist.plotOn(frame2);
  pass_model.plotOn(frame2, RooFit::Name("beauty"), RooFit::FillColor(kOrange-2), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  pass_model.plotOn(frame, RooFit::Name("charm"), RooFit::Components("pdfhist4,pdfhist5"), RooFit::FillColor(kViolet-1), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  pass_model.plotOn(frame2, RooFit::Name("light"), RooFit::Components("pdfhist5"), RooFit::FillColor(kRed), RooFit::DrawOption("F"), RooFit::LineWidth(0));
  pass_datahist.plotOn(frame2);
  frame2->Draw();
  legend->Draw("same");
  c2->Print("/user2/sfarry/workspaces/top/figures/tagging_pass.pdf");

  TCanvas* c3 = new TCanvas();
  RooPlot* frame3 = x.frame();
  tot_datahist.plotOn(frame3);
  tot_model.plotOn(frame3, RooFit::Name("beauty"), RooFit::Components("pdfhist0"), RooFit::DrawOption("L"));
  tot_model.plotOn(frame3, RooFit::Name("charm"), RooFit::Components("pdfhist1"), RooFit::LineColor(kViolet-1), RooFit::DrawOption("L"));
  tot_model.plotOn(frame3, RooFit::Name("light"), RooFit::Components("pdfhist2"), RooFit::LineColor(kRed), RooFit::DrawOption("L"));
  tot_datahist.plotOn(frame3);

  TLegend* legend2 = new TLegend(0.2, 0.7, 0.5, 0.9);
  legend2->SetFillStyle(0);
  legend2->AddEntry(frame3->findObject("beauty"), "beauty", "L");
  legend2->AddEntry(frame3->findObject("charm"), "charm", "L");
  legend2->AddEntry(frame3->findObject("light"), "light", "L");

  frame3->Draw();
  legend2->Draw("same");
  c3->Print("/user2/sfarry/workspaces/top/figures/tagging_tot_unstacked.pdf");


  TCanvas* c4 = new TCanvas();
  RooPlot* frame4 = x.frame();
  pass_datahist.plotOn(frame4);
  pass_model.plotOn(frame4, RooFit::Name("beauty"), RooFit::Components("pdfhist3"), RooFit::DrawOption("L"));
  pass_model.plotOn(frame4, RooFit::Name("charm"), RooFit::Components("pdfhist4"), RooFit::LineColor(kViolet-1), RooFit::DrawOption("L"));
  pass_model.plotOn(frame4, RooFit::Name("light"), RooFit::Components("pdfhist5"), RooFit::LineColor(kRed), RooFit::DrawOption("L"));
  pass_datahist.plotOn(frame4);

  frame4->Draw();
  legend2->Draw("same");
  c4->Print("/user2/sfarry/workspaces/top/figures/tagging_pass_unstacked.pdf");



  cout<<var0.getVal()<<" "<<var3.getVal()<<endl;
  cout<<"Tagging Efficiency: "<<var3.getVal() / var0.getVal() << " +/- "<<
    var3.getVal()/var0.getVal() * sqrt(pow(var3.getError()/var3.getVal(),2) +
				   pow(var0.getError()/var0.getVal(),2))<<endl;

  return;
}
#ifndef __CINT__
int main(){
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  fit_tagging_2016();
  return 0;
}
#endif
