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


mu_f   = TFile.Open("/hepstore/sfarry/GridOutput/2786/ZMuMuJet.JetReco.Z_mumujet17.MU.MC2016.root")
md_f   = TFile.Open("/hepstore/sfarry/GridOutput/2787/ZMuMuJet.JetReco.Z_mumujet17.MD.MC2016.root")
mu_t   = mu_f.Get("ZMuMu/DecayTree")
md_t   = md_f.Get("ZMuMu/DecayTree")

fid = TCut("muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_PT > 20000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muplus_PT > 20000 && boson_M > 60000 && boson_M < 120000")

recjet      = TCut("boson_jet_PT > 15000")
truejet     = TCut("boson_truejet_PT > 15000")
rec2truejet = TCut("boson_mcjet_PT >7500")
rec2fakejet = TCut("boson_mcjet_PT <7500")
true2recjet = TCut("boson_rectruejet_PT > 7500") 

recRunIjet      = TCut("boson_RunIjet_PT > 15000")
trueRunIjet     = TCut("boson_trueRunIjet_PT > 15000")
rec2trueRunIjet = TCut("boson_mcRunIjet_PT >7500")
rec2fakeRunIjet = TCut("boson_mcRunIjet_PT <7500")
true2recRunIjet = TCut("boson_rectrueRunIjet_PT > 7500") 
pvtrueRunIjet   = TCut("sqrt(pow(boson_rectrueRunIjet_vtx_x - boson_OWNPV_X,2) + pow(boson_rectrueRunIjet_vtx_y - boson_OWNPV_Y,2) + pow(boson_rectrueRunIjet_vtx_z - boson_OWNPV_Z,2)) < 1")

recHltjet      = TCut("boson_Hltjet_PT > 15000")
trueHltjet     = TCut("boson_trueHltjet_PT > 15000")
rec2trueHltjet = TCut("boson_mcHltjet_PT >7500")
rec2fakeHltjet = TCut("boson_mcHltjet_PT <7500")
true2recHltjet = TCut("boson_rectrueHltjet_PT > 7500") 
pvtrueHltjet   = TCut("sqrt(pow(boson_rectrueHltjet_vtx_x - boson_OWNPV_X,2) + pow(boson_rectrueHltjet_vtx_y - boson_OWNPV_Y,2) + pow(boson_rectrueHltjet_vtx_z - boson_OWNPV_Z,2)) < 1")

recHltGPjet      = TCut("boson_HltGPjet_PT > 15000")
trueHltGPjet     = TCut("boson_trueHltGPjet_PT > 15000")
rec2trueHltGPjet = TCut("boson_mcHltGPjet_PT >7500")
rec2fakeHltGPjet = TCut("boson_mcHltGPjet_PT <7500")
true2recHltGPjet = TCut("boson_rectrueHltGPjet_PT > 7500") 
pvtrueHltGPjet   = TCut("sqrt(pow(boson_rectrueHltGPjet_vtx_x - boson_OWNPV_X,2) + pow(boson_rectrueHltGPjet_vtx_y - boson_OWNPV_Y,2) + pow(boson_rectrueHltGPjet_vtx_z - boson_OWNPV_Z,2)) < 1")

recTurbojet      = TCut("boson_Turbojet_PT > 15000")
trueTurbojet     = TCut("boson_trueTurbojet_PT > 15000")
rec2trueTurbojet = TCut("boson_mcTurbojet_PT >7500")
rec2fakeTurbojet = TCut("boson_mcTurbojet_PT <7500")
true2recTurbojet = TCut("boson_rectrueTurbojet_PT > 7500") 
pvtrueTurbojet   = TCut("sqrt(pow(boson_rectrueTurbojet_vtx_x - boson_OWNPV_X,2) + pow(boson_rectrueTurbojet_vtx_y - boson_OWNPV_Y,2) + pow(boson_rectrueTurbojet_vtx_z - boson_OWNPV_Z,2)) < 1")

RunIjettag   = TCut("boson_RunIjet_BDTTag == 1")
Hltjettag    = TCut("boson_Hltjet_BDTTag == 1")
HltGPjettag    = TCut("boson_HltGPjet_BDTTag == 1")
Turbojettag  = TCut("boson_Turbojet_BDTTag == 1")

