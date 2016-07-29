void wj_eta_8TeV()
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
   
   TH1F *__145 = new TH1F("__145","",1,0,1);
   __145->SetDirectory(0);
   __145->SetStats(0);
   __145->SetFillStyle(0);
   __145->SetLineWidth(2);
   __145->SetMarkerStyle(0);
   __145->GetXaxis()->SetNdivisions(4);
   __145->GetXaxis()->SetLabelFont(132);
   __145->GetXaxis()->SetLabelOffset(999);
   __145->GetXaxis()->SetLabelSize(0);
   __145->GetXaxis()->SetTitleSize(0.06);
   __145->GetXaxis()->SetTitleFont(132);
   __145->GetYaxis()->SetTitle("Ratio");
   __145->GetYaxis()->CenterTitle(true);
   __145->GetYaxis()->SetLabelFont(132);
   __145->GetYaxis()->SetLabelOffset(999);
   __145->GetYaxis()->SetLabelSize(0.05);
   __145->GetYaxis()->SetTitleSize(0.06);
   __145->GetYaxis()->SetTitleFont(132);
   __145->GetZaxis()->SetLabelFont(132);
   __145->GetZaxis()->SetLabelSize(0.05);
   __145->GetZaxis()->SetTitleSize(0.06);
   __145->GetZaxis()->SetTitleFont(132);
   __145->Draw("");
   
   TH1F *_copy__146 = new TH1F("_copy__146","",1,0,1);
   _copy__146->SetDirectory(0);
   _copy__146->SetStats(0);
   _copy__146->SetFillStyle(0);
   _copy__146->SetLineWidth(2);
   _copy__146->SetMarkerStyle(0);
   _copy__146->GetXaxis()->SetNdivisions(4);
   _copy__146->GetXaxis()->SetLabelFont(132);
   _copy__146->GetXaxis()->SetLabelOffset(999);
   _copy__146->GetXaxis()->SetLabelSize(0);
   _copy__146->GetXaxis()->SetTitleSize(0.06);
   _copy__146->GetXaxis()->SetTitleFont(132);
   _copy__146->GetYaxis()->SetTitle("Ratio");
   _copy__146->GetYaxis()->CenterTitle(true);
   _copy__146->GetYaxis()->SetLabelFont(132);
   _copy__146->GetYaxis()->SetLabelOffset(999);
   _copy__146->GetYaxis()->SetLabelSize(0.05);
   _copy__146->GetYaxis()->SetTitleSize(0.06);
   _copy__146->GetYaxis()->SetTitleFont(132);
   _copy__146->GetZaxis()->SetLabelFont(132);
   _copy__146->GetZaxis()->SetLabelSize(0.05);
   _copy__146->GetZaxis()->SetTitleSize(0.06);
   _copy__146->GetZaxis()->SetTitleFont(132);
   _copy__146->Draw("sameaxis");
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(1.567901,-45.55379,4.654321,65.55546);
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
   Double_t xAxis121[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_toterr__147 = new TH1F("wp_eta_toterr__147","wp_eta",4, xAxis121);
   wp_eta_toterr__147->SetBinContent(1,44.48695);
   wp_eta_toterr__147->SetBinContent(2,36.18721);
   wp_eta_toterr__147->SetBinContent(3,22.58616);
   wp_eta_toterr__147->SetBinContent(4,6.068387);
   wp_eta_toterr__147->SetBinContent(5,6.068387);
   wp_eta_toterr__147->SetBinError(1,4.178366);
   wp_eta_toterr__147->SetBinError(2,3.399085);
   wp_eta_toterr__147->SetBinError(3,1.937638);
   wp_eta_toterr__147->SetBinError(4,0.473664);
   wp_eta_toterr__147->SetBinError(5,0.473664);
   wp_eta_toterr__147->SetMinimum(0.001);
   wp_eta_toterr__147->SetMaximum(60);
   wp_eta_toterr__147->SetEntries(9);
   wp_eta_toterr__147->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__147->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__147->SetLineColor(ci);
   wp_eta_toterr__147->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__147->SetMarkerColor(ci);
   wp_eta_toterr__147->SetMarkerStyle(0);
   wp_eta_toterr__147->GetXaxis()->SetNdivisions(4);
   wp_eta_toterr__147->GetXaxis()->SetLabelFont(132);
   wp_eta_toterr__147->GetXaxis()->SetLabelOffset(999);
   wp_eta_toterr__147->GetXaxis()->SetLabelSize(0);
   wp_eta_toterr__147->GetXaxis()->SetTitleSize(0.06);
   wp_eta_toterr__147->GetXaxis()->SetTitleFont(132);
   wp_eta_toterr__147->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_toterr__147->GetYaxis()->SetLabelFont(132);
   wp_eta_toterr__147->GetYaxis()->SetLabelSize(0.05);
   wp_eta_toterr__147->GetYaxis()->SetTitleSize(0.06);
   wp_eta_toterr__147->GetYaxis()->SetTitleFont(132);
   wp_eta_toterr__147->GetZaxis()->SetLabelFont(132);
   wp_eta_toterr__147->GetZaxis()->SetLabelSize(0.05);
   wp_eta_toterr__147->GetZaxis()->SetTitleSize(0.06);
   wp_eta_toterr__147->GetZaxis()->SetTitleFont(132);
   wp_eta_toterr__147->Draw("e2");
   Double_t xAxis122[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_staterr__148 = new TH1F("wp_eta_staterr__148","wp_eta",4, xAxis122);
   wp_eta_staterr__148->SetBinContent(1,44.48695);
   wp_eta_staterr__148->SetBinContent(2,36.18721);
   wp_eta_staterr__148->SetBinContent(3,22.58616);
   wp_eta_staterr__148->SetBinContent(4,6.068387);
   wp_eta_staterr__148->SetBinContent(5,6.068387);
   wp_eta_staterr__148->SetBinError(1,0.305628);
   wp_eta_staterr__148->SetBinError(2,0.2473742);
   wp_eta_staterr__148->SetBinError(3,0.1921072);
   wp_eta_staterr__148->SetBinError(4,0.07689115);
   wp_eta_staterr__148->SetBinError(5,0.07689115);
   wp_eta_staterr__148->SetMinimum(0.001);
   wp_eta_staterr__148->SetMaximum(60);
   wp_eta_staterr__148->SetEntries(9);
   wp_eta_staterr__148->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__148->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__148->SetLineColor(ci);
   wp_eta_staterr__148->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__148->SetMarkerColor(ci);
   wp_eta_staterr__148->SetMarkerStyle(0);
   wp_eta_staterr__148->GetXaxis()->SetNdivisions(4);
   wp_eta_staterr__148->GetXaxis()->SetLabelFont(132);
   wp_eta_staterr__148->GetXaxis()->SetLabelOffset(999);
   wp_eta_staterr__148->GetXaxis()->SetLabelSize(0);
   wp_eta_staterr__148->GetXaxis()->SetTitleSize(0.06);
   wp_eta_staterr__148->GetXaxis()->SetTitleFont(132);
   wp_eta_staterr__148->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_staterr__148->GetYaxis()->SetLabelFont(132);
   wp_eta_staterr__148->GetYaxis()->SetLabelSize(0.05);
   wp_eta_staterr__148->GetYaxis()->SetTitleSize(0.06);
   wp_eta_staterr__148->GetYaxis()->SetTitleFont(132);
   wp_eta_staterr__148->GetZaxis()->SetLabelFont(132);
   wp_eta_staterr__148->GetZaxis()->SetLabelSize(0.05);
   wp_eta_staterr__148->GetZaxis()->SetTitleSize(0.06);
   wp_eta_staterr__148->GetZaxis()->SetTitleFont(132);
   wp_eta_staterr__148->Draw("e2same");
   Double_t xAxis123[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_toterr__149 = new TH1F("wm_eta_toterr__149","wm_eta",4, xAxis123);
   wm_eta_toterr__149->SetBinContent(1,20.31135);
   wm_eta_toterr__149->SetBinContent(2,19.05704);
   wm_eta_toterr__149->SetBinContent(3,14.77047);
   wm_eta_toterr__149->SetBinContent(4,6.28784);
   wm_eta_toterr__149->SetBinContent(5,6.28784);
   wm_eta_toterr__149->SetBinError(1,2.211244);
   wm_eta_toterr__149->SetBinError(2,2.174277);
   wm_eta_toterr__149->SetBinError(3,1.504852);
   wm_eta_toterr__149->SetBinError(4,0.7324271);
   wm_eta_toterr__149->SetBinError(5,0.7324271);
   wm_eta_toterr__149->SetMinimum(0.001);
   wm_eta_toterr__149->SetMaximum(60);
   wm_eta_toterr__149->SetEntries(9);
   wm_eta_toterr__149->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__149->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__149->SetLineColor(ci);
   wm_eta_toterr__149->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wm_eta_toterr__149->SetMarkerColor(ci);
   wm_eta_toterr__149->SetMarkerStyle(0);
   wm_eta_toterr__149->GetXaxis()->SetNdivisions(4);
   wm_eta_toterr__149->GetXaxis()->SetLabelFont(132);
   wm_eta_toterr__149->GetXaxis()->SetLabelOffset(999);
   wm_eta_toterr__149->GetXaxis()->SetLabelSize(0);
   wm_eta_toterr__149->GetXaxis()->SetTitleSize(0.06);
   wm_eta_toterr__149->GetXaxis()->SetTitleFont(132);
   wm_eta_toterr__149->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_toterr__149->GetYaxis()->SetLabelFont(132);
   wm_eta_toterr__149->GetYaxis()->SetLabelSize(0.05);
   wm_eta_toterr__149->GetYaxis()->SetTitleSize(0.06);
   wm_eta_toterr__149->GetYaxis()->SetTitleFont(132);
   wm_eta_toterr__149->GetZaxis()->SetLabelFont(132);
   wm_eta_toterr__149->GetZaxis()->SetLabelSize(0.05);
   wm_eta_toterr__149->GetZaxis()->SetTitleSize(0.06);
   wm_eta_toterr__149->GetZaxis()->SetTitleFont(132);
   wm_eta_toterr__149->Draw("e2same");
   Double_t xAxis124[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_staterr__150 = new TH1F("wm_eta_staterr__150","wm_eta",4, xAxis124);
   wm_eta_staterr__150->SetBinContent(1,20.31135);
   wm_eta_staterr__150->SetBinContent(2,19.05704);
   wm_eta_staterr__150->SetBinContent(3,14.77047);
   wm_eta_staterr__150->SetBinContent(4,6.28784);
   wm_eta_staterr__150->SetBinContent(5,6.28784);
   wm_eta_staterr__150->SetBinError(1,0.2067664);
   wm_eta_staterr__150->SetBinError(2,0.1786075);
   wm_eta_staterr__150->SetBinError(3,0.1537429);
   wm_eta_staterr__150->SetBinError(4,0.0794311);
   wm_eta_staterr__150->SetBinError(5,0.0794311);
   wm_eta_staterr__150->SetMinimum(0.001);
   wm_eta_staterr__150->SetMaximum(60);
   wm_eta_staterr__150->SetEntries(9);
   wm_eta_staterr__150->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__150->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__150->SetLineColor(ci);
   wm_eta_staterr__150->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wm_eta_staterr__150->SetMarkerColor(ci);
   wm_eta_staterr__150->SetMarkerStyle(0);
   wm_eta_staterr__150->GetXaxis()->SetNdivisions(4);
   wm_eta_staterr__150->GetXaxis()->SetLabelFont(132);
   wm_eta_staterr__150->GetXaxis()->SetLabelOffset(999);
   wm_eta_staterr__150->GetXaxis()->SetLabelSize(0);
   wm_eta_staterr__150->GetXaxis()->SetTitleSize(0.06);
   wm_eta_staterr__150->GetXaxis()->SetTitleFont(132);
   wm_eta_staterr__150->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_staterr__150->GetYaxis()->SetLabelFont(132);
   wm_eta_staterr__150->GetYaxis()->SetLabelSize(0.05);
   wm_eta_staterr__150->GetYaxis()->SetTitleSize(0.06);
   wm_eta_staterr__150->GetYaxis()->SetTitleFont(132);
   wm_eta_staterr__150->GetZaxis()->SetLabelFont(132);
   wm_eta_staterr__150->GetZaxis()->SetLabelSize(0.05);
   wm_eta_staterr__150->GetZaxis()->SetTitleSize(0.06);
   wm_eta_staterr__150->GetZaxis()->SetTitleFont(132);
   wm_eta_staterr__150->Draw("e2same");
   TBox *box = new TBox(3.5,5.555413,4.5,7.020267);
   box->SetFillColor(19);
   box->SetFillStyle(0);

   ci = TColor::GetColor("#ffff00");
   box->SetLineColor(ci);
   box->SetLineWidth(2);
   box->Draw();
   
   Double_t eta_plus_toterrs_fx3177[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t eta_plus_toterrs_fy3177[4] = {
   47.32533,
   38.9919,
   23.46391,
   5.924761};
   Double_t eta_plus_toterrs_felx3177[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fely3177[4] = {
   3.540604,
   2.964117,
   2.407115,
   0.58535};
   Double_t eta_plus_toterrs_fehx3177[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fehy3177[4] = {
   3.05974,
   3.019728,
   1.770769,
   0.6694141};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,eta_plus_toterrs_fx3177,eta_plus_toterrs_fy3177,eta_plus_toterrs_felx3177,eta_plus_toterrs_fehx3177,eta_plus_toterrs_fely3177,eta_plus_toterrs_fehy3177);
   grae->SetName("eta_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_eta_plus_toterrs30653177 = new TH1F("Graph_Graph_eta_plus_toterrs30653177","",100,2.17,4.03);
   Graph_Graph_eta_plus_toterrs30653177->SetMinimum(0.001);
   Graph_Graph_eta_plus_toterrs30653177->SetMaximum(60);
   Graph_Graph_eta_plus_toterrs30653177->SetDirectory(0);
   Graph_Graph_eta_plus_toterrs30653177->SetStats(0);
   Graph_Graph_eta_plus_toterrs30653177->SetLineWidth(2);
   Graph_Graph_eta_plus_toterrs30653177->SetMarkerStyle(0);
   Graph_Graph_eta_plus_toterrs30653177->GetXaxis()->SetNdivisions(4);
   Graph_Graph_eta_plus_toterrs30653177->GetXaxis()->SetLabelFont(132);
   Graph_Graph_eta_plus_toterrs30653177->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_eta_plus_toterrs30653177->GetXaxis()->SetLabelSize(0);
   Graph_Graph_eta_plus_toterrs30653177->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_plus_toterrs30653177->GetXaxis()->SetTitleFont(132);
   Graph_Graph_eta_plus_toterrs30653177->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_eta_plus_toterrs30653177->GetYaxis()->SetLabelFont(132);
   Graph_Graph_eta_plus_toterrs30653177->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_eta_plus_toterrs30653177->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_plus_toterrs30653177->GetYaxis()->SetTitleFont(132);
   Graph_Graph_eta_plus_toterrs30653177->GetZaxis()->SetLabelFont(132);
   Graph_Graph_eta_plus_toterrs30653177->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_eta_plus_toterrs30653177->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_plus_toterrs30653177->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_eta_plus_toterrs30653177);
   
   grae->Draw("p1p");
   
   Double_t eta_plus_toterrs_fx3178[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t eta_plus_toterrs_fy3178[4] = {
   47.79052,
   39.73359,
   24.34292,
   6.287156};
   Double_t eta_plus_toterrs_felx3178[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fely3178[4] = {
   3.555086,
   3.167225,
   2.012039,
   0.5928745};
   Double_t eta_plus_toterrs_fehx3178[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fehy3178[4] = {
   3.712474,
   3.28169,
   2.136315,
   0.6808392};
   grae = new TGraphAsymmErrors(4,eta_plus_toterrs_fx3178,eta_plus_toterrs_fy3178,eta_plus_toterrs_felx3178,eta_plus_toterrs_fehx3178,eta_plus_toterrs_fely3178,eta_plus_toterrs_fehy3178);
   grae->SetName("eta_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_eta_plus_toterrs30673178 = new TH1F("Graph_Graph_eta_plus_toterrs30673178","",100,2.0175,3.9075);
   Graph_Graph_eta_plus_toterrs30673178->SetMinimum(0.001);
   Graph_Graph_eta_plus_toterrs30673178->SetMaximum(60);
   Graph_Graph_eta_plus_toterrs30673178->SetDirectory(0);
   Graph_Graph_eta_plus_toterrs30673178->SetStats(0);
   Graph_Graph_eta_plus_toterrs30673178->SetLineWidth(2);
   Graph_Graph_eta_plus_toterrs30673178->SetMarkerStyle(0);
   Graph_Graph_eta_plus_toterrs30673178->GetXaxis()->SetNdivisions(4);
   Graph_Graph_eta_plus_toterrs30673178->GetXaxis()->SetLabelFont(132);
   Graph_Graph_eta_plus_toterrs30673178->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_eta_plus_toterrs30673178->GetXaxis()->SetLabelSize(0);
   Graph_Graph_eta_plus_toterrs30673178->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_plus_toterrs30673178->GetXaxis()->SetTitleFont(132);
   Graph_Graph_eta_plus_toterrs30673178->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_eta_plus_toterrs30673178->GetYaxis()->SetLabelFont(132);
   Graph_Graph_eta_plus_toterrs30673178->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_eta_plus_toterrs30673178->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_plus_toterrs30673178->GetYaxis()->SetTitleFont(132);
   Graph_Graph_eta_plus_toterrs30673178->GetZaxis()->SetLabelFont(132);
   Graph_Graph_eta_plus_toterrs30673178->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_eta_plus_toterrs30673178->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_plus_toterrs30673178->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_eta_plus_toterrs30673178);
   
   grae->Draw("p1p");
   
   Double_t eta_minus_toterrs_fx3179[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t eta_minus_toterrs_fy3179[4] = {
   24.69105,
   21.53431,
   16.77246,
   6.521709};
   Double_t eta_minus_toterrs_felx3179[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fely3179[4] = {
   2.650178,
   1.505858,
   2.136883,
   0.7587894};
   Double_t eta_minus_toterrs_fehx3179[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fehy3179[4] = {
   1.770777,
   1.514672,
   1.574916,
   0.7803406};
   grae = new TGraphAsymmErrors(4,eta_minus_toterrs_fx3179,eta_minus_toterrs_fy3179,eta_minus_toterrs_felx3179,eta_minus_toterrs_fehx3179,eta_minus_toterrs_fely3179,eta_minus_toterrs_fehy3179);
   grae->SetName("eta_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_eta_minus_toterrs30773179 = new TH1F("Graph_Graph_eta_minus_toterrs30773179","",100,2.1325,4.4425);
   Graph_Graph_eta_minus_toterrs30773179->SetMinimum(0.001);
   Graph_Graph_eta_minus_toterrs30773179->SetMaximum(60);
   Graph_Graph_eta_minus_toterrs30773179->SetDirectory(0);
   Graph_Graph_eta_minus_toterrs30773179->SetStats(0);
   Graph_Graph_eta_minus_toterrs30773179->SetLineWidth(2);
   Graph_Graph_eta_minus_toterrs30773179->SetMarkerStyle(0);
   Graph_Graph_eta_minus_toterrs30773179->GetXaxis()->SetNdivisions(4);
   Graph_Graph_eta_minus_toterrs30773179->GetXaxis()->SetLabelFont(132);
   Graph_Graph_eta_minus_toterrs30773179->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_eta_minus_toterrs30773179->GetXaxis()->SetLabelSize(0);
   Graph_Graph_eta_minus_toterrs30773179->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_minus_toterrs30773179->GetXaxis()->SetTitleFont(132);
   Graph_Graph_eta_minus_toterrs30773179->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_eta_minus_toterrs30773179->GetYaxis()->SetLabelFont(132);
   Graph_Graph_eta_minus_toterrs30773179->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_eta_minus_toterrs30773179->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_minus_toterrs30773179->GetYaxis()->SetTitleFont(132);
   Graph_Graph_eta_minus_toterrs30773179->GetZaxis()->SetLabelFont(132);
   Graph_Graph_eta_minus_toterrs30773179->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_eta_minus_toterrs30773179->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_minus_toterrs30773179->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_eta_minus_toterrs30773179);
   
   grae->Draw("p1p");
   
   Double_t eta_minus_toterrs_fx3180[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t eta_minus_toterrs_fy3180[4] = {
   24.34978,
   21.59002,
   16.53536,
   6.707781};
   Double_t eta_minus_toterrs_felx3180[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fely3180[4] = {
   1.887475,
   1.685778,
   1.408083,
   0.7344018};
   Double_t eta_minus_toterrs_fehx3180[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fehy3180[4] = {
   1.946961,
   1.776958,
   1.529902,
   0.7848048};
   grae = new TGraphAsymmErrors(4,eta_minus_toterrs_fx3180,eta_minus_toterrs_fy3180,eta_minus_toterrs_felx3180,eta_minus_toterrs_fehx3180,eta_minus_toterrs_fely3180,eta_minus_toterrs_fehy3180);
   grae->SetName("eta_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_eta_minus_toterrs30793180 = new TH1F("Graph_Graph_eta_minus_toterrs30793180","",100,1.98,4.32);
   Graph_Graph_eta_minus_toterrs30793180->SetMinimum(0.001);
   Graph_Graph_eta_minus_toterrs30793180->SetMaximum(60);
   Graph_Graph_eta_minus_toterrs30793180->SetDirectory(0);
   Graph_Graph_eta_minus_toterrs30793180->SetStats(0);
   Graph_Graph_eta_minus_toterrs30793180->SetLineWidth(2);
   Graph_Graph_eta_minus_toterrs30793180->SetMarkerStyle(0);
   Graph_Graph_eta_minus_toterrs30793180->GetXaxis()->SetNdivisions(4);
   Graph_Graph_eta_minus_toterrs30793180->GetXaxis()->SetLabelFont(132);
   Graph_Graph_eta_minus_toterrs30793180->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_eta_minus_toterrs30793180->GetXaxis()->SetLabelSize(0);
   Graph_Graph_eta_minus_toterrs30793180->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_minus_toterrs30793180->GetXaxis()->SetTitleFont(132);
   Graph_Graph_eta_minus_toterrs30793180->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_eta_minus_toterrs30793180->GetYaxis()->SetLabelFont(132);
   Graph_Graph_eta_minus_toterrs30793180->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_eta_minus_toterrs30793180->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_minus_toterrs30793180->GetYaxis()->SetTitleFont(132);
   Graph_Graph_eta_minus_toterrs30793180->GetZaxis()->SetLabelFont(132);
   Graph_Graph_eta_minus_toterrs30793180->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_eta_minus_toterrs30793180->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_eta_minus_toterrs30793180->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_eta_minus_toterrs30793180);
   
   grae->Draw("p1p");
   
   Double_t _fx3181[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t _fy3181[4] = {
   47.32533,
   38.9919,
   23.46391,
   5.924761};
   Double_t _felx3181[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3181[4] = {
   2.535717,
   2.140228,
   1.269583,
   0.3501558};
   Double_t _fehx3181[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3181[4] = {
   2.417316,
   2.077194,
   1.218067,
   0.4287262};
   grae = new TGraphAsymmErrors(4,_fx3181,_fy3181,_felx3181,_fehx3181,_fely3181,_fehy3181);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph30663181 = new TH1F("Graph_Graph_Graph30663181","",100,2.17,4.03);
   Graph_Graph_Graph30663181->SetMinimum(0.001);
   Graph_Graph_Graph30663181->SetMaximum(60);
   Graph_Graph_Graph30663181->SetDirectory(0);
   Graph_Graph_Graph30663181->SetStats(0);
   Graph_Graph_Graph30663181->SetLineWidth(2);
   Graph_Graph_Graph30663181->SetMarkerStyle(0);
   Graph_Graph_Graph30663181->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30663181->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30663181->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30663181->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30663181->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30663181->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30663181->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph30663181->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30663181->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30663181->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30663181->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30663181->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30663181->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30663181->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30663181->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30663181);
   
   grae->Draw("p1p");
   
   Double_t _fx3182[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t _fy3182[4] = {
   47.79052,
   39.73359,
   24.34292,
   6.287156};
   Double_t _felx3182[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3182[4] = {
   2.911022,
   2.491634,
   1.555553,
   0.4153972};
   Double_t _fehx3182[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3182[4] = {
   3.070263,
   2.672722,
   1.706875,
   0.4669943};
   grae = new TGraphAsymmErrors(4,_fx3182,_fy3182,_felx3182,_fehx3182,_fely3182,_fehy3182);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30683182 = new TH1F("Graph_Graph_Graph30683182","",100,2.0175,3.9075);
   Graph_Graph_Graph30683182->SetMinimum(0.001);
   Graph_Graph_Graph30683182->SetMaximum(60);
   Graph_Graph_Graph30683182->SetDirectory(0);
   Graph_Graph_Graph30683182->SetStats(0);
   Graph_Graph_Graph30683182->SetLineWidth(2);
   Graph_Graph_Graph30683182->SetMarkerStyle(0);
   Graph_Graph_Graph30683182->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30683182->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30683182->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30683182->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30683182->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30683182->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30683182->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph30683182->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30683182->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30683182->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30683182->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30683182->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30683182->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30683182->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30683182->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30683182);
   
   grae->Draw("p1p");
   
   Double_t _fx3183[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t _fy3183[4] = {
   24.69105,
   21.53431,
   16.77246,
   6.521709};
   Double_t _felx3183[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3183[4] = {
   1.403467,
   1.102299,
   0.935895,
   0.3957744};
   Double_t _fehx3183[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3183[4] = {
   1.399612,
   1.006586,
   1.048164,
   0.4442883};
   grae = new TGraphAsymmErrors(4,_fx3183,_fy3183,_felx3183,_fehx3183,_fely3183,_fehy3183);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph_Graph30783183 = new TH1F("Graph_Graph_Graph30783183","",100,2.1325,4.4425);
   Graph_Graph_Graph30783183->SetMinimum(0.001);
   Graph_Graph_Graph30783183->SetMaximum(60);
   Graph_Graph_Graph30783183->SetDirectory(0);
   Graph_Graph_Graph30783183->SetStats(0);
   Graph_Graph_Graph30783183->SetLineWidth(2);
   Graph_Graph_Graph30783183->SetMarkerStyle(0);
   Graph_Graph_Graph30783183->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30783183->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30783183->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30783183->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30783183->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30783183->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30783183->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph30783183->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30783183->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30783183->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30783183->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30783183->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30783183->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30783183->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30783183->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30783183);
   
   grae->Draw("p1p");
   
   Double_t _fx3184[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t _fy3184[4] = {
   24.34978,
   21.59002,
   16.53536,
   6.707781};
   Double_t _felx3184[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3184[4] = {
   1.482811,
   1.286926,
   0.9989262,
   0.430294};
   Double_t _fehx3184[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3184[4] = {
   1.576153,
   1.363707,
   1.084366,
   0.4796934};
   grae = new TGraphAsymmErrors(4,_fx3184,_fy3184,_felx3184,_fehx3184,_fely3184,_fehy3184);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph_Graph30803184 = new TH1F("Graph_Graph_Graph30803184","",100,1.98,4.32);
   Graph_Graph_Graph30803184->SetMinimum(0.001);
   Graph_Graph_Graph30803184->SetMaximum(60);
   Graph_Graph_Graph30803184->SetDirectory(0);
   Graph_Graph_Graph30803184->SetStats(0);
   Graph_Graph_Graph30803184->SetLineWidth(2);
   Graph_Graph_Graph30803184->SetMarkerStyle(0);
   Graph_Graph_Graph30803184->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30803184->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30803184->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30803184->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30803184->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30803184->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30803184->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph_Graph30803184->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30803184->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30803184->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30803184->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30803184->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30803184->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30803184->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30803184->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30803184);
   
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
   Double_t xAxis125[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_toterr_copy__151 = new TH1F("wp_eta_toterr_copy__151","wp_eta",4, xAxis125);
   wp_eta_toterr_copy__151->SetBinContent(1,44.48695);
   wp_eta_toterr_copy__151->SetBinContent(2,36.18721);
   wp_eta_toterr_copy__151->SetBinContent(3,22.58616);
   wp_eta_toterr_copy__151->SetBinContent(4,6.068387);
   wp_eta_toterr_copy__151->SetBinContent(5,6.068387);
   wp_eta_toterr_copy__151->SetBinError(1,4.178366);
   wp_eta_toterr_copy__151->SetBinError(2,3.399085);
   wp_eta_toterr_copy__151->SetBinError(3,1.937638);
   wp_eta_toterr_copy__151->SetBinError(4,0.473664);
   wp_eta_toterr_copy__151->SetBinError(5,0.473664);
   wp_eta_toterr_copy__151->SetMinimum(0.001);
   wp_eta_toterr_copy__151->SetMaximum(60);
   wp_eta_toterr_copy__151->SetEntries(9);
   wp_eta_toterr_copy__151->SetDirectory(0);
   wp_eta_toterr_copy__151->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__151->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__151->SetLineColor(ci);
   wp_eta_toterr_copy__151->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__151->SetMarkerColor(ci);
   wp_eta_toterr_copy__151->SetMarkerStyle(0);
   wp_eta_toterr_copy__151->GetXaxis()->SetNdivisions(4);
   wp_eta_toterr_copy__151->GetXaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__151->GetXaxis()->SetLabelOffset(999);
   wp_eta_toterr_copy__151->GetXaxis()->SetLabelSize(0);
   wp_eta_toterr_copy__151->GetXaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__151->GetXaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__151->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_toterr_copy__151->GetYaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__151->GetYaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__151->GetYaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__151->GetYaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__151->GetZaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__151->GetZaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__151->GetZaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__151->GetZaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__151->Draw("sameaxis");
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
   Double_t xAxis126[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_870_1001_2ratiocomp0__152 = new TH1F("wj_eta_8TeV_870_1001_2ratiocomp0__152","wm_eta",4, xAxis126);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinContent(1,1);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinContent(2,1);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinContent(3,1);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinContent(4,1);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinContent(5,6.28784);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinError(1,0.1088674);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinError(2,0.1140931);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinError(3,0.1018825);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinError(4,0.1164831);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetBinError(5,0.7324271);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetMinimum(0.71);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetMaximum(1.29);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetEntries(13);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetLineColor(ci);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetMarkerColor(ci);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->SetMarkerStyle(0);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0__152->Draw("e2");
   Double_t xAxis127[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_870_1001_2ratiocomp1__153 = new TH1F("wj_eta_8TeV_870_1001_2ratiocomp1__153","wm_eta",4, xAxis127);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinContent(1,1);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinContent(2,1);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinContent(3,1);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinContent(4,1);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinContent(5,6.28784);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinError(1,0.01017984);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinError(2,0.009372258);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinError(3,0.0104088);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinError(4,0.01263249);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetBinError(5,0.0794311);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetMinimum(0.71);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetMaximum(1.29);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetEntries(13);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetStats(0);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetFillColor(ci);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetLineColor(ci);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetLineWidth(2);

   ci = TColor::GetColor("#0033ff");
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetMarkerColor(ci);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->SetMarkerStyle(0);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp1__153->Draw("e2same");
   
   Double_t wj_eta_8TeV_870_1001_2ratiocomp2_fx3185[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp2_fy3185[4] = {
   1.215628,
   1.129992,
   1.13554,
   1.037194};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp2_felx3185[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp2_fely3185[4] = {
   0.1304777,
   0.07901847,
   0.1446727,
   0.1206757};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp2_fehx3185[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp2_fehy3185[4] = {
   0.08718166,
   0.07948094,
   0.106626,
   0.1241031};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_870_1001_2ratiocomp2_fx3185,wj_eta_8TeV_870_1001_2ratiocomp2_fy3185,wj_eta_8TeV_870_1001_2ratiocomp2_felx3185,wj_eta_8TeV_870_1001_2ratiocomp2_fehx3185,wj_eta_8TeV_870_1001_2ratiocomp2_fely3185,wj_eta_8TeV_870_1001_2ratiocomp2_fehy3185);
   grae->SetName("wj_eta_8TeV_870_1001_2ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_eta_8TeV_870_1001_2ratiocomp23185 = new TH1F("Graph_wj_eta_8TeV_870_1001_2ratiocomp23185","",100,2.1325,4.4425);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->SetMinimum(0.71);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->SetMaximum(1.29);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->SetDirectory(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->SetStats(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->SetLineWidth(2);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp23185->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_870_1001_2ratiocomp23185);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_870_1001_2ratiocomp3_fx3186[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp3_fy3186[4] = {
   1.198826,
   1.132916,
   1.119488,
   1.066786};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp3_felx3186[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp3_fely3186[4] = {
   0.09292708,
   0.08845959,
   0.09533098,
   0.1167971};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp3_fehx3186[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp3_fehy3186[4] = {
   0.09585579,
   0.09324414,
   0.1035784,
   0.1248131};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_870_1001_2ratiocomp3_fx3186,wj_eta_8TeV_870_1001_2ratiocomp3_fy3186,wj_eta_8TeV_870_1001_2ratiocomp3_felx3186,wj_eta_8TeV_870_1001_2ratiocomp3_fehx3186,wj_eta_8TeV_870_1001_2ratiocomp3_fely3186,wj_eta_8TeV_870_1001_2ratiocomp3_fehy3186);
   grae->SetName("wj_eta_8TeV_870_1001_2ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_eta_8TeV_870_1001_2ratiocomp33186 = new TH1F("Graph_wj_eta_8TeV_870_1001_2ratiocomp33186","",100,1.98,4.32);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->SetMinimum(0.71);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->SetMaximum(1.29);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->SetDirectory(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->SetStats(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->SetLineWidth(2);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp33186->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_870_1001_2ratiocomp33186);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_870_1001_2ratiocomp4_fx3187[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp4_fy3187[4] = {
   1.215628,
   1.129992,
   1.13554,
   1.037194};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp4_felx3187[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp4_fely3187[4] = {
   0.06909767,
   0.05784207,
   0.06336258,
   0.06294281};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp4_fehx3187[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp4_fehy3187[4] = {
   0.06890789,
   0.05281964,
   0.07096352,
   0.07065832};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_870_1001_2ratiocomp4_fx3187,wj_eta_8TeV_870_1001_2ratiocomp4_fy3187,wj_eta_8TeV_870_1001_2ratiocomp4_felx3187,wj_eta_8TeV_870_1001_2ratiocomp4_fehx3187,wj_eta_8TeV_870_1001_2ratiocomp4_fely3187,wj_eta_8TeV_870_1001_2ratiocomp4_fehy3187);
   grae->SetName("wj_eta_8TeV_870_1001_2ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_wj_eta_8TeV_870_1001_2ratiocomp43187 = new TH1F("Graph_wj_eta_8TeV_870_1001_2ratiocomp43187","",100,2.1325,4.4425);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->SetMinimum(0.71);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->SetMaximum(1.29);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->SetDirectory(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->SetStats(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->SetLineWidth(2);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp43187->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_870_1001_2ratiocomp43187);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_870_1001_2ratiocomp5_fx3188[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp5_fy3188[4] = {
   1.198826,
   1.132916,
   1.119488,
   1.066786};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp5_felx3188[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp5_fely3188[4] = {
   0.07300405,
   0.06753022,
   0.06762996,
   0.06843272};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp5_fehx3188[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_870_1001_2ratiocomp5_fehy3188[4] = {
   0.0775996,
   0.07155919,
   0.07341446,
   0.07628906};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_870_1001_2ratiocomp5_fx3188,wj_eta_8TeV_870_1001_2ratiocomp5_fy3188,wj_eta_8TeV_870_1001_2ratiocomp5_felx3188,wj_eta_8TeV_870_1001_2ratiocomp5_fehx3188,wj_eta_8TeV_870_1001_2ratiocomp5_fely3188,wj_eta_8TeV_870_1001_2ratiocomp5_fehy3188);
   grae->SetName("wj_eta_8TeV_870_1001_2ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_wj_eta_8TeV_870_1001_2ratiocomp53188 = new TH1F("Graph_wj_eta_8TeV_870_1001_2ratiocomp53188","",100,1.98,4.32);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->SetMinimum(0.71);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->SetMaximum(1.29);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->SetDirectory(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->SetStats(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->SetLineWidth(2);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_870_1001_2ratiocomp53188->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_870_1001_2ratiocomp53188);
   
   grae->Draw("p1");
   Double_t xAxis128[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_870_1001_2ratiocomp0_copy__154 = new TH1F("wj_eta_8TeV_870_1001_2ratiocomp0_copy__154","wm_eta",4, xAxis128);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinContent(1,1);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinContent(2,1);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinContent(3,1);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinContent(4,1);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinContent(5,6.28784);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinError(1,0.1088674);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinError(2,0.1140931);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinError(3,0.1018825);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinError(4,0.1164831);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetBinError(5,0.7324271);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetMinimum(0.71);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetMaximum(1.29);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetEntries(13);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetDirectory(0);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetStats(0);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetFillColor(ci);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetLineColor(ci);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetLineWidth(2);

   ci = TColor::GetColor("#00ccff");
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetMarkerColor(ci);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->SetMarkerStyle(0);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetXaxis()->SetLabelOffset(0.02);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetXaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_870_1001_2ratiocomp0_copy__154->Draw("sameaxis");
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
   Double_t xAxis129[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_400_1001_0ratiocomp0__155 = new TH1F("wj_eta_8TeV_400_1001_0ratiocomp0__155","wp_eta",4, xAxis129);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinContent(1,1);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinContent(2,1);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinContent(3,1);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinContent(4,1);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinContent(5,6.068387);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinError(1,0.09392341);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinError(2,0.09393057);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinError(3,0.08578873);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinError(4,0.07805435);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetBinError(5,0.473664);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetMinimum(0.71);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetMaximum(1.29);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetEntries(13);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetLineColor(ci);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetMarkerColor(ci);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->SetMarkerStyle(0);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0__155->Draw("e2");
   Double_t xAxis130[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_400_1001_0ratiocomp1__156 = new TH1F("wj_eta_8TeV_400_1001_0ratiocomp1__156","wp_eta",4, xAxis130);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinContent(1,1);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinContent(2,1);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinContent(3,1);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinContent(4,1);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinContent(5,6.068387);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinError(1,0.00687006);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinError(2,0.006835955);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinError(3,0.008505529);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinError(4,0.01267077);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetBinError(5,0.07689115);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetMinimum(0.71);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetMaximum(1.29);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetEntries(13);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetLineColor(ci);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetMarkerColor(ci);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->SetMarkerStyle(0);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp1__156->Draw("e2same");
   
   Double_t wj_eta_8TeV_400_1001_0ratiocomp2_fx3189[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp2_fy3189[4] = {
   1.063803,
   1.077505,
   1.038863,
   0.9763321};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp2_felx3189[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp2_fely3189[4] = {
   0.07958749,
   0.08191061,
   0.1065748,
   0.09645891};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp2_fehx3189[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp2_fehy3189[4] = {
   0.06877838,
   0.08344737,
   0.07840062,
   0.1103117};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_400_1001_0ratiocomp2_fx3189,wj_eta_8TeV_400_1001_0ratiocomp2_fy3189,wj_eta_8TeV_400_1001_0ratiocomp2_felx3189,wj_eta_8TeV_400_1001_0ratiocomp2_fehx3189,wj_eta_8TeV_400_1001_0ratiocomp2_fely3189,wj_eta_8TeV_400_1001_0ratiocomp2_fehy3189);
   grae->SetName("wj_eta_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_eta_8TeV_400_1001_0ratiocomp23189 = new TH1F("Graph_wj_eta_8TeV_400_1001_0ratiocomp23189","",100,2.17,4.03);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->SetMinimum(0.71);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->SetMaximum(1.29);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->SetDirectory(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->SetStats(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->SetLineWidth(2);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp23189->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_400_1001_0ratiocomp23189);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_400_1001_0ratiocomp3_fx3190[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp3_fy3190[4] = {
   1.074259,
   1.098001,
   1.077781,
   1.036051};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp3_felx3190[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp3_fely3190[4] = {
   0.07991302,
   0.08752332,
   0.08908284,
   0.09769886};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp3_fehx3190[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp3_fehy3190[4] = {
   0.08345087,
   0.09068646,
   0.09458514,
   0.1121944};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_400_1001_0ratiocomp3_fx3190,wj_eta_8TeV_400_1001_0ratiocomp3_fy3190,wj_eta_8TeV_400_1001_0ratiocomp3_felx3190,wj_eta_8TeV_400_1001_0ratiocomp3_fehx3190,wj_eta_8TeV_400_1001_0ratiocomp3_fely3190,wj_eta_8TeV_400_1001_0ratiocomp3_fehy3190);
   grae->SetName("wj_eta_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_eta_8TeV_400_1001_0ratiocomp33190 = new TH1F("Graph_wj_eta_8TeV_400_1001_0ratiocomp33190","",100,2.0175,3.9075);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->SetMinimum(0.71);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->SetMaximum(1.29);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->SetDirectory(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->SetStats(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->SetLineWidth(2);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp33190->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_400_1001_0ratiocomp33190);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_400_1001_0ratiocomp4_fx3191[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp4_fy3191[4] = {
   1.063803,
   1.077505,
   1.038863,
   0.9763321};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp4_felx3191[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp4_fely3191[4] = {
   0.05699913,
   0.05914322,
   0.05621066,
   0.05770163};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp4_fehx3191[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp4_fehy3191[4] = {
   0.05433766,
   0.05740133,
   0.05392981,
   0.07064912};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_400_1001_0ratiocomp4_fx3191,wj_eta_8TeV_400_1001_0ratiocomp4_fy3191,wj_eta_8TeV_400_1001_0ratiocomp4_felx3191,wj_eta_8TeV_400_1001_0ratiocomp4_fehx3191,wj_eta_8TeV_400_1001_0ratiocomp4_fely3191,wj_eta_8TeV_400_1001_0ratiocomp4_fehy3191);
   grae->SetName("wj_eta_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_eta_8TeV_400_1001_0ratiocomp43191 = new TH1F("Graph_wj_eta_8TeV_400_1001_0ratiocomp43191","",100,2.17,4.03);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->SetMinimum(0.71);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->SetMaximum(1.29);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->SetDirectory(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->SetStats(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->SetLineWidth(2);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp43191->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_400_1001_0ratiocomp43191);
   
   grae->Draw("p1");
   
   Double_t wj_eta_8TeV_400_1001_0ratiocomp5_fx3192[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp5_fy3192[4] = {
   1.074259,
   1.098001,
   1.077781,
   1.036051};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp5_felx3192[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp5_fely3192[4] = {
   0.06543542,
   0.068854,
   0.06887198,
   0.06845265};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp5_fehx3192[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_eta_8TeV_400_1001_0ratiocomp5_fehy3192[4] = {
   0.06901492,
   0.07385818,
   0.07557173,
   0.07695526};
   grae = new TGraphAsymmErrors(4,wj_eta_8TeV_400_1001_0ratiocomp5_fx3192,wj_eta_8TeV_400_1001_0ratiocomp5_fy3192,wj_eta_8TeV_400_1001_0ratiocomp5_felx3192,wj_eta_8TeV_400_1001_0ratiocomp5_fehx3192,wj_eta_8TeV_400_1001_0ratiocomp5_fely3192,wj_eta_8TeV_400_1001_0ratiocomp5_fehy3192);
   grae->SetName("wj_eta_8TeV_400_1001_0ratiocomp5");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_eta_8TeV_400_1001_0ratiocomp53192 = new TH1F("Graph_wj_eta_8TeV_400_1001_0ratiocomp53192","",100,2.0175,3.9075);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->SetMinimum(0.71);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->SetMaximum(1.29);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->SetDirectory(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->SetStats(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->SetLineWidth(2);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->SetMarkerStyle(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetXaxis()->SetNdivisions(4);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetXaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetXaxis()->SetLabelOffset(999);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetXaxis()->SetLabelSize(0);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetXaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetYaxis()->SetNdivisions(505);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetYaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetYaxis()->SetTitleFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetZaxis()->SetLabelFont(132);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_eta_8TeV_400_1001_0ratiocomp53192->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_eta_8TeV_400_1001_0ratiocomp53192);
   
   grae->Draw("p1");
   Double_t xAxis131[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_eta_8TeV_400_1001_0ratiocomp0_copy__157 = new TH1F("wj_eta_8TeV_400_1001_0ratiocomp0_copy__157","wp_eta",4, xAxis131);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinContent(1,1);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinContent(2,1);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinContent(3,1);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinContent(4,1);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinContent(5,6.068387);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinError(1,0.09392341);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinError(2,0.09393057);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinError(3,0.08578873);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinError(4,0.07805435);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetBinError(5,0.473664);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetMinimum(0.71);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetMaximum(1.29);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetEntries(13);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetDirectory(0);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetLineColor(ci);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetMarkerColor(ci);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->SetMarkerStyle(0);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetXaxis()->SetNdivisions(4);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetXaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetXaxis()->SetLabelOffset(999);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetXaxis()->SetLabelSize(0);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetXaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetXaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetYaxis()->SetNdivisions(505);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetYaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetYaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetYaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetYaxis()->SetTickLength(0.12325);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetYaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetZaxis()->SetLabelFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetZaxis()->SetLabelSize(0.05);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetZaxis()->SetTitleSize(0.06);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->GetZaxis()->SetTitleFont(132);
   wj_eta_8TeV_400_1001_0ratiocomp0_copy__157->Draw("sameaxis");
   middlPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
