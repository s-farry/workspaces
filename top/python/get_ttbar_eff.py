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



from top_config import *

TH1.AddDirectory(False)

fid = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000 && ttbar_jet_PT > 20000 && abs(ttbar_jet_flavour) == 5")

mupem = TCut("lp_ID == -13 && lm_ID == 11" )
mumep = TCut("lp_ID == -11  && lm_ID == 13")

lp_rec = TCut("lp_isRec == 1")
lm_rec = TCut("lm_isRec == 1")
jet_rec = TCut("ttbar_recjet_PT > 0")
lp_muid = TCut("lp_rec_ISMUON == 1")
lm_muid = TCut("lm_rec_ISMUON == 1")

lp_eid  = TCut("lp_rec_CaloPrsE > 50.0 && lp_rec_CaloEcalE/lp_P > 0.1 && lp_rec_CaloHcalE/lp_P < 0.05 && lp_rec_CaloHcalE >= 0")
lm_eid  = TCut("lm_rec_CaloPrsE > 50.0 && lm_rec_CaloEcalE/lm_P > 0.1 && lm_rec_CaloHcalE/lm_P < 0.05 && lm_rec_CaloHcalE >= 0")

lp_mutrigger = TCut("lp_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && lp_Hlt1SingleMuonHighPTDecision_TOS == 1 && lp_L0MuonEWDecision_TOS ==1")
lm_mutrigger = TCut("lm_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && lm_Hlt1SingleMuonHighPTDecision_TOS == 1 && lm_L0MuonEWDecision_TOS ==1")

lp_recpt20 = TCut("lp_rec_PT > 20000")
lm_recpt20 = TCut("lm_rec_PT > 20000")
lp_recpt15 = TCut("lp_rec_PT > 15000")
lm_recpt15 = TCut("lm_rec_PT > 15000")

f = TFile("/hepstore/sfarry/GridOutput/2554/ttbar.ttbar_gg.MU.MC2016.root")
g = TFile("/hepstore/sfarry/GridOutput/2555/ttbar.ttbar_gg.MD.MC2016.root")
h = TFile("/hepstore/sfarry/GridOutput/2556/ttbar.ttbar_qqbar.MU.MC2016.root")
i = TFile("/hepstore/sfarry/GridOutput/2557/ttbar.ttbar_qqbar.MD.MC2016.root")


