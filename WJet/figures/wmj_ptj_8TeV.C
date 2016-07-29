void wmj_ptj_8TeV()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Thu Apr 28 10:19:35 2016) by ROOT version6.04/10
   TCanvas *default_Canvas = new TCanvas("default_Canvas", "defaultCanvas",0,0,700,500);
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
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(6.172839,-1.846169,104.9383,0.785252);
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
   upperPad->SetBottomMargin(0.14);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   Double_t xAxis49[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_toterr__61 = new TH1F("wm_ptj_toterr__61","wm_ptj",5, xAxis49);
   wm_ptj_toterr__61->SetBinContent(1,2.161372);
   wm_ptj_toterr__61->SetBinContent(2,1.324459);
   wm_ptj_toterr__61->SetBinContent(3,0.7447754);
   wm_ptj_toterr__61->SetBinContent(4,0.3862884);
   wm_ptj_toterr__61->SetBinContent(5,0.07929422);
   wm_ptj_toterr__61->SetBinContent(6,3.964711);
   wm_ptj_toterr__61->SetBinError(1,0.2161911);
   wm_ptj_toterr__61->SetBinError(2,0.1517678);
   wm_ptj_toterr__61->SetBinError(3,0.08010473);
   wm_ptj_toterr__61->SetBinError(4,0.04449275);
   wm_ptj_toterr__61->SetBinError(5,0.01272714);
   wm_ptj_toterr__61->SetBinError(6,0.636357);
   wm_ptj_toterr__61->SetEntries(12);
   wm_ptj_toterr__61->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wm_ptj_toterr__61->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wm_ptj_toterr__61->SetLineColor(ci);
   wm_ptj_toterr__61->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wm_ptj_toterr__61->SetMarkerColor(ci);
   wm_ptj_toterr__61->SetMarkerStyle(0);
   wm_ptj_toterr__61->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wm_ptj_toterr__61->GetXaxis()->SetNdivisions(4);
   wm_ptj_toterr__61->GetXaxis()->SetLabelFont(132);
   wm_ptj_toterr__61->GetXaxis()->SetLabelOffset(0.02);
   wm_ptj_toterr__61->GetXaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__61->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__61->GetXaxis()->SetTitleFont(132);
   wm_ptj_toterr__61->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{#it{j}} [pb]");
   wm_ptj_toterr__61->GetYaxis()->SetLabelFont(132);
   wm_ptj_toterr__61->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__61->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__61->GetYaxis()->SetTitleFont(132);
   wm_ptj_toterr__61->GetZaxis()->SetLabelFont(132);
   wm_ptj_toterr__61->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_toterr__61->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_toterr__61->GetZaxis()->SetTitleFont(132);
   wm_ptj_toterr__61->Draw("e2");
   Double_t xAxis50[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_staterr__62 = new TH1F("wm_ptj_staterr__62","wm_ptj",5, xAxis50);
   wm_ptj_staterr__62->SetBinContent(1,2.161372);
   wm_ptj_staterr__62->SetBinContent(2,1.324459);
   wm_ptj_staterr__62->SetBinContent(3,0.7447754);
   wm_ptj_staterr__62->SetBinContent(4,0.3862884);
   wm_ptj_staterr__62->SetBinContent(5,0.07929422);
   wm_ptj_staterr__62->SetBinContent(6,3.964711);
   wm_ptj_staterr__62->SetBinError(1,0.01981714);
   wm_ptj_staterr__62->SetBinError(2,0.01549705);
   wm_ptj_staterr__62->SetBinError(3,0.008176924);
   wm_ptj_staterr__62->SetBinError(4,0.00603614);
   wm_ptj_staterr__62->SetBinError(5,0.001217149);
   wm_ptj_staterr__62->SetBinError(6,0.06085747);
   wm_ptj_staterr__62->SetEntries(12);
   wm_ptj_staterr__62->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wm_ptj_staterr__62->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wm_ptj_staterr__62->SetLineColor(ci);
   wm_ptj_staterr__62->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wm_ptj_staterr__62->SetMarkerColor(ci);
   wm_ptj_staterr__62->SetMarkerStyle(0);
   wm_ptj_staterr__62->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wm_ptj_staterr__62->GetXaxis()->SetNdivisions(4);
   wm_ptj_staterr__62->GetXaxis()->SetLabelFont(132);
   wm_ptj_staterr__62->GetXaxis()->SetLabelOffset(0.02);
   wm_ptj_staterr__62->GetXaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__62->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__62->GetXaxis()->SetTitleFont(132);
   wm_ptj_staterr__62->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{#it{j}} [pb]");
   wm_ptj_staterr__62->GetYaxis()->SetLabelFont(132);
   wm_ptj_staterr__62->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__62->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__62->GetYaxis()->SetTitleFont(132);
   wm_ptj_staterr__62->GetZaxis()->SetLabelFont(132);
   wm_ptj_staterr__62->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_staterr__62->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_staterr__62->GetZaxis()->SetTitleFont(132);
   wm_ptj_staterr__62->Draw("e2same");
   
   Double_t ptj_minus_toterrs_fx3073[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_minus_toterrs_fy3073[5] = {
   2.562893,
   1.476188,
   0.8436134,
   0.4057886,
   0.09869911};
   Double_t ptj_minus_toterrs_felx3073[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fely3073[5] = {
   0.266341,
   0.1072309,
   0.08437284,
   0.03839483,
   0.01553516};
   Double_t ptj_minus_toterrs_fehx3073[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fehy3073[5] = {
   0.1762218,
   0.2029888,
   0.07273972,
   0.04002159,
   0.01249906};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,ptj_minus_toterrs_fx3073,ptj_minus_toterrs_fy3073,ptj_minus_toterrs_felx3073,ptj_minus_toterrs_fehx3073,ptj_minus_toterrs_fely3073,ptj_minus_toterrs_fehy3073);
   grae->SetName("ptj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_ptj_minus_toterrs3073 = new TH1F("Graph_ptj_minus_toterrs3073","",100,17.325,88.425);
   Graph_ptj_minus_toterrs3073->SetMinimum(0.07484756);
   Graph_ptj_minus_toterrs3073->SetMaximum(3.00471);
   Graph_ptj_minus_toterrs3073->SetDirectory(0);
   Graph_ptj_minus_toterrs3073->SetStats(0);
   Graph_ptj_minus_toterrs3073->SetLineWidth(2);
   Graph_ptj_minus_toterrs3073->SetMarkerStyle(0);
   Graph_ptj_minus_toterrs3073->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_ptj_minus_toterrs3073->GetXaxis()->SetNdivisions(4);
   Graph_ptj_minus_toterrs3073->GetXaxis()->SetLabelFont(132);
   Graph_ptj_minus_toterrs3073->GetXaxis()->SetLabelOffset(0.02);
   Graph_ptj_minus_toterrs3073->GetXaxis()->SetLabelSize(0.05);
   Graph_ptj_minus_toterrs3073->GetXaxis()->SetTitleSize(0.06);
   Graph_ptj_minus_toterrs3073->GetXaxis()->SetTitleFont(132);
   Graph_ptj_minus_toterrs3073->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{#it{j}} [pb]");
   Graph_ptj_minus_toterrs3073->GetYaxis()->SetLabelFont(132);
   Graph_ptj_minus_toterrs3073->GetYaxis()->SetLabelSize(0.05);
   Graph_ptj_minus_toterrs3073->GetYaxis()->SetTitleSize(0.06);
   Graph_ptj_minus_toterrs3073->GetYaxis()->SetTitleFont(132);
   Graph_ptj_minus_toterrs3073->GetZaxis()->SetLabelFont(132);
   Graph_ptj_minus_toterrs3073->GetZaxis()->SetLabelSize(0.05);
   Graph_ptj_minus_toterrs3073->GetZaxis()->SetTitleSize(0.06);
   Graph_ptj_minus_toterrs3073->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ptj_minus_toterrs3073);
   
   grae->Draw("p1p");
   
   Double_t _fx3074[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3074[5] = {
   2.562893,
   1.476188,
   0.8436134,
   0.4057886,
   0.09869911};
   Double_t _felx3074[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3074[5] = {
   0.1369467,
   0.0783433,
   0.04753537,
   0.0220407,
   0.007140055};
   Double_t _fehx3074[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3074[5] = {
   0.1275658,
   0.07309179,
   0.05322437,
   0.02140498,
   0.009120522};
   grae = new TGraphAsymmErrors(5,_fx3074,_fy3074,_felx3074,_fehx3074,_fely3074,_fehy3074);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph3074 = new TH1F("Graph_Graph3074","",100,17.325,88.425);
   Graph_Graph3074->SetMinimum(0.08240315);
   Graph_Graph3074->SetMaximum(2.950349);
   Graph_Graph3074->SetDirectory(0);
   Graph_Graph3074->SetStats(0);
   Graph_Graph3074->SetLineWidth(2);
   Graph_Graph3074->SetMarkerStyle(0);
   Graph_Graph3074->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_Graph3074->GetXaxis()->SetNdivisions(4);
   Graph_Graph3074->GetXaxis()->SetLabelFont(132);
   Graph_Graph3074->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3074->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3074->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3074->GetXaxis()->SetTitleFont(132);
   Graph_Graph3074->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{#it{j}} [pb]");
   Graph_Graph3074->GetYaxis()->SetLabelFont(132);
   Graph_Graph3074->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3074->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3074->GetYaxis()->SetTitleFont(132);
   Graph_Graph3074->GetZaxis()->SetLabelFont(132);
   Graph_Graph3074->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3074->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3074->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3074);
   
   grae->Draw("p1p");
   
   Double_t ptj_minus_toterrs_fx3075[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_minus_toterrs_fy3075[5] = {
   2.425233,
   1.507886,
   0.829673,
   0.4212834,
   0.1045012};
   Double_t ptj_minus_toterrs_felx3075[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fely3075[5] = {
   0.1865384,
   0.1193402,
   0.06892636,
   0.03735492,
   0.01026445};
   Double_t ptj_minus_toterrs_fehx3075[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_minus_toterrs_fehy3075[5] = {
   0.1902493,
   0.1251425,
   0.0772211,
   0.04040276,
   0.01118462};
   grae = new TGraphAsymmErrors(5,ptj_minus_toterrs_fx3075,ptj_minus_toterrs_fy3075,ptj_minus_toterrs_felx3075,ptj_minus_toterrs_fehx3075,ptj_minus_toterrs_fely3075,ptj_minus_toterrs_fehy3075);
   grae->SetName("ptj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_ptj_minus_toterrs3075 = new TH1F("Graph_ptj_minus_toterrs3075","",100,17.175,72.075);
   Graph_ptj_minus_toterrs3075->SetMinimum(0.08481303);
   Graph_ptj_minus_toterrs3075->SetMaximum(2.867607);
   Graph_ptj_minus_toterrs3075->SetDirectory(0);
   Graph_ptj_minus_toterrs3075->SetStats(0);
   Graph_ptj_minus_toterrs3075->SetLineWidth(2);
   Graph_ptj_minus_toterrs3075->SetMarkerStyle(0);
   Graph_ptj_minus_toterrs3075->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_ptj_minus_toterrs3075->GetXaxis()->SetNdivisions(4);
   Graph_ptj_minus_toterrs3075->GetXaxis()->SetLabelFont(132);
   Graph_ptj_minus_toterrs3075->GetXaxis()->SetLabelOffset(0.02);
   Graph_ptj_minus_toterrs3075->GetXaxis()->SetLabelSize(0.05);
   Graph_ptj_minus_toterrs3075->GetXaxis()->SetTitleSize(0.06);
   Graph_ptj_minus_toterrs3075->GetXaxis()->SetTitleFont(132);
   Graph_ptj_minus_toterrs3075->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{#it{j}} [pb]");
   Graph_ptj_minus_toterrs3075->GetYaxis()->SetLabelFont(132);
   Graph_ptj_minus_toterrs3075->GetYaxis()->SetLabelSize(0.05);
   Graph_ptj_minus_toterrs3075->GetYaxis()->SetTitleSize(0.06);
   Graph_ptj_minus_toterrs3075->GetYaxis()->SetTitleFont(132);
   Graph_ptj_minus_toterrs3075->GetZaxis()->SetLabelFont(132);
   Graph_ptj_minus_toterrs3075->GetZaxis()->SetLabelSize(0.05);
   Graph_ptj_minus_toterrs3075->GetZaxis()->SetTitleSize(0.06);
   Graph_ptj_minus_toterrs3075->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ptj_minus_toterrs3075);
   
   grae->Draw("p1p");
   
   Double_t _fx3076[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3076[5] = {
   2.425233,
   1.507886,
   0.829673,
   0.4212834,
   0.1045012};
   Double_t _felx3076[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3076[5] = {
   0.1399179,
   0.08881254,
   0.05086884,
   0.02694438,
   0.006972694};
   Double_t _fehx3076[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3076[5] = {
   0.1450405,
   0.09567509,
   0.05554514,
   0.02997656,
   0.007936096};
   grae = new TGraphAsymmErrors(5,_fx3076,_fy3076,_felx3076,_fehx3076,_fely3076,_fehy3076);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph3076 = new TH1F("Graph_Graph3076","",100,17.175,72.075);
   Graph_Graph3076->SetMinimum(0.08777561);
   Graph_Graph3076->SetMaximum(2.817548);
   Graph_Graph3076->SetDirectory(0);
   Graph_Graph3076->SetStats(0);
   Graph_Graph3076->SetLineWidth(2);
   Graph_Graph3076->SetMarkerStyle(0);
   Graph_Graph3076->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_Graph3076->GetXaxis()->SetNdivisions(4);
   Graph_Graph3076->GetXaxis()->SetLabelFont(132);
   Graph_Graph3076->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3076->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3076->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3076->GetXaxis()->SetTitleFont(132);
   Graph_Graph3076->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{#it{j}} [pb]");
   Graph_Graph3076->GetYaxis()->SetLabelFont(132);
   Graph_Graph3076->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3076->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3076->GetYaxis()->SetTitleFont(132);
   Graph_Graph3076->GetZaxis()->SetLabelFont(132);
   Graph_Graph3076->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3076->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3076->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3076);
   
   grae->Draw("p1p");
   
   TLegend *leg = new TLegend(0.65,0.57,0.95,0.82,NULL,"brNDC");
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
   entry=leg->AddEntry("powheg_temp","POWHEG","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("amcatnlo_temp","aMC@NLO","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   Double_t xAxis51[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wm_ptj_toterr_copy__63 = new TH1F("wm_ptj_toterr_copy__63","wm_ptj",5, xAxis51);
   wm_ptj_toterr_copy__63->SetBinContent(1,2.161372);
   wm_ptj_toterr_copy__63->SetBinContent(2,1.324459);
   wm_ptj_toterr_copy__63->SetBinContent(3,0.7447754);
   wm_ptj_toterr_copy__63->SetBinContent(4,0.3862884);
   wm_ptj_toterr_copy__63->SetBinContent(5,0.07929422);
   wm_ptj_toterr_copy__63->SetBinContent(6,3.964711);
   wm_ptj_toterr_copy__63->SetBinError(1,0.2161911);
   wm_ptj_toterr_copy__63->SetBinError(2,0.1517678);
   wm_ptj_toterr_copy__63->SetBinError(3,0.08010473);
   wm_ptj_toterr_copy__63->SetBinError(4,0.04449275);
   wm_ptj_toterr_copy__63->SetBinError(5,0.01272714);
   wm_ptj_toterr_copy__63->SetBinError(6,0.636357);
   wm_ptj_toterr_copy__63->SetEntries(12);
   wm_ptj_toterr_copy__63->SetDirectory(0);
   wm_ptj_toterr_copy__63->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wm_ptj_toterr_copy__63->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wm_ptj_toterr_copy__63->SetLineColor(ci);
   wm_ptj_toterr_copy__63->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wm_ptj_toterr_copy__63->SetMarkerColor(ci);
   wm_ptj_toterr_copy__63->SetMarkerStyle(0);
   wm_ptj_toterr_copy__63->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wm_ptj_toterr_copy__63->GetXaxis()->SetNdivisions(4);
   wm_ptj_toterr_copy__63->GetXaxis()->SetLabelFont(132);
   wm_ptj_toterr_copy__63->GetXaxis()->SetLabelOffset(0.02);
   wm_ptj_toterr_copy__63->GetXaxis()->SetLabelSize(0.05);
   wm_ptj_toterr_copy__63->GetXaxis()->SetTitleSize(0.06);
   wm_ptj_toterr_copy__63->GetXaxis()->SetTitleFont(132);
   wm_ptj_toterr_copy__63->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{#it{j}} [pb]");
   wm_ptj_toterr_copy__63->GetYaxis()->SetLabelFont(132);
   wm_ptj_toterr_copy__63->GetYaxis()->SetLabelSize(0.05);
   wm_ptj_toterr_copy__63->GetYaxis()->SetTitleSize(0.06);
   wm_ptj_toterr_copy__63->GetYaxis()->SetTitleFont(132);
   wm_ptj_toterr_copy__63->GetZaxis()->SetLabelFont(132);
   wm_ptj_toterr_copy__63->GetZaxis()->SetLabelSize(0.05);
   wm_ptj_toterr_copy__63->GetZaxis()->SetTitleSize(0.06);
   wm_ptj_toterr_copy__63->GetZaxis()->SetTitleFont(132);
   wm_ptj_toterr_copy__63->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
