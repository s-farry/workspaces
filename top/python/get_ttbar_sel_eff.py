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
    ["mu_pt"        , "mu_PT/1000.0"         , 8  , 20 , 100 ],
    ["e_pt"         , "e_PT/1000.0"          , 8  , 20 , 100 ],
    ["mu_pt"        , "mu_PT/1000.0"         , 8  , 20 , 100 ],
    ["mu_ipubs"     , "mu_ipubs_d"           , 100  , 0 , 0.1 ],
    ["e_ipubs"      , "e_ipubs_d"            , 100  , 0 , 0.1 ],
    ["mu_ipubs_tune", "mu_ipubs_d_tune"      , 100  , 0 , 0.1 ],
    ["e_ipubs_tune" , "e_ipubs_d_tune"       , 100  , 0 , 0.1 ],
    ["mu_ipownpv"   , "mu_IP_OWNPV"          , 100  , 0 , 0.1 ],
    ["e_ipownpv"    , "e_IP_OWNPV"           , 100  , 0 , 0.1 ],
    ["mu_eta"       , "abs(mu_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(e_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["eiso"         , "e_cpt_0.50/1000.0"       , 100, 0, 10],
    ["muiso"        , "mu_cpt_0.50/1000.0"      , 100, 0, 10],
    ["iso"          , "max(mu_cpt_0.50,e_cpt_0.50)/1000.0" , 10, 0, 20],
    ]
zmumu_recvars = [
    ["mupiso"        , "muplus_cpt_0.50/1000.0"       , 100, 0, 10],
    ["mumiso"        , "muminus_cpt_0.50/1000.0"      , 100, 0, 10]
]

# get other efficiencies from fully reconstructed version
kinematic = TCut("mu_ETA > 2.0 && mu_ETA < 4.5 && e_ETA > 2.0 && e_ETA < 4.5 && mu_PT > 20000 && e_PT > 20000 && ttbar_jet_PT > 20000")
#ip  = TCut("mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
ip  = TCut("mu_ipubs_d < 0.04 && e_ipubs_d < 0.04")
ip_tune = TCut("mu_ipubs_d_tune < 0.04 && e_ipubs_d_tune < 0.04")
#iso = TCut("mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000")
iso = TCut("mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000")
iso_zmumu = TCut("muplus_cpt_0.50 < 5000 && muminus_cpt_0.50 < 5000")
zmumu = TCut("muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_PT > 20000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muplus_PT > 20000 && boson_M > 60000 && boson_M < 120000 && boson_jet_PT > 20000")
trueb = TCut("ttbar_mcjet_PT > 0 && abs(ttbar_mcjet_flavour) == 5")
jettag = TCut("ttbar_jet_BDTTag == 1")

dijet = TCut("ttbar_jetmult20 > 1")
monojet = TCut("ttbar_jetmult20 == 1")

#add the ip tuning variables
qq2ttbar_mc2016.add_iptune()
gg2ttbar_mc2016.add_iptune()

isoeff = EfficiencyClass("isoeff")
isoeff.SetSelectionCut(kinematic + trueb)
isoeff.SetPassCut(iso)
isoeff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale)
isoeff.AddTrees(gg2ttbar_mc2016.trees() )
isoeff.AddVars(recvars)
isoeff.Run()
isoeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff.root")

isoeff_gg = EfficiencyClass("isoeff_gg")
isoeff_gg.SetSelectionCut(kinematic + trueb)
isoeff_gg.SetPassCut(iso)
isoeff_gg.AddTrees(gg2ttbar_mc2016.trees() )
isoeff_gg.AddVars(recvars)
isoeff_gg.Run()
isoeff_gg.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff_gg.root")

isoeff_qq = EfficiencyClass("isoeff_qq")
isoeff_qq.SetSelectionCut(kinematic + trueb)
isoeff_qq.SetPassCut(iso)
isoeff_qq.AddTrees(qq2ttbar_mc2016.trees() )
isoeff_qq.AddVars(recvars)
isoeff_qq.Run()
isoeff_qq.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff_qq.root")

isoeff_monojet = EfficiencyClass("isoeff_monojet")
isoeff_monojet.SetSelectionCut(kinematic + trueb + monojet)
isoeff_monojet.SetPassCut(iso)
isoeff_monojet.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale)
isoeff_monojet.AddTrees(gg2ttbar_mc2016.trees() )
isoeff_monojet.AddVars(recvars)
isoeff_monojet.Run()
isoeff_monojet.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff_monojet.root")

