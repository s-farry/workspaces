void wj_eta_8TeV_log()
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
   
   TH1F *__158 = new TH1F("__158","",1,0,1);
   __158->SetDirectory(0);
   __158->SetStats(0);
   __158->SetFillStyle(0);
   __158->SetLineWidth(2);
   __158->SetMarkerStyle(0);
   __158->GetXaxis()->SetNdivisions(4);
   __158->GetXaxis()->SetLabelFont(132);
   __158->GetXaxis()->SetLabelOffset(999);
   __158->GetXaxis()->SetLabelSize(0);
   __158->GetXaxis()->SetTitleSize(0.06);
   __158->GetXaxis()->SetTitleFont(132);
   __158->GetYaxis()->SetTitle("Ratio");
   __158->GetYaxis()->CenterTitle(true);
   __158->GetYaxis()->SetLabelFont(132);
   __158->GetYaxis()->SetLabelOffset(999);
   __158->GetYaxis()->SetLabelSize(0.05);
   __158->GetYaxis()->SetTitleSize(0.06);
   __158->GetYaxis()->SetTitleFont(132);
   __158->GetZaxis()->SetLabelFont(132);
   __158->GetZaxis()->SetLabelSize(0.05);
   __158->GetZaxis()->SetTitleSize(0.06);
   __158->GetZaxis()->SetTitleFont(132);
   __158->Draw("");
   
   TH1F *_copy__159 = new TH1F("_copy__159","",1,0,1);
   _copy__159->SetDirectory(0);
   _copy__159->SetStats(0);
   _copy__159->SetFillStyle(0);
   _copy__159->SetLineWidth(2);
   _copy__159->SetMarkerStyle(0);
   _copy__159->GetXaxis()->SetNdivisions(4);
   _copy__159->GetXaxis()->SetLabelFont(132);
   _copy__159->GetXaxis()->SetLabelOffset(999);
   _copy__159->GetXaxis()->SetLabelSize(0);
   _copy__159->GetXaxis()->SetTitleSize(0.06);
   _copy__159->GetXaxis()->SetTitleFont(132);
   _copy__159->GetYaxis()->SetTitle("Ratio");
   _copy__159->GetYaxis()->CenterTitle(true);
   _copy__159->GetYaxis()->SetLabelFont(132);
   _copy__159->GetYaxis()->SetLabelOffset(999);
   _copy__159->GetYaxis()->SetLabelSize(0.05);
   _copy__159->GetYaxis()->SetTitleSize(0.06);
   _copy__159->GetYaxis()->SetTitleFont(132);
   _copy__159->GetZaxis()->SetLabelFont(132);
   _copy__159->GetZaxis()->SetLabelSize(0.05);
   _copy__159->GetZaxis()->SetTitleSize(0.06);
   _copy__159->GetZaxis()->SetTitleFont(132);
   _copy__159->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(1.567901,-6.627855,4.654321,2.220573);
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
   Double_t xAxis132[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_toterr__160 = new TH1F("wp_eta_toterr__160","wp_eta",4, xAxis132);
   wp_eta_toterr__160->SetBinContent(1,44.48695);
   wp_eta_toterr__160->SetBinContent(2,36.18721);
   wp_eta_toterr__160->SetBinContent(3,22.58616);
   wp_eta_toterr__160->SetBinContent(4,6.068387);
   wp_eta_toterr__160->SetBinContent(5,6.068387);
   wp_eta_toterr__160->SetBinError(1,4.178366);
   wp_eta_toterr__160->SetBinError(2,3.399085);
   wp_eta_toterr__160->SetBinError(3,1.937638);
   wp_eta_toterr__160->SetBinError(4,0.473664);
   wp_eta_toterr__160->SetBinError(5,0.473664);
   wp_eta_toterr__160->SetMinimum(0.001);
   wp_eta_toterr__160->SetMaximum(60);
   wp_eta_toterr__160->SetEntries(9);
   wp_eta_toterr__160->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__160->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__160->SetLineColor(ci);
   wp_eta_toterr__160->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__160->SetMarkerColor(ci);
   wp_eta_toterr__160->SetMarkerStyle(0);
   wp_eta_toterr__160->GetXaxis()->SetNdivisions(4);
   wp_eta_toterr__160->GetXaxis()->SetLabelFont(132);
   wp_eta_toterr__160->GetXaxis()->SetLabelOffset(999);
   wp_eta_toterr__160->GetXaxis()->SetLabelSize(0);
   wp_eta_toterr__160->GetXaxis()->SetTitleSize(0.06);
   wp_eta_toterr__160->GetXaxis()->SetTitleFont(132);
   wp_eta_toterr__160->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_toterr__160->GetYaxis()->SetLabelFont(132);
   wp_eta_toterr__160->GetYaxis()->SetLabelSize(0.05);
   wp_eta_toterr__160->GetYaxis()->SetTitleSize(0.06);
   wp_eta_toterr__160->GetYaxis()->SetTitleFont(132);
   wp_eta_toterr__160->GetZaxis()->SetLabelFont(132);
   wp_eta_toterr__160->GetZaxis()->SetLabelSize(0.05);
   wp_eta_toterr__160->GetZaxis()->SetTitleSize(0.06);
   wp_eta_toterr__160->GetZaxis()->SetTitleFont(132);
   wp_eta_toterr__160->Draw("e2");
   Double_t xAxis133[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_staterr__161 = new TH1F("wp_eta_staterr__161","wp_eta",4, xAxis133);
   wp_eta_staterr__161->SetBinContent(1,44.48695);
   wp_eta_staterr__161->SetBinContent(2,36.18721);
   wp_eta_staterr__161->SetBinContent(3,22.58616);
   wp_eta_staterr__161->SetBinContent(4,6.068387);
   wp_eta_staterr__161->SetBinContent(5,6.068387);
   wp_eta_staterr__161->SetBinError(1,0.305628);
   wp_eta_staterr__161->SetBinError(2,0.2473742);
   wp_eta_staterr__161->SetBinError(3,0.1921072);
   wp_eta_staterr__161->SetBinError(4,0.07689115);
   wp_eta_staterr__161->SetBinError(5,0.07689115);
   wp_eta_staterr__161->SetMinimum(0.001);
   wp_eta_staterr__161->SetMaximum(60);
   wp_eta_staterr__161->SetEntries(9);
   wp_eta_staterr__161->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__161->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__161->SetLineColor(ci);
   wp_eta_staterr__161->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__161->SetMarkerColor(ci);
   wp_eta_staterr__161->SetMarkerStyle(0);
   wp_eta_staterr__161->GetXaxis()->SetNdivisions(4);
   wp_eta_staterr__161->GetXaxis()->SetLabelFont(132);
   wp_eta_staterr__161->GetXaxis()->SetLabelOffset(999);
   wp_eta_staterr__161->GetXaxis()->SetLabelSize(0);
   wp_eta_staterr__161->GetXaxis()->SetTitleSize(0.06);
   wp_eta_staterr__161->GetXaxis()->SetTitleFont(132);
   wp_eta_staterr__161->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_staterr__161->GetYaxis()->SetLabelFont(132);
   wp_eta_staterr__161->GetYaxis()->SetLabelSize(0.05);
   wp_eta_staterr__161->GetYaxis()->SetTitleSize(0.06);
   wp_eta_staterr__161->GetYaxis()->SetTitleFont(132);
   wp_eta_staterr__161->GetZaxis()->SetLabelFont(132);
   wp_eta_staterr__161->GetZaxis()->SetLabelSize(0.05);
   wp_eta_staterr__161->GetZaxis()->SetTitleSize(0.06);
   wp_eta_staterr__161->GetZaxis()->SetTitleFont(132);
   wp_eta_staterr__161->Draw("e2same");
   Double_t xAxis134[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_toterr__162 = new TH1F("wm_eta_toterr__162","wm_eta",4, xAxis134);
   wm_eta_toterr__162->SetBinContent(1,20.31135);
   wm_eta_toterr__162->SetBinContent(2,19.05704);
   wm_eta_toterr__162->SetBinContent(3,14.77047);
   wm_eta_toterr__162->SetBinContent(4,6.28784);
   wm_eta_toterr__162->SetBinContent(5,6.28784);
   wm_eta_toterr__162->SetBinError(1,2.211244);
   wm_eta_toterr__162->SetBinError(2,2.174277);
   wm_eta_toterr__162->SetBinError(3,1.504852);
   wm_eta_toterr__162->SetBinError(4,0.7324271);
   wm_eta_toterr__162->SetBinError(5,0.7324271);
   wm_eta_toterr__162->SetMinimum(0.001);
   wm_eta_toterr__162->SetMaximum(60);
   wm_eta_toterr__162->SetEntries(9);
   wm_eta_toterr__162->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__162->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__162->SetLineColor(ci);
   wm_eta_toterr__162->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__162->SetMarkerColor(ci);
   wm_eta_toterr__162->SetMarkerStyle(0);
   wm_eta_toterr__162->GetXaxis()->SetNdivisions(4);
   wm_eta_toterr__162->GetXaxis()->SetLabelFont(132);
   wm_eta_toterr__162->GetXaxis()->SetLabelOffset(999);
   wm_eta_toterr__162->GetXaxis()->SetLabelSize(0);
   wm_eta_toterr__162->GetXaxis()->SetTitleSize(0.06);
   wm_eta_toterr__162->GetXaxis()->SetTitleFont(132);
   wm_eta_toterr__162->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_toterr__162->GetYaxis()->SetLabelFont(132);
   wm_eta_toterr__162->GetYaxis()->SetLabelSize(0.05);
   wm_eta_toterr__162->GetYaxis()->SetTitleSize(0.06);
   wm_eta_toterr__162->GetYaxis()->SetTitleFont(132);
   wm_eta_toterr__162->GetZaxis()->SetLabelFont(132);
   wm_eta_toterr__162->GetZaxis()->SetLabelSize(0.05);
   wm_eta_toterr__162->GetZaxis()->SetTitleSize(0.06);
   wm_eta_toterr__162->GetZaxis()->SetTitleFont(132);
   wm_eta_toterr__162->Draw("e2same");
   Double_t xAxis135[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_staterr__163 = new TH1F("wm_eta_staterr__163","wm_eta",4, xAxis135);
   wm_eta_staterr__163->SetBinContent(1,20.31135);
   wm_eta_staterr__163->SetBinContent(2,19.05704);
   wm_eta_staterr__163->SetBinContent(3,14.77047);
   wm_eta_staterr__163->SetBinContent(4,6.28784);
   wm_eta_staterr__163->SetBinContent(5,6.28784);
   wm_eta_staterr__163->SetBinError(1,0.2067664);
   wm_eta_staterr__163->SetBinError(2,0.1786075);
   wm_eta_staterr__163->SetBinError(3,0.1537429);
   wm_eta_staterr__163->SetBinError(4,0.0794311);
   wm_eta_staterr__163->SetBinError(5,0.0794311);
   wm_eta_staterr__163->SetMinimum(0.001);
   wm_eta_staterr__163->SetMaximum(60);
   wm_eta_staterr__163->SetEntries(9);
   wm_eta_staterr__163->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__163->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__163->SetLineColor(ci);
   wm_eta_staterr__163->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__163->SetMarkerColor(ci);
   wm_eta_staterr__163->SetMarkerStyle(0);
   wm_eta_staterr__163->GetXaxis()->SetNdivisions(4);
   wm_eta_staterr__163->GetXaxis()->SetLabelFont(132);
   wm_eta_staterr__163->GetXaxis()->SetLabelOffset(999);
   wm_eta_staterr__163->GetXaxis()->SetLabelSize(0);
   wm_eta_staterr__163->GetXaxis()->SetTitleSize(0.06);
   wm_eta_staterr__163->GetXaxis()->SetTitleFont(132);
   wm_eta_staterr__163->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_staterr__163->GetYaxis()->SetLabelFont(132);
   wm_eta_staterr__163->GetYaxis()->SetLabelSize(0.05);
   wm_eta_staterr__163->GetYaxis()->SetTitleSize(0.06);
   wm_eta_staterr__163->GetYaxis()->SetTitleFont(132);
   wm_eta_staterr__163->GetZaxis()->SetLabelFont(132);
   wm_eta_staterr__163->GetZaxis()->SetLabelSize(0.05);
   wm_eta_staterr__163->GetZaxis()->SetTitleSize(0.06);
   wm_eta_staterr__163->GetZaxis()->SetTitleFont(132);
   wm_eta_staterr__163->Draw("e2same");
   TBox *box = new TBox(3.5,5.555413,4.5,7.020267);
   box->SetFillColor(19);
   box->SetFillStyle(0);

   ci = TColor::GetColor("#ffff00");
   box->SetLineColor(ci);
   box->SetLineWidth(2);
   box->Draw();
   
   Double_t eta_plus_toterrs_fx3193[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t eta_plus_toterrs_fy3193[4] = {
   47.32533,
   38.9919,
   23.46391,
   5.924761};
   Double_t eta_plus_toterrs_felx3193[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fely3193[4] = {
   3.540604,
   2.964117,
   2.407115,
   0.58535};
   Double_t eta_plus_toterrs_fehx3193[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fehy3193[4] = {
   3.05974,
   3.019728,
   1.770769,
   0.6694141};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,eta_plus_toterrs_fx3193,eta_plus_toterrs_fy3193,eta_plus_toterrs_felx3193,eta_plus_toterrs_fehx3193,eta_plus_toterrs_fely3193,eta_plus_toterrs_fehy3193);
   grae->SetName("eta_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_eta_plus_toterrs306531773193 = new TH1F("Graph_Graph_Graph_eta_plus_toterrs306531773193","",100,2.17,4.03);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->SetMinimum(0.001);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->SetMaximum(60);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->SetDirectory(0);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->SetStats(0);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->SetLineWidth(2);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->SetMarkerStyle(0);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_plus_toterrs306531773193->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_eta_plus_toterrs306531773193);
   
   grae->Draw("p1p");
   
   Double_t eta_plus_toterrs_fx3194[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t eta_plus_toterrs_fy3194[4] = {
   47.79052,
   39.73359,
   24.34292,
   6.287156};
   Double_t eta_plus_toterrs_felx3194[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fely3194[4] = {
   3.555086,
   3.167225,
   2.012039,
   0.5928745};
   Double_t eta_plus_toterrs_fehx3194[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fehy3194[4] = {
   3.712474,
   3.28169,
   2.136315,
   0.6808392};
   grae = new TGraphAsymmErrors(4,eta_plus_toterrs_fx3194,eta_plus_toterrs_fy3194,eta_plus_toterrs_felx3194,eta_plus_toterrs_fehx3194,eta_plus_toterrs_fely3194,eta_plus_toterrs_fehy3194);
   grae->SetName("eta_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_eta_plus_toterrs306731783194 = new TH1F("Graph_Graph_Graph_eta_plus_toterrs306731783194","",100,2.0175,3.9075);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->SetMinimum(0.001);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->SetMaximum(60);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->SetDirectory(0);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->SetStats(0);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->SetLineWidth(2);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->SetMarkerStyle(0);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_plus_toterrs306731783194->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_eta_plus_toterrs306731783194);
   
   grae->Draw("p1p");
   
   Double_t eta_minus_toterrs_fx3195[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t eta_minus_toterrs_fy3195[4] = {
   24.69105,
   21.53431,
   16.77246,
   6.521709};
   Double_t eta_minus_toterrs_felx3195[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fely3195[4] = {
   2.650178,
   1.505858,
   2.136883,
   0.7587894};
   Double_t eta_minus_toterrs_fehx3195[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fehy3195[4] = {
   1.770777,
   1.514672,
   1.574916,
   0.7803406};
   grae = new TGraphAsymmErrors(4,eta_minus_toterrs_fx3195,eta_minus_toterrs_fy3195,eta_minus_toterrs_felx3195,eta_minus_toterrs_fehx3195,eta_minus_toterrs_fely3195,eta_minus_toterrs_fehy3195);
   grae->SetName("eta_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_eta_minus_toterrs307731793195 = new TH1F("Graph_Graph_Graph_eta_minus_toterrs307731793195","",100,2.1325,4.4425);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->SetMinimum(0.001);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->SetMaximum(60);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->SetDirectory(0);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->SetStats(0);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->SetLineWidth(2);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->SetMarkerStyle(0);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_minus_toterrs307731793195->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_eta_minus_toterrs307731793195);
   
   grae->Draw("p1p");
   
   Double_t eta_minus_toterrs_fx3196[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t eta_minus_toterrs_fy3196[4] = {
   24.34978,
   21.59002,
   16.53536,
   6.707781};
   Double_t eta_minus_toterrs_felx3196[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fely3196[4] = {
   1.887475,
   1.685778,
   1.408083,
   0.7344018};
   Double_t eta_minus_toterrs_fehx3196[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fehy3196[4] = {
   1.946961,
   1.776958,
   1.529902,
   0.7848048};
   grae = new TGraphAsymmErrors(4,eta_minus_toterrs_fx3196,eta_minus_toterrs_fy3196,eta_minus_toterrs_felx3196,eta_minus_toterrs_fehx3196,eta_minus_toterrs_fely3196,eta_minus_toterrs_fehy3196);
   grae->SetName("eta_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_eta_minus_toterrs307931803196 = new TH1F("Graph_Graph_Graph_eta_minus_toterrs307931803196","",100,1.98,4.32);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->SetMinimum(0.001);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->SetMaximum(60);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->SetDirectory(0);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->SetStats(0);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->SetLineWidth(2);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->SetMarkerStyle(0);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_eta_minus_toterrs307931803196->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_eta_minus_toterrs307931803196);
   
   grae->Draw("p1p");
   
   Double_t _fx3197[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t _fy3197[4] = {
   47.32533,
   38.9919,
   23.46391,
   5.924761};
   Double_t _felx3197[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3197[4] = {
   2.535717,
   2.140228,
   1.269583,
   0.3501558};
   Double_t _fehx3197[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3197[4] = {
   2.417316,
   2.077194,
   1.218067,
   0.4287262};
   grae = new TGraphAsymmErrors(4,_fx3197,_fy3197,_felx3197,_fehx3197,_fely3197,_fehy3197);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph_Graph306631813197 = new TH1F("Graph_Graph_Graph_Graph306631813197","",100,2.17,4.03);
   Graph_Graph_Graph_Graph306631813197->SetMinimum(0.001);
   Graph_Graph_Graph_Graph306631813197->SetMaximum(60);
   Graph_Graph_Graph_Graph306631813197->SetDirectory(0);
   Graph_Graph_Graph_Graph306631813197->SetStats(0);
   Graph_Graph_Graph_Graph306631813197->SetLineWidth(2);
   Graph_Graph_Graph_Graph306631813197->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph306631813197->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph306631813197->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306631813197->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph306631813197->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph306631813197->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306631813197->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306631813197->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph306631813197->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306631813197->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306631813197->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306631813197->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306631813197->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306631813197->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306631813197->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306631813197->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph306631813197);
   
   grae->Draw("p1p");
   
   Double_t _fx3198[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t _fy3198[4] = {
   47.79052,
   39.73359,
   24.34292,
   6.287156};
   Double_t _felx3198[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3198[4] = {
   2.911022,
   2.491634,
   1.555553,
   0.4153972};
   Double_t _fehx3198[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3198[4] = {
   3.070263,
   2.672722,
   1.706875,
   0.4669943};
   grae = new TGraphAsymmErrors(4,_fx3198,_fy3198,_felx3198,_fehx3198,_fely3198,_fehy3198);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph306831823198 = new TH1F("Graph_Graph_Graph_Graph306831823198","",100,2.0175,3.9075);
   Graph_Graph_Graph_Graph306831823198->SetMinimum(0.001);
   Graph_Graph_Graph_Graph306831823198->SetMaximum(60);
   Graph_Graph_Graph_Graph306831823198->SetDirectory(0);
   Graph_Graph_Graph_Graph306831823198->SetStats(0);
   Graph_Graph_Graph_Graph306831823198->SetLineWidth(2);
   Graph_Graph_Graph_Graph306831823198->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph306831823198->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph306831823198->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306831823198->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph306831823198->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph306831823198->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306831823198->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306831823198->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph306831823198->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306831823198->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306831823198->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306831823198->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph306831823198->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph306831823198->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph306831823198->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph306831823198->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph306831823198);
   
   grae->Draw("p1p");
   
   Double_t _fx3199[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t _fy3199[4] = {
   24.69105,
   21.53431,
   16.77246,
   6.521709};
   Double_t _felx3199[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3199[4] = {
   1.403467,
   1.102299,
   0.935895,
   0.3957744};
   Double_t _fehx3199[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3199[4] = {
   1.399612,
   1.006586,
   1.048164,
   0.4442883};
   grae = new TGraphAsymmErrors(4,_fx3199,_fy3199,_felx3199,_fehx3199,_fely3199,_fehy3199);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph_Graph307831833199 = new TH1F("Graph_Graph_Graph_Graph307831833199","",100,2.1325,4.4425);
   Graph_Graph_Graph_Graph307831833199->SetMinimum(0.001);
   Graph_Graph_Graph_Graph307831833199->SetMaximum(60);
   Graph_Graph_Graph_Graph307831833199->SetDirectory(0);
   Graph_Graph_Graph_Graph307831833199->SetStats(0);
   Graph_Graph_Graph_Graph307831833199->SetLineWidth(2);
   Graph_Graph_Graph_Graph307831833199->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph307831833199->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph307831833199->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307831833199->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph307831833199->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph307831833199->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307831833199->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307831833199->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph307831833199->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307831833199->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307831833199->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307831833199->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph307831833199->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph307831833199->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph307831833199->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph307831833199->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph307831833199);
   
   grae->Draw("p1p");
   
   Double_t _fx3200[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t _fy3200[4] = {
   24.34978,
   21.59002,
   16.53536,
   6.707781};
   Double_t _felx3200[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3200[4] = {
   1.482811,
   1.286926,
   0.9989262,
   0.430294};
   Double_t _fehx3200[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3200[4] = {
   1.576153,
   1.363707,
   1.084366,
   0.4796934};
   grae = new TGraphAsymmErrors(4,_fx3200,_fy3200,_felx3200,_fehx3200,_fely3200,_fehy3200);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph_Graph308031843200 = new TH1F("Graph_Graph_Graph_Graph308031843200","",100,1.98,4.32);
   Graph_Graph_Graph_Graph308031843200->SetMinimum(0.001);
   Graph_Graph_Graph_Graph308031843200->SetMaximum(60);
   Graph_Graph_Graph_Graph308031843200->SetDirectory(0);
   Graph_Graph_Graph_Graph308031843200->SetStats(0);
   Graph_Graph_Graph_Graph308031843200->SetLineWidth(2);
   Graph_Graph_Graph_Graph308031843200->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph308031843200->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph_Graph308031843200->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph308031843200->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph_Graph308031843200->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph_Graph308031843200->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph308031843200->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph308031843200->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph_Graph308031843200->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph308031843200->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph308031843200->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph308031843200->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph308031843200->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph308031843200->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph308031843200->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph308031843200->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph308031843200);
   
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
   Double_t xAxis136[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_toterr_copy__164 = new TH1F("wp_eta_toterr_copy__164","wp_eta",4, xAxis136);
   wp_eta_toterr_copy__164->SetBinContent(1,44.48695);
   wp_eta_toterr_copy__164->SetBinContent(2,36.18721);
   wp_eta_toterr_copy__164->SetBinContent(3,22.58616);
   wp_eta_toterr_copy__164->SetBinContent(4,6.068387);
   wp_eta_toterr_copy__164->SetBinContent(5,6.068387);
   wp_eta_toterr_copy__164->SetBinError(1,4.178366);
   wp_eta_toterr_copy__164->SetBinError(2,3.399085);
   wp_eta_toterr_copy__164->SetBinError(3,1.937638);
   wp_eta_toterr_copy__164->SetBinError(4,0.473664);
   wp_eta_toterr_copy__164->SetBinError(5,0.473664);
   wp_eta_toterr_copy__164->SetMinimum(0.001);
   wp_eta_toterr_copy__164->SetMaximum(60);
   wp_eta_toterr_copy__164->SetEntries(9);
   wp_eta_toterr_copy__164->SetDirectory(0);
   wp_eta_toterr_copy__164->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__164->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__164->SetLineColor(ci);
   wp_eta_toterr_copy__164->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__164->SetMarkerColor(ci);
   wp_eta_toterr_copy__164->SetMarkerStyle(0);
   wp_eta_toterr_copy__164->GetXaxis()->SetNdivisions(4);
   wp_eta_toterr_copy__164->GetXaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__164->GetXaxis()->SetLabelOffset(999);
   wp_eta_toterr_copy__164->GetXaxis()->SetLabelSize(0);
   wp_eta_toterr_copy__164->GetXaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__164->GetXaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__164->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_toterr_copy__164->GetYaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__164->GetYaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__164->GetYaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__164->GetYaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__164->GetZaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__164->GetZaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__164->GetZaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__164->GetZaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__164->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.567901,0.1085185,4.654321,4.404815);
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
   Double_t xAxis137[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_870_1001_2ratiocomp0__165 = new TH1F("wj_eta_8TeV_log_870_1001_2ratiocomp0__165","wm_eta",4, xAxis137);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinContent(1,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinContent(2,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinContent(3,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinContent(4,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinContent(5,6.28784);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinError(1,0.1088674);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinError(2,0.1140931);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinError(3,0.1018825);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinError(4,0.1164831);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetBinError(5,0.7324271);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetMinimum(0.71);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetMaximum(1.29);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetEntries(13);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetLineColor(ci);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetMarkerColor(ci);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->SetMarkerStyle(0);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0__165->Draw("e2");
   Double_t xAxis138[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_870_1001_2ratiocomp1__166 = new TH1F("wj_eta_8TeV_log_870_1001_2ratiocomp1__166","wm_eta",4, xAxis138);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinContent(1,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinContent(2,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinContent(3,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinContent(4,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinContent(5,6.28784);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinError(1,0.01017984);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinError(2,0.009372258);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinError(3,0.0104088);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinError(4,0.01263249);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetBinError(5,0.0794311);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetMinimum(0.71);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetMaximum(1.29);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetEntries(13);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetLineColor(ci);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetMarkerColor(ci);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->SetMarkerStyle(0);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp1__166->Draw("e2same");
   
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp2_fx3201[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp2_fy3201[4] = {
   1.215628,
   1.129992,
   1.13554,
   1.037194};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp2_felx3201[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp2_fely3201[4] = {
   0.1304777,
   0.07901847,
   0.1446727,
   0.1206757};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp2_fehx3201[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp2_fehy3201[4] = {
   0.08718166,
   0.07948094,
   0.106626,
   0.1241031};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_870_1001_2ratiocomp2_fx3201,wj_eta_8TeV_log_870_1001_2ratiocomp2_fy3201,wj_eta_8TeV_log_870_1001_2ratiocomp2_felx3201,wj_eta_8TeV_log_870_1001_2ratiocomp2_fehx3201,wj_eta_8TeV_log_870_1001_2ratiocomp2_fely3201,wj_eta_8TeV_log_870_1001_2ratiocomp2_fehy3201);
   grae->SetName("wj_eta_8TeV_log_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201 = new TH1F("Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201","",100,2.1325,4.4425);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->SetDirectory(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->SetStats(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_870_1001_2ratiocomp23201);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp3_fx3202[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp3_fy3202[4] = {
   1.198826,
   1.132916,
   1.119488,
   1.066786};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp3_felx3202[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp3_fely3202[4] = {
   0.09292708,
   0.08845959,
   0.09533098,
   0.1167971};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp3_fehx3202[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp3_fehy3202[4] = {
   0.09585579,
   0.09324414,
   0.1035784,
   0.1248131};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_870_1001_2ratiocomp3_fx3202,wj_eta_8TeV_log_870_1001_2ratiocomp3_fy3202,wj_eta_8TeV_log_870_1001_2ratiocomp3_felx3202,wj_eta_8TeV_log_870_1001_2ratiocomp3_fehx3202,wj_eta_8TeV_log_870_1001_2ratiocomp3_fely3202,wj_eta_8TeV_log_870_1001_2ratiocomp3_fehy3202);
   grae->SetName("wj_eta_8TeV_log_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202 = new TH1F("Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202","",100,1.98,4.32);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->SetDirectory(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->SetStats(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_870_1001_2ratiocomp33202);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp4_fx3203[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp4_fy3203[4] = {
   1.215628,
   1.129992,
   1.13554,
   1.037194};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp4_felx3203[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp4_fely3203[4] = {
   0.06909767,
   0.05784207,
   0.06336258,
   0.06294281};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp4_fehx3203[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp4_fehy3203[4] = {
   0.06890789,
   0.05281964,
   0.07096352,
   0.07065832};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_870_1001_2ratiocomp4_fx3203,wj_eta_8TeV_log_870_1001_2ratiocomp4_fy3203,wj_eta_8TeV_log_870_1001_2ratiocomp4_felx3203,wj_eta_8TeV_log_870_1001_2ratiocomp4_fehx3203,wj_eta_8TeV_log_870_1001_2ratiocomp4_fely3203,wj_eta_8TeV_log_870_1001_2ratiocomp4_fehy3203);
   grae->SetName("wj_eta_8TeV_log_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203 = new TH1F("Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203","",100,2.1325,4.4425);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->SetDirectory(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->SetStats(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_870_1001_2ratiocomp43203);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp5_fx3204[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp5_fy3204[4] = {
   1.198826,
   1.132916,
   1.119488,
   1.066786};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp5_felx3204[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp5_fely3204[4] = {
   0.07300405,
   0.06753022,
   0.06762996,
   0.06843272};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp5_fehx3204[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_870_1001_2ratiocomp5_fehy3204[4] = {
   0.0775996,
   0.07155919,
   0.07341446,
   0.07628906};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_870_1001_2ratiocomp5_fx3204,wj_eta_8TeV_log_870_1001_2ratiocomp5_fy3204,wj_eta_8TeV_log_870_1001_2ratiocomp5_felx3204,wj_eta_8TeV_log_870_1001_2ratiocomp5_fehx3204,wj_eta_8TeV_log_870_1001_2ratiocomp5_fely3204,wj_eta_8TeV_log_870_1001_2ratiocomp5_fehy3204);
   grae->SetName("wj_eta_8TeV_log_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204 = new TH1F("Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204","",100,1.98,4.32);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->SetDirectory(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->SetStats(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_870_1001_2ratiocomp53204);
   
   grae->Draw("p1");
   Double_t xAxis139[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167 = new TH1F("wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167","wm_eta",4, xAxis139);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinContent(1,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinContent(2,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinContent(3,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinContent(4,1);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinContent(5,6.28784);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinError(1,0.1088674);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinError(2,0.1140931);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinError(3,0.1018825);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinError(4,0.1164831);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetBinError(5,0.7324271);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetMinimum(0.71);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetMaximum(1.29);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetEntries(13);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetDirectory(0);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetLineColor(ci);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetMarkerColor(ci);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->SetMarkerStyle(0);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_870_1001_2ratiocomp0_copy__167->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: middlPad
   TPad *middlPad = new TPad("middlPad", "middlPad",0.005,0.05,0.995,0.995);
   middlPad->Draw();
   middlPad->cd();
   middlPad->Range(1.567901,-0.3699997,4.654321,3.629999);
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
   Double_t xAxis140[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_400_1001_0ratiocomp0__168 = new TH1F("wj_eta_8TeV_log_400_1001_0ratiocomp0__168","wp_eta",4, xAxis140);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinContent(1,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinContent(2,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinContent(3,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinContent(4,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinContent(5,6.068387);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinError(1,0.09392341);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinError(2,0.09393057);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinError(3,0.08578873);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinError(4,0.07805435);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetBinError(5,0.473664);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetMinimum(0.71);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetMaximum(1.29);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetEntries(13);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetLineColor(ci);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetMarkerColor(ci);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->SetMarkerStyle(0);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0__168->Draw("e2");
   Double_t xAxis141[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_400_1001_0ratiocomp1__169 = new TH1F("wj_eta_8TeV_log_400_1001_0ratiocomp1__169","wp_eta",4, xAxis141);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinContent(1,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinContent(2,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinContent(3,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinContent(4,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinContent(5,6.068387);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinError(1,0.00687006);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinError(2,0.006835955);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinError(3,0.008505529);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinError(4,0.01267077);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetBinError(5,0.07689115);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetMinimum(0.71);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetMaximum(1.29);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetEntries(13);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetLineColor(ci);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetMarkerColor(ci);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->SetMarkerStyle(0);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp1__169->Draw("e2same");
   
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp2_fx3205[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp2_fy3205[4] = {
   1.063803,
   1.077505,
   1.038863,
   0.9763321};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp2_felx3205[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp2_fely3205[4] = {
   0.07958749,
   0.08191061,
   0.1065748,
   0.09645891};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp2_fehx3205[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp2_fehy3205[4] = {
   0.06877838,
   0.08344737,
   0.07840062,
   0.1103117};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_400_1001_0ratiocomp2_fx3205,wj_eta_8TeV_log_400_1001_0ratiocomp2_fy3205,wj_eta_8TeV_log_400_1001_0ratiocomp2_felx3205,wj_eta_8TeV_log_400_1001_0ratiocomp2_fehx3205,wj_eta_8TeV_log_400_1001_0ratiocomp2_fely3205,wj_eta_8TeV_log_400_1001_0ratiocomp2_fehy3205);
   grae->SetName("wj_eta_8TeV_log_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205 = new TH1F("Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205","",100,2.17,4.03);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->SetDirectory(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->SetStats(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_400_1001_0ratiocomp23205);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp3_fx3206[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp3_fy3206[4] = {
   1.074259,
   1.098001,
   1.077781,
   1.036051};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp3_felx3206[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp3_fely3206[4] = {
   0.07991302,
   0.08752332,
   0.08908284,
   0.09769886};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp3_fehx3206[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp3_fehy3206[4] = {
   0.08345087,
   0.09068646,
   0.09458514,
   0.1121944};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_400_1001_0ratiocomp3_fx3206,wj_eta_8TeV_log_400_1001_0ratiocomp3_fy3206,wj_eta_8TeV_log_400_1001_0ratiocomp3_felx3206,wj_eta_8TeV_log_400_1001_0ratiocomp3_fehx3206,wj_eta_8TeV_log_400_1001_0ratiocomp3_fely3206,wj_eta_8TeV_log_400_1001_0ratiocomp3_fehy3206);
   grae->SetName("wj_eta_8TeV_log_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206 = new TH1F("Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206","",100,2.0175,3.9075);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->SetDirectory(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->SetStats(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_400_1001_0ratiocomp33206);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp4_fx3207[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp4_fy3207[4] = {
   1.063803,
   1.077505,
   1.038863,
   0.9763321};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp4_felx3207[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp4_fely3207[4] = {
   0.05699913,
   0.05914322,
   0.05621066,
   0.05770163};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp4_fehx3207[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp4_fehy3207[4] = {
   0.05433766,
   0.05740133,
   0.05392981,
   0.07064912};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_400_1001_0ratiocomp4_fx3207,wj_eta_8TeV_log_400_1001_0ratiocomp4_fy3207,wj_eta_8TeV_log_400_1001_0ratiocomp4_felx3207,wj_eta_8TeV_log_400_1001_0ratiocomp4_fehx3207,wj_eta_8TeV_log_400_1001_0ratiocomp4_fely3207,wj_eta_8TeV_log_400_1001_0ratiocomp4_fehy3207);
   grae->SetName("wj_eta_8TeV_log_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207 = new TH1F("Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207","",100,2.17,4.03);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->SetDirectory(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->SetStats(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_400_1001_0ratiocomp43207);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp5_fx3208[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp5_fy3208[4] = {
   1.074259,
   1.098001,
   1.077781,
   1.036051};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp5_felx3208[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp5_fely3208[4] = {
   0.06543542,
   0.068854,
   0.06887198,
   0.06845265};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp5_fehx3208[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_log_400_1001_0ratiocomp5_fehy3208[4] = {
   0.06901492,
   0.07385818,
   0.07557173,
   0.07695526};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_log_400_1001_0ratiocomp5_fx3208,wj_eta_8TeV_log_400_1001_0ratiocomp5_fy3208,wj_eta_8TeV_log_400_1001_0ratiocomp5_felx3208,wj_eta_8TeV_log_400_1001_0ratiocomp5_fehx3208,wj_eta_8TeV_log_400_1001_0ratiocomp5_fely3208,wj_eta_8TeV_log_400_1001_0ratiocomp5_fehy3208);
   grae->SetName("wj_eta_8TeV_log_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208 = new TH1F("Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208","",100,2.0175,3.9075);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->SetMinimum(0.71);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->SetMaximum(1.29);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->SetDirectory(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->SetStats(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->SetLineWidth(2);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_log_400_1001_0ratiocomp53208);
   
   grae->Draw("p1");
   Double_t xAxis142[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170 = new TH1F("wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170","wp_eta",4, xAxis142);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinContent(1,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinContent(2,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinContent(3,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinContent(4,1);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinContent(5,6.068387);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinError(1,0.09392341);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinError(2,0.09393057);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinError(3,0.08578873);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinError(4,0.07805435);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetBinError(5,0.473664);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetMinimum(0.71);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetMaximum(1.29);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetEntries(13);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetDirectory(0);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetLineColor(ci);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetMarkerColor(ci);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->SetMarkerStyle(0);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_log_400_1001_0ratiocomp0_copy__170->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
