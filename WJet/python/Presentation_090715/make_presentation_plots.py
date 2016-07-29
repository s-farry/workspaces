from os import sys
from Jawa import Template
import copy

from Wjconfig_new import *

m = ["m", "boson_M/1000", 100, 60, 120]

zmumuj_data = Template("zmumuj")
zmumuj_data.SetSelCut(selcut_zmumu)
zmumuj_data.AddTree(zmumuj.MDt)
zmumuj_data.AddTree(zmumuj.MUt)
zmumuj_data.AddVar(m)
zmumuj_data.Run()

zmumu = Template("zmumu")
zmumu.SetSelCut(selcut_zmumu_nojet)
zmumu.AddTree(zmumuj.MDt)
zmumu.AddTree(zmumuj.MUt)
zmumu.AddVar(m)
zmumu.Run()

from Style import SetLHCbStyle
from PlotTools import Plot
#hack
import ROOT
ROOT.gStyle.Reset()
SetLHCbStyle()
ROOT.gStyle.SetTitleFont(132, "xyz")
ROOT.gStyle.SetLabelFont(132, "xyz")

properties = {
    'includeNormErr' : False,
    'labels'          :      ['ptj>10', 'ptj>20', 'ptj>40', 'ptj>60'],
    'xlabel':     '#eta'    ,
    'ylabel':     '[A.U.]',
    'location' : ".",
    'normalised' : True,
    'logscale' : False,
    'colors' : "None",
    'leglims'  : [0.6, 0.7, 0.9, 0.9],
}

a = Plot([zmumu.GetVar("m").GetHist(), zmumuj_data.GetVar("m").GetHist()])
a.plots[1].SetMarkerStyle(20)
a.plots[0].SetLineWidth(2)
a.setProps(properties)
a.properties['labels'] = ['Z#rightarrow#mu#mu (2012 Data)', 'Z#rightarrow#mu#muj (2012 Data)']
a.properties['ylabel'] = 'A.U'
a.properties['xlabel'] = 'M_{#mu#mu} [GeV]'
a.properties['linecolors'] = ['red', 'black']
a.properties['drawOpts'] = ['h', 'epl']
a.properties['filename']   = "zmumu_mass"
a.drawROOT()
