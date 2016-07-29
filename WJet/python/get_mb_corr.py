from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *

f = TFile("/hepstore/sfarry/GridOutput/862/WMuJet_MinBias.MD.2012_R14S21.root")
t = f.Get("WTuple/DecayTree")
g = TFile("/hepstore/sfarry/GridOutput/869/WMuJet_MinBias.MU.2012_R14S21.root")
u = f.Get("WTuple/DecayTree")


mb_bal_plus = Template("mbbal_plus_data2012", [t, u], selcut_mb_noep + antimumjpt + plus)
mb_bal_plus.AddVars(variables)
mb_bal_plus.AddVars(jetvars)
mb_bal_plus.Add2DVars(vars2d)
mb_bal_plus.Run()
mb_bal_plus.SaveToFile()

mb_bal_minus = Template("mbbal_minus_data2012", [t, u], selcut_mb_noep + antimumjpt + minus)
mb_bal_minus.AddVars(variables)
mb_bal_minus.AddVars(jetvars)
mb_bal_minus.Add2DVars(vars2d)
mb_bal_minus.Run()
mb_bal_minus.SaveToFile()

mb_bal = Template("mbbal_data2012", mb_bal_plus, mb_bal_minus)
mb_bal.SaveToFile()

mb_unbal_plus = Template("mbunbal_plus_data2012", [t, u], selcut_mb_noep + mumjpt + plus)
mb_unbal_plus.AddVars(variables)
mb_unbal_plus.AddVars(jetvars)
mb_unbal_plus.Add2DVars(vars2d)
mb_unbal_plus.Run()
mb_unbal_plus.SaveToFile()

mb_unbal_minus = Template("mbunbal_minus_data2012", [t, u], selcut_mb_noep + mumjpt + minus)
mb_unbal_minus.AddVars(variables)
mb_unbal_minus.AddVars(jetvars)
mb_unbal_minus.Add2DVars(vars2d)
mb_unbal_minus.Run()
mb_unbal_minus.SaveToFile()

mb_unbal = Template("mbunbal_data2012", mb_unbal_plus, mb_unbal_minus)
mb_unbal.SaveToFile()


#now get weight
plus_rw   = GetWeightHist("mb_corr_plus",   mb_bal_plus.Get2DVar("MuJet_PT", "JetIso").GetHist().ProjectionX("plus_sig", 0, 16) , mb_unbal_plus.GetVar("MuJet_PT").GetHist()      )
minus_rw  = GetWeightHist("mb_corr_minus",  mb_bal_minus.Get2DVar("MuJet_PT", "JetIso").GetHist().ProjectionX("minus_sig", 0,16), mb_unbal_minus.GetVar("MuJet_PT").GetHist()      )

mb_unbal_plus_rw = Template("mbunbal_plus_rw_data2012", [t, u], selcut_mb_noep + antimumjpt + plus)
mb_unbal_plus_rw.AddVars(variables)
mb_unbal_plus_rw.AddVars(jetvars)
mb_unbal_plus_rw.Add2DVars(vars2d)
mb_unbal_plus_rw.Reweight("muminus_sigjet_PT", plus_rw)
mb_unbal_plus_rw.Run()
mb_unbal_plus_rw.SaveToFile()

mb_unbal_minus_rw = Template("mbunbal_minus_rw_data2012", [t, u], selcut_mb_noep + antimumjpt + minus)
mb_unbal_minus_rw.AddVars(variables)
mb_unbal_minus_rw.AddVars(jetvars)
mb_unbal_minus_rw.Add2DVars(vars2d)
mb_unbal_minus_rw.Reweight("muminus_sigjet_PT", minus_rw)
mb_unbal_minus_rw.Run()
mb_unbal_minus_rw.SaveToFile()

mb_unbal_rw = Template("mbunbal_rw_data2012", mb_unbal_plus_rw, mb_unbal_minus_rw)
mb_unbal_rw.SaveToFile()

