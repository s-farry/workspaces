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

jetmult1 = TCut("muminus_jetmult20 == 1")

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


recvars = [
    ["mu_pt"        , "muminus_PT/1000.0"           , 8  , 20 , 100 ],
    #["e_pt"         , "e_PT/1000.0"            , 8  , 20 , 100 ],
    ["mu_ipchi2"    , "muminus_IPCHI2_OWNPV"    , 8  , 0 , 10 ],
    ["ipchi2"       , "muminus_jet_Tag0_ipChi2Sum/muminus_jet_Tag0_nTrk", 20, 0, 200],
    ["svmult"       , "muminus_jet_Tag0_nTrk", 12, -0.5, 11.5 ],
    ["avipchi2", "log10(muminus_jet_avipchi2)", 20, -3, 5],
    #["e_ipchi2"         , "e_IPCHI2_OWNPV"     , 8  , 0 , 10 ],
    ["mu_eta"       , "abs(muminus_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    #["e_eta"        , "abs(e_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "muminus_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "muminus_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["phij"         , "muminus_jet_PHI"   , 6, -TMath.Pi(), TMath.Pi()],
    ["cpf"          , "muminus_jet_cpf"   , 20, 0, 1],
    ["mult",    "muminus_jet_ndauts" , 26, -0.5, 25.5],
    ["mpt",     "muminus_jet_mpt" , 20, 0, 40000.0],
    ["mtf",     "muminus_jet_mtf" , 20, 0, 1.0 ],
    ["npoint",  "muminus_jet_npoint" ,23, -0.5, 45.5],
    ["width",   "muminus_jet_width" , 20, 0, 1.0 ],
    ["n90",     "muminus_jet_n90" , 16, -0.5, 15.5],
    #["eiso"         , "e_cpt_0.50/1000.0"       , 10, 0, 20],
    ["muiso"        , "muminus_cpt_0.50/1000.0"      , 10, 0, 20],
    #["iso"          , "max(muminus_cpt_0.50,e_cpt_0.50)/1000.0" , 10, 0, 20],
    ["ntbvs"         , "muminus_jet_Tag0_tbvs" , 10, -0.5, 9.5]
    ]

recvars2d = [ ['ptj', 'etaj'], ['phij', 'etaj'] ]

# get other efficiencies from fully reconstructed version
kinematic = TCut("muminus_ETA > 2.0 && muminus_ETA < 4.5 && muminus_PT > 20000 && muminus_jet_PT > 20000")
trueb = TCut("muminus_mcjet_PT > 12500 && abs(muminus_mcjet_flavour) == 5")
jettag = TCut("muminus_jet_BDTTag == 1")

#f = TFile("/hepstore/sfarry/GridOutput/3099/WMuJet.ttbar_gg.MU.MC2012.root")
#g = TFile("/hepstore/sfarry/GridOutput/3100/WMuJet.ttbar_gg.MD.MC2012.root")
f = TFile("/hepstore/sfarry/GridOutput/3149/WMuJet.ttbar_gg.MU.MC2012.root")
g = TFile("/hepstore/sfarry/GridOutput/3150/WMuJet.ttbar_gg.MD.MC2012.root")


t = f.Get("WTuple/DecayTree")
u = g.Get("WTuple/DecayTree")
#trt = f.Get("MCGenTrackEff/MCTrackEffTuple")
tru = g.Get("MCGenTrackEff/MCTrackEffTuple")


#ff = TFile("/hepstore/sfarry/GridOutput/3097/WMuJet.ttbar_gg.MU.MC2016.root")
#gg = TFile("/hepstore/sfarry/GridOutput/3098/WMuJet.ttbar_gg.MD.MC2016.root")
ff = TFile("/hepstore/sfarry/GridOutput/3151/WMuJet.ttbar_gg.MU.MC2016.root")
gg = TFile("/hepstore/sfarry/GridOutput/3152/WMuJet.ttbar_gg.MD.MC2016.root")


tt = ff.Get("WTuple/DecayTree")
uu = gg.Get("WTuple/DecayTree")

tageff = EfficiencyClass("tageff")
tageff.SetSelectionCut(kinematic + trueb)
tageff.SetPassCut(jettag)
tageff.AddTree( tt )
tageff.AddTree( uu )
tageff.AddVars(recvars)
tageff.Add2DVars(recvars2d)
tageff.Run()
tageff.SaveToFile("/user2/sfarry/workspaces/top/tuples/tageff_test_mc2016.root")

tageff_2012 = EfficiencyClass("tageff_2012")
tageff_2012.SetSelectionCut(kinematic + trueb)
tageff_2012.SetPassCut(jettag)
tageff_2012.AddTree( t )
tageff_2012.AddTree( u )
tageff_2012.AddVars(recvars)
tageff_2012.Add2DVars(recvars2d)
tageff_2012.Run()
tageff_2012.SaveToFile("/user2/sfarry/workspaces/top/tuples/tageff_test_mc2012.root")

tag = Template("tag")
tag.SetSelCut(kinematic + trueb + jetmult1 )
tag.AddTree( tt   )
tag.AddTree( uu )
tag.AddVars(recvars)
tag.Add2DVars(recvars2d)
tag.Run()
tag.SaveToFile("/user2/sfarry/workspaces/top/tuples/tag_test_mc2016.root")

tag_2012 = Template("tag_2012")
tag_2012.SetSelCut(kinematic + trueb + jetmult1 )
tag_2012.AddTree( t )
tag_2012.AddTree( u )
tag_2012.AddVars(recvars)
tag_2012.Add2DVars(recvars2d)
tag_2012.Run()
tag_2012.SaveToFile("/user2/sfarry/workspaces/top/tuples/tag_test_mc2012.root")
