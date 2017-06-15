from ROOT import TFile, TTree, TCut
from Jawa import *
from PlotTools import *
from Utils import Bunch

f = TFile("/hepstore/sfarry/GridOutput/3129/BjpsiK.BJpsiK.MU.MC2016.root")
g = TFile("/hepstore/sfarry/GridOutput/3130/BjpsiK.BJpsiK.MD.MC2016.root")
t = f.Get("BJpsiKDT/DecayTree")
u = g.Get("BJpsiKDT/DecayTree")
v = f.Get("BJpsiKDT_tp/DecayTree")
w = g.Get("BJpsiKDT_tp/DecayTree")
x = f.Get("BJpsiK/TrueTree")
y = g.Get("BJpsiK/TrueTree")

true_lp_pt = TCut("lp_PT > 500")
true_rec_lp = TCut("lp_rec_PT > 0")
true_stub_lp = TCut("lp_stub_PT > 0 && lp_stub_Charge == 1")
match_stub_lp = TCut("lp_stub_deltaR < 0.02 && lp_stub_Long2CalodRt < 500 && lp_stub_nCommonVeloHits/lp_stub_nVeloHits > 0.7")

true_lm_pt = TCut("lm_PT > 500")
true_rec_lm = TCut("lm_rec_PT > 0")
true_stub_lm = TCut("lm_stub_PT > 0 && lm_stub_Charge == -1")
match_stub_lm = TCut("lm_stub_deltaR < 0.02 && lm_stub_Long2CalodRt < 500 && lm_stub_nCommonVeloHits/lm_stub_nVeloHits > 0.7")

passcut = TCut("probe_deltaR < 0.02 && probe_deltaRt < 500 && probe_VeloMatch > 0.7")
failcut = TCut("probe_deltaR > 0.02 || probe_deltaRt > 500 || probe_VeloMatch < 0.7")

true_bunches = [
    Bunch(name='pt' , var='<l>_PT', bins = 100, lo = 0, hi = 10000),
    Bunch(name='eta' , var='<l>_ETA', bins = 100, lo = 2.0, hi = 5.0),
    Bunch(name='dR' , var='<l>_stub_deltaR', bins = 100, lo = 0, hi = 0.02),
    Bunch(name='dRt' , var='<l>_stub_Long2CalodRt', bins = 100, lo = 0, hi = 1000),
    Bunch(name='RE'  , var='(<l>_stub_CaloE/cosh(lp_stub_ETA))/<l>_stub_PT', bins = 100, lo = 0, hi = 1.5),
    Bunch(name='nCommonVelo' , var='<l>_stub_nCommonVeloHits/<l>_stub_nVeloHits', bins = 50, lo = 0, hi = 1),
    ]

loc = '/user2/sfarry/workspaces/rkst/tuples'
trueprobe = TCut("abs(probe_TRUEID) == 11")
truetags  = TCut("abs(tag_TRUEID) == 11 && abs(K_TRUEID) == 321")

ptag = TCut("lp_rec_PT > 500 && K_rec_PT > 500 && lm_stub_PT > 500")
mtag = TCut("lm_rec_PT > 500 && K_rec_PT > 500 && lp_stub_PT > 500")

true_lp_eff = EfficiencyClass("true_lp_eff")
true_lp_eff.SetSelectionCut(true_lp_pt)
true_lp_eff.SetPassCut(true_rec_lp)
true_lp_eff.AddTree(x)
true_lp_eff.AddTree(y)
for p in true_bunches:
    true_lp_eff.AddVar(p.name, p.var.replace('<l>', 'lp'), p.bins, p.lo, p.hi)
true_lp_eff.Run()

true_lm_eff = EfficiencyClass("true_lm_eff")
true_lm_eff.SetSelectionCut(true_lm_pt)
true_lm_eff.SetPassCut(true_rec_lm)
true_lm_eff.AddTree(x)
true_lm_eff.AddTree(y)
for p in true_bunches:
    true_lm_eff.AddVar(p.name, p.var.replace('<l>', 'lm'), p.bins, p.lo, p.hi)
true_lm_eff.Run()

stub_lp_eff = EfficiencyClass("stub_lp_eff")
stub_lp_eff.SetSelectionCut(true_lp_pt)
stub_lp_eff.SetPassCut(true_stub_lp)
stub_lp_eff.AddTree(x)
stub_lp_eff.AddTree(y)
for p in true_bunches:
    stub_lp_eff.AddVar(p.name, p.var.replace('<l>', 'lp'), p.bins, p.lo, p.hi)
stub_lp_eff.Run()

stub_lm_eff = EfficiencyClass("stub_lm_eff")
stub_lm_eff.SetSelectionCut(true_lm_pt)
stub_lm_eff.SetPassCut(true_stub_lm)
stub_lm_eff.AddTree(x)
stub_lm_eff.AddTree(y)
for p in true_bunches:
    stub_lm_eff.AddVar(p.name, p.var.replace('<l>', 'lm'), p.bins, p.lo, p.hi)
stub_lm_eff.Run()

