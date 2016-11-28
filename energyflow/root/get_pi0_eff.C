{
  //number of MC events - Sim09 Reco15a, Stripping24
  double nevents_BjpsiKst = 1033043 + 1011762;
  double nevents_BjpsiK   = 2080296 + 2121701;
  // cross-sections * generator efficiency
  double genEff_BjpsiK   = 1000.0 / 545041.0;
  double genEff_BjpsiKst = 1000.0 / 645653.0;
  // effective luminosity (excluding prod. cross-section)
  double lumi_BjpsiK   = nevents_BjpsiK/genEff_BjpsiK;
  double lumi_BjpsiKst = nevents_BjpsiKst/genEff_BjpsiKst;

  TFile f("/user2/sfarry/workspaces/energyflow/tuples/bjpsik_data2015_fit.root");
  TFile g("/user2/sfarry/workspaces/energyflow/tuples/bjpsik_mc2015_fit.root");
  TFile h("/user2/sfarry/workspaces/energyflow/tuples/bjpsikst_data2015_fit.root");
  TFile i("/user2/sfarry/workspaces/energyflow/tuples/bjpsikst_mc2015_fit.root");
  
  double BjpsiK_Nsig = ((TParameter<double>*)f.Get("m_Nsig_tot"))->GetVal();
  double BjpsiK_Nsig_fit_err = ((TParameter<double>*)f.Get("m_Nsig_tot_err"))->GetVal();
  
  double BjpsiK_Nsig_poly =  ((TParameter<double>*)f.Get("m_Nsig_polynomial_tot"))->GetVal();
  double BjpsiK_Nsig_novo =  ((TParameter<double>*)f.Get("m_Nsig_novosibirsk_tot"))->GetVal();
  
  double BjpsiK_Nsig_err = sqrt(pow(BjpsiK_Nsig_fit_err,2) + pow(BjpsiK_Nsig - BjpsiK_Nsig_poly,2) + pow(BjpsiK_Nsig - BjpsiK_Nsig_novo,2));

  cout<<"Data B->Jpsi K"<<endl;
  cout<<BjpsiK_Nsig<<" +/- "<<BjpsiK_Nsig_err<<" ( "<<(BjpsiK_Nsig_err / BjpsiK_Nsig)*100.0<<" % )"<<endl;
  
  
  double BjpsiKst_Nsig = ((TParameter<double>*)h.Get("m2_Nsig_tot"))->GetVal();
  double BjpsiKst_Nsig_fit_err = ((TParameter<double>*)h.Get("m2_Nsig_tot_err"))->GetVal();
  
  double BjpsiKst_Nsig_poly =  ((TParameter<double>*)h.Get("m2_Nsig_polynomial_tot"))->GetVal();
  double BjpsiKst_Nsig_novo =  ((TParameter<double>*)h.Get("m2_Nsig_novosibirsk_tot"))->GetVal();
  
  double BjpsiKst_Nsig_err = sqrt(pow(BjpsiKst_Nsig_fit_err,2) + pow(BjpsiKst_Nsig - BjpsiKst_Nsig_poly,2) + pow(BjpsiKst_Nsig - BjpsiKst_Nsig_novo,2));

  cout<<"Data B->JpsiK* Total"<<endl;
  cout<<BjpsiKst_Nsig<<" +/- "<<BjpsiKst_Nsig_err<<" ( "<<(BjpsiKst_Nsig_err / BjpsiKst_Nsig)*100.0<<" % )"<<endl;


  double data_ratio      = (BjpsiKst_Nsig / BjpsiK_Nsig)*(lumi_BjpsiK/lumi_BjpsiKst);
  double data_ratio_poly = (BjpsiKst_Nsig_poly / BjpsiK_Nsig_poly)*(lumi_BjpsiK/lumi_BjpsiKst);
  double data_ratio_novo = (BjpsiKst_Nsig_novo / BjpsiK_Nsig_novo)*(lumi_BjpsiK/lumi_BjpsiKst);

  cout<<"Data: BJpsiK* / BJpsiK ratio"<<endl;
  cout<<"Nominal     Ratio: "<<data_ratio<<endl;
  cout<<"Poly        Ratio: "<<data_ratio_poly<<endl;
  cout<<"Novosibirsk Ratio: "<<data_ratio_novo<<endl;
  
  double BjpsiKst_gamma00_Nsig         = ((TH2F*)h.Get("Nsig_v_gamma1_pt_gamma2_pt"))->GetBinContent(1,1);
  double BjpsiKst_gamma00_Nsig_fit_err = ((TH2F*)h.Get("Nsig_v_gamma1_pt_gamma2_pt"))->GetBinError(1,1);
  
  double BjpsiKst_gamma00_Nsig_poly =  ((TH2F*)h.Get("Nsig_v_gamma1_pt_gamma2_pt_polynomial"))->GetBinContent(1,1);
  double BjpsiKst_gamma00_Nsig_novo =  ((TH2F*)h.Get("Nsig_v_gamma1_pt_gamma2_pt_novosibirsk"))->GetBinContent(1,1);

  double BjpsiKst_gamma00_Nsig_err = sqrt(pow(BjpsiKst_gamma00_Nsig_fit_err,2) + pow(BjpsiKst_gamma00_Nsig - BjpsiKst_gamma00_Nsig_poly,2) + pow(BjpsiKst_gamma00_Nsig - BjpsiKst_gamma00_Nsig_novo,2));

  cout<<BjpsiKst_gamma00_Nsig<<" +/- "<<BjpsiKst_gamma00_Nsig_err<<" ( "<<(BjpsiKst_gamma00_Nsig_err / BjpsiKst_gamma00_Nsig)*100.0<<" % )"<<endl;

  double data_gamma00_ratio      = (BjpsiKst_gamma00_Nsig / BjpsiK_Nsig)*(lumi_BjpsiK/lumi_BjpsiKst);
  double data_gamma00_ratio_poly = (BjpsiKst_gamma00_Nsig_poly / BjpsiK_Nsig_poly)*(lumi_BjpsiK/lumi_BjpsiKst);
  double data_gamma00_ratio_novo = (BjpsiKst_gamma00_Nsig_novo / BjpsiK_Nsig_novo)*(lumi_BjpsiK/lumi_BjpsiKst);

  cout<<"Data_gamma00_Ratio: "<<data_gamma00_ratio<<endl;
  cout<<"Data_gamma00_Ratio: "<<data_gamma00_ratio_poly<<endl;
  cout<<"Data_gamma00_Ratio: "<<data_gamma00_ratio_novo<<endl;
  
  
  double BjpsiKst_gamma11_Nsig         = ((TH2F*)h.Get("Nsig_v_gamma1_pt_gamma2_pt"))->GetBinContent(2,2);
  double BjpsiKst_gamma11_Nsig_fit_err = ((TH2F*)h.Get("Nsig_v_gamma1_pt_gamma2_pt"))->GetBinError(2,2);
  
  double BjpsiKst_gamma11_Nsig_poly =  ((TH2F*)h.Get("Nsig_v_gamma1_pt_gamma2_pt_polynomial"))->GetBinContent(2,2);
  double BjpsiKst_gamma11_Nsig_novo =  ((TH2F*)h.Get("Nsig_v_gamma1_pt_gamma2_pt_novosibirsk"))->GetBinContent(2,2);

  double BjpsiKst_gamma11_Nsig_err = sqrt(pow(BjpsiKst_gamma11_Nsig_fit_err,2) + pow(BjpsiKst_gamma11_Nsig - BjpsiKst_gamma11_Nsig_poly,2) + pow(BjpsiKst_gamma11_Nsig - BjpsiKst_gamma11_Nsig_novo,2));

  cout<<BjpsiKst_gamma11_Nsig<<" +/- "<<BjpsiKst_gamma11_Nsig_err<<" ( "<<(BjpsiKst_gamma11_Nsig_err / BjpsiKst_gamma11_Nsig)*100.0<<" % )"<<endl;

  double data_gamma11_ratio      = (BjpsiKst_gamma11_Nsig / BjpsiK_Nsig)*(lumi_BjpsiK/lumi_BjpsiKst);
  double data_gamma11_ratio_poly = (BjpsiKst_gamma11_Nsig_poly / BjpsiK_Nsig_poly)*(lumi_BjpsiK/lumi_BjpsiKst);
  double data_gamma11_ratio_novo = (BjpsiKst_gamma11_Nsig_novo / BjpsiK_Nsig_novo)*(lumi_BjpsiK/lumi_BjpsiKst);

  cout<<"Data_gamma11_Ratio: "<<data_gamma11_ratio<<endl;
  cout<<"Data_gamma11_Ratio: "<<data_gamma11_ratio_poly<<endl;
  cout<<"Data_gamma11_Ratio: "<<data_gamma11_ratio_novo<<endl;
  

  // mc
  // correction factor

  
  double BjpsiK_mc_Nsig = ((TParameter<double>*)g.Get("m_Nsig_tot"))->GetVal();
  double BjpsiK_mc_Nsig_fit_err = ((TParameter<double>*)g.Get("m_Nsig_tot_err"))->GetVal();
  
  double BjpsiK_mc_Nsig_poly =  ((TParameter<double>*)g.Get("m_Nsig_polynomial_tot"))->GetVal();
  double BjpsiK_mc_Nsig_novo =  ((TParameter<double>*)g.Get("m_Nsig_novosibirsk_tot"))->GetVal();
  
  double BjpsiK_mc_Nsig_err = sqrt(pow(BjpsiK_mc_Nsig_fit_err,2) + pow(BjpsiK_mc_Nsig - BjpsiK_mc_Nsig_poly,2) + pow(BjpsiK_mc_Nsig - BjpsiK_mc_Nsig_novo,2));

  cout<<BjpsiK_mc_Nsig<<" +/- "<<BjpsiK_mc_Nsig_err<<" ( "<<(BjpsiK_mc_Nsig_err / BjpsiK_mc_Nsig)*100.0<<" % )"<<endl;

  
  double BjpsiKst_mc_Nsig = ((TParameter<double>*)g.Get("m2_Nsig_tot"))->GetVal();
  double BjpsiKst_mc_Nsig_fit_err = ((TParameter<double>*)g.Get("m2_Nsig_tot_err"))->GetVal();
  
  double BjpsiKst_mc_Nsig_poly =  ((TParameter<double>*)g.Get("m2_Nsig_polynomial_tot"))->GetVal();
  double BjpsiKst_mc_Nsig_novo =  ((TParameter<double>*)g.Get("m2_Nsig_novosibirsk_tot"))->GetVal();
  
  double BjpsiKst_mc_Nsig_err = sqrt(pow(BjpsiKst_mc_Nsig_fit_err,2) + pow(BjpsiKst_mc_Nsig - BjpsiKst_mc_Nsig_poly,2) + pow(BjpsiKst_mc_Nsig - BjpsiKst_mc_Nsig_novo,2));

  cout<<BjpsiKst_mc_Nsig<<" +/- "<<BjpsiKst_mc_Nsig_err<<" ( "<<(BjpsiKst_mc_Nsig_err / BjpsiKst_mc_Nsig)*100.0<<" % )"<<endl;

  double mc_ratio      = (BjpsiKst_mc_Nsig / BjpsiK_mc_Nsig)*(lumi_BjpsiK/lumi_BjpsiKst);
  double mc_ratio_poly = (BjpsiKst_mc_Nsig_poly / BjpsiK_mc_Nsig_poly)*(lumi_BjpsiK/lumi_BjpsiKst);
  double mc_ratio_novo = (BjpsiKst_mc_Nsig_novo / BjpsiK_mc_Nsig_novo)*(lumi_BjpsiK/lumi_BjpsiKst);

  cout<<"Ratio (MC): "<<mc_ratio<<endl;
  cout<<"Ratio (MC): "<<mc_ratio_poly<<endl;
  cout<<"Ratio (MC): "<<mc_ratio_novo<<endl;
  

  double double_ratio      = data_ratio/mc_ratio;
  double double_ratio_poly = data_ratio_poly/mc_ratio_poly;
  double double_ratio_novo = data_ratio_novo/mc_ratio_novo;

  cout<<"Double Ratio: "<<data_ratio/mc_ratio<<endl;
  cout<<"Double Ratio: "<<data_ratio_poly/mc_ratio_poly<<endl;
  cout<<"Double Ratio: "<<data_ratio_novo/mc_ratio_novo<<endl;

  double double_ratio_err = sqrt(pow(double_ratio - double_ratio_poly,2)+pow(double_ratio - double_ratio_novo,2));
  cout<<"double ratio: "<<double_ratio<<" +/- "<<double_ratio_err<<" ("<<(double_ratio_err / double_ratio)*100<<" %)"<<endl;

  double BjpsiKst_mc_gamma00_Nsig         = ((TH2F*)i.Get("Nsig_v_gamma1_pt_gamma2_pt"))->GetBinContent(1,1);
  double BjpsiKst_mc_gamma00_Nsig_fit_err = ((TH2F*)i.Get("Nsig_v_gamma1_pt_gamma2_pt"))->GetBinError(1,1);
  
  double BjpsiKst_mc_gamma00_Nsig_poly =  ((TH2F*)i.Get("Nsig_v_gamma1_pt_gamma2_pt_polynomial"))->GetBinContent(1,1);
  double BjpsiKst_mc_gamma00_Nsig_novo =  ((TH2F*)i.Get("Nsig_v_gamma1_pt_gamma2_pt_novosibirsk"))->GetBinContent(1,1);
  
  double BjpsiKst_mc_gamma00_Nsig_err = sqrt(pow(BjpsiKst_mc_gamma00_Nsig_fit_err,2) + pow(BjpsiKst_mc_gamma00_Nsig - BjpsiKst_mc_gamma00_Nsig_poly,2) + pow(BjpsiKst_mc_gamma00_Nsig - BjpsiKst_mc_gamma00_Nsig_novo,2));

  cout<<BjpsiKst_mc_gamma00_Nsig<<" +/- "<<BjpsiKst_mc_gamma00_Nsig_err<<" ( "<<(BjpsiKst_mc_gamma00_Nsig_err / BjpsiKst_mc_gamma00_Nsig)*100.0<<" % )"<<endl;

  double mc_gamma00_ratio      = (BjpsiKst_mc_gamma00_Nsig / BjpsiK_mc_Nsig)*(lumi_BjpsiK/lumi_BjpsiKst);
  double mc_gamma00_ratio_poly = (BjpsiKst_mc_gamma00_Nsig_poly / BjpsiK_mc_Nsig_poly)*(lumi_BjpsiK/lumi_BjpsiKst);
  double mc_gamma00_ratio_novo = (BjpsiKst_mc_gamma00_Nsig_novo / BjpsiK_mc_Nsig_novo)*(lumi_BjpsiK/lumi_BjpsiKst);

  cout<<"Ratio gamma00 (MC): "<<mc_gamma00_ratio<<endl;
  cout<<"Ratio gamma00 (MC): "<<mc_gamma00_ratio_poly<<endl;
  cout<<"Ratio gamma00 (MC): "<<mc_gamma00_ratio_novo<<endl;

  double double_gamma00_ratio      = data_gamma00_ratio/mc_gamma00_ratio;
  double double_gamma00_ratio_poly = data_gamma00_ratio_poly/mc_gamma00_ratio_poly;
  double double_gamma00_ratio_novo = data_gamma00_ratio_novo/mc_gamma00_ratio_novo;

  cout<<"Double gamma00 Ratio: "<<data_gamma00_ratio/mc_gamma00_ratio<<endl;
  cout<<"Double gamma00 Ratio: "<<data_gamma00_ratio_poly/mc_gamma00_ratio_poly<<endl;
  cout<<"Double gamma00 Ratio: "<<data_gamma00_ratio_novo/mc_gamma00_ratio_novo<<endl;

  double double_gamma00_ratio_err = sqrt(pow(double_gamma00_ratio - double_gamma00_ratio_poly,2)+pow(double_gamma00_ratio - double_gamma00_ratio_novo,2));
  cout<<"double gamma00_ratio: "<<double_gamma00_ratio<<" +/- "<<double_gamma00_ratio_err<<" ("<<(double_gamma00_ratio_err / double_gamma00_ratio)*100<<" %)"<<endl;

  
  double BjpsiKst_mc_gamma11_Nsig         = ((TH2F*)i.Get("Nsig_v_gamma1_pt_gamma2_pt"))->GetBinContent(2,2);
  double BjpsiKst_mc_gamma11_Nsig_fit_err = ((TH2F*)i.Get("Nsig_v_gamma1_pt_gamma2_pt"))->GetBinError(2,2);
  
  double BjpsiKst_mc_gamma11_Nsig_poly =  ((TH2F*)i.Get("Nsig_v_gamma1_pt_gamma2_pt_polynomial"))->GetBinContent(2,2);
  double BjpsiKst_mc_gamma11_Nsig_novo =  ((TH2F*)i.Get("Nsig_v_gamma1_pt_gamma2_pt_novosibirsk"))->GetBinContent(2,2);
  
  double BjpsiKst_mc_gamma11_Nsig_err = sqrt(pow(BjpsiKst_mc_gamma11_Nsig_fit_err,2) + pow(BjpsiKst_mc_gamma11_Nsig - BjpsiKst_mc_gamma11_Nsig_poly,2) + pow(BjpsiKst_mc_gamma11_Nsig - BjpsiKst_mc_gamma11_Nsig_novo,2));

  cout<<BjpsiKst_mc_gamma11_Nsig<<" +/- "<<BjpsiKst_mc_gamma11_Nsig_err<<" ( "<<(BjpsiKst_mc_gamma11_Nsig_err / BjpsiKst_mc_gamma11_Nsig)*100.0<<" % )"<<endl;

  double mc_gamma11_ratio      = (BjpsiKst_mc_gamma11_Nsig / BjpsiK_mc_Nsig)*(lumi_BjpsiK/lumi_BjpsiKst);
  double mc_gamma11_ratio_poly = (BjpsiKst_mc_gamma11_Nsig_poly / BjpsiK_mc_Nsig_poly)*(lumi_BjpsiK/lumi_BjpsiKst);
  double mc_gamma11_ratio_novo = (BjpsiKst_mc_gamma11_Nsig_novo / BjpsiK_mc_Nsig_novo)*(lumi_BjpsiK/lumi_BjpsiKst);

  cout<<"Ratio gamma11 (MC): "<<mc_gamma11_ratio<<endl;
  cout<<"Ratio gamma11 (MC): "<<mc_gamma11_ratio_poly<<endl;
  cout<<"Ratio gamma11 (MC): "<<mc_gamma11_ratio_novo<<endl;

  double double_gamma11_ratio      = data_gamma11_ratio/mc_gamma11_ratio;
  double double_gamma11_ratio_poly = data_gamma11_ratio_poly/mc_gamma11_ratio_poly;
  double double_gamma11_ratio_novo = data_gamma11_ratio_novo/mc_gamma11_ratio_novo;

  cout<<"Double gamma11 Ratio: "<<data_gamma11_ratio/mc_gamma11_ratio<<endl;
  cout<<"Double gamma11 Ratio: "<<data_gamma11_ratio_poly/mc_gamma11_ratio_poly<<endl;
  cout<<"Double gamma11 Ratio: "<<data_gamma11_ratio_novo/mc_gamma11_ratio_novo<<endl;

  double double_gamma11_ratio_err = sqrt(pow(double_gamma11_ratio - double_gamma11_ratio_poly,2)+pow(double_gamma11_ratio - double_gamma11_ratio_novo,2));
  cout<<"double gamma11_ratio: "<<double_gamma11_ratio<<" +/- "<<double_gamma11_ratio_err<<" ("<<(double_gamma11_ratio_err / double_gamma11_ratio)*100<<" %)"<<endl;
}
