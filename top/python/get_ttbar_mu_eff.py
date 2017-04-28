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
#muon efficiency weights
mf = TFile("/user2/sfarry/workspaces/top/tuples/muon_eff_weights.root")

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
muplus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_trackeff.AddVars(mupemvars)
muplus_trackeff.Run()
muplus_trackeff.SaveToFile()

muminus_trackeff = EfficiencyClass("muminus_trackeff")
muminus_trackeff.SetSelectionCut(fid + mumep)
muminus_trackeff.SetPassCut(lm_rec)
muminus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_trackeff.AddVars(mumepvars)
muminus_trackeff.Run()
muminus_trackeff.SaveToFile()


mu_trackeff = EfficiencyClass("mu_trackeff", muplus_trackeff, muminus_trackeff)
mu_trackeff.MakeEfficiencyGraph()
mu_trackeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff.root")

muplus_trackeff_nlorw = EfficiencyClass("muplus_trackeff_nlorw")
muplus_trackeff_nlorw.SetSelectionCut(fid + mupem)
muplus_trackeff_nlorw.SetPassCut(lp_rec)
muplus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_trackeff_nlorw.AddVars(mupemvars)
muplus_trackeff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_trackeff_nlorw.Run()
muplus_trackeff_nlorw.SaveToFile()

muminus_trackeff_nlorw = EfficiencyClass("muminus_trackeff_nlorw")
muminus_trackeff_nlorw.SetSelectionCut(fid + mumep)
muminus_trackeff_nlorw.SetPassCut(lm_rec)
muminus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_trackeff_nlorw.AddVars(mumepvars)
muminus_trackeff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_trackeff_nlorw.Run()
muminus_trackeff_nlorw.SaveToFile()

mu_trackeff_nlorw = EfficiencyClass("mu_trackeff_nlorw", muplus_trackeff_nlorw, muminus_trackeff_nlorw)
mu_trackeff_nlorw.MakeEfficiencyGraph()
mu_trackeff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff_nlorw.root")

muplus_trackeff_effrw = EfficiencyClass("muplus_trackeff_effrw")
muplus_trackeff_effrw.SetSelectionCut(fid + mupem)
muplus_trackeff_effrw.SetPassCut(lp_rec)
muplus_trackeff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_trackeff_effrw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_trackeff_effrw.AddVars(mupemvars)
muplus_trackeff_effrw.ScaleErrs = True
muplus_trackeff_effrw.ReweightEff("lp_ETA", "lp_PT/1000.0", mf.Get('pt_eta_trk_weights'))
muplus_trackeff_effrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_trackeff_effrw.Run()
muplus_trackeff_effrw.SaveToFile()

muminus_trackeff_effrw = EfficiencyClass("muminus_trackeff_effrw")
muminus_trackeff_effrw.SetSelectionCut(fid + mumep)
muminus_trackeff_effrw.SetPassCut(lm_rec)
muminus_trackeff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_trackeff_effrw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_trackeff_effrw.AddVars(mumepvars)
muminus_trackeff_effrw.ScaleErrs = True
muminus_trackeff_effrw.ReweightEff("lm_ETA", "lm_PT/1000.0", mf.Get('pt_eta_trk_weights'))
muminus_trackeff_effrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_trackeff_effrw.Run()
muminus_trackeff_effrw.SaveToFile()

mu_trackeff_effrw = EfficiencyClass("mu_trackeff_effrw", muplus_trackeff_effrw, muminus_trackeff_effrw)
mu_trackeff_effrw.MakeEfficiencyGraph()
mu_trackeff_effrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff_effrw.root")

muplus_trackeff_wtrw = EfficiencyClass("muplus_trackeff_wtrw")
muplus_trackeff_wtrw.SetSelectionCut(fid + mupem)
muplus_trackeff_wtrw.SetPassCut(lp_rec)
muplus_trackeff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_trackeff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_trackeff_wtrw.AddVars(mupemvars)
muplus_trackeff_wtrw.ScaleErrs = True
muplus_trackeff_wtrw.ReweightEff("lp_ETA", "lp_PT/1000.0", mf.Get('pt_eta_trk_weights'))
muplus_trackeff_wtrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_wt_powheg_lp_pt10_lp_eta10"))
muplus_trackeff_wtrw.Run()
muplus_trackeff_wtrw.SaveToFile()

