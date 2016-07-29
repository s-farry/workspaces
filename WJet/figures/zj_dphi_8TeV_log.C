void zj_dphi_8TeV_log()
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
   upperPad->Range(-0.5429913,-2.062865,3.335518,1.327192);
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
   
   TH1F *z_dphi_toterr__37 = new TH1F("z_dphi_toterr__37","z_dphi",6,0,3.141593);
   z_dphi_toterr__37->SetBinContent(1,0.261202);
   z_dphi_toterr__37->SetBinContent(2,0.3162337);
   z_dphi_toterr__37->SetBinContent(3,0.3852335);
   z_dphi_toterr__37->SetBinContent(4,0.7150939);
   z_dphi_toterr__37->SetBinContent(5,1.796506);
   z_dphi_toterr__37->SetBinContent(6,7.258657);
   z_dphi_toterr__37->SetBinContent(7,3.800624);
   z_dphi_toterr__37->SetBinError(1,0.03375302);
   z_dphi_toterr__37->SetBinError(2,0.03634611);
   z_dphi_toterr__37->SetBinError(3,0.0427511);
   z_dphi_toterr__37->SetBinError(4,0.05747346);
   z_dphi_toterr__37->SetBinError(5,0.1278198);
   z_dphi_toterr__37->SetBinError(6,0.3295685);
   z_dphi_toterr__37->SetBinError(7,0.1725617);
   z_dphi_toterr__37->SetEntries(14);
   z_dphi_toterr__37->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr__37->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr__37->SetLineColor(ci);
   z_dphi_toterr__37->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr__37->SetMarkerColor(ci);
   z_dphi_toterr__37->SetMarkerStyle(0);
   z_dphi_toterr__37->GetXaxis()->SetNdivisions(4);
   z_dphi_toterr__37->GetXaxis()->SetLabelFont(132);
   z_dphi_toterr__37->GetXaxis()->SetLabelOffset(999);
   z_dphi_toterr__37->GetXaxis()->SetLabelSize(0);
   z_dphi_toterr__37->GetXaxis()->SetTitleSize(0.06);
   z_dphi_toterr__37->GetXaxis()->SetTitleFont(132);
   z_dphi_toterr__37->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   z_dphi_toterr__37->GetYaxis()->SetLabelFont(132);
   z_dphi_toterr__37->GetYaxis()->SetLabelSize(0.05);
   z_dphi_toterr__37->GetYaxis()->SetTitleSize(0.06);
   z_dphi_toterr__37->GetYaxis()->SetTitleOffset(1.3);
   z_dphi_toterr__37->GetYaxis()->SetTitleFont(132);
   z_dphi_toterr__37->GetZaxis()->SetLabelFont(132);
   z_dphi_toterr__37->GetZaxis()->SetLabelSize(0.05);
   z_dphi_toterr__37->GetZaxis()->SetTitleSize(0.06);
   z_dphi_toterr__37->GetZaxis()->SetTitleFont(132);
   z_dphi_toterr__37->Draw("e2");
   
   TH1F *z_dphi_staterr__38 = new TH1F("z_dphi_staterr__38","z_dphi",6,0,3.141593);
   z_dphi_staterr__38->SetBinContent(1,0.261202);
   z_dphi_staterr__38->SetBinContent(2,0.3162337);
   z_dphi_staterr__38->SetBinContent(3,0.3852335);
   z_dphi_staterr__38->SetBinContent(4,0.7150939);
   z_dphi_staterr__38->SetBinContent(5,1.796506);
   z_dphi_staterr__38->SetBinContent(6,7.258657);
   z_dphi_staterr__38->SetBinContent(7,3.800624);
   z_dphi_staterr__38->SetBinError(1,0.01764622);
   z_dphi_staterr__38->SetBinError(2,0.01951211);
   z_dphi_staterr__38->SetBinError(3,0.02108379);
   z_dphi_staterr__38->SetBinError(4,0.03021233);
   z_dphi_staterr__38->SetBinError(5,0.04899558);
   z_dphi_staterr__38->SetBinError(6,0.1002775);
   z_dphi_staterr__38->SetBinError(7,0.05250516);
   z_dphi_staterr__38->SetEntries(14);
   z_dphi_staterr__38->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   z_dphi_staterr__38->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   z_dphi_staterr__38->SetLineColor(ci);
   z_dphi_staterr__38->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   z_dphi_staterr__38->SetMarkerColor(ci);
   z_dphi_staterr__38->SetMarkerStyle(0);
   z_dphi_staterr__38->GetXaxis()->SetNdivisions(4);
   z_dphi_staterr__38->GetXaxis()->SetLabelFont(132);
   z_dphi_staterr__38->GetXaxis()->SetLabelOffset(999);
   z_dphi_staterr__38->GetXaxis()->SetLabelSize(0);
   z_dphi_staterr__38->GetXaxis()->SetTitleSize(0.06);
   z_dphi_staterr__38->GetXaxis()->SetTitleFont(132);
   z_dphi_staterr__38->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   z_dphi_staterr__38->GetYaxis()->SetLabelFont(132);
   z_dphi_staterr__38->GetYaxis()->SetLabelSize(0.05);
   z_dphi_staterr__38->GetYaxis()->SetTitleSize(0.06);
   z_dphi_staterr__38->GetYaxis()->SetTitleFont(132);
   z_dphi_staterr__38->GetZaxis()->SetLabelFont(132);
   z_dphi_staterr__38->GetZaxis()->SetLabelSize(0.05);
   z_dphi_staterr__38->GetZaxis()->SetTitleSize(0.06);
   z_dphi_staterr__38->GetZaxis()->SetTitleFont(132);
   z_dphi_staterr__38->Draw("e2same");
   
   Double_t dphi_toterrs_fx3043[6] = {
   0.3403392,
   0.863938,
   1.387537,
   1.911136,
   2.434734,
   2.958333};
   Double_t dphi_toterrs_fy3043[6] = {
   0.1926519,
   0.2207154,
   0.3546338,
   0.6864677,
   2.01515,
   7.779723};
   Double_t dphi_toterrs_felx3043[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t dphi_toterrs_fely3043[6] = {
   0.03415733,
   0.03577312,
   0.05682396,
   0.09598937,
   0.1897309,
   0.5023379};
   Double_t dphi_toterrs_fehx3043[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t dphi_toterrs_fehy3043[6] = {
   0.04673612,
   0.05211068,
   0.07287587,
   0.1207667,
   0.143423,
   0.3949306};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6,dphi_toterrs_fx3043,dphi_toterrs_fy3043,dphi_toterrs_felx3043,dphi_toterrs_fehx3043,dphi_toterrs_fely3043,dphi_toterrs_fehy3043);
   grae->SetName("dphi_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_dphi_toterrs3043 = new TH1F("Graph_dphi_toterrs3043","",100,0.07853982,3.220132);
   Graph_dphi_toterrs3043->SetMinimum(0.1426451);
   Graph_dphi_toterrs3043->SetMaximum(8.976269);
   Graph_dphi_toterrs3043->SetDirectory(0);
   Graph_dphi_toterrs3043->SetStats(0);
   Graph_dphi_toterrs3043->SetLineWidth(2);
   Graph_dphi_toterrs3043->SetMarkerStyle(0);
   Graph_dphi_toterrs3043->GetXaxis()->SetNdivisions(4);
   Graph_dphi_toterrs3043->GetXaxis()->SetLabelFont(132);
   Graph_dphi_toterrs3043->GetXaxis()->SetLabelOffset(999);
   Graph_dphi_toterrs3043->GetXaxis()->SetLabelSize(0);
   Graph_dphi_toterrs3043->GetXaxis()->SetTitleSize(0.06);
   Graph_dphi_toterrs3043->GetXaxis()->SetTitleFont(132);
   Graph_dphi_toterrs3043->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   Graph_dphi_toterrs3043->GetYaxis()->SetLabelFont(132);
   Graph_dphi_toterrs3043->GetYaxis()->SetLabelSize(0.05);
   Graph_dphi_toterrs3043->GetYaxis()->SetTitleSize(0.06);
   Graph_dphi_toterrs3043->GetYaxis()->SetTitleFont(132);
   Graph_dphi_toterrs3043->GetZaxis()->SetLabelFont(132);
   Graph_dphi_toterrs3043->GetZaxis()->SetLabelSize(0.05);
   Graph_dphi_toterrs3043->GetZaxis()->SetTitleSize(0.06);
   Graph_dphi_toterrs3043->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_dphi_toterrs3043);
   
   grae->Draw("p1p");
   
   Double_t _fx3044[6] = {
   0.3403392,
   0.863938,
   1.387537,
   1.911136,
   2.434734,
   2.958333};
   Double_t _fy3044[6] = {
   0.1926519,
   0.2207154,
   0.3546338,
   0.6864677,
   2.01515,
   7.779723};
   Double_t _felx3044[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3044[6] = {
   0.02873042,
   0.03223617,
   0.04948444,
   0.07740101,
   0.1117696,
   0.3251484};
   Double_t _fehx3044[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3044[6] = {
   0.03948655,
   0.04420709,
   0.06698785,
   0.1028379,
   0.1104173,
   0.2636435};
   grae = new TGraphAsymmErrors(6,_fx3044,_fy3044,_felx3044,_fehx3044,_fely3044,_fehy3044);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph3044 = new TH1F("Graph_Graph3044","",100,0.07853982,3.220132);
   Graph_Graph3044->SetMinimum(0.1475293);
   Graph_Graph3044->SetMaximum(8.831311);
   Graph_Graph3044->SetDirectory(0);
   Graph_Graph3044->SetStats(0);
   Graph_Graph3044->SetLineWidth(2);
   Graph_Graph3044->SetMarkerStyle(0);
   Graph_Graph3044->GetXaxis()->SetNdivisions(4);
   Graph_Graph3044->GetXaxis()->SetLabelFont(132);
   Graph_Graph3044->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3044->GetXaxis()->SetLabelSize(0);
   Graph_Graph3044->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3044->GetXaxis()->SetTitleFont(132);
   Graph_Graph3044->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   Graph_Graph3044->GetYaxis()->SetLabelFont(132);
   Graph_Graph3044->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3044->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3044->GetYaxis()->SetTitleFont(132);
   Graph_Graph3044->GetZaxis()->SetLabelFont(132);
   Graph_Graph3044->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3044->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3044->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3044);
   
   grae->Draw("p1p");
   
   Double_t dphi_toterrs_fx3045[6] = {
   0.1832596,
   0.7068583,
   1.230457,
   1.754056,
   2.277655,
   2.801253};
   Double_t dphi_toterrs_fy3045[6] = {
   0.3071206,
   0.3788296,
   0.5235754,
   0.9026085,
   2.09773,
   8.042891};
   Double_t dphi_toterrs_felx3045[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t dphi_toterrs_fely3045[6] = {
   0.03223837,
   0.05049376,
   0.0513308,
   0.07859791,
   0.1671821,
   0.6048482};
   Double_t dphi_toterrs_fehx3045[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t dphi_toterrs_fehy3045[6] = {
   0.05069997,
   0.04670219,
   0.05741781,
   0.0972528,
   0.2140117,
   0.6377428};
   grae = new TGraphAsymmErrors(6,dphi_toterrs_fx3045,dphi_toterrs_fy3045,dphi_toterrs_felx3045,dphi_toterrs_fehx3045,dphi_toterrs_fely3045,dphi_toterrs_fehy3045);
   grae->SetName("dphi_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_dphi_toterrs3045 = new TH1F("Graph_dphi_toterrs3045","",100,0,3.063053);
   Graph_dphi_toterrs3045->SetMinimum(0.247394);
   Graph_dphi_toterrs3045->SetMaximum(9.521209);
   Graph_dphi_toterrs3045->SetDirectory(0);
   Graph_dphi_toterrs3045->SetStats(0);
   Graph_dphi_toterrs3045->SetLineWidth(2);
   Graph_dphi_toterrs3045->SetMarkerStyle(0);
   Graph_dphi_toterrs3045->GetXaxis()->SetNdivisions(4);
   Graph_dphi_toterrs3045->GetXaxis()->SetLabelFont(132);
   Graph_dphi_toterrs3045->GetXaxis()->SetLabelOffset(999);
   Graph_dphi_toterrs3045->GetXaxis()->SetLabelSize(0);
   Graph_dphi_toterrs3045->GetXaxis()->SetTitleSize(0.06);
   Graph_dphi_toterrs3045->GetXaxis()->SetTitleFont(132);
   Graph_dphi_toterrs3045->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   Graph_dphi_toterrs3045->GetYaxis()->SetLabelFont(132);
   Graph_dphi_toterrs3045->GetYaxis()->SetLabelSize(0.05);
   Graph_dphi_toterrs3045->GetYaxis()->SetTitleSize(0.06);
   Graph_dphi_toterrs3045->GetYaxis()->SetTitleFont(132);
   Graph_dphi_toterrs3045->GetZaxis()->SetLabelFont(132);
   Graph_dphi_toterrs3045->GetZaxis()->SetLabelSize(0.05);
   Graph_dphi_toterrs3045->GetZaxis()->SetTitleSize(0.06);
   Graph_dphi_toterrs3045->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_dphi_toterrs3045);
   
   grae->Draw("p1p");
   
   Double_t _fx3046[6] = {
   0.1832596,
   0.7068583,
   1.230457,
   1.754056,
   2.277655,
   2.801253};
   Double_t _fy3046[6] = {
   0.3071206,
   0.3788296,
   0.5235754,
   0.9026085,
   2.09773,
   8.042891};
   Double_t _felx3046[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3046[6] = {
   0.02710968,
   0.03295216,
   0.04124188,
   0.06402796,
   0.1338949,
   0.4694553};
   Double_t _fehx3046[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3046[6] = {
   0.03469016,
   0.04020747,
   0.048986,
   0.07362466,
   0.1488417,
   0.5027875};
   grae = new TGraphAsymmErrors(6,_fx3046,_fy3046,_felx3046,_fehx3046,_fely3046,_fehy3046);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3046 = new TH1F("Graph_Graph3046","",100,0,3.063053);
   Graph_Graph3046->SetMinimum(0.2520099);
   Graph_Graph3046->SetMaximum(9.372245);
   Graph_Graph3046->SetDirectory(0);
   Graph_Graph3046->SetStats(0);
   Graph_Graph3046->SetLineWidth(2);
   Graph_Graph3046->SetMarkerStyle(0);
   Graph_Graph3046->GetXaxis()->SetNdivisions(4);
   Graph_Graph3046->GetXaxis()->SetLabelFont(132);
   Graph_Graph3046->GetXaxis()->SetLabelOffset(999);
   Graph_Graph3046->GetXaxis()->SetLabelSize(0);
   Graph_Graph3046->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph3046->GetXaxis()->SetTitleFont(132);
   Graph_Graph3046->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   Graph_Graph3046->GetYaxis()->SetLabelFont(132);
   Graph_Graph3046->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3046->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph3046->GetYaxis()->SetTitleFont(132);
   Graph_Graph3046->GetZaxis()->SetLabelFont(132);
   Graph_Graph3046->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph3046->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph3046->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph3046);
   
   grae->Draw("p1p");
   
   TLegend *leg = new TLegend(0.2,0.57,0.5,0.82,NULL,"brNDC");
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
   
   TPaveText *pt = new TPaveText(0.2,0.8,0.55,0.95,"brNDC");
   pt->SetBorderSize(0);
   pt->SetFillStyle(0);
   pt->SetLineWidth(2);
   pt->SetTextFont(132);
   TText *AText = pt->AddText("LHCb, #sqrt{s} = 8 TeV");
   pt->Draw();
   
   TH1F *z_dphi_toterr_copy__39 = new TH1F("z_dphi_toterr_copy__39","z_dphi",6,0,3.141593);
   z_dphi_toterr_copy__39->SetBinContent(1,0.261202);
   z_dphi_toterr_copy__39->SetBinContent(2,0.3162337);
   z_dphi_toterr_copy__39->SetBinContent(3,0.3852335);
   z_dphi_toterr_copy__39->SetBinContent(4,0.7150939);
   z_dphi_toterr_copy__39->SetBinContent(5,1.796506);
   z_dphi_toterr_copy__39->SetBinContent(6,7.258657);
   z_dphi_toterr_copy__39->SetBinContent(7,3.800624);
   z_dphi_toterr_copy__39->SetBinError(1,0.03375302);
   z_dphi_toterr_copy__39->SetBinError(2,0.03634611);
   z_dphi_toterr_copy__39->SetBinError(3,0.0427511);
   z_dphi_toterr_copy__39->SetBinError(4,0.05747346);
   z_dphi_toterr_copy__39->SetBinError(5,0.1278198);
   z_dphi_toterr_copy__39->SetBinError(6,0.3295685);
   z_dphi_toterr_copy__39->SetBinError(7,0.1725617);
   z_dphi_toterr_copy__39->SetEntries(14);
   z_dphi_toterr_copy__39->SetDirectory(0);
   z_dphi_toterr_copy__39->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr_copy__39->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr_copy__39->SetLineColor(ci);
   z_dphi_toterr_copy__39->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr_copy__39->SetMarkerColor(ci);
   z_dphi_toterr_copy__39->SetMarkerStyle(0);
   z_dphi_toterr_copy__39->GetXaxis()->SetNdivisions(4);
   z_dphi_toterr_copy__39->GetXaxis()->SetLabelFont(132);
   z_dphi_toterr_copy__39->GetXaxis()->SetLabelOffset(999);
   z_dphi_toterr_copy__39->GetXaxis()->SetLabelSize(0);
   z_dphi_toterr_copy__39->GetXaxis()->SetTitleSize(0.06);
   z_dphi_toterr_copy__39->GetXaxis()->SetTitleFont(132);
   z_dphi_toterr_copy__39->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   z_dphi_toterr_copy__39->GetYaxis()->SetLabelFont(132);
   z_dphi_toterr_copy__39->GetYaxis()->SetLabelSize(0.05);
   z_dphi_toterr_copy__39->GetYaxis()->SetTitleSize(0.06);
   z_dphi_toterr_copy__39->GetYaxis()->SetTitleOffset(1.3);
   z_dphi_toterr_copy__39->GetYaxis()->SetTitleFont(132);
   z_dphi_toterr_copy__39->GetZaxis()->SetLabelFont(132);
   z_dphi_toterr_copy__39->GetZaxis()->SetLabelSize(0.05);
   z_dphi_toterr_copy__39->GetZaxis()->SetTitleSize(0.06);
   z_dphi_toterr_copy__39->GetZaxis()->SetTitleFont(132);
   z_dphi_toterr_copy__39->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
  
// ------------>Primitives in pad: lowerPad
   TPad *lowerPad = new TPad("lowerPad", "lowerPad",0.005,0.05,0.995,0.995);
   lowerPad->Draw();
   lowerPad->cd();
   lowerPad->Range(-0.5429913,-0.4371795,3.335518,5.614103);
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
   
   TH1F *zj_dphi_8TeV_log_400_1001_0ratiocomp0__40 = new TH1F("zj_dphi_8TeV_log_400_1001_0ratiocomp0__40","z_dphi",6,0,3.141593);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinContent(1,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinContent(2,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinContent(3,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinContent(4,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinContent(5,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinContent(6,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinContent(7,3.800624);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinError(1,0.1292219);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinError(2,0.1149343);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinError(3,0.1109745);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinError(4,0.08037191);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinError(5,0.07114914);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinError(6,0.04540351);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetBinError(7,0.1725617);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetMinimum(0.41);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetMaximum(1.59);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetEntries(20);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetLineColor(ci);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetMarkerColor(ci);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->SetMarkerStyle(0);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetXaxis()->SetNdivisions(4);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetXaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetXaxis()->SetLabelOffset(0.02);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetXaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetXaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetXaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->SetTitle("Ratio");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->CenterTitle(true);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->SetNdivisions(505);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->SetTickLength(0.12325);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->SetTitleOffset(1.3);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetYaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetZaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetZaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetZaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->GetZaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0__40->Draw("e2");
   
   TH1F *zj_dphi_8TeV_log_400_1001_0ratiocomp1__41 = new TH1F("zj_dphi_8TeV_log_400_1001_0ratiocomp1__41","z_dphi",6,0,3.141593);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinContent(1,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinContent(2,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinContent(3,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinContent(4,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinContent(5,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinContent(6,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinContent(7,3.800624);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinError(1,0.06755777);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinError(2,0.06170157);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinError(3,0.0547299);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinError(4,0.04224946);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinError(5,0.02727271);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinError(6,0.01381488);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetBinError(7,0.05250516);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetMinimum(0.41);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetMaximum(1.59);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetEntries(20);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetLineColor(ci);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetMarkerColor(ci);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->SetMarkerStyle(0);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetXaxis()->SetNdivisions(4);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetXaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetXaxis()->SetLabelOffset(0.02);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetXaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetXaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetXaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetYaxis()->SetTitle("Ratio");
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetYaxis()->CenterTitle(true);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetYaxis()->SetNdivisions(505);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetYaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetYaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetYaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetYaxis()->SetTickLength(0.12325);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetYaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetZaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetZaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetZaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->GetZaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp1__41->Draw("e2same");
   
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp2_fx3047[6] = {
   0.3403392,
   0.863938,
   1.387537,
   1.911136,
   2.434734,
   2.958333};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp2_fy3047[6] = {
   0.7375589,
   0.6979502,
   0.9205685,
   0.9599686,
   1.121705,
   1.071786};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp2_felx3047[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp2_fely3047[6] = {
   0.1307698,
   0.1131224,
   0.1475052,
   0.1342332,
   0.1056111,
   0.06920535};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp2_fehx3047[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp2_fehy3047[6] = {
   0.1789271,
   0.1647854,
   0.1891732,
   0.1688822,
   0.07983441,
   0.05440822};
   grae = new TGraphAsymmErrors(6,zj_dphi_8TeV_log_400_1001_0ratiocomp2_fx3047,zj_dphi_8TeV_log_400_1001_0ratiocomp2_fy3047,zj_dphi_8TeV_log_400_1001_0ratiocomp2_felx3047,zj_dphi_8TeV_log_400_1001_0ratiocomp2_fehx3047,zj_dphi_8TeV_log_400_1001_0ratiocomp2_fely3047,zj_dphi_8TeV_log_400_1001_0ratiocomp2_fehy3047);
   grae->SetName("zj_dphi_8TeV_log_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047 = new TH1F("Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047","",100,0.07853982,3.220132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->SetMinimum(0.41);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->SetMaximum(1.59);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->SetDirectory(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->SetStats(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->SetLineWidth(2);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->SetMarkerStyle(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetXaxis()->SetNdivisions(4);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetXaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetXaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetYaxis()->SetTitle("Ratio");
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetYaxis()->CenterTitle(true);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetYaxis()->SetNdivisions(505);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetYaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetYaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetZaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp23047);
   
   grae->Draw("p1");
   
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp3_fx3048[6] = {
   0.3403392,
   0.863938,
   1.387537,
   1.911136,
   2.434734,
   2.958333};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp3_fy3048[6] = {
   0.7375589,
   0.6979502,
   0.9205685,
   0.9599686,
   1.121705,
   1.071786};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp3_felx3048[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp3_fely3048[6] = {
   0.1099931,
   0.1019378,
   0.1284531,
   0.1082389,
   0.06221498,
   0.04479457};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp3_fehx3048[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp3_fehy3048[6] = {
   0.1511724,
   0.1397925,
   0.1738889,
   0.1438103,
   0.06146226,
   0.03632125};
   grae = new TGraphAsymmErrors(6,zj_dphi_8TeV_log_400_1001_0ratiocomp3_fx3048,zj_dphi_8TeV_log_400_1001_0ratiocomp3_fy3048,zj_dphi_8TeV_log_400_1001_0ratiocomp3_felx3048,zj_dphi_8TeV_log_400_1001_0ratiocomp3_fehx3048,zj_dphi_8TeV_log_400_1001_0ratiocomp3_fely3048,zj_dphi_8TeV_log_400_1001_0ratiocomp3_fehy3048);
   grae->SetName("zj_dphi_8TeV_log_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048 = new TH1F("Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048","",100,0.07853982,3.220132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->SetMinimum(0.41);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->SetMaximum(1.59);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->SetDirectory(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->SetStats(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->SetLineWidth(2);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->SetMarkerStyle(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetXaxis()->SetNdivisions(4);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetXaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetXaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetYaxis()->SetTitle("Ratio");
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetYaxis()->CenterTitle(true);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetYaxis()->SetNdivisions(505);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetYaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetYaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetZaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp33048);
   
   grae->Draw("p1");
   
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp4_fx3049[6] = {
   0.1832596,
   0.7068583,
   1.230457,
   1.754056,
   2.277655,
   2.801253};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp4_fy3049[6] = {
   1.175797,
   1.197942,
   1.359112,
   1.262224,
   1.167673,
   1.108041};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp4_felx3049[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp4_fely3049[6] = {
   0.1234231,
   0.1596723,
   0.1332459,
   0.1099127,
   0.09305962,
   0.08332785};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp4_fehx3049[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_log_400_1001_0ratiocomp4_fehy3049[6] = {
   0.1941025,
   0.1476825,
   0.1490468,
   0.136,
   0.1191266,
   0.08785962};
   grae = new TGraphAsymmErrors(6,zj_dphi_8TeV_log_400_1001_0ratiocomp4_fx3049,zj_dphi_8TeV_log_400_1001_0ratiocomp4_fy3049,zj_dphi_8TeV_log_400_1001_0ratiocomp4_felx3049,zj_dphi_8TeV_log_400_1001_0ratiocomp4_fehx3049,zj_dphi_8TeV_log_400_1001_0ratiocomp4_fely3049,zj_dphi_8TeV_log_400_1001_0ratiocomp4_fehy3049);
   grae->SetName("zj_dphi_8TeV_log_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049 = new TH1F("Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049","",100,0,3.063053);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->SetMinimum(0.41);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->SetMaximum(1.59);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->SetDirectory(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->SetStats(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->SetLineWidth(2);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->SetMarkerStyle(0);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetXaxis()->SetNdivisions(4);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetXaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetXaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetYaxis()->SetTitle("Ratio");
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetYaxis()->CenterTitle(true);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetYaxis()->SetNdivisions(505);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetYaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetYaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetZaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_dphi_8TeV_log_400_1001_0ratiocomp43049);
   
   grae->Draw("p1");
   
   TH1F *zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42 = new TH1F("zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42","z_dphi",6,0,3.141593);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinContent(1,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinContent(2,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinContent(3,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinContent(4,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinContent(5,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinContent(6,1);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinContent(7,3.800624);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinError(1,0.1292219);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinError(2,0.1149343);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinError(3,0.1109745);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinError(4,0.08037191);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinError(5,0.07114914);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinError(6,0.04540351);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetBinError(7,0.1725617);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetMinimum(0.41);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetMaximum(1.59);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetEntries(20);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetDirectory(0);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetLineColor(ci);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetMarkerColor(ci);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->SetMarkerStyle(0);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetXaxis()->SetNdivisions(4);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetXaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetXaxis()->SetLabelOffset(0.02);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetXaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetXaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetXaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->SetTitle("Ratio");
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->CenterTitle(true);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->SetNdivisions(505);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->SetTickLength(0.12325);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->SetTitleOffset(1.3);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetYaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetZaxis()->SetLabelFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetZaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetZaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->GetZaxis()->SetTitleFont(132);
   zj_dphi_8TeV_log_400_1001_0ratiocomp0_copy__42->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
