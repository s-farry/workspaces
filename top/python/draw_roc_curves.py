from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()

a = TFile("/user2/sfarry/workspaces/top/tuples/tmva_mc2016_top_maxip.root")
b = TFile("/user2/sfarry/workspaces/top/tuples/tmva_mc2016_top_vtxchi2.root")
c = TFile("/user2/sfarry/workspaces/top/tuples/tmva_mc2016_top_twoip.root")
d = TFile("/user2/sfarry/workspaces/top/tuples/tmva_mc2016_top_sumip.root")

d = Plot([f.Get('Method_Cuts/Cuts/MVA_Cuts_rejBvsS') for f in [a,b,c,d]])
d.setProp('xlabel', 'Background Rejection')
d.setProp('ylabel', 'Signal Efficiency')
d.setProp('labels', ['Max IP', '#chi^{2}_{vtx}', 'Both IPs', 'Sum IP'])
d.setProp('colors', ['red', 'blue', 'black','green'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'roccurves_ip.pdf')
d.setProp('markerstyles', 20)
d.setProp('drawOpts', 'hist')
d.setProp('fillstyles', 0)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
d.drawROOT()
