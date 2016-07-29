void createGraphs(){
  double x = 0.0, y = 0.0;
  Float_t etaj[] = {2.2, 2.7, 3.2, 3.7, 4.2};
  Float_t eta[]  = {2.0, 2.5, 3.0, 3.5, 4.5};
  Float_t ptj[]  = {20000, 25000, 30000, 40000, 50000, 100000};
  TH1F* wp_etaj = new TH1F("wp_etaj", "wp_etaj", 4, etaj);
  TH1F* wm_etaj = new TH1F("wm_etaj", "wm_etaj", 4, etaj);
  TH1F* z_etaj  = new TH1F("z_etaj" , "z_etaj" , 4, etaj);
  TH1F* wp_eta  = new TH1F("wp_eta" , "wp_eta", 4, eta);
  TH1F* wm_eta  = new TH1F("wm_eta" , "wm_eta", 4, eta);
  TH1F* z_y     = new TH1F("z_y"    , "z_y"   , 4, eta);
  TH1F* wp_ptj  = new TH1F("wp_ptj" , "wp_ptj", 5, ptj);
  TH1F* wm_ptj  = new TH1F("wm_ptj" , "wm_ptj", 5, ptj);
  TH1F* z_ptj   = new TH1F("z_ptj"  , "z_ptj" , 5, ptj);
  TH1F* z_dphi  = new TH1F("z_dphi" , "z_dphi" , 6, 0, TMath::Pi());
  int i;
  string line;
  ifstream in;
  in.open("/user2/sfarry/WJet/octave/wp_etaj_muoneff.oct");
  i = 0;
  while(getline(in, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      wp_etaj->SetBinContent(i+1, x);
      wp_etaj->SetBinError(i+1, y);
      i++;
    }
  }
  
  ifstream in2;
  in2.open("/user2/sfarry/WJet/octave/wm_etaj_muoneff.oct");
  i = 0;
  while(getline(in2, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      wm_etaj->SetBinContent(i+1, x);
      wm_etaj->SetBinError(i+1, y);
      i++;
    }
  }

  ifstream in3;
  in3.open("/user2/sfarry/WJet/octave/wp_eta_muoneff.oct");
  i = 0;
  while(getline(in3, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      wp_eta->SetBinContent(i+1, x);
      wp_eta->SetBinError(i+1, y);
      i++;
    }
  }

  ifstream in4;
  in4.open("/user2/sfarry/WJet/octave/wm_eta_muoneff.oct");
  i = 0;
  while(getline(in4, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      wm_eta->SetBinContent(i+1, x);
      wm_eta->SetBinError(i+1, y);
      i++;
    }
  }

  ifstream in5;
  in5.open("/user2/sfarry/WJet/octave/wp_ptj_muoneff.oct");
  i = 0;
  while(getline(in5, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      wp_ptj->SetBinContent(i+1, x);
      wp_ptj->SetBinError(i+1, y);
      i++;
    }
  }

  ifstream in6;
  in6.open("/user2/sfarry/WJet/octave/wm_ptj_muoneff.oct");
  i = 0;
  while(getline(in6, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      wm_ptj->SetBinContent(i+1, x);
      wm_ptj->SetBinError(i+1, y);
      i++;
    }
  }
  ifstream in7;
  in7.open("/user2/sfarry/WJet/octave/z_etaj_muoneff.oct");
  i = 0;
  while(getline(in7, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      z_etaj->SetBinContent(i+1, x);
      z_etaj->SetBinError(i+1, y);
      i++;
    }
  }
  ifstream in8;
  in8.open("/user2/sfarry/WJet/octave/z_y_muoneff.oct");
  i = 0;
  while(getline(in8, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      z_y->SetBinContent(i+1, x);
      z_y->SetBinError(i+1, y);
      i++;
    }
  }
  ifstream in9;
  in9.open("/user2/sfarry/WJet/octave/z_ptj_muoneff.oct");
  i = 0;
  while(getline(in9, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      z_ptj->SetBinContent(i+1, x);
      z_ptj->SetBinError(i+1, y);
      i++;
    }
  }
  ifstream in10;
  in10.open("/user2/sfarry/WJet/octave/z_dphi_muoneff.oct");
  i = 0;
  while(getline(in10, line)){
    if (line[0] != '#'){
      if(line[0] == ' ') line.erase(line.begin());
      istringstream iss(line, istringstream::in);
      iss>>x>>y;
      z_dphi->SetBinContent(i+1, x);
      z_dphi->SetBinError(i+1, y);
      i++;
    }
  }
  
  TFile f("/user2/sfarry/WJet/tuples/effs.root", "RECREATE");
  wp_etaj->Write();
  wm_etaj->Write();
  wp_eta->Write();
  wm_eta->Write();
  wp_ptj->Write();
  wm_ptj->Write();
  z_etaj->Write();
  z_y->Write();
  z_ptj->Write();
  z_dphi->Write();
  f.Close();
}
