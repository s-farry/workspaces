from PlotTools import *
from Style import *
from ROOT import TFile, TPaveText
SetLHCbStyle()

f = TFile("MuonTrackingMC2015RW.root")
g = TFile("MuonTrackingCorrMC2015RW.root")
h = TFile("MuonUbsTrackingMC2015.root")


tp_tot     = f.Get("TotalEff").GetVal()
tpcorr_tot = g.Get("TotalEff").GetVal()
truth_tot  = h.Get("TotalEff").GetVal()

txt = TPaveText(0.4, 0.2, 0.7, 0.4, "NDC")
txt.AddText("Total Eff (T&P)      = {0:.3f}".format(tp_tot))
txt.AddText("Total Eff (T&P Corr) = {0:.3f}".format(tpcorr_tot))
txt.AddText("Total Eff (Truth)    = {0:.3f}".format(truth_tot))


a = Plot([ff.Get('ETA/EfficiencyGraph') for ff in [f, g, h]])
a.setProp('labels', ['T&P', 'T&P(corr.)', 'Truth'])
a.setProp('colors', ['red', 'blue', 'green'])
a.setProp('filename', 'test')
a.setProp('xlabel', '#eta')
a.setProp('ylabel', 'Tracking Efficiency')
a.setProp('leglims', [0.2, 0.7, 0.4, 0.85])
a.setProp('markerstyles', 20)
a.setProp('extraObjs', [txt])
a.drawROOT()


a.plots = [ff.Get('PT/EfficiencyGraph') for ff in [f, g, h]]
a.setProp('filename', 'test2')
a.setProp('xlabel', 'p_{T} [GeV]')
a.setProp('ylims', [0.8,1])
a.drawROOT()


a = Plot([ff.Get('ETA/TotalHist') for ff in [f, h]])
a.setProp('labels', ['T&P', 'Truth'])
a.setProp('colors', ['red', 'green'])
a.setProp('filename', 'test3')
a.setProp('xlabel', '#eta')
a.setProp('ylabel', '[A.U.]')
a.setProp('leglims', [0.2, 0.7, 0.4, 0.85])
a.setProp('markerstyles', 20)
a.setProp('normalised', True)
a.setProp('fillstyles', 0)
a.drawROOT()
