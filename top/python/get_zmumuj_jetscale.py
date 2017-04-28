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

data2015_mu_f   = TFile.Open("/hepstore/sfarry/GridOutput/2818/ZMuMuJet.MU.2015.root")
data2015_md_f   = TFile.Open("/hepstore/sfarry/GridOutput/2817/ZMuMuJet.MD.2015.root")
data2015_mu_t   = data2015_mu_f.Get("ZMuMu/DecayTree")
data2015_md_t   = data2015_md_f.Get("ZMuMu/DecayTree")

data2016_mu_f   = TFile.Open("/hepstore/sfarry/GridOutput/2821/ZMuMuJet.MU.2016.root")
data2016_md_f   = TFile.Open("/hepstore/sfarry/GridOutput/2819/ZMuMuJet.MD.2016.root")
data2016_mu_t   = data2016_mu_f.Get("ZMuMu/DecayTree")
data2016_md_t   = data2016_md_f.Get("ZMuMu/DecayTree")

mc_mu_f   = TFile.Open("/hepstore/sfarry/GridOutput/2813/Zmumujet.Zg_mumu.MU.MC2016.root")
mc_md_f   = TFile.Open("/hepstore/sfarry/GridOutput/2814/Zmumujet.Zg_mumu.MD.MC2016.root")
mc_mu_t   = mc_mu_f.Get("ZMuMu/DecayTree")
mc_md_t   = mc_md_f.Get("ZMuMu/DecayTree")

fid = TCut("muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_PT > 20000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muplus_PT > 20000 && boson_M > 60000 && boson_M < 120000")

recjet      = TCut("boson_jet_PT > 15000 && (boson_PHI - boson_jet_PHI < TMath::Pi() ? abs(boson_PHI - boson_jet_PHI) : 2*TMath::Pi() - abs(boson_PHI - boson_jet_PHI)) > 2.7")

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

true2dvars = [ ['true_ptj10', 'dptj'], ['true_etaj10', 'dptj'] ]

