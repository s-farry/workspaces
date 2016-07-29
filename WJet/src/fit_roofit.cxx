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
#include <TLegend.h>
#include <TPaveText.h>
#include <RooRealVar.h>
#include <RooArgSet.h>
#include <RooDataHist.h>
#include <RooHistPdf.h>
#include <RooAddPdf.h>
#include <RooPlot.h>
#include <RooWorkspace.h>
using namespace std;
using namespace RooFit;
#endif

void do_fit(string var){
  gROOT->ProcessLine(".x /user2/sfarry/WJet/root/lhcbStyle.C");
  TH1::AddDirectory(false);
  
  TFile* f = new TFile("/user2/sfarry/WJet/python/wmupj.root");
  string fvar = var+"_JetIso";
  TH2F* fdata   = (TH2F*)f->Get(("Data/"+fvar).c_str());
  TH2F* fmc0    = (TH2F*)f->Get(("w/"+fvar).c_str());
  TH2F* fmc0b   = (TH2F*)f->Get(("w_nocorr/"+fvar).c_str()); // w->mu w/o corrections
  TH2F* fmc0c   = (TH2F*)f->Get(("z/"+fvar).c_str());        // replace with z->mu mu
  TH2F* fmc1    = (TH2F*)f->Get(("qcd/"+fvar).c_str());

  TH1F* fdata_1D = (TH1F*)f->Get(("Data/"+var).c_str());
  int nbins = fdata_1D->GetNbinsX();

  TFile* outF = new TFile((var+".root").c_str(), "RECREATE");
  for (int i = 0 ; i < nbins ; ++i ){
    std::ostringstream o;
    o << i;
    string idx = o.str();

    double lo = fdata_1D->GetXaxis()->GetBinLowEdge(i+1);
    double hi = lo + fdata_1D->GetXaxis()->GetBinWidth(i+1);

    std::ostringstream b;
    b<<lo;
    if (var.find("ETA") == 0) b<<"< #eta^{#mu} < ";
    else if (var.find("Jet_ETA") == 0) b<<"< #eta^{j} < ";
    else if (var.find("Jet_PT") == 0) b<<"< p_{T}^{j} < ";
    b<<hi;
    string label = b.str();

    TH1D* data = fdata->ProjectionY((var+"_data_"+idx).c_str(), i+1, i+1);
    TH1D* mc0  = fmc0->ProjectionY((var+"_mc0_"+idx).c_str(), i+1, i+1);
    TH1D* mc0b  = fmc0b->ProjectionY((var+"_mc0b_"+idx).c_str(), i+1, i+1);
    TH1D* mc0c  = fmc0c->ProjectionY((var+"_mc0c_"+idx).c_str(), i+1, i+1);
    TH1D* mc1  = fmc1->ProjectionY((var+"_mc1_"+idx).c_str(), i+1, i+1);

    double data_evts = data->Integral();

    RooRealVar x("X","p_{T}^{#mu}/p_{T}^{#mu-jet}", data->GetBinLowEdge(1), data->GetXaxis()->GetBinUpEdge(data->GetNbinsX() + 1));
    RooDataHist roodata((var+"_roodata_"+idx).c_str(),"data",RooArgSet(x), data);
    RooDataHist roomc0((var+"_roomc0_"+idx).c_str(), "mc0", RooArgSet(x), mc0);
    RooDataHist roomc0b((var+"_roomc0b_"+idx).c_str(), "mc0", RooArgSet(x), mc0b);
    RooDataHist roomc0c((var+"_roomc0c_"+idx).c_str(), "mc0", RooArgSet(x), mc0c);
    RooDataHist roomc1((var+"_roomc1_"+idx).c_str(), "mc1", RooArgSet(x), mc1);
    RooRealVar Nmc0("Nmc0", "Nmc0", 0, data_evts);
    RooRealVar Nmc0b("Nmc0b", "Nmc0b", 0, data_evts);
    RooRealVar Nmc0c("Nmc0c", "Nmc0c", 0, data_evts);
    RooRealVar Nmc1("Nmc1", "Nmc1", 0, data_evts);
    RooHistPdf roomc0pdf("mc0pdf", "mc0", x, roomc0);
    RooHistPdf roomc0bpdf("mc0bpdf", "mc0b", x, roomc0b);
    RooHistPdf roomc0cpdf("mc0cpdf", "mc0c", x, roomc0c);
    RooHistPdf roomc1pdf("mc1pdf", "mc1", x, roomc1);



    RooArgList rooyields_mc(Nmc0, Nmc1)  ;
    RooArgList roohistpdfs_mc(roomc0pdf, roomc1pdf);

    RooArgList rooyieldsb_mc(Nmc0b, Nmc1)  ;
    RooArgList roohistpdfsb_mc(roomc0bpdf, roomc1pdf);

    RooArgList rooyieldsc_mc(Nmc0c, Nmc1)  ;
    RooArgList roohistpdfsc_mc(roomc0cpdf, roomc1pdf);

    RooAddPdf model("model","model", roohistpdfs_mc, rooyields_mc);
    model.fitTo(roodata, RooFit::Extended());
    RooArgSet* params = model.getParameters(x);
    params->Print("v");
    RooAddPdf modelb("modelb","modelb", roohistpdfsb_mc, rooyieldsb_mc);
    modelb.fitTo(roodata, RooFit::Extended());
    RooAddPdf modelc("modelc","modelc", roohistpdfsc_mc, rooyieldsc_mc);
    modelc.fitTo(roodata, RooFit::Extended());

    TCanvas* c1 = new TCanvas();

    RooPlot* frame = x.frame(RooFit::Name("JetIso"), RooFit::Title("JetIso"));
    roodata.plotOn(frame, RooFit::Name("data"));
    model.plotOn(frame, RooFit::LineColor(kRed), RooFit::LineStyle(kDashed), RooFit::Name("Fit"));
    model.plotOn(frame, RooFit::Components("mc0pdf"), RooFit::LineColor(kGreen), RooFit::LineStyle(kDashed), RooFit::Name("mc0"));
    model.plotOn(frame, RooFit::Components("mc1pdf"), RooFit::LineColor(kBlue), RooFit::LineStyle(kDashed), RooFit::Name("mc1"));

    frame->Draw();
    TLegend* leg = new TLegend(0.2, 0.6, 0.6, 0.9);
    leg->AddEntry(frame->findObject("data"), "2012 Data", "lep");
    leg->AddEntry(frame->findObject("mc0"), "W#rightarrow#mu#nuj (MC2012)", "l");
    leg->AddEntry(frame->findObject("mc1"), "QCD", "l");
    leg->SetFillStyle(0);
    leg->SetTextFont(132);
    leg->Draw("same");
    TPaveText* pave = new TPaveText(0.2, 0.4, 0.5, 0.5, "NDC");
    pave->AddText(label.c_str());
    pave->SetFillStyle(0);
    pave->SetMargin(0.1);
    pave->Draw("same");
    c1->Print(("/user2/sfarry/WJet/figures/wmupj_jetiso_"+var+idx+".pdf").c_str());
    outF->cd();
    RooWorkspace* tot = new RooWorkspace();
    tot->import(roodata);
    tot->import(model);
    tot->import(modelb, RooFit::RenameConflictNodes("_b"));
    tot->import(modelc, RooFit::RenameConflictNodes("_c"));
    tot->Write((var+"_tot_"+idx).c_str());

  }

  outF->Close();
  return;
}


void fit_roofit(){
  do_fit("Jet_ETA");
  do_fit("Jet_PT");
  do_fit("ETA");

}

#ifndef __CINT__
int main(){
  fit_roofit();
  return 0;
}
#endif
