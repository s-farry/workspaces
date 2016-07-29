#include <iostream>
#include <TMath.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TH2.h>
#include <TH1.h>
#include <TFile.h>
#include <TF1.h>
#include <TRandom3.h>
#include <TStyle.h>
#include <TF2.h>
#include <TString.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TProfile.h>
#include <fstream>
#include <TLegend.h>
#include <TTree.h>

//Define Pi
double pi = TMath::Pi();

double phi(double py, double px){
  return atan2(py,px);
}

double totMom(double px, double py, double pz) {
  double mom = sqrt(pz*pz+px*px+py*py);
  return mom;
}

double eta(double px,double py,double pz){
  double totalP = totMom(px,py,pz);
  double etaVal = 0.5*log((totalP+pz)/(totalP-pz));
  return etaVal;
}

double rap(double pz,double pe){
  double rapVal = 0.5*log((pe+pz)/(pe-pz));
  return rapVal;
}

double delta_phi(double phi1, double phi2){
  double diff = phi1-phi2;
  if (diff >pi){
    diff = diff-(2*pi);
  }
  if (diff < -1.0*pi) {
    diff = diff+(2*pi);
  }
  return abs(diff);
}

int counterWdata_unbal = 0;
int counterWmc_unbal = 0;
int counterWmc_bal = 0;
int counterWmc_bal_events = 0;
int counterWmc_unbal_events = 0;
TH1D * Zdatatemplate_bal = new TH1D("Zdatatemplate_bal","Zdatatemplate_bal",20,0,1);
TH1D * Zmctemplate_bal = new TH1D("Zmctemplate_bal","Zmctemplate_bal",20,0,1);
TH1D * Wmctemplate_bal = new TH1D("Wmctemplate_bal","Wmctemplate_bal",20,0,1);

TH1D * Zdatatemplate_unbal = new TH1D("Zdatatemplate_unbal","Zdatatemplate_unbal",20,0,1);
TH1D * Zmctemplate_unbal = new TH1D("Zmctemplate_unbal","Zmctemplate_unbal",20,0,1);
TH1D * Wmctemplate_unbal = new TH1D("Wmctemplate_unbal","Wmctemplate_unbal",20,0,1);

TH1D * datamc_correction_bal = new TH1D("datamc_correction_bal","datamc_correction_bal",20,0,1);
TH1D * datamc_correction_unbal = new TH1D("datamc_correction_unbal","datamc_correction_unbal",20,0,1);

TH1D * qcdtemplate_bal = new TH1D("qcdtemplate_bal","qcdtemplate_bal",20,0,1);
TH1D * dist = new TH1D("dist","dist",20,0,1);

TH1D * fitsum = new TH1D("fitsum","fitsum",20,0,1);
TH1D * ptdist_unbal = new TH1D("ptdist_unbal","ptdist_unbal",80,20,100);
TH1D * ptdist_bal = new TH1D("ptdist_bal","ptdist_bal",80,20,100);
TH1D * weight = new TH1D("weight","weight",80,20,100);

