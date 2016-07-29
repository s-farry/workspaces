void wmj_etaj_8TeV()
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
   upperPad->Range(1.854321,-10.3692,4.323457,63.70364);
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
   Double_t xAxis46[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_toterr__58 = new TH1F("wm_etaj_toterr__58","wm_etaj",4, xAxis46);
   wm_etaj_toterr__58->SetBinContent(1,30.50039);
   wm_etaj_toterr__58->SetBinContent(2,20.57146);
   wm_etaj_toterr__58->SetBinContent(3,11.20298);
   wm_etaj_toterr__58->SetBinContent(4,3.930728);
   wm_etaj_toterr__58->SetBinContent(5,1.965363);
   wm_etaj_toterr__58->SetBinError(1,3.140994);
   wm_etaj_toterr__58->SetBinError(2,2.204208);
   wm_etaj_toterr__58->SetBinError(3,1.339208);
   wm_etaj_toterr__58->SetBinError(4,0.6610862);
   wm_etaj_toterr__58->SetBinError(5,0.3305429);
   wm_etaj_toterr__58->SetMinimum(0.001);
   wm_etaj_toterr__58->SetMaximum(60);
   wm_etaj_toterr__58->SetEntries(10);
   wm_etaj_toterr__58->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wm_etaj_toterr__58->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wm_etaj_toterr__58->SetLineColor(ci);
   wm_etaj_toterr__58->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wm_etaj_toterr__58->SetMarkerColor(ci);
   wm_etaj_toterr__58->SetMarkerStyle(0);
   wm_etaj_toterr__58->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wm_etaj_toterr__58->GetXaxis()->SetNdivisions(4);
   wm_etaj_toterr__58->GetXaxis()->SetLabelFont(132);
   wm_etaj_toterr__58->GetXaxis()->SetLabelOffset(0.02);
   wm_etaj_toterr__58->GetXaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__58->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__58->GetXaxis()->SetTitleFont(132);
   wm_etaj_toterr__58->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{#it{j}} [pb]");
   wm_etaj_toterr__58->GetYaxis()->SetLabelFont(132);
   wm_etaj_toterr__58->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__58->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__58->GetYaxis()->SetTitleFont(132);
   wm_etaj_toterr__58->GetZaxis()->SetLabelFont(132);
   wm_etaj_toterr__58->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_toterr__58->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_toterr__58->GetZaxis()->SetTitleFont(132);
   wm_etaj_toterr__58->Draw("e2");
   Double_t xAxis47[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_staterr__59 = new TH1F("wm_etaj_staterr__59","wm_etaj",4, xAxis47);
   wm_etaj_staterr__59->SetBinContent(1,30.50039);
   wm_etaj_staterr__59->SetBinContent(2,20.57146);
   wm_etaj_staterr__59->SetBinContent(3,11.20298);
   wm_etaj_staterr__59->SetBinContent(4,3.930728);
   wm_etaj_staterr__59->SetBinContent(5,1.965363);
   wm_etaj_staterr__59->SetBinError(1,0.2315095);
   wm_etaj_staterr__59->SetBinError(2,0.1981347);
   wm_etaj_staterr__59->SetBinError(3,0.1458553);
   wm_etaj_staterr__59->SetBinError(4,0.08079061);
   wm_etaj_staterr__59->SetBinError(5,0.04039529);
   wm_etaj_staterr__59->SetMinimum(0.001);
   wm_etaj_staterr__59->SetMaximum(60);
   wm_etaj_staterr__59->SetEntries(10);
   wm_etaj_staterr__59->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wm_etaj_staterr__59->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wm_etaj_staterr__59->SetLineColor(ci);
   wm_etaj_staterr__59->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wm_etaj_staterr__59->SetMarkerColor(ci);
   wm_etaj_staterr__59->SetMarkerStyle(0);
   wm_etaj_staterr__59->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wm_etaj_staterr__59->GetXaxis()->SetNdivisions(4);
   wm_etaj_staterr__59->GetXaxis()->SetLabelFont(132);
   wm_etaj_staterr__59->GetXaxis()->SetLabelOffset(0.02);
   wm_etaj_staterr__59->GetXaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__59->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__59->GetXaxis()->SetTitleFont(132);
   wm_etaj_staterr__59->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{#it{j}} [pb]");
   wm_etaj_staterr__59->GetYaxis()->SetLabelFont(132);
   wm_etaj_staterr__59->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__59->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__59->GetYaxis()->SetTitleFont(132);
   wm_etaj_staterr__59->GetZaxis()->SetLabelFont(132);
   wm_etaj_staterr__59->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_staterr__59->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_staterr__59->GetZaxis()->SetTitleFont(132);
   wm_etaj_staterr__59->Draw("e2same");
   
   Double_t etaj_minus_toterrs_fx3069[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_minus_toterrs_fy3069[4] = {
   33.75167,
   23.54495,
   13.13125,
   5.618726};
   Double_t etaj_minus_toterrs_felx3069[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fely3069[4] = {
   3.331792,
   2.081235,
   1.468378,
   0.5957157};
   Double_t etaj_minus_toterrs_fehx3069[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fehy3069[4] = {
   2.655911,
   1.820553,
   0.9805522,
   0.8736437};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,etaj_minus_toterrs_fx3069,etaj_minus_toterrs_fy3069,etaj_minus_toterrs_felx3069,etaj_minus_toterrs_fehx3069,etaj_minus_toterrs_fely3069,etaj_minus_toterrs_fehy3069);
   grae->SetName("etaj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_etaj_minus_toterrs3069 = new TH1F("Graph_etaj_minus_toterrs3069","",100,2.375,4.175);
   Graph_etaj_minus_toterrs3069->SetMinimum(0.001);
   Graph_etaj_minus_toterrs3069->SetMaximum(60);
   Graph_etaj_minus_toterrs3069->SetDirectory(0);
   Graph_etaj_minus_toterrs3069->SetStats(0);
   Graph_etaj_minus_toterrs3069->SetLineWidth(2);
   Graph_etaj_minus_toterrs3069->SetMarkerStyle(0);
   Graph_etaj_minus_toterrs3069->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_etaj_minus_toterrs3069->GetXaxis()->SetNdivisions(4);
   Graph_etaj_minus_toterrs3069->GetXaxis()->SetLabelFont(132);
   Graph_etaj_minus_toterrs3069->GetXaxis()->SetLabelOffset(0.02);
   Graph_etaj_minus_toterrs3069->GetXaxis()->SetLabelSize(0.05);
   Graph_etaj_minus_toterrs3069->GetXaxis()->SetTitleSize(0.06);
   Graph_etaj_minus_toterrs3069->GetXaxis()->SetTitleFont(132);
   Graph_etaj_minus_toterrs3069->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{#it{j}} [pb]");
   Graph_etaj_minus_toterrs3069->GetYaxis()->SetLabelFont(132);
   Graph_etaj_minus_toterrs3069->GetYaxis()->SetLabelSize(0.05);
   Graph_etaj_minus_toterrs3069->GetYaxis()->SetTitleSize(0.06);
   Graph_etaj_minus_toterrs3069->GetYaxis()->SetTitleFont(132);
   Graph_etaj_minus_toterrs3069->GetZaxis()->SetLabelFont(132);
   Graph_etaj_minus_toterrs3069->GetZaxis()->SetLabelSize(0.05);
   Graph_etaj_minus_toterrs3069->GetZaxis()->SetTitleSize(0.06);
   Graph_etaj_minus_toterrs3069->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_etaj_minus_toterrs3069);
   
   grae->Draw("p1p");
   
   Double_t _fx3070[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3070[4] = {
   33.75167,
   23.54495,
   13.13125,
   5.618726};
   Double_t _felx3070[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3070[4] = {
   1.953403,
   1.325998,
   0.668684,
   0.29035};
   Double_t _fehx3070[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3070[4] = {
   1.972477,
   1.306662,
   0.6129732,
   0.3088737};
   grae = new TGraphAsymmErrors(4,_fx3070,_fy3070,_felx3070,_fehx3070,_fely3070,_fehy3070);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(26);
   
   TH1F *Graph_Graph3070 = new TH1F("Graph_Graph3070","",100,2.375,4.175);
   Graph_Graph3070->SetMinimum(0.001);
   Graph_Graph3070->SetMaximum(60);
   Graph_Graph3070->SetDirectory(0);
   Graph_Graph3070->SetStats(0);
   Graph_Graph3070->SetLineWidth(2);
   Graph_Graph3070->SetMarkerStyle(0);
   Graph_Graph3070->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_Graph3070->GetXaxis()->SetNdivisions(4);
   Graph_Graph3070->GetXaxis()->SetLabelFont(132);
   Graph_Graph3070->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3070->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3070->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3070->GetXaxis()->SetTitleFont(132);
   Graph_Graph3070->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{#it{j}} [pb]");
   Graph_Graph3070->GetYaxis()->SetLabelFont(132);
   Graph_Graph3070->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3070->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3070->GetYaxis()->SetTitleFont(132);
   Graph_Graph3070->GetZaxis()->SetLabelFont(132);
   Graph_Graph3070->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3070->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3070->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3070);
   
   grae->Draw("p1p");
   
   Double_t etaj_minus_toterrs_fx3071[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_minus_toterrs_fy3071[4] = {
   34.25415,
   23.32036,
   12.9946,
   5.344251};
   Double_t etaj_minus_toterrs_felx3071[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fely3071[4] = {
   2.822029,
   1.901017,
   1.140151,
   0.5488711};
   Double_t etaj_minus_toterrs_fehx3071[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_minus_toterrs_fehy3071[4] = {
   2.930556,
   2.008099,
   1.186782,
   0.6439278};
   grae = new TGraphAsymmErrors(4,etaj_minus_toterrs_fx3071,etaj_minus_toterrs_fy3071,etaj_minus_toterrs_felx3071,etaj_minus_toterrs_fehx3071,etaj_minus_toterrs_fely3071,etaj_minus_toterrs_fehy3071);
   grae->SetName("etaj_minus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_etaj_minus_toterrs3071 = new TH1F("Graph_etaj_minus_toterrs3071","",100,2.225,4.025);
   Graph_etaj_minus_toterrs3071->SetMinimum(0.001);
   Graph_etaj_minus_toterrs3071->SetMaximum(60);
   Graph_etaj_minus_toterrs3071->SetDirectory(0);
   Graph_etaj_minus_toterrs3071->SetStats(0);
   Graph_etaj_minus_toterrs3071->SetLineWidth(2);
   Graph_etaj_minus_toterrs3071->SetMarkerStyle(0);
   Graph_etaj_minus_toterrs3071->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_etaj_minus_toterrs3071->GetXaxis()->SetNdivisions(4);
   Graph_etaj_minus_toterrs3071->GetXaxis()->SetLabelFont(132);
   Graph_etaj_minus_toterrs3071->GetXaxis()->SetLabelOffset(0.02);
   Graph_etaj_minus_toterrs3071->GetXaxis()->SetLabelSize(0.05);
   Graph_etaj_minus_toterrs3071->GetXaxis()->SetTitleSize(0.06);
   Graph_etaj_minus_toterrs3071->GetXaxis()->SetTitleFont(132);
   Graph_etaj_minus_toterrs3071->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{#it{j}} [pb]");
   Graph_etaj_minus_toterrs3071->GetYaxis()->SetLabelFont(132);
   Graph_etaj_minus_toterrs3071->GetYaxis()->SetLabelSize(0.05);
   Graph_etaj_minus_toterrs3071->GetYaxis()->SetTitleSize(0.06);
   Graph_etaj_minus_toterrs3071->GetYaxis()->SetTitleFont(132);
   Graph_etaj_minus_toterrs3071->GetZaxis()->SetLabelFont(132);
   Graph_etaj_minus_toterrs3071->GetZaxis()->SetLabelSize(0.05);
   Graph_etaj_minus_toterrs3071->GetZaxis()->SetTitleSize(0.06);
   Graph_etaj_minus_toterrs3071->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_etaj_minus_toterrs3071);
   
   grae->Draw("p1p");
   
   Double_t _fx3072[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3072[4] = {
   34.25415,
   23.32036,
   12.9946,
   5.344251};
   Double_t _felx3072[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3072[4] = {
   2.132698,
   1.400249,
   0.7785425,
   0.3408947};
   Double_t _fehx3072[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3072[4] = {
   2.256241,
   1.482401,
   0.844492,
   0.3783941};
   grae = new TGraphAsymmErrors(4,_fx3072,_fy3072,_felx3072,_fehx3072,_fely3072,_fehy3072);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(22);
   
   TH1F *Graph_Graph3072 = new TH1F("Graph_Graph3072","",100,2.225,4.025);
   Graph_Graph3072->SetMinimum(0.001);
   Graph_Graph3072->SetMaximum(60);
   Graph_Graph3072->SetDirectory(0);
   Graph_Graph3072->SetStats(0);
   Graph_Graph3072->SetLineWidth(2);
   Graph_Graph3072->SetMarkerStyle(0);
   Graph_Graph3072->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_Graph3072->GetXaxis()->SetNdivisions(4);
   Graph_Graph3072->GetXaxis()->SetLabelFont(132);
   Graph_Graph3072->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3072->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3072->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3072->GetXaxis()->SetTitleFont(132);
   Graph_Graph3072->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{#it{j}} [pb]");
   Graph_Graph3072->GetYaxis()->SetLabelFont(132);
   Graph_Graph3072->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3072->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3072->GetYaxis()->SetTitleFont(132);
   Graph_Graph3072->GetZaxis()->SetLabelFont(132);
   Graph_Graph3072->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3072->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3072->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3072);
   
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
   Double_t xAxis48[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *wm_etaj_toterr_copy__60 = new TH1F("wm_etaj_toterr_copy__60","wm_etaj",4, xAxis48);
   wm_etaj_toterr_copy__60->SetBinContent(1,30.50039);
   wm_etaj_toterr_copy__60->SetBinContent(2,20.57146);
   wm_etaj_toterr_copy__60->SetBinContent(3,11.20298);
   wm_etaj_toterr_copy__60->SetBinContent(4,3.930728);
   wm_etaj_toterr_copy__60->SetBinContent(5,1.965363);
   wm_etaj_toterr_copy__60->SetBinError(1,3.140994);
   wm_etaj_toterr_copy__60->SetBinError(2,2.204208);
   wm_etaj_toterr_copy__60->SetBinError(3,1.339208);
   wm_etaj_toterr_copy__60->SetBinError(4,0.6610862);
   wm_etaj_toterr_copy__60->SetBinError(5,0.3305429);
   wm_etaj_toterr_copy__60->SetMinimum(0.001);
   wm_etaj_toterr_copy__60->SetMaximum(60);
   wm_etaj_toterr_copy__60->SetEntries(10);
   wm_etaj_toterr_copy__60->SetDirectory(0);
   wm_etaj_toterr_copy__60->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wm_etaj_toterr_copy__60->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wm_etaj_toterr_copy__60->SetLineColor(ci);
   wm_etaj_toterr_copy__60->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wm_etaj_toterr_copy__60->SetMarkerColor(ci);
   wm_etaj_toterr_copy__60->SetMarkerStyle(0);
   wm_etaj_toterr_copy__60->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   wm_etaj_toterr_copy__60->GetXaxis()->SetNdivisions(4);
   wm_etaj_toterr_copy__60->GetXaxis()->SetLabelFont(132);
   wm_etaj_toterr_copy__60->GetXaxis()->SetLabelOffset(0.02);
   wm_etaj_toterr_copy__60->GetXaxis()->SetLabelSize(0.05);
   wm_etaj_toterr_copy__60->GetXaxis()->SetTitleSize(0.06);
   wm_etaj_toterr_copy__60->GetXaxis()->SetTitleFont(132);
   wm_etaj_toterr_copy__60->GetYaxis()->SetTitle("d#sigma(#it{Wj})/#it{#eta}^{#it{j}} [pb]");
   wm_etaj_toterr_copy__60->GetYaxis()->SetLabelFont(132);
   wm_etaj_toterr_copy__60->GetYaxis()->SetLabelSize(0.05);
   wm_etaj_toterr_copy__60->GetYaxis()->SetTitleSize(0.06);
   wm_etaj_toterr_copy__60->GetYaxis()->SetTitleFont(132);
   wm_etaj_toterr_copy__60->GetZaxis()->SetLabelFont(132);
   wm_etaj_toterr_copy__60->GetZaxis()->SetLabelSize(0.05);
   wm_etaj_toterr_copy__60->GetZaxis()->SetTitleSize(0.06);
   wm_etaj_toterr_copy__60->GetZaxis()->SetTitleFont(132);
   wm_etaj_toterr_copy__60->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
