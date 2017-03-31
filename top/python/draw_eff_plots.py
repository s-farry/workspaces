from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()

def get_eff(f):
    return f.Get('TotalEff').GetVal()

def get_eff_err(f):
    return f.Get('TotalEffErrLo').GetVal()


f = TFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff_nlorw.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/e_trackeff_nlorw.root")

h = TFile("/user2/sfarry/workspaces/top/tuples/mu_ideff_nlorw.root")
i = TFile("/user2/sfarry/workspaces/top/tuples/e_ideff_nlorw.root")

j = TFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff_nlorw.root")

k = TFile("/user2/sfarry/workspaces/top/tuples/jeteff_nlorw.root")
l = TFile("/user2/sfarry/workspaces/top/tuples/tageff_nlorw.root")

#o = TFile("/user2/sfarry/workspaces/top/tuples/e_kineff.root")
m = TFile("/user2/sfarry/workspaces/top/tuples/seleff.root")

#n = TFile("/user2/sfarry/workspaces/top/tuples/receff.root")


plots = [
    Bunch(name='eta', xlabel = '#eta'),
    Bunch(name='pt', xlabel = 'p_{T} [GeV]'),
]
jetplots = [
    Bunch(name='etaj', xlabel = '#eta'),
    Bunch(name='ptj', xlabel = 'p_{T} [GeV]'),
]

for p in plots:
    d = Plot([f.Get('mu_'+p.name+'/EfficiencyGraph'), g.Get('e_'+p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Tracking Eff.')
    d.setProp('labels', ['muons', 'electrons'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'trackingeff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.ShiftLegX(-0.4)
    d.ShiftLegY(-0.45)
    d.drawROOT()

for p in plots:
    d = Plot([h.Get('mu_'+p.name+'/EfficiencyGraph'), i.Get('e_'+p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'ID Eff.')
    d.setProp('labels', ['muons', 'electrons'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'ideff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('ylims', [0.45, 1.1])
    d.ShiftLegX(-0.4)
    d.ShiftLegY(-0.15)
    d.drawROOT()


for p in plots:
    d = Plot([h.Get('mu_'+p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Trigger Eff.')
    d.setProp('colors', ['red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'triggereff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegy'):
        d.ShiftLegY(p.shiftlegy)
    d.drawROOT()


for p in jetplots:
    d = Plot([k.Get(p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Eff.')
    d.setProp('colors', ['red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'jeteff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegy'):
        d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

for p in jetplots:
    d = Plot([l.Get(p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Jet Tagging Eff.')
    d.setProp('colors', ['red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'jettageff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegy'):
        d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

for p in plots:
    d = Plot([m.Get('mu_'+p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Selection Eff.')
    d.setProp('colors', ['red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'seleff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegy'):
        d.ShiftLegY(p.shiftlegy)
    d.drawROOT()
