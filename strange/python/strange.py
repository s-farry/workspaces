import ROOT as r
from Jawa import *

f = r.TFile("/user2/sfarry/workspaces/strange/tuples/zmumuj.root")
t = f.Get("Zjet")


vars = [
    ['ptj' , 'jet_pt', 100, 0, 50],
    ['etaj', 'jet_eta', 100, -5, 5],
    ['kaonpt', 'jet_kaonpt', 100, 0, 30],
    ['kaoncpt', 'jet_kaoncpt', 100, 0, 30],
    ['kaonminpt', 'jet_minkaonpt', 100, 0, 30],
    ['kaonmaxpt', 'jet_maxkaonpt', 100, 0, 30],
    ['kaonptr', 'jet_kaonpt/jet_pt', 100, 0, 1],
    ['kaoncptr', 'jet_kaoncpt/jet_pt', 100, 0, 1],
    ['kaonminptr', 'jet_minkaonpt/jet_pt', 100, 0, 1],
    ['kaonmaxptr', 'jet_maxkaonpt/jet_pt', 100, 0, 1],
    ['pionpt', 'jet_pionpt', 100, 0, 30],
    ['pionminpt', 'jet_minpionpt', 100, 0, 30],
    ['pionmaxpt', 'jet_maxpionpt', 100, 0, 30],
    ['pionptr', 'jet_pionpt/jet_pt', 100, 0, 1],
    ['pionminptr', 'jet_minpionpt/jet_pt', 100, 0, 1],
    ['pionmaxptr', 'jet_maxpionpt/jet_pt', 100, 0, 1],
    ['mult'      ,  'jet_mult',      30, -0.5, 29.5],
    ['dR_maxkaon'      ,  'jet_dR_maxkaon',      20, 0, 1.0]
]


j = Template("incjet")
j.SetSelCut(r.TCut('jet_pt > 0 && abs(jet_flav) != 3'))
j.AddTree(t)
j.AddVars(vars)
j.Run()
j.SaveToFile()

s = Template("strangejet")
s.SetSelCut(r.TCut('jet_pt > 0 && abs(jet_flav) == 3'))
s.AddTree(t)
s.AddVars(vars)
s.Run()
s.SaveToFile()


from Style import *
SetLHCbStyle()

from PlotTools import *

for v in vars:
    name = v[0]
    p = Plot([j.GetVar(name).GetHist(), s.GetVar(name).GetHist()])
    for plot in p.plots: plot.UseCurrentStyle()
    p.setProp('labels', ['Inclusive', 'Strange'])
    p.setProp('colors', ['red', 'blue'])
    p.setProp('location', '/user2/sfarry/workspaces/strange/figures/strange')
    p.setProp('filename', name+'.pdf')
    p.setProp('normalised', True)
    p.setProp('ylabel', '[A.U.]')
    p.drawROOT()
