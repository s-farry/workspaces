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

mu_f   = TFile.Open("/hepstore/sfarry/GridOutput/2759/WMuJet.JetReco.ttbar_gg.MU.MC2016.root")
md_f   = TFile.Open("/hepstore/sfarry/GridOutput/2760/WMuJet.JetReco.ttbar_gg.MD.MC2016.root")
mu_t   = mu_f.Get("WTuple/DecayTree")
md_t   = md_f.Get("WTuple/DecayTree")


fid = TCut("muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_PT > 20000")

recjet      = TCut("muminus_jet_PT > 15000")
truejet     = TCut("muminus_truejet_PT > 15000")
rec2truejet = TCut("muminus_mcjet_PT >7500")
rec2fakejet = TCut("muminus_mcjet_PT <7500")
true2recjet = TCut("muminus_rectruejet_PT > 7500") 

recRunIjet      = TCut("muminus_RunIjet_PT > 15000")
trueRunIjet     = TCut("muminus_trueRunIjet_PT > 15000")
rec2trueRunIjet = TCut("muminus_mcRunIjet_PT >7500")
rec2fakeRunIjet = TCut("muminus_mcRunIjet_PT <7500")
true2recRunIjet = TCut("muminus_rectrueRunIjet_PT > 7500") 

recHltjet      = TCut("muminus_Hltjet_PT > 15000")
trueHltjet     = TCut("muminus_trueHltjet_PT > 15000")
rec2trueHltjet = TCut("muminus_mcHltjet_PT >7500")
rec2fakeHltjet = TCut("muminus_mcHltjet_PT <7500")
true2recHltjet = TCut("muminus_rectrueHltjet_PT > 7500") 

recHltGPjet      = TCut("muminus_HltGPjet_PT > 15000")
trueHltGPjet     = TCut("muminus_trueHltGPjet_PT > 15000")
rec2trueHltGPjet = TCut("muminus_mcHltGPjet_PT >7500")
rec2fakeHltGPjet = TCut("muminus_mcHltGPjet_PT <7500")
true2recHltGPjet = TCut("muminus_rectrueHltGPjet_PT > 7500") 

recTurbojet      = TCut("muminus_Turbojet_PT > 15000")
trueTurbojet     = TCut("muminus_trueTurbojet_PT > 15000")
rec2trueTurbojet = TCut("muminus_mcTurbojet_PT >7500")
rec2fakeTurbojet = TCut("muminus_mcTurbojet_PT <7500")
true2recTurbojet = TCut("muminus_rectrueTurbojet_PT > 7500") 

RunIjettag   = TCut("muminus_RunIjet_BDTTag == 1")
Hltjettag    = TCut("muminus_Hltjet_BDTTag == 1")
HltGPjettag    = TCut("muminus_HltGPjet_BDTTag == 1")
Turbojettag  = TCut("muminus_Turbojet_BDTTag == 1")

Run1jet_trueb  = TCut("abs(muminus_mcRunIjet_flavour) == 5"  )
Hltjet_trueb   = TCut("abs(muminus_mcHltjet_flavour) == 5"   )
HltGPjet_trueb   = TCut("abs(muminus_mcHltGPjet_flavour) == 5"   )
Turbojet_trueb = TCut("abs(muminus_mcTurbojet_flavour) == 5")

plots = [
    Bunch(name="ptj"     ,var= "<jet>_PT/1000.0" , bins = 50, lo = 15.0, hi = 150.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="etaj"    ,var= "<jet>_ETA", bins = 20, lo = 2.0, hi = 4.5, xlabel = '#eta^{j}'),
    Bunch(name="ptj10"   ,var= "<jet>_PT/1000.0" , bins = 10, lo = 15.0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="etaj10"  ,var= "<jet>_ETA", bins = 10, lo = 2.0, hi = 4.5, xlabel='#eta^{j}'),
    Bunch(name="cpf"     ,var= "<jet>_cpf" , bins = 100, lo = 0, hi = 1.0, xlabel = 'cpf', shiftlegx = -0.4),
    Bunch(name="mult"    ,var= "<jet>_ndauts" , bins = 46, lo = -0.5, hi = 45.5, xlabel = 'jet multiplicity', shiftlegx = -0.4),
    Bunch(name="mpt"     ,var= "<jet>_mpt" , bins = 100, lo = 0, hi = 40000.0, xlabel = 'mpt'),
    Bunch(name="mtf"     ,var= "<jet>_mtf" , bins = 100, lo = 0, hi = 1.0, xlabel = 'mtf'),
    Bunch(name="npoint"  ,var= "<jet>_npoint" , bins = 46, lo = -0.5, hi = 45.5, xlabel = 'npoint'),
    Bunch(name="width"   ,var= "<jet>_width" , bins = 50, lo = 0, hi = 1.0, xlabel = 'jet width'),
    Bunch(name="n90"     ,var= "<jet>_n90" , bins = 16, lo = -0.5, hi = 15.5, xlabel = 'n90')]
