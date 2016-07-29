from os import sys
from Jawa import Template
from ROOT import TFile, TTree, TCut, TH1, TParameter
import copy
TH1.AddDirectory(False)


def get_correction(name, histA, histB):
    num = histA.Clone(name)
    num.Scale(1/histA.Integral())
    den = histB.Clone(name)
    den.Scale(1/histB.Integral())
    num.Divide(den)
    den.Delete()
    return num

ptbins = [20, 25, 30, 40, 50,100]
etabins = [2, 2.5, 3.0, 3.5, 4.5]
eta8bins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
jetetabins = [2.2, 2.6, 3.0, 3.4, 4.2]
ptjbins = [10 + 2*i for i in range(26)] + [60 + 5*j for j in range(9)]

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
    ["ptj",  "fwdjet_pt", ptjbins],
    ["etaj", "fwdjet_eta", 45, 2.0, 4.5]
    ]

vars = [
    ["etap",  "mup_eta", etabins],
    ["etam",  "mum_eta", etabins],
    ["ptp",  "mup_pt", 20, 20, 80],
    ["ptm",  "mum_pt", 20, 20, 80],
    ["Y",   "dimu_y", etabins],
    ["M",   "dimu_M", 40, 40, 120],
    ]

vars2d = [['etaj', 'ptj']]

py8mass  = TCut("dimu_M > 60 && dimu_M < 120")
py8fid_plus  = TCut("mup_pt > 20 && mup_eta > 2 && mup_eta < 4.5")
py8fid_minus = TCut("mum_pt > 20 && mum_eta > 2 && mum_eta < 4.5")

py8nofid_plus  = TCut("mup_eta < 2 || mup_eta > 4.5 || mup_eta == 0") # the zero if for z->tau tau when no muon is present
py8nofid_minus = TCut("mum_eta < 2 || mum_eta > 4.5 || mum_eta == 0")

zm40 = TCut("Z_M > 40")
fwdjet10 = TCut("fwdjet_pt > 10")
fwdjet20 = TCut("fwdjet_pt > 20")

z_mcatnlo_f   = TFile.Open("/hepstore/sfarry/aMC@NLO/Zmumuj/Events/pythia.root")
z_mcatnlo_t   = z_mcatnlo_f.Get("Zjet")

z_powheg_f   = TFile.Open("/hepstore/sfarry/Powheg/Zmumuj/pythia.root")
z_powheg_t   = z_powheg_f.Get("Zjet")


zgmumu_py8 = Template("zgmumu_py8", zgmumu_py8_t, py8fid_minus + py8fid_plus + py8mass + fwdjet10)
zgmumu_py8.AddVars(jetvars)
zgmumu_py8.AddVars(vars)
zgmumu_py8.Add2DVars(vars2d)
zgmumu_py8.Run()
#zgmumu_py8.Scale(zgxsec / zgmumu_py8_t.GetEntries())
zgmumu_py8.SaveToFile()

zgmumu_mcatnlo = Template("zgmumu_mcatnlo", z_mcatnlo_t, py8fid_minus + py8fid_plus + py8mass + fwdjet10)
zgmumu_mcatnlo.AddVars(jetvars)
zgmumu_mcatnlo.AddVars(vars)
zgmumu_mcatnlo.Add2DVars(vars2d)
zgmumu_mcatnlo.Run()
zgmumu_mcatnlo.SaveToFile()

zgmumu_powheg = Template("zgmumu_powheg", z_powheg_t, py8fid_minus + py8fid_plus + py8mass + fwdjet10)
zgmumu_powheg.AddVars(jetvars)
zgmumu_powheg.AddVars(vars)
zgmumu_powheg.Add2DVars(vars2d)
zgmumu_powheg.Run()
zgmumu_powheg.SaveToFile()

corr_mcatnlo_etaj = get_correction("corr_mcatnlo_etaj", zgmumu_mcatnlo.Get2DVar('etaj', 'ptj').GetHist().ProjectionX("temp", 6, 36),
                                   zgmumu_py8.Get2DVar('etaj', 'ptj').GetHist().ProjectionX("temp2", 6, 36))
corr_mcatnlo_ptj  = get_correction("corr_mcatnlo_ptj" , zgmumu_mcatnlo.GetVar('ptj').GetHist() , zgmumu_py8.GetVar('ptj').GetHist() )

corr_powheg_etaj = get_correction("corr_powheg_etaj", zgmumu_powheg.Get2DVar('etaj', 'ptj').GetHist().ProjectionX("temp", 6, 36),
                                  zgmumu_py8.Get2DVar('etaj', 'ptj').GetHist().ProjectionX("temp2", 6, 36))
corr_powheg_ptj  = get_correction("corr_powheg_ptj" , zgmumu_powheg.GetVar('ptj').GetHist() , zgmumu_py8.GetVar('ptj').GetHist() )

outputF = TFile("zgmumuj_kfactors.root", "RECREATE")
corr_mcatnlo_etaj.Write()
corr_mcatnlo_ptj.Write()
corr_powheg_etaj.Write()
corr_powheg_ptj.Write()
outputF.Close()
