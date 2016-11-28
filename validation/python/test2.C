void test2()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Fri May  6 10:50:13 2016) by ROOT version6.04/10
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
   upperPad->Range(4.62963,0.7654321,78.7037,1.012346);
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
   
   Double_t Graph0_fx3004[10] = {
   22.5,
   27.5,
   32.5,
   37.5,
   42.5,
   47.5,
   52.5,
   57.5,
   62.5,
   67.5};
   Double_t Graph0_fy3004[10] = {
   0.8813038,
   0.8945409,
   0.9123641,
   0.9128106,
   0.9113571,
   0.9162492,
   0.9116245,
   0.9170141,
   0.9229201,
   0.9192416};
   Double_t Graph0_felx3004[10] = {
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5};
   Double_t Graph0_fely3004[10] = {
   0.007378957,
   0.004505258,
   0.003235574,
   0.002926801,
   0.003141413,
   0.003530482,
   0.004479803,
   0.005566622,
   0.006897556,
   0.009295911};
   Double_t Graph0_fehx3004[10] = {
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5};
   Double_t Graph0_fehy3004[10] = {
   0.007378957,
   0.004505258,
   0.003235574,
   0.002926801,
   0.003141413,
   0.003530482,
   0.004479803,
   0.005566622,
   0.006897556,
   0.009295911};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3004,Graph0_fy3004,Graph0_felx3004,Graph0_fehx3004,Graph0_fely3004,Graph0_fehy3004);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#ff0000");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3004 = new TH1F("Graph_Graph3004","Graph",100,15,75);
   Graph_Graph3004->SetMinimum(0.8);
   Graph_Graph3004->SetMaximum(1);
   Graph_Graph3004->SetDirectory(0);
   Graph_Graph3004->SetStats(0);
   Graph_Graph3004->SetLineWidth(2);
   Graph_Graph3004->SetMarkerStyle(0);
   Graph_Graph3004->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Graph3004->GetXaxis()->SetNdivisions(1005);
   Graph_Graph3004->GetXaxis()->SetLabelFont(132);
   Graph_Graph3004->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3004->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3004->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3004->GetXaxis()->SetTitleFont(132);
   Graph_Graph3004->GetYaxis()->SetTitle("Tracking Efficiency");
   Graph_Graph3004->GetYaxis()->SetLabelFont(132);
   Graph_Graph3004->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3004->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3004->GetYaxis()->SetTitleFont(132);
   Graph_Graph3004->GetZaxis()->SetLabelFont(132);
   Graph_Graph3004->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3004->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3004->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3004);
   
   grae->Draw("pa");
   
   Double_t Graph1_fx3005[10] = {
   22.5,
   27.5,
   32.5,
   37.5,
   42.5,
   47.5,
   52.5,
   57.5,
   62.5,
   67.5};
   Double_t Graph1_fy3005[10] = {
   0.8610889,
   0.8875603,
   0.9014548,
   0.9028733,
   0.9014864,
   0.9062255,
   0.9007675,
   0.907357,
   0.9125277,
   0.9154631};
   Double_t Graph1_felx3005[10] = {
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5};
   Double_t Graph1_fely3005[10] = {
   0.01313475,
   0.00760897,
   0.006010321,
   0.005028112,
   0.004752034,
   0.005300814,
   0.006927118,
   0.008972102,
   0.01169933,
   0.01561315};
   Double_t Graph1_fehx3005[10] = {
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5};
   Double_t Graph1_fehy3005[10] = {
   0.01261313,
   0.007442292,
   0.00594588,
   0.004996115,
   0.004733766,
   0.005270285,
   0.006816408,
   0.008670298,
   0.01105283,
   0.01431366};
   grae = new TGraphAsymmErrors(10,Graph1_fx3005,Graph1_fy3005,Graph1_felx3005,Graph1_fehx3005,Graph1_fely3005,Graph1_fehy3005);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#0000ff");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3005 = new TH1F("Graph_Graph3005","Graph",100,15,75);
   Graph_Graph3005->SetMinimum(0.8);
   Graph_Graph3005->SetMaximum(1);
   Graph_Graph3005->SetDirectory(0);
   Graph_Graph3005->SetStats(0);
   Graph_Graph3005->SetLineWidth(2);
   Graph_Graph3005->SetMarkerStyle(0);
   Graph_Graph3005->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Graph3005->GetXaxis()->SetNdivisions(1005);
   Graph_Graph3005->GetXaxis()->SetLabelFont(132);
   Graph_Graph3005->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3005->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3005->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3005->GetXaxis()->SetTitleFont(132);
   Graph_Graph3005->GetYaxis()->SetTitle("Tracking Efficiency");
   Graph_Graph3005->GetYaxis()->SetLabelFont(132);
   Graph_Graph3005->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3005->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3005->GetYaxis()->SetTitleFont(132);
   Graph_Graph3005->GetZaxis()->SetLabelFont(132);
   Graph_Graph3005->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3005->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3005->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3005);
   
   grae->Draw("p");
   
   Double_t Graph2_fx3006[10] = {
   22.5,
   27.5,
   32.5,
   37.5,
   42.5,
   47.5,
   52.5,
   57.5,
   62.5,
   67.5};
   Double_t Graph2_fy3006[10] = {
   0.8721502,
   0.8888249,
   0.8999757,
   0.9072017,
   0.9117642,
   0.9137187,
   0.9145825,
   0.9124374,
   0.9014293,
   0.904801};
   Double_t Graph2_felx3006[10] = {
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5};
   Double_t Graph2_fely3006[10] = {
   0.005188933,
   0.002924087,
   0.001944712,
   0.001450858,
   0.001177386,
   0.001413224,
   0.002297298,
   0.003412989,
   0.004904148,
   0.00632239};
   Double_t Graph2_fehx3006[10] = {
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5,
   2.5};
   Double_t Graph2_fehy3006[10] = {
   0.005018869,
   0.002859221,
   0.001912014,
   0.001430942,
   0.001163464,
   0.001392746,
   0.002243366,
   0.003299064,
   0.004701119,
   0.005978788};
   grae = new TGraphAsymmErrors(10,Graph2_fx3006,Graph2_fy3006,Graph2_felx3006,Graph2_fehx3006,Graph2_fely3006,Graph2_fehy3006);
   grae->SetName("Graph2");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);

   ci = TColor::GetColor("#00ff00");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3006 = new TH1F("Graph_Graph3006","Graph",100,15,75);
   Graph_Graph3006->SetMinimum(0.8);
   Graph_Graph3006->SetMaximum(1);
   Graph_Graph3006->SetDirectory(0);
   Graph_Graph3006->SetStats(0);
   Graph_Graph3006->SetLineWidth(2);
   Graph_Graph3006->SetMarkerStyle(0);
   Graph_Graph3006->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_Graph3006->GetXaxis()->SetNdivisions(1005);
   Graph_Graph3006->GetXaxis()->SetLabelFont(132);
   Graph_Graph3006->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3006->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3006->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3006->GetXaxis()->SetTitleFont(132);
   Graph_Graph3006->GetYaxis()->SetTitle("Tracking Efficiency");
   Graph_Graph3006->GetYaxis()->SetLabelFont(132);
   Graph_Graph3006->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3006->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3006->GetYaxis()->SetTitleFont(132);
   Graph_Graph3006->GetZaxis()->SetLabelFont(132);
   Graph_Graph3006->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3006->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3006->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3006);
   
   grae->Draw("p");
   
   TLegend *leg = new TLegend(0.2,0.7,0.4,0.85,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(10);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph0","T&P","lep");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph1","T&P(corr.)","lep");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("Graph2","Truth","lep");

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.4,0.2,0.7,0.4,"brNDC");
   pt->SetLineWidth(2);
   pt->SetTextFont(132);
   TText *AText = pt->AddText("Total Eff (T&P)      = 0.910");
   AText = pt->AddText("Total Eff (T&P Corr) = 0.900");
   AText = pt->AddText("Total Eff (Truth)    = 0.907");
   pt->Draw();
   
   TH1F *Graph_copy = new TH1F("Graph_copy","Graph",100,15,75);
   Graph_copy->SetMinimum(0.8);
   Graph_copy->SetMaximum(1);
   Graph_copy->SetDirectory(0);
   Graph_copy->SetStats(0);
   Graph_copy->SetLineWidth(2);
   Graph_copy->SetMarkerStyle(0);
   Graph_copy->GetXaxis()->SetTitle("p_{T} [GeV]");
   Graph_copy->GetXaxis()->SetNdivisions(1005);
   Graph_copy->GetXaxis()->SetLabelFont(132);
   Graph_copy->GetXaxis()->SetLabelOffset(0.02);
   Graph_copy->GetXaxis()->SetLabelSize(0.05);
   Graph_copy->GetXaxis()->SetTitleSize(0.06);
   Graph_copy->GetXaxis()->SetTitleFont(132);
   Graph_copy->GetYaxis()->SetTitle("Tracking Efficiency");
   Graph_copy->GetYaxis()->SetLabelFont(132);
   Graph_copy->GetYaxis()->SetLabelSize(0.05);
   Graph_copy->GetYaxis()->SetTitleSize(0.06);
   Graph_copy->GetYaxis()->SetTitleFont(132);
   Graph_copy->GetZaxis()->SetLabelFont(132);
   Graph_copy->GetZaxis()->SetLabelSize(0.05);
   Graph_copy->GetZaxis()->SetTitleSize(0.06);
   Graph_copy->GetZaxis()->SetTitleFont(132);
   Graph_copy->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
