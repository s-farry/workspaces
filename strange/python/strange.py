import ROOT as r
from Jawa import *

from Utils import Bunch

f = r.TFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_amcatnlo_13tev.root")
t = f.Get("Zjet")


fwdcut = r.TCut('fwdjet_pt > 20 && mup_pt > 20 && mum_pt > 20 && min(mup_eta, mum_eta) > 2 && max(mum_eta, mup_eta) < 4.5 && Z_m > 60 && Z_m < 120')
bwdcut = r.TCut('bwdjet_pt > 20 && mup_pt > 20 && mum_pt > 20 && min(mup_eta, mum_eta) > -4.5 && max(mum_eta, mup_eta) < -2 && Z_m > 60 && Z_m < 120')

fwd_strange = r.TCut('abs(fwdjet_flav) == 3')
bwd_strange = r.TCut('abs(bwdjet_flav) == 3')

fwd_quark = r.TCut('abs(fwdjet_flav) < 6')
bwd_quark = r.TCut('abs(bwdjet_flav) < 6')

fwd_gluon = r.TCut('abs(fwdjet_flav) == 21')
bwd_gluon = r.TCut('abs(bwdjet_flav) == 21')

fwd_beauty = r.TCut('abs(fwdjet_flav) == 5')
bwd_beauty = r.TCut('abs(bwdjet_flav) == 5')

fwd_charm = r.TCut('abs(fwdjet_flav) == 4')
bwd_charm = r.TCut('abs(bwdjet_flav) == 4')

fwd_light = r.TCut('abs(fwdjet_flav) < 3')
bwd_light = r.TCut('abs(bwdjet_flav) < 3')


vars = [
    Bunch(name='ptj'       , var='<jet>_pt'              , nbins=40, lo=20, hi=100, xlabel='p_{T} [GeV]'),
    Bunch(name='etaj'      , var='abs(<jet>_eta)'             , nbins=10, lo=2.2, hi=4.2, shiftlegx = 0.1, ylabel='[A.U.]', xlabel='#eta^{j}'),
    Bunch(name='kaonpt'    , var='<jet>_kaonpt'          , nbins=100, lo=0, hi=30),
    Bunch(name='kaoncpt'   , var='<jet>_kaoncpt'         , nbins=100, lo=0, hi=30),
    Bunch(name='kaonminpt' , var='<jet>_minkaonpt'       , nbins=100, lo=0, hi=30),
    Bunch(name='kaonmaxpt' , var='<jet>_maxkaonpt'       , nbins=100, lo=0, hi=30),
    Bunch(name='kaonptr'   , var='<jet>_kaonpt/<jet>_pt'   , nbins=100, lo=0, hi=1),
    Bunch(name='kaoncptr'  , var='<jet>_kaoncpt/<jet>_pt'  , nbins=100, lo=0, hi=1),
    Bunch(name='kaonminptr', var='<jet>_minkaonpt/<jet>_pt', nbins=100, lo=0, hi=1),
    Bunch(name='kaonmaxptr', var='<jet>_maxkaonpt/<jet>_pt', nbins=100, lo=0, hi=1),
    Bunch(name='pionpt'    , var='<jet>_pionpt', nbins=100, lo=0, hi=30),
    Bunch(name='pioncpt'   , var='<jet>_pioncpt', nbins=100, lo=0, hi=30),
    Bunch(name='pioncptr'  , var='<jet>_pioncpt/<jet>_pt', nbins=100, lo=0, hi=30),
    Bunch(name='pionminpt'       , var='<jet>_minpionpt'       , nbins=100, lo=0, hi=30),
    Bunch(name='pionmaxpt'       , var='<jet>_maxpionpt'       , nbins=100, lo=0, hi=30),
    Bunch(name='pionptr'         , var='<jet>_pionpt/<jet>_pt'   , nbins=100, lo=0, hi=1),
    Bunch(name='pionminptr'      , var='<jet>_minpionpt/<jet>_pt', nbins=100, lo=0, hi=1),
    Bunch(name='pionmaxptr'      , var='<jet>_maxpionpt/<jet>_pt', nbins=100, lo=0, hi=1),
    Bunch(name='mult'            , var='<jet>_mult'            , nbins=30,  lo=-0.5, hi=29.5),
    Bunch(name='dR_maxkaon'      , var='<jet>_dR_maxkaon'      , nbins=20,  lo=0, hi=1.0),
    Bunch(name='dR_maxpion'      , var='<jet>_dR_maxpion'      , nbins=20,  lo=0, hi=1.0),
    Bunch(name='chargeFrac'      , var='<jet>_chargedPt/(<jet>_chargedPt + <jet>_neutralPt)',      nbins=100, lo=0, hi=1.0),
    Bunch(name='eccentricity'    , var='<jet>_eccentricity', nbins=100, lo=0.5, hi=1.0),
    Bunch(name='width'           , var='<jet>_width', nbins=100, lo=0, hi=0.5)
]

