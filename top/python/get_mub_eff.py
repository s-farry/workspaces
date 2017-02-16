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

fid_plus   = TCut("lp_ID == -13 && lp_ETA > 2 && lp_ETA < 4.5 && lp_PT > 20000 && ttbar_jet_PT > 20000 && abs(ttbar_jet_flavour) == 5")
fid_minus  = TCut("lm_ID == 13 && lm_ETA > 2 && lm_ETA < 4.5 && lm_PT > 20000 && ttbar_jet_PT > 20000 && abs(ttbar_jet_flavour) == 5")

lp_rec = TCut("lp_isRec == 1")
lm_rec = TCut("lm_isRec == 1")
jet_rec = TCut("ttbar_recjet_PT > 0")
lp_muid = TCut("lp_rec_ISMUON == 1")
lm_muid = TCut("lm_rec_ISMUON == 1")

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
wf = TFile("/user2/sfarry/workspaces/top/tuples/top_mub_weights.root")

pvars = [
    ["mu_pt"        , "lp_PT/1000.0"           , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(lp_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]
mvars = [
    ["mu_pt"        , "lm_PT/1000.0"           , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(lm_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]

recvars = [
    ["mu_pt"        , "muminus_PT/1000.0"           , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(muminus_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "muminus_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "muminus_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["muiso"        , "muminus_cpt_0.50/1000.0"      , 10, 0, 20],
    ["iso"          , "muminus_cpt_0.50/1000.0" , 10, 0, 20],
    ]

muplus_trackeff = EfficiencyClass("muplus_mub_trackeff")
muplus_trackeff.SetSelectionCut(fid_plus)
muplus_trackeff.SetPassCut(lp_rec)
muplus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_trackeff.AddVars(mupemvars)
#muplus_trackeff.ReweightEff("lp_P", "lp_ETA", ratio)
muplus_trackeff.ScaleErrs = True
muplus_trackeff.Run()
muplus_trackeff.SaveToFile()

muminus_trackeff = EfficiencyClass("muminus_mub_trackeff")
muminus_trackeff.SetSelectionCut(fid_minus)
muminus_trackeff.SetPassCut(lm_rec)
muminus_trackeff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_trackeff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_trackeff.AddVars(mvars)
muminus_trackeff.ScaleErrs = True
muminus_trackeff.Run()
muminus_trackeff.SaveToFile()


mu_trackeff = EfficiencyClass("mu_trackeff", muplus_trackeff, muminus_trackeff)
mu_trackeff.ScaleErrs = True
mu_trackeff.MakeEfficiencyGraph()
mu_trackeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_mub_trackeff.root")

muplus_trackeff_nlorw = EfficiencyClass("muplus_mub_trackeff_nlorw")
muplus_trackeff_nlorw.SetSelectionCut(fid_plus)
muplus_trackeff_nlorw.SetPassCut(lp_rec)
muplus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_trackeff_nlorw.AddVars(pvars)
#muplus_trackeff_nlorw.ReweightEff("lp_P", "lp_ETA", ratio)
muplus_trackeff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_trackeff_nlorw.ScaleErrs = True
muplus_trackeff_nlorw.Run()
muplus_trackeff_nlorw.SaveToFile()

muminus_trackeff_nlorw = EfficiencyClass("muminus_mub_trackeff_nlorw")
muminus_trackeff_nlorw.SetSelectionCut(fid_minus)
muminus_trackeff_nlorw.SetPassCut(lm_rec)
muminus_trackeff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_trackeff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_trackeff_nlorw.AddVars(mvars)
muminus_trackeff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_trackeff_nlorw.ScaleErrs = True
muminus_trackeff_nlorw.Run()
muminus_trackeff_nlorw.SaveToFile()

mu_trackeff_nlorw = EfficiencyClass("mu_mub_trackeff_nlorw", muplus_trackeff_nlorw, muminus_trackeff_nlorw)
mu_trackeff_nlorw.ScaleErrs = True
mu_trackeff_nlorw.MakeEfficiencyGraph()
mu_trackeff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_mub_trackeff_nlorw.root")

muplus_ideff = EfficiencyClass("muplus_mub_ideff")
muplus_ideff.SetSelectionCut(fid_plus + lp_rec)
muplus_ideff.SetPassCut(lp_muid)
muplus_ideff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_ideff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_ideff.AddVars(pvars)
muplus_ideff.Run()
#muplus_ideff.SaveToFile()

muminus_ideff = EfficiencyClass("muminus_mub_ideff")
muminus_ideff.SetSelectionCut(fid_minus + lm_rec)
muminus_ideff.SetPassCut(lm_muid)
muminus_ideff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_ideff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_ideff.AddVars(mpvars)
muminus_ideff.Run()
#muminus_ideff.SaveToFile()

mu_ideff = EfficiencyClass("mu_ideff", muplus_ideff, muminus_ideff)
mu_ideff.MakeEfficiencyGraph()
mu_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_mub_ideff.root")

muplus_ideff_nlorw = EfficiencyClass("muplus_mub_ideff_nlorw")
muplus_ideff_nlorw.SetSelectionCut(fid_plus + lp_rec)
muplus_ideff_nlorw.SetPassCut(lp_muid)
muplus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_ideff_nlorw.AddVars(pvars)
muplus_ideff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_ideff_nlorw.Run()
#muplus_ideff_nlorw.SaveToFile()

muminus_ideff_nlorw = EfficiencyClass("muminus_ideff_nlorw")
muminus_ideff_nlorw.SetSelectionCut(fid_minus + lm_rec)
muminus_ideff_nlorw.SetPassCut(lm_muid)
muminus_ideff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_ideff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_ideff_nlorw.AddVars(mvars)
muminus_ideff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_ideff_nlorw.Run()
#muminus_ideff_nlorw.SaveToFile()

mu_ideff_nlorw = EfficiencyClass("mu_ideff_nlorw", muplus_ideff_nlorw, muminus_ideff_nlorw)
mu_ideff_nlorw.MakeEfficiencyGraph()
mu_ideff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_mub_ideff_nlorw.root")


muplus_triggereff = EfficiencyClass("muplus_mub_triggereff")
muplus_triggereff.SetSelectionCut(fid_plus + lp_rec + lp_muid)
muplus_triggereff.SetPassCut(lp_mutrigger)
muplus_triggereff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_triggereff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_triggereff.AddVars(pvars)
muplus_triggereff.Run()
#muplus_triggereff.SaveToFile()

muminus_triggereff = EfficiencyClass("muminus_mub_triggereff")
muminus_triggereff.SetSelectionCut(fid_minus + lm_rec + lm_muid)
muminus_triggereff.SetPassCut(lm_mutrigger)
muminus_triggereff.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_triggereff.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_triggereff.AddVars(mvars)
muminus_triggereff.Run()
#muminus_triggereff.SaveToFile()

mu_triggereff = EfficiencyClass("mu_mub_triggereff", muplus_triggereff, muminus_triggereff)
mu_triggereff.MakeEfficiencyGraph()
mu_triggereff.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_mub_triggereff.root")


muplus_triggereff_nlorw = EfficiencyClass("muplus_mub_triggereff_nlorw")
muplus_triggereff_nlorw.SetSelectionCut(fid_plus + lp_rec + lp_muid)
muplus_triggereff_nlorw.SetPassCut(lp_mutrigger)
muplus_triggereff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muplus_triggereff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muplus_triggereff_nlorw.AddVars(pvars)
muplus_triggereff_nlorw.Reweight("lp_PT/1000.0", "lp_ETA", wf.Get("sf_tt_amcatnlo_lp_pt10_lp_eta10"))
muplus_triggereff_nlorw.Run()
#muplus_triggereff_nlorw.SaveToFile()

muminus_triggereff_nlorw = EfficiencyClass("muminus_mub_triggereff_nlorw")
muminus_triggereff_nlorw.SetSelectionCut(fid_minus + lm_rec + lm_muid)
muminus_triggereff_nlorw.SetPassCut(lm_mutrigger)
muminus_triggereff_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
muminus_triggereff_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
muminus_triggereff_nlorw.AddVars(mvars)
muminus_triggereff_nlorw.Reweight("lm_PT/1000.0", "lm_ETA", wf.Get("sf_tt_amcatnlo_lm_pt10_lm_eta10"))
muminus_triggereff_nlorw.Run()
#muminus_triggereff_nlorw.SaveToFile()

mu_triggereff_nlorw = EfficiencyClass("mu_triggereff_nlorw", muplus_triggereff_nlorw, muminus_triggereff_nlorw)
mu_triggereff_nlorw.MakeEfficiencyGraph()
mu_triggereff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/mu_mub_triggereff_nlorw.root")

jeteff_plus = EfficiencyClass("jeteff_plus")
jeteff_plus.SetSelectionCut(fid_plus + lp_rec)
jeteff_plus.SetPassCut(jet_rec)
jeteff_plus.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
jeteff_plus.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
jeteff_plus.AddVars(pvars)
jeteff_plus.Run()
#jeteff_mupem.SaveToFile()

jeteff_minus = EfficiencyClass("jeteff_minus")
jeteff_minus.SetSelectionCut(fid_minus + lm_rec)
jeteff_minus.SetPassCut(jet_rec)
jeteff_minus.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
jeteff_minus.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
jeteff_minus.AddVars(mumepvars)
jeteff_minus.Run()
#jeteff_mumep.SaveToFile()

jeteff = EfficiencyClass("jeteff", jeteff_mupem, jeteff_mumep)
jeteff.MakeEfficiencyGraph()
jeteff.SaveToFile("/user2/sfarry/workspaces/top/tuples/jeteff_mub.root")

jeteff_plus_nlorw = EfficiencyClass("jeteff_plus_nlorw")
jeteff_plus_nlorw.SetSelectionCut(fid_plus + lp_rec)
jeteff_plus_nlorw.SetPassCut(jet_rec)
jeteff_plus_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
jeteff_plus_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(). tt_gg_scale)
jeteff_plus_nlorw.AddVars(pvars)
jeteff_plus_nlorw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_tt_amcatnlo_ptj10_etaj10"))
jeteff_plus_nlorw.Run()
#jeteff_mupem.SaveToFile()

jeteff_minus_nlorw = EfficiencyClass("jeteff_minus_nlorw")
jeteff_minus_nlorw.SetSelectionCut(fid_minus + lm_rec)
jeteff_minus_nlorw.SetPassCut(jet_rec)
jeteff_minus_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
jeteff_minus_nlorw.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
jeteff_minus_nlorw.AddVars(mvars)
jeteff_minus_nlorw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_tt_amcatnlo_ptj10_etaj10"))
jeteff_minus_nlorw.Run()
#jeteff_mumep.SaveToFile()

jeteff_nlorw = EfficiencyClass("jeteff_mub_nlorw", jeteff_mupem_nlorw, jeteff_mumep_nlorw)
jeteff_nlorw.MakeEfficiencyGraph()
jeteff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/jeteff_nlorw.root")

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



outputFile = TFile("ttbar_mub_effs.root")
mu_trkeff_obj.Write()
mu_ideff_obj.Write()
mu_trgeff_obj.Write()
e_trkeff_obj.Write()
e_ideff_obj.Write()
jet_receff_obj.Write()
jet_tageff_obj.Write()
selfeff_obj.Write()
outputFile.Close()
