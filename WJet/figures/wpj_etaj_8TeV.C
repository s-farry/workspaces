void wpj_etaj_8TeV()
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
   upperPad->Range(1.854321,-13.82599,4.323457,84.93821);
   upperPad->SetFillColor(0);
   upperPad->SetFillStyle(4000);
   upperPad->SetBorderMode(0);
   upperPad->SetBorderSize(2);
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
   Double_t xAxis37[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_toterr__49 = new TH1F("wp_etaj_toterr__49","wp_etaj",4, xAxis37);
   wp_etaj_toterr__49->SetBinContent(1,48.4905);
   wp_etaj_toterr__49->SetBinContent(2,35.86988);
   wp_etaj_toterr__49->SetBinContent(3,21.33691);
   wp_etaj_toterr__49->SetBinContent(4,8.08127);
   wp_etaj_toterr__49->SetBinContent(5,4.040633);
   wp_etaj_toterr__49->SetBinError(1,4.411155);
   wp_etaj_toterr__49->SetBinError(2,3.103339);
   wp_etaj_toterr__49->SetBinError(3,1.964878);
   wp_etaj_toterr__49->SetBinError(4,1.063724);
   wp_etaj_toterr__49->SetBinError(5,0.5318616);
   wp_etaj_toterr__49->SetMinimum(0.001);
   wp_etaj_toterr__49->SetMaximum(80);
   wp_etaj_toterr__49->SetEntries(10);
   wp_etaj_toterr__49->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__49->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__49->SetLineColor(ci);
   wp_etaj_toterr__49->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr__49->SetMarkerColor(ci);
   wp_etaj_toterr__49->SetMarkerStyle(0);
   wp_etaj_toterr__49->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wp_etaj_toterr__49->GetXaxis()->SetNdivisions(4);
   wp_etaj_toterr__49->GetXaxis()->SetLabelFont(132);
   wp_etaj_toterr__49->GetXaxis()->SetLabelOffset(0.02);
   wp_etaj_toterr__49->GetXaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__49->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__49->GetXaxis()->SetTitleFont(132);
   wp_etaj_toterr__49->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_toterr__49->GetYaxis()->SetLabelFont(132);
   wp_etaj_toterr__49->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__49->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__49->GetYaxis()->SetTitleFont(132);
   wp_etaj_toterr__49->GetZaxis()->SetLabelFont(132);
   wp_etaj_toterr__49->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_toterr__49->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_toterr__49->GetZaxis()->SetTitleFont(132);
   wp_etaj_toterr__49->Draw("e2");
   Double_t xAxis38[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_staterr__50 = new TH1F("wp_etaj_staterr__50","wp_etaj",4, xAxis38);
   wp_etaj_staterr__50->SetBinContent(1,48.4905);
   wp_etaj_staterr__50->SetBinContent(2,35.86988);
   wp_etaj_staterr__50->SetBinContent(3,21.33691);
   wp_etaj_staterr__50->SetBinContent(4,8.08127);
   wp_etaj_staterr__50->SetBinContent(5,4.040633);
   wp_etaj_staterr__50->SetBinError(1,0.2913562);
   wp_etaj_staterr__50->SetBinError(2,0.2625);
   wp_etaj_staterr__50->SetBinError(3,0.2016292);
   wp_etaj_staterr__50->SetBinError(4,0.1160552);
   wp_etaj_staterr__50->SetBinError(5,0.05802755);
   wp_etaj_staterr__50->SetMinimum(0.001);
   wp_etaj_staterr__50->SetMaximum(80);
   wp_etaj_staterr__50->SetEntries(10);
   wp_etaj_staterr__50->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__50->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__50->SetLineColor(ci);
   wp_etaj_staterr__50->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_etaj_staterr__50->SetMarkerColor(ci);
   wp_etaj_staterr__50->SetMarkerStyle(0);
   wp_etaj_staterr__50->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wp_etaj_staterr__50->GetXaxis()->SetNdivisions(4);
   wp_etaj_staterr__50->GetXaxis()->SetLabelFont(132);
   wp_etaj_staterr__50->GetXaxis()->SetLabelOffset(0.02);
   wp_etaj_staterr__50->GetXaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__50->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__50->GetXaxis()->SetTitleFont(132);
   wp_etaj_staterr__50->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_staterr__50->GetYaxis()->SetLabelFont(132);
   wp_etaj_staterr__50->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__50->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__50->GetYaxis()->SetTitleFont(132);
   wp_etaj_staterr__50->GetZaxis()->SetLabelFont(132);
   wp_etaj_staterr__50->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_staterr__50->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_staterr__50->GetZaxis()->SetTitleFont(132);
   wp_etaj_staterr__50->Draw("e2same");
   
   Double_t etaj_plus_toterrs_fx3057[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_plus_toterrs_fy3057[4] = {
   51.28224,
   38.08475,
   22.54357,
   9.721132};
   Double_t etaj_plus_toterrs_felx3057[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fely3057[4] = {
   4.135599,
   2.864222,
   1.897241,
   1.171681};
   Double_t etaj_plus_toterrs_fehx3057[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fehy3057[4] = {
   3.726354,
   2.706163,
   1.524886,
   1.41675};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,etaj_plus_toterrs_fx3057,etaj_plus_toterrs_fy3057,etaj_plus_toterrs_felx3057,etaj_plus_toterrs_fehx3057,etaj_plus_toterrs_fely3057,etaj_plus_toterrs_fehy3057);
   grae->SetName("etaj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_etaj_plus_toterrs3057 = new TH1F("Graph_etaj_plus_toterrs3057","",100,2.375,4.175);
   Graph_etaj_plus_toterrs3057->SetMinimum(0.001);
   Graph_etaj_plus_toterrs3057->SetMaximum(80);
   Graph_etaj_plus_toterrs3057->SetDirectory(0);
   Graph_etaj_plus_toterrs3057->SetStats(0);
   Graph_etaj_plus_toterrs3057->SetLineWidth(2);
   Graph_etaj_plus_toterrs3057->SetMarkerStyle(0);
   Graph_etaj_plus_toterrs3057->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_etaj_plus_toterrs3057->GetXaxis()->SetNdivisions(4);
   Graph_etaj_plus_toterrs3057->GetXaxis()->SetLabelFont(132);
   Graph_etaj_plus_toterrs3057->GetXaxis()->SetLabelOffset(0.02);
   Graph_etaj_plus_toterrs3057->GetXaxis()->SetLabelSize(0.05);
   Graph_etaj_plus_toterrs3057->GetXaxis()->SetTitleSize(0.06);
   Graph_etaj_plus_toterrs3057->GetXaxis()->SetTitleFont(132);
   Graph_etaj_plus_toterrs3057->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_etaj_plus_toterrs3057->GetYaxis()->SetLabelFont(132);
   Graph_etaj_plus_toterrs3057->GetYaxis()->SetLabelSize(0.05);
   Graph_etaj_plus_toterrs3057->GetYaxis()->SetTitleSize(0.06);
   Graph_etaj_plus_toterrs3057->GetYaxis()->SetTitleFont(132);
   Graph_etaj_plus_toterrs3057->GetZaxis()->SetLabelFont(132);
   Graph_etaj_plus_toterrs3057->GetZaxis()->SetLabelSize(0.05);
   Graph_etaj_plus_toterrs3057->GetZaxis()->SetTitleSize(0.06);
   Graph_etaj_plus_toterrs3057->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_etaj_plus_toterrs3057);
   
   grae->Draw("p1p");
   
   Double_t _fx3058[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3058[4] = {
   51.28224,
   38.08475,
   22.54357,
   9.721132};
   Double_t _felx3058[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3058[4] = {
   2.936905,
   2.066395,
   1.139271,
   0.5043745};
   Double_t _fehx3058[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3058[4] = {
   2.927589,
   2.099415,
   1.044388,
   0.5327406};
   grae = new TGraphAsymmErrors(4,_fx3058,_fy3058,_felx3058,_fehx3058,_fely3058,_fehy3058);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3058 = new TH1F("Graph_Graph3058","",100,2.375,4.175);
   Graph_Graph3058->SetMinimum(0.001);
   Graph_Graph3058->SetMaximum(80);
   Graph_Graph3058->SetDirectory(0);
   Graph_Graph3058->SetStats(0);
   Graph_Graph3058->SetLineWidth(2);
   Graph_Graph3058->SetMarkerStyle(0);
   Graph_Graph3058->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_Graph3058->GetXaxis()->SetNdivisions(4);
   Graph_Graph3058->GetXaxis()->SetLabelFont(132);
   Graph_Graph3058->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3058->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3058->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3058->GetXaxis()->SetTitleFont(132);
   Graph_Graph3058->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph3058->GetYaxis()->SetLabelFont(132);
   Graph_Graph3058->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3058->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3058->GetYaxis()->SetTitleFont(132);
   Graph_Graph3058->GetZaxis()->SetLabelFont(132);
   Graph_Graph3058->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3058->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3058->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3058);
   
   grae->Draw("p1p");
   
   Double_t etaj_plus_toterrs_fx3059[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_plus_toterrs_fy3059[4] = {
   52.81753,
   39.16372,
   22.80511,
   9.659266};
   Double_t etaj_plus_toterrs_felx3059[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fely3059[4] = {
   4.306575,
   3.058371,
   1.708201,
   0.8035311};
   Double_t etaj_plus_toterrs_fehx3059[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_plus_toterrs_fehy3059[4] = {
   4.54964,
   3.141914,
   1.795995,
   0.9815417};
   grae = new TGraphAsymmErrors(4,etaj_plus_toterrs_fx3059,etaj_plus_toterrs_fy3059,etaj_plus_toterrs_felx3059,etaj_plus_toterrs_fehx3059,etaj_plus_toterrs_fely3059,etaj_plus_toterrs_fehy3059);
   grae->SetName("etaj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_etaj_plus_toterrs3059 = new TH1F("Graph_etaj_plus_toterrs3059","",100,2.225,4.025);
   Graph_etaj_plus_toterrs3059->SetMinimum(0.001);
   Graph_etaj_plus_toterrs3059->SetMaximum(80);
   Graph_etaj_plus_toterrs3059->SetDirectory(0);
   Graph_etaj_plus_toterrs3059->SetStats(0);
   Graph_etaj_plus_toterrs3059->SetLineWidth(2);
   Graph_etaj_plus_toterrs3059->SetMarkerStyle(0);
   Graph_etaj_plus_toterrs3059->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_etaj_plus_toterrs3059->GetXaxis()->SetNdivisions(4);
   Graph_etaj_plus_toterrs3059->GetXaxis()->SetLabelFont(132);
   Graph_etaj_plus_toterrs3059->GetXaxis()->SetLabelOffset(0.02);
   Graph_etaj_plus_toterrs3059->GetXaxis()->SetLabelSize(0.05);
   Graph_etaj_plus_toterrs3059->GetXaxis()->SetTitleSize(0.06);
   Graph_etaj_plus_toterrs3059->GetXaxis()->SetTitleFont(132);
   Graph_etaj_plus_toterrs3059->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_etaj_plus_toterrs3059->GetYaxis()->SetLabelFont(132);
   Graph_etaj_plus_toterrs3059->GetYaxis()->SetLabelSize(0.05);
   Graph_etaj_plus_toterrs3059->GetYaxis()->SetTitleSize(0.06);
   Graph_etaj_plus_toterrs3059->GetYaxis()->SetTitleFont(132);
   Graph_etaj_plus_toterrs3059->GetZaxis()->SetLabelFont(132);
   Graph_etaj_plus_toterrs3059->GetZaxis()->SetLabelSize(0.05);
   Graph_etaj_plus_toterrs3059->GetZaxis()->SetTitleSize(0.06);
   Graph_etaj_plus_toterrs3059->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_etaj_plus_toterrs3059);
   
   grae->Draw("p1p");
   
   Double_t _fx3060[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3060[4] = {
   52.81753,
   39.16372,
   22.80511,
   9.659266};
   Double_t _felx3060[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3060[4] = {
   3.452812,
   2.405918,
   1.347227,
   0.5864553};
   Double_t _fehx3060[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3060[4] = {
   3.75058,
   2.558147,
   1.433882,
   0.6369553};
   grae = new TGraphAsymmErrors(4,_fx3060,_fy3060,_felx3060,_fehx3060,_fely3060,_fehy3060);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3060 = new TH1F("Graph_Graph3060","",100,2.225,4.025);
   Graph_Graph3060->SetMinimum(0.001);
   Graph_Graph3060->SetMaximum(80);
   Graph_Graph3060->SetDirectory(0);
   Graph_Graph3060->SetStats(0);
   Graph_Graph3060->SetLineWidth(2);
   Graph_Graph3060->SetMarkerStyle(0);
   Graph_Graph3060->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_Graph3060->GetXaxis()->SetNdivisions(4);
   Graph_Graph3060->GetXaxis()->SetLabelFont(132);
   Graph_Graph3060->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3060->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3060->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3060->GetXaxis()->SetTitleFont(132);
   Graph_Graph3060->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   Graph_Graph3060->GetYaxis()->SetLabelFont(132);
   Graph_Graph3060->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3060->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3060->GetYaxis()->SetTitleFont(132);
   Graph_Graph3060->GetZaxis()->SetLabelFont(132);
   Graph_Graph3060->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3060->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3060->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3060);
   
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
   Double_t xAxis39[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wp_etaj_toterr_copy__51 = new TH1F("wp_etaj_toterr_copy__51","wp_etaj",4, xAxis39);
   wp_etaj_toterr_copy__51->SetBinContent(1,48.4905);
   wp_etaj_toterr_copy__51->SetBinContent(2,35.86988);
   wp_etaj_toterr_copy__51->SetBinContent(3,21.33691);
   wp_etaj_toterr_copy__51->SetBinContent(4,8.08127);
   wp_etaj_toterr_copy__51->SetBinContent(5,4.040633);
   wp_etaj_toterr_copy__51->SetBinError(1,4.411155);
   wp_etaj_toterr_copy__51->SetBinError(2,3.103339);
   wp_etaj_toterr_copy__51->SetBinError(3,1.964878);
   wp_etaj_toterr_copy__51->SetBinError(4,1.063724);
   wp_etaj_toterr_copy__51->SetBinError(5,0.5318616);
   wp_etaj_toterr_copy__51->SetMinimum(0.001);
   wp_etaj_toterr_copy__51->SetMaximum(80);
   wp_etaj_toterr_copy__51->SetEntries(10);
   wp_etaj_toterr_copy__51->SetDirectory(0);
   wp_etaj_toterr_copy__51->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__51->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__51->SetLineColor(ci);
   wp_etaj_toterr_copy__51->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_etaj_toterr_copy__51->SetMarkerColor(ci);
   wp_etaj_toterr_copy__51->SetMarkerStyle(0);
   wp_etaj_toterr_copy__51->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wp_etaj_toterr_copy__51->GetXaxis()->SetNdivisions(4);
   wp_etaj_toterr_copy__51->GetXaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__51->GetXaxis()->SetLabelOffset(0.02);
   wp_etaj_toterr_copy__51->GetXaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__51->GetXaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__51->GetXaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__51->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{jet} [pb]");
   wp_etaj_toterr_copy__51->GetYaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__51->GetYaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__51->GetYaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__51->GetYaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__51->GetZaxis()->SetLabelFont(132);
   wp_etaj_toterr_copy__51->GetZaxis()->SetLabelSize(0.05);
   wp_etaj_toterr_copy__51->GetZaxis()->SetTitleSize(0.06);
   wp_etaj_toterr_copy__51->GetZaxis()->SetTitleFont(132);
   wp_etaj_toterr_copy__51->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
