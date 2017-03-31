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

mu_f   = TFile.Open("/hepstore/sfarry/GridOutput/2749/ZMuMuJet.JetReco.MD.2016.root")
md_f   = TFile.Open("/hepstore/sfarry/GridOutput/2750/ZMuMuJet.JetReco.MU.2016.root")
mu_t   = mu_f.Get("ZMuMu/DecayTree")
md_t   = md_f.Get("ZMuMu/DecayTree")

fid = TCut("muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_PT > 20000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muplus_PT > 20000 && boson_M > 60000 && boson_M < 120000")

recRunIjet      = TCut("boson_RunIjet_PT > 15000 && (boson_PHI - boson_RunIjet_PHI < TMath::Pi() ? abs(boson_PHI - boson_RunIjet_PHI) : 2*TMath::Pi() - abs(boson_PHI - boson_RunIjet_PHI)) > 2.7")
recHltjet      = TCut("boson_Hltjet_PT > 15000 && (boson_PHI - boson_Hltjet_PHI < TMath::Pi() ? abs(boson_PHI - boson_Hltjet_PHI) : 2*TMath::Pi() - abs(boson_PHI - boson_Hltjet_PHI)) > 2.7")
recTurbojet      = TCut("boson_Turbojet_PT > 15000 && (boson_PHI - boson_Turbojet_PHI < TMath::Pi() ? abs(boson_PHI - boson_Turbojet_PHI) : 2*TMath::Pi() - abs(boson_PHI - boson_Turbojet_PHI)) > 2.7")

RunIjettag   = TCut("boson_RunIjet_BDTTag == 1")
Hltjettag    = TCut("boson_Hltjet_BDTTag == 1")
Turbojettag  = TCut("boson_Turbojet_BDTTag == 1")

onejet = TCut("boson_mult20==1")

runs = [174000, 176000, 178000, 180000, 182000, 184000, 186000]

plots = [
    Bunch(name="ptj"     ,var= "<jet>_PT/1000.0" , bins = 30, lo = 15.0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="etaj"    ,var= "<jet>_ETA", bins = 20, lo = 2.0, hi = 4.5, xlabel = '#eta^{j}'),
    Bunch(name="ptj10"     ,var= "<jet>_PT/1000.0" , bins = 10, lo = 15.0, hi = 100.0, xlabel = 'p_{T}^{j} [GeV]'),
    Bunch(name="etaj10"    ,var= "<jet>_ETA", bins = 10, lo = 2.0, hi = 4.5, xlabel='#eta^{j}'),
    Bunch(name="cpf"     ,var= "<jet>_cpf" , bins = 100, lo = 0, hi = 1.0, xlabel = 'cpf', shiftlegx = -0.4),
    Bunch(name="mult"    ,var= "<jet>_ndauts" , bins = 26, lo = -0.5, hi = 25.5, xlabel = 'jet multiplicity', shiftlegx = -0.4),
    Bunch(name="mpt"     ,var= "<jet>_mpt" , bins = 100, lo = 0, hi = 40000.0, xlabel = 'mpt'),
    Bunch(name="mtf"     ,var= "<jet>_mtf" , bins = 100, lo = 0, hi = 1.0, xlabel = 'mtf'),
    Bunch(name="npoint"  ,var= "<jet>_npoint" , bins = 46, lo = -0.5, hi = 45.5, xlabel = 'npoint'),
    Bunch(name="width"   ,var= "<jet>_width" , bins = 50, lo = 0, hi = 1.0, xlabel = 'jet width'),
    Bunch(name="n90"     ,var= "<jet>_n90" , bins = 16, lo = -0.5, hi = 15.5, xlabel = 'n90'),
    Bunch(name='balance' ,var = "(boson_PT - <jet>_PT) / boson_PT", bins = 50, lo = -2.0, hi = 2.0, xlabel = 'Jet Balance'),
    Bunch(name='run', var='runNumber', binedges = runs, xlabel = 'run')
    ]

tag_plots = [
    Bunch(name="bdt0"   ,var= "<jet>_Tag0_bdt0" , bins = 50, lo = 0, hi = 1.0, xlabel = 'bdt0'),
    Bunch(name="bdt1"   ,var= "<jet>_Tag0_bdt1" , bins = 50, lo = 0, hi = 1.0, xlabel = 'bdt1'),
    ]

