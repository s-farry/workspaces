from ROOT import *
from Style import *
SetLHCbStyle()

from Jawa import *
from PlotTools import *
f = TFile("/user2/sfarry/validation/python/MuonL0EWTrigger2015.root")


for i in [3]:
    plot2d = Plot([f.Get('musta_'+str(i)+'_x_musta_'+str(i)+'_y/EffGraph2D')])
    plot2d.setProp('drawOpts', 'colz')
    plot2d.setProp('filename', 'muid_2d_'+str(i))
    plot2d.setProp('xlabel', 'x[mm]')
    plot2d.setProp('ylabel', 'y[mm]')
    plot2d.drawROOT()

    for i in range(plot2d.plot[0].GetXaxis().GetNbinsX()):
        


