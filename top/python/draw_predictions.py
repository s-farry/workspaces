from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()

f = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13teV_amcatnlo_predictions.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_powheg_predictions.root")

plots = [
    Bunch(name='etaj', xlabel = '#eta^{j}', ylabel = '#sigma [pb]', ylims = [0, 0.045]),
    Bunch(name='ptj', xlabel = 'p_{T}^{j}', ylabel = '#sigma [pb]', ylims = [0, 0.045]),
    Bunch(name='mu_eta', xlabel = '#eta^{#mu}', ylabel = '#sigma [pb]'),
    Bunch(name='mu_pt', xlabel = '#p_{T}^{#mu}', ylabel = '#sigma [pb]'),
    Bunch(name='e_eta', xlabel = '#eta^{e}', ylabel = '#sigma [pb]'),
    Bunch(name='e_pt', xlabel = '#p_{T}^{e}', ylabel = '#sigma [pb]'),
]

details = ROOT.TPaveText(0.15,0.18,0.53,0.35, "NDC")
details.AddText("NLO t#bar{t}#rightarrow #muebX")
details.AddText("NNPDF 3.0, #alpha_{s}(M_{Z}) = 0.118")
details.AddText("PYTHIA8")
details.SetFillStyle(0)
details.SetBorderSize(0)

for p in plots:
    d = Plot([f.Get(p.name+'_toterrs'), f.Get(p.name+'_scaleerrs'),
              g.Get(p.name+'_toterrs'), g.Get(p.name+'_scaleerrs')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', p.ylabel)
    d.setProp('labels', ['aMC@NLO Scale', 'aMC@NLO Total', 'Powheg Scale', 'Powheg Total'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', p.name+'_predictions_13tev.pdf')
    #d.setProp('markerstyles', 0)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    d.properties['colors'] = [ROOT.kGreen, ROOT.kYellow+1, ROOT.kRed+2, ROOT.kRed+2]
    d.properties['drawOpts'] = ['e2', 'e2','e2','e2']
    d.properties['extraObjs'] = [ details ]
    d.properties['fillstyles'] = [1001,1001, 0,3003]
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    if hasattr(p, 'ylims'): d.setProp('ylims', p.ylims)
    d.drawROOT()
