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
#include <TEntryList.h>
#include <TH1.h>
#include <TMVA/Tools.h>
#include <TMVA/Reader.h>
#include <TMinuit.h>
#include <TParameter.h>
#include <Tune.h>
#include <Expr.h>
#include <Tree.h>
#include <Utils.h>

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

  TRandom3* r3 = new TRandom3(0);

  //Expr* dx_mu  = new Expr("mu_ipubs_dx");
  //Expr* dy_mu  = new Expr("mu_ipubs_dy");
  //Expr* dx_e  = new Expr("mu_ipubs_dx");
  //Expr* dy_e  = new Expr("mu_ipubs_dy");

  Expr* dx_zmumu  = new Expr("muplus_ipubs_dx");
  Expr* dy_zmumu  = new Expr("muminus_ipubs_dy");
  //Expr* tx  = new Expr("mu_PX/mu_PZ");
  //Expr* ty  = new Expr("mu_PY/mu_PZ");
  //Expr* cov00  = new Expr("mu_ipubs_cov00");
  //Expr* cov10  = new Expr("mu_ipubs_cov10");
  //Expr* cov11  = new Expr("mu_ipubs_cov11");

  //Load the root files for performing tuning
  TFile tuner_dx_plus("/user2/sfarry/workspaces/top/tuples/dx_etaphitune_plus.root");
  TH2F* dx_plus_s = (TH2F*)tuner_dx_plus.Get("dx_etaphitune_plus_sigma_2D");
  TH2F* dx_plus_m = (TH2F*)tuner_dx_plus.Get("dx_etaphitune_plus_mean_2D");
  
  TFile tuner_dx_minus("/user2/sfarry/workspaces/top/tuples/dx_etaphitune_minus.root");
  TH2F* dx_minus_s = (TH2F*)tuner_dx_minus.Get("dx_etaphitune_minus_sigma_2D");
  TH2F* dx_minus_m = (TH2F*)tuner_dx_minus.Get("dx_etaphitune_minus_mean_2D");

  TFile tuner_dy_plus("/user2/sfarry/workspaces/top/tuples/dy_etaphitune_plus.root");
  TH2F* dy_plus_s = (TH2F*)tuner_dy_plus.Get("dy_etaphitune_plus_sigma_2D");
  TH2F* dy_plus_m = (TH2F*)tuner_dy_plus.Get("dy_etaphitune_plus_mean_2D");
  
  TFile tuner_dy_minus("/user2/sfarry/workspaces/top/tuples/dy_etaphitune_minus.root");
  TH2F* dy_minus_s = (TH2F*)tuner_dy_minus.Get("dy_etaphitune_minus_sigma_2D");
  TH2F* dy_minus_m = (TH2F*)tuner_dy_minus.Get("dy_etaphitune_minus_mean_2D");


  //Data plus cuts for correlation matrix

  TFile* dataMUf = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MU.2016.root");
  //TFile* dataMDf = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MD.2016.root");
  Tree* datat = new Tree("data", (TTree*)dataMUf->Get("ZMuMu/DecayTree"), 1.0);
  Expr* zmumu = new Expr("boson_M > 60000 && boson_M < 120000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muplus_ETA < 4.5");

  vector<Expr*> vars;
  vars.push_back(dx_zmumu);
  vars.push_back(dy_zmumu);

  vector< vector<double> > cov = datat->getCorrelationMatrix(vars, zmumu);
  cout<<"Correlation Matrix: "<<endl;
  Utils::printMatrix(cov);

  //To Calculate Weight
  //TFile data("/user2/sfarry/WTau/python/IPchi2/ZMuMu_Data2012.root");
  //TFile mc("/user2/sfarry/WTau/python/IPchi2/ZMuMu_MC2012.root");

  //TH1F* rwtracks = Utils::GetWeightHist("rwtracks", (TH1F*)data.Get("PVMult"), (TH1F*)mc.Get("PVMult"));

  string input, output;

  if ( argc >= 2 ){
    input = argv[1];
    stringstream s;
    s<<input;
    input = s.str();
    std::vector<string> temp = split(input, '.');
    std::vector<string> dpns = split(input, '/');
    string loc = "/user2/sfarry/workspaces/top/tuples/";
    string mva = ".iptune.";
    cout<<dpns.size()<<" "<<dpns.at(0)<<" "<<dpns.at(1)<<endl;
    if (dpns.size() == 2 && strcmp(dpns.at(0).c_str(),"dpm") == 0){
      input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/"+dpns[1];
      std::vector<string> temp2 = split(dpns[1],'.');
      if (temp2.size() == 4){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + mva + temp.at(3);
      }
      else if (temp2.size() == 5){
	output = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + '.' + temp2.at(3) + mva +temp2.at(4);
      }
    }
    else if (dpns.size() == 2 && strcmp(dpns.at(0).c_str(),"eos") == 0){
      input = "root://eoslhcb.cern.ch///eos/lhcb/user/s/sfarry/top/"+dpns[1];
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
      output+="iptune.root";
    }
  }
  if ( argc >=3 ){
    output = argv[2];
  }
  /*
  if ( argc >= 2 ){
    //input = argv[1];

    stringstream s;
    s<<argv[1];
    inputS = s.str();
    std::vector<string> temp = split(inputS, '.');
    std::vector<string> dpns = split(inputS, '/');


    string loc    = "/user2/sfarry/WTau/tuples/";
    string iptune = "ipetaphitune";
    if (dpns.size() == 2 && strcmp(dpns.at(0).c_str(),"dpm") == 0){
      inputS = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/"+dpns[1];
      //input = inputS.c_str();
      std::vector<string> temp2 = split(dpns[1],'.');
      if (temp2.size() == 3){
	outputS = loc+temp2.at(0)+'.'+temp2.at(1)+iptune+temp2.at(2);
      }
      else if (temp2.size() == 4){
	outputS = loc+temp2.at(0)+'.'+temp2.at(1)+'.' + temp2.at(2) + '.'+iptune+'.' +temp2.at(3);
      }
      //output = outputS.c_str();
    }
    else{
      outputS = "";
      if (temp.size() > 1){
	for (unsigned int i = 0 ; i < temp.size()-1; ++i) {
	  outputS+=temp.at(i);
	  outputS+=".";
	}
	outputS+=iptune+'.';
	outputS+=temp.at(temp.size() -1);
      }
    }
  }
  */

  cout<<"Input File: "<<input<<endl;
  cout<<"Outputting to: "<<output<<endl;

  string var1 = "mu";
  string var2 = "e";

  TFile* f = TFile::Open(input.c_str());
  TTree* t = (TTree*)f->Get("WTuple/DecayTree");
  if (!t) {
    t = (TTree*)f->Get("ZMuMu/DecayTree");
    if (t){
      var1 = "muplus";
      var2 = "muminus";
    }
  }
  if (!t) {
    t = (TTree*)f->Get("ttbar/DecayTree");
  }
  if (!t) {
    t = (TTree*)f->Get("TupleOS/DecayTree");
  }

  Tree* inputT = new Tree("input", t, 1.0);
  float tunedx = 0.0, tunedy = 0.0;
  float tuneip = -1.0, tuneipchi2 = -1.0;
  float tuneipt = -1.0, tuneipl = -1.0;
  float px = -1.0, py = -1.0, pz = -1.0;
  float cov00 = -1.0, cov10 = -1.0, cov11 = -1.0;

  float tunedx_plus = 0.0, tunedy_plus = 0.0;
  float tuneip_plus = -1.0, tuneipchi2_plus = -1.0;
  float tuneipt_plus = -1.0, tuneipl_plus = -1.0;
  float px_plus = -1.0, py_plus = -1.0, pz_plus = -1.0;
  float cov00_plus = -1.0, cov10_plus = -1.0, cov11_plus = -1.0;
  double ipw = 1.0;
  
  inputT->SetBranch(var1+"_ipubs_dx");
  inputT->SetBranch(var1+"_ipubs_dy");
  inputT->SetBranch(var1+"_PX");
  inputT->SetBranch(var1+"_PY");
  inputT->SetBranch(var1+"_PZ");
  inputT->SetBranch(var1+"_ipubs_cov00");
  inputT->SetBranch(var1+"_ipubs_cov10");
  inputT->SetBranch(var1+"_ipubs_cov11");
  inputT->SetBranch(var1+"_ETA");
  inputT->SetBranch(var1+"_PHI");
  inputT->SetBranch(var1+"_PT");
  inputT->SetBranch(var1+"_ID");
  inputT->SetBranch(var1+"_nTracksInPV");

  inputT->SetBranch(var2+"_ipubs_dx");
  inputT->SetBranch(var2+"_ipubs_dy");
  inputT->SetBranch(var2+"_PX");
  inputT->SetBranch(var2+"_PY");
  inputT->SetBranch(var2+"_PZ");
  inputT->SetBranch(var2+"_ipubs_cov00");
  inputT->SetBranch(var2+"_ipubs_cov10");
  inputT->SetBranch(var2+"_ipubs_cov11");
  inputT->SetBranch(var2+"_ETA");
  inputT->SetBranch(var2+"_PHI");
  inputT->SetBranch(var2+"_PT");
  inputT->SetBranch(var2+"_ID"); 

  TFile outputF(output.c_str(), "RECREATE");
  TTree* tree = new TTree("tree", "tree");

  tree->Branch((var1+"_ipubs_dx_tune").c_str()   , &tunedx);
  tree->Branch((var1+"_ipubs_dy_tune").c_str()   , &tunedy);
  tree->Branch((var1+"_ipubs_d_tune").c_str()    , &tuneip);
  tree->Branch((var1+"_iptrans_tune").c_str()    , &tuneipt);
  tree->Branch((var1+"_iplong_tune").c_str()     , &tuneipl);
  tree->Branch((var1+"_ipubs_chi2_tune").c_str() , &tuneipchi2);
  tree->Branch((var1+"_PX").c_str(), &px);
  tree->Branch((var1+"_PY").c_str(), &py);
  tree->Branch((var1+"_PZ").c_str(), &pz);
  tree->Branch((var1+"_ipubs_cov00").c_str(), &cov00);
  tree->Branch((var1+"_ipubs_cov10").c_str(), &cov10);
  tree->Branch((var1+"_ipubs_cov11").c_str(), &cov11);  

  tree->Branch((var2+"_ipubs_dx_tune").c_str(), &tunedx_plus);
  tree->Branch((var2+"_ipubs_dy_tune").c_str(), &tunedy_plus);
  tree->Branch((var2+"_ipubs_d_tune").c_str(), &tuneip_plus);
  tree->Branch((var2+"_iptrans_tune").c_str(), &tuneipt_plus);
  tree->Branch((var2+"_iplong_tune").c_str(), &tuneipl_plus);
  tree->Branch((var2+"_ipubs_chi2_tune").c_str(), &tuneipchi2_plus);
  tree->Branch((var2+"_PX").c_str(), &px_plus);
  tree->Branch((var2+"_PY").c_str(), &py_plus);
  tree->Branch((var2+"_PZ").c_str(), &pz_plus);
  tree->Branch((var2+"_ipubs_cov00").c_str(), &cov00_plus);
  tree->Branch((var2+"_ipubs_cov10").c_str(), &cov10_plus);
  tree->Branch((var2+"_ipubs_cov11").c_str(), &cov11_plus);  

  tree->Branch("ipw", &ipw);
  
  //Tune* tuner = new Tune();
  
  int entries = t->GetEntries();
  

  for(int i = 0; i < entries; ++i){
    if (i%10000 == 0) cout<<"Entry: "<<i<<" of "<<entries<<endl;
    inputT->GetEntry(i);
    double mu_eta = inputT->GetVal(var1+"_ETA");
    double mu_phi = inputT->GetVal(var1+"_PHI");
    //double pt  = inputT->GetVal(var1+"_PT");
    double mu_id  = inputT->GetVal(var1+"_ID");
    double pol    = inputT->GetVal("Polarity");

    vector<double> rndms = Utils::getCorrelatedRandoms(r3, cov);

    int id1 = var2 == "e" ? -11 : -13;

    double mu_dx_sigma  = mu_id == id1 ? dx_minus_s->GetBinContent(dx_minus_s->FindBin(mu_eta, mu_phi))   : dx_plus_s->GetBinContent(dx_plus_s->FindBin(mu_eta, mu_phi)) ;
    double mu_dx_mean   = mu_id == id1 ? dx_minus_m->GetBinContent(dx_minus_m->FindBin(mu_eta, mu_phi))   : dx_plus_m->GetBinContent(dx_plus_m->FindBin(mu_eta, mu_phi)) ;
    double mu_dy_sigma  = mu_id == id1 ? dy_minus_s->GetBinContent(dy_minus_s->FindBin(mu_eta, mu_phi))   : dy_plus_s->GetBinContent(dy_plus_s->FindBin(mu_eta, mu_phi)) ;
    double mu_dy_mean   = mu_id == id1 ? dy_minus_m->GetBinContent(dy_minus_m->FindBin(mu_eta, mu_phi))   : dy_plus_m->GetBinContent(dy_plus_m->FindBin(mu_eta, mu_phi)) ;


    tunedx  = inputT->GetVal(var1+"_ipubs_dx")  + mu_dx_sigma * rndms.at(0) + mu_dx_mean   ;
    tunedy  = inputT->GetVal(var1+"_ipubs_dy")  + mu_dy_sigma * rndms.at(1) + mu_dy_mean   ;
    tuneip   = sqrt( pow(tunedx,2) + pow(tunedy,2) );


    cov00  = inputT->GetVal(var1+"_ipubs_cov00" );
    cov10  = inputT->GetVal(var1+"_ipubs_cov10" );
    cov11  = inputT->GetVal(var1+"_ipubs_cov11" );
    px = inputT->GetVal(var1+"_PX");
    py = inputT->GetVal(var1+"_PY");
    pz = inputT->GetVal(var1+"_PZ");
    double tx     = px/pz;
    double ty     = py/pz;
    double D = cov00*cov11 - cov10*cov10 ;
    double invcov00 = cov11 / D ;
    double invcov10 = -cov10 / D ;
    double invcov11 = cov00 / D ;

    tuneipchi2 = tunedx*tunedx * invcov00 + 2*tunedx*tunedy * invcov10 + tunedy*tunedy * invcov11;

    tuneipt = (tunedx * ty - tunedy*tx) / sqrt(tx*tx + ty*ty);
    tuneipl  = (tunedx * tx + tunedy*ty) / sqrt(tx*tx + ty*ty);

    //ipw = rwtracks->GetBinContent(rwtracks->FindBin(inputT->GetVal(var1+"_nTracksInPV")));
    ipw = 1.0;

    double eta_plus = inputT->GetVal(var2+"_ETA");
    double phi_plus = inputT->GetVal(var2+"_PHI");
    //double pt_plus  = inputT->GetVal(var2+"_PT");
    double id_plus  = inputT->GetVal(var2+"_ID");
    
    vector<double> rndms_plus = Utils::getCorrelatedRandoms(r3, cov);
    
    int id2 = var2 == "e" ? -11 : -13;

    double dx_sigma_plus  = id_plus == id2 ? dx_minus_s->GetBinContent(dx_minus_s->FindBin(eta_plus, phi_plus))   : dx_plus_s->GetBinContent(dx_plus_s->FindBin(eta_plus, phi_plus)) ;
    double dx_mean_plus   = id_plus == id2 ? dx_minus_m->GetBinContent(dx_minus_m->FindBin(eta_plus, phi_plus))   : dx_plus_m->GetBinContent(dx_plus_m->FindBin(eta_plus, phi_plus)) ;
    double dy_sigma_plus  = id_plus == id2 ? dy_minus_s->GetBinContent(dy_minus_s->FindBin(eta_plus, phi_plus))   : dy_plus_s->GetBinContent(dy_plus_s->FindBin(eta_plus, phi_plus)) ;
    double dy_mean_plus   = id_plus == id2 ? dy_minus_m->GetBinContent(dy_minus_m->FindBin(eta_plus, phi_plus))   : dy_plus_m->GetBinContent(dy_plus_m->FindBin(eta_plus, phi_plus)) ;
    
    tunedx_plus  = inputT->GetVal(var2+"_ipubs_dx")  + dx_sigma_plus * rndms_plus.at(0) + dx_mean_plus   ;
    tunedy_plus  = inputT->GetVal(var2+"_ipubs_dy")  + dy_sigma_plus * rndms_plus.at(1) + dy_mean_plus   ;
    tuneip_plus   = sqrt( pow(tunedx_plus,2) + pow(tunedy_plus,2) );
    
    cov00_plus  = inputT->GetVal(var2+"_ipubs_cov00" );
    cov10_plus  = inputT->GetVal(var2+"_ipubs_cov10" );
    cov11_plus  = inputT->GetVal(var2+"_ipubs_cov11" );
    px_plus = inputT->GetVal(var2+"_PX");
    py_plus = inputT->GetVal(var2+"_PY");
    pz_plus = inputT->GetVal(var2+"_PZ");
    double tx_plus     = inputT->GetVal(var2+"_PX/e_PZ");
    double ty_plus     = inputT->GetVal(var2+"_PY/e_PZ");
    double D_plus = cov00_plus*cov11_plus - cov10_plus*cov10_plus ;
    double invcov00_plus = cov11_plus / D_plus ;
    double invcov10_plus = -cov10_plus / D_plus ;
    double invcov11_plus = cov00_plus / D_plus ;
    
    tuneipchi2_plus = tunedx_plus*tunedx_plus * invcov00_plus + 2*tunedx_plus*tunedy_plus * invcov10_plus + tunedy_plus*tunedy_plus * invcov11_plus;
    
    tuneipt_plus = (tunedx_plus * ty_plus - tunedy_plus*tx_plus) / sqrt(tx_plus*tx_plus + ty_plus*ty_plus);
    tuneipl_plus = (tunedx_plus * tx_plus + tunedy_plus*ty_plus) / sqrt(tx_plus*tx_plus + ty_plus*ty_plus);
    
      
    tree->Fill();
    
  }
  tree->Write("iptune");
  outputF.Close();
}
