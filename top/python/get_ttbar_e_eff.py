from os import sys
import copy
from Jawa import *
from ROOT import TCut, TTree, TFile, TMath, TH1F, TF1, TH1, TParameter
from Utils import GetWeightHist, GetSpreadGraph, GetPDFGraph, asymm_details, ratio_details, details
from math import sqrt

class eff_vals:
    def _init_(self, name, val, staterr = 0.0, modelerr = 0.0, mcerr = 0.0):
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

muplus_trackeff = EfficiencyClass("muplus_trackeff")
muplus_trackeff.SetSelectionCut(fid + mupem)
muplus_trackeff.SetPassCut(lp_rec)
muplus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_trackeff.AddVars(mupemvars)
#muplus_trackeff.ReweightEff("lp_P", "lp_ETA", ratio)
muplus_trackeff.ScaleErrs = True
muplus_trackeff.Run()
muplus_trackeff.SaveToFile()

muminus_trackeff = EfficiencyClass("muminus_trackeff")
muminus_trackeff.SetSelectionCut(fid + mumep)
muminus_trackeff.SetPassCut(lm_rec)
muminus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_trackeff.AddVars(mumepvars)
#muminus_trackeff.ReweightEff("lm_P", "lm_ETA", ratio)
muminus_trackeff.ScaleErrs = True
muminus_trackeff.Run()
muminus_trackeff.SaveToFile()


mu_trackeff = EfficiencyClass("mu_trackeff", muplus_trackeff, muminus_trackeff)
mu_trackeff.ScaleErrs = True
mu_trackeff.MakeEfficiencyGraph()
mu_trackeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff.root")

muplus_trackeff_nlorw = EfficiencyClass("muplus_trackeff_nlorw")
muplus_trackeff_nlorw.SetSelectionCut(fid + mupem)
muplus_trackeff_nlorw.SetPassCut(lp_rec)
muplus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_trackeff_nlorw.AddVars(mupemvars)
#muplus_trackeff_nlorw.ReweightEff("lp_P", "lp_ETA", ratio)
muplus_trackeff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_trackeff_nlorw.ScaleErrs = True
muplus_trackeff_nlorw.Run()
muplus_trackeff_nlorw.SaveToFile()

muminus_trackeff_nlorw = EfficiencyClass("muminus_trackeff_nlorw")
muminus_trackeff_nlorw.SetSelectionCut(fid + mumep)
muminus_trackeff_nlorw.SetPassCut(lm_rec)
muminus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_trackeff_nlorw.AddVars(mumepvars)
#muminus_trackeff_nlorw.ReweightEff("lm_P", "lm_ETA", ratio)
muminus_trackeff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_trackeff_nlorw.ScaleErrs = True
muminus_trackeff_nlorw.Run()
muminus_trackeff_nlorw.SaveToFile()

mu_trackeff_nlorw = EfficiencyClass("mu_trackeff_nlorw", muplus_trackeff_nlorw, muminus_trackeff_nlorw)
mu_trackeff_nlorw.ScaleErrs = True
mu_trackeff_nlorw.MakeEfficiencyGraph()
mu_trackeff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff_nlorw.root")

eplus_trackeff = EfficiencyClass("eplus_trackeff")
eplus_trackeff.SetSelectionCut(fid + mumep)
eplus_trackeff.SetPassCut(lp_rec)
eplus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eplus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eplus_trackeff.AddVars(mumepvars)
eplus_trackeff.Run()
#eplus_trackeff.SaveToFile()

eminus_trackeff = EfficiencyClass("eminus_trackeff")
eminus_trackeff.SetSelectionCut(fid + mupem)
eminus_trackeff.SetPassCut(lm_rec)
eminus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eminus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eminus_trackeff.AddVars(mupemvars)
eminus_trackeff.Run()
#eminus_trackeff.SaveToFile()

e_trackeff = EfficiencyClass("e_trackeff", eplus_trackeff, eminus_trackeff)
e_trackeff.MakeEfficiencyGraph()
e_trackeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trackeff.root")


eplus_trackeff_nlorw = EfficiencyClass("eplus_trackeff_nlorw")
eplus_trackeff_nlorw.SetSelectionCut(fid + mumep)
eplus_trackeff_nlorw.SetPassCut(lp_rec)
eplus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eplus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eplus_trackeff_nlorw.AddVars(mumepvars)
eplus_trackeff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
eplus_trackeff_nlorw.Run()
#eplus_trackeff_nlorw.SaveToFile()

