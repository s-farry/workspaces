from os import sys
import copy
from Jawa import *
from ROOT import TCut, TTree, TFile, TMath, TH1F, TF1, TH1, TParameter
from Utils import GetWeightHist, GetSpreadGraph, GetPDFGraph, asymm_details, ratio_details, details
from math import sqrt

def getpdfuncertainty(central, pdfsets):
    sumsq = 0
    for pdf in pdfsets:
        sumsq = sumsq + pow(central - pdf,2)
    return sqrt(sumsq / (len(pdfsets) - 1))



TH1.AddDirectory(False)

fid = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000 && ttbar_jet_PT > 20000 && abs(ttbar_jet_flavour) == 5")

mupem = TCut("lp_ID == -13 && lm_ID == 11" )
mumep = TCut("lp_ID == -11  && lm_ID == 13")

lp_rec = TCut("lp_isRec == 1")
lm_rec = TCut("lm_isRec == 1")
jet_rec = TCut("ttbar_recjet_PT > 0")
lp_muid = TCut("lp_rec_ISMUON == 1")
lm_muid = TCut("lm_rec_ISMUON == 1")

lp_eid  = TCut("lp_rec_CaloPrsE > 50.0 && lp_rec_CaloEcalE/lp_P > 0.1 && lp_rec_CaloHcalE/lp_P < 0.05 && lp_rec_CaloHcalE > 0")
lm_eid  = TCut("lm_rec_CaloPrsE > 50.0 && lm_rec_CaloEcalE/lp_P > 0.1 && lm_rec_CaloHcalE/lp_P < 0.05 && lm_rec_CaloHcalE > 0")

lp_recpt20 = TCut("lp_rec_PT > 20000")
lm_recpt20 = TCut("lm_rec_PT > 20000")
lp_recpt15 = TCut("lp_rec_PT > 15000")
lm_recpt15 = TCut("lm_rec_PT > 15000")

