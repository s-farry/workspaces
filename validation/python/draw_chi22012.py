from os import sys
from Jawa import Template
import copy

from ROOT import TFile, TCut
from Style import SetLHCbStyle
from PlotTools import Plot
#hack
import ROOT
ROOT.gStyle.Reset()
SetLHCbStyle()
ROOT.gStyle.SetTitleFont(132, "xyz")
ROOT.gStyle.SetLabelFont(132, "xyz")

f = TFile("/hepstore/sfarry/GridOutput/1507/WMu.2012.root")
t = f.Get("WTuple/DecayTree")

chi2ndof = ["chi2ndof", "muminus_TRACK_CHI2NDOF", 100, 0, 5]

wmu_2012 = Template("wmu_2012")
wmu_2012.AddTree(t)
wmu_2012.AddVar(chi2ndof)
wmu_2012.Run()
wmu_2012.SaveToFile()

wmu_2012_iso = Template("wmu_2012_iso")
wmu_2012_iso.SetSelCut(TCut("muminus_cpt_0.50 < 2000"))
wmu_2012_iso.AddTree(t)
wmu_2012_iso.AddVar(chi2ndof)
wmu_2012_iso.Run()
wmu_2012_iso.SaveToFile()

wmu_2012_perr2 = Template("wmu_2012_perr2")
wmu_2012_perr2.SetSelCut(TCut("sqrt(muminus_PERR2)/muminus_P < 0.1"))
wmu_2012_perr2.AddTree(t)
wmu_2012_perr2.AddVar(chi2ndof)
wmu_2012_perr2.Run()
wmu_2012_perr2.SaveToFile()


to_plot = [['chi2ndof', '#chi^{2}/ndof']]

properties = {
    'includeNormErr' : False,
    'labels'          :      ['ptj>10', 'ptj>20', 'ptj>40', 'ptj>60'],
    'xlabel':     '#eta'    ,
    'ylabel':     'Tracking Efficiency',
    'location' : "../figures",
    'normalised' : True,
    'logscale' : False,
    'colors' : "None",
    'leglims'  : [0.6, 0.7, 0.9, 0.9]
}

'''
for p in to_plot:
    a = Plot([dimu_mc2015.GetVar(p[0]).GetHist(), dimu_mc2015_b.GetVar(p[0]).GetHist()])
    a.plots[0].SetLineWidth(2)
    a.plots[1].SetMarkerStyle(20)
    a.setProps(properties)
    a.properties['labels']     = ['MC2015', 'MC2015 - 0x40f9014e' ]
    a.properties['ylabel']     = 'Events'
    a.properties['xlabel']     = p[1]
    a.properties['ylims']      = copy.copy((p[2]))
    a.properties['ylims'][1] = a.properties['ylims'][1]*a.plots[0].Integral()
    a.properties['linecolors'] = ['red', 'black']
    a.properties['drawOpts']   = ['h', 'epl']
    a.properties['filename']   = "dimu_mc2015_"+p[0]
    a.drawROOT()
'''

for p in to_plot:
    a = Plot([temp.GetVar(p[0]).GetHist() for temp in [wmu_2012, wmu_2012_iso, wmu_2012_perr2]])
    a.setProps(properties)
    a.setProp('ylims', [0, 0.06])
    for pp in a.plots: pp.GetYaxis().SetRangeUser(0, 0.05)
    a.properties['labels']      = ['2012 Data' , '2012 Data (isolated)', '2012 Data (sigmap/p)']
    a.properties['ylabel']      = '[A.U.]'
    a.properties['xlabel']      = p[1]
    a.properties['linecolors']  = ['black', 'blue', 'red']
    a.properties['markerstyles'] = [0, 20, 20]
    a.properties['drawOpts']    = ['hist', 'ep', 'ep']
    a.properties['filename']    = "wmu_2012_"+p[0]
    a.drawROOT()
