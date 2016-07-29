void wpj_fit_stack_ewk()
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
   upperPad->Range(-0.1730123,-7777.778,1.06279,47777.78);
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
   
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3011[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3011[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3011[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3011[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3011[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3011[20] = {
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
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(20,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3011,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3011,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3011,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3011,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3011,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3011);
   grae->SetName("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]");
   grae->SetTitle("Histogram of combData_plot__muminus_ISO_");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011 = new TH1F("Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->SetMinimum(0);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->SetMaximum(45000);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]5630033004300730083011);
   
   grae->Draw("e1pa");
   
   Double_t i5_fx16[47] = {
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
   Double_t i5_fy16[47] = {
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
   TGraph *graph = new TGraph(47,i5_fx16,i5_fy16);
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
   
   TH1F *Graph_Graph_i51016 = new TH1F("Graph_Graph_i51016","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_i51016->SetMinimum(0);
   Graph_Graph_i51016->SetMaximum(45000);
   Graph_Graph_i51016->SetDirectory(0);
   Graph_Graph_i51016->SetStats(0);
   Graph_Graph_i51016->SetLineWidth(2);
   Graph_Graph_i51016->SetMarkerStyle(0);
   Graph_Graph_i51016->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_i51016->GetXaxis()->SetRange(11,90);
   Graph_Graph_i51016->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_i51016->GetXaxis()->SetLabelFont(132);
   Graph_Graph_i51016->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_i51016->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_i51016->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_i51016->GetXaxis()->SetTitleFont(132);
   Graph_Graph_i51016->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_i51016->GetYaxis()->SetLabelFont(132);
   Graph_Graph_i51016->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_i51016->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_i51016->GetYaxis()->SetTitleFont(132);
   Graph_Graph_i51016->GetZaxis()->SetLabelFont(132);
   Graph_Graph_i51016->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_i51016->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_i51016->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_i51016);
   
   graph->Draw("f");
   
   Double_t i7_fx17[47] = {
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
   Double_t i7_fy17[47] = {
   0,
   0,
   0,
   3.433318e-06,
   3.433318e-06,
   3.433318e-06,
   3.433318e-06,
   3.433318e-06,
   3.433318e-06,
   3.654573,
   3.654573,
   65.14773,
   65.14773,
   247.5918,
   247.5918,
   882.8439,
   882.8439,
   1985.963,
   1985.963,
   3454.916,
   3454.916,
   4826.584,
   4826.584,
   6233.599,
   6233.599,
   7350.998,
   7350.998,
   7388.825,
   7388.825,
   7130.22,
   7130.22,
   6464.68,
   6464.68,
   5289.722,
   5289.722,
   4292.746,
   4292.746,
   3725.1,
   3725.1,
   4416.841,
   4416.841,
   6788.686,
   6788.686,
   0,
   0,
   0,
   0};
   graph = new TGraph(47,i7_fx17,i7_fy17);
   graph->SetName("i7");
   graph->SetTitle("Projection of ");

   ci = TColor::GetColor("#66cc66");
   graph->SetFillColor(ci);

   ci = TColor::GetColor("#66cc66");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);

   ci = TColor::GetColor("#66cc66");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(0);
   
   TH1F *Graph_i717 = new TH1F("Graph_i717","Projection of ",100,-0.1292683,1.129268);
   Graph_i717->SetMinimum(0);
   Graph_i717->SetMaximum(45000);
   Graph_i717->SetDirectory(0);
   Graph_i717->SetStats(0);
   Graph_i717->SetLineWidth(2);
   Graph_i717->SetMarkerStyle(0);
   Graph_i717->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_i717->GetXaxis()->SetRange(11,90);
   Graph_i717->GetXaxis()->SetNdivisions(1005);
   Graph_i717->GetXaxis()->SetLabelFont(132);
   Graph_i717->GetXaxis()->SetLabelOffset(0.02);
   Graph_i717->GetXaxis()->SetLabelSize(0.05);
   Graph_i717->GetXaxis()->SetTitleSize(0.06);
   Graph_i717->GetXaxis()->SetTitleFont(132);
   Graph_i717->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_i717->GetYaxis()->SetLabelFont(132);
   Graph_i717->GetYaxis()->SetLabelSize(0.05);
   Graph_i717->GetYaxis()->SetTitleSize(0.06);
   Graph_i717->GetYaxis()->SetTitleFont(132);
   Graph_i717->GetZaxis()->SetLabelFont(132);
   Graph_i717->GetZaxis()->SetLabelSize(0.05);
   Graph_i717->GetZaxis()->SetTitleSize(0.06);
   Graph_i717->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_i717);
   
   graph->Draw("f");
   
   Double_t sumBkgPdf_totbkg_fitW_fx18[47] = {
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
   Double_t sumBkgPdf_totbkg_fitW_fy18[47] = {
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
   graph = new TGraph(47,sumBkgPdf_totbkg_fitW_fx18,sumBkgPdf_totbkg_fitW_fy18);
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
   
   TH1F *Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118 = new TH1F("Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118","Projection of ",100,-0.1292683,1.129268);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->SetMinimum(0);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->SetMaximum(45000);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetXaxis()->SetRange(11,90);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118->GetZaxis()->SetTitleFont(132);
   graph->SetHistogram(Graph_Graph_Graph_Graph_Graph_sumBkgPdf_totbkg_fitW131641118);
   
   graph->Draw("f");
   
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3012[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3012[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3012[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3012[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3012[20] = {
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
   Double_t h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3012[20] = {
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
   grae = new TGraphAsymmErrors(20,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fx3012,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fy3012,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_felx3012,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehx3012,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fely3012,h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]_fehy3012);
   grae->SetName("h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]");
   grae->SetTitle("Histogram of combData_plot__muminus_ISO_");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012 = new TH1F("Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->SetMinimum(0);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->SetMaximum(45000);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]56300330043007300830113012);
   
   grae->Draw("p");
   
   TLegend *leg = new TLegend(0.2,0.5,0.6,0.8,NULL,"brNDC");
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
   entry=leg->AddEntry("i5","#it{W^{#scale[1.2]{#plus}}j}","f");

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
   entry=leg->AddEntry("i7","Electroweak","f");

   ci = TColor::GetColor("#66cc66");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#66cc66");
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
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2,0.8,0.4,0.87,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(132);
   TText *AText = pt->AddText("LHCb");
   pt->Draw();
   
   TH1F *Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy = new TH1F("Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy","Histogram of combData_plot__muminus_ISO_",100,0,1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->SetMinimum(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->SetMaximum(45000);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->SetDirectory(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->SetStats(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->SetLineWidth(2);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->SetMarkerStyle(0);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetXaxis()->SetTitle("#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ");
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetXaxis()->SetRange(1,91);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetXaxis()->SetNdivisions(1005);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetYaxis()->SetTitle("Events / (0.05)");
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetYaxis()->SetTitleOffset(1.1);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->GetZaxis()->SetTitleFont(132);
   Graph_Graph_Graph_Graph_Graph_Graph_h_combData_Cut[samples == samples::fitW_etam_0 || samples == samples::fitW_etam_1 || samples == samples::fitW_etam_2 || samples == samples::fitW_etam_3]563003300430073008_copy->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