muminus_trackeff_wtrw = EfficiencyClass("muminus_trackeff_wtrw")
muminus_trackeff_wtrw.SetSelectionCut(fid + mumep)
muminus_trackeff_wtrw.SetPassCut(lm_rec)
muminus_trackeff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_trackeff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_trackeff_wtrw.AddVars(mumepvars)
muminus_trackeff_wtrw.ScaleErrs = True
muminus_trackeff_wtrw.ReweightEff("lm_ETA", "lm_PT/1000.0", mf.Get('pt_eta_trk_weights'))
muminus_trackeff_wtrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_wt_powheg_lm_pt10_lm_eta10"))
muminus_trackeff_wtrw.Run()
muminus_trackeff_wtrw.SaveToFile()

mu_trackeff_wtrw = EfficiencyClass("mu_trackeff_wtrw", muplus_trackeff_wtrw, muminus_trackeff_wtrw)
mu_trackeff_wtrw.MakeEfficiencyGraph()
mu_trackeff_wtrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_trackeff_wtrw.root")



muplus_ideff = EfficiencyClass("muplus_ideff")
muplus_ideff.SetSelectionCut(fid + mupem + lp_rec)
muplus_ideff.SetPassCut(lp_muid)
muplus_ideff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_ideff.AddVars(mupemvars)
muplus_ideff.Run()
#muplus_ideff.SaveToFile()

muminus_ideff = EfficiencyClass("muminus_ideff")
muminus_ideff.SetSelectionCut(fid + mumep + lm_rec)
muminus_ideff.SetPassCut(lm_muid)
muminus_ideff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_ideff.AddVars(mumepvars)
muminus_ideff.Run()
#muminus_ideff.SaveToFile()

mu_ideff = EfficiencyClass("mu_ideff", muplus_ideff, muminus_ideff)
mu_ideff.MakeEfficiencyGraph()
mu_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_ideff.root")

muplus_ideff_nlorw = EfficiencyClass("muplus_ideff_nlorw")
muplus_ideff_nlorw.SetSelectionCut(fid + mupem + lp_rec)
muplus_ideff_nlorw.SetPassCut(lp_muid)
muplus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_ideff_nlorw.AddVars(mupemvars)
muplus_ideff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_ideff_nlorw.Run()
#muplus_ideff_nlorw.SaveToFile()

muminus_ideff_nlorw = EfficiencyClass("muminus_ideff_nlorw")
muminus_ideff_nlorw.SetSelectionCut(fid + mumep + lm_rec)
muminus_ideff_nlorw.SetPassCut(lm_muid)
muminus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_ideff_nlorw.AddVars(mumepvars)
muminus_ideff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_ideff_nlorw.Run()
#muminus_ideff_nlorw.SaveToFile()

mu_ideff_nlorw = EfficiencyClass("mu_ideff_nlorw", muplus_ideff_nlorw, muminus_ideff_nlorw)
mu_ideff_nlorw.MakeEfficiencyGraph()
mu_ideff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_ideff_nlorw.root")

muplus_ideff_effrw = EfficiencyClass("muplus_ideff_effrw")
muplus_ideff_effrw.SetSelectionCut(fid + mupem + lp_rec)
muplus_ideff_effrw.SetPassCut(lp_muid)
muplus_ideff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_ideff_effrw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_ideff_effrw.AddVars(mupemvars)
muplus_ideff_effrw.ScaleErrs = True
muplus_ideff_effrw.ReweightEff("lp_ETA", "lp_PT/1000.0", mf.Get('pt_eta_id_weights'))
muplus_ideff_effrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_ideff_effrw.Run()
#muplus_ideff_effrw.SaveToFile()

muminus_ideff_effrw = EfficiencyClass("muminus_ideff_effrw")
muminus_ideff_effrw.SetSelectionCut(fid + mumep + lm_rec)
muminus_ideff_effrw.SetPassCut(lm_muid)
muminus_ideff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_ideff_effrw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_ideff_effrw.AddVars(mumepvars)
muminus_ideff_effrw.ScaleErrs = True
muminus_ideff_effrw.ReweightEff("lm_ETA", "lm_PT/1000.0", mf.Get('pt_eta_id_weights'))
muminus_ideff_effrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_ideff_effrw.Run()
#muminus_ideff_effrw.SaveToFile()

mu_ideff_effrw = EfficiencyClass("mu_ideff_effrw", muplus_ideff_effrw, muminus_ideff_effrw)
mu_ideff_effrw.MakeEfficiencyGraph()
mu_ideff_effrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_ideff_effrw.root")


muplus_ideff_wtrw = EfficiencyClass("muplus_ideff_wtrw")
muplus_ideff_wtrw.SetSelectionCut(fid + mupem + lp_rec)
muplus_ideff_wtrw.SetPassCut(lp_muid)
muplus_ideff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_ideff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_ideff_wtrw.AddVars(mupemvars)
muplus_ideff_wtrw.ScaleErrs = True
muplus_ideff_wtrw.ReweightEff("lp_ETA", "lp_PT/1000.0", mf.Get('pt_eta_id_weights'))
muplus_ideff_wtrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_wt_powheg_lp_pt10_lp_eta10"))
muplus_ideff_wtrw.Run()
#muplus_ideff_wtrw.SaveToFile()

