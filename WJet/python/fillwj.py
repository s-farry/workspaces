from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *

vars2d = [ ['Jet_PT', 'JetPtIso'], ['Jet_PT', 'JetEIso']]

#get corrections
f = TFile("jetiso_corr.root")
jetiso_corr = f.Get("jetiso_corr")
g = TFile("qcd_corr.root")
qcd_ptmuj_corr_plus      = g.Get("qcd_ptmujcorr_antiiso_plus")
qcd_etaptmuj_corr_plus   = g.Get("qcd_etaptmujcorr_antiiso_plus")
qcd_ptmuj_corr_plus_ptj0 = g.Get("qcd_mujptcorr_antiiso_plus_ptj0")
qcd_ptmuj_corr_plus_ptj1 = g.Get("qcd_mujptcorr_antiiso_plus_ptj1")
qcd_ptmuj_corr_plus_ptj2 = g.Get("qcd_mujptcorr_antiiso_plus_ptj2")
qcd_ptmuj_corr_plus_ptj3 = g.Get("qcd_mujptcorr_antiiso_plus_ptj3")
qcd_ptmuj_corr_plus_ptj4 = g.Get("qcd_mujptcorr_antiiso_plus_ptj4")

qcd_ptmuj_corr_minus      = g.Get("qcd_ptmujcorr_antiiso_minus")
qcd_etaptmuj_corr_minus   = g.Get("qcd_etaptmujcorr_antiiso_minus")
qcd_ptmuj_corr_minus_ptj0 = g.Get("qcd_mujptcorr_antiiso_minus_ptj0")
qcd_ptmuj_corr_minus_ptj1 = g.Get("qcd_mujptcorr_antiiso_minus_ptj1")
qcd_ptmuj_corr_minus_ptj2 = g.Get("qcd_mujptcorr_antiiso_minus_ptj2")
qcd_ptmuj_corr_minus_ptj3 = g.Get("qcd_mujptcorr_antiiso_minus_ptj3")
qcd_ptmuj_corr_minus_ptj4 = g.Get("qcd_mujptcorr_antiiso_minus_ptj4")


wmupj = AnalysisClass("wmupj")
wmupj.SetSelCut(selcut + plus)
wmupj.AddData("Data", wmuj.MUt)
wmupj.GetTemplate("Data").AddTree(wmuj.MDt)
wmupj.AddTemplate("w", wmuj_mc2012.MUt, kYellow)
wmupj.GetTemplate("w").AddTree(wmuj_mc2012.MDt)
wmupj.AddTemplate("w_nocorr", wmuj_mc2012.MUt, kYellow)
wmupj.GetTemplate("w_nocorr").AddTree(wmuj_mc2012.MDt)
#wmupj.AddTemplate("z", zmuj_mc2012.MUt, kYellow)
#wmupj.GetTemplate("z").AddTree(zmuj_mc2012.MDt)
wmupj.AddTemplate("qcd", wmuj.MUt, selcut_base + antimumjpt + plus, kBlue)
wmupj.GetTemplate("qcd").AddTree(wmuj.MDt)
'''
wmupj.AddTemplate("qcd_jetpt0corr", wmuj.MUt, selcut_base + antimumjpt + plus, kBlue)
wmupj.GetTemplate("qcd_jetpt0corr").AddTree(wmuj.MDt)
wmupj.AddTemplate("qcd_jetpt1corr", wmuj.MUt, selcut_base + antimumjpt + plus, kBlue)
wmupj.GetTemplate("qcd_jetpt1corr").AddTree(wmuj.MDt)
wmupj.AddTemplate("qcd_jetpt2corr", wmuj.MUt, selcut_base + antimumjpt + plus, kBlue)
wmupj.GetTemplate("qcd_jetpt2corr").AddTree(wmuj.MDt)
wmupj.AddTemplate("qcd_jetpt3corr", wmuj.MUt, selcut_base + antimumjpt + plus, kBlue)
wmupj.GetTemplate("qcd_jetpt3corr").AddTree(wmuj.MDt)
wmupj.AddTemplate("qcd_jetpt4corr", wmuj.MUt, selcut_base + antimumjpt + plus, kBlue)
wmupj.GetTemplate("qcd_jetpt4corr").AddTree(wmuj.MDt)
wmupj.AddTemplate("qcd_nocorr", wmuj.MUt, selcut_base + antimumjpt + plus, kBlue)
wmupj.GetTemplate("qcd_nocorr").AddTree(wmuj.MDt)
'''
#wmupj.AddTemplate("qcd_hiip", wmuj.MUt, selcut_base + hi_ip + plus, kBlue)
#wmupj.GetTemplate("qcd_hiip").AddTree(wmuj.MDt)
#corrections
wmupj.GetTemplate("w").Reweight("muminus_PT/muminus_sigjet_PT", jetiso_corr)
#wmupj.GetTemplate("z").Reweight("muminus_PT/muminus_sigjet_PT", jetiso_corr)
#wmupj.GetTemplate("qcd_1dcorr").Reweight(jetpt_e, qcd_corr_plus)
'''
wmupj.GetTemplate("qcd_jetpt0corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_plus_ptj0)
wmupj.GetTemplate("qcd_jetpt1corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_plus_ptj1)
wmupj.GetTemplate("qcd_jetpt2corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_plus_ptj2)
wmupj.GetTemplate("qcd_jetpt3corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_plus_ptj3)
wmupj.GetTemplate("qcd_jetpt4corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_plus_ptj4)
#wmupj.GetTemplate("qcd_1dcorr").Reweight("muminus_PT", qcd_corr_plus)
'''
#wmupj.GetTemplate("qcd").Reweight("muminus_ETA", "muminus_sigjet_PT", qcd_etaptmuj_corr_plus)
wmupj.AddVars(variables)
wmupj.AddVars(jetvars)
wmupj.Add2DVars(vars2d)
wmupj.Run()
wmupj.StyleTemplates()
wmupj.SaveToFile()

