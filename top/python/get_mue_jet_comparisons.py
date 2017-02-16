from os import sys
import copy
from Jawa import *
from ROOT import TCut, TTree, TFile, TMath, TH1F, TF1, TH1, TParameter
from Utils import GetWeightHist, GetSpreadGraph, GetPDFGraph, asymm_details, ratio_details, details
from math import sqrt

from Utils import Bunch

def getpdfuncertainty(central, pdfsets):
    sumsq = 0
    for pdf in pdfsets:
        sumsq = sumsq + pow(central - pdf,2)
    return sqrt(sumsq / (len(pdfsets) - 1))


loc = '/user2/sfarry/workspaces/top/tuples'
TH1.AddDirectory(False)

hlt_mu_f   = TFile.Open("/hepstore/sfarry/GridOutput/2717/ttbar.ttbar_gg.HltJet.MU.MC2016.root")
hlt_md_f   = TFile.Open("/hepstore/sfarry/GridOutput/2718/ttbar.ttbar_gg.HltJet.MD.MC2016.root")
turbo_mu_f = TFile.Open("/hepstore/sfarry/GridOutput/2715/ttbar.ttbar_gg.TurboJet.MU.MC2016.root")
turbo_md_f = TFile.Open("/hepstore/sfarry/GridOutput/2716/ttbar.ttbar_gg.TurboJet.MD.MC2016.root")
run1_mu_f  = TFile.Open("/hepstore/sfarry/GridOutput/2709/ttbar.ttbar_gg.RunIJet.MU.MC2016.root")
run1_md_f  = TFile.Open("/hepstore/sfarry/GridOutput/2710/ttbar.ttbar_gg.RunIJet.MD.MC2016.root")

mu_f   = TFile.Open("/hepstore/sfarry/GridOutput/2719/WMuJet.JetReco.ttbar_gg.MU.MC2016.root")
md_f   = TFile.Open("/hepstore/sfarry/GridOutput/2720/WMuJet.JetReco.ttbar_gg.MD.MC2016.root")
mu_t   = mu_f.Get("WTuple/DecayTree")
md_t   = mu_f.Get("WTuple/DecayTree")


fid = TCut("mu_ETA > 2 && mu_ETA < 4.5 && e_ETA > 2 && e_ETA < 4.5 && mu_PT > 20000 && e_PT > 20000")

recjet      = TCut("ttbar_jet_PT > 15000")
truejet     = TCut("ttbar_truejet_PT > 15000")
rec2truejet = TCut("ttbar_mcjet_PT >7500")
rec2fakejet = TCut("ttbar_mcjet_PT <7500")
true2recjet = TCut("ttbar_rectruejet_PT > 7500") 


plots = [
    Bunch(name="ptj"     ,var= "<jet>_PT/1000.0" , bins = 20, lo = 0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="etaj"    ,var= "<jet>_ETA", bins = 20, lo = 2.0, hi = 4.5, xlabel = '#eta^{j}'),
    Bunch(name="ptj5"     ,var= "<jet>_PT/1000.0" , bins = 5, lo = 0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="etaj5"    ,var= "<jet>_ETA", bins = 5, lo = 2.0, hi = 4.5, xlabel='#eta^{j}')]

res_plots = [
    Bunch(name="dptj"     ,var= "(<jet1>_PT - <jet2>_PT)/<jet1>_PT"   , bins = 50, lo = -1, hi = 1),
    Bunch(name="detaj"    ,var= "(<jet1>_ETA - <jet2>_ETA)/<jet1>_ETA", bins = 50, lo = -1, hi = 1)]

true2dvars = [ ['ptj5', 'dptj'], ['etaj5', 'dptj'] ]


