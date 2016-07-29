void fill_th1f(const char* name, TH1F* h, TH1F* h2){
  int i;
  stringstream s, s2;
  s<<"/user2/sfarry/WJet/octave/"<<name<<"_staterr.oct";
  s2<<"/user2/sfarry/WJet/octave/"<<name<<"_toterr.oct";
  cout<<s.str()<<endl;
  cout<<s2.str()<<endl;
  double x, y;
  string line;
  ifstream in;
  in.open(s.str().c_str());
  i = 0;
  while(getline(in, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      h->SetBinContent(i+1, x);
      h->SetBinError(i+1, y);
      i++;
    }
  }

  ifstream in2;
  in2.open(s2.str().c_str());
  i = 0;
  while(getline(in2, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      h2->SetBinContent(i+1, x);
      h2->SetBinError(i+1, y);
      i++;
    }
  }
  h->Write();
  h2->Write();
  
}

void createXsecs(){
  double x = 0.0, y = 0.0;
  Float_t etaj[] = {2.2, 2.7, 3.2, 3.7, 4.2};
  Float_t eta[]  = {2.0, 2.5, 3.0, 3.5, 4.5};
  Float_t ptj[]  = {20, 25, 30, 40, 50, 100};
  TH1F* wp_etaj_toterr  = new TH1F("wp_etaj_toterr" , "wp_etaj", 4, etaj);
  TH1F* wp_etaj_staterr = new TH1F("wp_etaj_staterr", "wp_etaj", 4, etaj);
  TH1F* wp_eta_toterr   = new TH1F("wp_eta_toterr"  , "wp_eta", 4, eta);
  TH1F* wp_eta_staterr  = new TH1F("wp_eta_staterr" , "wp_eta", 4, eta);
  TH1F* wp_ptj_toterr   = new TH1F("wp_ptj_toterr"  , "wp_ptj", 5, ptj);
  TH1F* wp_ptj_staterr  = new TH1F("wp_ptj_staterr" , "wp_ptj", 5, ptj);

  TH1F* wm_etaj_toterr  = new TH1F("wm_etaj_toterr" , "wm_etaj", 4, etaj);
  TH1F* wm_etaj_staterr = new TH1F("wm_etaj_staterr", "wm_etaj", 4, etaj);
  TH1F* wm_eta_toterr   = new TH1F("wm_eta_toterr"  , "wm_eta", 4, eta);
  TH1F* wm_eta_staterr  = new TH1F("wm_eta_staterr" , "wm_eta", 4, eta);
  TH1F* wm_ptj_toterr   = new TH1F("wm_ptj_toterr"  , "wm_ptj", 5, ptj);
  TH1F* wm_ptj_staterr  = new TH1F("wm_ptj_staterr" , "wm_ptj", 5, ptj);

  TH1F* w_a_eta_toterr   = new TH1F("w_a_eta_toterr"  , "w_eta", 4, eta);
  TH1F* w_a_eta_staterr  = new TH1F("w_a_eta_staterr" , "w_eta", 4, eta);
  TH1F* w_r_eta_toterr   = new TH1F("w_r_eta_toterr"  , "w_eta", 4, eta);
  TH1F* w_r_eta_staterr  = new TH1F("w_r_eta_staterr" , "w_eta", 4, eta);

  TH1F* w_a_ptj_toterr   = new TH1F("w_a_ptj_toterr"  , "w_ptj", 5, ptj);
  TH1F* w_a_ptj_staterr  = new TH1F("w_a_ptj_staterr" , "w_ptj", 5, ptj);
  TH1F* w_r_ptj_toterr   = new TH1F("w_r_ptj_toterr"  , "w_ptj", 5, ptj);
  TH1F* w_r_ptj_staterr  = new TH1F("w_r_ptj_staterr" , "w_ptj", 5, ptj);

  
  
  TH1F* z_etaj_toterr  = new TH1F("z_etaj_toterr" , "z_etaj", 4, etaj);
  TH1F* z_etaj_staterr = new TH1F("z_etaj_staterr", "z_etaj", 4, etaj);
  TH1F* z_y_toterr     = new TH1F("z_y_toterr"  , "z_y", 4, eta);
  TH1F* z_y_staterr    = new TH1F("z_y_staterr" , "z_y", 4, eta);
  TH1F* z_ptj_toterr   = new TH1F("z_ptj_toterr"  , "z_ptj", 5, ptj);
  TH1F* z_ptj_staterr  = new TH1F("z_ptj_staterr" , "z_ptj", 5, ptj);
  TH1F* z_dphi_toterr   = new TH1F("z_dphi_toterr"  , "z_dphi", 6, 0, TMath::Pi());
  TH1F* z_dphi_staterr  = new TH1F("z_dphi_staterr" , "z_dphi", 6, 0, TMath::Pi());


  
  
  
  TFile f("/user2/sfarry/WJet/tuples/xsecs.root", "RECREATE");
  fill_th1f("zmumu_y"    , z_y_staterr, z_y_toterr);
  fill_th1f("zmumu_etaj" , z_etaj_staterr, z_etaj_toterr);
  fill_th1f("zmumu_ptj"  , z_ptj_staterr , z_ptj_toterr);
  fill_th1f("zmumu_dphi"  , z_dphi_staterr , z_dphi_toterr);

  fill_th1f("wp_eta"  , wp_eta_staterr , wp_eta_toterr);
  fill_th1f("wp_etaj" , wp_etaj_staterr, wp_etaj_toterr);
  fill_th1f("wp_ptj"  , wp_ptj_staterr , wp_ptj_toterr);

  fill_th1f("wm_eta"  , wm_eta_staterr , wm_eta_toterr);
  fill_th1f("wm_etaj" , wm_etaj_staterr, wm_etaj_toterr);
  fill_th1f("wm_ptj"  , wm_ptj_staterr , wm_ptj_toterr);

  fill_th1f("w_a_eta"  , w_a_eta_staterr , w_a_eta_toterr);
  fill_th1f("w_r_eta"  , w_r_eta_staterr , w_r_eta_toterr);

  fill_th1f("w_a_ptj"  , w_a_ptj_staterr , w_a_ptj_toterr);
  fill_th1f("w_r_ptj"  , w_r_ptj_staterr , w_r_ptj_toterr);
  
  f.Close();
}