mupemvars = [
    ["mu_pt"        , "lp_PT/1000.0"           , 8  , 20 , 100 ],
    ["e_pt"         , "lm_PT/1000.0"            , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(lp_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(lm_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]

mumepvars = [
    ["mu_pt"        , "lm_PT/1000.0"           , 8  , 20 , 100 ],
    ["e_pt"         , "lp_PT/1000.0"            , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(lm_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(lp_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]

recvars = [
    ["mu_pt"        , "mu_PT/1000.0"           , 8  , 20 , 100 ],
    ["e_pt"         , "e_PT/1000.0"            , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(mu_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(e_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["eiso"         , "e_cpt_0.50/1000.0"       , 10, 0, 20],
    ["muiso"        , "mu_cpt_0.50/1000.0"      , 10, 0, 20],
    ["iso"          , "max(mu_cpt_0.50,e_cpt_0.50)/1000.0" , 10, 0, 20],
    ]

muplus_trackeff = EfficiencyClass("muplus_trackeff")
muplus_trackeff.SetSelectionCut(fid + mupem)
muplus_trackeff.SetPassCut(lp_rec)
muplus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees())
muplus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_trackeff.AddVars(mupemvars)
muplus_trackeff.Run()
#muplus_trackeff.SaveToFile()

muminus_trackeff = EfficiencyClass("muminus_trackeff")
muminus_trackeff.SetSelectionCut(fid + mumep)
muminus_trackeff.SetPassCut(lm_rec)
muminus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees())
muminus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_trackeff.AddVars(mumepvars)
muminus_trackeff.Run()
#muminus_trackeff.SaveToFile()


mu_trackeff = EfficiencyClass("mu_trackeff", muplus_trackeff, muminus_trackeff)
mu_trackeff.MakeEfficiencyGraph()
mu_trackeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff.root")

eplus_trackeff = EfficiencyClass("eplus_trackeff")
eplus_trackeff.SetSelectionCut(fid + mumep)
eplus_trackeff.SetPassCut(lp_rec)
#eplus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees())
#eplus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_trackeff.AddTree(f.Get('MCGenTrackEff/MCTrackEffTuple'))
eplus_trackeff.AddTree(g.Get('MCGenTrackEff/MCTrackEffTuple'))
eplus_trackeff.AddTree(h.Get('MCGenTrackEff/MCTrackEffTuple'))
eplus_trackeff.AddTree(i.Get('MCGenTrackEff/MCTrackEffTuple'))
eplus_trackeff.AddVars(mumepvars)
eplus_trackeff.Run()
#eplus_trackeff.SaveToFile()

eminus_trackeff = EfficiencyClass("eminus_trackeff")
eminus_trackeff.SetSelectionCut(fid + mupem)
eminus_trackeff.SetPassCut(lm_rec)
#eminus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees())
#eminus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_trackeff.AddTree(f.Get('MCGenTrackEff/MCTrackEffTuple'))
eminus_trackeff.AddTree(g.Get('MCGenTrackEff/MCTrackEffTuple'))
eminus_trackeff.AddTree(h.Get('MCGenTrackEff/MCTrackEffTuple'))
eminus_trackeff.AddTree(i.Get('MCGenTrackEff/MCTrackEffTuple'))
eminus_trackeff.AddVars(mupemvars)
eminus_trackeff.Run()
#eminus_trackeff.SaveToFile()

e_trackeff = EfficiencyClass("e_trackeff", eplus_trackeff, eminus_trackeff)
e_trackeff.MakeEfficiencyGraph()
e_trackeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trackeff.root")

muplus_ideff = EfficiencyClass("muplus_ideff")
muplus_ideff.SetSelectionCut(fid + mupem + lp_rec)
muplus_ideff.SetPassCut(lp_muid)
muplus_ideff.AddTrees(qq2ttbar_mc2016.true_trees())
muplus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_ideff.AddVars(mupemvars)
muplus_ideff.Run()
#muplus_ideff.SaveToFile()

muminus_ideff = EfficiencyClass("muminus_ideff")
muminus_ideff.SetSelectionCut(fid + mumep + lm_rec)
muminus_ideff.SetPassCut(lm_muid)
muminus_ideff.AddTrees(qq2ttbar_mc2016.true_trees())
muminus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_ideff.AddVars(mumepvars)
muminus_ideff.Run()
#muminus_ideff.SaveToFile()

mu_ideff = EfficiencyClass("mu_ideff", muplus_ideff, muminus_ideff)
mu_ideff.MakeEfficiencyGraph()
mu_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_ideff.root")


muplus_triggereff = EfficiencyClass("muplus_triggereff")
muplus_triggereff.SetSelectionCut(fid + mupem + lp_rec + lp_muid)
muplus_triggereff.SetPassCut(lp_mutrigger)
muplus_triggereff.AddTrees(qq2ttbar_mc2016.true_trees())
muplus_triggereff.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_triggereff.AddVars(mupemvars)
muplus_triggereff.Run()
#muplus_triggereff.SaveToFile()

muminus_triggereff = EfficiencyClass("muminus_triggereff")
muminus_triggereff.SetSelectionCut(fid + mumep + lm_rec + lm_muid)
muminus_triggereff.SetPassCut(lm_mutrigger)
muminus_triggereff.AddTrees(qq2ttbar_mc2016.true_trees())
muminus_triggereff.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_triggereff.AddVars(mumepvars)
muminus_triggereff.Run()
#muminus_triggereff.SaveToFile()

mu_triggereff = EfficiencyClass("mu_triggereff", muplus_triggereff, muminus_triggereff)
mu_triggereff.MakeEfficiencyGraph()
mu_triggereff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff.root")

eplus_ideff = EfficiencyClass("eplus_ideff")
eplus_ideff.SetSelectionCut(fid + mumep + lp_rec)
eplus_ideff.SetPassCut(lp_eid)
eplus_ideff.AddTree(f.Get('MCGenTrackEff/MCTrackEffTuple'))
eplus_ideff.AddTree(g.Get('MCGenTrackEff/MCTrackEffTuple'))
eplus_ideff.AddTree(h.Get('MCGenTrackEff/MCTrackEffTuple'))
eplus_ideff.AddTree(i.Get('MCGenTrackEff/MCTrackEffTuple'))
#eplus_ideff.AddTrees(qq2ttbar_mc2016.true_trees())
#eplus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_ideff.AddVars(mumepvars)
eplus_ideff.Run()
#eplus_ideff.SaveToFile()

eminus_ideff = EfficiencyClass("eminus_ideff")
eminus_ideff.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff.SetPassCut(lm_eid)
eminus_ideff.AddTree(f.Get('MCGenTrackEff/MCTrackEffTuple'))
eminus_ideff.AddTree(g.Get('MCGenTrackEff/MCTrackEffTuple'))
eminus_ideff.AddTree(h.Get('MCGenTrackEff/MCTrackEffTuple'))
eminus_ideff.AddTree(i.Get('MCGenTrackEff/MCTrackEffTuple'))
#eminus_ideff.AddTrees(qq2ttbar_mc2016.true_trees())
#eminus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_ideff.AddVars(mupemvars)
eminus_ideff.Run()
#eminus_ideff.SaveToFile()

e_ideff = EfficiencyClass("e_ideff", eplus_ideff, eminus_ideff)
e_ideff.MakeEfficiencyGraph()
e_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ideff.root")

eplus_kineff = EfficiencyClass("eplus_kineff")
eplus_kineff.SetSelectionCut(fid + mumep + lp_rec + lp_eid)
eplus_kineff.SetPassCut(lp_recpt20)
eplus_kineff.AddTrees(qq2ttbar_mc2016.true_trees())
eplus_kineff.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_kineff.AddVars(mumepvars)
eplus_kineff.Run()
#eplus_kineff.SaveToFile()

eminus_kineff = EfficiencyClass("eminus_kineff")
eminus_kineff.SetSelectionCut(fid + mupem + lm_rec + lm_eid)
eminus_kineff.SetPassCut(lm_recpt20)
eminus_kineff.AddTrees(qq2ttbar_mc2016.true_trees())
eminus_kineff.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_kineff.AddVars(mupemvars)
eminus_kineff.Run()
#eminus_kineff.SaveToFile()

e_kineff = EfficiencyClass("e_kineff", eplus_kineff, eminus_kineff)
e_kineff.MakeEfficiencyGraph()
e_kineff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_kineff.root")

eplus_kin15eff = EfficiencyClass("eplus_kin15eff")
eplus_kin15eff.SetSelectionCut(fid + mumep + lp_rec + lp_eid)
eplus_kin15eff.SetPassCut(lp_recpt15)
eplus_kineff.AddTrees(qq2ttbar_mc2016.true_trees())
eplus_kineff.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_kin15eff.AddVars(mumepvars)
eplus_kin15eff.Run()
#eplus_kin15eff.SaveToFile()

eminus_kin15eff = EfficiencyClass("eminus_kin15eff")
eminus_kin15eff.SetSelectionCut(fid + mupem + lm_rec + lm_eid)
eminus_kin15eff.SetPassCut(lm_recpt20)
eminus_kin15eff.AddTrees(qq2ttbar_mc2016.true_trees())
eminus_kin15eff.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_kin15eff.AddVars(mupemvars)
eminus_kin15eff.Run()
#eminus_kin15eff.SaveToFile()

e_kin15eff = EfficiencyClass("e_kin15eff", eplus_kin15eff, eminus_kin15eff)
e_kin15eff.MakeEfficiencyGraph()
e_kin15eff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_kin15eff.root")

jeteff_mupem = EfficiencyClass("jeteff_mupem")
jeteff_mupem.SetSelectionCut(fid + lp_rec + lm_rec + mupem)
jeteff_mupem.SetPassCut(jet_rec)
jeteff_mupem.AddTrees(qq2ttbar_mc2016.true_trees())
jeteff_mupem.AddTrees(gg2ttbar_mc2016.true_trees())
jeteff_mupem.AddVars(mupemvars)
jeteff_mupem.Run()
#jeteff_mupem.SaveToFile()

jeteff_mumep = EfficiencyClass("jeteff_mumep")
jeteff_mumep.SetSelectionCut(fid + lp_rec + lm_rec + mumep)
jeteff_mumep.SetPassCut(jet_rec)
jeteff_mumep.AddTrees(qq2ttbar_mc2016.true_trees())
jeteff_mumep.AddTrees(gg2ttbar_mc2016.true_trees())
jeteff_mumep.AddVars(mumepvars)
jeteff_mumep.Run()
#jeteff_mumep.SaveToFile()

jeteff = EfficiencyClass("jeteff", jeteff_mupem, jeteff_mumep)
jeteff.MakeEfficiencyGraph()
jeteff.SaveToFile("/user2/sfarry/workspaces/top/tuples/jeteff.root")

receff_mupem = EfficiencyClass("receff_mupem")
receff_mupem.SetSelectionCut(fid + mupem)
receff_mupem.SetPassCut(jet_rec + lp_rec + lm_rec + lm_recpt20 + lp_muid + lm_eid )
receff_mupem.AddTrees(qq2ttbar_mc2016.true_trees())
receff_mupem.AddTrees(gg2ttbar_mc2016.true_trees())
receff_mupem.AddVars(mupemvars)
receff_mupem.Run()
receff_mupem.SaveToFile()

receff_mumep = EfficiencyClass("receff_mumep")
receff_mumep.SetSelectionCut(fid + mumep)
receff_mumep.SetPassCut(jet_rec + lp_rec + lm_rec + lp_recpt20 + lp_eid + lm_muid )
receff_mumep.AddTrees(qq2ttbar_mc2016.true_trees())
receff_mumep.AddTrees(gg2ttbar_mc2016.true_trees())
receff_mumep.AddVars(mumepvars)
receff_mumep.Run()
receff_mumep.SaveToFile()

receff = EfficiencyClass("receff", receff_mupem, receff_mumep)
receff.MakeEfficiencyGraph()
receff.SaveToFile("/user2/sfarry/workspaces/top/tuples/receff.root")


# get other efficiencies from fully reconstructed version
kinematic = TCut("mu_ETA > 2.0 && mu_ETA < 4.5 && e_ETA > 2.0 && e_ETA < 4.5 && mu_PT > 20000 && e_PT > 20000 && ttbar_jet_PT > 20000")
ip  = TCut("mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
iso = TCut("mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000")
iso = TCut("mu_cpt_0.50 < 5000")
trueb = TCut("ttbar_mcjet_PT > 0 && abs(ttbar_mcjet_flavour) == 5")
jettag = TCut("ttbar_jet_BDTTag == 1")

isoeff = EfficiencyClass("isoeff")
isoeff.SetSelectionCut(kinematic + trueb)
isoeff.SetPassCut(iso)
isoeff.AddTrees(qq2ttbar_mc2016.trees())
isoeff.AddTrees(gg2ttbar_mc2016.trees())
isoeff.AddVars(recvars)
isoeff.Run()
isoeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff.root")

ipeff = EfficiencyClass("ipeff")
ipeff.SetSelectionCut(kinematic + iso + trueb)
ipeff.SetPassCut(ip)
ipeff.AddTrees(qq2ttbar_mc2016.trees())
ipeff.AddTrees(gg2ttbar_mc2016.trees())
ipeff.AddVars(recvars)
ipeff.Run()
ipeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/ipeff.root")

tageff = EfficiencyClass("tageff")
tageff.SetSelectionCut(kinematic + trueb)
tageff.SetPassCut(jettag)
tageff.AddTrees(qq2ttbar_mc2016.trees())
tageff.AddTrees(gg2ttbar_mc2016.trees())
tageff.AddVars(recvars)
tageff.Run()
tageff.SaveToFile("/user2/sfarry/workspaces/top/tuples/tageff.root")

seleff = EfficiencyClass("seleff")
seleff.SetSelectionCut(kinematic + trueb)
seleff.SetPassCut(iso + ip)
seleff.AddTrees(qq2ttbar_mc2016.trees())
seleff.AddTrees(gg2ttbar_mc2016.trees())
seleff.AddVars(recvars)
seleff.Run()
seleff.SaveToFile("/user2/sfarry/workspaces/top/tuples/seleff.root")
