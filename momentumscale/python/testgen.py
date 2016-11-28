from ROOT import *
from Jawa import *
from PlotTools import *


dpm_loc = 'root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/'

f = TFile.Open(dpm_loc+'zmumu.pythia.root')
t = f.Get('Zjet')

cut = TCut('Z_M > 60 && Z_M < 120 && min(mup_eta, mum_eta) > 2.0 && max(mup_eta, mum_eta) < 4.5 && min(mum_pt, mup_pt) > 20')


zmumu = Template("zmumu_pythia")
zmumu.SetSelCut(cut)
zmumu.AddTree(t)
zmumu.AddVars([['M', 'Z_M', 100, 60, 120], ['ETA', 'mup_eta', 10, 2.0, 4.5]])
zmumu.Add2DVar(['M', 'ETA'])
zmumu.Run()

plots = []

hist2d = zmumu.Get2DVar('M','ETA').GetHist()

for i in range(5):
    h = hist2d.ProjectionX('hist'+str(i), i*2+1, i*2+1)
    h.Scale(1/h.Integral())
    plots += [ h ]

from Style import *
SetLHCbStyle()

p = Plot(plots)
for plot in p.plots: plot.UseCurrentStyle()
p.setProp('filename', 'z0_mass_v_eta_pythia')
p.setProp('location', '/user2/sfarry/momentumscale/figures')
#p.setProp('ylims', [88, 94])
p.setProp('colors', ['red', 'blue', 'green', 'orange', 'yellow'])
#p.setProp('markerstyles', 20)
p.setProp('xlabel', '#eta (#mu^{+})')
#p.setProp('leglims', [0.2, 0.7, 0.55, 0.9])
p.drawROOT()

