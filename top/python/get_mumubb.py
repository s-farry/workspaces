from ROOT import *
from Jawa import *
from PlotTools import *
from Utils import Bunch

f = TFile("/hepstore/sfarry/GridOutput/2520/A2MuMuJet.MD.2015.root")
g = TFile("/hepstore/sfarry/GridOutput/2521/A2MuMuJet.MU.2015.root")
t = f.Get("ZMuMu/DecayTree")
u = g.Get("ZMuMu/DecayTree")

selection = TCut("boson_jet_tag == 1 && boson_jet2_tag == 1")

vars = [
    Bunch(name='m', var='boson_M', bins = 20, lo = 10, hi = 100)
]

a2mumu = Template("a2mumu")
a2mumu.SetSelCut(selection)
a2mumu.AddTree(t)
a2mumu.AddTree(u)
for v in vars:
    a2mumu.AddVar(v.name, v.var, v.bins, v.lo, v.hi)
a2mumu.Run()
a2mumu.SaveToFile()
