void wmj_eta_8TeV()
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
   upperPad->Range(1.567901,-6.221049,4.654321,38.22216);
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
   Double_t xAxis52[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_toterr__64 = new TH1F("wm_eta_toterr__64","wm_eta",4, xAxis52);
   wm_eta_toterr__64->SetBinContent(1,20.31135);
   wm_eta_toterr__64->SetBinContent(2,19.05704);
   wm_eta_toterr__64->SetBinContent(3,14.77047);
   wm_eta_toterr__64->SetBinContent(4,6.28784);
   wm_eta_toterr__64->SetBinContent(5,6.28784);
   wm_eta_toterr__64->SetBinError(1,2.211244);
   wm_eta_toterr__64->SetBinError(2,2.174277);
   wm_eta_toterr__64->SetBinError(3,1.504852);
   wm_eta_toterr__64->SetBinError(4,0.7324271);
   wm_eta_toterr__64->SetBinError(5,0.7324271);
   wm_eta_toterr__64->SetMinimum(0.001);
   wm_eta_toterr__64->SetMaximum(36);
   wm_eta_toterr__64->SetEntries(9);
   wm_eta_toterr__64->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wm_eta_toterr__64->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wm_eta_toterr__64->SetLineColor(ci);
   wm_eta_toterr__64->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wm_eta_toterr__64->SetMarkerColor(ci);
   wm_eta_toterr__64->SetMarkerStyle(0);
   wm_eta_toterr__64->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wm_eta_toterr__64->GetXaxis()->SetNdivisions(4);
   wm_eta_toterr__64->GetXaxis()->SetLabelFont(132);
   wm_eta_toterr__64->GetXaxis()->SetLabelOffset(0.02);
   wm_eta_toterr__64->GetXaxis()->SetLabelSize(0.05);
   wm_eta_toterr__64->GetXaxis()->SetTitleSize(0.06);
   wm_eta_toterr__64->GetXaxis()->SetTitleFont(132);
   wm_eta_toterr__64->GetYaxis()->SetTitle("#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_toterr__64->GetYaxis()->SetLabelFont(132);
   wm_eta_toterr__64->GetYaxis()->SetLabelSize(0.05);
   wm_eta_toterr__64->GetYaxis()->SetTitleSize(0.06);
   wm_eta_toterr__64->GetYaxis()->SetTitleFont(132);
   wm_eta_toterr__64->GetZaxis()->SetLabelFont(132);
   wm_eta_toterr__64->GetZaxis()->SetLabelSize(0.05);
   wm_eta_toterr__64->GetZaxis()->SetTitleSize(0.06);
   wm_eta_toterr__64->GetZaxis()->SetTitleFont(132);
   wm_eta_toterr__64->Draw("e2");
   Double_t xAxis53[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_staterr__65 = new TH1F("wm_eta_staterr__65","wm_eta",4, xAxis53);
   wm_eta_staterr__65->SetBinContent(1,20.31135);
   wm_eta_staterr__65->SetBinContent(2,19.05704);
   wm_eta_staterr__65->SetBinContent(3,14.77047);
   wm_eta_staterr__65->SetBinContent(4,6.28784);
   wm_eta_staterr__65->SetBinContent(5,6.28784);
   wm_eta_staterr__65->SetBinError(1,0.2067664);
   wm_eta_staterr__65->SetBinError(2,0.1786075);
   wm_eta_staterr__65->SetBinError(3,0.1537429);
   wm_eta_staterr__65->SetBinError(4,0.0794311);
   wm_eta_staterr__65->SetBinError(5,0.0794311);
   wm_eta_staterr__65->SetMinimum(0.001);
   wm_eta_staterr__65->SetMaximum(36);
   wm_eta_staterr__65->SetEntries(9);
   wm_eta_staterr__65->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wm_eta_staterr__65->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wm_eta_staterr__65->SetLineColor(ci);
   wm_eta_staterr__65->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wm_eta_staterr__65->SetMarkerColor(ci);
   wm_eta_staterr__65->SetMarkerStyle(0);
   wm_eta_staterr__65->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wm_eta_staterr__65->GetXaxis()->SetNdivisions(4);
   wm_eta_staterr__65->GetXaxis()->SetLabelFont(132);
   wm_eta_staterr__65->GetXaxis()->SetLabelOffset(0.02);
   wm_eta_staterr__65->GetXaxis()->SetLabelSize(0.05);
   wm_eta_staterr__65->GetXaxis()->SetTitleSize(0.06);
   wm_eta_staterr__65->GetXaxis()->SetTitleFont(132);
   wm_eta_staterr__65->GetYaxis()->SetTitle("#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_staterr__65->GetYaxis()->SetLabelFont(132);
   wm_eta_staterr__65->GetYaxis()->SetLabelSize(0.05);
   wm_eta_staterr__65->GetYaxis()->SetTitleSize(0.06);
   wm_eta_staterr__65->GetYaxis()->SetTitleFont(132);
   wm_eta_staterr__65->GetZaxis()->SetLabelFont(132);
   wm_eta_staterr__65->GetZaxis()->SetLabelSize(0.05);
   wm_eta_staterr__65->GetZaxis()->SetTitleSize(0.06);
   wm_eta_staterr__65->GetZaxis()->SetTitleFont(132);
   wm_eta_staterr__65->Draw("e2same");
   
   Double_t eta_minus_toterrs_fx3077[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t eta_minus_toterrs_fy3077[4] = {
   24.69105,
   21.53431,
   16.77246,
   6.521709};
   Double_t eta_minus_toterrs_felx3077[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fely3077[4] = {
   2.650178,
   1.505858,
   2.136883,
   0.7587894};
   Double_t eta_minus_toterrs_fehx3077[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fehy3077[4] = {
   1.770777,
   1.514672,
   1.574916,
   0.7803406};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,eta_minus_toterrs_fx3077,eta_minus_toterrs_fy3077,eta_minus_toterrs_felx3077,eta_minus_toterrs_fehx3077,eta_minus_toterrs_fely3077,eta_minus_toterrs_fehy3077);
   grae->SetName("eta_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_eta_minus_toterrs3077 = new TH1F("Graph_eta_minus_toterrs3077","",100,2.1325,4.4425);
   Graph_eta_minus_toterrs3077->SetMinimum(0.001);
   Graph_eta_minus_toterrs3077->SetMaximum(36);
   Graph_eta_minus_toterrs3077->SetDirectory(0);
   Graph_eta_minus_toterrs3077->SetStats(0);
   Graph_eta_minus_toterrs3077->SetLineWidth(2);
   Graph_eta_minus_toterrs3077->SetMarkerStyle(0);
   Graph_eta_minus_toterrs3077->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_eta_minus_toterrs3077->GetXaxis()->SetNdivisions(4);
   Graph_eta_minus_toterrs3077->GetXaxis()->SetLabelFont(132);
   Graph_eta_minus_toterrs3077->GetXaxis()->SetLabelOffset(0.02);
   Graph_eta_minus_toterrs3077->GetXaxis()->SetLabelSize(0.05);
   Graph_eta_minus_toterrs3077->GetXaxis()->SetTitleSize(0.06);
   Graph_eta_minus_toterrs3077->GetXaxis()->SetTitleFont(132);
   Graph_eta_minus_toterrs3077->GetYaxis()->SetTitle("#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_eta_minus_toterrs3077->GetYaxis()->SetLabelFont(132);
   Graph_eta_minus_toterrs3077->GetYaxis()->SetLabelSize(0.05);
   Graph_eta_minus_toterrs3077->GetYaxis()->SetTitleSize(0.06);
   Graph_eta_minus_toterrs3077->GetYaxis()->SetTitleFont(132);
   Graph_eta_minus_toterrs3077->GetZaxis()->SetLabelFont(132);
   Graph_eta_minus_toterrs3077->GetZaxis()->SetLabelSize(0.05);
   Graph_eta_minus_toterrs3077->GetZaxis()->SetTitleSize(0.06);
   Graph_eta_minus_toterrs3077->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_eta_minus_toterrs3077);
   
   grae->Draw("p1p");
   
   Double_t _fx3078[4] = {
   2.325,
   2.825,
   3.325,
   4.25};
   Double_t _fy3078[4] = {
   24.69105,
   21.53431,
   16.77246,
   6.521709};
   Double_t _felx3078[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3078[4] = {
   1.403467,
   1.102299,
   0.935895,
   0.3957744};
   Double_t _fehx3078[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3078[4] = {
   1.399612,
   1.006586,
   1.048164,
   0.4442883};
   grae = new TGraphAsymmErrors(4,_fx3078,_fy3078,_felx3078,_fehx3078,_fely3078,_fehy3078);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph3078 = new TH1F("Graph_Graph3078","",100,2.1325,4.4425);
   Graph_Graph3078->SetMinimum(0.001);
   Graph_Graph3078->SetMaximum(36);
   Graph_Graph3078->SetDirectory(0);
   Graph_Graph3078->SetStats(0);
   Graph_Graph3078->SetLineWidth(2);
   Graph_Graph3078->SetMarkerStyle(0);
   Graph_Graph3078->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_Graph3078->GetXaxis()->SetNdivisions(4);
   Graph_Graph3078->GetXaxis()->SetLabelFont(132);
   Graph_Graph3078->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3078->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3078->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3078->GetXaxis()->SetTitleFont(132);
   Graph_Graph3078->GetYaxis()->SetTitle("#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph3078->GetYaxis()->SetLabelFont(132);
   Graph_Graph3078->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3078->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3078->GetYaxis()->SetTitleFont(132);
   Graph_Graph3078->GetZaxis()->SetLabelFont(132);
   Graph_Graph3078->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3078->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3078->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3078);
   
   grae->Draw("p1p");
   
   Double_t eta_minus_toterrs_fx3079[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t eta_minus_toterrs_fy3079[4] = {
   24.34978,
   21.59002,
   16.53536,
   6.707781};
   Double_t eta_minus_toterrs_felx3079[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fely3079[4] = {
   1.887475,
   1.685778,
   1.408083,
   0.7344018};
   Double_t eta_minus_toterrs_fehx3079[4] = {
   0,
   0,
   0,
   0};
   Double_t eta_minus_toterrs_fehy3079[4] = {
   1.946961,
   1.776958,
   1.529902,
   0.7848048};
   grae = new TGraphAsymmErrors(4,eta_minus_toterrs_fx3079,eta_minus_toterrs_fy3079,eta_minus_toterrs_felx3079,eta_minus_toterrs_fehx3079,eta_minus_toterrs_fely3079,eta_minus_toterrs_fehy3079);
   grae->SetName("eta_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_eta_minus_toterrs3079 = new TH1F("Graph_eta_minus_toterrs3079","",100,1.98,4.32);
   Graph_eta_minus_toterrs3079->SetMinimum(0.001);
   Graph_eta_minus_toterrs3079->SetMaximum(36);
   Graph_eta_minus_toterrs3079->SetDirectory(0);
   Graph_eta_minus_toterrs3079->SetStats(0);
   Graph_eta_minus_toterrs3079->SetLineWidth(2);
   Graph_eta_minus_toterrs3079->SetMarkerStyle(0);
   Graph_eta_minus_toterrs3079->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_eta_minus_toterrs3079->GetXaxis()->SetNdivisions(4);
   Graph_eta_minus_toterrs3079->GetXaxis()->SetLabelFont(132);
   Graph_eta_minus_toterrs3079->GetXaxis()->SetLabelOffset(0.02);
   Graph_eta_minus_toterrs3079->GetXaxis()->SetLabelSize(0.05);
   Graph_eta_minus_toterrs3079->GetXaxis()->SetTitleSize(0.06);
   Graph_eta_minus_toterrs3079->GetXaxis()->SetTitleFont(132);
   Graph_eta_minus_toterrs3079->GetYaxis()->SetTitle("#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_eta_minus_toterrs3079->GetYaxis()->SetLabelFont(132);
   Graph_eta_minus_toterrs3079->GetYaxis()->SetLabelSize(0.05);
   Graph_eta_minus_toterrs3079->GetYaxis()->SetTitleSize(0.06);
   Graph_eta_minus_toterrs3079->GetYaxis()->SetTitleFont(132);
   Graph_eta_minus_toterrs3079->GetZaxis()->SetLabelFont(132);
   Graph_eta_minus_toterrs3079->GetZaxis()->SetLabelSize(0.05);
   Graph_eta_minus_toterrs3079->GetZaxis()->SetTitleSize(0.06);
   Graph_eta_minus_toterrs3079->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_eta_minus_toterrs3079);
   
   grae->Draw("p1p");
   
   Double_t _fx3080[4] = {
   2.175,
   2.675,
   3.175,
   4.125};
   Double_t _fy3080[4] = {
   24.34978,
   21.59002,
   16.53536,
   6.707781};
   Double_t _felx3080[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3080[4] = {
   1.482811,
   1.286926,
   0.9989262,
   0.430294};
   Double_t _fehx3080[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3080[4] = {
   1.576153,
   1.363707,
   1.084366,
   0.4796934};
   grae = new TGraphAsymmErrors(4,_fx3080,_fy3080,_felx3080,_fehx3080,_fely3080,_fehy3080);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph3080 = new TH1F("Graph_Graph3080","",100,1.98,4.32);
   Graph_Graph3080->SetMinimum(0.001);
   Graph_Graph3080->SetMaximum(36);
   Graph_Graph3080->SetDirectory(0);
   Graph_Graph3080->SetStats(0);
   Graph_Graph3080->SetLineWidth(2);
   Graph_Graph3080->SetMarkerStyle(0);
   Graph_Graph3080->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_Graph3080->GetXaxis()->SetNdivisions(4);
   Graph_Graph3080->GetXaxis()->SetLabelFont(132);
   Graph_Graph3080->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3080->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3080->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3080->GetXaxis()->SetTitleFont(132);
   Graph_Graph3080->GetYaxis()->SetTitle("#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   Graph_Graph3080->GetYaxis()->SetLabelFont(132);
   Graph_Graph3080->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3080->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3080->GetYaxis()->SetTitleFont(132);
   Graph_Graph3080->GetZaxis()->SetLabelFont(132);
   Graph_Graph3080->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3080->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3080->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3080);
   
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
   Double_t xAxis54[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wm_eta_toterr_copy__66 = new TH1F("wm_eta_toterr_copy__66","wm_eta",4, xAxis54);
   wm_eta_toterr_copy__66->SetBinContent(1,20.31135);
   wm_eta_toterr_copy__66->SetBinContent(2,19.05704);
   wm_eta_toterr_copy__66->SetBinContent(3,14.77047);
   wm_eta_toterr_copy__66->SetBinContent(4,6.28784);
   wm_eta_toterr_copy__66->SetBinContent(5,6.28784);
   wm_eta_toterr_copy__66->SetBinError(1,2.211244);
   wm_eta_toterr_copy__66->SetBinError(2,2.174277);
   wm_eta_toterr_copy__66->SetBinError(3,1.504852);
   wm_eta_toterr_copy__66->SetBinError(4,0.7324271);
   wm_eta_toterr_copy__66->SetBinError(5,0.7324271);
   wm_eta_toterr_copy__66->SetMinimum(0.001);
   wm_eta_toterr_copy__66->SetMaximum(36);
   wm_eta_toterr_copy__66->SetEntries(9);
   wm_eta_toterr_copy__66->SetDirectory(0);
   wm_eta_toterr_copy__66->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wm_eta_toterr_copy__66->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wm_eta_toterr_copy__66->SetLineColor(ci);
   wm_eta_toterr_copy__66->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wm_eta_toterr_copy__66->SetMarkerColor(ci);
   wm_eta_toterr_copy__66->SetMarkerStyle(0);
   wm_eta_toterr_copy__66->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wm_eta_toterr_copy__66->GetXaxis()->SetNdivisions(4);
   wm_eta_toterr_copy__66->GetXaxis()->SetLabelFont(132);
   wm_eta_toterr_copy__66->GetXaxis()->SetLabelOffset(0.02);
   wm_eta_toterr_copy__66->GetXaxis()->SetLabelSize(0.05);
   wm_eta_toterr_copy__66->GetXaxis()->SetTitleSize(0.06);
   wm_eta_toterr_copy__66->GetXaxis()->SetTitleFont(132);
   wm_eta_toterr_copy__66->GetYaxis()->SetTitle("#sigma(#it{Wj})/d#it{#eta^{#mu}} [pb]");
   wm_eta_toterr_copy__66->GetYaxis()->SetLabelFont(132);
   wm_eta_toterr_copy__66->GetYaxis()->SetLabelSize(0.05);
   wm_eta_toterr_copy__66->GetYaxis()->SetTitleSize(0.06);
   wm_eta_toterr_copy__66->GetYaxis()->SetTitleFont(132);
   wm_eta_toterr_copy__66->GetZaxis()->SetLabelFont(132);
   wm_eta_toterr_copy__66->GetZaxis()->SetLabelSize(0.05);
   wm_eta_toterr_copy__66->GetZaxis()->SetTitleSize(0.06);
   wm_eta_toterr_copy__66->GetZaxis()->SetTitleFont(132);
   wm_eta_toterr_copy__66->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
