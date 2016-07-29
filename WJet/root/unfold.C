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
#include <RooUnfoldResponse.h>
#include <RooUnfoldBayes.h>
#include <Tree.h>
using namespace std;
#endif


int main(){
  RooUnfoldResponse* Uetaj = new RooUnfoldResponse("Uetaj", "Uetaj");
  RooUnfoldResponse* Uetaj_plus = new RooUnfoldResponse("Uetaj_plus", "Uetaj_plus");
  RooUnfoldResponse* Uetaj_minus = new RooUnfoldResponse("Uetaj_minus", "Uetaj_minus");
  RooUnfoldResponse* Uptj = new RooUnfoldResponse("Uptj", "Uptj");
  RooUnfoldResponse* Uptj_plus = new RooUnfoldResponse("Uptj_plus", "Uptj_plus");
  RooUnfoldResponse* Uptj_minus = new RooUnfoldResponse("Uptj_minus", "Uptj_minus");
  RooUnfoldResponse* response2d = new RooUnfoldResponse("combined", "combined");
  RooUnfoldResponse* response2d_plus = new RooUnfoldResponse("plus", "plus");
  RooUnfoldResponse* response2d_minus = new RooUnfoldResponse("minus", "minus");
  Float_t etaj_bins[] = {2.0, 2.2, 2.7, 3.2, 3.7, 4.2, 4.5};
  TH1F* etaj               = new TH1F("etaj", "etaj", 6, etaj_bins);
  TH1F* etaj_plus          = new TH1F("etaj_plus", "etaj_plus", 6, etaj_bins);
  TH1F* etaj_minus         = new TH1F("etaj_minus", "etaj_minus", 6, etaj_bins);
  Float_t ptj_bins[]  = {12.5, 20, 25, 30, 40, 50, 100, 150.0};
  TH1F* ptj               = new TH1F("ptj", "ptj", 6, ptj_bins);
  TH1F* ptj_plus          = new TH1F("ptj_plus", "ptj_plus", 6, ptj_bins);
  TH1F* ptj_minus         = new TH1F("ptj_minus", "ptj_minus", 6, ptj_bins);
  TH2F* etaj_ptj_plus     = new TH2F("plus", "setup", 6, etaj_bins, 7,  ptj_bins);
  TH2F* etaj_ptj_minus    = new TH2F("minus", "setup", 6, etaj_bins, 7, ptj_bins);
  TH2F* etaj_ptj          = new TH2F("combined", "setup", 6, etaj_bins, 7, ptj_bins);
  TH2F* jet_true_plus   = new TH2F("jet_true_plus"  , "true", 6, etaj_bins, 7, ptj_bins);
  TH2F* jet_reco_plus   = new TH2F("jet_reco_plus"  , "reco", 6, etaj_bins, 7, ptj_bins);
  TH2F* jet_true_minus   = new TH2F("jet_true_minus"  , "true", 6, etaj_bins, 7, ptj_bins);
  TH2F* jet_reco_minus   = new TH2F("jet_reco_minus"  , "reco", 6, etaj_bins, 7, ptj_bins);

  TH1F* jet_true_ptj_wetacut_plus   = new TH1F("jet_true_ptj_weta_plus"  , "jet_true_ptj_weta_plus", 7, ptj_bins);
  TH1F* jet_true_ptj_wetacut_minus  = new TH1F("jet_true_ptj_weta_minus" , "jet_true_ptj_weta_minus", 7, ptj_bins);

  TH1F* jet_true_ptj_plus   = new TH1F("jet_true_ptj_plus"  , "jet_true_ptj_plus", 7, ptj_bins);
  TH1F* jet_true_ptj_minus  = new TH1F("jet_true_ptj_minus" , "jet_true_ptj_minus", 7, ptj_bins);

  TH1F* jet_true_etaj_plus   = new TH1F("jet_true_etaj_plus"  , "jet_true_etaj_plus", 6, etaj_bins);
  TH1F* jet_true_etaj_minus  = new TH1F("jet_true_etaj_minus" , "jet_true_etaj_minus", 6, etaj_bins);

  TH1F* jet_reco_ptj_wetacut_plus   = new TH1F("jet_reco_ptj_weta_plus"  , "jet_reco_ptj_weta_plus", 7, ptj_bins);
  TH1F* jet_reco_ptj_wetacut_minus  = new TH1F("jet_reco_ptj_weta_minus" , "jet_reco_ptj_weta_minus", 7, ptj_bins);

  TH1F* jet_reco_ptj_plus   = new TH1F("jet_reco_ptj_plus"  , "jet_reco_ptj_plus", 7, ptj_bins);
  TH1F* jet_reco_ptj_minus  = new TH1F("jet_reco_ptj_minus" , "jet_reco_ptj_minus", 7, ptj_bins);

  TH1F* jet_reco_etaj_plus   = new TH1F("jet_reco_etaj_plus"  , "jet_reco_etaj_plus", 6, etaj_bins);
  TH1F* jet_reco_etaj_minus  = new TH1F("jet_reco_etaj_minus" , "jet_reco_etaj_minus", 6, etaj_bins);

  //TH2F* jet_unfold = new TH2F("jet_unfold", "unfold", 6, etaj, 7, ptj);

  response2d->Setup(etaj_ptj, etaj_ptj);
  response2d_plus->Setup(etaj_ptj_plus, etaj_ptj_plus);
  response2d_minus->Setup(etaj_ptj_minus, etaj_ptj_minus);
  Uetaj->Setup(etaj, etaj);
  Uetaj_plus->Setup(etaj_plus, etaj_plus);
  Uetaj_minus->Setup(etaj_minus, etaj_minus);
  Uptj->Setup(ptj, ptj);
  Uptj_plus->Setup(ptj_plus, ptj_plus);
  Uptj_minus->Setup(ptj_minus, ptj_minus);

  TFile* wmuj_mc2012_mdf = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/Wmujet.Wmunujet.MD.MC2012.root");
  TFile* wmuj_mc2012_muf = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/Wmujet.Wmunujet.MU.MC2012.root");

  TTree* wmuj_mc2012_md_t = (TTree*)wmuj_mc2012_mdf->Get("WTuple/DecayTree");
  TTree* wmuj_mc2012_mu_t = (TTree*)wmuj_mc2012_muf->Get("WTuple/DecayTree");
  
  Tree* wmuj_mc2012_md = new Tree("wmuj_mc2012_md", (TTree*)wmuj_mc2012_mdf->Get("WTuple/DecayTree"));
  Tree* wmuj_mc2012_mu = new Tree("wmuj_mc2012_mu", (TTree*)wmuj_mc2012_muf->Get("WTuple/DecayTree"));

  TCut select("muminus_PT > 20000 && muminus_nMuonsG20GeV == 0 && muminus_Hlt2SingleMuonHighPTDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonDecision_TOS ==1 && ((muminus_CaloHcalE + muminus_CaloEcalE)/muminus_P)<0.04 && muminus_InAccHcal ==1 && muminus_InAccEcal == 1 && sqrt( (muminus_jet_PX + muminus_sigjet_PX)^2 + (muminus_jet_PY + muminus_sigjet_PY)^2) > 20000 && muminus_TRACK_PCHI2 > 0.01 && sqrt(muminus_PERR2)/muminus_P < 0.1 && muminus_TRACK_nTTHits > 0");
  TCut plus("muminus_ID == -13");
  TCut minus("muminus_ID == 13" );

  TCut truejet = TCut("(muminus_truejet_PT > 12500 && muminus_truejet_ETA > 2.0 && muminus_truejet_ETA < 4.5) || (muminus_mcjet_PT > 12500 && muminus_mcjet_ETA > 2.0 && muminus_mcjet_ETA < 4.5)");
  TCut recjet  = TCut("(muminus_jet_PT > 12500 && muminus_jet_ETA > 2.0 && muminus_jet_ETA < 4.5) || (muminus_rectruejet_PT > 12500 && muminus_rectruejet_ETA > 2.0 && muminus_rectruejet_ETA < 4.5)");

  TCut selcut = select && truejet && recjet;

  cout<<"applying tcuts"<<endl;

  wmuj_mc2012_md->GetTTree()->Draw(">>list1", selcut && plus, "entrylist");
  wmuj_mc2012_mu->GetTTree()->Draw(">>list2", selcut && minus, "entrylist");
  wmuj_mc2012_md->GetTTree()->Draw(">>list3", selcut && plus, "entrylist");
  wmuj_mc2012_mu->GetTTree()->Draw(">>list4", selcut && minus, "entrylist");

  wmuj_mc2012_md->GetTTree()->SetBranchStatus("*",0);
  wmuj_mc2012_mu->GetTTree()->SetBranchStatus("*",0);

  vector<string> vars{"muminus_jet_PT", "muminus_jet_ETA", "muminus_mcjet_PT", "muminus_mcjet_ETA",
      "muminus_truejet_PT", "muminus_truejet_ETA", "muminus_rectruejet_PT", "muminus_rectruejet_ETA"};
  wmuj_mc2012_md->SetBranches(vars);
  wmuj_mc2012_mu->SetBranches(vars);
  cout<<"branches added"<<endl;

  TEntryList* mdmp = (TEntryList*)gDirectory->Get("list1");
  TEntryList* mump = (TEntryList*)gDirectory->Get("list2");
  TEntryList* mdmm = (TEntryList*)gDirectory->Get("list3");
  TEntryList* mumm = (TEntryList*)gDirectory->Get("list4");

  cout<<"preparing to loop"<<endl;
  for (int i = 0 ; i < mdmp->GetN(); ++i){
    if (i%1000 == 0) cout<<"Entry "<<i<<" of "<<mdmp->GetN()<<endl;
    int entry = mdmp->GetEntry(i);
    wmuj_mc2012_md->GetEntry(entry);
    double rec_eta  =  wmuj_mc2012_md->GetVal("muminus_jet_ETA");
    double rec_pt   =  wmuj_mc2012_md->GetVal("muminus_jet_PT")/1000.0;
    double true_eta =  wmuj_mc2012_md->GetVal("muminus_mcjet_ETA");
    double true_pt  =  wmuj_mc2012_md->GetVal("muminus_mcjet_PT")/1000.0;
    
    if (rec_pt > 12.5 && true_pt > 12.5){
      Uptj->Fill(rec_pt, true_pt);
      Uptj_plus->Fill(rec_pt, true_pt);
      jet_reco_ptj_wetacut_plus->Fill(rec_pt);
      jet_true_ptj_wetacut_plus->Fill(true_pt);
    }
    if ( rec_pt < 12.5 ){
      rec_pt  = wmuj_mc2012_md->GetVal("muminus_rectruejet_PT")/1000.0;
      rec_eta = wmuj_mc2012_md->GetVal("muminus_rectruejet_ETA");
    }
    if ( true_pt < 12.5 ){
      true_pt  = wmuj_mc2012_md->GetVal("muminus_mcjet_PT")/1000.0;
      true_eta = wmuj_mc2012_md->GetVal("muminus_mcjet_ETA");
    }

    response2d->Fill(rec_eta, rec_pt, true_eta, true_pt);
    response2d_plus->Fill(rec_eta, rec_pt, true_eta, true_pt);
    Uetaj->Fill(rec_pt, true_pt);
    Uetaj_plus->Fill(rec_pt, true_pt);
    jet_true_plus->Fill(true_eta, true_pt);
    jet_reco_plus->Fill(rec_eta, rec_pt);
    jet_reco_etaj_plus->Fill(rec_eta);
    jet_true_etaj_plus->Fill(true_eta);
    jet_reco_ptj_plus->Fill(rec_pt);
    jet_true_ptj_plus->Fill(true_pt);
  }
  for (int i = 0 ; i < mump->GetN(); ++i){
    if (i%1000 == 0) cout<<"Entry "<<i<<" of "<<mump->GetN()<<endl;
    int entry = mump->GetEntry(i);
    wmuj_mc2012_mu->GetEntry(entry);
    double rec_eta  =  wmuj_mc2012_mu->GetVal("muminus_jet_ETA");
    double rec_pt   =  wmuj_mc2012_mu->GetVal("muminus_jet_PT")/1000.0;
    double true_eta =  wmuj_mc2012_mu->GetVal("muminus_mcjet_ETA");
    double true_pt  =  wmuj_mc2012_mu->GetVal("muminus_mcjet_PT")/1000.0;
    
    if (rec_pt > 12.5 && true_pt > 12.5){
      Uptj->Fill(rec_pt, true_pt);
      Uptj_plus->Fill(rec_pt, true_pt);
      jet_reco_ptj_wetacut_plus->Fill(rec_pt);
      jet_true_ptj_wetacut_plus->Fill(true_pt);
    }
    
    if ( rec_pt < 12.5 ){
      rec_pt  = wmuj_mc2012_mu->GetVal("muminus_rectruejet_PT")/1000.0;
      rec_eta = wmuj_mc2012_mu->GetVal("muminus_rectruejet_ETA");
    }
    if ( true_pt < 12.5 ){
      true_pt  = wmuj_mc2012_mu->GetVal("muminus_mcjet_PT")/1000.0;
      true_eta = wmuj_mc2012_mu->GetVal("muminus_mcjet_ETA");
    }
    response2d->Fill(rec_eta, rec_pt, true_eta, true_pt);
    response2d_plus->Fill(rec_eta, rec_pt, true_eta, true_pt);
    Uetaj->Fill(rec_pt, true_pt);
    Uetaj_plus->Fill(rec_pt, true_pt);
    jet_true_plus->Fill(true_eta, true_pt);
    jet_reco_plus->Fill(rec_eta, rec_pt);
    jet_reco_etaj_plus->Fill(rec_eta);
    jet_true_etaj_plus->Fill(true_eta);
    jet_reco_ptj_plus->Fill(rec_pt);
    jet_true_ptj_plus->Fill(true_pt);
  }
  for (int i = 0 ; i < mdmm->GetN(); ++i){
    if (i%1000 == 0) cout<<"Entry "<<i<<" of "<<mdmm->GetN()<<endl;
    int entry = mdmm->GetEntry(i);
    wmuj_mc2012_md->GetEntry(entry);
    double rec_eta  =  wmuj_mc2012_md->GetVal("muminus_jet_ETA");
    double rec_pt   =  wmuj_mc2012_md->GetVal("muminus_jet_PT")/1000.0;
    double true_eta =  wmuj_mc2012_md->GetVal("muminus_mcjet_ETA");
    double true_pt  =  wmuj_mc2012_md->GetVal("muminus_mcjet_PT")/1000.0;
    
    
    if (rec_pt > 12.5 && true_pt > 12.5){
      Uptj->Fill(rec_pt, true_pt);
      Uptj_minus->Fill(rec_pt, true_pt);
      jet_reco_ptj_wetacut_minus->Fill(rec_pt);
      jet_true_ptj_wetacut_minus->Fill(true_pt);
    }
    
    if ( rec_pt < 12.5 ){
      rec_pt  = wmuj_mc2012_md->GetVal("muminus_rectruejet_PT")/1000.0;
      rec_eta = wmuj_mc2012_md->GetVal("muminus_rectruejet_ETA");
    }
    if ( true_pt < 12.5 ){
      true_pt  = wmuj_mc2012_md->GetVal("muminus_mcjet_PT")/1000.0;
      true_eta = wmuj_mc2012_md->GetVal("muminus_mcjet_ETA");
    }
    Uetaj->Fill(rec_eta, true_eta);
    Uetaj_minus->Fill(rec_eta, true_eta);
    response2d->Fill(rec_eta, rec_pt, true_eta, true_pt);
    response2d_minus->Fill(rec_eta, rec_pt, true_eta, true_pt);
    jet_true_minus->Fill(true_eta, true_pt);
    jet_reco_minus->Fill(rec_eta, rec_pt);
    jet_reco_etaj_minus->Fill(rec_eta);
    jet_true_etaj_minus->Fill(true_eta);
    jet_reco_ptj_minus->Fill(rec_pt);
    jet_true_ptj_minus->Fill(true_pt);
  }
  for (int i = 0 ; i < mumm->GetN(); ++i){
    if (i%1000 == 0) cout<<"Entry "<<i<<" of "<<mumm->GetN()<<endl;
    int entry = mumm->GetEntry(i);
    wmuj_mc2012_mu->GetEntry(entry);
    double rec_eta  =  wmuj_mc2012_md->GetVal("muminus_jet_ETA");
    double rec_pt   =  wmuj_mc2012_md->GetVal("muminus_jet_PT")/1000.0;
    double true_eta =  wmuj_mc2012_md->GetVal("muminus_mcjet_ETA");
    double true_pt  =  wmuj_mc2012_md->GetVal("muminus_mcjet_PT")/1000.0;
    
    if (rec_pt > 12.5 && true_pt > 12.5){
      Uptj->Fill(rec_pt, true_pt);
      Uptj_minus->Fill(rec_pt, true_pt);
      jet_reco_ptj_wetacut_minus->Fill(rec_pt);
      jet_true_ptj_wetacut_minus->Fill(true_pt);
    }
    
    if ( rec_pt < 12.5 ){
      rec_pt  = wmuj_mc2012_md->GetVal("muminus_rectruejet_PT")/1000.0;
      rec_eta = wmuj_mc2012_md->GetVal("muminus_rectruejet_ETA");
    }
    if ( true_pt < 12.5 ){
      true_pt  = wmuj_mc2012_md->GetVal("muminus_mcjet_PT")/1000.0;
      true_eta = wmuj_mc2012_md->GetVal("muminus_mcjet_ETA");
    }
    Uetaj->Fill(rec_eta, true_eta);
    Uetaj_minus->Fill(rec_eta, true_eta);
    response2d->Fill(rec_eta, rec_pt, true_eta, true_pt);
    response2d_minus->Fill(rec_eta, rec_pt, true_eta, true_pt);
    jet_true_minus->Fill(true_eta, true_pt);
    jet_reco_minus->Fill(rec_eta, rec_pt);
    jet_reco_etaj_minus->Fill(rec_eta);
    jet_true_etaj_minus->Fill(true_eta);
    jet_reco_ptj_minus->Fill(rec_pt);
    jet_true_ptj_minus->Fill(true_pt);
  }
  
  RooUnfoldBayes unfold_plus(response2d, jet_reco_plus, 3);
  RooUnfoldBayes unfold_plus_plus(response2d_plus, jet_reco_plus, 3);
  RooUnfoldBayes unfold_plus_minus(response2d_minus, jet_reco_plus, 3);
  RooUnfoldBayes unfold_minus(response2d, jet_reco_minus, 3);
  RooUnfoldBayes unfold_minus_plus(response2d_plus, jet_reco_minus, 3);
  RooUnfoldBayes unfold_minus_minus(response2d_minus, jet_reco_minus, 3);
  
  RooUnfoldBayes unfold_ptj_plus(Uptj, jet_reco_plus, 3);
  RooUnfoldBayes unfold_ptj_plus_plus(response2d_plus, jet_reco_plus, 3);
  RooUnfoldBayes unfold_ptj_plus_minus(response2d_minus, jet_reco_plus, 3);
  RooUnfoldBayes unfold_ptj_minus(response2d, jet_reco_minus, 3);
  RooUnfoldBayes unfold_ptj_minus_plus(response2d_plus, jet_reco_minus, 3);
  RooUnfoldBayes unfold_ptj_minus_minus(response2d_minus, jet_reco_minus, 3);
  
  TH2D* plus_unfolded = (TH2D*)unfold_plus.Hreco();
  TH2D* minus_unfolded = (TH2D*)unfold_minus.Hreco();
  
  TH2D* plus_unfolded_plus = (TH2D*)unfold_plus_plus.Hreco();
  TH2D* minus_unfolded_plus = (TH2D*)unfold_minus_plus.Hreco();
  
  TH2D* plus_unfolded_minus = (TH2D*)unfold_plus_minus.Hreco();
  TH2D* minus_unfolded_minus = (TH2D*)unfold_minus_minus.Hreco();
  
  
  TFile g("/user2/sfarry/WJet/tuples/unfold.root", "RECREATE");
  jet_true_plus->Write();
  jet_reco_plus->Write();
  jet_true_minus->Write();
  jet_reco_minus->Write();
  jet_reco_ptj_plus->Write();
  jet_reco_ptj_minus->Write();
  jet_reco_ptj_wetacut_plus->Write();
  jet_reco_ptj_wetacut_minus->Write();
  jet_reco_etaj_plus->Write();
  jet_reco_etaj_minus->Write();
  jet_true_ptj_plus->Write();
  jet_true_ptj_minus->Write();
  jet_true_ptj_wetacut_plus->Write();
  jet_true_ptj_wetacut_minus->Write();
  jet_true_etaj_plus->Write();
  jet_true_etaj_minus->Write();
  plus_unfolded->Write("jet_plus_unfolded");
  minus_unfolded->Write("jet_minus_unfolded");
  plus_unfolded_plus->Write("jet_plus_unfolded_plus");
  plus_unfolded_minus->Write("jet_plus_unfolded_minus");
  minus_unfolded_plus->Write("jet_minus_unfolded_plus");
  minus_unfolded_minus->Write("jet_minus_unfolded_minus");
  /*
  plus_unfolded->Write();
  minus_unfolded->Write();
  plus_unfolded_plus->Write();
  plus_unfolded_minus->Write();
  minus_unfolded_plus->Write();
  minus_unfolded_minus->Write();
  */
}