void SigShape_WMC(){
  TChain *t1 = new TChain("WTuple/DecayTree");
 
  double muminus_PT,muminus_ETA,muminus_TRACK_PCHI2;
  bool muminus_L0, muminus_HLT1,muminus_HLT2;
  double boson_jet_PT, boson_jet_PX, boson_jet_PY, boson_jet_PZ, boson_jet_ETA;
  double muminus_sigjet_PT, muminus_sigjet_PX, muminus_sigjet_PY, muminus_sigjet_PZ;
  int muminus_ID;
  double muminus_ipubs;
  int totCandidates;
  double muminus_CaloHcalE, muminus_CaloEcalE;
  double muminus_P;
  double muminus_TRACK_nTTHits;
  TFile* mu = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/WMuJet.MU.2012.root")
  TFile* md = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/WMuJet.MD.2012.root")

  t1 -> Add(mu);
  t1 -> Add(md);
    
  t1 -> SetBranchAddress("muminus_L0MuonDecision_TOS",& muminus_L0);
  t1 -> SetBranchAddress("muminus_Hlt1SingleMuonHighPTDecision_TOS",& muminus_HLT1);
  t1 -> SetBranchAddress("muminus_Hlt2SingleMuonHighPTDecision_TOS",& muminus_HLT2);
  t1 -> SetBranchAddress("muminus_PT",&muminus_PT);
  t1 -> SetBranchAddress("muminus_P",&muminus_P);
  t1 -> SetBranchAddress("muminus_ETA",&muminus_ETA);
  t1 -> SetBranchAddress("muminus_TRACK_PCHI2",&muminus_TRACK_PCHI2);
  t1 -> SetBranchAddress("muminus_CaloHcalE",&muminus_CaloHcalE);
  t1 -> SetBranchAddress("muminus_CaloEcalE",&muminus_CaloEcalE);
  t1 -> SetBranchAddress("muminus_TRACK_nTTHits",&muminus_TRACK_nTTHits);
  
  t1 -> SetBranchAddress("muminus_jet_PX",&boson_jet_PX);
  t1 -> SetBranchAddress("muminus_jet_PY",&boson_jet_PY);
  t1 -> SetBranchAddress("muminus_jet_PZ",&boson_jet_PZ);
  t1 -> SetBranchAddress("muminus_jet_PT",&boson_jet_PT);
  t1 -> SetBranchAddress("muminus_jet_ETA",&boson_jet_ETA);
  
  t1 -> SetBranchAddress("muminus_sigjet_PX",&muminus_sigjet_PX);
  t1 -> SetBranchAddress("muminus_sigjet_PY",&muminus_sigjet_PY);
  t1 -> SetBranchAddress("muminus_sigjet_PZ",&muminus_sigjet_PZ);
  t1 -> SetBranchAddress("muminus_sigjet_PT",&muminus_sigjet_PT);

  t1->SetBranchAddress("muminus_ID",&muminus_ID);
  t1->SetBranchAddress("muminus_ipubs",&muminus_ipubs);
  t1->SetBranchAddress("totCandidates",&totCandidates);
  int i =0;
  int nentries = t1->GetEntries();
  std::cout<<"Looping over "<<nentries<<std::endl;
  for (; i<nentries; i++) {
    if (i% 50000 == 0){std::cout<<i<<std::endl;}
    t1 -> GetEntry(i);
    if(muminus_ETA <3.5){continue;}
    if ( muminus_ID != -13 || totCandidates > 1 || muminus_TRACK_nTTHits<0.5){continue;}
   
    double calo_e = muminus_CaloEcalE + muminus_CaloHcalE;
    if ( muminus_PT > 20000 &&  muminus_ETA>2.0 && muminus_ETA<4.5 &&  muminus_TRACK_PCHI2 > 0.01 && calo_e < 0.04*muminus_P && calo_e > -0.5 &&muminus_ipubs < 0.04 && muminus_CaloEcalE>-0.50 && muminus_CaloHcalE > -0.50 ){
      if(muminus_L0 && muminus_HLT1 && muminus_HLT2){
	if(boson_jet_PT > 20000){
	
	  double balance = sqrt((muminus_sigjet_PX+boson_jet_PX)*(muminus_sigjet_PX+boson_jet_PX)+(muminus_sigjet_PY+boson_jet_PY)*(muminus_sigjet_PY+boson_jet_PY))/1000.0;
	  if(muminus_PT/muminus_sigjet_PT > 0.99){muminus_PT = 0.99*muminus_sigjet_PT;}
	  double isolation = muminus_PT / muminus_sigjet_PT;
	  if(balance<20){
	    int bin = (muminus_sigjet_PT/1000.0) -20.0;
	    Wmctemplate_bal->Fill(muminus_PT / muminus_sigjet_PT, weight->GetBinContent(bin+1));
	    counterWmc_bal++;
	    counterWmc_bal_events++;
	  }
	  if(balance > 20){
	    Wmctemplate_unbal->Fill(muminus_PT / muminus_sigjet_PT);
	    if(muminus_PT / muminus_sigjet_PT>0.95){
	      counterWmc_unbal++;
	    }
	    counterWmc_unbal_events++;
	  }
	}
      }
    }
  }
  t1->Delete();
  
}