res_plots = [
    Bunch(name="dptj"     ,var= "(<jet1>_PT - <jet2>_PT)/<jet1>_PT"   , bins = 50, lo = -1, hi = 1),
    Bunch(name="detaj"    ,var= "(<jet1>_ETA - <jet2>_ETA)/<jet1>_ETA", bins = 50, lo = -1, hi = 1)]

true2dvars = [ ['true_ptj10', 'dptj'], ['true_etaj10', 'dptj'], ['run', 'dptj'] ]

run1jet = Template("run1jet")
run1jet.SetSelCut(fid + recRunIjet)
run1jet.AddTree(mu_t)
run1jet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_RunIjet')
    if hasattr(p, 'binedges'):
        run1jet.AddVar(p.name, var, p.binedges )
    else:
        run1jet.AddVar(p.name, var, p.bins, p.lo, p.hi)
run1jet.Add2DVar(['etaj10', 'balance'])
run1jet.Add2DVar(['ptj10', 'balance'])
run1jet.Add2DVar(['run', 'balance'])
run1jet.Run()
run1jet.SaveToFile(loc + '/run1zjet.root')

hltjet = Template("hltjet")
hltjet.SetSelCut(fid + recHltjet)
hltjet.AddTree(mu_t)
hltjet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Hltjet')
    if hasattr(p, 'binedges'):
        hltjet.AddVar(p.name, var, p.binedges)
    else:
        hltjet.AddVar(p.name, var, p.bins, p.lo, p.hi)
hltjet.Add2DVar(['etaj10', 'balance'])
hltjet.Add2DVar(['ptj10', 'balance'])
hltjet.Add2DVar(['run', 'balance'])
hltjet.Run()
hltjet.SaveToFile(loc + '/hltzjet.root')

turbojet = Template("turbojet")
turbojet.SetSelCut(fid + recTurbojet)
turbojet.AddTree(mu_t)
turbojet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Turbojet')
    if hasattr(p, 'binedges'):
        turbojet.AddVar(p.name, var, p.binedges)
    else:
        turbojet.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbojet.Add2DVar(['etaj10', 'balance'])
turbojet.Add2DVar(['ptj10', 'balance'])
turbojet.Add2DVar(['run', 'balance'])
turbojet.Run()
turbojet.SaveToFile(loc + '/turbozjet.root')

run11jet = Template("run11jet")
run11jet.SetSelCut(fid + recRunIjet + onejet)
run11jet.AddTree(mu_t)
run11jet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_RunIjet')
    if hasattr(p, 'binedges'):
        run11jet.AddVar(p.name, var, p.binedges)
    else:
        run11jet.AddVar(p.name, var, p.bins, p.lo, p.hi)
run11jet.Run()
run11jet.SaveToFile(loc + '/run1z1jet.root')

hlt1jet = Template("hltjet")
hlt1jet.SetSelCut(fid + recHltjet + onejet)
hlt1jet.AddTree(mu_t)
hlt1jet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Hltjet')
    if hasattr(p, 'binedges'):
        hlt1jet.AddVar(p.name, var, p.binedges )
    else:
        hlt1jet.AddVar(p.name, var, p.bins, p.lo, p.hi)
hlt1jet.Run()
hlt1jet.SaveToFile(loc + '/hltz1jet.root')

