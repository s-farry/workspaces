
from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas, TMath

from Wjconfig_new import *
'''
wmup_fakerate = EfficiencyClass("wmup_fakerate")
wmup_fakerate.SetSelectionCut(selcut_base_nojet + ptj20 + plus)
wmup_fakerate.SetPassCut(TCut("muminus_mcjet_PT < 12500"))
wmup_fakerate.AddTree(wmuj_mc2012.MUt)
wmup_fakerate.AddTree(wmuj_mc2012.MDt)
wmup_fakerate.AddVars(jetvars)
wmup_fakerate.AddVars(variables)
wmup_fakerate.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
wmup_fakerate.MakeEntryLists()
wmup_fakerate.MakeHists()
wmup_fakerate.MakeEfficiencyGraph()
wmup_fakerate.SaveToFile()

wmum_fakerate = EfficiencyClass("wmum_fakerate")
wmum_fakerate.SetSelectionCut(selcut_base_nojet + ptj20 + minus )
wmum_fakerate.SetPassCut(TCut("muminus_mcjet_PT < 12500"))
wmum_fakerate.AddTree(wmuj_mc2012.MUt)
wmum_fakerate.AddTree(wmuj_mc2012.MDt)
wmum_fakerate.AddVars(jetvars)
wmum_fakerate.AddVars(variables)
wmum_fakerate.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
wmum_fakerate.MakeEntryLists()
wmum_fakerate.MakeHists()
wmum_fakerate.MakeEfficiencyGraph()
wmum_fakerate.SaveToFile()


f = TFile("/hepstore/sfarry/GridOutput/1020/Zmumujet.Z_mumujet17.MU.MC2012.root")
g = TFile("/hepstore/sfarry/GridOutput/1021/Zmumujet.Z_mumujet17.MD.MC2012.root")
t = f.Get("ZMuMu/DecayTree")
u = g.Get("ZMuMu/DecayTree")

zmumu_fakerate = EfficiencyClass("zmumu_fakerate")
zmumu_fakerate.SetSelectionCut(selcut_zmumu_nojet + ptj20_zmumu)
zmumu_fakerate.SetPassCut(TCut("boson_mcjet_PT < 12500"))
#zmumu_fakerate.AddTree(zmumuj_mc2012.MUt)
#zmumu_fakerate.AddTree(zmumuj_mc2012.MDt)
zmumu_fakerate.AddTree(t)
zmumu_fakerate.AddTree(u)
zmumu_fakerate.AddVars(zvars)
zmumu_fakerate.AddVars(jetvars_zmumu)
zmumu_fakerate.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmumu_fakerate.MakeEntryLists()
zmumu_fakerate.MakeHists()
zmumu_fakerate.MakeEfficiencyGraph()
zmumu_fakerate.SaveToFile()


j = TFile("/user2/sfarry/WJet/python/wmum_fakerate.root")
saveTGraph('/user2/sfarry/WJet/dat/wm_fakerate_ptj.dat', j.Get("Jet_PT/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/wm_fakerate_etaj.dat', j.Get("Jet_ETA/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/wm_fakerate_eta.dat', j.Get("ETA/EfficiencyGraph"))
'''
k = TFile("/user2/sfarry/WJet/python/wmup_fakerate.root")
saveTGraph('/user2/sfarry/WJet/dat/wp_fakerate_ptj.dat', k.Get("Jet_PT/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/wp_fakerate_etaj.dat', k.Get("Jet_ETA/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/wp_fakerate_eta.dat', k.Get("ETA/EfficiencyGraph"))

'''
l = TFile("/user2/sfarry/WJet/python/zmumu_fakerate.root")
saveTGraph('/user2/sfarry/WJet/dat/zmumu_fakerate_ptj.dat', l.Get("Jet_PT/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/zmumu_fakerate_etaj.dat', l.Get("Jet_ETA/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/zmumu_fakerate_y.dat', l.Get("Y/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/zmumu_fakerate_dphi.dat', l.Get("dPhi/EfficiencyGraph"))
'''