Run1jet_trueb  = TCut("abs(boson_mcRunIjet_flavour) == 5"  )
Hltjet_trueb   = TCut("abs(boson_mcHltjet_flavour) == 5"   )
HltGPjet_trueb   = TCut("abs(boson_mcHltGPjet_flavour) == 5"   )
Turbojet_trueb = TCut("abs(boson_mcTurbojet_flavour) == 5")

plots = [
    Bunch(name="ptj"     ,var= "<jet>_PT/1000.0" , bins = 50, lo = 15.0, hi = 150.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="etaj"    ,var= "<jet>_ETA", bins = 20, lo = 2.0, hi = 4.5, xlabel = '#eta^{j}'),
    Bunch(name="phi"    ,var= "<jet>_PHI", bins = 20, lo = -TMath.Pi(), hi = TMath.Pi(), xlabel = '#phi(j)'),
    Bunch(name="ptj10"   ,var= "<jet>_PT/1000.0" , bins = 10, lo = 15.0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="etaj10"  ,var= "<jet>_ETA", bins = 10, lo = 2.0, hi = 4.5, xlabel='#eta^{j}'),
    Bunch(name="cpf"     ,var= "<jet>_cpf" , bins = 100, lo = 0, hi = 1.0, xlabel = 'cpf', shiftlegx = -0.4),
    Bunch(name="mult"    ,var= "<jet>_ndauts" , bins = 46, lo = -0.5, hi = 45.5, xlabel = 'jet multiplicity', shiftlegx = -0.4),
    Bunch(name="mpt"     ,var= "<jet>_mpt" , bins = 100, lo = 0, hi = 40000.0, xlabel = 'mpt'),
    Bunch(name="mtf"     ,var= "<jet>_mtf" , bins = 100, lo = 0, hi = 1.0, xlabel = 'mtf'),
    Bunch(name="npoint"  ,var= "<jet>_npoint" , bins = 46, lo = -0.5, hi = 45.5, xlabel = 'npoint'),
    Bunch(name="width"   ,var= "<jet>_width" , bins = 50, lo = 0, hi = 1.0, xlabel = 'jet width'),
    Bunch(name="n90"     ,var= "<jet>_n90" , bins = 16, lo = -0.5, hi = 15.5, xlabel = 'n90'),
    Bunch(name='balance' ,var = "(boson_PT - <jet>_PT) / boson_PT", bins = 50, lo = -2.0, hi = 2.0, xlabel = 'Jet Balance')]
tag_plots = [
    Bunch(name="bdt0"    ,var= "<jet>_Tag0_bdt0" , bins = 50, lo = 0, hi = 1.0, xlabel = 'bdt0', shiftlegx = -0.2, shiftlegy = -0.3),
    Bunch(name="bdt1"    ,var= "<jet>_Tag0_bdt1" , bins = 50, lo = 0, hi = 1.0, xlabel = 'bdt1', shiftlegx = -0.2, shiftlegy = -0.3)
    ]
true_plots = [
    Bunch(name="true_ptj"     ,var= "<jet>_PT/1000.0" , bins = 50, lo = 15.0, hi = 150.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="true_etaj"    ,var= "<jet>_ETA", bins = 20, lo = 2.0, hi = 4.5, xlabel = '#eta^{j}'),
    Bunch(name="true_ptj10"   ,var= "<jet>_PT/1000.0" , bins = 9, lo = 10.0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="true_etaj10"  ,var= "<jet>_ETA", bins = 10, lo = 2.0, hi = 4.5, xlabel = '#eta^{j}'),
    Bunch(name="true_cpf"     ,var= "<jet>_cpf" , bins = 100, lo = 0.0, hi = 1.0, xlabel = 'cpf'),
    Bunch(name="true_mult"    ,var= "<jet>_ndauts", bins = 46, lo = -0.5, hi = 45.5, xlabel = 'multiplicity'),
    Bunch(name="true_mpt"     ,var= "<jet>_mpt" , bins = 100, lo = 0, hi = 40000.0, xlabel = 'mpt'),
    Bunch(name="true_mtf"     ,var= "<jet>_mtf" , bins = 100, lo = 0, hi = 1.0, xlabel = 'mtf'),
    Bunch(name="true_width"   ,var= "<jet>_width", bins = 50, lo = 0, hi = 1.0, xlabel = 'width')
    ]

