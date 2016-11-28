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
    string mva = "MVA.";
    if (dpns.size() > 2 && strcmp(dpns.at(0).c_str(),"dpm") == 0){
      input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb";
      for (int i = 0 ; i < (int)dpns.size() -1; ++i) {
	input += ("/"+dpns.at(i+1));
      }
      string filename;
      std::vector<string> temp2 = split(dpns.at(dpns.size()-1),'.');
      output = loc;
      for (unsigned int i = 0 ; i < temp2.size() ; ++i){
	if (i == temp2.size()- 1) output+= mva;
	output += temp2.at(i);
	if (i != temp2.size() -1) output += ".";
      }

      /*if (temp2.size() == 3){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+mva+temp2.at(2);
      }
      else if (temp2.size() == 4){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + mva +temp2.at(3);
	}*/
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

  const char* weights  = "/user2/sfarry/workspaces/strange/cfg/weights/strange_BDT.weights.xml";
  const char* weights2 = "/user2/sfarry/workspaces/strange/cfg/weights/gluon_BDT.weights.xml";
  const char* weights3 = "/user2/sfarry/workspaces/strange/cfg/weights/vts_BDT.weights.xml";

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


  bool isJet = false;

  TFile* f = TFile::Open(input.c_str());
  TTree* t = (TTree*)f->Get("ZMuMu/DecayTree");
  if (!t) {
    t = (TTree*)f->Get("TupleOS/DecayTree");
  }
  if (!t) {
    t = (TTree*)f->Get("ZMuMu/DecayTree");
  }
  if (!t) {
    t = (TTree*)f->Get("Jet/DecayTree");
    isJet = true;
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
  Int_t jet_ndauts;
  Double_t jet_cpf;
  Double_t jet_width;
  Double_t jet_pi_dR;
  Double_t jet_M;
  Double_t jet_ETA;
  Double_t jet_charge;
  Double_t jet_leading_id;
  Double_t jet_avipchi2;
  Double_t jet_leading_ipchi2;
  
  t->SetBranchStatus("*",0);
  
  if (!isJet){

    t->SetBranchStatus("boson_jet_maxkaonpt",  1 );
    t->SetBranchStatus("boson_jet_PT"       ,  1 );
    t->SetBranchStatus("boson_jet_maxpionpt",  1 );
    t->SetBranchStatus("boson_jet_kaonpt",     1 );
    t->SetBranchStatus("boson_jet_pionpt",     1 );
    t->SetBranchStatus("boson_jet_kaonmult",   1 );
    t->SetBranchStatus("boson_jet_kaoncmult",  1 );
    t->SetBranchStatus("boson_jet_pionmult",   1 );
    t->SetBranchStatus("boson_jet_pioncmult",  1 );
    t->SetBranchStatus("boson_jet_ndauts",     1 );
    t->SetBranchStatus("boson_jet_pi_dR",      1 );
    t->SetBranchStatus("boson_jet_K_dR",       1 );
    t->SetBranchStatus("boson_jet_cpf",        1 );
    t->SetBranchStatus("boson_jet_width",      1 );
    t->SetBranchStatus("boson_jet_M"    ,      1 );
    t->SetBranchStatus("boson_jet_ETA"  ,      1 );
    t->SetBranchStatus("boson_jet_charge"  ,   1 );
    t->SetBranchStatus("boson_jet_leading_id" ,1 );
    t->SetBranchStatus("boson_jet_avipchi2"  , 1);
    t->SetBranchStatus("boson_jet_leading_ipchi2", 1);
    
    t->SetBranchAddress("boson_jet_maxkaonpt",  &jet_maxkaonpt );
    t->SetBranchAddress("boson_jet_PT"       ,  &jet_PT );
    t->SetBranchAddress("boson_jet_maxpionpt",  &jet_maxpionpt );
    t->SetBranchAddress("boson_jet_kaonpt",     &jet_kaonpt );
    t->SetBranchAddress("boson_jet_pionpt",     &jet_pionpt );
    t->SetBranchAddress("boson_jet_kaonmult",   &jet_kaonmult );
    t->SetBranchAddress("boson_jet_kaoncmult",  &jet_kaoncmult );
    t->SetBranchAddress("boson_jet_pionmult",   &jet_pionmult );
    t->SetBranchAddress("boson_jet_pioncmult",  &jet_pioncmult );
    t->SetBranchAddress("boson_jet_ndauts",     &jet_ndauts );
    t->SetBranchAddress("boson_jet_K_dR",       &jet_K_dR );
    t->SetBranchAddress("boson_jet_pi_dR",      &jet_pi_dR );
    t->SetBranchAddress("boson_jet_cpf",        &jet_cpf );
    t->SetBranchAddress("boson_jet_width",      &jet_width );
    t->SetBranchAddress("boson_jet_M"  ,        &jet_M );
    t->SetBranchAddress("boson_jet_ETA",        &jet_ETA );
    t->SetBranchAddress("boson_jet_charge"  ,        &jet_charge );
    t->SetBranchAddress("boson_jet_leading_id",        &jet_leading_id );
    t->SetBranchAddress("boson_jet_avipchi2"  , &jet_avipchi2);
    t->SetBranchAddress("boson_jet_leading_ipchi2", &jet_leading_ipchi2);

    
  }
  else{

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
    t->SetBranchStatus("jet_pi_dR",      1 );
    t->SetBranchStatus("jet_K_dR",       1 );
    t->SetBranchStatus("jet_cpf",        1 );
    t->SetBranchStatus("jet_width",      1 );
    t->SetBranchStatus("jet_M"    ,      1 );
    t->SetBranchStatus("jet_ETA"  ,      1 );
    t->SetBranchStatus("jet_charge"  ,   1 );
    t->SetBranchStatus("jet_leading_id", 1 );
    t->SetBranchStatus("jet_avipchi2"  , 1);
    t->SetBranchStatus("jet_leading_ipchi2", 1);

    
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
    t->SetBranchAddress("jet_pi_dR",      &jet_pi_dR );
    t->SetBranchAddress("jet_cpf",        &jet_cpf );
    t->SetBranchAddress("jet_width",      &jet_width );
    t->SetBranchAddress("jet_M"  ,        &jet_M );
    t->SetBranchAddress("jet_ETA",        &jet_ETA );
    t->SetBranchAddress("jet_charge",     &jet_charge );
    t->SetBranchAddress("jet_leading_id", &jet_leading_id );
    t->SetBranchAddress("jet_avipchi2"  , &jet_avipchi2);
    t->SetBranchAddress("jet_leading_ipchi2", &jet_leading_ipchi2);

  }


  std::vector<float> dummy(21,0.0);
  
  TMVA::Reader* strange_reader = new TMVA::Reader("!Color!Silent");
  strange_reader->AddVariable("jet_maxkaonpt", &dummy.at(0));
  strange_reader->AddVariable("jet_maxkaonpt/jet_PT", &dummy.at(1));
  strange_reader->AddVariable("jet_maxpionpt", &dummy.at(2));
  strange_reader->AddVariable("jet_maxpionpt/jet_PT", &dummy.at(3));
  strange_reader->AddVariable("jet_kaonpt",    &dummy.at(4));
  strange_reader->AddVariable("jet_pionpt",    &dummy.at(5));
  strange_reader->AddVariable("jet_kaonmult" , &dummy.at(6));
  strange_reader->AddVariable("jet_kaoncmult", &dummy.at(7));
  strange_reader->AddVariable("jet_pionmult" , &dummy.at(8));
  strange_reader->AddVariable("jet_pioncmult",    &dummy.at(9));
  strange_reader->AddVariable("jet_ndauts", &dummy.at(10));
  strange_reader->AddVariable("jet_PT"    , &dummy.at(11));
  strange_reader->AddVariable("jet_pi_dR"  , &dummy.at(12));
  strange_reader->AddVariable("jet_K_dR"  , &dummy.at(13));
  strange_reader->AddVariable("jet_cpf"   , &dummy.at(14));
  strange_reader->AddVariable("jet_leading_id"  , &dummy.at(15));
  strange_reader->BookMVA("BDT", weights);
  
  TMVA::Reader* gluon_reader = new TMVA::Reader("!Color!Silent");
  gluon_reader->AddVariable("jet_maxkaonpt", &dummy.at(0));
  gluon_reader->AddVariable("jet_maxkaonpt/jet_PT", &dummy.at(1));
  gluon_reader->AddVariable("jet_maxpionpt", &dummy.at(2));
  gluon_reader->AddVariable("jet_maxpionpt/jet_PT", &dummy.at(3));
  gluon_reader->AddVariable("jet_kaonpt",    &dummy.at(4));
  gluon_reader->AddVariable("jet_pionpt",    &dummy.at(5));
  gluon_reader->AddVariable("jet_kaonmult" , &dummy.at(6));
  gluon_reader->AddVariable("jet_kaoncmult", &dummy.at(7));
  gluon_reader->AddVariable("jet_pionmult" , &dummy.at(8));
  gluon_reader->AddVariable("jet_pioncmult",    &dummy.at(9));
  gluon_reader->AddVariable("jet_ndauts", &dummy.at(10));
  gluon_reader->AddVariable("jet_PT"    , &dummy.at(11));
  gluon_reader->AddVariable("jet_pi_dR"  , &dummy.at(12));
  gluon_reader->AddVariable("jet_K_dR"  , &dummy.at(13));
  gluon_reader->AddVariable("jet_cpf"   , &dummy.at(14));
  gluon_reader->AddVariable("jet_M", &dummy.at(15));
  gluon_reader->AddVariable("jet_width" , &dummy.at(16));
  gluon_reader->AddVariable("jet_leading_id"  , &dummy.at(17));
  gluon_reader->AddVariable("jet_charge"  , &dummy.at(18));
  gluon_reader->BookMVA("BDT", weights2);
  
  TMVA::Reader* vts_reader = new TMVA::Reader("!Color!Silent");
  //vts_reader->AddVariable("jet_maxkaonpt", &dummy.at(0));
  //vts_reader->AddVariable("jet_maxkaonpt/jet_PT", &dummy.at(1));
  vts_reader->AddVariable("jet_maxpionpt", &dummy.at(2));
  vts_reader->AddVariable("jet_maxpionpt/jet_PT", &dummy.at(3));
  vts_reader->AddVariable("jet_kaonpt",    &dummy.at(4));
  vts_reader->AddVariable("jet_pionpt",    &dummy.at(5));
  vts_reader->AddVariable("jet_kaonmult" , &dummy.at(6));
  vts_reader->AddVariable("jet_kaoncmult", &dummy.at(7));
  vts_reader->AddVariable("jet_pionmult" , &dummy.at(8));
  vts_reader->AddVariable("jet_pioncmult",    &dummy.at(9));
  vts_reader->AddVariable("jet_ndauts", &dummy.at(10));
  vts_reader->AddVariable("jet_PT"    , &dummy.at(11));
  vts_reader->AddVariable("jet_pi_dR"  , &dummy.at(12));
  vts_reader->AddVariable("jet_K_dR"  , &dummy.at(13));
  vts_reader->AddVariable("jet_cpf"   , &dummy.at(14));
  vts_reader->AddVariable("jet_M", &dummy.at(15));
  vts_reader->AddVariable("jet_width" , &dummy.at(16));
  vts_reader->AddVariable("jet_leading_id"  , &dummy.at(17));
  vts_reader->AddVariable("jet_avipchi2", &dummy.at(18));
  vts_reader->AddVariable("jet_leading_ipchi2", &dummy.at(19));
  vts_reader->BookMVA("BDT", weights3);

  Long64_t nentries = t->GetEntriesFast();
  double BDT1val = -1, BDT2val = -1, BDT3val = -1;
  
  TFile* g = new TFile(output.c_str(),"RECREATE");
  TTree* tree = new TTree("tree","tree");
  tree->Branch("bdt_strange",     &BDT1val     ,  "bdt_strange/D");
  tree->Branch("bdt_gluon"  ,     &BDT2val     ,  "bdt_gluon/D");
  tree->Branch("bdt_vts"    ,     &BDT3val     ,  "bdt_vts/D");

  std::vector<float> strange_input(16, -1.0);
  std::vector<float> gluon_input(19, -1.0);
  std::vector<float> vts_input(18,-1.0);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     //for (Long64_t jentry=0; jentry<10000;jentry++) {
      Long64_t ientry = t->LoadTree(jentry);
      if (ientry < 0) break;
      nb = t->GetEntry(jentry);   nbytes += nb;

      if (jentry%10000==0) cout<<"Entry "<<jentry<<" of "<<nentries<<endl;

      if (TMath::IsNaN(jet_PT)==0){
      
	strange_input.at(0)   =  jet_maxkaonpt  ;
	strange_input.at(1)   =  jet_PT > 0 ? jet_maxkaonpt/jet_PT : 0  ;
	strange_input.at(2)   =  jet_maxpionpt  ;
	strange_input.at(3)   =  jet_PT > 0 ? jet_maxpionpt/jet_PT : 0  ;
	strange_input.at(4)   =  jet_kaonpt      ;
	strange_input.at(5)   =  jet_pionpt      ;
	strange_input.at(6)   =  jet_kaonmult    ;
	strange_input.at(7)   =  jet_kaoncmult   ;
	strange_input.at(8)   =  jet_pionmult    ;
	strange_input.at(9)   =  jet_pioncmult   ;
	strange_input.at(10)  =  jet_ndauts      ;
	strange_input.at(11)  =  jet_PT          ;
	strange_input.at(12)  =  jet_pi_dR       ;
	strange_input.at(13)  =  jet_K_dR        ;
	strange_input.at(14)  =  jet_cpf         ;
	strange_input.at(15)  =  jet_leading_id   ;
      
	gluon_input.at(0)   =  jet_maxkaonpt  ;
	gluon_input.at(1)   =  jet_PT > 0 ? jet_maxkaonpt/jet_PT : 0  ;
	gluon_input.at(2)   =  jet_maxpionpt  ;
	gluon_input.at(3)   =  jet_PT > 0 ? jet_maxpionpt/jet_PT : 0  ;
	gluon_input.at(4)   =  jet_kaonpt      ;
	gluon_input.at(5)   =  jet_pionpt      ;
	gluon_input.at(6)   =  jet_kaonmult    ;
	gluon_input.at(7)   =  jet_kaoncmult   ;
	gluon_input.at(8)   =  jet_pionmult    ;
	gluon_input.at(9)   =  jet_pioncmult   ;
	gluon_input.at(10)  =  jet_ndauts      ;
	gluon_input.at(11)  =  jet_PT          ;
	gluon_input.at(12)  =  jet_pi_dR       ;
	gluon_input.at(13)  =  jet_K_dR        ;
	gluon_input.at(14)  =  jet_cpf         ;
	gluon_input.at(15)  =  jet_M           ;
	gluon_input.at(16)  =  jet_width       ;
	gluon_input.at(17)  =  jet_leading_id  ;
	gluon_input.at(18)  =  jet_charge      ;
      
	vts_input.at(0)   =  jet_maxpionpt  ;
	vts_input.at(1)   =  jet_PT > 0 ? jet_maxpionpt/jet_PT : 0  ;
	vts_input.at(2)   =  jet_kaonpt      ;
	vts_input.at(3)   =  jet_pionpt      ;
	vts_input.at(4)   =  jet_kaonmult    ;
	vts_input.at(5)   =  jet_kaoncmult   ;
	vts_input.at(6)   =  jet_pionmult    ;
	vts_input.at(7)   =  jet_pioncmult   ;
	vts_input.at(8)  =  jet_ndauts      ;
	vts_input.at(9)  =  jet_PT          ;
	vts_input.at(10)  =  jet_pi_dR       ;
	vts_input.at(11)  =  jet_K_dR        ;
	vts_input.at(12)  =  jet_cpf         ;
	vts_input.at(13)  =  jet_M           ;
	vts_input.at(14)  =  jet_width       ;
	vts_input.at(15)  =  jet_leading_id  ;
	vts_input.at(16)  =  jet_avipchi2    ;
	vts_input.at(17)  =  jet_leading_ipchi2  ;

	BDT1val       = strange_reader->EvaluateMVA(strange_input, "BDT");
	BDT2val       = gluon_reader->EvaluateMVA(gluon_input, "BDT");
	BDT3val       = vts_reader->EvaluateMVA(vts_input, "BDT");
      }
      else{
	BDT1val = -999;
	BDT2val = -999;
	BDT3val = -999;
      }
      tree->Fill();
   }
   tree->Write();
   TObjString* tune = new TObjString("MC2015");
   TParameter<int>* date = new TParameter<int>("Date", day + (month * 100) + (year * 10000));
   tune->Write("Tune");
   date->Write("Date");
   g->Close();
   return 0;
}
