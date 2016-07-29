void wpj_eta_8TeV()
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
   upperPad->Range(1.567901,-10.3692,4.654321,63.70364);
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
   Double_t xAxis43[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_toterr__55 = new TH1F("wp_eta_toterr__55","wp_eta",4, xAxis43);
   wp_eta_toterr__55->SetBinContent(1,44.48695);
   wp_eta_toterr__55->SetBinContent(2,36.18721);
   wp_eta_toterr__55->SetBinContent(3,22.58616);
   wp_eta_toterr__55->SetBinContent(4,6.068387);
   wp_eta_toterr__55->SetBinContent(5,6.068387);
   wp_eta_toterr__55->SetBinError(1,4.178366);
   wp_eta_toterr__55->SetBinError(2,3.399085);
   wp_eta_toterr__55->SetBinError(3,1.937638);
   wp_eta_toterr__55->SetBinError(4,0.473664);
   wp_eta_toterr__55->SetBinError(5,0.473664);
   wp_eta_toterr__55->SetMinimum(0.001);
   wp_eta_toterr__55->SetMaximum(60);
   wp_eta_toterr__55->SetEntries(9);
   wp_eta_toterr__55->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__55->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__55->SetLineColor(ci);
   wp_eta_toterr__55->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr__55->SetMarkerColor(ci);
   wp_eta_toterr__55->SetMarkerStyle(0);
   wp_eta_toterr__55->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wp_eta_toterr__55->GetXaxis()->SetNdivisions(4);
   wp_eta_toterr__55->GetXaxis()->SetLabelFont(132);
   wp_eta_toterr__55->GetXaxis()->SetLabelOffset(0.02);
   wp_eta_toterr__55->GetXaxis()->SetLabelSize(0.05);
   wp_eta_toterr__55->GetXaxis()->SetTitleSize(0.06);
   wp_eta_toterr__55->GetXaxis()->SetTitleFont(132);
   wp_eta_toterr__55->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_toterr__55->GetYaxis()->SetLabelFont(132);
   wp_eta_toterr__55->GetYaxis()->SetLabelSize(0.05);
   wp_eta_toterr__55->GetYaxis()->SetTitleSize(0.06);
   wp_eta_toterr__55->GetYaxis()->SetTitleFont(132);
   wp_eta_toterr__55->GetZaxis()->SetLabelFont(132);
   wp_eta_toterr__55->GetZaxis()->SetLabelSize(0.05);
   wp_eta_toterr__55->GetZaxis()->SetTitleSize(0.06);
   wp_eta_toterr__55->GetZaxis()->SetTitleFont(132);
   wp_eta_toterr__55->Draw("e2");
   Double_t xAxis44[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_staterr__56 = new TH1F("wp_eta_staterr__56","wp_eta",4, xAxis44);
   wp_eta_staterr__56->SetBinContent(1,44.48695);
   wp_eta_staterr__56->SetBinContent(2,36.18721);
   wp_eta_staterr__56->SetBinContent(3,22.58616);
   wp_eta_staterr__56->SetBinContent(4,6.068387);
   wp_eta_staterr__56->SetBinContent(5,6.068387);
   wp_eta_staterr__56->SetBinError(1,0.305628);
   wp_eta_staterr__56->SetBinError(2,0.2473742);
   wp_eta_staterr__56->SetBinError(3,0.1921072);
   wp_eta_staterr__56->SetBinError(4,0.07689115);
   wp_eta_staterr__56->SetBinError(5,0.07689115);
   wp_eta_staterr__56->SetMinimum(0.001);
   wp_eta_staterr__56->SetMaximum(60);
   wp_eta_staterr__56->SetEntries(9);
   wp_eta_staterr__56->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__56->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__56->SetLineColor(ci);
   wp_eta_staterr__56->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_eta_staterr__56->SetMarkerColor(ci);
   wp_eta_staterr__56->SetMarkerStyle(0);
   wp_eta_staterr__56->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wp_eta_staterr__56->GetXaxis()->SetNdivisions(4);
   wp_eta_staterr__56->GetXaxis()->SetLabelFont(132);
   wp_eta_staterr__56->GetXaxis()->SetLabelOffset(0.02);
   wp_eta_staterr__56->GetXaxis()->SetLabelSize(0.05);
   wp_eta_staterr__56->GetXaxis()->SetTitleSize(0.06);
   wp_eta_staterr__56->GetXaxis()->SetTitleFont(132);
   wp_eta_staterr__56->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_staterr__56->GetYaxis()->SetLabelFont(132);
   wp_eta_staterr__56->GetYaxis()->SetLabelSize(0.05);
   wp_eta_staterr__56->GetYaxis()->SetTitleSize(0.06);
   wp_eta_staterr__56->GetYaxis()->SetTitleFont(132);
   wp_eta_staterr__56->GetZaxis()->SetLabelFont(132);
   wp_eta_staterr__56->GetZaxis()->SetLabelSize(0.05);
   wp_eta_staterr__56->GetZaxis()->SetTitleSize(0.06);
   wp_eta_staterr__56->GetZaxis()->SetTitleFont(132);
   wp_eta_staterr__56->Draw("e2same");
   
   Double_t eta_plus_toterrs_fx3065[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t eta_plus_toterrs_fy3065[4] = {
   47.32533,
   38.9919,
   23.46391,
   5.924761};
   Double_t eta_plus_toterrs_felx3065[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fely3065[4] = {
   3.540604,
   2.964117,
   2.407115,
   0.58535};
   Double_t eta_plus_toterrs_fehx3065[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fehy3065[4] = {
   3.05974,
   3.019728,
   1.770769,
   0.6694141};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,eta_plus_toterrs_fx3065,eta_plus_toterrs_fy3065,eta_plus_toterrs_felx3065,eta_plus_toterrs_fehx3065,eta_plus_toterrs_fely3065,eta_plus_toterrs_fehy3065);
   grae->SetName("eta_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_eta_plus_toterrs3065 = new TH1F("Graph_eta_plus_toterrs3065","",100,2.17,4.03);
   Graph_eta_plus_toterrs3065->SetMinimum(0.001);
   Graph_eta_plus_toterrs3065->SetMaximum(60);
   Graph_eta_plus_toterrs3065->SetDirectory(0);
   Graph_eta_plus_toterrs3065->SetStats(0);
   Graph_eta_plus_toterrs3065->SetLineWidth(2);
   Graph_eta_plus_toterrs3065->SetMarkerStyle(0);
   Graph_eta_plus_toterrs3065->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_eta_plus_toterrs3065->GetXaxis()->SetNdivisions(4);
   Graph_eta_plus_toterrs3065->GetXaxis()->SetLabelFont(132);
   Graph_eta_plus_toterrs3065->GetXaxis()->SetLabelOffset(0.02);
   Graph_eta_plus_toterrs3065->GetXaxis()->SetLabelSize(0.05);
   Graph_eta_plus_toterrs3065->GetXaxis()->SetTitleSize(0.06);
   Graph_eta_plus_toterrs3065->GetXaxis()->SetTitleFont(132);
   Graph_eta_plus_toterrs3065->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_eta_plus_toterrs3065->GetYaxis()->SetLabelFont(132);
   Graph_eta_plus_toterrs3065->GetYaxis()->SetLabelSize(0.05);
   Graph_eta_plus_toterrs3065->GetYaxis()->SetTitleSize(0.06);
   Graph_eta_plus_toterrs3065->GetYaxis()->SetTitleFont(132);
   Graph_eta_plus_toterrs3065->GetZaxis()->SetLabelFont(132);
   Graph_eta_plus_toterrs3065->GetZaxis()->SetLabelSize(0.05);
   Graph_eta_plus_toterrs3065->GetZaxis()->SetTitleSize(0.06);
   Graph_eta_plus_toterrs3065->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_eta_plus_toterrs3065);
   
   grae->Draw("p1p");
   
   Double_t _fx3066[4] = {
   2.325,
   2.825,
   3.325,
   3.875};
   Double_t _fy3066[4] = {
   47.32533,
   38.9919,
   23.46391,
   5.924761};
   Double_t _felx3066[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3066[4] = {
   2.535717,
   2.140228,
   1.269583,
   0.3501558};
   Double_t _fehx3066[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3066[4] = {
   2.417316,
   2.077194,
   1.218067,
   0.4287262};
   grae = new TGraphAsymmErrors(4,_fx3066,_fy3066,_felx3066,_fehx3066,_fely3066,_fehy3066);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3066 = new TH1F("Graph_Graph3066","",100,2.17,4.03);
   Graph_Graph3066->SetMinimum(0.001);
   Graph_Graph3066->SetMaximum(60);
   Graph_Graph3066->SetDirectory(0);
   Graph_Graph3066->SetStats(0);
   Graph_Graph3066->SetLineWidth(2);
   Graph_Graph3066->SetMarkerStyle(0);
   Graph_Graph3066->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_Graph3066->GetXaxis()->SetNdivisions(4);
   Graph_Graph3066->GetXaxis()->SetLabelFont(132);
   Graph_Graph3066->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3066->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3066->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3066->GetXaxis()->SetTitleFont(132);
   Graph_Graph3066->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph3066->GetYaxis()->SetLabelFont(132);
   Graph_Graph3066->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3066->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3066->GetYaxis()->SetTitleFont(132);
   Graph_Graph3066->GetZaxis()->SetLabelFont(132);
   Graph_Graph3066->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3066->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3066->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3066);
   
   grae->Draw("p1p");
   
   Double_t eta_plus_toterrs_fx3067[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t eta_plus_toterrs_fy3067[4] = {
   47.79052,
   39.73359,
   24.34292,
   6.287156};
   Double_t eta_plus_toterrs_felx3067[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fely3067[4] = {
   3.555086,
   3.167225,
   2.012039,
   0.5928745};
   Double_t eta_plus_toterrs_fehx3067[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_plus_toterrs_fehy3067[4] = {
   3.712474,
   3.28169,
   2.136315,
   0.6808392};
   grae = new TGraphAsymmErrors(4,eta_plus_toterrs_fx3067,eta_plus_toterrs_fy3067,eta_plus_toterrs_felx3067,eta_plus_toterrs_fehx3067,eta_plus_toterrs_fely3067,eta_plus_toterrs_fehy3067);
   grae->SetName("eta_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_eta_plus_toterrs3067 = new TH1F("Graph_eta_plus_toterrs3067","",100,2.0175,3.9075);
   Graph_eta_plus_toterrs3067->SetMinimum(0.001);
   Graph_eta_plus_toterrs3067->SetMaximum(60);
   Graph_eta_plus_toterrs3067->SetDirectory(0);
   Graph_eta_plus_toterrs3067->SetStats(0);
   Graph_eta_plus_toterrs3067->SetLineWidth(2);
   Graph_eta_plus_toterrs3067->SetMarkerStyle(0);
   Graph_eta_plus_toterrs3067->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_eta_plus_toterrs3067->GetXaxis()->SetNdivisions(4);
   Graph_eta_plus_toterrs3067->GetXaxis()->SetLabelFont(132);
   Graph_eta_plus_toterrs3067->GetXaxis()->SetLabelOffset(0.02);
   Graph_eta_plus_toterrs3067->GetXaxis()->SetLabelSize(0.05);
   Graph_eta_plus_toterrs3067->GetXaxis()->SetTitleSize(0.06);
   Graph_eta_plus_toterrs3067->GetXaxis()->SetTitleFont(132);
   Graph_eta_plus_toterrs3067->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_eta_plus_toterrs3067->GetYaxis()->SetLabelFont(132);
   Graph_eta_plus_toterrs3067->GetYaxis()->SetLabelSize(0.05);
   Graph_eta_plus_toterrs3067->GetYaxis()->SetTitleSize(0.06);
   Graph_eta_plus_toterrs3067->GetYaxis()->SetTitleFont(132);
   Graph_eta_plus_toterrs3067->GetZaxis()->SetLabelFont(132);
   Graph_eta_plus_toterrs3067->GetZaxis()->SetLabelSize(0.05);
   Graph_eta_plus_toterrs3067->GetZaxis()->SetTitleSize(0.06);
   Graph_eta_plus_toterrs3067->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_eta_plus_toterrs3067);
   
   grae->Draw("p1p");
   
   Double_t _fx3068[4] = {
   2.175,
   2.675,
   3.175,
   3.75};
   Double_t _fy3068[4] = {
   47.79052,
   39.73359,
   24.34292,
   6.287156};
   Double_t _felx3068[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3068[4] = {
   2.911022,
   2.491634,
   1.555553,
   0.4153972};
   Double_t _fehx3068[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3068[4] = {
   3.070263,
   2.672722,
   1.706875,
   0.4669943};
   grae = new TGraphAsymmErrors(4,_fx3068,_fy3068,_felx3068,_fehx3068,_fely3068,_fehy3068);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3068 = new TH1F("Graph_Graph3068","",100,2.0175,3.9075);
   Graph_Graph3068->SetMinimum(0.001);
   Graph_Graph3068->SetMaximum(60);
   Graph_Graph3068->SetDirectory(0);
   Graph_Graph3068->SetStats(0);
   Graph_Graph3068->SetLineWidth(2);
   Graph_Graph3068->SetMarkerStyle(0);
   Graph_Graph3068->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_Graph3068->GetXaxis()->SetNdivisions(4);
   Graph_Graph3068->GetXaxis()->SetLabelFont(132);
   Graph_Graph3068->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3068->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3068->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3068->GetXaxis()->SetTitleFont(132);
   Graph_Graph3068->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph3068->GetYaxis()->SetLabelFont(132);
   Graph_Graph3068->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3068->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3068->GetYaxis()->SetTitleFont(132);
   Graph_Graph3068->GetZaxis()->SetLabelFont(132);
   Graph_Graph3068->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3068->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3068->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3068);
   
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
   Double_t xAxis45[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wp_eta_toterr_copy__57 = new TH1F("wp_eta_toterr_copy__57","wp_eta",4, xAxis45);
   wp_eta_toterr_copy__57->SetBinContent(1,44.48695);
   wp_eta_toterr_copy__57->SetBinContent(2,36.18721);
   wp_eta_toterr_copy__57->SetBinContent(3,22.58616);
   wp_eta_toterr_copy__57->SetBinContent(4,6.068387);
   wp_eta_toterr_copy__57->SetBinContent(5,6.068387);
   wp_eta_toterr_copy__57->SetBinError(1,4.178366);
   wp_eta_toterr_copy__57->SetBinError(2,3.399085);
   wp_eta_toterr_copy__57->SetBinError(3,1.937638);
   wp_eta_toterr_copy__57->SetBinError(4,0.473664);
   wp_eta_toterr_copy__57->SetBinError(5,0.473664);
   wp_eta_toterr_copy__57->SetMinimum(0.001);
   wp_eta_toterr_copy__57->SetMaximum(60);
   wp_eta_toterr_copy__57->SetEntries(9);
   wp_eta_toterr_copy__57->SetDirectory(0);
   wp_eta_toterr_copy__57->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__57->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__57->SetLineColor(ci);
   wp_eta_toterr_copy__57->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_eta_toterr_copy__57->SetMarkerColor(ci);
   wp_eta_toterr_copy__57->SetMarkerStyle(0);
   wp_eta_toterr_copy__57->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wp_eta_toterr_copy__57->GetXaxis()->SetNdivisions(4);
   wp_eta_toterr_copy__57->GetXaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__57->GetXaxis()->SetLabelOffset(0.02);
   wp_eta_toterr_copy__57->GetXaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__57->GetXaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__57->GetXaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__57->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wp_eta_toterr_copy__57->GetYaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__57->GetYaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__57->GetYaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__57->GetYaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__57->GetZaxis()->SetLabelFont(132);
   wp_eta_toterr_copy__57->GetZaxis()->SetLabelSize(0.05);
   wp_eta_toterr_copy__57->GetZaxis()->SetTitleSize(0.06);
   wp_eta_toterr_copy__57->GetZaxis()->SetTitleFont(132);
   wp_eta_toterr_copy__57->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