res_plots = [
    Bunch(name="dptj"   , var= "(<jet1>_PT - <jet2>_PT)/<jet1>_PT"   , bins = 50, lo = -1, hi = 1),
    Bunch(name="detaj"  , var= "(<jet1>_ETA - <jet2>_ETA)/<jet1>_ETA", bins = 50, lo = -1, hi = 1)]

true2dvars = [ ['true_ptj10', 'dptj'], ['true_etaj10', 'dptj'] ]
vars2d = [ ['ptj10', 'balance'], ['etaj10', 'balance'] ]

run1jet = Template("run1jet")
run1jet.SetSelCut(fid + recRunIjet)
run1jet.AddTree(mu_t)
run1jet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_RunIjet')
    run1jet.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet.Add2DVars(vars2d)
run1jet.Run()
run1jet.SaveToFile(loc + '/run1jet.root')

hltjet = Template("hltjet")
hltjet.SetSelCut(fid + recHltjet)
hltjet.AddTree(mu_t)
hltjet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Hltjet')
    hltjet.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet.Add2DVars(vars2d)
hltjet.Run()
hltjet.SaveToFile(loc + '/hltzjet.root')

hltgpjet = Template("hltgpjet")
hltgpjet.SetSelCut(fid + recHltGPjet)
hltgpjet.AddTree(mu_t)
hltgpjet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_HltGPjet')
    hltgpjet.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet.Add2DVars(vars2d)
hltgpjet.Run()
hltgpjet.SaveToFile(loc + '/hltgpzjet.root')

turbojet = Template("turbojet")
turbojet.SetSelCut(fid + recTurbojet)
turbojet.AddTree(mu_t)
turbojet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Turbojet')
    turbojet.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet.Add2DVars(vars2d)
turbojet.Run()
turbojet.SaveToFile(loc + '/turbozjet.root')

run1jet_fake = Template("run1jet_fake")
run1jet_fake.SetSelCut(fid + recRunIjet + rec2fakeRunIjet)
run1jet_fake.AddTree(mu_t)
run1jet_fake.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_RunIjet')
    run1jet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_fake.Run()
run1jet_fake.SaveToFile(loc + '/run1zjet_fake.root')

hltjet_fake = Template("hltjet_fake")
hltjet_fake.SetSelCut(fid + recHltjet + rec2fakeHltjet)
hltjet_fake.AddTree(mu_t)
hltjet_fake.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Hltjet')
    hltjet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_fake.Run()

hltgpjet_fake = Template("hltjetgp_fake")
hltgpjet_fake.SetSelCut(fid + recHltjet + rec2fakeHltjet)
hltgpjet_fake.AddTree(mu_t)
hltgpjet_fake.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_HltGPjet')
    hltgpjet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_fake.Run()

turbojet_fake = Template("turbojet_fake")
turbojet_fake.SetSelCut(fid + recTurbojet + rec2fakeTurbojet)
turbojet_fake.AddTree(mu_t)
turbojet_fake.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Turbojet')
    turbojet_fake.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_fake.Run()

run1jet_true = Template("run1jet_true")
run1jet_true.SetSelCut(fid + trueRunIjet + rec2trueRunIjet)
run1jet_true.AddTree(mu_t)
run1jet_true.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_RunIjet')
    run1jet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in true_plots:
    var = p.var.replace('<jet>', 'boson_trueRunIjet')
    run1jet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'boson_trueRunIjet').replace('<jet2>', 'boson_rectrueRunIjet')
    run1jet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_true.Add2DVars(true2dvars)
run1jet_true.Run()
run1jet_true.SaveToFile(loc + '/run1zjet_true.root')