void realWtemplates(TFile* mu, TFile* md){
  TChain *t1 = new TChain("WTuple/DecayTree");
 
  double muminus_PT,muminus_ETA,muminus_TRACK_PCHI2;
  bool muminus_L0, muminus_HLT1,muminus_HLT2;
  double boson_jet_PT, boson_jet_PX, boson_jet_PY, boson_jet_PZ, boson_jet_ETA;
  double muminus_sigjet_PT, muminus_sigjet_PX, muminus_sigjet_PY, muminus_sigjet_PZ;
  int muminus_ID;
  double muminus_ipubs;
  int totCandidates;
  double muminus_CaloHcalE, muminus_CaloEcalE;
  double muminus_P;
  double muminus_TRACK_nTTHits;
  TFile* mu = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/WMuJet.MU.2012.root");
  TFile* md = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/WMuJet.MD.2012.root");
  t1 -> Add(mu);
  t1 -> Add(md);
    
  t1 -> SetBranchAddress("muminus_L0MuonDecision_TOS",& muminus_L0);
  t1 -> SetBranchAddress("muminus_Hlt1SingleMuonHighPTDecision_TOS",& muminus_HLT1);
  t1 -> SetBranchAddress("muminus_Hlt2SingleMuonHighPTDecision_TOS",& muminus_HLT2);
  t1 -> SetBranchAddress("muminus_PT",&muminus_PT);
  t1 -> SetBranchAddress("muminus_P",&muminus_P);
  t1 -> SetBranchAddress("muminus_ETA",&muminus_ETA);
  t1 -> SetBranchAddress("muminus_TRACK_PCHI2",&muminus_TRACK_PCHI2);
  t1 -> SetBranchAddress("muminus_CaloHcalE",&muminus_CaloHcalE);
  t1 -> SetBranchAddress("muminus_CaloEcalE",&muminus_CaloEcalE);
  t1 -> SetBranchAddress("muminus_TRACK_nTTHits",&muminus_TRACK_nTTHits);
  
  t1 -> SetBranchAddress("muminus_jet_PX",&boson_jet_PX);
  t1 -> SetBranchAddress("muminus_jet_PY",&boson_jet_PY);
  t1 -> SetBranchAddress("muminus_jet_PZ",&boson_jet_PZ);
  t1 -> SetBranchAddress("muminus_jet_PT",&boson_jet_PT);
  t1 -> SetBranchAddress("muminus_jet_ETA",&boson_jet_ETA);
  
  t1 -> SetBranchAddress("muminus_sigjet_PX",&muminus_sigjet_PX);
  t1 -> SetBranchAddress("muminus_sigjet_PY",&muminus_sigjet_PY);
  t1 -> SetBranchAddress("muminus_sigjet_PZ",&muminus_sigjet_PZ);
  t1 -> SetBranchAddress("muminus_sigjet_PT",&muminus_sigjet_PT);

  t1->SetBranchAddress("muminus_ID",&muminus_ID);
  t1->SetBranchAddress("muminus_ipubs",&muminus_ipubs);
  t1->SetBranchAddress("totCandidates",&totCandidates);
  int i =0;
  int nentries = t1->GetEntries();
  std::cout<<"Looping over "<<nentries<<std::endl;
  for (; i<nentries; i++) {
    if (i% 50000 == 0){std::cout<<i<<std::endl;}
    t1 -> GetEntry(i);
    if(muminus_ETA <3.5){continue;}
    if ( muminus_ID != -13 || totCandidates > 1 || muminus_TRACK_nTTHits<0.5){continue;}
   
    double calo_e = muminus_CaloEcalE + muminus_CaloHcalE;
    if ( muminus_PT > 20000 &&  muminus_ETA>2.0 && muminus_ETA<4.5 &&  muminus_TRACK_PCHI2 > 0.01 && calo_e < 0.04*muminus_P && calo_e > -0.5 &&muminus_ipubs < 0.04 && muminus_CaloEcalE>-0.5 && muminus_CaloHcalE > -0.5 ){
      
      if(boson_jet_PT > 20000){
	if(muminus_L0 && muminus_HLT1 && muminus_HLT2){
	  double balance = sqrt((muminus_sigjet_PX+boson_jet_PX)*(muminus_sigjet_PX+boson_jet_PX)+(muminus_sigjet_PY+boson_jet_PY)*(muminus_sigjet_PY+boson_jet_PY))/1000.0;
	  int bin = (muminus_sigjet_PT/1000.0) -20.0;
	  if(balance<20){
	    if(muminus_PT/muminus_sigjet_PT > 0.99){muminus_PT = 0.99*muminus_sigjet_PT;}
	    qcdtemplate_bal->Fill(muminus_PT / muminus_sigjet_PT, weight->GetBinContent(bin+1));	
	  }
	  if(balance > 20){
	    if(muminus_PT/muminus_sigjet_PT > 0.99){muminus_PT = 0.99*muminus_sigjet_PT;}
	    dist -> Fill(muminus_PT / muminus_sigjet_PT);
	    if(muminus_PT / muminus_sigjet_PT>0.95){
	      counterWdata_unbal++;
	    }
	  }
	}
      }
    }
  }
  t1->Delete();
  
}

