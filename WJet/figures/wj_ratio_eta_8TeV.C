void wj_ratio_eta_8TeV()
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
   upperPad->Range(1.567901,-1.847581,4.654321,3.781452);
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
   Double_t xAxis160[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_r_eta_toterr__190 = new TH1F("w_r_eta_toterr__190","w_eta",4, xAxis160);
   w_r_eta_toterr__190->SetBinContent(1,2.19025);
   w_r_eta_toterr__190->SetBinContent(2,1.898889);
   w_r_eta_toterr__190->SetBinContent(3,1.529143);
   w_r_eta_toterr__190->SetBinContent(4,0.9650988);
   w_r_eta_toterr__190->SetBinContent(5,0.9650988);
   w_r_eta_toterr__190->SetBinError(1,0.07464207);
   w_r_eta_toterr__190->SetBinError(2,0.0660939);
   w_r_eta_toterr__190->SetBinError(3,0.06010184);
   w_r_eta_toterr__190->SetBinError(4,0.06616402);
   w_r_eta_toterr__190->SetBinError(5,0.06616402);
   w_r_eta_toterr__190->SetMinimum(0.01);
   w_r_eta_toterr__190->SetMaximum(3.5);
   w_r_eta_toterr__190->SetEntries(6);
   w_r_eta_toterr__190->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr__190->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr__190->SetLineColor(ci);
   w_r_eta_toterr__190->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr__190->SetMarkerColor(ci);
   w_r_eta_toterr__190->SetMarkerStyle(0);
   w_r_eta_toterr__190->GetXaxis()->SetRange(1,4);
   w_r_eta_toterr__190->GetXaxis()->SetNdivisions(4);
   w_r_eta_toterr__190->GetXaxis()->SetLabelFont(132);
   w_r_eta_toterr__190->GetXaxis()->SetLabelOffset(999);
   w_r_eta_toterr__190->GetXaxis()->SetLabelSize(0);
   w_r_eta_toterr__190->GetXaxis()->SetTitleSize(0.06);
   w_r_eta_toterr__190->GetXaxis()->SetTitleFont(132);
   w_r_eta_toterr__190->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_eta_toterr__190->GetYaxis()->SetLabelFont(132);
   w_r_eta_toterr__190->GetYaxis()->SetLabelSize(0.05);
   w_r_eta_toterr__190->GetYaxis()->SetTitleSize(0.06);
   w_r_eta_toterr__190->GetYaxis()->SetTitleFont(132);
   w_r_eta_toterr__190->GetZaxis()->SetLabelFont(132);
   w_r_eta_toterr__190->GetZaxis()->SetLabelSize(0.05);
   w_r_eta_toterr__190->GetZaxis()->SetTitleSize(0.06);
   w_r_eta_toterr__190->GetZaxis()->SetTitleFont(132);
   w_r_eta_toterr__190->Draw("e2");
   Double_t xAxis161[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_r_eta_staterr__191 = new TH1F("w_r_eta_staterr__191","w_eta",4, xAxis161);
   w_r_eta_staterr__191->SetBinContent(1,2.19025);
   w_r_eta_staterr__191->SetBinContent(2,1.898889);
   w_r_eta_staterr__191->SetBinContent(3,1.529143);
   w_r_eta_staterr__191->SetBinContent(4,0.9650988);
   w_r_eta_staterr__191->SetBinContent(5,0.9650988);
   w_r_eta_staterr__191->SetBinError(1,0.02689882);
   w_r_eta_staterr__191->SetBinError(2,0.02202789);
   w_r_eta_staterr__191->SetBinError(3,0.02055473);
   w_r_eta_staterr__191->SetBinError(4,0.01726767);
   w_r_eta_staterr__191->SetBinError(5,0.01726767);
   w_r_eta_staterr__191->SetMinimum(0.01);
   w_r_eta_staterr__191->SetMaximum(3.5);
   w_r_eta_staterr__191->SetEntries(6);
   w_r_eta_staterr__191->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   w_r_eta_staterr__191->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   w_r_eta_staterr__191->SetLineColor(ci);
   w_r_eta_staterr__191->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   w_r_eta_staterr__191->SetMarkerColor(ci);
   w_r_eta_staterr__191->SetMarkerStyle(0);
   w_r_eta_staterr__191->GetXaxis()->SetRange(1,4);
   w_r_eta_staterr__191->GetXaxis()->SetNdivisions(4);
   w_r_eta_staterr__191->GetXaxis()->SetLabelFont(132);
   w_r_eta_staterr__191->GetXaxis()->SetLabelOffset(999);
   w_r_eta_staterr__191->GetXaxis()->SetLabelSize(0);
   w_r_eta_staterr__191->GetXaxis()->SetTitleSize(0.06);
   w_r_eta_staterr__191->GetXaxis()->SetTitleFont(132);
   w_r_eta_staterr__191->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_eta_staterr__191->GetYaxis()->SetLabelFont(132);
   w_r_eta_staterr__191->GetYaxis()->SetLabelSize(0.05);
   w_r_eta_staterr__191->GetYaxis()->SetTitleSize(0.06);
   w_r_eta_staterr__191->GetYaxis()->SetTitleFont(132);
   w_r_eta_staterr__191->GetZaxis()->SetLabelFont(132);
   w_r_eta_staterr__191->GetZaxis()->SetLabelSize(0.05);
   w_r_eta_staterr__191->GetZaxis()->SetTitleSize(0.06);
   w_r_eta_staterr__191->GetZaxis()->SetTitleFont(132);
   w_r_eta_staterr__191->Draw("e2same");
   
   Double_t ratio_eta_toterrs_fx3232[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t ratio_eta_toterrs_fy3232[4] = {
   1.9167,
   1.810688,
   1.398955,
   0.9084675};
   Double_t ratio_eta_toterrs_felx3232[4] = {
   0,
   0,
   0,
   0};
   Double_t ratio_eta_toterrs_fely3232[4] = {
   0.0320084,
   0.04428531,
   0.08207213,
   0.07479894};
   Double_t ratio_eta_toterrs_fehx3232[4] = {
   0,
   0,
   0,
   0};
   Double_t ratio_eta_toterrs_fehy3232[4] = {
   0.07412408,
   0.04531405,
   0.06666425,
   0.07666142};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,ratio_eta_toterrs_fx3232,ratio_eta_toterrs_fy3232,ratio_eta_toterrs_felx3232,ratio_eta_toterrs_fehx3232,ratio_eta_toterrs_fely3232,ratio_eta_toterrs_fehy3232);
   grae->SetName("ratio_eta_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_ratio_eta_toterrs3232 = new TH1F("Graph_ratio_eta_toterrs3232","",100,2.1425,4.3325);
   Graph_ratio_eta_toterrs3232->SetMinimum(0.01);
   Graph_ratio_eta_toterrs3232->SetMaximum(3.5);
   Graph_ratio_eta_toterrs3232->SetDirectory(0);
   Graph_ratio_eta_toterrs3232->SetStats(0);
   Graph_ratio_eta_toterrs3232->SetLineWidth(2);
   Graph_ratio_eta_toterrs3232->SetMarkerStyle(0);
   Graph_ratio_eta_toterrs3232->GetXaxis()->SetRange(0,101);
   Graph_ratio_eta_toterrs3232->GetXaxis()->SetNdivisions(4);
   Graph_ratio_eta_toterrs3232->GetXaxis()->SetLabelFont(132);
   Graph_ratio_eta_toterrs3232->GetXaxis()->SetLabelOffset(999);
   Graph_ratio_eta_toterrs3232->GetXaxis()->SetLabelSize(0);
   Graph_ratio_eta_toterrs3232->GetXaxis()->SetTitleSize(0.06);
   Graph_ratio_eta_toterrs3232->GetXaxis()->SetTitleFont(132);
   Graph_ratio_eta_toterrs3232->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_ratio_eta_toterrs3232->GetYaxis()->SetLabelFont(132);
   Graph_ratio_eta_toterrs3232->GetYaxis()->SetLabelSize(0.05);
   Graph_ratio_eta_toterrs3232->GetYaxis()->SetTitleSize(0.06);
   Graph_ratio_eta_toterrs3232->GetYaxis()->SetTitleFont(132);
   Graph_ratio_eta_toterrs3232->GetZaxis()->SetLabelFont(132);
   Graph_ratio_eta_toterrs3232->GetZaxis()->SetLabelSize(0.05);
   Graph_ratio_eta_toterrs3232->GetZaxis()->SetTitleSize(0.06);
   Graph_ratio_eta_toterrs3232->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ratio_eta_toterrs3232);
   
   grae->Draw("p1p");
   
   Double_t _fx3233[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t _fy3233[4] = {
   1.9167,
   1.810688,
   1.398955,
   0.9084675};
   Double_t _felx3233[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3233[4] = {
   0.01016915,
   0.008714437,
   0.01437879,
   0.004769564};
   Double_t _fehx3233[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3233[4] = {
   0.006626129,
   0.01491261,
   0.01178885,
   0.005902946};
   grae = new TGraphAsymmErrors(4,_fx3233,_fy3233,_felx3233,_fehx3233,_fely3233,_fehy3233);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3233 = new TH1F("Graph_Graph3233","",100,2.1425,4.3325);
   Graph_Graph3233->SetMinimum(0.01);
   Graph_Graph3233->SetMaximum(3.5);
   Graph_Graph3233->SetDirectory(0);
   Graph_Graph3233->SetStats(0);
   Graph_Graph3233->SetLineWidth(2);
   Graph_Graph3233->SetMarkerStyle(0);
   Graph_Graph3233->GetXaxis()->SetRange(0,101);
   Graph_Graph3233->GetXaxis()->SetNdivisions(4);
   Graph_Graph3233->GetXaxis()->SetLabelFont(132);
   Graph_Graph3233->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3233->GetXaxis()->SetLabelSize(0);
   Graph_Graph3233->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3233->GetXaxis()->SetTitleFont(132);
   Graph_Graph3233->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3233->GetYaxis()->SetLabelFont(132);
   Graph_Graph3233->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3233->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3233->GetYaxis()->SetTitleFont(132);
   Graph_Graph3233->GetZaxis()->SetLabelFont(132);
   Graph_Graph3233->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3233->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3233->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3233);
   
   grae->Draw("p1p");
   
   Double_t ratio_eta_toterrs_fx3234[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t ratio_eta_toterrs_fy3234[4] = {
   1.962667,
   1.840368,
   1.472174,
   0.937293};
   Double_t ratio_eta_toterrs_felx3234[4] = {
   0,
   0,
   0,
   0};
   Double_t ratio_eta_toterrs_fely3234[4] = {
   0.02270708,
   0.04032278,
   0.05539104,
   0.05953985};
   Double_t ratio_eta_toterrs_fehx3234[4] = {
   0,
   0,
   0,
   0};
   Double_t ratio_eta_toterrs_fehy3234[4] = {
   0.025816,
   0.03905986,
   0.04917565,
   0.06394863};
   grae = new TGraphAsymmErrors(4,ratio_eta_toterrs_fx3234,ratio_eta_toterrs_fy3234,ratio_eta_toterrs_felx3234,ratio_eta_toterrs_fehx3234,ratio_eta_toterrs_fely3234,ratio_eta_toterrs_fehy3234);
   grae->SetName("ratio_eta_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ratio_eta_toterrs3234 = new TH1F("Graph_ratio_eta_toterrs3234","",100,2.0075,4.0175);
   Graph_ratio_eta_toterrs3234->SetMinimum(0.01);
   Graph_ratio_eta_toterrs3234->SetMaximum(3.5);
   Graph_ratio_eta_toterrs3234->SetDirectory(0);
   Graph_ratio_eta_toterrs3234->SetStats(0);
   Graph_ratio_eta_toterrs3234->SetLineWidth(2);
   Graph_ratio_eta_toterrs3234->SetMarkerStyle(0);
   Graph_ratio_eta_toterrs3234->GetXaxis()->SetRange(0,101);
   Graph_ratio_eta_toterrs3234->GetXaxis()->SetNdivisions(4);
   Graph_ratio_eta_toterrs3234->GetXaxis()->SetLabelFont(132);
   Graph_ratio_eta_toterrs3234->GetXaxis()->SetLabelOffset(999);
   Graph_ratio_eta_toterrs3234->GetXaxis()->SetLabelSize(0);
   Graph_ratio_eta_toterrs3234->GetXaxis()->SetTitleSize(0.06);
   Graph_ratio_eta_toterrs3234->GetXaxis()->SetTitleFont(132);
   Graph_ratio_eta_toterrs3234->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_ratio_eta_toterrs3234->GetYaxis()->SetLabelFont(132);
   Graph_ratio_eta_toterrs3234->GetYaxis()->SetLabelSize(0.05);
   Graph_ratio_eta_toterrs3234->GetYaxis()->SetTitleSize(0.06);
   Graph_ratio_eta_toterrs3234->GetYaxis()->SetTitleFont(132);
   Graph_ratio_eta_toterrs3234->GetZaxis()->SetLabelFont(132);
   Graph_ratio_eta_toterrs3234->GetZaxis()->SetLabelSize(0.05);
   Graph_ratio_eta_toterrs3234->GetZaxis()->SetTitleSize(0.06);
   Graph_ratio_eta_toterrs3234->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ratio_eta_toterrs3234);
   
   grae->Draw("p1p");
   
   Double_t _fx3235[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t _fy3235[4] = {
   1.962667,
   1.840368,
   1.472174,
   0.937293};
   Double_t _felx3235[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3235[4] = {
   0.0008949041,
   0.00809288,
   0.009610057,
   0.007408142};
   Double_t _fehx3235[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3235[4] = {
   0.001328468,
   0.01045287,
   0.01094544,
   0.009582102};
   grae = new TGraphAsymmErrors(4,_fx3235,_fy3235,_felx3235,_fehx3235,_fely3235,_fehy3235);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3235 = new TH1F("Graph_Graph3235","",100,2.0075,4.0175);
   Graph_Graph3235->SetMinimum(0.01);
   Graph_Graph3235->SetMaximum(3.5);
   Graph_Graph3235->SetDirectory(0);
   Graph_Graph3235->SetStats(0);
   Graph_Graph3235->SetLineWidth(2);
   Graph_Graph3235->SetMarkerStyle(0);
   Graph_Graph3235->GetXaxis()->SetRange(0,101);
   Graph_Graph3235->GetXaxis()->SetNdivisions(4);
   Graph_Graph3235->GetXaxis()->SetLabelFont(132);
   Graph_Graph3235->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3235->GetXaxis()->SetLabelSize(0);
   Graph_Graph3235->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3235->GetXaxis()->SetTitleFont(132);
   Graph_Graph3235->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   Graph_Graph3235->GetYaxis()->SetLabelFont(132);
   Graph_Graph3235->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3235->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3235->GetYaxis()->SetTitleFont(132);
   Graph_Graph3235->GetZaxis()->SetLabelFont(132);
   Graph_Graph3235->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3235->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3235->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3235);
   
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
   Double_t xAxis162[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *w_r_eta_toterr_copy__192 = new TH1F("w_r_eta_toterr_copy__192","w_eta",4, xAxis162);
   w_r_eta_toterr_copy__192->SetBinContent(1,2.19025);
   w_r_eta_toterr_copy__192->SetBinContent(2,1.898889);
   w_r_eta_toterr_copy__192->SetBinContent(3,1.529143);
   w_r_eta_toterr_copy__192->SetBinContent(4,0.9650988);
   w_r_eta_toterr_copy__192->SetBinContent(5,0.9650988);
   w_r_eta_toterr_copy__192->SetBinError(1,0.07464207);
   w_r_eta_toterr_copy__192->SetBinError(2,0.0660939);
   w_r_eta_toterr_copy__192->SetBinError(3,0.06010184);
   w_r_eta_toterr_copy__192->SetBinError(4,0.06616402);
   w_r_eta_toterr_copy__192->SetBinError(5,0.06616402);
   w_r_eta_toterr_copy__192->SetMinimum(0.01);
   w_r_eta_toterr_copy__192->SetMaximum(3.5);
   w_r_eta_toterr_copy__192->SetEntries(6);
   w_r_eta_toterr_copy__192->SetDirectory(0);
   w_r_eta_toterr_copy__192->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr_copy__192->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr_copy__192->SetLineColor(ci);
   w_r_eta_toterr_copy__192->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_r_eta_toterr_copy__192->SetMarkerColor(ci);
   w_r_eta_toterr_copy__192->SetMarkerStyle(0);
   w_r_eta_toterr_copy__192->GetXaxis()->SetRange(1,4);
   w_r_eta_toterr_copy__192->GetXaxis()->SetNdivisions(4);
   w_r_eta_toterr_copy__192->GetXaxis()->SetLabelFont(132);
   w_r_eta_toterr_copy__192->GetXaxis()->SetLabelOffset(999);
   w_r_eta_toterr_copy__192->GetXaxis()->SetLabelSize(0);
   w_r_eta_toterr_copy__192->GetXaxis()->SetTitleSize(0.06);
   w_r_eta_toterr_copy__192->GetXaxis()->SetTitleFont(132);
   w_r_eta_toterr_copy__192->GetYaxis()->SetTitle("R_{#it{W}^{#pm}}");
   w_r_eta_toterr_copy__192->GetYaxis()->SetLabelFont(132);
   w_r_eta_toterr_copy__192->GetYaxis()->SetLabelSize(0.05);
   w_r_eta_toterr_copy__192->GetYaxis()->SetTitleSize(0.06);
   w_r_eta_toterr_copy__192->GetYaxis()->SetTitleFont(132);
   w_r_eta_toterr_copy__192->GetZaxis()->SetLabelFont(132);
   w_r_eta_toterr_copy__192->GetZaxis()->SetLabelSize(0.05);
   w_r_eta_toterr_copy__192->GetZaxis()->SetTitleSize(0.06);
   w_r_eta_toterr_copy__192->GetZaxis()->SetTitleFont(132);
   w_r_eta_toterr_copy__192->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(1.567901,0.2935897,4.654321,3.267949);
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
   Double_t xAxis163[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193 = new TH1F("wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193","w_eta",4, xAxis163);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinContent(1,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinContent(2,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinContent(3,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinContent(4,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinContent(5,0.9650988);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinError(1,0.03407924);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinError(2,0.03480661);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinError(3,0.03930426);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinError(4,0.06855673);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetBinError(5,0.06616402);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetMinimum(0.71);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetMaximum(1.29);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetEntries(10);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetLineColor(ci);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetMarkerColor(ci);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->SetMarkerStyle(0);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetXaxis()->SetRange(1,4);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetXaxis()->SetNdivisions(4);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetXaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetXaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetYaxis()->SetTitle("Ratio");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetYaxis()->CenterTitle(true);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetYaxis()->SetNdivisions(505);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetYaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetYaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetZaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->GetZaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0__193->Draw("e2");
   Double_t xAxis164[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194 = new TH1F("wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194","w_eta",4, xAxis164);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinContent(1,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinContent(2,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinContent(3,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinContent(4,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinContent(5,0.9650988);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinError(1,0.01228116);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinError(2,0.01160041);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinError(3,0.01344199);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinError(4,0.01789213);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetBinError(5,0.01726767);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetMinimum(0.71);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetMaximum(1.29);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetEntries(10);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetLineColor(ci);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetMarkerColor(ci);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->SetMarkerStyle(0);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetXaxis()->SetRange(1,4);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetXaxis()->SetNdivisions(4);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetXaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetXaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetYaxis()->SetTitle("Ratio");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetYaxis()->CenterTitle(true);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetYaxis()->SetNdivisions(505);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetYaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetYaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetZaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->GetZaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp1__194->Draw("e2same");
   
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fx3236[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fy3236[4] = {
   0.8751053,
   0.9535509,
   0.9148621,
   0.9413208};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp2_felx3236[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fely3236[4] = {
   0.01461404,
   0.02332169,
   0.05367198,
   0.07750392};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fehx3236[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fehy3236[4] = {
   0.03384274,
   0.02386345,
   0.04359582,
   0.07943375};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fx3236,wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fy3236,wj_ratio_eta_8TeV_400_1001_0ratiocomp2_felx3236,wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fehx3236,wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fely3236,wj_ratio_eta_8TeV_400_1001_0ratiocomp2_fehy3236);
   grae->SetName("wj_ratio_eta_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236 = new TH1F("Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236","",100,2.1425,4.3325);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->SetMinimum(0.71);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->SetMaximum(1.29);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->SetDirectory(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->SetStats(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->SetLineWidth(2);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->SetMarkerStyle(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetXaxis()->SetRange(0,101);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp23236);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fx3237[4] = {
   2.325,
   2.825,
   3.325,
   4.15};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fy3237[4] = {
   0.8751053,
   0.9535509,
   0.9148621,
   0.9413208};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp3_felx3237[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fely3237[4] = {
   0.004642916,
   0.004589229,
   0.009403166,
   0.004942047};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fehx3237[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fehy3237[4] = {
   0.003025284,
   0.007853331,
   0.007709445,
   0.006116416};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fx3237,wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fy3237,wj_ratio_eta_8TeV_400_1001_0ratiocomp3_felx3237,wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fehx3237,wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fely3237,wj_ratio_eta_8TeV_400_1001_0ratiocomp3_fehy3237);
   grae->SetName("wj_ratio_eta_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237 = new TH1F("Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237","",100,2.1425,4.3325);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->SetMinimum(0.71);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->SetMaximum(1.29);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->SetDirectory(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->SetStats(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->SetLineWidth(2);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->SetMarkerStyle(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetXaxis()->SetRange(0,101);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp33237);
   
   grae->Draw("p1");
   
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fx3238[4] = {
   2.175,
   2.675,
   3.175,
   3.85};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fy3238[4] = {
   0.8960927,
   0.9691813,
   0.9627444,
   0.9711886};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp4_felx3238[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fely3238[4] = {
   0.01036734,
   0.02123493,
   0.03622358,
   0.06169301};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fehx3238[4] = {
   0,
   0,
   0,
   0};
   Double_t wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fehy3238[4] = {
   0.01178678,
   0.02056985,
   0.03215896,
   0.06626123};
   grae = new TGraphAsymmErrors(4,wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fx3238,wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fy3238,wj_ratio_eta_8TeV_400_1001_0ratiocomp4_felx3238,wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fehx3238,wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fely3238,wj_ratio_eta_8TeV_400_1001_0ratiocomp4_fehy3238);
   grae->SetName("wj_ratio_eta_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238 = new TH1F("Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238","",100,2.0075,4.0175);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->SetMinimum(0.71);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->SetMaximum(1.29);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->SetDirectory(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->SetStats(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->SetLineWidth(2);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->SetMarkerStyle(0);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetXaxis()->SetRange(0,101);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetXaxis()->SetNdivisions(4);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetXaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetXaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetYaxis()->SetTitle("Ratio");
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetYaxis()->CenterTitle(true);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetYaxis()->SetNdivisions(505);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetYaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetYaxis()->SetTitleFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetZaxis()->SetLabelFont(132);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_ratio_eta_8TeV_400_1001_0ratiocomp43238);
   
   grae->Draw("p1");
   Double_t xAxis165[5] = {2, 2.5, 3, 3.5, 4.5}; 
   
   TH1F *wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195 = new TH1F("wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195","w_eta",4, xAxis165);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinContent(1,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinContent(2,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinContent(3,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinContent(4,1);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinContent(5,0.9650988);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinError(1,0.03407924);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinError(2,0.03480661);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinError(3,0.03930426);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinError(4,0.06855673);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetBinError(5,0.06616402);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetMinimum(0.71);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetMaximum(1.29);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetEntries(10);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetDirectory(0);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetLineColor(ci);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetMarkerColor(ci);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->SetMarkerStyle(0);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetXaxis()->SetTitle("#it{#eta^{#mu}}");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetXaxis()->SetRange(1,4);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetXaxis()->SetNdivisions(4);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetXaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetXaxis()->SetLabelOffset(0.02);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetXaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetXaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetXaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetYaxis()->SetTitle("Ratio");
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetYaxis()->CenterTitle(true);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetYaxis()->SetNdivisions(505);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetYaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetYaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetYaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetYaxis()->SetTickLength(0.12325);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetYaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetZaxis()->SetLabelFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetZaxis()->SetLabelSize(0.05);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetZaxis()->SetTitleSize(0.06);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->GetZaxis()->SetTitleFont(132);
   wj_ratio_eta_8TeV_400_1001_0ratiocomp0_copy__195->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
