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

eplus_trackeff = EfficiencyClass("eplus_trackeff")
eplus_trackeff.SetSelectionCut(fid + mumep)
eplus_trackeff.SetPassCut(lp_rec)
eplus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eplus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_trackeff.AddVars(mumepvars)
eplus_trackeff.Run()
#eplus_trackeff.SaveToFile()

eminus_trackeff = EfficiencyClass("eminus_trackeff")
eminus_trackeff.SetSelectionCut(fid + mupem)
eminus_trackeff.SetPassCut(lm_rec)
eminus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale/tt_gg_scale)
eminus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_trackeff.AddVars(mupemvars)
eminus_trackeff.Run()
#eminus_trackeff.SaveToFile()

e_trackeff = EfficiencyClass("e_trackeff", eplus_trackeff, eminus_trackeff)
e_trackeff.MakeEfficiencyGraph()
e_trackeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trackeff.root")


eplus_trackeff_nlorw = EfficiencyClass("eplus_trackeff_nlorw")
eplus_trackeff_nlorw.SetSelectionCut(fid + mumep)
eplus_trackeff_nlorw.SetPassCut(lp_rec)
eplus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eplus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_trackeff_nlorw.AddVars(mumepvars)
eplus_trackeff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
eplus_trackeff_nlorw.Run()
#eplus_trackeff_nlorw.SaveToFile()

eminus_trackeff_nlorw = EfficiencyClass("eminus_trackeff_nlorw")
eminus_trackeff_nlorw.SetSelectionCut(fid + mupem)
eminus_trackeff_nlorw.SetPassCut(lm_rec)
eminus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eminus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_trackeff_nlorw.AddVars(mupemvars)
eminus_trackeff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
eminus_trackeff_nlorw.Run()
#eminus_trackeff_nlorw.SaveToFile()

e_trackeff_nlorw = EfficiencyClass("e_trackeff_nlorw", eplus_trackeff_nlorw, eminus_trackeff_nlorw)
e_trackeff_nlorw.MakeEfficiencyGraph()
e_trackeff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trackeff_nlorw.root")


eplus_trackeff_wtrw = EfficiencyClass("eplus_trackeff_wtrw")
eplus_trackeff_wtrw.SetSelectionCut(fid + mumep)
eplus_trackeff_wtrw.SetPassCut(lp_rec)
eplus_trackeff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eplus_trackeff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_trackeff_wtrw.AddVars(mumepvars)
eplus_trackeff_wtrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_wt_powheg_lp_pt10_lp_eta10"))
eplus_trackeff_wtrw.Run()
#eplus_trackeff_wtrw.SaveToFile()

eminus_trackeff_wtrw = EfficiencyClass("eminus_trackeff_wtrw")
eminus_trackeff_wtrw.SetSelectionCut(fid + mupem)
eminus_trackeff_wtrw.SetPassCut(lm_rec)
eminus_trackeff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eminus_trackeff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_trackeff_wtrw.AddVars(mupemvars)
eminus_trackeff_wtrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_wt_powheg_lm_pt10_lm_eta10"))
eminus_trackeff_wtrw.Run()
#eminus_trackeff_wtrw.SaveToFile()

e_trackeff_wtrw = EfficiencyClass("e_trackeff_wtrw", eplus_trackeff_wtrw, eminus_trackeff_wtrw)
e_trackeff_wtrw.MakeEfficiencyGraph()
e_trackeff_wtrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trackeff_wtrw.root")


eplus_ideff = EfficiencyClass("eplus_ideff")
eplus_ideff.SetSelectionCut(fid + mumep + lp_rec)
eplus_ideff.SetPassCut(lp_eid)
eplus_ideff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eplus_ideff.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_ideff.AddVars(mumepvars)
eplus_ideff.Run()
#eplus_ideff.SaveToFile()

eminus_ideff = EfficiencyClass("eminus_ideff")
eminus_ideff.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff.SetPassCut(lm_eid)
eminus_ideff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
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
eplus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eplus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_ideff_nlorw.AddVars(mumepvars)
eplus_ideff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
eplus_ideff_nlorw.Run()
#eplus_ideff_nlorw.SaveToFile()

