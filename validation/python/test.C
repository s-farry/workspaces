void test()
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
   upperPad->Range(1.231481,0.7056261,4.935185,1.004763);
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
   
   Double_t Graph0_fx3001[10] = {
   2.125,
   2.375,
   2.625,
   2.875,
   3.125,
   3.375,
   3.625,
   3.875,
   4.125,
   4.375};
   Double_t Graph0_fy3001[10] = {
   0.7745598,
   0.863698,
   0.9066791,
   0.9186175,
   0.9233212,
   0.9525989,
   0.9673797,
   0.9533916,
   0.941386,
   0.9424504};
   Double_t Graph0_felx3001[10] = {
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125};
   Double_t Graph0_fely3001[10] = {
   0.006862663,
   0.00502323,
   0.003437488,
   0.003171856,
   0.003002845,
   0.0023184,
   0.002235022,
   0.002872821,
   0.003467893,
   0.004546227};
   Double_t Graph0_fehx3001[10] = {
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125};
   Double_t Graph0_fehy3001[10] = {
   0.006862663,
   0.00502323,
   0.003437488,
   0.003171856,
   0.003002845,
   0.0023184,
   0.002235022,
   0.002872821,
   0.003467893,
   0.004546227};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(10,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,1.75,4.75);
   Graph_Graph3001->SetMinimum(0.7475053);
   Graph_Graph3001->SetMaximum(0.9898065);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);
   Graph_Graph3001->SetLineWidth(2);
   Graph_Graph3001->SetMarkerStyle(0);
   Graph_Graph3001->GetXaxis()->SetTitle("#eta");
   Graph_Graph3001->GetXaxis()->SetNdivisions(1005);
   Graph_Graph3001->GetXaxis()->SetLabelFont(132);
   Graph_Graph3001->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3001->GetXaxis()->SetTitleFont(132);
   Graph_Graph3001->GetYaxis()->SetTitle("Tracking Efficiency");
   Graph_Graph3001->GetYaxis()->SetLabelFont(132);
   Graph_Graph3001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3001->GetYaxis()->SetTitleFont(132);
   Graph_Graph3001->GetZaxis()->SetLabelFont(132);
   Graph_Graph3001->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3001->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3001);
   
   grae->Draw("pa");
   
   Double_t Graph1_fx3002[10] = {
   2.125,
   2.375,
   2.625,
   2.875,
   3.125,
   3.375,
   3.625,
   3.875,
   4.125,
   4.375};
   Double_t Graph1_fy3002[10] = {
   0.7537911,
   0.8630445,
   0.9009785,
   0.913797,
   0.9131923,
   0.9467558,
   0.965363,
   0.9478888,
   0.9271573,
   0.9217059};
   Double_t Graph1_felx3002[10] = {
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125};
   Double_t Graph1_fely3002[10] = {
   0.009876175,
   0.006730544,
   0.005168973,
   0.004995239,
   0.005234831,
   0.003940596,
   0.003836555,
   0.00456215,
   0.006371899,
   0.00823017};
   Double_t Graph1_fehx3002[10] = {
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125};
   Double_t Graph1_fehy3002[10] = {
   0.009818302,
   0.006652095,
   0.005112184,
   0.004935478,
   0.005179049,
   0.003874098,
   0.003729825,
   0.004444406,
   0.006245408,
   0.008023812};
   grae = new TGraphAsymmErrors(10,Graph1_fx3002,Graph1_fy3002,Graph1_felx3002,Graph1_fehx3002,Graph1_fely3002,Graph1_fehy3002);
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
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,1.75,4.75);
   Graph_Graph3002->SetMinimum(0.7213971);
   Graph_Graph3002->SetMaximum(0.9916106);
   Graph_Graph3002->SetDirectory(0);
   Graph_Graph3002->SetStats(0);
   Graph_Graph3002->SetLineWidth(2);
   Graph_Graph3002->SetMarkerStyle(0);
   Graph_Graph3002->GetXaxis()->SetTitle("#eta");
   Graph_Graph3002->GetXaxis()->SetNdivisions(1005);
   Graph_Graph3002->GetXaxis()->SetLabelFont(132);
   Graph_Graph3002->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3002->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3002->GetXaxis()->SetTitleFont(132);
   Graph_Graph3002->GetYaxis()->SetTitle("Tracking Efficiency");
   Graph_Graph3002->GetYaxis()->SetLabelFont(132);
   Graph_Graph3002->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3002->GetYaxis()->SetTitleFont(132);
   Graph_Graph3002->GetZaxis()->SetLabelFont(132);
   Graph_Graph3002->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3002->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3002);
   
   grae->Draw("p");
   
   Double_t Graph2_fx3003[10] = {
   2.125,
   2.375,
   2.625,
   2.875,
   3.125,
   3.375,
   3.625,
   3.875,
   4.125,
   4.375};
   Double_t Graph2_fy3003[10] = {
   0.7792114,
   0.8741628,
   0.9095512,
   0.9201751,
   0.9267055,
   0.9505894,
   0.9584144,
   0.9525248,
   0.9343284,
   0.9271957};
   Double_t Graph2_felx3003[10] = {
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125};
   Double_t Graph2_fely3003[10] = {
   0.002580959,
   0.002055752,
   0.001770975,
   0.001707375,
   0.001684362,
   0.001471016,
   0.001439401,
   0.001676954,
   0.002155299,
   0.002580451};
   Double_t Graph2_fehx3003[10] = {
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125,
   0.125};
   Double_t Graph2_fehy3003[10] = {
   0.002559673,
   0.002027653,
   0.001740603,
   0.001675022,
   0.001649861,
   0.001431223,
   0.00139403,
   0.001623421,
   0.002092513,
   0.002500261};
   grae = new TGraphAsymmErrors(10,Graph2_fx3003,Graph2_fy3003,Graph2_felx3003,Graph2_fehx3003,Graph2_fely3003,Graph2_fehy3003);
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
   
   TH1F *Graph_Graph3003 = new TH1F("Graph_Graph3003","Graph",100,1.75,4.75);
   Graph_Graph3003->SetMinimum(0.7583127);
   Graph_Graph3003->SetMaximum(0.9781262);
   Graph_Graph3003->SetDirectory(0);
   Graph_Graph3003->SetStats(0);
   Graph_Graph3003->SetLineWidth(2);
   Graph_Graph3003->SetMarkerStyle(0);
   Graph_Graph3003->GetXaxis()->SetTitle("#eta");
   Graph_Graph3003->GetXaxis()->SetNdivisions(1005);
   Graph_Graph3003->GetXaxis()->SetLabelFont(132);
   Graph_Graph3003->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3003->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3003->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3003->GetXaxis()->SetTitleFont(132);
   Graph_Graph3003->GetYaxis()->SetTitle("Tracking Efficiency");
   Graph_Graph3003->GetYaxis()->SetLabelFont(132);
   Graph_Graph3003->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3003->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3003->GetYaxis()->SetTitleFont(132);
   Graph_Graph3003->GetZaxis()->SetLabelFont(132);
   Graph_Graph3003->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3003->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3003->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3003);
   
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
   
   TH1F *Graph_copy = new TH1F("Graph_copy","Graph",100,1.75,4.75);
   Graph_copy->SetMinimum(0.7475053);
   Graph_copy->SetMaximum(0.9898065);
   Graph_copy->SetDirectory(0);
   Graph_copy->SetStats(0);
   Graph_copy->SetLineWidth(2);
   Graph_copy->SetMarkerStyle(0);
   Graph_copy->GetXaxis()->SetTitle("#eta");
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