isoeff_dijet = EfficiencyClass("isoeff_dijet")
isoeff_dijet.SetSelectionCut(kinematic + trueb + dijet)
isoeff_dijet.SetPassCut(iso)
isoeff_dijet.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale)
isoeff_dijet.AddTrees(gg2ttbar_mc2016.trees() )
isoeff_dijet.AddVars(recvars)
isoeff_dijet.Run()
isoeff_dijet.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff_dijet.root")



'''
isoeff1j = EfficiencyClass("isoeff1j")
isoeff1j.SetSelectionCut(kinematic + trueb + TCut("ttbar_jetmult20 == 1"))
isoeff1j.SetPassCut(iso)
isoeff1j.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale)
isoeff1j.AddTrees(gg2ttbar_mc2016.trees() )
isoeff1j.AddVars(recvars)
isoeff1j.Run()
isoeff1j.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff1j.root")

isoeff2j = EfficiencyClass("isoeff2j")
isoeff2j.SetSelectionCut(kinematic + trueb + TCut("ttbar_jetmult20 > 1"))
isoeff2j.SetPassCut(iso)
isoeff2j.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale)
isoeff2j.AddTrees(gg2ttbar_mc2016.trees() )
isoeff2j.AddVars(recvars)
isoeff2j.Run()
isoeff2j.SaveToFile("/user2/sfarry/workspaces/top/tuples/isoeff2j.root")
'''
isoeff_zmumu_data = EfficiencyClass("isoeff_zmumu_data")
isoeff_zmumu_data.SetSelectionCut(zmumu)
isoeff_zmumu_data.SetPassCut(iso_zmumu)
#isoeff_zmumu_data.AddTrees(zmumuj_2015.trees() )
isoeff_zmumu_data.AddTrees(zmumuj_2016.trees() )
isoeff_zmumu_data.AddVars(zmumu_recvars)
isoeff_zmumu_data.Run()
isoeff_zmumu_data.SaveToFile("/user2/sfarry/workspaces/top/tuples/zmumuj_data_isoeff.root")

isoeff_zmumu_mc2016 = EfficiencyClass("isoeff_zmumu_data")
isoeff_zmumu_mc2016.SetSelectionCut(zmumu)
isoeff_zmumu_mc2016.SetPassCut(iso_zmumu)
isoeff_zmumu_mc2016.AddTrees(zmumu_mc2016.trees() )
isoeff_zmumu_mc2016.AddVars(zmumu_recvars)
isoeff_zmumu_mc2016.Run()
isoeff_zmumu_mc2016.SaveToFile("/user2/sfarry/workspaces/top/tuples/zmumuj_mc2016_isoeff.root")

ipeff = EfficiencyClass("ipeff")
ipeff.SetSelectionCut(kinematic + iso + trueb)
ipeff.SetPassCut(ip)
ipeff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale )
ipeff.AddTrees(gg2ttbar_mc2016.trees())
ipeff.AddVars(recvars)
ipeff.Run()
ipeff.SaveToFile("/user2/sfarry/workspaces/top/tuples/ipeff.root")

ipeff_tune = EfficiencyClass("ipeff_tune")
ipeff_tune.SetSelectionCut(kinematic + iso + trueb)
ipeff_tune.SetPassCut(ip_tune)
ipeff_tune.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale )
ipeff_tune.AddTrees(gg2ttbar_mc2016.trees())
ipeff_tune.AddVars(recvars)
ipeff_tune.Run()
ipeff_tune.SaveToFile("/user2/sfarry/workspaces/top/tuples/ipeff_tune.root")

seleff = EfficiencyClass("seleff")
seleff.SetSelectionCut(kinematic + trueb)
seleff.SetPassCut(iso + ip_tune)
seleff.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale / tt_gg_scale )
seleff.AddTrees(gg2ttbar_mc2016.trees())
seleff.AddVars(recvars)
seleff.Run()
seleff.SaveToFile("/user2/sfarry/workspaces/top/tuples/seleff.root")


seleff_val = ipeff_tune.GetTotEff() * isoeff.GetTotEff()

seleff_obj = eff_vals('seleff',
                      seleff_val,
                      seleff_val * 
                      sqrt(pow(ipeff_tune.GetTotEffErrLo()/ipeff_tune.GetTotEff(),2) +
                           pow(isoeff.GetTotEffErrLo()/isoeff.GetTotEff(),2)),
                      seleff_val * abs(ipeff_tune.GetTotEff() - ipeff.GetTotEff())/ipeff_tune.GetTotEff(),
                      seleff_val * abs(isoeff_zmumu_mc2016.GetTotEff() - isoeff_zmumu_data.GetTotEff())/isoeff_zmumu_mc2016.GetTotEff())



outputFile = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_sel_effs.root", "RECREATE")
seleff_obj.write()
outputFile.Close()