muminus_ideff_wtrw = EfficiencyClass("muminus_ideff_wtrw")
muminus_ideff_wtrw.SetSelectionCut(fid + mumep + lm_rec)
muminus_ideff_wtrw.SetPassCut(lm_muid)
muminus_ideff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_ideff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_ideff_wtrw.AddVars(mumepvars)
muminus_ideff_wtrw.ScaleErrs = True
muminus_ideff_wtrw.ReweightEff("lm_ETA", "lm_PT/1000.0", mf.Get('pt_eta_id_weights'))
muminus_ideff_wtrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_wt_powheg_lm_pt10_lm_eta10"))
muminus_ideff_wtrw.Run()
#muminus_ideff_wtrw.SaveToFile()

mu_ideff_wtrw = EfficiencyClass("mu_ideff_wtrw", muplus_ideff_wtrw, muminus_ideff_wtrw)
mu_ideff_wtrw.MakeEfficiencyGraph()
mu_ideff_wtrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_ideff_wtrw.root")


muplus_triggereff = EfficiencyClass("muplus_triggereff")
muplus_triggereff.SetSelectionCut(fid + mupem + lp_rec + lp_muid)
muplus_triggereff.SetPassCut(lp_mutrigger)
muplus_triggereff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_triggereff.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_triggereff.AddVars(mupemvars)
muplus_triggereff.Run()
#muplus_triggereff.SaveToFile()

muminus_triggereff = EfficiencyClass("muminus_triggereff")
muminus_triggereff.SetSelectionCut(fid + mumep + lm_rec + lm_muid)
muminus_triggereff.SetPassCut(lm_mutrigger)
muminus_triggereff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_triggereff.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_triggereff.AddVars(mumepvars)
muminus_triggereff.Run()
#muminus_triggereff.SaveToFile()

mu_triggereff = EfficiencyClass("mu_triggereff", muplus_triggereff, muminus_triggereff)
mu_triggereff.MakeEfficiencyGraph()
mu_triggereff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff.root")


muplus_triggereff_nlorw = EfficiencyClass("muplus_triggereff_nlorw")
muplus_triggereff_nlorw.SetSelectionCut(fid + mupem + lp_rec + lp_muid)
muplus_triggereff_nlorw.SetPassCut(lp_mutrigger)
muplus_triggereff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_triggereff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_triggereff_nlorw.AddVars(mupemvars)
muplus_triggereff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_triggereff_nlorw.Run()
#muplus_triggereff_nlorw.SaveToFile()

muminus_triggereff_nlorw = EfficiencyClass("muminus_triggereff_nlorw")
muminus_triggereff_nlorw.SetSelectionCut(fid + mumep + lm_rec + lm_muid)
muminus_triggereff_nlorw.SetPassCut(lm_mutrigger)
muminus_triggereff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_triggereff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_triggereff_nlorw.AddVars(mumepvars)
muminus_triggereff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_triggereff_nlorw.Run()
#muminus_triggereff_nlorw.SaveToFile()

mu_triggereff_nlorw = EfficiencyClass("mu_triggereff_nlorw", muplus_triggereff_nlorw, muminus_triggereff_nlorw)
mu_triggereff_nlorw.MakeEfficiencyGraph()
mu_triggereff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff_nlorw.root")


muplus_triggereff_effrw = EfficiencyClass("muplus_triggereff_effrw")
muplus_triggereff_effrw.SetSelectionCut(fid + mupem + lp_rec + lp_muid)
muplus_triggereff_effrw.SetPassCut(lp_mutrigger)
muplus_triggereff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_triggereff_effrw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_triggereff_effrw.AddVars(mupemvars)
muplus_triggereff_effrw.ScaleErrs = True
muplus_triggereff_effrw.ReweightEff("lp_ETA", "lp_PT/1000.0", mf.Get('pt_eta_trg_weights'))
muplus_triggereff_effrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_triggereff_effrw.Run()
#muplus_triggereff_effrw.SaveToFile()

muminus_triggereff_effrw = EfficiencyClass("muminus_triggereff_effrw")
muminus_triggereff_effrw.SetSelectionCut(fid + mumep + lm_rec + lm_muid)
muminus_triggereff_effrw.SetPassCut(lm_mutrigger)
muminus_triggereff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_triggereff_effrw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_triggereff_effrw.AddVars(mumepvars)
muminus_triggereff_effrw.ScaleErrs = True
muminus_triggereff_effrw.ReweightEff("lm_ETA", "lm_PT/1000.0", mf.Get('pt_eta_trg_weights'))
muminus_triggereff_effrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_triggereff_effrw.Run()
#muminus_triggereff_effrw.SaveToFile()