vars2d = [
    ['ptj', 'etaj']

    ]


j_fwd = Template("incjet_fwd")
j_fwd.SetSelCut(fwdcut)
j_fwd.AddTree(t)
for v in vars: j_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
j_fwd.Add2DVars(vars2d)
j_fwd.Run()

j_bwd = Template("incjet_bwd")
j_bwd.SetSelCut(bwdcut)
j_bwd.AddTree(t)
for v in vars: j_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
j_bwd.Add2DVars(vars2d)
j_bwd.Run()

j = Template("incjet", j_fwd, j_bwd)
j.SaveToFile()

q_fwd = Template("quarkjet_fwd")
q_fwd.SetSelCut(fwdcut + fwd_quark)
q_fwd.AddTree(t)
for v in vars: q_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
q_fwd.Add2DVars(vars2d)
q_fwd.Run()

q_bwd = Template("quarkjet_bwd")
q_bwd.SetSelCut(bwdcut + bwd_quark)
q_bwd.AddTree(t)
for v in vars: q_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
q_bwd.Add2DVars(vars2d)
q_bwd.Run()

q = Template("quarkjet", q_fwd, q_bwd)
q.SaveToFile()

g_fwd = Template("gluonjet_fwd")
g_fwd.SetSelCut(fwdcut + fwd_gluon)
g_fwd.AddTree(t)
for v in vars: g_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
g_fwd.Add2DVars(vars2d)
g_fwd.Run()

g_bwd = Template("gluonjet_bwd")
g_bwd.SetSelCut(bwdcut + bwd_gluon)
g_bwd.AddTree(t)
for v in vars: g_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
g_bwd.Add2DVars(vars2d)
g_bwd.Run()

g = Template("gluonjet", g_fwd, g_bwd)
g.SaveToFile()

s_fwd = Template("strangejet_fwd")
s_fwd.SetSelCut(fwdcut + fwd_strange)
s_fwd.AddTree(t)
for v in vars: s_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
s_fwd.Add2DVars(vars2d)
s_fwd.Run()

s_bwd = Template("strangejet_bwd")
s_bwd.SetSelCut(bwdcut + bwd_strange)
s_bwd.AddTree(t)
for v in vars: s_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
s_bwd.Add2DVars(vars2d)
s_bwd.Run()

s = Template("strangejet", s_fwd, s_bwd)
s.SaveToFile()

b_fwd = Template("beautyjet_fwd")
b_fwd.SetSelCut(fwdcut + fwd_beauty)
b_fwd.AddTree(t)
for v in vars: b_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
b_fwd.Add2DVars(vars2d)
b_fwd.Run()

b_bwd = Template("beautyjet_bwd")
b_bwd.SetSelCut(bwdcut + bwd_beauty)
b_bwd.AddTree(t)
for v in vars: b_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
b_bwd.Add2DVars(vars2d)
b_bwd.Run()

b = Template("beautyjet", b_fwd, b_bwd)
b.SaveToFile()

c_fwd = Template("charmjet_fwd")
c_fwd.SetSelCut(fwdcut + fwd_charm)
c_fwd.AddTree(t)
for v in vars: c_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
c_fwd.Add2DVars(vars2d)
c_fwd.Run()

