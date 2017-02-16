
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

//#include "TMVAGui.C"

#if not defined(__CINT__) || defined(__MAKECINT__)
// needs to be included when makecint runs (ACLIC)
#include "TMVA/Factory.h"
#include "TMVA/Tools.h"
#endif

void TMVATraining( )
{
  /*
  TFile* inputS1 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ttbar.ttbar_gg.MU.MC2016.root");
  TFile* inputS2 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ttbar.ttbar_gg.MD.MC2016.root");
  TFile* inputS3 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ttbar.ttbar_qqbar.MU.MC2016.root");
  TFile* inputS4 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ttbar.ttbar_qqbar.MD.MC2016.root");
  TFile* inputB1 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ttbar.Z_tautau.MU.MC2016.root");
  TFile* inputB2 = TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ttbar.Z_tautau.MD.MC2016.root");
  */

  TFile* inputS1 = TFile::Open("/hepstore/sfarry/GridOutput/2685/ttbar.ttbar_gg.MU.MC2016.root");
  TFile* inputS2 = TFile::Open("/hepstore/sfarry/GridOutput/2686/ttbar.ttbar_gg.MD.MC2016.root");
  TFile* inputS3 = TFile::Open("/hepstore/sfarry/GridOutput/2683/ttbar.ttbar_qqbar.MU.MC2016.root");
  TFile* inputS4 = TFile::Open("/hepstore/sfarry/GridOutput/2684/ttbar.ttbar_qqbar.MD.MC2016.root");
  TFile* inputB1 = TFile::Open("/hepstore/sfarry/GridOutput/2689/ttbar.Z_tautau.MU.MC2016.root");
  TFile* inputB2 = TFile::Open("/hepstore/sfarry/GridOutput/2690/ttbar.Z_tautau.MD.MC2016.root");

  TTree *treeS1  = (TTree*)inputS1->Get("ttbar/DecayTree");
  TTree *treeS2  = (TTree*)inputS2->Get("ttbar/DecayTree");
  TTree *treeS3  = (TTree*)inputS3->Get("ttbar/DecayTree");
  TTree *treeS4  = (TTree*)inputS4->Get("ttbar/DecayTree");
  TTree *treeB1  = (TTree*)inputB1->Get("ttbar/DecayTree");
  TTree *treeB2  = (TTree*)inputB2->Get("ttbar/DecayTree");

  TCut cut = "mu_PT > 20000 && e_PT > 20000 && min(mu_ETA, e_ETA) > 2.0 && max(mu_ETA, e_ETA) < 4.5";
  
  TFile* outputFile1 = TFile::Open( "tmva_mc2016_top_maxip.root", "RECREATE" );
  TMVA::Factory *factory1 = new TMVA::Factory( "tmva_mc2016_top_maxip", outputFile1,"!V");
  factory1->AddVariable("max(mu_IP_OWNPV, e_IP_OWNPV)" , 'D');
  factory1->AddSignalTree ( treeS1 );
  factory1->AddSignalTree ( treeS2 );
  factory1->AddSignalTree ( treeS3 );
  factory1->AddSignalTree ( treeS4 );
  factory1->AddBackgroundTree ( treeB1 );
  factory1->AddBackgroundTree ( treeB2 );
  factory1->PrepareTrainingAndTestTree( cut,"!V:nTrain_Background=30:nTrain_Signal=500:nTest_Signal=0:nTest_Background=0" );
  factory1->BookMethod( TMVA::Types::kCuts, "Cuts" );
  factory1->TrainAllMethods();  
  factory1->TestAllMethods();
  factory1->EvaluateAllMethods();
  
  TFile* outputFile2 = TFile::Open( "tmva_mc2016_top_vtxchi2.root", "RECREATE" );
  TMVA::Factory *factory2 = new TMVA::Factory( "tmva_mc2016_top_vtxchi2", outputFile2,"!V");
  factory2->AddVariable("ttbar_ENDVERTEX_CHI2/ttbar_ENDVERTEX_NDOF", 'D');
  factory2->AddSignalTree ( treeS1 );
  factory2->AddSignalTree ( treeS2 );
  factory2->AddSignalTree ( treeS3 );
  factory2->AddSignalTree ( treeS4 );
  factory2->AddBackgroundTree ( treeB1 );
  factory2->AddBackgroundTree ( treeB2 );
  factory2->PrepareTrainingAndTestTree( cut,"!V:nTrain_Background=30:nTrain_Signal=500:nTest_Signal=0:nTest_Background=0" );
  factory2->BookMethod( TMVA::Types::kCuts, "Cuts" );
  factory2->TrainAllMethods();  
  factory2->TestAllMethods();
  factory2->EvaluateAllMethods();
  
  TFile* outputFile3 = TFile::Open( "tmva_mc2016_top_twoip.root", "RECREATE" );
  TMVA::Factory *factory3 = new TMVA::Factory( "tmva_mc2016_top_twoip", outputFile3,"!V");
  factory3->AddVariable("mu_IP_OWNPV", 'D');
  factory3->AddVariable("e_IP_OWNPV", 'D');
  factory3->AddSignalTree ( treeS1 );
  factory3->AddSignalTree ( treeS2 );
  factory3->AddSignalTree ( treeS3 );
  factory3->AddSignalTree ( treeS4 );
  factory3->AddBackgroundTree ( treeB1 );
  factory3->AddBackgroundTree ( treeB2 );
  factory3->PrepareTrainingAndTestTree( cut,"!V:nTrain_Background=30:nTrain_Signal=500:nTest_Signal=0:nTest_Background=0" );
  factory3->BookMethod( TMVA::Types::kCuts, "Cuts" );
  factory3->TrainAllMethods();  
  factory3->TestAllMethods();
  factory3->EvaluateAllMethods();
  
  TFile* outputFile4 = TFile::Open( "tmva_mc2016_top_sumip.root", "RECREATE" );
  TMVA::Factory *factory4 = new TMVA::Factory( "tmva_mc2016_top_sumip", outputFile4,"!V");
  factory4->AddVariable("mu_IP_OWNPV + e_IP_OWNPV" , 'D');
  factory4->AddSignalTree ( treeS1 );
  factory4->AddSignalTree ( treeS2 );
  factory4->AddSignalTree ( treeS3 );
  factory4->AddSignalTree ( treeS4 );
  factory4->AddBackgroundTree ( treeB1 );
  factory4->AddBackgroundTree ( treeB2 );
  factory4->PrepareTrainingAndTestTree( cut,"!V:nTrain_Background=30:nTrain_Signal=500:nTest_Signal=0:nTest_Background=0" );
  factory4->BookMethod( TMVA::Types::kCuts, "Cuts" );
  factory4->TrainAllMethods();  
  factory4->TestAllMethods();
  factory4->EvaluateAllMethods();

  outputFile1->Close();
  outputFile2->Close();
  outputFile3->Close();
  outputFile4->Close();

  delete factory1;
  delete factory2;
  delete factory3;
  delete factory4;

}

int main()
{
  TMVATraining();
}
