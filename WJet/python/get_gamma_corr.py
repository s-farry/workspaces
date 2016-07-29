from os import sys
from Jawa import Template
from ROOT import TFile, TTree, TCut, TH1, TParameter
import copy
TH1.AddDirectory(False)

ptbins = [20, 25, 30, 40, 50,100]
etabins = [2, 2.5, 3.0, 3.5, 4.5]
eta8bins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
jetetabins = [2.2, 2.6, 3.0, 3.4, 4.2]

zmumu_py8_f   = TFile("/hepstore/sfarry/zmumuj_pythia/zmumuj_pythia.root")
zmumu_py8_t = zmumu_py8_f.Get("Zjet")

zgmumu_py8_f   = TFile("/hepstore/sfarry/zgmumuj_pythia/zgmumuj_pythia.root")
zgmumu_py8_t = zgmumu_py8_f.Get("Zjet")


#zxsec = 8.243e-7 + 6.925e-7 + 4.830e-7
#zgxsec  = 1.458e-6 + 1.246e-6 + 1.839e-6

zxsec = 6.924e-7 + 4.848e-7
zgxsec  = 1.244e-6 + 1.849e-6

#| q qbar -> gamma*/Z0 g                          241 |      557200      29328      29328 |   6.924e-07  1.996e-09 |
# | q g-> gamma*/Z0 q                              242 |      440914      20672      20672 |   4.848e-07  1.740e-09 |
# | q qbar -> gamma*/Z0 g                          241 |      429688      20367      20367 |   1.244e-06  4.002e-09 |
# | q g-> gamma*/Z0 q                              242 |      574767      29633      29633 |   1.849e-06  7.114e-09 |
# |                                                    |                                   |                        |


jetvars = [
    ["ptj",  "fwdjet_pt", ptbins],
    ["etaj", "fwdjet_eta", jetetabins],
    ]

vars = [
    ["etap",  "mup_eta", etabins],
    ["etam",  "mum_eta", etabins],
    ["ptp",  "mup_pt", 20, 20, 80],
    ["ptm",  "mum_pt", 20, 20, 80],
    ["Y",   "dimu_y", etabins],
    ["M",   "dimu_M", 40, 40, 120],
    ]

py8mass  = TCut("dimu_M > 60 && dimu_M < 120")
py8fid_plus  = TCut("mup_pt > 20 && mup_eta > 2 && mup_eta < 4.5")
py8fid_minus = TCut("mum_pt > 20 && mum_eta > 2 && mum_eta < 4.5")

py8fid15_plus  = TCut("mup_pt > 15 && mup_eta > 2 && mup_eta < 4.5")
py8fid15_minus = TCut("mum_pt > 15 && mum_eta > 2 && mum_eta < 4.5")

py8nofid_plus  = TCut("mup_eta < 2 || mup_eta > 4.5 || mup_eta == 0") # the zero if for z->tau tau when no muon is present
py8nofid_minus = TCut("mum_eta < 2 || mum_eta > 4.5 || mum_eta == 0")

zm40 = TCut("Z_M > 40")
fwdjet20 = TCut("fwdjet_pt > 20")

zmu_py8_p = Template("zmu_py8_p", zmumu_py8_t, py8fid_plus + py8nofid_minus + fwdjet20)
zmu_py8_p.AddVars(jetvars)
zmu_py8_p.AddVars(vars)
zmu_py8_p.Run()
zmu_py8_p.Scale(zxsec / zmumu_py8_t.GetEntries())
zmu_py8_p.SaveToFile()

zmu_py8_m = Template("zmu_py8_m", zmumu_py8_t, py8fid_minus + py8nofid_plus + fwdjet20)
zmu_py8_m.AddVars(jetvars)
zmu_py8_m.AddVars(vars)
zmu_py8_m.Run()
zmu_py8_m.Scale(zxsec / zmumu_py8_t.GetEntries())
zmu_py8_m.SaveToFile()

zmumu_py8 = Template("zmumu_py8", zmumu_py8_t, py8fid_minus + py8fid_plus + py8mass + fwdjet20)
zmumu_py8.AddVars(jetvars)
zmumu_py8.AddVars(vars)
zmumu_py8.Run()
zmumu_py8.Scale(zxsec / zmumu_py8_t.GetEntries())
zmumu_py8.SaveToFile()

zgmu_py8_p = Template("zgmu_py8_p", zgmumu_py8_t, py8fid_plus + py8nofid_minus + fwdjet20)
zgmu_py8_p.AddVars(jetvars)
zgmu_py8_p.AddVars(vars)
zgmu_py8_p.Run()
zgmu_py8_p.Scale(zgxsec / zgmumu_py8_t.GetEntries())
zgmu_py8_p.SaveToFile()

