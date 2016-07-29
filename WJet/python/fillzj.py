from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *


def save_to_file(name, central, jecup, jecdown, jecmcup, jecmcdown, smear):
    f = open(name,'w')
    for i in range(central.GetNbinsX()):
        f.write("0  ")
    f.write('\n')
    for i in range(central.GetNbinsX()):
        c = central.GetBinContent(i+1)
        u = jecup.GetBinContent(i+1)
        d = jecdown.GetBinContent(i+1)
        f.write(str(max(abs(c-u), abs(c-d))/c) + " ")
    f.write('\n')
    for i in range(central.GetNbinsX()):
        c = central.GetBinContent(i+1)
        u = jecmcup.GetBinContent(i+1)
        d = jecmcdown.GetBinContent(i+1)
        f.write(str(max(abs(c-u), abs(c-d))/c) + " ")
    f.write('\n')
    for i in range(central.GetNbinsX()):
        c = central.GetBinContent(i+1)
        s = smear.GetBinContent(i+1)
        f.write(str(abs(c-s)/c) + " ")
    f.write('\n')
    f.close()

f = TFile("/hepstore/sfarry/GridOutput/801/ZMuMuJet.MD.2012.root")
t = f.Get("ZMuMu/DecayTree")
g = TFile("/hepstore/sfarry/GridOutput/802/ZMuMuJet.MU.2012.root")
u = g.Get("ZMuMu/DecayTree")


# central
zmumuj_data2012 = AnalysisClass("zmumuj")
zmumuj_data2012.SetSelCut(selcut_zmumu_nojet + ptj20_zmumu + select_runs)
zmumuj_data2012.AddData("Data", zmumuj.MUt)
zmumuj_data2012.GetTemplate("Data").AddTree(zmumuj.MDt)
#zmumuj_data2012.AddData("Data", zmumuj.MUt)
#zmumuj_data2012.GetTemplate("Data").AddTree(zmumuj.MDt)
#zmumuj_data2012.AddData("Data", t)
#zmumuj_data2012.GetTemplate("Data").AddTree(u)
#zmumuj_data2012.AddTemplate("z", zmumuj_mc2012.MUt, kYellow)
#zmumuj_data2012.GetTemplate("z").AddTree(zmumuj_mc2012.MDt)
zmumuj_data2012.AddVars(zvars)
zmumuj_data2012.AddVars(jetvars_zmumu)
zmumuj_data2012.Add3DVars(vars3d)
zmumuj_data2012.Run()
zmumuj_data2012.StyleTemplates()
zmumuj_data2012.SaveToFile()


# jec up
ptj20_zmumu_jecup     = TCut("boson_jet_PT_jecup > 20000")
jetvars_zmumu[0][1] = "boson_jet_PT_jecup/1000.0"

zmumuj_data2012_jecup = AnalysisClass("zmumuj_jecup")
zmumuj_data2012_jecup.SetSelCut(selcut_zmumu_nojet + ptj20_zmumu_jecup + select_runs)
zmumuj_data2012_jecup.AddData("Data", zmumuj.MUt)
zmumuj_data2012_jecup.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumuj_data2012_jecup.AddVars(zvars)
zmumuj_data2012_jecup.AddVars(jetvars_zmumu)
zmumuj_data2012_jecup.Add3DVars(vars3d)
zmumuj_data2012_jecup.Run()
zmumuj_data2012_jecup.StyleTemplates()
zmumuj_data2012_jecup.SaveToFile()

# jec down
ptj20_zmumu_jecdown     = TCut("boson_jet_PT_jecdown > 20000")
jetvars_zmumu[0][1] = "boson_jet_PT_jecdown/1000.0"

zmumuj_data2012_jecdown = AnalysisClass("zmumuj_jecdown")
zmumuj_data2012_jecdown.SetSelCut(selcut_zmumu_nojet + ptj20_zmumu_jecdown + select_runs)
zmumuj_data2012_jecdown.AddData("Data", zmumuj.MUt)
zmumuj_data2012_jecdown.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumuj_data2012_jecdown.AddVars(zvars)
zmumuj_data2012_jecdown.AddVars(jetvars_zmumu)
zmumuj_data2012_jecdown.Add3DVars(vars3d)
zmumuj_data2012_jecdown.Run()
zmumuj_data2012_jecdown.StyleTemplates()
zmumuj_data2012_jecdown.SaveToFile()



# jecmc up
ptj20_zmumu_jecmcup     = TCut("boson_jet_PT_jecmcup > 20000")
jetvars_zmumu[0][1] = "boson_jet_PT_jecmcup/1000.0"

zmumuj_data2012_jecmcup = AnalysisClass("zmumuj_jecmcup")
zmumuj_data2012_jecmcup.SetSelCut(selcut_zmumu_nojet + ptj20_zmumu_jecmcup + select_runs)
zmumuj_data2012_jecmcup.AddData("Data", zmumuj.MUt)
zmumuj_data2012_jecmcup.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumuj_data2012_jecmcup.AddVars(zvars)
zmumuj_data2012_jecmcup.AddVars(jetvars_zmumu)
zmumuj_data2012_jecmcup.Add3DVars(vars3d)
zmumuj_data2012_jecmcup.Run()
zmumuj_data2012_jecmcup.StyleTemplates()
zmumuj_data2012_jecmcup.SaveToFile()