eminus_trackeff_nlorw = EfficiencyClass("eminus_trackeff_nlorw")
eminus_trackeff_nlorw.SetSelectionCut(fid + mupem)
eminus_trackeff_nlorw.SetPassCut(lm_rec)
eminus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eminus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eminus_trackeff_nlorw.AddVars(mupemvars)
eminus_trackeff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
eminus_trackeff_nlorw.Run()
#eminus_trackeff_nlorw.SaveToFile()

e_trackeff_nlorw = EfficiencyClass("e_trackeff_nlorw", eplus_trackeff_nlorw, eminus_trackeff_nlorw)
e_trackeff_nlorw.MakeEfficiencyGraph()
e_trackeff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trackeff_nlorw.root")

muplus_ideff = EfficiencyClass("muplus_ideff")
muplus_ideff.SetSelectionCut(fid + mupem + lp_rec)
muplus_ideff.SetPassCut(lp_muid)
muplus_ideff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_ideff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_ideff.AddVars(mupemvars)
muplus_ideff.Run()
#muplus_ideff.SaveToFile()

muminus_ideff = EfficiencyClass("muminus_ideff")
muminus_ideff.SetSelectionCut(fid + mumep + lm_rec)
muminus_ideff.SetPassCut(lm_muid)
muminus_ideff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_ideff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_ideff.AddVars(mumepvars)
muminus_ideff.Run()
#muminus_ideff.SaveToFile()

mu_ideff = EfficiencyClass("mu_ideff", muplus_ideff, muminus_ideff)
mu_ideff.MakeEfficiencyGraph()
mu_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_ideff.root")

muplus_ideff_nlorw = EfficiencyClass("muplus_ideff_nlorw")
muplus_ideff_nlorw.SetSelectionCut(fid + mupem + lp_rec)
muplus_ideff_nlorw.SetPassCut(lp_muid)
muplus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_ideff_nlorw.AddVars(mupemvars)
muplus_ideff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_ideff_nlorw.Run()
#muplus_ideff_nlorw.SaveToFile()

muminus_ideff_nlorw = EfficiencyClass("muminus_ideff_nlorw")
muminus_ideff_nlorw.SetSelectionCut(fid + mumep + lm_rec)
muminus_ideff_nlorw.SetPassCut(lm_muid)
muminus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_ideff_nlorw.AddVars(mumepvars)
muminus_ideff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_ideff_nlorw.Run()
#muminus_ideff_nlorw.SaveToFile()

mu_ideff_nlorw = EfficiencyClass("mu_ideff_nlorw", muplus_ideff_nlorw, muminus_ideff_nlorw)
mu_ideff_nlorw.MakeEfficiencyGraph()
mu_ideff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_ideff_nlorw.root")


muplus_triggereff = EfficiencyClass("muplus_triggereff")
muplus_triggereff.SetSelectionCut(fid + mupem + lp_rec + lp_muid)
muplus_triggereff.SetPassCut(lp_mutrigger)
muplus_triggereff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_triggereff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_triggereff.AddVars(mupemvars)
muplus_triggereff.Run()
#muplus_triggereff.SaveToFile()

muminus_triggereff = EfficiencyClass("muminus_triggereff")
muminus_triggereff.SetSelectionCut(fid + mumep + lm_rec + lm_muid)
muminus_triggereff.SetPassCut(lm_mutrigger)
muminus_triggereff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_triggereff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_triggereff.AddVars(mumepvars)
muminus_triggereff.Run()
#muminus_triggereff.SaveToFile()

mu_triggereff = EfficiencyClass("mu_triggereff", muplus_triggereff, muminus_triggereff)
mu_triggereff.MakeEfficiencyGraph()
mu_triggereff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff.root")


muplus_triggereff_nlorw = EfficiencyClass("muplus_triggereff_nlorw")
muplus_triggereff_nlorw.SetSelectionCut(fid + mupem + lp_rec + lp_muid)
muplus_triggereff_nlorw.SetPassCut(lp_mutrigger)
muplus_triggereff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_triggereff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_triggereff_nlorw.AddVars(mupemvars)
muplus_triggereff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_triggereff_nlorw.Run()
#muplus_triggereff_nlorw.SaveToFile()

muminus_triggereff_nlorw = EfficiencyClass("muminus_triggereff_nlorw")
muminus_triggereff_nlorw.SetSelectionCut(fid + mumep + lm_rec + lm_muid)
muminus_triggereff_nlorw.SetPassCut(lm_mutrigger)
muminus_triggereff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_triggereff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_triggereff_nlorw.AddVars(mumepvars)
muminus_triggereff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_triggereff_nlorw.Run()
#muminus_triggereff_nlorw.SaveToFile()