zgmu_py8_m = Template("zgmu_py8_m", zgmumu_py8_t, py8fid_minus + py8nofid_plus + fwdjet20)
zgmu_py8_m.AddVars(jetvars)
zgmu_py8_m.AddVars(vars)
zgmu_py8_m.Run()
zgmu_py8_m.Scale(zgxsec / zgmumu_py8_t.GetEntries())
zgmu_py8_m.SaveToFile()

zgmumu_py8 = Template("zgmumu_py8", zgmumu_py8_t, py8fid_minus + py8fid_plus + py8mass + fwdjet20)
zgmumu_py8.AddVars(jetvars)
zgmumu_py8.AddVars(vars)
zgmumu_py8.Run()
zgmumu_py8.Scale(zgxsec / zgmumu_py8_t.GetEntries())
zgmumu_py8.SaveToFile()

# dimuon scale factor is already taken into account by normalising to data
# hence it is to be factored out

factor_out = zmumu_py8.GetNormEvts() / zgmumu_py8.GetNormEvts()

totcorr_p = (zgmu_py8_p.GetNormEvts() / zmu_py8_p.GetNormEvts()) * factor_out
totcorr_m = (zgmu_py8_m.GetNormEvts() / zmu_py8_m.GetNormEvts()) * factor_out

corr_zmu_eta_p = zgmu_py8_p.GetVar("etap").GetHist().Clone("corr_zmu_eta_p")
corr_zmu_eta_p.Divide(zmu_py8_p.GetVar("etap").GetHist())
corr_zmu_eta_p.Scale(factor_out)

corr_zmu_pt_p = zgmu_py8_p.GetVar("ptp").GetHist().Clone("corr_zmu_pt_p")
corr_zmu_pt_p.Divide(zmu_py8_p.GetVar("ptp").GetHist())
corr_zmu_pt_p.Scale(factor_out)

corr_zmu_etaj_p = zgmu_py8_p.GetVar("etaj").GetHist().Clone("corr_zmu_etaj_p")
corr_zmu_etaj_p.Divide(zmu_py8_p.GetVar("etaj").GetHist())
corr_zmu_etaj_p.Scale(factor_out)

corr_zmu_ptj_p = zgmu_py8_p.GetVar("ptj").GetHist().Clone("corr_zmu_ptj_p")
corr_zmu_ptj_p.Divide(zmu_py8_p.GetVar("ptj").GetHist())
corr_zmu_ptj_p.Scale(factor_out)

corr_zmu_eta_m = zgmu_py8_m.GetVar("etam").GetHist().Clone("corr_zmu_eta_m")
corr_zmu_eta_m.Divide(zmu_py8_m.GetVar("etam").GetHist())
corr_zmu_eta_m.Scale(factor_out)

corr_zmu_pt_m = zgmu_py8_m.GetVar("ptm").GetHist().Clone("corr_zmu_pt_m")
corr_zmu_pt_m.Divide(zmu_py8_m.GetVar("ptm").GetHist())
corr_zmu_pt_m.Scale(factor_out)

corr_zmu_etaj_m = zgmu_py8_m.GetVar("etaj").GetHist().Clone("corr_zmu_etaj_m")
corr_zmu_etaj_m.Divide(zmu_py8_m.GetVar("etaj").GetHist())
corr_zmu_etaj_m.Scale(factor_out)

corr_zmu_ptj_m = zgmu_py8_m.GetVar("ptj").GetHist().Clone("corr_zmu_ptj_m")
corr_zmu_ptj_m.Divide(zmu_py8_m.GetVar("ptj").GetHist())
corr_zmu_ptj_m.Scale(factor_out)

corr_zmumu_M = zgmumu_py8.GetVar("M").GetHist().Clone("corr_zmumu_M")
corr_zmumu_M.Divide(zmumu_py8.GetVar("M").GetHist())



outputF = TFile("zgmumu_corrections.root", "RECREATE")
TParameter(float)("corr_zmu_tot_p", totcorr_p).Write()
TParameter(float)("corr_zmu_tot_m", totcorr_m).Write()
corr_zmu_eta_p.Write()
corr_zmu_eta_m.Write()
corr_zmu_pt_p.Write()
corr_zmu_pt_m.Write()
corr_zmu_etaj_p.Write()
corr_zmu_etaj_m.Write()
corr_zmu_ptj_p.Write()
corr_zmu_ptj_m.Write()
corr_zmumu_M.Write()
outputF.Close()
