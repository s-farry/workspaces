from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *

lumi = 1977.9

wmupj_data2012 = Template("wmupj_data2012")
wmupj_data2012.SetSelCut(selcut + plus)
wmupj_data2012.AddTrees(wmuj.trees())
wmupj_data2012.AddVars(variables)
wmupj_data2012.AddVars(jetvars)
wmupj_data2012.ApplyCut()
wmupj_data2012.FillVars()
wmupj_data2012.SaveToFile()

wmumj_data2012 = Template("wmumj_data2012")
wmumj_data2012.SetSelCut(selcut + minus)
wmumj_data2012.AddTrees(wmuj.trees())
wmumj_data2012.AddVars(variables)
wmumj_data2012.AddVars(jetvars)
wmumj_data2012.ApplyCut()
wmumj_data2012.FillVars()
wmumj_data2012.SaveToFile()


wmupj_mc2012 = Template("wmupj_mc2012")
wmupj_mc2012.SetSelCut(selcut + plus)
wmupj_mc2012.AddTrees(wmuj_mc2012.trees())
wmupj_mc2012.AddVars(variables)
wmupj_mc2012.AddVars(jetvars)
wmupj_mc2012.ApplyCut()
wmupj_mc2012.FillVars()
wmupj_mc2012.Scale(lumi/wmujetLumi)
wmupj_mc2012.SaveToFile()

wmumj_mc2012 = Template("wmumj_mc2012")
wmumj_mc2012.SetSelCut(selcut + minus)
wmumj_mc2012.AddTrees(wmuj_mc2012.trees())
wmumj_mc2012.AddVars(variables)
wmumj_mc2012.AddVars(jetvars)
wmumj_mc2012.ApplyCut()
wmumj_mc2012.FillVars()
wmumj_mc2012.Scale(lumi/wmujetLumi)
wmumj_mc2012.SaveToFile()