mu_triggereff_nlorw = EfficiencyClass("mu_triggereff_nlorw", muplus_triggereff_nlorw, muminus_triggereff_nlorw)
mu_triggereff_nlorw.MakeEfficiencyGraph()
mu_triggereff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff_nlorw.root")

eplus_ideff = EfficiencyClass("eplus_ideff")
eplus_ideff.SetSelectionCut(fid + mumep + lp_rec)
eplus_ideff.SetPassCut(lp_eid)
eplus_ideff.AddTrees(qq2ttbar_mc2016.true_trees())
eplus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_ideff.AddVars(mumepvars)
eplus_ideff.Run()
#eplus_ideff.SaveToFile()

eminus_ideff = EfficiencyClass("eminus_ideff")
eminus_ideff.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff.SetPassCut(lm_eid)
eminus_ideff.AddTrees(qq2ttbar_mc2016.true_trees())
eminus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_ideff.AddVars(mupemvars)
eminus_ideff.Run()
#eminus_ideff.SaveToFile()

e_ideff = EfficiencyClass("e_ideff", eplus_ideff, eminus_ideff)
e_ideff.MakeEfficiencyGraph()
e_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ideff.root")

eplus_ideff_nlorw = EfficiencyClass("eplus_ideff_nlorw")
eplus_ideff_nlorw.SetSelectionCut(fid + mumep + lp_rec)
eplus_ideff_nlorw.SetPassCut(lp_eid)
eplus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees())
eplus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_ideff_nlorw.AddVars(mumepvars)
eplus_ideff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
eplus_ideff_nlorw.Run()
#eplus_ideff_nlorw.SaveToFile()

eminus_ideff_nlorw = EfficiencyClass("eminus_ideff_nlorw")
eminus_ideff_nlorw.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff_nlorw.SetPassCut(lm_eid)
eminus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees())
eminus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_ideff_nlorw.AddVars(mupemvars)
eminus_ideff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
eminus_ideff_nlorw.Run()
#eminus_ideff_nlorw.SaveToFile()

e_ideff_nlorw = EfficiencyClass("e_ideff_nlorw", eplus_ideff_nlorw, eminus_ideff_nlorw)
e_ideff_nlorw.MakeEfficiencyGraph()
e_ideff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ideff_nlorw.root")

eplus_ideff_effrw = EfficiencyClass("eplus_ideff_effrw")
eplus_ideff_effrw.SetSelectionCut(fid + mumep + lp_rec)
eplus_ideff_effrw.SetPassCut(lp_eid)
eplus_ideff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eplus_ideff_effrw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eplus_ideff_effrw.AddVars(mumepvars)
eplus_ideff_effrw.ReweightEff("lp_ETA", ef.Get("zee_eid_weights_eta"))
eplus_ideff_effrw.Run()
#eplus_ideff_effrw.SaveToFile()

eminus_ideff_effrw = EfficiencyClass("eminus_ideff_effrw")
eminus_ideff_effrw.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff_effrw.SetPassCut(lm_eid)
eminus_ideff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eminus_ideff_effrw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eminus_ideff_effrw.AddVars(mupemvars)
eminus_ideff_effrw.ReweightEff("lm_ETA", ef.Get("zee_eid_weights_eta"))
eminus_ideff_effrw.ScaleErrs = True
eminus_ideff_effrw.Run()
#eminus_ideff_effrw.SaveToFile()

e_ideff_effrw = EfficiencyClass("e_ideff_effrw", eplus_ideff_effrw, eminus_ideff_effrw)
e_ideff_effrw.MakeEfficiencyGraph()
e_ideff_effrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ideff_effrw.root")


eplus_kineff = EfficiencyClass("eplus_kineff")
eplus_kineff.SetSelectionCut(fid + mumep + lp_rec + lp_eid)
eplus_kineff.SetPassCut(lp_recpt20)
eplus_kineff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eplus_kineff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eplus_kineff.AddVars(mumepvars)
eplus_kineff.Run()
#eplus_kineff.SaveToFile()

eminus_kineff = EfficiencyClass("eminus_kineff")
eminus_kineff.SetSelectionCut(fid + mupem + lm_rec + lm_eid)
eminus_kineff.SetPassCut(lm_recpt20)
eminus_kineff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eminus_kineff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eminus_kineff.AddVars(mupemvars)
eminus_kineff.Run()
#eminus_kineff.SaveToFile()

e_kineff = EfficiencyClass("e_kineff", eplus_kineff, eminus_kineff)
e_kineff.MakeEfficiencyGraph()
e_kineff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_kineff.root")

