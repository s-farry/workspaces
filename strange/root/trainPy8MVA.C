

void trainMVA(){

  TFile* outputFile = TFile::Open("tmvaout.root", "RECREATE");
  TMVA::Factory *factory = new TMVA::Factory("TMVAClassification", outputFile,
					     "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
  factory->AddVariable("jet_maxkaonpt", 'F');
  factory->AddVariable("jet_maxkaonptr := jet_maxkaonpt / jet_pt", 'F');
  factory->AddVariable("jet_maxpionpt", 'F');
  factory->AddVariable("jet_maxpionptr := jet_maxpionpt / jet_pt", 'F');
  factory->AddVariable("jet_kaonpt", 'F');
  factory->AddVariable("jet_pionpt", 'F');
  factory->AddVariable("jet_kaoncpt", 'F');
  factory->AddVariable("jet_pioncpt", 'F');
  factory->AddVariable("jet_neutralPt", 'F');
  factory->AddVariable("jet_chargedPt", 'F');
  //factory->AddVariable("jet_mult", 'D');
  factory->AddVariable("jet_pt", 'F');
  factory->AddVariable("jet_dR_maxkaon", 'F');
  factory->AddVariable("jet_dR_maxpion", 'F');
  factory->AddVariable("jet_chargedF := jet_chargedPt/(jet_chargedPt + jet_neutralPt)", 'F');

  TFile* input = TFile::Open("/user2/sfarry/workspaces/strange/tuples/zmumuj.root");
  TTree* t = (TTree*)input->Get("Zjet");
  outputFile->cd();
  t->SetBranchStatus("Z*",0);
  t->SetBranchStatus("*mu*",0);
  TTree* sig = (TTree*)t->CopyTree("abs(jet_flav) == 3 && jet_nkaons > 0");
  TTree* bkg = (TTree*)t->CopyTree("abs(jet_flav) != 3 && jet_nkaons > 0");

  factory->AddSignalTree(sig);
  factory->AddBackgroundTree(bkg);

  factory->PrepareTrainingAndTestTree("", "nTrain_Signal=4000:nTrain_Background=4000:SplitMode=Random:NormMode=NumEvents:!V");
  factory->BookMethod( TMVA::Types::kBDT, "BDTB", "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=30:VarTransform=Decorrelate");
  factory->BookMethod( TMVA::Types::kBDT, "BDT","!V:NTrees=800:BoostType=Grad:nCuts=50:NNodesMax=5" );
  factory->BookMethod( TMVA::Types::kBDT, "BDTAdaBoost","!H:!V:NTrees=800:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=50:NNodesMax=5" );
  factory->BookMethod( TMVA::Types::kLikelihood, "Likelihood","!V:NAvEvtPerBin=50" );

  factory->TrainAllMethods();
  factory->TestAllMethods();
  factory->EvaluateAllMethods();

  outputFile->Close();

  delete factory;















}
