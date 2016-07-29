from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas
from PlotTools import *

from Wjconfig_new import *

f = TFile("/hepstore/sfarry/GridOutput/801/ZMuMuJet.MD.2012.root")
t = f.Get("ZMuMu/DecayTree")
g = TFile("/hepstore/sfarry/GridOutput/802/ZMuMuJet.MU.2012.root")
u = g.Get("ZMuMu/DecayTree")

fwd = TCut("muminus_ETA > muplus_ETA")
bwd = TCut("muminus_ETA < muplus_ETA")

zvars[4] = ["M", "boson_M/1000.0", [60, 65, 70, 72.5,75.0, 77.5, 80.0, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,100,102.5, 105.0, 107.5, 110.0, 120.0]]

lowzpt = TCut("boson_PT < 10000")

#get corrections
zmumu_fwd = AnalysisClass("zmumu_fwd")
zmumu_fwd.SetSelCut(selcut_zmumu_nojet + fwd)
zmumu_fwd.AddData("Data", zmumuj.MUt)
zmumu_fwd.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumu_fwd.AddVars(zvars)
zmumu_fwd.Run()
zmumu_fwd.SaveToFile()

zmumu_bwd = AnalysisClass("zmumu_bwd")
zmumu_bwd.SetSelCut(selcut_zmumu_nojet + bwd)
zmumu_bwd.AddData("Data", zmumuj.MUt)
zmumu_bwd.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumu_bwd.AddVars(zvars)
zmumu_bwd.Run()
zmumu_bwd.SaveToFile()


asymm_tot = zmumu_fwd.GetTemplate("Data").GetVar("M").GetHist().GetAsymmetry(zmumu_bwd.GetTemplate("Data").GetVar("M").GetHist())


zmumu_lowpt_fwd = AnalysisClass("zmumu_lowpt_fwd")
zmumu_lowpt_fwd.SetSelCut(selcut_zmumu_nojet + fwd + lowzpt)
zmumu_lowpt_fwd.AddData("Data", zmumuj.MUt)
zmumu_lowpt_fwd.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumu_lowpt_fwd.AddVars(zvars)
zmumu_lowpt_fwd.Run()
zmumu_lowpt_fwd.SaveToFile()

zmumu_lowpt_bwd = AnalysisClass("zmumu_lowpt_bwd")
zmumu_lowpt_bwd.SetSelCut(selcut_zmumu_nojet + bwd + lowzpt) 
zmumu_lowpt_bwd.AddData("Data", zmumuj.MUt)
zmumu_lowpt_bwd.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumu_lowpt_bwd.AddVars(zvars)
zmumu_lowpt_bwd.Run()
zmumu_lowpt_bwd.SaveToFile()


asymm_lowpt_tot = zmumu_lowpt_fwd.GetTemplate("Data").GetVar("M").GetHist().GetAsymmetry(zmumu_lowpt_bwd.GetTemplate("Data").GetVar("M").GetHist())
