
from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas, TMath

from strange_config import *
#
#jetsveff = EfficiencyClass("jetsveff")
#jetsveff.SetSelectionCut(ptj20 + etaj)
#jetsveff.SetPassCut(svtag)
#jetsveff.AddTrees(jet_pt20_50.trees())
#jetsveff.AddTrees(jet_pt50.trees())
#jetsveff.AddVars(jetvars)
#jetsveff.Run()
#jetsveff.SaveToFile()


sjetsveff = EfficiencyClass("sjetsveff")
sjetsveff.SetSelectionCut(ptj20 + etaj + truth_stag)
sjetsveff.SetPassCut(svtag)
sjetsveff.AddTrees(jet_pt20_50.trees())
sjetsveff.AddTrees(jet_pt50.trees())
sjetsveff.AddVars(jetvars)
sjetsveff.Add2DVar('ptj', 'etaj')
sjetsveff.Run()
sjetsveff.SaveToFile()


qjetsveff = EfficiencyClass("qjetsveff")
qjetsveff.SetSelectionCut(ptj20 + etaj + truth_qtag)
qjetsveff.SetPassCut(svtag)
qjetsveff.AddTrees(jet_pt20_50.trees())
qjetsveff.AddTrees(jet_pt50.trees())
qjetsveff.AddVars(jetvars)
qjetsveff.Add2DVar('ptj', 'etaj')
qjetsveff.Run()
qjetsveff.SaveToFile()

gjetsveff = EfficiencyClass("gjetsveff")
gjetsveff.SetSelectionCut(ptj20 + etaj + truth_gtag)
gjetsveff.SetPassCut(svtag)
gjetsveff.AddTrees(jet_pt20_50.trees())
gjetsveff.AddTrees(jet_pt50.trees())
gjetsveff.AddVars(jetvars)
gjetsveff.Add2DVar('ptj', 'etaj')
gjetsveff.Run()
gjetsveff.SaveToFile()

bjetsveff = EfficiencyClass("bjetsveff")
bjetsveff.SetSelectionCut(ptj20 + etaj + truth_btag)
bjetsveff.SetPassCut(svtag)
bjetsveff.AddTrees(bjet_pt20_50.trees())
bjetsveff.AddTrees(bjet_pt50.trees())
bjetsveff.AddVars(jetvars)
bjetsveff.Run()
bjetsveff.SaveToFile()

cjetsveff = EfficiencyClass("cjetsveff")
cjetsveff.SetSelectionCut(ptj20 + etaj + truth_ctag)
cjetsveff.SetPassCut(svtag)
cjetsveff.AddTrees(cjet_pt20_50.trees())
cjetsveff.AddTrees(cjet_pt50.trees())
cjetsveff.AddVars(jetvars)
cjetsveff.Run()
cjetsveff.SaveToFile()


from PlotTools import *
from Style import *
SetLHCbStyle()

n = Plot([qjetsveff.GetVar('ptj').GetEffGraph(), sjetsveff.GetVar('ptj').GetEffGraph(), gjetsveff.GetVar('ptj').GetEffGraph(), bjetsveff.GetVar('ptj').GetEffGraph(), cjetsveff.GetVar('ptj').GetEffGraph()])
n.setProp('labels', ['quark jets', 'strange jets', 'gluon jets', 'beauty jets', 'charm jets'])
n.setProp('filename', 'sveff_ptj.pdf')
n.setProp('xlabel', 'p_{T}^{j} [GeV]')
n.setProp('ylabel', 'SV Tagging Efficiency')
n.setProp('colors', ['green', 'red', 'blue', 'black', 'orange'])
n.setProp('markerstyles', 20)
n.setProp('xlims', [20,80])
n.setProp('ylims', [0.0,0.7])
n.setProp('leglims', [0.2, 0.15, 0.6, 0.4])
n.ShiftLegX(0.3)
n.ShiftLegY(0.35)
n.drawROOT()


o = Plot([qjetsveff.GetVar('etaj').GetEffGraph(), sjetsveff.GetVar('etaj').GetEffGraph(), gjetsveff.GetVar('etaj').GetEffGraph(), bjetsveff.GetVar('etaj').GetEffGraph(), cjetsveff.GetVar('etaj').GetEffGraph()])
o.setProp('labels', ['quark jets', 'strange jets', 'gluon jets', 'beauty jets', 'charm jets'])
o.setProp('filename', 'sveff_etaj.pdf')
o.setProp('xlabel', '#eta^{j}')
o.setProp('ylabel', 'SV Tagging Efficiency')
o.setProp('colors', ['green', 'red', 'blue', 'black', 'orange'])
o.setProp('markerstyles', 20)
o.setProp('ylims', [0.0, 0.7])
o.setProp('leglims', [0.2, 0.15, 0.6, 0.4])
o.ShiftLegX(0.3)
o.ShiftLegY(0.4)
o.drawROOT()
