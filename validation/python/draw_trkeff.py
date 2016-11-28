from os import sys
from Jawa import Template
import copy

from ROOT import TFile
from Style import SetLHCbStyle
from PlotTools import Plot
#hack
import ROOT
ROOT.gStyle.Reset()
SetLHCbStyle()
ROOT.gStyle.SetTitleFont(132, "xyz")
ROOT.gStyle.SetLabelFont(132, "xyz")

f = TFile("MuonWTracking2015.root")
g = TFile("MuonWTracking2015MuPlus.root")
h = TFile("MuonWTracking2015MuMinus.root")

to_plot = [['ETA', '#eta'], ['PT', 'p_{T} [GeV]'], ['PHI', '#phi [rad.]'], ['SPDHits', 'SPDHits']]

properties = {
    'includeNormErr' : False,
    'labels'          :      ['ptj>10', 'ptj>20', 'ptj>40', 'ptj>60'],
    'xlabel':     '#eta'    ,
    'ylabel':     'Tracking Efficiency',
    'location' : "../figures",
    'normalised' : False,
    'logscale' : False,
    'colors' : "None",
    'leglims'  : [0.6, 0.2, 0.9, 0.4]
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
    a = Plot([f.Get(p[0]+'/EfficiencyGraph')])
    a.setProps(properties)
    if p[0] == 'SPDHits': a.ShiftLegX(-0.4)
    a.properties['labels']      = ['2015 Data' ]
    a.properties['ylabel']      = 'Tracking Efficiency'
    a.properties['xlabel']      = p[1]
    a.properties['ylims']       = [0.8, 1.0]
    a.properties['linecolors']  = ['black']
    a.properties['markerstyles'] = [20, 20, 20]
    a.properties['drawOpts']    = ['ep', 'ep']
    a.properties['filename']    = "trkeff_2015_"+p[0]
    a.drawROOT()

    b = Plot([g.Get(p[0]+'/EfficiencyGraph'), h.Get(p[0]+'/EfficiencyGraph')])
    b.setProps(properties)
    if p[0] == 'SPDHits': b.ShiftLegX(-0.4)
    b.properties['labels']      = ['2015 Data - +ve', '2015 Data - -ve' ]
    b.properties['ylabel']      = 'Tracking Efficiency'
    b.properties['xlabel']      = p[1]
    b.properties['ylims']       = [0.8, 1.0]
    b.properties['linecolors']  = ['red', 'blue']
    b.properties['markerstyles'] = [20, 20]
    b.properties['drawOpts']    = ['ep', 'ep']
    b.properties['filename']    = "trkeff_2015_charge_"+p[0]
    b.drawROOT()
