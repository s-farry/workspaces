void wj_ratio_ptj_8TeV()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Thu Apr 28 10:19:36 2016) by ROOT version6.04/10
   TCanvas *default_Canvas = new TCanvas("default_Canvas", "defaultCanvas",0,0,800,800);
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
  
// ------------>Primitives in pad: bottomPad
   TPad *bottomPad = new TPad("bottomPad", "bottomPad",0.005,0.05,0.995,0.995);
   bottomPad->Draw();
   bottomPad->cd();
   bottomPad->Range(0,0,1,1);
   bottomPad->SetFillColor(0);
   bottomPad->SetFillStyle(4000);
   bottomPad->SetBorderMode(0);
   bottomPad->SetBorderSize(2);
   bottomPad->SetTickx(1);
   bottomPad->SetTicky(1);
   bottomPad->SetLeftMargin(0.14);
   bottomPad->SetRightMargin(0.05);
   bottomPad->SetTopMargin(0.05);
   bottomPad->SetBottomMargin(0.16);
   bottomPad->SetFrameLineWidth(2);
   bottomPad->SetFrameBorderMode(0);
   bottomPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(6.172839,-2.379839,104.9383,4.862097);
   upperPad->SetFillColor(0);
   upperPad->SetFillStyle(4000);
   upperPad->SetBorderMode(0);
   upperPad->SetBorderSize(2);
   upperPad->SetTickx(1);
   upperPad->SetTicky(1);
   upperPad->SetLeftMargin(0.14);
   upperPad->SetRightMargin(0.05);
   upperPad->SetTopMargin(0.05);
   upperPad->SetBottomMargin(0.33);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   Double_t xAxis184[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *w_r_ptj_toterr__214 = new TH1F("w_r_ptj_toterr__214","w_ptj",5, xAxis184);
   w_r_ptj_toterr__214->SetBinContent(1,1.596652);
   w_r_ptj_toterr__214->SetBinContent(2,1.703834);
   w_r_ptj_toterr__214->SetBinContent(3,1.701042);
   w_r_ptj_toterr__214->SetBinContent(4,1.727608);
   w_r_ptj_toterr__214->SetBinContent(5,2.062401);
   w_r_ptj_toterr__214->SetBinContent(6,2.062401);
   w_r_ptj_toterr__214->SetBinError(1,0.05958778);
   w_r_ptj_toterr__214->SetBinError(2,0.06989999);
   w_r_ptj_toterr__214->SetBinError(3,0.06665453);
   w_r_ptj_toterr__214->SetBinError(4,0.09208622);
   w_r_ptj_toterr__214->SetBinError(5,0.1403675);
   w_r_ptj_toterr__214->SetBinError(6,0.1403675);
   w_r_ptj_toterr__214->SetMinimum(0.01);
   w_r_ptj_toterr__214->SetMaximum(4.5);
   w_r_ptj_toterr__214->SetEntries(7);
   w_r_ptj_toterr__214->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   w_r_ptj_toterr__214->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_r_ptj_toterr__214->SetLineColor(ci);
   w_r_ptj_toterr__214->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_r_ptj_toterr__214->SetMarkerColor(ci);
   w_r_ptj_toterr__214->SetMarkerStyle(0);
   w_r_ptj_toterr__214->GetXaxis()->SetRange(1,5);
   w_r_ptj_toterr__214->GetXaxis()->SetNdivisions(4);
   w_r_ptj_toterr__214->GetXaxis()->SetLabelFont(132);
   w_r_ptj_toterr__214->GetXaxis()->SetLabelOffset(999);
   w_r_ptj_toterr__214->GetXaxis()->SetLabelSize(0);
   w_r_ptj_toterr__214->GetXaxis()->SetTitleSize(0.06);
   w_r_ptj_toterr__214->GetXaxis()->SetTitleFont(132);
   w_r_ptj_toterr__214->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_ptj_toterr__214->GetYaxis()->SetLabelFont(132);
   w_r_ptj_toterr__214->GetYaxis()->SetLabelSize(0.05);
   w_r_ptj_toterr__214->GetYaxis()->SetTitleSize(0.06);
   w_r_ptj_toterr__214->GetYaxis()->SetTitleFont(132);
   w_r_ptj_toterr__214->GetZaxis()->SetLabelFont(132);
   w_r_ptj_toterr__214->GetZaxis()->SetLabelSize(0.05);
   w_r_ptj_toterr__214->GetZaxis()->SetTitleSize(0.06);
   w_r_ptj_toterr__214->GetZaxis()->SetTitleFont(132);
   w_r_ptj_toterr__214->Draw("e2");
   Double_t xAxis185[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *w_r_ptj_staterr__215 = new TH1F("w_r_ptj_staterr__215","w_ptj",5, xAxis185);
   w_r_ptj_staterr__215->SetBinContent(1,1.596652);
   w_r_ptj_staterr__215->SetBinContent(2,1.703834);
   w_r_ptj_staterr__215->SetBinContent(3,1.701042);
   w_r_ptj_staterr__215->SetBinContent(4,1.727608);
   w_r_ptj_staterr__215->SetBinContent(5,2.062401);
   w_r_ptj_staterr__215->SetBinContent(6,2.062401);
   w_r_ptj_staterr__215->SetBinError(1,0.01864921);
   w_r_ptj_staterr__215->SetBinError(2,0.02509893);
   w_r_ptj_staterr__215->SetBinError(3,0.02358865);
   w_r_ptj_staterr__215->SetBinError(4,0.03388354);
   w_r_ptj_staterr__215->SetBinError(5,0.03879225);
   w_r_ptj_staterr__215->SetBinError(6,0.03879225);
   w_r_ptj_staterr__215->SetMinimum(0.01);
   w_r_ptj_staterr__215->SetMaximum(4.5);
   w_r_ptj_staterr__215->SetEntries(7);
   w_r_ptj_staterr__215->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   w_r_ptj_staterr__215->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   w_r_ptj_staterr__215->SetLineColor(ci);
   w_r_ptj_staterr__215->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   w_r_ptj_staterr__215->SetMarkerColor(ci);
   w_r_ptj_staterr__215->SetMarkerStyle(0);
   w_r_ptj_staterr__215->GetXaxis()->SetRange(1,5);
   w_r_ptj_staterr__215->GetXaxis()->SetNdivisions(4);
   w_r_ptj_staterr__215->GetXaxis()->SetLabelFont(132);
   w_r_ptj_staterr__215->GetXaxis()->SetLabelOffset(999);
   w_r_ptj_staterr__215->GetXaxis()->SetLabelSize(0);
   w_r_ptj_staterr__215->GetXaxis()->SetTitleSize(0.06);
   w_r_ptj_staterr__215->GetXaxis()->SetTitleFont(132);
   w_r_ptj_staterr__215->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_ptj_staterr__215->GetYaxis()->SetLabelFont(132);
   w_r_ptj_staterr__215->GetYaxis()->SetLabelSize(0.05);
   w_r_ptj_staterr__215->GetYaxis()->SetTitleSize(0.06);
   w_r_ptj_staterr__215->GetYaxis()->SetTitleFont(132);
   w_r_ptj_staterr__215->GetZaxis()->SetLabelFont(132);
   w_r_ptj_staterr__215->GetZaxis()->SetLabelSize(0.05);
   w_r_ptj_staterr__215->GetZaxis()->SetTitleSize(0.06);
   w_r_ptj_staterr__215->GetZaxis()->SetTitleFont(132);
   w_r_ptj_staterr__215->Draw("e2same");
   
   Double_t ratio_ptj_toterrs_fx3270[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ratio_ptj_toterrs_fy3270[5] = {
   1.475391,
   1.674126,
   1.595838,
   1.660017,
   1.743303};
   Double_t ratio_ptj_toterrs_felx3270[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ratio_ptj_toterrs_fely3270[5] = {
   0.04494813,
   0.1433834,
   0.07206887,
   0.06879118,
   0.1034802};
   Double_t ratio_ptj_toterrs_fehx3270[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ratio_ptj_toterrs_fehy3270[5] = {
   0.06885362,
   0.0360066,
   0.09633159,
   0.07987301,
   0.1415384};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,ratio_ptj_toterrs_fx3270,ratio_ptj_toterrs_fy3270,ratio_ptj_toterrs_felx3270,ratio_ptj_toterrs_fehx3270,ratio_ptj_toterrs_fely3270,ratio_ptj_toterrs_fehy3270);
   grae->SetName("ratio_ptj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_ratio_ptj_toterrs3270 = new TH1F("Graph_ratio_ptj_toterrs3270","",100,17.325,88.425);
   Graph_ratio_ptj_toterrs3270->SetMinimum(0.01);
   Graph_ratio_ptj_toterrs3270->SetMaximum(4.5);
   Graph_ratio_ptj_toterrs3270->SetDirectory(0);
   Graph_ratio_ptj_toterrs3270->SetStats(0);
   Graph_ratio_ptj_toterrs3270->SetLineWidth(2);
   Graph_ratio_ptj_toterrs3270->SetMarkerStyle(0);
   Graph_ratio_ptj_toterrs3270->GetXaxis()->SetRange(1,100);
   Graph_ratio_ptj_toterrs3270->GetXaxis()->SetNdivisions(4);
   Graph_ratio_ptj_toterrs3270->GetXaxis()->SetLabelFont(132);
   Graph_ratio_ptj_toterrs3270->GetXaxis()->SetLabelOffset(999);
   Graph_ratio_ptj_toterrs3270->GetXaxis()->SetLabelSize(0);
   Graph_ratio_ptj_toterrs3270->GetXaxis()->SetTitleSize(0.06);
   Graph_ratio_ptj_toterrs3270->GetXaxis()->SetTitleFont(132);
   Graph_ratio_ptj_toterrs3270->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_ratio_ptj_toterrs3270->GetYaxis()->SetLabelFont(132);
   Graph_ratio_ptj_toterrs3270->GetYaxis()->SetLabelSize(0.05);
   Graph_ratio_ptj_toterrs3270->GetYaxis()->SetTitleSize(0.06);
   Graph_ratio_ptj_toterrs3270->GetYaxis()->SetTitleFont(132);
   Graph_ratio_ptj_toterrs3270->GetZaxis()->SetLabelFont(132);
   Graph_ratio_ptj_toterrs3270->GetZaxis()->SetLabelSize(0.05);
   Graph_ratio_ptj_toterrs3270->GetZaxis()->SetTitleSize(0.06);
   Graph_ratio_ptj_toterrs3270->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ratio_ptj_toterrs3270);
   
   grae->Draw("p1p");
   
   Double_t _fx3271[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3271[5] = {
   1.475391,
   1.674126,
   1.595838,
   1.660017,
   1.743303};
   Double_t _felx3271[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3271[5] = {
   0.01993883,
   0.00298667,
   0.03746188,
   0.01415777,
   0.02520609};
   Double_t _fehx3271[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3271[5] = {
   0.02119267,
   0.004976869,
   0.0338192,
   0.01672947,
   0.02163887};
   grae = new TGraphAsymmErrors(5,_fx3271,_fy3271,_felx3271,_fehx3271,_fely3271,_fehy3271);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3271 = new TH1F("Graph_Graph3271","",100,17.325,88.425);
   Graph_Graph3271->SetMinimum(0.01);
   Graph_Graph3271->SetMaximum(4.5);
   Graph_Graph3271->SetDirectory(0);
   Graph_Graph3271->SetStats(0);
   Graph_Graph3271->SetLineWidth(2);
   Graph_Graph3271->SetMarkerStyle(0);
   Graph_Graph3271->GetXaxis()->SetRange(1,100);
   Graph_Graph3271->GetXaxis()->SetNdivisions(4);
   Graph_Graph3271->GetXaxis()->SetLabelFont(132);
   Graph_Graph3271->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3271->GetXaxis()->SetLabelSize(0);
   Graph_Graph3271->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3271->GetXaxis()->SetTitleFont(132);
   Graph_Graph3271->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3271->GetYaxis()->SetLabelFont(132);
   Graph_Graph3271->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3271->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3271->GetYaxis()->SetTitleFont(132);
   Graph_Graph3271->GetZaxis()->SetLabelFont(132);
   Graph_Graph3271->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3271->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3271->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3271);
   
   grae->Draw("p1p");
   
   Double_t ratio_ptj_toterrs_fx3272[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ratio_ptj_toterrs_fy3272[5] = {
   1.545173,
   1.579955,
   1.661478,
   1.705818,
   1.808957};
   Double_t ratio_ptj_toterrs_felx3272[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ratio_ptj_toterrs_fely3272[5] = {
   0.026739,
   0.02954284,
   0.05290237,
   0.0481648,
   0.06367413};
   Double_t ratio_ptj_toterrs_fehx3272[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ratio_ptj_toterrs_fehy3272[5] = {
   0.02770457,
   0.03458678,
   0.03709619,
   0.05007362,
   0.06841838};
   grae = new TGraphAsymmErrors(5,ratio_ptj_toterrs_fx3272,ratio_ptj_toterrs_fy3272,ratio_ptj_toterrs_felx3272,ratio_ptj_toterrs_fehx3272,ratio_ptj_toterrs_fely3272,ratio_ptj_toterrs_fehy3272);
   grae->SetName("ratio_ptj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ratio_ptj_toterrs3272 = new TH1F("Graph_ratio_ptj_toterrs3272","",100,17.175,72.075);
   Graph_ratio_ptj_toterrs3272->SetMinimum(0.01);
   Graph_ratio_ptj_toterrs3272->SetMaximum(4.5);
   Graph_ratio_ptj_toterrs3272->SetDirectory(0);
   Graph_ratio_ptj_toterrs3272->SetStats(0);
   Graph_ratio_ptj_toterrs3272->SetLineWidth(2);
   Graph_ratio_ptj_toterrs3272->SetMarkerStyle(0);
   Graph_ratio_ptj_toterrs3272->GetXaxis()->SetRange(1,100);
   Graph_ratio_ptj_toterrs3272->GetXaxis()->SetNdivisions(4);
   Graph_ratio_ptj_toterrs3272->GetXaxis()->SetLabelFont(132);
   Graph_ratio_ptj_toterrs3272->GetXaxis()->SetLabelOffset(999);
   Graph_ratio_ptj_toterrs3272->GetXaxis()->SetLabelSize(0);
   Graph_ratio_ptj_toterrs3272->GetXaxis()->SetTitleSize(0.06);
   Graph_ratio_ptj_toterrs3272->GetXaxis()->SetTitleFont(132);
   Graph_ratio_ptj_toterrs3272->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_ratio_ptj_toterrs3272->GetYaxis()->SetLabelFont(132);
   Graph_ratio_ptj_toterrs3272->GetYaxis()->SetLabelSize(0.05);
   Graph_ratio_ptj_toterrs3272->GetYaxis()->SetTitleSize(0.06);
   Graph_ratio_ptj_toterrs3272->GetYaxis()->SetTitleFont(132);
   Graph_ratio_ptj_toterrs3272->GetZaxis()->SetLabelFont(132);
   Graph_ratio_ptj_toterrs3272->GetZaxis()->SetLabelSize(0.05);
   Graph_ratio_ptj_toterrs3272->GetZaxis()->SetTitleSize(0.06);
   Graph_ratio_ptj_toterrs3272->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ratio_ptj_toterrs3272);
   
   grae->Draw("p1p");
   
   Double_t _fx3273[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3273[5] = {
   1.545173,
   1.579955,
   1.661478,
   1.705818,
   1.808957};
   Double_t _felx3273[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3273[5] = {
   0.002583265,
   0.002978563,
   0.003439665,
   0.001578927,
   0.005151153};
   Double_t _fehx3273[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3273[5] = {
   0.004328132,
   0.004105687,
   0.004673243,
   0.002981663,
   0.008617878};
   grae = new TGraphAsymmErrors(5,_fx3273,_fy3273,_felx3273,_fehx3273,_fely3273,_fehy3273);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3273 = new TH1F("Graph_Graph3273","",100,17.175,72.075);
   Graph_Graph3273->SetMinimum(0.01);
   Graph_Graph3273->SetMaximum(4.5);
   Graph_Graph3273->SetDirectory(0);
   Graph_Graph3273->SetStats(0);
   Graph_Graph3273->SetLineWidth(2);
   Graph_Graph3273->SetMarkerStyle(0);
   Graph_Graph3273->GetXaxis()->SetRange(1,100);
   Graph_Graph3273->GetXaxis()->SetNdivisions(4);
   Graph_Graph3273->GetXaxis()->SetLabelFont(132);
   Graph_Graph3273->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3273->GetXaxis()->SetLabelSize(0);
   Graph_Graph3273->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3273->GetXaxis()->SetTitleFont(132);
   Graph_Graph3273->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3273->GetYaxis()->SetLabelFont(132);
   Graph_Graph3273->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3273->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3273->GetYaxis()->SetTitleFont(132);
   Graph_Graph3273->GetZaxis()->SetLabelFont(132);
   Graph_Graph3273->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3273->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3273->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3273);
   
   grae->Draw("p1p");
   
   TPaveText *pt = new TPaveText(0.5,0.85,0.85,0.94,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(132);
   TText *AText = pt->AddText("LHCb, #sqrt{s} = 8 TeV");
   pt->Draw();
   
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
   Double_t xAxis186[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *w_r_ptj_toterr_copy__216 = new TH1F("w_r_ptj_toterr_copy__216","w_ptj",5, xAxis186);
   w_r_ptj_toterr_copy__216->SetBinContent(1,1.596652);
   w_r_ptj_toterr_copy__216->SetBinContent(2,1.703834);
   w_r_ptj_toterr_copy__216->SetBinContent(3,1.701042);
   w_r_ptj_toterr_copy__216->SetBinContent(4,1.727608);
   w_r_ptj_toterr_copy__216->SetBinContent(5,2.062401);
   w_r_ptj_toterr_copy__216->SetBinContent(6,2.062401);
   w_r_ptj_toterr_copy__216->SetBinError(1,0.05958778);
   w_r_ptj_toterr_copy__216->SetBinError(2,0.06989999);
   w_r_ptj_toterr_copy__216->SetBinError(3,0.06665453);
   w_r_ptj_toterr_copy__216->SetBinError(4,0.09208622);
   w_r_ptj_toterr_copy__216->SetBinError(5,0.1403675);
   w_r_ptj_toterr_copy__216->SetBinError(6,0.1403675);
   w_r_ptj_toterr_copy__216->SetMinimum(0.01);
   w_r_ptj_toterr_copy__216->SetMaximum(4.5);
   w_r_ptj_toterr_copy__216->SetEntries(7);
   w_r_ptj_toterr_copy__216->SetDirectory(0);
   w_r_ptj_toterr_copy__216->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   w_r_ptj_toterr_copy__216->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_r_ptj_toterr_copy__216->SetLineColor(ci);
   w_r_ptj_toterr_copy__216->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_r_ptj_toterr_copy__216->SetMarkerColor(ci);
   w_r_ptj_toterr_copy__216->SetMarkerStyle(0);
   w_r_ptj_toterr_copy__216->GetXaxis()->SetRange(1,5);
   w_r_ptj_toterr_copy__216->GetXaxis()->SetNdivisions(4);
   w_r_ptj_toterr_copy__216->GetXaxis()->SetLabelFont(132);
   w_r_ptj_toterr_copy__216->GetXaxis()->SetLabelOffset(999);
   w_r_ptj_toterr_copy__216->GetXaxis()->SetLabelSize(0);
   w_r_ptj_toterr_copy__216->GetXaxis()->SetTitleSize(0.06);
   w_r_ptj_toterr_copy__216->GetXaxis()->SetTitleFont(132);
   w_r_ptj_toterr_copy__216->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_ptj_toterr_copy__216->GetYaxis()->SetLabelFont(132);
   w_r_ptj_toterr_copy__216->GetYaxis()->SetLabelSize(0.05);
   w_r_ptj_toterr_copy__216->GetYaxis()->SetTitleSize(0.06);
   w_r_ptj_toterr_copy__216->GetYaxis()->SetTitleFont(132);
   w_r_ptj_toterr_copy__216->GetZaxis()->SetLabelFont(132);
   w_r_ptj_toterr_copy__216->GetZaxis()->SetLabelSize(0.05);
   w_r_ptj_toterr_copy__216->GetZaxis()->SetTitleSize(0.06);
   w_r_ptj_toterr_copy__216->GetZaxis()->SetTitleFont(132);
   w_r_ptj_toterr_copy__216->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(6.172839,0.2935897,104.9383,3.267949);
   lowerPad->SetFillColor(0);
   lowerPad->SetFillStyle(4000);
   lowerPad->SetBorderMode(0);
   lowerPad->SetBorderSize(2);
   lowerPad->SetTickx(1);
   lowerPad->SetTicky(1);
   lowerPad->SetLeftMargin(0.14);
   lowerPad->SetRightMargin(0.05);
   lowerPad->SetTopMargin(0.665);
   lowerPad->SetBottomMargin(0.14);
   lowerPad->SetFrameLineWidth(2);
   lowerPad->SetFrameBorderMode(0);
   lowerPad->SetFrameLineWidth(2);
   lowerPad->SetFrameBorderMode(0);
   Double_t xAxis187[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217 = new TH1F("wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217","w_ptj",5, xAxis187);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinContent(1,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinContent(2,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinContent(3,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinContent(4,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinContent(5,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinContent(6,2.062401);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinError(1,0.03732045);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinError(2,0.04102512);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinError(3,0.03918453);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinError(4,0.05330272);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinError(5,0.06806025);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetBinError(6,0.1403675);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetMinimum(0.71);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetMaximum(1.29);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetEntries(12);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetLineColor(ci);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetMarkerColor(ci);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->SetMarkerStyle(0);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetXaxis()->SetRange(1,5);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetXaxis()->SetNdivisions(4);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetXaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetXaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetYaxis()->SetTitle("Ratio");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetYaxis()->CenterTitle(true);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetYaxis()->SetNdivisions(505);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetYaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetYaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetZaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->GetZaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0__217->Draw("e2");
   Double_t xAxis188[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218 = new TH1F("wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218","w_ptj",5, xAxis188);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinContent(1,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinContent(2,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinContent(3,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinContent(4,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinContent(5,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinContent(6,2.062401);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinError(1,0.0116802);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinError(2,0.01473086);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinError(3,0.01386718);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinError(4,0.01961298);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinError(5,0.01880927);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetBinError(6,0.03879225);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetMinimum(0.71);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetMaximum(1.29);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetEntries(12);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetLineColor(ci);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetMarkerColor(ci);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->SetMarkerStyle(0);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetXaxis()->SetRange(1,5);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetXaxis()->SetNdivisions(4);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetXaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetXaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetYaxis()->SetTitle("Ratio");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetYaxis()->CenterTitle(true);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetYaxis()->SetNdivisions(505);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetYaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetYaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetZaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->GetZaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp1__218->Draw("e2same");
   
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fx3274[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fy3274[5] = {
   0.9240526,
   0.982564,
   0.9381533,
   0.9608759,
   0.8452782};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_felx3274[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fely3274[5] = {
   0.02815149,
   0.08415336,
   0.04236748,
   0.03981874,
   0.0501746};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fehx3274[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fehy3274[5] = {
   0.04312374,
   0.02113269,
   0.05663093,
   0.04623329,
   0.06862796};
   grae = new TGraphAsymmErrors(5,wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fx3274,wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fy3274,wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_felx3274,wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fehx3274,wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fely3274,wj_ratio_ptj_8TeV_400_1001_0ratiocomp2_fehy3274);
   grae->SetName("wj_ratio_ptj_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274 = new TH1F("Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274","",100,17.325,88.425);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->SetMinimum(0.71);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->SetMaximum(1.29);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->SetDirectory(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->SetStats(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->SetLineWidth(2);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->SetMarkerStyle(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetXaxis()->SetRange(1,100);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp23274);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fx3275[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fy3275[5] = {
   0.9240526,
   0.982564,
   0.9381533,
   0.9608759,
   0.8452782};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_felx3275[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fely3275[5] = {
   0.0124879,
   0.001752911,
   0.0220229,
   0.008195013,
   0.01222172};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fehx3275[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fehy3275[5] = {
   0.01327319,
   0.002920982,
   0.01988146,
   0.009683604,
   0.01049208};
   grae = new TGraphAsymmErrors(5,wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fx3275,wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fy3275,wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_felx3275,wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fehx3275,wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fely3275,wj_ratio_ptj_8TeV_400_1001_0ratiocomp3_fehy3275);
   grae->SetName("wj_ratio_ptj_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275 = new TH1F("Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275","",100,17.325,88.425);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->SetMinimum(0.71);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->SetMaximum(1.29);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->SetDirectory(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->SetStats(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->SetLineWidth(2);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->SetMarkerStyle(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetXaxis()->SetRange(1,100);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp33275);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fx3276[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fy3276[5] = {
   0.9677581,
   0.9272943,
   0.9767414,
   0.9873872,
   0.877112};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_felx3276[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fely3276[5] = {
   0.01674691,
   0.01733904,
   0.03109998,
   0.02787947,
   0.03087378};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fehx3276[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fehy3276[5] = {
   0.01735166,
   0.02029938,
   0.02180792,
   0.02898436,
   0.03317414};
   grae = new TGraphAsymmErrors(5,wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fx3276,wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fy3276,wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_felx3276,wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fehx3276,wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fely3276,wj_ratio_ptj_8TeV_400_1001_0ratiocomp4_fehy3276);
   grae->SetName("wj_ratio_ptj_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276 = new TH1F("Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276","",100,17.175,72.075);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->SetMinimum(0.71);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->SetMaximum(1.29);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->SetDirectory(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->SetStats(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->SetLineWidth(2);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->SetMarkerStyle(0);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetXaxis()->SetRange(1,100);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_ptj_8TeV_400_1001_0ratiocomp43276);
   
   grae->Draw("p1");
   Double_t xAxis189[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219 = new TH1F("wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219","w_ptj",5, xAxis189);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinContent(1,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinContent(2,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinContent(3,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinContent(4,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinContent(5,1);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinContent(6,2.062401);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinError(1,0.03732045);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinError(2,0.04102512);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinError(3,0.03918453);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinError(4,0.05330272);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinError(5,0.06806025);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetBinError(6,0.1403675);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetMinimum(0.71);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetMaximum(1.29);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetEntries(12);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetDirectory(0);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetLineColor(ci);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetMarkerColor(ci);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->SetMarkerStyle(0);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetXaxis()->SetRange(1,5);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetXaxis()->SetNdivisions(4);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetXaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetXaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetYaxis()->SetTitle("Ratio");
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetYaxis()->CenterTitle(true);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetYaxis()->SetNdivisions(505);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetYaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetYaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetZaxis()->SetLabelFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->GetZaxis()->SetTitleFont(132);
   wj_ratio_ptj_8TeV_400_1001_0ratiocomp0_copy__219->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