########################################################################
#
#
# W minus
#
#
########################################################################

wmumj = AnalysisClass("wmumj")
wmumj.SetSelCut(selcut + minus)
wmumj.AddData("Data", wmuj.MUt)
wmumj.GetTemplate("Data").AddTree(wmuj.MDt)
wmumj.AddTemplate("w", wmuj_mc2012.MUt, kYellow)
wmumj.GetTemplate("w").AddTree(wmuj_mc2012.MDt)
wmumj.AddTemplate("w_nocorr", wmuj_mc2012.MUt, kYellow)
wmumj.GetTemplate("w_nocorr").AddTree(wmuj_mc2012.MDt)
#wmumj.AddTemplate("z", zmuj_mc2012.MUt, kYellow)
#wmumj.GetTemplate("z").AddTree(zmuj_mc2012.MDt)
wmumj.AddTemplate("qcd", wmuj.MUt, selcut_base + antimumjpt + minus, kBlue)
wmumj.GetTemplate("qcd").AddTree(wmuj.MDt)
'''
wmumj.AddTemplate("qcd_jetpt0corr", wmuj.MUt, selcut_base + antimumjpt + minus, kBlue)
wmumj.GetTemplate("qcd_jetpt0corr").AddTree(wmuj.MDt)
wmumj.AddTemplate("qcd_jetpt1corr", wmuj.MUt, selcut_base + antimumjpt + minus, kBlue)
wmumj.GetTemplate("qcd_jetpt1corr").AddTree(wmuj.MDt)
wmumj.AddTemplate("qcd_jetpt2corr", wmuj.MUt, selcut_base + antimumjpt + minus, kBlue)
wmumj.GetTemplate("qcd_jetpt2corr").AddTree(wmuj.MDt)
wmumj.AddTemplate("qcd_jetpt3corr", wmuj.MUt, selcut_base + antimumjpt + minus, kBlue)
wmumj.GetTemplate("qcd_jetpt3corr").AddTree(wmuj.MDt)
wmumj.AddTemplate("qcd_jetpt4corr", wmuj.MUt, selcut_base + antimumjpt + minus, kBlue)
wmumj.GetTemplate("qcd_jetpt4corr").AddTree(wmuj.MDt)
wmumj.AddTemplate("qcd_nocorr", wmuj.MUt, selcut_base + antimumjpt + minus, kBlue)
wmumj.GetTemplate("qcd_nocorr").AddTree(wmuj.MDt)
'''
#wmumj.AddTemplate("qcd_hiip", wmuj.MUt, selcut_base + hi_ip + minus, kBlue)
#wmumj.GetTemplate("qcd_hiip").AddTree(wmuj.MDt)
#corrections
wmumj.GetTemplate("w").Reweight("muminus_PT/muminus_sigjet_PT", jetiso_corr)
#wmumj.GetTemplate("z").Reweight("muminus_PT/muminus_sigjet_PT", jetiso_corr)
#wmumj.GetTemplate("qcd_1dcorr").Reweight(jetpt_e, qcd_corr_minus)
'''
wmumj.GetTemplate("qcd_jetpt0corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_minus_ptj0)
wmumj.GetTemplate("qcd_jetpt1corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_minus_ptj1)
wmumj.GetTemplate("qcd_jetpt2corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_minus_ptj2)
wmumj.GetTemplate("qcd_jetpt3corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_minus_ptj3)
wmumj.GetTemplate("qcd_jetpt4corr").Reweight("muminus_sigjet_PT", qcd_ptmuj_corr_minus_ptj4)
'''
#wmumj.GetTemplate("qcd_1dcorr").Reweight("muminus_PT", qcd_corr_minus)
#wmumj.GetTemplate("qcd").Reweight("muminus_ETA", "muminus_sigjet_PT", qcd_etaptmuj_corr_minus)
wmumj.AddVars(variables)
wmumj.AddVars(jetvars)
wmumj.Add2DVars(vars2d)
wmumj.Run()
wmumj.StyleTemplates()
wmumj.SaveToFile()


