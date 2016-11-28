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

fid = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000")

mupem = TCut("lp_ID == -11 && lm_ID == 11" )
mumep = TCut("lp_ID == -11  && lm_ID == 11")

lp_rec = TCut("lp_isRec == 1")
lm_rec = TCut("lm_isRec == 1")
jet_rec = TCut("ttbar_recjet_PT > 0")
lp_muid = TCut("lp_rec_ISMUON == 1")
lm_muid = TCut("lm_rec_ISMUON == 1")

lp_eid  = TCut("lp_rec_CaloPrsE > 50.0 && lp_rec_CaloEcalE/lp_P > 0.1 && lp_rec_CaloHcalE/lp_P < 0.05 && lp_rec_CaloHcalE > 0")
lm_eid  = TCut("lm_rec_CaloPrsE > 50.0 && lm_rec_CaloEcalE/lm_P > 0.1 && lm_rec_CaloHcalE/lm_P < 0.05 && lm_rec_CaloHcalE > 0")

lp_mutrigger = TCut("lp_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && lp_Hlt1SingleMuonHighPTDecision_TOS == 1 && lp_L0MuonEWDecision_TOS ==1")
lm_mutrigger = TCut("lm_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && lm_Hlt1SingleMuonHighPTDecision_TOS == 1 && lm_L0MuonEWDecision_TOS ==1")

lp_recpt20 = TCut("lp_rec_PT > 20000")
lm_recpt20 = TCut("lm_rec_PT > 20000")
lp_recpt15 = TCut("lp_rec_PT > 15000")
lm_recpt15 = TCut("lm_rec_PT > 15000")

f = TFile("/hepstore/sfarry/GridOutput/2583/ttbar.Z_tautau.MU.MC2012.root")
g = TFile("/hepstore/sfarry/GridOutput/2584/ttbar.Z_tautau.MD.MC2012.root")
h = TFile("/hepstore/sfarry/GridOutput/2585/ttbar.Zg_ee.MU.MC2012.root")
i = TFile("/hepstore/sfarry/GridOutput/2586/ttbar.Zg_ee.MD.MC2012.root")


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
mu_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_ideff_mc2012.root")

eplus_ideff = EfficiencyClass("eplus_ideff")
eplus_ideff.SetSelectionCut(fid + mumep + lp_rec)
eplus_ideff.SetPassCut(lp_eid)
eplus_ideff.AddTree(h.Get('MCGenTrackEff/MCTrackEffTuple'))
eplus_ideff.AddTree(i.Get('MCGenTrackEff/MCTrackEffTuple'))
#eplus_ideff.AddTree(h.Get('MCGenTrackEff/MCTrackEffTuple'))
#eplus_ideff.AddTree(i.Get('MCGenTrackEff/MCTrackEffTuple'))
#eplus_ideff.AddTrees(qq2ttbar_mc2016.true_trees())
#eplus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_ideff.AddVars(mumepvars)
eplus_ideff.Run()
#eplus_ideff.SaveToFile()

eminus_ideff = EfficiencyClass("eminus_ideff")
eminus_ideff.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff.SetPassCut(lm_eid)
eminus_ideff.AddTree(h.Get('MCGenTrackEff/MCTrackEffTuple'))
eminus_ideff.AddTree(i.Get('MCGenTrackEff/MCTrackEffTuple'))
#eminus_ideff.AddTree(h.Get('MCGenTrackEff/MCTrackEffTuple'))
#eminus_ideff.AddTree(i.Get('MCGenTrackEff/MCTrackEffTuple'))
#eminus_ideff.AddTrees(qq2ttbar_mc2016.true_trees())
#eminus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_ideff.AddVars(mupemvars)
eminus_ideff.Run()
#eminus_ideff.SaveToFile()

e_ideff = EfficiencyClass("e_ideff", eplus_ideff, eminus_ideff)
e_ideff.MakeEfficiencyGraph()
e_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ideff_mc2012.root")