eplus_kineff_nlorw = EfficiencyClass("eplus_kineff_nlorw")
eplus_kineff_nlorw.SetSelectionCut(fid + mumep + lp_rec + lp_eid)
eplus_kineff_nlorw.SetPassCut(lp_recpt20)
eplus_kineff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eplus_kineff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eplus_kineff_nlorw.AddVars(mumepvars)
eplus_kineff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
eplus_kineff_nlorw.Run()
#eplus_kineff_nlorw.SaveToFile()

eminus_kineff_nlorw = EfficiencyClass("eminus_kineff_nlorw")
eminus_kineff_nlorw.SetSelectionCut(fid + mupem + lm_rec + lm_eid)
eminus_kineff_nlorw.SetPassCut(lm_recpt20)
eminus_kineff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eminus_kineff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eminus_kineff_nlorw.AddVars(mupemvars)
eminus_kineff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
eminus_kineff_nlorw.Run()
#eminus_kineff_nlorw.SaveToFile()

e_kineff_nlorw = EfficiencyClass("e_kineff_nlorw", eplus_kineff_nlorw, eminus_kineff_nlorw)
e_kineff_nlorw.MakeEfficiencyGraph()
e_kineff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_kineff_nlorw.root")

eplus_kin15eff = EfficiencyClass("eplus_kin15eff")
eplus_kin15eff.SetSelectionCut(fid + mumep + lp_rec + lp_eid)
eplus_kin15eff.SetPassCut(lp_recpt15)
eplus_kineff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eplus_kineff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eplus_kin15eff.AddVars(mumepvars)
eplus_kin15eff.Run()
#eplus_kin15eff.SaveToFile()

eminus_kin15eff = EfficiencyClass("eminus_kin15eff")
eminus_kin15eff.SetSelectionCut(fid + mupem + lm_rec + lm_eid)
eminus_kin15eff.SetPassCut(lm_recpt20)
eminus_kin15eff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
eminus_kin15eff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
eminus_kin15eff.AddVars(mupemvars)
eminus_kin15eff.Run()
#eminus_kin15eff.SaveToFile()

e_kin15eff = EfficiencyClass("e_kin15eff", eplus_kin15eff, eminus_kin15eff)
e_kin15eff.MakeEfficiencyGraph()
e_kin15eff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_kin15eff.root")

jeteff_mupem = EfficiencyClass("jeteff_mupem")
jeteff_mupem.SetSelectionCut(fid + lp_rec + lm_rec + mupem)
jeteff_mupem.SetPassCut(jet_rec)
jeteff_mupem.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
jeteff_mupem.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
jeteff_mupem.AddVars(mupemvars)
jeteff_mupem.Run()
#jeteff_mupem.SaveToFile()

jeteff_mumep = EfficiencyClass("jeteff_mumep")
jeteff_mumep.SetSelectionCut(fid + lp_rec + lm_rec + mumep)
jeteff_mumep.SetPassCut(jet_rec)
jeteff_mumep.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
jeteff_mumep.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
jeteff_mumep.AddVars(mumepvars)
jeteff_mumep.Run()
#jeteff_mumep.SaveToFile()

jeteff = EfficiencyClass("jeteff", jeteff_mupem, jeteff_mumep)
jeteff.MakeEfficiencyGraph()
jeteff.SaveToFile("/user2/sfarry/workspaces/top/tuples/jeteff.root")

jeteff_mupem_nlorw = EfficiencyClass("jeteff_mupem_nlorw")
jeteff_mupem_nlorw.SetSelectionCut(fid + lp_rec + lm_rec + mupem)
jeteff_mupem_nlorw.SetPassCut(jet_rec)
jeteff_mupem_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
jeteff_mupem_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(). tt_gg_scale)
jeteff_mupem_nlorw.AddVars(mupemvars)
jeteff_mupem_nlorw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_tt_amcatnlo_ptj10_etaj10"))
jeteff_mupem_nlorw.Run()
#jeteff_mupem.SaveToFile()

jeteff_mumep_nlorw = EfficiencyClass("jeteff_mumep_nlorw")
jeteff_mumep_nlorw.SetSelectionCut(fid + lp_rec + lm_rec + mumep)
jeteff_mumep_nlorw.SetPassCut(jet_rec)
jeteff_mumep_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
jeteff_mumep_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
jeteff_mumep_nlorw.AddVars(mumepvars)
jeteff_mumep_nlorw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_tt_amcatnlo_ptj10_etaj10"))
jeteff_mumep_nlorw.Run()
#jeteff_mumep.SaveToFile()

