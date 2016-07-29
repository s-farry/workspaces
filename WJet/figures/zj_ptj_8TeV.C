void zj_ptj_8TeV()
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
   upperPad->Range(6.172839,-0.2132695,104.9383,0.4330016);
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
   Double_t xAxis19[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *z_ptj_toterr__19 = new TH1F("z_ptj_toterr__19","z_ptj",5, xAxis19);
   z_ptj_toterr__19->SetBinContent(1,0.3608738);
   z_ptj_toterr__19->SetBinContent(2,0.225932);
   z_ptj_toterr__19->SetBinContent(3,0.1253807);
   z_ptj_toterr__19->SetBinContent(4,0.06703913);
   z_ptj_toterr__19->SetBinContent(5,0.01561868);
   z_ptj_toterr__19->SetBinContent(6,0.780934);
   z_ptj_toterr__19->SetBinError(1,0.02073388);
   z_ptj_toterr__19->SetBinError(2,0.01400757);
   z_ptj_toterr__19->SetBinError(3,0.009350811);
   z_ptj_toterr__19->SetBinError(4,0.004623786);
   z_ptj_toterr__19->SetBinError(5,0.001395185);
   z_ptj_toterr__19->SetBinError(6,0.06975923);
   z_ptj_toterr__19->SetEntries(12);
   z_ptj_toterr__19->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr__19->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr__19->SetLineColor(ci);
   z_ptj_toterr__19->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr__19->SetMarkerColor(ci);
   z_ptj_toterr__19->SetMarkerStyle(0);
   z_ptj_toterr__19->GetXaxis()->SetNdivisions(4);
   z_ptj_toterr__19->GetXaxis()->SetLabelFont(132);
   z_ptj_toterr__19->GetXaxis()->SetLabelOffset(999);
   z_ptj_toterr__19->GetXaxis()->SetLabelSize(0);
   z_ptj_toterr__19->GetXaxis()->SetTitleSize(0.06);
   z_ptj_toterr__19->GetXaxis()->SetTitleFont(132);
   z_ptj_toterr__19->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   z_ptj_toterr__19->GetYaxis()->SetLabelFont(132);
   z_ptj_toterr__19->GetYaxis()->SetLabelSize(0.05);
   z_ptj_toterr__19->GetYaxis()->SetTitleSize(0.06);
   z_ptj_toterr__19->GetYaxis()->SetTitleOffset(1.3);
   z_ptj_toterr__19->GetYaxis()->SetTitleFont(132);
   z_ptj_toterr__19->GetZaxis()->SetLabelFont(132);
   z_ptj_toterr__19->GetZaxis()->SetLabelSize(0.05);
   z_ptj_toterr__19->GetZaxis()->SetTitleSize(0.06);
   z_ptj_toterr__19->GetZaxis()->SetTitleFont(132);
   z_ptj_toterr__19->Draw("e2");
   Double_t xAxis20[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *z_ptj_staterr__20 = new TH1F("z_ptj_staterr__20","z_ptj",5, xAxis20);
   z_ptj_staterr__20->SetBinContent(1,0.3608738);
   z_ptj_staterr__20->SetBinContent(2,0.225932);
   z_ptj_staterr__20->SetBinContent(3,0.1253807);
   z_ptj_staterr__20->SetBinContent(4,0.06703913);
   z_ptj_staterr__20->SetBinContent(5,0.01561868);
   z_ptj_staterr__20->SetBinContent(6,0.780934);
   z_ptj_staterr__20->SetBinError(1,0.007287406);
   z_ptj_staterr__20->SetBinError(2,0.005663236);
   z_ptj_staterr__20->SetBinError(3,0.002951952);
   z_ptj_staterr__20->SetBinError(4,0.002192817);
   z_ptj_staterr__20->SetBinError(5,0.0004728113);
   z_ptj_staterr__20->SetBinError(6,0.02364057);
   z_ptj_staterr__20->SetEntries(12);
   z_ptj_staterr__20->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   z_ptj_staterr__20->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   z_ptj_staterr__20->SetLineColor(ci);
   z_ptj_staterr__20->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   z_ptj_staterr__20->SetMarkerColor(ci);
   z_ptj_staterr__20->SetMarkerStyle(0);
   z_ptj_staterr__20->GetXaxis()->SetNdivisions(4);
   z_ptj_staterr__20->GetXaxis()->SetLabelFont(132);
   z_ptj_staterr__20->GetXaxis()->SetLabelOffset(999);
   z_ptj_staterr__20->GetXaxis()->SetLabelSize(0);
   z_ptj_staterr__20->GetXaxis()->SetTitleSize(0.06);
   z_ptj_staterr__20->GetXaxis()->SetTitleFont(132);
   z_ptj_staterr__20->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   z_ptj_staterr__20->GetYaxis()->SetLabelFont(132);
   z_ptj_staterr__20->GetYaxis()->SetLabelSize(0.05);
   z_ptj_staterr__20->GetYaxis()->SetTitleSize(0.06);
   z_ptj_staterr__20->GetYaxis()->SetTitleFont(132);
   z_ptj_staterr__20->GetZaxis()->SetLabelFont(132);
   z_ptj_staterr__20->GetZaxis()->SetLabelSize(0.05);
   z_ptj_staterr__20->GetZaxis()->SetTitleSize(0.06);
   z_ptj_staterr__20->GetZaxis()->SetTitleFont(132);
   z_ptj_staterr__20->Draw("e2same");
   
   Double_t ptj_toterrs_fx3022[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t ptj_toterrs_fy3022[5] = {
   0.3671394,
   0.2404275,
   0.1334798,
   0.06537649,
   0.01594908};
   Double_t ptj_toterrs_felx3022[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_toterrs_fely3022[5] = {
   0.02997783,
   0.02293181,
   0.009217184,
   0.004503167,
   0.001643067};
   Double_t ptj_toterrs_fehx3022[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_toterrs_fehy3022[5] = {
   0.02512764,
   0.01751375,
   0.008693834,
   0.005222099,
   0.001753864};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,ptj_toterrs_fx3022,ptj_toterrs_fy3022,ptj_toterrs_felx3022,ptj_toterrs_fehx3022,ptj_toterrs_fely3022,ptj_toterrs_fehy3022);
   grae->SetName("ptj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_ptj_toterrs30153022 = new TH1F("Graph_Graph_ptj_toterrs30153022","",100,17.325,88.425);
   Graph_Graph_ptj_toterrs30153022->SetMinimum(0.01287542);
   Graph_Graph_ptj_toterrs30153022->SetMaximum(0.4300631);
   Graph_Graph_ptj_toterrs30153022->SetDirectory(0);
   Graph_Graph_ptj_toterrs30153022->SetStats(0);
   Graph_Graph_ptj_toterrs30153022->SetLineWidth(2);
   Graph_Graph_ptj_toterrs30153022->SetMarkerStyle(0);
   Graph_Graph_ptj_toterrs30153022->GetXaxis()->SetNdivisions(4);
   Graph_Graph_ptj_toterrs30153022->GetXaxis()->SetLabelFont(132);
   Graph_Graph_ptj_toterrs30153022->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_ptj_toterrs30153022->GetXaxis()->SetLabelSize(0);
   Graph_Graph_ptj_toterrs30153022->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_toterrs30153022->GetXaxis()->SetTitleFont(132);
   Graph_Graph_ptj_toterrs30153022->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_ptj_toterrs30153022->GetYaxis()->SetLabelFont(132);
   Graph_Graph_ptj_toterrs30153022->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_toterrs30153022->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_toterrs30153022->GetYaxis()->SetTitleFont(132);
   Graph_Graph_ptj_toterrs30153022->GetZaxis()->SetLabelFont(132);
   Graph_Graph_ptj_toterrs30153022->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_toterrs30153022->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_toterrs30153022->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_ptj_toterrs30153022);
   
   grae->Draw("p1p");
   
   Double_t _fx3023[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3023[5] = {
   0.3671394,
   0.2404275,
   0.1334798,
   0.06537649,
   0.01594908};
   Double_t _felx3023[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3023[5] = {
   0.01985385,
   0.01348796,
   0.006928003,
   0.003412992,
   0.001084033};
   Double_t _fehx3023[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3023[5] = {
   0.01921597,
   0.01338518,
   0.006596172,
   0.003531927,
   0.001381032};
   grae = new TGraphAsymmErrors(5,_fx3023,_fy3023,_felx3023,_fehx3023,_fely3023,_fehy3023);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph30163023 = new TH1F("Graph_Graph_Graph30163023","",100,17.325,88.425);
   Graph_Graph_Graph30163023->SetMinimum(0.01337855);
   Graph_Graph_Graph30163023->SetMaximum(0.4235044);
   Graph_Graph_Graph30163023->SetDirectory(0);
   Graph_Graph_Graph30163023->SetStats(0);
   Graph_Graph_Graph30163023->SetLineWidth(2);
   Graph_Graph_Graph30163023->SetMarkerStyle(0);
   Graph_Graph_Graph30163023->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30163023->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30163023->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30163023->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30163023->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30163023->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30163023->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph30163023->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30163023->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30163023->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30163023->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30163023->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30163023->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30163023->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30163023->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30163023);
   
   grae->Draw("p1p");
   
   Double_t ptj_toterrs_fx3024[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t ptj_toterrs_fy3024[5] = {
   0.389299,
   0.2509263,
   0.1443755,
   0.07365244,
   0.01874484};
   Double_t ptj_toterrs_felx3024[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_toterrs_fely3024[5] = {
   0.0283978,
   0.01982285,
   0.01219084,
   0.00636368,
   0.001684181};
   Double_t ptj_toterrs_fehx3024[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t ptj_toterrs_fehy3024[5] = {
   0.03041728,
   0.02088176,
   0.0127053,
   0.007720362,
   0.001934453};
   grae = new TGraphAsymmErrors(5,ptj_toterrs_fx3024,ptj_toterrs_fy3024,ptj_toterrs_felx3024,ptj_toterrs_fehx3024,ptj_toterrs_fely3024,ptj_toterrs_fehy3024);
   grae->SetName("ptj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_ptj_toterrs30173024 = new TH1F("Graph_Graph_ptj_toterrs30173024","",100,17.175,72.075);
   Graph_Graph_ptj_toterrs30173024->SetMinimum(0.01535459);
   Graph_Graph_ptj_toterrs30173024->SetMaximum(0.4599818);
   Graph_Graph_ptj_toterrs30173024->SetDirectory(0);
   Graph_Graph_ptj_toterrs30173024->SetStats(0);
   Graph_Graph_ptj_toterrs30173024->SetLineWidth(2);
   Graph_Graph_ptj_toterrs30173024->SetMarkerStyle(0);
   Graph_Graph_ptj_toterrs30173024->GetXaxis()->SetNdivisions(4);
   Graph_Graph_ptj_toterrs30173024->GetXaxis()->SetLabelFont(132);
   Graph_Graph_ptj_toterrs30173024->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_ptj_toterrs30173024->GetXaxis()->SetLabelSize(0);
   Graph_Graph_ptj_toterrs30173024->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_toterrs30173024->GetXaxis()->SetTitleFont(132);
   Graph_Graph_ptj_toterrs30173024->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_ptj_toterrs30173024->GetYaxis()->SetLabelFont(132);
   Graph_Graph_ptj_toterrs30173024->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_toterrs30173024->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_toterrs30173024->GetYaxis()->SetTitleFont(132);
   Graph_Graph_ptj_toterrs30173024->GetZaxis()->SetLabelFont(132);
   Graph_Graph_ptj_toterrs30173024->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_ptj_toterrs30173024->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_ptj_toterrs30173024->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_ptj_toterrs30173024);
   
   grae->Draw("p1p");
   
   Double_t _fx3025[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3025[5] = {
   0.389299,
   0.2509263,
   0.1443755,
   0.07365244,
   0.01874484};
   Double_t _felx3025[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3025[5] = {
   0.02243218,
   0.01539977,
   0.009090877,
   0.00492242,
   0.001303763};
   Double_t _fehx3025[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3025[5] = {
   0.02411537,
   0.01689699,
   0.0100922,
   0.005544287,
   0.001554499};
   grae = new TGraphAsymmErrors(5,_fx3025,_fy3025,_felx3025,_fehx3025,_fely3025,_fehy3025);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30183025 = new TH1F("Graph_Graph_Graph30183025","",100,17.175,72.075);
   Graph_Graph_Graph30183025->SetMinimum(0.01569697);
   Graph_Graph_Graph30183025->SetMaximum(0.4530117);
   Graph_Graph_Graph30183025->SetDirectory(0);
   Graph_Graph_Graph30183025->SetStats(0);
   Graph_Graph_Graph30183025->SetLineWidth(2);
   Graph_Graph_Graph30183025->SetMarkerStyle(0);
   Graph_Graph_Graph30183025->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30183025->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30183025->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30183025->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30183025->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30183025->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30183025->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   Graph_Graph_Graph30183025->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30183025->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30183025->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30183025->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30183025->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30183025->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30183025->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30183025->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30183025);
   
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
   Double_t xAxis21[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *z_ptj_toterr_copy__21 = new TH1F("z_ptj_toterr_copy__21","z_ptj",5, xAxis21);
   z_ptj_toterr_copy__21->SetBinContent(1,0.3608738);
   z_ptj_toterr_copy__21->SetBinContent(2,0.225932);
   z_ptj_toterr_copy__21->SetBinContent(3,0.1253807);
   z_ptj_toterr_copy__21->SetBinContent(4,0.06703913);
   z_ptj_toterr_copy__21->SetBinContent(5,0.01561868);
   z_ptj_toterr_copy__21->SetBinContent(6,0.780934);
   z_ptj_toterr_copy__21->SetBinError(1,0.02073388);
   z_ptj_toterr_copy__21->SetBinError(2,0.01400757);
   z_ptj_toterr_copy__21->SetBinError(3,0.009350811);
   z_ptj_toterr_copy__21->SetBinError(4,0.004623786);
   z_ptj_toterr_copy__21->SetBinError(5,0.001395185);
   z_ptj_toterr_copy__21->SetBinError(6,0.06975923);
   z_ptj_toterr_copy__21->SetEntries(12);
   z_ptj_toterr_copy__21->SetDirectory(0);
   z_ptj_toterr_copy__21->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr_copy__21->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr_copy__21->SetLineColor(ci);
   z_ptj_toterr_copy__21->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_ptj_toterr_copy__21->SetMarkerColor(ci);
   z_ptj_toterr_copy__21->SetMarkerStyle(0);
   z_ptj_toterr_copy__21->GetXaxis()->SetNdivisions(4);
   z_ptj_toterr_copy__21->GetXaxis()->SetLabelFont(132);
   z_ptj_toterr_copy__21->GetXaxis()->SetLabelOffset(999);
   z_ptj_toterr_copy__21->GetXaxis()->SetLabelSize(0);
   z_ptj_toterr_copy__21->GetXaxis()->SetTitleSize(0.06);
   z_ptj_toterr_copy__21->GetXaxis()->SetTitleFont(132);
   z_ptj_toterr_copy__21->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d#it{p}_{T}^{jet} [pb/GeV]");
   z_ptj_toterr_copy__21->GetYaxis()->SetLabelFont(132);
   z_ptj_toterr_copy__21->GetYaxis()->SetLabelSize(0.05);
   z_ptj_toterr_copy__21->GetYaxis()->SetTitleSize(0.06);
   z_ptj_toterr_copy__21->GetYaxis()->SetTitleOffset(1.3);
   z_ptj_toterr_copy__21->GetYaxis()->SetTitleFont(132);
   z_ptj_toterr_copy__21->GetZaxis()->SetLabelFont(132);
   z_ptj_toterr_copy__21->GetZaxis()->SetLabelSize(0.05);
   z_ptj_toterr_copy__21->GetZaxis()->SetTitleSize(0.06);
   z_ptj_toterr_copy__21->GetZaxis()->SetTitleFont(132);
   z_ptj_toterr_copy__21->Draw("sameaxis");
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
   Double_t xAxis22[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *zj_ptj_8TeV_400_1001_0ratiocomp0__22 = new TH1F("zj_ptj_8TeV_400_1001_0ratiocomp0__22","z_ptj",5, xAxis22);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinContent(1,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinContent(2,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinContent(3,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinContent(4,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinContent(5,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinContent(6,0.780934);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinError(1,0.05745466);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinError(2,0.06199906);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinError(3,0.07457933);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinError(4,0.06897145);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinError(5,0.08932795);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetBinError(6,0.06975923);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetMinimum(0.51);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetMaximum(1.49);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetEntries(17);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetLineColor(ci);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetMarkerColor(ci);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->SetMarkerStyle(0);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetXaxis()->SetNdivisions(4);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetXaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetXaxis()->SetLabelOffset(0.02);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetXaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetXaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetXaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->SetTitle("Ratio");
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->CenterTitle(true);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->SetNdivisions(505);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->SetTickLength(0.12325);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->SetTitleOffset(1.3);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetYaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetZaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetZaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetZaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->GetZaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0__22->Draw("e2");
   Double_t xAxis23[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *zj_ptj_8TeV_400_1001_0ratiocomp1__23 = new TH1F("zj_ptj_8TeV_400_1001_0ratiocomp1__23","z_ptj",5, xAxis23);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinContent(1,1);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinContent(2,1);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinContent(3,1);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinContent(4,1);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinContent(5,1);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinContent(6,0.780934);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinError(1,0.02019378);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinError(2,0.02506611);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinError(3,0.02354391);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinError(4,0.03270951);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinError(5,0.03027217);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetBinError(6,0.02364057);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetMinimum(0.51);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetMaximum(1.49);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetEntries(17);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetLineColor(ci);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetMarkerColor(ci);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->SetMarkerStyle(0);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetXaxis()->SetNdivisions(4);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetXaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetXaxis()->SetLabelOffset(0.02);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetXaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetXaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetXaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetYaxis()->SetTitle("Ratio");
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetYaxis()->CenterTitle(true);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetYaxis()->SetNdivisions(505);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetYaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetYaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetYaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetYaxis()->SetTickLength(0.12325);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetYaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetZaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetZaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetZaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->GetZaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp1__23->Draw("e2same");
   
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp2_fx3026[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp2_fy3026[5] = {
   1.017362,
   1.064159,
   1.064596,
   0.9751989,
   1.021154};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp2_felx3026[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp2_fely3026[5] = {
   0.08307013,
   0.1014988,
   0.07351357,
   0.06717222,
   0.1051988};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp2_fehx3026[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp2_fehy3026[5] = {
   0.06962999,
   0.07751779,
   0.06933948,
   0.07789628,
   0.1122927};
   grae = new TGraphAsymmErrors(5,zj_ptj_8TeV_400_1001_0ratiocomp2_fx3026,zj_ptj_8TeV_400_1001_0ratiocomp2_fy3026,zj_ptj_8TeV_400_1001_0ratiocomp2_felx3026,zj_ptj_8TeV_400_1001_0ratiocomp2_fehx3026,zj_ptj_8TeV_400_1001_0ratiocomp2_fely3026,zj_ptj_8TeV_400_1001_0ratiocomp2_fehy3026);
   grae->SetName("zj_ptj_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026 = new TH1F("Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026","",100,17.325,88.425);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->SetMinimum(0.51);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->SetMaximum(1.49);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->SetDirectory(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->SetStats(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->SetLineWidth(2);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->SetMarkerStyle(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetXaxis()->SetNdivisions(4);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetXaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetXaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetYaxis()->SetTitle("Ratio");
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetYaxis()->CenterTitle(true);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetYaxis()->SetNdivisions(505);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetYaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetYaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetZaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_ptj_8TeV_400_1001_0ratiocomp23026);
   
   grae->Draw("p1");
   
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp3_fx3027[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp3_fy3027[5] = {
   1.017362,
   1.064159,
   1.064596,
   0.9751989,
   1.021154};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp3_felx3027[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp3_fely3027[5] = {
   0.05501606,
   0.05969921,
   0.05525572,
   0.05091044,
   0.06940621};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp3_fehx3027[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp3_fehy3027[5] = {
   0.05324843,
   0.05924428,
   0.05260914,
   0.05268456,
   0.08842185};
   grae = new TGraphAsymmErrors(5,zj_ptj_8TeV_400_1001_0ratiocomp3_fx3027,zj_ptj_8TeV_400_1001_0ratiocomp3_fy3027,zj_ptj_8TeV_400_1001_0ratiocomp3_felx3027,zj_ptj_8TeV_400_1001_0ratiocomp3_fehx3027,zj_ptj_8TeV_400_1001_0ratiocomp3_fely3027,zj_ptj_8TeV_400_1001_0ratiocomp3_fehy3027);
   grae->SetName("zj_ptj_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027 = new TH1F("Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027","",100,17.325,88.425);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->SetMinimum(0.51);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->SetMaximum(1.49);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->SetDirectory(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->SetStats(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->SetLineWidth(2);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->SetMarkerStyle(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetXaxis()->SetNdivisions(4);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetXaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetXaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetYaxis()->SetTitle("Ratio");
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetYaxis()->CenterTitle(true);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetYaxis()->SetNdivisions(505);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetYaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetYaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetZaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_ptj_8TeV_400_1001_0ratiocomp33027);
   
   grae->Draw("p1");
   
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp4_fx3028[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp4_fy3028[5] = {
   1.078768,
   1.110628,
   1.151497,
   1.098648,
   1.200155};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp4_felx3028[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp4_fely3028[5] = {
   0.07869176,
   0.08773815,
   0.0972306,
   0.09492486,
   0.1078312};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp4_fehx3028[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t zj_ptj_8TeV_400_1001_0ratiocomp4_fehy3028[5] = {
   0.08428785,
   0.09242501,
   0.1013337,
   0.115162,
   0.1238551};
   grae = new TGraphAsymmErrors(5,zj_ptj_8TeV_400_1001_0ratiocomp4_fx3028,zj_ptj_8TeV_400_1001_0ratiocomp4_fy3028,zj_ptj_8TeV_400_1001_0ratiocomp4_felx3028,zj_ptj_8TeV_400_1001_0ratiocomp4_fehx3028,zj_ptj_8TeV_400_1001_0ratiocomp4_fely3028,zj_ptj_8TeV_400_1001_0ratiocomp4_fehy3028);
   grae->SetName("zj_ptj_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028 = new TH1F("Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028","",100,17.175,72.075);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->SetMinimum(0.51);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->SetMaximum(1.49);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->SetDirectory(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->SetStats(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->SetLineWidth(2);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->SetMarkerStyle(0);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetXaxis()->SetNdivisions(4);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetXaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetXaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetYaxis()->SetTitle("Ratio");
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetYaxis()->CenterTitle(true);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetYaxis()->SetNdivisions(505);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetYaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetYaxis()->SetTitleFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetZaxis()->SetLabelFont(132);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_ptj_8TeV_400_1001_0ratiocomp43028);
   
   grae->Draw("p1");
   Double_t xAxis24[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24 = new TH1F("zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24","z_ptj",5, xAxis24);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinContent(1,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinContent(2,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinContent(3,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinContent(4,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinContent(5,1);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinContent(6,0.780934);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinError(1,0.05745466);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinError(2,0.06199906);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinError(3,0.07457933);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinError(4,0.06897145);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinError(5,0.08932795);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetBinError(6,0.06975923);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetMinimum(0.51);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetMaximum(1.49);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetEntries(17);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetDirectory(0);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetLineColor(ci);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetMarkerColor(ci);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->SetMarkerStyle(0);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetXaxis()->SetNdivisions(4);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetXaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetXaxis()->SetLabelOffset(0.02);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetXaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetXaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetXaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->SetTitle("Ratio");
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->CenterTitle(true);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->SetNdivisions(505);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->SetTickLength(0.12325);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->SetTitleOffset(1.3);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetYaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetZaxis()->SetLabelFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetZaxis()->SetLabelSize(0.05);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetZaxis()->SetTitleSize(0.06);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->GetZaxis()->SetTitleFont(132);
   zj_ptj_8TeV_400_1001_0ratiocomp0_copy__24->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