tag_plots = [
    Bunch(name="bdt0"    ,var= "<jet>_Tag0_bdt0" , bins = 50, lo = 0, hi = 1.0, xlabel = 'bdt0'),
    Bunch(name="bdt1"    ,var= "<jet>_Tag0_bdt1" , bins = 50, lo = 0, hi = 1.0, xlabel = 'bdt1'),
    ]
true_plots = [
    Bunch(name="true_ptj"     ,var= "<jet>_PT/1000.0" , bins = 18, lo = 0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="true_etaj"    ,var= "<jet>_ETA", bins = 20, lo = 2.0, hi = 4.5, xlabel = '#eta^{j}'),
    Bunch(name="true_ptj10"   ,var= "<jet>_PT/1000.0" , bins = 9, lo = 10.0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="true_etaj10"  ,var= "<jet>_ETA", bins = 10, lo = 2.0, hi = 4.5, xlabel = '#eta^{j}'),
    Bunch(name="true_cpf"     ,var= "<jet>_cpf" , bins = 100, lo = 0.0, hi = 1.0, xlabel = 'cpf'),
    Bunch(name="true_mult"    ,var= "<jet>_ndauts", bins = 46, lo = -0.5, hi = 45.5, xlabel = 'multiplicity'),
    Bunch(name="true_width"   ,var= "<jet>_width", bins = 50, lo = 0, hi = 1.0, xlabel = 'width')
    ]

res_plots = [
    Bunch(name="dptj"   , var= "(<jet1>_PT - <jet2>_PT)/<jet1>_PT"   , bins = 50, lo = -1, hi = 1),
    Bunch(name="detaj"  , var= "(<jet1>_ETA - <jet2>_ETA)/<jet1>_ETA", bins = 50, lo = -1, hi = 1)]

true2dvars = [ ['true_ptj10', 'dptj'], ['true_etaj10', 'dptj'] ]

run1jet = Template("run1jet")
run1jet.SetSelCut(fid + recRunIjet)
run1jet.AddTree(mu_t)
run1jet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_RunIjet')
    run1jet.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet.Run()
run1jet.SaveToFile(loc + '/run1jet.root')

hltjet = Template("hltjet")
hltjet.SetSelCut(fid + recHltjet)
hltjet.AddTree(mu_t)
hltjet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_Hltjet')
    hltjet.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet.Run()
hltjet.SaveToFile(loc + '/hltjet.root')

hltgpjet = Template("hltgpjet")
hltgpjet.SetSelCut(fid + recHltGPjet)
hltgpjet.AddTree(mu_t)
hltgpjet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_HltGPjet')
    hltgpjet.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet.Run()
hltgpjet.SaveToFile(loc + '/hltgpjet.root')

turbojet = Template("turbojet")
turbojet.SetSelCut(fid + recTurbojet)
turbojet.AddTree(mu_t)
turbojet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_Turbojet')
    turbojet.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet.Run()
turbojet.SaveToFile(loc + '/turbojet.root')

run1jet_fake = Template("run1jet_fake")
run1jet_fake.SetSelCut(fid + recRunIjet + rec2fakeRunIjet)
run1jet_fake.AddTree(mu_t)
run1jet_fake.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_RunIjet')
    run1jet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_fake.Run()
run1jet_fake.SaveToFile(loc + '/run1jet_fake.root')

hltjet_fake = Template("hltjet_fake")
hltjet_fake.SetSelCut(fid + recHltjet + rec2fakeHltjet)
hltjet_fake.AddTree(mu_t)
hltjet_fake.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_Hltjet')
    hltjet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_fake.Run()

hltgpjet_fake = Template("hltjetgp_fake")
hltgpjet_fake.SetSelCut(fid + recHltjet + rec2fakeHltjet)
hltgpjet_fake.AddTree(mu_t)
hltgpjet_fake.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_HltGPjet')
    hltgpjet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_fake.Run()

turbojet_fake = Template("turbojet_fake")
turbojet_fake.SetSelCut(fid + recTurbojet + rec2fakeTurbojet)
turbojet_fake.AddTree(mu_t)
turbojet_fake.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_Turbojet')
    turbojet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_fake.Run()