turbo1jet = Template("turbo1jet")
turbo1jet.SetSelCut(fid + recTurbojet + onejet)
turbo1jet.AddTree(mu_t)
turbo1jet.AddTree(md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_Turbojet')
    if hasattr(p, 'binedges'):
        turbo1jet.AddVar(p.name, var, p.binedges)
    else:
        turbo1jet.AddVar(p.name, var, p.bins, p.lo, p.hi)
turbo1jet.Run()
turbo1jet.SaveToFile(loc + '/turboz1jet.root')


run1fit = FitAnalysis("res_RunI", "balance", "CB(x, N, a, n2, m,s,sl,c)")
run1fit.FixVal('c', 0)
run1fit.FixVal('sl',0)
run1fit.FixVal('a',1)
run1fit.SetVal('n2', 1.8)
run1fit.Init(run1jet)
run1fit.SetToMean('m')
run1fit.SetToEntries('N')
run1fit.SetToRMS('s')
run1fit.SetVal('etaj10', 5, 'm', 0.1)
run1fit.SetVal('etaj10', 5, 's', 0.2)
run1fit.FitIt("MLLQ")
run1fit.SaveToFile(loc+"/run1zjetres.root")

hltfit = FitAnalysis("res_Hlt", "balance", "CB(x, N, a, n2, m,s,sl,c)")
hltfit.FixVal('c', 0)
hltfit.FixVal('sl',0)
hltfit.SetVal('a',1)
hltfit.SetVal('n2', 1.8)
hltfit.Init(hltjet)
hltfit.SetToMean('m')
hltfit.SetToEntries('N')
hltfit.SetToRMS('s')
hltfit.SetVal('etaj10', 8, 'm', 0.08)
hltfit.SetVal('etaj10', 8, 's', 0.3)
hltfit.SetVal('ptj10', 3, 'm', 0.02)
hltfit.SetVal('ptj10', 3, 's', 0.2)
hltfit.FitIt("MLLQ")
hltfit.SaveToFile(loc+"/hltzjetres.root")

turbofit = FitAnalysis("res_Turbo", "balance", "CB(x, N, a, n2, m,s,sl,c)")
turbofit.FixVal('c', 0)
turbofit.FixVal('sl',0)
turbofit.FixVal('a',1)
turbofit.SetVal('n2', 1.8)
turbofit.Init(turbojet)
turbofit.SetToMean('m')
turbofit.SetToEntries('N')
turbofit.SetToRMS('s')
turbofit.SetVal('etaj10', 6, 'm', 0.3)
turbofit.SetVal('ptj10' , 3, 'm', 0.1)
turbofit.SetVal('ptj10' , 3, 's', 0.3)
turbofit.SetVal('ptj10' , 8, 'm', -0.1)
turbofit.SetVal('ptj10' , 8, 's', 0.35)
turbofit.SetVal('ptj10' , 9, 'm', 0)
turbofit.SetVal('ptj10' , 9, 's', 0.3)
turbofit.FitIt("MLLQ")
turbofit.SaveToFile(loc+"/turbozjetres.root")

from PlotTools import *
from Style import *

SetLHCbStyle()


for p in plots:
    #plot distributions

    d = Plot([run1jet.GetVar(p.name).GetHist(), hltjet.GetVar(p.name).GetHist(), turbojet.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zmumuj_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

    d = Plot([run11jet.GetVar(p.name).GetHist(), hlt1jet.GetVar(p.name).GetHist(), turbo1jet.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Run I Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zmumu1j_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()




for p in ('ptj10', 'etaj10', 'run'):
    #plot mean and resolution
    d = Plot([run1fit.GetParHist(p,3), hltfit.GetParHist(p,3), turbofit.GetParHist(p,4)])
    d.forceStyle()
    d.setProp('ylabel', 'Mean')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red', 'black', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zjmeans_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.3)
    d.ShiftLegY(-0.4)
    d.setProp('ylims', [-0.4, 0.45])
    d.drawROOT()
    d = Plot([run1fit.GetParHist(p,4), hltfit.GetParHist(p,4), turbofit.GetParHist(p,4)])
    d.forceStyle()
    #d.AutoYlims()
    d.setProp('ylabel', '#sigma')
    d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
    d.setProp('colors', ['red','black','blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zjres_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.25, 0.2, 0.5, 0.4])
    d.setProp('ylims', [0,0.4])
    d.drawROOT()

d = Plot([run1fit.GetHist(), hltfit.GetHist(), turbofit.GetHist()])
d.forceStyle()
d.plots[0].GetListOfFunctions()[0].SetLineColor(2)
d.plots[1].GetListOfFunctions()[0].SetLineColor(1)
d.plots[2].GetListOfFunctions()[0].SetLineColor(4)
d.setProp('ylabel', '[A.U.]')
d.setProp('xlabel', '(p_{T}^{Z} - p_{T}^{j}) / p_{T}^{Z}')
d.setProp('labels', ['Run 1 Jets', 'Hlt Jets', 'Turbo Jets'])
d.setProp('colors', ['red', 'black', 'blue'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures')
d.setProp('filename', 'zjbalance.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
#d.setProp('normalised', True)
d.ShiftLegX(-0.45)
#d.ShiftLegY(-0.1)
#d.setProp('ylims', [-0.4, 0.45])
d.drawROOT()
