void wj_ptj_8TeV_log_logx()
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
   
   TH1F *__132 = new TH1F("__132","",1,0,1);
   __132->SetDirectory(0);
   __132->SetStats(0);
   __132->SetFillStyle(0);
   __132->SetLineWidth(2);
   __132->SetMarkerStyle(0);
   __132->GetXaxis()->SetNdivisions(4);
   __132->GetXaxis()->SetLabelFont(132);
   __132->GetXaxis()->SetLabelOffset(999);
   __132->GetXaxis()->SetLabelSize(0);
   __132->GetXaxis()->SetTitleSize(0.06);
   __132->GetXaxis()->SetTitleFont(132);
   __132->GetYaxis()->SetTitle("Ratio");
   __132->GetYaxis()->CenterTitle(true);
   __132->GetYaxis()->SetLabelFont(132);
   __132->GetYaxis()->SetLabelOffset(999);
   __132->GetYaxis()->SetLabelSize(0.05);
   __132->GetYaxis()->SetTitleSize(0.06);
   __132->GetYaxis()->SetTitleFont(132);
   __132->GetZaxis()->SetLabelFont(132);
   __132->GetZaxis()->SetLabelSize(0.05);
   __132->GetZaxis()->SetTitleSize(0.06);
   __132->GetZaxis()->SetTitleFont(132);
   __132->Draw("");
   
   TH1F *_copy__133 = new TH1F("_copy__133","",1,0,1);
   _copy__133->SetDirectory(0);
   _copy__133->SetStats(0);
   _copy__133->SetFillStyle(0);
   _copy__133->SetLineWidth(2);
   _copy__133->SetMarkerStyle(0);
   _copy__133->GetXaxis()->SetNdivisions(4);
   _copy__133->GetXaxis()->SetLabelFont(132);
   _copy__133->GetXaxis()->SetLabelOffset(999);
   _copy__133->GetXaxis()->SetLabelSize(0);
   _copy__133->GetXaxis()->SetTitleSize(0.06);
   _copy__133->GetXaxis()->SetTitleFont(132);
   _copy__133->GetYaxis()->SetTitle("Ratio");
   _copy__133->GetYaxis()->CenterTitle(true);
   _copy__133->GetYaxis()->SetLabelFont(132);
   _copy__133->GetYaxis()->SetLabelOffset(999);
   _copy__133->GetYaxis()->SetLabelSize(0.05);
   _copy__133->GetYaxis()->SetTitleSize(0.06);
   _copy__133->GetYaxis()->SetTitleFont(132);
   _copy__133->GetZaxis()->SetLabelFont(132);
   _copy__133->GetZaxis()->SetLabelSize(0.05);
   _copy__133->GetZaxis()->SetTitleSize(0.06);
   _copy__133->GetZaxis()->SetTitleFont(132);
   _copy__133->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(1.18022,-2.819548,2.043146,0.8841552);
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
   Double_t xAxis110[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_toterr__134 = new TH1F("wp_ptj_toterr__134","wp_ptj",5, xAxis110);
   wp_ptj_toterr__134->SetBinContent(1,3.450959);
   wp_ptj_toterr__134->SetBinContent(2,2.256658);
   wp_ptj_toterr__134->SetBinContent(3,1.266894);
   wp_ptj_toterr__134->SetBinContent(4,0.667355);
   wp_ptj_toterr__134->SetBinContent(5,0.1635365);
   wp_ptj_toterr__134->SetBinContent(6,8.176826);
   wp_ptj_toterr__134->SetBinError(1,0.2914732);
   wp_ptj_toterr__134->SetBinError(2,0.2298212);
   wp_ptj_toterr__134->SetBinError(3,0.117779);
   wp_ptj_toterr__134->SetBinError(4,0.07112221);
   wp_ptj_toterr__134->SetBinError(5,0.02028571);
   wp_ptj_toterr__134->SetBinError(6,1.014286);
   wp_ptj_toterr__134->SetMinimum(0.05);
   wp_ptj_toterr__134->SetMaximum(5);
   wp_ptj_toterr__134->SetEntries(12);
   wp_ptj_toterr__134->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__134->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__134->SetLineColor(ci);
   wp_ptj_toterr__134->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__134->SetMarkerColor(ci);
   wp_ptj_toterr__134->SetMarkerStyle(0);
   wp_ptj_toterr__134->GetXaxis()->SetNdivisions(505);
   wp_ptj_toterr__134->GetXaxis()->SetLabelFont(132);
   wp_ptj_toterr__134->GetXaxis()->SetLabelOffset(999);
   wp_ptj_toterr__134->GetXaxis()->SetLabelSize(0);
   wp_ptj_toterr__134->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__134->GetXaxis()->SetTitleFont(132);
   wp_ptj_toterr__134->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_toterr__134->GetYaxis()->SetLabelFont(132);
   wp_ptj_toterr__134->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__134->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__134->GetYaxis()->SetTitleFont(132);
   wp_ptj_toterr__134->GetZaxis()->SetLabelFont(132);
   wp_ptj_toterr__134->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__134->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__134->GetZaxis()->SetTitleFont(132);
   wp_ptj_toterr__134->Draw("e2");
   Double_t xAxis111[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_staterr__135 = new TH1F("wp_ptj_staterr__135","wp_ptj",5, xAxis111);
   wp_ptj_staterr__135->SetBinContent(1,3.450959);
   wp_ptj_staterr__135->SetBinContent(2,2.256658);
   wp_ptj_staterr__135->SetBinContent(3,1.266894);
   wp_ptj_staterr__135->SetBinContent(4,0.667355);
   wp_ptj_staterr__135->SetBinContent(5,0.1635365);
   wp_ptj_staterr__135->SetBinContent(6,8.176826);
   wp_ptj_staterr__135->SetBinError(1,0.02497134);
   wp_ptj_staterr__135->SetBinError(2,0.02019583);
   wp_ptj_staterr__135->SetBinError(3,0.01073196);
   wp_ptj_staterr__135->SetBinError(4,0.007910258);
   wp_ptj_staterr__135->SetBinError(5,0.001777759);
   wp_ptj_staterr__135->SetBinError(6,0.08888796);
   wp_ptj_staterr__135->SetMinimum(0.05);
   wp_ptj_staterr__135->SetMaximum(5);
   wp_ptj_staterr__135->SetEntries(12);
   wp_ptj_staterr__135->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__135->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__135->SetLineColor(ci);
   wp_ptj_staterr__135->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__135->SetMarkerColor(ci);
   wp_ptj_staterr__135->SetMarkerStyle(0);
   wp_ptj_staterr__135->GetXaxis()->SetNdivisions(505);
   wp_ptj_staterr__135->GetXaxis()->SetLabelFont(132);
   wp_ptj_staterr__135->GetXaxis()->SetLabelOffset(999);
   wp_ptj_staterr__135->GetXaxis()->SetLabelSize(0);
   wp_ptj_staterr__135->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__135->GetXaxis()->SetTitleFont(132);
   wp_ptj_staterr__135->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_staterr__135->GetYaxis()->SetLabelFont(132);
   wp_ptj_staterr__135->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__135->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__135->GetYaxis()->SetTitleFont(132);
   wp_ptj_staterr__135->GetZaxis()->SetLabelFont(132);
   wp_ptj_staterr__135->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__135->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__135->GetZaxis()->SetTitleFont(132);
   wp_ptj_staterr__135->Draw("e2same");
   Double_t xAxis112[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_toterr__136 = new TH1F("wm_ptj_toterr__136","wm_ptj",5, xAxis112);
   wm_ptj_toterr__136->SetBinContent(1,2.161372);
   wm_ptj_toterr__136->SetBinContent(2,1.324459);
   wm_ptj_toterr__136->SetBinContent(3,0.7447754);
   wm_ptj_toterr__136->SetBinContent(4,0.3862884);
   wm_ptj_toterr__136->SetBinContent(5,0.07929422);
   wm_ptj_toterr__136->SetBinContent(6,3.964711);
   wm_ptj_toterr__136->SetBinError(1,0.2161911);
   wm_ptj_toterr__136->SetBinError(2,0.1517678);
   wm_ptj_toterr__136->SetBinError(3,0.08010473);
   wm_ptj_toterr__136->SetBinError(4,0.04449275);
   wm_ptj_toterr__136->SetBinError(5,0.01272714);
   wm_ptj_toterr__136->SetBinError(6,0.636357);
   wm_ptj_toterr__136->SetMinimum(0.05);
   wm_ptj_toterr__136->SetMaximum(5);
   wm_ptj_toterr__136->SetEntries(12);
   wm_ptj_toterr__136->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__136->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__136->SetLineColor(ci);
   wm_ptj_toterr__136->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_ptj_toterr__136->SetMarkerColor(ci);
   wm_ptj_toterr__136->SetMarkerStyle(0);
   wm_ptj_toterr__136->GetXaxis()->SetNdivisions(505);
   wm_ptj_toterr__136->GetXaxis()->SetLabelFont(132);
   wm_ptj_toterr__136->GetXaxis()->SetLabelOffset(999);
   wm_ptj_toterr__136->GetXaxis()->SetLabelSize(0);
   wm_ptj_toterr__136->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__136->GetXaxis()->SetTitleFont(132);
   wm_ptj_toterr__136->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wm_ptj_toterr__136->GetYaxis()->SetLabelFont(132);
   wm_ptj_toterr__136->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__136->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__136->GetYaxis()->SetTitleFont(132);
   wm_ptj_toterr__136->GetZaxis()->SetLabelFont(132);
   wm_ptj_toterr__136->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__136->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__136->GetZaxis()->SetTitleFont(132);
   wm_ptj_toterr__136->Draw("e2same");
   Double_t xAxis113[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_staterr__137 = new TH1F("wm_ptj_staterr__137","wm_ptj",5, xAxis113);
   wm_ptj_staterr__137->SetBinContent(1,2.161372);
   wm_ptj_staterr__137->SetBinContent(2,1.324459);
   wm_ptj_staterr__137->SetBinContent(3,0.7447754);
   wm_ptj_staterr__137->SetBinContent(4,0.3862884);
   wm_ptj_staterr__137->SetBinContent(5,0.07929422);
   wm_ptj_staterr__137->SetBinContent(6,3.964711);
   wm_ptj_staterr__137->SetBinError(1,0.01981714);
   wm_ptj_staterr__137->SetBinError(2,0.01549705);
   wm_ptj_staterr__137->SetBinError(3,0.008176924);
   wm_ptj_staterr__137->SetBinError(4,0.00603614);
   wm_ptj_staterr__137->SetBinError(5,0.001217149);
   wm_ptj_staterr__137->SetBinError(6,0.06085747);
   wm_ptj_staterr__137->SetMinimum(0.05);
   wm_ptj_staterr__137->SetMaximum(5);
   wm_ptj_staterr__137->SetEntries(12);
   wm_ptj_staterr__137->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__137->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__137->SetLineColor(ci);
   wm_ptj_staterr__137->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_ptj_staterr__137->SetMarkerColor(ci);
   wm_ptj_staterr__137->SetMarkerStyle(0);
   wm_ptj_staterr__137->GetXaxis()->SetNdivisions(505);
   wm_ptj_staterr__137->GetXaxis()->SetLabelFont(132);
   wm_ptj_staterr__137->GetXaxis()->SetLabelOffset(999);
   wm_ptj_staterr__137->GetXaxis()->SetLabelSize(0);
   wm_ptj_staterr__137->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__137->GetXaxis()->SetTitleFont(132);
   wm_ptj_staterr__137->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wm_ptj_staterr__137->GetYaxis()->SetLabelFont(132);
   wm_ptj_staterr__137->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__137->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__137->GetYaxis()->SetTitleFont(132);
   wm_ptj_staterr__137->GetZaxis()->SetLabelFont(132);
   wm_ptj_staterr__137->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__137->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__137->GetZaxis()->SetTitleFont(132);
   wm_ptj_staterr__137->Draw("e2same");
   
   Double_t ptj_plus_toterrs_fx3161[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_plus_toterrs_fy3161[5] = {
   3.781269,
   2.471324,
   1.346271,
   0.6736161,
   0.1720625};
   Double_t ptj_plus_toterrs_felx3161[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fely3161[5] = {
   0.2880126,
   0.2336951,
   0.09951573,
   0.04524418,
   0.01969193};
   Double_t ptj_plus_toterrs_fehx3161[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fehy3161[5] = {
   0.237181,
   0.1691029,
   0.09861914,
   0.05727119,
   0.01814489};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,ptj_plus_toterrs_fx3161,ptj_plus_toterrs_fy3161,ptj_plus_toterrs_felx3161,ptj_plus_toterrs_fehx3161,ptj_plus_toterrs_fely3161,ptj_plus_toterrs_fehy3161);
   grae->SetName("ptj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161 = new TH1F("Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161","",100,17.325,88.425);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->SetMinimum(0.05);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->SetMaximum(5);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->SetDirectory(0);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->SetStats(0);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->SetLineWidth(2);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_ptj_plus_toterrs3061312931453161);
   
   grae->Draw("p1p");
   
   Double_t ptj_plus_toterrs_fx3162[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_plus_toterrs_fy3162[5] = {
   3.747404,
   2.382393,
   1.378484,
   0.718633,
   0.1890381};
   Double_t ptj_plus_toterrs_felx3162[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fely3162[5] = {
   0.2766023,
   0.1785285,
   0.1117659,
   0.05911753,
   0.01596438};
   Double_t ptj_plus_toterrs_fehx3162[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fehy3162[5] = {
   0.2834241,
   0.1899127,
   0.1152294,
   0.06511091,
   0.01862706};
   grae = new TGraphAsymmErrors(5,ptj_plus_toterrs_fx3162,ptj_plus_toterrs_fy3162,ptj_plus_toterrs_felx3162,ptj_plus_toterrs_fehx3162,ptj_plus_toterrs_fely3162,ptj_plus_toterrs_fehy3162);
   grae->SetName("ptj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162 = new TH1F("Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162","",100,17.175,72.075);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->SetMinimum(0.05);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->SetMaximum(5);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->SetDirectory(0);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->SetStats(0);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->SetLineWidth(2);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_ptj_plus_toterrs3063313031463162);
   
   grae->Draw("p1p");
   
   Double_t ptj_minus_toterrs_fx3163[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_minus_toterrs_fy3163[5] = {
   2.562893,
   1.476188,
   0.8436134,
   0.4057886,
   0.09869911};
   Double_t ptj_minus_toterrs_felx3163[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fely3163[5] = {
   0.266341,
   0.1072309,
   0.08437284,
   0.03839483,
   0.01553516};
   Double_t ptj_minus_toterrs_fehx3163[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fehy3163[5] = {
   0.1762218,
   0.2029888,
   0.07273972,
   0.04002159,
   0.01249906};
   grae = new TGraphAsymmErrors(5,ptj_minus_toterrs_fx3163,ptj_minus_toterrs_fy3163,ptj_minus_toterrs_felx3163,ptj_minus_toterrs_fehx3163,ptj_minus_toterrs_fely3163,ptj_minus_toterrs_fehy3163);
   grae->SetName("ptj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163 = new TH1F("Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163","",100,17.325,88.425);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->SetMinimum(0.05);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->SetMaximum(5);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->SetDirectory(0);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->SetStats(0);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->SetLineWidth(2);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_ptj_minus_toterrs3073313131473163);
   
   grae->Draw("p1p");
   
   Double_t ptj_minus_toterrs_fx3164[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_minus_toterrs_fy3164[5] = {
   2.425233,
   1.507886,
   0.829673,
   0.4212834,
   0.1045012};
   Double_t ptj_minus_toterrs_felx3164[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fely3164[5] = {
   0.1865384,
   0.1193402,
   0.06892636,
   0.03735492,
   0.01026445};
   Double_t ptj_minus_toterrs_fehx3164[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fehy3164[5] = {
   0.1902493,
   0.1251425,
   0.0772211,
   0.04040276,
   0.01118462};
   grae = new TGraphAsymmErrors(5,ptj_minus_toterrs_fx3164,ptj_minus_toterrs_fy3164,ptj_minus_toterrs_felx3164,ptj_minus_toterrs_fehx3164,ptj_minus_toterrs_fely3164,ptj_minus_toterrs_fehy3164);
   grae->SetName("ptj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164 = new TH1F("Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164","",100,17.175,72.075);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->SetMinimum(0.05);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->SetMaximum(5);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->SetDirectory(0);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->SetStats(0);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->SetLineWidth(2);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_ptj_minus_toterrs3075313231483164);
   
   grae->Draw("p1p");
   
   Double_t _fx3165[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3165[5] = {
   3.781269,
   2.471324,
   1.346271,
   0.6736161,
   0.1720625};
   Double_t _felx3165[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3165[5] = {
   0.190572,
   0.1353315,
   0.0746666,
   0.03416157,
   0.01098946};
   Double_t _fehx3165[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3165[5] = {
   0.1784855,
   0.1300753,
   0.07322493,
   0.03857584,
   0.01318213};
   grae = new TGraphAsymmErrors(5,_fx3165,_fy3165,_felx3165,_fehx3165,_fely3165,_fehy3165);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3062313331493165 = new TH1F("Graph_Graph_Graph_Graph_Graph3062313331493165","",100,17.325,88.425);
   Graph_Graph_Graph_Graph_Graph3062313331493165->SetMinimum(0.05);
   Graph_Graph_Graph_Graph_Graph3062313331493165->SetMaximum(5);
   Graph_Graph_Graph_Graph_Graph3062313331493165->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3062313331493165->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3062313331493165->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3062313331493165->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3062313331493165->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3062313331493165);
   
   grae->Draw("p1p");
   
   Double_t _fx3166[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3166[5] = {
   3.747404,
   2.382393,
   1.378484,
   0.718633,
   0.1890381};
   Double_t _felx3166[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3166[5] = {
   0.2195713,
   0.1431244,
   0.08659163,
   0.04658484,
   0.01299852};
   Double_t _fehx3166[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3166[5] = {
   0.2285816,
   0.1531721,
   0.09393196,
   0.05202641,
   0.01532503};
   grae = new TGraphAsymmErrors(5,_fx3166,_fy3166,_felx3166,_fehx3166,_fely3166,_fehy3166);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3064313431503166 = new TH1F("Graph_Graph_Graph_Graph_Graph3064313431503166","",100,17.175,72.075);
   Graph_Graph_Graph_Graph_Graph3064313431503166->SetMinimum(0.05);
   Graph_Graph_Graph_Graph_Graph3064313431503166->SetMaximum(5);
   Graph_Graph_Graph_Graph_Graph3064313431503166->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3064313431503166->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3064313431503166->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3064313431503166->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3064313431503166->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3064313431503166);
   
   grae->Draw("p1p");
   
   Double_t _fx3167[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3167[5] = {
   2.562893,
   1.476188,
   0.8436134,
   0.4057886,
   0.09869911};
   Double_t _felx3167[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3167[5] = {
   0.1369467,
   0.0783433,
   0.04753537,
   0.0220407,
   0.007140055};
   Double_t _fehx3167[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3167[5] = {
   0.1275658,
   0.07309179,
   0.05322437,
   0.02140498,
   0.009120522};
   grae = new TGraphAsymmErrors(5,_fx3167,_fy3167,_felx3167,_fehx3167,_fely3167,_fehy3167);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3074313531513167 = new TH1F("Graph_Graph_Graph_Graph_Graph3074313531513167","",100,17.325,88.425);
   Graph_Graph_Graph_Graph_Graph3074313531513167->SetMinimum(0.05);
   Graph_Graph_Graph_Graph_Graph3074313531513167->SetMaximum(5);
   Graph_Graph_Graph_Graph_Graph3074313531513167->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3074313531513167->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3074313531513167->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3074313531513167->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3074313531513167->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3074313531513167);
   
   grae->Draw("p1p");
   
   Double_t _fx3168[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3168[5] = {
   2.425233,
   1.507886,
   0.829673,
   0.4212834,
   0.1045012};
   Double_t _felx3168[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3168[5] = {
   0.1399179,
   0.08881254,
   0.05086884,
   0.02694438,
   0.006972694};
   Double_t _fehx3168[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3168[5] = {
   0.1450405,
   0.09567509,
   0.05554514,
   0.02997656,
   0.007936096};
   grae = new TGraphAsymmErrors(5,_fx3168,_fy3168,_felx3168,_fehx3168,_fely3168,_fehy3168);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph_Graph3076313631523168 = new TH1F("Graph_Graph_Graph_Graph_Graph3076313631523168","",100,17.175,72.075);
   Graph_Graph_Graph_Graph_Graph3076313631523168->SetMinimum(0.05);
   Graph_Graph_Graph_Graph_Graph3076313631523168->SetMaximum(5);
   Graph_Graph_Graph_Graph_Graph3076313631523168->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph3076313631523168->SetStats(0);
   Graph_Graph_Graph_Graph_Graph3076313631523168->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph3076313631523168->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetXaxis()->SetNdivisions(505);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph3076313631523168->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph3076313631523168);
   
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
   Double_t xAxis114[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_toterr_copy__138 = new TH1F("wp_ptj_toterr_copy__138","wp_ptj",5, xAxis114);
   wp_ptj_toterr_copy__138->SetBinContent(1,3.450959);
   wp_ptj_toterr_copy__138->SetBinContent(2,2.256658);
   wp_ptj_toterr_copy__138->SetBinContent(3,1.266894);
   wp_ptj_toterr_copy__138->SetBinContent(4,0.667355);
   wp_ptj_toterr_copy__138->SetBinContent(5,0.1635365);
   wp_ptj_toterr_copy__138->SetBinContent(6,8.176826);
   wp_ptj_toterr_copy__138->SetBinError(1,0.2914732);
   wp_ptj_toterr_copy__138->SetBinError(2,0.2298212);
   wp_ptj_toterr_copy__138->SetBinError(3,0.117779);
   wp_ptj_toterr_copy__138->SetBinError(4,0.07112221);
   wp_ptj_toterr_copy__138->SetBinError(5,0.02028571);
   wp_ptj_toterr_copy__138->SetBinError(6,1.014286);
   wp_ptj_toterr_copy__138->SetMinimum(0.05);
   wp_ptj_toterr_copy__138->SetMaximum(5);
   wp_ptj_toterr_copy__138->SetEntries(12);
   wp_ptj_toterr_copy__138->SetDirectory(0);
   wp_ptj_toterr_copy__138->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__138->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__138->SetLineColor(ci);
   wp_ptj_toterr_copy__138->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__138->SetMarkerColor(ci);
   wp_ptj_toterr_copy__138->SetMarkerStyle(0);
   wp_ptj_toterr_copy__138->GetXaxis()->SetNdivisions(505);
   wp_ptj_toterr_copy__138->GetXaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__138->GetXaxis()->SetLabelOffset(999);
   wp_ptj_toterr_copy__138->GetXaxis()->SetLabelSize(0);
   wp_ptj_toterr_copy__138->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__138->GetXaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__138->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_toterr_copy__138->GetYaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__138->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__138->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__138->GetYaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__138->GetZaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__138->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__138->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__138->GetZaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__138->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.18022,-0.4062964,2.043146,6.852964);
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
   Double_t xAxis115[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139 = new TH1F("wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139","wm_ptj",5, xAxis115);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinContent(1,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinContent(2,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinContent(3,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinContent(4,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinContent(5,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinContent(6,3.964711);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinError(1,0.100025);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinError(2,0.1145886);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinError(3,0.1075556);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinError(4,0.1151801);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinError(5,0.1605053);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetBinError(6,0.636357);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetMinimum(0.61);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetMaximum(1.59);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetEntries(17);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetLineColor(ci);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetMarkerColor(ci);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->SetMarkerStyle(0);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0__139->Draw("e2");
   Double_t xAxis116[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140 = new TH1F("wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140","wm_ptj",5, xAxis116);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinContent(1,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinContent(2,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinContent(3,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinContent(4,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinContent(5,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinContent(6,3.964711);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinError(1,0.009168779);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinError(2,0.01170067);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinError(3,0.01097905);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinError(4,0.01562599);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinError(5,0.01534979);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetBinError(6,0.06085747);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetMinimum(0.61);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetMaximum(1.59);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetEntries(17);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetLineColor(ci);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetMarkerColor(ci);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->SetMarkerStyle(0);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp1__140->Draw("e2same");
   
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fx3169[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fy3169[5] = {
   1.185772,
   1.114559,
   1.132708,
   1.050481,
   1.24472};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_felx3169[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fely3169[5] = {
   0.1232278,
   0.08096209,
   0.1132863,
   0.09939422,
   0.1959179};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fehx3169[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fehy3169[5] = {
   0.08153238,
   0.1532617,
   0.09766665,
   0.1036055,
   0.1576289};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fx3169,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fy3169,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_felx3169,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fehx3169,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fely3169,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2_fehy3169);
   grae->SetName("wj_ptj_8TeV_log_logx_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169 = new TH1F("Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->SetStats(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp23169);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fx3170[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fy3170[5] = {
   1.12208,
   1.138492,
   1.113991,
   1.090593,
   1.317891};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_felx3170[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fely3170[5] = {
   0.08630558,
   0.09010488,
   0.09254651,
   0.09670217,
   0.1294476};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fehx3170[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fehy3170[5] = {
   0.08802248,
   0.09448576,
   0.1036837,
   0.1045922,
   0.1410521};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fx3170,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fy3170,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_felx3170,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fehx3170,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fely3170,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3_fehy3170);
   grae->SetName("wj_ptj_8TeV_log_logx_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170 = new TH1F("Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->SetStats(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp33170);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fx3171[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fy3171[5] = {
   1.185772,
   1.114559,
   1.132708,
   1.050481,
   1.24472};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_felx3171[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fely3171[5] = {
   0.063361,
   0.05915119,
   0.06382511,
   0.05705763,
   0.09004508};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fehx3171[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fehy3171[5] = {
   0.05902074,
   0.05518617,
   0.07146365,
   0.05541192,
   0.1150213};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fx3171,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fy3171,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_felx3171,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fehx3171,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fely3171,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4_fehy3171);
   grae->SetName("wj_ptj_8TeV_log_logx_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171 = new TH1F("Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->SetStats(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp43171);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fx3172[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fy3172[5] = {
   1.12208,
   1.138492,
   1.113991,
   1.090593,
   1.317891};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_felx3172[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fely3172[5] = {
   0.06473572,
   0.06705573,
   0.06830092,
   0.06975197,
   0.08793446};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fehx3172[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fehy3172[5] = {
   0.06710577,
   0.07223713,
   0.07457972,
   0.0776015,
   0.1000842};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fx3172,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fy3172,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_felx3172,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fehx3172,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fely3172,wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5_fehy3172);
   grae->SetName("wj_ptj_8TeV_log_logx_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172 = new TH1F("Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->SetStats(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_logx_870_1001_2ratiocomp53172);
   
   grae->Draw("p1");
   Double_t xAxis117[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141 = new TH1F("wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141","wm_ptj",5, xAxis117);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinContent(1,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinContent(2,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinContent(3,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinContent(4,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinContent(5,1);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinContent(6,3.964711);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinError(1,0.100025);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinError(2,0.1145886);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinError(3,0.1075556);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinError(4,0.1151801);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinError(5,0.1605053);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetBinError(6,0.636357);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetMinimum(0.61);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetMaximum(1.59);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetEntries(17);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetDirectory(0);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetLineColor(ci);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetMarkerColor(ci);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->SetMarkerStyle(0);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetXaxis()->SetLabelOffset(0.02);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetXaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_870_1001_2ratiocomp0_copy__141->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: middlPad
   TPad *middlPad = new TPad("middlPad", "middlPad",0.005,0.05,0.995,0.995);
   middlPad->Draw();
   middlPad->cd();
   middlPad->Range(1.18022,-1.214827,2.043146,5.543792);
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
   Double_t xAxis118[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142 = new TH1F("wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142","wp_ptj",5, xAxis118);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinContent(1,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinContent(2,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinContent(3,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinContent(4,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinContent(5,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinContent(6,8.176826);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinError(1,0.08446152);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinError(2,0.1018414);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinError(3,0.09296672);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinError(4,0.1065733);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinError(5,0.1240439);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetBinError(6,1.014286);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetMinimum(0.61);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetMaximum(1.59);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetEntries(17);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetLineColor(ci);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetMarkerColor(ci);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->SetMarkerStyle(0);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0__142->Draw("e2");
   Double_t xAxis119[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143 = new TH1F("wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143","wp_ptj",5, xAxis119);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinContent(1,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinContent(2,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinContent(3,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinContent(4,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinContent(5,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinContent(6,8.176826);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinError(1,0.007236058);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinError(2,0.008949443);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinError(3,0.008471081);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinError(4,0.01185315);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinError(5,0.01087072);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetBinError(6,0.08888796);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetMinimum(0.61);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetMaximum(1.59);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetEntries(17);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetLineColor(ci);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetMarkerColor(ci);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->SetMarkerStyle(0);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp1__143->Draw("e2same");
   
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fx3173[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fy3173[5] = {
   1.095715,
   1.095126,
   1.062654,
   1.009382,
   1.052135};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_felx3173[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fely3173[5] = {
   0.08345872,
   0.103558,
   0.07855093,
   0.06779626,
   0.120413};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fehx3173[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fehy3173[5] = {
   0.068729,
   0.07493511,
   0.07784322,
   0.08581818,
   0.1109532};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fx3173,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fy3173,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_felx3173,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fehx3173,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fely3173,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2_fehy3173);
   grae->SetName("wj_ptj_8TeV_log_logx_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173 = new TH1F("Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->SetStats(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp23173);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fx3174[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fy3174[5] = {
   1.085902,
   1.055717,
   1.088081,
   1.076838,
   1.155938};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_felx3174[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fely3174[5] = {
   0.0801523,
   0.07911191,
   0.0882204,
   0.08858483,
   0.0976197};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fehx3174[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fehy3174[5] = {
   0.08212909,
   0.08415661,
   0.09095427,
   0.09756563,
   0.1139015};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fx3174,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fy3174,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_felx3174,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fehx3174,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fely3174,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3_fehy3174);
   grae->SetName("wj_ptj_8TeV_log_logx_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174 = new TH1F("Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->SetStats(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp33174);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fx3175[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fy3175[5] = {
   1.095715,
   1.095126,
   1.062654,
   1.009382,
   1.052135};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_felx3175[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fely3175[5] = {
   0.05522291,
   0.0599699,
   0.05893672,
   0.0511895,
   0.0671988};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fehx3175[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fehy3175[5] = {
   0.05172055,
   0.05764067,
   0.05779876,
   0.05780408,
   0.08060662};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fx3175,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fy3175,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_felx3175,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fehx3175,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fely3175,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4_fehy3175);
   grae->SetName("wj_ptj_8TeV_log_logx_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175 = new TH1F("Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175","",100,17.325,88.425);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->SetStats(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp43175);
   
   grae->Draw("p1");
   
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fx3176[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fy3176[5] = {
   1.085902,
   1.055717,
   1.088081,
   1.076838,
   1.155938};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_felx3176[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fely3176[5] = {
   0.06362618,
   0.06342317,
   0.06834952,
   0.06980519,
   0.07948393};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fehx3176[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fehy3176[5] = {
   0.06623714,
   0.06787565,
   0.07414348,
   0.07795913,
   0.09371016};
   grae = new TGraphAsymmErrors(5,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fx3176,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fy3176,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_felx3176,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fehx3176,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fely3176,wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5_fehy3176);
   grae->SetName("wj_ptj_8TeV_log_logx_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176 = new TH1F("Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176","",100,17.175,72.075);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->SetMinimum(0.61);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->SetMaximum(1.59);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->SetDirectory(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->SetStats(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->SetLineWidth(2);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->SetMarkerStyle(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetXaxis()->SetNdivisions(4);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetXaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetXaxis()->SetLabelOffset(999);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetXaxis()->SetLabelSize(0);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetXaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetYaxis()->SetNdivisions(505);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetYaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetYaxis()->SetTitleFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetZaxis()->SetLabelFont(132);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ptj_8TeV_log_logx_400_1001_0ratiocomp53176);
   
   grae->Draw("p1");
   Double_t xAxis120[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144 = new TH1F("wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144","wp_ptj",5, xAxis120);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinContent(1,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinContent(2,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinContent(3,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinContent(4,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinContent(5,1);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinContent(6,8.176826);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinError(1,0.08446152);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinError(2,0.1018414);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinError(3,0.09296672);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinError(4,0.1065733);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinError(5,0.1240439);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetBinError(6,1.014286);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetMinimum(0.61);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetMaximum(1.59);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetEntries(17);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetDirectory(0);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetLineColor(ci);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetMarkerColor(ci);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->SetMarkerStyle(0);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetXaxis()->SetNdivisions(4);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetXaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetXaxis()->SetLabelOffset(999);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetXaxis()->SetLabelSize(0);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetXaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetXaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetYaxis()->SetNdivisions(505);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetYaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetYaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetYaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetYaxis()->SetTickLength(0.12325);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetYaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetZaxis()->SetLabelFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetZaxis()->SetLabelSize(0.05);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetZaxis()->SetTitleSize(0.06);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->GetZaxis()->SetTitleFont(132);
   wj_ptj_8TeV_log_logx_400_1001_0ratiocomp0_copy__144->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
