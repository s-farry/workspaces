
from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas, TMath

from Wjconfig_new import *

#f = TFile("/hepstore/sfarry/GridOutput/1120/Zmumujet.Z_mumujet17.MU.MC2012.root")
#g = TFile("/hepstore/sfarry/GridOutput/1121/Zmumujet.Z_mumujet17.MD.MC2012.root")
#h = TFile("/hepstore/sfarry/GridOutput/1116/Wmujet.Wmunujet.MU.MC2012.root")
#i = TFile("/hepstore/sfarry/GridOutput/1117/Wmujet.Wmunujet.MD.MC2012.root")
#j = TFile("/hepstore/sfarry/GridOutput/1118/Wmujet.Z_mumujet17.MU.MC2012.root")
#k = TFile("/hepstore/sfarry/GridOutput/1119/Wmujet.Z_mumujet17.MD.MC2012.root")

#f = TFile("/hepstore/sfarry/GridOutput/1171/Zmumujet.Z_mumujet17.MU.MC2012.root")
#g = TFile("/hepstore/sfarry/GridOutput/1172/Zmumujet.Z_mumujet17.MD.MC2012.root")
#h = TFile("/hepstore/sfarry/GridOutput/1173/Wmujet.Wmunujet.MU.MC2012.root")
#i = TFile("/hepstore/sfarry/GridOutput/1174/Wmujet.Wmunujet.MD.MC2012.root")
#j = TFile("/hepstore/sfarry/GridOutput/1175/Wmujet.Z_mumujet17.MU.MC2012.root")
#k = TFile("/hepstore/sfarry/GridOutput/1176/Wmujet.Z_mumujet17.MD.MC2012.root")

#most up-to-date files, just using here for now in case
f = TFile.Open(dpm_loc+"/Zmumujet_new.Z_mumujet17.MU.MC2012.root")
g = TFile.Open(dpm_loc+"/Zmumujet_new.Z_mumujet17.MD.MC2012.root")
h = TFile.Open(dpm_loc+"/Wmujet_new.Wmunujet.MU.MC2012.root")
i = TFile.Open(dpm_loc+"/Wmujet_new.Wmunujet.MD.MC2012.root")
j = TFile.Open(dpm_loc+"/Wmujet_new.Z_mumujet17.MU.MC2012.root")
k = TFile.Open(dpm_loc+"/Wmujet_new.Z_mumujet17.MD.MC2012.root")


t = f.Get("ZMuMu/DecayTree")
u = g.Get("ZMuMu/DecayTree")
v = h.Get("WTuple/DecayTree")
w = i.Get("WTuple/DecayTree")
x = j.Get("WTuple/DecayTree")
y = k.Get("WTuple/DecayTree")

#all should be consecutive
'''
wmu_receff = EfficiencyClass("wmu_receff")
wmu_receff.SetSelectionCut(selcut_murec + ptmcj20)
wmu_receff.SetPassCut(muonVeto + Ep + tthits)
wmu_receff.SetTree(t)
wmu_receff.AddVars(mcjetvars)
wmu_receff.SetPltRange("muminus_mcjet_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
wmu_receff.MakeEntryLists()
wmu_receff.MakeHists()
wmu_receff.MakeEfficiencyGraph()
wmu_receff.SaveToFile()

wmu_ipeff = EfficiencyClass("wmu_ipeff")
wmu_ipeff.SetSelectionCut(selcut_murec + muonVeto + Ep + tthits + ptmcj20)
wmu_ipeff.SetPassCut(ip)
wmu_ipeff.SetTree(t)
wmu_ipeff.AddVars(mcjetvars)
wmu_ipeff.SetPltRange("muminus_mcjet_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
wmu_ipeff.MakeEntryLists()
wmu_ipeff.MakeHists()
wmu_ipeff.MakeEfficiencyGraph()
wmu_ipeff.SaveToFile()
'''
wmup_jeteff = EfficiencyClass("wmup_jeteff")
wmup_jeteff.SetSelectionCut(selcut_base_nojet + ptmcj20 + mumjpt_true + plus)
wmup_jeteff.SetPassCut(TCut("muminus_rectruejet_PT > 12500"))
#wmup_jeteff.AddTree(wmuj_mc2012.MUt)
#wmup_jeteff.AddTree(wmuj_mc2012.MDt)
wmup_jeteff.AddTree(v)
wmup_jeteff.AddTree(w)
wmup_jeteff.AddVars(mcjetvars)
wmup_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
wmup_jeteff.MakeEntryLists()
wmup_jeteff.MakeHists()
wmup_jeteff.MakeEfficiencyGraph()
wmup_jeteff.SaveToFile()

wmum_jeteff = EfficiencyClass("wmum_jeteff")
wmum_jeteff.SetSelectionCut(selcut_base_nojet + ptmcj20 + mumjpt_true + minus )
wmum_jeteff.SetPassCut(TCut("muminus_rectruejet_PT > 12500"))
#wmum_jeteff.AddTree(wmuj_mc2012.MUt)
#wmum_jeteff.AddTree(wmuj_mc2012.MDt)
wmum_jeteff.AddTree(v)
wmum_jeteff.AddTree(w)
wmum_jeteff.AddVars(mcjetvars)
wmum_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
wmum_jeteff.MakeEntryLists()
wmum_jeteff.MakeHists()
wmum_jeteff.MakeEfficiencyGraph()
wmum_jeteff.SaveToFile()

