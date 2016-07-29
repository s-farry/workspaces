void zj_yz_8TeV()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Thu Apr 28 10:19:34 2016) by ROOT version6.04/10
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
   upperPad->Range(1.567901,-4.256533,4.654321,8.645081);
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
   Double_t xAxis31[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *z_y_toterr__31 = new TH1F("z_y_toterr__31","z_y",4, xAxis31);
   z_y_toterr__31->SetBinContent(1,2.185837);
   z_y_toterr__31->SetBinContent(2,4.879675);
   z_y_toterr__31->SetBinContent(3,3.628071);
   z_y_toterr__31->SetBinContent(4,0.4349621);
   z_y_toterr__31->SetBinContent(5,0.4349621);
   z_y_toterr__31->SetBinError(1,0.1364841);
   z_y_toterr__31->SetBinError(2,0.2553951);
   z_y_toterr__31->SetBinError(3,0.2095409);
   z_y_toterr__31->SetBinError(4,0.03159313);
   z_y_toterr__31->SetBinError(5,0.03159313);
   z_y_toterr__31->SetMinimum(0.001);
   z_y_toterr__31->SetMaximum(8);
   z_y_toterr__31->SetEntries(9);
   z_y_toterr__31->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   z_y_toterr__31->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr__31->SetLineColor(ci);
   z_y_toterr__31->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr__31->SetMarkerColor(ci);
   z_y_toterr__31->SetMarkerStyle(0);
   z_y_toterr__31->GetXaxis()->SetNdivisions(4);
   z_y_toterr__31->GetXaxis()->SetLabelFont(132);
   z_y_toterr__31->GetXaxis()->SetLabelOffset(999);
   z_y_toterr__31->GetXaxis()->SetLabelSize(0);
   z_y_toterr__31->GetXaxis()->SetTitleSize(0.06);
   z_y_toterr__31->GetXaxis()->SetTitleFont(132);
   z_y_toterr__31->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   z_y_toterr__31->GetYaxis()->SetLabelFont(132);
   z_y_toterr__31->GetYaxis()->SetLabelSize(0.05);
   z_y_toterr__31->GetYaxis()->SetTitleSize(0.06);
   z_y_toterr__31->GetYaxis()->SetTitleOffset(1.3);
   z_y_toterr__31->GetYaxis()->SetTitleFont(132);
   z_y_toterr__31->GetZaxis()->SetLabelFont(132);
   z_y_toterr__31->GetZaxis()->SetLabelSize(0.05);
   z_y_toterr__31->GetZaxis()->SetTitleSize(0.06);
   z_y_toterr__31->GetZaxis()->SetTitleFont(132);
   z_y_toterr__31->Draw("e2");
   Double_t xAxis32[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *z_y_staterr__32 = new TH1F("z_y_staterr__32","z_y",4, xAxis32);
   z_y_staterr__32->SetBinContent(1,2.185837);
   z_y_staterr__32->SetBinContent(2,4.879675);
   z_y_staterr__32->SetBinContent(3,3.628071);
   z_y_staterr__32->SetBinContent(4,0.4349621);
   z_y_staterr__32->SetBinContent(5,0.4349621);
   z_y_staterr__32->SetBinError(1,0.05898224);
   z_y_staterr__32->SetBinError(2,0.08434909);
   z_y_staterr__32->SetBinError(3,0.07099095);
   z_y_staterr__32->SetBinError(4,0.01698204);
   z_y_staterr__32->SetBinError(5,0.01698204);
   z_y_staterr__32->SetMinimum(0.001);
   z_y_staterr__32->SetMaximum(8);
   z_y_staterr__32->SetEntries(9);
   z_y_staterr__32->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   z_y_staterr__32->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   z_y_staterr__32->SetLineColor(ci);
   z_y_staterr__32->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   z_y_staterr__32->SetMarkerColor(ci);
   z_y_staterr__32->SetMarkerStyle(0);
   z_y_staterr__32->GetXaxis()->SetNdivisions(4);
   z_y_staterr__32->GetXaxis()->SetLabelFont(132);
   z_y_staterr__32->GetXaxis()->SetLabelOffset(999);
   z_y_staterr__32->GetXaxis()->SetLabelSize(0);
   z_y_staterr__32->GetXaxis()->SetTitleSize(0.06);
   z_y_staterr__32->GetXaxis()->SetTitleFont(132);
   z_y_staterr__32->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   z_y_staterr__32->GetYaxis()->SetLabelFont(132);
   z_y_staterr__32->GetYaxis()->SetLabelSize(0.05);
   z_y_staterr__32->GetYaxis()->SetTitleSize(0.06);
   z_y_staterr__32->GetYaxis()->SetTitleFont(132);
   z_y_staterr__32->GetZaxis()->SetLabelFont(132);
   z_y_staterr__32->GetZaxis()->SetLabelSize(0.05);
   z_y_staterr__32->GetZaxis()->SetTitleSize(0.06);
   z_y_staterr__32->GetZaxis()->SetTitleFont(132);
   z_y_staterr__32->Draw("e2same");
   
   Double_t yz_toterrs_fx3036[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t yz_toterrs_fy3036[4] = {
   2.22476,
   4.844015,
   3.54881,
   0.4022607};
   Double_t yz_toterrs_felx3036[4] = {
   0,
   0,
   0,
   0};
   Double_t yz_toterrs_fely3036[4] = {
   0.2006029,
   0.356475,
   0.2605432,
   0.06093241};
   Double_t yz_toterrs_fehx3036[4] = {
   0,
   0,
   0,
   0};
   Double_t yz_toterrs_fehy3036[4] = {
   0.1405623,
   0.3214376,
   0.2546509,
   0.04976848};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,yz_toterrs_fx3036,yz_toterrs_fy3036,yz_toterrs_felx3036,yz_toterrs_fehx3036,yz_toterrs_fely3036,yz_toterrs_fehy3036);
   grae->SetName("yz_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_yz_toterrs30293036 = new TH1F("Graph_Graph_yz_toterrs30293036","",100,2.1425,4.3325);
   Graph_Graph_yz_toterrs30293036->SetMinimum(0.001);
   Graph_Graph_yz_toterrs30293036->SetMaximum(8);
   Graph_Graph_yz_toterrs30293036->SetDirectory(0);
   Graph_Graph_yz_toterrs30293036->SetStats(0);
   Graph_Graph_yz_toterrs30293036->SetLineWidth(2);
   Graph_Graph_yz_toterrs30293036->SetMarkerStyle(0);
   Graph_Graph_yz_toterrs30293036->GetXaxis()->SetNdivisions(4);
   Graph_Graph_yz_toterrs30293036->GetXaxis()->SetLabelFont(132);
   Graph_Graph_yz_toterrs30293036->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_yz_toterrs30293036->GetXaxis()->SetLabelSize(0);
   Graph_Graph_yz_toterrs30293036->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_yz_toterrs30293036->GetXaxis()->SetTitleFont(132);
   Graph_Graph_yz_toterrs30293036->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   Graph_Graph_yz_toterrs30293036->GetYaxis()->SetLabelFont(132);
   Graph_Graph_yz_toterrs30293036->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_yz_toterrs30293036->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_yz_toterrs30293036->GetYaxis()->SetTitleFont(132);
   Graph_Graph_yz_toterrs30293036->GetZaxis()->SetLabelFont(132);
   Graph_Graph_yz_toterrs30293036->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_yz_toterrs30293036->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_yz_toterrs30293036->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_yz_toterrs30293036);
   
   grae->Draw("p1p");
   
   Double_t _fx3037[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t _fy3037[4] = {
   2.22476,
   4.844015,
   3.54881,
   0.4022607};
   Double_t _felx3037[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3037[4] = {
   0.1155136,
   0.2531385,
   0.1966617,
   0.02826533};
   Double_t _fehx3037[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3037[4] = {
   0.1111548,
   0.2410007,
   0.1939836,
   0.03140715};
   grae = new TGraphAsymmErrors(4,_fx3037,_fy3037,_felx3037,_fehx3037,_fely3037,_fehy3037);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph30303037 = new TH1F("Graph_Graph_Graph30303037","",100,2.1425,4.3325);
   Graph_Graph_Graph30303037->SetMinimum(0.001);
   Graph_Graph_Graph30303037->SetMaximum(8);
   Graph_Graph_Graph30303037->SetDirectory(0);
   Graph_Graph_Graph30303037->SetStats(0);
   Graph_Graph_Graph30303037->SetLineWidth(2);
   Graph_Graph_Graph30303037->SetMarkerStyle(0);
   Graph_Graph_Graph30303037->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30303037->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30303037->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30303037->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30303037->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30303037->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30303037->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   Graph_Graph_Graph30303037->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30303037->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30303037->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30303037->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30303037->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30303037->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30303037->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30303037->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30303037);
   
   grae->Draw("p1p");
   
   Double_t yz_toterrs_fx3038[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t yz_toterrs_fy3038[4] = {
   2.460021,
   5.444098,
   4.015299,
   0.4541293};
   Double_t yz_toterrs_felx3038[4] = {
   0,
   0,
   0,
   0};
   Double_t yz_toterrs_fely3038[4] = {
   0.1845896,
   0.4251943,
   0.332433,
   0.0610496};
   Double_t yz_toterrs_fehx3038[4] = {
   0,
   0,
   0,
   0};
   Double_t yz_toterrs_fehy3038[4] = {
   0.1961081,
   0.4397508,
   0.3843861,
   0.06742976};
   grae = new TGraphAsymmErrors(4,yz_toterrs_fx3038,yz_toterrs_fy3038,yz_toterrs_felx3038,yz_toterrs_fehx3038,yz_toterrs_fely3038,yz_toterrs_fehy3038);
   grae->SetName("yz_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_yz_toterrs30313038 = new TH1F("Graph_Graph_yz_toterrs30313038","",100,2.0075,4.0175);
   Graph_Graph_yz_toterrs30313038->SetMinimum(0.001);
   Graph_Graph_yz_toterrs30313038->SetMaximum(8);
   Graph_Graph_yz_toterrs30313038->SetDirectory(0);
   Graph_Graph_yz_toterrs30313038->SetStats(0);
   Graph_Graph_yz_toterrs30313038->SetLineWidth(2);
   Graph_Graph_yz_toterrs30313038->SetMarkerStyle(0);
   Graph_Graph_yz_toterrs30313038->GetXaxis()->SetNdivisions(4);
   Graph_Graph_yz_toterrs30313038->GetXaxis()->SetLabelFont(132);
   Graph_Graph_yz_toterrs30313038->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_yz_toterrs30313038->GetXaxis()->SetLabelSize(0);
   Graph_Graph_yz_toterrs30313038->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_yz_toterrs30313038->GetXaxis()->SetTitleFont(132);
   Graph_Graph_yz_toterrs30313038->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   Graph_Graph_yz_toterrs30313038->GetYaxis()->SetLabelFont(132);
   Graph_Graph_yz_toterrs30313038->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_yz_toterrs30313038->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_yz_toterrs30313038->GetYaxis()->SetTitleFont(132);
   Graph_Graph_yz_toterrs30313038->GetZaxis()->SetLabelFont(132);
   Graph_Graph_yz_toterrs30313038->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_yz_toterrs30313038->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_yz_toterrs30313038->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_yz_toterrs30313038);
   
   grae->Draw("p1p");
   
   Double_t _fx3039[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t _fy3039[4] = {
   2.460021,
   5.444098,
   4.015299,
   0.4541293};
   Double_t _felx3039[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3039[4] = {
   0.150059,
   0.3283963,
   0.2580678,
   0.03286934};
   Double_t _fehx3039[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3039[4] = {
   0.1642063,
   0.3603582,
   0.2895746,
   0.03804311};
   grae = new TGraphAsymmErrors(4,_fx3039,_fy3039,_felx3039,_fehx3039,_fely3039,_fehy3039);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30323039 = new TH1F("Graph_Graph_Graph30323039","",100,2.0075,4.0175);
   Graph_Graph_Graph30323039->SetMinimum(0.001);
   Graph_Graph_Graph30323039->SetMaximum(8);
   Graph_Graph_Graph30323039->SetDirectory(0);
   Graph_Graph_Graph30323039->SetStats(0);
   Graph_Graph_Graph30323039->SetLineWidth(2);
   Graph_Graph_Graph30323039->SetMarkerStyle(0);
   Graph_Graph_Graph30323039->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30323039->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30323039->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30323039->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30323039->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30323039->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30323039->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   Graph_Graph_Graph30323039->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30323039->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30323039->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30323039->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30323039->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30323039->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30323039->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30323039->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30323039);
   
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
   
   TPaveText *pt = new TPaveText(0.5,0.85,0.85,0.94,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(132);
   TText *AText = pt->AddText("LHCb, #sqrt{s} = 8 TeV");
   pt->Draw();
   Double_t xAxis33[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *z_y_toterr_copy__33 = new TH1F("z_y_toterr_copy__33","z_y",4, xAxis33);
   z_y_toterr_copy__33->SetBinContent(1,2.185837);
   z_y_toterr_copy__33->SetBinContent(2,4.879675);
   z_y_toterr_copy__33->SetBinContent(3,3.628071);
   z_y_toterr_copy__33->SetBinContent(4,0.4349621);
   z_y_toterr_copy__33->SetBinContent(5,0.4349621);
   z_y_toterr_copy__33->SetBinError(1,0.1364841);
   z_y_toterr_copy__33->SetBinError(2,0.2553951);
   z_y_toterr_copy__33->SetBinError(3,0.2095409);
   z_y_toterr_copy__33->SetBinError(4,0.03159313);
   z_y_toterr_copy__33->SetBinError(5,0.03159313);
   z_y_toterr_copy__33->SetMinimum(0.001);
   z_y_toterr_copy__33->SetMaximum(8);
   z_y_toterr_copy__33->SetEntries(9);
   z_y_toterr_copy__33->SetDirectory(0);
   z_y_toterr_copy__33->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr_copy__33->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr_copy__33->SetLineColor(ci);
   z_y_toterr_copy__33->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr_copy__33->SetMarkerColor(ci);
   z_y_toterr_copy__33->SetMarkerStyle(0);
   z_y_toterr_copy__33->GetXaxis()->SetNdivisions(4);
   z_y_toterr_copy__33->GetXaxis()->SetLabelFont(132);
   z_y_toterr_copy__33->GetXaxis()->SetLabelOffset(999);
   z_y_toterr_copy__33->GetXaxis()->SetLabelSize(0);
   z_y_toterr_copy__33->GetXaxis()->SetTitleSize(0.06);
   z_y_toterr_copy__33->GetXaxis()->SetTitleFont(132);
   z_y_toterr_copy__33->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   z_y_toterr_copy__33->GetYaxis()->SetLabelFont(132);
   z_y_toterr_copy__33->GetYaxis()->SetLabelSize(0.05);
   z_y_toterr_copy__33->GetYaxis()->SetTitleSize(0.06);
   z_y_toterr_copy__33->GetYaxis()->SetTitleOffset(1.3);
   z_y_toterr_copy__33->GetYaxis()->SetTitleFont(132);
   z_y_toterr_copy__33->GetZaxis()->SetLabelFont(132);
   z_y_toterr_copy__33->GetZaxis()->SetLabelSize(0.05);
   z_y_toterr_copy__33->GetZaxis()->SetTitleSize(0.06);
   z_y_toterr_copy__33->GetZaxis()->SetTitleFont(132);
   z_y_toterr_copy__33->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.567901,-0.1935898,4.654321,4.832052);
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
   Double_t xAxis34[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *zj_yz_8TeV_400_1001_0ratiocomp0__34 = new TH1F("zj_yz_8TeV_400_1001_0ratiocomp0__34","z_y",4, xAxis34);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinContent(1,1);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinContent(2,1);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinContent(3,1);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinContent(4,1);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinContent(5,0.4349621);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinError(1,0.06244019);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinError(2,0.05233856);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinError(3,0.05775547);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinError(4,0.07263422);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetBinError(5,0.03159313);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetMinimum(0.51);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetMaximum(1.49);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetEntries(13);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetLineColor(ci);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetMarkerColor(ci);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->SetMarkerStyle(0);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetXaxis()->SetTitle("#it{y^{Z}}");
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetXaxis()->SetNdivisions(4);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetXaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetXaxis()->SetLabelOffset(0.02);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetXaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetXaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetXaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->SetTitle("Ratio");
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->CenterTitle(true);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->SetNdivisions(505);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->SetTickLength(0.12325);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->SetTitleOffset(1.3);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetYaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetZaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetZaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetZaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->GetZaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0__34->Draw("e2");
   Double_t xAxis35[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *zj_yz_8TeV_400_1001_0ratiocomp1__35 = new TH1F("zj_yz_8TeV_400_1001_0ratiocomp1__35","z_y",4, xAxis35);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinContent(1,1);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinContent(2,1);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinContent(3,1);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinContent(4,1);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinContent(5,0.4349621);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinError(1,0.02698382);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinError(2,0.0172858);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinError(3,0.01956713);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinError(4,0.03904257);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetBinError(5,0.01698204);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetMinimum(0.51);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetMaximum(1.49);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetEntries(13);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetLineColor(ci);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetMarkerColor(ci);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->SetMarkerStyle(0);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetXaxis()->SetTitle("#it{y^{Z}}");
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetXaxis()->SetNdivisions(4);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetXaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetXaxis()->SetLabelOffset(0.02);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetXaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetXaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetXaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetYaxis()->SetTitle("Ratio");
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetYaxis()->CenterTitle(true);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetYaxis()->SetNdivisions(505);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetYaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetYaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetYaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetYaxis()->SetTickLength(0.12325);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetYaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetZaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetZaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetZaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->GetZaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp1__35->Draw("e2same");
   
   Double_t zj_yz_8TeV_400_1001_0ratiocomp2_fx3040[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp2_fy3040[4] = {
   1.017807,
   0.9926922,
   0.9781535,
   0.9248179};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp2_felx3040[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp2_fely3040[4] = {
   0.09177396,
   0.07305303,
   0.07181315,
   0.1400867};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp2_fehx3040[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp2_fehy3040[4] = {
   0.06430594,
   0.06587274,
   0.07018905,
   0.1144203};
   grae = new TGraphAsymmErrors(4,zj_yz_8TeV_400_1001_0ratiocomp2_fx3040,zj_yz_8TeV_400_1001_0ratiocomp2_fy3040,zj_yz_8TeV_400_1001_0ratiocomp2_felx3040,zj_yz_8TeV_400_1001_0ratiocomp2_fehx3040,zj_yz_8TeV_400_1001_0ratiocomp2_fely3040,zj_yz_8TeV_400_1001_0ratiocomp2_fehy3040);
   grae->SetName("zj_yz_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_yz_8TeV_400_1001_0ratiocomp23040 = new TH1F("Graph_zj_yz_8TeV_400_1001_0ratiocomp23040","",100,2.1425,4.3325);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->SetMinimum(0.51);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->SetMaximum(1.49);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->SetDirectory(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->SetStats(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->SetLineWidth(2);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->SetMarkerStyle(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetXaxis()->SetTitle("#it{y^{Z}}");
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetXaxis()->SetNdivisions(4);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetXaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetXaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetYaxis()->SetTitle("Ratio");
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetYaxis()->CenterTitle(true);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetYaxis()->SetNdivisions(505);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetYaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetYaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetZaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp23040->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_yz_8TeV_400_1001_0ratiocomp23040);
   
   grae->Draw("p1");
   
   Double_t zj_yz_8TeV_400_1001_0ratiocomp3_fx3041[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp3_fy3041[4] = {
   1.017807,
   0.9926922,
   0.9781535,
   0.9248179};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp3_felx3041[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp3_fely3041[4] = {
   0.05284637,
   0.05187611,
   0.05420559,
   0.06498343};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp3_fehx3041[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp3_fehy3041[4] = {
   0.05085227,
   0.04938867,
   0.05346741,
   0.07220664};
   grae = new TGraphAsymmErrors(4,zj_yz_8TeV_400_1001_0ratiocomp3_fx3041,zj_yz_8TeV_400_1001_0ratiocomp3_fy3041,zj_yz_8TeV_400_1001_0ratiocomp3_felx3041,zj_yz_8TeV_400_1001_0ratiocomp3_fehx3041,zj_yz_8TeV_400_1001_0ratiocomp3_fely3041,zj_yz_8TeV_400_1001_0ratiocomp3_fehy3041);
   grae->SetName("zj_yz_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_yz_8TeV_400_1001_0ratiocomp33041 = new TH1F("Graph_zj_yz_8TeV_400_1001_0ratiocomp33041","",100,2.1425,4.3325);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->SetMinimum(0.51);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->SetMaximum(1.49);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->SetDirectory(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->SetStats(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->SetLineWidth(2);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->SetMarkerStyle(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetXaxis()->SetTitle("#it{y^{Z}}");
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetXaxis()->SetNdivisions(4);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetXaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetXaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetYaxis()->SetTitle("Ratio");
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetYaxis()->CenterTitle(true);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetYaxis()->SetNdivisions(505);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetYaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetYaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetZaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp33041->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_yz_8TeV_400_1001_0ratiocomp33041);
   
   grae->Draw("p1");
   
   Double_t zj_yz_8TeV_400_1001_0ratiocomp4_fx3042[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp4_fy3042[4] = {
   1.125437,
   1.115668,
   1.106731,
   1.044066};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp4_felx3042[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp4_fely3042[4] = {
   0.08444803,
   0.08713578,
   0.09162804,
   0.1403561};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp4_fehx3042[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_400_1001_0ratiocomp4_fehy3042[4] = {
   0.08971762,
   0.09011887,
   0.1059478,
   0.1550245};
   grae = new TGraphAsymmErrors(4,zj_yz_8TeV_400_1001_0ratiocomp4_fx3042,zj_yz_8TeV_400_1001_0ratiocomp4_fy3042,zj_yz_8TeV_400_1001_0ratiocomp4_felx3042,zj_yz_8TeV_400_1001_0ratiocomp4_fehx3042,zj_yz_8TeV_400_1001_0ratiocomp4_fely3042,zj_yz_8TeV_400_1001_0ratiocomp4_fehy3042);
   grae->SetName("zj_yz_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_zj_yz_8TeV_400_1001_0ratiocomp43042 = new TH1F("Graph_zj_yz_8TeV_400_1001_0ratiocomp43042","",100,2.0075,4.0175);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->SetMinimum(0.51);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->SetMaximum(1.49);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->SetDirectory(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->SetStats(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->SetLineWidth(2);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->SetMarkerStyle(0);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetXaxis()->SetTitle("#it{y^{Z}}");
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetXaxis()->SetNdivisions(4);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetXaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetXaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetYaxis()->SetTitle("Ratio");
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetYaxis()->CenterTitle(true);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetYaxis()->SetNdivisions(505);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetYaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetYaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetZaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_400_1001_0ratiocomp43042->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_yz_8TeV_400_1001_0ratiocomp43042);
   
   grae->Draw("p1");
   Double_t xAxis36[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *zj_yz_8TeV_400_1001_0ratiocomp0_copy__36 = new TH1F("zj_yz_8TeV_400_1001_0ratiocomp0_copy__36","z_y",4, xAxis36);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinContent(1,1);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinContent(2,1);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinContent(3,1);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinContent(4,1);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinContent(5,0.4349621);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinError(1,0.06244019);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinError(2,0.05233856);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinError(3,0.05775547);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinError(4,0.07263422);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetBinError(5,0.03159313);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetMinimum(0.51);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetMaximum(1.49);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetEntries(13);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetDirectory(0);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetLineColor(ci);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetMarkerColor(ci);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->SetMarkerStyle(0);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetXaxis()->SetTitle("#it{y^{Z}}");
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetXaxis()->SetNdivisions(4);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetXaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetXaxis()->SetLabelOffset(0.02);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetXaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetXaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetXaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->SetTitle("Ratio");
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->CenterTitle(true);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->SetNdivisions(505);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->SetTickLength(0.12325);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->SetTitleOffset(1.3);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetYaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetZaxis()->SetLabelFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetZaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetZaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->GetZaxis()->SetTitleFont(132);
   zj_yz_8TeV_400_1001_0ratiocomp0_copy__36->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
