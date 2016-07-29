from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *
from math import *

def GetAcceptance(name, numerator, denominator, common):
    asymm = numerator.Clone(name)
    asymm.Divide(denominator)
    #calculate error correctly to take into account common events
    # i.e. acceptance = (a+b)/(a+c)
    #df/da = (c-b)/(a+c)^2
    #df/db = (a+c)/(a+c)^2
    #df/dc = -(a+b)/(a+c)^2
    for i in range(asymm.GetNbinsX()):
        a = common.GetBinContent(i+1)
        b = numerator.GetBinContent(i+1) - a
        c = denominator.GetBinContent(i+1) - a
        print a, b, c
        err = sqrt(pow(sqrt(a)*(c - b)/pow(a+c,2),2) + pow(sqrt(b)*(a+c)/pow(a+c,2),2)
                   + pow(sqrt(c) * (a+b)/pow(a+c,2),2))
        asymm.SetBinError(i+1, err)
    return asymm


zmupj_mc2012 = Template("zmupj_jmu_mc2012")
zmupj_mc2012.SetSelCut(selcut_zmumu_base_p + ip_plus + mupjpt)
zmupj_mc2012.AddTree(zmumuj_mc2012.MUt)
zmupj_mc2012.AddTree(zmumuj_mc2012.MDt)
zmupj_mc2012.AddVars(plusvariables)
zmupj_mc2012.AddVars(plusjetvars)
zmupj_mc2012.Run()
#zmupj.SaveToFile()

zmumj_mc2012 = Template("zmumj_jmu_mc2012")
zmumj_mc2012.SetSelCut(selcut_zmumu_base_m + ip + mumjpt)
zmumj_mc2012.AddTree(zmumuj_mc2012.MUt)
zmumj_mc2012.AddTree(zmumuj_mc2012.MDt)
zmumj_mc2012.AddVars(variables)
zmumj_mc2012.AddVars(jetvars)
zmumj_mc2012.Run()
#zmumj.SaveToFile()


zmupj_mc2012_mu = Template("zmupj_mu_mc2012")
zmupj_mc2012_mu.SetSelCut(selcut_zmumu_base_p + ip_plus + mupjpt_nojet)
zmupj_mc2012_mu.AddTree(zmumuj_mc2012.MUt)
zmupj_mc2012_mu.AddTree(zmumuj_mc2012.MDt)
zmupj_mc2012_mu.AddVars(plusvariables)
zmupj_mc2012_mu.AddVars(plusjetvars)
zmupj_mc2012_mu.Run()
#zmupj.SaveToFile()

zmumj_mc2012_mu = Template("zmumj_mu_mc2012")
zmumj_mc2012_mu.SetSelCut(selcut_zmumu_base_m + ip + mumjpt_nojet)
zmumj_mc2012_mu.AddTree(zmumuj_mc2012.MUt)
zmumj_mc2012_mu.AddTree(zmumuj_mc2012.MDt)
zmumj_mc2012_mu.AddVars(variables)
zmumj_mc2012_mu.AddVars(jetvars)
zmumj_mc2012_mu.Run()
#zmumj.SaveToFile()

zmupj_mc2012_all = Template("zmupj_all_mc2012")
zmupj_mc2012_all.SetSelCut(selcut_zmumu_base_p + ip_plus + mupjpt_nojet + mupjpt)
zmupj_mc2012_all.AddTree(zmumuj_mc2012.MUt)
zmupj_mc2012_all.AddTree(zmumuj_mc2012.MDt)
zmupj_mc2012_all.AddVars(plusvariables)
zmupj_mc2012_all.AddVars(plusjetvars)
zmupj_mc2012_all.Run()
#zmupj.SaveToFile()

zmumj_mc2012_all = Template("zmumj_all_mc2012")
zmumj_mc2012_all.SetSelCut(selcut_zmumu_base_m + ip + mumjpt_nojet + mumjpt)
zmumj_mc2012_all.AddTree(zmumuj_mc2012.MUt)
zmumj_mc2012_all.AddTree(zmumuj_mc2012.MDt)
zmumj_mc2012_all.AddVars(variables)
zmumj_mc2012_all.AddVars(jetvars)
zmumj_mc2012_all.Run()
#zmumj.SaveToFile()