void SigShape_Zdata(){
   
  TChain *t1 = new TChain("ZMuMu/DecayTree");

  double boson_M;
  double boson_PX, boson_PY,boson_PZ,boson_PE;
  double muplus_PT,muplus_ETA,muplus_TRACK_PCHI2;
  bool muplus_L0, muplus_HLT1,muplus_HLT2;
 
  double muminus_PT,muminus_ETA,muminus_TRACK_PCHI2;
  bool muminus_L0, muminus_HLT1,muminus_HLT2;
  double boson_jet_PT, boson_jet_PX, boson_jet_PY, boson_jet_PZ, boson_jet_ETA;
  double muplus_sigjet_PT, muplus_sigjet_PX, muplus_sigjet_PY, muplus_sigjet_PZ;
  
  TFile* mu = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/ZMuMuJet.MU.2012.root");
  TFile* md = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/ZMuMuJet.MD.2012.root");

  t1 -> Add(mu);
  t1 -> Add(md);
  
  t1 -> SetBranchAddress("boson_M",&boson_M);
  t1 -> SetBranchAddress("boson_PX",&boson_PX);
  t1 -> SetBranchAddress("boson_PY",&boson_PY);
  t1 -> SetBranchAddress("boson_PZ",&boson_PZ);
  t1 -> SetBranchAddress("boson_PE",&boson_PE);
  t1 -> SetBranchAddress("muplus_L0MuonDecision_TOS",& muplus_L0);
  t1 -> SetBranchAddress("muminus_L0MuonDecision_TOS",& muminus_L0);
  t1 -> SetBranchAddress("muplus_Hlt1SingleMuonHighPTDecision_TOS",& muplus_HLT1);
  t1 -> SetBranchAddress("muplus_Hlt2SingleMuonHighPTDecision_TOS",& muplus_HLT2);
  t1 -> SetBranchAddress("muminus_Hlt1SingleMuonHighPTDecision_TOS",& muminus_HLT1);
  t1 -> SetBranchAddress("muminus_Hlt2SingleMuonHighPTDecision_TOS",& muminus_HLT2);
  t1 -> SetBranchAddress("muplus_PT",&muplus_PT);
  t1 -> SetBranchAddress("muplus_ETA",&muplus_ETA);
  t1 -> SetBranchAddress("muplus_TRACK_PCHI2",&muplus_TRACK_PCHI2);
  t1 -> SetBranchAddress("muminus_PT",&muminus_PT);
  t1 -> SetBranchAddress("muminus_ETA",&muminus_ETA);
  t1 -> SetBranchAddress("muminus_TRACK_PCHI2",&muminus_TRACK_PCHI2);
  
  t1 -> SetBranchAddress("boson_jet_PX",&boson_jet_PX);
  t1 -> SetBranchAddress("boson_jet_PY",&boson_jet_PY);
  t1 -> SetBranchAddress("boson_jet_PZ",&boson_jet_PZ);
  t1 -> SetBranchAddress("boson_jet_PT",&boson_jet_PT);
  t1 -> SetBranchAddress("boson_jet_ETA",&boson_jet_ETA);
  
  t1 -> SetBranchAddress("muplus_sigjet_PX",&muplus_sigjet_PX);
  t1 -> SetBranchAddress("muplus_sigjet_PY",&muplus_sigjet_PY);
  t1 -> SetBranchAddress("muplus_sigjet_PZ",&muplus_sigjet_PZ);
  t1 -> SetBranchAddress("muplus_sigjet_PT",&muplus_sigjet_PT);

  int i =0;
  int nentries = t1->GetEntries();
  std::cout<<"Looping over "<<nentries<<std::endl;
  for (; i<nentries; i++) {
    if (i% 50000 == 0){std::cout<<i<<std::endl;}
    t1 -> GetEntry(i);
    if(muplus_ETA <3.5){continue;}
    if (boson_M>60000 && boson_M<120000 && muplus_PT>20000 && muminus_PT > 20000 && muplus_ETA>2.0 && muplus_ETA<4.5 && muminus_ETA>2.0 && muminus_ETA<4.5 && muplus_TRACK_PCHI2 > 0.01 && muminus_TRACK_PCHI2 > 0.01){
      if((muplus_L0 && muplus_HLT1 && muplus_HLT2)||(muminus_L0&&muminus_HLT1&&muminus_HLT2)){
	if(boson_jet_PT > 20000){
	  double balance = sqrt((muplus_sigjet_PX+boson_jet_PX)*(muplus_sigjet_PX+boson_jet_PX)+(muplus_sigjet_PY+boson_jet_PY)*(muplus_sigjet_PY+boson_jet_PY))/1000.0;
	  //let's get the shape in the background enriched region...
	  if(balance<20){
	    if(muplus_PT/muplus_sigjet_PT > 0.99){muplus_PT = 0.99*muplus_sigjet_PT;}
	    int bin = (muplus_sigjet_PT/1000.0) -20.0;
	    Zdatatemplate_bal->Fill(muplus_PT / muplus_sigjet_PT, weight->GetBinContent(bin+1));	
	  }
	  if(balance>20){
	    if(muplus_PT/muplus_sigjet_PT > 0.99){muplus_PT = 0.99*muplus_sigjet_PT;}
	    Zdatatemplate_unbal->Fill(muplus_PT / muplus_sigjet_PT);	
	  }
	}
      }
    }
  }
  t1->Delete();
  
  
}





