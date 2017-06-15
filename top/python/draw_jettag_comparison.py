from ROOT import TFile, TH1F
from Utils import Bunch
from Jawa import *
from PlotTools import *
from Style import *

f = TFile("/user2/sfarry/workspaces/top/tuples/tageff_test_mc2016.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/tageff_test_mc2012.root")
h = TFile("/user2/sfarry/workspaces/top/tuples/tag_test_mc2016.root")
i = TFile("/user2/sfarry/workspaces/top/tuples/tag_test_mc2012.root")

plots = [
    Bunch(name='ptj', var='pt', xlabel='p_{T} [GeV]'),
    Bunch(name='etaj', var='eta', xlabel='#eta', ShiftLegX = -0.05, ShiftLegY = 0.4, ylims = [0.5, 0.75]),
    Bunch(name='phij', var='phi', xlabel='#phi', ShiftLegX = -0.05, ShiftLegY = 0.4, ylims = [0.5, 0.75]),
    Bunch(name='mu_ipchi2', var='mu_ipchi2', xlabel='#chi^2_{IP}', ShiftLegX = 0.2, ShiftLegY = 0.4, ylims = [0.5, 0.75]),
    Bunch(name='cpf', var='cpf', xlabel='cpf'),
    Bunch(name='mpt', var='mpt', xlabel='mpt'),
    Bunch(name='mtf', var='mtf', xlabel='mtf'),
    Bunch(name='npoint', var='npoint', xlabel='npoint'),
    Bunch(name='width', var='width', xlabel='width'),
    Bunch(name='mult', var='mult', xlabel='mult'),
    Bunch(name='ntbvs', var='ntbvs', xlabel='ntbvs', ShiftLegX = 0.2, ShiftLegY = 0.2),
    Bunch(name='ipchi2', var='ipchi2', xlabel='ipchi2', ShiftLegX = 0.2, ShiftLegY = 0.2),
    Bunch(name='svmult', var='svmult', xlabel='svmult', ShiftLegX = 0.2, ShiftLegY = 0.2)
    ]

SetLHCbStyle()

for p in plots:
    a = Plot([f.Get(p.name+'/EfficiencyGraph'), g.Get(p.name+'/EfficiencyGraph')])
    a.AutoYlims()
    a.setProp('location', '/user2/sfarry/workspaces/top/figures')
    a.setProp('filename', 'tageff_simcomp_'+p.name+'.pdf')
    a.setProp('colors', ['red', 'blue'])
    a.setProp('labels', ['MC2016', 'MC2012'])
    a.setProp('markerstyles', 20)
    a.setProp('leglims', [0.2, 0.3, 0.6, 0.5])
    if hasattr(p, 'ShiftLegX'): a.ShiftLegX(p.ShiftLegX)
    if hasattr(p, 'ShiftLegY'): a.ShiftLegY(p.ShiftLegY)
    if hasattr(p, 'ylims'): a.setProp('ylims', p.ylims)
    if hasattr(p, 'xlabel'): a.setProp('xlabel', p.xlabel)
    a.drawROOT()

for p in plots:
    a = Plot([h.Get(p.name), i.Get(p.name)])
    a.AutoYlims()
    a.setProp('location', '/user2/sfarry/workspaces/top/figures')
    a.setProp('filename', 'tageff_simcomp_norm_'+p.name+'.pdf')
    a.setProp('colors', ['red', 'blue'])
    a.setProp('labels', ['MC2016', 'MC2012'])
    a.setProp('markerstyles', 20)
    a.setProp('leglims', [0.2, 0.3, 0.6, 0.5])
    a.setProp('normalised', True)
    a.setProp('ylabel', '[A.U.]')
    if hasattr(p, 'ShiftLegX'): a.ShiftLegX(p.ShiftLegX)
    if hasattr(p, 'ShiftLegY'): a.ShiftLegY(p.ShiftLegY)
    if hasattr(p, 'ylims'): a.setProp('ylims', p.ylims)
    if hasattr(p, 'xlabel'): a.setProp('xlabel', p.xlabel)
    a.drawROOT()
