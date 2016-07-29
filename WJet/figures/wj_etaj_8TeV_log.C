void wj_etaj_8TeV_log()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Thu Apr 28 10:19:35 2016) by ROOT version6.04/10
   TCanvas *default_Canvas = new TCanvas("default_Canvas", "defaultCanvas",0,0,600,800);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   default_Canvas->SetHighLightColor(2);
   default_Canvas->Range(0,0,1,1);
   default_Canvas->SetFillColor(0);
   default_Canvas->SetBorderMode(0);
   default_Canvas->SetBorderSize(2);
   default_Canvas->SetTickx(1);
   default_Canvas->SetTicky(1);
   default_Canvas->SetLeftMargin(0.14);
   default_Canvas->SetRightMargin(0.05);
   default_Canvas->SetTopMargin(0.05);
   default_Canvas->SetBottomMargin(0.16);
   default_Canvas->SetFrameLineWidth(2);
   default_Canvas->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: bottomPad
   TPad *bottomPad = new TPad("bottomPad", "bottomPad",0.005,0.05,0.995,0.995);
   bottomPad->Draw();
   bottomPad->cd();
   bottomPad->Range(-0.1728395,-0.5345454,1.061728,3.283636);
   bottomPad->SetFillColor(0);
   bottomPad->SetFillStyle(4000);
   bottomPad->SetBorderMode(0);
   bottomPad->SetBorderSize(2);
   bottomPad->SetTickx(1);
   bottomPad->SetTicky(1);
   bottomPad->SetLeftMargin(0.14);
   bottomPad->SetRightMargin(0.05);
   bottomPad->SetTopMargin(0.585);
   bottomPad->SetBottomMargin(0.14);
   bottomPad->SetFrameLineWidth(2);
   bottomPad->SetFrameBorderMode(0);
   bottomPad->SetFrameLineWidth(2);
   bottomPad->SetFrameBorderMode(0);
   
   TH1F *__80 = new TH1F("__80","",1,0,1);
   __80->SetDirectory(0);
   __80->SetStats(0);
   __80->SetFillStyle(0);
   __80->SetLineWidth(2);
   __80->SetMarkerStyle(0);
   __80->GetXaxis()->SetNdivisions(4);
   __80->GetXaxis()->SetLabelFont(132);
   __80->GetXaxis()->SetLabelOffset(999);
   __80->GetXaxis()->SetLabelSize(0);
   __80->GetXaxis()->SetTitleSize(0.06);
   __80->GetXaxis()->SetTitleFont(132);
   __80->GetYaxis()->SetTitle("Ratio");
   __80->GetYaxis()->CenterTitle(true);
   __80->GetYaxis()->SetLabelFont(132);
   __80->GetYaxis()->SetLabelOffset(999);
   __80->GetYaxis()->SetLabelSize(0.05);
   __80->GetYaxis()->SetTitleSize(0.06);
   __80->GetYaxis()->SetTitleFont(132);
   __80->GetZaxis()->SetLabelFont(132);
   __80->GetZaxis()->SetLabelSize(0.05);
   __80->GetZaxis()->SetTitleSize(0.06);
   __80->GetZaxis()->SetTitleFont(132);
   __80->Draw("");
   
   TH1F *_copy__81 = new TH1F("_copy__81","",1,0,1);
   _copy__81->SetDirectory(0);
   _copy__81->SetStats(0);
   _copy__81->SetFillStyle(0);
   _copy__81->SetLineWidth(2);
   _copy__81->SetMarkerStyle(0);
   _copy__81->GetXaxis()->SetNdivisions(4);
   _copy__81->GetXaxis()->SetLabelFont(132);
   _copy__81->GetXaxis()->SetLabelOffset(999);
   _copy__81->GetXaxis()->SetLabelSize(0);
   _copy__81->GetXaxis()->SetTitleSize(0.06);
   _copy__81->GetXaxis()->SetTitleFont(132);
   _copy__81->GetYaxis()->SetTitle("Ratio");
   _copy__81->GetYaxis()->CenterTitle(true);
   _copy__81->GetYaxis()->SetLabelFont(132);
   _copy__81->GetYaxis()->SetLabelOffset(999);
   _copy__81->GetYaxis()->SetLabelSize(0.05);
   _copy__81->GetYaxis()->SetTitleSize(0.06);
   _copy__81->GetYaxis()->SetTitleFont(132);
   _copy__81->GetZaxis()->SetLabelFont(132);
   _copy__81->GetZaxis()->SetLabelSize(0.05);
   _copy__81->GetZaxis()->SetTitleSize(0.06);
   _copy__81->GetZaxis()->SetTitleFont(132);
   _copy__81->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(1.854321,-6.722716,4.323457,2.35708);
   upperPad->SetFillColor(0);
   upperPad->SetFillStyle(4000);
   upperPad->SetBorderMode(0);
   upperPad->SetBorderSize(2);
   upperPad->SetLogy();
   upperPad->SetTickx(1);
   upperPad->SetTicky(1);
   upperPad->SetLeftMargin(0.14);
   upperPad->SetRightMargin(0.05);
   upperPad->SetTopMargin(0.05);
   upperPad->SetBottomMargin(0.41);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   Double_t xAxis66[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_toterr__82 = new TH1F("wp_etaj_toterr__82","wp_etaj",4, xAxis66);
   wp_etaj_toterr__82->SetBinContent(1,48.4905);
   wp_etaj_toterr__82->SetBinContent(2,35.86988);
   wp_etaj_toterr__82->SetBinContent(3,21.33691);
   wp_etaj_toterr__82->SetBinContent(4,8.08127);
   wp_etaj_toterr__82->SetBinContent(5,4.040633);
   wp_etaj_toterr__82->SetBinError(1,4.411155);
   wp_etaj_toterr__82->SetBinError(2,3.103339);
   wp_etaj_toterr__82->SetBinError(3,1.964878);
   wp_etaj_toterr__82->SetBinError(4,1.063724);
   wp_etaj_toterr__82->SetBinError(5,0.5318616);
   wp_etaj_toterr__82->SetMinimum(0.001);
   wp_etaj_toterr__82->SetMaximum(80);
   wp_etaj_toterr__82->SetEntries(10);
   wp_etaj_toterr__82->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__82->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__82->SetLineColor(ci);
   wp_etaj_toterr__82->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__82->SetMarkerColor(ci);
   wp_etaj_toterr__82->SetMarkerStyle(0);
   wp_etaj_toterr__82->GetXaxis()->SetNdivisions(4);
   wp_etaj_toterr__82->GetXaxis()->SetLabelFont(132);
   wp_etaj_toterr__82->GetXaxis()->SetLabelOffset(999);
   wp_etaj_toterr__82->GetXaxis()->SetLabelSize(0);
   wp_etaj_toterr__82->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__82->GetXaxis()->SetTitleFont(132);
   wp_etaj_toterr__82->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_toterr__82->GetYaxis()->SetLabelFont(132);
   wp_etaj_toterr__82->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__82->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__82->GetYaxis()->SetTitleFont(132);
   wp_etaj_toterr__82->GetZaxis()->SetLabelFont(132);
   wp_etaj_toterr__82->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__82->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__82->GetZaxis()->SetTitleFont(132);
   wp_etaj_toterr__82->Draw("e2");
   Double_t xAxis67[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_staterr__83 = new TH1F("wp_etaj_staterr__83","wp_etaj",4, xAxis67);
   wp_etaj_staterr__83->SetBinContent(1,48.4905);
   wp_etaj_staterr__83->SetBinContent(2,35.86988);
   wp_etaj_staterr__83->SetBinContent(3,21.33691);
   wp_etaj_staterr__83->SetBinContent(4,8.08127);
   wp_etaj_staterr__83->SetBinContent(5,4.040633);
   wp_etaj_staterr__83->SetBinError(1,0.2913562);
   wp_etaj_staterr__83->SetBinError(2,0.2625);
   wp_etaj_staterr__83->SetBinError(3,0.2016292);
   wp_etaj_staterr__83->SetBinError(4,0.1160552);
   wp_etaj_staterr__83->SetBinError(5,0.05802755);
   wp_etaj_staterr__83->SetMinimum(0.001);
   wp_etaj_staterr__83->SetMaximum(80);
   wp_etaj_staterr__83->SetEntries(10);
   wp_etaj_staterr__83->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__83->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__83->SetLineColor(ci);
   wp_etaj_staterr__83->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__83->SetMarkerColor(ci);
   wp_etaj_staterr__83->SetMarkerStyle(0);
   wp_etaj_staterr__83->GetXaxis()->SetNdivisions(4);
   wp_etaj_staterr__83->GetXaxis()->SetLabelFont(132);
   wp_etaj_staterr__83->GetXaxis()->SetLabelOffset(999);
   wp_etaj_staterr__83->GetXaxis()->SetLabelSize(0);
   wp_etaj_staterr__83->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__83->GetXaxis()->SetTitleFont(132);
   wp_etaj_staterr__83->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_staterr__83->GetYaxis()->SetLabelFont(132);
   wp_etaj_staterr__83->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__83->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__83->GetYaxis()->SetTitleFont(132);
   wp_etaj_staterr__83->GetZaxis()->SetLabelFont(132);
   wp_etaj_staterr__83->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__83->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__83->GetZaxis()->SetTitleFont(132);
   wp_etaj_staterr__83->Draw("e2same");
   Double_t xAxis68[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_toterr__84 = new TH1F("wm_etaj_toterr__84","wm_etaj",4, xAxis68);
   wm_etaj_toterr__84->SetBinContent(1,30.50039);
   wm_etaj_toterr__84->SetBinContent(2,20.57146);
   wm_etaj_toterr__84->SetBinContent(3,11.20298);
   wm_etaj_toterr__84->SetBinContent(4,3.930728);
   wm_etaj_toterr__84->SetBinContent(5,1.965363);
   wm_etaj_toterr__84->SetBinError(1,3.140994);
   wm_etaj_toterr__84->SetBinError(2,2.204208);
   wm_etaj_toterr__84->SetBinError(3,1.339208);
   wm_etaj_toterr__84->SetBinError(4,0.6610862);
   wm_etaj_toterr__84->SetBinError(5,0.3305429);
   wm_etaj_toterr__84->SetMinimum(0.001);
   wm_etaj_toterr__84->SetMaximum(80);
   wm_etaj_toterr__84->SetEntries(10);
   wm_etaj_toterr__84->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__84->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__84->SetLineColor(ci);
   wm_etaj_toterr__84->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__84->SetMarkerColor(ci);
   wm_etaj_toterr__84->SetMarkerStyle(0);
   wm_etaj_toterr__84->GetXaxis()->SetNdivisions(4);
   wm_etaj_toterr__84->GetXaxis()->SetLabelFont(132);
   wm_etaj_toterr__84->GetXaxis()->SetLabelOffset(999);
   wm_etaj_toterr__84->GetXaxis()->SetLabelSize(0);
   wm_etaj_toterr__84->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__84->GetXaxis()->SetTitleFont(132);
   wm_etaj_toterr__84->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wm_etaj_toterr__84->GetYaxis()->SetLabelFont(132);
   wm_etaj_toterr__84->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__84->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__84->GetYaxis()->SetTitleFont(132);
   wm_etaj_toterr__84->GetZaxis()->SetLabelFont(132);
   wm_etaj_toterr__84->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__84->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__84->GetZaxis()->SetTitleFont(132);
   wm_etaj_toterr__84->Draw("e2same");
   Double_t xAxis69[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_staterr__85 = new TH1F("wm_etaj_staterr__85","wm_etaj",4, xAxis69);
   wm_etaj_staterr__85->SetBinContent(1,30.50039);
   wm_etaj_staterr__85->SetBinContent(2,20.57146);
   wm_etaj_staterr__85->SetBinContent(3,11.20298);
   wm_etaj_staterr__85->SetBinContent(4,3.930728);
   wm_etaj_staterr__85->SetBinContent(5,1.965363);
   wm_etaj_staterr__85->SetBinError(1,0.2315095);
   wm_etaj_staterr__85->SetBinError(2,0.1981347);
   wm_etaj_staterr__85->SetBinError(3,0.1458553);
   wm_etaj_staterr__85->SetBinError(4,0.08079061);
   wm_etaj_staterr__85->SetBinError(5,0.04039529);
   wm_etaj_staterr__85->SetMinimum(0.001);
   wm_etaj_staterr__85->SetMaximum(80);
   wm_etaj_staterr__85->SetEntries(10);
   wm_etaj_staterr__85->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__85->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__85->SetLineColor(ci);
   wm_etaj_staterr__85->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__85->SetMarkerColor(ci);
   wm_etaj_staterr__85->SetMarkerStyle(0);
   wm_etaj_staterr__85->GetXaxis()->SetNdivisions(4);
   wm_etaj_staterr__85->GetXaxis()->SetLabelFont(132);
   wm_etaj_staterr__85->GetXaxis()->SetLabelOffset(999);
   wm_etaj_staterr__85->GetXaxis()->SetLabelSize(0);
   wm_etaj_staterr__85->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__85->GetXaxis()->SetTitleFont(132);
   wm_etaj_staterr__85->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wm_etaj_staterr__85->GetYaxis()->SetLabelFont(132);
   wm_etaj_staterr__85->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__85->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__85->GetYaxis()->SetTitleFont(132);
   wm_etaj_staterr__85->GetZaxis()->SetLabelFont(132);
   wm_etaj_staterr__85->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__85->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__85->GetZaxis()->SetTitleFont(132);
   wm_etaj_staterr__85->Draw("e2same");
   
   Double_t etaj_plus_toterrs_fx3097[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_plus_toterrs_fy3097[4] = {
   51.28224,
   38.08475,
   22.54357,
   9.721132};
   Double_t etaj_plus_toterrs_felx3097[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fely3097[4] = {
   4.135599,
   2.864222,
   1.897241,
   1.171681};
   Double_t etaj_plus_toterrs_fehx3097[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fehy3097[4] = {
   3.726354,
   2.706163,
   1.524886,
   1.41675};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,etaj_plus_toterrs_fx3097,etaj_plus_toterrs_fy3097,etaj_plus_toterrs_felx3097,etaj_plus_toterrs_fehx3097,etaj_plus_toterrs_fely3097,etaj_plus_toterrs_fehy3097);
   grae->SetName("etaj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_etaj_plus_toterrs305730813097 = new TH1F("Graph_Graph_Graph_etaj_plus_toterrs305730813097","",100,2.375,4.175);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->SetMinimum(0.001);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->SetMaximum(80);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->SetDirectory(0);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->SetStats(0);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->SetLineWidth(2);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->SetMarkerStyle(0);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_plus_toterrs305730813097->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_etaj_plus_toterrs305730813097);
   
   grae->Draw("p1p");
   
   Double_t etaj_plus_toterrs_fx3098[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_plus_toterrs_fy3098[4] = {
   52.81753,
   39.16372,
   22.80511,
   9.659266};
   Double_t etaj_plus_toterrs_felx3098[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fely3098[4] = {
   4.306575,
   3.058371,
   1.708201,
   0.8035311};
   Double_t etaj_plus_toterrs_fehx3098[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fehy3098[4] = {
   4.54964,
   3.141914,
   1.795995,
   0.9815417};
   grae = new TGraphAsymmErrors(4,etaj_plus_toterrs_fx3098,etaj_plus_toterrs_fy3098,etaj_plus_toterrs_felx3098,etaj_plus_toterrs_fehx3098,etaj_plus_toterrs_fely3098,etaj_plus_toterrs_fehy3098);
   grae->SetName("etaj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_etaj_plus_toterrs305930823098 = new TH1F("Graph_Graph_Graph_etaj_plus_toterrs305930823098","",100,2.225,4.025);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->SetMinimum(0.001);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->SetMaximum(80);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->SetDirectory(0);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->SetStats(0);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->SetLineWidth(2);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->SetMarkerStyle(0);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_plus_toterrs305930823098->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_etaj_plus_toterrs305930823098);
   
   grae->Draw("p1p");
   
   Double_t etaj_minus_toterrs_fx3099[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_minus_toterrs_fy3099[4] = {
   33.75167,
   23.54495,
   13.13125,
   5.618726};
   Double_t etaj_minus_toterrs_felx3099[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fely3099[4] = {
   3.331792,
   2.081235,
   1.468378,
   0.5957157};
   Double_t etaj_minus_toterrs_fehx3099[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fehy3099[4] = {
   2.655911,
   1.820553,
   0.9805522,
   0.8736437};
   grae = new TGraphAsymmErrors(4,etaj_minus_toterrs_fx3099,etaj_minus_toterrs_fy3099,etaj_minus_toterrs_felx3099,etaj_minus_toterrs_fehx3099,etaj_minus_toterrs_fely3099,etaj_minus_toterrs_fehy3099);
   grae->SetName("etaj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_etaj_minus_toterrs306930833099 = new TH1F("Graph_Graph_Graph_etaj_minus_toterrs306930833099","",100,2.375,4.175);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->SetMinimum(0.001);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->SetMaximum(80);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->SetDirectory(0);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->SetStats(0);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->SetLineWidth(2);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->SetMarkerStyle(0);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_minus_toterrs306930833099->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_etaj_minus_toterrs306930833099);
   
   grae->Draw("p1p");
   
   Double_t etaj_minus_toterrs_fx3100[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_minus_toterrs_fy3100[4] = {
   34.25415,
   23.32036,
   12.9946,
   5.344251};
   Double_t etaj_minus_toterrs_felx3100[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fely3100[4] = {
   2.822029,
   1.901017,
   1.140151,
   0.5488711};
   Double_t etaj_minus_toterrs_fehx3100[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fehy3100[4] = {
   2.930556,
   2.008099,
   1.186782,
   0.6439278};
   grae = new TGraphAsymmErrors(4,etaj_minus_toterrs_fx3100,etaj_minus_toterrs_fy3100,etaj_minus_toterrs_felx3100,etaj_minus_toterrs_fehx3100,etaj_minus_toterrs_fely3100,etaj_minus_toterrs_fehy3100);
   grae->SetName("etaj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_etaj_minus_toterrs307130843100 = new TH1F("Graph_Graph_Graph_etaj_minus_toterrs307130843100","",100,2.225,4.025);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->SetMinimum(0.001);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->SetMaximum(80);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->SetDirectory(0);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->SetStats(0);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->SetLineWidth(2);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->SetMarkerStyle(0);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_etaj_minus_toterrs307130843100->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_etaj_minus_toterrs307130843100);
   
   grae->Draw("p1p");
   
   Double_t _fx3101[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3101[4] = {
   51.28224,
   38.08475,
   22.54357,
   9.721132};
   Double_t _felx3101[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3101[4] = {
   2.936905,
   2.066395,
   1.139271,
   0.5043745};
   Double_t _fehx3101[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3101[4] = {
   2.927589,
   2.099415,
   1.044388,
   0.5327406};
   grae = new TGraphAsymmErrors(4,_fx3101,_fy3101,_felx3101,_fehx3101,_fely3101,_fehy3101);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph305830853101 = new TH1F("Graph_Graph_Graph_Graph305830853101","",100,2.375,4.175);
   Graph_Graph_Graph_Graph305830853101->SetMinimum(0.001);
   Graph_Graph_Graph_Graph305830853101->SetMaximum(80);
   Graph_Graph_Graph_Graph305830853101->SetDirectory(0);
   Graph_Graph_Graph_Graph305830853101->SetStats(0);
   Graph_Graph_Graph_Graph305830853101->SetLineWidth(2);
   Graph_Graph_Graph_Graph305830853101->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph305830853101->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph305830853101->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph305830853101->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph305830853101->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph305830853101->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph305830853101->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph305830853101->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph305830853101->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph305830853101->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph305830853101->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph305830853101->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph305830853101->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph305830853101->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph305830853101->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph305830853101->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph305830853101);
   
   grae->Draw("p1p");
   
   Double_t _fx3102[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3102[4] = {
   52.81753,
   39.16372,
   22.80511,
   9.659266};
   Double_t _felx3102[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3102[4] = {
   3.452812,
   2.405918,
   1.347227,
   0.5864553};
   Double_t _fehx3102[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3102[4] = {
   3.75058,
   2.558147,
   1.433882,
   0.6369553};
   grae = new TGraphAsymmErrors(4,_fx3102,_fy3102,_felx3102,_fehx3102,_fely3102,_fehy3102);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph306030863102 = new TH1F("Graph_Graph_Graph_Graph306030863102","",100,2.225,4.025);
   Graph_Graph_Graph_Graph306030863102->SetMinimum(0.001);
   Graph_Graph_Graph_Graph306030863102->SetMaximum(80);
   Graph_Graph_Graph_Graph306030863102->SetDirectory(0);
   Graph_Graph_Graph_Graph306030863102->SetStats(0);
   Graph_Graph_Graph_Graph306030863102->SetLineWidth(2);
   Graph_Graph_Graph_Graph306030863102->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph306030863102->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph306030863102->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306030863102->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph306030863102->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph306030863102->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306030863102->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306030863102->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph306030863102->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306030863102->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306030863102->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306030863102->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306030863102->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306030863102->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306030863102->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306030863102->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph306030863102);
   
   grae->Draw("p1p");
   
   Double_t _fx3103[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3103[4] = {
   33.75167,
   23.54495,
   13.13125,
   5.618726};
   Double_t _felx3103[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3103[4] = {
   1.953403,
   1.325998,
   0.668684,
   0.29035};
   Double_t _fehx3103[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3103[4] = {
   1.972477,
   1.306662,
   0.6129732,
   0.3088737};
   grae = new TGraphAsymmErrors(4,_fx3103,_fy3103,_felx3103,_fehx3103,_fely3103,_fehy3103);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph307030873103 = new TH1F("Graph_Graph_Graph_Graph307030873103","",100,2.375,4.175);
   Graph_Graph_Graph_Graph307030873103->SetMinimum(0.001);
   Graph_Graph_Graph_Graph307030873103->SetMaximum(80);
   Graph_Graph_Graph_Graph307030873103->SetDirectory(0);
   Graph_Graph_Graph_Graph307030873103->SetStats(0);
   Graph_Graph_Graph_Graph307030873103->SetLineWidth(2);
   Graph_Graph_Graph_Graph307030873103->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph307030873103->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph307030873103->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307030873103->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph307030873103->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph307030873103->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307030873103->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307030873103->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph307030873103->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307030873103->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307030873103->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307030873103->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307030873103->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307030873103->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307030873103->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307030873103->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph307030873103);
   
   grae->Draw("p1p");
   
   Double_t _fx3104[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3104[4] = {
   34.25415,
   23.32036,
   12.9946,
   5.344251};
   Double_t _felx3104[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3104[4] = {
   2.132698,
   1.400249,
   0.7785425,
   0.3408947};
   Double_t _fehx3104[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3104[4] = {
   2.256241,
   1.482401,
   0.844492,
   0.3783941};
   grae = new TGraphAsymmErrors(4,_fx3104,_fy3104,_felx3104,_fehx3104,_fely3104,_fehy3104);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph307230883104 = new TH1F("Graph_Graph_Graph_Graph307230883104","",100,2.225,4.025);
   Graph_Graph_Graph_Graph307230883104->SetMinimum(0.001);
   Graph_Graph_Graph_Graph307230883104->SetMaximum(80);
   Graph_Graph_Graph_Graph307230883104->SetDirectory(0);
   Graph_Graph_Graph_Graph307230883104->SetStats(0);
   Graph_Graph_Graph_Graph307230883104->SetLineWidth(2);
   Graph_Graph_Graph_Graph307230883104->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph307230883104->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph307230883104->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307230883104->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph307230883104->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph307230883104->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307230883104->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307230883104->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph307230883104->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307230883104->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307230883104->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307230883104->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307230883104->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307230883104->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307230883104->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307230883104->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph307230883104);
   
   grae->Draw("p1p");
   
   TPaveText *pt = new TPaveText(0.5,0.85,0.85,0.94,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(132);
   TText *AText = pt->AddText("LHCb, #sqrt{s} = 8 TeV");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.56,0.75,0.95,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(10);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("data_tot","  Data (#it{W^{#scale[1.2]{#plus}}j})","f");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("data2_tot","  Data (#it{W^{#scale[1.2]{#minus}}j})","f");

   ci = TColor::GetColor("#00ccff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   
   leg = new TLegend(0.56,0.63,0.95,0.75,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(10);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("powheg_temp","","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("powheg2_temp","  POWHEG","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("amcatnlo_temp","","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("amcatnlo2_temp","  aMC@NLO","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(26);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   TPave *pave = new TPave(0.57605,0.7745,0.64135,0.7855,0,"brNDC");

   ci = TColor::GetColor("#0000ff");
   pave->SetFillColor(ci);
   pave->SetLineWidth(2);
   pave->Draw();
   pave = new TPave(0.57605,0.8345,0.64135,0.8455,0,"brNDC");

   ci = TColor::GetColor("#ffcc00");
   pave->SetFillColor(ci);
   pave->SetLineWidth(2);
   pave->Draw();
   Double_t xAxis70[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_toterr_copy__86 = new TH1F("wp_etaj_toterr_copy__86","wp_etaj",4, xAxis70);
   wp_etaj_toterr_copy__86->SetBinContent(1,48.4905);
   wp_etaj_toterr_copy__86->SetBinContent(2,35.86988);
   wp_etaj_toterr_copy__86->SetBinContent(3,21.33691);
   wp_etaj_toterr_copy__86->SetBinContent(4,8.08127);
   wp_etaj_toterr_copy__86->SetBinContent(5,4.040633);
   wp_etaj_toterr_copy__86->SetBinError(1,4.411155);
   wp_etaj_toterr_copy__86->SetBinError(2,3.103339);
   wp_etaj_toterr_copy__86->SetBinError(3,1.964878);
   wp_etaj_toterr_copy__86->SetBinError(4,1.063724);
   wp_etaj_toterr_copy__86->SetBinError(5,0.5318616);
   wp_etaj_toterr_copy__86->SetMinimum(0.001);
   wp_etaj_toterr_copy__86->SetMaximum(80);
   wp_etaj_toterr_copy__86->SetEntries(10);
   wp_etaj_toterr_copy__86->SetDirectory(0);
   wp_etaj_toterr_copy__86->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__86->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__86->SetLineColor(ci);
   wp_etaj_toterr_copy__86->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__86->SetMarkerColor(ci);
   wp_etaj_toterr_copy__86->SetMarkerStyle(0);
   wp_etaj_toterr_copy__86->GetXaxis()->SetNdivisions(4);
   wp_etaj_toterr_copy__86->GetXaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__86->GetXaxis()->SetLabelOffset(999);
   wp_etaj_toterr_copy__86->GetXaxis()->SetLabelSize(0);
   wp_etaj_toterr_copy__86->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__86->GetXaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__86->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_toterr_copy__86->GetYaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__86->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__86->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__86->GetYaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__86->GetZaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__86->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__86->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__86->GetZaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__86->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.854321,-0.4062964,4.323457,6.852964);
   lowerPad->SetFillColor(0);
   lowerPad->SetFillStyle(4000);
   lowerPad->SetBorderMode(0);
   lowerPad->SetBorderSize(2);
   lowerPad->SetTickx(1);
   lowerPad->SetTicky(1);
   lowerPad->SetLeftMargin(0.14);
   lowerPad->SetRightMargin(0.05);
   lowerPad->SetTopMargin(0.725);
   lowerPad->SetBottomMargin(0.14);
   lowerPad->SetFrameLineWidth(2);
   lowerPad->SetFrameBorderMode(0);
   lowerPad->SetFrameLineWidth(2);
   lowerPad->SetFrameBorderMode(0);
   Double_t xAxis71[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_870_1001_2ratiocomp0__87 = new TH1F("wj_etaj_8TeV_log_870_1001_2ratiocomp0__87","wm_etaj",4, xAxis71);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinContent(1,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinContent(2,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinContent(3,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinContent(4,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinContent(5,1.965363);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinError(1,0.1029821);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinError(2,0.1071488);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinError(3,0.1195403);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinError(4,0.1681842);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetBinError(5,0.3305429);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetMinimum(0.61);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetMaximum(1.59);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetEntries(14);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetLineColor(ci);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetMarkerColor(ci);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->SetMarkerStyle(0);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0__87->Draw("e2");
   Double_t xAxis72[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_870_1001_2ratiocomp1__88 = new TH1F("wj_etaj_8TeV_log_870_1001_2ratiocomp1__88","wm_etaj",4, xAxis72);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinContent(1,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinContent(2,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinContent(3,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinContent(4,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinContent(5,1.965363);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinError(1,0.007590379);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinError(2,0.009631532);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinError(3,0.01301933);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinError(4,0.0205536);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetBinError(5,0.04039529);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetMinimum(0.61);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetMaximum(1.59);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetEntries(14);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetLineColor(ci);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetMarkerColor(ci);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->SetMarkerStyle(0);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp1__88->Draw("e2same");
   
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp2_fx3105[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp2_fy3105[4] = {
   1.106598,
   1.144544,
   1.172121,
   1.429436};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp2_felx3105[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp2_fely3105[4] = {
   0.1092377,
   0.101171,
   0.1310702,
   0.1515535};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp2_fehx3105[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp2_fehy3105[4] = {
   0.08707793,
   0.08849896,
   0.08752599,
   0.22226};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_870_1001_2ratiocomp2_fx3105,wj_etaj_8TeV_log_870_1001_2ratiocomp2_fy3105,wj_etaj_8TeV_log_870_1001_2ratiocomp2_felx3105,wj_etaj_8TeV_log_870_1001_2ratiocomp2_fehx3105,wj_etaj_8TeV_log_870_1001_2ratiocomp2_fely3105,wj_etaj_8TeV_log_870_1001_2ratiocomp2_fehy3105);
   grae->SetName("wj_etaj_8TeV_log_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105 = new TH1F("Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->SetStats(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp23105);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp3_fx3106[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp3_fy3106[4] = {
   1.123073,
   1.133627,
   1.159923,
   1.359608};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp3_felx3106[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp3_fely3106[4] = {
   0.09252438,
   0.09241037,
   0.1017721,
   0.139636};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp3_fehx3106[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp3_fehy3106[4] = {
   0.09608259,
   0.09761576,
   0.1059344,
   0.163819};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_870_1001_2ratiocomp3_fx3106,wj_etaj_8TeV_log_870_1001_2ratiocomp3_fy3106,wj_etaj_8TeV_log_870_1001_2ratiocomp3_felx3106,wj_etaj_8TeV_log_870_1001_2ratiocomp3_fehx3106,wj_etaj_8TeV_log_870_1001_2ratiocomp3_fely3106,wj_etaj_8TeV_log_870_1001_2ratiocomp3_fehy3106);
   grae->SetName("wj_etaj_8TeV_log_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106 = new TH1F("Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->SetStats(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp33106);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp4_fx3107[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp4_fy3107[4] = {
   1.106598,
   1.144544,
   1.172121,
   1.429436};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp4_felx3107[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp4_fely3107[4] = {
   0.0640452,
   0.06445814,
   0.05968803,
   0.07386671};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp4_fehx3107[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp4_fehy3107[4] = {
   0.06467055,
   0.06351816,
   0.05471517,
   0.07857924};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_870_1001_2ratiocomp4_fx3107,wj_etaj_8TeV_log_870_1001_2ratiocomp4_fy3107,wj_etaj_8TeV_log_870_1001_2ratiocomp4_felx3107,wj_etaj_8TeV_log_870_1001_2ratiocomp4_fehx3107,wj_etaj_8TeV_log_870_1001_2ratiocomp4_fely3107,wj_etaj_8TeV_log_870_1001_2ratiocomp4_fehy3107);
   grae->SetName("wj_etaj_8TeV_log_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107 = new TH1F("Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->SetStats(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp43107);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp5_fx3108[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp5_fy3108[4] = {
   1.123073,
   1.133627,
   1.159923,
   1.359608};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp5_felx3108[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp5_fely3108[4] = {
   0.06992364,
   0.06806756,
   0.06949421,
   0.08672558};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp5_fehx3108[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_870_1001_2ratiocomp5_fehy3108[4] = {
   0.07397417,
   0.07206103,
   0.07538099,
   0.09626566};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_870_1001_2ratiocomp5_fx3108,wj_etaj_8TeV_log_870_1001_2ratiocomp5_fy3108,wj_etaj_8TeV_log_870_1001_2ratiocomp5_felx3108,wj_etaj_8TeV_log_870_1001_2ratiocomp5_fehx3108,wj_etaj_8TeV_log_870_1001_2ratiocomp5_fely3108,wj_etaj_8TeV_log_870_1001_2ratiocomp5_fehy3108);
   grae->SetName("wj_etaj_8TeV_log_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108 = new TH1F("Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->SetStats(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_870_1001_2ratiocomp53108);
   
   grae->Draw("p1");
   Double_t xAxis73[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89 = new TH1F("wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89","wm_etaj",4, xAxis73);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinContent(1,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinContent(2,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinContent(3,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinContent(4,1);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinContent(5,1.965363);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinError(1,0.1029821);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinError(2,0.1071488);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinError(3,0.1195403);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinError(4,0.1681842);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetBinError(5,0.3305429);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetMinimum(0.61);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetMaximum(1.59);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetEntries(14);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetDirectory(0);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetLineColor(ci);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetMarkerColor(ci);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->SetMarkerStyle(0);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_870_1001_2ratiocomp0_copy__89->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: middlPad
   TPad *middlPad = new TPad("middlPad", "middlPad",0.005,0.05,0.995,0.995);
   middlPad->Draw();
   middlPad->cd();
   middlPad->Range(1.854321,-1.214827,4.323457,5.543792);
   middlPad->SetFillColor(0);
   middlPad->SetFillStyle(4000);
   middlPad->SetBorderMode(0);
   middlPad->SetBorderSize(2);
   middlPad->SetTickx(1);
   middlPad->SetTicky(1);
   middlPad->SetLeftMargin(0.14);
   middlPad->SetRightMargin(0.05);
   middlPad->SetTopMargin(0.585);
   middlPad->SetBottomMargin(0.27);
   middlPad->SetFrameLineWidth(2);
   middlPad->SetFrameBorderMode(0);
   middlPad->SetFrameLineWidth(2);
   middlPad->SetFrameBorderMode(0);
   Double_t xAxis74[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_400_1001_0ratiocomp0__90 = new TH1F("wj_etaj_8TeV_log_400_1001_0ratiocomp0__90","wp_etaj",4, xAxis74);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinContent(1,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinContent(2,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinContent(3,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinContent(4,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinContent(5,4.040633);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinError(1,0.09096947);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinError(2,0.08651658);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinError(3,0.09208823);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinError(4,0.1316283);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetBinError(5,0.5318616);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetMinimum(0.61);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetMaximum(1.59);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetEntries(14);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetLineColor(ci);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetMarkerColor(ci);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->SetMarkerStyle(0);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0__90->Draw("e2");
   Double_t xAxis75[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_400_1001_0ratiocomp1__91 = new TH1F("wj_etaj_8TeV_log_400_1001_0ratiocomp1__91","wp_etaj",4, xAxis75);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinContent(1,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinContent(2,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinContent(3,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinContent(4,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinContent(5,4.040633);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinError(1,0.006008522);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinError(2,0.007318117);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinError(3,0.009449783);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinError(4,0.014361);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetBinError(5,0.05802755);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetMinimum(0.61);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetMaximum(1.59);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetEntries(14);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetLineColor(ci);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetMarkerColor(ci);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->SetMarkerStyle(0);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp1__91->Draw("e2same");
   
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp2_fx3109[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp2_fy3109[4] = {
   1.057573,
   1.061747,
   1.056553,
   1.202921};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp2_felx3109[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp2_fely3109[4] = {
   0.0852868,
   0.07985034,
   0.08891828,
   0.1449872};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp2_fehx3109[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp2_fehy3109[4] = {
   0.0768471,
   0.07544389,
   0.07146708,
   0.1753128};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_400_1001_0ratiocomp2_fx3109,wj_etaj_8TeV_log_400_1001_0ratiocomp2_fy3109,wj_etaj_8TeV_log_400_1001_0ratiocomp2_felx3109,wj_etaj_8TeV_log_400_1001_0ratiocomp2_fehx3109,wj_etaj_8TeV_log_400_1001_0ratiocomp2_fely3109,wj_etaj_8TeV_log_400_1001_0ratiocomp2_fehy3109);
   grae->SetName("wj_etaj_8TeV_log_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109 = new TH1F("Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->SetStats(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp23109);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp3_fx3110[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp3_fy3110[4] = {
   1.089235,
   1.091828,
   1.06881,
   1.195266};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp3_felx3110[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp3_fely3110[4] = {
   0.08881276,
   0.08526295,
   0.0800585,
   0.09943128};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp3_fehx3110[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp3_fehy3110[4] = {
   0.09382539,
   0.08759198,
   0.08417318,
   0.1214588};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_400_1001_0ratiocomp3_fx3110,wj_etaj_8TeV_log_400_1001_0ratiocomp3_fy3110,wj_etaj_8TeV_log_400_1001_0ratiocomp3_felx3110,wj_etaj_8TeV_log_400_1001_0ratiocomp3_fehx3110,wj_etaj_8TeV_log_400_1001_0ratiocomp3_fely3110,wj_etaj_8TeV_log_400_1001_0ratiocomp3_fehy3110);
   grae->SetName("wj_etaj_8TeV_log_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110 = new TH1F("Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->SetStats(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp33110);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp4_fx3111[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp4_fy3111[4] = {
   1.057573,
   1.061747,
   1.056553,
   1.202921};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp4_felx3111[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp4_fely3111[4] = {
   0.06056661,
   0.05760808,
   0.05339437,
   0.06241278};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp4_fehx3111[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp4_fehy3111[4] = {
   0.0603745,
   0.05852863,
   0.04894748,
   0.06592288};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_400_1001_0ratiocomp4_fx3111,wj_etaj_8TeV_log_400_1001_0ratiocomp4_fy3111,wj_etaj_8TeV_log_400_1001_0ratiocomp4_felx3111,wj_etaj_8TeV_log_400_1001_0ratiocomp4_fehx3111,wj_etaj_8TeV_log_400_1001_0ratiocomp4_fely3111,wj_etaj_8TeV_log_400_1001_0ratiocomp4_fehy3111);
   grae->SetName("wj_etaj_8TeV_log_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111 = new TH1F("Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->SetStats(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp43111);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp5_fx3112[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp5_fy3112[4] = {
   1.089235,
   1.091828,
   1.06881,
   1.195266};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp5_felx3112[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp5_fely3112[4] = {
   0.07120596,
   0.0670735,
   0.06314069,
   0.0725697};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp5_fehx3112[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_400_1001_0ratiocomp5_fehy3112[4] = {
   0.0773467,
   0.07131743,
   0.06720195,
   0.07881871};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_400_1001_0ratiocomp5_fx3112,wj_etaj_8TeV_log_400_1001_0ratiocomp5_fy3112,wj_etaj_8TeV_log_400_1001_0ratiocomp5_felx3112,wj_etaj_8TeV_log_400_1001_0ratiocomp5_fehx3112,wj_etaj_8TeV_log_400_1001_0ratiocomp5_fely3112,wj_etaj_8TeV_log_400_1001_0ratiocomp5_fehy3112);
   grae->SetName("wj_etaj_8TeV_log_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112 = new TH1F("Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->SetStats(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_400_1001_0ratiocomp53112);
   
   grae->Draw("p1");
   Double_t xAxis76[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92 = new TH1F("wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92","wp_etaj",4, xAxis76);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinContent(1,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinContent(2,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinContent(3,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinContent(4,1);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinContent(5,4.040633);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinError(1,0.09096947);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinError(2,0.08651658);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinError(3,0.09208823);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinError(4,0.1316283);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetBinError(5,0.5318616);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetMinimum(0.61);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetMaximum(1.59);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetEntries(14);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetDirectory(0);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetLineColor(ci);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetMarkerColor(ci);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->SetMarkerStyle(0);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__92->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