hltjet_true = Template("hltjet_true")
hltjet_true.SetSelCut(fid + recHltjet + rec2trueHltjet)
hltjet_true.AddTree(mu_t)
hltjet_true.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Hltjet')
    hltjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in true_plots:
    var = p.var.replace('<jet>', 'boson_trueHltjet')
    hltjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'boson_trueHltjet').replace('<jet2>', 'boson_rectrueHltjet')
    hltjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_true.Add2DVars(true2dvars)
hltjet_true.Run()

hltgpjet_true = Template("hltgpjet_true")
hltgpjet_true.SetSelCut(fid + recHltGPjet + rec2trueHltGPjet)
hltgpjet_true.AddTree(mu_t)
hltgpjet_true.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_HltGPjet')
    hltgpjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in true_plots:
    var = p.var.replace('<jet>', 'boson_trueHltGPjet')
    hltgpjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'boson_trueHltGPjet').replace('<jet2>', 'boson_rectrueHltGPjet')
    hltgpjet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_true.Add2DVars(true2dvars)
hltgpjet_true.Run()

turbojet_true = Template("turbojet_true")
turbojet_true.SetSelCut(fid + recTurbojet + rec2trueTurbojet)
turbojet_true.AddTree(mu_t)
turbojet_true.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Turbojet')
    turbojet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in true_plots:
    var = p.var.replace('<jet>', 'boson_trueTurbojet')
    turbojet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in res_plots:
    var = p.var.replace('<jet1>', 'boson_trueTurbojet').replace('<jet2>', 'boson_rectrueTurbojet')
    turbojet_true.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_true.Add2DVars(true2dvars)
turbojet_true.Run()

run1jet_eff = EfficiencyClass("run1jet_eff")
run1jet_eff.SetSelectionCut(fid + trueRunIjet)
run1jet_eff.SetPassCut(true2recRunIjet)
run1jet_eff.AddTree(mu_t)
run1jet_eff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_trueRunIjet')
    run1jet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_eff.Run()
run1jet_eff.SaveToFile(loc + '/run1zjet_eff.root')

hltjet_eff = EfficiencyClass("hltjet_eff")
hltjet_eff.SetSelectionCut(fid + trueHltjet)
hltjet_eff.SetPassCut(true2recHltjet)
hltjet_eff.AddTree(mu_t)
hltjet_eff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_trueHltjet')
    hltjet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_eff.Run()
hltjet_eff.SaveToFile(loc + '/hltzjet_eff.root')

hltgpjet_eff = EfficiencyClass("hltgpjet_eff")
hltgpjet_eff.SetSelectionCut(fid + trueHltGPjet)
hltgpjet_eff.SetPassCut(true2recHltGPjet)
hltgpjet_eff.AddTree(mu_t)
hltgpjet_eff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_trueHltGPjet')
    hltgpjet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_eff.Run()
hltgpjet_eff.SaveToFile(loc + '/hltgpzjet_eff.root')

turbojet_eff = EfficiencyClass("turbojet_eff")
turbojet_eff.SetSelectionCut(fid + trueTurbojet)
turbojet_eff.SetPassCut(true2recTurbojet)
turbojet_eff.AddTree(mu_t)
turbojet_eff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_trueTurbojet')
    turbojet_eff.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_eff.Run()
turbojet_eff.SaveToFile(loc + '/turbozjet_eff.root')

run1jet_pveff = EfficiencyClass("run1jet_pveff")
run1jet_pveff.SetSelectionCut(fid + trueRunIjet + true2recRunIjet )
run1jet_pveff.SetPassCut( pvtrueRunIjet )
run1jet_pveff.AddTree(mu_t)
run1jet_pveff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_trueRunIjet')
    run1jet_pveff.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_pveff.Run()
run1jet_pveff.SaveToFile(loc + '/run1zjet_pveff.root')

hltjet_pveff = EfficiencyClass("hltjet_pveff")
hltjet_pveff.SetSelectionCut(fid + trueHltjet + true2recHltjet )
hltjet_pveff.SetPassCut( pvtrueHltGPjet )
hltjet_pveff.AddTree(mu_t)
hltjet_pveff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_trueHltjet')
    hltjet_pveff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_pveff.Run()