wmupj_nomujet = AnalysisClass("wmupj_nomujet")
wmupj_nomujet.SetSelCut(selcut_base + ip + mumjpt_nojet + plus)
wmupj_nomujet.AddData("Data", wmuj.MUt)
wmupj_nomujet.GetTemplate("Data").AddTree(wmuj.MDt)
wmupj_nomujet.AddTemplate("w", wmuj_mc2012.MUt, kYellow)
wmupj_nomujet.GetTemplate("w").AddTree(wmuj_mc2012.MDt)
wmupj_nomujet.AddTemplate("w_nocorr", wmuj_mc2012.MUt, kYellow)
wmupj_nomujet.GetTemplate("w_nocorr").AddTree(wmuj_mc2012.MDt)
#wmup_nomujetj.AddTemplate("z", zmuj_mc2012.MUt, kYellow)
#wmup_nomujetj.GetTemplate("z").AddTree(zmuj_mc2012.MDt)
wmupj_nomujet.AddTemplate("qcd", wmuj.MUt, selcut_base + antimumjpt_nojet + plus, kBlue)
wmupj_nomujet.GetTemplate("qcd").AddTree(wmuj.MDt)
wmupj_nomujet.GetTemplate("w").Reweight("muminus_PT/muminus_sigjet_PT", jetiso_corr)
#wmupj_nomujet.GetTemplate("qcd").Reweight("muminus_ETA", "muminus_sigjet_PT", qcd_etaptmuj_corr_plus)
wmupj_nomujet.AddVars(variables)
wmupj_nomujet.AddVars(jetvars)
wmupj_nomujet.Add2DVars(vars2d)
wmupj_nomujet.Run()
wmupj_nomujet.StyleTemplates()
wmupj_nomujet.SaveToFile()


wmumj_nomujet = AnalysisClass("wmumj_nomujet")
wmumj_nomujet.SetSelCut(selcut_base + ip + mumjpt_nojet + minus)
wmumj_nomujet.AddData("Data", wmuj.MUt)
wmumj_nomujet.GetTemplate("Data").AddTree(wmuj.MDt)
wmumj_nomujet.AddTemplate("w", wmuj_mc2012.MUt, kYellow)
wmumj_nomujet.GetTemplate("w").AddTree(wmuj_mc2012.MDt)
wmumj_nomujet.AddTemplate("w_nocorr", wmuj_mc2012.MUt, kYellow)
wmumj_nomujet.GetTemplate("w_nocorr").AddTree(wmuj_mc2012.MDt)
#wmup_nomujetj.AddTemplate("z", zmuj_mc2012.MUt, kYellow)
#wmup_nomujetj.GetTemplate("z").AddTree(zmuj_mc2012.MDt)
wmumj_nomujet.AddTemplate("qcd", wmuj.MUt, selcut_base + antimumjpt_nojet + plus, kBlue)
wmumj_nomujet.GetTemplate("qcd").AddTree(wmuj.MDt)
wmumj_nomujet.GetTemplate("w").Reweight("muminus_PT/muminus_sigjet_PT", jetiso_corr)
#wmumj_nomujet.GetTemplate("qcd").Reweight("muminus_ETA", "muminus_sigjet_PT", qcd_etaptmuj_corr_plus)
wmumj_nomujet.AddVars(variables)
wmumj_nomujet.AddVars(jetvars)
wmumj_nomujet.Add2DVars(vars2d)
wmumj_nomujet.Run()
wmumj_nomujet.StyleTemplates()
wmumj_nomujet.SaveToFile()
