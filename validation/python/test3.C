void test3()
{
//=========Macro generated from canvas: default_Canvas/defaultCanvas
//=========  (Fri May  6 10:50:13 2016) by ROOT version6.04/10
   TCanvas *default_Canvas = new TCanvas("default_Canvas", "defaultCanvas",0,0,700,500);
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
  
// ------------>Primitives in pad: upperPad
   TPad *upperPad = new TPad("upperPad", "upperPad",0.005,0.05,0.995,0.995);
   upperPad->Draw();
   upperPad->cd();
   upperPad->Range(1.567901,0.02811051,4.654321,0.1367104);
   upperPad->SetFillColor(0);
   upperPad->SetFillStyle(4000);
   upperPad->SetBorderMode(0);
   upperPad->SetBorderSize(2);
   upperPad->SetTickx(1);
   upperPad->SetTicky(1);
   upperPad->SetLeftMargin(0.14);
   upperPad->SetRightMargin(0.05);
   upperPad->SetTopMargin(0.05);
   upperPad->SetBottomMargin(0.14);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   upperPad->SetFrameLineWidth(2);
   upperPad->SetFrameBorderMode(0);
   
   TH1F *test3_red_0_0_norm__1 = new TH1F("test3_red_0_0_norm__1","ETA",10,2,4.5);
   test3_red_0_0_norm__1->SetBinContent(1,0.1040398);
   test3_red_0_0_norm__1->SetBinContent(2,0.1186439);
   test3_red_0_0_norm__1->SetBinContent(3,0.1256071);
   test3_red_0_0_norm__1->SetBinContent(4,0.1229555);
   test3_red_0_0_norm__1->SetBinContent(5,0.118442);
   test3_red_0_0_norm__1->SetBinContent(6,0.1127067);
   test3_red_0_0_norm__1->SetBinContent(7,0.09951538);
   test3_red_0_0_norm__1->SetBinContent(8,0.08332527);
   test3_red_0_0_norm__1->SetBinContent(9,0.06651872);
   test3_red_0_0_norm__1->SetBinContent(10,0.0482457);
   test3_red_0_0_norm__1->SetBinError(1,0.001708584);
   test3_red_0_0_norm__1->SetBinError(2,0.001736969);
   test3_red_0_0_norm__1->SetBinError(3,0.001484444);
   test3_red_0_0_norm__1->SetBinError(4,0.001426268);
   test3_red_0_0_norm__1->SetBinError(5,0.001336676);
   test3_red_0_0_norm__1->SetBinError(6,0.00122978);
   test3_red_0_0_norm__1->SetBinError(7,0.00125216);
   test3_red_0_0_norm__1->SetBinError(8,0.00113555);
   test3_red_0_0_norm__1->SetBinError(9,0.0009819959);
   test3_red_0_0_norm__1->SetBinError(10,0.0009418311);
   test3_red_0_0_norm__1->SetEntries(58129);
   test3_red_0_0_norm__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   test3_red_0_0_norm__1->SetFillColor(ci);
   test3_red_0_0_norm__1->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   test3_red_0_0_norm__1->SetLineColor(ci);
   test3_red_0_0_norm__1->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   test3_red_0_0_norm__1->SetMarkerColor(ci);
   test3_red_0_0_norm__1->SetMarkerStyle(20);
   test3_red_0_0_norm__1->GetXaxis()->SetTitle("#eta");
   test3_red_0_0_norm__1->GetXaxis()->SetNdivisions(1005);
   test3_red_0_0_norm__1->GetXaxis()->SetLabelFont(132);
   test3_red_0_0_norm__1->GetXaxis()->SetLabelOffset(0.02);
   test3_red_0_0_norm__1->GetXaxis()->SetLabelSize(0.05);
   test3_red_0_0_norm__1->GetXaxis()->SetTitleSize(0.06);
   test3_red_0_0_norm__1->GetXaxis()->SetTitleFont(132);
   test3_red_0_0_norm__1->GetYaxis()->SetNdivisions(505);
   test3_red_0_0_norm__1->GetYaxis()->SetLabelFont(132);
   test3_red_0_0_norm__1->GetYaxis()->SetLabelSize(0.05);
   test3_red_0_0_norm__1->GetYaxis()->SetTitleSize(0.06);
   test3_red_0_0_norm__1->GetYaxis()->SetTitleFont(132);
   test3_red_0_0_norm__1->GetZaxis()->SetLabelFont(132);
   test3_red_0_0_norm__1->GetZaxis()->SetLabelSize(0.05);
   test3_red_0_0_norm__1->GetZaxis()->SetTitleSize(0.06);
   test3_red_0_0_norm__1->GetZaxis()->SetTitleFont(132);
   test3_red_0_0_norm__1->Draw("");
   Double_t xAxis1[11] = {2, 2.25, 2.5, 2.75, 3, 3.25, 3.5, 3.75, 4, 4.25, 4.5}; 
   
   TH1F *test3_green_0_1_norm__2 = new TH1F("test3_green_0_1_norm__2","ETA",10, xAxis1);
   test3_green_0_1_norm__2->SetBinContent(1,0.1214835);
   test3_green_0_1_norm__2->SetBinContent(2,0.1235428);
   test3_green_0_1_norm__2->SetBinContent(3,0.1252758);
   test3_green_0_1_norm__2->SetBinContent(4,0.1207572);
   test3_green_0_1_norm__2->SetBinContent(5,0.1150848);
   test3_green_0_1_norm__2->SetBinContent(6,0.1056844);
   test3_green_0_1_norm__2->SetBinContent(7,0.09450962);
   test3_green_0_1_norm__2->SetBinContent(8,0.07910584);
   test3_green_0_1_norm__2->SetBinContent(9,0.06467657);
   test3_green_0_1_norm__2->SetBinContent(10,0.04987957);
   test3_green_0_1_norm__2->SetEntries(10);
   test3_green_0_1_norm__2->SetStats(0);

   ci = TColor::GetColor("#00ff00");
   test3_green_0_1_norm__2->SetFillColor(ci);
   test3_green_0_1_norm__2->SetFillStyle(0);

   ci = TColor::GetColor("#00ff00");
   test3_green_0_1_norm__2->SetLineColor(ci);
   test3_green_0_1_norm__2->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   test3_green_0_1_norm__2->SetMarkerColor(ci);
   test3_green_0_1_norm__2->SetMarkerStyle(20);
   test3_green_0_1_norm__2->GetXaxis()->SetTitle("#eta");
   test3_green_0_1_norm__2->GetXaxis()->SetNdivisions(1005);
   test3_green_0_1_norm__2->GetXaxis()->SetLabelFont(132);
   test3_green_0_1_norm__2->GetXaxis()->SetLabelOffset(0.02);
   test3_green_0_1_norm__2->GetXaxis()->SetLabelSize(0.05);
   test3_green_0_1_norm__2->GetXaxis()->SetTitleSize(0.06);
   test3_green_0_1_norm__2->GetXaxis()->SetTitleFont(132);
   test3_green_0_1_norm__2->GetYaxis()->SetNdivisions(505);
   test3_green_0_1_norm__2->GetYaxis()->SetLabelFont(132);
   test3_green_0_1_norm__2->GetYaxis()->SetLabelSize(0.05);
   test3_green_0_1_norm__2->GetYaxis()->SetTitleSize(0.06);
   test3_green_0_1_norm__2->GetYaxis()->SetTitleFont(132);
   test3_green_0_1_norm__2->GetZaxis()->SetLabelFont(132);
   test3_green_0_1_norm__2->GetZaxis()->SetLabelSize(0.05);
   test3_green_0_1_norm__2->GetZaxis()->SetTitleSize(0.06);
   test3_green_0_1_norm__2->GetZaxis()->SetTitleFont(132);
   test3_green_0_1_norm__2->Draw("same");
   
   TLegend *leg = new TLegend(0.2,0.7,0.4,0.85,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(132);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(2);
   leg->SetFillColor(10);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("MuonTrackingMC2015RW_Sim09/ETA_tot","T&P","lep");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   entry=leg->AddEntry("MuonUbsTrackingMC2015/ETA_tot","Truth","lep");

   ci = TColor::GetColor("#00ff00");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);

   ci = TColor::GetColor("#00ff00");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(132);
   leg->Draw();
   
   TH1F *test3_red_0_0_norm_copy__3 = new TH1F("test3_red_0_0_norm_copy__3","ETA",10,2,4.5);
   test3_red_0_0_norm_copy__3->SetBinContent(1,0.1040398);
   test3_red_0_0_norm_copy__3->SetBinContent(2,0.1186439);
   test3_red_0_0_norm_copy__3->SetBinContent(3,0.1256071);
   test3_red_0_0_norm_copy__3->SetBinContent(4,0.1229555);
   test3_red_0_0_norm_copy__3->SetBinContent(5,0.118442);
   test3_red_0_0_norm_copy__3->SetBinContent(6,0.1127067);
   test3_red_0_0_norm_copy__3->SetBinContent(7,0.09951538);
   test3_red_0_0_norm_copy__3->SetBinContent(8,0.08332527);
   test3_red_0_0_norm_copy__3->SetBinContent(9,0.06651872);
   test3_red_0_0_norm_copy__3->SetBinContent(10,0.0482457);
   test3_red_0_0_norm_copy__3->SetBinError(1,0.001708584);
   test3_red_0_0_norm_copy__3->SetBinError(2,0.001736969);
   test3_red_0_0_norm_copy__3->SetBinError(3,0.001484444);
   test3_red_0_0_norm_copy__3->SetBinError(4,0.001426268);
   test3_red_0_0_norm_copy__3->SetBinError(5,0.001336676);
   test3_red_0_0_norm_copy__3->SetBinError(6,0.00122978);
   test3_red_0_0_norm_copy__3->SetBinError(7,0.00125216);
   test3_red_0_0_norm_copy__3->SetBinError(8,0.00113555);
   test3_red_0_0_norm_copy__3->SetBinError(9,0.0009819959);
   test3_red_0_0_norm_copy__3->SetBinError(10,0.0009418311);
   test3_red_0_0_norm_copy__3->SetEntries(58129);
   test3_red_0_0_norm_copy__3->SetDirectory(0);
   test3_red_0_0_norm_copy__3->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   test3_red_0_0_norm_copy__3->SetFillColor(ci);
   test3_red_0_0_norm_copy__3->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   test3_red_0_0_norm_copy__3->SetLineColor(ci);
   test3_red_0_0_norm_copy__3->SetLineWidth(2);

   ci = TColor::GetColor("#ff0000");
   test3_red_0_0_norm_copy__3->SetMarkerColor(ci);
   test3_red_0_0_norm_copy__3->SetMarkerStyle(20);
   test3_red_0_0_norm_copy__3->GetXaxis()->SetTitle("#eta");
   test3_red_0_0_norm_copy__3->GetXaxis()->SetNdivisions(1005);
   test3_red_0_0_norm_copy__3->GetXaxis()->SetLabelFont(132);
   test3_red_0_0_norm_copy__3->GetXaxis()->SetLabelOffset(0.02);
   test3_red_0_0_norm_copy__3->GetXaxis()->SetLabelSize(0.05);
   test3_red_0_0_norm_copy__3->GetXaxis()->SetTitleSize(0.06);
   test3_red_0_0_norm_copy__3->GetXaxis()->SetTitleFont(132);
   test3_red_0_0_norm_copy__3->GetYaxis()->SetNdivisions(505);
   test3_red_0_0_norm_copy__3->GetYaxis()->SetLabelFont(132);
   test3_red_0_0_norm_copy__3->GetYaxis()->SetLabelSize(0.05);
   test3_red_0_0_norm_copy__3->GetYaxis()->SetTitleSize(0.06);
   test3_red_0_0_norm_copy__3->GetYaxis()->SetTitleFont(132);
   test3_red_0_0_norm_copy__3->GetZaxis()->SetLabelFont(132);
   test3_red_0_0_norm_copy__3->GetZaxis()->SetLabelSize(0.05);
   test3_red_0_0_norm_copy__3->GetZaxis()->SetTitleSize(0.06);
   test3_red_0_0_norm_copy__3->GetZaxis()->SetTitleFont(132);
   test3_red_0_0_norm_copy__3->Draw("sameaxis");
   upperPad->Modified();
   default_Canvas->cd();
   default_Canvas->Modified();
   default_Canvas->cd();
   default_Canvas->SetSelected(default_Canvas);
}