mu_triggereff_effrw = EfficiencyClass("mu_triggereff_effrw", muplus_triggereff_effrw, muminus_triggereff_effrw)
mu_triggereff_effrw.MakeEfficiencyGraph()
mu_triggereff_effrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff_effrw.root")

muplus_triggereff_wtrw = EfficiencyClass("muplus_triggereff_wtrw")
muplus_triggereff_wtrw.SetSelectionCut(fid + mupem + lp_rec + lp_muid)
muplus_triggereff_wtrw.SetPassCut(lp_mutrigger)
muplus_triggereff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muplus_triggereff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
muplus_triggereff_wtrw.AddVars(mupemvars)
muplus_triggereff_wtrw.ScaleErrs = True
muplus_triggereff_wtrw.ReweightEff("lp_ETA", "lp_PT/1000.0", mf.Get('pt_eta_trg_weights'))
muplus_triggereff_wtrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_wt_powheg_lp_pt10_lp_eta10"))
muplus_triggereff_wtrw.Run()
#muplus_triggereff_wtrw.SaveToFile()

muminus_triggereff_wtrw = EfficiencyClass("muminus_triggereff_wtrw")
muminus_triggereff_wtrw.SetSelectionCut(fid + mumep + lm_rec + lm_muid)
muminus_triggereff_wtrw.SetPassCut(lm_mutrigger)
muminus_triggereff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
muminus_triggereff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
muminus_triggereff_wtrw.AddVars(mumepvars)
muminus_triggereff_wtrw.ScaleErrs = True
muminus_triggereff_wtrw.ReweightEff("lm_ETA", "lm_PT/1000.0", mf.Get('pt_eta_trg_weights'))
muminus_triggereff_wtrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_wt_powheg_lm_pt10_lm_eta10"))
muminus_triggereff_wtrw.Run()
#muminus_triggereff_wtrw.SaveToFile()

mu_triggereff_wtrw = EfficiencyClass("mu_triggereff_wtrw", muplus_triggereff_wtrw, muminus_triggereff_wtrw)
mu_triggereff_wtrw.MakeEfficiencyGraph()
mu_triggereff_wtrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_triggereff_wtrw.root")


mu_trkeff_obj = eff_vals('mu_trkeff',
                         mu_trackeff_effrw.GetTotEff(),
                         mu_trackeff_effrw.GetTotEffErrLo(),
                         abs(mu_trackeff.GetTotEff() - mu_trackeff_nlorw.GetTotEff()),
                         mu_trackeff_effrw.GetTotEffRWErr())

mu_ideff_obj  = eff_vals('mu_ideff',
                         mu_ideff_effrw.GetTotEff(),
                         mu_ideff_effrw.GetTotEffErrLo(),
                         abs(mu_ideff.GetTotEff() - mu_ideff_nlorw.GetTotEff()),
                         mu_ideff_effrw.GetTotEffRWErr())

mu_trgeff_obj = eff_vals('mu_trgeff',
                         mu_triggereff_effrw.GetTotEff(),
                         mu_triggereff_effrw.GetTotEffErrLo(),
                         abs(mu_triggereff.GetTotEff() - mu_triggereff_nlorw.GetTotEff()),
                         mu_triggereff_effrw.GetTotEffRWErr())

mu_wt_trkeff_obj = eff_vals('mu_wt_trkeff',
                            mu_trackeff_wtrw.GetTotEff(),
                            mu_trackeff_wtrw.GetTotEffErrLo(),
                            0.0,
                            mu_trackeff_effrw.GetTotEffRWErr())

mu_wt_ideff_obj  = eff_vals('mu_wt_ideff',
                            mu_ideff_wtrw.GetTotEff(),
                            mu_ideff_wtrw.GetTotEffErrLo(),
                            0.0,
                            mu_ideff_wtrw.GetTotEffRWErr())

mu_wt_trgeff_obj = eff_vals('mu_wt_trgeff',
                            mu_triggereff_wtrw.GetTotEff(),
                            mu_triggereff_wtrw.GetTotEffErrLo(),
                            0.0,
                            mu_triggereff_wtrw.GetTotEffRWErr())


outputFile = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mu_effs.root", "RECREATE")
mu_trkeff_obj.write()
mu_ideff_obj.write()
mu_trgeff_obj.write()
mu_wt_trkeff_obj.write()
mu_wt_ideff_obj.write()
mu_wt_trgeff_obj.write()
outputFile.Close()