hltjet_pveff.SaveToFile(loc + '/hltzjet_pveff.root')

hltgpjet_pveff = EfficiencyClass("hltgpjet_pveff")
hltgpjet_pveff.SetSelectionCut(fid + trueHltGPjet + true2recHltGPjet)
hltgpjet_pveff.SetPassCut( pvtrueHltGPjet )
hltgpjet_pveff.AddTree(mu_t)
hltgpjet_pveff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_trueHltGPjet')
    hltgpjet_pveff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_pveff.Run()
hltgpjet_pveff.SaveToFile(loc + '/hltgpzjet_pveff.root')

turbojet_pveff = EfficiencyClass("turbojet_pveff")
turbojet_pveff.SetSelectionCut(fid + trueTurbojet + true2recTurbojet)
turbojet_pveff.SetPassCut( pvtrueTurbojet)
turbojet_pveff.AddTree(mu_t)
turbojet_pveff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_trueTurbojet')
    turbojet_pveff.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_pveff.Run()
turbojet_pveff.SaveToFile(loc + '/turbozjet_pveff.root')

run1jet_tageff = EfficiencyClass("run1jet_tageff")
run1jet_tageff.SetSelectionCut(fid + recRunIjet + rec2trueRunIjet + Run1jet_trueb)
run1jet_tageff.SetPassCut(RunIjettag)
run1jet_tageff.AddTree(mu_t)
run1jet_tageff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_RunIjet')
    run1jet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in tag_plots:
    var = p.var.replace('<jet>', 'boson_RunIjet')
    run1jet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet_tageff.Run()
run1jet_tageff.SaveToFile(loc + '/run1zjet_tageff.root')

hltjet_tageff = EfficiencyClass("hltjet_tageff")
hltjet_tageff.SetSelectionCut(fid + recHltjet + rec2trueHltjet + Hltjet_trueb )
hltjet_tageff.SetPassCut(Hltjettag)
hltjet_tageff.AddTree(mu_t)
hltjet_tageff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Hltjet')
    hltjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in tag_plots:
    var = p.var.replace('<jet>', 'boson_Hltjet')
    hltjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet_tageff.Run()
hltjet_tageff.SaveToFile(loc + '/hltzjet_tageff.root')

hltgpjet_tageff = EfficiencyClass("hltgpjet_tageff")
hltgpjet_tageff.SetSelectionCut(fid + recHltGPjet + rec2trueHltGPjet + HltGPjet_trueb )
hltgpjet_tageff.SetPassCut(HltGPjettag)
hltgpjet_tageff.AddTree(mu_t)
hltgpjet_tageff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_HltGPjet')
    hltgpjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in tag_plots:
    var = p.var.replace('<jet>', 'boson_HltGPjet')
    hltgpjet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltgpjet_tageff.Run()
hltgpjet_tageff.SaveToFile(loc + '/hltgpzjet_tageff.root')

turbojet_tageff = EfficiencyClass("turbojet_tageff")
turbojet_tageff.SetSelectionCut(fid + recTurbojet + rec2trueTurbojet + Turbojet_trueb)
turbojet_tageff.SetPassCut(Turbojettag)
turbojet_tageff.AddTree(mu_t)
turbojet_tageff.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Turbojet')
    turbojet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
for p in tag_plots:
    var = p.var.replace('<jet>', 'boson_Turbojet')
    turbojet_tageff.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet_tageff.Run()
turbojet_tageff.SaveToFile(loc + '/turbozjet_tageff.root')

run1fit = FitAnalysis("res_RunI", "dptj", "Voigtian(x, N, m, s, a)")
run1fit.SetVal('m', 0.1)
run1fit.SetVal('s', 0.15)
run1fit.FixVal('a', 0.08)
run1fit.SetRange('m', -0.4, 0.4)
run1fit.SetRange('s', 0, 0.5)
run1fit.Init(run1jet_true)
run1fit.SetToMean('m')
run1fit.SetToMax('N')
run1fit.SetToRMS('s')
run1fit.FitIt("MLLQ")
run1fit.SaveToFile(loc+"/run1zjetres.root")

