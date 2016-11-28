from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()


f = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_tot_fiducial.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_amcatnlo.root")


plots = [
    Bunch(name='t_y', xlabel = 'y^{t}', ylabel = '#sigma [pb]'),
    Bunch(name='tbar_y', xlabel = 'y^{#bar{t}}', ylabel = '#sigma [pb]'),
    Bunch(name='t_pt', xlabel = 'p_{T}^{t} [GeV]', ylabel = '#sigma [pb]', shiftlegy = -0.2),
    Bunch(name='tbar_pt', xlabel = 'p_{T}^{#bar{t} [GeV]}', ylabel = '#sigma [pb]', shiftlegy = -0.2)
]

a = TPaveText(0.2, 0.5, 0.4, 0.6, 'NDC')
a.AddText('t#bar{t} -> #mu^{#pm} e^{#mp} bb')
a.SetFillStyle(0)
a.SetBorderSize(0)


for p in plots:
    d = Plot([f.Get(p.name+'_Central'), g.Get(p.name+'_Central')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', p.ylabel)
    d.setProp('labels', ['tot', 'fiducial'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', p.name+'_fiducial')
    d.setProp('logscale', True )
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('extraObjs', [ a ] )
    d.setProp('ylims', [0.0001, 10])
    if hasattr(p, 'shiftlegy'):
        d.ShiftLegY(p.shiftlegy)
    d.drawROOT()
