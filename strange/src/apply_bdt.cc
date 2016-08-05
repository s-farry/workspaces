#include <iostream>
#include <sstream>
#include <iomanip>
#include <TTree.h>
#include <TCut.h>
#include <TMath.h>
#include <TObjArray.h>
#include <math.h>
#include <TH1F.h>
#include <TFile.h>
#include <TF1.h>
#include <TMVA/Tools.h>
#include <TMVA/Reader.h>
#include <TParameter.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

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
  string input  = "/hepstore/sfarry/WMu.WTauNu.MC2012.root";
  string output = "WMu.WTauNu.MC2012.MVA.root";

  if ( argc >= 2 ){
    input = argv[1];
    stringstream s;
    s<<input;
    input = s.str();
    std::vector<string> temp = split(input, '.');
    std::vector<string> dpns = split(input, '/');
    string loc = "/user2/sfarry/workspaces/strange/tuples/";
    string mva = ".MVA.";
    if (dpns.size() == 2 && strcmp(dpns.at(0).c_str(),"dpm") == 0){
      input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/"+dpns[1];
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

  const char* weights = "/user2/sfarry/workspaces/strange/cfg/weights/TMVAClassification_BDT.weights.xml";

  struct tm* clock;
  struct stat attrib;
  stat(weights, &attrib);
  clock = gmtime(&(attrib.st_mtime));
  int year = clock->tm_year + 1900;
  int month = clock->tm_mon;
  int day   = clock->tm_mday;
  cout<<"Year: "<<year<<" Month: "<<month<<" Day: "<<day<<endl;

  //stringstream outputss;
  //outputss<<output;
  //string outputS = outputss.str();

  //stringstream inputss;
  //inputss<<input;
  //string inputS = inputss.str();


  cout<<"Input File:  "<<input<<"---------------------"<<endl;
  cout<<"Output File: "<<output<<"-----------------"<<endl;


  TFile* f = TFile::Open(input.c_str());
  TTree* t = (TTree*)f->Get("ZMuMu/DecayTree");
  if (!t) {
    t = (TTree*)f->Get("TupleOS/DecayTree");
  }
  if (!t) {
    t = (TTree*)f->Get("ZMuMu/DecayTree");
  }

  // IP VARIABLES
  Double_t jet_maxkaonpt;
  Double_t jet_maxpionpt;
  Double_t jet_kaonpt;
  Double_t jet_pionpt;
  Double_t jet_kaonmult;
  Double_t jet_kaoncmult;
  Double_t jet_pionmult;
  Double_t jet_pioncmult;
  Double_t jet_K_dR;
  Double_t jet_PT;
  Double_t jet_ndauts;
  Double_t jet_cpf;
  
  t->SetBranchStatus("*",0);
  
  t->SetBranchStatus("jet_maxkaonpt",  1 );
  t->SetBranchStatus("jet_PT"       ,  1 );
  t->SetBranchStatus("jet_maxpionpt",  1 );
  t->SetBranchStatus("jet_kaonpt",     1 );
  t->SetBranchStatus("jet_pionpt",     1 );
  t->SetBranchStatus("jet_kaonmult",   1 );
  t->SetBranchStatus("jet_kaoncmult",  1 );
  t->SetBranchStatus("jet_pionmult",   1 );
  t->SetBranchStatus("jet_pioncmult",  1 );
  t->SetBranchStatus("jet_ndauts",     1 );
  t->SetBranchStatus("jet_K_dR",       1 );
  t->SetBranchStatus("jet_cpf",        1 );
  
  t->SetBranchAddress("jet_maxkaonpt",  &jet_maxkaonpt );
  t->SetBranchAddress("jet_PT"       ,  &jet_PT );
  t->SetBranchAddress("jet_maxpionpt",  &jet_maxpionpt );
  t->SetBranchAddress("jet_kaonpt",     &jet_kaonpt );
  t->SetBranchAddress("jet_pionpt",     &jet_pionpt );
  t->SetBranchAddress("jet_kaonmult",   &jet_kaonmult );
  t->SetBranchAddress("jet_kaoncmult",  &jet_kaoncmult );
  t->SetBranchAddress("jet_pionmult",   &jet_pionmult );
  t->SetBranchAddress("jet_pioncmult",  &jet_pioncmult );
  t->SetBranchAddress("jet_ndauts",     &jet_ndauts );
  t->SetBranchAddress("jet_K_dR",       &jet_K_dR );
  t->SetBranchAddress("jet_cpf",        &jet_cpf );
   
  std::vector<float> dummy(14,0.0);
  
  TMVA::Reader* reader = new TMVA::Reader("!Color!Silent");
  reader->AddVariable("jet_maxkaonpt", &dummy.at(0));
  reader->AddVariable("jet_maxpionpt", &dummy.at(1));
  reader->AddVariable("jet_maxkaonpt/jet_PT", &dummy.at(2));
  reader->AddVariable("jet_maxpionpt/jet_PT", &dummy.at(3));
  reader->AddVariable("jet_kaonpt",    &dummy.at(4));
  reader->AddVariable("jet_pionpt",    &dummy.at(5));
  reader->AddVariable("jet_kaonmult" , &dummy.at(6));
  reader->AddVariable("jet_kaoncmult", &dummy.at(7));
  reader->AddVariable("jet_pionmult" , &dummy.at(8));
  reader->AddVariable("jet_pioncmult",    &dummy.at(9));
  reader->AddVariable("jet_PT",    &dummy.at(10));
  reader->AddVariable("jet_K_dR" , &dummy.at(11));
  reader->AddVariable("jet_cpf", &dummy.at(12));
  reader->AddVariable("jet_ndauts", &dummy.at(13));
  reader->BookMVA("BDT", weights);

  Long64_t nentries = t->GetEntriesFast();
  double BDTval = -1;
  
  TFile* g = new TFile(output.c_str(),"RECREATE");
  TTree* tree = new TTree("tree","tree");
  tree->Branch("BDT",           &BDTval     ,  "BDT/D");

  std::vector<float> inputvector(14, -1.0);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     //for (Long64_t jentry=0; jentry<10000;jentry++) {
      Long64_t ientry = t->LoadTree(jentry);
      if (ientry < 0) break;
      nb = t->GetEntry(jentry);   nbytes += nb;

      if (jentry%10000==0) cout<<"Entry "<<jentry<<" of "<<nentries<<endl;
      
      inputvector.at(0)   =  jet_maxkaonpt  ;
      inputvector.at(1)   =  jet_maxpionpt  ;
      inputvector.at(2)   =  jet_maxkaonpt/jet_PT     ;
      inputvector.at(3)   =  jet_maxpionpt/jet_PT      ;
      inputvector.at(4)   =  jet_kaonpt      ;
      inputvector.at(5)   =  jet_pionpt      ;
      inputvector.at(6)   =  jet_kaonmult    ;
      inputvector.at(7)   =  jet_kaoncmult   ;
      inputvector.at(8)   =  jet_pionmult    ;
      inputvector.at(9)   =  jet_pioncmult   ;
      inputvector.at(10)  =  jet_PT          ;
      inputvector.at(11)  =  jet_K_dR        ;
      inputvector.at(12)  =  jet_cpf         ;
      inputvector.at(13)  =  jet_ndauts      ;
      
      BDTval       = reader->EvaluateMVA(inputvector, "BDT");
      tree->Fill();
      
   }
   tree->Write();
   TObjString* tune = new TObjString("MC2012");
   TParameter<int>* date = new TParameter<int>("Date", day + (month * 100) + (year * 10000));
   tune->Write("Tune");
   date->Write("Date");
   g->Close();
   return 0;
}