hltfit = FitAnalysis("res_Hlt", "dptj", "Voigtian(x, N, m, s,a)")
hltfit.SetVal('m', 0.0)
hltfit.SetVal('s', 0.15)
hltfit.FixVal('a', 0.08)
hltfit.SetRange('m', -0.4, 0.4)
hltfit.SetRange('s', 0, 0.5)
hltfit.Init(hltjet_true)
hltfit.SetToMean('m')
hltfit.SetToMax('N')
hltfit.SetToRMS('s')
hltfit.FitIt("MLLQ")
hltfit.SaveToFile(loc+"/hltzjetres.root")

hltgpfit = FitAnalysis("res_HltGP", "dptj", "Voigtian(x, N, m, s,a)")
hltgpfit.SetVal('m', 0.0)
hltgpfit.SetVal('s', 0.15)
hltgpfit.FixVal('a', 0.08)
hltgpfit.SetRange('m', -0.4, 0.4)
hltgpfit.SetRange('s', 0, 0.5)
hltgpfit.Init(hltgpjet_true)
hltgpfit.SetToMean('m')
hltgpfit.SetToMax('N')
hltgpfit.SetToRMS('s')
hltgpfit.FitIt("MLLQ")
hltgpfit.SaveToFile(loc+"/hltgpzjetres.root")

turbofit = FitAnalysis("res_Turbo", "dptj", "Voigtian(x, N, m, s,a)")
turbofit.SetVal('m', 0.0)
turbofit.SetVal('s', 0.15)
turbofit.FixVal('a', 0.08)
turbofit.SetRange('m', -0.4, 0.4)
turbofit.SetRange('s', 0, 0.5)
turbofit.Init(turbojet_true)
turbofit.SetToMean('m')
turbofit.SetToMax('N')
turbofit.SetToRMS('s')
turbofit.FitIt("MLLQ")
turbofit.SaveToFile(loc+"/turbozjetres.root")


run1balfit = FitAnalysis("res_balRunI", "balance", "CB(x, N, a, n2, m,s,sl,c)")
run1balfit.FixVal('c', 0)
run1balfit.FixVal('sl',0)
run1balfit.FixVal('a',1)
run1balfit.SetVal('n2', 1.8)
run1balfit.Init(run1jet)
run1balfit.SetToMean('m')
run1balfit.SetToEntries('N')
run1balfit.SetToRMS('s')
run1balfit.SetVal('etaj10', 5, 'm', 0.1)
run1balfit.SetVal('etaj10', 5, 's', 0.2)
run1balfit.FitIt("MLLQ")
run1balfit.SaveToFile(loc+"/run1zjetbalres_mc2016.root")

hltbalfit = FitAnalysis("res_balHlt", "balance", "CB(x, N, a, n2, m,s,sl,c)")
hltbalfit.FixVal('c', 0)
hltbalfit.FixVal('sl',0)
hltbalfit.SetVal('a',1)
hltbalfit.SetVal('n2', 1.8)
hltbalfit.Init(hltjet)
hltbalfit.SetToMean('m')
hltbalfit.SetToEntries('N')
hltbalfit.SetToRMS('s')
hltbalfit.SetVal('etaj10', 8, 'm', 0.08)
hltbalfit.SetVal('etaj10', 8, 's', 0.3)
hltbalfit.SetVal('ptj10', 3, 'm', 0.02)
hltbalfit.SetVal('ptj10', 3, 's', 0.2)
hltbalfit.FitIt("MLLQ")
hltbalfit.SaveToFile(loc+"/hltzjetbalres_mc2016.root")

