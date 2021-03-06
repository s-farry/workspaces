

void train_strange_mva(){

  TFile* outputFile = TFile::Open("tmva_strange.root", "RECREATE");
  TMVA::Factory *factory = new TMVA::Factory("strange", outputFile,
					     "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
  factory->AddVariable("jet_maxkaonpt", 'F');
  factory->AddVariable("jet_maxkaonptr := jet_maxkaonpt / jet_PT", 'F');
  factory->AddVariable("jet_maxpionpt", 'F');
  factory->AddVariable("jet_maxpionptr := jet_maxpionpt / jet_PT", 'F');
  factory->AddVariable("jet_kaonpt", 'F');
  factory->AddVariable("jet_pionpt", 'F');
  factory->AddVariable("jet_kaonmult", 'F');
  factory->AddVariable("jet_kaoncmult", 'F');
  factory->AddVariable("jet_pionmult", 'F');
  factory->AddVariable("jet_pioncmult", 'F');
  factory->AddVariable("jet_ndauts", 'F');
  factory->AddVariable("jet_PT", 'F');
  factory->AddVariable("jet_pi_dR", 'F');
  factory->AddVariable("jet_K_dR", 'F');
  factory->AddVariable("jet_cpf", 'F');
  //factory->AddVariable("jet_M", 'F');
  //factory->AddVariable("jet_width", 'F');
  factory->AddVariable("jet_leading_id", 'F');
  //factory->AddVariable("jet_charge");
  //factory->AddVariable("jet_ETA", 'F');
  //factory->AddSpectator("jet_eccentricity", 'F');
  //factory->AddSpectator("jet_PT", 'F');

  vector<TFile*> inputs {
    //TFile::Open("/user2/sfarry/workspaces/strange/tuples/jet.dijetl_pt15_20.MD.MC2015.root"),
    //TFile::Open("/user2/sfarry/workspaces/strange/tuples/jet.dijetl_pt15_20.MD.MC2015.root"),
      TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/strange/Jet.dijetl_pt20_50.MD.MC2015.root"),
      TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/strange/Jet.dijetl_pt20_50.MD.MC2015.root"),
      TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/strange/Jet.dijetl_pt50.MD.MC2015.root"),
      TFile::Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/strange/Jet.dijetl_pt50.MD.MC2015.root")
  };
  outputFile->cd();
  //TTree* sig = (TTree*)t->CopyTree("abs(jet_mc_flavour) == 3 && jet_PT > 0 && jet_kaonpt > 0");
  //TTree* bkg = (TTree*)t->CopyTree("abs(jet_mc_flavour) != 3 && jet_PT > 0 && jet_kaonpt > 0");

  for (int i = 0 ; i < inputs.size() ; ++i){
    TTree* t = (TTree*)inputs[i]->Get("Jet/DecayTree");
    //TTree* c = (TTree*)t->CopyTree("abs(jet_mc_flavour) == 3 && jet_PT > 0 && jet_kaonpt > 0");
    //factory->AddSignalTree((TTree*)inputs[i]->Get("Jet/DecayTree"));
    factory->AddSignalTree(t);
    //factory->AddBackgroundTree((TTree*)inputs[i]->Get("Jet/DecayTree"));
    factory->AddBackgroundTree(t);
  }
  TCut sig("abs(jet_mc_flavour) == 3 && jet_mc_PT != -1 && jet_PT > 0");
  TCut bkg("abs(jet_mc_flavour) != 3 && abs(jet_mc_flavour) < 6 && jet_mc_PT != -1 && jet_PT > 0");
  
  factory->PrepareTrainingAndTestTree(sig, bkg, "nTrain_Signal=15000:nTrain_Background=50000:nTest_Signal=15000:nTest_Background=15000:SplitMode=Random:NormMode=NumEvents:!V");
  
  factory->BookMethod( TMVA::Types::kBDT, "BDTB", "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=30:VarTransform=Decorrelate");
  factory->BookMethod( TMVA::Types::kBDT, "BDT","!V:NTrees=800:BoostType=Grad:nCuts=50:MaxDepth=3" );
  factory->BookMethod( TMVA::Types::kBDT, "BDTAdaBoost","!H:!V:NTrees=800:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=50" );
  factory->BookMethod( TMVA::Types::kLikelihood, "Likelihood","!V:NAvEvtPerBin=50" );
  
  factory->TrainAllMethods();
  factory->TestAllMethods();
  factory->EvaluateAllMethods();
  
  outputFile->Close();

  delete factory;















}
