void zj_ptj_8TeV_log()
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
   upperPad->Range(6.172839,-3.216367,104.9383,0.02103618);
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
   Double_t xAxis13[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *z_ptj_toterr__13 = new TH1F("z_ptj_toterr__13","z_ptj",5, xAxis13);
   z_ptj_toterr__13->SetBinContent(1,0.3608738);
   z_ptj_toterr__13->SetBinContent(2,0.225932);
   z_ptj_toterr__13->SetBinContent(3,0.1253807);
   z_ptj_toterr__13->SetBinContent(4,0.06703913);
   z_ptj_toterr__13->SetBinContent(5,0.01561868);
   z_ptj_toterr__13->SetBinContent(6,0.780934);
   z_ptj_toterr__13->SetBinError(1,0.02073388);
   z_ptj_toterr__13->SetBinError(2,0.01400757);
   z_ptj_toterr__13->SetBinError(3,0.009350811);
   z_ptj_toterr__13->SetBinError(4,0.004623786);
   z_ptj_toterr__13->SetBinError(5,0.001395185);
   z_ptj_toterr__13->SetBinError(6,0.06975923);
   z_ptj_toterr__13->SetEntries(12);
   z_ptj_toterr__13->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr__13->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr__13->SetLineColor(ci);
   z_ptj_toterr__13->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr__13->SetMarkerColor(ci);
   z_ptj_toterr__13->SetMarkerStyle(0);
   z_ptj_toterr__13->GetXaxis()->SetNdivisions(4);
   z_ptj_toterr__13->GetXaxis()->SetLabelFont(132);
   z_ptj_toterr__13->GetXaxis()->SetLabelOffset(999);
   z_ptj_toterr__13->GetXaxis()->SetLabelSize(0);
   z_ptj_toterr__13->GetXaxis()->SetTitleSize(0.06);
   z_ptj_toterr__13->GetXaxis()->SetTitleFont(132);
   z_ptj_toterr__13->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   z_ptj_toterr__13->GetYaxis()->SetLabelFont(132);
   z_ptj_toterr__13->GetYaxis()->SetLabelSize(0.05);
   z_ptj_toterr__13->GetYaxis()->SetTitleSize(0.06);
   z_ptj_toterr__13->GetYaxis()->SetTitleOffset(1.3);
   z_ptj_toterr__13->GetYaxis()->SetTitleFont(132);
   z_ptj_toterr__13->GetZaxis()->SetLabelFont(132);
   z_ptj_toterr__13->GetZaxis()->SetLabelSize(0.05);
   z_ptj_toterr__13->GetZaxis()->SetTitleSize(0.06);
   z_ptj_toterr__13->GetZaxis()->SetTitleFont(132);
   z_ptj_toterr__13->Draw("e2");
   Double_t xAxis14[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *z_ptj_staterr__14 = new TH1F("z_ptj_staterr__14","z_ptj",5, xAxis14);
   z_ptj_staterr__14->SetBinContent(1,0.3608738);
   z_ptj_staterr__14->SetBinContent(2,0.225932);
   z_ptj_staterr__14->SetBinContent(3,0.1253807);
   z_ptj_staterr__14->SetBinContent(4,0.06703913);
   z_ptj_staterr__14->SetBinContent(5,0.01561868);
   z_ptj_staterr__14->SetBinContent(6,0.780934);
   z_ptj_staterr__14->SetBinError(1,0.007287406);
   z_ptj_staterr__14->SetBinError(2,0.005663236);
   z_ptj_staterr__14->SetBinError(3,0.002951952);
   z_ptj_staterr__14->SetBinError(4,0.002192817);
   z_ptj_staterr__14->SetBinError(5,0.0004728113);
   z_ptj_staterr__14->SetBinError(6,0.02364057);
   z_ptj_staterr__14->SetEntries(12);
   z_ptj_staterr__14->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   z_ptj_staterr__14->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   z_ptj_staterr__14->SetLineColor(ci);
   z_ptj_staterr__14->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   z_ptj_staterr__14->SetMarkerColor(ci);
   z_ptj_staterr__14->SetMarkerStyle(0);
   z_ptj_staterr__14->GetXaxis()->SetNdivisions(4);
   z_ptj_staterr__14->GetXaxis()->SetLabelFont(132);
   z_ptj_staterr__14->GetXaxis()->SetLabelOffset(999);
   z_ptj_staterr__14->GetXaxis()->SetLabelSize(0);
   z_ptj_staterr__14->GetXaxis()->SetTitleSize(0.06);
   z_ptj_staterr__14->GetXaxis()->SetTitleFont(132);
   z_ptj_staterr__14->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   z_ptj_staterr__14->GetYaxis()->SetLabelFont(132);
   z_ptj_staterr__14->GetYaxis()->SetLabelSize(0.05);
   z_ptj_staterr__14->GetYaxis()->SetTitleSize(0.06);
   z_ptj_staterr__14->GetYaxis()->SetTitleFont(132);
   z_ptj_staterr__14->GetZaxis()->SetLabelFont(132);
   z_ptj_staterr__14->GetZaxis()->SetLabelSize(0.05);
   z_ptj_staterr__14->GetZaxis()->SetTitleSize(0.06);
   z_ptj_staterr__14->GetZaxis()->SetTitleFont(132);
   z_ptj_staterr__14->Draw("e2same");
   
   Double_t ptj_toterrs_fx3015[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_toterrs_fy3015[5] = {
   0.3671394,
   0.2404275,
   0.1334798,
   0.06537649,
   0.01594908};
   Double_t ptj_toterrs_felx3015[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_toterrs_fely3015[5] = {
   0.02997783,
   0.02293181,
   0.009217184,
   0.004503167,
   0.001643067};
   Double_t ptj_toterrs_fehx3015[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_toterrs_fehy3015[5] = {
   0.02512764,
   0.01751375,
   0.008693834,
   0.005222099,
   0.001753864};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,ptj_toterrs_fx3015,ptj_toterrs_fy3015,ptj_toterrs_felx3015,ptj_toterrs_fehx3015,ptj_toterrs_fely3015,ptj_toterrs_fehy3015);
   grae->SetName("ptj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_ptj_toterrs3015 = new TH1F("Graph_ptj_toterrs3015","",100,17.325,88.425);
   Graph_ptj_toterrs3015->SetMinimum(0.01287542);
   Graph_ptj_toterrs3015->SetMaximum(0.4300631);
   Graph_ptj_toterrs3015->SetDirectory(0);
   Graph_ptj_toterrs3015->SetStats(0);
   Graph_ptj_toterrs3015->SetLineWidth(2);
   Graph_ptj_toterrs3015->SetMarkerStyle(0);
   Graph_ptj_toterrs3015->GetXaxis()->SetNdivisions(4);
   Graph_ptj_toterrs3015->GetXaxis()->SetLabelFont(132);
   Graph_ptj_toterrs3015->GetXaxis()->SetLabelOffset(999);
   Graph_ptj_toterrs3015->GetXaxis()->SetLabelSize(0);
   Graph_ptj_toterrs3015->GetXaxis()->SetTitleSize(0.06);
   Graph_ptj_toterrs3015->GetXaxis()->SetTitleFont(132);
   Graph_ptj_toterrs3015->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_ptj_toterrs3015->GetYaxis()->SetLabelFont(132);
   Graph_ptj_toterrs3015->GetYaxis()->SetLabelSize(0.05);
   Graph_ptj_toterrs3015->GetYaxis()->SetTitleSize(0.06);
   Graph_ptj_toterrs3015->GetYaxis()->SetTitleFont(132);
   Graph_ptj_toterrs3015->GetZaxis()->SetLabelFont(132);
   Graph_ptj_toterrs3015->GetZaxis()->SetLabelSize(0.05);
   Graph_ptj_toterrs3015->GetZaxis()->SetTitleSize(0.06);
   Graph_ptj_toterrs3015->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ptj_toterrs3015);
   
   grae->Draw("p1p");
   
   Double_t _fx3016[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3016[5] = {
   0.3671394,
   0.2404275,
   0.1334798,
   0.06537649,
   0.01594908};
   Double_t _felx3016[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3016[5] = {
   0.01985385,
   0.01348796,
   0.006928003,
   0.003412992,
   0.001084033};
   Double_t _fehx3016[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3016[5] = {
   0.01921597,
   0.01338518,
   0.006596172,
   0.003531927,
   0.001381032};
   grae = new TGraphAsymmErrors(5,_fx3016,_fy3016,_felx3016,_fehx3016,_fely3016,_fehy3016);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3016 = new TH1F("Graph_Graph3016","",100,17.325,88.425);
   Graph_Graph3016->SetMinimum(0.01337855);
   Graph_Graph3016->SetMaximum(0.4235044);
   Graph_Graph3016->SetDirectory(0);
   Graph_Graph3016->SetStats(0);
   Graph_Graph3016->SetLineWidth(2);
   Graph_Graph3016->SetMarkerStyle(0);
   Graph_Graph3016->GetXaxis()->SetNdivisions(4);
   Graph_Graph3016->GetXaxis()->SetLabelFont(132);
   Graph_Graph3016->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3016->GetXaxis()->SetLabelSize(0);
   Graph_Graph3016->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3016->GetXaxis()->SetTitleFont(132);
   Graph_Graph3016->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph3016->GetYaxis()->SetLabelFont(132);
   Graph_Graph3016->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3016->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3016->GetYaxis()->SetTitleFont(132);
   Graph_Graph3016->GetZaxis()->SetLabelFont(132);
   Graph_Graph3016->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3016->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3016->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3016);
   
   grae->Draw("p1p");
   
   Double_t ptj_toterrs_fx3017[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_toterrs_fy3017[5] = {
   0.389299,
   0.2509263,
   0.1443755,
   0.07365244,
   0.01874484};
   Double_t ptj_toterrs_felx3017[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_toterrs_fely3017[5] = {
   0.0283978,
   0.01982285,
   0.01219084,
   0.00636368,
   0.001684181};
   Double_t ptj_toterrs_fehx3017[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_toterrs_fehy3017[5] = {
   0.03041728,
   0.02088176,
   0.0127053,
   0.007720362,
   0.001934453};
   grae = new TGraphAsymmErrors(5,ptj_toterrs_fx3017,ptj_toterrs_fy3017,ptj_toterrs_felx3017,ptj_toterrs_fehx3017,ptj_toterrs_fely3017,ptj_toterrs_fehy3017);
   grae->SetName("ptj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_ptj_toterrs3017 = new TH1F("Graph_ptj_toterrs3017","",100,17.175,72.075);
   Graph_ptj_toterrs3017->SetMinimum(0.01535459);
   Graph_ptj_toterrs3017->SetMaximum(0.4599818);
   Graph_ptj_toterrs3017->SetDirectory(0);
   Graph_ptj_toterrs3017->SetStats(0);
   Graph_ptj_toterrs3017->SetLineWidth(2);
   Graph_ptj_toterrs3017->SetMarkerStyle(0);
   Graph_ptj_toterrs3017->GetXaxis()->SetNdivisions(4);
   Graph_ptj_toterrs3017->GetXaxis()->SetLabelFont(132);
   Graph_ptj_toterrs3017->GetXaxis()->SetLabelOffset(999);
   Graph_ptj_toterrs3017->GetXaxis()->SetLabelSize(0);
   Graph_ptj_toterrs3017->GetXaxis()->SetTitleSize(0.06);
   Graph_ptj_toterrs3017->GetXaxis()->SetTitleFont(132);
   Graph_ptj_toterrs3017->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_ptj_toterrs3017->GetYaxis()->SetLabelFont(132);
   Graph_ptj_toterrs3017->GetYaxis()->SetLabelSize(0.05);
   Graph_ptj_toterrs3017->GetYaxis()->SetTitleSize(0.06);
   Graph_ptj_toterrs3017->GetYaxis()->SetTitleFont(132);
   Graph_ptj_toterrs3017->GetZaxis()->SetLabelFont(132);
   Graph_ptj_toterrs3017->GetZaxis()->SetLabelSize(0.05);
   Graph_ptj_toterrs3017->GetZaxis()->SetTitleSize(0.06);
   Graph_ptj_toterrs3017->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_ptj_toterrs3017);
   
   grae->Draw("p1p");
   
   Double_t _fx3018[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3018[5] = {
   0.389299,
   0.2509263,
   0.1443755,
   0.07365244,
   0.01874484};
   Double_t _felx3018[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3018[5] = {
   0.02243218,
   0.01539977,
   0.009090877,
   0.00492242,
   0.001303763};
   Double_t _fehx3018[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3018[5] = {
   0.02411537,
   0.01689699,
   0.0100922,
   0.005544287,
   0.001554499};
   grae = new TGraphAsymmErrors(5,_fx3018,_fy3018,_felx3018,_fehx3018,_fely3018,_fehy3018);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3018 = new TH1F("Graph_Graph3018","",100,17.175,72.075);
   Graph_Graph3018->SetMinimum(0.01569697);
   Graph_Graph3018->SetMaximum(0.4530117);
   Graph_Graph3018->SetDirectory(0);
   Graph_Graph3018->SetStats(0);
   Graph_Graph3018->SetLineWidth(2);
   Graph_Graph3018->SetMarkerStyle(0);
   Graph_Graph3018->GetXaxis()->SetNdivisions(4);
   Graph_Graph3018->GetXaxis()->SetLabelFont(132);
   Graph_Graph3018->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3018->GetXaxis()->SetLabelSize(0);
   Graph_Graph3018->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3018->GetXaxis()->SetTitleFont(132);
   Graph_Graph3018->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph3018->GetYaxis()->SetLabelFont(132);
   Graph_Graph3018->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3018->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3018->GetYaxis()->SetTitleFont(132);
   Graph_Graph3018->GetZaxis()->SetLabelFont(132);
   Graph_Graph3018->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3018->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3018->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3018);
   
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
   Double_t xAxis15[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *z_ptj_toterr_copy__15 = new TH1F("z_ptj_toterr_copy__15","z_ptj",5, xAxis15);
   z_ptj_toterr_copy__15->SetBinContent(1,0.3608738);
   z_ptj_toterr_copy__15->SetBinContent(2,0.225932);
   z_ptj_toterr_copy__15->SetBinContent(3,0.1253807);
   z_ptj_toterr_copy__15->SetBinContent(4,0.06703913);
   z_ptj_toterr_copy__15->SetBinContent(5,0.01561868);
   z_ptj_toterr_copy__15->SetBinContent(6,0.780934);
   z_ptj_toterr_copy__15->SetBinError(1,0.02073388);
   z_ptj_toterr_copy__15->SetBinError(2,0.01400757);
   z_ptj_toterr_copy__15->SetBinError(3,0.009350811);
   z_ptj_toterr_copy__15->SetBinError(4,0.004623786);
   z_ptj_toterr_copy__15->SetBinError(5,0.001395185);
   z_ptj_toterr_copy__15->SetBinError(6,0.06975923);
   z_ptj_toterr_copy__15->SetEntries(12);
   z_ptj_toterr_copy__15->SetDirectory(0);
   z_ptj_toterr_copy__15->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr_copy__15->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr_copy__15->SetLineColor(ci);
   z_ptj_toterr_copy__15->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr_copy__15->SetMarkerColor(ci);
   z_ptj_toterr_copy__15->SetMarkerStyle(0);
   z_ptj_toterr_copy__15->GetXaxis()->SetNdivisions(4);
   z_ptj_toterr_copy__15->GetXaxis()->SetLabelFont(132);
   z_ptj_toterr_copy__15->GetXaxis()->SetLabelOffset(999);
   z_ptj_toterr_copy__15->GetXaxis()->SetLabelSize(0);
   z_ptj_toterr_copy__15->GetXaxis()->SetTitleSize(0.06);
   z_ptj_toterr_copy__15->GetXaxis()->SetTitleFont(132);
   z_ptj_toterr_copy__15->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   z_ptj_toterr_copy__15->GetYaxis()->SetLabelFont(132);
   z_ptj_toterr_copy__15->GetYaxis()->SetLabelSize(0.05);
   z_ptj_toterr_copy__15->GetYaxis()->SetTitleSize(0.06);
   z_ptj_toterr_copy__15->GetYaxis()->SetTitleOffset(1.3);
   z_ptj_toterr_copy__15->GetYaxis()->SetTitleFont(132);
   z_ptj_toterr_copy__15->GetZaxis()->SetLabelFont(132);
   z_ptj_toterr_copy__15->GetZaxis()->SetLabelSize(0.05);
   z_ptj_toterr_copy__15->GetZaxis()->SetTitleSize(0.06);
   z_ptj_toterr_copy__15->GetZaxis()->SetTitleFont(132);
   z_ptj_toterr_copy__15->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(6.172839,-0.1935898,104.9383,4.832052);
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
   Double_t xAxis16[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *zj_ptj_8TeV_log_400_1001_0ratiocomp0__16 = new TH1F("zj_ptj_8TeV_log_400_1001_0ratiocomp0__16","z_ptj",5, xAxis16);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinContent(1,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinContent(2,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinContent(3,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinContent(4,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinContent(5,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinContent(6,0.780934);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinError(1,0.05745466);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinError(2,0.06199906);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinError(3,0.07457933);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinError(4,0.06897145);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinError(5,0.08932795);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetBinError(6,0.06975923);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetMinimum(0.51);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetMaximum(1.49);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetEntries(17);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetLineColor(ci);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetMarkerColor(ci);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->SetMarkerStyle(0);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetXaxis()->SetNdivisions(4);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetXaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetXaxis()->SetLabelOffset(0.02);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetXaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetXaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetXaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->SetTitle("Ratio");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->CenterTitle(true);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->SetNdivisions(505);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->SetTickLength(0.12325);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->SetTitleOffset(1.3);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetYaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetZaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetZaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetZaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->GetZaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0__16->Draw("e2");
   Double_t xAxis17[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *zj_ptj_8TeV_log_400_1001_0ratiocomp1__17 = new TH1F("zj_ptj_8TeV_log_400_1001_0ratiocomp1__17","z_ptj",5, xAxis17);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinContent(1,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinContent(2,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinContent(3,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinContent(4,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinContent(5,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinContent(6,0.780934);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinError(1,0.02019378);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinError(2,0.02506611);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinError(3,0.02354391);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinError(4,0.03270951);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinError(5,0.03027217);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetBinError(6,0.02364057);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetMinimum(0.51);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetMaximum(1.49);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetEntries(17);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetLineColor(ci);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetMarkerColor(ci);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->SetMarkerStyle(0);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetXaxis()->SetNdivisions(4);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetXaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetXaxis()->SetLabelOffset(0.02);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetXaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetXaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetXaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetYaxis()->SetTitle("Ratio");
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetYaxis()->CenterTitle(true);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetYaxis()->SetNdivisions(505);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetYaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetYaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetYaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetYaxis()->SetTickLength(0.12325);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetYaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetZaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetZaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetZaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->GetZaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp1__17->Draw("e2same");
   
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp2_fx3019[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp2_fy3019[5] = {
   1.017362,
   1.064159,
   1.064596,
   0.9751989,
   1.021154};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp2_felx3019[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp2_fely3019[5] = {
   0.08307013,
   0.1014988,
   0.07351357,
   0.06717222,
   0.1051988};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp2_fehx3019[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp2_fehy3019[5] = {
   0.06962999,
   0.07751779,
   0.06933948,
   0.07789628,
   0.1122927};
   grae = new TGraphAsymmErrors(5,zj_ptj_8TeV_log_400_1001_0ratiocomp2_fx3019,zj_ptj_8TeV_log_400_1001_0ratiocomp2_fy3019,zj_ptj_8TeV_log_400_1001_0ratiocomp2_felx3019,zj_ptj_8TeV_log_400_1001_0ratiocomp2_fehx3019,zj_ptj_8TeV_log_400_1001_0ratiocomp2_fely3019,zj_ptj_8TeV_log_400_1001_0ratiocomp2_fehy3019);
   grae->SetName("zj_ptj_8TeV_log_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019 = new TH1F("Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019","",100,17.325,88.425);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->SetMinimum(0.51);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->SetMaximum(1.49);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->SetDirectory(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->SetStats(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->SetLineWidth(2);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->SetMarkerStyle(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetXaxis()->SetNdivisions(4);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetXaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetXaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetYaxis()->SetTitle("Ratio");
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetYaxis()->CenterTitle(true);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetYaxis()->SetNdivisions(505);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetYaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetYaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetZaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp23019);
   
   grae->Draw("p1");
   
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp3_fx3020[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp3_fy3020[5] = {
   1.017362,
   1.064159,
   1.064596,
   0.9751989,
   1.021154};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp3_felx3020[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp3_fely3020[5] = {
   0.05501606,
   0.05969921,
   0.05525572,
   0.05091044,
   0.06940621};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp3_fehx3020[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp3_fehy3020[5] = {
   0.05324843,
   0.05924428,
   0.05260914,
   0.05268456,
   0.08842185};
   grae = new TGraphAsymmErrors(5,zj_ptj_8TeV_log_400_1001_0ratiocomp3_fx3020,zj_ptj_8TeV_log_400_1001_0ratiocomp3_fy3020,zj_ptj_8TeV_log_400_1001_0ratiocomp3_felx3020,zj_ptj_8TeV_log_400_1001_0ratiocomp3_fehx3020,zj_ptj_8TeV_log_400_1001_0ratiocomp3_fely3020,zj_ptj_8TeV_log_400_1001_0ratiocomp3_fehy3020);
   grae->SetName("zj_ptj_8TeV_log_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020 = new TH1F("Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020","",100,17.325,88.425);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->SetMinimum(0.51);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->SetMaximum(1.49);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->SetDirectory(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->SetStats(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->SetLineWidth(2);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->SetMarkerStyle(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetXaxis()->SetNdivisions(4);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetXaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetXaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetYaxis()->SetTitle("Ratio");
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetYaxis()->CenterTitle(true);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetYaxis()->SetNdivisions(505);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetYaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetYaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetZaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp33020);
   
   grae->Draw("p1");
   
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp4_fx3021[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp4_fy3021[5] = {
   1.078768,
   1.110628,
   1.151497,
   1.098648,
   1.200155};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp4_felx3021[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp4_fely3021[5] = {
   0.07869176,
   0.08773815,
   0.0972306,
   0.09492486,
   0.1078312};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp4_fehx3021[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_log_400_1001_0ratiocomp4_fehy3021[5] = {
   0.08428785,
   0.09242501,
   0.1013337,
   0.115162,
   0.1238551};
   grae = new TGraphAsymmErrors(5,zj_ptj_8TeV_log_400_1001_0ratiocomp4_fx3021,zj_ptj_8TeV_log_400_1001_0ratiocomp4_fy3021,zj_ptj_8TeV_log_400_1001_0ratiocomp4_felx3021,zj_ptj_8TeV_log_400_1001_0ratiocomp4_fehx3021,zj_ptj_8TeV_log_400_1001_0ratiocomp4_fely3021,zj_ptj_8TeV_log_400_1001_0ratiocomp4_fehy3021);
   grae->SetName("zj_ptj_8TeV_log_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021 = new TH1F("Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021","",100,17.175,72.075);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->SetMinimum(0.51);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->SetMaximum(1.49);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->SetDirectory(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->SetStats(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->SetLineWidth(2);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->SetMarkerStyle(0);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetXaxis()->SetNdivisions(4);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetXaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetXaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetYaxis()->SetTitle("Ratio");
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetYaxis()->CenterTitle(true);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetYaxis()->SetNdivisions(505);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetYaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetYaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetZaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_ptj_8TeV_log_400_1001_0ratiocomp43021);
   
   grae->Draw("p1");
   Double_t xAxis18[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18 = new TH1F("zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18","z_ptj",5, xAxis18);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinContent(1,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinContent(2,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinContent(3,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinContent(4,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinContent(5,1);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinContent(6,0.780934);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinError(1,0.05745466);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinError(2,0.06199906);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinError(3,0.07457933);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinError(4,0.06897145);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinError(5,0.08932795);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetBinError(6,0.06975923);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetMinimum(0.51);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetMaximum(1.49);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetEntries(17);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetDirectory(0);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetLineColor(ci);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetMarkerColor(ci);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->SetMarkerStyle(0);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetXaxis()->SetNdivisions(4);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetXaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetXaxis()->SetLabelOffset(0.02);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetXaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetXaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetXaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->SetTitle("Ratio");
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->CenterTitle(true);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->SetNdivisions(505);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->SetTickLength(0.12325);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->SetTitleOffset(1.3);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetYaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetZaxis()->SetLabelFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetZaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetZaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->GetZaxis()->SetTitleFont(132);
   zj_ptj_8TeV_log_400_1001_0ratiocomp0_copy__18->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
