void wj_etaj_8TeV_log_logx()
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
   
   TH1F *__93 = new TH1F("__93","",1,0,1);
   __93->SetDirectory(0);
   __93->SetStats(0);
   __93->SetFillStyle(0);
   __93->SetLineWidth(2);
   __93->SetMarkerStyle(0);
   __93->GetXaxis()->SetNdivisions(4);
   __93->GetXaxis()->SetLabelFont(132);
   __93->GetXaxis()->SetLabelOffset(999);
   __93->GetXaxis()->SetLabelSize(0);
   __93->GetXaxis()->SetTitleSize(0.06);
   __93->GetXaxis()->SetTitleFont(132);
   __93->GetYaxis()->SetTitle("Ratio");
   __93->GetYaxis()->CenterTitle(true);
   __93->GetYaxis()->SetLabelFont(132);
   __93->GetYaxis()->SetLabelOffset(999);
   __93->GetYaxis()->SetLabelSize(0.05);
   __93->GetYaxis()->SetTitleSize(0.06);
   __93->GetYaxis()->SetTitleFont(132);
   __93->GetZaxis()->SetLabelFont(132);
   __93->GetZaxis()->SetLabelSize(0.05);
   __93->GetZaxis()->SetTitleSize(0.06);
   __93->GetZaxis()->SetTitleFont(132);
   __93->Draw("");
   
   TH1F *_copy__94 = new TH1F("_copy__94","",1,0,1);
   _copy__94->SetDirectory(0);
   _copy__94->SetStats(0);
   _copy__94->SetFillStyle(0);
   _copy__94->SetLineWidth(2);
   _copy__94->SetMarkerStyle(0);
   _copy__94->GetXaxis()->SetNdivisions(4);
   _copy__94->GetXaxis()->SetLabelFont(132);
   _copy__94->GetXaxis()->SetLabelOffset(999);
   _copy__94->GetXaxis()->SetLabelSize(0);
   _copy__94->GetXaxis()->SetTitleSize(0.06);
   _copy__94->GetXaxis()->SetTitleFont(132);
   _copy__94->GetYaxis()->SetTitle("Ratio");
   _copy__94->GetYaxis()->CenterTitle(true);
   _copy__94->GetYaxis()->SetLabelFont(132);
   _copy__94->GetYaxis()->SetLabelOffset(999);
   _copy__94->GetYaxis()->SetLabelSize(0.05);
   _copy__94->GetYaxis()->SetTitleSize(0.06);
   _copy__94->GetYaxis()->SetTitleFont(132);
   _copy__94->GetZaxis()->SetLabelFont(132);
   _copy__94->GetZaxis()->SetLabelSize(0.05);
   _copy__94->GetZaxis()->SetTitleSize(0.06);
   _copy__94->GetZaxis()->SetTitleFont(132);
   _copy__94->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(0.2938848,-6.722716,0.6405842,2.35708);
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
   Double_t xAxis77[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_toterr__95 = new TH1F("wp_etaj_toterr__95","wp_etaj",4, xAxis77);
   wp_etaj_toterr__95->SetBinContent(1,48.4905);
   wp_etaj_toterr__95->SetBinContent(2,35.86988);
   wp_etaj_toterr__95->SetBinContent(3,21.33691);
   wp_etaj_toterr__95->SetBinContent(4,8.08127);
   wp_etaj_toterr__95->SetBinContent(5,4.040633);
   wp_etaj_toterr__95->SetBinError(1,4.411155);
   wp_etaj_toterr__95->SetBinError(2,3.103339);
   wp_etaj_toterr__95->SetBinError(3,1.964878);
   wp_etaj_toterr__95->SetBinError(4,1.063724);
   wp_etaj_toterr__95->SetBinError(5,0.5318616);
   wp_etaj_toterr__95->SetMinimum(0.001);
   wp_etaj_toterr__95->SetMaximum(80);
   wp_etaj_toterr__95->SetEntries(10);
   wp_etaj_toterr__95->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__95->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__95->SetLineColor(ci);
   wp_etaj_toterr__95->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__95->SetMarkerColor(ci);
   wp_etaj_toterr__95->SetMarkerStyle(0);
   wp_etaj_toterr__95->GetXaxis()->SetNdivisions(404);
   wp_etaj_toterr__95->GetXaxis()->SetLabelFont(132);
   wp_etaj_toterr__95->GetXaxis()->SetLabelOffset(999);
   wp_etaj_toterr__95->GetXaxis()->SetLabelSize(0);
   wp_etaj_toterr__95->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__95->GetXaxis()->SetTitleFont(132);
   wp_etaj_toterr__95->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_toterr__95->GetYaxis()->SetLabelFont(132);
   wp_etaj_toterr__95->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__95->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__95->GetYaxis()->SetTitleFont(132);
   wp_etaj_toterr__95->GetZaxis()->SetLabelFont(132);
   wp_etaj_toterr__95->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__95->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__95->GetZaxis()->SetTitleFont(132);
   wp_etaj_toterr__95->Draw("e2");
   Double_t xAxis78[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_staterr__96 = new TH1F("wp_etaj_staterr__96","wp_etaj",4, xAxis78);
   wp_etaj_staterr__96->SetBinContent(1,48.4905);
   wp_etaj_staterr__96->SetBinContent(2,35.86988);
   wp_etaj_staterr__96->SetBinContent(3,21.33691);
   wp_etaj_staterr__96->SetBinContent(4,8.08127);
   wp_etaj_staterr__96->SetBinContent(5,4.040633);
   wp_etaj_staterr__96->SetBinError(1,0.2913562);
   wp_etaj_staterr__96->SetBinError(2,0.2625);
   wp_etaj_staterr__96->SetBinError(3,0.2016292);
   wp_etaj_staterr__96->SetBinError(4,0.1160552);
   wp_etaj_staterr__96->SetBinError(5,0.05802755);
   wp_etaj_staterr__96->SetMinimum(0.001);
   wp_etaj_staterr__96->SetMaximum(80);
   wp_etaj_staterr__96->SetEntries(10);
   wp_etaj_staterr__96->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__96->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__96->SetLineColor(ci);
   wp_etaj_staterr__96->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__96->SetMarkerColor(ci);
   wp_etaj_staterr__96->SetMarkerStyle(0);
   wp_etaj_staterr__96->GetXaxis()->SetNdivisions(404);
   wp_etaj_staterr__96->GetXaxis()->SetLabelFont(132);
   wp_etaj_staterr__96->GetXaxis()->SetLabelOffset(999);
   wp_etaj_staterr__96->GetXaxis()->SetLabelSize(0);
   wp_etaj_staterr__96->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__96->GetXaxis()->SetTitleFont(132);
   wp_etaj_staterr__96->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_staterr__96->GetYaxis()->SetLabelFont(132);
   wp_etaj_staterr__96->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__96->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__96->GetYaxis()->SetTitleFont(132);
   wp_etaj_staterr__96->GetZaxis()->SetLabelFont(132);
   wp_etaj_staterr__96->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__96->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__96->GetZaxis()->SetTitleFont(132);
   wp_etaj_staterr__96->Draw("e2same");
   Double_t xAxis79[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_toterr__97 = new TH1F("wm_etaj_toterr__97","wm_etaj",4, xAxis79);
   wm_etaj_toterr__97->SetBinContent(1,30.50039);
   wm_etaj_toterr__97->SetBinContent(2,20.57146);
   wm_etaj_toterr__97->SetBinContent(3,11.20298);
   wm_etaj_toterr__97->SetBinContent(4,3.930728);
   wm_etaj_toterr__97->SetBinContent(5,1.965363);
   wm_etaj_toterr__97->SetBinError(1,3.140994);
   wm_etaj_toterr__97->SetBinError(2,2.204208);
   wm_etaj_toterr__97->SetBinError(3,1.339208);
   wm_etaj_toterr__97->SetBinError(4,0.6610862);
   wm_etaj_toterr__97->SetBinError(5,0.3305429);
   wm_etaj_toterr__97->SetMinimum(0.001);
   wm_etaj_toterr__97->SetMaximum(80);
   wm_etaj_toterr__97->SetEntries(10);
   wm_etaj_toterr__97->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__97->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__97->SetLineColor(ci);
   wm_etaj_toterr__97->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__97->SetMarkerColor(ci);
   wm_etaj_toterr__97->SetMarkerStyle(0);
   wm_etaj_toterr__97->GetXaxis()->SetNdivisions(404);
   wm_etaj_toterr__97->GetXaxis()->SetLabelFont(132);
   wm_etaj_toterr__97->GetXaxis()->SetLabelOffset(999);
   wm_etaj_toterr__97->GetXaxis()->SetLabelSize(0);
   wm_etaj_toterr__97->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__97->GetXaxis()->SetTitleFont(132);
   wm_etaj_toterr__97->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wm_etaj_toterr__97->GetYaxis()->SetLabelFont(132);
   wm_etaj_toterr__97->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__97->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__97->GetYaxis()->SetTitleFont(132);
   wm_etaj_toterr__97->GetZaxis()->SetLabelFont(132);
   wm_etaj_toterr__97->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__97->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__97->GetZaxis()->SetTitleFont(132);
   wm_etaj_toterr__97->Draw("e2same");
   Double_t xAxis80[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_staterr__98 = new TH1F("wm_etaj_staterr__98","wm_etaj",4, xAxis80);
   wm_etaj_staterr__98->SetBinContent(1,30.50039);
   wm_etaj_staterr__98->SetBinContent(2,20.57146);
   wm_etaj_staterr__98->SetBinContent(3,11.20298);
   wm_etaj_staterr__98->SetBinContent(4,3.930728);
   wm_etaj_staterr__98->SetBinContent(5,1.965363);
   wm_etaj_staterr__98->SetBinError(1,0.2315095);
   wm_etaj_staterr__98->SetBinError(2,0.1981347);
   wm_etaj_staterr__98->SetBinError(3,0.1458553);
   wm_etaj_staterr__98->SetBinError(4,0.08079061);
   wm_etaj_staterr__98->SetBinError(5,0.04039529);
   wm_etaj_staterr__98->SetMinimum(0.001);
   wm_etaj_staterr__98->SetMaximum(80);
   wm_etaj_staterr__98->SetEntries(10);
   wm_etaj_staterr__98->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__98->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__98->SetLineColor(ci);
   wm_etaj_staterr__98->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__98->SetMarkerColor(ci);
   wm_etaj_staterr__98->SetMarkerStyle(0);
   wm_etaj_staterr__98->GetXaxis()->SetNdivisions(404);
   wm_etaj_staterr__98->GetXaxis()->SetLabelFont(132);
   wm_etaj_staterr__98->GetXaxis()->SetLabelOffset(999);
   wm_etaj_staterr__98->GetXaxis()->SetLabelSize(0);
   wm_etaj_staterr__98->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__98->GetXaxis()->SetTitleFont(132);
   wm_etaj_staterr__98->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wm_etaj_staterr__98->GetYaxis()->SetLabelFont(132);
   wm_etaj_staterr__98->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__98->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__98->GetYaxis()->SetTitleFont(132);
   wm_etaj_staterr__98->GetZaxis()->SetLabelFont(132);
   wm_etaj_staterr__98->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__98->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__98->GetZaxis()->SetTitleFont(132);
   wm_etaj_staterr__98->Draw("e2same");
   
   Double_t etaj_plus_toterrs_fx3113[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_plus_toterrs_fy3113[4] = {
   51.28224,
   38.08475,
   22.54357,
   9.721132};
   Double_t etaj_plus_toterrs_felx3113[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fely3113[4] = {
   4.135599,
   2.864222,
   1.897241,
   1.171681};
   Double_t etaj_plus_toterrs_fehx3113[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fehy3113[4] = {
   3.726354,
   2.706163,
   1.524886,
   1.41675};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,etaj_plus_toterrs_fx3113,etaj_plus_toterrs_fy3113,etaj_plus_toterrs_felx3113,etaj_plus_toterrs_fehx3113,etaj_plus_toterrs_fely3113,etaj_plus_toterrs_fehy3113);
   grae->SetName("etaj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113 = new TH1F("Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113","",100,2.375,4.175);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->SetMaximum(80);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->SetDirectory(0);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->SetStats(0);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->SetLineWidth(2);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetXaxis()->SetNdivisions(404);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_etaj_plus_toterrs3057308130973113);
   
   grae->Draw("p1p");
   
   Double_t etaj_plus_toterrs_fx3114[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_plus_toterrs_fy3114[4] = {
   52.81753,
   39.16372,
   22.80511,
   9.659266};
   Double_t etaj_plus_toterrs_felx3114[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fely3114[4] = {
   4.306575,
   3.058371,
   1.708201,
   0.8035311};
   Double_t etaj_plus_toterrs_fehx3114[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fehy3114[4] = {
   4.54964,
   3.141914,
   1.795995,
   0.9815417};
   grae = new TGraphAsymmErrors(4,etaj_plus_toterrs_fx3114,etaj_plus_toterrs_fy3114,etaj_plus_toterrs_felx3114,etaj_plus_toterrs_fehx3114,etaj_plus_toterrs_fely3114,etaj_plus_toterrs_fehy3114);
   grae->SetName("etaj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114 = new TH1F("Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114","",100,2.225,4.025);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->SetMaximum(80);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->SetDirectory(0);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->SetStats(0);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->SetLineWidth(2);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetXaxis()->SetNdivisions(404);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_etaj_plus_toterrs3059308230983114);
   
   grae->Draw("p1p");
   
   Double_t etaj_minus_toterrs_fx3115[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_minus_toterrs_fy3115[4] = {
   33.75167,
   23.54495,
   13.13125,
   5.618726};
   Double_t etaj_minus_toterrs_felx3115[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fely3115[4] = {
   3.331792,
   2.081235,
   1.468378,
   0.5957157};
   Double_t etaj_minus_toterrs_fehx3115[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fehy3115[4] = {
   2.655911,
   1.820553,
   0.9805522,
   0.8736437};
   grae = new TGraphAsymmErrors(4,etaj_minus_toterrs_fx3115,etaj_minus_toterrs_fy3115,etaj_minus_toterrs_felx3115,etaj_minus_toterrs_fehx3115,etaj_minus_toterrs_fely3115,etaj_minus_toterrs_fehy3115);
   grae->SetName("etaj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115 = new TH1F("Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115","",100,2.375,4.175);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->SetMaximum(80);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->SetDirectory(0);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->SetStats(0);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->SetLineWidth(2);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetXaxis()->SetNdivisions(404);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_etaj_minus_toterrs3069308330993115);
   
   grae->Draw("p1p");
   
   Double_t etaj_minus_toterrs_fx3116[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_minus_toterrs_fy3116[4] = {
   34.25415,
   23.32036,
   12.9946,
   5.344251};
   Double_t etaj_minus_toterrs_felx3116[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fely3116[4] = {
   2.822029,
   1.901017,
   1.140151,
   0.5488711};
   Double_t etaj_minus_toterrs_fehx3116[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fehy3116[4] = {
   2.930556,
   2.008099,
   1.186782,
   0.6439278};
   grae = new TGraphAsymmErrors(4,etaj_minus_toterrs_fx3116,etaj_minus_toterrs_fy3116,etaj_minus_toterrs_felx3116,etaj_minus_toterrs_fehx3116,etaj_minus_toterrs_fely3116,etaj_minus_toterrs_fehy3116);
   grae->SetName("etaj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116 = new TH1F("Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116","",100,2.225,4.025);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->SetMaximum(80);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->SetDirectory(0);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->SetStats(0);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->SetLineWidth(2);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetXaxis()->SetNdivisions(404);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_etaj_minus_toterrs3071308431003116);
   
   grae->Draw("p1p");
   
   Double_t _fx3117[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3117[4] = {
   51.28224,
   38.08475,
   22.54357,
   9.721132};
   Double_t _felx3117[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3117[4] = {
   2.936905,
   2.066395,
   1.139271,
   0.5043745};
   Double_t _fehx3117[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3117[4] = {
   2.927589,
   2.099415,
   1.044388,
   0.5327406};
   grae = new TGraphAsymmErrors(4,_fx3117,_fy3117,_felx3117,_fehx3117,_fely3117,_fehy3117);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3058308531013117 = new TH1F("Graph_Graph_Graph_Graph_Graph3058308531013117","",100,2.375,4.175);
   Graph_Graph_Graph_Graph_Graph3058308531013117->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_Graph3058308531013117->SetMaximum(80);
   Graph_Graph_Graph_Graph_Graph3058308531013117->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3058308531013117->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3058308531013117->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3058308531013117->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetXaxis()->SetNdivisions(404);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3058308531013117->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3058308531013117);
   
   grae->Draw("p1p");
   
   Double_t _fx3118[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3118[4] = {
   52.81753,
   39.16372,
   22.80511,
   9.659266};
   Double_t _felx3118[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3118[4] = {
   3.452812,
   2.405918,
   1.347227,
   0.5864553};
   Double_t _fehx3118[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3118[4] = {
   3.75058,
   2.558147,
   1.433882,
   0.6369553};
   grae = new TGraphAsymmErrors(4,_fx3118,_fy3118,_felx3118,_fehx3118,_fely3118,_fehy3118);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3060308631023118 = new TH1F("Graph_Graph_Graph_Graph_Graph3060308631023118","",100,2.225,4.025);
   Graph_Graph_Graph_Graph_Graph3060308631023118->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_Graph3060308631023118->SetMaximum(80);
   Graph_Graph_Graph_Graph_Graph3060308631023118->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3060308631023118->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3060308631023118->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3060308631023118->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetXaxis()->SetNdivisions(404);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3060308631023118->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3060308631023118);
   
   grae->Draw("p1p");
   
   Double_t _fx3119[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3119[4] = {
   33.75167,
   23.54495,
   13.13125,
   5.618726};
   Double_t _felx3119[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3119[4] = {
   1.953403,
   1.325998,
   0.668684,
   0.29035};
   Double_t _fehx3119[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3119[4] = {
   1.972477,
   1.306662,
   0.6129732,
   0.3088737};
   grae = new TGraphAsymmErrors(4,_fx3119,_fy3119,_felx3119,_fehx3119,_fely3119,_fehy3119);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3070308731033119 = new TH1F("Graph_Graph_Graph_Graph_Graph3070308731033119","",100,2.375,4.175);
   Graph_Graph_Graph_Graph_Graph3070308731033119->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_Graph3070308731033119->SetMaximum(80);
   Graph_Graph_Graph_Graph_Graph3070308731033119->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3070308731033119->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3070308731033119->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3070308731033119->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetXaxis()->SetNdivisions(404);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3070308731033119->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3070308731033119);
   
   grae->Draw("p1p");
   
   Double_t _fx3120[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3120[4] = {
   34.25415,
   23.32036,
   12.9946,
   5.344251};
   Double_t _felx3120[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3120[4] = {
   2.132698,
   1.400249,
   0.7785425,
   0.3408947};
   Double_t _fehx3120[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3120[4] = {
   2.256241,
   1.482401,
   0.844492,
   0.3783941};
   grae = new TGraphAsymmErrors(4,_fx3120,_fy3120,_felx3120,_fehx3120,_fely3120,_fehy3120);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3072308831043120 = new TH1F("Graph_Graph_Graph_Graph_Graph3072308831043120","",100,2.225,4.025);
   Graph_Graph_Graph_Graph_Graph3072308831043120->SetMinimum(0.001);
   Graph_Graph_Graph_Graph_Graph3072308831043120->SetMaximum(80);
   Graph_Graph_Graph_Graph_Graph3072308831043120->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3072308831043120->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3072308831043120->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3072308831043120->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetXaxis()->SetNdivisions(404);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3072308831043120->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3072308831043120);
   
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
   Double_t xAxis81[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_toterr_copy__99 = new TH1F("wp_etaj_toterr_copy__99","wp_etaj",4, xAxis81);
   wp_etaj_toterr_copy__99->SetBinContent(1,48.4905);
   wp_etaj_toterr_copy__99->SetBinContent(2,35.86988);
   wp_etaj_toterr_copy__99->SetBinContent(3,21.33691);
   wp_etaj_toterr_copy__99->SetBinContent(4,8.08127);
   wp_etaj_toterr_copy__99->SetBinContent(5,4.040633);
   wp_etaj_toterr_copy__99->SetBinError(1,4.411155);
   wp_etaj_toterr_copy__99->SetBinError(2,3.103339);
   wp_etaj_toterr_copy__99->SetBinError(3,1.964878);
   wp_etaj_toterr_copy__99->SetBinError(4,1.063724);
   wp_etaj_toterr_copy__99->SetBinError(5,0.5318616);
   wp_etaj_toterr_copy__99->SetMinimum(0.001);
   wp_etaj_toterr_copy__99->SetMaximum(80);
   wp_etaj_toterr_copy__99->SetEntries(10);
   wp_etaj_toterr_copy__99->SetDirectory(0);
   wp_etaj_toterr_copy__99->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__99->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__99->SetLineColor(ci);
   wp_etaj_toterr_copy__99->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__99->SetMarkerColor(ci);
   wp_etaj_toterr_copy__99->SetMarkerStyle(0);
   wp_etaj_toterr_copy__99->GetXaxis()->SetNdivisions(404);
   wp_etaj_toterr_copy__99->GetXaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__99->GetXaxis()->SetLabelOffset(999);
   wp_etaj_toterr_copy__99->GetXaxis()->SetLabelSize(0);
   wp_etaj_toterr_copy__99->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__99->GetXaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__99->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_toterr_copy__99->GetYaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__99->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__99->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__99->GetYaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__99->GetZaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__99->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__99->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__99->GetZaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__99->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(0.2938848,-0.4062964,0.6405842,6.852964);
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
   Double_t xAxis82[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100 = new TH1F("wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100","wm_etaj",4, xAxis82);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinContent(1,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinContent(2,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinContent(3,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinContent(4,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinContent(5,1.965363);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinError(1,0.1029821);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinError(2,0.1071488);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinError(3,0.1195403);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinError(4,0.1681842);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetBinError(5,0.3305429);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetMinimum(0.61);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetMaximum(1.59);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetEntries(14);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetLineColor(ci);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetMarkerColor(ci);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->SetMarkerStyle(0);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0__100->Draw("e2");
   Double_t xAxis83[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101 = new TH1F("wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101","wm_etaj",4, xAxis83);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinContent(1,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinContent(2,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinContent(3,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinContent(4,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinContent(5,1.965363);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinError(1,0.007590379);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinError(2,0.009631532);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinError(3,0.01301933);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinError(4,0.0205536);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetBinError(5,0.04039529);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetMinimum(0.61);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetMaximum(1.59);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetEntries(14);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetLineColor(ci);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetMarkerColor(ci);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->SetMarkerStyle(0);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp1__101->Draw("e2same");
   
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fx3121[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fy3121[4] = {
   1.106598,
   1.144544,
   1.172121,
   1.429436};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_felx3121[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fely3121[4] = {
   0.1092377,
   0.101171,
   0.1310702,
   0.1515535};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fehx3121[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fehy3121[4] = {
   0.08707793,
   0.08849896,
   0.08752599,
   0.22226};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fx3121,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fy3121,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_felx3121,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fehx3121,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fely3121,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2_fehy3121);
   grae->SetName("wj_etaj_8TeV_log_logx_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121 = new TH1F("Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->SetStats(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp23121);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fx3122[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fy3122[4] = {
   1.123073,
   1.133627,
   1.159923,
   1.359608};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_felx3122[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fely3122[4] = {
   0.09252438,
   0.09241037,
   0.1017721,
   0.139636};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fehx3122[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fehy3122[4] = {
   0.09608259,
   0.09761576,
   0.1059344,
   0.163819};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fx3122,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fy3122,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_felx3122,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fehx3122,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fely3122,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3_fehy3122);
   grae->SetName("wj_etaj_8TeV_log_logx_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122 = new TH1F("Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->SetStats(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp33122);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fx3123[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fy3123[4] = {
   1.106598,
   1.144544,
   1.172121,
   1.429436};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_felx3123[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fely3123[4] = {
   0.0640452,
   0.06445814,
   0.05968803,
   0.07386671};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fehx3123[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fehy3123[4] = {
   0.06467055,
   0.06351816,
   0.05471517,
   0.07857924};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fx3123,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fy3123,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_felx3123,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fehx3123,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fely3123,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4_fehy3123);
   grae->SetName("wj_etaj_8TeV_log_logx_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123 = new TH1F("Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->SetStats(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp43123);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fx3124[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fy3124[4] = {
   1.123073,
   1.133627,
   1.159923,
   1.359608};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_felx3124[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fely3124[4] = {
   0.06992364,
   0.06806756,
   0.06949421,
   0.08672558};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fehx3124[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fehy3124[4] = {
   0.07397417,
   0.07206103,
   0.07538099,
   0.09626566};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fx3124,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fy3124,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_felx3124,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fehx3124,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fely3124,wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5_fehy3124);
   grae->SetName("wj_etaj_8TeV_log_logx_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124 = new TH1F("Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->SetStats(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_logx_870_1001_2ratiocomp53124);
   
   grae->Draw("p1");
   Double_t xAxis84[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102 = new TH1F("wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102","wm_etaj",4, xAxis84);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinContent(1,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinContent(2,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinContent(3,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinContent(4,1);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinContent(5,1.965363);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinError(1,0.1029821);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinError(2,0.1071488);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinError(3,0.1195403);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinError(4,0.1681842);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetBinError(5,0.3305429);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetMinimum(0.61);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetMaximum(1.59);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetEntries(14);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetDirectory(0);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetLineColor(ci);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetMarkerColor(ci);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->SetMarkerStyle(0);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_870_1001_2ratiocomp0_copy__102->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: middlPad
   TPad *middlPad = new TPad("middlPad", "middlPad",0.005,0.05,0.995,0.995);
   middlPad->Draw();
   middlPad->cd();
   middlPad->Range(0.2938848,-1.214827,0.6405842,5.543792);
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
   Double_t xAxis85[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103 = new TH1F("wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103","wp_etaj",4, xAxis85);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinContent(1,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinContent(2,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinContent(3,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinContent(4,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinContent(5,4.040633);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinError(1,0.09096947);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinError(2,0.08651658);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinError(3,0.09208823);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinError(4,0.1316283);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetBinError(5,0.5318616);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetMinimum(0.61);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetMaximum(1.59);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetEntries(14);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetLineColor(ci);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetMarkerColor(ci);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->SetMarkerStyle(0);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0__103->Draw("e2");
   Double_t xAxis86[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104 = new TH1F("wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104","wp_etaj",4, xAxis86);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinContent(1,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinContent(2,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinContent(3,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinContent(4,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinContent(5,4.040633);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinError(1,0.006008522);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinError(2,0.007318117);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinError(3,0.009449783);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinError(4,0.014361);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetBinError(5,0.05802755);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetMinimum(0.61);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetMaximum(1.59);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetEntries(14);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetLineColor(ci);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetMarkerColor(ci);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->SetMarkerStyle(0);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp1__104->Draw("e2same");
   
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fx3125[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fy3125[4] = {
   1.057573,
   1.061747,
   1.056553,
   1.202921};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_felx3125[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fely3125[4] = {
   0.0852868,
   0.07985034,
   0.08891828,
   0.1449872};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fehx3125[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fehy3125[4] = {
   0.0768471,
   0.07544389,
   0.07146708,
   0.1753128};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fx3125,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fy3125,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_felx3125,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fehx3125,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fely3125,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2_fehy3125);
   grae->SetName("wj_etaj_8TeV_log_logx_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125 = new TH1F("Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->SetStats(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp23125);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fx3126[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fy3126[4] = {
   1.089235,
   1.091828,
   1.06881,
   1.195266};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_felx3126[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fely3126[4] = {
   0.08881276,
   0.08526295,
   0.0800585,
   0.09943128};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fehx3126[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fehy3126[4] = {
   0.09382539,
   0.08759198,
   0.08417318,
   0.1214588};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fx3126,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fy3126,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_felx3126,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fehx3126,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fely3126,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3_fehy3126);
   grae->SetName("wj_etaj_8TeV_log_logx_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126 = new TH1F("Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->SetStats(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp33126);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fx3127[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fy3127[4] = {
   1.057573,
   1.061747,
   1.056553,
   1.202921};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_felx3127[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fely3127[4] = {
   0.06056661,
   0.05760808,
   0.05339437,
   0.06241278};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fehx3127[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fehy3127[4] = {
   0.0603745,
   0.05852863,
   0.04894748,
   0.06592288};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fx3127,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fy3127,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_felx3127,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fehx3127,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fely3127,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4_fehy3127);
   grae->SetName("wj_etaj_8TeV_log_logx_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127 = new TH1F("Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->SetStats(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp43127);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fx3128[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fy3128[4] = {
   1.089235,
   1.091828,
   1.06881,
   1.195266};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_felx3128[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fely3128[4] = {
   0.07120596,
   0.0670735,
   0.06314069,
   0.0725697};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fehx3128[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fehy3128[4] = {
   0.0773467,
   0.07131743,
   0.06720195,
   0.07881871};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fx3128,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fy3128,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_felx3128,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fehx3128,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fely3128,wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5_fehy3128);
   grae->SetName("wj_etaj_8TeV_log_logx_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128 = new TH1F("Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->SetDirectory(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->SetStats(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->SetLineWidth(2);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_log_logx_400_1001_0ratiocomp53128);
   
   grae->Draw("p1");
   Double_t xAxis87[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105 = new TH1F("wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105","wp_etaj",4, xAxis87);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinContent(1,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinContent(2,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinContent(3,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinContent(4,1);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinContent(5,4.040633);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinError(1,0.09096947);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinError(2,0.08651658);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinError(3,0.09208823);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinError(4,0.1316283);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetBinError(5,0.5318616);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetMinimum(0.61);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetMaximum(1.59);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetEntries(14);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetDirectory(0);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetLineColor(ci);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetMarkerColor(ci);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->SetMarkerStyle(0);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_log_logx_400_1001_0ratiocomp0_copy__105->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