mupemvars = [
    ["mu_pt"        , "lp_PT/1000.0"           , 80  , 20 , 100 ],
    ["e_pt"         , "lm_PT/1000.0"            , 80  , 20 , 100 ],
    ["mu_eta"       , "abs(lp_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(lm_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]

mumepvars = [
    ["mu_pt"        , "lm_PT/1000.0"           , 80  , 20 , 100 ],
    ["e_pt"         , "lp_PT/1000.0"            , 80  , 20 , 100 ],
    ["mu_eta"       , "abs(lm_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(lp_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]

recvars = [
    ["mu_pt"        , "mu_PT/1000.0"           , 80  , 20 , 100 ],
    ["e_pt"         , "e_PT/1000.0"            , 80  , 20 , 100 ],
    ["mu_eta"       , "abs(mu_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(e_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["eiso"         , "e_cpt_0.50/1000.0"       , 10, 0, 20],
    ["muiso"        , "mu_cpt_0.50/1000.0"      , 10, 0, 20],
    ["iso"          , "max(mu_cpt_0.50,e_cpt_0.50)/1000.0" , 10, 0, 20],
    ]

f   = TFile.Open("/hepstore/sfarry/GridOutput/2428/ttbar.ttbar_gg.MU.MC2016.root")
t   = f.Get("MCGenTrackEff/MCTrackEffTuple")
g   = TFile.Open("/hepstore/sfarry/GridOutput/2429/ttbar.ttbar_gg.MD.MC2016.root")
u   = g.Get("MCGenTrackEff/MCTrackEffTuple")
h   = TFile.Open("/hepstore/sfarry/GridOutput/2426/ttbar.ttbar_qqbar.MU.MC2016.root")
v   = h.Get("MCGenTrackEff/MCTrackEffTuple")
i   = TFile.Open("/hepstore/sfarry/GridOutput/2427/ttbar.ttbar_qqbar.MD.MC2016.root")
w   = i.Get("MCGenTrackEff/MCTrackEffTuple")

x = f.Get("ttbar/DecayTree")
y = g.Get("ttbar/DecayTree")
z = h.Get("ttbar/DecayTree")
a = i.Get("ttbar/DecayTree")


muplus_trackeff = EfficiencyClass("muplus_trackeff")
muplus_trackeff.SetSelectionCut(fid + mupem)
muplus_trackeff.SetPassCut(lp_rec)
muplus_trackeff.AddTree(t)
muplus_trackeff.AddTree(u)
muplus_trackeff.AddTree(v)
muplus_trackeff.AddTree(w)
muplus_trackeff.AddVars(mupemvars)
muplus_trackeff.Run()
muplus_trackeff.SaveToFile()

muminus_trackeff = EfficiencyClass("muminus_trackeff")
muminus_trackeff.SetSelectionCut(fid + mumep)
muminus_trackeff.SetPassCut(lm_rec)
muminus_trackeff.AddTree(t)
muminus_trackeff.AddTree(u)
muminus_trackeff.AddTree(v)
muminus_trackeff.AddTree(w)
muminus_trackeff.AddVars(mumepvars)
muminus_trackeff.Run()
muminus_trackeff.SaveToFile()


mu_trackeff = EfficiencyClass("mu_trackeff", muplus_trackeff, muminus_trackeff)
mu_trackeff.MakeEfficiencyGraph()
mu_trackeff.SaveToFile()

eplus_trackeff = EfficiencyClass("eplus_trackeff")
eplus_trackeff.SetSelectionCut(fid + mumep)
eplus_trackeff.SetPassCut(lp_rec)
eplus_trackeff.AddTree(t)
eplus_trackeff.AddTree(u)
eplus_trackeff.AddTree(v)
eplus_trackeff.AddTree(w)
eplus_trackeff.AddVars(mumepvars)
eplus_trackeff.Run()
eplus_trackeff.SaveToFile()

eminus_trackeff = EfficiencyClass("eminus_trackeff")
eminus_trackeff.SetSelectionCut(fid + mupem)
eminus_trackeff.SetPassCut(lm_rec)
eminus_trackeff.AddTree(t)
eminus_trackeff.AddTree(u)
eminus_trackeff.AddTree(v)
eminus_trackeff.AddTree(w)
eminus_trackeff.AddVars(mupemvars)
eminus_trackeff.Run()
eminus_trackeff.SaveToFile()

e_trackeff = EfficiencyClass("e_trackeff", eplus_trackeff, eminus_trackeff)
e_trackeff.MakeEfficiencyGraph()
e_trackeff.SaveToFile()

muplus_ideff = EfficiencyClass("muplus_ideff")
muplus_ideff.SetSelectionCut(fid + mupem + lp_rec)
muplus_ideff.SetPassCut(lp_muid)
muplus_ideff.AddTree(t)
muplus_ideff.AddTree(u)
muplus_trackeff.AddTree(v)
muplus_trackeff.AddTree(w)
muplus_ideff.AddVars(mupemvars)
muplus_ideff.Run()
muplus_ideff.SaveToFile()

muminus_ideff = EfficiencyClass("muminus_ideff")
muminus_ideff.SetSelectionCut(fid + mumep + lm_rec)
muminus_ideff.SetPassCut(lm_muid)
muminus_ideff.AddTree(t)
muminus_ideff.AddTree(u)
muminus_ideff.AddVars(mumepvars)
muminus_ideff.Run()
muminus_ideff.SaveToFile()

mu_ideff = EfficiencyClass("mu_ideff", muplus_ideff, muminus_ideff)
mu_ideff.MakeEfficiencyGraph()
mu_ideff.SaveToFile()

eplus_ideff = EfficiencyClass("eplus_ideff")
eplus_ideff.SetSelectionCut(fid + mumep + lp_rec)
eplus_ideff.SetPassCut(lp_eid)
eplus_ideff.AddTree(t)
eplus_ideff.AddTree(u)
eplus_ideff.AddTree(v)
eplus_ideff.AddTree(w)
eplus_ideff.AddVars(mumepvars)
eplus_ideff.Run()
eplus_ideff.SaveToFile()

eminus_ideff = EfficiencyClass("eminus_ideff")
eminus_ideff.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff.SetPassCut(lm_eid)
eminus_ideff.AddTree(t)
eminus_ideff.AddTree(u)
eminus_ideff.AddTree(v)
eminus_ideff.AddTree(w)
eminus_ideff.AddVars(mupemvars)
eminus_ideff.Run()
eminus_ideff.SaveToFile()

e_ideff = EfficiencyClass("e_ideff", eplus_ideff, eminus_ideff)
e_ideff.MakeEfficiencyGraph()
e_ideff.SaveToFile()

eplus_kineff = EfficiencyClass("eplus_kineff")
eplus_kineff.SetSelectionCut(fid + mumep + lp_rec + lp_eid)
eplus_kineff.SetPassCut(lp_recpt20)
eplus_kineff.AddTree(t)
eplus_kineff.AddTree(u)
eplus_kineff.AddTree(v)
eplus_kineff.AddTree(w)
eplus_kineff.AddVars(mumepvars)
eplus_kineff.Run()
eplus_kineff.SaveToFile()

eminus_kineff = EfficiencyClass("eminus_kineff")
eminus_kineff.SetSelectionCut(fid + mupem + lm_rec + lm_eid)
eminus_kineff.SetPassCut(lm_recpt20)
eminus_kineff.AddTree(t)
eminus_kineff.AddTree(u)
eminus_kineff.AddTree(v)
eminus_kineff.AddTree(w)
eminus_kineff.AddVars(mupemvars)
eminus_kineff.Run()
eminus_kineff.SaveToFile()

e_kineff = EfficiencyClass("e_kineff", eplus_kineff, eminus_kineff)
e_kineff.MakeEfficiencyGraph()
e_kineff.SaveToFile()

eplus_kin15eff = EfficiencyClass("eplus_kin15eff")
eplus_kin15eff.SetSelectionCut(fid + mumep + lp_rec + lp_eid)
eplus_kin15eff.SetPassCut(lp_recpt15)
eplus_kin15eff.AddTree(t)
eplus_kin15eff.AddTree(u)
eplus_kin15eff.AddTree(v)
eplus_kin15eff.AddTree(w)
eplus_kin15eff.AddVars(mumepvars)
eplus_kin15eff.Run()
eplus_kin15eff.SaveToFile()

eminus_kin15eff = EfficiencyClass("eminus_kin15eff")
eminus_kin15eff.SetSelectionCut(fid + mupem + lm_rec + lm_eid)
eminus_kin15eff.SetPassCut(lm_recpt20)
eminus_kin15eff.AddTree(t)
eminus_kin15eff.AddTree(u)
eminus_kin15eff.AddTree(v)
eminus_kin15eff.AddTree(w)
eminus_kin15eff.AddVars(mupemvars)
eminus_kin15eff.Run()
eminus_kin15eff.SaveToFile()

e_kin15eff = EfficiencyClass("e_kin15eff", eplus_kin15eff, eminus_kin15eff)
e_kin15eff.MakeEfficiencyGraph()
e_kin15eff.SaveToFile()

jeteff_mupem = EfficiencyClass("jeteff_mupem")
jeteff_mupem.SetSelectionCut(fid + lp_rec + lm_rec + mupem)
jeteff_mupem.SetPassCut(jet_rec)
jeteff_mupem.AddTree(t)
jeteff_mupem.AddTree(u)
jeteff_mupem.AddTree(v)
jeteff_mupem.AddTree(w)
jeteff_mupem.AddVars(mupemvars)
jeteff_mupem.Run()
jeteff_mupem.SaveToFile()

jeteff_mumep = EfficiencyClass("jeteff_mumep")
jeteff_mumep.SetSelectionCut(fid + lp_rec + lm_rec + mumep)
jeteff_mumep.SetPassCut(jet_rec)
jeteff_mumep.AddTree(t)
jeteff_mumep.AddTree(u)
jeteff_mumep.AddTree(v)
jeteff_mumep.AddTree(w)
jeteff_mumep.AddVars(mumepvars)
jeteff_mumep.Run()
jeteff_mumep.SaveToFile()

jeteff = EfficiencyClass("jeteff", jeteff_mupem, jeteff_mumep)
jeteff.MakeEfficiencyGraph()
jeteff.SaveToFile()


# get other efficiencies from fully reconstructed version
kinematic = TCut("mu_ETA > 2.0 && mu_ETA < 4.5 && e_ETA > 2.0 && e_ETA < 4.5 && mu_PT > 20000 && e_PT > 20000 && ttbar_jet_PT > 20000")
ip  = TCut("mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
iso = TCut("mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000")
jettag = TCut("ttbar_jet_BDTTag == 1")

isoeff = EfficiencyClass("isoeff")
isoeff.SetSelectionCut(kinematic)
isoeff.SetPassCut(iso)
isoeff.AddTrees([x,y,z,a])
isoeff.AddVars(recvars)
isoeff.Run()
isoeff.SaveToFile()

ipeff = EfficiencyClass("ipeff")
ipeff.SetSelectionCut(kinematic + iso)
ipeff.SetPassCut(ip)
ipeff.AddTrees([x,y,z,a])
ipeff.AddVars(recvars)
ipeff.Run()
ipeff.SaveToFile()

tageff = EfficiencyClass("tageff")
tageff.SetSelectionCut(kinematic)
tageff.SetPassCut(jettag)
tageff.AddTrees([x,y,z,a])
tageff.AddVars(recvars)
tageff.Run()
tageff.SaveToFile()
