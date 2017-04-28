from os import sys
import copy
from Jawa import *
from ROOT import TCut, TTree, TFile, TMath, TH1F, TF1, TH1, TParameter
from Utils import GetWeightHist, GetSpreadGraph, GetPDFGraph, asymm_details, ratio_details, details
from math import sqrt

from top_config import *

TH1.AddDirectory(False)

true_fid = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000 && ttbar_jet_PT > 20000 && abs(ttbar_jet_flavour) == 5 && ttbar_jet_ETA > 2.2 && ttbar_jet_ETA < 4.2")
rec_fid  = TCut("lp_rec_ETA > 2 && lp_rec_ETA < 4.5 && lm_rec_ETA > 2 && lm_rec_ETA < 4.5 && lp_rec_PT > 20000 && lm_rec_PT > 20000 && ttbar_recjet_PT > 20000 && abs(ttbar_jet_flavour) == 5 && ttbar_recjet_ETA > 2.2 && ttbar_recjet_ETA < 4.2")
rec_fid_lp_escale  = TCut("lp_rec_ETA > 2 && lp_rec_ETA < 4.5 && lm_rec_ETA > 2 && lm_rec_ETA < 4.5 && lp_rec_PT*0.997 > 20000 && lm_rec_PT > 20000 && ttbar_recjet_PT > 20000 && abs(ttbar_jet_flavour) == 5 && ttbar_recjet_ETA > 2.2 && ttbar_recjet_ETA < 4.2")
rec_fid_lm_escale  = TCut("lp_rec_ETA > 2 && lp_rec_ETA < 4.5 && lm_rec_ETA > 2 && lm_rec_ETA < 4.5 && lp_rec_PT > 20000 && lm_rec_PT*0.997 > 20000 && ttbar_recjet_PT > 20000 && abs(ttbar_jet_flavour) == 5 && ttbar_recjet_ETA > 2.2 && ttbar_recjet_ETA < 4.2")
rec_fid_jscale  = TCut("lp_rec_ETA > 2 && lp_rec_ETA < 4.5 && lm_rec_ETA > 2 && lm_rec_ETA < 4.5 && lp_rec_PT > 20000 && lm_rec_PT > 20000 && jscale.ptj_scaled > 20000 && abs(ttbar_jet_flavour) == 5 && ttbar_recjet_ETA > 2.2 && ttbar_recjet_ETA < 4.2")

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

mupem_recd = lp_rec + lm_rec + jet_rec + lp_muid + lm_eid + lp_mutrigger
mumep_recd = lp_rec + lm_rec + jet_rec + lp_eid + lm_muid + lm_mutrigger


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
#adjusted jet energy scale
gg2ttbar_mu_scale = TFile("/user2/sfarry/workspaces/top/tuples/ttbar.ttbar_gg.MU.MC2016.jscal.root")
gg2ttbar_md_scale = TFile("/user2/sfarry/workspaces/top/tuples/ttbar.ttbar_gg.MD.MC2016.jscal.root")
qq2ttbar_mu_scale = TFile("/user2/sfarry/workspaces/top/tuples/ttbar.ttbar_qqbar.MU.MC2016.jscal.root")
qq2ttbar_md_scale = TFile("/user2/sfarry/workspaces/top/tuples/ttbar.ttbar_qqbar.MD.MC2016.jscal.root")


mupem_true = Template("mupem_true")
mupem_true.SetSelCut(true_fid + mupem + mupem_recd)
mupem_true.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mupem_true.AddTrees(gg2ttbar_mc2016.true_trees())
mupem_true.Run()

mumep_true = Template("mumep_true")
mumep_true.SetSelCut(true_fid + mumep + mumep_recd)
mumep_true.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mumep_true.AddTrees(gg2ttbar_mc2016.true_trees())
mumep_true.Run()

mupem_rec = Template("mupem_rec")
mupem_rec.SetSelCut(rec_fid + mupem + mupem_recd)
mupem_rec.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mupem_rec.AddTrees(gg2ttbar_mc2016.true_trees())
mupem_rec.Run()

mumep_rec = Template("mumep_rec")
mumep_rec.SetSelCut(rec_fid + mumep + mumep_recd)
mumep_rec.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mumep_rec.AddTrees(gg2ttbar_mc2016.true_trees())
mumep_rec.Run()

mupem_rec_escale = Template("mupem_rec_escale")
mupem_rec_escale.SetSelCut(rec_fid_lm_escale + mupem + mupem_recd)
mupem_rec_escale.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mupem_rec_escale.AddTrees(gg2ttbar_mc2016.true_trees())
mupem_rec_escale.Run()

mumep_rec_escale = Template("mumep_rec_escale")
mumep_rec_escale.SetSelCut(rec_fid_lp_escale + mumep + mumep_recd)
mumep_rec_escale.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mumep_rec_escale.AddTrees(gg2ttbar_mc2016.true_trees())
mumep_rec_escale.Run()

qq2ttbar_mut = qq2ttbar_mc2016.MU_true_t
qq2ttbar_mdt = qq2ttbar_mc2016.MD_true_t
qq2ttbar_mut.AddFriend(qq2ttbar_mu_scale.Get('tree'), 'jscale')
qq2ttbar_mdt.AddFriend(qq2ttbar_md_scale.Get('tree'), 'jscale')
gg2ttbar_mut = gg2ttbar_mc2016.MU_true_t
gg2ttbar_mdt = gg2ttbar_mc2016.MD_true_t
gg2ttbar_mut.AddFriend(gg2ttbar_mu_scale.Get('tree'), 'jscale')
gg2ttbar_mdt.AddFriend(gg2ttbar_md_scale.Get('tree'), 'jscale')

