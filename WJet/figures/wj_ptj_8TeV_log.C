void wj_ptj_8TeV_log()
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
   
   TH1F *__119 = new TH1F("__119","",1,0,1);
   __119->SetDirectory(0);
   __119->SetStats(0);
   __119->SetFillStyle(0);
   __119->SetLineWidth(2);
   __119->SetMarkerStyle(0);
   __119->GetXaxis()->SetNdivisions(4);
   __119->GetXaxis()->SetLabelFont(132);
   __119->GetXaxis()->SetLabelOffset(999);
   __119->GetXaxis()->SetLabelSize(0);
   __119->GetXaxis()->SetTitleSize(0.06);
   __119->GetXaxis()->SetTitleFont(132);
   __119->GetYaxis()->SetTitle("Ratio");
   __119->GetYaxis()->CenterTitle(true);
   __119->GetYaxis()->SetLabelFont(132);
   __119->GetYaxis()->SetLabelOffset(999);
   __119->GetYaxis()->SetLabelSize(0.05);
   __119->GetYaxis()->SetTitleSize(0.06);
   __119->GetYaxis()->SetTitleFont(132);
   __119->GetZaxis()->SetLabelFont(132);
   __119->GetZaxis()->SetLabelSize(0.05);
   __119->GetZaxis()->SetTitleSize(0.06);
   __119->GetZaxis()->SetTitleFont(132);
   __119->Draw("");
   
   TH1F *_copy__120 = new TH1F("_copy__120","",1,0,1);
   _copy__120->SetDirectory(0);
   _copy__120->SetStats(0);
   _copy__120->SetFillStyle(0);
   _copy__120->SetLineWidth(2);
   _copy__120->SetMarkerStyle(0);
   _copy__120->GetXaxis()->SetNdivisions(4);
   _copy__120->GetXaxis()->SetLabelFont(132);
   _copy__120->GetXaxis()->SetLabelOffset(999);
   _copy__120->GetXaxis()->SetLabelSize(0);
   _copy__120->GetXaxis()->SetTitleSize(0.06);
   _copy__120->GetXaxis()->SetTitleFont(132);
   _copy__120->GetYaxis()->SetTitle("Ratio");
   _copy__120->GetYaxis()->CenterTitle(true);
   _copy__120->GetYaxis()->SetLabelFont(132);
   _copy__120->GetYaxis()->SetLabelOffset(999);
   _copy__120->GetYaxis()->SetLabelSize(0.05);
   _copy__120->GetYaxis()->SetTitleSize(0.06);
   _copy__120->GetYaxis()->SetTitleFont(132);
   _copy__120->GetZaxis()->SetLabelFont(132);
   _copy__120->GetZaxis()->SetLabelSize(0.05);
   _copy__120->GetZaxis()->SetTitleSize(0.06);
   _copy__120->GetZaxis()->SetTitleFont(132);
   _copy__120->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(6.172839,-2.819548,104.9383,0.8841552);
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
   Double_t xAxis99[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_toterr__121 = new TH1F("wp_ptj_toterr__121","wp_ptj",5, xAxis99);
   wp_ptj_toterr__121->SetBinContent(1,3.450959);
   wp_ptj_toterr__121->SetBinContent(2,2.256658);
   wp_ptj_toterr__121->SetBinContent(3,1.266894);
   wp_ptj_toterr__121->SetBinContent(4,0.667355);
   wp_ptj_toterr__121->SetBinContent(5,0.1635365);
   wp_ptj_toterr__121->SetBinContent(6,8.176826);
   wp_ptj_toterr__121->SetBinError(1,0.2914732);
   wp_ptj_toterr__121->SetBinError(2,0.2298212);
   wp_ptj_toterr__121->SetBinError(3,0.117779);
   wp_ptj_toterr__121->SetBinError(4,0.07112221);
   wp_ptj_toterr__121->SetBinError(5,0.02028571);
   wp_ptj_toterr__121->SetBinError(6,1.014286);
   wp_ptj_toterr__121->SetMinimum(0.05);
   wp_ptj_toterr__121->SetMaximum(5);
   wp_ptj_toterr__121->SetEntries(12);
   wp_ptj_toterr__121->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__121->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__121->SetLineColor(ci);
   wp_ptj_toterr__121->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__121->SetMarkerColor(ci);
   wp_ptj_toterr__121->SetMarkerStyle(0);
   wp_ptj_toterr__121->GetXaxis()->SetNdivisions(4);
   wp_ptj_toterr__121->GetXaxis()->SetLabelFont(132);
   wp_ptj_toterr__121->GetXaxis()->SetLabelOffset(999);
   wp_ptj_toterr__121->GetXaxis()->SetLabelSize(0);
   wp_ptj_toterr__121->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__121->GetXaxis()->SetTitleFont(132);
   wp_ptj_toterr__121->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_toterr__121->GetYaxis()->SetLabelFont(132);
   wp_ptj_toterr__121->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__121->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__121->GetYaxis()->SetTitleFont(132);
   wp_ptj_toterr__121->GetZaxis()->SetLabelFont(132);
   wp_ptj_toterr__121->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__121->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__121->GetZaxis()->SetTitleFont(132);
   wp_ptj_toterr__121->Draw("e2");
   Double_t xAxis100[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_staterr__122 = new TH1F("wp_ptj_staterr__122","wp_ptj",5, xAxis100);
   wp_ptj_staterr__122->SetBinContent(1,3.450959);
   wp_ptj_staterr__122->SetBinContent(2,2.256658);
   wp_ptj_staterr__122->SetBinContent(3,1.266894);
   wp_ptj_staterr__122->SetBinContent(4,0.667355);
   wp_ptj_staterr__122->SetBinContent(5,0.1635365);
   wp_ptj_staterr__122->SetBinContent(6,8.176826);
   wp_ptj_staterr__122->SetBinError(1,0.02497134);
   wp_ptj_staterr__122->SetBinError(2,0.02019583);
   wp_ptj_staterr__122->SetBinError(3,0.01073196);
   wp_ptj_staterr__122->SetBinError(4,0.007910258);
   wp_ptj_staterr__122->SetBinError(5,0.001777759);
   wp_ptj_staterr__122->SetBinError(6,0.08888796);
   wp_ptj_staterr__122->SetMinimum(0.05);
   wp_ptj_staterr__122->SetMaximum(5);
   wp_ptj_staterr__122->SetEntries(12);
   wp_ptj_staterr__122->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__122->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__122->SetLineColor(ci);
   wp_ptj_staterr__122->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__122->SetMarkerColor(ci);
   wp_ptj_staterr__122->SetMarkerStyle(0);
   wp_ptj_staterr__122->GetXaxis()->SetNdivisions(4);
   wp_ptj_staterr__122->GetXaxis()->SetLabelFont(132);
   wp_ptj_staterr__122->GetXaxis()->SetLabelOffset(999);
   wp_ptj_staterr__122->GetXaxis()->SetLabelSize(0);
   wp_ptj_staterr__122->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__122->GetXaxis()->SetTitleFont(132);
   wp_ptj_staterr__122->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_staterr__122->GetYaxis()->SetLabelFont(132);
   wp_ptj_staterr__122->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__122->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__122->GetYaxis()->SetTitleFont(132);
   wp_ptj_staterr__122->GetZaxis()->SetLabelFont(132);
   wp_ptj_staterr__122->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__122->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__122->GetZaxis()->SetTitleFont(132);
   wp_ptj_staterr__122->Draw("e2same");
   Double_t xAxis101[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_toterr__123 = new TH1F("wm_ptj_toterr__123","wm_ptj",5, xAxis101);
   wm_ptj_toterr__123->SetBinContent(1,2.161372);
   wm_ptj_toterr__123->SetBinContent(2,1.324459);
   wm_ptj_toterr__123->SetBinContent(3,0.7447754);
   wm_ptj_toterr__123->SetBinContent(4,0.3862884);
   wm_ptj_toterr__123->SetBinContent(5,0.07929422);
   wm_ptj_toterr__123->SetBinContent(6,3.964711);
   wm_ptj_toterr__123->SetBinError(1,0.2161911);
   wm_ptj_toterr__123->SetBinError(2,0.1517678);
   wm_ptj_toterr__123->SetBinError(3,0.08010473);
   wm_ptj_toterr__123->SetBinError(4,0.04449275);
   wm_ptj_toterr__123->SetBinError(5,0.01272714);
   wm_ptj_toterr__123->SetBinError(6,0.636357);
   wm_ptj_toterr__123->SetMinimum(0.05);
   wm_ptj_toterr__123->SetMaximum(5);
   wm_ptj_toterr__123->SetEntries(12);
   wm_ptj_toterr__123->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__123->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__123->SetLineColor(ci);
   wm_ptj_toterr__123->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__123->SetMarkerColor(ci);
   wm_ptj_toterr__123->SetMarkerStyle(0);
   wm_ptj_toterr__123->GetXaxis()->SetNdivisions(4);
   wm_ptj_toterr__123->GetXaxis()->SetLabelFont(132);
   wm_ptj_toterr__123->GetXaxis()->SetLabelOffset(999);
   wm_ptj_toterr__123->GetXaxis()->SetLabelSize(0);
   wm_ptj_toterr__123->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__123->GetXaxis()->SetTitleFont(132);
   wm_ptj_toterr__123->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wm_ptj_toterr__123->GetYaxis()->SetLabelFont(132);
   wm_ptj_toterr__123->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__123->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__123->GetYaxis()->SetTitleFont(132);
   wm_ptj_toterr__123->GetZaxis()->SetLabelFont(132);
   wm_ptj_toterr__123->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__123->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__123->GetZaxis()->SetTitleFont(132);
   wm_ptj_toterr__123->Draw("e2same");
   Double_t xAxis102[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_staterr__124 = new TH1F("wm_ptj_staterr__124","wm_ptj",5, xAxis102);
   wm_ptj_staterr__124->SetBinContent(1,2.161372);
   wm_ptj_staterr__124->SetBinContent(2,1.324459);
   wm_ptj_staterr__124->SetBinContent(3,0.7447754);
   wm_ptj_staterr__124->SetBinContent(4,0.3862884);
   wm_ptj_staterr__124->SetBinContent(5,0.07929422);
   wm_ptj_staterr__124->SetBinContent(6,3.964711);
   wm_ptj_staterr__124->SetBinError(1,0.01981714);
   wm_ptj_staterr__124->SetBinError(2,0.01549705);
   wm_ptj_staterr__124->SetBinError(3,0.008176924);
   wm_ptj_staterr__124->SetBinError(4,0.00603614);
   wm_ptj_staterr__124->SetBinError(5,0.001217149);
   wm_ptj_staterr__124->SetBinError(6,0.06085747);
   wm_ptj_staterr__124->SetMinimum(0.05);
   wm_ptj_staterr__124->SetMaximum(5);
   wm_ptj_staterr__124->SetEntries(12);
   wm_ptj_staterr__124->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__124->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__124->SetLineColor(ci);
   wm_ptj_staterr__124->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__124->SetMarkerColor(ci);
   wm_ptj_staterr__124->SetMarkerStyle(0);
   wm_ptj_staterr__124->GetXaxis()->SetNdivisions(4);
   wm_ptj_staterr__124->GetXaxis()->SetLabelFont(132);
   wm_ptj_staterr__124->GetXaxis()->SetLabelOffset(999);
   wm_ptj_staterr__124->GetXaxis()->SetLabelSize(0);
   wm_ptj_staterr__124->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__124->GetXaxis()->SetTitleFont(132);
   wm_ptj_staterr__124->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wm_ptj_staterr__124->GetYaxis()->SetLabelFont(132);
   wm_ptj_staterr__124->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__124->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__124->GetYaxis()->SetTitleFont(132);
   wm_ptj_staterr__124->GetZaxis()->SetLabelFont(132);
   wm_ptj_staterr__124->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__124->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__124->GetZaxis()->SetTitleFont(132);
   wm_ptj_staterr__124->Draw("e2same");
   
   Double_t ptj_plus_toterrs_fx3145[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_plus_toterrs_fy3145[5] = {
   3.781269,
   2.471324,
   1.346271,
   0.6736161,
   0.1720625};
   Double_t ptj_plus_toterrs_felx3145[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fely3145[5] = {
   0.2880126,
   0.2336951,
   0.09951573,
   0.04524418,
   0.01969193};
   Double_t ptj_plus_toterrs_fehx3145[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fehy3145[5] = {
   0.237181,
   0.1691029,
   0.09861914,
   0.05727119,
   0.01814489};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,ptj_plus_toterrs_fx3145,ptj_plus_toterrs_fy3145,ptj_plus_toterrs_felx3145,ptj_plus_toterrs_fehx3145,ptj_plus_toterrs_fely3145,ptj_plus_toterrs_fehy3145);
   grae->SetName("ptj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_ptj_plus_toterrs306131293145 = new TH1F("Graph_Graph_Graph_ptj_plus_toterrs306131293145","",100,17.325,88.425);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->SetMinimum(0.05);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->SetMaximum(5);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->SetDirectory(0);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->SetStats(0);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->SetLineWidth(2);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->SetMarkerStyle(0);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_plus_toterrs306131293145->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_ptj_plus_toterrs306131293145);
   
   grae->Draw("p1p");
   
   Double_t ptj_plus_toterrs_fx3146[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_plus_toterrs_fy3146[5] = {
   3.747404,
   2.382393,
   1.378484,
   0.718633,
   0.1890381};
   Double_t ptj_plus_toterrs_felx3146[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fely3146[5] = {
   0.2766023,
   0.1785285,
   0.1117659,
   0.05911753,
   0.01596438};
   Double_t ptj_plus_toterrs_fehx3146[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fehy3146[5] = {
   0.2834241,
   0.1899127,
   0.1152294,
   0.06511091,
   0.01862706};
   grae = new TGraphAsymmErrors(5,ptj_plus_toterrs_fx3146,ptj_plus_toterrs_fy3146,ptj_plus_toterrs_felx3146,ptj_plus_toterrs_fehx3146,ptj_plus_toterrs_fely3146,ptj_plus_toterrs_fehy3146);
   grae->SetName("ptj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_ptj_plus_toterrs306331303146 = new TH1F("Graph_Graph_Graph_ptj_plus_toterrs306331303146","",100,17.175,72.075);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->SetMinimum(0.05);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->SetMaximum(5);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->SetDirectory(0);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->SetStats(0);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->SetLineWidth(2);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->SetMarkerStyle(0);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_plus_toterrs306331303146->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_ptj_plus_toterrs306331303146);
   
   grae->Draw("p1p");
   
   Double_t ptj_minus_toterrs_fx3147[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_minus_toterrs_fy3147[5] = {
   2.562893,
   1.476188,
   0.8436134,
   0.4057886,
   0.09869911};
   Double_t ptj_minus_toterrs_felx3147[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fely3147[5] = {
   0.266341,
   0.1072309,
   0.08437284,
   0.03839483,
   0.01553516};
   Double_t ptj_minus_toterrs_fehx3147[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fehy3147[5] = {
   0.1762218,
   0.2029888,
   0.07273972,
   0.04002159,
   0.01249906};
   grae = new TGraphAsymmErrors(5,ptj_minus_toterrs_fx3147,ptj_minus_toterrs_fy3147,ptj_minus_toterrs_felx3147,ptj_minus_toterrs_fehx3147,ptj_minus_toterrs_fely3147,ptj_minus_toterrs_fehy3147);
   grae->SetName("ptj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_ptj_minus_toterrs307331313147 = new TH1F("Graph_Graph_Graph_ptj_minus_toterrs307331313147","",100,17.325,88.425);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->SetMinimum(0.05);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->SetMaximum(5);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->SetDirectory(0);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->SetStats(0);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->SetLineWidth(2);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->SetMarkerStyle(0);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_minus_toterrs307331313147->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_ptj_minus_toterrs307331313147);
   
   grae->Draw("p1p");
   
   Double_t ptj_minus_toterrs_fx3148[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_minus_toterrs_fy3148[5] = {
   2.425233,
   1.507886,
   0.829673,
   0.4212834,
   0.1045012};
   Double_t ptj_minus_toterrs_felx3148[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fely3148[5] = {
   0.1865384,
   0.1193402,
   0.06892636,
   0.03735492,
   0.01026445};
   Double_t ptj_minus_toterrs_fehx3148[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fehy3148[5] = {
   0.1902493,
   0.1251425,
   0.0772211,
   0.04040276,
   0.01118462};
   grae = new TGraphAsymmErrors(5,ptj_minus_toterrs_fx3148,ptj_minus_toterrs_fy3148,ptj_minus_toterrs_felx3148,ptj_minus_toterrs_fehx3148,ptj_minus_toterrs_fely3148,ptj_minus_toterrs_fehy3148);
   grae->SetName("ptj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_ptj_minus_toterrs307531323148 = new TH1F("Graph_Graph_Graph_ptj_minus_toterrs307531323148","",100,17.175,72.075);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->SetMinimum(0.05);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->SetMaximum(5);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->SetDirectory(0);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->SetStats(0);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->SetLineWidth(2);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->SetMarkerStyle(0);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_ptj_minus_toterrs307531323148->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_ptj_minus_toterrs307531323148);
   
   grae->Draw("p1p");
   
   Double_t _fx3149[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3149[5] = {
   3.781269,
   2.471324,
   1.346271,
   0.6736161,
   0.1720625};
   Double_t _felx3149[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3149[5] = {
   0.190572,
   0.1353315,
   0.0746666,
   0.03416157,
   0.01098946};
   Double_t _fehx3149[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3149[5] = {
   0.1784855,
   0.1300753,
   0.07322493,
   0.03857584,
   0.01318213};
   grae = new TGraphAsymmErrors(5,_fx3149,_fy3149,_felx3149,_fehx3149,_fely3149,_fehy3149);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph306231333149 = new TH1F("Graph_Graph_Graph_Graph306231333149","",100,17.325,88.425);
   Graph_Graph_Graph_Graph306231333149->SetMinimum(0.05);
   Graph_Graph_Graph_Graph306231333149->SetMaximum(5);
   Graph_Graph_Graph_Graph306231333149->SetDirectory(0);
   Graph_Graph_Graph_Graph306231333149->SetStats(0);
   Graph_Graph_Graph_Graph306231333149->SetLineWidth(2);
   Graph_Graph_Graph_Graph306231333149->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph306231333149->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph306231333149->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306231333149->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph306231333149->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph306231333149->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306231333149->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306231333149->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph306231333149->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306231333149->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306231333149->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306231333149->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306231333149->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306231333149->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306231333149->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306231333149->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph306231333149);
   
   grae->Draw("p1p");
   
   Double_t _fx3150[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3150[5] = {
   3.747404,
   2.382393,
   1.378484,
   0.718633,
   0.1890381};
   Double_t _felx3150[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3150[5] = {
   0.2195713,
   0.1431244,
   0.08659163,
   0.04658484,
   0.01299852};
   Double_t _fehx3150[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3150[5] = {
   0.2285816,
   0.1531721,
   0.09393196,
   0.05202641,
   0.01532503};
   grae = new TGraphAsymmErrors(5,_fx3150,_fy3150,_felx3150,_fehx3150,_fely3150,_fehy3150);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph306431343150 = new TH1F("Graph_Graph_Graph_Graph306431343150","",100,17.175,72.075);
   Graph_Graph_Graph_Graph306431343150->SetMinimum(0.05);
   Graph_Graph_Graph_Graph306431343150->SetMaximum(5);
   Graph_Graph_Graph_Graph306431343150->SetDirectory(0);
   Graph_Graph_Graph_Graph306431343150->SetStats(0);
   Graph_Graph_Graph_Graph306431343150->SetLineWidth(2);
   Graph_Graph_Graph_Graph306431343150->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph306431343150->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph306431343150->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306431343150->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph306431343150->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph306431343150->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306431343150->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306431343150->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph306431343150->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306431343150->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306431343150->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306431343150->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306431343150->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306431343150->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306431343150->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306431343150->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph306431343150);
   
   grae->Draw("p1p");
   
   Double_t _fx3151[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3151[5] = {
   2.562893,
   1.476188,
   0.8436134,
   0.4057886,
   0.09869911};
   Double_t _felx3151[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3151[5] = {
   0.1369467,
   0.0783433,
   0.04753537,
   0.0220407,
   0.007140055};
   Double_t _fehx3151[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3151[5] = {
   0.1275658,
   0.07309179,
   0.05322437,
   0.02140498,
   0.009120522};
   grae = new TGraphAsymmErrors(5,_fx3151,_fy3151,_felx3151,_fehx3151,_fely3151,_fehy3151);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph307431353151 = new TH1F("Graph_Graph_Graph_Graph307431353151","",100,17.325,88.425);
   Graph_Graph_Graph_Graph307431353151->SetMinimum(0.05);
   Graph_Graph_Graph_Graph307431353151->SetMaximum(5);
   Graph_Graph_Graph_Graph307431353151->SetDirectory(0);
   Graph_Graph_Graph_Graph307431353151->SetStats(0);
   Graph_Graph_Graph_Graph307431353151->SetLineWidth(2);
   Graph_Graph_Graph_Graph307431353151->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph307431353151->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph307431353151->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307431353151->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph307431353151->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph307431353151->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307431353151->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307431353151->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph307431353151->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307431353151->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307431353151->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307431353151->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307431353151->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307431353151->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307431353151->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307431353151->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph307431353151);
   
   grae->Draw("p1p");
   
   Double_t _fx3152[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3152[5] = {
   2.425233,
   1.507886,
   0.829673,
   0.4212834,
   0.1045012};
   Double_t _felx3152[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3152[5] = {
   0.1399179,
   0.08881254,
   0.05086884,
   0.02694438,
   0.006972694};
   Double_t _fehx3152[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3152[5] = {
   0.1450405,
   0.09567509,
   0.05554514,
   0.02997656,
   0.007936096};
   grae = new TGraphAsymmErrors(5,_fx3152,_fy3152,_felx3152,_fehx3152,_fely3152,_fehy3152);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph307631363152 = new TH1F("Graph_Graph_Graph_Graph307631363152","",100,17.175,72.075);
   Graph_Graph_Graph_Graph307631363152->SetMinimum(0.05);
   Graph_Graph_Graph_Graph307631363152->SetMaximum(5);
   Graph_Graph_Graph_Graph307631363152->SetDirectory(0);
   Graph_Graph_Graph_Graph307631363152->SetStats(0);
   Graph_Graph_Graph_Graph307631363152->SetLineWidth(2);
   Graph_Graph_Graph_Graph307631363152->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph307631363152->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph307631363152->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307631363152->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph307631363152->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph307631363152->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307631363152->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307631363152->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph307631363152->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307631363152->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307631363152->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307631363152->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307631363152->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307631363152->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307631363152->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307631363152->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph307631363152);
   
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
   Double_t xAxis103[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_toterr_copy__125 = new TH1F("wp_ptj_toterr_copy__125","wp_ptj",5, xAxis103);
   wp_ptj_toterr_copy__125->SetBinContent(1,3.450959);
   wp_ptj_toterr_copy__125->SetBinContent(2,2.256658);
   wp_ptj_toterr_copy__125->SetBinContent(3,1.266894);
   wp_ptj_toterr_copy__125->SetBinContent(4,0.667355);
   wp_ptj_toterr_copy__125->SetBinContent(5,0.1635365);
   wp_ptj_toterr_copy__125->SetBinContent(6,8.176826);
   wp_ptj_toterr_copy__125->SetBinError(1,0.2914732);
   wp_ptj_toterr_copy__125->SetBinError(2,0.2298212);
   wp_ptj_toterr_copy__125->SetBinError(3,0.117779);
   wp_ptj_toterr_copy__125->SetBinError(4,0.07112221);
   wp_ptj_toterr_copy__125->SetBinError(5,0.02028571);
   wp_ptj_toterr_copy__125->SetBinError(6,1.014286);
   wp_ptj_toterr_copy__125->SetMinimum(0.05);
   wp_ptj_toterr_copy__125->SetMaximum(5);
   wp_ptj_toterr_copy__125->SetEntries(12);
   wp_ptj_toterr_copy__125->SetDirectory(0);
   wp_ptj_toterr_copy__125->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__125->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__125->SetLineColor(ci);
   wp_ptj_toterr_copy__125->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__125->SetMarkerColor(ci);
   wp_ptj_toterr_copy__125->SetMarkerStyle(0);
   wp_ptj_toterr_copy__125->GetXaxis()->SetNdivisions(4);
   wp_ptj_toterr_copy__125->GetXaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__125->GetXaxis()->SetLabelOffset(999);
   wp_ptj_toterr_copy__125->GetXaxis()->SetLabelSize(0);
   wp_ptj_toterr_copy__125->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__125->GetXaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__125->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_toterr_copy__125->GetYaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__125->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__125->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__125->GetYaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__125->GetZaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__125->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__125->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__125->GetZaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__125->Draw("sameaxis");
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
   Double_t xAxis104[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_870_1001_2ratiocomp0__126 = new TH1F("wj_ptj_8TeV_log_870_1001_2ratiocomp0__126","wm_ptj",5, xAxis104);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinContent(1,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinContent(2,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinContent(3,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinContent(4,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinContent(5,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinContent(6,3.964711);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinError(1,0.100025);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinError(2,0.1145886);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinError(3,0.1075556);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinError(4,0.1151801);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinError(5,0.1605053);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetBinError(6,0.636357);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetMinimum(0.61);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetMaximum(1.59);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetEntries(17);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetLineColor(ci);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetMarkerColor(ci);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->SetMarkerStyle(0);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0__126->Draw("e2");
   Double_t xAxis105[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_870_1001_2ratiocomp1__127 = new TH1F("wj_ptj_8TeV_log_870_1001_2ratiocomp1__127","wm_ptj",5, xAxis105);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinContent(1,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinContent(2,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinContent(3,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinContent(4,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinContent(5,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinContent(6,3.964711);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinError(1,0.009168779);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinError(2,0.01170067);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinError(3,0.01097905);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinError(4,0.01562599);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinError(5,0.01534979);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetBinError(6,0.06085747);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetMinimum(0.61);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetMaximum(1.59);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetEntries(17);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetLineColor(ci);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetMarkerColor(ci);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->SetMarkerStyle(0);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp1__127->Draw("e2same");
   
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp2_fx3153[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp2_fy3153[5] = {
   1.185772,
   1.114559,
   1.132708,
   1.050481,
   1.24472};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp2_felx3153[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp2_fely3153[5] = {
   0.1232278,
   0.08096209,
   0.1132863,
   0.09939422,
   0.1959179};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp2_fehx3153[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp2_fehy3153[5] = {
   0.08153238,
   0.1532617,
   0.09766665,
   0.1036055,
   0.1576289};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_870_1001_2ratiocomp2_fx3153,wj_ptj_8TeV_log_870_1001_2ratiocomp2_fy3153,wj_ptj_8TeV_log_870_1001_2ratiocomp2_felx3153,wj_ptj_8TeV_log_870_1001_2ratiocomp2_fehx3153,wj_ptj_8TeV_log_870_1001_2ratiocomp2_fely3153,wj_ptj_8TeV_log_870_1001_2ratiocomp2_fehy3153);
   grae->SetName("wj_ptj_8TeV_log_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153 = new TH1F("Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->SetStats(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp23153);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp3_fx3154[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp3_fy3154[5] = {
   1.12208,
   1.138492,
   1.113991,
   1.090593,
   1.317891};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp3_felx3154[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp3_fely3154[5] = {
   0.08630558,
   0.09010488,
   0.09254651,
   0.09670217,
   0.1294476};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp3_fehx3154[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp3_fehy3154[5] = {
   0.08802248,
   0.09448576,
   0.1036837,
   0.1045922,
   0.1410521};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_870_1001_2ratiocomp3_fx3154,wj_ptj_8TeV_log_870_1001_2ratiocomp3_fy3154,wj_ptj_8TeV_log_870_1001_2ratiocomp3_felx3154,wj_ptj_8TeV_log_870_1001_2ratiocomp3_fehx3154,wj_ptj_8TeV_log_870_1001_2ratiocomp3_fely3154,wj_ptj_8TeV_log_870_1001_2ratiocomp3_fehy3154);
   grae->SetName("wj_ptj_8TeV_log_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154 = new TH1F("Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->SetStats(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp33154);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp4_fx3155[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp4_fy3155[5] = {
   1.185772,
   1.114559,
   1.132708,
   1.050481,
   1.24472};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp4_felx3155[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp4_fely3155[5] = {
   0.063361,
   0.05915119,
   0.06382511,
   0.05705763,
   0.09004508};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp4_fehx3155[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp4_fehy3155[5] = {
   0.05902074,
   0.05518617,
   0.07146365,
   0.05541192,
   0.1150213};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_870_1001_2ratiocomp4_fx3155,wj_ptj_8TeV_log_870_1001_2ratiocomp4_fy3155,wj_ptj_8TeV_log_870_1001_2ratiocomp4_felx3155,wj_ptj_8TeV_log_870_1001_2ratiocomp4_fehx3155,wj_ptj_8TeV_log_870_1001_2ratiocomp4_fely3155,wj_ptj_8TeV_log_870_1001_2ratiocomp4_fehy3155);
   grae->SetName("wj_ptj_8TeV_log_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155 = new TH1F("Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->SetStats(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp43155);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp5_fx3156[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp5_fy3156[5] = {
   1.12208,
   1.138492,
   1.113991,
   1.090593,
   1.317891};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp5_felx3156[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp5_fely3156[5] = {
   0.06473572,
   0.06705573,
   0.06830092,
   0.06975197,
   0.08793446};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp5_fehx3156[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_870_1001_2ratiocomp5_fehy3156[5] = {
   0.06710577,
   0.07223713,
   0.07457972,
   0.0776015,
   0.1000842};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_870_1001_2ratiocomp5_fx3156,wj_ptj_8TeV_log_870_1001_2ratiocomp5_fy3156,wj_ptj_8TeV_log_870_1001_2ratiocomp5_felx3156,wj_ptj_8TeV_log_870_1001_2ratiocomp5_fehx3156,wj_ptj_8TeV_log_870_1001_2ratiocomp5_fely3156,wj_ptj_8TeV_log_870_1001_2ratiocomp5_fehy3156);
   grae->SetName("wj_ptj_8TeV_log_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156 = new TH1F("Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->SetStats(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_870_1001_2ratiocomp53156);
   
   grae->Draw("p1");
   Double_t xAxis106[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128 = new TH1F("wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128","wm_ptj",5, xAxis106);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinContent(1,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinContent(2,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinContent(3,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinContent(4,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinContent(5,1);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinContent(6,3.964711);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinError(1,0.100025);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinError(2,0.1145886);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinError(3,0.1075556);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinError(4,0.1151801);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinError(5,0.1605053);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetBinError(6,0.636357);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetMinimum(0.61);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetMaximum(1.59);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetEntries(17);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetDirectory(0);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetLineColor(ci);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetMarkerColor(ci);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->SetMarkerStyle(0);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_870_1001_2ratiocomp0_copy__128->Draw("sameaxis");
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
   Double_t xAxis107[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_400_1001_0ratiocomp0__129 = new TH1F("wj_ptj_8TeV_log_400_1001_0ratiocomp0__129","wp_ptj",5, xAxis107);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinContent(1,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinContent(2,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinContent(3,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinContent(4,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinContent(5,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinContent(6,8.176826);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinError(1,0.08446152);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinError(2,0.1018414);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinError(3,0.09296672);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinError(4,0.1065733);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinError(5,0.1240439);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetBinError(6,1.014286);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetMinimum(0.61);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetMaximum(1.59);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetEntries(17);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetLineColor(ci);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetMarkerColor(ci);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->SetMarkerStyle(0);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0__129->Draw("e2");
   Double_t xAxis108[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_400_1001_0ratiocomp1__130 = new TH1F("wj_ptj_8TeV_log_400_1001_0ratiocomp1__130","wp_ptj",5, xAxis108);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinContent(1,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinContent(2,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinContent(3,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinContent(4,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinContent(5,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinContent(6,8.176826);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinError(1,0.007236058);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinError(2,0.008949443);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinError(3,0.008471081);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinError(4,0.01185315);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinError(5,0.01087072);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetBinError(6,0.08888796);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetMinimum(0.61);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetMaximum(1.59);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetEntries(17);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetLineColor(ci);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetMarkerColor(ci);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->SetMarkerStyle(0);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp1__130->Draw("e2same");
   
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp2_fx3157[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp2_fy3157[5] = {
   1.095715,
   1.095126,
   1.062654,
   1.009382,
   1.052135};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp2_felx3157[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp2_fely3157[5] = {
   0.08345872,
   0.103558,
   0.07855093,
   0.06779626,
   0.120413};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp2_fehx3157[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp2_fehy3157[5] = {
   0.068729,
   0.07493511,
   0.07784322,
   0.08581818,
   0.1109532};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_400_1001_0ratiocomp2_fx3157,wj_ptj_8TeV_log_400_1001_0ratiocomp2_fy3157,wj_ptj_8TeV_log_400_1001_0ratiocomp2_felx3157,wj_ptj_8TeV_log_400_1001_0ratiocomp2_fehx3157,wj_ptj_8TeV_log_400_1001_0ratiocomp2_fely3157,wj_ptj_8TeV_log_400_1001_0ratiocomp2_fehy3157);
   grae->SetName("wj_ptj_8TeV_log_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157 = new TH1F("Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->SetStats(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp23157);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp3_fx3158[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp3_fy3158[5] = {
   1.085902,
   1.055717,
   1.088081,
   1.076838,
   1.155938};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp3_felx3158[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp3_fely3158[5] = {
   0.0801523,
   0.07911191,
   0.0882204,
   0.08858483,
   0.0976197};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp3_fehx3158[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp3_fehy3158[5] = {
   0.08212909,
   0.08415661,
   0.09095427,
   0.09756563,
   0.1139015};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_400_1001_0ratiocomp3_fx3158,wj_ptj_8TeV_log_400_1001_0ratiocomp3_fy3158,wj_ptj_8TeV_log_400_1001_0ratiocomp3_felx3158,wj_ptj_8TeV_log_400_1001_0ratiocomp3_fehx3158,wj_ptj_8TeV_log_400_1001_0ratiocomp3_fely3158,wj_ptj_8TeV_log_400_1001_0ratiocomp3_fehy3158);
   grae->SetName("wj_ptj_8TeV_log_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158 = new TH1F("Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->SetStats(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp33158);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp4_fx3159[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp4_fy3159[5] = {
   1.095715,
   1.095126,
   1.062654,
   1.009382,
   1.052135};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp4_felx3159[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp4_fely3159[5] = {
   0.05522291,
   0.0599699,
   0.05893672,
   0.0511895,
   0.0671988};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp4_fehx3159[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp4_fehy3159[5] = {
   0.05172055,
   0.05764067,
   0.05779876,
   0.05780408,
   0.08060662};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_400_1001_0ratiocomp4_fx3159,wj_ptj_8TeV_log_400_1001_0ratiocomp4_fy3159,wj_ptj_8TeV_log_400_1001_0ratiocomp4_felx3159,wj_ptj_8TeV_log_400_1001_0ratiocomp4_fehx3159,wj_ptj_8TeV_log_400_1001_0ratiocomp4_fely3159,wj_ptj_8TeV_log_400_1001_0ratiocomp4_fehy3159);
   grae->SetName("wj_ptj_8TeV_log_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159 = new TH1F("Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->SetStats(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp43159);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp5_fx3160[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp5_fy3160[5] = {
   1.085902,
   1.055717,
   1.088081,
   1.076838,
   1.155938};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp5_felx3160[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp5_fely3160[5] = {
   0.06362618,
   0.06342317,
   0.06834952,
   0.06980519,
   0.07948393};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp5_fehx3160[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_400_1001_0ratiocomp5_fehy3160[5] = {
   0.06623714,
   0.06787565,
   0.07414348,
   0.07795913,
   0.09371016};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_400_1001_0ratiocomp5_fx3160,wj_ptj_8TeV_log_400_1001_0ratiocomp5_fy3160,wj_ptj_8TeV_log_400_1001_0ratiocomp5_felx3160,wj_ptj_8TeV_log_400_1001_0ratiocomp5_fehx3160,wj_ptj_8TeV_log_400_1001_0ratiocomp5_fely3160,wj_ptj_8TeV_log_400_1001_0ratiocomp5_fehy3160);
   grae->SetName("wj_ptj_8TeV_log_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160 = new TH1F("Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->SetStats(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_400_1001_0ratiocomp53160);
   
   grae->Draw("p1");
   Double_t xAxis109[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131 = new TH1F("wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131","wp_ptj",5, xAxis109);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinContent(1,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinContent(2,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinContent(3,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinContent(4,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinContent(5,1);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinContent(6,8.176826);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinError(1,0.08446152);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinError(2,0.1018414);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinError(3,0.09296672);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinError(4,0.1065733);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinError(5,0.1240439);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetBinError(6,1.014286);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetMinimum(0.61);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetMaximum(1.59);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetEntries(17);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetDirectory(0);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetLineColor(ci);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetMarkerColor(ci);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->SetMarkerStyle(0);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__131->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
