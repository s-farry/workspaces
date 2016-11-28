
from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas, TMath

from strange_config import *

f = TFile("/user2/sfarry/workspaces/strange/tuples/jet.dijetl_pt20_50.MD.MC2015.root")
g = TFile("/user2/sfarry/workspaces/strange/tuples/jet.dijetl_pt20_50.MU.MC2015.root")

t = f.Get("MCJet/DecayTree")
u = g.Get("MCJet/DecayTree")

v = f.Get("Jet/DecayTree")
w = g.Get("Jet/DecayTree")

jeteff = EfficiencyClass("jeteff")
jeteff.SetSelectionCut(ptmcj20 + etamcj)
jeteff.SetPassCut(TCut("jet_rectruejet_PT > 12500"))
jeteff.AddTree(t)
jeteff.AddTree(u)
jeteff.AddVars(mcjetvars)
jeteff.Run()
jeteff.SaveToFile()


sjeteff = EfficiencyClass("sjeteff")
sjeteff.SetSelectionCut(ptmcj20 + etamcj + mc_stag)
sjeteff.SetPassCut(TCut("jet_rectruejet_PT > 12500"))
sjeteff.AddTree(t)
sjeteff.AddTree(u)
sjeteff.AddVars(mcjetvars)
sjeteff.Add2DVar('ptj', 'etaj')
sjeteff.Run()
sjeteff.SaveToFile()


qjeteff = EfficiencyClass("qjeteff")
qjeteff.SetSelectionCut(ptmcj20 + etamcj + mc_qtag)
qjeteff.SetPassCut(TCut("jet_rectruejet_PT > 12500"))
qjeteff.AddTree(t)
qjeteff.AddTree(u)
qjeteff.AddVars(mcjetvars)
qjeteff.Add2DVar('ptj', 'etaj')
qjeteff.Run()
qjeteff.SaveToFile()


gjeteff = EfficiencyClass("gjeteff")
gjeteff.SetSelectionCut(ptmcj20 + etamcj + mc_gtag)
gjeteff.SetPassCut(TCut("jet_rectruejet_PT > 12500"))
gjeteff.AddTree(t)
gjeteff.AddTree(u)
gjeteff.AddVars(mcjetvars)
gjeteff.Add2DVar('ptj', 'etaj')
gjeteff.Run()
gjeteff.SaveToFile()

incjeteff = EfficiencyClass("incjeteff")
incjeteff.SetSelectionCut(ptmcj20 + etamcj + mc_inctag)
incjeteff.SetPassCut(TCut("jet_rectruejet_PT > 12500"))
incjeteff.AddTree(t)
incjeteff.AddTree(u)
incjeteff.AddVars(mcjetvars)
incjeteff.Run()
incjeteff.SaveToFile()


weights = TFile("/user2/sfarry/workspaces/strange/tuples/dijet2zj_weights.root")
strange_weights2d = weights.Get("strange_weights2d")
gluon_weights2d   = weights.Get("gluon_weights2d")
quark_weights2d   = weights.Get("quark_weights2d")

sjeteff_2dweight = EfficiencyClass("sjeteff_2dweight")
sjeteff_2dweight.SetSelectionCut(ptmcj20 + etamcj + mc_stag)
sjeteff_2dweight.SetPassCut(TCut("jet_rectruejet_PT > 12500"))
sjeteff_2dweight.AddTree(t)
sjeteff_2dweight.AddTree(u)
sjeteff_2dweight.AddVars(mcjetvars)
sjeteff_2dweight.Add2DVar('ptj', 'etaj')
sjeteff_2dweight.Reweight("jet_truejet_PT/1000.0", "jet_truejet_ETA", strange_weights2d)
sjeteff_2dweight.Run()
sjeteff_2dweight.SaveToFile()


qjeteff_2dweight = EfficiencyClass("qjeteff_2dweight")
qjeteff_2dweight.SetSelectionCut(ptmcj20 + etamcj + mc_qtag)
qjeteff_2dweight.SetPassCut(TCut("jet_rectruejet_PT > 12500"))
qjeteff_2dweight.AddTree(t)
qjeteff_2dweight.AddTree(u)
qjeteff_2dweight.AddVars(mcjetvars)
qjeteff_2dweight.Add2DVar('ptj', 'etaj')
qjeteff_2dweight.Reweight("jet_truejet_PT/1000.0", "jet_truejet_ETA", quark_weights2d)
qjeteff_2dweight.Run()
qjeteff_2dweight.SaveToFile()


gjeteff_2dweight = EfficiencyClass("gjeteff_2dweight")
gjeteff_2dweight.SetSelectionCut(ptmcj20 + etamcj + mc_gtag)
gjeteff_2dweight.SetPassCut(TCut("jet_rectruejet_PT > 12500"))
gjeteff_2dweight.AddTree(t)
gjeteff_2dweight.AddTree(u)
gjeteff_2dweight.AddVars(mcjetvars)
gjeteff_2dweight.Add2DVar('ptj', 'etaj')
gjeteff_2dweight.Reweight("jet_truejet_PT/1000.0", "jet_truejet_ETA", gluon_weights2d)
gjeteff_2dweight.Run()
gjeteff_2dweight.SaveToFile()


kaoncut = TCut("jet_kaonmult > 0")


