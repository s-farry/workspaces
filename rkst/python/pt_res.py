from ROOT import TFile, TTree, TCut
from Jawa import *
from PlotTools import *
from Utils import Bunch

f = TFile("/user2/sfarry/lhcb/DaVinciDev_v42r1/Rkst/options/bjpsik.root")
t = f.Get("VeloCaloTuple/DecayTree")

eid  = TCut("abs(piplus_TRUEID) == 11 && piplus_TRUEID*piplus_ID < 0")
piid = TCut("abs(piplus_TRUEID) == 211 && piplus_TRUEID*piplus_ID > 0")
unmatch = TCut("piplus_TRUEID == 0")

bunches = [
    Bunch(name='ptres', var='(piplus_PT - piplus_TRUEPT) / piplus_TRUEPT', bins = 100, lo = -0.5, hi = 0.5, xlabel = 'p_{T}(rec) - p_{T}(true) / p_{T}(true)'),
    Bunch(name='ER', var = 'piplus_EcalClusterEt/piplus_PT', bins = 100, lo = 0, hi = 2, xlabel = 'CaloEt/pt'),
    Bunch(name='EHcalP', var = 'piplus_CaloHcalE/piplus_P', bins = 100, lo = 0, hi = 1.0, xlabel = 'HcalE/P', logy = True, ylims = [0.001, 1.0]),
    Bunch(name='velochi2ndof', var = 'piplus_velo_chi2ndof', bins = 100, lo = 0, hi = 5, xlabel = '#chi^{2}/ndof (velo)'),
    Bunch(name='chi2ndof', var = 'piplus_TRACK_CHI2NDOF', bins = 100, lo = 0, hi = 3, xlabel = '#chi^{2}/ndof (velo-calo)')
    ]

electrons = Template("electrons")
electrons.SetSelCut(eid)
electrons.AddTree(t)
for p in bunches:
    electrons.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
electrons.Run()

pions = Template("pions")
pions.SetSelCut(piid)
pions.AddTree(t)
for p in bunches:
    pions.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
pions.Run()

nomatch = Template("nomatch")
nomatch.SetSelCut(unmatch)
nomatch.AddTree(t)
for p in bunches:
    nomatch.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
nomatch.Run()


from Style import *
SetLHCbStyle()

for b in bunches:
    d = Plot([electrons.GetVar(b.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    if hasattr(b, 'xlabel'): d.setProp('xlabel', b.xlabel)
    d.setProp('ylabel', '[A.U.]')
    d.setProp('labels', ['Electrons'])
    d.setProp('colors', ['blue'])
    d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
    d.setProp('filename', 'electrons_'+b.name+'_mc2016.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('normalised', True)
    if hasattr(b, 'shiftlegx'): d.ShiftLegX(b.shiftlegx)
    if hasattr(b, 'shiftlegy'): d.ShiftLegY(b.shiftlegy)
    d.drawROOT()

    e = Plot([pions.GetVar(b.name).GetHist()])
    if e.name=='ptres': e.plots[0].Fit('gaus')
    e.forceStyle()
    e.AutoYlims()
    if hasattr(b, 'xlabel'): e.setProp('xlabel', b.xlabel)
    e.setProp('ylabel', '[A.U.]')
    e.setProp('labels', ['Pions'])
    e.setProp('colors', ['red'])
    e.setProp('normalised', True)
    e.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
    e.setProp('filename', 'pions_'+b.name+'_mc2016.pdf')
    e.setProp('markerstyles', 20)
    e.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(b, 'shiftlegx'): e.ShiftLegX(b.shiftlegx)
    if hasattr(b, 'shiftlegy'): e.ShiftLegY(b.shiftlegy)
    e.drawROOT()

    ff = Plot([nomatch.GetVar(b.name).GetHist()])
    ff.forceStyle()
    ff.AutoYlims()
    if hasattr(b, 'xlabel'): ff.setProp('xlabel', b.xlabel)
    ff.setProp('ylabel', '[A.U.]')
    ff.setProp('labels', ['Unmatched'])
    ff.setProp('colors', ['orange'])
    ff.setProp('normalised', True)
    ff.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
    ff.setProp('filename', 'nomatch_'+b.name+'_mc2016.pdf')
    ff.setProp('markerstyles', 20)
    ff.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(b, 'shiftlegx'): ff.ShiftLegX(b.shiftlegx)
    if hasattr(b, 'shiftlegy'): ff.ShiftLegY(b.shiftlegy)
    ff.drawROOT()

    ff = Plot([electrons.GetVar(b.name).GetHist(), pions.GetVar(b.name).GetHist(), nomatch.GetVar(b.name).GetHist()])
    ff.forceStyle()
    ff.AutoYlims()
    if hasattr(b, 'xlabel'): ff.setProp('xlabel', b.xlabel)
    ff.setProp('ylabel', '[A.U.]')
    ff.setProp('labels', ['Electrons', 'Pions', 'Unmatched'])
    ff.setProp('colors', ['blue', 'red', 'orange'])
    ff.setProp('normalised', True)
    ff.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
    ff.setProp('filename', 'alltracks_'+b.name+'_mc2016.pdf')
    ff.setProp('markerstyles', 20)
    ff.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(b, 'logy'):
        ff.setProp('logscale', b.logy)
        ff.AutoYlims(scale = 1.5, ylow = 0.001)
    if hasattr(b, 'shiftlegx'): ff.ShiftLegX(b.shiftlegx)
    if hasattr(b, 'shiftlegy'): ff.ShiftLegY(b.shiftlegy)
    ff.drawROOT()

