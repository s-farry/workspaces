void wj_ratio_eta_fewz_8TeV()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Thu Apr 28 10:19:36 2016) by ROOT version6.04/10
   TCanvas *default_Canvas = new TCanvas("default_Canvas", "defaultCanvas",0,0,800,800);
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
   bottomPad->SetTickx(1);
   bottomPad->SetTicky(1);
   bottomPad->SetLeftMargin(0.14);
   bottomPad->SetRightMargin(0.05);
   bottomPad->SetTopMargin(0.05);
   bottomPad->SetBottomMargin(0.16);
   bottomPad->SetFrameLineWidth(2);
   bottomPad->SetFrameBorderMode(0);
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(1.567901,-1.847581,4.654321,3.781452);
   upperPad->SetFillColor(0);
   upperPad->SetFillStyle(4000);
   upperPad->SetBorderMode(0);
   upperPad->SetBorderSize(2);
   upperPad->SetTickx(1);
   upperPad->SetTicky(1);
   upperPad->SetLeftMargin(0.14);
   upperPad->SetRightMargin(0.05);
   upperPad->SetTopMargin(0.05);
   upperPad->SetBottomMargin(0.33);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   Double_t xAxis172[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_r_eta_toterr__202 = new TH1F("w_r_eta_toterr__202","w_eta",4, xAxis172);
   w_r_eta_toterr__202->SetBinContent(1,2.19025);
   w_r_eta_toterr__202->SetBinContent(2,1.898889);
   w_r_eta_toterr__202->SetBinContent(3,1.529143);
   w_r_eta_toterr__202->SetBinContent(4,0.9650988);
   w_r_eta_toterr__202->SetBinContent(5,0.9650988);
   w_r_eta_toterr__202->SetBinError(1,0.07464207);
   w_r_eta_toterr__202->SetBinError(2,0.0660939);
   w_r_eta_toterr__202->SetBinError(3,0.06010184);
   w_r_eta_toterr__202->SetBinError(4,0.06616402);
   w_r_eta_toterr__202->SetBinError(5,0.06616402);
   w_r_eta_toterr__202->SetMinimum(0.01);
   w_r_eta_toterr__202->SetMaximum(3.5);
   w_r_eta_toterr__202->SetEntries(6);
   w_r_eta_toterr__202->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr__202->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr__202->SetLineColor(ci);
   w_r_eta_toterr__202->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr__202->SetMarkerColor(ci);
   w_r_eta_toterr__202->SetMarkerStyle(0);
   w_r_eta_toterr__202->GetXaxis()->SetRange(1,4);
   w_r_eta_toterr__202->GetXaxis()->SetNdivisions(4);
   w_r_eta_toterr__202->GetXaxis()->SetLabelFont(132);
   w_r_eta_toterr__202->GetXaxis()->SetLabelOffset(999);
   w_r_eta_toterr__202->GetXaxis()->SetLabelSize(0);
   w_r_eta_toterr__202->GetXaxis()->SetTitleSize(0.06);
   w_r_eta_toterr__202->GetXaxis()->SetTitleFont(132);
   w_r_eta_toterr__202->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_eta_toterr__202->GetYaxis()->SetLabelFont(132);
   w_r_eta_toterr__202->GetYaxis()->SetLabelSize(0.05);
   w_r_eta_toterr__202->GetYaxis()->SetTitleSize(0.06);
   w_r_eta_toterr__202->GetYaxis()->SetTitleFont(132);
   w_r_eta_toterr__202->GetZaxis()->SetLabelFont(132);
   w_r_eta_toterr__202->GetZaxis()->SetLabelSize(0.05);
   w_r_eta_toterr__202->GetZaxis()->SetTitleSize(0.06);
   w_r_eta_toterr__202->GetZaxis()->SetTitleFont(132);
   w_r_eta_toterr__202->Draw("e2");
   Double_t xAxis173[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_r_eta_staterr__203 = new TH1F("w_r_eta_staterr__203","w_eta",4, xAxis173);
   w_r_eta_staterr__203->SetBinContent(1,2.19025);
   w_r_eta_staterr__203->SetBinContent(2,1.898889);
   w_r_eta_staterr__203->SetBinContent(3,1.529143);
   w_r_eta_staterr__203->SetBinContent(4,0.9650988);
   w_r_eta_staterr__203->SetBinContent(5,0.9650988);
   w_r_eta_staterr__203->SetBinError(1,0.02689882);
   w_r_eta_staterr__203->SetBinError(2,0.02202789);
   w_r_eta_staterr__203->SetBinError(3,0.02055473);
   w_r_eta_staterr__203->SetBinError(4,0.01726767);
   w_r_eta_staterr__203->SetBinError(5,0.01726767);
   w_r_eta_staterr__203->SetMinimum(0.01);
   w_r_eta_staterr__203->SetMaximum(3.5);
   w_r_eta_staterr__203->SetEntries(6);
   w_r_eta_staterr__203->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   w_r_eta_staterr__203->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   w_r_eta_staterr__203->SetLineColor(ci);
   w_r_eta_staterr__203->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   w_r_eta_staterr__203->SetMarkerColor(ci);
   w_r_eta_staterr__203->SetMarkerStyle(0);
   w_r_eta_staterr__203->GetXaxis()->SetRange(1,4);
   w_r_eta_staterr__203->GetXaxis()->SetNdivisions(4);
   w_r_eta_staterr__203->GetXaxis()->SetLabelFont(132);
   w_r_eta_staterr__203->GetXaxis()->SetLabelOffset(999);
   w_r_eta_staterr__203->GetXaxis()->SetLabelSize(0);
   w_r_eta_staterr__203->GetXaxis()->SetTitleSize(0.06);
   w_r_eta_staterr__203->GetXaxis()->SetTitleFont(132);
   w_r_eta_staterr__203->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_eta_staterr__203->GetYaxis()->SetLabelFont(132);
   w_r_eta_staterr__203->GetYaxis()->SetLabelSize(0.05);
   w_r_eta_staterr__203->GetYaxis()->SetTitleSize(0.06);
   w_r_eta_staterr__203->GetYaxis()->SetTitleFont(132);
   w_r_eta_staterr__203->GetZaxis()->SetLabelFont(132);
   w_r_eta_staterr__203->GetZaxis()->SetLabelSize(0.05);
   w_r_eta_staterr__203->GetZaxis()->SetTitleSize(0.06);
   w_r_eta_staterr__203->GetZaxis()->SetTitleFont(132);
   w_r_eta_staterr__203->Draw("e2same");
   
   Double_t Graph0_fx3251[4] = {
   2.15,
   2.65,
   3.15,
   3.8};
   Double_t Graph0_fy3251[4] = {
   2.04965,
   1.91604,
   1.54792,
   1.06955};
   Double_t Graph0_felx3251[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph0_fely3251[4] = {
   0.0149,
   0.0084,
   0.0082,
   0.0107};
   Double_t Graph0_fehx3251[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph0_fehy3251[4] = {
   0.0149,
   0.0084,
   0.0082,
   0.0107};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,Graph0_fx3251,Graph0_fy3251,Graph0_felx3251,Graph0_fehx3251,Graph0_fely3251,Graph0_fehy3251);
   grae->SetName("Graph0");
   grae->SetTitle("CT14 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3251 = new TH1F("Graph_Graph3251","CT14 Ratio",100,1.985,3.965);
   Graph_Graph3251->SetMinimum(0.01);
   Graph_Graph3251->SetMaximum(3.5);
   Graph_Graph3251->SetDirectory(0);
   Graph_Graph3251->SetStats(0);
   Graph_Graph3251->SetLineWidth(2);
   Graph_Graph3251->SetMarkerStyle(0);
   Graph_Graph3251->GetXaxis()->SetRange(1,101);
   Graph_Graph3251->GetXaxis()->SetNdivisions(4);
   Graph_Graph3251->GetXaxis()->SetLabelFont(132);
   Graph_Graph3251->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3251->GetXaxis()->SetLabelSize(0);
   Graph_Graph3251->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3251->GetXaxis()->SetTitleFont(132);
   Graph_Graph3251->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3251->GetYaxis()->SetLabelFont(132);
   Graph_Graph3251->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3251->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3251->GetYaxis()->SetTitleFont(132);
   Graph_Graph3251->GetZaxis()->SetLabelFont(132);
   Graph_Graph3251->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3251->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3251->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3251);
   
   grae->Draw("p1p");
   
   Double_t Graph1_fx3252[4] = {
   2.15,
   2.65,
   3.15,
   3.8};
   Double_t Graph1_fy3252[4] = {
   2.04965,
   1.91604,
   1.54792,
   1.06955};
   Double_t Graph1_felx3252[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph1_fely3252[4] = {
   0.0453817,
   0.05013483,
   0.05973052,
   0.07642827};
   Double_t Graph1_fehx3252[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph1_fehy3252[4] = {
   0.04986359,
   0.05132815,
   0.05619836,
   0.06324486};
   grae = new TGraphAsymmErrors(4,Graph1_fx3252,Graph1_fy3252,Graph1_felx3252,Graph1_fehx3252,Graph1_fely3252,Graph1_fehy3252);
   grae->SetName("Graph1");
   grae->SetTitle("CT14 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3252 = new TH1F("Graph_Graph3252","CT14 Ratio",100,1.985,3.965);
   Graph_Graph3252->SetMinimum(0.01);
   Graph_Graph3252->SetMaximum(3.5);
   Graph_Graph3252->SetDirectory(0);
   Graph_Graph3252->SetStats(0);
   Graph_Graph3252->SetLineWidth(2);
   Graph_Graph3252->SetMarkerStyle(0);
   Graph_Graph3252->GetXaxis()->SetRange(1,101);
   Graph_Graph3252->GetXaxis()->SetNdivisions(4);
   Graph_Graph3252->GetXaxis()->SetLabelFont(132);
   Graph_Graph3252->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3252->GetXaxis()->SetLabelSize(0);
   Graph_Graph3252->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3252->GetXaxis()->SetTitleFont(132);
   Graph_Graph3252->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3252->GetYaxis()->SetLabelFont(132);
   Graph_Graph3252->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3252->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3252->GetYaxis()->SetTitleFont(132);
   Graph_Graph3252->GetZaxis()->SetLabelFont(132);
   Graph_Graph3252->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3252->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3252->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3252);
   
   grae->Draw("p1p");
   
   Double_t Graph2_fx3253[4] = {
   2.25,
   2.75,
   3.25,
   4};
   Double_t Graph2_fy3253[4] = {
   2.00126,
   1.85043,
   1.4888,
   1.01778};
   Double_t Graph2_felx3253[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph2_fely3253[4] = {
   0.0149,
   0.0084,
   0.0082,
   0.0107};
   Double_t Graph2_fehx3253[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph2_fehy3253[4] = {
   0.0149,
   0.0084,
   0.0082,
   0.0107};
   grae = new TGraphAsymmErrors(4,Graph2_fx3253,Graph2_fy3253,Graph2_felx3253,Graph2_fehx3253,Graph2_fely3253,Graph2_fehy3253);
   grae->SetName("Graph2");
   grae->SetTitle("MMHT14 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph3253 = new TH1F("Graph_Graph3253","MMHT14 Ratio",100,2.075,4.175);
   Graph_Graph3253->SetMinimum(0.01);
   Graph_Graph3253->SetMaximum(3.5);
   Graph_Graph3253->SetDirectory(0);
   Graph_Graph3253->SetStats(0);
   Graph_Graph3253->SetLineWidth(2);
   Graph_Graph3253->SetMarkerStyle(0);
   Graph_Graph3253->GetXaxis()->SetRange(0,101);
   Graph_Graph3253->GetXaxis()->SetNdivisions(4);
   Graph_Graph3253->GetXaxis()->SetLabelFont(132);
   Graph_Graph3253->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3253->GetXaxis()->SetLabelSize(0);
   Graph_Graph3253->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3253->GetXaxis()->SetTitleFont(132);
   Graph_Graph3253->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3253->GetYaxis()->SetLabelFont(132);
   Graph_Graph3253->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3253->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3253->GetYaxis()->SetTitleFont(132);
   Graph_Graph3253->GetZaxis()->SetLabelFont(132);
   Graph_Graph3253->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3253->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3253->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3253);
   
   grae->Draw("p1p");
   
   Double_t Graph3_fx3254[4] = {
   2.25,
   2.75,
   3.25,
   4};
   Double_t Graph3_fy3254[4] = {
   2.00126,
   1.85043,
   1.4888,
   1.01778};
   Double_t Graph3_felx3254[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph3_fely3254[4] = {
   0.0428347,
   0.0420005,
   0.0472866,
   0.0560206};
   Double_t Graph3_fehx3254[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph3_fehy3254[4] = {
   0.041402,
   0.0406719,
   0.0459362,
   0.056178};
   grae = new TGraphAsymmErrors(4,Graph3_fx3254,Graph3_fy3254,Graph3_felx3254,Graph3_fehx3254,Graph3_fely3254,Graph3_fehy3254);
   grae->SetName("Graph3");
   grae->SetTitle("MMHT14 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph3254 = new TH1F("Graph_Graph3254","MMHT14 Ratio",100,2.075,4.175);
   Graph_Graph3254->SetMinimum(0.01);
   Graph_Graph3254->SetMaximum(3.5);
   Graph_Graph3254->SetDirectory(0);
   Graph_Graph3254->SetStats(0);
   Graph_Graph3254->SetLineWidth(2);
   Graph_Graph3254->SetMarkerStyle(0);
   Graph_Graph3254->GetXaxis()->SetRange(0,101);
   Graph_Graph3254->GetXaxis()->SetNdivisions(4);
   Graph_Graph3254->GetXaxis()->SetLabelFont(132);
   Graph_Graph3254->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3254->GetXaxis()->SetLabelSize(0);
   Graph_Graph3254->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3254->GetXaxis()->SetTitleFont(132);
   Graph_Graph3254->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3254->GetYaxis()->SetLabelFont(132);
   Graph_Graph3254->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3254->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3254->GetYaxis()->SetTitleFont(132);
   Graph_Graph3254->GetZaxis()->SetLabelFont(132);
   Graph_Graph3254->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3254->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3254->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3254);
   
   grae->Draw("p1p");
   
   Double_t Graph4_fx3255[4] = {
   2.35,
   2.85,
   3.35,
   4.2};
   Double_t Graph4_fy3255[4] = {
   2.0268,
   1.8851,
   1.4885,
   0.9614};
   Double_t Graph4_felx3255[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph4_fely3255[4] = {
   0.0149,
   0.0084,
   0.0082,
   0.0107};
   Double_t Graph4_fehx3255[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph4_fehy3255[4] = {
   0.0149,
   0.0084,
   0.0082,
   0.0107};
   grae = new TGraphAsymmErrors(4,Graph4_fx3255,Graph4_fy3255,Graph4_felx3255,Graph4_fehx3255,Graph4_fely3255,Graph4_fehy3255);
   grae->SetName("Graph4");
   grae->SetTitle("NNPDF30 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_Graph3255 = new TH1F("Graph_Graph3255","NNPDF30 Ratio",100,2.165,4.385);
   Graph_Graph3255->SetMinimum(0.01);
   Graph_Graph3255->SetMaximum(3.5);
   Graph_Graph3255->SetDirectory(0);
   Graph_Graph3255->SetStats(0);
   Graph_Graph3255->SetLineWidth(2);
   Graph_Graph3255->SetMarkerStyle(0);
   Graph_Graph3255->GetXaxis()->SetRange(0,101);
   Graph_Graph3255->GetXaxis()->SetNdivisions(4);
   Graph_Graph3255->GetXaxis()->SetLabelFont(132);
   Graph_Graph3255->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3255->GetXaxis()->SetLabelSize(0);
   Graph_Graph3255->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3255->GetXaxis()->SetTitleFont(132);
   Graph_Graph3255->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3255->GetYaxis()->SetLabelFont(132);
   Graph_Graph3255->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3255->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3255->GetYaxis()->SetTitleFont(132);
   Graph_Graph3255->GetZaxis()->SetLabelFont(132);
   Graph_Graph3255->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3255->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3255->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3255);
   
   grae->Draw("p1p");
   
   Double_t Graph5_fx3256[4] = {
   2.35,
   2.85,
   3.35,
   4.2};
   Double_t Graph5_fy3256[4] = {
   2.0268,
   1.8851,
   1.4885,
   0.9614};
   Double_t Graph5_felx3256[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph5_fely3256[4] = {
   0.0373,
   0.038,
   0.0489,
   0.0855};
   Double_t Graph5_fehx3256[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph5_fehy3256[4] = {
   0.0373,
   0.038,
   0.0489,
   0.0855};
   grae = new TGraphAsymmErrors(4,Graph5_fx3256,Graph5_fy3256,Graph5_felx3256,Graph5_fehx3256,Graph5_fely3256,Graph5_fehy3256);
   grae->SetName("Graph5");
   grae->SetTitle("NNPDF30 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_Graph3256 = new TH1F("Graph_Graph3256","NNPDF30 Ratio",100,2.165,4.385);
   Graph_Graph3256->SetMinimum(0.01);
   Graph_Graph3256->SetMaximum(3.5);
   Graph_Graph3256->SetDirectory(0);
   Graph_Graph3256->SetStats(0);
   Graph_Graph3256->SetLineWidth(2);
   Graph_Graph3256->SetMarkerStyle(0);
   Graph_Graph3256->GetXaxis()->SetRange(0,101);
   Graph_Graph3256->GetXaxis()->SetNdivisions(4);
   Graph_Graph3256->GetXaxis()->SetLabelFont(132);
   Graph_Graph3256->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3256->GetXaxis()->SetLabelSize(0);
   Graph_Graph3256->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3256->GetXaxis()->SetTitleFont(132);
   Graph_Graph3256->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3256->GetYaxis()->SetLabelFont(132);
   Graph_Graph3256->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3256->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3256->GetYaxis()->SetTitleFont(132);
   Graph_Graph3256->GetZaxis()->SetLabelFont(132);
   Graph_Graph3256->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3256->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3256->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3256);
   
   grae->Draw("p1p");
   
   TPaveText *pt = new TPaveText(0.5,0.85,0.85,0.94,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(132);
   TText *AText = pt->AddText("LHCb, #sqrt{s} = 8 TeV");
   pt->Draw();
   
   TLegend *leg = new TLegend(0.5,0.62,0.9,0.87,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(10);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("data_stat","Data_{stat}","f");

   ci = TColor::GetColor("#ff9933");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("data_tot","Data_{tot}","f");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("ct_temp","CT14","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("mmht_temp","MMHT14","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("nnpdf_temp","NNPDF30","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(25);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   Double_t xAxis174[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_r_eta_toterr_copy__204 = new TH1F("w_r_eta_toterr_copy__204","w_eta",4, xAxis174);
   w_r_eta_toterr_copy__204->SetBinContent(1,2.19025);
   w_r_eta_toterr_copy__204->SetBinContent(2,1.898889);
   w_r_eta_toterr_copy__204->SetBinContent(3,1.529143);
   w_r_eta_toterr_copy__204->SetBinContent(4,0.9650988);
   w_r_eta_toterr_copy__204->SetBinContent(5,0.9650988);
   w_r_eta_toterr_copy__204->SetBinError(1,0.07464207);
   w_r_eta_toterr_copy__204->SetBinError(2,0.0660939);
   w_r_eta_toterr_copy__204->SetBinError(3,0.06010184);
   w_r_eta_toterr_copy__204->SetBinError(4,0.06616402);
   w_r_eta_toterr_copy__204->SetBinError(5,0.06616402);
   w_r_eta_toterr_copy__204->SetMinimum(0.01);
   w_r_eta_toterr_copy__204->SetMaximum(3.5);
   w_r_eta_toterr_copy__204->SetEntries(6);
   w_r_eta_toterr_copy__204->SetDirectory(0);
   w_r_eta_toterr_copy__204->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr_copy__204->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr_copy__204->SetLineColor(ci);
   w_r_eta_toterr_copy__204->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr_copy__204->SetMarkerColor(ci);
   w_r_eta_toterr_copy__204->SetMarkerStyle(0);
   w_r_eta_toterr_copy__204->GetXaxis()->SetRange(1,4);
   w_r_eta_toterr_copy__204->GetXaxis()->SetNdivisions(4);
   w_r_eta_toterr_copy__204->GetXaxis()->SetLabelFont(132);
   w_r_eta_toterr_copy__204->GetXaxis()->SetLabelOffset(999);
   w_r_eta_toterr_copy__204->GetXaxis()->SetLabelSize(0);
   w_r_eta_toterr_copy__204->GetXaxis()->SetTitleSize(0.06);
   w_r_eta_toterr_copy__204->GetXaxis()->SetTitleFont(132);
   w_r_eta_toterr_copy__204->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_eta_toterr_copy__204->GetYaxis()->SetLabelFont(132);
   w_r_eta_toterr_copy__204->GetYaxis()->SetLabelSize(0.05);
   w_r_eta_toterr_copy__204->GetYaxis()->SetTitleSize(0.06);
   w_r_eta_toterr_copy__204->GetYaxis()->SetTitleFont(132);
   w_r_eta_toterr_copy__204->GetZaxis()->SetLabelFont(132);
   w_r_eta_toterr_copy__204->GetZaxis()->SetLabelSize(0.05);
   w_r_eta_toterr_copy__204->GetZaxis()->SetTitleSize(0.06);
   w_r_eta_toterr_copy__204->GetZaxis()->SetTitleFont(132);
   w_r_eta_toterr_copy__204->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.567901,0.2935897,4.654321,3.267949);
   lowerPad->SetFillColor(0);
   lowerPad->SetFillStyle(4000);
   lowerPad->SetBorderMode(0);
   lowerPad->SetBorderSize(2);
   lowerPad->SetTickx(1);
   lowerPad->SetTicky(1);
   lowerPad->SetLeftMargin(0.14);
   lowerPad->SetRightMargin(0.05);
   lowerPad->SetTopMargin(0.665);
   lowerPad->SetBottomMargin(0.14);
   lowerPad->SetFrameLineWidth(2);
   lowerPad->SetFrameBorderMode(0);
   lowerPad->SetFrameLineWidth(2);
   lowerPad->SetFrameBorderMode(0);
   Double_t xAxis175[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205 = new TH1F("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205","w_eta",4, xAxis175);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinContent(1,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinContent(2,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinContent(3,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinContent(4,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinContent(5,0.9650988);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinError(1,0.03407924);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinError(2,0.03480661);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinError(3,0.03930426);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinError(4,0.06855673);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetBinError(5,0.06616402);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetMinimum(0.71);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetMaximum(1.29);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetEntries(10);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetLineColor(ci);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetMarkerColor(ci);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->SetMarkerStyle(0);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetXaxis()->SetRange(1,4);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetXaxis()->SetNdivisions(4);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetXaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetXaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetYaxis()->SetTitle("Ratio");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetYaxis()->CenterTitle(true);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetYaxis()->SetNdivisions(505);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetYaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetYaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetZaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->GetZaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0__205->Draw("e2");
   Double_t xAxis176[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206 = new TH1F("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206","w_eta",4, xAxis176);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinContent(1,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinContent(2,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinContent(3,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinContent(4,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinContent(5,0.9650988);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinError(1,0.01228116);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinError(2,0.01160041);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinError(3,0.01344199);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinError(4,0.01789213);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetBinError(5,0.01726767);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetMinimum(0.71);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetMaximum(1.29);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetEntries(10);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetLineColor(ci);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetMarkerColor(ci);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->SetMarkerStyle(0);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetXaxis()->SetRange(1,4);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetXaxis()->SetNdivisions(4);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetXaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetXaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetYaxis()->SetTitle("Ratio");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetYaxis()->CenterTitle(true);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetYaxis()->SetNdivisions(505);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetYaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetYaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetZaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->GetZaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp1__206->Draw("e2same");
   
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fx3257[4] = {
   2.15,
   2.65,
   3.15,
   3.8};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fy3257[4] = {
   0.9358062,
   1.009032,
   1.012279,
   1.108229};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_felx3257[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fely3257[4] = {
   0.006802875,
   0.004423639,
   0.00536248,
   0.01108695};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fehx3257[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fehy3257[4] = {
   0.006802875,
   0.004423639,
   0.00536248,
   0.01108695};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fx3257,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fy3257,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_felx3257,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fehx3257,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fely3257,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2_fehy3257);
   grae->SetName("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("CT14 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257 = new TH1F("Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257","CT14 Ratio",100,1.985,3.965);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->SetMinimum(0.71);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->SetMaximum(1.29);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->SetDirectory(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->SetStats(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->SetLineWidth(2);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->SetMarkerStyle(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetXaxis()->SetRange(1,101);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp23257);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fx3258[4] = {
   2.15,
   2.65,
   3.15,
   3.8};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fy3258[4] = {
   0.9358062,
   1.009032,
   1.012279,
   1.108229};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_felx3258[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fely3258[4] = {
   0.02071987,
   0.02640219,
   0.03906143,
   0.07919217};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fehx3258[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fehy3258[4] = {
   0.02276616,
   0.02703062,
   0.03675154,
   0.06553201};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fx3258,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fy3258,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_felx3258,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fehx3258,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fely3258,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3_fehy3258);
   grae->SetName("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("CT14 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258 = new TH1F("Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258","CT14 Ratio",100,1.985,3.965);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->SetMinimum(0.71);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->SetMaximum(1.29);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->SetDirectory(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->SetStats(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->SetLineWidth(2);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->SetMarkerStyle(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetXaxis()->SetRange(1,101);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp33258);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fx3259[4] = {
   2.25,
   2.75,
   3.25,
   4};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fy3259[4] = {
   0.9137129,
   0.9744802,
   0.9736172,
   1.054586};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_felx3259[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fely3259[4] = {
   0.006802875,
   0.004423639,
   0.00536248,
   0.01108695};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fehx3259[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fehy3259[4] = {
   0.006802875,
   0.004423639,
   0.00536248,
   0.01108695};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fx3259,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fy3259,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_felx3259,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fehx3259,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fely3259,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4_fehy3259);
   grae->SetName("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("MMHT14 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259 = new TH1F("Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259","MMHT14 Ratio",100,2.075,4.175);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->SetMinimum(0.71);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->SetMaximum(1.29);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->SetDirectory(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->SetStats(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->SetLineWidth(2);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->SetMarkerStyle(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetXaxis()->SetRange(0,101);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp43259);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fx3260[4] = {
   2.25,
   2.75,
   3.25,
   4};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fy3260[4] = {
   0.9137129,
   0.9744802,
   0.9736172,
   1.054586};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_felx3260[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fely3260[4] = {
   0.01955699,
   0.02211846,
   0.03092359,
   0.05804649};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fehx3260[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fehy3260[4] = {
   0.01890286,
   0.02141879,
   0.03004048,
   0.05820958};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fx3260,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fy3260,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_felx3260,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fehx3260,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fely3260,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5_fehy3260);
   grae->SetName("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp5");
   grae->SetTitle("MMHT14 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260 = new TH1F("Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260","MMHT14 Ratio",100,2.075,4.175);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->SetMinimum(0.71);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->SetMaximum(1.29);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->SetDirectory(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->SetStats(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->SetLineWidth(2);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->SetMarkerStyle(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetXaxis()->SetRange(0,101);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp53260);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fx3261[4] = {
   2.35,
   2.85,
   3.35,
   4.2};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fy3261[4] = {
   0.9253736,
   0.9927383,
   0.973421,
   0.9961674};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_felx3261[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fely3261[4] = {
   0.006802875,
   0.004423639,
   0.00536248,
   0.01108695};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fehx3261[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fehy3261[4] = {
   0.006802875,
   0.004423639,
   0.00536248,
   0.01108695};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fx3261,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fy3261,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_felx3261,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fehx3261,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fely3261,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6_fehy3261);
   grae->SetName("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp6");
   grae->SetTitle("NNPDF30 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261 = new TH1F("Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261","NNPDF30 Ratio",100,2.165,4.385);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->SetMinimum(0.71);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->SetMaximum(1.29);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->SetDirectory(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->SetStats(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->SetLineWidth(2);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->SetMarkerStyle(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetXaxis()->SetRange(0,101);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp63261);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fx3262[4] = {
   2.35,
   2.85,
   3.35,
   4.2};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fy3262[4] = {
   0.9253736,
   0.9927383,
   0.973421,
   0.9961674};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_felx3262[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fely3262[4] = {
   0.01703002,
   0.0200117,
   0.03197869,
   0.08859197};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fehx3262[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fehy3262[4] = {
   0.01703002,
   0.0200117,
   0.03197869,
   0.08859197};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fx3262,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fy3262,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_felx3262,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fehx3262,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fely3262,wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7_fehy3262);
   grae->SetName("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp7");
   grae->SetTitle("NNPDF30 Ratio");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262 = new TH1F("Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262","NNPDF30 Ratio",100,2.165,4.385);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->SetMinimum(0.71);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->SetMaximum(1.29);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->SetDirectory(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->SetStats(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->SetLineWidth(2);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->SetMarkerStyle(0);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetXaxis()->SetRange(0,101);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp73262);
   
   grae->Draw("p1");
   Double_t xAxis177[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207 = new TH1F("wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207","w_eta",4, xAxis177);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinContent(1,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinContent(2,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinContent(3,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinContent(4,1);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinContent(5,0.9650988);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinError(1,0.03407924);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinError(2,0.03480661);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinError(3,0.03930426);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinError(4,0.06855673);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetBinError(5,0.06616402);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetMinimum(0.71);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetMaximum(1.29);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetEntries(10);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetDirectory(0);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetLineColor(ci);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetMarkerColor(ci);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->SetMarkerStyle(0);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetXaxis()->SetRange(1,4);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetXaxis()->SetNdivisions(4);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetXaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetXaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetYaxis()->SetTitle("Ratio");
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetYaxis()->CenterTitle(true);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetYaxis()->SetNdivisions(505);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetYaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetYaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetZaxis()->SetLabelFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->GetZaxis()->SetTitleFont(132);
   wj_ratio_eta_fewz_8TeV_400_1001_0ratiocomp0_copy__207->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