turbobalfit = FitAnalysis("res_balTurbo", "balance", "CB(x, N, a, n2, m,s,sl,c)")
turbobalfit.FixVal('c', 0)
turbobalfit.FixVal('sl',0)
turbobalfit.FixVal('a',1)
turbobalfit.SetVal('n2', 1.8)
turbobalfit.Init(turbojet)
turbobalfit.SetToMean('m')
turbobalfit.SetToEntries('N')
turbobalfit.SetToRMS('s')
turbobalfit.SetVal('etaj10', 6, 'm', 0.3)
turbobalfit.SetVal('ptj10' , 3, 'm', 0.1)
turbobalfit.SetVal('ptj10' , 3, 's', 0.3)
turbobalfit.SetVal('ptj10' , 8, 'm', -0.1)
turbobalfit.SetVal('ptj10' , 8, 's', 0.35)
turbobalfit.SetVal('ptj10' , 9, 'm', 0)
turbobalfit.SetVal('ptj10' , 9, 's', 0.3)
turbobalfit.FitIt("MLLQ")
turbobalfit.SaveToFile(loc+"/turbozjetbalres_mc2016.root")

from PlotTools import *
from Style import *

SetLHCbStyle()


for p in plots:  
    #plot distributions
    d = Plot([run1jet.GetVar(p.name).GetHist(), hltjet.GetVar(p.name).GetHist(), turbojet.GetVar(p.name).GetHist()])
    #d = Plot([run1jet.GetVar(p.name).GetHist(), hltjet.GetVar(p.name).GetHist(), hltgpjet.GetVar(p.name).GetHist(), turbojet.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    #d.setProp('colors', ['red','black','green','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetcomp_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

    d = Plot([run1jet_fake.GetVar(p.name).GetHist(), hltjet_fake.GetVar(p.name).GetHist(), turbojet_fake.GetVar(p.name).GetHist()])
    #d = Plot([run1jet_fake.GetVar(p.name).GetHist(), hltjet_fake.GetVar(p.name).GetHist(),  hltgpjet_fake.GetVar(p.name).GetHist(), turbojet_fake.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', '[A.U.]')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    #d.setProp('colors', ['red','black','green','blue'])
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

    d = Plot([run1, hlt, turbo])
    #d = Plot([run1, hlt, hltgp,turbo])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Fake Rate')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    #d.setProp('colors', ['red','black','green','blue'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetfakerate_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'lims'): d.setProp('ylims', p.ylims)
    d.drawROOT()
    
    #plot efficiency
    d = Plot([run1jet_eff.GetVar(p.name).GetEffGraph(), hltjet_eff.GetVar(p.name).GetEffGraph(), turbojet_eff.GetVar(p.name).GetEffGraph()])
    #d = Plot([run1jet_eff.GetVar(p.name).GetEffGraph(), hltjet_eff.GetVar(p.name).GetEffGraph(),  hltgpjet_eff.GetVar(p.name).GetEffGraph(),turbojet_eff.GetVar(p.name).GetEffGraph()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Rec. Eff.')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    #d.setProp('colors', ['red','black','green','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jeteff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.4)
    d.ShiftLegY(-0.4)
    d.setProp('ylims', [0.8, 1.05])
    d.drawROOT()
    
    #plot efficiency
    d = Plot([run1jet_eff.GetVar(p.name).GetEffGraph(), hltjet_eff.GetVar(p.name).GetEffGraph(), turbojet_eff.GetVar(p.name).GetEffGraph()])
    #d = Plot([run1jet_eff.GetVar(p.name).GetEffGraph(), hltjet_eff.GetVar(p.name).GetEffGraph(),  hltgpjet_eff.GetVar(p.name).GetEffGraph(),turbojet_eff.GetVar(p.name).GetEffGraph()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Rec. Eff.')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    #d.setProp('colors', ['red','black','green','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jeteff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.4)
    d.ShiftLegY(-0.4)
    d.setProp('ylims', [0.8, 1.05])
    d.drawROOT()
    
    #plot efficiency
    d = Plot([run1jet_pveff.GetVar(p.name).GetEffGraph(), hltjet_pveff.GetVar(p.name).GetEffGraph(), turbojet_pveff.GetVar(p.name).GetEffGraph()])
    #d = Plot([run1jet_eff.GetVar(p.name).GetEffGraph(), hltjet_eff.GetVar(p.name).GetEffGraph(),  hltgpjet_eff.GetVar(p.name).GetEffGraph(),turbojet_eff.GetVar(p.name).GetEffGraph()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet PV. Eff.')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    #d.setProp('colors', ['red','black','green','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetpveff_'+p.name+'.pdf')
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
    #d.ShiftLegY(-0.4)
    d.setProp('ylims', [0, 1.05])
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
    d.setProp('drawOpts', 'hist')
    d.setProp('fillstyles', 0)
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