data = Template("data")
data.SetSelCut(fid + recjet)
data.AddTree(data2015_mu_t)
data.AddTree(data2015_md_t)
data.AddTree(data2016_mu_t)
data.AddTree(data2016_md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_jet')
    if hasattr(p, 'binedges'):
        data.AddVar(p.name, var, p.binedges )
    else:
        data.AddVar(p.name, var, p.bins, p.lo, p.hi)
data.Add2DVar(['etaj10', 'balance'])
data.Add2DVar(['ptj10', 'balance'])
data.Add2DVar(['run', 'balance'])
data.Run()
#data.SaveToFile(loc + '/run1zjet.root')

mc = Template("mc")
mc.SetSelCut(fid + recjet)
mc.AddTree(mc_mu_t)
mc.AddTree(mc_md_t)
for p in plots:
    var = p.var.replace('<jet>', 'boson_jet')
    if hasattr(p, 'binedges'):
        mc.AddVar(p.name, var, p.binedges)
    else:
        mc.AddVar(p.name, var, p.bins, p.lo, p.hi)
mc.Add2DVar(['etaj10', 'balance'])
mc.Add2DVar(['ptj10', 'balance'])
mc.Run()
#mc.SaveToFile(loc + '/hltzjet.root')

datafit = FitAnalysis("res_data", "balance", "CB(x, N, a, n2, m,s,sl,c)")
datafit.FixVal('c', 0)
datafit.FixVal('sl',0)
datafit.FixVal('a',1)
datafit.SetVal('n2', 1.8)
datafit.Init(data)
datafit.SetToMean('m')
datafit.SetToEntries('N')
datafit.SetToRMS('s')
datafit.SetVal('ptj10', 3, 'm', 0.13)
datafit.SetVal('ptj10', 3, 's', 0.25)
#datafit.SetVal('etaj10', 5, 'm', 0.1)
#datafit.SetVal('etaj10', 5, 's', 0.2)
datafit.FitIt("MLLQ")
datafit.SaveToFile(loc+"/datazjetres.root")

mcfit = FitAnalysis("res_mc", "balance", "CB(x, N, a, n2, m,s,sl,c)")
mcfit.FixVal('c', 0)
mcfit.FixVal('sl',0)
mcfit.SetVal('a',1)
mcfit.SetVal('n2', 1.8)
mcfit.Init(mc)
mcfit.SetToMean('m')
mcfit.SetToEntries('N')
mcfit.SetToRMS('s')
#mcfit.SetVal('etaj10', 8, 'm', 0.08)
#mcfit.SetVal('etaj10', 8, 's', 0.3)
#mcfit.SetVal('ptj10', 3, 'm', 0.02)
#mcfit.SetVal('ptj10', 3, 's', 0.2)
mcfit.SetVal('ptj10', 1, 'm', 0.15)
mcfit.SetVal('ptj10', 1, 's', 0.25)
mcfit.FitIt("MLLQ")
mcfit.SaveToFile(loc+"/mczjetres.root")

from PlotTools import *
from Style import *

SetLHCbStyle()

for p in plots:
    #plot distributions
    d = Plot([data.GetVar(p.name).GetHist(), mc.GetVar(p.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Data', 'MC2016'])
    d.setProp('colors', ['black','red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zmumuj_jetscale_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

for p in ('ptj10', 'etaj10'):
    #plot mean and resolution
    d = Plot([datafit.GetParHist(p,3), mcfit.GetParHist(p,3)])
    d.forceStyle()
    d.setProp('ylabel', 'Mean')
    d.setProp('labels', ['Data', 'MC2016'])
    d.setProp('colors', ['black', 'red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zmumuj_jetscale_mean_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.3)
    d.ShiftLegY(-0.4)
    d.setProp('ylims', [-0.4, 0.45])
    d.drawROOT()
    d = Plot([datafit.GetParHist(p,4), mcfit.GetParHist(p,4)])
    d.forceStyle()
    #d.AutoYlims()
    d.setProp('ylabel', '#sigma')
    d.setProp('labels', ['Data', 'MC2016'])
    d.setProp('colors', ['black','red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures')
    d.setProp('filename', 'zmumuj_jetscale_res_'+p+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.25, 0.2, 0.5, 0.4])
    d.setProp('ylims', [0,0.4])
    d.drawROOT()

d = Plot([datafit.GetHist(), mcfit.GetHist()])
d.forceStyle()
d.plots[0].GetListOfFunctions()[0].SetLineColor(2)
d.plots[1].GetListOfFunctions()[0].SetLineColor(1)
d.setProp('ylabel', '[A.U.]')
d.setProp('xlabel', '(p_{T}^{Z} - p_{T}^{j}) / p_{T}^{Z}')
d.setProp('labels', ['Data', 'MC2016'])
d.setProp('colors', ['black', 'red'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures')
d.setProp('filename', 'zjbalance_jetscale.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
#d.setProp('normalised', True)
d.ShiftLegX(-0.45)
#d.ShiftLegY(-0.1)
#d.setProp('ylims', [-0.4, 0.45])
d.drawROOT()


#make ratio
res_data = datafit.GetParHist('ptj10',4)
res_mc   = mcfit.GetParHist('ptj10',4)

mean_data = datafit.GetParHist('ptj10',3)
mean_mc   = mcfit.GetParHist('ptj10',3)

res_ratio = res_data.Clone("zmumuj_jetres_smear")
for i in range(res_ratio.GetNbinsX()):
    f = 0.0
    if res_data.GetBinContent(i+1) > res_mc.GetBinContent(i+1) and res_data.GetBinContent(i+1) > 0 and res_mc.GetBinContent(i+1) > 0:
        f = sqrt(pow(res_data.GetBinContent(i+1),2) - pow(res_mc.GetBinContent(i+1),2))
    res_ratio.SetBinContent(i+1, f)

mean_offset = mean_data.Clone("zmumuj_jetmean_offset")
mean_offset.Add(mean_mc, -1)

f = TFile("/user2/sfarry/workspaces/top/tuples/jetenergyscale_corrections.root", "RECREATE")
res_ratio.Write()
mean_offset.Write()
f.Close()
