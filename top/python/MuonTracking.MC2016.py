from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath

phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>0.1")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")
  
#triggercut = TCut("tag_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonEWDecision_TOS ==1")
triggercut = TCut("tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonEWDecision_TOS ==1")
trkqual    = TCut("tag_TRACK_PCHI2 > 0.001 && (sqrt(tag_PERR2)/tag_P) < 0.1")
eta        = TCut("tag_ETA > 2 && tag_ETA < 4.5 && probe_ETA > 2 && probe_ETA < 4.5")
vtxcut     = TCut("boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
isocut     = TCut("tag_cpt_0.50 < 2000")
tck        = TCut("OdinTCK != 7602230")
tck2       = TCut("OdinTCK != 0x5a0032")
pt25_plus  = TCut("muplus_PT  > 25000")
pt25_minus = TCut("muminus_PT > 25000")
pt30_plus  = TCut("muplus_PT  > 30000")
pt30_minus = TCut("muminus_PT > 30000")
passcut = TCut("probe_AssocZM == 1")
mass = TCut("boson_M > 70000 && boson_M < 110000")

selcut = ptcut + phicut + triggercut + tck + vtxcut + eta + mass

even = TCut("eventNumber%2==0")
odd  = TCut("eventNumber%2==1")

zmumuMDf   = TFile("/hepstore/sfarry/GridOutput/2784/MuonTracking_WLine.Zg_mumu.MU.MC2016.root")
zmumuMUf   = TFile("/hepstore/sfarry/GridOutput/2785/MuonTracking_WLine.Zg_mumu.MD.MC2016.root")
zmumuMDGenf   = TFile("/hepstore/sfarry/GridOutput/2991/MuonTracking_WLine.Zg_mumu.MD.MC2016.root")
zmumuMUGenf   = TFile("/hepstore/sfarry/GridOutput/2990/MuonTracking_WLine.Zg_mumu.MU.MC2016.root")

t = zmumuMDf.Get("PlusTag/DecayTree")
u = zmumuMDf.Get("MinusTag/DecayTree")
v = zmumuMUf.Get("PlusTag/DecayTree")
w = zmumuMUf.Get("MinusTag/DecayTree")

zmumuMDPTagt = zmumuMDf.Get("PlusTag/DecayTree")
zmumuMDMTagt = zmumuMDf.Get("MinusTag/DecayTree")
zmumuMUPTagt = zmumuMUf.Get("PlusTag/DecayTree")
zmumuMUMTagt = zmumuMUf.Get("MinusTag/DecayTree")
zmumuMDGent  = zmumuMDGenf.Get("MCGenTrackEff/MCTrackEffTuple")
zmumuMUGent  = zmumuMUGenf.Get("MCGenTrackEff/MCTrackEffTuple")

magup   = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

selcutMU = selcut + magup
selcutMD = selcut + magdown


fiducial = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000 && Z0_M > 60000 && Z0_M < 120000")

passcut_plus  = TCut("lp_isRec == 1 && TMath::Prob(lp_rec_CHI2, lp_rec_nDoF) > 0.001 && lp_rec_SigmaP/lp_rec_P < 0.1")
passcut_minus = TCut("lm_isRec == 1 && TMath::Prob(lm_rec_CHI2, lm_rec_nDoF) > 0.001 && lm_rec_SigmaP/lm_rec_P < 0.1")

hasmutt_plus  = TCut("lp_stub_PT > 20000");
hasmutt_minus = TCut("lm_stub_PT > 20000");

from effbins_config import *

def makeMuonTrackingMC2016Truth(name, selcut, passcut):
    selcutplus = selcut[0]
    selcutminus = selcut[0]
    if (len(selcut) == 2):
        selcutplus  = selcut[0]
        selcutminus = selcut[1]
    passcutplus  = passcut[0]
    passcutminus = passcut[0]
    if (len(passcut) == 2):
        passcutplus  = passcut[0]
        passcutminus = passcut[1]
        
    MuonTrackingMC2016_P  = EfficiencyClass("Muon"+name+"TrackingMC2016_P")
    MuonTrackingMC2016_P.AddTree(zmumuMDGent)
    MuonTrackingMC2016_P.AddTree(zmumuMUGent)
    MuonTrackingMC2016_P.SetSelectionCut(selcutplus)
    MuonTrackingMC2016_P.SetPassCut(passcutplus)
    MuonTrackingMC2016_P.AddVars(pluseffvars + trkpluseffvars)
    MuonTrackingMC2016_P.Add2DVars(trk2dvars)
    MuonTrackingMC2016_P.Run()
    MuonTrackingMC2016_P.SaveToFile()

    MuonTrackingMC2016_M  = EfficiencyClass("Muon"+name+"TrackingMC2016_M")
    MuonTrackingMC2016_M.AddTree(zmumuMDGent)
    MuonTrackingMC2016_M.AddTree(zmumuMUGent)
    MuonTrackingMC2016_M.SetSelectionCut(selcutminus)
    MuonTrackingMC2016_M.SetPassCut(passcutminus)
    MuonTrackingMC2016_M.AddVars(minuseffvars + trkminuseffvars)
    MuonTrackingMC2016_M.Add2DVars(trk2dvars)
    MuonTrackingMC2016_M.Run()
    MuonTrackingMC2016_M.SaveToFile()

    MuonTrackingMC2016 = EfficiencyClass("Muon"+name+"TrackingMC2016" , MuonTrackingMC2016_P , MuonTrackingMC2016_M );
    MuonTrackingMC2016.MakeEfficiencyGraph();
    MuonTrackingMC2016.SaveToFile();

def makeMuonTrackingMC2016(name, selcut, passcut):
    MuonTrackingMC2016 = EfficiencyClass("Muon"+name+"TrackingMC2016")
    MuonTrackingMC2016.AddTree(t)
    MuonTrackingMC2016.AddTree(u)
    MuonTrackingMC2016.AddTree(v)
    MuonTrackingMC2016.AddTree(w)
    MuonTrackingMC2016.SetSelectionCut(selcut)
    MuonTrackingMC2016.SetPassCut(passcut)
    MuonTrackingMC2016.AddVars(effvars + trkeffvars)
    MuonTrackingMC2016.Add2DVars(trk2dvars)
    MuonTrackingMC2016.Run()
    MuonTrackingMC2016.SaveToFile("/user2/sfarry/workspaces/top/tuples/Muon"+name+"TrackingMC2016.root")

makeMuonTrackingMC2016("", selcut, passcut)
makeMuonTrackingMC2016Truth("Ubs",[fiducial], [passcut_plus, passcut_minus])
#makeMuonTrackingMC2016Truth("Bs",[fiducial + hasmutt_plus, fiducial + hasmutt_minus], [passcut_plus, passcut_minus])

#makeMuonTrackingMC2016Truth("WUbs",[fiducial], [passcutW_plus, passcutW_minus])
#makeMuonTrackingMC2016Truth("WBs",[fiducial + hasmutt_plus, fiducial + hasmutt_minus], [passcutW_plus, passcutW_minus])

'''makeMuonTrackingMC2016Truth("PT25Ubs",[fiducial + pt25_plus, fiducial + pt25_minus], [passcut_plus, passcut_minus])
makeMuonTrackingMC2016Truth("PT25Bs",[fiducial + hasmutt_plus + pt25_plus, fiducial + hasmutt_minus + pt25_minus], [passcut_plus, passcut_minus])

makeMuonTrackingMC2016Truth("PT30Ubs",[fiducial + pt30_plus, fiducial + pt30_minus], [passcut_plus, passcut_minus])
makeMuonTrackingMC2016Truth("PT30Bs", [fiducial + hasmutt_plus + pt30_plus, fiducial + hasmutt_minus + pt30_minus], [passcut_plus, passcut_minus])
'''
