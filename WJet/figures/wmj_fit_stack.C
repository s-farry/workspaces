void wmj_fit_stack()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Tue May  3 07:35:30 2016) by ROOT version6.04/10
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
   upperPad->Range(-0.1730123,-5358.989,1.06279,32919.5);
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
   
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3005[20] = {
   0.025,
   0.075,
   0.125,
   0.175,
   0.225,
   0.275,
   0.325,
   0.375,
   0.425,
   0.475,
   0.525,
   0.575,
   0.625,
   0.675,
   0.725,
   0.775,
   0.825,
   0.875,
   0.925,
   0.975};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3005[20] = {
   0,
   0,
   9,
   26,
   118,
   315,
   881,
   1812,
   3086,
   4575,
   5856,
   6537,
   6824,
   6348,
   5662,
   4769,
   4941,
   6726,
   13179,
   28019};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3005[20] = {
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3005[20] = {
   0,
   0,
   2.943461,
   5.066015,
   10.37428,
   17.25528,
   29.18586,
   42.07053,
   55.05403,
   67.14059,
   76.02614,
   80.35326,
   82.10902,
   79.17591,
   74.74792,
   68.55976,
   69.79403,
   81.51372,
   114.3009,
   166.8895};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3005[20] = {
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3005[20] = {
   1.147874,
   1.147874,
   4.110204,
   6.164324,
   11.37428,
   18.25528,
   30.18586,
   43.07053,
   56.05403,
   68.14059,
   77.02614,
   81.35326,
   83.10902,
   80.17591,
   75.74792,
   69.55976,
   70.79403,
   82.51372,
   115.3009,
   167.8895};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3005,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3005,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3005,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3005,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3005,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3005);
   grae->SetName("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]");
   grae->SetTitle("Histogram of combData_plot__muminus_ISO_");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005 = new TH1F("Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->SetMinimum(0);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->SetMaximum(31005.58);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300130023005);
   
   grae->Draw("e1pa");
   
   Double_t h5_fx7[47] = {
   -0.02439024,
   -0.02439024,
   0,
   1.0201e-08,
   0.04999999,
   0.05000001,
   0.09999999,
   0.1,
   0.15,
   0.15,
   0.2,
   0.2,
   0.25,
   0.25,
   0.3,
   0.3,
   0.35,
   0.35,
   0.4,
   0.4,
   0.45,
   0.45,
   0.5,
   0.5,
   0.55,
   0.55,
   0.6,
   0.6,
   0.65,
   0.65,
   0.7,
   0.7,
   0.75,
   0.75,
   0.8,
   0.8,
   0.85,
   0.85,
   0.9,
   0.9,
   0.95,
   0.95,
   1,
   1,
   1,
   1.02439,
   1.02439};
   Double_t h5_fy7[47] = {
   0,
   0,
   0,
   8.630173e-06,
   8.630173e-06,
   8.630173e-06,
   8.630173e-06,
   8.630173e-06,
   8.630173e-06,
   3.789762,
   3.789762,
   71.12063,
   71.12063,
   211.4394,
   211.4394,
   857.7007,
   857.7007,
   1798.534,
   1798.534,
   3099.609,
   3099.609,
   4425.901,
   4425.901,
   5601.584,
   5601.584,
   6533.687,
   6533.687,
   6910.208,
   6910.208,
   6392.171,
   6392.171,
   5777.193,
   5777.193,
   5020.919,
   5020.919,
   5207.834,
   5207.834,
   6798.159,
   6798.159,
   13033.98,
   13033.98,
   27939.27,
   27939.27,
   0,
   0,
   0,
   0};
   TGraph *graph = new TGraph(47,h5_fx7,h5_fy7);
   graph->SetName("h5");
   graph->SetTitle("Projection of ");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#3333ff");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#3333ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);

   ci = TColor::GetColor("#3333ff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(0);
   
   TH1F *Graph_h57 = new TH1F("Graph_h57","Projection of ",100,-0.1292683,1.129268);
   Graph_h57->SetMinimum(0);
   Graph_h57->SetMaximum(30733.2);
   Graph_h57->SetDirectory(0);
   Graph_h57->SetStats(0);
   Graph_h57->SetLineWidth(2);
   Graph_h57->SetMarkerStyle(0);
   Graph_h57->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_h57->GetXaxis()->SetRange(11,90);
   Graph_h57->GetXaxis()->SetNdivisions(1005);
   Graph_h57->GetXaxis()->SetLabelFont(132);
   Graph_h57->GetXaxis()->SetLabelOffset(0.02);
   Graph_h57->GetXaxis()->SetLabelSize(0.05);
   Graph_h57->GetXaxis()->SetTitleSize(0.06);
   Graph_h57->GetXaxis()->SetTitleFont(132);
   Graph_h57->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_h57->GetYaxis()->SetLabelFont(132);
   Graph_h57->GetYaxis()->SetLabelSize(0.05);
   Graph_h57->GetYaxis()->SetTitleSize(0.06);
   Graph_h57->GetYaxis()->SetTitleFont(132);
   Graph_h57->GetZaxis()->SetLabelFont(132);
   Graph_h57->GetZaxis()->SetLabelSize(0.05);
   Graph_h57->GetZaxis()->SetTitleSize(0.06);
   Graph_h57->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_h57);
   
   graph->Draw("f");
   
   Double_t sumBkgPdf_totbkg_fitW_fx8[47] = {
   -0.02439024,
   -0.02439024,
   0,
   1.0201e-08,
   0.04999999,
   0.05000001,
   0.09999999,
   0.1,
   0.15,
   0.15,
   0.2,
   0.2,
   0.25,
   0.25,
   0.3,
   0.3,
   0.35,
   0.35,
   0.4,
   0.4,
   0.45,
   0.45,
   0.5,
   0.5,
   0.55,
   0.55,
   0.6,
   0.6,
   0.65,
   0.65,
   0.7,
   0.7,
   0.75,
   0.75,
   0.8,
   0.8,
   0.85,
   0.85,
   0.9,
   0.9,
   0.95,
   0.95,
   1,
   1,
   1,
   1.02439,
   1.02439};
   Double_t sumBkgPdf_totbkg_fitW_fy8[47] = {
   0,
   0,
   0,
   2.878569e-06,
   2.878569e-06,
   2.878569e-06,
   2.878569e-06,
   2.878569e-06,
   2.878569e-06,
   3.789757,
   3.789757,
   71.12063,
   71.12063,
   211.4394,
   211.4394,
   855.0132,
   855.0132,
   1794.513,
   1794.513,
   3088.88,
   3088.88,
   4399.772,
   4399.772,
   5568.272,
   5568.272,
   6460.972,
   6460.972,
   6790.725,
   6790.725,
   6142.168,
   6142.168,
   5333.208,
   5333.208,
   4062.953,
   4062.953,
   3103.771,
   3103.771,
   2394.858,
   2394.858,
   1734.507,
   1734.507,
   1650.883,
   1650.883,
   0,
   0,
   0,
   0};
   graph = new TGraph(47,sumBkgPdf_totbkg_fitW_fx8,sumBkgPdf_totbkg_fitW_fy8);
   graph->SetName("sumBkgPdf_totbkg_fitW");
   graph->SetTitle("Projection of ");

   ci = TColor::GetColor("#ffff66");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#ffff66");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);

   ci = TColor::GetColor("#ffff66");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(0);
   
   TH1F *Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618 = new TH1F("Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->SetMinimum(0);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->SetMaximum(7469.797);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->SetDirectory(0);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->SetStats(0);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->SetLineWidth(2);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetXaxis()->SetRange(11,90);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131618);
   
   graph->Draw("f");
   
   Double_t sumPdf_Norm[muminus_ISO_]_fx9[47] = {
   -0.02439024,
   -0.02439024,
   0,
   1.0201e-08,
   0.04999999,
   0.05000001,
   0.09999999,
   0.1,
   0.15,
   0.15,
   0.2,
   0.2,
   0.25,
   0.25,
   0.3,
   0.3,
   0.35,
   0.35,
   0.4,
   0.4,
   0.45,
   0.45,
   0.5,
   0.5,
   0.55,
   0.55,
   0.6,
   0.6,
   0.65,
   0.65,
   0.7,
   0.7,
   0.75,
   0.75,
   0.8,
   0.8,
   0.85,
   0.85,
   0.9,
   0.9,
   0.95,
   0.95,
   1,
   1,
   1,
   1.02439,
   1.02439};
   Double_t sumPdf_Norm[muminus_ISO_]_fy9[47] = {
   0,
   0,
   0,
   8.630165e-06,
   8.630165e-06,
   8.630165e-06,
   8.630165e-06,
   8.630165e-06,
   8.630165e-06,
   3.789756,
   3.789756,
   71.12054,
   71.12054,
   211.4391,
   211.4391,
   857.6998,
   857.6998,
   1798.532,
   1798.532,
   3099.606,
   3099.606,
   4425.897,
   4425.897,
   5601.578,
   5601.578,
   6533.68,
   6533.68,
   6910.201,
   6910.201,
   6392.164,
   6392.164,
   5777.187,
   5777.187,
   5020.914,
   5020.914,
   5207.829,
   5207.829,
   6798.152,
   6798.152,
   13033.97,
   13033.97,
   27939.24,
   27939.24,
   0,
   0,
   0,
   0};
   graph = new TGraph(47,sumPdf_Norm[muminus_ISO_]_fx9,sumPdf_Norm[muminus_ISO_]_fy9);
   graph->SetName("sumPdf_Norm[muminus_ISO_]");
   graph->SetTitle("Projection of ");

   ci = TColor::GetColor("#ff0000");
   graph->SetFillColor(ci);
   graph->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(0);
   
   TH1F *Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839 = new TH1F("Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->SetMinimum(0);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->SetMaximum(30733.17);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->SetDirectory(0);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->SetStats(0);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->SetLineWidth(2);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetXaxis()->SetRange(11,90);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]151839);
   
   graph->Draw("");
   
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3006[20] = {
   0.025,
   0.075,
   0.125,
   0.175,
   0.225,
   0.275,
   0.325,
   0.375,
   0.425,
   0.475,
   0.525,
   0.575,
   0.625,
   0.675,
   0.725,
   0.775,
   0.825,
   0.875,
   0.925,
   0.975};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3006[20] = {
   0,
   0,
   9,
   26,
   118,
   315,
   881,
   1812,
   3086,
   4575,
   5856,
   6537,
   6824,
   6348,
   5662,
   4769,
   4941,
   6726,
   13179,
   28019};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3006[20] = {
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3006[20] = {
   0,
   0,
   2.943461,
   5.066015,
   10.37428,
   17.25528,
   29.18586,
   42.07053,
   55.05403,
   67.14059,
   76.02614,
   80.35326,
   82.10902,
   79.17591,
   74.74792,
   68.55976,
   69.79403,
   81.51372,
   114.3009,
   166.8895};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3006[20] = {
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025,
   0.025};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3006[20] = {
   1.147874,
   1.147874,
   4.110204,
   6.164324,
   11.37428,
   18.25528,
   30.18586,
   43.07053,
   56.05403,
   68.14059,
   77.02614,
   81.35326,
   83.10902,
   80.17591,
   75.74792,
   69.55976,
   70.79403,
   82.51372,
   115.3009,
   167.8895};
   grae = new TGraphAsymmErrors(20,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3006,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3006,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3006,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3006,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3006,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3006);
   grae->SetName("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]");
   grae->SetTitle("Histogram of combData_plot__muminus_ISO_");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006 = new TH1F("Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->SetMinimum(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->SetMaximum(31005.58);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001300230053006);
   
   grae->Draw("e1p");
   
   TLegend *leg = new TLegend(0.2,0.53,0.6,0.78,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(10);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]","Data, #sqrt{s}=8 TeV","lep");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("h5","Electroweak","f");

   ci = TColor::GetColor("#3333ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#3333ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("sumBkgPdf_totbkg_fitW","QCD","f");

   ci = TColor::GetColor("#ffff66");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ffff66");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("sumPdf_Norm[muminus_ISO_]","Fit","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2,0.8,0.4,0.87,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(132);
   TText *AText = pt->AddText("LHCb");
   pt->Draw();
   
   TH1F *Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy = new TH1F("Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->SetMinimum(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->SetMaximum(31005.58);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->SetDirectory(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->SetStats(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->SetLineWidth(2);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->GetZaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002_copy->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
