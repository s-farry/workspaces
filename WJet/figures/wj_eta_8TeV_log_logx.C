void wj_eta_8TeV_log_logx()
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
   bottomPad->Range(0,0,1,1);
   bottomPad->SetFillColor(0);
   bottomPad->SetFillStyle(4000);
   bottomPad->SetBorderMode(0);
   bottomPad->SetBorderSize(2);
   bottomPad->SetLogx();
   bottomPad->SetTickx(1);
   bottomPad->SetTicky(1);
   bottomPad->SetLeftMargin(0.14);
   bottomPad->SetRightMargin(0.05);
   bottomPad->SetTopMargin(0.585);
   bottomPad->SetBottomMargin(0.14);
   bottomPad->SetFrameLineWidth(2);
   bottomPad->SetFrameBorderMode(0);
   
   TH1F *__171 = new TH1F("__171","",1,0,1);
   __171->SetDirectory(0);
   __171->SetStats(0);
   __171->SetFillStyle(0);
   __171->SetLineWidth(2);
   __171->SetMarkerStyle(0);
   __171->GetXaxis()->SetNdivisions(4);
   __171->GetXaxis()->SetLabelFont(132);
   __171->GetXaxis()->SetLabelOffset(999);
   __171->GetXaxis()->SetLabelSize(0);
   __171->GetXaxis()->SetTitleSize(0.06);
   __171->GetXaxis()->SetTitleFont(132);
   __171->GetYaxis()->SetTitle("Ratio");
   __171->GetYaxis()->CenterTitle(true);
   __171->GetYaxis()->SetLabelFont(132);
   __171->GetYaxis()->SetLabelOffset(999);
   __171->GetYaxis()->SetLabelSize(0.05);
   __171->GetYaxis()->SetTitleSize(0.06);
   __171->GetYaxis()->SetTitleFont(132);
   __171->GetZaxis()->SetLabelFont(132);
   __171->GetZaxis()->SetLabelSize(0.05);
   __171->GetZaxis()->SetTitleSize(0.06);
   __171->GetZaxis()->SetTitleFont(132);
   __171->Draw("");
   
   TH1F *_copy__172 = new TH1F("_copy__172","",1,0,1);
   _copy__172->SetDirectory(0);
   _copy__172->SetStats(0);
   _copy__172->SetFillStyle(0);
   _copy__172->SetLineWidth(2);
   _copy__172->SetMarkerStyle(0);
   _copy__172->GetXaxis()->SetNdivisions(4);
   _copy__172->GetXaxis()->SetLabelFont(132);
   _copy__172->GetXaxis()->SetLabelOffset(999);
   _copy__172->GetXaxis()->SetLabelSize(0);
   _copy__172->GetXaxis()->SetTitleSize(0.06);
   _copy__172->GetXaxis()->SetTitleFont(132);
   _copy__172->GetYaxis()->SetTitle("Ratio");
   _copy__172->GetYaxis()->CenterTitle(true);
   _copy__172->GetYaxis()->SetLabelFont(132);
   _copy__172->GetYaxis()->SetLabelOffset(999);
   _copy__172->GetYaxis()->SetLabelSize(0.05);
   _copy__172->GetYaxis()->SetTitleSize(0.06);
   _copy__172->GetYaxis()->SetTitleFont(132);
   _copy__172->GetZaxis()->SetLabelFont(132);
   _copy__172->GetZaxis()->SetLabelSize(0.05);
   _copy__172->GetZaxis()->SetTitleSize(0.06);
   _copy__172->GetZaxis()->SetTitleFont(132);
   _copy__172->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(0.2401589,-6.627855,0.6749522,2.220573);
   upperPad->SetFillColor(0);
   upperPad->SetFillStyle(4000);
   upperPad->SetBorderMode(0);
   upperPad->SetBorderSize(2);
   upperPad->SetLogx();
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
   Double_t xAxis143[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_toterr__173 = new TH1F("wp_eta_toterr__173","wp_eta",4, xAxis143);
   wp_eta_toterr__173->SetBinContent(1,44.48695);
   wp_eta_toterr__173->SetBinContent(2,36.18721);
   wp_eta_toterr__173->SetBinContent(3,22.58616);
   wp_eta_toterr__173->SetBinContent(4,6.068387);
   wp_eta_toterr__173->SetBinContent(5,6.068387);
   wp_eta_toterr__173->SetBinError(1,4.178366);
   wp_eta_toterr__173->SetBinError(2,3.399085);
   wp_eta_toterr__173->SetBinError(3,1.937638);
   wp_eta_toterr__173->SetBinError(4,0.473664);
   wp_eta_toterr__173->SetBinError(5,0.473664);
   wp_eta_toterr__173->SetMinimum(0.001);
   wp_eta_toterr__173->SetMaximum(60);
   wp_eta_toterr__173->SetEntries(9);
   wp_eta_toterr__173->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__173->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__173->SetLineColor(ci);
   wp_eta_toterr__173->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__173->SetMarkerColor(ci);
   wp_eta_toterr__173->SetMarkerStyle(0);
   wp_eta_toterr__173->GetXaxis()->SetNdivisions(505);
   wp_eta_toterr__173->GetXaxis()->SetLabelFont(132);
   wp_eta_toterr__173->GetXaxis()->SetLabelOffset(999);
   wp_eta_toterr__173->GetXaxis()->SetLabelSize(0);
   wp_eta_toterr__173->GetXaxis()->SetTitleSize(0.06);
   wp_eta_toterr__173->GetXaxis()->SetTitleFont(132);
   wp_eta_toterr__173->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_toterr__173->GetYaxis()->SetLabelFont(132);
   wp_eta_toterr__173->GetYaxis()->SetLabelSize(0.05);
   wp_eta_toterr__173->GetYaxis()->SetTitleSize(0.06);
   wp_eta_toterr__173->GetYaxis()->SetTitleFont(132);
   wp_eta_toterr__173->GetZaxis()->SetLabelFont(132);
   wp_eta_toterr__173->GetZaxis()->SetLabelSize(0.05);
   wp_eta_toterr__173->GetZaxis()->SetTitleSize(0.06);
   wp_eta_toterr__173->GetZaxis()->SetTitleFont(132);
   wp_eta_toterr__173->Draw("e2");
   Double_t xAxis144[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_staterr__174 = new TH1F("wp_eta_staterr__174","wp_eta",4, xAxis144);
   wp_eta_staterr__174->SetBinContent(1,44.48695);
   wp_eta_staterr__174->SetBinContent(2,36.18721);
   wp_eta_staterr__174->SetBinContent(3,22.58616);
   wp_eta_staterr__174->SetBinContent(4,6.068387);
   wp_eta_staterr__174->SetBinContent(5,6.068387);
   wp_eta_staterr__174->SetBinError(1,0.305628);
   wp_eta_staterr__174->SetBinError(2,0.2473742);
   wp_eta_staterr__174->SetBinError(3,0.1921072);
   wp_eta_staterr__174->SetBinError(4,0.07689115);
   wp_eta_staterr__174->SetBinError(5,0.07689115);
   wp_eta_staterr__174->SetMinimum(0.001);
   wp_eta_staterr__174->SetMaximum(60);
   wp_eta_staterr__174->SetEntries(9);
   wp_eta_staterr__174->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__174->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__174->SetLineColor(ci);
   wp_eta_staterr__174->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__174->SetMarkerColor(ci);
   wp_eta_staterr__174->SetMarkerStyle(0);
   wp_eta_staterr__174->GetXaxis()->SetNdivisions(505);
   wp_eta_staterr__174->GetXaxis()->SetLabelFont(132);
   wp_eta_staterr__174->GetXaxis()->SetLabelOffset(999);
   wp_eta_staterr__174->GetXaxis()->SetLabelSize(0);
   wp_eta_staterr__174->GetXaxis()->SetTitleSize(0.06);
   wp_eta_staterr__174->GetXaxis()->SetTitleFont(132);
   wp_eta_staterr__174->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_staterr__174->GetYaxis()->SetLabelFont(132);
   wp_eta_staterr__174->GetYaxis()->SetLabelSize(0.05);
   wp_eta_staterr__174->GetYaxis()->SetTitleSize(0.06);
   wp_eta_staterr__174->GetYaxis()->SetTitleFont(132);
   wp_eta_staterr__174->GetZaxis()->SetLabelFont(132);
   wp_eta_staterr__174->GetZaxis()->SetLabelSize(0.05);
   wp_eta_staterr__174->GetZaxis()->SetTitleSize(0.06);
   wp_eta_staterr__174->GetZaxis()->SetTitleFont(132);
   wp_eta_staterr__174->Draw("e2same");
   Double_t xAxis145[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_toterr__175 = new TH1F("wm_eta_toterr__175","wm_eta",4, xAxis145);
   wm_eta_toterr__175->SetBinContent(1,20.31135);
   wm_eta_toterr__175->SetBinContent(2,19.05704);
   wm_eta_toterr__175->SetBinContent(3,14.77047);
   wm_eta_toterr__175->SetBinContent(4,6.28784);
   wm_eta_toterr__175->SetBinContent(5,6.28784);
   wm_eta_toterr__175->SetBinError(1,2.211244);
   wm_eta_toterr__175->SetBinError(2,2.174277);
   wm_eta_toterr__175->SetBinError(3,1.504852);
   wm_eta_toterr__175->SetBinError(4,0.7324271);
   wm_eta_toterr__175->SetBinError(5,0.7324271);
   wm_eta_toterr__175->SetMinimum(0.001);
   wm_eta_toterr__175->SetMaximum(60);
   wm_eta_toterr__175->SetEntries(9);
   wm_eta_toterr__175->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__175->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__175->SetLineColor(ci);
   wm_eta_toterr__175->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__175->SetMarkerColor(ci);
   wm_eta_toterr__175->SetMarkerStyle(0);
   wm_eta_toterr__175->GetXaxis()->SetNdivisions(505);
   wm_eta_toterr__175->GetXaxis()->SetLabelFont(132);
   wm_eta_toterr__175->GetXaxis()->SetLabelOffset(999);
   wm_eta_toterr__175->GetXaxis()->SetLabelSize(0);
   wm_eta_toterr__175->GetXaxis()->SetTitleSize(0.06);
   wm_eta_toterr__175->GetXaxis()->SetTitleFont(132);
   wm_eta_toterr__175->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_toterr__175->GetYaxis()->SetLabelFont(132);
   wm_eta_toterr__175->GetYaxis()->SetLabelSize(0.05);
   wm_eta_toterr__175->GetYaxis()->SetTitleSize(0.06);
   wm_eta_toterr__175->GetYaxis()->SetTitleFont(132);
   wm_eta_toterr__175->GetZaxis()->SetLabelFont(132);
   wm_eta_toterr__175->GetZaxis()->SetLabelSize(0.05);
   wm_eta_toterr__175->GetZaxis()->SetTitleSize(0.06);
   wm_eta_toterr__175->GetZaxis()->SetTitleFont(132);
   wm_eta_toterr__175->Draw("e2same");
   Double_t xAxis146[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_staterr__176 = new TH1F("wm_eta_staterr__176","wm_eta",4, xAxis146);
   wm_eta_staterr__176->SetBinContent(1,20.31135);
   wm_eta_staterr__176->SetBinContent(2,19.05704);
   wm_eta_staterr__176->SetBinContent(3,14.77047);
   wm_eta_staterr__176->SetBinContent(4,6.28784);
   wm_eta_staterr__176->SetBinContent(5,6.28784);
   wm_eta_staterr__176->SetBinError(1,0.2067664);
   wm_eta_staterr__176->SetBinError(2,0.1786075);
   wm_eta_staterr__176->SetBinError(3,0.1537429);
   wm_eta_staterr__176->SetBinError(4,0.0794311);
   wm_eta_staterr__176->SetBinError(5,0.0794311);
   wm_eta_staterr__176->SetMinimum(0.001);
   wm_eta_staterr__176->SetMaximum(60);
   wm_eta_staterr__176->SetEntries(9);
   wm_eta_staterr__176->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__176->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__176->SetLineColor(ci);
   wm_eta_staterr__176->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__176->SetMarkerColor(ci);
   wm_eta_staterr__176->SetMarkerStyle(0);
   wm_eta_staterr__176->GetXaxis()->SetNdivisions(505);
   wm_eta_staterr__176->GetXaxis()->SetLabelFont(132);
   wm_eta_staterr__176->GetXaxis()->SetLabelOffset(999);
   wm_eta_staterr__176->GetXaxis()->SetLabelSize(0);
   wm_eta_staterr__176->GetXaxis()->SetTitleSize(0.06);
   wm_eta_staterr__176->GetXaxis()->SetTitleFont(132);
   wm_eta_staterr__176->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_staterr__176->GetYaxis()->SetLabelFont(132);
   wm_eta_staterr__176->GetYaxis()->SetLabelSize(0.05);
   wm_eta_staterr__176->GetYaxis()->SetTitleSize(0.06);
   wm_eta_staterr__176->GetYaxis()->SetTitleFont(132);
   wm_eta_staterr__176->GetZaxis()->SetLabelFont(132);
   wm_eta_staterr__176->GetZaxis()->SetLabelSize(0.05);
   wm_eta_staterr__176->GetZaxis()->SetTitleSize(0.06);
   wm_eta_staterr__176->GetZaxis()->SetTitleFont(132);
   wm_eta_staterr__176->Draw("e2same");
   TBox *box = new TBox(3.5,5.555413,4.5,7.020267);
   box->SetFillColor(19);
   box->SetFillStyle(0);

   ci = TColor::GetColor("#ffff00");
   box->SetLineColor(ci);
   box->SetLineWidth(2);
   box->Draw();
   
   Double_t eta_plus_toterrs_fx3209[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t eta_plus_toterrs_fy3209[4] = {
   47.32533,
   38.9919,
   23.46391,
   5.924761};
   Double_t eta_plus_toterrs_felx3209[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fely3209[4] = {
   3.540604,
   2.964117,
   2.407115,
   0.58535};
   Double_t eta_plus_toterrs_fehx3209[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fehy3209[4] = {
   3.05974,
   3.019728,
   1.770769,
   0.6694141};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,eta_plus_toterrs_fx3209,eta_plus_toterrs_fy3209,eta_plus_toterrs_felx3209,eta_plus_toterrs_fehx3209,eta_plus_toterrs_fely3209,eta_plus_toterrs_fehy3209);
   grae->SetName("eta_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209 = new TH1F("Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209","",100,2.17,4.03);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->SetMaximum(60);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->SetDirectory(0);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->SetStats(0);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->SetLineWidth(2);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_eta_plus_toterrs3065317731933209);
   
   grae->Draw("p1p");
   
   Double_t eta_plus_toterrs_fx3210[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t eta_plus_toterrs_fy3210[4] = {
   47.79052,
   39.73359,
   24.34292,
   6.287156};
   Double_t eta_plus_toterrs_felx3210[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fely3210[4] = {
   3.555086,
   3.167225,
   2.012039,
   0.5928745};
   Double_t eta_plus_toterrs_fehx3210[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fehy3210[4] = {
   3.712474,
   3.28169,
   2.136315,
   0.6808392};
   grae = new TGraphAsymmErrors(4,eta_plus_toterrs_fx3210,eta_plus_toterrs_fy3210,eta_plus_toterrs_felx3210,eta_plus_toterrs_fehx3210,eta_plus_toterrs_fely3210,eta_plus_toterrs_fehy3210);
   grae->SetName("eta_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210 = new TH1F("Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210","",100,2.0175,3.9075);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->SetMaximum(60);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->SetDirectory(0);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->SetStats(0);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->SetLineWidth(2);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_eta_plus_toterrs3067317831943210);
   
   grae->Draw("p1p");
   
   Double_t eta_minus_toterrs_fx3211[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t eta_minus_toterrs_fy3211[4] = {
   24.69105,
   21.53431,
   16.77246,
   6.521709};
   Double_t eta_minus_toterrs_felx3211[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fely3211[4] = {
   2.650178,
   1.505858,
   2.136883,
   0.7587894};
   Double_t eta_minus_toterrs_fehx3211[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fehy3211[4] = {
   1.770777,
   1.514672,
   1.574916,
   0.7803406};
   grae = new TGraphAsymmErrors(4,eta_minus_toterrs_fx3211,eta_minus_toterrs_fy3211,eta_minus_toterrs_felx3211,eta_minus_toterrs_fehx3211,eta_minus_toterrs_fely3211,eta_minus_toterrs_fehy3211);
   grae->SetName("eta_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211 = new TH1F("Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211","",100,2.1325,4.4425);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->SetMaximum(60);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->SetDirectory(0);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->SetStats(0);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->SetLineWidth(2);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_eta_minus_toterrs3077317931953211);
   
   grae->Draw("p1p");
   
   Double_t eta_minus_toterrs_fx3212[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t eta_minus_toterrs_fy3212[4] = {
   24.34978,
   21.59002,
   16.53536,
   6.707781};
   Double_t eta_minus_toterrs_felx3212[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fely3212[4] = {
   1.887475,
   1.685778,
   1.408083,
   0.7344018};
   Double_t eta_minus_toterrs_fehx3212[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fehy3212[4] = {
   1.946961,
   1.776958,
   1.529902,
   0.7848048};
   grae = new TGraphAsymmErrors(4,eta_minus_toterrs_fx3212,eta_minus_toterrs_fy3212,eta_minus_toterrs_felx3212,eta_minus_toterrs_fehx3212,eta_minus_toterrs_fely3212,eta_minus_toterrs_fehy3212);
   grae->SetName("eta_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212 = new TH1F("Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212","",100,1.98,4.32);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->SetMaximum(60);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->SetDirectory(0);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->SetStats(0);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->SetLineWidth(2);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_eta_minus_toterrs3079318031963212);
   
   grae->Draw("p1p");
   
   Double_t _fx3213[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t _fy3213[4] = {
   47.32533,
   38.9919,
   23.46391,
   5.924761};
   Double_t _felx3213[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3213[4] = {
   2.535717,
   2.140228,
   1.269583,
   0.3501558};
   Double_t _fehx3213[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3213[4] = {
   2.417316,
   2.077194,
   1.218067,
   0.4287262};
   grae = new TGraphAsymmErrors(4,_fx3213,_fy3213,_felx3213,_fehx3213,_fely3213,_fehy3213);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3066318131973213 = new TH1F("Graph_Graph_Graph_Graph_Graph3066318131973213","",100,2.17,4.03);
   Graph_Graph_Graph_Graph_Graph3066318131973213->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_Graph3066318131973213->SetMaximum(60);
   Graph_Graph_Graph_Graph_Graph3066318131973213->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3066318131973213->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3066318131973213->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3066318131973213->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3066318131973213->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3066318131973213);
   
   grae->Draw("p1p");
   
   Double_t _fx3214[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t _fy3214[4] = {
   47.79052,
   39.73359,
   24.34292,
   6.287156};
   Double_t _felx3214[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3214[4] = {
   2.911022,
   2.491634,
   1.555553,
   0.4153972};
   Double_t _fehx3214[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3214[4] = {
   3.070263,
   2.672722,
   1.706875,
   0.4669943};
   grae = new TGraphAsymmErrors(4,_fx3214,_fy3214,_felx3214,_fehx3214,_fely3214,_fehy3214);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3068318231983214 = new TH1F("Graph_Graph_Graph_Graph_Graph3068318231983214","",100,2.0175,3.9075);
   Graph_Graph_Graph_Graph_Graph3068318231983214->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_Graph3068318231983214->SetMaximum(60);
   Graph_Graph_Graph_Graph_Graph3068318231983214->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3068318231983214->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3068318231983214->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3068318231983214->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3068318231983214->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3068318231983214);
   
   grae->Draw("p1p");
   
   Double_t _fx3215[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t _fy3215[4] = {
   24.69105,
   21.53431,
   16.77246,
   6.521709};
   Double_t _felx3215[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3215[4] = {
   1.403467,
   1.102299,
   0.935895,
   0.3957744};
   Double_t _fehx3215[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3215[4] = {
   1.399612,
   1.006586,
   1.048164,
   0.4442883};
   grae = new TGraphAsymmErrors(4,_fx3215,_fy3215,_felx3215,_fehx3215,_fely3215,_fehy3215);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3078318331993215 = new TH1F("Graph_Graph_Graph_Graph_Graph3078318331993215","",100,2.1325,4.4425);
   Graph_Graph_Graph_Graph_Graph3078318331993215->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_Graph3078318331993215->SetMaximum(60);
   Graph_Graph_Graph_Graph_Graph3078318331993215->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3078318331993215->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3078318331993215->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3078318331993215->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3078318331993215->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3078318331993215);
   
   grae->Draw("p1p");
   
   Double_t _fx3216[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t _fy3216[4] = {
   24.34978,
   21.59002,
   16.53536,
   6.707781};
   Double_t _felx3216[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3216[4] = {
   1.482811,
   1.286926,
   0.9989262,
   0.430294};
   Double_t _fehx3216[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3216[4] = {
   1.576153,
   1.363707,
   1.084366,
   0.4796934};
   grae = new TGraphAsymmErrors(4,_fx3216,_fy3216,_felx3216,_fehx3216,_fely3216,_fehy3216);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3080318432003216 = new TH1F("Graph_Graph_Graph_Graph_Graph3080318432003216","",100,1.98,4.32);
   Graph_Graph_Graph_Graph_Graph3080318432003216->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_Graph3080318432003216->SetMaximum(60);
   Graph_Graph_Graph_Graph_Graph3080318432003216->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3080318432003216->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3080318432003216->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3080318432003216->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3080318432003216->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3080318432003216);
   
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
   Double_t xAxis147[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_toterr_copy__177 = new TH1F("wp_eta_toterr_copy__177","wp_eta",4, xAxis147);
   wp_eta_toterr_copy__177->SetBinContent(1,44.48695);
   wp_eta_toterr_copy__177->SetBinContent(2,36.18721);
   wp_eta_toterr_copy__177->SetBinContent(3,22.58616);
   wp_eta_toterr_copy__177->SetBinContent(4,6.068387);
   wp_eta_toterr_copy__177->SetBinContent(5,6.068387);
   wp_eta_toterr_copy__177->SetBinError(1,4.178366);
   wp_eta_toterr_copy__177->SetBinError(2,3.399085);
   wp_eta_toterr_copy__177->SetBinError(3,1.937638);
   wp_eta_toterr_copy__177->SetBinError(4,0.473664);
   wp_eta_toterr_copy__177->SetBinError(5,0.473664);
   wp_eta_toterr_copy__177->SetMinimum(0.001);
   wp_eta_toterr_copy__177->SetMaximum(60);
   wp_eta_toterr_copy__177->SetEntries(9);
   wp_eta_toterr_copy__177->SetDirectory(0);
   wp_eta_toterr_copy__177->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__177->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__177->SetLineColor(ci);
   wp_eta_toterr_copy__177->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__177->SetMarkerColor(ci);
   wp_eta_toterr_copy__177->SetMarkerStyle(0);
   wp_eta_toterr_copy__177->GetXaxis()->SetNdivisions(505);
   wp_eta_toterr_copy__177->GetXaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__177->GetXaxis()->SetLabelOffset(999);
   wp_eta_toterr_copy__177->GetXaxis()->SetLabelSize(0);
   wp_eta_toterr_copy__177->GetXaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__177->GetXaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__177->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_toterr_copy__177->GetYaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__177->GetYaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__177->GetYaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__177->GetYaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__177->GetZaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__177->GetZaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__177->GetZaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__177->GetZaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__177->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(0.2401589,0.1085185,0.6749522,4.404815);
   lowerPad->SetFillColor(0);
   lowerPad->SetFillStyle(4000);
   lowerPad->SetBorderMode(0);
   lowerPad->SetBorderSize(2);
   lowerPad->SetLogx();
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
   Double_t xAxis148[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178 = new TH1F("wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178","wm_eta",4, xAxis148);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinContent(1,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinContent(2,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinContent(3,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinContent(4,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinContent(5,6.28784);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinError(1,0.1088674);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinError(2,0.1140931);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinError(3,0.1018825);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinError(4,0.1164831);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetBinError(5,0.7324271);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetMinimum(0.71);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetMaximum(1.29);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetEntries(13);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetLineColor(ci);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetMarkerColor(ci);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->SetMarkerStyle(0);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0__178->Draw("e2");
   Double_t xAxis149[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179 = new TH1F("wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179","wm_eta",4, xAxis149);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinContent(1,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinContent(2,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinContent(3,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinContent(4,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinContent(5,6.28784);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinError(1,0.01017984);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinError(2,0.009372258);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinError(3,0.0104088);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinError(4,0.01263249);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetBinError(5,0.0794311);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetMinimum(0.71);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetMaximum(1.29);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetEntries(13);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetLineColor(ci);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetMarkerColor(ci);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->SetMarkerStyle(0);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp1__179->Draw("e2same");
   
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fx3217[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fy3217[4] = {
   1.215628,
   1.129992,
   1.13554,
   1.037194};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_felx3217[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fely3217[4] = {
   0.1304777,
   0.07901847,
   0.1446727,
   0.1206757};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fehx3217[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fehy3217[4] = {
   0.08718166,
   0.07948094,
   0.106626,
   0.1241031};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fx3217,wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fy3217,wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_felx3217,wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fehx3217,wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fely3217,wj_eta_8TeV_log_logx_870_1001_2ratiocomp2_fehy3217);
   grae->SetName("wj_eta_8TeV_log_logx_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217 = new TH1F("Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217","",100,2.1325,4.4425);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->SetDirectory(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->SetStats(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp23217);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fx3218[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fy3218[4] = {
   1.198826,
   1.132916,
   1.119488,
   1.066786};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_felx3218[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fely3218[4] = {
   0.09292708,
   0.08845959,
   0.09533098,
   0.1167971};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fehx3218[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fehy3218[4] = {
   0.09585579,
   0.09324414,
   0.1035784,
   0.1248131};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fx3218,wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fy3218,wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_felx3218,wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fehx3218,wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fely3218,wj_eta_8TeV_log_logx_870_1001_2ratiocomp3_fehy3218);
   grae->SetName("wj_eta_8TeV_log_logx_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218 = new TH1F("Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218","",100,1.98,4.32);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->SetDirectory(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->SetStats(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp33218);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fx3219[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fy3219[4] = {
   1.215628,
   1.129992,
   1.13554,
   1.037194};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_felx3219[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fely3219[4] = {
   0.06909767,
   0.05784207,
   0.06336258,
   0.06294281};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fehx3219[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fehy3219[4] = {
   0.06890789,
   0.05281964,
   0.07096352,
   0.07065832};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fx3219,wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fy3219,wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_felx3219,wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fehx3219,wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fely3219,wj_eta_8TeV_log_logx_870_1001_2ratiocomp4_fehy3219);
   grae->SetName("wj_eta_8TeV_log_logx_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219 = new TH1F("Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219","",100,2.1325,4.4425);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->SetDirectory(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->SetStats(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp43219);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fx3220[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fy3220[4] = {
   1.198826,
   1.132916,
   1.119488,
   1.066786};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_felx3220[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fely3220[4] = {
   0.07300405,
   0.06753022,
   0.06762996,
   0.06843272};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fehx3220[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fehy3220[4] = {
   0.0775996,
   0.07155919,
   0.07341446,
   0.07628906};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fx3220,wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fy3220,wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_felx3220,wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fehx3220,wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fely3220,wj_eta_8TeV_log_logx_870_1001_2ratiocomp5_fehy3220);
   grae->SetName("wj_eta_8TeV_log_logx_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220 = new TH1F("Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220","",100,1.98,4.32);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->SetDirectory(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->SetStats(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_logx_870_1001_2ratiocomp53220);
   
   grae->Draw("p1");
   Double_t xAxis150[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180 = new TH1F("wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180","wm_eta",4, xAxis150);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinContent(1,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinContent(2,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinContent(3,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinContent(4,1);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinContent(5,6.28784);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinError(1,0.1088674);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinError(2,0.1140931);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinError(3,0.1018825);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinError(4,0.1164831);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetBinError(5,0.7324271);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetMinimum(0.71);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetMaximum(1.29);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetEntries(13);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetDirectory(0);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetLineColor(ci);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetMarkerColor(ci);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->SetMarkerStyle(0);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_870_1001_2ratiocomp0_copy__180->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: middlPad
   TPad *middlPad = new TPad("middlPad", "middlPad",0.005,0.05,0.995,0.995);
   middlPad->Draw();
   middlPad->cd();
   middlPad->Range(0.2401589,-0.3699997,0.6749522,3.629999);
   middlPad->SetFillColor(0);
   middlPad->SetFillStyle(4000);
   middlPad->SetBorderMode(0);
   middlPad->SetBorderSize(2);
   middlPad->SetLogx();
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
   Double_t xAxis151[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181 = new TH1F("wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181","wp_eta",4, xAxis151);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinContent(1,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinContent(2,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinContent(3,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinContent(4,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinContent(5,6.068387);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinError(1,0.09392341);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinError(2,0.09393057);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinError(3,0.08578873);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinError(4,0.07805435);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetBinError(5,0.473664);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetMinimum(0.71);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetMaximum(1.29);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetEntries(13);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetLineColor(ci);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetMarkerColor(ci);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->SetMarkerStyle(0);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0__181->Draw("e2");
   Double_t xAxis152[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182 = new TH1F("wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182","wp_eta",4, xAxis152);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinContent(1,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinContent(2,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinContent(3,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinContent(4,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinContent(5,6.068387);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinError(1,0.00687006);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinError(2,0.006835955);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinError(3,0.008505529);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinError(4,0.01267077);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetBinError(5,0.07689115);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetMinimum(0.71);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetMaximum(1.29);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetEntries(13);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetLineColor(ci);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetMarkerColor(ci);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->SetMarkerStyle(0);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp1__182->Draw("e2same");
   
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fx3221[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fy3221[4] = {
   1.063803,
   1.077505,
   1.038863,
   0.9763321};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_felx3221[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fely3221[4] = {
   0.07958749,
   0.08191061,
   0.1065748,
   0.09645891};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fehx3221[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fehy3221[4] = {
   0.06877838,
   0.08344737,
   0.07840062,
   0.1103117};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fx3221,wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fy3221,wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_felx3221,wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fehx3221,wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fely3221,wj_eta_8TeV_log_logx_400_1001_0ratiocomp2_fehy3221);
   grae->SetName("wj_eta_8TeV_log_logx_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221 = new TH1F("Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221","",100,2.17,4.03);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->SetDirectory(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->SetStats(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp23221);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fx3222[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fy3222[4] = {
   1.074259,
   1.098001,
   1.077781,
   1.036051};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_felx3222[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fely3222[4] = {
   0.07991302,
   0.08752332,
   0.08908284,
   0.09769886};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fehx3222[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fehy3222[4] = {
   0.08345087,
   0.09068646,
   0.09458514,
   0.1121944};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fx3222,wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fy3222,wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_felx3222,wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fehx3222,wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fely3222,wj_eta_8TeV_log_logx_400_1001_0ratiocomp3_fehy3222);
   grae->SetName("wj_eta_8TeV_log_logx_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222 = new TH1F("Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222","",100,2.0175,3.9075);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->SetDirectory(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->SetStats(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp33222);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fx3223[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fy3223[4] = {
   1.063803,
   1.077505,
   1.038863,
   0.9763321};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_felx3223[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fely3223[4] = {
   0.05699913,
   0.05914322,
   0.05621066,
   0.05770163};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fehx3223[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fehy3223[4] = {
   0.05433766,
   0.05740133,
   0.05392981,
   0.07064912};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fx3223,wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fy3223,wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_felx3223,wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fehx3223,wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fely3223,wj_eta_8TeV_log_logx_400_1001_0ratiocomp4_fehy3223);
   grae->SetName("wj_eta_8TeV_log_logx_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223 = new TH1F("Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223","",100,2.17,4.03);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->SetDirectory(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->SetStats(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp43223);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fx3224[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fy3224[4] = {
   1.074259,
   1.098001,
   1.077781,
   1.036051};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_felx3224[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fely3224[4] = {
   0.06543542,
   0.068854,
   0.06887198,
   0.06845265};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fehx3224[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fehy3224[4] = {
   0.06901492,
   0.07385818,
   0.07557173,
   0.07695526};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fx3224,wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fy3224,wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_felx3224,wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fehx3224,wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fely3224,wj_eta_8TeV_log_logx_400_1001_0ratiocomp5_fehy3224);
   grae->SetName("wj_eta_8TeV_log_logx_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224 = new TH1F("Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224","",100,2.0175,3.9075);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->SetDirectory(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->SetStats(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_logx_400_1001_0ratiocomp53224);
   
   grae->Draw("p1");
   Double_t xAxis153[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183 = new TH1F("wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183","wp_eta",4, xAxis153);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinContent(1,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinContent(2,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinContent(3,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinContent(4,1);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinContent(5,6.068387);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinError(1,0.09392341);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinError(2,0.09393057);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinError(3,0.08578873);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinError(4,0.07805435);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetBinError(5,0.473664);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetMinimum(0.71);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetMaximum(1.29);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetEntries(13);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetDirectory(0);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetLineColor(ci);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetMarkerColor(ci);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->SetMarkerStyle(0);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_logx_400_1001_0ratiocomp0_copy__183->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