void SigShape_ZMC(){
   
  TChain *t1 = new TChain("ZMuMu/DecayTree");

  double boson_M;
  double boson_PX, boson_PY,boson_PZ,boson_PE;
  double muplus_PT,muplus_ETA,muplus_TRACK_PCHI2;
  bool muplus_L0, muplus_HLT1,muplus_HLT2;
 
  double muminus_PT,muminus_ETA,muminus_TRACK_PCHI2;
  bool muminus_L0, muminus_HLT1,muminus_HLT2;
  double boson_jet_PT, boson_jet_PX, boson_jet_PY, boson_jet_PZ, boson_jet_ETA;
  double muplus_sigjet_PT, muplus_sigjet_PX, muplus_sigjet_PY, muplus_sigjet_PZ;


  t1 -> Add("../Tuples/Wj/Zmumujet.Z_mumujet17.MU.MC2012.root");
  t1 -> Add("../Tuples/Wj/Zmumujet.Z_mumujet17.MD.MC2012.root");
  
  t1 -> SetBranchAddress("boson_M",&boson_M);
  t1 -> SetBranchAddress("boson_PX",&boson_PX);
  t1 -> SetBranchAddress("boson_PY",&boson_PY);
  t1 -> SetBranchAddress("boson_PZ",&boson_PZ);
  t1 -> SetBranchAddress("boson_PE",&boson_PE);
  t1 -> SetBranchAddress("muplus_L0MuonDecision_TOS",& muplus_L0);
  t1 -> SetBranchAddress("muminus_L0MuonDecision_TOS",& muminus_L0);
  t1 -> SetBranchAddress("muplus_Hlt1SingleMuonHighPTDecision_TOS",& muplus_HLT1);
  t1 -> SetBranchAddress("muplus_Hlt2SingleMuonHighPTDecision_TOS",& muplus_HLT2);
  t1 -> SetBranchAddress("muminus_Hlt1SingleMuonHighPTDecision_TOS",& muminus_HLT1);
  t1 -> SetBranchAddress("muminus_Hlt2SingleMuonHighPTDecision_TOS",& muminus_HLT2);
  t1 -> SetBranchAddress("muplus_PT",&muplus_PT);
  t1 -> SetBranchAddress("muplus_ETA",&muplus_ETA);
  t1 -> SetBranchAddress("muplus_TRACK_PCHI2",&muplus_TRACK_PCHI2);
  t1 -> SetBranchAddress("muminus_PT",&muminus_PT);
  t1 -> SetBranchAddress("muminus_ETA",&muminus_ETA);
  t1 -> SetBranchAddress("muminus_TRACK_PCHI2",&muminus_TRACK_PCHI2);
  
  t1 -> SetBranchAddress("boson_jet_PX",&boson_jet_PX);
  t1 -> SetBranchAddress("boson_jet_PY",&boson_jet_PY);
  t1 -> SetBranchAddress("boson_jet_PZ",&boson_jet_PZ);
  t1 -> SetBranchAddress("boson_jet_PT",&boson_jet_PT);
  t1 -> SetBranchAddress("boson_jet_ETA",&boson_jet_ETA);
    
  t1 -> SetBranchAddress("muplus_sigjet_PX",&muplus_sigjet_PX);
  t1 -> SetBranchAddress("muplus_sigjet_PY",&muplus_sigjet_PY);
  t1 -> SetBranchAddress("muplus_sigjet_PZ",&muplus_sigjet_PZ);
  t1 -> SetBranchAddress("muplus_sigjet_PT",&muplus_sigjet_PT);

  int i =0;
  int nentries = t1->GetEntries();
  std::cout<<"Looping over "<<nentries<<std::endl;
  for (; i<nentries; i++) {
    if (i% 50000 == 0){std::cout<<i<<std::endl;}
    t1 -> GetEntry(i);
    if(muplus_ETA <3.5){continue;}
    if (boson_M>60000 && boson_M<120000 && muplus_PT>20000 && muminus_PT > 20000 && muplus_ETA>2.0 && muplus_ETA<4.5 && muminus_ETA>2.0 && muminus_ETA<4.5 && muplus_TRACK_PCHI2 > 0.01 && muminus_TRACK_PCHI2 > 0.01){
      if((muplus_L0 && muplus_HLT1 && muplus_HLT2)||(muminus_L0&&muminus_HLT1&&muminus_HLT2)){
	if(boson_jet_PT > 20000){
	  double balance = sqrt((muplus_sigjet_PX+boson_jet_PX)*(muplus_sigjet_PX+boson_jet_PX)+(muplus_sigjet_PY+boson_jet_PY)*(muplus_sigjet_PY+boson_jet_PY))/1000.0;
	  if(balance<20){
	    if(muplus_PT/muplus_sigjet_PT > 0.99){muplus_PT = 0.99*muplus_sigjet_PT;}
	    int bin = (muplus_sigjet_PT/1000.0) -20.0;
	    Zmctemplate_bal->Fill(muplus_PT / muplus_sigjet_PT, weight->GetBinContent(bin+1));	
	  }
	  if(balance>20){
	    if(muplus_PT/muplus_sigjet_PT > 0.99){muplus_PT = 0.99*muplus_sigjet_PT;}
	    
	    Zmctemplate_unbal->Fill(muplus_PT / muplus_sigjet_PT);	
	  }
	}
      }
    }
  }
  t1->Delete();
  
  
}

