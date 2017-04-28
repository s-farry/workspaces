from os import sys
import copy
from Jawa import *
from ROOT import TCut, TTree, TFile, TMath, TH1F, TF1, TH1, TParameter
from Utils import GetWeightHist, GetSpreadGraph, GetPDFGraph, asymm_details, ratio_details, details
from math import sqrt

class eff_vals:
    def __init__(self, name, val, staterr = 0.0, modelerr = 0.0, mcerr = 0.0):
        self.name = name
        self.val = val
        self.staterr = staterr
        self.modelerr = modelerr
        self.mcerr = mcerr
        self.tot_err = sqrt(staterr*staterr + modelerr*modelerr + mcerr*mcerr)
    def write(self):
        TParameter(float)(self.name+"_eff", self.val).Write()
        TParameter(float)(self.name+"_eff_stat_err", self.staterr).Write()
        TParameter(float)(self.name+"_eff_model_err",self.modelerr).Write()
        TParameter(float)(self.name+"_eff_mc_err", self.mcerr).Write()
        TParameter(float)(self.name+"_eff_err", self.tot_err).Write()



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

tt_qq_evts = qq2ttbar_mc2016.MU.Get('TotEvts').GetVal() + qq2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_qq_xsec = 9.966e-8*1e9
tt_qq_acc  = 10000.0/106462.0
tt_qq_scale = tt_qq_xsec * tt_qq_acc /tt_qq_evts

tt_gg_evts = gg2ttbar_mc2016.MU.Get('TotEvts').GetVal() + gg2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_gg_xsec = 5.826e-7*1e9
tt_gg_acc  = 10000.0/156045.0
tt_gg_scale = tt_gg_xsec * tt_gg_acc /tt_gg_evts


#weight file
wf = TFile("/user2/sfarry/workspaces/top/tuples/top_weights.root")
#electron efficiency weights
ef = TFile("/user2/sfarry/workspaces/top/tuples/electron_eff_weights.root")


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
isoeff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale )
isoeff.AddTrees(gg2ttbar_mc2016.trees())
isoeff.AddVars(recvars)
isoeff.Run()
isoeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff.root")

ipeff = EfficiencyClass("ipeff")
ipeff.SetSelectionCut(kinematic + iso + trueb)
ipeff.SetPassCut(ip)
ipeff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale )
ipeff.AddTrees(gg2ttbar_mc2016.trees())
ipeff.AddVars(recvars)
ipeff.Run()
ipeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/ipeff.root")

seleff = EfficiencyClass("seleff")
seleff.SetSelectionCut(kinematic + trueb)
seleff.SetPassCut(iso + ip)
seleff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale )
seleff.AddTrees(gg2ttbar_mc2016.trees())
seleff.AddVars(recvars)
seleff.Run()
seleff.SaveToFile("/user2/sfarry/workspaces/top/tuples/seleff.root")

seleff_obj = eff_vals('seleff',
                      ipeff.GetTotEff() * isoeff.GetTotEff(),
                      sqrt(pow(ipeff.GetTotEffErrLo()/ipeff.GetTotEff(),2) +
                           pow(isoeff.GetTotEffErrLo()/isoeff.GetTotEff(),2)),
                      0.0, 0.0)



outputFile = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_sel_effs.root", "RECREATE")
seleff_obj.write()
outputFile.Close()