run1jet_true = Template("run1jet_true")
run1jet_true.SetSelCut(fid + trueRunIjet + rec2trueRunIjet)
run1jet_true.AddTree(mu_t)
run1jet_true.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_RunIjet')
    run1jet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in true_plots:
    var = p.var.replace('<jet>', 'muminus_trueRunIjet')
    run1jet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'muminus_trueRunIjet').replace('<jet2>', 'muminus_rectrueRunIjet')
    run1jet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_true.Add2DVars(true2dvars)
run1jet_true.Run()
run1jet_true.SaveToFile(loc + '/run1jet_true.root')

hltjet_true = Template("hltjet_true")
hltjet_true.SetSelCut(fid + recHltjet + rec2trueHltjet)
hltjet_true.AddTree(mu_t)
hltjet_true.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_Hltjet')
    hltjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in true_plots:
    var = p.var.replace('<jet>', 'muminus_trueHltjet')
    hltjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'muminus_trueHltjet').replace('<jet2>', 'muminus_rectrueHltjet')
    hltjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_true.Add2DVars(true2dvars)
hltjet_true.Run()

hltgpjet_true = Template("hltgpjet_true")
hltgpjet_true.SetSelCut(fid + recHltGPjet + rec2trueHltGPjet)
hltgpjet_true.AddTree(mu_t)
hltgpjet_true.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_HltGPjet')
    hltgpjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in true_plots:
    var = p.var.replace('<jet>', 'muminus_trueHltGPjet')
    hltgpjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'muminus_trueHltGPjet').replace('<jet2>', 'muminus_rectrueHltGPjet')
    hltgpjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_true.Add2DVars(true2dvars)
hltgpjet_true.Run()

turbojet_true = Template("turbojet_true")
turbojet_true.SetSelCut(fid + recTurbojet + rec2trueTurbojet)
turbojet_true.AddTree(mu_t)
turbojet_true.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_Turbojet')
    turbojet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in true_plots:
    var = p.var.replace('<jet>', 'muminus_trueTurbojet')
    turbojet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'muminus_trueTurbojet').replace('<jet2>', 'muminus_rectrueTurbojet')
    turbojet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_true.Add2DVars(true2dvars)
turbojet_true.Run()

run1jet_eff = EfficiencyClass("run1jet_eff")
run1jet_eff.SetSelectionCut(fid + trueRunIjet)
run1jet_eff.SetPassCut(true2recRunIjet)
run1jet_eff.AddTree(mu_t)
run1jet_eff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_trueRunIjet')
    run1jet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_eff.Run()
run1jet_eff.SaveToFile(loc + '/run1jet_eff.root')

hltjet_eff = EfficiencyClass("hltjet_eff")
hltjet_eff.SetSelectionCut(fid + trueHltjet)
hltjet_eff.SetPassCut(true2recHltjet)
hltjet_eff.AddTree(mu_t)
hltjet_eff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_trueHltjet')
    hltjet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_eff.Run()
hltjet_eff.SaveToFile(loc + '/hltjet_eff.root')

hltgpjet_eff = EfficiencyClass("hltgpjet_eff")
hltgpjet_eff.SetSelectionCut(fid + trueHltGPjet)
hltgpjet_eff.SetPassCut(true2recHltGPjet)
hltgpjet_eff.AddTree(mu_t)
hltgpjet_eff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_trueHltGPjet')
    hltgpjet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_eff.Run()
hltgpjet_eff.SaveToFile(loc + '/hltgpjet_eff.root')

turbojet_eff = EfficiencyClass("turbojet_eff")
turbojet_eff.SetSelectionCut(fid + trueTurbojet)
turbojet_eff.SetPassCut(true2recTurbojet)
turbojet_eff.AddTree(mu_t)
turbojet_eff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_trueTurbojet')
    turbojet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_eff.Run()
turbojet_eff.SaveToFile(loc + '/turbojet_eff.root')

run1jet_tageff = EfficiencyClass("run1jet_tageff")
run1jet_tageff.SetSelectionCut(fid + recRunIjet + rec2trueRunIjet + Run1jet_trueb)
run1jet_tageff.SetPassCut(RunIjettag)
run1jet_tageff.AddTree(mu_t)
run1jet_tageff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_RunIjet')
    run1jet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in tag_plots:
    var = p.var.replace('<jet>', 'muminus_RunIjet')
    run1jet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_tageff.Run()
run1jet_tageff.SaveToFile(loc + '/run1jet_tageff.root')

hltjet_tageff = EfficiencyClass("hltjet_tageff")
hltjet_tageff.SetSelectionCut(fid + recHltjet + rec2trueHltjet + Hltjet_trueb )
hltjet_tageff.SetPassCut(Hltjettag)
hltjet_tageff.AddTree(mu_t)
hltjet_tageff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_Hltjet')
    hltjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in tag_plots:
    var = p.var.replace('<jet>', 'muminus_Hltjet')
    hltjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_tageff.Run()