for p in ('true_ptj10', 'true_etaj10'):
    #plot mean and resolution
    d = Plot([run1fit.GetParHist(p,1), hltfit.GetParHist(p,1), turbofit.GetParHist(p,1)])
    #d = Plot([run1fit.GetParHist(p,1), hltfit.GetParHist(p,1), hltgpfit.GetParHist(p,1), turbofit.GetParHist(p,1)])
    d.forceStyle()
    d.setProp('ylabel', 'Mean')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red', 'black', 'blue'])
    #d.setProp('colors', ['red', 'black', 'green', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zjetmeans_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.3)
    d.setProp('ylims', [-0.4, 0.45])
    d.drawROOT()
    d = Plot([run1fit.GetParHist(p,2), hltfit.GetParHist(p,2), turbofit.GetParHist(p,2)])
    #d = Plot([run1fit.GetParHist(p,2), hltfit.GetParHist(p,2), hltgpfit.GetParHist(p,2), turbofit.GetParHist(p,2)])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('ylabel', '#sigma')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black', 'blue'])
    #d.setProp('colors', ['red','black','green', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zjetres_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.25, 0.2, 0.5, 0.4])
    d.setProp('ylims', [0, 0.4])
    d.drawROOT()


for p in ('ptj10', 'etaj10'):
    #plot mean and resolution
    d = Plot([run1balfit.GetParHist(p,3), hltbalfit.GetParHist(p,3), turbobalfit.GetParHist(p,3)])
    #d = Plot([run1fit.GetParHist(p,1), hltfit.GetParHist(p,1), hltgpfit.GetParHist(p,1), turbofit.GetParHist(p,1)])
    d.forceStyle()
    d.setProp('ylabel', 'Mean')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red', 'black', 'blue'])
    #d.setProp('colors', ['red', 'black', 'green', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zjetbalmeans_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.3)
    d.setProp('ylims', [-0.4, 0.45])
    d.drawROOT()
    d = Plot([run1balfit.GetParHist(p,4), hltbalfit.GetParHist(p,4), turbobalfit.GetParHist(p,4)])
    #d = Plot([run1fit.GetParHist(p,2), hltfit.GetParHist(p,2), hltgpfit.GetParHist(p,2), turbofit.GetParHist(p,2)])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('ylabel', '#sigma')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jets (GP)', 'Turbo Jets'])
    d.setProp('colors', ['red','black', 'blue'])
    #d.setProp('colors', ['red','black','green', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zjetbalres_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.25, 0.2, 0.5, 0.4])
    d.setProp('ylims', [0, 0.4])
    d.drawROOT()


for p in ('cpf', 'mult', 'mpt', 'width', 'ptj', 'etaj'):
    #plot mean and resolution
    d = Plot([run1jet.GetVar(p).GetHist(), hltjet.GetVar(p).GetHist(), turbojet.GetVar(p).GetHist(), run1jet_true.GetVar('true_'+p).GetHist()])
    #d = Plot([run1jet.GetVar(p).GetHist(), hltjet.GetVar(p).GetHist(), hltgpjet.GetVar(p).GetHist(), turbojet.GetVar(p).GetHist(), run1jet_true.GetVar('true_'+p).GetHist()])
    d.forceStyle()
    d.setProp('ylabel', '[A.U.]')
    d.setProp('xlabel', p)
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets', 'True Jets'])
    #d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Hlt Jest (GP)', 'Turbo Jets', 'True Jets'])
    d.setProp('colors', ['red', 'black', 'blue', 'orange'])
    #d.setProp('colors', ['red', 'black', 'green', 'blue', 'orange'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'jetcomp_norm_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.6, 0.9, 0.9])
    d.setProp('normalised', True)
    if p == 'cpf':
        d.ShiftLegX(-0.4)
        d.setProp('ynormlims', [0, 0.04])
    d.drawROOT()

