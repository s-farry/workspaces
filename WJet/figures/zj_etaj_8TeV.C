void zj_etaj_8TeV()
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
   upperPad->Range(1.854321,-3.617823,4.323457,7.348307);
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
   Double_t xAxis7[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *z_etaj_toterr__7 = new TH1F("z_etaj_toterr__7","z_etaj",4, xAxis7);
   z_etaj_toterr__7->SetBinContent(1,4.864718);
   z_etaj_toterr__7->SetBinContent(2,3.656438);
   z_etaj_toterr__7->SetBinContent(3,2.102091);
   z_etaj_toterr__7->SetBinContent(4,0.7875633);
   z_etaj_toterr__7->SetBinContent(5,0.3937815);
   z_etaj_toterr__7->SetBinError(1,0.2523818);
   z_etaj_toterr__7->SetBinError(2,0.1946216);
   z_etaj_toterr__7->SetBinError(3,0.1228768);
   z_etaj_toterr__7->SetBinError(4,0.08590874);
   z_etaj_toterr__7->SetBinError(5,0.04295435);
   z_etaj_toterr__7->SetMinimum(0.001);
   z_etaj_toterr__7->SetMaximum(6.8);
   z_etaj_toterr__7->SetEntries(10);
   z_etaj_toterr__7->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr__7->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr__7->SetLineColor(ci);
   z_etaj_toterr__7->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr__7->SetMarkerColor(ci);
   z_etaj_toterr__7->SetMarkerStyle(0);
   z_etaj_toterr__7->GetXaxis()->SetNdivisions(4);
   z_etaj_toterr__7->GetXaxis()->SetLabelFont(132);
   z_etaj_toterr__7->GetXaxis()->SetLabelOffset(999);
   z_etaj_toterr__7->GetXaxis()->SetLabelSize(0);
   z_etaj_toterr__7->GetXaxis()->SetTitleSize(0.06);
   z_etaj_toterr__7->GetXaxis()->SetTitleFont(132);
   z_etaj_toterr__7->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   z_etaj_toterr__7->GetYaxis()->SetLabelFont(132);
   z_etaj_toterr__7->GetYaxis()->SetLabelSize(0.05);
   z_etaj_toterr__7->GetYaxis()->SetTitleSize(0.06);
   z_etaj_toterr__7->GetYaxis()->SetTitleOffset(1.3);
   z_etaj_toterr__7->GetYaxis()->SetTitleFont(132);
   z_etaj_toterr__7->GetZaxis()->SetLabelFont(132);
   z_etaj_toterr__7->GetZaxis()->SetLabelSize(0.05);
   z_etaj_toterr__7->GetZaxis()->SetTitleSize(0.06);
   z_etaj_toterr__7->GetZaxis()->SetTitleFont(132);
   z_etaj_toterr__7->Draw("e2");
   Double_t xAxis8[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *z_etaj_staterr__8 = new TH1F("z_etaj_staterr__8","z_etaj",4, xAxis8);
   z_etaj_staterr__8->SetBinContent(1,4.864718);
   z_etaj_staterr__8->SetBinContent(2,3.656438);
   z_etaj_staterr__8->SetBinContent(3,2.102091);
   z_etaj_staterr__8->SetBinContent(4,0.7875633);
   z_etaj_staterr__8->SetBinContent(5,0.3937815);
   z_etaj_staterr__8->SetBinError(1,0.08115928);
   z_etaj_staterr__8->SetBinError(2,0.07436891);
   z_etaj_staterr__8->SetBinError(3,0.05628071);
   z_etaj_staterr__8->SetBinError(4,0.03260277);
   z_etaj_staterr__8->SetBinError(5,0.01630138);
   z_etaj_staterr__8->SetMinimum(0.001);
   z_etaj_staterr__8->SetMaximum(6.8);
   z_etaj_staterr__8->SetEntries(10);
   z_etaj_staterr__8->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   z_etaj_staterr__8->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   z_etaj_staterr__8->SetLineColor(ci);
   z_etaj_staterr__8->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   z_etaj_staterr__8->SetMarkerColor(ci);
   z_etaj_staterr__8->SetMarkerStyle(0);
   z_etaj_staterr__8->GetXaxis()->SetNdivisions(4);
   z_etaj_staterr__8->GetXaxis()->SetLabelFont(132);
   z_etaj_staterr__8->GetXaxis()->SetLabelOffset(999);
   z_etaj_staterr__8->GetXaxis()->SetLabelSize(0);
   z_etaj_staterr__8->GetXaxis()->SetTitleSize(0.06);
   z_etaj_staterr__8->GetXaxis()->SetTitleFont(132);
   z_etaj_staterr__8->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   z_etaj_staterr__8->GetYaxis()->SetLabelFont(132);
   z_etaj_staterr__8->GetYaxis()->SetLabelSize(0.05);
   z_etaj_staterr__8->GetYaxis()->SetTitleSize(0.06);
   z_etaj_staterr__8->GetYaxis()->SetTitleFont(132);
   z_etaj_staterr__8->GetZaxis()->SetLabelFont(132);
   z_etaj_staterr__8->GetZaxis()->SetLabelSize(0.05);
   z_etaj_staterr__8->GetZaxis()->SetTitleSize(0.06);
   z_etaj_staterr__8->GetZaxis()->SetTitleFont(132);
   z_etaj_staterr__8->Draw("e2same");
   
   Double_t etaj_toterrs_fx3008[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t etaj_toterrs_fy3008[4] = {
   5.006851,
   3.693534,
   2.148507,
   0.9320054};
   Double_t etaj_toterrs_felx3008[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_toterrs_fely3008[4] = {
   0.4340191,
   0.2682618,
   0.1631731,
   0.07850046};
   Double_t etaj_toterrs_fehx3008[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_toterrs_fehy3008[4] = {
   0.3718691,
   0.242935,
   0.1639715,
   0.07143119};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,etaj_toterrs_fx3008,etaj_toterrs_fy3008,etaj_toterrs_felx3008,etaj_toterrs_fehx3008,etaj_toterrs_fely3008,etaj_toterrs_fehy3008);
   grae->SetName("etaj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_etaj_toterrs30013008 = new TH1F("Graph_Graph_etaj_toterrs30013008","",100,2.375,4.175);
   Graph_Graph_etaj_toterrs30013008->SetMinimum(0.001);
   Graph_Graph_etaj_toterrs30013008->SetMaximum(6.8);
   Graph_Graph_etaj_toterrs30013008->SetDirectory(0);
   Graph_Graph_etaj_toterrs30013008->SetStats(0);
   Graph_Graph_etaj_toterrs30013008->SetLineWidth(2);
   Graph_Graph_etaj_toterrs30013008->SetMarkerStyle(0);
   Graph_Graph_etaj_toterrs30013008->GetXaxis()->SetNdivisions(4);
   Graph_Graph_etaj_toterrs30013008->GetXaxis()->SetLabelFont(132);
   Graph_Graph_etaj_toterrs30013008->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_etaj_toterrs30013008->GetXaxis()->SetLabelSize(0);
   Graph_Graph_etaj_toterrs30013008->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_toterrs30013008->GetXaxis()->SetTitleFont(132);
   Graph_Graph_etaj_toterrs30013008->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   Graph_Graph_etaj_toterrs30013008->GetYaxis()->SetLabelFont(132);
   Graph_Graph_etaj_toterrs30013008->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_toterrs30013008->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_toterrs30013008->GetYaxis()->SetTitleFont(132);
   Graph_Graph_etaj_toterrs30013008->GetZaxis()->SetLabelFont(132);
   Graph_Graph_etaj_toterrs30013008->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_toterrs30013008->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_toterrs30013008->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_etaj_toterrs30013008);
   
   grae->Draw("p1p");
   
   Double_t _fx3009[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t _fy3009[4] = {
   5.006851,
   3.693534,
   2.148507,
   0.9320054};
   Double_t _felx3009[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3009[4] = {
   0.2892594,
   0.1928613,
   0.1090078,
   0.05077791};
   Double_t _fehx3009[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3009[4] = {
   0.2924705,
   0.1850412,
   0.101917,
   0.04944241};
   grae = new TGraphAsymmErrors(4,_fx3009,_fy3009,_felx3009,_fehx3009,_fely3009,_fehy3009);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph30023009 = new TH1F("Graph_Graph_Graph30023009","",100,2.375,4.175);
   Graph_Graph_Graph30023009->SetMinimum(0.001);
   Graph_Graph_Graph30023009->SetMaximum(6.8);
   Graph_Graph_Graph30023009->SetDirectory(0);
   Graph_Graph_Graph30023009->SetStats(0);
   Graph_Graph_Graph30023009->SetLineWidth(2);
   Graph_Graph_Graph30023009->SetMarkerStyle(0);
   Graph_Graph_Graph30023009->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30023009->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30023009->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30023009->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30023009->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30023009->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30023009->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph30023009->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30023009->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30023009->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30023009->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30023009->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30023009->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30023009->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30023009->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30023009);
   
   grae->Draw("p1p");
   
   Double_t etaj_toterrs_fx3010[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t etaj_toterrs_fy3010[4] = {
   5.510216,
   4.034758,
   2.280329,
   1.003218};
   Double_t etaj_toterrs_felx3010[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_toterrs_fely3010[4] = {
   0.4464053,
   0.3264889,
   0.1765766,
   0.10494};
   Double_t etaj_toterrs_fehx3010[4] = {
   0,
   0,
   0,
   0};
   Double_t etaj_toterrs_fehy3010[4] = {
   0.5290736,
   0.3335314,
   0.2051868,
   0.09361191};
   grae = new TGraphAsymmErrors(4,etaj_toterrs_fx3010,etaj_toterrs_fy3010,etaj_toterrs_felx3010,etaj_toterrs_fehx3010,etaj_toterrs_fely3010,etaj_toterrs_fehy3010);
   grae->SetName("etaj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_etaj_toterrs30033010 = new TH1F("Graph_Graph_etaj_toterrs30033010","",100,2.225,4.025);
   Graph_Graph_etaj_toterrs30033010->SetMinimum(0.001);
   Graph_Graph_etaj_toterrs30033010->SetMaximum(6.8);
   Graph_Graph_etaj_toterrs30033010->SetDirectory(0);
   Graph_Graph_etaj_toterrs30033010->SetStats(0);
   Graph_Graph_etaj_toterrs30033010->SetLineWidth(2);
   Graph_Graph_etaj_toterrs30033010->SetMarkerStyle(0);
   Graph_Graph_etaj_toterrs30033010->GetXaxis()->SetNdivisions(4);
   Graph_Graph_etaj_toterrs30033010->GetXaxis()->SetLabelFont(132);
   Graph_Graph_etaj_toterrs30033010->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_etaj_toterrs30033010->GetXaxis()->SetLabelSize(0);
   Graph_Graph_etaj_toterrs30033010->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_toterrs30033010->GetXaxis()->SetTitleFont(132);
   Graph_Graph_etaj_toterrs30033010->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   Graph_Graph_etaj_toterrs30033010->GetYaxis()->SetLabelFont(132);
   Graph_Graph_etaj_toterrs30033010->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_toterrs30033010->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_toterrs30033010->GetYaxis()->SetTitleFont(132);
   Graph_Graph_etaj_toterrs30033010->GetZaxis()->SetLabelFont(132);
   Graph_Graph_etaj_toterrs30033010->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_etaj_toterrs30033010->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_etaj_toterrs30033010->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_etaj_toterrs30033010);
   
   grae->Draw("p1p");
   
   Double_t _fx3011[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t _fy3011[4] = {
   5.510216,
   4.034758,
   2.280329,
   1.003218};
   Double_t _felx3011[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3011[4] = {
   0.3592615,
   0.2429364,
   0.1361966,
   0.06400239};
   Double_t _fehx3011[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3011[4] = {
   0.4057941,
   0.2659426,
   0.147594,
   0.07089078};
   grae = new TGraphAsymmErrors(4,_fx3011,_fy3011,_felx3011,_fehx3011,_fely3011,_fehy3011);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30043011 = new TH1F("Graph_Graph_Graph30043011","",100,2.225,4.025);
   Graph_Graph_Graph30043011->SetMinimum(0.001);
   Graph_Graph_Graph30043011->SetMaximum(6.8);
   Graph_Graph_Graph30043011->SetDirectory(0);
   Graph_Graph_Graph30043011->SetStats(0);
   Graph_Graph_Graph30043011->SetLineWidth(2);
   Graph_Graph_Graph30043011->SetMarkerStyle(0);
   Graph_Graph_Graph30043011->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30043011->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30043011->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30043011->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30043011->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30043011->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30043011->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   Graph_Graph_Graph30043011->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30043011->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30043011->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30043011->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30043011->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30043011->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30043011->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30043011->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30043011);
   
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
   Double_t xAxis9[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *z_etaj_toterr_copy__9 = new TH1F("z_etaj_toterr_copy__9","z_etaj",4, xAxis9);
   z_etaj_toterr_copy__9->SetBinContent(1,4.864718);
   z_etaj_toterr_copy__9->SetBinContent(2,3.656438);
   z_etaj_toterr_copy__9->SetBinContent(3,2.102091);
   z_etaj_toterr_copy__9->SetBinContent(4,0.7875633);
   z_etaj_toterr_copy__9->SetBinContent(5,0.3937815);
   z_etaj_toterr_copy__9->SetBinError(1,0.2523818);
   z_etaj_toterr_copy__9->SetBinError(2,0.1946216);
   z_etaj_toterr_copy__9->SetBinError(3,0.1228768);
   z_etaj_toterr_copy__9->SetBinError(4,0.08590874);
   z_etaj_toterr_copy__9->SetBinError(5,0.04295435);
   z_etaj_toterr_copy__9->SetMinimum(0.001);
   z_etaj_toterr_copy__9->SetMaximum(6.8);
   z_etaj_toterr_copy__9->SetEntries(10);
   z_etaj_toterr_copy__9->SetDirectory(0);
   z_etaj_toterr_copy__9->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr_copy__9->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr_copy__9->SetLineColor(ci);
   z_etaj_toterr_copy__9->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_etaj_toterr_copy__9->SetMarkerColor(ci);
   z_etaj_toterr_copy__9->SetMarkerStyle(0);
   z_etaj_toterr_copy__9->GetXaxis()->SetNdivisions(4);
   z_etaj_toterr_copy__9->GetXaxis()->SetLabelFont(132);
   z_etaj_toterr_copy__9->GetXaxis()->SetLabelOffset(999);
   z_etaj_toterr_copy__9->GetXaxis()->SetLabelSize(0);
   z_etaj_toterr_copy__9->GetXaxis()->SetTitleSize(0.06);
   z_etaj_toterr_copy__9->GetXaxis()->SetTitleFont(132);
   z_etaj_toterr_copy__9->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{#eta}^{jet} [pb]");
   z_etaj_toterr_copy__9->GetYaxis()->SetLabelFont(132);
   z_etaj_toterr_copy__9->GetYaxis()->SetLabelSize(0.05);
   z_etaj_toterr_copy__9->GetYaxis()->SetTitleSize(0.06);
   z_etaj_toterr_copy__9->GetYaxis()->SetTitleOffset(1.3);
   z_etaj_toterr_copy__9->GetYaxis()->SetTitleFont(132);
   z_etaj_toterr_copy__9->GetZaxis()->SetLabelFont(132);
   z_etaj_toterr_copy__9->GetZaxis()->SetLabelSize(0.05);
   z_etaj_toterr_copy__9->GetZaxis()->SetTitleSize(0.06);
   z_etaj_toterr_copy__9->GetZaxis()->SetTitleFont(132);
   z_etaj_toterr_copy__9->Draw("sameaxis");
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
   Double_t xAxis10[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *zj_etaj_8TeV_400_1001_0ratiocomp0__10 = new TH1F("zj_etaj_8TeV_400_1001_0ratiocomp0__10","z_etaj",4, xAxis10);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinContent(1,1);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinContent(2,1);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinContent(3,1);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinContent(4,1);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinContent(5,0.3937815);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinError(1,0.05188004);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinError(2,0.05322711);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinError(3,0.05845457);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinError(4,0.1090817);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetBinError(5,0.04295435);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetMinimum(0.51);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetMaximum(1.49);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetEntries(14);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetLineColor(ci);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetMarkerColor(ci);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->SetMarkerStyle(0);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetXaxis()->SetNdivisions(4);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetXaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetXaxis()->SetLabelOffset(0.02);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetXaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetXaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetXaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->SetTitle("Ratio");
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->CenterTitle(true);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->SetNdivisions(505);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->SetTickLength(0.12325);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->SetTitleOffset(1.3);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetYaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetZaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetZaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetZaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->GetZaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0__10->Draw("e2");
   Double_t xAxis11[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *zj_etaj_8TeV_400_1001_0ratiocomp1__11 = new TH1F("zj_etaj_8TeV_400_1001_0ratiocomp1__11","z_etaj",4, xAxis11);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinContent(1,1);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinContent(2,1);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinContent(3,1);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinContent(4,1);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinContent(5,0.3937815);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinError(1,0.01668324);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinError(2,0.02033917);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinError(3,0.02677368);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinError(4,0.04139701);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetBinError(5,0.01630138);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetMinimum(0.51);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetMaximum(1.49);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetEntries(14);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetLineColor(ci);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetMarkerColor(ci);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->SetMarkerStyle(0);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetXaxis()->SetNdivisions(4);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetXaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetXaxis()->SetLabelOffset(0.02);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetXaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetXaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetXaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetYaxis()->SetTitle("Ratio");
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetYaxis()->CenterTitle(true);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetYaxis()->SetNdivisions(505);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetYaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetYaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetYaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetYaxis()->SetTickLength(0.12325);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetYaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetZaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetZaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetZaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->GetZaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp1__11->Draw("e2same");
   
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp2_fx3012[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp2_fy3012[4] = {
   1.029217,
   1.010145,
   1.022081,
   1.183404};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp2_felx3012[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp2_fely3012[4] = {
   0.08921773,
   0.07336696,
   0.07762418,
   0.0996751};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp2_fehx3012[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp2_fehy3012[4] = {
   0.07644208,
   0.06644034,
   0.07800402,
   0.09069898};
   grae = new TGraphAsymmErrors(4,zj_etaj_8TeV_400_1001_0ratiocomp2_fx3012,zj_etaj_8TeV_400_1001_0ratiocomp2_fy3012,zj_etaj_8TeV_400_1001_0ratiocomp2_felx3012,zj_etaj_8TeV_400_1001_0ratiocomp2_fehx3012,zj_etaj_8TeV_400_1001_0ratiocomp2_fely3012,zj_etaj_8TeV_400_1001_0ratiocomp2_fehy3012);
   grae->SetName("zj_etaj_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012 = new TH1F("Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012","",100,2.375,4.175);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->SetMinimum(0.51);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->SetMaximum(1.49);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->SetDirectory(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->SetStats(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->SetLineWidth(2);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->SetMarkerStyle(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetXaxis()->SetNdivisions(4);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetXaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetXaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetYaxis()->SetTitle("Ratio");
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetYaxis()->CenterTitle(true);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetYaxis()->SetNdivisions(505);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetYaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetYaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetZaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_etaj_8TeV_400_1001_0ratiocomp23012);
   
   grae->Draw("p1");
   
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp3_fx3013[4] = {
   2.525,
   3.025,
   3.525,
   4.025};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp3_fy3013[4] = {
   1.029217,
   1.010145,
   1.022081,
   1.183404};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp3_felx3013[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp3_fely3013[4] = {
   0.05946068,
   0.05274568,
   0.05185687,
   0.0644747};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp3_fehx3013[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp3_fehy3013[4] = {
   0.06012074,
   0.05060695,
   0.04848365,
   0.06277897};
   grae = new TGraphAsymmErrors(4,zj_etaj_8TeV_400_1001_0ratiocomp3_fx3013,zj_etaj_8TeV_400_1001_0ratiocomp3_fy3013,zj_etaj_8TeV_400_1001_0ratiocomp3_felx3013,zj_etaj_8TeV_400_1001_0ratiocomp3_fehx3013,zj_etaj_8TeV_400_1001_0ratiocomp3_fely3013,zj_etaj_8TeV_400_1001_0ratiocomp3_fehy3013);
   grae->SetName("zj_etaj_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013 = new TH1F("Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013","",100,2.375,4.175);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->SetMinimum(0.51);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->SetMaximum(1.49);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->SetDirectory(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->SetStats(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->SetLineWidth(2);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->SetMarkerStyle(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetXaxis()->SetNdivisions(4);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetXaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetXaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetYaxis()->SetTitle("Ratio");
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetYaxis()->CenterTitle(true);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetYaxis()->SetNdivisions(505);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetYaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetYaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetZaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_etaj_8TeV_400_1001_0ratiocomp33013);
   
   grae->Draw("p1");
   
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp4_fx3014[4] = {
   2.375,
   2.875,
   3.375,
   3.875};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp4_fy3014[4] = {
   1.13269,
   1.103467,
   1.084791,
   1.273825};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp4_felx3014[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp4_fely3014[4] = {
   0.09176385,
   0.0892915,
   0.08400049,
   0.1332464};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp4_fehx3014[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_etaj_8TeV_400_1001_0ratiocomp4_fehy3014[4] = {
   0.1087573,
   0.09121756,
   0.09761085,
   0.1188627};
   grae = new TGraphAsymmErrors(4,zj_etaj_8TeV_400_1001_0ratiocomp4_fx3014,zj_etaj_8TeV_400_1001_0ratiocomp4_fy3014,zj_etaj_8TeV_400_1001_0ratiocomp4_felx3014,zj_etaj_8TeV_400_1001_0ratiocomp4_fehx3014,zj_etaj_8TeV_400_1001_0ratiocomp4_fely3014,zj_etaj_8TeV_400_1001_0ratiocomp4_fehy3014);
   grae->SetName("zj_etaj_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014 = new TH1F("Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014","",100,2.225,4.025);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->SetMinimum(0.51);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->SetMaximum(1.49);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->SetDirectory(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->SetStats(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->SetLineWidth(2);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->SetMarkerStyle(0);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetXaxis()->SetNdivisions(4);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetXaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetXaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetYaxis()->SetTitle("Ratio");
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetYaxis()->CenterTitle(true);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetYaxis()->SetNdivisions(505);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetYaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetYaxis()->SetTitleFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetZaxis()->SetLabelFont(132);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_etaj_8TeV_400_1001_0ratiocomp43014);
   
   grae->Draw("p1");
   Double_t xAxis12[5] = {2.2, 2.7, 3.2, 3.7, 4.2}; 
   
   TH1F *zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12 = new TH1F("zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12","z_etaj",4, xAxis12);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinContent(1,1);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinContent(2,1);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinContent(3,1);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinContent(4,1);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinContent(5,0.3937815);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinError(1,0.05188004);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinError(2,0.05322711);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinError(3,0.05845457);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinError(4,0.1090817);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetBinError(5,0.04295435);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetMinimum(0.51);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetMaximum(1.49);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetEntries(14);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetDirectory(0);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetLineColor(ci);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetMarkerColor(ci);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->SetMarkerStyle(0);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetXaxis()->SetTitle("#it{#eta}^{jet}");
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetXaxis()->SetNdivisions(4);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetXaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetXaxis()->SetLabelOffset(0.02);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetXaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetXaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetXaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->SetTitle("Ratio");
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->CenterTitle(true);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->SetNdivisions(505);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->SetTickLength(0.12325);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->SetTitleOffset(1.3);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetYaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetZaxis()->SetLabelFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetZaxis()->SetLabelSize(0.05);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetZaxis()->SetTitleSize(0.06);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->GetZaxis()->SetTitleFont(132);
   zj_etaj_8TeV_400_1001_0ratiocomp0_copy__12->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
