#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooPolynomial.h"
#include "RooKeysPdf.h"
#include "RooNDKeysPdf.h"
#include "RooProdPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1.h"
#include "RooPlot.h"
using namespace RooFit ;

void fitbinned(){
  TFile* outputFile = new TFile("output.root");
  TTree* new_mbt = (TTree*)outputFile->Get("mb_tree");
  TTree* new_ewkt = (TTree*)outputFile->Get("ewk_tree");
  TTree* new_hft = (TTree*)outputFile->Get("hf_tree");

  new_mbt->SetBranchStatus("*", 0);
  new_mbt->SetBranchStatus("muminus_cpt_0.50", 1);
  new_mbt->SetBranchStatus("muminus_cmult_0.50", 1);
  new_mbt->SetBranchStatus("muminus_ID", 1);
  new_mbt->SetBranchStatus("IP_BDT", 1);

  new_ewkt->SetBranchStatus("*", 0);
  new_ewkt->SetBranchStatus("muminus_cpt_0.50", 1);
  new_ewkt->SetBranchStatus("muminus_cmult_0.50", 1);
  new_ewkt->SetBranchStatus("muminus_ID", 1);
  new_ewkt->SetBranchStatus("IP_BDT", 1);

  new_hft->SetBranchStatus("*", 0);
  new_hft->SetBranchStatus("muminus_cpt_0.50", 1);
  new_hft->SetBranchStatus("muminus_cmult_0.50", 1);
  new_hft->SetBranchStatus("muminus_ID", 1);
  new_hft->SetBranchStatus("IP_BDT", 1);


  RooRealVar isovar("muminus_cpt_0.50", "ISO", 0, 20000);
  isovar.setBins(100);
  RooRealVar multvar("muminus_cmult_0.50", "ISOMULT", 0, 20);
  RooRealVar ptvar("muminus_PT", "PT", 20000, 70000);
  RooRealVar pchi2var("muminus_TRACK_PCHI2", "PCHI2", 0, 1);
  RooRealVar tthitsvar("muminus_TRACK_nTTHits", "TTHits", 0, 100);
  RooRealVar Hcalvar("muminus_CaloHcalE", "Hcal", 0, 100000);
  RooRealVar Ecalvar("muminus_CaloEcalE", "Ecal", 0, 100000);
  RooRealVar isMuonvar("muminus_isMuon", "ISMUON", 0, 1);
  RooRealVar ipvar("IP_BDT", "BDT", -1, 1);
  RooRealVar idvar("muminus_ID", "ID", -15, 15);

  RooDataSet mbds("mbds", "mbds", new_mbt, RooArgSet(isovar, ipvar, idvar, multvar));
  RooDataSet ewkds("ewkds", "ewkds", new_ewkt, RooArgSet(isovar, ipvar, idvar, multvar));
  RooDataSet hfds("hfds", "hfds", new_hft, RooArgSet(isovar, ipvar, idvar, multvar));

  RooDataSet* ds = hfds.reduce("muminus_ID < 0 && IP_BDT < -0.2");
  RooDataSet* ds2 = hfds.reduce("muminus_ID < 0 && IP_BDT < -0.2 && muminus_cpt_0.50 > 400");

  RooKeysPdf kest_mb_plus("kest_mb_plus","kest_mbplus"    , isovar, (*ds2)  ,RooKeysPdf::MirrorBoth,2) ;
  cout<<"Made Kernel"<<endl;

  //RooGenericPdf stepFuncPDF("stepFuncPDF", "stepFuncPDF", "(@0 >= 400)", RooArgList(isovar));

  //isovar.setBins(10000, "FFT");
  //RooFFTConvPdf kstep("kstep", "kstep", isovar, stepFuncPDF, kest_mb_plus); 

  //TFile keys("keys.root");
  //RooWorkspace* workspace = (RooWorkspace*)keys.Get("workspace");
  //RooAbsPdf* kest_mb_plus  = workspace->pdf("kest_mb_plus");

  Int_t nbins(3);
  TArrayD limits(nbins+1);
  limits[0] = 0.0;
  limits[1] = 200.0;
  limits[2] = 400.0;
  limits[3] = 20000.0;
  RooArgList* list = new RooArgList("list");
  RooRealVar binHeight0("binHeight0", "bin 0 value", 1.0);
  RooRealVar binHeight1("binHeight1", "bin 1 value", 0.0, -10.0, 10.0);
  RooRealVar binHeight2("binHeight2", "bin 2 value", 0.0);
  list->add(binHeight0);
  list->add(binHeight1);
  list->add(binHeight2);

  RooParametricStepFunction aPDF("aPdf", "PDF", isovar, *list, limits, nbins);

  RooDataHist dh("dh", "binned", RooArgSet(isovar), *ds);

  double N = ds.sumEntries();

  RooRealVar n1("n1", "Electroweak Normalisation", 0.9995*N,0,N);
  RooRealVar n2("n2", "Electroweak Normalisation", 1,0,N);

  RooAddPdf sum("sum", "Sum of PDFs", RooArgList(kest_mb_plus,aPDF), RooArgList(n1,n2));
  sum.fitTo(dh);

  RooPlot* frame = isovar.frame(Title("Decay in flight kernel estimation"), Bins(100)) ;
  dh.plotOn(frame);
  sum.plotOn(frame);
  frame->Draw();

  //sum.fitTo(*dh);
  
}
