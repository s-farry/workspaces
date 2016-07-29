void wj_asymm_ptj_8TeV()
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
   upperPad->Range(6.172839,-0.2178226,104.9383,0.7483065);
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
   Double_t xAxis178[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *w_a_ptj_toterr__208 = new TH1F("w_a_ptj_toterr__208","w_ptj",5, xAxis178);
   w_a_ptj_toterr__208->SetBinContent(1,0.2297775);
   w_a_ptj_toterr__208->SetBinContent(2,0.2603096);
   w_a_ptj_toterr__208->SetBinContent(3,0.259545);
   w_a_ptj_toterr__208->SetBinContent(4,0.2667569);
   w_a_ptj_toterr__208->SetBinContent(5,0.3469177);
   w_a_ptj_toterr__208->SetBinContent(6,0.3469177);
   w_a_ptj_toterr__208->SetBinError(1,0.01767501);
   w_a_ptj_toterr__208->SetBinError(2,0.01912261);
   w_a_ptj_toterr__208->SetBinError(3,0.01827246);
   w_a_ptj_toterr__208->SetBinError(4,0.02475487);
   w_a_ptj_toterr__208->SetBinError(5,0.02993453);
   w_a_ptj_toterr__208->SetBinError(6,0.02993453);
   w_a_ptj_toterr__208->SetMinimum(0.101);
   w_a_ptj_toterr__208->SetMaximum(0.7);
   w_a_ptj_toterr__208->SetEntries(7);
   w_a_ptj_toterr__208->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   w_a_ptj_toterr__208->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_a_ptj_toterr__208->SetLineColor(ci);
   w_a_ptj_toterr__208->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_a_ptj_toterr__208->SetMarkerColor(ci);
   w_a_ptj_toterr__208->SetMarkerStyle(0);
   w_a_ptj_toterr__208->GetXaxis()->SetRange(1,5);
   w_a_ptj_toterr__208->GetXaxis()->SetNdivisions(4);
   w_a_ptj_toterr__208->GetXaxis()->SetLabelFont(132);
   w_a_ptj_toterr__208->GetXaxis()->SetLabelOffset(999);
   w_a_ptj_toterr__208->GetXaxis()->SetLabelSize(0);
   w_a_ptj_toterr__208->GetXaxis()->SetTitleSize(0.06);
   w_a_ptj_toterr__208->GetXaxis()->SetTitleFont(132);
   w_a_ptj_toterr__208->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_ptj_toterr__208->GetYaxis()->SetLabelFont(132);
   w_a_ptj_toterr__208->GetYaxis()->SetLabelSize(0.05);
   w_a_ptj_toterr__208->GetYaxis()->SetTitleSize(0.06);
   w_a_ptj_toterr__208->GetYaxis()->SetTitleFont(132);
   w_a_ptj_toterr__208->GetZaxis()->SetLabelFont(132);
   w_a_ptj_toterr__208->GetZaxis()->SetLabelSize(0.05);
   w_a_ptj_toterr__208->GetZaxis()->SetTitleSize(0.06);
   w_a_ptj_toterr__208->GetZaxis()->SetTitleFont(132);
   w_a_ptj_toterr__208->Draw("e2");
   Double_t xAxis179[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *w_a_ptj_staterr__209 = new TH1F("w_a_ptj_staterr__209","w_ptj",5, xAxis179);
   w_a_ptj_staterr__209->SetBinContent(1,0.2297775);
   w_a_ptj_staterr__209->SetBinContent(2,0.2603096);
   w_a_ptj_staterr__209->SetBinContent(3,0.259545);
   w_a_ptj_staterr__209->SetBinContent(4,0.2667569);
   w_a_ptj_staterr__209->SetBinContent(5,0.3469177);
   w_a_ptj_staterr__209->SetBinContent(6,0.3469177);
   w_a_ptj_staterr__209->SetBinError(1,0.005531756);
   w_a_ptj_staterr__209->SetBinError(2,0.006866338);
   w_a_ptj_staterr__209->SetBinError(3,0.006466518);
   w_a_ptj_staterr__209->SetBinError(4,0.009108666);
   w_a_ptj_staterr__209->SetBinError(5,0.008272767);
   w_a_ptj_staterr__209->SetBinError(6,0.008272767);
   w_a_ptj_staterr__209->SetMinimum(0.101);
   w_a_ptj_staterr__209->SetMaximum(0.7);
   w_a_ptj_staterr__209->SetEntries(7);
   w_a_ptj_staterr__209->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   w_a_ptj_staterr__209->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   w_a_ptj_staterr__209->SetLineColor(ci);
   w_a_ptj_staterr__209->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   w_a_ptj_staterr__209->SetMarkerColor(ci);
   w_a_ptj_staterr__209->SetMarkerStyle(0);
   w_a_ptj_staterr__209->GetXaxis()->SetRange(1,5);
   w_a_ptj_staterr__209->GetXaxis()->SetNdivisions(4);
   w_a_ptj_staterr__209->GetXaxis()->SetLabelFont(132);
   w_a_ptj_staterr__209->GetXaxis()->SetLabelOffset(999);
   w_a_ptj_staterr__209->GetXaxis()->SetLabelSize(0);
   w_a_ptj_staterr__209->GetXaxis()->SetTitleSize(0.06);
   w_a_ptj_staterr__209->GetXaxis()->SetTitleFont(132);
   w_a_ptj_staterr__209->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_ptj_staterr__209->GetYaxis()->SetLabelFont(132);
   w_a_ptj_staterr__209->GetYaxis()->SetLabelSize(0.05);
   w_a_ptj_staterr__209->GetYaxis()->SetTitleSize(0.06);
   w_a_ptj_staterr__209->GetYaxis()->SetTitleFont(132);
   w_a_ptj_staterr__209->GetZaxis()->SetLabelFont(132);
   w_a_ptj_staterr__209->GetZaxis()->SetLabelSize(0.05);
   w_a_ptj_staterr__209->GetZaxis()->SetTitleSize(0.06);
   w_a_ptj_staterr__209->GetZaxis()->SetTitleFont(132);
   w_a_ptj_staterr__209->Draw("e2same");
   
   Double_t asymm_ptj_toterrs_fx3263[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t asymm_ptj_toterrs_fy3263[5] = {
   0.1920467,
   0.2520921,
   0.229536,
   0.2481252,
   0.2709518};
   Double_t asymm_ptj_toterrs_felx3263[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t asymm_ptj_toterrs_fely3263[5] = {
   0.01472643,
   0.04212129,
   0.02157426,
   0.01951616,
   0.02758839};
   Double_t asymm_ptj_toterrs_fehx3263[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t asymm_ptj_toterrs_fehy3263[5] = {
   0.0222348,
   0.01006934,
   0.02822224,
   0.02248663,
   0.03700491};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,asymm_ptj_toterrs_fx3263,asymm_ptj_toterrs_fy3263,asymm_ptj_toterrs_felx3263,asymm_ptj_toterrs_fehx3263,asymm_ptj_toterrs_fely3263,asymm_ptj_toterrs_fehy3263);
   grae->SetName("asymm_ptj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_asymm_ptj_toterrs3263 = new TH1F("Graph_asymm_ptj_toterrs3263","",100,17.325,88.425);
   Graph_asymm_ptj_toterrs3263->SetMinimum(0.101);
   Graph_asymm_ptj_toterrs3263->SetMaximum(0.7);
   Graph_asymm_ptj_toterrs3263->SetDirectory(0);
   Graph_asymm_ptj_toterrs3263->SetStats(0);
   Graph_asymm_ptj_toterrs3263->SetLineWidth(2);
   Graph_asymm_ptj_toterrs3263->SetMarkerStyle(0);
   Graph_asymm_ptj_toterrs3263->GetXaxis()->SetRange(1,100);
   Graph_asymm_ptj_toterrs3263->GetXaxis()->SetNdivisions(4);
   Graph_asymm_ptj_toterrs3263->GetXaxis()->SetLabelFont(132);
   Graph_asymm_ptj_toterrs3263->GetXaxis()->SetLabelOffset(999);
   Graph_asymm_ptj_toterrs3263->GetXaxis()->SetLabelSize(0);
   Graph_asymm_ptj_toterrs3263->GetXaxis()->SetTitleSize(0.06);
   Graph_asymm_ptj_toterrs3263->GetXaxis()->SetTitleFont(132);
   Graph_asymm_ptj_toterrs3263->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_asymm_ptj_toterrs3263->GetYaxis()->SetLabelFont(132);
   Graph_asymm_ptj_toterrs3263->GetYaxis()->SetLabelSize(0.05);
   Graph_asymm_ptj_toterrs3263->GetYaxis()->SetTitleSize(0.06);
   Graph_asymm_ptj_toterrs3263->GetYaxis()->SetTitleFont(132);
   Graph_asymm_ptj_toterrs3263->GetZaxis()->SetLabelFont(132);
   Graph_asymm_ptj_toterrs3263->GetZaxis()->SetLabelSize(0.05);
   Graph_asymm_ptj_toterrs3263->GetZaxis()->SetTitleSize(0.06);
   Graph_asymm_ptj_toterrs3263->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_asymm_ptj_toterrs3263);
   
   grae->Draw("p1p");
   
   Double_t _fx3264[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t _fy3264[5] = {
   0.1920467,
   0.2520921,
   0.229536,
   0.2481252,
   0.2709518};
   Double_t _felx3264[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3264[5] = {
   0.006560758,
   0.000836283,
   0.01128179,
   0.004023209,
   0.006760776};
   Double_t _fehx3264[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3264[5] = {
   0.006858453,
   0.001389325,
   0.009908676,
   0.0046992,
   0.005705625};
   grae = new TGraphAsymmErrors(5,_fx3264,_fy3264,_felx3264,_fehx3264,_fely3264,_fehy3264);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3264 = new TH1F("Graph_Graph3264","",100,17.325,88.425);
   Graph_Graph3264->SetMinimum(0.101);
   Graph_Graph3264->SetMaximum(0.7);
   Graph_Graph3264->SetDirectory(0);
   Graph_Graph3264->SetStats(0);
   Graph_Graph3264->SetLineWidth(2);
   Graph_Graph3264->SetMarkerStyle(0);
   Graph_Graph3264->GetXaxis()->SetRange(1,100);
   Graph_Graph3264->GetXaxis()->SetNdivisions(4);
   Graph_Graph3264->GetXaxis()->SetLabelFont(132);
   Graph_Graph3264->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3264->GetXaxis()->SetLabelSize(0);
   Graph_Graph3264->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3264->GetXaxis()->SetTitleFont(132);
   Graph_Graph3264->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3264->GetYaxis()->SetLabelFont(132);
   Graph_Graph3264->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3264->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3264->GetYaxis()->SetTitleFont(132);
   Graph_Graph3264->GetZaxis()->SetLabelFont(132);
   Graph_Graph3264->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3264->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3264->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3264);
   
   grae->Draw("p1p");
   
   Double_t asymm_ptj_toterrs_fx3265[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t asymm_ptj_toterrs_fy3265[5] = {
   0.2141988,
   0.2247928,
   0.2485379,
   0.2608521,
   0.2879919};
   Double_t asymm_ptj_toterrs_felx3265[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t asymm_ptj_toterrs_fely3265[5] = {
   0.008252311,
   0.00886514,
   0.01504863,
   0.01306144,
   0.01611142};
   Double_t asymm_ptj_toterrs_fehx3265[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t asymm_ptj_toterrs_fehy3265[5] = {
   0.008543443,
   0.0103666,
   0.01046673,
   0.01357977,
   0.01730278};
   grae = new TGraphAsymmErrors(5,asymm_ptj_toterrs_fx3265,asymm_ptj_toterrs_fy3265,asymm_ptj_toterrs_felx3265,asymm_ptj_toterrs_fehx3265,asymm_ptj_toterrs_fely3265,asymm_ptj_toterrs_fehy3265);
   grae->SetName("asymm_ptj_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_asymm_ptj_toterrs3265 = new TH1F("Graph_asymm_ptj_toterrs3265","",100,17.175,72.075);
   Graph_asymm_ptj_toterrs3265->SetMinimum(0.101);
   Graph_asymm_ptj_toterrs3265->SetMaximum(0.7);
   Graph_asymm_ptj_toterrs3265->SetDirectory(0);
   Graph_asymm_ptj_toterrs3265->SetStats(0);
   Graph_asymm_ptj_toterrs3265->SetLineWidth(2);
   Graph_asymm_ptj_toterrs3265->SetMarkerStyle(0);
   Graph_asymm_ptj_toterrs3265->GetXaxis()->SetRange(1,100);
   Graph_asymm_ptj_toterrs3265->GetXaxis()->SetNdivisions(4);
   Graph_asymm_ptj_toterrs3265->GetXaxis()->SetLabelFont(132);
   Graph_asymm_ptj_toterrs3265->GetXaxis()->SetLabelOffset(999);
   Graph_asymm_ptj_toterrs3265->GetXaxis()->SetLabelSize(0);
   Graph_asymm_ptj_toterrs3265->GetXaxis()->SetTitleSize(0.06);
   Graph_asymm_ptj_toterrs3265->GetXaxis()->SetTitleFont(132);
   Graph_asymm_ptj_toterrs3265->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_asymm_ptj_toterrs3265->GetYaxis()->SetLabelFont(132);
   Graph_asymm_ptj_toterrs3265->GetYaxis()->SetLabelSize(0.05);
   Graph_asymm_ptj_toterrs3265->GetYaxis()->SetTitleSize(0.06);
   Graph_asymm_ptj_toterrs3265->GetYaxis()->SetTitleFont(132);
   Graph_asymm_ptj_toterrs3265->GetZaxis()->SetLabelFont(132);
   Graph_asymm_ptj_toterrs3265->GetZaxis()->SetLabelSize(0.05);
   Graph_asymm_ptj_toterrs3265->GetZaxis()->SetTitleSize(0.06);
   Graph_asymm_ptj_toterrs3265->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_asymm_ptj_toterrs3265);
   
   grae->Draw("p1p");
   
   Double_t _fx3266[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t _fy3266[5] = {
   0.2141988,
   0.2247928,
   0.2485379,
   0.2608521,
   0.2879919};
   Double_t _felx3266[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3266[5] = {
   0.0007983595,
   0.0008960366,
   0.0009724647,
   0.0004315674,
   0.001308113};
   Double_t _fehx3266[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3266[5] = {
   0.001333997,
   0.001231641,
   0.001317173,
   0.0008136034,
   0.002177775};
   grae = new TGraphAsymmErrors(5,_fx3266,_fy3266,_felx3266,_fehx3266,_fely3266,_fehy3266);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3266 = new TH1F("Graph_Graph3266","",100,17.175,72.075);
   Graph_Graph3266->SetMinimum(0.101);
   Graph_Graph3266->SetMaximum(0.7);
   Graph_Graph3266->SetDirectory(0);
   Graph_Graph3266->SetStats(0);
   Graph_Graph3266->SetLineWidth(2);
   Graph_Graph3266->SetMarkerStyle(0);
   Graph_Graph3266->GetXaxis()->SetRange(1,100);
   Graph_Graph3266->GetXaxis()->SetNdivisions(4);
   Graph_Graph3266->GetXaxis()->SetLabelFont(132);
   Graph_Graph3266->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3266->GetXaxis()->SetLabelSize(0);
   Graph_Graph3266->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3266->GetXaxis()->SetTitleFont(132);
   Graph_Graph3266->GetYaxis()->SetTitle("A(#it{Wj})");
   Graph_Graph3266->GetYaxis()->SetLabelFont(132);
   Graph_Graph3266->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3266->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3266->GetYaxis()->SetTitleFont(132);
   Graph_Graph3266->GetZaxis()->SetLabelFont(132);
   Graph_Graph3266->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3266->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3266->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3266);
   
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
   Double_t xAxis180[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *w_a_ptj_toterr_copy__210 = new TH1F("w_a_ptj_toterr_copy__210","w_ptj",5, xAxis180);
   w_a_ptj_toterr_copy__210->SetBinContent(1,0.2297775);
   w_a_ptj_toterr_copy__210->SetBinContent(2,0.2603096);
   w_a_ptj_toterr_copy__210->SetBinContent(3,0.259545);
   w_a_ptj_toterr_copy__210->SetBinContent(4,0.2667569);
   w_a_ptj_toterr_copy__210->SetBinContent(5,0.3469177);
   w_a_ptj_toterr_copy__210->SetBinContent(6,0.3469177);
   w_a_ptj_toterr_copy__210->SetBinError(1,0.01767501);
   w_a_ptj_toterr_copy__210->SetBinError(2,0.01912261);
   w_a_ptj_toterr_copy__210->SetBinError(3,0.01827246);
   w_a_ptj_toterr_copy__210->SetBinError(4,0.02475487);
   w_a_ptj_toterr_copy__210->SetBinError(5,0.02993453);
   w_a_ptj_toterr_copy__210->SetBinError(6,0.02993453);
   w_a_ptj_toterr_copy__210->SetMinimum(0.101);
   w_a_ptj_toterr_copy__210->SetMaximum(0.7);
   w_a_ptj_toterr_copy__210->SetEntries(7);
   w_a_ptj_toterr_copy__210->SetDirectory(0);
   w_a_ptj_toterr_copy__210->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   w_a_ptj_toterr_copy__210->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   w_a_ptj_toterr_copy__210->SetLineColor(ci);
   w_a_ptj_toterr_copy__210->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   w_a_ptj_toterr_copy__210->SetMarkerColor(ci);
   w_a_ptj_toterr_copy__210->SetMarkerStyle(0);
   w_a_ptj_toterr_copy__210->GetXaxis()->SetRange(1,5);
   w_a_ptj_toterr_copy__210->GetXaxis()->SetNdivisions(4);
   w_a_ptj_toterr_copy__210->GetXaxis()->SetLabelFont(132);
   w_a_ptj_toterr_copy__210->GetXaxis()->SetLabelOffset(999);
   w_a_ptj_toterr_copy__210->GetXaxis()->SetLabelSize(0);
   w_a_ptj_toterr_copy__210->GetXaxis()->SetTitleSize(0.06);
   w_a_ptj_toterr_copy__210->GetXaxis()->SetTitleFont(132);
   w_a_ptj_toterr_copy__210->GetYaxis()->SetTitle("A(#it{Wj})");
   w_a_ptj_toterr_copy__210->GetYaxis()->SetLabelFont(132);
   w_a_ptj_toterr_copy__210->GetYaxis()->SetLabelSize(0.05);
   w_a_ptj_toterr_copy__210->GetYaxis()->SetTitleSize(0.06);
   w_a_ptj_toterr_copy__210->GetYaxis()->SetTitleFont(132);
   w_a_ptj_toterr_copy__210->GetZaxis()->SetLabelFont(132);
   w_a_ptj_toterr_copy__210->GetZaxis()->SetLabelSize(0.05);
   w_a_ptj_toterr_copy__210->GetZaxis()->SetTitleSize(0.06);
   w_a_ptj_toterr_copy__210->GetZaxis()->SetTitleFont(132);
   w_a_ptj_toterr_copy__210->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(6.172839,-0.2428718,104.9383,0.7776411);
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
   Double_t xAxis181[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211 = new TH1F("wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211","w_ptj",5, xAxis181);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetBinContent(6,0.3469177);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetBinError(1,0.01767501);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetBinError(2,0.01912261);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetBinError(3,0.01827246);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetBinError(4,0.02475487);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetBinError(5,0.02993453);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetBinError(6,0.02993453);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetMinimum(-0.1);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetMaximum(0.099);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetEntries(12);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetLineColor(ci);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetMarkerColor(ci);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->SetMarkerStyle(0);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetXaxis()->SetRange(1,5);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetXaxis()->SetNdivisions(4);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetXaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetXaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetYaxis()->SetTitle("Diff.");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetYaxis()->SetNdivisions(505);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetYaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetYaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetZaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->GetZaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0__211->Draw("e2");
   Double_t xAxis182[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212 = new TH1F("wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212","w_ptj",5, xAxis182);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetBinContent(6,0.3469177);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetBinError(1,0.005531756);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetBinError(2,0.006866338);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetBinError(3,0.006466518);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetBinError(4,0.009108666);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetBinError(5,0.008272767);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetBinError(6,0.008272767);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetMinimum(-0.1);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetMaximum(0.099);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetEntries(12);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetLineColor(ci);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetMarkerColor(ci);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->SetMarkerStyle(0);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetXaxis()->SetRange(1,5);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetXaxis()->SetNdivisions(4);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetXaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetXaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetYaxis()->SetTitle("Diff.");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetYaxis()->SetNdivisions(505);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetYaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetYaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetZaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->GetZaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp1__212->Draw("e2same");
   
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fx3267[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fy3267[5] = {
   -0.03773075,
   -0.008217543,
   -0.03000906,
   -0.01863173,
   -0.07596588};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp2_felx3267[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fely3267[5] = {
   0.01472643,
   0.04212129,
   0.02157426,
   0.01951616,
   0.02758839};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fehx3267[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fehy3267[5] = {
   0.0222348,
   0.01006934,
   0.02822224,
   0.02248663,
   0.03700491};
   grae = new TGraphAsymmErrors(5,wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fx3267,wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fy3267,wj_asymm_ptj_8TeV_400_1001_0diffcomp2_felx3267,wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fehx3267,wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fely3267,wj_asymm_ptj_8TeV_400_1001_0diffcomp2_fehy3267);
   grae->SetName("wj_asymm_ptj_8TeV_400_1001_0diffcomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267 = new TH1F("Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267","",100,17.325,88.425);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->SetMinimum(-0.1);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->SetMaximum(0.099);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->SetDirectory(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->SetStats(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->SetLineWidth(2);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->SetMarkerStyle(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetXaxis()->SetRange(1,100);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp23267);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fx3268[5] = {
   23.25,
   28.25,
   36.5,
   46.5,
   82.5};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fy3268[5] = {
   -0.03773075,
   -0.008217543,
   -0.03000906,
   -0.01863173,
   -0.07596588};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp3_felx3268[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fely3268[5] = {
   0.006560758,
   0.000836283,
   0.01128179,
   0.004023209,
   0.006760776};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fehx3268[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fehy3268[5] = {
   0.006858453,
   0.001389325,
   0.009908676,
   0.0046992,
   0.005705625};
   grae = new TGraphAsymmErrors(5,wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fx3268,wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fy3268,wj_asymm_ptj_8TeV_400_1001_0diffcomp3_felx3268,wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fehx3268,wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fely3268,wj_asymm_ptj_8TeV_400_1001_0diffcomp3_fehy3268);
   grae->SetName("wj_asymm_ptj_8TeV_400_1001_0diffcomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268 = new TH1F("Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268","",100,17.325,88.425);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->SetMinimum(-0.1);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->SetMaximum(0.099);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->SetDirectory(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->SetStats(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->SetLineWidth(2);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->SetMarkerStyle(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetXaxis()->SetRange(1,100);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp33268);
   
   grae->Draw("p1");
   
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fx3269[5] = {
   21.75,
   26.75,
   33.5,
   43.5,
   67.5};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fy3269[5] = {
   -0.01557864,
   -0.03551677,
   -0.0110071,
   -0.005904794,
   -0.05892578};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp4_felx3269[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fely3269[5] = {
   0.008252311,
   0.00886514,
   0.01504863,
   0.01306144,
   0.01611142};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fehx3269[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fehy3269[5] = {
   0.008543443,
   0.0103666,
   0.01046673,
   0.01357977,
   0.01730278};
   grae = new TGraphAsymmErrors(5,wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fx3269,wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fy3269,wj_asymm_ptj_8TeV_400_1001_0diffcomp4_felx3269,wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fehx3269,wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fely3269,wj_asymm_ptj_8TeV_400_1001_0diffcomp4_fehy3269);
   grae->SetName("wj_asymm_ptj_8TeV_400_1001_0diffcomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269 = new TH1F("Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269","",100,17.175,72.075);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->SetMinimum(-0.1);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->SetMaximum(0.099);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->SetDirectory(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->SetStats(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->SetLineWidth(2);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->SetMarkerStyle(0);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetXaxis()->SetRange(1,100);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetXaxis()->SetNdivisions(4);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetXaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetXaxis()->SetLabelOffset(0.02);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetXaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetXaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetXaxis()->SetTitleFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetYaxis()->SetTitle("Diff.");
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetYaxis()->SetNdivisions(505);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetYaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetYaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetYaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetYaxis()->SetTitleOffset(1.2);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetYaxis()->SetTitleFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetZaxis()->SetLabelFont(132);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetZaxis()->SetLabelSize(0.05);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetZaxis()->SetTitleSize(0.06);
   Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_wj_asymm_ptj_8TeV_400_1001_0diffcomp43269);
   
   grae->Draw("p1");
   Double_t xAxis183[6] = {20, 25, 30, 40, 50, 100}; 
   
   TH1F *wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213 = new TH1F("wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213","w_ptj",5, xAxis183);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetBinContent(6,0.3469177);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetBinError(1,0.01767501);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetBinError(2,0.01912261);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetBinError(3,0.01827246);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetBinError(4,0.02475487);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetBinError(5,0.02993453);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetBinError(6,0.02993453);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetMinimum(-0.1);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetMaximum(0.099);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetEntries(12);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetDirectory(0);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetLineColor(ci);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetMarkerColor(ci);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->SetMarkerStyle(0);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetXaxis()->SetTitle("#it{p}_{T}^{jet} [GeV]");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetXaxis()->SetRange(1,5);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetXaxis()->SetNdivisions(4);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetXaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetXaxis()->SetLabelOffset(0.02);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetXaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetXaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetXaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetYaxis()->SetTitle("Diff.");
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetYaxis()->SetNdivisions(505);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetYaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetYaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetYaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetYaxis()->SetTickLength(0.12325);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetYaxis()->SetTitleOffset(1.2);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetYaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetZaxis()->SetLabelFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetZaxis()->SetLabelSize(0.05);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetZaxis()->SetTitleSize(0.06);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->GetZaxis()->SetTitleFont(132);
   wj_asymm_ptj_8TeV_400_1001_0diffcomp0_copy__213->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
