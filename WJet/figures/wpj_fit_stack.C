void wpj_fit_stack()
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
   upperPad->Range(-0.1730123,-8004.232,1.06279,49168.86);
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
   
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3007[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3007[20] = {
   0,
   3,
   3,
   23,
   105,
   381,
   883,
   2017,
   3414,
   5032,
   6548,
   7514,
   7845,
   7426,
   6921,
   6219,
   6893,
   10157,
   20467,
   41895};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3007[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3007[20] = {
   0,
   1.632705,
   1.632705,
   4.760717,
   9.759142,
   19.02562,
   29.21952,
   44.41381,
   57.93158,
   70.43835,
   80.42126,
   86.18477,
   88.07342,
   85.67569,
   82.69405,
   78.36222,
   82.5256,
   100.2832,
   142.5638,
   204.1833};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3007[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3007[20] = {
   1.147874,
   2.918186,
   2.918186,
   5.865235,
   10.75914,
   20.02562,
   30.21952,
   45.41381,
   58.93158,
   71.43835,
   81.42126,
   87.18477,
   89.07342,
   86.67569,
   83.69405,
   79.36222,
   83.5256,
   101.2832,
   143.5638,
   205.1833};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3007,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3007,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3007,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3007,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3007,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3007);
   grae->SetName("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]");
   grae->SetTitle("Histogram of combData_plot__muminus_ISO_");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007 = new TH1F("Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->SetMinimum(0);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->SetMaximum(46310.2);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007);
   
   grae->Draw("e1pa");
   
   Double_t i5_fx10[47] = {
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
   Double_t i5_fy10[47] = {
   0,
   0,
   0,
   7.92077e-06,
   7.92077e-06,
   7.92077e-06,
   7.92077e-06,
   7.92077e-06,
   7.92077e-06,
   3.654577,
   3.654577,
   65.14774,
   65.14774,
   250.736,
   250.736,
   887.2128,
   887.2128,
   1993.106,
   1993.106,
   3468.816,
   3468.816,
   4859.589,
   4859.589,
   6288.901,
   6288.901,
   7468.671,
   7468.671,
   7565.416,
   7565.416,
   7473.61,
   7473.61,
   7165.965,
   7165.965,
   6809.66,
   6809.66,
   7403.883,
   7403.883,
   10113.75,
   10113.75,
   20486.03,
   20486.03,
   41441.87,
   41441.87,
   0,
   0,
   0,
   0};
   TGraph *graph = new TGraph(47,i5_fx10,i5_fy10);
   graph->SetName("i5");
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
   
   TH1F *Graph_i510 = new TH1F("Graph_i510","Projection of ",100,-0.1292683,1.129268);
   Graph_i510->SetMinimum(0);
   Graph_i510->SetMaximum(45586.05);
   Graph_i510->SetDirectory(0);
   Graph_i510->SetStats(0);
   Graph_i510->SetLineWidth(2);
   Graph_i510->SetMarkerStyle(0);
   Graph_i510->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_i510->GetXaxis()->SetRange(11,90);
   Graph_i510->GetXaxis()->SetNdivisions(1005);
   Graph_i510->GetXaxis()->SetLabelFont(132);
   Graph_i510->GetXaxis()->SetLabelOffset(0.02);
   Graph_i510->GetXaxis()->SetLabelSize(0.05);
   Graph_i510->GetXaxis()->SetTitleSize(0.06);
   Graph_i510->GetXaxis()->SetTitleFont(132);
   Graph_i510->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_i510->GetYaxis()->SetLabelFont(132);
   Graph_i510->GetYaxis()->SetLabelSize(0.05);
   Graph_i510->GetYaxis()->SetTitleSize(0.06);
   Graph_i510->GetYaxis()->SetTitleFont(132);
   Graph_i510->GetZaxis()->SetLabelFont(132);
   Graph_i510->GetZaxis()->SetLabelSize(0.05);
   Graph_i510->GetZaxis()->SetTitleSize(0.06);
   Graph_i510->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_i510);
   
   graph->Draw("f");
   
   Double_t sumBkgPdf_totbkg_fitW_fx11[47] = {
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
   Double_t sumBkgPdf_totbkg_fitW_fy11[47] = {
   0,
   0,
   0,
   2.822783e-06,
   2.822783e-06,
   2.822783e-06,
   2.822783e-06,
   2.822783e-06,
   2.822783e-06,
   3.654572,
   3.654572,
   65.14773,
   65.14773,
   247.164,
   247.164,
   882.2495,
   882.2495,
   1984.991,
   1984.991,
   3453.025,
   3453.025,
   4822.093,
   4822.093,
   6226.075,
   6226.075,
   7334.988,
   7334.988,
   7364.799,
   7364.799,
   7083.501,
   7083.501,
   6369.267,
   6369.267,
   5082.929,
   5082.929,
   3869.464,
   3869.464,
   2855.9,
   2855.9,
   2230.567,
   2230.567,
   2073.989,
   2073.989,
   0,
   0,
   0,
   0};
   graph = new TGraph(47,sumBkgPdf_totbkg_fitW_fx11,sumBkgPdf_totbkg_fitW_fy11);
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
   
   TH1F *Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411 = new TH1F("Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->SetMinimum(0);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->SetMaximum(8101.279);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->SetDirectory(0);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->SetStats(0);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->SetLineWidth(2);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetXaxis()->SetRange(11,90);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW1316411);
   
   graph->Draw("f");
   
   Double_t sumPdf_Norm[muminus_ISO_]_fx12[47] = {
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
   Double_t sumPdf_Norm[muminus_ISO_]_fy12[47] = {
   0,
   0,
   0,
   7.920762e-06,
   7.920762e-06,
   7.920762e-06,
   7.920762e-06,
   7.920762e-06,
   7.920762e-06,
   3.654572,
   3.654572,
   65.14777,
   65.14777,
   250.736,
   250.736,
   887.2128,
   887.2128,
   1993.106,
   1993.106,
   3468.817,
   3468.817,
   4859.59,
   4859.59,
   6288.902,
   6288.902,
   7468.672,
   7468.672,
   7565.416,
   7565.416,
   7473.609,
   7473.609,
   7165.964,
   7165.964,
   6809.658,
   6809.658,
   7403.881,
   7403.881,
   10113.75,
   10113.75,
   20486.03,
   20486.03,
   41441.86,
   41441.86,
   0,
   0,
   0,
   0};
   graph = new TGraph(47,sumPdf_Norm[muminus_ISO_]_fx12,sumPdf_Norm[muminus_ISO_]_fy12);
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
   
   TH1F *Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612 = new TH1F("Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->SetMinimum(0);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->SetMaximum(45586.05);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->SetDirectory(0);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->SetStats(0);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->SetLineWidth(2);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetXaxis()->SetRange(11,90);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_Graph_Graph_sumPdf_Norm[muminus_ISO_]1518612);
   
   graph->Draw("");
   
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3008[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3008[20] = {
   0,
   3,
   3,
   23,
   105,
   381,
   883,
   2017,
   3414,
   5032,
   6548,
   7514,
   7845,
   7426,
   6921,
   6219,
   6893,
   10157,
   20467,
   41895};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3008[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3008[20] = {
   0,
   1.632705,
   1.632705,
   4.760717,
   9.759142,
   19.02562,
   29.21952,
   44.41381,
   57.93158,
   70.43835,
   80.42126,
   86.18477,
   88.07342,
   85.67569,
   82.69405,
   78.36222,
   82.5256,
   100.2832,
   142.5638,
   204.1833};
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3008[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3008[20] = {
   1.147874,
   2.918186,
   2.918186,
   5.865235,
   10.75914,
   20.02562,
   30.21952,
   45.41381,
   58.93158,
   71.43835,
   81.42126,
   87.18477,
   89.07342,
   86.67569,
   83.69405,
   79.36222,
   83.5256,
   101.2832,
   143.5638,
   205.1833};
   grae = new TGraphAsymmErrors(20,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3008,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3008,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3008,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3008,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3008,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3008);
   grae->SetName("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]");
   grae->SetTitle("Histogram of combData_plot__muminus_ISO_");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008 = new TH1F("Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->SetMinimum(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->SetMaximum(46310.2);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008);
   
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
   entry=leg->AddEntry("i5","Electroweak","f");

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
   
   TH1F *Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy = new TH1F("Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->SetMinimum(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->SetMaximum(46310.2);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->SetDirectory(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->SetStats(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->SetLineWidth(2);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->GetZaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004_copy->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
