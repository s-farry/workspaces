#include <iostream>
#include <sstream>
#include <iomanip>
#include <TFile.h>
#include <TTree.h>
#include <math.h>
#include <TH1F.h>
#include <Tune.h>
#include <Tune2D.h>
#include <Expr.h>
#include <Tree.h>
#include <TMath.h>
#include <Utils.h>
#include <ReweightVar.h>

using namespace std;


int main(){
  Var* phi_minus  = new Var("PHI_minus" , "muminus_PHI" , 6, -TMath::Pi(), TMath::Pi());
  Var* eta_minus  = new Var("ETA_minus" , "muminus_ETA" , 5, 2, 4.5 );
  Var* phi_plus   = new Var("PHI_plus"  , "muplus_PHI"  , 6, -TMath::Pi(), TMath::Pi());
  Var* eta_plus   = new Var("ETA_plus"  , "muplus_ETA"  , 5, 2, 4.5 );

  Var2D* eta_phi_minus  = new Var2D("PHI_ETA_minus", eta_minus , phi_minus);
  Var2D* eta_phi_plus   = new Var2D("PHI_ETA_plus" , eta_plus  , phi_plus);

  
  //TFile* dataf = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MU.2016.root");
  TFile* dataMUf = TFile::Open("/hepstore/sfarry/GridOutput/2669/ZMuMuJet.MU.2016.root");
  TFile* dataMDf = TFile::Open("/hepstore/sfarry/GridOutput/2668/ZMuMuJet.MD.2016.root");
  //TFile* mcf   = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/Zmumujet.Zg_mumu.MU.MC2015.root");
  TFile* mcMUf = TFile::Open("/hepstore/sfarry/GridOutput/2672/Zmumujet.Zg_mumu.MU.MC2015.root");
  TFile* mcMDf = TFile::Open("/hepstore/sfarry/GridOutput/2673/Zmumujet.Zg_mumu.MD.MC2015.root");
  TTree* data_mutt = ((TTree*)dataMUf->Get("ZMuMu/DecayTree"));
  TTree* data_mdtt = ((TTree*)dataMDf->Get("ZMuMu/DecayTree"));
  TTree* mc_mutt   = ((TTree*)mcMUf->Get("ZMuMu/DecayTree"));
  TTree* mc_mdtt   = ((TTree*)mcMDf->Get("ZMuMu/DecayTree"));
  
  Tree* data_mut = new Tree("data_mu", data_mutt );
  Tree* mc_mut   = new Tree("mc_mu"  , mc_mutt   );
  Tree* data_mdt = new Tree("data_md", data_mdtt );
  Tree* mc_mdt   = new Tree("mc_md"  , mc_mdtt   );
  
  Expr* zmumu = new Expr("muplus_PT > 20000 && muminus_PT > 20000 && boson_M > 60000 && boson_M < 120000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_TRACK_PCHI2 > 0.01 && muplus_TRACK_PCHI2 > 0.01 && sqrt(muminus_PERR2)/muminus_P < 0.1 && sqrt(muplus_PERR2)/muplus_P < 0.1 && nPVs > 0");

  Expr* dx_minus  = new Expr("muminus_ipubs_dx");
  Expr* dy_minus  = new Expr("muminus_ipubs_dy");

  Expr* dx_plus   = new Expr("muplus_ipubs_dx");
  Expr* dy_plus   = new Expr("muplus_ipubs_dy");
  
  //TFile f("/user2/sfarry/WTau/python/IPchi2/ZMuMu_Data2012.root");
  //TFile g("/user2/sfarry/WTau/python/IPchi2/ZMuMu_MC2012.root");

  //TH1F* rwtracks = Utils::GetWeightHist("rwtracks", (TH1F*)f.Get("PVMult"), (TH1F*)g.Get("PVMult"));

  //ReweightVar* rwvar_plus  = new ReweightVar("muplus_nTracksInPV" , rwtracks);
  //ReweightVar* rwvar_minus = new ReweightVar("muminus_nTracksInPV", rwtracks);
  
  Tune2D tuneretaphi_magup_dx_plus("dx_etaphitune_magup_plus", data_mut, mc_mut, dx_plus, eta_phi_plus, zmumu->GetExpr());
  //tuneretaphi_dx_plus.ReweightMC(rwvar_plus);
  tuneretaphi_magup_dx_plus.tune();
  tuneretaphi_magup_dx_plus.SaveToFile();
  
  Tune2D tuneretaphi_magup_dx_minus("dx_etaphitune_magup_minus", data_mut, mc_mut, dx_minus, eta_phi_minus, zmumu->GetExpr());
  //tuneretaphi_magup_dx_minus.ReweightMC(rwvar_minus);
  tuneretaphi_magup_dx_minus.tune();
  tuneretaphi_magup_dx_minus.SaveToFile();

  Tune2D tuneretaphi_magup_dy_plus("dy_etaphitune_magup_plus", data_mut, mc_mut, dy_plus, eta_phi_plus, zmumu->GetExpr());
  //tuneretaphi_dy_plus.ReweightMC(rwvar_plus);
  tuneretaphi_magup_dy_plus.tune();
  tuneretaphi_magup_dy_plus.SaveToFile();
  
  Tune2D tuneretaphi_magup_dy_minus("dy_etaphitune_magup_minus", data_mut, mc_mut, dy_minus, eta_phi_minus, zmumu->GetExpr());
  //tuneretaphi_dy_minus.ReweightMC(rwvar_minus);
  tuneretaphi_magup_dy_minus.tune();
  tuneretaphi_magup_dy_minus.SaveToFile();
  
  Tune2D tuneretaphi_magdown_dx_plus("dx_etaphitune_magdown_plus", data_mdt, mc_mdt, dx_plus, eta_phi_plus, zmumu->GetExpr());
  //tuneretaphi_dx_plus.ReweightMC(rwvar_plus);
  tuneretaphi_magdown_dx_plus.tune();
  tuneretaphi_magdown_dx_plus.SaveToFile();
  
  Tune2D tuneretaphi_magdown_dx_minus("dx_etaphitune_magdown_minus", data_mdt, mc_mdt, dx_minus, eta_phi_minus, zmumu->GetExpr());
  //tuneretaphi_magdown_dx_minus.ReweightMC(rwvar_minus);
  tuneretaphi_magdown_dx_minus.tune();
  tuneretaphi_magdown_dx_minus.SaveToFile();

  Tune2D tuneretaphi_magdown_dy_plus("dy_etaphitune_magdown_plus", data_mdt, mc_mdt, dy_plus, eta_phi_plus, zmumu->GetExpr());
  //tuneretaphi_dy_plus.ReweightMC(rwvar_plus);
  tuneretaphi_magdown_dy_plus.tune();
  tuneretaphi_magdown_dy_plus.SaveToFile();
  
  Tune2D tuneretaphi_magdown_dy_minus("dy_etaphitune_magdown_minus", data_mdt, mc_mdt, dy_minus, eta_phi_minus, zmumu->GetExpr());
  //tuneretaphi_dy_minus.ReweightMC(rwvar_minus);
  tuneretaphi_magdown_dy_minus.tune();
  tuneretaphi_magdown_dy_minus.SaveToFile();
  
}
