
from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas, TMath
from PlotTools import *
from Style import *
from Wjconfig_new import *

SetLHCbStyle()

f = TFile('wj_acc.root')

o = Plot([f.Get('ETA_acc_plus'), f.Get('ETA_acc_minus')])
o.setProp('colors', ['blue', 'red'])
o.setProp('leglims', [0.2, 0.7, 0.4, 0.85])
o.setProp('markerstyles', 20)
o.setProp('filename', 'wj_acc_eta')
o.setProp('normalised', False)
o.setProp('ylabel', 'Acceptance')
o.setProp('xlabel', '#eta^{#mu}')
o.setProp('ylims', [0.9, 1.02])
o.setProp('location', '../figures/acc')
o.setProp('labels', ['W^{+}j', 'W^{-}j'])
o.drawROOT()

o.plots = [f.Get('Jet_ETA_acc_plus'), f.Get('Jet_ETA_acc_minus')]
o.setProp('filename', 'wj_acc_etaj')
o.setProp('xlabel', '#eta^{j}')
o.drawROOT()

o.plots = [f.Get('Jet_PT_acc_plus'), f.Get('Jet_PT_acc_minus')]
o.setProp('filename', 'wj_acc_ptj')
o.setProp('xlabel', 'p_{T}^{j} [GeV')
o.drawROOT()
