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

f = TFile('/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/fit_W_1_Wm-isoz-qcd-etam/fitW_etam.root')
r = f.Get("frame_muminus_ISO__2a7b7f30")
h0 = r.getObject(0)
h1 = r.getObject(1)
h2 = r.getObject(2)
h3 = r.getObject(3)

a = TPaveText(0.2, 0.8, 0.4, 0.87, "NDC")
a.SetFillStyle(0)
a.SetBorderSize(0)
a.AddText('LHCb')

o = Plot([h1, h0, h2, h3, h1])
for p in o.plots: p.UseCurrentStyle()
o.plots[0].GetYaxis().SetTitleOffset(1.1)
o.setProp('colors', ['black', 'red', 'green', 'blue', 'black'])
o.setProp('leglims', [0.2, 0.6, 0.6, 0.85])
o.ShiftLegY(-0.07)
o.setProp('markerstyles', [20, 0, 0, 0, 0])
o.setProp('filename', 'wmj_fit')
o.setProp('normalised', False)
o.setProp('ylabel', 'Events / (0.05)')
o.setProp('xlabel', '#it{p}_{T}^{#it{#mu}} / #it{p}_{T}^{#it{#mu}-jet}   ')
o.setProp('xlims', [0, 1])
#o.setProp('ylims', [0.9, 1.02])
o.setProp('location', '../figures')
o.setProp('labels', ['Data, #sqrt{s}=8 TeV', 'QCD', 'Electroweak', 'Fit'])
o.setProp('extraObjs', [a])
o.drawROOT()


g = TFile('/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/fit_W_1_Wp-isoz-qcd-etam/fitW_etam.root')
r2 = g.Get("frame_muminus_ISO__2fb79990")
i0 = r2.getObject(0)
i1 = r2.getObject(1)
i2 = r2.getObject(2)
i3 = r2.getObject(3)

o.plots = [i1, i0, i2, i3, i1]
for p in o.plots: p.UseCurrentStyle()
o.plots[0].GetYaxis().SetTitleOffset(1.1)
o.setProp('filename', 'wpj_fit')
o.drawROOT()

#stacks
h5 = add('h5', h2, h0)
o.plots = [h1, h5, h0, h3, h1]
for p in o.plots: p.UseCurrentStyle()
o.plots[0].GetYaxis().SetTitleOffset(1.1)
o.setProp('drawOpts', ['e1', 'f', 'f', '', 'e1'])
o.setProp('fillstyles', [0, 1001, 1001, 0, 0, 0])
#o.setProp('colors', ['black', 'green', ROOT.kBlue-1, '', ''])
o.setProp('colors', ['black', ROOT.kBlue-4, ROOT.kYellow-7, 'red', 'black'])
o.setProp('labels', ['Data, #sqrt{s}=8 TeV', 'Electroweak', 'QCD', 'Fit'])
o.setProp('filename', 'wmj_fit_stack')
o.drawROOT()

i5 = add('i5', i2, i0)
o.plots = [i1, i5, i0, i3, i1]
for p in o.plots: p.UseCurrentStyle()
o.plots[0].GetYaxis().SetTitleOffset(1.1)
o.setProp('drawOpts', ['e1', 'f', 'f', '', 'e1'])
o.setProp('fillstyles', [0, 1001, 1001, 0, 0, 0])
#o.setProp('colors', ['black', 'green', ROOT.kBlue-1, '', ''])
o.setProp('colors', ['black', ROOT.kBlue-4, ROOT.kYellow-7, 'red', 'black'])
o.setProp('labels', ['Data, #sqrt{s}=8 TeV', 'Electroweak', 'QCD', 'Fit'])
o.setProp('filename', 'wpj_fit_stack')
o.drawROOT()


wp_ewk_frac = 0.11976
wm_ewk_frac = 0.19706

#stacks
h6 = scale('h6', h2, wp_ewk_frac)
h7 = add('h7', h6, h0)
o.plots = [h1, h5, h7, h0, h3, h1]
#leave out fit
o.plots = [h1, h5, h7, h0, h1]
for p in o.plots: p.UseCurrentStyle()
o.plots[0].GetYaxis().SetTitleOffset(1.1)
o.setProp('markerstyles', [20, 0, 0, 0, 0, 0])
o.setProp('drawOpts', ['e1', 'f', 'f', 'f','', 'e1'])
o.setProp('fillstyles', [0, 1001, 1001, 1001, 0, 0, 0])
o.setProp('leglims', [0.2, 0.50, 0.6, 0.80])
#o.setProp('colors', ['black', 'green', ROOT.kBlue-1, '', ''])
#o.setProp('colors', ['black', ROOT.kBlue-4, ROOT.kGreen-6, ROOT.kYellow-7, 'red', 'black'])
o.setProp('colors', ['black', ROOT.kBlue-4, ROOT.kGreen-6, ROOT.kYellow-7, 'black'])

#o.setProp('labels', ['Data, #sqrt{s}=8 TeV', '#it{W^{-}j}', 'Electroweak','QCD', 'Fit'])
o.setProp('labels', ['Data, #sqrt{s}=8 TeV', '#it{W^{#scale[1.2]{#minus}}j}', 'Electroweak','QCD'])

o.setProp('filename', 'wmj_fit_stack_ewk')
o.setProp('ylims', [0, 45000])
o.drawROOT()

i6 = scale('i6', i2, wp_ewk_frac)
i7 = add('i7', i6, i0)
o.plots = [i1, i5, i7, i0, i3, i1]
o.plots = [i1, i5, i7, i0, i1]

for p in o.plots: p.UseCurrentStyle()
o.plots[0].GetYaxis().SetTitleOffset(1.1)
o.setProp('labels', ['Data, #sqrt{s}=8 TeV', '#it{W^{#scale[1.2]{#plus}}j}', 'Electroweak','QCD'])
o.setProp('filename', 'wpj_fit_stack_ewk')
o.drawROOT()