mupem_rec_jscale = Template("mupem_rec_jscale")
mupem_rec_jscale.SetSelCut(rec_fid_jscale + mupem + mupem_recd)
mupem_rec_jscale.AddTree(qq2ttbar_mut, tt_qq_scale / tt_gg_scale)
mupem_rec_jscale.AddTree(qq2ttbar_mdt, tt_qq_scale / tt_gg_scale)
mupem_rec_jscale.AddTree(gg2ttbar_mut )
mupem_rec_jscale.AddTree(gg2ttbar_mdt )
mupem_rec_jscale.Run()

mumep_rec_jscale = Template("mumep_rec_escale")
mumep_rec_jscale.SetSelCut(rec_fid_jscale + mumep + mumep_recd)
mumep_rec_jscale.AddTree(qq2ttbar_mut, tt_qq_scale / tt_gg_scale)
mumep_rec_jscale.AddTree(qq2ttbar_mdt, tt_qq_scale / tt_gg_scale)
mumep_rec_jscale.AddTree(gg2ttbar_mut )
mumep_rec_jscale.AddTree(gg2ttbar_mdt )
mumep_rec_jscale.Run()

mupem_nlorw_true = Template("mupem_true")
mupem_nlorw_true.SetSelCut(true_fid + mupem + mupem_recd)
mupem_nlorw_true.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mupem_nlorw_true.AddTrees(gg2ttbar_mc2016.true_trees())
mupem_nlorw_true.Reweight("lm_PT/1000.0", "ttbar_jet_PT/1000.0", wf.Get("sf_tt_amcatnlo_lm_pt10_ptj10"))
mupem_nlorw_true.Run()

mumep_nlorw_true = Template("mumep_true")
mumep_nlorw_true.SetSelCut(true_fid + mumep + mumep_recd)
mumep_nlorw_true.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mumep_nlorw_true.AddTrees(gg2ttbar_mc2016.true_trees())
mumep_nlorw_true.Reweight("lp_PT/1000.0", "ttbar_jet_PT/1000.0", wf.Get("sf_tt_amcatnlo_lp_pt10_ptj10"))
mumep_nlorw_true.Run()

mupem_nlorw_rec = Template("mupem_rec")
mupem_nlorw_rec.SetSelCut(rec_fid + mupem + mupem_recd)
mupem_nlorw_rec.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mupem_nlorw_rec.AddTrees(gg2ttbar_mc2016.true_trees())
mupem_nlorw_rec.Reweight("lm_PT/1000.0", "ttbar_jet_PT/1000.0", wf.Get("sf_tt_amcatnlo_lm_pt10_ptj10"))
mupem_nlorw_rec.Run()

mumep_nlorw_rec = Template("mumep_rec")
mumep_nlorw_rec.SetSelCut(rec_fid + mumep + mumep_recd)
mumep_nlorw_rec.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale / tt_gg_scale)
mumep_nlorw_rec.AddTrees(gg2ttbar_mc2016.true_trees())
mumep_nlorw_rec.Reweight("lp_PT/1000.0", "ttbar_jet_PT/1000.0", wf.Get("sf_tt_amcatnlo_lp_pt10_ptj10"))
mumep_nlorw_rec.Run()


mumep_acc = mumep_true.GetNormEvts() / mumep_rec.GetNormEvts()
mupem_acc = mupem_true.GetNormEvts() / mupem_rec.GetNormEvts()

acc = (mupem_true.GetNormEvts() + mumep_true.GetNormEvts()) / (mupem_rec.GetNormEvts() + mumep_rec.GetNormEvts() )
acc_escale = (mupem_true.GetNormEvts() + mumep_true.GetNormEvts()) / (mupem_rec_escale.GetNormEvts() + mumep_rec_escale.GetNormEvts() )
acc_jscale = (mupem_true.GetNormEvts() + mumep_true.GetNormEvts()) / (mupem_rec_jscale.GetNormEvts() + mumep_rec_jscale.GetNormEvts() )

mumep_nlo_acc = mumep_nlorw_true.GetNormEvts() / mumep_nlorw_rec.GetNormEvts()
mupem_nlo_acc = mupem_nlorw_true.GetNormEvts() / mupem_nlorw_rec.GetNormEvts()

nlo_acc = (mupem_nlorw_true.GetNormEvts() + mumep_nlorw_true.GetNormEvts()) / (mupem_nlorw_rec.GetNormEvts() + mumep_nlorw_rec.GetNormEvts() )

acc_err = sqrt( pow(acc - nlo_acc,2) + pow(acc - acc_escale,2) + pow(acc - acc_jscale,2))
print 'Acceptance is {0} +/- {1}'.format(acc, acc_err)

f = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_acc.root", "RECREATE")
TParameter(float)('acc', nlo_acc).Write()
TParameter(float)('acc_err', acc_err).Write()
TParameter(float)('acc_nlo_err', abs(acc - nlo_acc)).Write()
TParameter(float)('acc_escale_err', abs(acc - acc_escale)).Write()
TParameter(float)('acc_jscale_err', abs(acc - acc_jscale)).Write()
f.Close()
