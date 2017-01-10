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

#f = TFile("/hepstore/sfarry/GridOutput/2554/ttbar.ttbar_gg.MU.MC2016.root")
#g = TFile("/hepstore/sfarry/GridOutput/2555/ttbar.ttbar_gg.MD.MC2016.root")
#h = TFile("/hepstore/sfarry/GridOutput/2556/ttbar.ttbar_qqbar.MU.MC2016.root")
#i = TFile("/hepstore/sfarry/GridOutput/2557/ttbar.ttbar_qqbar.MD.MC2016.root")


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

vars = [
    ["lm_pt"        , "lm_PT/1000.0"           , 8  , 20 , 100 ],
    ["lp_pt"        , "lp_PT/1000.0"            , 8  , 20 , 100 ],
    ["lm_eta"       , "abs(lm_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["lp_eta"       , "abs(lp_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
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

ttbar_py8 = Template("ttbar_py8")
ttbar_py8.SetSelCut(fid + mue)
ttbar_py8.AddTrees(qq2ttbar_mc2016.true_trees())
ttbar_py8.AddTrees(gg2ttbar_mc2016.true_trees())
ttbar_py8.AddVars(vars)
ttbar_py8.Run()
ttbar_py8.SaveToFile()
