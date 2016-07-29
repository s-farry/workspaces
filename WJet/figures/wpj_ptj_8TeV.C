void wpj_ptj_8TeV()
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
   upperPad->Range(6.172839,-1.489858,104.9383,0.9738902);
   upperPad->SetFillColor(0);
   upperPad->SetFillStyle(4000);
   upperPad->SetBorderMode(0);
   upperPad->SetBorderSize(2);
   upperPad->SetLogy();
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
   Double_t xAxis40[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_toterr__52 = new TH1F("wp_ptj_toterr__52","wp_ptj",5, xAxis40);
   wp_ptj_toterr__52->SetBinContent(1,3.450959);
   wp_ptj_toterr__52->SetBinContent(2,2.256658);
   wp_ptj_toterr__52->SetBinContent(3,1.266894);
   wp_ptj_toterr__52->SetBinContent(4,0.667355);
   wp_ptj_toterr__52->SetBinContent(5,0.1635365);
   wp_ptj_toterr__52->SetBinContent(6,8.176826);
   wp_ptj_toterr__52->SetBinError(1,0.2914732);
   wp_ptj_toterr__52->SetBinError(2,0.2298212);
   wp_ptj_toterr__52->SetBinError(3,0.117779);
   wp_ptj_toterr__52->SetBinError(4,0.07112221);
   wp_ptj_toterr__52->SetBinError(5,0.02028571);
   wp_ptj_toterr__52->SetBinError(6,1.014286);
   wp_ptj_toterr__52->SetEntries(12);
   wp_ptj_toterr__52->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__52->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__52->SetLineColor(ci);
   wp_ptj_toterr__52->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr__52->SetMarkerColor(ci);
   wp_ptj_toterr__52->SetMarkerStyle(0);
   wp_ptj_toterr__52->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wp_ptj_toterr__52->GetXaxis()->SetNdivisions(4);
   wp_ptj_toterr__52->GetXaxis()->SetLabelFont(132);
   wp_ptj_toterr__52->GetXaxis()->SetLabelOffset(0.02);
   wp_ptj_toterr__52->GetXaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__52->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__52->GetXaxis()->SetTitleFont(132);
   wp_ptj_toterr__52->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_toterr__52->GetYaxis()->SetLabelFont(132);
   wp_ptj_toterr__52->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__52->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__52->GetYaxis()->SetTitleFont(132);
   wp_ptj_toterr__52->GetZaxis()->SetLabelFont(132);
   wp_ptj_toterr__52->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_toterr__52->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_toterr__52->GetZaxis()->SetTitleFont(132);
   wp_ptj_toterr__52->Draw("e2");
   Double_t xAxis41[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_staterr__53 = new TH1F("wp_ptj_staterr__53","wp_ptj",5, xAxis41);
   wp_ptj_staterr__53->SetBinContent(1,3.450959);
   wp_ptj_staterr__53->SetBinContent(2,2.256658);
   wp_ptj_staterr__53->SetBinContent(3,1.266894);
   wp_ptj_staterr__53->SetBinContent(4,0.667355);
   wp_ptj_staterr__53->SetBinContent(5,0.1635365);
   wp_ptj_staterr__53->SetBinContent(6,8.176826);
   wp_ptj_staterr__53->SetBinError(1,0.02497134);
   wp_ptj_staterr__53->SetBinError(2,0.02019583);
   wp_ptj_staterr__53->SetBinError(3,0.01073196);
   wp_ptj_staterr__53->SetBinError(4,0.007910258);
   wp_ptj_staterr__53->SetBinError(5,0.001777759);
   wp_ptj_staterr__53->SetBinError(6,0.08888796);
   wp_ptj_staterr__53->SetEntries(12);
   wp_ptj_staterr__53->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__53->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__53->SetLineColor(ci);
   wp_ptj_staterr__53->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wp_ptj_staterr__53->SetMarkerColor(ci);
   wp_ptj_staterr__53->SetMarkerStyle(0);
   wp_ptj_staterr__53->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wp_ptj_staterr__53->GetXaxis()->SetNdivisions(4);
   wp_ptj_staterr__53->GetXaxis()->SetLabelFont(132);
   wp_ptj_staterr__53->GetXaxis()->SetLabelOffset(0.02);
   wp_ptj_staterr__53->GetXaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__53->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__53->GetXaxis()->SetTitleFont(132);
   wp_ptj_staterr__53->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_staterr__53->GetYaxis()->SetLabelFont(132);
   wp_ptj_staterr__53->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__53->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__53->GetYaxis()->SetTitleFont(132);
   wp_ptj_staterr__53->GetZaxis()->SetLabelFont(132);
   wp_ptj_staterr__53->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_staterr__53->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_staterr__53->GetZaxis()->SetTitleFont(132);
   wp_ptj_staterr__53->Draw("e2same");
   
   Double_t ptj_plus_toterrs_fx3061[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_plus_toterrs_fy3061[5] = {
   3.781269,
   2.471324,
   1.346271,
   0.6736161,
   0.1720625};
   Double_t ptj_plus_toterrs_felx3061[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fely3061[5] = {
   0.2880126,
   0.2336951,
   0.09951573,
   0.04524418,
   0.01969193};
   Double_t ptj_plus_toterrs_fehx3061[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fehy3061[5] = {
   0.237181,
   0.1691029,
   0.09861914,
   0.05727119,
   0.01814489};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,ptj_plus_toterrs_fx3061,ptj_plus_toterrs_fy3061,ptj_plus_toterrs_felx3061,ptj_plus_toterrs_fehx3061,ptj_plus_toterrs_fely3061,ptj_plus_toterrs_fehy3061);
   grae->SetName("ptj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_ptj_plus_toterrs3061 = new TH1F("Graph_ptj_plus_toterrs3061","",100,17.325,88.425);
   Graph_ptj_plus_toterrs3061->SetMinimum(0.1371335);
   Graph_ptj_plus_toterrs3061->SetMaximum(4.405058);
   Graph_ptj_plus_toterrs3061->SetDirectory(0);
   Graph_ptj_plus_toterrs3061->SetStats(0);
   Graph_ptj_plus_toterrs3061->SetLineWidth(2);
   Graph_ptj_plus_toterrs3061->SetMarkerStyle(0);
   Graph_ptj_plus_toterrs3061->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_ptj_plus_toterrs3061->GetXaxis()->SetNdivisions(4);
   Graph_ptj_plus_toterrs3061->GetXaxis()->SetLabelFont(132);
   Graph_ptj_plus_toterrs3061->GetXaxis()->SetLabelOffset(0.02);
   Graph_ptj_plus_toterrs3061->GetXaxis()->SetLabelSize(0.05);
   Graph_ptj_plus_toterrs3061->GetXaxis()->SetTitleSize(0.06);
   Graph_ptj_plus_toterrs3061->GetXaxis()->SetTitleFont(132);
   Graph_ptj_plus_toterrs3061->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_ptj_plus_toterrs3061->GetYaxis()->SetLabelFont(132);
   Graph_ptj_plus_toterrs3061->GetYaxis()->SetLabelSize(0.05);
   Graph_ptj_plus_toterrs3061->GetYaxis()->SetTitleSize(0.06);
   Graph_ptj_plus_toterrs3061->GetYaxis()->SetTitleFont(132);
   Graph_ptj_plus_toterrs3061->GetZaxis()->SetLabelFont(132);
   Graph_ptj_plus_toterrs3061->GetZaxis()->SetLabelSize(0.05);
   Graph_ptj_plus_toterrs3061->GetZaxis()->SetTitleSize(0.06);
   Graph_ptj_plus_toterrs3061->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ptj_plus_toterrs3061);
   
   grae->Draw("p1p");
   
   Double_t _fx3062[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3062[5] = {
   3.781269,
   2.471324,
   1.346271,
   0.6736161,
   0.1720625};
   Double_t _felx3062[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3062[5] = {
   0.190572,
   0.1353315,
   0.0746666,
   0.03416157,
   0.01098946};
   Double_t _fehx3062[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3062[5] = {
   0.1784855,
   0.1300753,
   0.07322493,
   0.03857584,
   0.01318213};
   grae = new TGraphAsymmErrors(5,_fx3062,_fy3062,_felx3062,_fehx3062,_fely3062,_fehy3062);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3062 = new TH1F("Graph_Graph3062","",100,17.325,88.425);
   Graph_Graph3062->SetMinimum(0.1449657);
   Graph_Graph3062->SetMaximum(4.339622);
   Graph_Graph3062->SetDirectory(0);
   Graph_Graph3062->SetStats(0);
   Graph_Graph3062->SetLineWidth(2);
   Graph_Graph3062->SetMarkerStyle(0);
   Graph_Graph3062->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_Graph3062->GetXaxis()->SetNdivisions(4);
   Graph_Graph3062->GetXaxis()->SetLabelFont(132);
   Graph_Graph3062->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3062->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3062->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3062->GetXaxis()->SetTitleFont(132);
   Graph_Graph3062->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph3062->GetYaxis()->SetLabelFont(132);
   Graph_Graph3062->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3062->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3062->GetYaxis()->SetTitleFont(132);
   Graph_Graph3062->GetZaxis()->SetLabelFont(132);
   Graph_Graph3062->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3062->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3062->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3062);
   
   grae->Draw("p1p");
   
   Double_t ptj_plus_toterrs_fx3063[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_plus_toterrs_fy3063[5] = {
   3.747404,
   2.382393,
   1.378484,
   0.718633,
   0.1890381};
   Double_t ptj_plus_toterrs_felx3063[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fely3063[5] = {
   0.2766023,
   0.1785285,
   0.1117659,
   0.05911753,
   0.01596438};
   Double_t ptj_plus_toterrs_fehx3063[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_plus_toterrs_fehy3063[5] = {
   0.2834241,
   0.1899127,
   0.1152294,
   0.06511091,
   0.01862706};
   grae = new TGraphAsymmErrors(5,ptj_plus_toterrs_fx3063,ptj_plus_toterrs_fy3063,ptj_plus_toterrs_felx3063,ptj_plus_toterrs_fehx3063,ptj_plus_toterrs_fely3063,ptj_plus_toterrs_fehy3063);
   grae->SetName("ptj_plus_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ptj_plus_toterrs3063 = new TH1F("Graph_ptj_plus_toterrs3063","",100,17.175,72.075);
   Graph_ptj_plus_toterrs3063->SetMinimum(0.1557663);
   Graph_ptj_plus_toterrs3063->SetMaximum(4.416604);
   Graph_ptj_plus_toterrs3063->SetDirectory(0);
   Graph_ptj_plus_toterrs3063->SetStats(0);
   Graph_ptj_plus_toterrs3063->SetLineWidth(2);
   Graph_ptj_plus_toterrs3063->SetMarkerStyle(0);
   Graph_ptj_plus_toterrs3063->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_ptj_plus_toterrs3063->GetXaxis()->SetNdivisions(4);
   Graph_ptj_plus_toterrs3063->GetXaxis()->SetLabelFont(132);
   Graph_ptj_plus_toterrs3063->GetXaxis()->SetLabelOffset(0.02);
   Graph_ptj_plus_toterrs3063->GetXaxis()->SetLabelSize(0.05);
   Graph_ptj_plus_toterrs3063->GetXaxis()->SetTitleSize(0.06);
   Graph_ptj_plus_toterrs3063->GetXaxis()->SetTitleFont(132);
   Graph_ptj_plus_toterrs3063->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_ptj_plus_toterrs3063->GetYaxis()->SetLabelFont(132);
   Graph_ptj_plus_toterrs3063->GetYaxis()->SetLabelSize(0.05);
   Graph_ptj_plus_toterrs3063->GetYaxis()->SetTitleSize(0.06);
   Graph_ptj_plus_toterrs3063->GetYaxis()->SetTitleFont(132);
   Graph_ptj_plus_toterrs3063->GetZaxis()->SetLabelFont(132);
   Graph_ptj_plus_toterrs3063->GetZaxis()->SetLabelSize(0.05);
   Graph_ptj_plus_toterrs3063->GetZaxis()->SetTitleSize(0.06);
   Graph_ptj_plus_toterrs3063->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ptj_plus_toterrs3063);
   
   grae->Draw("p1p");
   
   Double_t _fx3064[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3064[5] = {
   3.747404,
   2.382393,
   1.378484,
   0.718633,
   0.1890381};
   Double_t _felx3064[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3064[5] = {
   0.2195713,
   0.1431244,
   0.08659163,
   0.04658484,
   0.01299852};
   Double_t _fehx3064[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3064[5] = {
   0.2285816,
   0.1531721,
   0.09393196,
   0.05202641,
   0.01532503};
   grae = new TGraphAsymmErrors(5,_fx3064,_fy3064,_felx3064,_fehx3064,_fely3064,_fehy3064);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3064 = new TH1F("Graph_Graph3064","",100,17.175,72.075);
   Graph_Graph3064->SetMinimum(0.1584356);
   Graph_Graph3064->SetMaximum(4.355981);
   Graph_Graph3064->SetDirectory(0);
   Graph_Graph3064->SetStats(0);
   Graph_Graph3064->SetLineWidth(2);
   Graph_Graph3064->SetMarkerStyle(0);
   Graph_Graph3064->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_Graph3064->GetXaxis()->SetNdivisions(4);
   Graph_Graph3064->GetXaxis()->SetLabelFont(132);
   Graph_Graph3064->GetXaxis()->SetLabelOffset(0.02);
   Graph_Graph3064->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3064->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3064->GetXaxis()->SetTitleFont(132);
   Graph_Graph3064->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph3064->GetYaxis()->SetLabelFont(132);
   Graph_Graph3064->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3064->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3064->GetYaxis()->SetTitleFont(132);
   Graph_Graph3064->GetZaxis()->SetLabelFont(132);
   Graph_Graph3064->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3064->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3064->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3064);
   
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
   Double_t xAxis42[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wp_ptj_toterr_copy__54 = new TH1F("wp_ptj_toterr_copy__54","wp_ptj",5, xAxis42);
   wp_ptj_toterr_copy__54->SetBinContent(1,3.450959);
   wp_ptj_toterr_copy__54->SetBinContent(2,2.256658);
   wp_ptj_toterr_copy__54->SetBinContent(3,1.266894);
   wp_ptj_toterr_copy__54->SetBinContent(4,0.667355);
   wp_ptj_toterr_copy__54->SetBinContent(5,0.1635365);
   wp_ptj_toterr_copy__54->SetBinContent(6,8.176826);
   wp_ptj_toterr_copy__54->SetBinError(1,0.2914732);
   wp_ptj_toterr_copy__54->SetBinError(2,0.2298212);
   wp_ptj_toterr_copy__54->SetBinError(3,0.117779);
   wp_ptj_toterr_copy__54->SetBinError(4,0.07112221);
   wp_ptj_toterr_copy__54->SetBinError(5,0.02028571);
   wp_ptj_toterr_copy__54->SetBinError(6,1.014286);
   wp_ptj_toterr_copy__54->SetEntries(12);
   wp_ptj_toterr_copy__54->SetDirectory(0);
   wp_ptj_toterr_copy__54->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__54->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__54->SetLineColor(ci);
   wp_ptj_toterr_copy__54->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wp_ptj_toterr_copy__54->SetMarkerColor(ci);
   wp_ptj_toterr_copy__54->SetMarkerStyle(0);
   wp_ptj_toterr_copy__54->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wp_ptj_toterr_copy__54->GetXaxis()->SetNdivisions(4);
   wp_ptj_toterr_copy__54->GetXaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__54->GetXaxis()->SetLabelOffset(0.02);
   wp_ptj_toterr_copy__54->GetXaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__54->GetXaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__54->GetXaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__54->GetYaxis()->SetTitle("d#sigma(#it{Wj})/d#it{p}_{T}^{jet} [pb/GeV]");
   wp_ptj_toterr_copy__54->GetYaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__54->GetYaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__54->GetYaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__54->GetYaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__54->GetZaxis()->SetLabelFont(132);
   wp_ptj_toterr_copy__54->GetZaxis()->SetLabelSize(0.05);
   wp_ptj_toterr_copy__54->GetZaxis()->SetTitleSize(0.06);
   wp_ptj_toterr_copy__54->GetZaxis()->SetTitleFont(132);
   wp_ptj_toterr_copy__54->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
