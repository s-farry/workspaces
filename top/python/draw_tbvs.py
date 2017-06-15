from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()


f = TFile("/user2/sfarry/lhcb/DaVinciDev_v42r1/Top/options/tbvs_mc2016.root")
g = TFile("/user2/sfarry/lhcb/DaVinciDev_v42r1/Top/options/tbvs_mc2012.root")

plots = [
    Bunch(name='ghostprob', var = 'max(piplus_TRACK_GhostProb, piminus_TRACK_GhostProb)', bins = 50, lo = 0, hi = 0.6, xlabel = 'max ghostprob', ylabel = '[A.U.]'),
    Bunch(name='chi2ndof', var = 'KS0_ENDVERTEX_CHI2/KS0_ENDVERTEX_NDOF', bins = 50, lo = 0, hi = 10, xlabel = 'chi^{2}_{vtx.}/nDoF', ylabel = '[A.U.]'),
    Bunch(name='ipchi2', var='min(piplus_IPCHI2_TOPPV, piminus_IPCHI2_TOPPV)', bins = 50, lo = 0, hi = 10, xlabel = 'chi^{2}_{ip}', ylabel = '[A.U.]'),
    Bunch(name='eta', var='atanh( KS0_PZ / KS0_P)', bins = 50, lo = 2.0, hi = 4.5, xlabel = 'eta', ylabel = '[A.U.]'),
    Bunch(name='pt', var='KS0_PT', bins = 50, lo = 0, hi = 2000, xlabel = 'pt', ylabel = '[A.U.]'),
    Bunch(name='minpt', var='min(piplus_PT, piminus_PT)', bins = 50, lo = 0, hi = 2000, xlabel = 'min(pt)', ylabel = '[A.U.]')

]

evtplots = [
    Bunch(name='ntbvs', var = 'ntbvs', bins = 25, lo = 0, hi = 500, xlabel = 'ntbvs', ylabel = '[A.U.]'),
    Bunch(name='ntbvs_full', var = 'ntbvs_full', bins = 26, lo = -1.0, hi = 51.0, xlabel = 'ntbvs', ylabel = '[A.U.]'),
    Bunch(name='ntbvs_ip', var = 'ntbvs_ip', bins = 25, lo = 0, hi = 200, xlabel = 'ntbvs', ylabel = '[A.U.]'),
    Bunch(name='ntbvs_looseip', var = 'ntbvs_looseip', bins = 25, lo = 0, hi = 500, xlabel = 'ntbvs', ylabel = '[A.U.]'),
    Bunch(name='ntbvs_noip', var = 'ntbvs_noip', bins = 25, lo = 0, hi = 500, xlabel = 'ntbvs', ylabel = '[A.U.]'),
    Bunch(name='ntbvs_gp', var = 'ntbvs_gp', bins = 25, lo = 0, hi = 500, xlabel = 'ntbvs', ylabel = '[A.U.]'),
    Bunch(name='ntbvs_trchi2', var = 'ntbvs_trchi2', bins = 25, lo = 0, hi = 500, xlabel = 'ntbvs', ylabel = '[A.U.]')

]

ghostprob = TCut("max(piplus_TRACK_GhostProb, piminus_TRACK_GhostProb) < 0.4")

from Jawa import Template

tbvs_mc2012 = Template("tbvs_mc2012")
tbvs_mc2012.SetSelCut(ghostprob)
tbvs_mc2012.AddTree(g.Get("tbvs/DecayTree"))
for b in plots:
    tbvs_mc2012.AddVar(b.name, b.var, b.bins, b.lo, b.hi)
tbvs_mc2012.Run()

tbvs_mc2016 = Template("tbvs_mc2016")
tbvs_mc2016.SetSelCut(ghostprob)
tbvs_mc2016.AddTree(f.Get("tbvs/DecayTree"))
for b in plots:
    tbvs_mc2016.AddVar(b.name, b.var, b.bins, b.lo, b.hi)
tbvs_mc2016.Run()

tbvs_mc2012_evt = Template("tbvs_mc2012_evt")
tbvs_mc2012_evt.AddTree(g.Get("tbvs_evt/EventTuple"))
for b in evtplots:
    tbvs_mc2012_evt.AddVar(b.name, b.var, b.bins, b.lo, b.hi)
tbvs_mc2012_evt.Run()

tbvs_mc2016_evt = Template("tbvs_mc2016_evt")
tbvs_mc2016_evt.AddTree(f.Get("tbvs_evt/EventTuple"))
for b in evtplots:
    tbvs_mc2016_evt.AddVar(b.name, b.var, b.bins, b.lo, b.hi)
tbvs_mc2016_evt.Run()



for p in plots:
    d = Plot([tbvs_mc2012.GetVar(p.name).GetHist(), tbvs_mc2016.GetVar(p.name).GetHist()])
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', p.ylabel)
    d.setProp('labels', ['mc2012', 'mc2016'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'tbvs_'+p.name)
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('normalised', True)
    if hasattr(p, 'shiftlegy'):
        d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

for p in evtplots:
    d = Plot([tbvs_mc2012_evt.GetVar(p.name).GetHist(), tbvs_mc2016_evt.GetVar(p.name).GetHist()])
    d.AutoYlims()
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', p.ylabel)
    d.setProp('labels', ['mc2012', 'mc2016'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'tbvs_'+p.name)
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('normalised', True)
    if hasattr(p, 'shiftlegy'):
        d.ShiftLegY(p.shiftlegy)
    d.drawROOT()