# jecmc down
ptj20_zmumu_jecmcdown     = TCut("boson_jet_PT_jecmcdown > 20000")
jetvars_zmumu[0][1] = "boson_jet_PT_jecmcdown/1000.0"

zmumuj_data2012_jecmcdown = AnalysisClass("zmumuj_jecmcdown")
zmumuj_data2012_jecmcdown.SetSelCut(selcut_zmumu_nojet + ptj20_zmumu_jecmcdown + select_runs)
zmumuj_data2012_jecmcdown.AddData("Data", zmumuj.MUt)
zmumuj_data2012_jecmcdown.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumuj_data2012_jecmcdown.AddVars(zvars)
zmumuj_data2012_jecmcdown.AddVars(jetvars_zmumu)
zmumuj_data2012_jecmcdown.Add3DVars(vars3d)
zmumuj_data2012_jecmcdown.Run()
zmumuj_data2012_jecmcdown.StyleTemplates()
zmumuj_data2012_jecmcdown.SaveToFile()


# jecmc down
ptj20_zmumu_smear     = TCut("boson_jet_PT_smear > 20000")
jetvars_zmumu[0][1] = "boson_jet_PT_smear/1000.0"

zmumuj_data2012_smear = AnalysisClass("zmumuj_smear")
zmumuj_data2012_smear.SetSelCut(selcut_zmumu_nojet + ptj20_zmumu_smear + select_runs)
zmumuj_data2012_smear.AddData("Data", zmumuj.MUt)
zmumuj_data2012_smear.GetTemplate("Data").AddTree(zmumuj.MDt)
zmumuj_data2012_smear.AddVars(zvars)
zmumuj_data2012_smear.AddVars(jetvars_zmumu)
zmumuj_data2012_smear.Add3DVars(vars3d)
zmumuj_data2012_smear.Run()
zmumuj_data2012_smear.StyleTemplates()
zmumuj_data2012_smear.SaveToFile()


save_to_file('/user2/sfarry/WJet/dat/zmumu_jec_errs_ptj.dat', zmumuj_data2012.GetTemplate("Data").GetVar("Jet_PT").GetHist(),
             zmumuj_data2012_jecup.GetTemplate("Data").GetVar("Jet_PT").GetHist(),
             zmumuj_data2012_jecdown.GetTemplate("Data").GetVar("Jet_PT").GetHist(),
             zmumuj_data2012_jecmcup.GetTemplate("Data").GetVar("Jet_PT").GetHist(),
             zmumuj_data2012_jecmcdown.GetTemplate("Data").GetVar("Jet_PT").GetHist(),
             zmumuj_data2012_smear.GetTemplate("Data").GetVar("Jet_PT").GetHist()
             )
             

save_to_file('/user2/sfarry/WJet/dat/zmumu_jec_errs_etaj.dat', zmumuj_data2012.GetTemplate("Data").GetVar("Jet_ETA").GetHist(),
             zmumuj_data2012_jecup.GetTemplate("Data").GetVar("Jet_ETA").GetHist(),
             zmumuj_data2012_jecdown.GetTemplate("Data").GetVar("Jet_ETA").GetHist(),
             zmumuj_data2012_jecmcup.GetTemplate("Data").GetVar("Jet_ETA").GetHist(),
             zmumuj_data2012_jecmcdown.GetTemplate("Data").GetVar("Jet_ETA").GetHist(),
             zmumuj_data2012_smear.GetTemplate("Data").GetVar("Jet_ETA").GetHist()
             )
             
save_to_file('/user2/sfarry/WJet/dat/zmumu_jec_errs_y.dat', zmumuj_data2012.GetTemplate("Data").GetVar("Y").GetHist(),
             zmumuj_data2012_jecup.GetTemplate("Data").GetVar("Y").GetHist(),
             zmumuj_data2012_jecdown.GetTemplate("Data").GetVar("Y").GetHist(),
             zmumuj_data2012_jecmcup.GetTemplate("Data").GetVar("Y").GetHist(),
             zmumuj_data2012_jecmcdown.GetTemplate("Data").GetVar("Y").GetHist(),
             zmumuj_data2012_smear.GetTemplate("Data").GetVar("Y").GetHist()
             )
             
save_to_file('/user2/sfarry/WJet/dat/zmumu_jec_errs_dphi.dat', zmumuj_data2012.GetTemplate("Data").GetVar("dPhi").GetHist(),
             zmumuj_data2012_jecup.GetTemplate("Data").GetVar("dPhi").GetHist(),
             zmumuj_data2012_jecdown.GetTemplate("Data").GetVar("dPhi").GetHist(),
             zmumuj_data2012_jecmcup.GetTemplate("Data").GetVar("dPhi").GetHist(),
             zmumuj_data2012_jecmcdown.GetTemplate("Data").GetVar("dPhi").GetHist(),
             zmumuj_data2012_smear.GetTemplate("Data").GetVar("dPhi").GetHist()
             )
             


