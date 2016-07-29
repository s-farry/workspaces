void zj_dphi_8TeV()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Thu Apr 28 10:19:35 2016) by ROOT version6.04/10
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
   upperPad->Range(-0.5429913,-8.514598,3.335518,17.29024);
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
   
   TH1F *z_dphi_toterr__43 = new TH1F("z_dphi_toterr__43","z_dphi",6,0,3.141593);
   z_dphi_toterr__43->SetBinContent(1,0.261202);
   z_dphi_toterr__43->SetBinContent(2,0.3162337);
   z_dphi_toterr__43->SetBinContent(3,0.3852335);
   z_dphi_toterr__43->SetBinContent(4,0.7150939);
   z_dphi_toterr__43->SetBinContent(5,1.796506);
   z_dphi_toterr__43->SetBinContent(6,7.258657);
   z_dphi_toterr__43->SetBinContent(7,3.800624);
   z_dphi_toterr__43->SetBinError(1,0.03375302);
   z_dphi_toterr__43->SetBinError(2,0.03634611);
   z_dphi_toterr__43->SetBinError(3,0.0427511);
   z_dphi_toterr__43->SetBinError(4,0.05747346);
   z_dphi_toterr__43->SetBinError(5,0.1278198);
   z_dphi_toterr__43->SetBinError(6,0.3295685);
   z_dphi_toterr__43->SetBinError(7,0.1725617);
   z_dphi_toterr__43->SetMinimum(0.001);
   z_dphi_toterr__43->SetMaximum(16);
   z_dphi_toterr__43->SetEntries(14);
   z_dphi_toterr__43->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr__43->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr__43->SetLineColor(ci);
   z_dphi_toterr__43->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr__43->SetMarkerColor(ci);
   z_dphi_toterr__43->SetMarkerStyle(0);
   z_dphi_toterr__43->GetXaxis()->SetNdivisions(4);
   z_dphi_toterr__43->GetXaxis()->SetLabelFont(132);
   z_dphi_toterr__43->GetXaxis()->SetLabelOffset(999);
   z_dphi_toterr__43->GetXaxis()->SetLabelSize(0);
   z_dphi_toterr__43->GetXaxis()->SetTitleSize(0.06);
   z_dphi_toterr__43->GetXaxis()->SetTitleFont(132);
   z_dphi_toterr__43->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   z_dphi_toterr__43->GetYaxis()->SetLabelFont(132);
   z_dphi_toterr__43->GetYaxis()->SetLabelSize(0.05);
   z_dphi_toterr__43->GetYaxis()->SetTitleSize(0.06);
   z_dphi_toterr__43->GetYaxis()->SetTitleOffset(1.3);
   z_dphi_toterr__43->GetYaxis()->SetTitleFont(132);
   z_dphi_toterr__43->GetZaxis()->SetLabelFont(132);
   z_dphi_toterr__43->GetZaxis()->SetLabelSize(0.05);
   z_dphi_toterr__43->GetZaxis()->SetTitleSize(0.06);
   z_dphi_toterr__43->GetZaxis()->SetTitleFont(132);
   z_dphi_toterr__43->Draw("e2");
   
   TH1F *z_dphi_staterr__44 = new TH1F("z_dphi_staterr__44","z_dphi",6,0,3.141593);
   z_dphi_staterr__44->SetBinContent(1,0.261202);
   z_dphi_staterr__44->SetBinContent(2,0.3162337);
   z_dphi_staterr__44->SetBinContent(3,0.3852335);
   z_dphi_staterr__44->SetBinContent(4,0.7150939);
   z_dphi_staterr__44->SetBinContent(5,1.796506);
   z_dphi_staterr__44->SetBinContent(6,7.258657);
   z_dphi_staterr__44->SetBinContent(7,3.800624);
   z_dphi_staterr__44->SetBinError(1,0.01764622);
   z_dphi_staterr__44->SetBinError(2,0.01951211);
   z_dphi_staterr__44->SetBinError(3,0.02108379);
   z_dphi_staterr__44->SetBinError(4,0.03021233);
   z_dphi_staterr__44->SetBinError(5,0.04899558);
   z_dphi_staterr__44->SetBinError(6,0.1002775);
   z_dphi_staterr__44->SetBinError(7,0.05250516);
   z_dphi_staterr__44->SetMinimum(0.001);
   z_dphi_staterr__44->SetMaximum(16);
   z_dphi_staterr__44->SetEntries(14);
   z_dphi_staterr__44->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   z_dphi_staterr__44->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   z_dphi_staterr__44->SetLineColor(ci);
   z_dphi_staterr__44->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   z_dphi_staterr__44->SetMarkerColor(ci);
   z_dphi_staterr__44->SetMarkerStyle(0);
   z_dphi_staterr__44->GetXaxis()->SetNdivisions(4);
   z_dphi_staterr__44->GetXaxis()->SetLabelFont(132);
   z_dphi_staterr__44->GetXaxis()->SetLabelOffset(999);
   z_dphi_staterr__44->GetXaxis()->SetLabelSize(0);
   z_dphi_staterr__44->GetXaxis()->SetTitleSize(0.06);
   z_dphi_staterr__44->GetXaxis()->SetTitleFont(132);
   z_dphi_staterr__44->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   z_dphi_staterr__44->GetYaxis()->SetLabelFont(132);
   z_dphi_staterr__44->GetYaxis()->SetLabelSize(0.05);
   z_dphi_staterr__44->GetYaxis()->SetTitleSize(0.06);
   z_dphi_staterr__44->GetYaxis()->SetTitleFont(132);
   z_dphi_staterr__44->GetZaxis()->SetLabelFont(132);
   z_dphi_staterr__44->GetZaxis()->SetLabelSize(0.05);
   z_dphi_staterr__44->GetZaxis()->SetTitleSize(0.06);
   z_dphi_staterr__44->GetZaxis()->SetTitleFont(132);
   z_dphi_staterr__44->Draw("e2same");
   
   Double_t dphi_toterrs_fx3050[6] = {
   0.3403392,
   0.863938,
   1.387537,
   1.911136,
   2.434734,
   2.958333};
   Double_t dphi_toterrs_fy3050[6] = {
   0.1926519,
   0.2207154,
   0.3546338,
   0.6864677,
   2.01515,
   7.779723};
   Double_t dphi_toterrs_felx3050[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t dphi_toterrs_fely3050[6] = {
   0.03415733,
   0.03577312,
   0.05682396,
   0.09598937,
   0.1897309,
   0.5023379};
   Double_t dphi_toterrs_fehx3050[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t dphi_toterrs_fehy3050[6] = {
   0.04673612,
   0.05211068,
   0.07287587,
   0.1207667,
   0.143423,
   0.3949306};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6,dphi_toterrs_fx3050,dphi_toterrs_fy3050,dphi_toterrs_felx3050,dphi_toterrs_fehx3050,dphi_toterrs_fely3050,dphi_toterrs_fehy3050);
   grae->SetName("dphi_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_dphi_toterrs30433050 = new TH1F("Graph_Graph_dphi_toterrs30433050","",100,0.07853982,3.220132);
   Graph_Graph_dphi_toterrs30433050->SetMinimum(0.001);
   Graph_Graph_dphi_toterrs30433050->SetMaximum(16);
   Graph_Graph_dphi_toterrs30433050->SetDirectory(0);
   Graph_Graph_dphi_toterrs30433050->SetStats(0);
   Graph_Graph_dphi_toterrs30433050->SetLineWidth(2);
   Graph_Graph_dphi_toterrs30433050->SetMarkerStyle(0);
   Graph_Graph_dphi_toterrs30433050->GetXaxis()->SetNdivisions(4);
   Graph_Graph_dphi_toterrs30433050->GetXaxis()->SetLabelFont(132);
   Graph_Graph_dphi_toterrs30433050->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_dphi_toterrs30433050->GetXaxis()->SetLabelSize(0);
   Graph_Graph_dphi_toterrs30433050->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_dphi_toterrs30433050->GetXaxis()->SetTitleFont(132);
   Graph_Graph_dphi_toterrs30433050->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   Graph_Graph_dphi_toterrs30433050->GetYaxis()->SetLabelFont(132);
   Graph_Graph_dphi_toterrs30433050->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_dphi_toterrs30433050->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_dphi_toterrs30433050->GetYaxis()->SetTitleFont(132);
   Graph_Graph_dphi_toterrs30433050->GetZaxis()->SetLabelFont(132);
   Graph_Graph_dphi_toterrs30433050->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_dphi_toterrs30433050->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_dphi_toterrs30433050->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_dphi_toterrs30433050);
   
   grae->Draw("p1p");
   
   Double_t _fx3051[6] = {
   0.3403392,
   0.863938,
   1.387537,
   1.911136,
   2.434734,
   2.958333};
   Double_t _fy3051[6] = {
   0.1926519,
   0.2207154,
   0.3546338,
   0.6864677,
   2.01515,
   7.779723};
   Double_t _felx3051[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3051[6] = {
   0.02873042,
   0.03223617,
   0.04948444,
   0.07740101,
   0.1117696,
   0.3251484};
   Double_t _fehx3051[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3051[6] = {
   0.03948655,
   0.04420709,
   0.06698785,
   0.1028379,
   0.1104173,
   0.2636435};
   grae = new TGraphAsymmErrors(6,_fx3051,_fy3051,_felx3051,_fehx3051,_fely3051,_fehy3051);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_Graph_Graph30443051 = new TH1F("Graph_Graph_Graph30443051","",100,0.07853982,3.220132);
   Graph_Graph_Graph30443051->SetMinimum(0.001);
   Graph_Graph_Graph30443051->SetMaximum(16);
   Graph_Graph_Graph30443051->SetDirectory(0);
   Graph_Graph_Graph30443051->SetStats(0);
   Graph_Graph_Graph30443051->SetLineWidth(2);
   Graph_Graph_Graph30443051->SetMarkerStyle(0);
   Graph_Graph_Graph30443051->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30443051->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30443051->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30443051->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30443051->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30443051->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30443051->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   Graph_Graph_Graph30443051->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30443051->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30443051->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30443051->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30443051->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30443051->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30443051->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30443051->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30443051);
   
   grae->Draw("p1p");
   
   Double_t dphi_toterrs_fx3052[6] = {
   0.1832596,
   0.7068583,
   1.230457,
   1.754056,
   2.277655,
   2.801253};
   Double_t dphi_toterrs_fy3052[6] = {
   0.3071206,
   0.3788296,
   0.5235754,
   0.9026085,
   2.09773,
   8.042891};
   Double_t dphi_toterrs_felx3052[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t dphi_toterrs_fely3052[6] = {
   0.03223837,
   0.05049376,
   0.0513308,
   0.07859791,
   0.1671821,
   0.6048482};
   Double_t dphi_toterrs_fehx3052[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t dphi_toterrs_fehy3052[6] = {
   0.05069997,
   0.04670219,
   0.05741781,
   0.0972528,
   0.2140117,
   0.6377428};
   grae = new TGraphAsymmErrors(6,dphi_toterrs_fx3052,dphi_toterrs_fy3052,dphi_toterrs_felx3052,dphi_toterrs_fehx3052,dphi_toterrs_fely3052,dphi_toterrs_fehy3052);
   grae->SetName("dphi_toterrs");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_dphi_toterrs30453052 = new TH1F("Graph_Graph_dphi_toterrs30453052","",100,0,3.063053);
   Graph_Graph_dphi_toterrs30453052->SetMinimum(0.001);
   Graph_Graph_dphi_toterrs30453052->SetMaximum(16);
   Graph_Graph_dphi_toterrs30453052->SetDirectory(0);
   Graph_Graph_dphi_toterrs30453052->SetStats(0);
   Graph_Graph_dphi_toterrs30453052->SetLineWidth(2);
   Graph_Graph_dphi_toterrs30453052->SetMarkerStyle(0);
   Graph_Graph_dphi_toterrs30453052->GetXaxis()->SetNdivisions(4);
   Graph_Graph_dphi_toterrs30453052->GetXaxis()->SetLabelFont(132);
   Graph_Graph_dphi_toterrs30453052->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_dphi_toterrs30453052->GetXaxis()->SetLabelSize(0);
   Graph_Graph_dphi_toterrs30453052->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_dphi_toterrs30453052->GetXaxis()->SetTitleFont(132);
   Graph_Graph_dphi_toterrs30453052->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   Graph_Graph_dphi_toterrs30453052->GetYaxis()->SetLabelFont(132);
   Graph_Graph_dphi_toterrs30453052->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_dphi_toterrs30453052->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_dphi_toterrs30453052->GetYaxis()->SetTitleFont(132);
   Graph_Graph_dphi_toterrs30453052->GetZaxis()->SetLabelFont(132);
   Graph_Graph_dphi_toterrs30453052->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_dphi_toterrs30453052->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_dphi_toterrs30453052->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_dphi_toterrs30453052);
   
   grae->Draw("p1p");
   
   Double_t _fx3053[6] = {
   0.1832596,
   0.7068583,
   1.230457,
   1.754056,
   2.277655,
   2.801253};
   Double_t _fy3053[6] = {
   0.3071206,
   0.3788296,
   0.5235754,
   0.9026085,
   2.09773,
   8.042891};
   Double_t _felx3053[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fely3053[6] = {
   0.02710968,
   0.03295216,
   0.04124188,
   0.06402796,
   0.1338949,
   0.4694553};
   Double_t _fehx3053[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t _fehy3053[6] = {
   0.03469016,
   0.04020747,
   0.048986,
   0.07362466,
   0.1488417,
   0.5027875};
   grae = new TGraphAsymmErrors(6,_fx3053,_fy3053,_felx3053,_fehx3053,_fely3053,_fehy3053);
   grae->SetName("");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30463053 = new TH1F("Graph_Graph_Graph30463053","",100,0,3.063053);
   Graph_Graph_Graph30463053->SetMinimum(0.001);
   Graph_Graph_Graph30463053->SetMaximum(16);
   Graph_Graph_Graph30463053->SetDirectory(0);
   Graph_Graph_Graph30463053->SetStats(0);
   Graph_Graph_Graph30463053->SetLineWidth(2);
   Graph_Graph_Graph30463053->SetMarkerStyle(0);
   Graph_Graph_Graph30463053->GetXaxis()->SetNdivisions(4);
   Graph_Graph_Graph30463053->GetXaxis()->SetLabelFont(132);
   Graph_Graph_Graph30463053->GetXaxis()->SetLabelOffset(999);
   Graph_Graph_Graph30463053->GetXaxis()->SetLabelSize(0);
   Graph_Graph_Graph30463053->GetXaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30463053->GetXaxis()->SetTitleFont(132);
   Graph_Graph_Graph30463053->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   Graph_Graph_Graph30463053->GetYaxis()->SetLabelFont(132);
   Graph_Graph_Graph30463053->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30463053->GetYaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30463053->GetYaxis()->SetTitleFont(132);
   Graph_Graph_Graph30463053->GetZaxis()->SetLabelFont(132);
   Graph_Graph_Graph30463053->GetZaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph30463053->GetZaxis()->SetTitleSize(0.06);
   Graph_Graph_Graph30463053->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_Graph_Graph30463053);
   
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
   
   TH1F *z_dphi_toterr_copy__45 = new TH1F("z_dphi_toterr_copy__45","z_dphi",6,0,3.141593);
   z_dphi_toterr_copy__45->SetBinContent(1,0.261202);
   z_dphi_toterr_copy__45->SetBinContent(2,0.3162337);
   z_dphi_toterr_copy__45->SetBinContent(3,0.3852335);
   z_dphi_toterr_copy__45->SetBinContent(4,0.7150939);
   z_dphi_toterr_copy__45->SetBinContent(5,1.796506);
   z_dphi_toterr_copy__45->SetBinContent(6,7.258657);
   z_dphi_toterr_copy__45->SetBinContent(7,3.800624);
   z_dphi_toterr_copy__45->SetBinError(1,0.03375302);
   z_dphi_toterr_copy__45->SetBinError(2,0.03634611);
   z_dphi_toterr_copy__45->SetBinError(3,0.0427511);
   z_dphi_toterr_copy__45->SetBinError(4,0.05747346);
   z_dphi_toterr_copy__45->SetBinError(5,0.1278198);
   z_dphi_toterr_copy__45->SetBinError(6,0.3295685);
   z_dphi_toterr_copy__45->SetBinError(7,0.1725617);
   z_dphi_toterr_copy__45->SetMinimum(0.001);
   z_dphi_toterr_copy__45->SetMaximum(16);
   z_dphi_toterr_copy__45->SetEntries(14);
   z_dphi_toterr_copy__45->SetDirectory(0);
   z_dphi_toterr_copy__45->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr_copy__45->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr_copy__45->SetLineColor(ci);
   z_dphi_toterr_copy__45->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   z_dphi_toterr_copy__45->SetMarkerColor(ci);
   z_dphi_toterr_copy__45->SetMarkerStyle(0);
   z_dphi_toterr_copy__45->GetXaxis()->SetNdivisions(4);
   z_dphi_toterr_copy__45->GetXaxis()->SetLabelFont(132);
   z_dphi_toterr_copy__45->GetXaxis()->SetLabelOffset(999);
   z_dphi_toterr_copy__45->GetXaxis()->SetLabelSize(0);
   z_dphi_toterr_copy__45->GetXaxis()->SetTitleSize(0.06);
   z_dphi_toterr_copy__45->GetXaxis()->SetTitleFont(132);
   z_dphi_toterr_copy__45->GetYaxis()->SetTitle("d#sigma(#it{Zj})/d|#Delta#it{#phi} [pb/rad]");
   z_dphi_toterr_copy__45->GetYaxis()->SetLabelFont(132);
   z_dphi_toterr_copy__45->GetYaxis()->SetLabelSize(0.05);
   z_dphi_toterr_copy__45->GetYaxis()->SetTitleSize(0.06);
   z_dphi_toterr_copy__45->GetYaxis()->SetTitleOffset(1.3);
   z_dphi_toterr_copy__45->GetYaxis()->SetTitleFont(132);
   z_dphi_toterr_copy__45->GetZaxis()->SetLabelFont(132);
   z_dphi_toterr_copy__45->GetZaxis()->SetLabelSize(0.05);
   z_dphi_toterr_copy__45->GetZaxis()->SetTitleSize(0.06);
   z_dphi_toterr_copy__45->GetZaxis()->SetTitleFont(132);
   z_dphi_toterr_copy__45->Draw("sameaxis");
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
   
   TH1F *zj_dphi_8TeV_400_1001_0ratiocomp0__46 = new TH1F("zj_dphi_8TeV_400_1001_0ratiocomp0__46","z_dphi",6,0,3.141593);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinContent(1,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinContent(2,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinContent(3,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinContent(4,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinContent(5,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinContent(6,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinContent(7,3.800624);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinError(1,0.1292219);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinError(2,0.1149343);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinError(3,0.1109745);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinError(4,0.08037191);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinError(5,0.07114914);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinError(6,0.04540351);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetBinError(7,0.1725617);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetMinimum(0.41);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetMaximum(1.59);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetEntries(20);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetLineColor(ci);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetMarkerColor(ci);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->SetMarkerStyle(0);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetXaxis()->SetNdivisions(4);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetXaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetXaxis()->SetLabelOffset(0.02);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetXaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetXaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetXaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->SetTitle("Ratio");
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->CenterTitle(true);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->SetNdivisions(505);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->SetTickLength(0.12325);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->SetTitleOffset(1.3);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetYaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetZaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetZaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetZaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->GetZaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0__46->Draw("e2");
   
   TH1F *zj_dphi_8TeV_400_1001_0ratiocomp1__47 = new TH1F("zj_dphi_8TeV_400_1001_0ratiocomp1__47","z_dphi",6,0,3.141593);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinContent(1,1);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinContent(2,1);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinContent(3,1);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinContent(4,1);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinContent(5,1);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinContent(6,1);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinContent(7,3.800624);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinError(1,0.06755777);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinError(2,0.06170157);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinError(3,0.0547299);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinError(4,0.04224946);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinError(5,0.02727271);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinError(6,0.01381488);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetBinError(7,0.05250516);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetMinimum(0.41);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetMaximum(1.59);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetEntries(20);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetStats(0);

   ci = TColor::GetColor("#ff9933");
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetFillColor(ci);

   ci = TColor::GetColor("#ff9933");
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetLineColor(ci);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetLineWidth(2);

   ci = TColor::GetColor("#ff9933");
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetMarkerColor(ci);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->SetMarkerStyle(0);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetXaxis()->SetNdivisions(4);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetXaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetXaxis()->SetLabelOffset(0.02);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetXaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetXaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetXaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetYaxis()->SetTitle("Ratio");
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetYaxis()->CenterTitle(true);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetYaxis()->SetNdivisions(505);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetYaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetYaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetYaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetYaxis()->SetTickLength(0.12325);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetYaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetZaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetZaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetZaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->GetZaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp1__47->Draw("e2same");
   
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp2_fx3054[6] = {
   0.3403392,
   0.863938,
   1.387537,
   1.911136,
   2.434734,
   2.958333};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp2_fy3054[6] = {
   0.7375589,
   0.6979502,
   0.9205685,
   0.9599686,
   1.121705,
   1.071786};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp2_felx3054[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp2_fely3054[6] = {
   0.1307698,
   0.1131224,
   0.1475052,
   0.1342332,
   0.1056111,
   0.06920535};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp2_fehx3054[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp2_fehy3054[6] = {
   0.1789271,
   0.1647854,
   0.1891732,
   0.1688822,
   0.07983441,
   0.05440822};
   grae = new TGraphAsymmErrors(6,zj_dphi_8TeV_400_1001_0ratiocomp2_fx3054,zj_dphi_8TeV_400_1001_0ratiocomp2_fy3054,zj_dphi_8TeV_400_1001_0ratiocomp2_felx3054,zj_dphi_8TeV_400_1001_0ratiocomp2_fehx3054,zj_dphi_8TeV_400_1001_0ratiocomp2_fely3054,zj_dphi_8TeV_400_1001_0ratiocomp2_fehy3054);
   grae->SetName("zj_dphi_8TeV_400_1001_0ratiocomp2");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054 = new TH1F("Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054","",100,0.07853982,3.220132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->SetMinimum(0.41);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->SetMaximum(1.59);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->SetDirectory(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->SetStats(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->SetLineWidth(2);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->SetMarkerStyle(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetXaxis()->SetNdivisions(4);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetXaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetXaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetYaxis()->SetTitle("Ratio");
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetYaxis()->CenterTitle(true);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetYaxis()->SetNdivisions(505);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetYaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetYaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetZaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_dphi_8TeV_400_1001_0ratiocomp23054);
   
   grae->Draw("p1");
   
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp3_fx3055[6] = {
   0.3403392,
   0.863938,
   1.387537,
   1.911136,
   2.434734,
   2.958333};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp3_fy3055[6] = {
   0.7375589,
   0.6979502,
   0.9205685,
   0.9599686,
   1.121705,
   1.071786};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp3_felx3055[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp3_fely3055[6] = {
   0.1099931,
   0.1019378,
   0.1284531,
   0.1082389,
   0.06221498,
   0.04479457};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp3_fehx3055[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp3_fehy3055[6] = {
   0.1511724,
   0.1397925,
   0.1738889,
   0.1438103,
   0.06146226,
   0.03632125};
   grae = new TGraphAsymmErrors(6,zj_dphi_8TeV_400_1001_0ratiocomp3_fx3055,zj_dphi_8TeV_400_1001_0ratiocomp3_fy3055,zj_dphi_8TeV_400_1001_0ratiocomp3_felx3055,zj_dphi_8TeV_400_1001_0ratiocomp3_fehx3055,zj_dphi_8TeV_400_1001_0ratiocomp3_fely3055,zj_dphi_8TeV_400_1001_0ratiocomp3_fehy3055);
   grae->SetName("zj_dphi_8TeV_400_1001_0ratiocomp3");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(24);
   
   TH1F *Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055 = new TH1F("Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055","",100,0.07853982,3.220132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->SetMinimum(0.41);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->SetMaximum(1.59);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->SetDirectory(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->SetStats(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->SetLineWidth(2);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->SetMarkerStyle(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetXaxis()->SetNdivisions(4);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetXaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetXaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetYaxis()->SetTitle("Ratio");
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetYaxis()->CenterTitle(true);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetYaxis()->SetNdivisions(505);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetYaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetYaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetZaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_dphi_8TeV_400_1001_0ratiocomp33055);
   
   grae->Draw("p1");
   
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp4_fx3056[6] = {
   0.1832596,
   0.7068583,
   1.230457,
   1.754056,
   2.277655,
   2.801253};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp4_fy3056[6] = {
   1.175797,
   1.197942,
   1.359112,
   1.262224,
   1.167673,
   1.108041};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp4_felx3056[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp4_fely3056[6] = {
   0.1234231,
   0.1596723,
   0.1332459,
   0.1099127,
   0.09305962,
   0.08332785};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp4_fehx3056[6] = {
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t zj_dphi_8TeV_400_1001_0ratiocomp4_fehy3056[6] = {
   0.1941025,
   0.1476825,
   0.1490468,
   0.136,
   0.1191266,
   0.08785962};
   grae = new TGraphAsymmErrors(6,zj_dphi_8TeV_400_1001_0ratiocomp4_fx3056,zj_dphi_8TeV_400_1001_0ratiocomp4_fy3056,zj_dphi_8TeV_400_1001_0ratiocomp4_felx3056,zj_dphi_8TeV_400_1001_0ratiocomp4_fehx3056,zj_dphi_8TeV_400_1001_0ratiocomp4_fely3056,zj_dphi_8TeV_400_1001_0ratiocomp4_fehy3056);
   grae->SetName("zj_dphi_8TeV_400_1001_0ratiocomp4");
   grae->SetTitle("");
   grae->SetFillColor(1);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056 = new TH1F("Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056","",100,0,3.063053);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->SetMinimum(0.41);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->SetMaximum(1.59);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->SetDirectory(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->SetStats(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->SetLineWidth(2);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->SetMarkerStyle(0);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetXaxis()->SetNdivisions(4);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetXaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetXaxis()->SetLabelOffset(0.02);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetXaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetXaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetXaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetYaxis()->SetTitle("Ratio");
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetYaxis()->CenterTitle(true);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetYaxis()->SetNdivisions(505);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetYaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetYaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetYaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetYaxis()->SetTitleFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetZaxis()->SetLabelFont(132);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetZaxis()->SetLabelSize(0.05);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetZaxis()->SetTitleSize(0.06);
   Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056->GetZaxis()->SetTitleFont(132);
   grae->SetHistogram(Graph_zj_dphi_8TeV_400_1001_0ratiocomp43056);
   
   grae->Draw("p1");
   
   TH1F *zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48 = new TH1F("zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48","z_dphi",6,0,3.141593);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinContent(1,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinContent(2,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinContent(3,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinContent(4,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinContent(5,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinContent(6,1);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinContent(7,3.800624);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinError(1,0.1292219);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinError(2,0.1149343);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinError(3,0.1109745);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinError(4,0.08037191);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinError(5,0.07114914);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinError(6,0.04540351);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetBinError(7,0.1725617);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetMinimum(0.41);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetMaximum(1.59);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetEntries(20);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetDirectory(0);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetStats(0);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetFillColor(ci);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetLineColor(ci);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetLineWidth(2);

   ci = TColor::GetColor("#ffff00");
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetMarkerColor(ci);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->SetMarkerStyle(0);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetXaxis()->SetTitle("|#Delta#it{#phi}| [rad]");
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetXaxis()->SetNdivisions(4);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetXaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetXaxis()->SetLabelOffset(0.02);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetXaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetXaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetXaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->SetTitle("Ratio");
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->CenterTitle(true);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->SetNdivisions(505);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->SetTickLength(0.12325);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->SetTitleOffset(1.3);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetYaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetZaxis()->SetLabelFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetZaxis()->SetLabelSize(0.05);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetZaxis()->SetTitleSize(0.06);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->GetZaxis()->SetTitleFont(132);
   zj_dphi_8TeV_400_1001_0ratiocomp0_copy__48->Draw("sameaxis");
   lowerPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
