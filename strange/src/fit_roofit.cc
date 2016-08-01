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
void fit_roofit(){
  
  TFile* f = new TFile("/user2/sfarry/workspaces/strange/tmvaDVout.root");
  
  TH1F* data = new TH1F("data", "data" , 100, -1, 1 ) ;
  TH1F* mc0 = new TH1F("mc0", "mc0"    , 100, -1, 1 ) ;
  TH1F* mc1 = new TH1F("mc1", "mc0"    , 100, -1, 1 ) ;

  TTree* t = (TTree*)f->Get("TestTree");
  TTree* u = (TTree*)f->Get("TrainTree");

  t->Draw("BDT>>data", "jet_kaonmult > 0 && jet_PT > 10000 && jet_maxkaonpt > 5000");
  t->Draw("BDT>>mc0", "classID == 0 && jet_kaonmult > 0 && jet_PT > 10000 && jet_maxkaonpt > 5000");
  t->Draw("BDT>>mc1", "classID == 1 && jet_kaonmult > 0 && jet_PT > 10000 && jet_maxkaonpt > 5000");

  cout<<t->GetEntries()<<endl;
  cout<<data->GetEntries()<<endl;

  RooRealVar m("m","m", data->GetBinLowEdge(1), data->GetXaxis()->GetBinUpEdge(data->GetNbinsX() + 1));
  RooDataHist datahist("data","data",RooArgSet(m), data);
  
  double data_evts = data->Integral();

  RooDataHist hist0(mc0->GetName(), mc0->GetName(), m, mc0);
  double mc0_evts = mc0->Integral();
  RooRealVar var0("var0", mc0->GetName(),data_evts*0.2, 0,data_evts);
  RooHistPdf pdfhist0("pdfhist0", mc0->GetName(), m, hist0);

  RooDataHist hist1(mc1->GetName(), mc1->GetName(), m, mc1);
  double mc1_evts = mc1->Integral();
  RooRealVar var1("var1", mc1->GetName(),data_evts*0.8, 0,data_evts);
  RooHistPdf pdfhist1("pdfhist1", mc1->GetName(), m, hist1);

  //RooArgList rooyields_mc(var0, var1);
  RooArgList rooyields_mc(var0, var1);
  RooArgList roohistpdfs_mc(pdfhist0, pdfhist1);

  RooAddPdf model("model","model", roohistpdfs_mc, rooyields_mc);
  model.fitTo(datahist, RooFit::Extended());
  RooArgSet* params = model.getParameters(m);
  params->Print("v");

  RooPlot* frame = m.frame(RooFit::Name("PT"), RooFit::Title("PT"));
  datahist.plotOn(frame);
  model.plotOn(frame, RooFit::LineColor(kRed), RooFit::LineStyle(kDashed));
  model.plotOn(frame, RooFit::Components("pdfhist0"), RooFit::LineColor(kGreen), RooFit::LineStyle(kDashed));
  model.plotOn(frame, RooFit::Components("pdfhist1"), RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed));
  //model.plotOn(frame, RooFit::Components("pdfhist2"), RooFit::LineColor(kOrange), RooFit::LineStyle(kDashed));

  TCanvas* c1 = new TCanvas();
  frame->Draw();
  c1->Print("test.pdf");

  return;
}
#ifndef __CINT__
int main(){
  fit_roofit();
  return 0;
}
#endif
