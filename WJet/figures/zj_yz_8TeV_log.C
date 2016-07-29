void zj_yz_8TeV_log()
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
   upperPad->Range(1.567901,-1.591343,4.654321,1.123855);
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
   Double_t xAxis25[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *z_y_toterr__25 = new TH1F("z_y_toterr__25","z_y",4, xAxis25);
   z_y_toterr__25->SetBinContent(1,2.185837);
   z_y_toterr__25->SetBinContent(2,4.879675);
   z_y_toterr__25->SetBinContent(3,3.628071);
   z_y_toterr__25->SetBinContent(4,0.4349621);
   z_y_toterr__25->SetBinContent(5,0.4349621);
   z_y_toterr__25->SetBinError(1,0.1364841);
   z_y_toterr__25->SetBinError(2,0.2553951);
   z_y_toterr__25->SetBinError(3,0.2095409);
   z_y_toterr__25->SetBinError(4,0.03159313);
   z_y_toterr__25->SetBinError(5,0.03159313);
   z_y_toterr__25->SetEntries(9);
   z_y_toterr__25->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   z_y_toterr__25->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr__25->SetLineColor(ci);
   z_y_toterr__25->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr__25->SetMarkerColor(ci);
   z_y_toterr__25->SetMarkerStyle(0);
   z_y_toterr__25->GetXaxis()->SetNdivisions(4);
   z_y_toterr__25->GetXaxis()->SetLabelFont(132);
   z_y_toterr__25->GetXaxis()->SetLabelOffset(999);
   z_y_toterr__25->GetXaxis()->SetLabelSize(0);
   z_y_toterr__25->GetXaxis()->SetTitleSize(0.06);
   z_y_toterr__25->GetXaxis()->SetTitleFont(132);
   z_y_toterr__25->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   z_y_toterr__25->GetYaxis()->SetLabelFont(132);
   z_y_toterr__25->GetYaxis()->SetLabelSize(0.05);
   z_y_toterr__25->GetYaxis()->SetTitleSize(0.06);
   z_y_toterr__25->GetYaxis()->SetTitleOffset(1.3);
   z_y_toterr__25->GetYaxis()->SetTitleFont(132);
   z_y_toterr__25->GetZaxis()->SetLabelFont(132);
   z_y_toterr__25->GetZaxis()->SetLabelSize(0.05);
   z_y_toterr__25->GetZaxis()->SetTitleSize(0.06);
   z_y_toterr__25->GetZaxis()->SetTitleFont(132);
   z_y_toterr__25->Draw("e2");
   Double_t xAxis26[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *z_y_staterr__26 = new TH1F("z_y_staterr__26","z_y",4, xAxis26);
   z_y_staterr__26->SetBinContent(1,2.185837);
   z_y_staterr__26->SetBinContent(2,4.879675);
   z_y_staterr__26->SetBinContent(3,3.628071);
   z_y_staterr__26->SetBinContent(4,0.4349621);
   z_y_staterr__26->SetBinContent(5,0.4349621);
   z_y_staterr__26->SetBinError(1,0.05898224);
   z_y_staterr__26->SetBinError(2,0.08434909);
   z_y_staterr__26->SetBinError(3,0.07099095);
   z_y_staterr__26->SetBinError(4,0.01698204);
   z_y_staterr__26->SetBinError(5,0.01698204);
   z_y_staterr__26->SetEntries(9);
   z_y_staterr__26->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   z_y_staterr__26->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   z_y_staterr__26->SetLineColor(ci);
   z_y_staterr__26->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   z_y_staterr__26->SetMarkerColor(ci);
   z_y_staterr__26->SetMarkerStyle(0);
   z_y_staterr__26->GetXaxis()->SetNdivisions(4);
   z_y_staterr__26->GetXaxis()->SetLabelFont(132);
   z_y_staterr__26->GetXaxis()->SetLabelOffset(999);
   z_y_staterr__26->GetXaxis()->SetLabelSize(0);
   z_y_staterr__26->GetXaxis()->SetTitleSize(0.06);
   z_y_staterr__26->GetXaxis()->SetTitleFont(132);
   z_y_staterr__26->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   z_y_staterr__26->GetYaxis()->SetLabelFont(132);
   z_y_staterr__26->GetYaxis()->SetLabelSize(0.05);
   z_y_staterr__26->GetYaxis()->SetTitleSize(0.06);
   z_y_staterr__26->GetYaxis()->SetTitleFont(132);
   z_y_staterr__26->GetZaxis()->SetLabelFont(132);
   z_y_staterr__26->GetZaxis()->SetLabelSize(0.05);
   z_y_staterr__26->GetZaxis()->SetTitleSize(0.06);
   z_y_staterr__26->GetZaxis()->SetTitleFont(132);
   z_y_staterr__26->Draw("e2same");
   
   Double_t yz_toterrs_fx3029[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t yz_toterrs_fy3029[4] = {
   2.22476,
   4.844015,
   3.54881,
   0.4022607};
   Double_t yz_toterrs_felx3029[4] = {
   0,
   0,
   0,
   0};
   Double_t yz_toterrs_fely3029[4] = {
   0.2006029,
   0.356475,
   0.2605432,
   0.06093241};
   Double_t yz_toterrs_fehx3029[4] = {
   0,
   0,
   0,
   0};
   Double_t yz_toterrs_fehy3029[4] = {
   0.1405623,
   0.3214376,
   0.2546509,
   0.04976848};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,yz_toterrs_fx3029,yz_toterrs_fy3029,yz_toterrs_felx3029,yz_toterrs_fehx3029,yz_toterrs_fely3029,yz_toterrs_fehy3029);
   grae->SetName("yz_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_yz_toterrs3029 = new TH1F("Graph_yz_toterrs3029","",100,2.1425,4.3325);
   Graph_yz_toterrs3029->SetMinimum(0.3071955);
   Graph_yz_toterrs3029->SetMaximum(5.647865);
   Graph_yz_toterrs3029->SetDirectory(0);
   Graph_yz_toterrs3029->SetStats(0);
   Graph_yz_toterrs3029->SetLineWidth(2);
   Graph_yz_toterrs3029->SetMarkerStyle(0);
   Graph_yz_toterrs3029->GetXaxis()->SetNdivisions(4);
   Graph_yz_toterrs3029->GetXaxis()->SetLabelFont(132);
   Graph_yz_toterrs3029->GetXaxis()->SetLabelOffset(999);
   Graph_yz_toterrs3029->GetXaxis()->SetLabelSize(0);
   Graph_yz_toterrs3029->GetXaxis()->SetTitleSize(0.06);
   Graph_yz_toterrs3029->GetXaxis()->SetTitleFont(132);
   Graph_yz_toterrs3029->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   Graph_yz_toterrs3029->GetYaxis()->SetLabelFont(132);
   Graph_yz_toterrs3029->GetYaxis()->SetLabelSize(0.05);
   Graph_yz_toterrs3029->GetYaxis()->SetTitleSize(0.06);
   Graph_yz_toterrs3029->GetYaxis()->SetTitleFont(132);
   Graph_yz_toterrs3029->GetZaxis()->SetLabelFont(132);
   Graph_yz_toterrs3029->GetZaxis()->SetLabelSize(0.05);
   Graph_yz_toterrs3029->GetZaxis()->SetTitleSize(0.06);
   Graph_yz_toterrs3029->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_yz_toterrs3029);
   
   grae->Draw("p1p");
   
   Double_t _fx3030[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t _fy3030[4] = {
   2.22476,
   4.844015,
   3.54881,
   0.4022607};
   Double_t _felx3030[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3030[4] = {
   0.1155136,
   0.2531385,
   0.1966617,
   0.02826533};
   Double_t _fehx3030[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3030[4] = {
   0.1111548,
   0.2410007,
   0.1939836,
   0.03140715};
   grae = new TGraphAsymmErrors(4,_fx3030,_fy3030,_felx3030,_fehx3030,_fely3030,_fehy3030);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3030 = new TH1F("Graph_Graph3030","",100,2.1425,4.3325);
   Graph_Graph3030->SetMinimum(0.3365958);
   Graph_Graph3030->SetMaximum(5.556118);
   Graph_Graph3030->SetDirectory(0);
   Graph_Graph3030->SetStats(0);
   Graph_Graph3030->SetLineWidth(2);
   Graph_Graph3030->SetMarkerStyle(0);
   Graph_Graph3030->GetXaxis()->SetNdivisions(4);
   Graph_Graph3030->GetXaxis()->SetLabelFont(132);
   Graph_Graph3030->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3030->GetXaxis()->SetLabelSize(0);
   Graph_Graph3030->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3030->GetXaxis()->SetTitleFont(132);
   Graph_Graph3030->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   Graph_Graph3030->GetYaxis()->SetLabelFont(132);
   Graph_Graph3030->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3030->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3030->GetYaxis()->SetTitleFont(132);
   Graph_Graph3030->GetZaxis()->SetLabelFont(132);
   Graph_Graph3030->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3030->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3030->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3030);
   
   grae->Draw("p1p");
   
   Double_t yz_toterrs_fx3031[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t yz_toterrs_fy3031[4] = {
   2.460021,
   5.444098,
   4.015299,
   0.4541293};
   Double_t yz_toterrs_felx3031[4] = {
   0,
   0,
   0,
   0};
   Double_t yz_toterrs_fely3031[4] = {
   0.1845896,
   0.4251943,
   0.332433,
   0.0610496};
   Double_t yz_toterrs_fehx3031[4] = {
   0,
   0,
   0,
   0};
   Double_t yz_toterrs_fehy3031[4] = {
   0.1961081,
   0.4397508,
   0.3843861,
   0.06742976};
   grae = new TGraphAsymmErrors(4,yz_toterrs_fx3031,yz_toterrs_fy3031,yz_toterrs_felx3031,yz_toterrs_fehx3031,yz_toterrs_fely3031,yz_toterrs_fehy3031);
   grae->SetName("yz_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_yz_toterrs3031 = new TH1F("Graph_yz_toterrs3031","",100,2.0075,4.0175);
   Graph_yz_toterrs3031->SetMinimum(0.3537717);
   Graph_yz_toterrs3031->SetMaximum(6.432925);
   Graph_yz_toterrs3031->SetDirectory(0);
   Graph_yz_toterrs3031->SetStats(0);
   Graph_yz_toterrs3031->SetLineWidth(2);
   Graph_yz_toterrs3031->SetMarkerStyle(0);
   Graph_yz_toterrs3031->GetXaxis()->SetNdivisions(4);
   Graph_yz_toterrs3031->GetXaxis()->SetLabelFont(132);
   Graph_yz_toterrs3031->GetXaxis()->SetLabelOffset(999);
   Graph_yz_toterrs3031->GetXaxis()->SetLabelSize(0);
   Graph_yz_toterrs3031->GetXaxis()->SetTitleSize(0.06);
   Graph_yz_toterrs3031->GetXaxis()->SetTitleFont(132);
   Graph_yz_toterrs3031->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   Graph_yz_toterrs3031->GetYaxis()->SetLabelFont(132);
   Graph_yz_toterrs3031->GetYaxis()->SetLabelSize(0.05);
   Graph_yz_toterrs3031->GetYaxis()->SetTitleSize(0.06);
   Graph_yz_toterrs3031->GetYaxis()->SetTitleFont(132);
   Graph_yz_toterrs3031->GetZaxis()->SetLabelFont(132);
   Graph_yz_toterrs3031->GetZaxis()->SetLabelSize(0.05);
   Graph_yz_toterrs3031->GetZaxis()->SetTitleSize(0.06);
   Graph_yz_toterrs3031->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_yz_toterrs3031);
   
   grae->Draw("p1p");
   
   Double_t _fx3032[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t _fy3032[4] = {
   2.460021,
   5.444098,
   4.015299,
   0.4541293};
   Double_t _felx3032[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3032[4] = {
   0.150059,
   0.3283963,
   0.2580678,
   0.03286934};
   Double_t _fehx3032[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3032[4] = {
   0.1642063,
   0.3603582,
   0.2895746,
   0.03804311};
   grae = new TGraphAsymmErrors(4,_fx3032,_fy3032,_felx3032,_fehx3032,_fely3032,_fehy3032);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3032 = new TH1F("Graph_Graph3032","",100,2.0075,4.0175);
   Graph_Graph3032->SetMinimum(0.379134);
   Graph_Graph3032->SetMaximum(6.342775);
   Graph_Graph3032->SetDirectory(0);
   Graph_Graph3032->SetStats(0);
   Graph_Graph3032->SetLineWidth(2);
   Graph_Graph3032->SetMarkerStyle(0);
   Graph_Graph3032->GetXaxis()->SetNdivisions(4);
   Graph_Graph3032->GetXaxis()->SetLabelFont(132);
   Graph_Graph3032->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3032->GetXaxis()->SetLabelSize(0);
   Graph_Graph3032->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3032->GetXaxis()->SetTitleFont(132);
   Graph_Graph3032->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   Graph_Graph3032->GetYaxis()->SetLabelFont(132);
   Graph_Graph3032->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3032->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3032->GetYaxis()->SetTitleFont(132);
   Graph_Graph3032->GetZaxis()->SetLabelFont(132);
   Graph_Graph3032->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3032->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3032->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3032);
   
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
   Double_t xAxis27[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *z_y_toterr_copy__27 = new TH1F("z_y_toterr_copy__27","z_y",4, xAxis27);
   z_y_toterr_copy__27->SetBinContent(1,2.185837);
   z_y_toterr_copy__27->SetBinContent(2,4.879675);
   z_y_toterr_copy__27->SetBinContent(3,3.628071);
   z_y_toterr_copy__27->SetBinContent(4,0.4349621);
   z_y_toterr_copy__27->SetBinContent(5,0.4349621);
   z_y_toterr_copy__27->SetBinError(1,0.1364841);
   z_y_toterr_copy__27->SetBinError(2,0.2553951);
   z_y_toterr_copy__27->SetBinError(3,0.2095409);
   z_y_toterr_copy__27->SetBinError(4,0.03159313);
   z_y_toterr_copy__27->SetBinError(5,0.03159313);
   z_y_toterr_copy__27->SetEntries(9);
   z_y_toterr_copy__27->SetDirectory(0);
   z_y_toterr_copy__27->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr_copy__27->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr_copy__27->SetLineColor(ci);
   z_y_toterr_copy__27->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_y_toterr_copy__27->SetMarkerColor(ci);
   z_y_toterr_copy__27->SetMarkerStyle(0);
   z_y_toterr_copy__27->GetXaxis()->SetNdivisions(4);
   z_y_toterr_copy__27->GetXaxis()->SetLabelFont(132);
   z_y_toterr_copy__27->GetXaxis()->SetLabelOffset(999);
   z_y_toterr_copy__27->GetXaxis()->SetLabelSize(0);
   z_y_toterr_copy__27->GetXaxis()->SetTitleSize(0.06);
   z_y_toterr_copy__27->GetXaxis()->SetTitleFont(132);
   z_y_toterr_copy__27->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{y^{Z}} [pb]");
   z_y_toterr_copy__27->GetYaxis()->SetLabelFont(132);
   z_y_toterr_copy__27->GetYaxis()->SetLabelSize(0.05);
   z_y_toterr_copy__27->GetYaxis()->SetTitleSize(0.06);
   z_y_toterr_copy__27->GetYaxis()->SetTitleOffset(1.3);
   z_y_toterr_copy__27->GetYaxis()->SetTitleFont(132);
   z_y_toterr_copy__27->GetZaxis()->SetLabelFont(132);
   z_y_toterr_copy__27->GetZaxis()->SetLabelSize(0.05);
   z_y_toterr_copy__27->GetZaxis()->SetTitleSize(0.06);
   z_y_toterr_copy__27->GetZaxis()->SetTitleFont(132);
   z_y_toterr_copy__27->Draw("sameaxis");
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
   Double_t xAxis28[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *zj_yz_8TeV_log_400_1001_0ratiocomp0__28 = new TH1F("zj_yz_8TeV_log_400_1001_0ratiocomp0__28","z_y",4, xAxis28);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinContent(1,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinContent(2,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinContent(3,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinContent(4,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinContent(5,0.4349621);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinError(1,0.06244019);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinError(2,0.05233856);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinError(3,0.05775547);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinError(4,0.07263422);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetBinError(5,0.03159313);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetMinimum(0.51);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetMaximum(1.49);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetEntries(13);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetLineColor(ci);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetMarkerColor(ci);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->SetMarkerStyle(0);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetXaxis()->SetTitle("#it{y^{Z}}");
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetXaxis()->SetNdivisions(4);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetXaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetXaxis()->SetLabelOffset(0.02);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetXaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetXaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetXaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->SetTitle("Ratio");
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->CenterTitle(true);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->SetNdivisions(505);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->SetTickLength(0.12325);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->SetTitleOffset(1.3);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetYaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetZaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetZaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetZaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->GetZaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0__28->Draw("e2");
   Double_t xAxis29[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *zj_yz_8TeV_log_400_1001_0ratiocomp1__29 = new TH1F("zj_yz_8TeV_log_400_1001_0ratiocomp1__29","z_y",4, xAxis29);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinContent(1,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinContent(2,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinContent(3,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinContent(4,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinContent(5,0.4349621);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinError(1,0.02698382);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinError(2,0.0172858);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinError(3,0.01956713);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinError(4,0.03904257);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetBinError(5,0.01698204);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetMinimum(0.51);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetMaximum(1.49);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetEntries(13);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetLineColor(ci);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetMarkerColor(ci);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->SetMarkerStyle(0);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetXaxis()->SetTitle("#it{y^{Z}}");
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetXaxis()->SetNdivisions(4);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetXaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetXaxis()->SetLabelOffset(0.02);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetXaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetXaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetXaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetYaxis()->SetTitle("Ratio");
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetYaxis()->CenterTitle(true);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetYaxis()->SetNdivisions(505);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetYaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetYaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetYaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetYaxis()->SetTickLength(0.12325);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetYaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetZaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetZaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetZaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->GetZaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp1__29->Draw("e2same");
   
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp2_fx3033[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp2_fy3033[4] = {
   1.017807,
   0.9926922,
   0.9781535,
   0.9248179};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp2_felx3033[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp2_fely3033[4] = {
   0.09177396,
   0.07305303,
   0.07181315,
   0.1400867};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp2_fehx3033[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp2_fehy3033[4] = {
   0.06430594,
   0.06587274,
   0.07018905,
   0.1144203};
   grae = new TGraphAsymmErrors(4,zj_yz_8TeV_log_400_1001_0ratiocomp2_fx3033,zj_yz_8TeV_log_400_1001_0ratiocomp2_fy3033,zj_yz_8TeV_log_400_1001_0ratiocomp2_felx3033,zj_yz_8TeV_log_400_1001_0ratiocomp2_fehx3033,zj_yz_8TeV_log_400_1001_0ratiocomp2_fely3033,zj_yz_8TeV_log_400_1001_0ratiocomp2_fehy3033);
   grae->SetName("zj_yz_8TeV_log_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033 = new TH1F("Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033","",100,2.1425,4.3325);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->SetMinimum(0.51);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->SetMaximum(1.49);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->SetDirectory(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->SetStats(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->SetLineWidth(2);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->SetMarkerStyle(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetXaxis()->SetTitle("#it{y^{Z}}");
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetXaxis()->SetNdivisions(4);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetXaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetXaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetYaxis()->SetTitle("Ratio");
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetYaxis()->CenterTitle(true);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetYaxis()->SetNdivisions(505);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetYaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetYaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetZaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_yz_8TeV_log_400_1001_0ratiocomp23033);
   
   grae->Draw("p1");
   
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp3_fx3034[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp3_fy3034[4] = {
   1.017807,
   0.9926922,
   0.9781535,
   0.9248179};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp3_felx3034[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp3_fely3034[4] = {
   0.05284637,
   0.05187611,
   0.05420559,
   0.06498343};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp3_fehx3034[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp3_fehy3034[4] = {
   0.05085227,
   0.04938867,
   0.05346741,
   0.07220664};
   grae = new TGraphAsymmErrors(4,zj_yz_8TeV_log_400_1001_0ratiocomp3_fx3034,zj_yz_8TeV_log_400_1001_0ratiocomp3_fy3034,zj_yz_8TeV_log_400_1001_0ratiocomp3_felx3034,zj_yz_8TeV_log_400_1001_0ratiocomp3_fehx3034,zj_yz_8TeV_log_400_1001_0ratiocomp3_fely3034,zj_yz_8TeV_log_400_1001_0ratiocomp3_fehy3034);
   grae->SetName("zj_yz_8TeV_log_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034 = new TH1F("Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034","",100,2.1425,4.3325);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->SetMinimum(0.51);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->SetMaximum(1.49);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->SetDirectory(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->SetStats(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->SetLineWidth(2);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->SetMarkerStyle(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetXaxis()->SetTitle("#it{y^{Z}}");
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetXaxis()->SetNdivisions(4);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetXaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetXaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetYaxis()->SetTitle("Ratio");
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetYaxis()->CenterTitle(true);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetYaxis()->SetNdivisions(505);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetYaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetYaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetZaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_yz_8TeV_log_400_1001_0ratiocomp33034);
   
   grae->Draw("p1");
   
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp4_fx3035[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp4_fy3035[4] = {
   1.125437,
   1.115668,
   1.106731,
   1.044066};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp4_felx3035[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp4_fely3035[4] = {
   0.08444803,
   0.08713578,
   0.09162804,
   0.1403561};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp4_fehx3035[4] = {
   0,
   0,
   0,
   0};
   Double_t zj_yz_8TeV_log_400_1001_0ratiocomp4_fehy3035[4] = {
   0.08971762,
   0.09011887,
   0.1059478,
   0.1550245};
   grae = new TGraphAsymmErrors(4,zj_yz_8TeV_log_400_1001_0ratiocomp4_fx3035,zj_yz_8TeV_log_400_1001_0ratiocomp4_fy3035,zj_yz_8TeV_log_400_1001_0ratiocomp4_felx3035,zj_yz_8TeV_log_400_1001_0ratiocomp4_fehx3035,zj_yz_8TeV_log_400_1001_0ratiocomp4_fely3035,zj_yz_8TeV_log_400_1001_0ratiocomp4_fehy3035);
   grae->SetName("zj_yz_8TeV_log_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035 = new TH1F("Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035","",100,2.0075,4.0175);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->SetMinimum(0.51);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->SetMaximum(1.49);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->SetDirectory(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->SetStats(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->SetLineWidth(2);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->SetMarkerStyle(0);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetXaxis()->SetTitle("#it{y^{Z}}");
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetXaxis()->SetNdivisions(4);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetXaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetXaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetYaxis()->SetTitle("Ratio");
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetYaxis()->CenterTitle(true);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetYaxis()->SetNdivisions(505);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetYaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetYaxis()->SetTitleFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetZaxis()->SetLabelFont(132);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_yz_8TeV_log_400_1001_0ratiocomp43035);
   
   grae->Draw("p1");
   Double_t xAxis30[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30 = new TH1F("zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30","z_y",4, xAxis30);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinContent(1,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinContent(2,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinContent(3,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinContent(4,1);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinContent(5,0.4349621);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinError(1,0.06244019);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinError(2,0.05233856);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinError(3,0.05775547);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinError(4,0.07263422);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetBinError(5,0.03159313);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetMinimum(0.51);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetMaximum(1.49);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetEntries(13);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetDirectory(0);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetLineColor(ci);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetMarkerColor(ci);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->SetMarkerStyle(0);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetXaxis()->SetTitle("#it{y^{Z}}");
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetXaxis()->SetNdivisions(4);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetXaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetXaxis()->SetLabelOffset(0.02);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetXaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetXaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetXaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->SetTitle("Ratio");
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->CenterTitle(true);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->SetNdivisions(505);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->SetTickLength(0.12325);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->SetTitleOffset(1.3);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetYaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetZaxis()->SetLabelFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetZaxis()->SetLabelSize(0.05);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetZaxis()->SetTitleSize(0.06);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->GetZaxis()->SetTitleFont(132);
   zj_yz_8TeV_log_400_1001_0ratiocomp0_copy__30->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
