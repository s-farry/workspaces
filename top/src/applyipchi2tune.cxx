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

  Expr* dx  = new Expr("muminus_ipubs_dx");
  Expr* dy  = new Expr("muminus_ipubs_dy");
  //Expr* tx  = new Expr("muminus_PX/muminus_PZ");
  //Expr* ty  = new Expr("muminus_PY/muminus_PZ");
  //Expr* cov00  = new Expr("muminus_ipubs_cov00");
  //Expr* cov10  = new Expr("muminus_ipubs_cov10");
  //Expr* cov11  = new Expr("muminus_ipubs_cov11");

  bool dimuon = false;

  //Load the root files for performing tuning
  TFile tuner_dx_plus("dx_etaphitune_plus.root");
  TH2F* dx_plus_s = (TH2F*)tuner_dx_plus.Get("dx_etaphitune_plus_sigma_2D");
  TH2F* dx_plus_m = (TH2F*)tuner_dx_plus.Get("dx_etaphitune_plus_mean_2D");
  
  TFile tuner_dx_minus("dx_etaphitune_minus.root");
  TH2F* dx_minus_s = (TH2F*)tuner_dx_minus.Get("dx_etaphitune_minus_sigma_2D");
  TH2F* dx_minus_m = (TH2F*)tuner_dx_minus.Get("dx_etaphitune_minus_mean_2D");

  TFile tuner_dy_plus("dy_etaphitune_plus.root");
  TH2F* dy_plus_s = (TH2F*)tuner_dy_plus.Get("dy_etaphitune_plus_sigma_2D");
  TH2F* dy_plus_m = (TH2F*)tuner_dy_plus.Get("dy_etaphitune_plus_mean_2D");
  
  TFile tuner_dy_minus("dy_etaphitune_minus.root");
  TH2F* dy_minus_s = (TH2F*)tuner_dy_minus.Get("dy_etaphitune_minus_sigma_2D");
  TH2F* dy_minus_m = (TH2F*)tuner_dy_minus.Get("dy_etaphitune_minus_mean_2D");


  //Data plus cuts for correlation matrix
  TFile* dataf = TFile::Open("/hepstore/sfarry/ZMuMu.2012.root");
  Tree* datat = new Tree("data", (TTree*)dataf->Get("ZMuMu/DecayTree"), 1.0);
  Expr* zmumu = new Expr("boson_M > 60000 && boson_M < 120000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_TRACK_PCHI2 > 0.01 && muplus_TRACK_PCHI2 > 0.01 && sqrt(muminus_PERR2)/muminus_P < 0.1 && sqrt(muplus_PERR2)/muplus_P < 0.1");

  vector<Expr*> vars;
  vars.push_back(dx);
  vars.push_back(dy);

  vector< vector<double> > cov = datat->getCorrelationMatrix(vars, zmumu);
  cout<<"Correlation Matrix: "<<endl;
  Utils::printMatrix(cov);

  //To Calculate Weight
  //TFile data("/user2/sfarry/WTau/python/IPchi2/ZMuMu_Data2012.root");
  //TFile mc("/user2/sfarry/WTau/python/IPchi2/ZMuMu_MC2012.root");

  //TH1F* rwtracks = Utils::GetWeightHist("rwtracks", (TH1F*)data.Get("PVMult"), (TH1F*)mc.Get("PVMult"));

  string inputS, outputS;

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
      inputS = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/"+dpns[1];
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

  cout<<"Input File: "<<inputS<<endl;
  cout<<"Outputting to: "<<outputS<<endl;

  TFile* f = TFile::Open(inputS.c_str());
  TTree* t = (TTree*)f->Get("WTuple/DecayTree");
  if (!t) {
    t = (TTree*)f->Get("ZMuMu/DecayTree");
    dimuon = true;
  }
  if (!t) {
    t = (TTree*)f->Get("TupleOS/DecayTree");
    if (t) dimuon = true;
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
  
  inputT->SetBranch("muminus_ipubs_dx");
  inputT->SetBranch("muminus_ipubs_dy");
  inputT->SetBranch("muminus_PX");
  inputT->SetBranch("muminus_PY");
  inputT->SetBranch("muminus_PZ");
  inputT->SetBranch("muminus_ipubs_cov00");
  inputT->SetBranch("muminus_ipubs_cov10");
  inputT->SetBranch("muminus_ipubs_cov11");
  inputT->SetBranch("muminus_ETA");
  inputT->SetBranch("muminus_PHI");
  inputT->SetBranch("muminus_PT");
  inputT->SetBranch("muminus_ID");
  inputT->SetBranch("muminus_nTracksInPV");

  if (dimuon){
    inputT->SetBranch("muplus_ipubs_dx");
    inputT->SetBranch("muplus_ipubs_dy");
    inputT->SetBranch("muplus_PX");
    inputT->SetBranch("muplus_PY");
    inputT->SetBranch("muplus_PZ");
    inputT->SetBranch("muplus_ipubs_cov00");
    inputT->SetBranch("muplus_ipubs_cov10");
    inputT->SetBranch("muplus_ipubs_cov11");
    inputT->SetBranch("muplus_ETA");
    inputT->SetBranch("muplus_PHI");
    inputT->SetBranch("muplus_PT");
    inputT->SetBranch("muplus_ID"); 
  }


  TFile outputF(outputS.c_str(), "RECREATE");
  TTree* tree = new TTree("tree", "tree");

  tree->Branch("muminus_ipubs_dx_tune"   , &tunedx);
  tree->Branch("muminus_ipubs_dy_tune"   , &tunedy);
  tree->Branch("muminus_ipubs_d_tune"    , &tuneip);
  tree->Branch("muminus_iptrans_tune"    , &tuneipt);
  tree->Branch("muminus_iplong_tune"     , &tuneipl);
  tree->Branch("muminus_ipubs_chi2_tune" , &tuneipchi2);
  tree->Branch("muminus_PX", &px);
  tree->Branch("muminus_PY", &py);
  tree->Branch("muminus_PZ", &pz);
  tree->Branch("muminus_ipubs_cov00", &cov00);
  tree->Branch("muminus_ipubs_cov10", &cov10);
  tree->Branch("muminus_ipubs_cov11", &cov11);  

  if (dimuon){
    tree->Branch("muplus_ipubs_dx_tune", &tunedx_plus);
    tree->Branch("muplus_ipubs_dy_tune", &tunedy_plus);
    tree->Branch("muplus_ipubs_d_tune", &tuneip_plus);
    tree->Branch("muplus_iptrans_tune", &tuneipt_plus);
    tree->Branch("muplus_iplong_tune", &tuneipl_plus);
    tree->Branch("muplus_ipubs_chi2_tune", &tuneipchi2_plus);
    tree->Branch("muplus_PX", &px_plus);
    tree->Branch("muplus_PY", &py_plus);
    tree->Branch("muplus_PZ", &pz_plus);
    tree->Branch("muplus_ipubs_cov00", &cov00_plus);
    tree->Branch("muplus_ipubs_cov10", &cov10_plus);
    tree->Branch("muplus_ipubs_cov11", &cov11_plus);  
  }
  tree->Branch("ipw", &ipw);
  
  //Tune* tuner = new Tune();
  
  int entries = t->GetEntries();
  

  for(int i = 0; i < entries; ++i){
    if (i%10000 == 0) cout<<"Entry: "<<i<<" of "<<entries<<endl;
    inputT->GetEntry(i);
    double mu_eta = inputT->GetVal("mu_ETA");
    double mu_phi = inputT->GetVal("mu_PHI");
    //double pt  = inputT->GetVal("muminus_PT");
    double mu_id  = inputT->GetVal("mu_ID");
    double pol    = inputT->GetVal("Polarity");

    vector<double> rndms = Utils::getCorrelatedRandoms(r3, cov);

    double mu_dx_sigma  = id == -13 ? dx_minus_s->GetBinContent(dx_minus_s->FindBin(eta, phi))   : dx_plus_s->GetBinContent(dx_plus_s->FindBin(eta, phi)) ;
    double mu_dx_mean   = id == -13 ? dx_minus_m->GetBinContent(dx_minus_m->FindBin(eta, phi))   : dx_plus_m->GetBinContent(dx_plus_m->FindBin(eta, phi)) ;
    double mu_dy_sigma  = id == -13 ? dy_minus_s->GetBinContent(dy_minus_s->FindBin(eta, phi))   : dy_plus_s->GetBinContent(dy_plus_s->FindBin(eta, phi)) ;
    double mu_dy_mean   = id == -13 ? dy_minus_m->GetBinContent(dy_minus_m->FindBin(eta, phi))   : dy_plus_m->GetBinContent(dy_plus_m->FindBin(eta, phi)) ;


    tunedx  = inputT->GetVal("muminus_ipubs_dx")  + dx_sigma * rndms.at(0) + dx_mean   ;
    tunedy  = inputT->GetVal("muminus_ipubs_dy")  + dy_sigma * rndms.at(1) + dy_mean   ;
    tuneip   = sqrt( pow(tunedx,2) + pow(tunedy,2) );


    cov00  = inputT->GetVal("muminus_ipubs_cov00" );
    cov10  = inputT->GetVal("muminus_ipubs_cov10" );
    cov11  = inputT->GetVal("muminus_ipubs_cov11" );
    px = inputT->GetVal("muminus_PX");
    py = inputT->GetVal("muminus_PY");
    pz = inputT->GetVal("muminus_PZ");
    double tx     = px/pz;
    double ty     = py/pz;
    double D = cov00*cov11 - cov10*cov10 ;
    double invcov00 = cov11 / D ;
    double invcov10 = -cov10 / D ;
    double invcov11 = cov00 / D ;

    tuneipchi2 = tunedx*tunedx * invcov00 + 2*tunedx*tunedy * invcov10 + tunedy*tunedy * invcov11;

    tuneipt = (tunedx * ty - tunedy*tx) / sqrt(tx*tx + ty*ty);
    tuneipl  = (tunedx * tx + tunedy*ty) / sqrt(tx*tx + ty*ty);

    ipw = rwtracks->GetBinContent(rwtracks->FindBin(inputT->GetVal("muminus_nTracksInPV")));

    if (dimuon){
      double eta_plus = inputT->GetVal("muplus_ETA");
      double phi_plus = inputT->GetVal("muplus_PHI");
      //double pt_plus  = inputT->GetVal("muplus_PT");
      double id_plus  = inputT->GetVal("muplus_ID");

      vector<double> rndms = Utils::getCorrelatedRandoms(r3, cov);

      double dx_sigma_plus  = id_plus == -13 ? dx_minus_s->GetBinContent(dx_minus_s->FindBin(eta_plus, phi_plus))   : dx_plus_s->GetBinContent(dx_plus_s->FindBin(eta_plus, phi_plus)) ;
      double dx_mean_plus   = id_plus == -13 ? dx_minus_m->GetBinContent(dx_minus_m->FindBin(eta_plus, phi_plus))   : dx_plus_m->GetBinContent(dx_plus_m->FindBin(eta_plus, phi_plus)) ;
      double dy_sigma_plus  = id_plus == -13 ? dy_minus_s->GetBinContent(dy_minus_s->FindBin(eta_plus, phi_plus))   : dy_plus_s->GetBinContent(dy_plus_s->FindBin(eta_plus, phi_plus)) ;
      double dy_mean_plus   = id_plus == -13 ? dy_minus_m->GetBinContent(dy_minus_m->FindBin(eta_plus, phi_plus))   : dy_plus_m->GetBinContent(dy_plus_m->FindBin(eta_plus, phi_plus)) ;
      
      tunedx_plus  = inputT->GetVal("muplus_ipubs_dx")  + dx_sigma_plus * rndms.at(0) + dx_mean_plus   ;
      tunedy_plus  = inputT->GetVal("muplus_ipubs_dy")  + dy_sigma_plus * rndms.at(1) + dy_mean_plus   ;
      tuneip_plus   = sqrt( pow(tunedx,2) + pow(tunedy,2) );
      
      cov00_plus  = inputT->GetVal("muplus_ipubs_cov00" );
      cov10_plus  = inputT->GetVal("muplus_ipubs_cov10" );
      cov11_plus  = inputT->GetVal("muplus_ipubs_cov11" );
      px_plus = inputT->GetVal("muplus_PX");
      py_plus = inputT->GetVal("muplus_PY");
      pz_plus = inputT->GetVal("muplus_PZ");
      double tx_plus     = inputT->GetVal("muplus_PX/muplus_PZ");
      double ty_plus     = inputT->GetVal("muplus_PY/muplus_PZ");
      double D = cov00_plus*cov11_plus - cov10_plus*cov10_plus ;
      double invcov00 = cov11_plus / D ;
      double invcov10 = -cov10_plus / D ;
      double invcov11 = cov00_plus / D ;
      
      tuneipchi2_plus = tunedx_plus*tunedx_plus * invcov00 + 2*tunedx_plus*tunedy_plus * invcov10 + tunedy_plus*tunedy_plus * invcov11;
      
      tuneipt_plus = (tunedx_plus * ty_plus - tunedy_plus*tx_plus) / sqrt(tx_plus*tx_plus + ty_plus*ty_plus);
      tuneipl_plus = (tunedx_plus * tx_plus + tunedy_plus*ty_plus) / sqrt(tx_plus*tx_plus + ty_plus*ty_plus);
      
      
    }


    tree->Fill();
    
  }
  if (dimuon){
    tree->Write("iptune_zmumu");
  }
  else{
    tree->Write("iptune");
  }
  outputF.Close();
}