run1jet = Template("run1jet")
run1jet.SetSelCut(fid + recjet)
run1jet.AddTree(run1_mu_t.Get("ttbar/DecayTree"))
run1jet.AddTree(run1_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    run1jet.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet.Run()
run1jet.SaveToFile(loc + '/run1jet.root')

hltjet = Template("hltjet")
hltjet.SetSelCut(fid + recjet)
hltjet.AddTree(hlt_mu_f.Get("ttbar/DecayTree"))
hltjet.AddTree(hlt_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    hltjet.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet.Run()

turbojet = Template("turbojet")
turbojet.SetSelCut(fid + recjet)
turbojet.AddTree(turbo_mu_f.Get("ttbar/DecayTree"))
turbojet.AddTree(turbo_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_jet')
    turbojet.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet.Run()

run1jet_fake = Template("run1jet_fake")
run1jet_fake.SetSelCut(fid + recjet + rec2fakejet)
run1jet_fake.AddTree(run1_mu_f.Get("ttbar/DecayTree"))
run1jet_fake.AddTree(run1_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_jet')
    run1jet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_fake.Run()
run1jet_fake.SaveToFile(loc + '/run1jet_fake.root')

hltjet_fake = Template("hltjet_fake")
hltjet_fake.SetSelCut(fid + recjet + rec2fakejet)
hltjet_fake.AddTree(hlt_mu_f.Get("ttbar/DecayTree"))
hltjet_fake.AddTree(hlt_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_jet')
    hltjet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_fake.Run()

turbojet_fake = Template("turbojet_fake")
turbojet_fake.SetSelCut(fid + recjet + rec2fakejet)
turbojet_fake.AddTree(turbo_mu_f.Get("ttbar/DecayTree"))
turbojet_fake.AddTree(turbo_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_jet')
    turbojet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_fake.Run()

run1jet_true = Template("run1jet_true")
run1jet_true.SetSelCut(fid + truejet + rec2truejet)
run1jet_true.AddTree(run1_mu_f.Get("ttbar/DecayTree"))
run1jet_true.AddTree(run1_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    run1jet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'ttbar_truejet').replace('<jet2>', 'ttbar_rectruejet')
    run1jet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_true.Add2DVars(true2dvars)
run1jet_true.Run()
run1jet_true.SaveToFile(loc + '/run1jet_true.root')

hltjet_true = Template("hltjet_true")
hltjet_true.SetSelCut(fid + recjet + rec2truejet)
hltjet_true.AddTree(hlt_mu_f.Get("ttbar/DecayTree"))
hltjet_true.AddTree(hlt_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    hltjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'ttbar_truejet').replace('<jet2>', 'ttbar_jet')
    hltjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_true.Add2DVars(true2dvars)
hltjet_true.Run()

turbojet_true = Template("turbojet_true")
turbojet_true.SetSelCut(fid + recjet + rec2truejet)
turbojet_true.AddTree(turbo_mu_f.Get("ttbar/DecayTree"))
turbojet_true.AddTree(turbo_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    turbojet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'ttbar_truejet').replace('<jet2>', 'ttbar_jet')
    turbojet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_true.Add2DVars(true2dvars)
turbojet_true.Run()

run1jet_eff = EfficiencyClass("run1jet_eff")
run1jet_eff.SetSelectionCut(fid + truejet)
run1jet_eff.SetPassCut(true2recjet)
run1jet_eff.AddTree(run1_mu_f.Get("ttbar/DecayTree"))
run1jet_eff.AddTree(run1_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    run1jet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_eff.Run()
run1jet_eff.SaveToFile(loc + '/run1jet_eff.root')

hltjet_eff = EfficiencyClass("hltjet_eff")
hltjet_eff.SetSelectionCut(fid + truejet)
hltjet_eff.SetPassCut(true2recjet)
hltjet_eff.AddTree(hlt_mu_f.Get("ttbar/DecayTree"))
hltjet_eff.AddTree(hlt_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    hltjet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_eff.Run()

turbojet_eff = EfficiencyClass("turbojet_eff")
turbojet_eff.SetSelectionCut(fid + truejet)
turbojet_eff.SetPassCut(true2recjet)
turbojet_eff.AddTree(turbo_mu_f.Get("ttbar/DecayTree"))
turbojet_eff.AddTree(turbo_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    turbojet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_eff.Run()

run1jet_tageff = EfficiencyClass("run1jet_tageff")
run1jet_tageff.SetSelectionCut(fid + truejet)
run1jet_tageff.SetPassCut(true2recjet)
run1jet_tageff.AddTree(run1_mu_f.Get("ttbar/DecayTree"))
run1jet_tageff.AddTree(run1_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    run1jet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_tageff.Run()
run1jet_tageff.SaveToFile(loc + '/run1jet_tageff.root')

hltjet_tageff = EfficiencyClass("hltjet_tageff")
hltjet_tageff.SetSelectionCut(fid + truejet)
hltjet_tageff.SetPassCut(true2recjet)
hltjet_tageff.AddTree(hlt_mu_f.Get("ttbar/DecayTree"))
hltjet_tageff.AddTree(hlt_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    hltjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_tageff.Run()

turbojet_tageff = EfficiencyClass("turbojet_tageff")
turbojet_tageff.SetSelectionCut(fid + truejet)
turbojet_tageff.SetPassCut(true2recjet)
turbojet_tageff.AddTree(turbo_mu_f.Get("ttbar/DecayTree"))
turbojet_tageff.AddTree(turbo_md_f.Get("ttbar/DecayTree"))
for p in plots:
    var = p.var.replace('<jet>', 'ttbar_truejet')
    turbojet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_tageff.Run()

run1fit = FitAnalysis("res_Run1", "dptj", "Voigtian(x, N, m, s, a)")
run1fit.SetVal('m', 0.1)
run1fit.SetVal('s', 0.2)
run1fit.Init(run1jet_true)
run1fit.FitIt()
run1fit.SaveToFile(loc+"/run1jetres.root")

hltfit = FitAnalysis("res_Hlt", "dptj", "Voigtian(x, N, m, s, a)")
hltfit.SetVal('m', 0.1)
hltfit.SetVal('s', 0.2)
hltfit.Init(hltjet_true)
hltfit.FitIt()
hltfit.SaveToFile(loc+"/hltjetres.root")

turbofit = FitAnalysis("res_RunI", "dptj", "Voigtian(x, N, m, s, a)")
turbofit.SetVal('m', 0.1)
turbofit.SetVal('s', 0.2)
turbofit.Init(run1jet_true)
turbofit.FitIt()
turbofit.SaveToFile(loc+"/turbojetres.root")


from PlotTools import *
from Style import *

SetLHCbStyle()

for p in plots:
    #plot distributions
    d = Plot([run1jet.GetVar(p.name).GetHist(), hltjet.GetVar(p.name).GetHist(), turbojet.GetVar(p.name).GetHist()])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetcomp_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    if hasattr(p, 'lims'): d.setProp('ylims', p.ylims)
    d.drawROOT()

    #plot fake
    run1  = run1jet_fake.GetVar(p.name).GetHist().Clone('run1_'+p.name+'_fake_rate')
    hlt   = hltjet_fake.GetVar(p.name).GetHist().Clone('hlt_'+p.name+'_fake_rate')
    turbo = turbojet_fake.GetVar(p.name).GetHist().Clone('turbo_'+p.name+'_fake_rate')
    run1.Divide(run1jet.GetVar(p.name).GetHist())
    hlt.Divide(hltjet.GetVar(p.name).GetHist())
    turbo.Divide(turbojet.GetVar(p.name).GetHist())

    d = Plot([run1, hlt, turbo])
    d.forceStyle()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Fake Rate')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetfakerate_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    if hasattr(p, 'lims'): d.setProp('ylims', p.ylims)
    d.drawROOT()

    #plot efficiency
    d = Plot([run1jet_eff.GetVar(p.name).GetEffGraph(), hltjet_eff.GetVar(p.name).GetEffGraph(), turbojet_eff.GetVar(p.name).GetEffGraph()])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Rec. Eff.')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jeteff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    if hasattr(p, 'lims'): d.setProp('ylims', p.ylims)
    d.drawROOT()


for p in ('ptj5', 'etaj5'):
    #plot mean and resolution
    d = Plot([run1fit.GetParHist(p,1), hltfit.GetParHist(p,1), turbofit.GetParHist(p,1)])
    d.forceStyle()
    d.setProp('ylabel', 'Mean')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red', 'black', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetmeans_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    #d.setProp('drawOpts', 'e1')
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    if hasattr(p, 'lims'): d.setProp('ylims', p.ylims)
    d.setProp('ylims', [-0.2, 0.2])
    d.drawROOT()
    d = Plot([run1fit.GetParHist(p,2), hltfit.GetParHist(p,2), turbofit.GetParHist(p,2)])
    d.forceStyle()
    d.setProp('ylabel', '#sigma')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetres_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    if hasattr(p, 'lims'): d.setProp('ylims', p.ylims)
    d.setProp('ylims', [0, 0.25])
    d.drawROOT()
