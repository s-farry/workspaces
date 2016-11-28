from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()


f = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_noiso.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_noiso_ss.root")

h = TFile("/user2/sfarry/workspaces/top/tuples/zmumuj_data.root")

plots = [
    Bunch(name='iso', xlabel = 'max isolation [MeV]', ylabel = 'Events')
]

for p in plots:
    d = Plot([f.Get(p.name), g.Get(p.name)])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', p.ylabel)
    d.setProp('labels', ['opposite sign', 'same sign'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', p.name+'_qcd_background')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.setProp('ylims', [0.0001, 50])
    if hasattr(p, 'shiftlegy'):
        d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

d = Plot([h.Get('m')])
d.setProp('xlabel', 'M_{#mu#mu} [GeV]')
d.setProp('ylabel', 'Events')
d.setProp('labels', ['Z#rightarrow#mu#mu + sv-jet'])
d.setProp('colors', ['black'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'zj_data_m')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
d.drawROOT()

