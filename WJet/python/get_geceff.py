
from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *

zmup_geceff = EfficiencyClass("zmup_geceff")
zmup_geceff.SetSelectionCut(selcut_zmumu_dimu_p + selcut_zmumu_pass_p)
zmup_geceff.SetPassCut(TCut("nSPDHits < 600"))
zmup_geceff.AddTree(zmumuj.MUt)
zmup_geceff.AddTree(zmumuj.MDt)
zmup_geceff.AddVars(jetvars)
zmup_geceff.AddVars(evtvars)
zmup_geceff.AddVars(plusvariables)
zmup_geceff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmup_geceff.MakeEntryLists()
zmup_geceff.MakeHists()
zmup_geceff.MakeEfficiencyGraph()
zmup_geceff.SaveToFile()

zmum_geceff = EfficiencyClass("zmum_geceff")
zmum_geceff.SetSelectionCut(selcut_zmumu_dimu_m + selcut_zmumu_pass_m )
zmum_geceff.SetPassCut(TCut("nSPDHits < 600"))
zmum_geceff.AddTree(zmumuj.MUt)
zmum_geceff.AddTree(zmumuj.MDt)
zmum_geceff.AddVars(jetvars)
zmum_geceff.AddVars(evtvars)
zmum_geceff.AddVars(variables)
zmum_geceff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmum_geceff.MakeEntryLists()
zmum_geceff.MakeHists()
zmum_geceff.MakeEfficiencyGraph()
zmum_geceff.SaveToFile()

zmumu_geceff = EfficiencyClass("zmumu_geceff")
zmumu_geceff.SetSelectionCut(selcut_zmumu_dimu)
zmumu_geceff.SetPassCut(TCut("nSPDHits < 600"))
zmumu_geceff.AddTree(zmumuj.MUt)
zmumu_geceff.AddTree(zmumuj.MDt)
zmumu_geceff.AddVars(zvars)
zmumu_geceff.AddVars(evtvars)
zmumu_geceff.SetPltRange("muminus_PHI" , 50 , -TMath.Pi() , TMath.Pi() )
zmumu_geceff.MakeEntryLists()
zmumu_geceff.MakeHists()
zmumu_geceff.MakeEfficiencyGraph()
zmumu_geceff.SaveToFile()

