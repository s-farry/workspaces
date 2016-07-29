from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *

data_minus = Template("zmumuj_data2012_minus")
data_minus.SetSelCut(selcut + zmumu)
data_minus.AddTree(zmumuj.MUt)
data_minus.AddTree(zmumuj.MDt)
data_minus.AddVars(variables)
data_minus.AddVars(jetvars)
data_minus.Add2DVars(vars2d)
data_minus.ApplyCut()
data_minus.FillVars()

data_plus = Template("zmumuj_data2012_plus")
data_plus.SetSelCut(selcut_plus + zmumu)
data_plus.AddTree(zmumuj.MUt)
data_plus.AddTree(zmumuj.MDt)
data_plus.AddVars(plusvariables)
data_plus.AddVars(plusjetvars)
data_plus.Add2DVars(vars2d)
data_plus.ApplyCut()
data_plus.FillVars()

data = Template("zmumuj_data2012", data_plus, data_minus)
data.SaveToFile()


mc_minus = Template("zmumuj_mc2012_minus")
mc_minus.SetSelCut(selcut + zmumu)
mc_minus.AddTree(zmumuj_mc2012.MUt)
mc_minus.AddTree(zmumuj_mc2012.MDt)
mc_minus.AddVars(variables)
mc_minus.AddVars(jetvars)
mc_minus.Add2DVars(vars2d)
mc_minus.ApplyCut()
mc_minus.FillVars()
#mc.SaveToFile()


mc_plus = Template("zmumuj_mc2012_plus")
mc_plus.SetSelCut(selcut_plus + zmumu)
mc_plus.AddTree(zmumuj_mc2012.MUt)
mc_plus.AddTree(zmumuj_mc2012.MDt)
mc_plus.AddVars(plusvariables)
mc_plus.AddVars(plusjetvars)
mc_plus.Add2DVars(vars2d)
mc_plus.ApplyCut()
mc_plus.FillVars()

mc = Template("zmumuj_mc2012", mc_plus, mc_minus)
mc.SaveToFile()

jetiso_corr = GetWeightHist("jetiso_corr", data.GetVar("JetIso").GetHist(), mc.GetVar("JetIso").GetHist())

#corrections only meaningful at large values
for i in range(jetiso_corr.GetXaxis().FindBin(0.8) + 1):
    jetiso_corr.SetBinContent(i, 1.0)

outputF = TFile("jetiso_corr.root", "RECREATE")
jetiso_corr.Write("jetiso_corr")
outputF.Close()
