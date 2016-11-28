from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()

def get_eff(f):
    return f.Get('TotalEff').GetVal()

def get_eff_err(f):
    return f.Get('TotalEffErrLo').GetVal()


f = TFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/e_trackeff.root")

h = TFile("/user2/sfarry/workspaces/top/tuples/mu_ideff.root")
i = TFile("/user2/sfarry/workspaces/top/tuples/e_ideff.root")

j = TFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff.root")

k = TFile("/user2/sfarry/workspaces/top/tuples/jeteff.root")
l = TFile("/user2/sfarry/workspaces/top/tuples/tageff.root")

o = TFile("/user2/sfarry/workspaces/top/tuples/e_kineff.root")
m = TFile("/user2/sfarry/workspaces/top/tuples/seleff.root")

n = TFile("/user2/sfarry/workspaces/top/tuples/receff.root")


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


totaleff = get_eff(n)*get_eff(m)*get_eff(l)
totaleff_err = sqrt(pow(get_eff_err(n)/get_eff(n),2) + pow(get_eff_err(m)/get_eff(m),2) +
                    pow(get_eff_err(l)/get_eff(l),2))*get_eff(n)*get_eff(m)*get_eff(l)

print '''
muon tracking & {mutrack:.3f} $\pm$ {mutrackerr:.3f} \\\\
electron tracking & {etrack:.3f} $\pm$ {etrackerr:.3f}\\\\
muon id & {muonid:.3f} $\pm$ {muoniderr:.3f}\\\\
electron id & {electronid:.3f}$\pm$ {electroniderr:.3f} \\\\
trigger & {trigger:.3f}$\pm$ {triggererr:.3f} \\\\
electron kinematics & {ekin:.3f} $\pm$ {ekinerr:.3f}\\\\
jet reconstruction & {jetrec:.3f} $\pm$ {jetrecerr:.3f}\\\\
\hline
reconstruction & {rec:.3f} $\pm$ {recerr:.3f} \\\\
\hline
selection & {sel:.3f} $\pm$ {selerr:.3f}  \\\\
\hline
jet tagging & {jettag:.3f} $\pm$ {jettagerr:.3f}\\\\
\hline
total & {total:.3f} $\pm$ {totalerr:.3f}
'''.format(mutrack = get_eff(f), etrack = get_eff(g), muonid = get_eff(h), electronid = get_eff(i), trigger = get_eff(j), ekin = get_eff(o), rec = get_eff(n), jetrec = get_eff(k), jettag = get_eff(l), sel = get_eff(m),total= get_eff(n)*get_eff(m)*get_eff(l), mutrackerr = get_eff_err(f), etrackerr = get_eff_err(g),muoniderr=get_eff_err(h), electroniderr = get_eff_err(i), triggererr = get_eff_err(j), ekinerr = get_eff_err(o), recerr = get_eff_err(n), jetrecerr = get_eff_err(k), jettagerr = get_eff_err(l), selerr = get_eff_err(m), totalerr = totaleff_err)
