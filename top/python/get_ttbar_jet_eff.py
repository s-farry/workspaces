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
jet_rec = TCut("ttbar_recjet_PT > 12500")
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
    ["cpf"          , "ttbar_jet_cpf"   , 20, 0, 1],
    ["mult",    "ttbar_jet_ndauts" , 26, -0.5, 25.5],
    ["mpt",     "ttbar_jet_mpt" , 20, 0, 40000.0],
    ["mtf",     "ttbar_jet_mtf" , 20, 0, 1.0 ],
    ["npoint",  "ttbar_jet_npoint" ,23, -0.5, 45.5],
    ["width",   "ttbar_jet_width" , 20, 0, 1.0 ],
    ["n90",     "ttbar_jet_n90" , 16, -0.5, 15.5],
    ["eiso"         , "e_cpt_0.50/1000.0"       , 10, 0, 20],
    ["muiso"        , "mu_cpt_0.50/1000.0"      , 10, 0, 20],
    ["iso"          , "max(mu_cpt_0.50,e_cpt_0.50)/1000.0" , 10, 0, 20],
    ]

recvars2d = [ ['ptj', 'etaj'] ]

# get other efficiencies from fully reconstructed version
kinematic = TCut("mu_ETA > 2.0 && mu_ETA < 4.5 && e_ETA > 2.0 && e_ETA < 4.5 && mu_PT > 20000 && e_PT > 20000 && ttbar_jet_PT > 20000")
ip  = TCut("mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
iso = TCut("mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000")
iso = TCut("mu_cpt_0.50 < 5000")
trueb = TCut("ttbar_mcjet_PT > 12500 && abs(ttbar_mcjet_flavour) == 5")
jettag = TCut("ttbar_jet_BDTTag == 1")
'''
jeteff_mupem = EfficiencyClass("jeteff_mupem")
jeteff_mupem.SetSelectionCut(fid + lp_rec + lm_rec + mupem)
jeteff_mupem.SetPassCut(jet_rec)
jeteff_mupem.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
jeteff_mupem.AddTrees(gg2ttbar_mc2016.true_trees())
jeteff_mupem.AddVars(mupemvars)
jeteff_mupem.Run()
#jeteff_mupem.SaveToFile()

jeteff_mumep = EfficiencyClass("jeteff_mumep")
jeteff_mumep.SetSelectionCut(fid + lp_rec + lm_rec + mumep)
jeteff_mumep.SetPassCut(jet_rec)
jeteff_mumep.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
jeteff_mumep.AddTrees(gg2ttbar_mc2016.true_trees())
jeteff_mumep.AddVars(mumepvars)
jeteff_mumep.Run()
#jeteff_mumep.SaveToFile()

jeteff = EfficiencyClass("jeteff", jeteff_mupem, jeteff_mumep)
jeteff.MakeEfficiencyGraph()
jeteff.SaveToFile("/user2/sfarry/workspaces/top/tuples/jeteff.root")

jeteff_mupem_nlorw = EfficiencyClass("jeteff_mupem_nlorw")
jeteff_mupem_nlorw.SetSelectionCut(fid + lp_rec + lm_rec + mupem)
jeteff_mupem_nlorw.SetPassCut(jet_rec)
jeteff_mupem_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
jeteff_mupem_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
jeteff_mupem_nlorw.AddVars(mupemvars)
jeteff_mupem_nlorw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_tt_amcatnlo_ptj10_etaj10"))
jeteff_mupem_nlorw.Run()
#jeteff_mupem.SaveToFile()

jeteff_mumep_nlorw = EfficiencyClass("jeteff_mumep_nlorw")
jeteff_mumep_nlorw.SetSelectionCut(fid + lp_rec + lm_rec + mumep)
jeteff_mumep_nlorw.SetPassCut(jet_rec)
jeteff_mumep_nlorw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
jeteff_mumep_nlorw.AddTrees(gg2ttbar_mc2016.true_trees())
jeteff_mumep_nlorw.AddVars(mumepvars)
jeteff_mumep_nlorw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_tt_amcatnlo_ptj10_etaj10"))
jeteff_mumep_nlorw.Run()
#jeteff_mumep.SaveToFile()

jeteff_nlorw = EfficiencyClass("jeteff_nlorw", jeteff_mupem_nlorw, jeteff_mumep_nlorw)
jeteff_nlorw.MakeEfficiencyGraph()
jeteff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/jeteff_nlorw.root")

jeteff_mupem_wtrw = EfficiencyClass("jeteff_mupem_wtrw")
jeteff_mupem_wtrw.SetSelectionCut(fid + lp_rec + lm_rec + mupem)
jeteff_mupem_wtrw.SetPassCut(jet_rec)
jeteff_mupem_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
jeteff_mupem_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
jeteff_mupem_wtrw.AddVars(mupemvars)
jeteff_mupem_wtrw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_wt_powheg_ptj10_etaj10"))
jeteff_mupem_wtrw.Run()
#jeteff_mupem.SaveToFile()

jeteff_mumep_wtrw = EfficiencyClass("jeteff_mumep_wtrw")
jeteff_mumep_wtrw.SetSelectionCut(fid + lp_rec + lm_rec + mumep)
jeteff_mumep_wtrw.SetPassCut(jet_rec)
jeteff_mumep_wtrw.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
jeteff_mumep_wtrw.AddTrees(gg2ttbar_mc2016.true_trees())
jeteff_mumep_wtrw.AddVars(mumepvars)
jeteff_mumep_wtrw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_wt_powheg_ptj10_etaj10"))
jeteff_mumep_wtrw.Run()
#jeteff_mumep.SaveToFile()

jeteff_wtrw = EfficiencyClass("jeteff_wtrw", jeteff_mupem_wtrw, jeteff_mumep_wtrw)
jeteff_wtrw.MakeEfficiencyGraph()
jeteff_wtrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/jeteff_wtrw.root")

'''
tageff = EfficiencyClass("tageff")
tageff.SetSelectionCut(kinematic + trueb)
tageff.SetPassCut(jettag)
tageff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale)
tageff.AddTrees(gg2ttbar_mc2016.trees())
tageff.AddVars(recvars)
tageff.Add2DVars(recvars2d)
tageff.Run()
tageff.SaveToFile("/user2/sfarry/workspaces/top/tuples/tageff.root")

