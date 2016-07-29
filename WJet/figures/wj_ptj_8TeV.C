void wj_ptj_8TeV()
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
   
   TH1F *__106 = new TH1F("__106","",1,0,1);
   __106->SetDirectory(0);
   __106->SetStats(0);
   __106->SetFillStyle(0);
   __106->SetLineWidth(2);
   __106->SetMarkerStyle(0);
   __106->GetXaxis()->SetNdivisions(4);
   __106->GetXaxis()->SetLabelFont(132);
   __106->GetXaxis()->SetLabelOffset(999);
   __106->GetXaxis()->SetLabelSize(0);
   __106->GetXaxis()->SetTitleSize(0.06);
   __106->GetXaxis()->SetTitleFont(132);
   __106->GetYaxis()->SetTitle("Ratio");
   __106->GetYaxis()->CenterTitle(true);
   __106->GetYaxis()->SetLabelFont(132);
   __106->GetYaxis()->SetLabelOffset(999);
   __106->GetYaxis()->SetLabelSize(0.05);
   __106->GetYaxis()->SetTitleSize(0.06);
   __106->GetYaxis()->SetTitleFont(132);
   __106->GetZaxis()->SetLabelFont(132);
   __106->GetZaxis()->SetLabelSize(0.05);
   __106->GetZaxis()->SetTitleSize(0.06);
   __106->GetZaxis()->SetTitleFont(132);
   __106->Draw("");
   
   TH1F *_copy__107 = new TH1F("_copy__107","",1,0,1);
   _copy__107->SetDirectory(0);
   _copy__107->SetStats(0);
   _copy__107->SetFillStyle(0);
   _copy__107->SetLineWidth(2);
   _copy__107->SetMarkerStyle(0);
   _copy__107->GetXaxis()->SetNdivisions(4);
   _copy__107->GetXaxis()->SetLabelFont(132);
   _copy__107->GetXaxis()->SetLabelOffset(999);
   _copy__107->GetXaxis()->SetLabelSize(0);
   _copy__107->GetXaxis()->SetTitleSize(0.06);
   _copy__107->GetXaxis()->SetTitleFont(132);
   _copy__107->GetYaxis()->SetTitle("Ratio");
   _copy__107->GetYaxis()->CenterTitle(true);
   _copy__107->GetYaxis()->SetLabelFont(132);
   _copy__107->GetYaxis()->SetLabelOffset(999);
   _copy__107->GetYaxis()->SetLabelSize(0.05);
   _copy__107->GetYaxis()->SetTitleSize(0.06);
   _copy__107->GetYaxis()->SetTitleFont(132);
   _copy__107->GetZaxis()->SetLabelFont(132);
   _copy__107->GetZaxis()->SetLabelSize(0.05);
   _copy__107->GetZaxis()->SetTitleSize(0.06);
   _copy__107->GetZaxis()->SetTitleFont(132);
   _copy__107->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(6.172839,-2.98355,104.9383,4.293401);
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
   Double_t xAxis88[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_toterr__108 = new TH1F("wp_ptj_toterr__108","wp_ptj",5, xAxis88);
   wp_ptj_toterr__108->SetBinContent(1,3.450959);
   wp_ptj_toterr__108->SetBinContent(2,2.256658);
   wp_ptj_toterr__108->SetBinContent(3,1.266894);
   wp_ptj_toterr__108->SetBinContent(4,0.667355);
   wp_ptj_toterr__108->SetBinContent(5,0.1635365);
   wp_ptj_toterr__108->SetBinContent(6,8.176826);
   wp_ptj_toterr__108->SetBinError(1,0.2914732);
   wp_ptj_toterr__108->SetBinError(2,0.2298212);
   wp_ptj_toterr__108->SetBinError(3,0.117779);
   wp_ptj_toterr__108->SetBinError(4,0.07112221);
   wp_ptj_toterr__108->SetBinError(5,0.02028571);
   wp_ptj_toterr__108->SetBinError(6,1.014286);
   wp_ptj_toterr__108->SetEntries(12);
   wp_ptj_toterr__108->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__108->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__108->SetLineColor(ci);
   wp_ptj_toterr__108->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__108->SetMarkerColor(ci);
   wp_ptj_toterr__108->SetMarkerStyle(0);
   wp_ptj_toterr__108->GetXaxis()->SetNdivisions(4);
   wp_ptj_toterr__108->GetXaxis()->SetLabelFont(132);
   wp_ptj_toterr__108->GetXaxis()->SetLabelOffset(999);
   wp_ptj_toterr__108->GetXaxis()->SetLabelSize(0);
   wp_ptj_toterr__108->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__108->GetXaxis()->SetTitleFont(132);
   wp_ptj_toterr__108->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_toterr__108->GetYaxis()->SetLabelFont(132);
   wp_ptj_toterr__108->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__108->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__108->GetYaxis()->SetTitleFont(132);
   wp_ptj_toterr__108->GetZaxis()->SetLabelFont(132);
   wp_ptj_toterr__108->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__108->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__108->GetZaxis()->SetTitleFont(132);
   wp_ptj_toterr__108->Draw("e2");
   Double_t xAxis89[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_staterr__109 = new TH1F("wp_ptj_staterr__109","wp_ptj",5, xAxis89);
   wp_ptj_staterr__109->SetBinContent(1,3.450959);
   wp_ptj_staterr__109->SetBinContent(2,2.256658);
   wp_ptj_staterr__109->SetBinContent(3,1.266894);
   wp_ptj_staterr__109->SetBinContent(4,0.667355);
   wp_ptj_staterr__109->SetBinContent(5,0.1635365);
   wp_ptj_staterr__109->SetBinContent(6,8.176826);
   wp_ptj_staterr__109->SetBinError(1,0.02497134);
   wp_ptj_staterr__109->SetBinError(2,0.02019583);
   wp_ptj_staterr__109->SetBinError(3,0.01073196);
   wp_ptj_staterr__109->SetBinError(4,0.007910258);
   wp_ptj_staterr__109->SetBinError(5,0.001777759);
   wp_ptj_staterr__109->SetBinError(6,0.08888796);
   wp_ptj_staterr__109->SetEntries(12);
   wp_ptj_staterr__109->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__109->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__109->SetLineColor(ci);
   wp_ptj_staterr__109->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__109->SetMarkerColor(ci);
   wp_ptj_staterr__109->SetMarkerStyle(0);
   wp_ptj_staterr__109->GetXaxis()->SetNdivisions(4);
   wp_ptj_staterr__109->GetXaxis()->SetLabelFont(132);
   wp_ptj_staterr__109->GetXaxis()->SetLabelOffset(999);
   wp_ptj_staterr__109->GetXaxis()->SetLabelSize(0);
   wp_ptj_staterr__109->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__109->GetXaxis()->SetTitleFont(132);
   wp_ptj_staterr__109->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_staterr__109->GetYaxis()->SetLabelFont(132);
   wp_ptj_staterr__109->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__109->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__109->GetYaxis()->SetTitleFont(132);
   wp_ptj_staterr__109->GetZaxis()->SetLabelFont(132);
   wp_ptj_staterr__109->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__109->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__109->GetZaxis()->SetTitleFont(132);
   wp_ptj_staterr__109->Draw("e2same");
   Double_t xAxis90[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_toterr__110 = new TH1F("wm_ptj_toterr__110","wm_ptj",5, xAxis90);
   wm_ptj_toterr__110->SetBinContent(1,2.161372);
   wm_ptj_toterr__110->SetBinContent(2,1.324459);
   wm_ptj_toterr__110->SetBinContent(3,0.7447754);
   wm_ptj_toterr__110->SetBinContent(4,0.3862884);
   wm_ptj_toterr__110->SetBinContent(5,0.07929422);
   wm_ptj_toterr__110->SetBinContent(6,3.964711);
   wm_ptj_toterr__110->SetBinError(1,0.2161911);
   wm_ptj_toterr__110->SetBinError(2,0.1517678);
   wm_ptj_toterr__110->SetBinError(3,0.08010473);
   wm_ptj_toterr__110->SetBinError(4,0.04449275);
   wm_ptj_toterr__110->SetBinError(5,0.01272714);
   wm_ptj_toterr__110->SetBinError(6,0.636357);
   wm_ptj_toterr__110->SetEntries(12);
   wm_ptj_toterr__110->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__110->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__110->SetLineColor(ci);
   wm_ptj_toterr__110->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__110->SetMarkerColor(ci);
   wm_ptj_toterr__110->SetMarkerStyle(0);
   wm_ptj_toterr__110->GetXaxis()->SetNdivisions(4);
   wm_ptj_toterr__110->GetXaxis()->SetLabelFont(132);
   wm_ptj_toterr__110->GetXaxis()->SetLabelOffset(999);
   wm_ptj_toterr__110->GetXaxis()->SetLabelSize(0);
   wm_ptj_toterr__110->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__110->GetXaxis()->SetTitleFont(132);
   wm_ptj_toterr__110->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wm_ptj_toterr__110->GetYaxis()->SetLabelFont(132);
   wm_ptj_toterr__110->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__110->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__110->GetYaxis()->SetTitleFont(132);
   wm_ptj_toterr__110->GetZaxis()->SetLabelFont(132);
   wm_ptj_toterr__110->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__110->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__110->GetZaxis()->SetTitleFont(132);
   wm_ptj_toterr__110->Draw("e2same");
   Double_t xAxis91[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_staterr__111 = new TH1F("wm_ptj_staterr__111","wm_ptj",5, xAxis91);
   wm_ptj_staterr__111->SetBinContent(1,2.161372);
   wm_ptj_staterr__111->SetBinContent(2,1.324459);
   wm_ptj_staterr__111->SetBinContent(3,0.7447754);
   wm_ptj_staterr__111->SetBinContent(4,0.3862884);
   wm_ptj_staterr__111->SetBinContent(5,0.07929422);
   wm_ptj_staterr__111->SetBinContent(6,3.964711);
   wm_ptj_staterr__111->SetBinError(1,0.01981714);
   wm_ptj_staterr__111->SetBinError(2,0.01549705);
   wm_ptj_staterr__111->SetBinError(3,0.008176924);
   wm_ptj_staterr__111->SetBinError(4,0.00603614);
   wm_ptj_staterr__111->SetBinError(5,0.001217149);
   wm_ptj_staterr__111->SetBinError(6,0.06085747);
   wm_ptj_staterr__111->SetEntries(12);
   wm_ptj_staterr__111->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__111->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__111->SetLineColor(ci);
   wm_ptj_staterr__111->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__111->SetMarkerColor(ci);
   wm_ptj_staterr__111->SetMarkerStyle(0);
   wm_ptj_staterr__111->GetXaxis()->SetNdivisions(4);
   wm_ptj_staterr__111->GetXaxis()->SetLabelFont(132);
   wm_ptj_staterr__111->GetXaxis()->SetLabelOffset(999);
   wm_ptj_staterr__111->GetXaxis()->SetLabelSize(0);
   wm_ptj_staterr__111->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__111->GetXaxis()->SetTitleFont(132);
   wm_ptj_staterr__111->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wm_ptj_staterr__111->GetYaxis()->SetLabelFont(132);
   wm_ptj_staterr__111->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__111->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__111->GetYaxis()->SetTitleFont(132);
   wm_ptj_staterr__111->GetZaxis()->SetLabelFont(132);
   wm_ptj_staterr__111->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__111->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__111->GetZaxis()->SetTitleFont(132);
   wm_ptj_staterr__111->Draw("e2same");
   
   Double_t ptj_plus_toterrs_fx3129[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_plus_toterrs_fy3129[5] = {
   3.781269,
   2.471324,
   1.346271,
   0.6736161,
   0.1720625};
   Double_t ptj_plus_toterrs_felx3129[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fely3129[5] = {
   0.2880126,
   0.2336951,
   0.09951573,
   0.04524418,
   0.01969193};
   Double_t ptj_plus_toterrs_fehx3129[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fehy3129[5] = {
   0.237181,
   0.1691029,
   0.09861914,
   0.05727119,
   0.01814489};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,ptj_plus_toterrs_fx3129,ptj_plus_toterrs_fy3129,ptj_plus_toterrs_felx3129,ptj_plus_toterrs_fehx3129,ptj_plus_toterrs_fely3129,ptj_plus_toterrs_fehy3129);
   grae->SetName("ptj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_ptj_plus_toterrs30613129 = new TH1F("Graph_Graph_ptj_plus_toterrs30613129","",100,17.325,88.425);
   Graph_Graph_ptj_plus_toterrs30613129->SetMinimum(0.1371335);
   Graph_Graph_ptj_plus_toterrs30613129->SetMaximum(4.405058);
   Graph_Graph_ptj_plus_toterrs30613129->SetDirectory(0);
   Graph_Graph_ptj_plus_toterrs30613129->SetStats(0);
   Graph_Graph_ptj_plus_toterrs30613129->SetLineWidth(2);
   Graph_Graph_ptj_plus_toterrs30613129->SetMarkerStyle(0);
   Graph_Graph_ptj_plus_toterrs30613129->GetXaxis()->SetNdivisions(4);
   Graph_Graph_ptj_plus_toterrs30613129->GetXaxis()->SetLabelFont(132);
   Graph_Graph_ptj_plus_toterrs30613129->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_ptj_plus_toterrs30613129->GetXaxis()->SetLabelSize(0);
   Graph_Graph_ptj_plus_toterrs30613129->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_plus_toterrs30613129->GetXaxis()->SetTitleFont(132);
   Graph_Graph_ptj_plus_toterrs30613129->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_ptj_plus_toterrs30613129->GetYaxis()->SetLabelFont(132);
   Graph_Graph_ptj_plus_toterrs30613129->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_plus_toterrs30613129->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_plus_toterrs30613129->GetYaxis()->SetTitleFont(132);
   Graph_Graph_ptj_plus_toterrs30613129->GetZaxis()->SetLabelFont(132);
   Graph_Graph_ptj_plus_toterrs30613129->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_plus_toterrs30613129->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_plus_toterrs30613129->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_ptj_plus_toterrs30613129);
   
   grae->Draw("p1p");
   
   Double_t ptj_plus_toterrs_fx3130[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_plus_toterrs_fy3130[5] = {
   3.747404,
   2.382393,
   1.378484,
   0.718633,
   0.1890381};
   Double_t ptj_plus_toterrs_felx3130[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fely3130[5] = {
   0.2766023,
   0.1785285,
   0.1117659,
   0.05911753,
   0.01596438};
   Double_t ptj_plus_toterrs_fehx3130[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fehy3130[5] = {
   0.2834241,
   0.1899127,
   0.1152294,
   0.06511091,
   0.01862706};
   grae = new TGraphAsymmErrors(5,ptj_plus_toterrs_fx3130,ptj_plus_toterrs_fy3130,ptj_plus_toterrs_felx3130,ptj_plus_toterrs_fehx3130,ptj_plus_toterrs_fely3130,ptj_plus_toterrs_fehy3130);
   grae->SetName("ptj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_ptj_plus_toterrs30633130 = new TH1F("Graph_Graph_ptj_plus_toterrs30633130","",100,17.175,72.075);
   Graph_Graph_ptj_plus_toterrs30633130->SetMinimum(0.1557663);
   Graph_Graph_ptj_plus_toterrs30633130->SetMaximum(4.416604);
   Graph_Graph_ptj_plus_toterrs30633130->SetDirectory(0);
   Graph_Graph_ptj_plus_toterrs30633130->SetStats(0);
   Graph_Graph_ptj_plus_toterrs30633130->SetLineWidth(2);
   Graph_Graph_ptj_plus_toterrs30633130->SetMarkerStyle(0);
   Graph_Graph_ptj_plus_toterrs30633130->GetXaxis()->SetNdivisions(4);
   Graph_Graph_ptj_plus_toterrs30633130->GetXaxis()->SetLabelFont(132);
   Graph_Graph_ptj_plus_toterrs30633130->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_ptj_plus_toterrs30633130->GetXaxis()->SetLabelSize(0);
   Graph_Graph_ptj_plus_toterrs30633130->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_plus_toterrs30633130->GetXaxis()->SetTitleFont(132);
   Graph_Graph_ptj_plus_toterrs30633130->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_ptj_plus_toterrs30633130->GetYaxis()->SetLabelFont(132);
   Graph_Graph_ptj_plus_toterrs30633130->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_plus_toterrs30633130->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_plus_toterrs30633130->GetYaxis()->SetTitleFont(132);
   Graph_Graph_ptj_plus_toterrs30633130->GetZaxis()->SetLabelFont(132);
   Graph_Graph_ptj_plus_toterrs30633130->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_plus_toterrs30633130->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_plus_toterrs30633130->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_ptj_plus_toterrs30633130);
   
   grae->Draw("p1p");
   
   Double_t ptj_minus_toterrs_fx3131[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_minus_toterrs_fy3131[5] = {
   2.562893,
   1.476188,
   0.8436134,
   0.4057886,
   0.09869911};
   Double_t ptj_minus_toterrs_felx3131[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fely3131[5] = {
   0.266341,
   0.1072309,
   0.08437284,
   0.03839483,
   0.01553516};
   Double_t ptj_minus_toterrs_fehx3131[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fehy3131[5] = {
   0.1762218,
   0.2029888,
   0.07273972,
   0.04002159,
   0.01249906};
   grae = new TGraphAsymmErrors(5,ptj_minus_toterrs_fx3131,ptj_minus_toterrs_fy3131,ptj_minus_toterrs_felx3131,ptj_minus_toterrs_fehx3131,ptj_minus_toterrs_fely3131,ptj_minus_toterrs_fehy3131);
   grae->SetName("ptj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_ptj_minus_toterrs30733131 = new TH1F("Graph_Graph_ptj_minus_toterrs30733131","",100,17.325,88.425);
   Graph_Graph_ptj_minus_toterrs30733131->SetMinimum(0.07484756);
   Graph_Graph_ptj_minus_toterrs30733131->SetMaximum(3.00471);
   Graph_Graph_ptj_minus_toterrs30733131->SetDirectory(0);
   Graph_Graph_ptj_minus_toterrs30733131->SetStats(0);
   Graph_Graph_ptj_minus_toterrs30733131->SetLineWidth(2);
   Graph_Graph_ptj_minus_toterrs30733131->SetMarkerStyle(0);
   Graph_Graph_ptj_minus_toterrs30733131->GetXaxis()->SetNdivisions(4);
   Graph_Graph_ptj_minus_toterrs30733131->GetXaxis()->SetLabelFont(132);
   Graph_Graph_ptj_minus_toterrs30733131->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_ptj_minus_toterrs30733131->GetXaxis()->SetLabelSize(0);
   Graph_Graph_ptj_minus_toterrs30733131->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_minus_toterrs30733131->GetXaxis()->SetTitleFont(132);
   Graph_Graph_ptj_minus_toterrs30733131->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_ptj_minus_toterrs30733131->GetYaxis()->SetLabelFont(132);
   Graph_Graph_ptj_minus_toterrs30733131->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_minus_toterrs30733131->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_minus_toterrs30733131->GetYaxis()->SetTitleFont(132);
   Graph_Graph_ptj_minus_toterrs30733131->GetZaxis()->SetLabelFont(132);
   Graph_Graph_ptj_minus_toterrs30733131->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_minus_toterrs30733131->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_minus_toterrs30733131->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_ptj_minus_toterrs30733131);
   
   grae->Draw("p1p");
   
   Double_t ptj_minus_toterrs_fx3132[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_minus_toterrs_fy3132[5] = {
   2.425233,
   1.507886,
   0.829673,
   0.4212834,
   0.1045012};
   Double_t ptj_minus_toterrs_felx3132[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fely3132[5] = {
   0.1865384,
   0.1193402,
   0.06892636,
   0.03735492,
   0.01026445};
   Double_t ptj_minus_toterrs_fehx3132[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fehy3132[5] = {
   0.1902493,
   0.1251425,
   0.0772211,
   0.04040276,
   0.01118462};
   grae = new TGraphAsymmErrors(5,ptj_minus_toterrs_fx3132,ptj_minus_toterrs_fy3132,ptj_minus_toterrs_felx3132,ptj_minus_toterrs_fehx3132,ptj_minus_toterrs_fely3132,ptj_minus_toterrs_fehy3132);
   grae->SetName("ptj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_ptj_minus_toterrs30753132 = new TH1F("Graph_Graph_ptj_minus_toterrs30753132","",100,17.175,72.075);
   Graph_Graph_ptj_minus_toterrs30753132->SetMinimum(0.08481303);
   Graph_Graph_ptj_minus_toterrs30753132->SetMaximum(2.867607);
   Graph_Graph_ptj_minus_toterrs30753132->SetDirectory(0);
   Graph_Graph_ptj_minus_toterrs30753132->SetStats(0);
   Graph_Graph_ptj_minus_toterrs30753132->SetLineWidth(2);
   Graph_Graph_ptj_minus_toterrs30753132->SetMarkerStyle(0);
   Graph_Graph_ptj_minus_toterrs30753132->GetXaxis()->SetNdivisions(4);
   Graph_Graph_ptj_minus_toterrs30753132->GetXaxis()->SetLabelFont(132);
   Graph_Graph_ptj_minus_toterrs30753132->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_ptj_minus_toterrs30753132->GetXaxis()->SetLabelSize(0);
   Graph_Graph_ptj_minus_toterrs30753132->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_minus_toterrs30753132->GetXaxis()->SetTitleFont(132);
   Graph_Graph_ptj_minus_toterrs30753132->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_ptj_minus_toterrs30753132->GetYaxis()->SetLabelFont(132);
   Graph_Graph_ptj_minus_toterrs30753132->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_minus_toterrs30753132->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_minus_toterrs30753132->GetYaxis()->SetTitleFont(132);
   Graph_Graph_ptj_minus_toterrs30753132->GetZaxis()->SetLabelFont(132);
   Graph_Graph_ptj_minus_toterrs30753132->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_minus_toterrs30753132->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_minus_toterrs30753132->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_ptj_minus_toterrs30753132);
   
   grae->Draw("p1p");
   
   Double_t _fx3133[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3133[5] = {
   3.781269,
   2.471324,
   1.346271,
   0.6736161,
   0.1720625};
   Double_t _felx3133[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3133[5] = {
   0.190572,
   0.1353315,
   0.0746666,
   0.03416157,
   0.01098946};
   Double_t _fehx3133[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3133[5] = {
   0.1784855,
   0.1300753,
   0.07322493,
   0.03857584,
   0.01318213};
   grae = new TGraphAsymmErrors(5,_fx3133,_fy3133,_felx3133,_fehx3133,_fely3133,_fehy3133);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph30623133 = new TH1F("Graph_Graph_Graph30623133","",100,17.325,88.425);
   Graph_Graph_Graph30623133->SetMinimum(0.1449657);
   Graph_Graph_Graph30623133->SetMaximum(4.339622);
   Graph_Graph_Graph30623133->SetDirectory(0);
   Graph_Graph_Graph30623133->SetStats(0);
   Graph_Graph_Graph30623133->SetLineWidth(2);
   Graph_Graph_Graph30623133->SetMarkerStyle(0);
   Graph_Graph_Graph30623133->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30623133->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30623133->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30623133->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30623133->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30623133->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30623133->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph30623133->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30623133->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30623133->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30623133->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30623133->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30623133->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30623133->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30623133->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30623133);
   
   grae->Draw("p1p");
   
   Double_t _fx3134[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3134[5] = {
   3.747404,
   2.382393,
   1.378484,
   0.718633,
   0.1890381};
   Double_t _felx3134[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3134[5] = {
   0.2195713,
   0.1431244,
   0.08659163,
   0.04658484,
   0.01299852};
   Double_t _fehx3134[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3134[5] = {
   0.2285816,
   0.1531721,
   0.09393196,
   0.05202641,
   0.01532503};
   grae = new TGraphAsymmErrors(5,_fx3134,_fy3134,_felx3134,_fehx3134,_fely3134,_fehy3134);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30643134 = new TH1F("Graph_Graph_Graph30643134","",100,17.175,72.075);
   Graph_Graph_Graph30643134->SetMinimum(0.1584356);
   Graph_Graph_Graph30643134->SetMaximum(4.355981);
   Graph_Graph_Graph30643134->SetDirectory(0);
   Graph_Graph_Graph30643134->SetStats(0);
   Graph_Graph_Graph30643134->SetLineWidth(2);
   Graph_Graph_Graph30643134->SetMarkerStyle(0);
   Graph_Graph_Graph30643134->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30643134->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30643134->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30643134->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30643134->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30643134->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30643134->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph30643134->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30643134->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30643134->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30643134->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30643134->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30643134->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30643134->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30643134->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30643134);
   
   grae->Draw("p1p");
   
   Double_t _fx3135[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3135[5] = {
   2.562893,
   1.476188,
   0.8436134,
   0.4057886,
   0.09869911};
   Double_t _felx3135[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3135[5] = {
   0.1369467,
   0.0783433,
   0.04753537,
   0.0220407,
   0.007140055};
   Double_t _fehx3135[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3135[5] = {
   0.1275658,
   0.07309179,
   0.05322437,
   0.02140498,
   0.009120522};
   grae = new TGraphAsymmErrors(5,_fx3135,_fy3135,_felx3135,_fehx3135,_fely3135,_fehy3135);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph30743135 = new TH1F("Graph_Graph_Graph30743135","",100,17.325,88.425);
   Graph_Graph_Graph30743135->SetMinimum(0.08240315);
   Graph_Graph_Graph30743135->SetMaximum(2.950349);
   Graph_Graph_Graph30743135->SetDirectory(0);
   Graph_Graph_Graph30743135->SetStats(0);
   Graph_Graph_Graph30743135->SetLineWidth(2);
   Graph_Graph_Graph30743135->SetMarkerStyle(0);
   Graph_Graph_Graph30743135->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30743135->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30743135->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30743135->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30743135->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30743135->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30743135->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph30743135->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30743135->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30743135->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30743135->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30743135->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30743135->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30743135->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30743135->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30743135);
   
   grae->Draw("p1p");
   
   Double_t _fx3136[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3136[5] = {
   2.425233,
   1.507886,
   0.829673,
   0.4212834,
   0.1045012};
   Double_t _felx3136[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3136[5] = {
   0.1399179,
   0.08881254,
   0.05086884,
   0.02694438,
   0.006972694};
   Double_t _fehx3136[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3136[5] = {
   0.1450405,
   0.09567509,
   0.05554514,
   0.02997656,
   0.007936096};
   grae = new TGraphAsymmErrors(5,_fx3136,_fy3136,_felx3136,_fehx3136,_fely3136,_fehy3136);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph30763136 = new TH1F("Graph_Graph_Graph30763136","",100,17.175,72.075);
   Graph_Graph_Graph30763136->SetMinimum(0.08777561);
   Graph_Graph_Graph30763136->SetMaximum(2.817548);
   Graph_Graph_Graph30763136->SetDirectory(0);
   Graph_Graph_Graph30763136->SetStats(0);
   Graph_Graph_Graph30763136->SetLineWidth(2);
   Graph_Graph_Graph30763136->SetMarkerStyle(0);
   Graph_Graph_Graph30763136->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30763136->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30763136->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30763136->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30763136->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30763136->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30763136->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph30763136->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30763136->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30763136->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30763136->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30763136->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30763136->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30763136->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30763136->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30763136);
   
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
   Double_t xAxis92[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_toterr_copy__112 = new TH1F("wp_ptj_toterr_copy__112","wp_ptj",5, xAxis92);
   wp_ptj_toterr_copy__112->SetBinContent(1,3.450959);
   wp_ptj_toterr_copy__112->SetBinContent(2,2.256658);
   wp_ptj_toterr_copy__112->SetBinContent(3,1.266894);
   wp_ptj_toterr_copy__112->SetBinContent(4,0.667355);
   wp_ptj_toterr_copy__112->SetBinContent(5,0.1635365);
   wp_ptj_toterr_copy__112->SetBinContent(6,8.176826);
   wp_ptj_toterr_copy__112->SetBinError(1,0.2914732);
   wp_ptj_toterr_copy__112->SetBinError(2,0.2298212);
   wp_ptj_toterr_copy__112->SetBinError(3,0.117779);
   wp_ptj_toterr_copy__112->SetBinError(4,0.07112221);
   wp_ptj_toterr_copy__112->SetBinError(5,0.02028571);
   wp_ptj_toterr_copy__112->SetBinError(6,1.014286);
   wp_ptj_toterr_copy__112->SetEntries(12);
   wp_ptj_toterr_copy__112->SetDirectory(0);
   wp_ptj_toterr_copy__112->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__112->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__112->SetLineColor(ci);
   wp_ptj_toterr_copy__112->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__112->SetMarkerColor(ci);
   wp_ptj_toterr_copy__112->SetMarkerStyle(0);
   wp_ptj_toterr_copy__112->GetXaxis()->SetNdivisions(4);
   wp_ptj_toterr_copy__112->GetXaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__112->GetXaxis()->SetLabelOffset(999);
   wp_ptj_toterr_copy__112->GetXaxis()->SetLabelSize(0);
   wp_ptj_toterr_copy__112->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__112->GetXaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__112->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_toterr_copy__112->GetYaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__112->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__112->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__112->GetYaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__112->GetZaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__112->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__112->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__112->GetZaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__112->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(6.172839,-0.4062964,104.9383,6.852964);
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
   Double_t xAxis93[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_870_1001_2ratiocomp0__113 = new TH1F("wj_ptj_8TeV_870_1001_2ratiocomp0__113","wm_ptj",5, xAxis93);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinContent(1,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinContent(2,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinContent(3,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinContent(4,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinContent(5,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinContent(6,3.964711);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinError(1,0.100025);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinError(2,0.1145886);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinError(3,0.1075556);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinError(4,0.1151801);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinError(5,0.1605053);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetBinError(6,0.636357);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetMinimum(0.61);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetMaximum(1.59);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetEntries(17);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetLineColor(ci);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetMarkerColor(ci);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->SetMarkerStyle(0);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0__113->Draw("e2");
   Double_t xAxis94[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_870_1001_2ratiocomp1__114 = new TH1F("wj_ptj_8TeV_870_1001_2ratiocomp1__114","wm_ptj",5, xAxis94);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinContent(1,1);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinContent(2,1);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinContent(3,1);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinContent(4,1);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinContent(5,1);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinContent(6,3.964711);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinError(1,0.009168779);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinError(2,0.01170067);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinError(3,0.01097905);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinError(4,0.01562599);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinError(5,0.01534979);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetBinError(6,0.06085747);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetMinimum(0.61);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetMaximum(1.59);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetEntries(17);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetLineColor(ci);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetMarkerColor(ci);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->SetMarkerStyle(0);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp1__114->Draw("e2same");
   
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp2_fx3137[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp2_fy3137[5] = {
   1.185772,
   1.114559,
   1.132708,
   1.050481,
   1.24472};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp2_felx3137[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp2_fely3137[5] = {
   0.1232278,
   0.08096209,
   0.1132863,
   0.09939422,
   0.1959179};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp2_fehx3137[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp2_fehy3137[5] = {
   0.08153238,
   0.1532617,
   0.09766665,
   0.1036055,
   0.1576289};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_870_1001_2ratiocomp2_fx3137,wj_ptj_8TeV_870_1001_2ratiocomp2_fy3137,wj_ptj_8TeV_870_1001_2ratiocomp2_felx3137,wj_ptj_8TeV_870_1001_2ratiocomp2_fehx3137,wj_ptj_8TeV_870_1001_2ratiocomp2_fely3137,wj_ptj_8TeV_870_1001_2ratiocomp2_fehy3137);
   grae->SetName("wj_ptj_8TeV_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137 = new TH1F("Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->SetDirectory(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->SetStats(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->SetLineWidth(2);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_870_1001_2ratiocomp23137);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp3_fx3138[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp3_fy3138[5] = {
   1.12208,
   1.138492,
   1.113991,
   1.090593,
   1.317891};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp3_felx3138[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp3_fely3138[5] = {
   0.08630558,
   0.09010488,
   0.09254651,
   0.09670217,
   0.1294476};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp3_fehx3138[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp3_fehy3138[5] = {
   0.08802248,
   0.09448576,
   0.1036837,
   0.1045922,
   0.1410521};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_870_1001_2ratiocomp3_fx3138,wj_ptj_8TeV_870_1001_2ratiocomp3_fy3138,wj_ptj_8TeV_870_1001_2ratiocomp3_felx3138,wj_ptj_8TeV_870_1001_2ratiocomp3_fehx3138,wj_ptj_8TeV_870_1001_2ratiocomp3_fely3138,wj_ptj_8TeV_870_1001_2ratiocomp3_fehy3138);
   grae->SetName("wj_ptj_8TeV_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138 = new TH1F("Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->SetDirectory(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->SetStats(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->SetLineWidth(2);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_870_1001_2ratiocomp33138);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp4_fx3139[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp4_fy3139[5] = {
   1.185772,
   1.114559,
   1.132708,
   1.050481,
   1.24472};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp4_felx3139[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp4_fely3139[5] = {
   0.063361,
   0.05915119,
   0.06382511,
   0.05705763,
   0.09004508};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp4_fehx3139[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp4_fehy3139[5] = {
   0.05902074,
   0.05518617,
   0.07146365,
   0.05541192,
   0.1150213};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_870_1001_2ratiocomp4_fx3139,wj_ptj_8TeV_870_1001_2ratiocomp4_fy3139,wj_ptj_8TeV_870_1001_2ratiocomp4_felx3139,wj_ptj_8TeV_870_1001_2ratiocomp4_fehx3139,wj_ptj_8TeV_870_1001_2ratiocomp4_fely3139,wj_ptj_8TeV_870_1001_2ratiocomp4_fehy3139);
   grae->SetName("wj_ptj_8TeV_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139 = new TH1F("Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->SetDirectory(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->SetStats(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->SetLineWidth(2);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_870_1001_2ratiocomp43139);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp5_fx3140[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp5_fy3140[5] = {
   1.12208,
   1.138492,
   1.113991,
   1.090593,
   1.317891};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp5_felx3140[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp5_fely3140[5] = {
   0.06473572,
   0.06705573,
   0.06830092,
   0.06975197,
   0.08793446};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp5_fehx3140[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_870_1001_2ratiocomp5_fehy3140[5] = {
   0.06710577,
   0.07223713,
   0.07457972,
   0.0776015,
   0.1000842};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_870_1001_2ratiocomp5_fx3140,wj_ptj_8TeV_870_1001_2ratiocomp5_fy3140,wj_ptj_8TeV_870_1001_2ratiocomp5_felx3140,wj_ptj_8TeV_870_1001_2ratiocomp5_fehx3140,wj_ptj_8TeV_870_1001_2ratiocomp5_fely3140,wj_ptj_8TeV_870_1001_2ratiocomp5_fehy3140);
   grae->SetName("wj_ptj_8TeV_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140 = new TH1F("Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->SetDirectory(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->SetStats(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->SetLineWidth(2);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_870_1001_2ratiocomp53140);
   
   grae->Draw("p1");
   Double_t xAxis95[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115 = new TH1F("wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115","wm_ptj",5, xAxis95);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinContent(1,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinContent(2,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinContent(3,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinContent(4,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinContent(5,1);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinContent(6,3.964711);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinError(1,0.100025);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinError(2,0.1145886);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinError(3,0.1075556);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinError(4,0.1151801);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinError(5,0.1605053);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetBinError(6,0.636357);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetMinimum(0.61);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetMaximum(1.59);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetEntries(17);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetDirectory(0);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetLineColor(ci);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetMarkerColor(ci);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->SetMarkerStyle(0);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_870_1001_2ratiocomp0_copy__115->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: middlPad
   TPad *middlPad = new TPad("middlPad", "middlPad",0.005,0.05,0.995,0.995);
   middlPad->Draw();
   middlPad->cd();
   middlPad->Range(6.172839,-1.214827,104.9383,5.543792);
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
   Double_t xAxis96[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_400_1001_0ratiocomp0__116 = new TH1F("wj_ptj_8TeV_400_1001_0ratiocomp0__116","wp_ptj",5, xAxis96);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinContent(1,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinContent(2,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinContent(3,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinContent(4,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinContent(5,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinContent(6,8.176826);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinError(1,0.08446152);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinError(2,0.1018414);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinError(3,0.09296672);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinError(4,0.1065733);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinError(5,0.1240439);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetBinError(6,1.014286);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetMinimum(0.61);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetMaximum(1.59);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetEntries(17);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetLineColor(ci);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetMarkerColor(ci);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->SetMarkerStyle(0);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0__116->Draw("e2");
   Double_t xAxis97[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_400_1001_0ratiocomp1__117 = new TH1F("wj_ptj_8TeV_400_1001_0ratiocomp1__117","wp_ptj",5, xAxis97);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinContent(1,1);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinContent(2,1);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinContent(3,1);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinContent(4,1);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinContent(5,1);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinContent(6,8.176826);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinError(1,0.007236058);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinError(2,0.008949443);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinError(3,0.008471081);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinError(4,0.01185315);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinError(5,0.01087072);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetBinError(6,0.08888796);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetMinimum(0.61);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetMaximum(1.59);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetEntries(17);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetLineColor(ci);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetMarkerColor(ci);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->SetMarkerStyle(0);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp1__117->Draw("e2same");
   
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp2_fx3141[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp2_fy3141[5] = {
   1.095715,
   1.095126,
   1.062654,
   1.009382,
   1.052135};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp2_felx3141[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp2_fely3141[5] = {
   0.08345872,
   0.103558,
   0.07855093,
   0.06779626,
   0.120413};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp2_fehx3141[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp2_fehy3141[5] = {
   0.068729,
   0.07493511,
   0.07784322,
   0.08581818,
   0.1109532};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_400_1001_0ratiocomp2_fx3141,wj_ptj_8TeV_400_1001_0ratiocomp2_fy3141,wj_ptj_8TeV_400_1001_0ratiocomp2_felx3141,wj_ptj_8TeV_400_1001_0ratiocomp2_fehx3141,wj_ptj_8TeV_400_1001_0ratiocomp2_fely3141,wj_ptj_8TeV_400_1001_0ratiocomp2_fehy3141);
   grae->SetName("wj_ptj_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141 = new TH1F("Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->SetDirectory(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->SetStats(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->SetLineWidth(2);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_400_1001_0ratiocomp23141);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp3_fx3142[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp3_fy3142[5] = {
   1.085902,
   1.055717,
   1.088081,
   1.076838,
   1.155938};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp3_felx3142[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp3_fely3142[5] = {
   0.0801523,
   0.07911191,
   0.0882204,
   0.08858483,
   0.0976197};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp3_fehx3142[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp3_fehy3142[5] = {
   0.08212909,
   0.08415661,
   0.09095427,
   0.09756563,
   0.1139015};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_400_1001_0ratiocomp3_fx3142,wj_ptj_8TeV_400_1001_0ratiocomp3_fy3142,wj_ptj_8TeV_400_1001_0ratiocomp3_felx3142,wj_ptj_8TeV_400_1001_0ratiocomp3_fehx3142,wj_ptj_8TeV_400_1001_0ratiocomp3_fely3142,wj_ptj_8TeV_400_1001_0ratiocomp3_fehy3142);
   grae->SetName("wj_ptj_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142 = new TH1F("Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->SetDirectory(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->SetStats(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->SetLineWidth(2);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_400_1001_0ratiocomp33142);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp4_fx3143[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp4_fy3143[5] = {
   1.095715,
   1.095126,
   1.062654,
   1.009382,
   1.052135};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp4_felx3143[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp4_fely3143[5] = {
   0.05522291,
   0.0599699,
   0.05893672,
   0.0511895,
   0.0671988};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp4_fehx3143[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp4_fehy3143[5] = {
   0.05172055,
   0.05764067,
   0.05779876,
   0.05780408,
   0.08060662};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_400_1001_0ratiocomp4_fx3143,wj_ptj_8TeV_400_1001_0ratiocomp4_fy3143,wj_ptj_8TeV_400_1001_0ratiocomp4_felx3143,wj_ptj_8TeV_400_1001_0ratiocomp4_fehx3143,wj_ptj_8TeV_400_1001_0ratiocomp4_fely3143,wj_ptj_8TeV_400_1001_0ratiocomp4_fehy3143);
   grae->SetName("wj_ptj_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143 = new TH1F("Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->SetDirectory(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->SetStats(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->SetLineWidth(2);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_400_1001_0ratiocomp43143);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp5_fx3144[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp5_fy3144[5] = {
   1.085902,
   1.055717,
   1.088081,
   1.076838,
   1.155938};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp5_felx3144[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp5_fely3144[5] = {
   0.06362618,
   0.06342317,
   0.06834952,
   0.06980519,
   0.07948393};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp5_fehx3144[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_400_1001_0ratiocomp5_fehy3144[5] = {
   0.06623714,
   0.06787565,
   0.07414348,
   0.07795913,
   0.09371016};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_400_1001_0ratiocomp5_fx3144,wj_ptj_8TeV_400_1001_0ratiocomp5_fy3144,wj_ptj_8TeV_400_1001_0ratiocomp5_felx3144,wj_ptj_8TeV_400_1001_0ratiocomp5_fehx3144,wj_ptj_8TeV_400_1001_0ratiocomp5_fely3144,wj_ptj_8TeV_400_1001_0ratiocomp5_fehy3144);
   grae->SetName("wj_ptj_8TeV_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144 = new TH1F("Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->SetDirectory(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->SetStats(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->SetLineWidth(2);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_400_1001_0ratiocomp53144);
   
   grae->Draw("p1");
   Double_t xAxis98[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118 = new TH1F("wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118","wp_ptj",5, xAxis98);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinContent(1,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinContent(2,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinContent(3,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinContent(4,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinContent(5,1);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinContent(6,8.176826);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinError(1,0.08446152);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinError(2,0.1018414);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinError(3,0.09296672);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinError(4,0.1065733);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinError(5,0.1240439);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetBinError(6,1.014286);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetMinimum(0.61);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetMaximum(1.59);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetEntries(17);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetDirectory(0);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetLineColor(ci);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetMarkerColor(ci);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->SetMarkerStyle(0);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_400_1001_0ratiocomp0_copy__118->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