jeteff_nlorw = EfficiencyClass("jeteff_nlorw", jeteff_mupem_nlorw, jeteff_mumep_nlorw)
jeteff_nlorw.MakeEfficiencyGraph()
jeteff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/jeteff_nlorw.root")

'''
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
'''

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
isoeff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale)
isoeff.AddTrees(gg2ttbar_mc2016.trees(), tt_gg_scale)
isoeff.AddVars(recvars)
isoeff.Run()
isoeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff.root")

ipeff = EfficiencyClass("ipeff")
ipeff.SetSelectionCut(kinematic + iso + trueb)
ipeff.SetPassCut(ip)
ipeff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale)
ipeff.AddTrees(gg2ttbar_mc2016.trees(), tt_gg_scale)
ipeff.AddVars(recvars)
ipeff.Run()
ipeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/ipeff.root")

tageff = EfficiencyClass("tageff")
tageff.SetSelectionCut(kinematic + trueb)
tageff.SetPassCut(jettag)
tageff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale)
tageff.AddTrees(gg2ttbar_mc2016.trees(), tt_gg_scale)
tageff.AddVars(recvars)
tageff.Run()
tageff.SaveToFile("/user2/sfarry/workspaces/top/tuples/tageff.root")

seleff = EfficiencyClass("seleff")
seleff.SetSelectionCut(kinematic + trueb)
seleff.SetPassCut(iso + ip)
seleff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale)
seleff.AddTrees(gg2ttbar_mc2016.trees(), tt_gg_scale)
seleff.AddVars(recvars)
seleff.Run()
seleff.SaveToFile("/user2/sfarry/workspaces/top/tuples/seleff.root")

mu_trkeff_obj = eff_vals('mu_trkeff',
                         mu_trackeff_nlorw.GetTotEff(),
                         mu_trackeff_nlorw.GetTotEffErrLo(),
                         abs(mu_trackeff.GetTotEff() - mu_trkeff_nlorw.GetTotEff()),
                         0.0)

e_trkeff_obj     = eff_vals('e_trkeff',
                            e_trackeff_nlorw.GetTotEff(),
                            e_trackeff_nlorw.GetTotEffErrLo(),
                            abs(e_trkeff.GetTotEff() - e_trkeff_nlorw.GetTotEff()),
                            e_trkeff_val * 0.02)

mu_ideff_obj  = eff_vals('mu_ideff',
                         mu_ideff_nlorw.GetTotEff(),
                         mu_ideff_nlorw.GetTotEffErrLo(),
                         abs(mu_ideff.GetTotEff() - mu_ideff_nlorw.GetTotEff()),
                         0.0)

e_ideff_obj   = eff_vals('e_ideff',
                         e_ideff_nlorw.GetTotEff(),
                         e_ideff_nlorw.GetTotEffErrLo(),
                         abs(e_ideff.GetTotEff() - e_ideff_nlorw.GetTotEff()),
                         e_ideff_val * 2.0)

mu_trgeff_obj = eff_vals('mu_trgeff',
                         mu_trgeff_nlorw.GetTotEff(),
                         mu_trgeff_nlorw.GetTotEffErrLo(),
                         abs(mu_trgeff.GetTotEff() - mu_trgeff_nlorw.GetTotEff()),
                         0.0)

jet_receff_obj = eff_vals('jet_receff',
                          jeteff_nlorw.GetTotEff(),
                          jeteff_nlorw.GetTotEffErrLo(),
                          abs(jeteff.GetTotEff() - jeteff_nlorw.GetTotEff()),
                          jeteff_nlorw * 0.05)

jet_tageff_obj = tag_effs('jet_tageff',
                          tageff.GetTotEff(),
                          0.0,
                          0.0,
                          tageff.GetTotEff() * 0.05)

seleff_obj = tag_effs('seleff',
                      ipeff.GetTotEff() * isoeff.GetTotEff(),
                      sqrt(pow(ipeff.GetTotEffErrLo()/ipeff.GetTotEff(),2) +
                           pow(isoeff.GetTotEffErrLo()/isoeff.GetTotEff(),2)),
                      0.0, 0.0)



outputFile = TFile("ttbar_mu_effs.root")
mu_trkeff_obj.Write()
mu_ideff_obj.Write()
mu_trgeff_obj.Write()
e_trkeff_obj.Write()
e_ideff_obj.Write()
jet_receff_obj.Write()
jet_tageff_obj.Write()
selfeff_obj.Write()
outputFile.Close()
