from os import sys
from analysis import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from WTauConfig import *

jetvars = [
    ["Jet_M",  "PFjet_M", 100 , 0, 20000],
    ["Jet_PT", "PFjet_PT", 100 , 0, 100000],
    ["Jet_mpt", "PFjet_mpt", 100 , 0, 30000],
    ["Jet_mtf", "PFjet_mtf", 100 , 0, 1],
    ["Jet_npoint", "PFjet_npoint", 21 , -0.5, 20.5],
    ["Jet_mult", "PFjet_number_of_daughters", 41 , -0.5, 40.5],
    ["MuJet_M",  "sqrt( (PFjet_PE + muminus_PE)^2 - ((PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 + (PFjet_PZ + muminus_PZ)^2 ) )", 100, 0, 100000],
    ["MuJet_PT",  "sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 )", 100, 0, 100000]
    ]

jet        = TCut("PFjet_mtf <0.75 && PFjet_npoint >=2 && PFjet_mpt > 1800 && PFjet_PT > 20000")
jet10      = TCut("PFjet_mtf <0.75 && PFjet_npoint >=2 && PFjet_mpt > 1800 && PFjet_PT > 10000")
mupjpt     = TCut("sqrt( (PFjet_PX + muplus_PX)^2 + (PFjet_PY + muplus_PY)^2 ) > 20000")
mumjpt     = TCut("sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 ) > 20000")
taupjpt    = TCut("sqrt( (PFjet_PX + tau_mu2_px)^2 + (PFjet_PY + tau_mu2_py)^2 ) > 20000")
taumjpt    = TCut("sqrt( (PFjet_PX + tau_mu_px)^2 + (PFjet_PY + tau_mu_py)^2 ) > 20000")
antijpt    = TCut("sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 ) < 20000")

wmujet = Template("wmujet", datat, selcut + jet10 + lowip + mumjpt)
wmujet.AddVars(variables)
wmujet.AddVars(jetvars)
wmujet.ApplyCut()
wmujet.FillVars()
wmujet.SaveToFile()

wmupj = Template("wmupj", datat, selcut + jet10 + lowip + mumjpt + plus)
wmupj.AddVars(variables)
wmupj.AddVars(jetvars)
wmupj.ApplyCut()
wmupj.FillVars()
wmupj.SaveToFile()

wmumj = Template("wmumj", datat, selcut + jet10 + lowip + mumjpt + minus)
wmumj.AddVars(variables)
wmumj.AddVars(jetvars)
wmumj.ApplyCut()
wmumj.FillVars()
wmumj.SaveToFile()