tageff_2012 = EfficiencyClass("tageff_2012")
tageff_2012.SetSelectionCut(kinematic + trueb)
tageff_2012.SetPassCut(jettag)
tageff_2012.AddTrees(qq2ttbar_mc2012.trees(), tt_qq_scale / tt_gg_scale)
tageff_2012.AddTrees(gg2ttbar_mc2012.trees())
tageff_2012.AddVars(recvars)
tageff_2012.Add2DVars(recvars2d)
tageff_2012.Run()
tageff_2012.SaveToFile("/user2/sfarry/workspaces/top/tuples/tageff_2012.root")

tageff_nlorw = EfficiencyClass("tageff_nlorw")
tageff_nlorw.SetSelectionCut(kinematic + trueb)
tageff_nlorw.SetPassCut(jettag)
tageff_nlorw.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale)
tageff_nlorw.AddTrees(gg2ttbar_mc2016.trees())
tageff_nlorw.AddVars(recvars)
tageff_nlorw.Add2DVars(recvars2d)
tageff_nlorw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_tt_amcatnlo_ptj10_etaj10"))
tageff_nlorw.Run()
tageff_nlorw.SaveToFile("/user2/sfarry/workspaces/top/tuples/tageff_nlorw.root")

tageff_wtrw = EfficiencyClass("tageff_wtrw")
tageff_wtrw.SetSelectionCut(kinematic + trueb)
tageff_wtrw.SetPassCut(jettag)
tageff_wtrw.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale)
tageff_wtrw.AddTrees(gg2ttbar_mc2016.trees())
tageff_wtrw.AddVars(recvars)
tageff_wtrw.Reweight("ttbar_jet_PT/1000.0", "ttbar_jet_ETA", wf.Get("sf_wt_powheg_ptj10_etaj10"))
tageff_wtrw.Run()
tageff_wtrw.SaveToFile("/user2/sfarry/workspaces/top/tuples/tageff_wtrw.root")
'''
jet_receff_obj = eff_vals('jet_receff',
                          jeteff_nlorw.GetTotEff(),
                          jeteff_nlorw.GetTotEffErrLo(),
                          abs(jeteff.GetTotEff() - jeteff_nlorw.GetTotEff()),
                          jeteff_nlorw.GetTotEff() * 0.02)

jet_tageff_obj = eff_vals('jet_tageff',
                          tageff_nlorw.GetTotEff(),
                          tageff_nlorw.GetTotEffErrLo(),
                          abs(tageff.GetTotEff() - tageff_nlorw.GetTotEff()),
                          tageff.GetTotEff() * 0.05)

jet_wt_receff_obj = eff_vals('jet_wt_receff',
                          jeteff_wtrw.GetTotEff(),
                          jeteff_wtrw.GetTotEffErrLo(),
                          abs(jeteff.GetTotEff() - jeteff_wtrw.GetTotEff()),
                          jeteff_wtrw.GetTotEff() * 0.02)

jet_wt_tageff_obj = eff_vals('jet_wt_tageff',
                          tageff_wtrw.GetTotEff(),
                          tageff_wtrw.GetTotEffErrLo(),
                          abs(tageff.GetTotEff() - tageff_wtrw.GetTotEff()),
                          tageff_wtrw.GetTotEff() * 0.05)

outputFile = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_jet_effs.root", "RECREATE")
jet_receff_obj.write()
jet_tageff_obj.write()
jet_wt_receff_obj.write()
jet_wt_tageff_obj.write()
outputFile.Close()
'''
