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
#include <TMVA/Tools.h>
#include <TMVA/Reader.h>
#include <TRandom3.h>

using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems){
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

std::vector<std::string> split(const std::string &s, char delim){
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
  
}

int main(int argc, char** argv){
  string input  = "/hepstore/sfarry/WMu.WTauNu.MC11.root";
  string output = "WMu.WTauNu.MC11.IPSmear.root";

  string label = "muminus";

  if ( argc >= 2 ){
    input = argv[1];
    stringstream s;
    s<<input;
    input = s.str();
    std::vector<string> temp = split(input, '.');
    std::vector<string> dpns = split(input, '/');
    string loc = "/user2/sfarry/WJet/tuples/";
    string mva = ".jecvars.";
    cout<<dpns.size()<<" "<<dpns.at(0)<<" "<<dpns.at(1)<<endl;
    if (dpns.size() == 2 && strcmp(dpns.at(0).c_str(),"dpm") == 0){
      input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/"+dpns[1];
      std::vector<string> temp2 = split(dpns[1],'.');
      if (temp2.size() == 4){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + mva + temp.at(3);
      }
      else if (temp2.size() == 5){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + '.' + temp2.at(3) + mva +temp2.at(4);
      }
    }
    else if (dpns.size() == 2 && strcmp(dpns.at(0).c_str(),"eos") == 0){
      input = "root://eoslhcb.cern.ch///eos/lhcb/user/s/sfarry/WJets/"+dpns[1];
      std::vector<string> temp2 = split(dpns[1],'.');
      if (temp2.size() == 4){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + mva + '.' + temp.at(3);
      }
      else if (temp2.size() == 5){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + '.' + temp2.at(3) + mva +temp2.at(4);
      }
    }
    else{
      output = "";
      for (unsigned int i = 0 ; i < temp.size()-1; ++i) {
	output+=temp.at(i);
	output+=".";
      }
      output+="MVA.root";
    }
  }
  if ( argc >=3 ){
    output = argv[2];
  }

  cout<<"Input File:  "<<input<<"---------------------"<<endl;
  cout<<"Output File: "<<output<<"-----------------"<<endl;


  TFile* f = TFile::Open(input.c_str());
  TTree* t = (TTree*)f->Get("WTuple/DecayTree");
  if (!t) t = (TTree*)f->Get("TupleOS/DecayTree");
  if (!t) {
    t = (TTree*)f->Get("ZMuMu/DecayTree");
    label = "boson";
  }

  Double_t        muminus_jet_PT;
  Double_t        muminus_jet_ETA;
  Double_t        muminus_jet_PHI;
  Double_t        muminus_jet_cpf;
  Double_t        muminus_jet_jec;
  Int_t           nPVs;

  //Load root file for jet energy corections
  TFile* histosJEC_f = new TFile("/cvmfs/lhcb.cern.ch/lib/lhcb/PARAM/ParamFiles/v8r18/data/JetEnergyCorrections_R05_v3.root");
  TH1D* histosJEC[4][11][4][3];
  int npvbins = 4, netabins =11, nphibins=3, ncpfbins=4;
  for(int inpvs=0; inpvs<npvbins; ++inpvs) for (int ieta=0; ieta<netabins; ++ieta)
				       for(int icpf=0; icpf<ncpfbins;++icpf) for(int iphi = 0; iphi<nphibins; ++iphi){
					   ostringstream histoname;
					   histoname<<"JECSYS_PV"<<inpvs+1
						    <<"_ETA"<<ieta
						    <<"_CPF"<<icpf
						    <<"_PHI"<<iphi;
					   histosJEC[inpvs][ieta][icpf][iphi] = (TH1D*)histosJEC_f->Get((""+histoname.str()).c_str());
					 }

  TFile* modelerr_f = new TFile("/afs/cern.ch/user/w/wbarter/public/ForJets/overall.root");
  TH2D* modelerr    = (TH2D*)(modelerr_f->Get("overall"));


  cout<<"About to output to "<<output<<endl;
  t->SetBranchStatus("*",0);
  
  t->SetBranchStatus((label+"_jet_PT" ).c_str(), 1);
  t->SetBranchStatus((label+"_jet_ETA").c_str(), 1);
  t->SetBranchStatus((label+"_jet_PHI").c_str(), 1);
  t->SetBranchStatus((label+"_jet_cpf").c_str(), 1);
  t->SetBranchStatus((label+"_jet_jec").c_str(), 1);
  t->SetBranchStatus("nPVs"          , 1);
  
  t->SetBranchAddress((label+"_jet_PT" ).c_str() , &muminus_jet_PT  );
  t->SetBranchAddress((label+"_jet_ETA").c_str() , &muminus_jet_ETA );
  t->SetBranchAddress((label+"_jet_PHI").c_str() , &muminus_jet_PHI );
  t->SetBranchAddress((label+"_jet_cpf").c_str() , &muminus_jet_cpf );
  t->SetBranchAddress((label+"_jet_jec").c_str() , &muminus_jet_jec );
  t->SetBranchAddress("nPVs"            , &nPVs            );

   Long64_t nentries = t->GetEntriesFast();

   double jet_pt_jecup = -1.0, jet_pt_jecdown = -1.0, jet_pt_smear = -1.0, jet_pt_jecerr = -1.0, jet_pt_jecmcup = -1.0, jet_pt_jecmcdown = -1.0, jet_jec_modelerr = -1.0, jet_jec = -1.0;

   TFile* g = new TFile(output.c_str(),"RECREATE");
   TTree* tree = new TTree("tree","tree");
   TH1F* cpf        = new TH1F("cpf","cpf", 100, 0, 1);
   TH1F* cpf_before = new TH1F("cpf_before","cpf_before", 100, 0, 1);
   
   tree->Branch((label + "_jet_manual_jec"  ).c_str() , &jet_jec          ,  (label+"_jet_manual_jec/D"  ).c_str());
   tree->Branch((label + "_jet_PT_jecup"    ).c_str() , &jet_pt_jecup     ,  (label+"_jet_PT_jecup/D"    ).c_str());
   tree->Branch((label + "_jet_PT_jecdown"  ).c_str() , &jet_pt_jecdown   ,  (label+"_jet_PT_jecdown/D"  ).c_str());
   tree->Branch((label + "_jet_PT_smear"    ).c_str() , &jet_pt_smear     ,  (label+"_jet_PT_smear/D"    ).c_str());
   tree->Branch((label + "_jet_PT_jecerr"   ).c_str() , &jet_pt_jecerr    ,  (label+"_jet_PT_jecerr/D"   ).c_str());
   tree->Branch((label + "_jet_PT_jecmcup"  ).c_str() , &jet_pt_jecmcup   ,  (label+"_jet_PT_jecmcup/D"  ).c_str());
   tree->Branch((label + "_jet_PT_jecmcdown").c_str() , &jet_pt_jecmcdown ,  (label+"_jet_PT_jecmcdown/D").c_str());
   tree->Branch((label + "_jet_jec_modelerr").c_str() , &jet_jec_modelerr ,  (label+"_jet_jec_modelerr/D").c_str());
   
   TRandom3 r;
      
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = t->LoadTree(jentry);
      if (ientry < 0) break;
      nb = t->GetEntry(jentry);   nbytes += nb;
      jet_pt_jecup = -1.0, jet_pt_jecdown = -1.0, jet_pt_smear = -1.0, jet_pt_jecerr = -1.0, jet_pt_jecmcup = -1.0, jet_pt_jecmcdown = -1.0, jet_jec_modelerr = -1.0, jet_jec = -1.0;

      if (jentry%10000==0) cout<<"Entry "<<jentry<<" of "<<nentries<<endl;
      if (muminus_jet_PT != -1)
	{
      double jetpt   = muminus_jet_PT/(muminus_jet_jec*1000.);
      double jeteta  = muminus_jet_ETA;
      double jetphi  = muminus_jet_PHI;
      double jetcpf  = muminus_jet_cpf;
      int npv       = nPVs;

      if (npv == 0 ) npv = npvbins + 1;
      if (npv > npvbins-1) npv = npvbins;


      if (jetpt  < 5   ) jetpt  = 5;
      if (jetpt  > 299 ) jetpt  = 298;
      if (jeteta < 2.05) jeteta = 2.05;
      if (jeteta > 4.4 ) jeteta = 4.45;
      if (jetcpf < 0.2 ) jetcpf = 0.2;
      if (jetcpf > 0.99) jetcpf = 0.99;

      cpf_before->Fill(muminus_jet_cpf);
      cpf->Fill(jetcpf);

      float auxjetphi = TMath::Abs(TMath::Abs(jetphi)-TMath::Pi()/2.);
      float jetetalimits[12]={2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.8,3.0,3.2,3.8,4.5};
      float jetcpflimits[5]={0.1,0.3,0.5,0.7,1.0};
      float pi = TMath::Pi();
      float jetphilimits[4]={0,((float)(1.0/3.0*(0.5*(pi)))),((float)(2.0/3.0*(0.5*(pi)))),((float)(0.5*(pi)))};
      int ijeteta=0; while(jeteta>jetetalimits[ijeteta]) ijeteta++; ijeteta--;
      int ijetcpf=0; while(jetcpf>jetcpflimits[ijetcpf]) ijetcpf++; ijetcpf--;
      int ijetphi=0; while(auxjetphi>jetphilimits[ijetphi]) ijetphi++; ijetphi--;

      TH1D* histo = histosJEC[npv-1][ijeteta][ijetcpf][ijetphi];
      double cor = 1.;
      cor = histo->Interpolate(jetpt);
      double corerr = histo->GetBinError(histo->FindBin(jetpt));
      
      //cout<<cor<<" +/- "<<corerr<<" ("<<corerr*100/cor<<"%)"<<endl;

      jet_pt_jecup    = muminus_jet_PT* (cor + corerr) / cor;
      jet_pt_jecdown  = muminus_jet_PT* (cor - corerr) / cor;
      jet_pt_smear    = muminus_jet_PT* r.Gaus(1.0, 0.1);
      jet_pt_jecerr   = corerr;
      jet_jec         = cor;
      
      jet_jec_modelerr = modelerr->GetBinContent(modelerr->FindBin(muminus_jet_PT/1000., muminus_jet_ETA));

      jet_pt_jecmcup    = muminus_jet_PT* (1 + jet_jec_modelerr);
      jet_pt_jecmcdown  = muminus_jet_PT* (1 - jet_jec_modelerr);
      //if (abs(muminus_jet_jec - jet_jec) < 0.00001) cout<<"MATCH!!!!"<<endl;
      //cout<<muminus_jet_jec<<" "<<jet_jec<<endl;
      //cout<<nPVs<<" "<<npv<<endl;
      //cout<<muminus_jet_ETA<<" "<<ijeteta<<endl;
      //cout<<muminus_jet_PHI<<" "<<ijetphi<<endl;
      //cout<<muminus_jet_cpf<<" "<<ijetcpf<<endl;
      //cout<<histo->GetName()<<endl;
      /*
      for(int inpvs=0; inpvs<npvbins; ++inpvs) for (int ieta=0; ieta<netabins; ++ieta)
				       for(int icpf=0; icpf<ncpfbins;++icpf) for(int iphi = 0; iphi<nphibins; ++iphi){
					   TH1D* histo2 = histosJEC[inpvs][ieta][icpf][iphi];
					   double cor_guess = 1;
					   cor_guess = histo2->Interpolate(jetpt);
					   if (abs(cor_guess - muminus_jet_jec) < 0.0001) cout<<"matched: "<<cor_guess<<" "<<inpvs<<" "<<ieta<<" "<<icpf<<" "<<iphi<<endl;
					   
					   }
      
      if (npv != 4 && npv !=1){
	TH1D* histo2 = histosJEC[npv][ijeteta][ijetcpf][ijetphi];
	TH1D* histo3 = histosJEC[npv-2][ijeteta][ijetcpf][ijetphi];
	double cor2 = 1.;
	cor2 = histo2->Interpolate(jetpt);
	double cor3 = 1.;
	cor3 = histo3->Interpolate(jetpt);

	//double corerr = histo2->GetBinError(histo->FindBin(jetpt));
	}*/

	}


      tree->Fill();
      

   }
   tree->Write();
   cpf_before->Write();
   g->Close();


  return 0;
}