void ptweight(){
  TChain *t1 = new TChain("WTuple/DecayTree");
 
  double muminus_PT,muminus_ETA,muminus_TRACK_PCHI2;
  bool muminus_L0, muminus_HLT1,muminus_HLT2;
  double boson_jet_PT, boson_jet_PX, boson_jet_PY, boson_jet_PZ, boson_jet_ETA;
  double muminus_sigjet_PT, muminus_sigjet_PX, muminus_sigjet_PY, muminus_sigjet_PZ;
  int muminus_ID;
  double muminus_ipubs;
  int totCandidates;
  double muminus_CaloHcalE, muminus_CaloEcalE;
  double muminus_P;
  double muminus_TRACK_nTTHits;
  t1 -> Add("../Tuples/Wj/WMuJet.MU.2012.root");
  t1 -> Add("../Tuples/Wj/WMuJet.MD.2012.root");
    
  t1 -> SetBranchAddress("muminus_L0MuonDecision_TOS",& muminus_L0);
  t1 -> SetBranchAddress("muminus_Hlt1SingleMuonHighPTDecision_TOS",& muminus_HLT1);
  t1 -> SetBranchAddress("muminus_Hlt2SingleMuonHighPTDecision_TOS",& muminus_HLT2);
  t1 -> SetBranchAddress("muminus_PT",&muminus_PT);
  t1 -> SetBranchAddress("muminus_P",&muminus_P);
  t1 -> SetBranchAddress("muminus_ETA",&muminus_ETA);
  t1 -> SetBranchAddress("muminus_TRACK_PCHI2",&muminus_TRACK_PCHI2);
  t1 -> SetBranchAddress("muminus_CaloHcalE",&muminus_CaloHcalE);
  t1 -> SetBranchAddress("muminus_CaloEcalE",&muminus_CaloEcalE);
  t1 -> SetBranchAddress("muminus_TRACK_nTTHits",&muminus_TRACK_nTTHits);
  
  t1 -> SetBranchAddress("muminus_jet_PX",&boson_jet_PX);
  t1 -> SetBranchAddress("muminus_jet_PY",&boson_jet_PY);
  t1 -> SetBranchAddress("muminus_jet_PZ",&boson_jet_PZ);
  t1 -> SetBranchAddress("muminus_jet_PT",&boson_jet_PT);
  t1 -> SetBranchAddress("muminus_jet_ETA",&boson_jet_ETA);
    
  t1 -> SetBranchAddress("muminus_sigjet_PX",&muminus_sigjet_PX);
  t1 -> SetBranchAddress("muminus_sigjet_PY",&muminus_sigjet_PY);
  t1 -> SetBranchAddress("muminus_sigjet_PZ",&muminus_sigjet_PZ);
  t1 -> SetBranchAddress("muminus_sigjet_PT",&muminus_sigjet_PT);

  t1->SetBranchAddress("muminus_ID",&muminus_ID);
  t1->SetBranchAddress("muminus_ipubs",&muminus_ipubs);
  t1->SetBranchAddress("totCandidates",&totCandidates);
  int i =0;
  int nentries = t1->GetEntries();
  std::cout<<"Looping over "<<nentries<<std::endl;
  for (; i<nentries; i++) {
    if (i% 50000 == 0){std::cout<<i<<std::endl;}
    t1 -> GetEntry(i);
    if(muminus_ETA <3.5){continue;}
    if ( muminus_ID != -13 || totCandidates > 1 || muminus_TRACK_nTTHits<0.5){continue;}
    double calo_e = muminus_CaloEcalE + muminus_CaloHcalE;
    if ( muminus_PT > 20000 &&  muminus_ETA>2.0 && muminus_ETA<4.5 &&  muminus_TRACK_PCHI2 > 0.01 && calo_e < 0.04*muminus_P && calo_e > -0.5 &&muminus_ipubs < 0.04  && muminus_CaloEcalE>-0.50 && muminus_CaloHcalE > -0.50){
      if(boson_jet_PT > 20000){
	if(muminus_L0 && muminus_HLT1 && muminus_HLT2){
	  double balance = sqrt((muminus_sigjet_PX+boson_jet_PX)*(muminus_sigjet_PX+boson_jet_PX)+(muminus_sigjet_PY+boson_jet_PY)*(muminus_sigjet_PY+boson_jet_PY))/1000.0;
	  //let's get the shape in the background enriched region...
	  double isolation  = 	muminus_PT/muminus_sigjet_PT ;
	  //let's get the shape in the background enriched region...
	  muminus_sigjet_PT = muminus_sigjet_PT / 1000.0;
	  if(muminus_sigjet_PT > 99.5){muminus_sigjet_PT = 99.5;}
	  if(balance > 20  && isolation < 0.8){
	    ptdist_unbal->Fill(muminus_sigjet_PT);
	  }
	  if(balance < 20 && isolation < 0.8){
	    ptdist_bal->Fill(muminus_sigjet_PT );
	  }
	}
      }
    }
  }
  t1->Delete();
}

