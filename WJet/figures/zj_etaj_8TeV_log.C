void zj_etaj_8TeV_log()
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
   upperPad->Range(1.854321,-1.222146,4.323457,1.102821);
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
   upperPad->SetBottomMargin(0.33);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   Double_t xAxis1[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *z_etaj_toterr__1 = new TH1F("z_etaj_toterr__1","z_etaj",4, xAxis1);
   z_etaj_toterr__1->SetBinContent(1,4.864718);
   z_etaj_toterr__1->SetBinContent(2,3.656438);
   z_etaj_toterr__1->SetBinContent(3,2.102091);
   z_etaj_toterr__1->SetBinContent(4,0.7875633);
   z_etaj_toterr__1->SetBinContent(5,0.3937815);
   z_etaj_toterr__1->SetBinError(1,0.2523818);
   z_etaj_toterr__1->SetBinError(2,0.1946216);
   z_etaj_toterr__1->SetBinError(3,0.1228768);
   z_etaj_toterr__1->SetBinError(4,0.08590874);
   z_etaj_toterr__1->SetBinError(5,0.04295435);
   z_etaj_toterr__1->SetEntries(10);
   z_etaj_toterr__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr__1->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr__1->SetLineColor(ci);
   z_etaj_toterr__1->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr__1->SetMarkerColor(ci);
   z_etaj_toterr__1->SetMarkerStyle(0);
   z_etaj_toterr__1->GetXaxis()->SetNdivisions(4);
   z_etaj_toterr__1->GetXaxis()->SetLabelFont(132);
   z_etaj_toterr__1->GetXaxis()->SetLabelOffset(999);
   z_etaj_toterr__1->GetXaxis()->SetLabelSize(0);
   z_etaj_toterr__1->GetXaxis()->SetTitleSize(0.06);
   z_etaj_toterr__1->GetXaxis()->SetTitleFont(132);
   z_etaj_toterr__1->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   z_etaj_toterr__1->GetYaxis()->SetLabelFont(132);
   z_etaj_toterr__1->GetYaxis()->SetLabelSize(0.05);
   z_etaj_toterr__1->GetYaxis()->SetTitleSize(0.06);
   z_etaj_toterr__1->GetYaxis()->SetTitleOffset(1.3);
   z_etaj_toterr__1->GetYaxis()->SetTitleFont(132);
   z_etaj_toterr__1->GetZaxis()->SetLabelFont(132);
   z_etaj_toterr__1->GetZaxis()->SetLabelSize(0.05);
   z_etaj_toterr__1->GetZaxis()->SetTitleSize(0.06);
   z_etaj_toterr__1->GetZaxis()->SetTitleFont(132);
   z_etaj_toterr__1->Draw("e2");
   Double_t xAxis2[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *z_etaj_staterr__2 = new TH1F("z_etaj_staterr__2","z_etaj",4, xAxis2);
   z_etaj_staterr__2->SetBinContent(1,4.864718);
   z_etaj_staterr__2->SetBinContent(2,3.656438);
   z_etaj_staterr__2->SetBinContent(3,2.102091);
   z_etaj_staterr__2->SetBinContent(4,0.7875633);
   z_etaj_staterr__2->SetBinContent(5,0.3937815);
   z_etaj_staterr__2->SetBinError(1,0.08115928);
   z_etaj_staterr__2->SetBinError(2,0.07436891);
   z_etaj_staterr__2->SetBinError(3,0.05628071);
   z_etaj_staterr__2->SetBinError(4,0.03260277);
   z_etaj_staterr__2->SetBinError(5,0.01630138);
   z_etaj_staterr__2->SetEntries(10);
   z_etaj_staterr__2->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   z_etaj_staterr__2->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   z_etaj_staterr__2->SetLineColor(ci);
   z_etaj_staterr__2->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   z_etaj_staterr__2->SetMarkerColor(ci);
   z_etaj_staterr__2->SetMarkerStyle(0);
   z_etaj_staterr__2->GetXaxis()->SetNdivisions(4);
   z_etaj_staterr__2->GetXaxis()->SetLabelFont(132);
   z_etaj_staterr__2->GetXaxis()->SetLabelOffset(999);
   z_etaj_staterr__2->GetXaxis()->SetLabelSize(0);
   z_etaj_staterr__2->GetXaxis()->SetTitleSize(0.06);
   z_etaj_staterr__2->GetXaxis()->SetTitleFont(132);
   z_etaj_staterr__2->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   z_etaj_staterr__2->GetYaxis()->SetLabelFont(132);
   z_etaj_staterr__2->GetYaxis()->SetLabelSize(0.05);
   z_etaj_staterr__2->GetYaxis()->SetTitleSize(0.06);
   z_etaj_staterr__2->GetYaxis()->SetTitleFont(132);
   z_etaj_staterr__2->GetZaxis()->SetLabelFont(132);
   z_etaj_staterr__2->GetZaxis()->SetLabelSize(0.05);
   z_etaj_staterr__2->GetZaxis()->SetTitleSize(0.06);
   z_etaj_staterr__2->GetZaxis()->SetTitleFont(132);
   z_etaj_staterr__2->Draw("e2same");
   
   Double_t etaj_toterrs_fx3001[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_toterrs_fy3001[4] = {
   5.006851,
   3.693534,
   2.148507,
   0.9320054};
   Double_t etaj_toterrs_felx3001[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_toterrs_fely3001[4] = {
   0.4340191,
   0.2682618,
   0.1631731,
   0.07850046};
   Double_t etaj_toterrs_fehx3001[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_toterrs_fehy3001[4] = {
   0.3718691,
   0.242935,
   0.1639715,
   0.07143119};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,etaj_toterrs_fx3001,etaj_toterrs_fy3001,etaj_toterrs_felx3001,etaj_toterrs_fehx3001,etaj_toterrs_fely3001,etaj_toterrs_fehy3001);
   grae->SetName("etaj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_etaj_toterrs3001 = new TH1F("Graph_etaj_toterrs3001","",100,2.375,4.175);
   Graph_etaj_toterrs3001->SetMinimum(0.4009834);
   Graph_etaj_toterrs3001->SetMaximum(5.831242);
   Graph_etaj_toterrs3001->SetDirectory(0);
   Graph_etaj_toterrs3001->SetStats(0);
   Graph_etaj_toterrs3001->SetLineWidth(2);
   Graph_etaj_toterrs3001->SetMarkerStyle(0);
   Graph_etaj_toterrs3001->GetXaxis()->SetNdivisions(4);
   Graph_etaj_toterrs3001->GetXaxis()->SetLabelFont(132);
   Graph_etaj_toterrs3001->GetXaxis()->SetLabelOffset(999);
   Graph_etaj_toterrs3001->GetXaxis()->SetLabelSize(0);
   Graph_etaj_toterrs3001->GetXaxis()->SetTitleSize(0.06);
   Graph_etaj_toterrs3001->GetXaxis()->SetTitleFont(132);
   Graph_etaj_toterrs3001->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   Graph_etaj_toterrs3001->GetYaxis()->SetLabelFont(132);
   Graph_etaj_toterrs3001->GetYaxis()->SetLabelSize(0.05);
   Graph_etaj_toterrs3001->GetYaxis()->SetTitleSize(0.06);
   Graph_etaj_toterrs3001->GetYaxis()->SetTitleFont(132);
   Graph_etaj_toterrs3001->GetZaxis()->SetLabelFont(132);
   Graph_etaj_toterrs3001->GetZaxis()->SetLabelSize(0.05);
   Graph_etaj_toterrs3001->GetZaxis()->SetTitleSize(0.06);
   Graph_etaj_toterrs3001->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_etaj_toterrs3001);
   
   grae->Draw("p1p");
   
   Double_t _fx3002[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3002[4] = {
   5.006851,
   3.693534,
   2.148507,
   0.9320054};
   Double_t _felx3002[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3002[4] = {
   0.2892594,
   0.1928613,
   0.1090078,
   0.05077791};
   Double_t _fehx3002[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3002[4] = {
   0.2924705,
   0.1850412,
   0.101917,
   0.04944241};
   grae = new TGraphAsymmErrors(4,_fx3002,_fy3002,_felx3002,_fehx3002,_fely3002,_fehy3002);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","",100,2.375,4.175);
   Graph_Graph3002->SetMinimum(0.4394181);
   Graph_Graph3002->SetMaximum(5.741131);
   Graph_Graph3002->SetDirectory(0);
   Graph_Graph3002->SetStats(0);
   Graph_Graph3002->SetLineWidth(2);
   Graph_Graph3002->SetMarkerStyle(0);
   Graph_Graph3002->GetXaxis()->SetNdivisions(4);
   Graph_Graph3002->GetXaxis()->SetLabelFont(132);
   Graph_Graph3002->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3002->GetXaxis()->SetLabelSize(0);
   Graph_Graph3002->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3002->GetXaxis()->SetTitleFont(132);
   Graph_Graph3002->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   Graph_Graph3002->GetYaxis()->SetLabelFont(132);
   Graph_Graph3002->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3002->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3002->GetYaxis()->SetTitleFont(132);
   Graph_Graph3002->GetZaxis()->SetLabelFont(132);
   Graph_Graph3002->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3002->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3002->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3002);
   
   grae->Draw("p1p");
   
   Double_t etaj_toterrs_fx3003[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_toterrs_fy3003[4] = {
   5.510216,
   4.034758,
   2.280329,
   1.003218};
   Double_t etaj_toterrs_felx3003[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_toterrs_fely3003[4] = {
   0.4464053,
   0.3264889,
   0.1765766,
   0.10494};
   Double_t etaj_toterrs_fehx3003[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_toterrs_fehy3003[4] = {
   0.5290736,
   0.3335314,
   0.2051868,
   0.09361191};
   grae = new TGraphAsymmErrors(4,etaj_toterrs_fx3003,etaj_toterrs_fy3003,etaj_toterrs_felx3003,etaj_toterrs_fehx3003,etaj_toterrs_fely3003,etaj_toterrs_fehy3003);
   grae->SetName("etaj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_etaj_toterrs3003 = new TH1F("Graph_etaj_toterrs3003","",100,2.225,4.025);
   Graph_etaj_toterrs3003->SetMinimum(0.3841769);
   Graph_etaj_toterrs3003->SetMaximum(6.553391);
   Graph_etaj_toterrs3003->SetDirectory(0);
   Graph_etaj_toterrs3003->SetStats(0);
   Graph_etaj_toterrs3003->SetLineWidth(2);
   Graph_etaj_toterrs3003->SetMarkerStyle(0);
   Graph_etaj_toterrs3003->GetXaxis()->SetNdivisions(4);
   Graph_etaj_toterrs3003->GetXaxis()->SetLabelFont(132);
   Graph_etaj_toterrs3003->GetXaxis()->SetLabelOffset(999);
   Graph_etaj_toterrs3003->GetXaxis()->SetLabelSize(0);
   Graph_etaj_toterrs3003->GetXaxis()->SetTitleSize(0.06);
   Graph_etaj_toterrs3003->GetXaxis()->SetTitleFont(132);
   Graph_etaj_toterrs3003->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   Graph_etaj_toterrs3003->GetYaxis()->SetLabelFont(132);
   Graph_etaj_toterrs3003->GetYaxis()->SetLabelSize(0.05);
   Graph_etaj_toterrs3003->GetYaxis()->SetTitleSize(0.06);
   Graph_etaj_toterrs3003->GetYaxis()->SetTitleFont(132);
   Graph_etaj_toterrs3003->GetZaxis()->SetLabelFont(132);
   Graph_etaj_toterrs3003->GetZaxis()->SetLabelSize(0.05);
   Graph_etaj_toterrs3003->GetZaxis()->SetTitleSize(0.06);
   Graph_etaj_toterrs3003->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_etaj_toterrs3003);
   
   grae->Draw("p1p");
   
   Double_t _fx3004[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3004[4] = {
   5.510216,
   4.034758,
   2.280329,
   1.003218};
   Double_t _felx3004[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3004[4] = {
   0.3592615,
   0.2429364,
   0.1361966,
   0.06400239};
   Double_t _fehx3004[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3004[4] = {
   0.4057941,
   0.2659426,
   0.147594,
   0.07089078};
   grae = new TGraphAsymmErrors(4,_fx3004,_fy3004,_felx3004,_fehx3004,_fely3004,_fehy3004);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3004 = new TH1F("Graph_Graph3004","",100,2.225,4.025);
   Graph_Graph3004->SetMinimum(0.4415362);
   Graph_Graph3004->SetMaximum(6.41369);
   Graph_Graph3004->SetDirectory(0);
   Graph_Graph3004->SetStats(0);
   Graph_Graph3004->SetLineWidth(2);
   Graph_Graph3004->SetMarkerStyle(0);
   Graph_Graph3004->GetXaxis()->SetNdivisions(4);
   Graph_Graph3004->GetXaxis()->SetLabelFont(132);
   Graph_Graph3004->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3004->GetXaxis()->SetLabelSize(0);
   Graph_Graph3004->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3004->GetXaxis()->SetTitleFont(132);
   Graph_Graph3004->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   Graph_Graph3004->GetYaxis()->SetLabelFont(132);
   Graph_Graph3004->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3004->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3004->GetYaxis()->SetTitleFont(132);
   Graph_Graph3004->GetZaxis()->SetLabelFont(132);
   Graph_Graph3004->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3004->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3004->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3004);
   
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
   Double_t xAxis3[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *z_etaj_toterr_copy__3 = new TH1F("z_etaj_toterr_copy__3","z_etaj",4, xAxis3);
   z_etaj_toterr_copy__3->SetBinContent(1,4.864718);
   z_etaj_toterr_copy__3->SetBinContent(2,3.656438);
   z_etaj_toterr_copy__3->SetBinContent(3,2.102091);
   z_etaj_toterr_copy__3->SetBinContent(4,0.7875633);
   z_etaj_toterr_copy__3->SetBinContent(5,0.3937815);
   z_etaj_toterr_copy__3->SetBinError(1,0.2523818);
   z_etaj_toterr_copy__3->SetBinError(2,0.1946216);
   z_etaj_toterr_copy__3->SetBinError(3,0.1228768);
   z_etaj_toterr_copy__3->SetBinError(4,0.08590874);
   z_etaj_toterr_copy__3->SetBinError(5,0.04295435);
   z_etaj_toterr_copy__3->SetEntries(10);
   z_etaj_toterr_copy__3->SetDirectory(0);
   z_etaj_toterr_copy__3->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr_copy__3->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr_copy__3->SetLineColor(ci);
   z_etaj_toterr_copy__3->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr_copy__3->SetMarkerColor(ci);
   z_etaj_toterr_copy__3->SetMarkerStyle(0);
   z_etaj_toterr_copy__3->GetXaxis()->SetNdivisions(4);
   z_etaj_toterr_copy__3->GetXaxis()->SetLabelFont(132);
   z_etaj_toterr_copy__3->GetXaxis()->SetLabelOffset(999);
   z_etaj_toterr_copy__3->GetXaxis()->SetLabelSize(0);
   z_etaj_toterr_copy__3->GetXaxis()->SetTitleSize(0.06);
   z_etaj_toterr_copy__3->GetXaxis()->SetTitleFont(132);
   z_etaj_toterr_copy__3->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   z_etaj_toterr_copy__3->GetYaxis()->SetLabelFont(132);
   z_etaj_toterr_copy__3->GetYaxis()->SetLabelSize(0.05);
   z_etaj_toterr_copy__3->GetYaxis()->SetTitleSize(0.06);
   z_etaj_toterr_copy__3->GetYaxis()->SetTitleOffset(1.3);
   z_etaj_toterr_copy__3->GetYaxis()->SetTitleFont(132);
   z_etaj_toterr_copy__3->GetZaxis()->SetLabelFont(132);
   z_etaj_toterr_copy__3->GetZaxis()->SetLabelSize(0.05);
   z_etaj_toterr_copy__3->GetZaxis()->SetTitleSize(0.06);
   z_etaj_toterr_copy__3->GetZaxis()->SetTitleFont(132);
   z_etaj_toterr_copy__3->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.854321,-0.1935898,4.323457,4.832052);
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
   Double_t xAxis4[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *zj_etaj_8TeV_log_400_1001_0ratiocomp0__4 = new TH1F("zj_etaj_8TeV_log_400_1001_0ratiocomp0__4","z_etaj",4, xAxis4);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinContent(1,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinContent(2,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinContent(3,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinContent(4,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinContent(5,0.3937815);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinError(1,0.05188004);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinError(2,0.05322711);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinError(3,0.05845457);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinError(4,0.1090817);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetBinError(5,0.04295435);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetMinimum(0.51);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetMaximum(1.49);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetEntries(14);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetLineColor(ci);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetMarkerColor(ci);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->SetMarkerStyle(0);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetXaxis()->SetNdivisions(4);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetXaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetXaxis()->SetLabelOffset(0.02);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetXaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetXaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetXaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->SetTitle("Ratio");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->CenterTitle(true);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->SetNdivisions(505);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->SetTickLength(0.12325);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->SetTitleOffset(1.3);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetYaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetZaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetZaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetZaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->GetZaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0__4->Draw("e2");
   Double_t xAxis5[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *zj_etaj_8TeV_log_400_1001_0ratiocomp1__5 = new TH1F("zj_etaj_8TeV_log_400_1001_0ratiocomp1__5","z_etaj",4, xAxis5);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinContent(1,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinContent(2,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinContent(3,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinContent(4,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinContent(5,0.3937815);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinError(1,0.01668324);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinError(2,0.02033917);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinError(3,0.02677368);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinError(4,0.04139701);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetBinError(5,0.01630138);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetMinimum(0.51);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetMaximum(1.49);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetEntries(14);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetLineColor(ci);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetMarkerColor(ci);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->SetMarkerStyle(0);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetXaxis()->SetNdivisions(4);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetXaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetXaxis()->SetLabelOffset(0.02);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetXaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetXaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetXaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetYaxis()->SetTitle("Ratio");
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetYaxis()->CenterTitle(true);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetYaxis()->SetNdivisions(505);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetYaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetYaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetYaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetYaxis()->SetTickLength(0.12325);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetYaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetZaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetZaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetZaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->GetZaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp1__5->Draw("e2same");
   
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp2_fx3005[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp2_fy3005[4] = {
   1.029217,
   1.010145,
   1.022081,
   1.183404};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp2_felx3005[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp2_fely3005[4] = {
   0.08921773,
   0.07336696,
   0.07762418,
   0.0996751};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp2_fehx3005[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp2_fehy3005[4] = {
   0.07644208,
   0.06644034,
   0.07800402,
   0.09069898};
   grae = new TGraphAsymmErrors(4,zj_etaj_8TeV_log_400_1001_0ratiocomp2_fx3005,zj_etaj_8TeV_log_400_1001_0ratiocomp2_fy3005,zj_etaj_8TeV_log_400_1001_0ratiocomp2_felx3005,zj_etaj_8TeV_log_400_1001_0ratiocomp2_fehx3005,zj_etaj_8TeV_log_400_1001_0ratiocomp2_fely3005,zj_etaj_8TeV_log_400_1001_0ratiocomp2_fehy3005);
   grae->SetName("zj_etaj_8TeV_log_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005 = new TH1F("Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005","",100,2.375,4.175);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->SetMinimum(0.51);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->SetMaximum(1.49);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->SetDirectory(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->SetStats(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->SetLineWidth(2);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->SetMarkerStyle(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetXaxis()->SetNdivisions(4);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetXaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetXaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetYaxis()->SetTitle("Ratio");
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetYaxis()->CenterTitle(true);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetYaxis()->SetNdivisions(505);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetYaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetYaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetZaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp23005);
   
   grae->Draw("p1");
   
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp3_fx3006[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp3_fy3006[4] = {
   1.029217,
   1.010145,
   1.022081,
   1.183404};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp3_felx3006[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp3_fely3006[4] = {
   0.05946068,
   0.05274568,
   0.05185687,
   0.0644747};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp3_fehx3006[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp3_fehy3006[4] = {
   0.06012074,
   0.05060695,
   0.04848365,
   0.06277897};
   grae = new TGraphAsymmErrors(4,zj_etaj_8TeV_log_400_1001_0ratiocomp3_fx3006,zj_etaj_8TeV_log_400_1001_0ratiocomp3_fy3006,zj_etaj_8TeV_log_400_1001_0ratiocomp3_felx3006,zj_etaj_8TeV_log_400_1001_0ratiocomp3_fehx3006,zj_etaj_8TeV_log_400_1001_0ratiocomp3_fely3006,zj_etaj_8TeV_log_400_1001_0ratiocomp3_fehy3006);
   grae->SetName("zj_etaj_8TeV_log_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006 = new TH1F("Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006","",100,2.375,4.175);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->SetMinimum(0.51);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->SetMaximum(1.49);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->SetDirectory(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->SetStats(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->SetLineWidth(2);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->SetMarkerStyle(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetXaxis()->SetNdivisions(4);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetXaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetXaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetYaxis()->SetTitle("Ratio");
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetYaxis()->CenterTitle(true);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetYaxis()->SetNdivisions(505);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetYaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetYaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetZaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp33006);
   
   grae->Draw("p1");
   
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp4_fx3007[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp4_fy3007[4] = {
   1.13269,
   1.103467,
   1.084791,
   1.273825};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp4_felx3007[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp4_fely3007[4] = {
   0.09176385,
   0.0892915,
   0.08400049,
   0.1332464};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp4_fehx3007[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_log_400_1001_0ratiocomp4_fehy3007[4] = {
   0.1087573,
   0.09121756,
   0.09761085,
   0.1188627};
   grae = new TGraphAsymmErrors(4,zj_etaj_8TeV_log_400_1001_0ratiocomp4_fx3007,zj_etaj_8TeV_log_400_1001_0ratiocomp4_fy3007,zj_etaj_8TeV_log_400_1001_0ratiocomp4_felx3007,zj_etaj_8TeV_log_400_1001_0ratiocomp4_fehx3007,zj_etaj_8TeV_log_400_1001_0ratiocomp4_fely3007,zj_etaj_8TeV_log_400_1001_0ratiocomp4_fehy3007);
   grae->SetName("zj_etaj_8TeV_log_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007 = new TH1F("Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007","",100,2.225,4.025);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->SetMinimum(0.51);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->SetMaximum(1.49);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->SetDirectory(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->SetStats(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->SetLineWidth(2);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->SetMarkerStyle(0);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetXaxis()->SetNdivisions(4);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetXaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetXaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetYaxis()->SetTitle("Ratio");
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetYaxis()->CenterTitle(true);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetYaxis()->SetNdivisions(505);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetYaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetYaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetZaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_etaj_8TeV_log_400_1001_0ratiocomp43007);
   
   grae->Draw("p1");
   Double_t xAxis6[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6 = new TH1F("zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6","z_etaj",4, xAxis6);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinContent(1,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinContent(2,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinContent(3,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinContent(4,1);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinContent(5,0.3937815);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinError(1,0.05188004);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinError(2,0.05322711);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinError(3,0.05845457);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinError(4,0.1090817);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetBinError(5,0.04295435);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetMinimum(0.51);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetMaximum(1.49);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetEntries(14);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetDirectory(0);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetLineColor(ci);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetMarkerColor(ci);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->SetMarkerStyle(0);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetXaxis()->SetNdivisions(4);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetXaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetXaxis()->SetLabelOffset(0.02);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetXaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetXaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetXaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->SetTitle("Ratio");
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->CenterTitle(true);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->SetNdivisions(505);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->SetTickLength(0.12325);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->SetTitleOffset(1.3);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetYaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetZaxis()->SetLabelFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetZaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetZaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->GetZaxis()->SetTitleFont(132);
   zj_etaj_8TeV_log_400_1001_0ratiocomp0_copy__6->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