stubmatch_lp_eff = EfficiencyClass("stubmatch_lp_eff")
stubmatch_lp_eff.SetSelectionCut(true_lp_pt + true_stub_lp + true_rec_lp)
stubmatch_lp_eff.SetPassCut(match_stub_lp)
stubmatch_lp_eff.AddTree(x)
stubmatch_lp_eff.AddTree(y)
for p in true_bunches:
    stubmatch_lp_eff.AddVar(p.name, p.var.replace('<l>', 'lp'), p.bins, p.lo, p.hi)
stubmatch_lp_eff.Run()

stubmatch_lm_eff = EfficiencyClass("stubmatch_lm_eff")
stubmatch_lm_eff.SetSelectionCut(true_lm_pt + true_stub_lm + true_rec_lm )
stubmatch_lm_eff.SetPassCut(match_stub_lm)
stubmatch_lm_eff.AddTree(x)
stubmatch_lm_eff.AddTree(y)
for p in true_bunches:
    stubmatch_lm_eff.AddVar(p.name, p.var.replace('<l>', 'lm'), p.bins, p.lo, p.hi)
stubmatch_lm_eff.Run()

bias_lm_eff = EfficiencyClass("bias_lm_eff")
bias_lm_eff.SetSelectionCut(true_lm_pt + ptag)
bias_lm_eff.SetPassCut(true_rec_lm)
bias_lm_eff.AddTree(x)
bias_lm_eff.AddTree(y)
for p in true_bunches:
    bias_lm_eff.AddVar(p.name, p.var.replace('<l>', 'lm'), p.bins, p.lo, p.hi)
bias_lm_eff.Run()

bias_lp_eff = EfficiencyClass("bias_lp_eff")
bias_lp_eff.SetSelectionCut(true_lp_pt + mtag)
bias_lp_eff.SetPassCut(true_rec_lp)
bias_lp_eff.AddTree(x)
bias_lp_eff.AddTree(y)
for p in true_bunches:
    bias_lp_eff.AddVar(p.name, p.var.replace('<l>', 'lp'), p.bins, p.lo, p.hi)
bias_lp_eff.Run()

true = EfficiencyClass("true_eff", true_lp_eff, true_lm_eff)
true.MakeEfficiencyGraph()
true.SaveToFile(loc + '/true_eff.root')

stub = EfficiencyClass("stub_eff", stub_lp_eff, stub_lm_eff)
stub.MakeEfficiencyGraph()
stub.SaveToFile(loc + '/stub_eff.root')

match = EfficiencyClass("match_eff", stubmatch_lp_eff, stubmatch_lm_eff)
match.MakeEfficiencyGraph()
match.SaveToFile(loc + '/match_eff.root')

bias = EfficiencyClass("bias_eff", bias_lp_eff, bias_lm_eff)
bias.MakeEfficiencyGraph()
bias.SaveToFile(loc + '/bias_eff.root')

from PlotTools import *
from Style import *
SetLHCbStyle()
d = Plot([true.GetVar('pt').GetEffGraph(), bias.GetVar('pt').GetEffGraph()])
d.forceStyle()
d.AutoYlims()
d.setProp('ylabel', 'Efficiency')
d.setProp('labels', ['True', 'Biased'])
d.setProp('colors', ['black', 'red'])
d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
d.setProp('filename', 'eff_pt_mc2016.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
d.setProp('xlabel', 'p_{T} [MeV]')
d.ShiftLegY(-0.4)
d.drawROOT()

d = Plot([true.GetVar('eta').GetEffGraph(), bias.GetVar('eta').GetEffGraph()])
d.forceStyle()
d.AutoYlims()
d.setProp('ylabel', 'Efficiency')
d.setProp('labels', ['True', 'Biased'])
d.setProp('colors', ['black', 'red'])
d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
d.setProp('filename', 'eff_eta_mc2016.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
d.setProp('xlabel', 'p_{T} [MeV]')
d.ShiftLegY(-0.4)
d.drawROOT()


tagprobe_results = TFile("/user2/sfarry/workspaces/rkst/tuples/output.root.root")
eff_pt  = tagprobe_results.Get("eff_v_pt")
eff_eta = tagprobe_results.Get("eff_v_eta")



d = Plot([bias.GetVar('pt').GetEffGraph(), eff_pt])
d.forceStyle()
d.AutoYlims()
d.setProp('ylabel', 'Efficiency')
d.setProp('labels', ['Truth (Biased)', 'Tag-and-probe'])
d.setProp('colors', ['red', 'black'])
d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
d.setProp('filename', 'eff_tp_pt_mc2016.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
d.setProp('xlabel', 'p_{T} [MeV]')
d.drawROOT()

d = Plot([bias.GetVar('eta').GetEffGraph(), eff_eta])
d.forceStyle()
d.AutoYlims()
d.setProp('ylabel', 'Efficiency')
d.setProp('labels', ['Truth (Biased)', 'Tag-and-probe'])
d.setProp('colors', ['red', 'black'])
d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
d.setProp('filename', 'eff_tp_eta_mc2016.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
d.setProp('xlabel', 'p_{T} [MeV]')
d.ShiftLegY(-0.4)
d.drawROOT()