zmumu_jeteff = EfficiencyClass("zmumu_jeteff")
zmumu_jeteff.SetSelectionCut(selcut_zmumu_nojet + ptmcj20_zmumu)
zmumu_jeteff.SetPassCut(TCut("boson_rectruejet_PT > 12500"))
#zmumu_jeteff.AddTree(zmumuj_mc2012.MUt)
#zmumu_jeteff.AddTree(zmumuj_mc2012.MDt)
zmumu_jeteff.AddTree(t)
zmumu_jeteff.AddTree(u)
zmumu_jeteff.AddVars(mcjetvars_zmumu)
zmumu_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmumu_jeteff.MakeEntryLists()
zmumu_jeteff.MakeHists()
zmumu_jeteff.MakeEfficiencyGraph()
zmumu_jeteff.SaveToFile()

zmum_jeteff = EfficiencyClass("zmum_jeteff")
zmum_jeteff.SetSelectionCut(selcut_zmumu_nojet_m + ptmcj20)
zmum_jeteff.SetPassCut(TCut("muminus_rectruejet_PT > 12500"))
#zmum_jeteff.AddTree(zmumuj_mc2012.MUt)
#zmum_jeteff.AddTree(zmumuj_mc2012.MDt)
zmum_jeteff.AddTree(t)
zmum_jeteff.AddTree(u)
zmum_jeteff.AddVars(mcjetvars_zmumu)
zmum_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmum_jeteff.MakeEntryLists()
zmum_jeteff.MakeHists()
zmum_jeteff.MakeEfficiencyGraph()
zmum_jeteff.SaveToFile()

zmup_jeteff = EfficiencyClass("zmup_jeteff")
zmup_jeteff.SetSelectionCut(selcut_zmumu_nojet_p + ptmcj20)
zmup_jeteff.SetPassCut(TCut("muplus_rectruejet_PT > 12500"))
#zmup_jeteff.AddTree(zmumuj_mc2012.MUt)
#zmup_jeteff.AddTree(zmumuj_mc2012.MDt)
zmup_jeteff.AddTree(t)
zmup_jeteff.AddTree(u)
zmup_jeteff.AddVars(mcjetvars_zmumu)
zmup_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmup_jeteff.MakeEntryLists()
zmup_jeteff.MakeHists()
zmup_jeteff.MakeEfficiencyGraph()
zmup_jeteff.SaveToFile()

zaswmup_jeteff = EfficiencyClass("zaswmup_jeteff")
zaswmup_jeteff.SetSelectionCut(selcut_base_nojetnoveto + ptmcj20 + mumjpt_true + plus)
zaswmup_jeteff.SetPassCut(TCut("muminus_rectruejet_PT > 12500"))
#zaswmup_jeteff.AddTree(zaswmuj_mc2012.MUt)
#zaswmup_jeteff.AddTree(zaswmuj_mc2012.MDt)
zaswmup_jeteff.AddTree(x)
zaswmup_jeteff.AddTree(y)
zaswmup_jeteff.AddVars(mcjetvars)
zaswmup_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zaswmup_jeteff.MakeEntryLists()
zaswmup_jeteff.MakeHists()
zaswmup_jeteff.MakeEfficiencyGraph()
zaswmup_jeteff.SaveToFile()

zaswmum_jeteff = EfficiencyClass("zaswmum_jeteff")
zaswmum_jeteff.SetSelectionCut(selcut_base_nojetnoveto + ptmcj20 + mumjpt_true + minus )
zaswmum_jeteff.SetPassCut(TCut("muminus_rectruejet_PT > 12500"))
#zaswmum_jeteff.AddTree(zaswmuj_mc2012.MUt)
#zaswmum_jeteff.AddTree(zaswmuj_mc2012.MDt)
zaswmum_jeteff.AddTree(x)
zaswmum_jeteff.AddTree(y)
zaswmum_jeteff.AddVars(mcjetvars)
zaswmum_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zaswmum_jeteff.MakeEntryLists()
zaswmum_jeteff.MakeHists()
zaswmum_jeteff.MakeEfficiencyGraph()
zaswmum_jeteff.SaveToFile()


zmumu_1PV_jeteff = EfficiencyClass("zmumu_1PV_jeteff")
zmumu_1PV_jeteff.SetSelectionCut(selcut_zmumu_nojet + ptmcj20_zmumu + TCut("nPVs == 1"))
zmumu_1PV_jeteff.SetPassCut(TCut("boson_rectruejet_PT > 12500"))
zmumu_1PV_jeteff.AddTree(t)
zmumu_1PV_jeteff.AddTree(u)
zmumu_1PV_jeteff.AddVars(mcjetvars_zmumu)
zmumu_1PV_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmumu_1PV_jeteff.MakeEntryLists()
zmumu_1PV_jeteff.MakeHists()
zmumu_1PV_jeteff.MakeEfficiencyGraph()
zmumu_1PV_jeteff.SaveToFile()

zmumu_truemuons_jeteff = EfficiencyClass("zmumu_truemuons_jeteff")
zmumu_truemuons_jeteff.SetSelectionCut(selcut_zmumu_nojet + ptmcj20_zmumu + TCut("muminus_TRUEID==13") + TCut("muplus_TRUEID == -13"))
zmumu_truemuons_jeteff.SetPassCut(TCut("boson_rectruejet_PT > 12500"))
zmumu_truemuons_jeteff.AddTree(t)
zmumu_truemuons_jeteff.AddTree(u)
zmumu_truemuons_jeteff.AddVars(mcjetvars_zmumu)
zmumu_truemuons_jeteff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmumu_truemuons_jeteff.MakeEntryLists()
zmumu_truemuons_jeteff.MakeHists()
zmumu_truemuons_jeteff.MakeEfficiencyGraph()
zmumu_truemuons_jeteff.SaveToFile()

