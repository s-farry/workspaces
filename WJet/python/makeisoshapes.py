from os import sys
from analysis import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *

wmupj = AnalysisClass("wmupj")
wmupj.SetSelCut(selcut + ptj20 + plus)
wmupj.SetData("Data", datat)
wmupj.AddTemplate("w", wmumct, kYellow)
wmupj.AddTemplate("qcd", datat, selcut_ptunbal + plus + ptj20, kBlue)
wmupj.GetTemplate("qcd").Reweight("muminus_sigjet_PT", qcd_pj_rw)
#wmupj.GetTemplate("w").Reweight("muminus_PT", isoshape_rw )
wmupj.AddVars(variables)
wmupj.AddVars(jetvars)
wmupj.Add2DVars(vars2d)
wmupj.ApplyCuts()
wmupj.FillVars()
#merge z->mumu samples to produce w sample
wmupj.ApplyStyles()
wmupj.SaveToFile()

########################################################################
#
#
# W minus
#
#
########################################################################

wmumj = AnalysisClass("wmumj")
wmumj.SetSelCut(selcut + ptj20 + minus)
wmumj.SetData("Data", datat)
wmumj.AddTemplate("w", wmumct, kYellow)
wmumj.AddTemplate("qcd", datat, selcut_ptunbal + minus + ptj20, kBlue)
wmumj.GetTemplate("qcd").Reweight("muminus_sigjet_PT", qcd_pj_rw)
#wmumj.GetTemplate("w").Reweight("muminus_PT", isoshape_rw )
wmumj.AddVars(variables)
wmumj.AddVars(jetvars)
wmumj.Add2DVars(vars2d)
wmumj.ApplyCuts()
wmumj.FillVars()
#merge z->mumu samples to produce w sample
wmumj.ApplyStyles()
wmumj.SaveToFile()
