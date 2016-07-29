from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas, TMath, TPaveText
from PlotTools import *
from Style import *
from Wjconfig_new import *

def add(name, a, b):
    c = a.Clone(name)
    for i in range(c.GetN()):
        x  = ROOT.Double(0.0)
        y1 = ROOT.Double(0.0)
        y2 = ROOT.Double(0.0)
        a.GetPoint(i, x, y1)
        b.GetPoint(i, x, y2)
        c.SetPoint(i, x, y1+y2)
    return c

def scale(name, a, b):
    c = a.Clone(name)
    for i in range(c.GetN()):
        x = ROOT.Double(0.0)
        y1 = ROOT.Double(0.0)
        a.GetPoint(i, x, y1)
        c.SetPoint(i, x, y1*b)
    return c


SetLHCbStyle()

a = TPaveText(0.2, 0.8, 0.4, 0.87, "NDC")
a.SetFillStyle(0)
a.SetBorderSize(0)
a.AddText('LHCb')

zj = Template("zmumuj")
zj.SetSelCut(selcut_zmumu)
zj.AddTree(zmumuj.MUt)
zj.AddTree(zmumuj.MDt)
zj.AddVar(['M', 'boson_M/1000.0', 100, 60, 120])
zj.Run()

o = Plot([zj.GetVar('M').GetHist()])
for p in o.plots: p.UseCurrentStyle()
o.plots[0].GetYaxis().SetTitleOffset(1.1)
o.setProp('colors', ['black'])
o.setProp('leglims', [0.2, 0.65, 0.5, 0.85])
o.ShiftLegY(-0.07)
o.setProp('markerstyles', [20, 0, 0, 0, 0])
o.setProp('filename', 'zmumuj_m')
o.setProp('normalised', False)
o.setProp('ylabel', 'Events / (0.6 GeV)')
o.setProp('xlabel', '#it{M_{#mu#mu}} [GeV]')
o.setProp('xlims', [60, 1200])
#o.setProp('ylims', [0.9, 1.02])
o.setProp('location', '../figures')
o.setProp('labels', ['Data, #sqrt{s}=8 TeV'])
o.setProp('extraObjs', [a])
o.drawROOT()
