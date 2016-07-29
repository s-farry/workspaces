void wmj_fit()
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
   
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3001[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3001[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3001[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3001[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3001[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3001[20] = {
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
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3001,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3001,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3001,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3001,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3001,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3001);
   grae->SetName("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]");
   grae->SetTitle("Histogram of combData_plot__muminus_ISO_");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001 = new TH1F("Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->SetMinimum(0);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->SetMaximum(31005.58);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->SetDirectory(0);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->SetStats(0);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->SetLineWidth(2);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->SetMarkerStyle(0);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563001);
   
   grae->Draw("pa");
   
   Double_t sumBkgPdf_totbkg_fitW_fx1[47] = {
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
   Double_t sumBkgPdf_totbkg_fitW_fy1[47] = {
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
   TGraph *graph = new TGraph(47,sumBkgPdf_totbkg_fitW_fx1,sumBkgPdf_totbkg_fitW_fy1);
   graph->SetName("sumBkgPdf_totbkg_fitW");
   graph->SetTitle("Projection of ");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(0);
   
   TH1F *Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161 = new TH1F("Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->SetMinimum(0);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->SetMaximum(7469.797);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->SetDirectory(0);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->SetStats(0);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->SetLineWidth(2);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->SetMarkerStyle(0);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetXaxis()->SetRange(11,90);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_Graph_sumBkgPdf_totbkg_fitW13161);
   
   graph->Draw("");
   
   Double_t sumSigPdf_fx2[47] = {
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
   Double_t sumSigPdf_fy2[47] = {
   0,
   0,
   0,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   5.751604e-06,
   2.687496,
   2.687496,
   4.02075,
   4.02075,
   10.72899,
   10.72899,
   26.1298,
   26.1298,
   33.31184,
   33.31184,
   72.71484,
   72.71484,
   119.4831,
   119.4831,
   250.0034,
   250.0034,
   443.9845,
   443.9845,
   957.9669,
   957.9669,
   2104.063,
   2104.063,
   4403.301,
   4403.301,
   11299.47,
   11299.47,
   26288.39,
   26288.39,
   0,
   0,
   0,
   0};
   graph = new TGraph(47,sumSigPdf_fx2,sumSigPdf_fy2);
   graph->SetName("sumSigPdf");
   graph->SetTitle("Projection of ");

   ci = TColor::GetColor("#00ff00");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#00ff00");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(0);
   
   TH1F *Graph_Graph_Graph_sumSigPdf14172 = new TH1F("Graph_Graph_Graph_sumSigPdf14172","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_Graph_sumSigPdf14172->SetMinimum(0);
   Graph_Graph_Graph_sumSigPdf14172->SetMaximum(28917.23);
   Graph_Graph_Graph_sumSigPdf14172->SetDirectory(0);
   Graph_Graph_Graph_sumSigPdf14172->SetStats(0);
   Graph_Graph_Graph_sumSigPdf14172->SetLineWidth(2);
   Graph_Graph_Graph_sumSigPdf14172->SetMarkerStyle(0);
   Graph_Graph_Graph_sumSigPdf14172->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_sumSigPdf14172->GetXaxis()->SetRange(11,90);
   Graph_Graph_Graph_sumSigPdf14172->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_sumSigPdf14172->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumSigPdf14172->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_sumSigPdf14172->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumSigPdf14172->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumSigPdf14172->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_sumSigPdf14172->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_sumSigPdf14172->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumSigPdf14172->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumSigPdf14172->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumSigPdf14172->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_sumSigPdf14172->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumSigPdf14172->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumSigPdf14172->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumSigPdf14172->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_Graph_sumSigPdf14172);
   
   graph->Draw("");
   
   Double_t sumPdf_Norm[muminus_ISO_]_fx3[47] = {
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
   Double_t sumPdf_Norm[muminus_ISO_]_fy3[47] = {
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
   graph = new TGraph(47,sumPdf_Norm[muminus_ISO_]_fx3,sumPdf_Norm[muminus_ISO_]_fy3);
   graph->SetName("sumPdf_Norm[muminus_ISO_]");
   graph->SetTitle("Projection of ");

   ci = TColor::GetColor("#0000ff");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);

   ci = TColor::GetColor("#0000ff");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(0);
   
   TH1F *Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183 = new TH1F("Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->SetMinimum(0);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->SetMaximum(30733.17);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->SetDirectory(0);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->SetStats(0);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->SetLineWidth(2);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->SetMarkerStyle(0);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetXaxis()->SetRange(11,90);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]15183);
   
   graph->Draw("");
   
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3002[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3002[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3002[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3002[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3002[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3002[20] = {
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
   grae = new TGraphAsymmErrors(20,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3002,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3002,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3002,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3002,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3002,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3002);
   grae->SetName("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]");
   grae->SetTitle("Histogram of combData_plot__muminus_ISO_");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002 = new TH1F("Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->SetMinimum(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->SetMaximum(31005.58);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->SetDirectory(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->SetStats(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->SetLineWidth(2);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630013002);
   
   grae->Draw("p");
   
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
   entry=leg->AddEntry("sumBkgPdf_totbkg_fitW","QCD","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("sumSigPdf","Electroweak","l");

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("sumPdf_Norm[muminus_ISO_]","Fit","l");

   ci = TColor::GetColor("#0000ff");
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
   
   TH1F *Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy = new TH1F("Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->SetMinimum(0);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->SetMaximum(31005.58);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->SetDirectory(0);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->SetStats(0);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->SetLineWidth(2);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->SetMarkerStyle(0);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetXaxis()->SetRange(1,91);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetXaxis()->SetLabelFont(132);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetXaxis()->SetTitleFont(132);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetYaxis()->SetLabelFont(132);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetYaxis()->SetTitleFont(132);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetZaxis()->SetLabelFont(132);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->GetZaxis()->SetTitleFont(132);
   Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56_copy->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