void templategen(){
  
  ptweight();
  ptdist_unbal->Sumw2();
  ptdist_unbal->Scale(1.0/ptdist_unbal->Integral());
  ptdist_bal->Sumw2();
  ptdist_bal->Scale(1.0/ptdist_bal->Integral());
  weight->Divide(ptdist_unbal,ptdist_bal);

  for (int k = weight->GetNbinsX() ; k > 0 ; k--){
    if(weight->GetBinContent(k) < 0.0001 || weight->GetBinContent(k) > 10){
      weight->SetBinContent(k,weight->GetBinContent(k+1));
    }
  }
  
  //so I now have correct templates for signal in both regions...
  //in the balanced region, weight it to the expected number of events.

  SigShape_WMC();
  realWtemplates();
  SigShape_Zdata();
  SigShape_ZMC();


  Zmctemplate_bal->Sumw2();
  Zmctemplate_unbal->Sumw2();
  Zmctemplate_bal->Scale(1.0/Zmctemplate_bal->Integral());
  Zmctemplate_unbal->Scale(1.0/Zmctemplate_unbal->Integral());
  Zdatatemplate_bal->Sumw2();
  Zdatatemplate_unbal->Sumw2();
  Zdatatemplate_bal->Scale(1.0/Zdatatemplate_bal->Integral());
  Zdatatemplate_unbal->Scale(1.0/Zdatatemplate_unbal->Integral());
  //let's get the datamccorrection_bal;
  datamc_correction_unbal->Divide(Zdatatemplate_unbal,Zmctemplate_unbal);
  datamc_correction_bal->Divide(Zdatatemplate_bal,Zmctemplate_bal);
  
  for (int k = 0; k<Wmctemplate_unbal->GetNbinsX();k++){
    Wmctemplate_unbal->SetBinContent(k+1,Wmctemplate_unbal->GetBinContent(k+1) * datamc_correction_unbal->GetBinContent(k+1));
    Wmctemplate_bal->SetBinContent(k+1,Wmctemplate_bal->GetBinContent(k+1) * datamc_correction_bal->GetBinContent(k+1));
  }
  
  Wmctemplate_bal->Sumw2();
  Wmctemplate_bal->Scale(1.0/Wmctemplate_bal->Integral());
  //XSEC*LUMI*GEC*MURECO*MUSELECTION*JETRECO*UNFOLDING*ACCEPTANCE
  double normalisation1 = (125*2000) *0.91*0.72*0.84*0.935*1.04*1.03* counterWmc_unbal_events/(counterWmc_unbal_events + counterWmc_bal_events);
  
  double normalisation2 = counterWmc_bal * counterWdata_unbal/counterWmc_unbal;//
  std::cout<<normalisation1<<" "<<normalisation2<<std::endl;
  Wmctemplate_bal->Scale(normalisation2);
  qcdtemplate_bal->Sumw2();
  qcdtemplate_bal->Add(Wmctemplate_bal,-1.0);
  //I now have the pure qcd template...
  //let's scale it to match dist at 0.5-0.55...
  qcdtemplate_bal->Scale((dist->Integral(11,14) )/(qcdtemplate_bal->Integral(11,14))); 
  
  Wmctemplate_unbal->Sumw2();
  Wmctemplate_unbal->Scale(1.0/Wmctemplate_unbal->Integral());
  Wmctemplate_unbal->Scale((dist->Integral() - qcdtemplate_bal->Integral()) / Wmctemplate_unbal->Integral());

  TCanvas * c2 = new TCanvas();
  qcdtemplate_bal->Draw();
  Wmctemplate_bal->Draw("same");

  TCanvas * c3 = new TCanvas();
  dist->Draw();
  qcdtemplate_bal->Draw("same");
  Wmctemplate_unbal->Draw("same");
  fitsum->Add(qcdtemplate_bal,Wmctemplate_unbal);
  fitsum->Draw("same");
  
  
}
  







