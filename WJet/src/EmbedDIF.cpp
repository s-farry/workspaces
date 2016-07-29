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
#include <dif.h>


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

  if ( argc >= 2 ){
    input = argv[1];
    stringstream s;
    s<<input;
    input = s.str();
    std::vector<string> temp = split(input, '.');
    std::vector<string> dpns = split(input, '/');
    string loc = "/user2/sfarry/WJet/tuples/";
    string mva = ".dif.";
    if (dpns.size() == 2 && strcmp(dpns.at(0).c_str(),"dpm") == 0){
      input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJet/"+dpns[1];
      std::vector<string> temp2 = split(dpns[1],'.');
      if (temp2.size() == 3){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+mva+temp2.at(2);
      }
      else if (temp2.size() == 4){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + mva +temp2.at(3);
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

  // IP VARIABLES
  Double_t        muminus_PX;
  Double_t        muminus_PY;
  Double_t        muminus_PZ;
  Double_t        muminus_PT;
  Double_t        muminus_P;

   TBranch        *b_muminus_PX;
   TBranch        *b_muminus_PY;
   TBranch        *b_muminus_PZ;
   TBranch        *b_muminus_PT;
   TBranch        *b_muminus_P;

   cout<<"About to output to "<<output<<endl;
   t->SetBranchStatus("*",0);

   t->SetBranchStatus("muminus_P", 1);
   t->SetBranchStatus("muminus_PT", 1);
   t->SetBranchStatus("muminus_PX", 1);
   t->SetBranchStatus("muminus_PY", 1);
   t->SetBranchStatus("muminus_PZ", 1);
   t->SetBranchStatus("muminus_P", 1);

   t->SetBranchAddress("muminus_P", &muminus_P, &b_muminus_P);
   t->SetBranchAddress("muminus_PT", &muminus_PT, &b_muminus_PT);
   t->SetBranchAddress("muminus_PX", &muminus_PX, &b_muminus_PX);
   t->SetBranchAddress("muminus_PY", &muminus_PY, &b_muminus_PY);
   t->SetBranchAddress("muminus_PZ", &muminus_PZ, &b_muminus_PZ);
   t->SetBranchAddress("muminus_P", &muminus_P, &b_muminus_P);



   Long64_t nentries = t->GetEntriesFast();

   double dif_mu_px = 0.0, dif_mu_py = 0.0, dif_mu_pz = 0.0, dif_mu_pt, dif_mu_p;
   double dif_nu_px = 0.0, dif_nu_py = 0.0, dif_nu_pz = 0.0, dif_nu_pt, dif_nu_p;
   double dif_w;

   TFile* g = new TFile(output.c_str(),"RECREATE");
   TTree* tree = new TTree("tree","tree");

   tree->Branch("dif_mu_px", &dif_mu_px,  "dif_mu_px/D");
   tree->Branch("dif_mu_py", &dif_mu_py,  "dif_mu_py/D");
   tree->Branch("dif_mu_pz", &dif_mu_pz,  "dif_mu_pz/D");
   tree->Branch("dif_mu_pt", &dif_mu_pt,  "dif_mu_pt/D");
   tree->Branch("dif_mu_p" , &dif_mu_p ,  "dif_mu_p/D");

   tree->Branch("dif_nu_px", &dif_nu_px,  "dif_nu_px/D");
   tree->Branch("dif_nu_py", &dif_nu_py,  "dif_nu_py/D");
   tree->Branch("dif_nu_pz", &dif_nu_pz,  "dif_nu_pz/D");
   tree->Branch("dif_nu_pt", &dif_nu_pt,  "dif_nu_pt/D");
   tree->Branch("dif_nu_p" , &dif_nu_p ,  "dif_nu_p/D");

   tree->Branch("dif_w", &dif_w, "dif_w/D");
   
   TRandom3 r;
      
   DiF dif;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = t->LoadTree(jentry);
      if (ientry < 0) break;
      nb = t->GetEntry(jentry);   nbytes += nb;

      if (jentry%10000==0) cout<<"Entry "<<jentry<<" of "<<nentries<<endl;
      
      // Create a pion.
      TLorentzVector pion(muminus_PX, muminus_PY, muminus_PZ, 0);
      pion.SetE(sqrt(pion.P() * pion.P() + 139.6 * 139.6));
      
      // Decay it.
      vector<TLorentzVector> children = dif.decay(pion);
      pair<double, double> weight = dif.weight(pion);

      TLorentzVector muon = children[0];
      TLorentzVector neut = children[1];
      dif_mu_px = muon.Px();
      dif_mu_py = muon.Py();
      dif_mu_pz = muon.Pz();
      dif_mu_pt = muon.Pt();
      dif_mu_p  = muon.P();
      
      dif_nu_px = neut.Px();
      dif_nu_py = neut.Py();
      dif_nu_pz = neut.Pz();
      dif_nu_pt = neut.Pt();
      dif_nu_p  = neut.P();

      dif_w = weight.first;

      /*
      cout <<   "pion:     "; embed.print(pion);
      cout << "\nmuon:     "; embed.print(children[0]);
      cout << "\nneutrino: "; embed.print(children[1]);
      cout << "\ncheck:    "; embed.print(children[0] + children[1] - pion);
      cout << "\n";
      */
      
      tree->Fill();
      

   }
   tree->Write();
   g->Close();


  return 0;
}
