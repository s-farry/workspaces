void wj_etaj_8TeV()
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
   
   TH1F *__67 = new TH1F("__67","",1,0,1);
   __67->SetDirectory(0);
   __67->SetStats(0);
   __67->SetFillStyle(0);
   __67->SetLineWidth(2);
   __67->SetMarkerStyle(0);
   __67->GetXaxis()->SetNdivisions(4);
   __67->GetXaxis()->SetLabelFont(132);
   __67->GetXaxis()->SetLabelOffset(999);
   __67->GetXaxis()->SetLabelSize(0);
   __67->GetXaxis()->SetTitleSize(0.06);
   __67->GetXaxis()->SetTitleFont(132);
   __67->GetYaxis()->SetTitle("Ratio");
   __67->GetYaxis()->CenterTitle(true);
   __67->GetYaxis()->SetLabelFont(132);
   __67->GetYaxis()->SetLabelOffset(999);
   __67->GetYaxis()->SetLabelSize(0.05);
   __67->GetYaxis()->SetTitleSize(0.06);
   __67->GetYaxis()->SetTitleFont(132);
   __67->GetZaxis()->SetLabelFont(132);
   __67->GetZaxis()->SetLabelSize(0.05);
   __67->GetZaxis()->SetTitleSize(0.06);
   __67->GetZaxis()->SetTitleFont(132);
   __67->Draw("");
   
   TH1F *_copy__68 = new TH1F("_copy__68","",1,0,1);
   _copy__68->SetDirectory(0);
   _copy__68->SetStats(0);
   _copy__68->SetFillStyle(0);
   _copy__68->SetLineWidth(2);
   _copy__68->SetMarkerStyle(0);
   _copy__68->GetXaxis()->SetNdivisions(4);
   _copy__68->GetXaxis()->SetLabelFont(132);
   _copy__68->GetXaxis()->SetLabelOffset(999);
   _copy__68->GetXaxis()->SetLabelSize(0);
   _copy__68->GetXaxis()->SetTitleSize(0.06);
   _copy__68->GetXaxis()->SetTitleFont(132);
   _copy__68->GetYaxis()->SetTitle("Ratio");
   _copy__68->GetYaxis()->CenterTitle(true);
   _copy__68->GetYaxis()->SetLabelFont(132);
   _copy__68->GetYaxis()->SetLabelOffset(999);
   _copy__68->GetYaxis()->SetLabelSize(0.05);
   _copy__68->GetYaxis()->SetTitleSize(0.06);
   _copy__68->GetYaxis()->SetTitleFont(132);
   _copy__68->GetZaxis()->SetLabelFont(132);
   _copy__68->GetZaxis()->SetLabelSize(0.05);
   _copy__68->GetZaxis()->SetTitleSize(0.06);
   _copy__68->GetZaxis()->SetTitleFont(132);
   _copy__68->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(1.854321,-60.73898,4.323457,87.40731);
   upperPad->SetFillColor(0);
   upperPad->SetFillStyle(4000);
   upperPad->SetBorderMode(0);
   upperPad->SetBorderSize(2);
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
   Double_t xAxis55[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_toterr__69 = new TH1F("wp_etaj_toterr__69","wp_etaj",4, xAxis55);
   wp_etaj_toterr__69->SetBinContent(1,48.4905);
   wp_etaj_toterr__69->SetBinContent(2,35.86988);
   wp_etaj_toterr__69->SetBinContent(3,21.33691);
   wp_etaj_toterr__69->SetBinContent(4,8.08127);
   wp_etaj_toterr__69->SetBinContent(5,4.040633);
   wp_etaj_toterr__69->SetBinError(1,4.411155);
   wp_etaj_toterr__69->SetBinError(2,3.103339);
   wp_etaj_toterr__69->SetBinError(3,1.964878);
   wp_etaj_toterr__69->SetBinError(4,1.063724);
   wp_etaj_toterr__69->SetBinError(5,0.5318616);
   wp_etaj_toterr__69->SetMinimum(0.001);
   wp_etaj_toterr__69->SetMaximum(80);
   wp_etaj_toterr__69->SetEntries(10);
   wp_etaj_toterr__69->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__69->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__69->SetLineColor(ci);
   wp_etaj_toterr__69->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__69->SetMarkerColor(ci);
   wp_etaj_toterr__69->SetMarkerStyle(0);
   wp_etaj_toterr__69->GetXaxis()->SetNdivisions(4);
   wp_etaj_toterr__69->GetXaxis()->SetLabelFont(132);
   wp_etaj_toterr__69->GetXaxis()->SetLabelOffset(999);
   wp_etaj_toterr__69->GetXaxis()->SetLabelSize(0);
   wp_etaj_toterr__69->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__69->GetXaxis()->SetTitleFont(132);
   wp_etaj_toterr__69->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_toterr__69->GetYaxis()->SetLabelFont(132);
   wp_etaj_toterr__69->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__69->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__69->GetYaxis()->SetTitleFont(132);
   wp_etaj_toterr__69->GetZaxis()->SetLabelFont(132);
   wp_etaj_toterr__69->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__69->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__69->GetZaxis()->SetTitleFont(132);
   wp_etaj_toterr__69->Draw("e2");
   Double_t xAxis56[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_staterr__70 = new TH1F("wp_etaj_staterr__70","wp_etaj",4, xAxis56);
   wp_etaj_staterr__70->SetBinContent(1,48.4905);
   wp_etaj_staterr__70->SetBinContent(2,35.86988);
   wp_etaj_staterr__70->SetBinContent(3,21.33691);
   wp_etaj_staterr__70->SetBinContent(4,8.08127);
   wp_etaj_staterr__70->SetBinContent(5,4.040633);
   wp_etaj_staterr__70->SetBinError(1,0.2913562);
   wp_etaj_staterr__70->SetBinError(2,0.2625);
   wp_etaj_staterr__70->SetBinError(3,0.2016292);
   wp_etaj_staterr__70->SetBinError(4,0.1160552);
   wp_etaj_staterr__70->SetBinError(5,0.05802755);
   wp_etaj_staterr__70->SetMinimum(0.001);
   wp_etaj_staterr__70->SetMaximum(80);
   wp_etaj_staterr__70->SetEntries(10);
   wp_etaj_staterr__70->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__70->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__70->SetLineColor(ci);
   wp_etaj_staterr__70->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__70->SetMarkerColor(ci);
   wp_etaj_staterr__70->SetMarkerStyle(0);
   wp_etaj_staterr__70->GetXaxis()->SetNdivisions(4);
   wp_etaj_staterr__70->GetXaxis()->SetLabelFont(132);
   wp_etaj_staterr__70->GetXaxis()->SetLabelOffset(999);
   wp_etaj_staterr__70->GetXaxis()->SetLabelSize(0);
   wp_etaj_staterr__70->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__70->GetXaxis()->SetTitleFont(132);
   wp_etaj_staterr__70->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_staterr__70->GetYaxis()->SetLabelFont(132);
   wp_etaj_staterr__70->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__70->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__70->GetYaxis()->SetTitleFont(132);
   wp_etaj_staterr__70->GetZaxis()->SetLabelFont(132);
   wp_etaj_staterr__70->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__70->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__70->GetZaxis()->SetTitleFont(132);
   wp_etaj_staterr__70->Draw("e2same");
   Double_t xAxis57[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_toterr__71 = new TH1F("wm_etaj_toterr__71","wm_etaj",4, xAxis57);
   wm_etaj_toterr__71->SetBinContent(1,30.50039);
   wm_etaj_toterr__71->SetBinContent(2,20.57146);
   wm_etaj_toterr__71->SetBinContent(3,11.20298);
   wm_etaj_toterr__71->SetBinContent(4,3.930728);
   wm_etaj_toterr__71->SetBinContent(5,1.965363);
   wm_etaj_toterr__71->SetBinError(1,3.140994);
   wm_etaj_toterr__71->SetBinError(2,2.204208);
   wm_etaj_toterr__71->SetBinError(3,1.339208);
   wm_etaj_toterr__71->SetBinError(4,0.6610862);
   wm_etaj_toterr__71->SetBinError(5,0.3305429);
   wm_etaj_toterr__71->SetMinimum(0.001);
   wm_etaj_toterr__71->SetMaximum(80);
   wm_etaj_toterr__71->SetEntries(10);
   wm_etaj_toterr__71->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__71->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__71->SetLineColor(ci);
   wm_etaj_toterr__71->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_etaj_toterr__71->SetMarkerColor(ci);
   wm_etaj_toterr__71->SetMarkerStyle(0);
   wm_etaj_toterr__71->GetXaxis()->SetNdivisions(4);
   wm_etaj_toterr__71->GetXaxis()->SetLabelFont(132);
   wm_etaj_toterr__71->GetXaxis()->SetLabelOffset(999);
   wm_etaj_toterr__71->GetXaxis()->SetLabelSize(0);
   wm_etaj_toterr__71->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__71->GetXaxis()->SetTitleFont(132);
   wm_etaj_toterr__71->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wm_etaj_toterr__71->GetYaxis()->SetLabelFont(132);
   wm_etaj_toterr__71->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__71->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__71->GetYaxis()->SetTitleFont(132);
   wm_etaj_toterr__71->GetZaxis()->SetLabelFont(132);
   wm_etaj_toterr__71->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__71->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__71->GetZaxis()->SetTitleFont(132);
   wm_etaj_toterr__71->Draw("e2same");
   Double_t xAxis58[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_staterr__72 = new TH1F("wm_etaj_staterr__72","wm_etaj",4, xAxis58);
   wm_etaj_staterr__72->SetBinContent(1,30.50039);
   wm_etaj_staterr__72->SetBinContent(2,20.57146);
   wm_etaj_staterr__72->SetBinContent(3,11.20298);
   wm_etaj_staterr__72->SetBinContent(4,3.930728);
   wm_etaj_staterr__72->SetBinContent(5,1.965363);
   wm_etaj_staterr__72->SetBinError(1,0.2315095);
   wm_etaj_staterr__72->SetBinError(2,0.1981347);
   wm_etaj_staterr__72->SetBinError(3,0.1458553);
   wm_etaj_staterr__72->SetBinError(4,0.08079061);
   wm_etaj_staterr__72->SetBinError(5,0.04039529);
   wm_etaj_staterr__72->SetMinimum(0.001);
   wm_etaj_staterr__72->SetMaximum(80);
   wm_etaj_staterr__72->SetEntries(10);
   wm_etaj_staterr__72->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__72->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__72->SetLineColor(ci);
   wm_etaj_staterr__72->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_etaj_staterr__72->SetMarkerColor(ci);
   wm_etaj_staterr__72->SetMarkerStyle(0);
   wm_etaj_staterr__72->GetXaxis()->SetNdivisions(4);
   wm_etaj_staterr__72->GetXaxis()->SetLabelFont(132);
   wm_etaj_staterr__72->GetXaxis()->SetLabelOffset(999);
   wm_etaj_staterr__72->GetXaxis()->SetLabelSize(0);
   wm_etaj_staterr__72->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__72->GetXaxis()->SetTitleFont(132);
   wm_etaj_staterr__72->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wm_etaj_staterr__72->GetYaxis()->SetLabelFont(132);
   wm_etaj_staterr__72->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__72->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__72->GetYaxis()->SetTitleFont(132);
   wm_etaj_staterr__72->GetZaxis()->SetLabelFont(132);
   wm_etaj_staterr__72->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__72->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__72->GetZaxis()->SetTitleFont(132);
   wm_etaj_staterr__72->Draw("e2same");
   
   Double_t etaj_plus_toterrs_fx3081[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_plus_toterrs_fy3081[4] = {
   51.28224,
   38.08475,
   22.54357,
   9.721132};
   Double_t etaj_plus_toterrs_felx3081[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fely3081[4] = {
   4.135599,
   2.864222,
   1.897241,
   1.171681};
   Double_t etaj_plus_toterrs_fehx3081[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fehy3081[4] = {
   3.726354,
   2.706163,
   1.524886,
   1.41675};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,etaj_plus_toterrs_fx3081,etaj_plus_toterrs_fy3081,etaj_plus_toterrs_felx3081,etaj_plus_toterrs_fehx3081,etaj_plus_toterrs_fely3081,etaj_plus_toterrs_fehy3081);
   grae->SetName("etaj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_etaj_plus_toterrs30573081 = new TH1F("Graph_Graph_etaj_plus_toterrs30573081","",100,2.375,4.175);
   Graph_Graph_etaj_plus_toterrs30573081->SetMinimum(0.001);
   Graph_Graph_etaj_plus_toterrs30573081->SetMaximum(80);
   Graph_Graph_etaj_plus_toterrs30573081->SetDirectory(0);
   Graph_Graph_etaj_plus_toterrs30573081->SetStats(0);
   Graph_Graph_etaj_plus_toterrs30573081->SetLineWidth(2);
   Graph_Graph_etaj_plus_toterrs30573081->SetMarkerStyle(0);
   Graph_Graph_etaj_plus_toterrs30573081->GetXaxis()->SetNdivisions(4);
   Graph_Graph_etaj_plus_toterrs30573081->GetXaxis()->SetLabelFont(132);
   Graph_Graph_etaj_plus_toterrs30573081->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_etaj_plus_toterrs30573081->GetXaxis()->SetLabelSize(0);
   Graph_Graph_etaj_plus_toterrs30573081->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_plus_toterrs30573081->GetXaxis()->SetTitleFont(132);
   Graph_Graph_etaj_plus_toterrs30573081->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_etaj_plus_toterrs30573081->GetYaxis()->SetLabelFont(132);
   Graph_Graph_etaj_plus_toterrs30573081->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_plus_toterrs30573081->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_plus_toterrs30573081->GetYaxis()->SetTitleFont(132);
   Graph_Graph_etaj_plus_toterrs30573081->GetZaxis()->SetLabelFont(132);
   Graph_Graph_etaj_plus_toterrs30573081->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_plus_toterrs30573081->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_plus_toterrs30573081->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_etaj_plus_toterrs30573081);
   
   grae->Draw("p1p");
   
   Double_t etaj_plus_toterrs_fx3082[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_plus_toterrs_fy3082[4] = {
   52.81753,
   39.16372,
   22.80511,
   9.659266};
   Double_t etaj_plus_toterrs_felx3082[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fely3082[4] = {
   4.306575,
   3.058371,
   1.708201,
   0.8035311};
   Double_t etaj_plus_toterrs_fehx3082[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fehy3082[4] = {
   4.54964,
   3.141914,
   1.795995,
   0.9815417};
   grae = new TGraphAsymmErrors(4,etaj_plus_toterrs_fx3082,etaj_plus_toterrs_fy3082,etaj_plus_toterrs_felx3082,etaj_plus_toterrs_fehx3082,etaj_plus_toterrs_fely3082,etaj_plus_toterrs_fehy3082);
   grae->SetName("etaj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_etaj_plus_toterrs30593082 = new TH1F("Graph_Graph_etaj_plus_toterrs30593082","",100,2.225,4.025);
   Graph_Graph_etaj_plus_toterrs30593082->SetMinimum(0.001);
   Graph_Graph_etaj_plus_toterrs30593082->SetMaximum(80);
   Graph_Graph_etaj_plus_toterrs30593082->SetDirectory(0);
   Graph_Graph_etaj_plus_toterrs30593082->SetStats(0);
   Graph_Graph_etaj_plus_toterrs30593082->SetLineWidth(2);
   Graph_Graph_etaj_plus_toterrs30593082->SetMarkerStyle(0);
   Graph_Graph_etaj_plus_toterrs30593082->GetXaxis()->SetNdivisions(4);
   Graph_Graph_etaj_plus_toterrs30593082->GetXaxis()->SetLabelFont(132);
   Graph_Graph_etaj_plus_toterrs30593082->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_etaj_plus_toterrs30593082->GetXaxis()->SetLabelSize(0);
   Graph_Graph_etaj_plus_toterrs30593082->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_plus_toterrs30593082->GetXaxis()->SetTitleFont(132);
   Graph_Graph_etaj_plus_toterrs30593082->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_etaj_plus_toterrs30593082->GetYaxis()->SetLabelFont(132);
   Graph_Graph_etaj_plus_toterrs30593082->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_plus_toterrs30593082->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_plus_toterrs30593082->GetYaxis()->SetTitleFont(132);
   Graph_Graph_etaj_plus_toterrs30593082->GetZaxis()->SetLabelFont(132);
   Graph_Graph_etaj_plus_toterrs30593082->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_plus_toterrs30593082->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_plus_toterrs30593082->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_etaj_plus_toterrs30593082);
   
   grae->Draw("p1p");
   
   Double_t etaj_minus_toterrs_fx3083[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_minus_toterrs_fy3083[4] = {
   33.75167,
   23.54495,
   13.13125,
   5.618726};
   Double_t etaj_minus_toterrs_felx3083[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fely3083[4] = {
   3.331792,
   2.081235,
   1.468378,
   0.5957157};
   Double_t etaj_minus_toterrs_fehx3083[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fehy3083[4] = {
   2.655911,
   1.820553,
   0.9805522,
   0.8736437};
   grae = new TGraphAsymmErrors(4,etaj_minus_toterrs_fx3083,etaj_minus_toterrs_fy3083,etaj_minus_toterrs_felx3083,etaj_minus_toterrs_fehx3083,etaj_minus_toterrs_fely3083,etaj_minus_toterrs_fehy3083);
   grae->SetName("etaj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_etaj_minus_toterrs30693083 = new TH1F("Graph_Graph_etaj_minus_toterrs30693083","",100,2.375,4.175);
   Graph_Graph_etaj_minus_toterrs30693083->SetMinimum(0.001);
   Graph_Graph_etaj_minus_toterrs30693083->SetMaximum(80);
   Graph_Graph_etaj_minus_toterrs30693083->SetDirectory(0);
   Graph_Graph_etaj_minus_toterrs30693083->SetStats(0);
   Graph_Graph_etaj_minus_toterrs30693083->SetLineWidth(2);
   Graph_Graph_etaj_minus_toterrs30693083->SetMarkerStyle(0);
   Graph_Graph_etaj_minus_toterrs30693083->GetXaxis()->SetNdivisions(4);
   Graph_Graph_etaj_minus_toterrs30693083->GetXaxis()->SetLabelFont(132);
   Graph_Graph_etaj_minus_toterrs30693083->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_etaj_minus_toterrs30693083->GetXaxis()->SetLabelSize(0);
   Graph_Graph_etaj_minus_toterrs30693083->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_minus_toterrs30693083->GetXaxis()->SetTitleFont(132);
   Graph_Graph_etaj_minus_toterrs30693083->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_etaj_minus_toterrs30693083->GetYaxis()->SetLabelFont(132);
   Graph_Graph_etaj_minus_toterrs30693083->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_minus_toterrs30693083->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_minus_toterrs30693083->GetYaxis()->SetTitleFont(132);
   Graph_Graph_etaj_minus_toterrs30693083->GetZaxis()->SetLabelFont(132);
   Graph_Graph_etaj_minus_toterrs30693083->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_minus_toterrs30693083->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_minus_toterrs30693083->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_etaj_minus_toterrs30693083);
   
   grae->Draw("p1p");
   
   Double_t etaj_minus_toterrs_fx3084[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_minus_toterrs_fy3084[4] = {
   34.25415,
   23.32036,
   12.9946,
   5.344251};
   Double_t etaj_minus_toterrs_felx3084[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fely3084[4] = {
   2.822029,
   1.901017,
   1.140151,
   0.5488711};
   Double_t etaj_minus_toterrs_fehx3084[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fehy3084[4] = {
   2.930556,
   2.008099,
   1.186782,
   0.6439278};
   grae = new TGraphAsymmErrors(4,etaj_minus_toterrs_fx3084,etaj_minus_toterrs_fy3084,etaj_minus_toterrs_felx3084,etaj_minus_toterrs_fehx3084,etaj_minus_toterrs_fely3084,etaj_minus_toterrs_fehy3084);
   grae->SetName("etaj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_etaj_minus_toterrs30713084 = new TH1F("Graph_Graph_etaj_minus_toterrs30713084","",100,2.225,4.025);
   Graph_Graph_etaj_minus_toterrs30713084->SetMinimum(0.001);
   Graph_Graph_etaj_minus_toterrs30713084->SetMaximum(80);
   Graph_Graph_etaj_minus_toterrs30713084->SetDirectory(0);
   Graph_Graph_etaj_minus_toterrs30713084->SetStats(0);
   Graph_Graph_etaj_minus_toterrs30713084->SetLineWidth(2);
   Graph_Graph_etaj_minus_toterrs30713084->SetMarkerStyle(0);
   Graph_Graph_etaj_minus_toterrs30713084->GetXaxis()->SetNdivisions(4);
   Graph_Graph_etaj_minus_toterrs30713084->GetXaxis()->SetLabelFont(132);
   Graph_Graph_etaj_minus_toterrs30713084->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_etaj_minus_toterrs30713084->GetXaxis()->SetLabelSize(0);
   Graph_Graph_etaj_minus_toterrs30713084->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_minus_toterrs30713084->GetXaxis()->SetTitleFont(132);
   Graph_Graph_etaj_minus_toterrs30713084->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_etaj_minus_toterrs30713084->GetYaxis()->SetLabelFont(132);
   Graph_Graph_etaj_minus_toterrs30713084->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_minus_toterrs30713084->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_minus_toterrs30713084->GetYaxis()->SetTitleFont(132);
   Graph_Graph_etaj_minus_toterrs30713084->GetZaxis()->SetLabelFont(132);
   Graph_Graph_etaj_minus_toterrs30713084->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_minus_toterrs30713084->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_minus_toterrs30713084->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_etaj_minus_toterrs30713084);
   
   grae->Draw("p1p");
   
   Double_t _fx3085[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3085[4] = {
   51.28224,
   38.08475,
   22.54357,
   9.721132};
   Double_t _felx3085[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3085[4] = {
   2.936905,
   2.066395,
   1.139271,
   0.5043745};
   Double_t _fehx3085[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3085[4] = {
   2.927589,
   2.099415,
   1.044388,
   0.5327406};
   grae = new TGraphAsymmErrors(4,_fx3085,_fy3085,_felx3085,_fehx3085,_fely3085,_fehy3085);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph30583085 = new TH1F("Graph_Graph_Graph30583085","",100,2.375,4.175);
   Graph_Graph_Graph30583085->SetMinimum(0.001);
   Graph_Graph_Graph30583085->SetMaximum(80);
   Graph_Graph_Graph30583085->SetDirectory(0);
   Graph_Graph_Graph30583085->SetStats(0);
   Graph_Graph_Graph30583085->SetLineWidth(2);
   Graph_Graph_Graph30583085->SetMarkerStyle(0);
   Graph_Graph_Graph30583085->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30583085->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30583085->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30583085->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30583085->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30583085->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30583085->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph30583085->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30583085->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30583085->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30583085->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30583085->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30583085->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30583085->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30583085->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30583085);
   
   grae->Draw("p1p");
   
   Double_t _fx3086[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3086[4] = {
   52.81753,
   39.16372,
   22.80511,
   9.659266};
   Double_t _felx3086[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3086[4] = {
   3.452812,
   2.405918,
   1.347227,
   0.5864553};
   Double_t _fehx3086[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3086[4] = {
   3.75058,
   2.558147,
   1.433882,
   0.6369553};
   grae = new TGraphAsymmErrors(4,_fx3086,_fy3086,_felx3086,_fehx3086,_fely3086,_fehy3086);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30603086 = new TH1F("Graph_Graph_Graph30603086","",100,2.225,4.025);
   Graph_Graph_Graph30603086->SetMinimum(0.001);
   Graph_Graph_Graph30603086->SetMaximum(80);
   Graph_Graph_Graph30603086->SetDirectory(0);
   Graph_Graph_Graph30603086->SetStats(0);
   Graph_Graph_Graph30603086->SetLineWidth(2);
   Graph_Graph_Graph30603086->SetMarkerStyle(0);
   Graph_Graph_Graph30603086->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30603086->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30603086->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30603086->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30603086->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30603086->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30603086->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph30603086->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30603086->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30603086->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30603086->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30603086->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30603086->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30603086->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30603086->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30603086);
   
   grae->Draw("p1p");
   
   Double_t _fx3087[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3087[4] = {
   33.75167,
   23.54495,
   13.13125,
   5.618726};
   Double_t _felx3087[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3087[4] = {
   1.953403,
   1.325998,
   0.668684,
   0.29035};
   Double_t _fehx3087[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3087[4] = {
   1.972477,
   1.306662,
   0.6129732,
   0.3088737};
   grae = new TGraphAsymmErrors(4,_fx3087,_fy3087,_felx3087,_fehx3087,_fely3087,_fehy3087);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph30703087 = new TH1F("Graph_Graph_Graph30703087","",100,2.375,4.175);
   Graph_Graph_Graph30703087->SetMinimum(0.001);
   Graph_Graph_Graph30703087->SetMaximum(80);
   Graph_Graph_Graph30703087->SetDirectory(0);
   Graph_Graph_Graph30703087->SetStats(0);
   Graph_Graph_Graph30703087->SetLineWidth(2);
   Graph_Graph_Graph30703087->SetMarkerStyle(0);
   Graph_Graph_Graph30703087->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30703087->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30703087->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30703087->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30703087->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30703087->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30703087->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph30703087->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30703087->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30703087->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30703087->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30703087->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30703087->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30703087->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30703087->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30703087);
   
   grae->Draw("p1p");
   
   Double_t _fx3088[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3088[4] = {
   34.25415,
   23.32036,
   12.9946,
   5.344251};
   Double_t _felx3088[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3088[4] = {
   2.132698,
   1.400249,
   0.7785425,
   0.3408947};
   Double_t _fehx3088[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3088[4] = {
   2.256241,
   1.482401,
   0.844492,
   0.3783941};
   grae = new TGraphAsymmErrors(4,_fx3088,_fy3088,_felx3088,_fehx3088,_fely3088,_fehy3088);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph30723088 = new TH1F("Graph_Graph_Graph30723088","",100,2.225,4.025);
   Graph_Graph_Graph30723088->SetMinimum(0.001);
   Graph_Graph_Graph30723088->SetMaximum(80);
   Graph_Graph_Graph30723088->SetDirectory(0);
   Graph_Graph_Graph30723088->SetStats(0);
   Graph_Graph_Graph30723088->SetLineWidth(2);
   Graph_Graph_Graph30723088->SetMarkerStyle(0);
   Graph_Graph_Graph30723088->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30723088->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30723088->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30723088->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30723088->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30723088->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30723088->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph30723088->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30723088->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30723088->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30723088->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30723088->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30723088->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30723088->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30723088->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30723088);
   
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
   Double_t xAxis59[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_toterr_copy__73 = new TH1F("wp_etaj_toterr_copy__73","wp_etaj",4, xAxis59);
   wp_etaj_toterr_copy__73->SetBinContent(1,48.4905);
   wp_etaj_toterr_copy__73->SetBinContent(2,35.86988);
   wp_etaj_toterr_copy__73->SetBinContent(3,21.33691);
   wp_etaj_toterr_copy__73->SetBinContent(4,8.08127);
   wp_etaj_toterr_copy__73->SetBinContent(5,4.040633);
   wp_etaj_toterr_copy__73->SetBinError(1,4.411155);
   wp_etaj_toterr_copy__73->SetBinError(2,3.103339);
   wp_etaj_toterr_copy__73->SetBinError(3,1.964878);
   wp_etaj_toterr_copy__73->SetBinError(4,1.063724);
   wp_etaj_toterr_copy__73->SetBinError(5,0.5318616);
   wp_etaj_toterr_copy__73->SetMinimum(0.001);
   wp_etaj_toterr_copy__73->SetMaximum(80);
   wp_etaj_toterr_copy__73->SetEntries(10);
   wp_etaj_toterr_copy__73->SetDirectory(0);
   wp_etaj_toterr_copy__73->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__73->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__73->SetLineColor(ci);
   wp_etaj_toterr_copy__73->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__73->SetMarkerColor(ci);
   wp_etaj_toterr_copy__73->SetMarkerStyle(0);
   wp_etaj_toterr_copy__73->GetXaxis()->SetNdivisions(4);
   wp_etaj_toterr_copy__73->GetXaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__73->GetXaxis()->SetLabelOffset(999);
   wp_etaj_toterr_copy__73->GetXaxis()->SetLabelSize(0);
   wp_etaj_toterr_copy__73->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__73->GetXaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__73->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_toterr_copy__73->GetYaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__73->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__73->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__73->GetYaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__73->GetZaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__73->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__73->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__73->GetZaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__73->Draw("sameaxis");
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
   Double_t xAxis60[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_870_1001_2ratiocomp0__74 = new TH1F("wj_etaj_8TeV_870_1001_2ratiocomp0__74","wm_etaj",4, xAxis60);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinContent(1,1);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinContent(2,1);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinContent(3,1);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinContent(4,1);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinContent(5,1.965363);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinError(1,0.1029821);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinError(2,0.1071488);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinError(3,0.1195403);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinError(4,0.1681842);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetBinError(5,0.3305429);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetMinimum(0.61);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetMaximum(1.59);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetEntries(14);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetLineColor(ci);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetMarkerColor(ci);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->SetMarkerStyle(0);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0__74->Draw("e2");
   Double_t xAxis61[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_870_1001_2ratiocomp1__75 = new TH1F("wj_etaj_8TeV_870_1001_2ratiocomp1__75","wm_etaj",4, xAxis61);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinContent(1,1);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinContent(2,1);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinContent(3,1);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinContent(4,1);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinContent(5,1.965363);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinError(1,0.007590379);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinError(2,0.009631532);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinError(3,0.01301933);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinError(4,0.0205536);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetBinError(5,0.04039529);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetMinimum(0.61);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetMaximum(1.59);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetEntries(14);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetLineColor(ci);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetMarkerColor(ci);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->SetMarkerStyle(0);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp1__75->Draw("e2same");
   
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp2_fx3089[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp2_fy3089[4] = {
   1.106598,
   1.144544,
   1.172121,
   1.429436};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp2_felx3089[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp2_fely3089[4] = {
   0.1092377,
   0.101171,
   0.1310702,
   0.1515535};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp2_fehx3089[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp2_fehy3089[4] = {
   0.08707793,
   0.08849896,
   0.08752599,
   0.22226};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_870_1001_2ratiocomp2_fx3089,wj_etaj_8TeV_870_1001_2ratiocomp2_fy3089,wj_etaj_8TeV_870_1001_2ratiocomp2_felx3089,wj_etaj_8TeV_870_1001_2ratiocomp2_fehx3089,wj_etaj_8TeV_870_1001_2ratiocomp2_fely3089,wj_etaj_8TeV_870_1001_2ratiocomp2_fehy3089);
   grae->SetName("wj_etaj_8TeV_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089 = new TH1F("Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->SetDirectory(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->SetStats(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->SetLineWidth(2);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_870_1001_2ratiocomp23089);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp3_fx3090[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp3_fy3090[4] = {
   1.123073,
   1.133627,
   1.159923,
   1.359608};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp3_felx3090[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp3_fely3090[4] = {
   0.09252438,
   0.09241037,
   0.1017721,
   0.139636};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp3_fehx3090[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp3_fehy3090[4] = {
   0.09608259,
   0.09761576,
   0.1059344,
   0.163819};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_870_1001_2ratiocomp3_fx3090,wj_etaj_8TeV_870_1001_2ratiocomp3_fy3090,wj_etaj_8TeV_870_1001_2ratiocomp3_felx3090,wj_etaj_8TeV_870_1001_2ratiocomp3_fehx3090,wj_etaj_8TeV_870_1001_2ratiocomp3_fely3090,wj_etaj_8TeV_870_1001_2ratiocomp3_fehy3090);
   grae->SetName("wj_etaj_8TeV_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090 = new TH1F("Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->SetDirectory(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->SetStats(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->SetLineWidth(2);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_870_1001_2ratiocomp33090);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp4_fx3091[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp4_fy3091[4] = {
   1.106598,
   1.144544,
   1.172121,
   1.429436};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp4_felx3091[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp4_fely3091[4] = {
   0.0640452,
   0.06445814,
   0.05968803,
   0.07386671};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp4_fehx3091[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp4_fehy3091[4] = {
   0.06467055,
   0.06351816,
   0.05471517,
   0.07857924};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_870_1001_2ratiocomp4_fx3091,wj_etaj_8TeV_870_1001_2ratiocomp4_fy3091,wj_etaj_8TeV_870_1001_2ratiocomp4_felx3091,wj_etaj_8TeV_870_1001_2ratiocomp4_fehx3091,wj_etaj_8TeV_870_1001_2ratiocomp4_fely3091,wj_etaj_8TeV_870_1001_2ratiocomp4_fehy3091);
   grae->SetName("wj_etaj_8TeV_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091 = new TH1F("Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->SetDirectory(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->SetStats(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->SetLineWidth(2);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_870_1001_2ratiocomp43091);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp5_fx3092[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp5_fy3092[4] = {
   1.123073,
   1.133627,
   1.159923,
   1.359608};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp5_felx3092[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp5_fely3092[4] = {
   0.06992364,
   0.06806756,
   0.06949421,
   0.08672558};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp5_fehx3092[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_870_1001_2ratiocomp5_fehy3092[4] = {
   0.07397417,
   0.07206103,
   0.07538099,
   0.09626566};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_870_1001_2ratiocomp5_fx3092,wj_etaj_8TeV_870_1001_2ratiocomp5_fy3092,wj_etaj_8TeV_870_1001_2ratiocomp5_felx3092,wj_etaj_8TeV_870_1001_2ratiocomp5_fehx3092,wj_etaj_8TeV_870_1001_2ratiocomp5_fely3092,wj_etaj_8TeV_870_1001_2ratiocomp5_fehy3092);
   grae->SetName("wj_etaj_8TeV_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092 = new TH1F("Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->SetDirectory(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->SetStats(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->SetLineWidth(2);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_870_1001_2ratiocomp53092);
   
   grae->Draw("p1");
   Double_t xAxis62[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76 = new TH1F("wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76","wm_etaj",4, xAxis62);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinContent(1,1);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinContent(2,1);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinContent(3,1);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinContent(4,1);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinContent(5,1.965363);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinError(1,0.1029821);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinError(2,0.1071488);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinError(3,0.1195403);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinError(4,0.1681842);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetBinError(5,0.3305429);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetMinimum(0.61);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetMaximum(1.59);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetEntries(14);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetDirectory(0);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetLineColor(ci);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetMarkerColor(ci);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->SetMarkerStyle(0);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetXaxis()->SetLabelOffset(0.02);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetXaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_870_1001_2ratiocomp0_copy__76->Draw("sameaxis");
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
   Double_t xAxis63[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_400_1001_0ratiocomp0__77 = new TH1F("wj_etaj_8TeV_400_1001_0ratiocomp0__77","wp_etaj",4, xAxis63);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinContent(1,1);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinContent(2,1);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinContent(3,1);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinContent(4,1);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinContent(5,4.040633);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinError(1,0.09096947);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinError(2,0.08651658);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinError(3,0.09208823);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinError(4,0.1316283);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetBinError(5,0.5318616);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetMinimum(0.61);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetMaximum(1.59);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetEntries(14);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetLineColor(ci);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetMarkerColor(ci);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->SetMarkerStyle(0);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0__77->Draw("e2");
   Double_t xAxis64[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_400_1001_0ratiocomp1__78 = new TH1F("wj_etaj_8TeV_400_1001_0ratiocomp1__78","wp_etaj",4, xAxis64);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinContent(1,1);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinContent(2,1);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinContent(3,1);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinContent(4,1);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinContent(5,4.040633);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinError(1,0.006008522);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinError(2,0.007318117);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinError(3,0.009449783);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinError(4,0.014361);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetBinError(5,0.05802755);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetMinimum(0.61);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetMaximum(1.59);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetEntries(14);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetLineColor(ci);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetMarkerColor(ci);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->SetMarkerStyle(0);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp1__78->Draw("e2same");
   
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp2_fx3093[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp2_fy3093[4] = {
   1.057573,
   1.061747,
   1.056553,
   1.202921};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp2_felx3093[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp2_fely3093[4] = {
   0.0852868,
   0.07985034,
   0.08891828,
   0.1449872};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp2_fehx3093[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp2_fehy3093[4] = {
   0.0768471,
   0.07544389,
   0.07146708,
   0.1753128};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_400_1001_0ratiocomp2_fx3093,wj_etaj_8TeV_400_1001_0ratiocomp2_fy3093,wj_etaj_8TeV_400_1001_0ratiocomp2_felx3093,wj_etaj_8TeV_400_1001_0ratiocomp2_fehx3093,wj_etaj_8TeV_400_1001_0ratiocomp2_fely3093,wj_etaj_8TeV_400_1001_0ratiocomp2_fehy3093);
   grae->SetName("wj_etaj_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093 = new TH1F("Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->SetDirectory(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->SetStats(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->SetLineWidth(2);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_400_1001_0ratiocomp23093);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp3_fx3094[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp3_fy3094[4] = {
   1.089235,
   1.091828,
   1.06881,
   1.195266};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp3_felx3094[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp3_fely3094[4] = {
   0.08881276,
   0.08526295,
   0.0800585,
   0.09943128};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp3_fehx3094[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp3_fehy3094[4] = {
   0.09382539,
   0.08759198,
   0.08417318,
   0.1214588};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_400_1001_0ratiocomp3_fx3094,wj_etaj_8TeV_400_1001_0ratiocomp3_fy3094,wj_etaj_8TeV_400_1001_0ratiocomp3_felx3094,wj_etaj_8TeV_400_1001_0ratiocomp3_fehx3094,wj_etaj_8TeV_400_1001_0ratiocomp3_fely3094,wj_etaj_8TeV_400_1001_0ratiocomp3_fehy3094);
   grae->SetName("wj_etaj_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094 = new TH1F("Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->SetDirectory(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->SetStats(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->SetLineWidth(2);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_400_1001_0ratiocomp33094);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp4_fx3095[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp4_fy3095[4] = {
   1.057573,
   1.061747,
   1.056553,
   1.202921};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp4_felx3095[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp4_fely3095[4] = {
   0.06056661,
   0.05760808,
   0.05339437,
   0.06241278};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp4_fehx3095[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp4_fehy3095[4] = {
   0.0603745,
   0.05852863,
   0.04894748,
   0.06592288};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_400_1001_0ratiocomp4_fx3095,wj_etaj_8TeV_400_1001_0ratiocomp4_fy3095,wj_etaj_8TeV_400_1001_0ratiocomp4_felx3095,wj_etaj_8TeV_400_1001_0ratiocomp4_fehx3095,wj_etaj_8TeV_400_1001_0ratiocomp4_fely3095,wj_etaj_8TeV_400_1001_0ratiocomp4_fehy3095);
   grae->SetName("wj_etaj_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095 = new TH1F("Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095","",100,2.375,4.175);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->SetDirectory(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->SetStats(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->SetLineWidth(2);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_400_1001_0ratiocomp43095);
   
   grae->Draw("p1");
   
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp5_fx3096[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp5_fy3096[4] = {
   1.089235,
   1.091828,
   1.06881,
   1.195266};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp5_felx3096[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp5_fely3096[4] = {
   0.07120596,
   0.0670735,
   0.06314069,
   0.0725697};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp5_fehx3096[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_etaj_8TeV_400_1001_0ratiocomp5_fehy3096[4] = {
   0.0773467,
   0.07131743,
   0.06720195,
   0.07881871};
   grae = new TGraphAsymmErrors(4,wj_etaj_8TeV_400_1001_0ratiocomp5_fx3096,wj_etaj_8TeV_400_1001_0ratiocomp5_fy3096,wj_etaj_8TeV_400_1001_0ratiocomp5_felx3096,wj_etaj_8TeV_400_1001_0ratiocomp5_fehx3096,wj_etaj_8TeV_400_1001_0ratiocomp5_fely3096,wj_etaj_8TeV_400_1001_0ratiocomp5_fehy3096);
   grae->SetName("wj_etaj_8TeV_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096 = new TH1F("Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096","",100,2.225,4.025);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->SetMinimum(0.61);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->SetMaximum(1.59);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->SetDirectory(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->SetStats(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->SetLineWidth(2);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->SetMarkerStyle(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetXaxis()->SetNdivisions(4);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetXaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetXaxis()->SetLabelOffset(999);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetXaxis()->SetLabelSize(0);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetXaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetYaxis()->SetNdivisions(505);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetYaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetYaxis()->SetTitleFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetZaxis()->SetLabelFont(132);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_etaj_8TeV_400_1001_0ratiocomp53096);
   
   grae->Draw("p1");
   Double_t xAxis65[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79 = new TH1F("wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79","wp_etaj",4, xAxis65);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinContent(1,1);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinContent(2,1);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinContent(3,1);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinContent(4,1);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinContent(5,4.040633);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinError(1,0.09096947);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinError(2,0.08651658);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinError(3,0.09208823);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinError(4,0.1316283);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetBinError(5,0.5318616);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetMinimum(0.61);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetMaximum(1.59);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetEntries(14);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetDirectory(0);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetLineColor(ci);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetMarkerColor(ci);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->SetMarkerStyle(0);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetXaxis()->SetNdivisions(4);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetXaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetXaxis()->SetLabelOffset(999);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetXaxis()->SetLabelSize(0);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetXaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetXaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetYaxis()->SetNdivisions(505);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetYaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetYaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetYaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetYaxis()->SetTickLength(0.12325);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetYaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetZaxis()->SetLabelFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetZaxis()->SetLabelSize(0.05);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetZaxis()->SetTitleSize(0.06);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->GetZaxis()->SetTitleFont(132);
   wj_etaj_8TeV_400_1001_0ratiocomp0_copy__79->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