eminus_ideff_nlorw = EfficiencyClass("eminus_ideff_nlorw")
eminus_ideff_nlorw.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff_nlorw.SetPassCut(lm_eid)
eminus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
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
eplus_ideff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eplus_ideff_effrw.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_ideff_effrw.AddVars(mumepvars)
eplus_ideff_effrw.ScaleErrs = True
eplus_ideff_effrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
eplus_ideff_effrw.ReweightEff("lp_ETA", 'lp_PT/1000.0', ef.Get("zee_eid_weights_etapt"))
eplus_ideff_effrw.Run()
eplus_ideff_effrw.SaveToFile()

eminus_ideff_effrw = EfficiencyClass("eminus_ideff_effrw")
eminus_ideff_effrw.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff_effrw.SetPassCut(lm_eid)
eminus_ideff_effrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eminus_ideff_effrw.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_ideff_effrw.AddVars(mupemvars)
eminus_ideff_effrw.ScaleErrs = True
eminus_ideff_effrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
eminus_ideff_effrw.ReweightEff("lm_ETA", 'lm_PT/1000.0', ef.Get("zee_eid_weights_etapt"))
eminus_ideff_effrw.Run()
eminus_ideff_effrw.SaveToFile()

e_ideff_effrw = EfficiencyClass("e_ideff_effrw", eplus_ideff_effrw, eminus_ideff_effrw)
e_ideff_effrw.MakeEfficiencyGraph()
e_ideff_effrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ideff_effrw.root")

eplus_ideff_wtrw = EfficiencyClass("eplus_ideff_wtrw")
eplus_ideff_wtrw.SetSelectionCut(fid + mumep + lp_rec)
eplus_ideff_wtrw.SetPassCut(lp_eid)
eplus_ideff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eplus_ideff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
eplus_ideff_wtrw.AddVars(mumepvars)
eplus_ideff_wtrw.ScaleErrs = True
eplus_ideff_wtrw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_wt_powheg_lp_pt10_lp_eta10"))
eplus_ideff_wtrw.ReweightEff("lp_ETA", 'lp_PT/1000.0', ef.Get("zee_eid_weights_etapt"))
eplus_ideff_wtrw.Run()
eplus_ideff_wtrw.SaveToFile()

eminus_ideff_wtrw = EfficiencyClass("eminus_ideff_wtrw")
eminus_ideff_wtrw.SetSelectionCut(fid + mupem + lm_rec)
eminus_ideff_wtrw.SetPassCut(lm_eid)
eminus_ideff_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
eminus_ideff_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
eminus_ideff_wtrw.AddVars(mupemvars)
eminus_ideff_wtrw.ScaleErrs = True
eminus_ideff_wtrw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_wt_powheg_lm_pt10_lm_eta10"))
eminus_ideff_wtrw.ReweightEff("lm_ETA", 'lm_PT/1000.0', ef.Get("zee_eid_weights_etapt"))
eminus_ideff_wtrw.Run()
eminus_ideff_wtrw.SaveToFile()

e_ideff_wtrw = EfficiencyClass("e_ideff_wtrw", eplus_ideff_wtrw, eminus_ideff_wtrw)
e_ideff_wtrw.MakeEfficiencyGraph()
e_ideff_wtrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ideff_wtrw.root")


'''
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

'''
e_trkeff_obj     = eff_vals('e_trkeff',
                            e_trackeff_nlorw.GetTotEff(),
                            e_trackeff_nlorw.GetTotEffErrLo(),
                            abs(e_trackeff.GetTotEff() - e_trackeff_nlorw.GetTotEff()),
                            e_trackeff_nlorw.GetTotEff() * 0.028)

e_ideff_obj   = eff_vals('e_ideff',
                         e_ideff_effrw.GetTotEff(),
                         e_ideff_effrw.GetTotEffErrLo(),
                         abs(e_ideff.GetTotEff() - e_ideff_nlorw.GetTotEff()),
                         e_ideff_effrw.GetTotEffRWErr())
e_wt_trkeff_obj     = eff_vals('e_wt_trkeff',
                               e_trackeff_wtrw.GetTotEff(),
                               e_trackeff_wtrw.GetTotEffErrLo(),
                               0.0,
                               e_trackeff_wtrw.GetTotEff() * 0.028)

e_wt_ideff_obj   = eff_vals('e_wt_ideff',
                            e_ideff_wtrw.GetTotEff(),
                            e_ideff_wtrw.GetTotEffErrLo(),
                            0.0,
                            e_ideff_wtrw.GetTotEffRWErr())



outputFile = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_e_effs.root", "RECREATE")
e_trkeff_obj.write()
e_ideff_obj.write()
e_wt_trkeff_obj.write()
e_wt_ideff_obj.write()
outputFile.Close()