hltjet_tageff.SaveToFile(loc + '/hltjet_tageff.root')

hltgpjet_tageff = EfficiencyClass("hltgpjet_tageff")
hltgpjet_tageff.SetSelectionCut(fid + recHltGPjet + rec2trueHltGPjet + HltGPjet_trueb )
hltgpjet_tageff.SetPassCut(HltGPjettag)
hltgpjet_tageff.AddTree(mu_t)
hltgpjet_tageff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_HltGPjet')
    hltgpjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in tag_plots:
    var = p.var.replace('<jet>', 'muminus_HltGPjet')
    hltgpjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_tageff.Run()
hltgpjet_tageff.SaveToFile(loc + '/hltgpjet_tageff.root')

turbojet_tageff = EfficiencyClass("turbojet_tageff")
turbojet_tageff.SetSelectionCut(fid + recTurbojet + rec2trueTurbojet + Turbojet_trueb)
turbojet_tageff.SetPassCut(Turbojettag)
turbojet_tageff.AddTree(mu_t)
turbojet_tageff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'muminus_Turbojet')
    turbojet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in tag_plots:
    var = p.var.replace('<jet>', 'muminus_Turbojet')
    turbojet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_tageff.Run()
turbojet_tageff.SaveToFile(loc + '/turbojet_tageff.root')

run1fit = FitAnalysis("res_RunI", "dptj", "Voigtian(x, N, m, s, a)")
run1fit.SetVal('m', 0.1)
run1fit.SetVal('s', 0.15)
run1fit.SetRange('m', -0.4, 0.4)
run1fit.SetRange('s', 0, 0.5)
run1fit.Init(run1jet_true)
run1fit.SetToMean('m')
run1fit.SetToMax('N')
run1fit.SetToRMS('s')
run1fit.FitIt("MLLQ")
run1fit.SaveToFile(loc+"/run1jetres.root")

hltfit = FitAnalysis("res_Hlt", "dptj", "Voigtian(x, N, m, s,a)")
hltfit.SetVal('m', 0.0)
hltfit.SetVal('s', 0.15)
hltfit.SetRange('m', -0.4, 0.4)
hltfit.SetRange('s', 0, 0.5)
hltfit.Init(hltjet_true)
hltfit.SetToMean('m')
hltfit.SetToMax('N')
hltfit.SetToRMS('s')
hltfit.FitIt("MLLQ")
hltfit.SaveToFile(loc+"/hltjetres.root")

hltgpfit = FitAnalysis("res_HltGP", "dptj", "Voigtian(x, N, m, s,a)")
hltgpfit.SetVal('m', 0.0)
hltgpfit.SetVal('s', 0.15)
hltgpfit.SetRange('m', -0.4, 0.4)
hltgpfit.SetRange('s', 0, 0.5)
hltgpfit.Init(hltgpjet_true)
hltgpfit.SetToMean('m')
hltgpfit.SetToMax('N')
hltgpfit.SetToRMS('s')
hltgpfit.FitIt("MLLQ")
hltgpfit.SaveToFile(loc+"/hltgpjetres.root")

turbofit = FitAnalysis("res_Turbo", "dptj", "Voigtian(x, N, m, s,a)")
turbofit.SetVal('m', 0.0)
turbofit.SetVal('s', 0.15)
turbofit.SetRange('m', -0.4, 0.4)
turbofit.SetRange('s', 0, 0.5)
turbofit.Init(turbojet_true)
turbofit.SetToMean('m')
turbofit.SetToMax('N')
turbofit.SetToRMS('s')
turbofit.FitIt("MLLQ")
turbofit.SaveToFile(loc+"/turbojetres.root")


from PlotTools import *
from Style import *

SetLHCbStyle()