zmupj_data2012 = Template("zmupj_jmu_data2012")
zmupj_data2012.SetSelCut(selcut_zmumu_base_p + ip_plus + mupjpt)
zmupj_data2012.AddTree(zmumuj.MUt)
zmupj_data2012.AddTree(zmumuj.MDt)
zmupj_data2012.AddVars(plusvariables)
zmupj_data2012.AddVars(plusjetvars)
zmupj_data2012.Run()
#zmupj.SaveToFile()

zmumj_data2012 = Template("zmumj_jmu_data2012")
zmumj_data2012.SetSelCut(selcut_zmumu_base_m + ip + mumjpt)
zmumj_data2012.AddTree(zmumuj.MUt)
zmumj_data2012.AddTree(zmumuj.MDt)
zmumj_data2012.AddVars(variables)
zmumj_data2012.AddVars(jetvars)
zmumj_data2012.Run()
#zmumj.SaveToFile()


zmupj_data2012_mu = Template("zmupj_mu_data2012")
zmupj_data2012_mu.SetSelCut(selcut_zmumu_base_p + ip_plus + mupjpt_nojet)
zmupj_data2012_mu.AddTree(zmumuj.MUt)
zmupj_data2012_mu.AddTree(zmumuj.MDt)
zmupj_data2012_mu.AddVars(plusvariables)
zmupj_data2012_mu.AddVars(plusjetvars)
zmupj_data2012_mu.Run()
#zmupj.SaveToFile()

zmumj_data2012_mu = Template("zmumj_mu_data2012")
zmumj_data2012_mu.SetSelCut(selcut_zmumu_base_m + ip + mumjpt_nojet)
zmumj_data2012_mu.AddTree(zmumuj.MUt)
zmumj_data2012_mu.AddTree(zmumuj.MDt)
zmumj_data2012_mu.AddVars(variables)
zmumj_data2012_mu.AddVars(jetvars)
zmumj_data2012_mu.Run()
#zmumj.SaveToFile()

zmupj_data2012_all = Template("zmupj_all_data2012")
zmupj_data2012_all.SetSelCut(selcut_zmumu_base_p + ip_plus + mupjpt_nojet + mupjpt)
zmupj_data2012_all.AddTree(zmumuj.MUt)
zmupj_data2012_all.AddTree(zmumuj.MDt)
zmupj_data2012_all.AddVars(plusvariables)
zmupj_data2012_all.AddVars(plusjetvars)
zmupj_data2012_all.Run()
#zmupj.SaveToFile()

zmumj_data2012_all = Template("zmumj_all_data2012")
zmumj_data2012_all.SetSelCut(selcut_zmumu_base_m + ip + mumjpt_nojet + mumjpt)
zmumj_data2012_all.AddTree(zmumuj.MUt)
zmumj_data2012_all.AddTree(zmumuj.MDt)
zmumj_data2012_all.AddVars(variables)
zmumj_data2012_all.AddVars(jetvars)
zmumj_data2012_all.Run()
#zmumj.SaveToFile()


f = TFile("zj_mc2012_acc.root", "RECREATE")

for var in ['ETA', 'Jet_PT', 'Jet_ETA']:
    p = GetAcceptance(var+'zmupj_acc', zmupj_mc2012_mu.GetVar(var).GetHist(),
                      zmupj_mc2012.GetVar(var).GetHist(), zmupj_mc2012_all.GetVar(var).GetHist())
    m = GetAcceptance(var+'zmumj_acc', zmumj_mc2012_mu.GetVar(var).GetHist(),
                      zmumj_mc2012.GetVar(var).GetHist(), zmumj_mc2012_all.GetVar(var).GetHist())
    p.Write(var+'_acc_plus')
    m.Write(var+'_acc_minus')

f.Close()

f = TFile("zj_data2012_acc.root", "RECREATE")

for var in ['ETA', 'Jet_PT', 'Jet_ETA']:
    p = GetAcceptance(var+'zmupj_acc', zmupj_data2012_mu.GetVar(var).GetHist(),
                      zmupj_data2012.GetVar(var).GetHist(), zmupj_data2012_all.GetVar(var).GetHist())
    m = GetAcceptance(var+'zmumj_acc', zmumj_data2012_mu.GetVar(var).GetHist(),
                      zmumj_data2012.GetVar(var).GetHist(), zmumj_data2012_all.GetVar(var).GetHist())
    p.Write(var+'_acc_plus')
    m.Write(var+'_acc_minus')

f.Close()
