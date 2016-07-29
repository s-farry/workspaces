void wj_asymm_eta_8TeV()
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
   upperPad->Range(1.567901,-0.6637097,4.654321,0.7717742);
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
   Double_t xAxis154[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_a_eta_toterr__184 = new TH1F("w_a_eta_toterr__184","w_eta",4, xAxis154);
   w_a_eta_toterr__184->SetBinContent(1,0.37309);
   w_a_eta_toterr__184->SetBinContent(2,0.3100806);
   w_a_eta_toterr__184->SetBinContent(3,0.2092183);
   w_a_eta_toterr__184->SetBinContent(4,-0.01776053);
   w_a_eta_toterr__184->SetBinContent(5,-0.01776053);
   w_a_eta_toterr__184->SetBinError(1,0.01466777);
   w_a_eta_toterr__184->SetBinError(2,0.01572998);
   w_a_eta_toterr__184->SetBinError(3,0.01879191);
   w_a_eta_toterr__184->SetBinError(4,0.03426755);
   w_a_eta_toterr__184->SetBinError(5,0.03426755);
   w_a_eta_toterr__184->SetMinimum(-0.19);
   w_a_eta_toterr__184->SetMaximum(0.7);
   w_a_eta_toterr__184->SetEntries(6);
   w_a_eta_toterr__184->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr__184->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr__184->SetLineColor(ci);
   w_a_eta_toterr__184->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr__184->SetMarkerColor(ci);
   w_a_eta_toterr__184->SetMarkerStyle(0);
   w_a_eta_toterr__184->GetXaxis()->SetRange(1,4);
   w_a_eta_toterr__184->GetXaxis()->SetNdivisions(4);
   w_a_eta_toterr__184->GetXaxis()->SetLabelFont(132);
   w_a_eta_toterr__184->GetXaxis()->SetLabelOffset(999);
   w_a_eta_toterr__184->GetXaxis()->SetLabelSize(0);
   w_a_eta_toterr__184->GetXaxis()->SetTitleSize(0.06);
   w_a_eta_toterr__184->GetXaxis()->SetTitleFont(132);
   w_a_eta_toterr__184->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_eta_toterr__184->GetYaxis()->SetLabelFont(132);
   w_a_eta_toterr__184->GetYaxis()->SetLabelSize(0.05);
   w_a_eta_toterr__184->GetYaxis()->SetTitleSize(0.06);
   w_a_eta_toterr__184->GetYaxis()->SetTitleFont(132);
   w_a_eta_toterr__184->GetZaxis()->SetLabelFont(132);
   w_a_eta_toterr__184->GetZaxis()->SetLabelSize(0.05);
   w_a_eta_toterr__184->GetZaxis()->SetTitleSize(0.06);
   w_a_eta_toterr__184->GetZaxis()->SetTitleFont(132);
   w_a_eta_toterr__184->Draw("e2");
   Double_t xAxis155[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_a_eta_staterr__185 = new TH1F("w_a_eta_staterr__185","w_eta",4, xAxis155);
   w_a_eta_staterr__185->SetBinContent(1,0.37309);
   w_a_eta_staterr__185->SetBinContent(2,0.3100806);
   w_a_eta_staterr__185->SetBinContent(3,0.2092183);
   w_a_eta_staterr__185->SetBinContent(4,-0.01776053);
   w_a_eta_staterr__185->SetBinContent(5,-0.01776053);
   w_a_eta_staterr__185->SetBinError(1,0.005285836);
   w_a_eta_staterr__185->SetBinError(2,0.005242515);
   w_a_eta_staterr__185->SetBinError(3,0.006426803);
   w_a_eta_staterr__185->SetBinError(4,0.008943243);
   w_a_eta_staterr__185->SetBinError(5,0.008943243);
   w_a_eta_staterr__185->SetMinimum(-0.19);
   w_a_eta_staterr__185->SetMaximum(0.7);
   w_a_eta_staterr__185->SetEntries(6);
   w_a_eta_staterr__185->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   w_a_eta_staterr__185->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   w_a_eta_staterr__185->SetLineColor(ci);
   w_a_eta_staterr__185->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   w_a_eta_staterr__185->SetMarkerColor(ci);
   w_a_eta_staterr__185->SetMarkerStyle(0);
   w_a_eta_staterr__185->GetXaxis()->SetRange(1,4);
   w_a_eta_staterr__185->GetXaxis()->SetNdivisions(4);
   w_a_eta_staterr__185->GetXaxis()->SetLabelFont(132);
   w_a_eta_staterr__185->GetXaxis()->SetLabelOffset(999);
   w_a_eta_staterr__185->GetXaxis()->SetLabelSize(0);
   w_a_eta_staterr__185->GetXaxis()->SetTitleSize(0.06);
   w_a_eta_staterr__185->GetXaxis()->SetTitleFont(132);
   w_a_eta_staterr__185->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_eta_staterr__185->GetYaxis()->SetLabelFont(132);
   w_a_eta_staterr__185->GetYaxis()->SetLabelSize(0.05);
   w_a_eta_staterr__185->GetYaxis()->SetTitleSize(0.06);
   w_a_eta_staterr__185->GetYaxis()->SetTitleFont(132);
   w_a_eta_staterr__185->GetZaxis()->SetLabelFont(132);
   w_a_eta_staterr__185->GetZaxis()->SetLabelSize(0.05);
   w_a_eta_staterr__185->GetZaxis()->SetTitleSize(0.06);
   w_a_eta_staterr__185->GetZaxis()->SetTitleFont(132);
   w_a_eta_staterr__185->Draw("e2same");
   
   Double_t asymm_eta_toterrs_fx3225[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t asymm_eta_toterrs_fy3225[4] = {
   0.3142935,
   0.2884303,
   0.1663037,
   -0.04796124};
   Double_t asymm_eta_toterrs_felx3225[4] = {
   0,
   0,
   0,
   0};
   Double_t asymm_eta_toterrs_fely3225[4] = {
   0.007538251,
   0.01124843,
   0.02894682,
   0.04097771};
   Double_t asymm_eta_toterrs_fehx3225[4] = {
   0,
   0,
   0,
   0};
   Double_t asymm_eta_toterrs_fehy3225[4] = {
   0.01712026,
   0.01146322,
   0.02307544,
   0.04198072};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,asymm_eta_toterrs_fx3225,asymm_eta_toterrs_fy3225,asymm_eta_toterrs_felx3225,asymm_eta_toterrs_fehx3225,asymm_eta_toterrs_fely3225,asymm_eta_toterrs_fehy3225);
   grae->SetName("asymm_eta_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_asymm_eta_toterrs3225 = new TH1F("Graph_asymm_eta_toterrs3225","",100,2.1425,4.3325);
   Graph_asymm_eta_toterrs3225->SetMinimum(-0.19);
   Graph_asymm_eta_toterrs3225->SetMaximum(0.7);
   Graph_asymm_eta_toterrs3225->SetDirectory(0);
   Graph_asymm_eta_toterrs3225->SetStats(0);
   Graph_asymm_eta_toterrs3225->SetLineWidth(2);
   Graph_asymm_eta_toterrs3225->SetMarkerStyle(0);
   Graph_asymm_eta_toterrs3225->GetXaxis()->SetRange(0,101);
   Graph_asymm_eta_toterrs3225->GetXaxis()->SetNdivisions(4);
   Graph_asymm_eta_toterrs3225->GetXaxis()->SetLabelFont(132);
   Graph_asymm_eta_toterrs3225->GetXaxis()->SetLabelOffset(999);
   Graph_asymm_eta_toterrs3225->GetXaxis()->SetLabelSize(0);
   Graph_asymm_eta_toterrs3225->GetXaxis()->SetTitleSize(0.06);
   Graph_asymm_eta_toterrs3225->GetXaxis()->SetTitleFont(132);
   Graph_asymm_eta_toterrs3225->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_asymm_eta_toterrs3225->GetYaxis()->SetLabelFont(132);
   Graph_asymm_eta_toterrs3225->GetYaxis()->SetLabelSize(0.05);
   Graph_asymm_eta_toterrs3225->GetYaxis()->SetTitleSize(0.06);
   Graph_asymm_eta_toterrs3225->GetYaxis()->SetTitleFont(132);
   Graph_asymm_eta_toterrs3225->GetZaxis()->SetLabelFont(132);
   Graph_asymm_eta_toterrs3225->GetZaxis()->SetLabelSize(0.05);
   Graph_asymm_eta_toterrs3225->GetZaxis()->SetTitleSize(0.06);
   Graph_asymm_eta_toterrs3225->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_asymm_eta_toterrs3225);
   
   grae->Draw("p1p");
   
   Double_t _fx3226[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t _fy3226[4] = {
   0.3142935,
   0.2884303,
   0.1663037,
   -0.04796124};
   Double_t _felx3226[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3226[4] = {
   0.002399117,
   0.002213031,
   0.0050271,
   0.002625573};
   Double_t _fehx3226[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3226[4] = {
   0.001554221,
   0.00375545,
   0.004076868,
   0.00323138};
   grae = new TGraphAsymmErrors(4,_fx3226,_fy3226,_felx3226,_fehx3226,_fely3226,_fehy3226);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3226 = new TH1F("Graph_Graph3226","",100,2.1425,4.3325);
   Graph_Graph3226->SetMinimum(-0.19);
   Graph_Graph3226->SetMaximum(0.7);
   Graph_Graph3226->SetDirectory(0);
   Graph_Graph3226->SetStats(0);
   Graph_Graph3226->SetLineWidth(2);
   Graph_Graph3226->SetMarkerStyle(0);
   Graph_Graph3226->GetXaxis()->SetRange(0,101);
   Graph_Graph3226->GetXaxis()->SetNdivisions(4);
   Graph_Graph3226->GetXaxis()->SetLabelFont(132);
   Graph_Graph3226->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3226->GetXaxis()->SetLabelSize(0);
   Graph_Graph3226->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3226->GetXaxis()->SetTitleFont(132);
   Graph_Graph3226->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3226->GetYaxis()->SetLabelFont(132);
   Graph_Graph3226->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3226->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3226->GetYaxis()->SetTitleFont(132);
   Graph_Graph3226->GetZaxis()->SetLabelFont(132);
   Graph_Graph3226->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3226->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3226->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3226);
   
   grae->Draw("p1p");
   
   Double_t asymm_eta_toterrs_fx3227[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t asymm_eta_toterrs_fy3227[4] = {
   0.3249326,
   0.2958658,
   0.1909954,
   -0.03236835};
   Double_t asymm_eta_toterrs_felx3227[4] = {
   0,
   0,
   0,
   0};
   Double_t asymm_eta_toterrs_fely3227[4] = {
   0.005181714,
   0.01002897,
   0.0181324,
   0.03113499};
   Double_t asymm_eta_toterrs_fehx3227[4] = {
   0,
   0,
   0,
   0};
   Double_t asymm_eta_toterrs_fehy3227[4] = {
   0.005884798,
   0.009694029,
   0.01601284,
   0.0334509};
   grae = new TGraphAsymmErrors(4,asymm_eta_toterrs_fx3227,asymm_eta_toterrs_fy3227,asymm_eta_toterrs_felx3227,asymm_eta_toterrs_fehx3227,asymm_eta_toterrs_fely3227,asymm_eta_toterrs_fehy3227);
   grae->SetName("asymm_eta_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_asymm_eta_toterrs3227 = new TH1F("Graph_asymm_eta_toterrs3227","",100,2.0075,4.0175);
   Graph_asymm_eta_toterrs3227->SetMinimum(-0.19);
   Graph_asymm_eta_toterrs3227->SetMaximum(0.7);
   Graph_asymm_eta_toterrs3227->SetDirectory(0);
   Graph_asymm_eta_toterrs3227->SetStats(0);
   Graph_asymm_eta_toterrs3227->SetLineWidth(2);
   Graph_asymm_eta_toterrs3227->SetMarkerStyle(0);
   Graph_asymm_eta_toterrs3227->GetXaxis()->SetRange(0,101);
   Graph_asymm_eta_toterrs3227->GetXaxis()->SetNdivisions(4);
   Graph_asymm_eta_toterrs3227->GetXaxis()->SetLabelFont(132);
   Graph_asymm_eta_toterrs3227->GetXaxis()->SetLabelOffset(999);
   Graph_asymm_eta_toterrs3227->GetXaxis()->SetLabelSize(0);
   Graph_asymm_eta_toterrs3227->GetXaxis()->SetTitleSize(0.06);
   Graph_asymm_eta_toterrs3227->GetXaxis()->SetTitleFont(132);
   Graph_asymm_eta_toterrs3227->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_asymm_eta_toterrs3227->GetYaxis()->SetLabelFont(132);
   Graph_asymm_eta_toterrs3227->GetYaxis()->SetLabelSize(0.05);
   Graph_asymm_eta_toterrs3227->GetYaxis()->SetTitleSize(0.06);
   Graph_asymm_eta_toterrs3227->GetYaxis()->SetTitleFont(132);
   Graph_asymm_eta_toterrs3227->GetZaxis()->SetLabelFont(132);
   Graph_asymm_eta_toterrs3227->GetZaxis()->SetLabelSize(0.05);
   Graph_asymm_eta_toterrs3227->GetZaxis()->SetTitleSize(0.06);
   Graph_asymm_eta_toterrs3227->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_asymm_eta_toterrs3227);
   
   grae->Draw("p1p");
   
   Double_t _fx3228[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t _fy3228[4] = {
   0.3249326,
   0.2958658,
   0.1909954,
   -0.03236835};
   Double_t _felx3228[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3228[4] = {
   0.0002039671,
   0.002011985,
   0.003157094,
   0.003962893};
   Double_t _fehx3228[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3228[4] = {
   0.000302583,
   0.002581775,
   0.003566056,
   0.005081091};
   grae = new TGraphAsymmErrors(4,_fx3228,_fy3228,_felx3228,_fehx3228,_fely3228,_fehy3228);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3228 = new TH1F("Graph_Graph3228","",100,2.0075,4.0175);
   Graph_Graph3228->SetMinimum(-0.19);
   Graph_Graph3228->SetMaximum(0.7);
   Graph_Graph3228->SetDirectory(0);
   Graph_Graph3228->SetStats(0);
   Graph_Graph3228->SetLineWidth(2);
   Graph_Graph3228->SetMarkerStyle(0);
   Graph_Graph3228->GetXaxis()->SetRange(0,101);
   Graph_Graph3228->GetXaxis()->SetNdivisions(4);
   Graph_Graph3228->GetXaxis()->SetLabelFont(132);
   Graph_Graph3228->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3228->GetXaxis()->SetLabelSize(0);
   Graph_Graph3228->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3228->GetXaxis()->SetTitleFont(132);
   Graph_Graph3228->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3228->GetYaxis()->SetLabelFont(132);
   Graph_Graph3228->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3228->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3228->GetYaxis()->SetTitleFont(132);
   Graph_Graph3228->GetZaxis()->SetLabelFont(132);
   Graph_Graph3228->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3228->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3228->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3228);
   
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
   Double_t xAxis156[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_a_eta_toterr_copy__186 = new TH1F("w_a_eta_toterr_copy__186","w_eta",4, xAxis156);
   w_a_eta_toterr_copy__186->SetBinContent(1,0.37309);
   w_a_eta_toterr_copy__186->SetBinContent(2,0.3100806);
   w_a_eta_toterr_copy__186->SetBinContent(3,0.2092183);
   w_a_eta_toterr_copy__186->SetBinContent(4,-0.01776053);
   w_a_eta_toterr_copy__186->SetBinContent(5,-0.01776053);
   w_a_eta_toterr_copy__186->SetBinError(1,0.01466777);
   w_a_eta_toterr_copy__186->SetBinError(2,0.01572998);
   w_a_eta_toterr_copy__186->SetBinError(3,0.01879191);
   w_a_eta_toterr_copy__186->SetBinError(4,0.03426755);
   w_a_eta_toterr_copy__186->SetBinError(5,0.03426755);
   w_a_eta_toterr_copy__186->SetMinimum(-0.19);
   w_a_eta_toterr_copy__186->SetMaximum(0.7);
   w_a_eta_toterr_copy__186->SetEntries(6);
   w_a_eta_toterr_copy__186->SetDirectory(0);
   w_a_eta_toterr_copy__186->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr_copy__186->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr_copy__186->SetLineColor(ci);
   w_a_eta_toterr_copy__186->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_a_eta_toterr_copy__186->SetMarkerColor(ci);
   w_a_eta_toterr_copy__186->SetMarkerStyle(0);
   w_a_eta_toterr_copy__186->GetXaxis()->SetRange(1,4);
   w_a_eta_toterr_copy__186->GetXaxis()->SetNdivisions(4);
   w_a_eta_toterr_copy__186->GetXaxis()->SetLabelFont(132);
   w_a_eta_toterr_copy__186->GetXaxis()->SetLabelOffset(999);
   w_a_eta_toterr_copy__186->GetXaxis()->SetLabelSize(0);
   w_a_eta_toterr_copy__186->GetXaxis()->SetTitleSize(0.06);
   w_a_eta_toterr_copy__186->GetXaxis()->SetTitleFont(132);
   w_a_eta_toterr_copy__186->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_eta_toterr_copy__186->GetYaxis()->SetLabelFont(132);
   w_a_eta_toterr_copy__186->GetYaxis()->SetLabelSize(0.05);
   w_a_eta_toterr_copy__186->GetYaxis()->SetTitleSize(0.06);
   w_a_eta_toterr_copy__186->GetYaxis()->SetTitleFont(132);
   w_a_eta_toterr_copy__186->GetZaxis()->SetLabelFont(132);
   w_a_eta_toterr_copy__186->GetZaxis()->SetLabelSize(0.05);
   w_a_eta_toterr_copy__186->GetZaxis()->SetTitleSize(0.06);
   w_a_eta_toterr_copy__186->GetZaxis()->SetTitleFont(132);
   w_a_eta_toterr_copy__186->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.567901,-0.2435897,4.654321,0.7820513);
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
   Double_t xAxis157[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_asymm_eta_8TeV_400_1001_0diffcomp0__187 = new TH1F("wj_asymm_eta_8TeV_400_1001_0diffcomp0__187","w_eta",4, xAxis157);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetBinContent(5,-0.01776053);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetBinError(1,0.01466777);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetBinError(2,0.01572998);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetBinError(3,0.01879191);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetBinError(4,0.03426755);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetBinError(5,0.03426755);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetMinimum(-0.1);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetMaximum(0.1);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetEntries(10);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetLineColor(ci);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetMarkerColor(ci);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->SetMarkerStyle(0);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetXaxis()->SetRange(1,4);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetXaxis()->SetNdivisions(4);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetXaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetXaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetYaxis()->SetTitle("Diff.");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetYaxis()->SetNdivisions(505);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetYaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetYaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetZaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->GetZaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0__187->Draw("e2");
   Double_t xAxis158[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_asymm_eta_8TeV_400_1001_0diffcomp1__188 = new TH1F("wj_asymm_eta_8TeV_400_1001_0diffcomp1__188","w_eta",4, xAxis158);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetBinContent(5,-0.01776053);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetBinError(1,0.005285836);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetBinError(2,0.005242515);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetBinError(3,0.006426803);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetBinError(4,0.008943243);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetBinError(5,0.008943243);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetMinimum(-0.1);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetMaximum(0.1);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetEntries(10);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetLineColor(ci);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetMarkerColor(ci);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->SetMarkerStyle(0);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetXaxis()->SetRange(1,4);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetXaxis()->SetNdivisions(4);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetXaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetXaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetYaxis()->SetTitle("Diff.");
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetYaxis()->SetNdivisions(505);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetYaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetYaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetZaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->GetZaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp1__188->Draw("e2same");
   
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp2_fx3229[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp2_fy3229[4] = {
   -0.0587965,
   -0.02165025,
   -0.04291466,
   -0.03020071};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp2_felx3229[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp2_fely3229[4] = {
   0.007538251,
   0.01124843,
   0.02894682,
   0.04097771};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp2_fehx3229[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp2_fehy3229[4] = {
   0.01712026,
   0.01146322,
   0.02307544,
   0.04198072};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_8TeV_400_1001_0diffcomp2_fx3229,wj_asymm_eta_8TeV_400_1001_0diffcomp2_fy3229,wj_asymm_eta_8TeV_400_1001_0diffcomp2_felx3229,wj_asymm_eta_8TeV_400_1001_0diffcomp2_fehx3229,wj_asymm_eta_8TeV_400_1001_0diffcomp2_fely3229,wj_asymm_eta_8TeV_400_1001_0diffcomp2_fehy3229);
   grae->SetName("wj_asymm_eta_8TeV_400_1001_0diffcomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229 = new TH1F("Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229","",100,2.1425,4.3325);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->SetMinimum(-0.1);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->SetMaximum(0.1);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->SetDirectory(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->SetStats(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->SetLineWidth(2);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->SetMarkerStyle(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetXaxis()->SetRange(0,101);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp23229);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp3_fx3230[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp3_fy3230[4] = {
   -0.0587965,
   -0.02165025,
   -0.04291466,
   -0.03020071};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp3_felx3230[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp3_fely3230[4] = {
   0.002399117,
   0.002213031,
   0.0050271,
   0.002625573};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp3_fehx3230[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp3_fehy3230[4] = {
   0.001554221,
   0.00375545,
   0.004076868,
   0.00323138};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_8TeV_400_1001_0diffcomp3_fx3230,wj_asymm_eta_8TeV_400_1001_0diffcomp3_fy3230,wj_asymm_eta_8TeV_400_1001_0diffcomp3_felx3230,wj_asymm_eta_8TeV_400_1001_0diffcomp3_fehx3230,wj_asymm_eta_8TeV_400_1001_0diffcomp3_fely3230,wj_asymm_eta_8TeV_400_1001_0diffcomp3_fehy3230);
   grae->SetName("wj_asymm_eta_8TeV_400_1001_0diffcomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230 = new TH1F("Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230","",100,2.1425,4.3325);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->SetMinimum(-0.1);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->SetMaximum(0.1);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->SetDirectory(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->SetStats(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->SetLineWidth(2);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->SetMarkerStyle(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetXaxis()->SetRange(0,101);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp33230);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp4_fx3231[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp4_fy3231[4] = {
   -0.04815733,
   -0.01421472,
   -0.0182229,
   -0.01460783};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp4_felx3231[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp4_fely3231[4] = {
   0.005181714,
   0.01002897,
   0.0181324,
   0.03113499};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp4_fehx3231[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_asymm_eta_8TeV_400_1001_0diffcomp4_fehy3231[4] = {
   0.005884798,
   0.009694029,
   0.01601284,
   0.0334509};
   grae = new TGraphAsymmErrors(4,wj_asymm_eta_8TeV_400_1001_0diffcomp4_fx3231,wj_asymm_eta_8TeV_400_1001_0diffcomp4_fy3231,wj_asymm_eta_8TeV_400_1001_0diffcomp4_felx3231,wj_asymm_eta_8TeV_400_1001_0diffcomp4_fehx3231,wj_asymm_eta_8TeV_400_1001_0diffcomp4_fely3231,wj_asymm_eta_8TeV_400_1001_0diffcomp4_fehy3231);
   grae->SetName("wj_asymm_eta_8TeV_400_1001_0diffcomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231 = new TH1F("Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231","",100,2.0075,4.0175);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->SetMinimum(-0.1);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->SetMaximum(0.1);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->SetDirectory(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->SetStats(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->SetLineWidth(2);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->SetMarkerStyle(0);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetXaxis()->SetRange(0,101);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_eta_8TeV_400_1001_0diffcomp43231);
   
   grae->Draw("p1");
   Double_t xAxis159[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189 = new TH1F("wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189","w_eta",4, xAxis159);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetBinContent(5,-0.01776053);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetBinError(1,0.01466777);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetBinError(2,0.01572998);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetBinError(3,0.01879191);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetBinError(4,0.03426755);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetBinError(5,0.03426755);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetMinimum(-0.1);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetMaximum(0.1);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetEntries(10);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetDirectory(0);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetLineColor(ci);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetMarkerColor(ci);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->SetMarkerStyle(0);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetXaxis()->SetRange(1,4);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetXaxis()->SetNdivisions(4);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetXaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetXaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetYaxis()->SetTitle("Diff.");
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetYaxis()->SetNdivisions(505);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetYaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetYaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetZaxis()->SetLabelFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->GetZaxis()->SetTitleFont(132);
   wj_asymm_eta_8TeV_400_1001_0diffcomp0_copy__189->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
