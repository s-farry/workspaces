void wj_asymm_eta_fewz_8TeV()
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
   upperPad->Range(1.567901,-0.6637097,4.654321,0.7717742);
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
   Double_t xAxis166[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_a_eta_toterr__196 = new TH1F("w_a_eta_toterr__196","w_eta",4, xAxis166);
   w_a_eta_toterr__196->SetBinContent(1,0.37309);
   w_a_eta_toterr__196->SetBinContent(2,0.3100806);
   w_a_eta_toterr__196->SetBinContent(3,0.2092183);
   w_a_eta_toterr__196->SetBinContent(4,-0.01776053);
   w_a_eta_toterr__196->SetBinContent(5,-0.01776053);
   w_a_eta_toterr__196->SetBinError(1,0.01466777);
   w_a_eta_toterr__196->SetBinError(2,0.01572998);
   w_a_eta_toterr__196->SetBinError(3,0.01879191);
   w_a_eta_toterr__196->SetBinError(4,0.03426755);
   w_a_eta_toterr__196->SetBinError(5,0.03426755);
   w_a_eta_toterr__196->SetMinimum(-0.19);
   w_a_eta_toterr__196->SetMaximum(0.7);
   w_a_eta_toterr__196->SetEntries(6);
   w_a_eta_toterr__196->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr__196->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr__196->SetLineColor(ci);
   w_a_eta_toterr__196->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr__196->SetMarkerColor(ci);
   w_a_eta_toterr__196->SetMarkerStyle(0);
   w_a_eta_toterr__196->GetXaxis()->SetRange(1,4);
   w_a_eta_toterr__196->GetXaxis()->SetNdivisions(4);
   w_a_eta_toterr__196->GetXaxis()->SetLabelFont(132);
   w_a_eta_toterr__196->GetXaxis()->SetLabelOffset(999);
   w_a_eta_toterr__196->GetXaxis()->SetLabelSize(0);
   w_a_eta_toterr__196->GetXaxis()->SetTitleSize(0.06);
   w_a_eta_toterr__196->GetXaxis()->SetTitleFont(132);
   w_a_eta_toterr__196->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_eta_toterr__196->GetYaxis()->SetLabelFont(132);
   w_a_eta_toterr__196->GetYaxis()->SetLabelSize(0.05);
   w_a_eta_toterr__196->GetYaxis()->SetTitleSize(0.06);
   w_a_eta_toterr__196->GetYaxis()->SetTitleFont(132);
   w_a_eta_toterr__196->GetZaxis()->SetLabelFont(132);
   w_a_eta_toterr__196->GetZaxis()->SetLabelSize(0.05);
   w_a_eta_toterr__196->GetZaxis()->SetTitleSize(0.06);
   w_a_eta_toterr__196->GetZaxis()->SetTitleFont(132);
   w_a_eta_toterr__196->Draw("e2");
   Double_t xAxis167[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_a_eta_staterr__197 = new TH1F("w_a_eta_staterr__197","w_eta",4, xAxis167);
   w_a_eta_staterr__197->SetBinContent(1,0.37309);
   w_a_eta_staterr__197->SetBinContent(2,0.3100806);
   w_a_eta_staterr__197->SetBinContent(3,0.2092183);
   w_a_eta_staterr__197->SetBinContent(4,-0.01776053);
   w_a_eta_staterr__197->SetBinContent(5,-0.01776053);
   w_a_eta_staterr__197->SetBinError(1,0.005285836);
   w_a_eta_staterr__197->SetBinError(2,0.005242515);
   w_a_eta_staterr__197->SetBinError(3,0.006426803);
   w_a_eta_staterr__197->SetBinError(4,0.008943243);
   w_a_eta_staterr__197->SetBinError(5,0.008943243);
   w_a_eta_staterr__197->SetMinimum(-0.19);
   w_a_eta_staterr__197->SetMaximum(0.7);
   w_a_eta_staterr__197->SetEntries(6);
   w_a_eta_staterr__197->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   w_a_eta_staterr__197->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   w_a_eta_staterr__197->SetLineColor(ci);
   w_a_eta_staterr__197->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   w_a_eta_staterr__197->SetMarkerColor(ci);
   w_a_eta_staterr__197->SetMarkerStyle(0);
   w_a_eta_staterr__197->GetXaxis()->SetRange(1,4);
   w_a_eta_staterr__197->GetXaxis()->SetNdivisions(4);
   w_a_eta_staterr__197->GetXaxis()->SetLabelFont(132);
   w_a_eta_staterr__197->GetXaxis()->SetLabelOffset(999);
   w_a_eta_staterr__197->GetXaxis()->SetLabelSize(0);
   w_a_eta_staterr__197->GetXaxis()->SetTitleSize(0.06);
   w_a_eta_staterr__197->GetXaxis()->SetTitleFont(132);
   w_a_eta_staterr__197->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_eta_staterr__197->GetYaxis()->SetLabelFont(132);
   w_a_eta_staterr__197->GetYaxis()->SetLabelSize(0.05);
   w_a_eta_staterr__197->GetYaxis()->SetTitleSize(0.06);
   w_a_eta_staterr__197->GetYaxis()->SetTitleFont(132);
   w_a_eta_staterr__197->GetZaxis()->SetLabelFont(132);
   w_a_eta_staterr__197->GetZaxis()->SetLabelSize(0.05);
   w_a_eta_staterr__197->GetZaxis()->SetTitleSize(0.06);
   w_a_eta_staterr__197->GetZaxis()->SetTitleFont(132);
   w_a_eta_staterr__197->Draw("e2same");
   
   Double_t Graph0_fx3239[4] = {
   2.15,
   2.65,
   3.15,
   3.8};
   Double_t Graph0_fy3239[4] = {
   0.344188,
   0.314139,
   0.215046,
   0.0336065};
   Double_t Graph0_felx3239[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph0_fely3239[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   Double_t Graph0_fehx3239[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph0_fehy3239[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,Graph0_fx3239,Graph0_fy3239,Graph0_felx3239,Graph0_fehx3239,Graph0_fely3239,Graph0_fehy3239);
   grae->SetName("Graph0");
   grae->SetTitle("CT14 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3239 = new TH1F("Graph_Graph3239","CT14 Asym",100,1.985,3.965);
   Graph_Graph3239->SetMinimum(-0.19);
   Graph_Graph3239->SetMaximum(0.7);
   Graph_Graph3239->SetDirectory(0);
   Graph_Graph3239->SetStats(0);
   Graph_Graph3239->SetLineWidth(2);
   Graph_Graph3239->SetMarkerStyle(0);
   Graph_Graph3239->GetXaxis()->SetRange(1,101);
   Graph_Graph3239->GetXaxis()->SetNdivisions(4);
   Graph_Graph3239->GetXaxis()->SetLabelFont(132);
   Graph_Graph3239->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3239->GetXaxis()->SetLabelSize(0);
   Graph_Graph3239->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3239->GetXaxis()->SetTitleFont(132);
   Graph_Graph3239->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3239->GetYaxis()->SetLabelFont(132);
   Graph_Graph3239->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3239->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3239->GetYaxis()->SetTitleFont(132);
   Graph_Graph3239->GetZaxis()->SetLabelFont(132);
   Graph_Graph3239->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3239->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3239->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3239);
   
   grae->Draw("p1p");
   
   Double_t Graph1_fx3240[4] = {
   2.15,
   2.65,
   3.15,
   3.8};
   Double_t Graph1_fy3240[4] = {
   0.344188,
   0.314139,
   0.215046,
   0.0336065};
   Double_t Graph1_felx3240[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph1_fely3240[4] = {
   0.009788632,
   0.01189271,
   0.01897647,
   0.03837556};
   Double_t Graph1_fehx3240[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph1_fehy3240[4] = {
   0.01066322,
   0.01200255,
   0.0175228,
   0.03120213};
   grae = new TGraphAsymmErrors(4,Graph1_fx3240,Graph1_fy3240,Graph1_felx3240,Graph1_fehx3240,Graph1_fely3240,Graph1_fehy3240);
   grae->SetName("Graph1");
   grae->SetTitle("CT14 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3240 = new TH1F("Graph_Graph3240","CT14 Asym",100,1.985,3.965);
   Graph_Graph3240->SetMinimum(-0.19);
   Graph_Graph3240->SetMaximum(0.7);
   Graph_Graph3240->SetDirectory(0);
   Graph_Graph3240->SetStats(0);
   Graph_Graph3240->SetLineWidth(2);
   Graph_Graph3240->SetMarkerStyle(0);
   Graph_Graph3240->GetXaxis()->SetRange(1,101);
   Graph_Graph3240->GetXaxis()->SetNdivisions(4);
   Graph_Graph3240->GetXaxis()->SetLabelFont(132);
   Graph_Graph3240->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3240->GetXaxis()->SetLabelSize(0);
   Graph_Graph3240->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3240->GetXaxis()->SetTitleFont(132);
   Graph_Graph3240->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3240->GetYaxis()->SetLabelFont(132);
   Graph_Graph3240->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3240->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3240->GetYaxis()->SetTitleFont(132);
   Graph_Graph3240->GetZaxis()->SetLabelFont(132);
   Graph_Graph3240->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3240->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3240->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3240);
   
   grae->Draw("p1p");
   
   Double_t Graph2_fx3241[4] = {
   2.25,
   2.75,
   3.25,
   4};
   Double_t Graph2_fy3241[4] = {
   0.333614,
   0.29835,
   0.196399,
   0.00881251};
   Double_t Graph2_felx3241[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph2_fely3241[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   Double_t Graph2_fehx3241[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph2_fehy3241[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   grae = new TGraphAsymmErrors(4,Graph2_fx3241,Graph2_fy3241,Graph2_felx3241,Graph2_fehx3241,Graph2_fely3241,Graph2_fehy3241);
   grae->SetName("Graph2");
   grae->SetTitle("MMHT14 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph3241 = new TH1F("Graph_Graph3241","MMHT14 Asym",100,2.075,4.175);
   Graph_Graph3241->SetMinimum(-0.19);
   Graph_Graph3241->SetMaximum(0.7);
   Graph_Graph3241->SetDirectory(0);
   Graph_Graph3241->SetStats(0);
   Graph_Graph3241->SetLineWidth(2);
   Graph_Graph3241->SetMarkerStyle(0);
   Graph_Graph3241->GetXaxis()->SetRange(0,101);
   Graph_Graph3241->GetXaxis()->SetNdivisions(4);
   Graph_Graph3241->GetXaxis()->SetLabelFont(132);
   Graph_Graph3241->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3241->GetXaxis()->SetLabelSize(0);
   Graph_Graph3241->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3241->GetXaxis()->SetTitleFont(132);
   Graph_Graph3241->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3241->GetYaxis()->SetLabelFont(132);
   Graph_Graph3241->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3241->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3241->GetYaxis()->SetTitleFont(132);
   Graph_Graph3241->GetZaxis()->SetLabelFont(132);
   Graph_Graph3241->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3241->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3241->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3241);
   
   grae->Draw("p1p");
   
   Double_t Graph3_fx3242[4] = {
   2.25,
   2.75,
   3.25,
   4};
   Double_t Graph3_fy3242[4] = {
   0.333614,
   0.29835,
   0.196399,
   0.00881251};
   Double_t Graph3_felx3242[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph3_fely3242[4] = {
   0.0094254,
   0.01030067,
   0.0155895,
   0.0294625};
   Double_t Graph3_fehx3242[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph3_fehy3242[4] = {
   0.00906558,
   0.00991985,
   0.0150238,
   0.0291465};
   grae = new TGraphAsymmErrors(4,Graph3_fx3242,Graph3_fy3242,Graph3_felx3242,Graph3_fehx3242,Graph3_fely3242,Graph3_fehy3242);
   grae->SetName("Graph3");
   grae->SetTitle("MMHT14 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph3242 = new TH1F("Graph_Graph3242","MMHT14 Asym",100,2.075,4.175);
   Graph_Graph3242->SetMinimum(-0.19);
   Graph_Graph3242->SetMaximum(0.7);
   Graph_Graph3242->SetDirectory(0);
   Graph_Graph3242->SetStats(0);
   Graph_Graph3242->SetLineWidth(2);
   Graph_Graph3242->SetMarkerStyle(0);
   Graph_Graph3242->GetXaxis()->SetRange(0,101);
   Graph_Graph3242->GetXaxis()->SetNdivisions(4);
   Graph_Graph3242->GetXaxis()->SetLabelFont(132);
   Graph_Graph3242->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3242->GetXaxis()->SetLabelSize(0);
   Graph_Graph3242->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3242->GetXaxis()->SetTitleFont(132);
   Graph_Graph3242->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3242->GetYaxis()->SetLabelFont(132);
   Graph_Graph3242->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3242->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3242->GetYaxis()->SetTitleFont(132);
   Graph_Graph3242->GetZaxis()->SetLabelFont(132);
   Graph_Graph3242->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3242->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3242->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3242);
   
   grae->Draw("p1p");
   
   Double_t Graph4_fx3243[4] = {
   2.35,
   2.85,
   3.35,
   4.2};
   Double_t Graph4_fy3243[4] = {
   0.3392,
   0.3067,
   0.1961,
   -0.0211};
   Double_t Graph4_felx3243[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph4_fely3243[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   Double_t Graph4_fehx3243[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph4_fehy3243[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   grae = new TGraphAsymmErrors(4,Graph4_fx3243,Graph4_fy3243,Graph4_felx3243,Graph4_fehx3243,Graph4_fely3243,Graph4_fehy3243);
   grae->SetName("Graph4");
   grae->SetTitle("NNPDF30 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_Graph3243 = new TH1F("Graph_Graph3243","NNPDF30 Asym",100,2.165,4.385);
   Graph_Graph3243->SetMinimum(-0.19);
   Graph_Graph3243->SetMaximum(0.7);
   Graph_Graph3243->SetDirectory(0);
   Graph_Graph3243->SetStats(0);
   Graph_Graph3243->SetLineWidth(2);
   Graph_Graph3243->SetMarkerStyle(0);
   Graph_Graph3243->GetXaxis()->SetRange(0,101);
   Graph_Graph3243->GetXaxis()->SetNdivisions(4);
   Graph_Graph3243->GetXaxis()->SetLabelFont(132);
   Graph_Graph3243->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3243->GetXaxis()->SetLabelSize(0);
   Graph_Graph3243->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3243->GetXaxis()->SetTitleFont(132);
   Graph_Graph3243->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3243->GetYaxis()->SetLabelFont(132);
   Graph_Graph3243->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3243->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3243->GetYaxis()->SetTitleFont(132);
   Graph_Graph3243->GetZaxis()->SetLabelFont(132);
   Graph_Graph3243->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3243->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3243->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3243);
   
   grae->Draw("p1p");
   
   Double_t Graph5_fx3244[4] = {
   2.35,
   2.85,
   3.35,
   4.2};
   Double_t Graph5_fy3244[4] = {
   0.3392,
   0.3067,
   0.1961,
   -0.0211};
   Double_t Graph5_felx3244[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph5_fely3244[4] = {
   0.0081,
   0.0091,
   0.016,
   0.0458};
   Double_t Graph5_fehx3244[4] = {
   0,
   0,
   0,
   0};
   Double_t Graph5_fehy3244[4] = {
   0.0081,
   0.0091,
   0.016,
   0.0458};
   grae = new TGraphAsymmErrors(4,Graph5_fx3244,Graph5_fy3244,Graph5_felx3244,Graph5_fehx3244,Graph5_fely3244,Graph5_fehy3244);
   grae->SetName("Graph5");
   grae->SetTitle("NNPDF30 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_Graph3244 = new TH1F("Graph_Graph3244","NNPDF30 Asym",100,2.165,4.385);
   Graph_Graph3244->SetMinimum(-0.19);
   Graph_Graph3244->SetMaximum(0.7);
   Graph_Graph3244->SetDirectory(0);
   Graph_Graph3244->SetStats(0);
   Graph_Graph3244->SetLineWidth(2);
   Graph_Graph3244->SetMarkerStyle(0);
   Graph_Graph3244->GetXaxis()->SetRange(0,101);
   Graph_Graph3244->GetXaxis()->SetNdivisions(4);
   Graph_Graph3244->GetXaxis()->SetLabelFont(132);
   Graph_Graph3244->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3244->GetXaxis()->SetLabelSize(0);
   Graph_Graph3244->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3244->GetXaxis()->SetTitleFont(132);
   Graph_Graph3244->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3244->GetYaxis()->SetLabelFont(132);
   Graph_Graph3244->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3244->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3244->GetYaxis()->SetTitleFont(132);
   Graph_Graph3244->GetZaxis()->SetLabelFont(132);
   Graph_Graph3244->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3244->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3244->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3244);
   
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
   Double_t xAxis168[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_a_eta_toterr_copy__198 = new TH1F("w_a_eta_toterr_copy__198","w_eta",4, xAxis168);
   w_a_eta_toterr_copy__198->SetBinContent(1,0.37309);
   w_a_eta_toterr_copy__198->SetBinContent(2,0.3100806);
   w_a_eta_toterr_copy__198->SetBinContent(3,0.2092183);
   w_a_eta_toterr_copy__198->SetBinContent(4,-0.01776053);
   w_a_eta_toterr_copy__198->SetBinContent(5,-0.01776053);
   w_a_eta_toterr_copy__198->SetBinError(1,0.01466777);
   w_a_eta_toterr_copy__198->SetBinError(2,0.01572998);
   w_a_eta_toterr_copy__198->SetBinError(3,0.01879191);
   w_a_eta_toterr_copy__198->SetBinError(4,0.03426755);
   w_a_eta_toterr_copy__198->SetBinError(5,0.03426755);
   w_a_eta_toterr_copy__198->SetMinimum(-0.19);
   w_a_eta_toterr_copy__198->SetMaximum(0.7);
   w_a_eta_toterr_copy__198->SetEntries(6);
   w_a_eta_toterr_copy__198->SetDirectory(0);
   w_a_eta_toterr_copy__198->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr_copy__198->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr_copy__198->SetLineColor(ci);
   w_a_eta_toterr_copy__198->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr_copy__198->SetMarkerColor(ci);
   w_a_eta_toterr_copy__198->SetMarkerStyle(0);
   w_a_eta_toterr_copy__198->GetXaxis()->SetRange(1,4);
   w_a_eta_toterr_copy__198->GetXaxis()->SetNdivisions(4);
   w_a_eta_toterr_copy__198->GetXaxis()->SetLabelFont(132);
   w_a_eta_toterr_copy__198->GetXaxis()->SetLabelOffset(999);
   w_a_eta_toterr_copy__198->GetXaxis()->SetLabelSize(0);
   w_a_eta_toterr_copy__198->GetXaxis()->SetTitleSize(0.06);
   w_a_eta_toterr_copy__198->GetXaxis()->SetTitleFont(132);
   w_a_eta_toterr_copy__198->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_eta_toterr_copy__198->GetYaxis()->SetLabelFont(132);
   w_a_eta_toterr_copy__198->GetYaxis()->SetLabelSize(0.05);
   w_a_eta_toterr_copy__198->GetYaxis()->SetTitleSize(0.06);
   w_a_eta_toterr_copy__198->GetYaxis()->SetTitleFont(132);
   w_a_eta_toterr_copy__198->GetZaxis()->SetLabelFont(132);
   w_a_eta_toterr_copy__198->GetZaxis()->SetLabelSize(0.05);
   w_a_eta_toterr_copy__198->GetZaxis()->SetTitleSize(0.06);
   w_a_eta_toterr_copy__198->GetZaxis()->SetTitleFont(132);
   w_a_eta_toterr_copy__198->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.567901,-0.2435897,4.654321,0.7820513);
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
   Double_t xAxis169[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199 = new TH1F("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199","w_eta",4, xAxis169);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetBinContent(5,-0.01776053);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetBinError(1,0.01466777);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetBinError(2,0.01572998);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetBinError(3,0.01879191);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetBinError(4,0.03426755);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetBinError(5,0.03426755);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetMinimum(-0.1);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetMaximum(0.1);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetEntries(10);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetLineColor(ci);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetMarkerColor(ci);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->SetMarkerStyle(0);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetXaxis()->SetRange(1,4);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetXaxis()->SetNdivisions(4);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetXaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetXaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetYaxis()->SetTitle("Diff.");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetYaxis()->SetNdivisions(505);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetYaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetYaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetZaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->GetZaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0__199->Draw("e2");
   Double_t xAxis170[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200 = new TH1F("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200","w_eta",4, xAxis170);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetBinContent(5,-0.01776053);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetBinError(1,0.005285836);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetBinError(2,0.005242515);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetBinError(3,0.006426803);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetBinError(4,0.008943243);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetBinError(5,0.008943243);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetMinimum(-0.1);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetMaximum(0.1);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetEntries(10);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetLineColor(ci);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetMarkerColor(ci);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->SetMarkerStyle(0);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetXaxis()->SetRange(1,4);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetXaxis()->SetNdivisions(4);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetXaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetXaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetYaxis()->SetTitle("Diff.");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetYaxis()->SetNdivisions(505);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetYaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetYaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetZaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->GetZaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp1__200->Draw("e2same");
   
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fx3245[4] = {
   2.15,
   2.65,
   3.15,
   3.8};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fy3245[4] = {
   -0.02890197,
   0.004058442,
   0.005827677,
   0.05136703};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_felx3245[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fely3245[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fehx3245[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fehy3245[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fx3245,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fy3245,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_felx3245,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fehx3245,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fely3245,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2_fehy3245);
   grae->SetName("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp2");
   grae->SetTitle("CT14 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245 = new TH1F("Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245","CT14 Asym",100,1.985,3.965);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->SetMinimum(-0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->SetMaximum(0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->SetDirectory(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->SetStats(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->SetLineWidth(2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->SetMarkerStyle(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetXaxis()->SetRange(1,101);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp23245);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fx3246[4] = {
   2.15,
   2.65,
   3.15,
   3.8};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fy3246[4] = {
   -0.02890197,
   0.004058442,
   0.005827677,
   0.05136703};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_felx3246[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fely3246[4] = {
   0.009788632,
   0.01189271,
   0.01897647,
   0.03837556};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fehx3246[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fehy3246[4] = {
   0.01066322,
   0.01200255,
   0.0175228,
   0.03120213};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fx3246,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fy3246,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_felx3246,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fehx3246,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fely3246,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3_fehy3246);
   grae->SetName("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp3");
   grae->SetTitle("CT14 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246 = new TH1F("Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246","CT14 Asym",100,1.985,3.965);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->SetMinimum(-0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->SetMaximum(0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->SetDirectory(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->SetStats(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->SetLineWidth(2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->SetMarkerStyle(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetXaxis()->SetRange(1,101);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp33246);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fx3247[4] = {
   2.25,
   2.75,
   3.25,
   4};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fy3247[4] = {
   -0.03947597,
   -0.01173056,
   -0.01281932,
   0.02657304};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_felx3247[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fely3247[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fehx3247[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fehy3247[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fx3247,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fy3247,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_felx3247,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fehx3247,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fely3247,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4_fehy3247);
   grae->SetName("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp4");
   grae->SetTitle("MMHT14 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247 = new TH1F("Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247","MMHT14 Asym",100,2.075,4.175);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->SetMinimum(-0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->SetMaximum(0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->SetDirectory(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->SetStats(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->SetLineWidth(2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->SetMarkerStyle(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetXaxis()->SetRange(0,101);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp43247);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fx3248[4] = {
   2.25,
   2.75,
   3.25,
   4};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fy3248[4] = {
   -0.03947597,
   -0.01173056,
   -0.01281932,
   0.02657304};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_felx3248[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fely3248[4] = {
   0.0094254,
   0.01030067,
   0.0155895,
   0.0294625};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fehx3248[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fehy3248[4] = {
   0.00906558,
   0.00991985,
   0.0150238,
   0.0291465};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fx3248,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fy3248,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_felx3248,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fehx3248,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fely3248,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5_fehy3248);
   grae->SetName("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp5");
   grae->SetTitle("MMHT14 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248 = new TH1F("Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248","MMHT14 Asym",100,2.075,4.175);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->SetMinimum(-0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->SetMaximum(0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->SetDirectory(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->SetStats(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->SetLineWidth(2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->SetMarkerStyle(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetXaxis()->SetRange(0,101);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp53248);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fx3249[4] = {
   2.35,
   2.85,
   3.35,
   4.2};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fy3249[4] = {
   -0.03388997,
   -0.003380558,
   -0.01311832,
   -0.003339474};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_felx3249[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fely3249[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fehx3249[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fehy3249[4] = {
   0.0032,
   0.002,
   0.0029,
   0.007};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fx3249,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fy3249,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_felx3249,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fehx3249,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fely3249,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6_fehy3249);
   grae->SetName("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp6");
   grae->SetTitle("NNPDF30 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249 = new TH1F("Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249","NNPDF30 Asym",100,2.165,4.385);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->SetMinimum(-0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->SetMaximum(0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->SetDirectory(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->SetStats(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->SetLineWidth(2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->SetMarkerStyle(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetXaxis()->SetRange(0,101);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp63249);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fx3250[4] = {
   2.35,
   2.85,
   3.35,
   4.2};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fy3250[4] = {
   -0.03388997,
   -0.003380558,
   -0.01311832,
   -0.003339474};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_felx3250[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fely3250[4] = {
   0.0081,
   0.0091,
   0.016,
   0.0458};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fehx3250[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fehy3250[4] = {
   0.0081,
   0.0091,
   0.016,
   0.0458};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fx3250,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fy3250,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_felx3250,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fehx3250,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fely3250,wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7_fehy3250);
   grae->SetName("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp7");
   grae->SetTitle("NNPDF30 Asym");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(25);
   
   TH1F *Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250 = new TH1F("Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250","NNPDF30 Asym",100,2.165,4.385);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->SetMinimum(-0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->SetMaximum(0.1);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->SetDirectory(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->SetStats(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->SetLineWidth(2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->SetMarkerStyle(0);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetXaxis()->SetRange(0,101);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp73250);
   
   grae->Draw("p1");
   Double_t xAxis171[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201 = new TH1F("wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201","w_eta",4, xAxis171);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetBinContent(5,-0.01776053);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetBinError(1,0.01466777);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetBinError(2,0.01572998);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetBinError(3,0.01879191);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetBinError(4,0.03426755);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetBinError(5,0.03426755);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetMinimum(-0.1);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetMaximum(0.1);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetEntries(10);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetDirectory(0);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetLineColor(ci);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetMarkerColor(ci);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->SetMarkerStyle(0);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetXaxis()->SetRange(1,4);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetXaxis()->SetNdivisions(4);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetXaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetXaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetYaxis()->SetTitle("Diff.");
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetYaxis()->SetNdivisions(505);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetYaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetYaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetZaxis()->SetLabelFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->GetZaxis()->SetTitleFont(132);
   wj_asymm_eta_fewz_8TeV_400_1001_0diffcomp0_copy__201->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