c_bwd = Template("charmjet_bwd")
c_bwd.SetSelCut(bwdcut + bwd_charm)
c_bwd.AddTree(t)
for v in vars: c_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
c_bwd.Add2DVars(vars2d)
c_bwd.Run()

c = Template("charmjet", c_fwd, c_bwd)
c.SaveToFile()

l_fwd = Template("lightjet_fwd")
l_fwd.SetSelCut(fwdcut + fwd_light)
l_fwd.AddTree(t)
for v in vars: l_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
l_fwd.Add2DVars(vars2d)
l_fwd.Run()

l_bwd = Template("lightjet_bwd")
l_bwd.SetSelCut(bwdcut + bwd_light)
l_bwd.AddTree(t)
for v in vars: l_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
l_bwd.Add2DVars(vars2d)
l_bwd.Run()

l = Template("lightjet", l_fwd, l_bwd)
l.SaveToFile()



'''
q = Template("quarkjet")
q.SetSelCut(r.TCut('jet_pt > 0 && abs(jet_flav) != 3 && abs(jet_flav) < 6 && abs(jet_flav) != 999'))
q.AddTree(t)
for v in vars: q.AddVar([v.name, v.var, v.nbins, v.lo, v.hi])
q.Run()
q.SaveToFile()

g = Template("gluonjet")
g.SetSelCut(r.TCut('jet_pt > 0 && abs(jet_flav) == 21'))
g.AddTree(t)
for v in vars: g.AddVar([v.name, v.var, v.nbins, v.lo, v.hi])
g.Run()
g.SaveToFile()

s = Template("strangejet")
s.SetSelCut(r.TCut('jet_pt > 0 && abs(jet_flav) == 3'))
s.AddTree(t)
for v in vars: s.AddVar([v.name, v.var, v.nbins, v.lo, v.hi])
s.Run()
s.SaveToFile()
'''
from Style import *
SetLHCbStyle()

from PlotTools import *

for v in vars:
    p = Plot([g.GetVar(v.name).GetHist(), q.GetVar(v.name).GetHist(), s.GetVar(v.name).GetHist()])
    for plot in p.plots: plot.UseCurrentStyle()
    p.setProp('labels', ['gluon', 'quark', 'strange'])
    p.setProp('colors', ['red', 'blue', 'green'])
    p.setProp('location', '/user2/sfarry/workspaces/strange/figures')
    p.setProp('filename', 'pythia_'+v.name+'.pdf')
    p.setProp('normalised', True)
    p.setProp('ylabel', '[A.U.]')
    p.setProp('leglims', [0.6, 0.7, 0.9, 0.9])
    if hasattr(v, 'xlabel'): p.setProp('xlabel', v.xlabel)
    if hasattr(v, 'ylabel'): p.setProp('ylabel', v.ylabel)
    if hasattr(v, 'shiftlegx'): p.ShiftLegX(v.shiftlegx)
    if hasattr(v, 'shiftlegy'): p.ShiftLegX(v.shiftlegy)
    p.drawROOT()

for v in vars:
    p = Plot([l.GetVar(v.name).GetHist(), b.GetVar(v.name).GetHist(), c.GetVar(v.name).GetHist()])
    for plot in p.plots: plot.UseCurrentStyle()
    p.setProp('labels', ['light', 'beauty', 'charm'])
    p.setProp('colors', ['red', 'blue', 'green'])
    p.setProp('location', '/user2/sfarry/workspaces/strange/figures')
    p.setProp('filename', 'pythia_heavy_light_'+v.name+'.pdf')
    p.setProp('normalised', True)
    p.setProp('ylabel', '[A.U.]')
    p.setProp('leglims', [0.6, 0.7, 0.9, 0.9])
    if hasattr(v, 'xlabel'): p.setProp('xlabel', v.xlabel)
    if hasattr(v, 'ylabel'): p.setProp('ylabel', v.ylabel)
    if hasattr(v, 'shiftlegx'): p.ShiftLegX(v.shiftlegx)
    if hasattr(v, 'shiftlegy'): p.ShiftLegX(v.shiftlegy)
    p.drawROOT()