jetkaoneff = EfficiencyClass("jetkaoneff")
jetkaoneff.SetSelectionCut(ptj20 + etaj)
jetkaoneff.SetPassCut(kaoncut)
jetkaoneff.AddTree(v)
jetkaoneff.AddTree(w)
jetkaoneff.AddVars(jetvars)
jetkaoneff.Run()
jetkaoneff.SaveToFile()


sjetkaoneff = EfficiencyClass("sjetkaoneff")
sjetkaoneff.SetSelectionCut(ptj20 + etaj + truth_stag)
sjetkaoneff.SetPassCut(kaoncut)
sjetkaoneff.AddTree(v)
sjetkaoneff.AddTree(w)
sjetkaoneff.AddVars(jetvars)
sjetkaoneff.Add2DVar('ptj', 'etaj')
sjetkaoneff.Run()
sjetkaoneff.SaveToFile()


qjetkaoneff = EfficiencyClass("qjetkaoneff")
qjetkaoneff.SetSelectionCut(ptj20 + etaj + truth_qtag)
qjetkaoneff.SetPassCut(kaoncut)
qjetkaoneff.AddTree(v)
qjetkaoneff.AddTree(w)
qjetkaoneff.AddVars(jetvars)
qjetkaoneff.Add2DVar('ptj', 'etaj')
qjetkaoneff.Run()
qjetkaoneff.SaveToFile()

gjetkaoneff = EfficiencyClass("gjetkaoneff")
gjetkaoneff.SetSelectionCut(ptj20 + etaj + truth_gtag)
gjetkaoneff.SetPassCut(kaoncut)
gjetkaoneff.AddTree(v)
gjetkaoneff.AddTree(w)
gjetkaoneff.AddVars(jetvars)
gjetkaoneff.Add2DVar('ptj', 'etaj')
gjetkaoneff.Run()
gjetkaoneff.SaveToFile()

incjetkaoneff = EfficiencyClass("incjetkaoneff")
incjetkaoneff.SetSelectionCut(ptj20 + etaj + truth_inctag)
incjetkaoneff.SetPassCut(kaoncut)
incjetkaoneff.AddTree(v)
incjetkaoneff.AddTree(w)
incjetkaoneff.AddVars(jetvars)
incjetkaoneff.Run()
incjetkaoneff.SaveToFile()


from PlotTools import *
from Style import *
SetLHCbStyle()

p = Plot([qjeteff.GetVar('ptj').GetEffGraph(), sjeteff.GetVar('ptj').GetEffGraph(), gjeteff.GetVar('ptj').GetEffGraph()])
p.setProp('labels', ['quark jets', 'strange jets','gluon jets'])
p.setProp('filename', 'eff_ptj.pdf')
p.setProp('xlabel', 'p_{T}^{j} [GeV]')
p.setProp('ylabel', 'Jet Efficiency')
p.setProp('colors', ['green', 'red', 'blue'])
p.setProp('markerstyles', 20)
p.setProp('xlims', [20,80])
p.setProp('ylims', [0.7,1.05])
p.setProp('leglims', [0.2, 0.2, 0.6, 0.4])
p.drawROOT()


m = Plot([qjeteff.GetVar('etaj').GetEffGraph(), sjeteff.GetVar('etaj').GetEffGraph(), gjeteff.GetVar('etaj').GetEffGraph()])
m.setProp('labels', ['quark jets', 'strange jets','gluon jets'])
m.setProp('filename', 'eff_etaj.pdf')
m.setProp('xlabel', '#eta^{j}')
m.setProp('ylabel', 'Jet Efficiency')
m.setProp('colors', ['green', 'red', 'blue'])
m.setProp('markerstyles', 20)
m.setProp('ylims', [0.6, 1.0])
m.setProp('leglims', [0.2, 0.2, 0.6, 0.4])
m.drawROOT()

n = Plot([qjetkaoneff.GetVar('ptj').GetEffGraph(), sjetkaoneff.GetVar('ptj').GetEffGraph(), gjetkaoneff.GetVar('ptj').GetEffGraph()])
n.setProp('labels', ['quark jets', 'strange jets', 'gluon jets'])
n.setProp('filename', 'kaoneff_ptj.pdf')
n.setProp('xlabel', 'p_{T}^{j} [GeV]')
n.setProp('ylabel', 'Kaon Efficiency')
n.setProp('colors', ['green', 'red', 'blue'])
n.setProp('markerstyles', 20)
n.setProp('xlims', [20,80])
n.setProp('ylims', [0.0,0.7])
n.setProp('leglims', [0.2, 0.2, 0.6, 0.4])
n.drawROOT()


o = Plot([qjetkaoneff.GetVar('etaj').GetEffGraph(), sjetkaoneff.GetVar('etaj').GetEffGraph(), gjetkaoneff.GetVar('etaj').GetEffGraph()])
o.setProp('labels', ['quark jets', 'strange jets', 'gluon jets'])
o.setProp('filename', 'kaoneff_etaj.pdf')
o.setProp('xlabel', '#eta^{j}')
o.setProp('ylabel', 'Kaon Efficiency')
o.setProp('colors', ['green', 'red', 'blue'])
o.setProp('markerstyles', 20)
o.setProp('ylims', [0.0, 0.7])
o.setProp('leglims', [0.2, 0.2, 0.6, 0.4])
o.drawROOT()