for p in plots:
    #plot distributions
    d = Plot([run1jet.GetVar(p.name).GetHist(), hltjet.GetVar(p.name).GetHist(), hltgpjet.GetVar(p.name).GetHist(), turbojet.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','green','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetcomp_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

    d = Plot([run1jet_fake.GetVar(p.name).GetHist(), hltjet_fake.GetVar(p.name).GetHist(),  hltgpjet_fake.GetVar(p.name).GetHist(), turbojet_fake.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', '[A.U.]')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','green','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetfake_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('normalised', True)
    d.drawROOT()

    d = Plot([run1jet_true.GetVar(p.name).GetHist(), run1jet_fake.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Run 1 Jets (true)', 'Run 1 Jets (fake)'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetrun1fake_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('normalised', True)
    d.setProp('ylabel', '[A.U.]')
    d.drawROOT()

    d = Plot([hltjet_true.GetVar(p.name).GetHist(), hltjet_fake.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Hlt Jets (true)', 'Hlt Jets (fake)'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jethltfake_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('normalised', True)
    d.setProp('ylabel', '[A.U.]')
    d.drawROOT()

    d = Plot([turbojet_true.GetVar(p.name).GetHist(), turbojet_fake.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Turbo Jets (true)', 'Turbo Jets (fake)'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetturbofake_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('normalised', True)
    if hasattr(p, 'lims'): d.setProp('ylims', p.ylims)
    d.drawROOT()

    #plot fake rate
    
    run1  = run1jet_fake.GetVar(p.name).GetHist().Clone('run1_'+p.name+'_fake_rate')
    hlt   = hltjet_fake.GetVar(p.name).GetHist().Clone('hlt_'+p.name+'_fake_rate')
    hltgp = hltgpjet_fake.GetVar(p.name).GetHist().Clone('hltgp_'+p.name+'_fake_rate')
    turbo = turbojet_fake.GetVar(p.name).GetHist().Clone('turbo_'+p.name+'_fake_rate')
    run1.Divide(run1jet.GetVar(p.name).GetHist())
    hlt.Divide(hltjet.GetVar(p.name).GetHist())
    hltgp.Divide(hltgpjet.GetVar(p.name).GetHist())
    turbo.Divide(turbojet.GetVar(p.name).GetHist())

    d = Plot([run1, hlt, hltgp,turbo])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Fake Rate')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','green','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetfakerate_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'lims'): d.setProp('ylims', p.ylims)
    d.drawROOT()
    
    #plot efficiency
    d = Plot([run1jet_eff.GetVar(p.name).GetEffGraph(), hltjet_eff.GetVar(p.name).GetEffGraph(),  hltgpjet_eff.GetVar(p.name).GetEffGraph(),turbojet_eff.GetVar(p.name).GetEffGraph()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Rec. Eff.')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','green','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jeteff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.4)
    d.ShiftLegY(-0.4)
    d.setProp('ylims', [0.8, 1.05])
    d.drawROOT()
    
    #plot tag efficiency
    d = Plot([run1jet_tageff.GetVar(p.name).GetEffGraph(), hltjet_tageff.GetVar(p.name).GetEffGraph(), turbojet_tageff.GetVar(p.name).GetEffGraph()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Tagging Eff.')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jettageff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.4)
    d.ShiftLegY(-0.4)
    d.setProp('ylims', [0.8, 1.05])
    d.drawROOT()


for p in tag_plots:
    d = Plot([run1jet_tageff.GetVar(p.name).GetPassHist(), hltjet_tageff.GetVar(p.name).GetPassHist(), turbojet_tageff.GetVar(p.name).GetPassHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', '[A.U.]')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetcomp_'+p.name+'.pdf')
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('normalised', True)
    d.setProp('drawOpts', 'e1')
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()


for p in ('true_ptj10', 'true_etaj10'):
    #plot mean and resolution
    d = Plot([run1fit.GetParHist(p,1), hltfit.GetParHist(p,1), hltgpfit.GetParHist(p,1), turbofit.GetParHist(p,1)])
    d.forceStyle()
    d.setProp('ylabel', 'Mean')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red', 'black', 'green', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetmeans_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.3)
    d.setProp('ylims', [-0.4, 0.45])
    d.drawROOT()
    d = Plot([run1fit.GetParHist(p,2), hltfit.GetParHist(p,2), hltgpfit.GetParHist(p,2), turbofit.GetParHist(p,2)])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('ylabel', '#sigma')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','green', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetres_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.25, 0.2, 0.5, 0.4])
    d.drawROOT()

for p in ('cpf', 'mult'):
    #plot mean and resolution
    d = Plot([run1jet.GetVar(p).GetHist(), hltjet.GetVar(p).GetHist(), hltgpjet.GetVar(p).GetHist(), turbojet.GetVar(p).GetHist(), run1jet_true.GetVar('true_'+p).GetHist()])
    d.forceStyle()
    d.setProp('ylabel', '[A.U.]')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jest (GP)', 'Turbo Jets', 'True Jets'])
    d.setProp('colors', ['red', 'black', 'green', 'blue', 'orange'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetcomp_norm_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.6, 0.9, 0.9])
    d.setProp('normalised', True)
    if p == 'cpf':
        d.ShiftLegX(-0.4)
        d.setProp('ynormlims', [0, 0.04])
    d.drawROOT()
