from os import sys
from analysis import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *

vars2d = [
    ['PT','LogIP'],
    ['PT','IsoAsymm']
    ]
vars3d = [
    ['PT','LogIP','TotIso'],
    ['PT','LogIP','MuJet_PT'],
    ['PT','LogIP','IsoAsymm'],
    ['PT','NNBTag','IsoAsymm'],
    ['PT','SVTag','IsoAsymm']
    ]

dataf   = TFile.Open("/hepstore/sfarry/WMu.2012.root")
datat   = dataf.Get("WTuple/DecayTree")


ptj20 = TCut("PFjet_PT > 20000")
jetvars = [
    ["Jet_M",  "PFjet_M", 100 , 0, 20000],
    ["Jet_PT", "PFjet_PT", 100 , 0, 100000],
    ["Jet_mpt", "PFjet_mpt", 100 , 0, 30000],
    ["Jet_mtf", "PFjet_mtf", 100 , 0, 1],
    ["Jet_npoint", "PFjet_npoint", 21 , -0.5, 20.5],
    ["Jet_mult", "PFjet_number_of_daughters", 41 , -0.5, 40.5],
    ["MuJet_M",  "sqrt( (PFjet_PE + muminus_PE)^2 - ((PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 + (PFjet_PZ + muminus_PZ)^2 ) )", 100, 0, 100000],
    ["MuJet_PT",  "sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 )", 100, 0, 100000],
    ["NNBTag", "PFjet_nnbtag", 200, 0, 1],
    ["SVTag" , "PFjet_svtag", 3, -1500, 1500]
    ]

mujpt     = TCut("sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 ) > 20000")
hiip  = TCut("log10(muminus_ipubs_chi2) > 1.2 && log10(muminus_ipubs_chi2) < 2.6")
loip = TCut("log10(muminus_ipubs_chi2) < 1")
nnbtag = TCut("PFjet_nnbtag < 0.85")
svtag = TCut("PFjet_svtag != 1")

muj_data2012 = Template("muj_data2012", datat, selcut_base + ptj20 + mujpt + iso )
muj_data2012.AddVars(muvars)
muj_data2012.AddVars(jetvars)
muj_data2012.Add2DVars(vars2d)
muj_data2012.Add3DVars(vars3d)
muj_data2012.ApplyCut()
muj_data2012.FillVars()
muj_data2012.SaveToFile()


'''
muj_data2012 = Template("muj_data2012", datat, selcut_base + ptj20 + mujpt + loip )
muj_data2012.AddVars(muvars)
muj_data2012.AddVars(jetvars)
muj_data2012.Add2DVars(vars2d)
muj_data2012.Add3DVars(vars3d)
muj_data2012.ApplyCut()
muj_data2012.FillVars()
muj_data2012.SaveToFile()
'''

tauj_data2012 = Template("tauj_data2012", datat, selcut_base + ptj20 + mujpt + hiip )
tauj_data2012.AddVars(muvars)
tauj_data2012.AddVars(jetvars)
tauj_data2012.Add2DVars(vars2d)
tauj_data2012.Add3DVars(vars3d)
tauj_data2012.ApplyCut()
tauj_data2012.FillVars()
tauj_data2012.SaveToFile()

tauj_nnbtag_data2012 = Template("tauj_nnbtag_data2012", datat, selcut_base + ptj20 + mujpt + hiip + nnbtag )
tauj_nnbtag_data2012.AddVars(muvars)
tauj_nnbtag_data2012.AddVars(jetvars)
tauj_nnbtag_data2012.Add2DVars(vars2d)
tauj_nnbtag_data2012.Add3DVars(vars3d)
tauj_nnbtag_data2012.ApplyCut()
tauj_nnbtag_data2012.FillVars()
tauj_nnbtag_data2012.SaveToFile()

tauj_svtag_data2012 = Template("tauj_svtag_data2012", datat, selcut_base + ptj20 + mujpt + hiip + svtag )
tauj_svtag_data2012.AddVars(muvars)
tauj_svtag_data2012.AddVars(jetvars)
tauj_svtag_data2012.Add2DVars(vars2d)
tauj_svtag_data2012.Add3DVars(vars3d)
tauj_svtag_data2012.ApplyCut()
tauj_svtag_data2012.FillVars()
tauj_svtag_data2012.SaveToFile()


