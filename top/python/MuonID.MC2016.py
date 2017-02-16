from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath

phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>2.7")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")
  
triggercut = TCut("tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonEWDecision_TOS ==1")
trkqual    = TCut("(sqrt(tag_PERR2)/tag_P) < 0.1 && (sqrt(probe_PERR2)/probe_P) < 0.1")
eta        = TCut("tag_ETA > 2 && tag_ETA < 4.5 && probe_ETA > 2 && probe_ETA < 4.5")
vtxcut     = TCut("boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
isocut     = TCut("tag_cpt_0.50 < 2000 && probe_cpt_0.50 < 2000")
tck        = TCut("OdinTCK != 7602230")
tck2       = TCut("OdinTCK != 0x5a0032")
pt25 = TCut("probe_PT > 25000")
pt30 = TCut("probe_PT > 30000")
passcut = TCut("probe_isMuon == 1")
Ep = TCut("((probe_CaloHcalE + probe_CaloEcalE)/probe_P)<0.04")

selcut = ptcut + phicut + isocut + triggercut + trkqual + vtxcut + eta

f = TFile("/hepstore/sfarry/GridOutput/2774/MuonID.Zg_mumu.MU.MC2016.root")
g = TFile("/hepstore/sfarry/GridOutput/2773/MuonID.Zg_mumu.MD.MC2016.root")
t = f.Get("PlusTag/DecayTree")
u = f.Get("MinusTag/DecayTree")
v = g.Get("PlusTag/DecayTree")
w = g.Get("MinusTag/DecayTree")


magup = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

selcutMU = selcut + magup
selcutMD = selcut + magdown

#generator level 
#genMDf = TFile("../Tuples/MuonTrackEff.Zg_mumu.MagDown.MC2012.root")
#genMUf = TFile("../Tuples/MuonTrackEff.Zg_mumu.MagUp.MC2012.root")
#zmumuMDGent   = genMDf.Get("MCGenTrackEff/MCTrackEffTuple")
#zmumuMUGent   = genMUf.Get("MCGenTrackEff/MCTrackEffTuple")

reconstructed_plus = TCut("recmuplus_PT > 20000 && recmuplus_SigmaP/recmuplus_P < 0.1")
reconstructed_minus = TCut("recmuminus_PT > 20000 && recmuminus_SigmaP/recmuminus_P < 0.1")

fiducial = TCut("muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5 && muplus_PT > 20000 && muminus_PT > 20000 && boson_M > 60000 && boson_M < 120000")

passcut_plus = TCut("recmuplus_ISMUON == 1")
passcut_minus = TCut("recmuminus_ISMUON == 1")


even = TCut("eventNumber%2==0");
odd = TCut("eventNumber%2==1");

from effbins_config import *

def makeMuonIDMC2016(name, selcut, passcut):
    MuonIDMC2016 = EfficiencyClass("Muon"+name+"IDMC2016")
    MuonIDMC2016.AddTree(t)
    MuonIDMC2016.AddTree(u)
    MuonIDMC2016.AddTree(v)
    MuonIDMC2016.AddTree(w)
    MuonIDMC2016.SetSelectionCut(selcut)
    MuonIDMC2016.SetPassCut(passcut)
    MuonIDMC2016.AddVars(effvars)
    MuonIDMC2016.Add2DVars(eff2dvars)
    MuonIDMC2016.Run()
    MuonIDMC2016.SaveToFile("/user2/sfarry/workspaces/top/tuples/MuonIDMC2016.root")
    
'''
def makeMuonIDMC2016Truth(name, selcut, passcut):
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
        
    MuonIDMC2016_P  = EfficiencyClass("Muon"+name+"IDMC2016_P")
    MuonIDMC2016_P.SetTree(zmumuMDGent)
    MuonIDMC2016_P.AddTree(zmumuMUGent)
    MuonIDMC2016_P.SetSelectionCut(selcutplus)
    MuonIDMC2016_P.SetPassCut(passcutplus)
    MuonIDMC2016_P.AddVars(pluseffvars)
    MuonIDMC2016_P.AddVars(eff2dvars)
    #MuonIDMC2016_P.SetPltRange("boson_M" , 150 , 0 , 150000);
    MuonIDMC2016_P.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonIDMC2016_P.MakeEntryLists()
    MuonIDMC2016_P.MakeHists()
    MuonIDMC2016_P.MakeEfficiencyGraph()

    MuonIDMC2016_M  = EfficiencyClass("Muon"+name+"IDMC2016_M")
    MuonIDMC2016_M.SetTree(zmumuMDGent)
    MuonIDMC2016_M.AddTree(zmumuMUGent)
    MuonIDMC2016_M.SetSelectionCut(selcutminus)
    MuonIDMC2016_M.SetPassCut(passcutminus)
    MuonIDMC2016_M.AddVars(minuseffvars)
    MuonIDMC2016_M.Add2DVars(eff2dvars)
    #MuonIDMC2016_M.SetPltRange("boson_M" , 150 , 0 , 150000);
    MuonIDMC2016_M.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonIDMC2016_M.MakeEntryLists()
    MuonIDMC2016_M.MakeHists()
    MuonIDMC2016_M.MakeEfficiencyGraph()

    MuonIDMC2016 = EfficiencyClass("Muon"+name+"IDMC2016" , MuonIDMC2016_P , MuonIDMC2016_M );
    MuonIDMC2016.MakeEfficiencyGraph();
    MuonIDMC2016.Verbose = True
    MuonIDMC2016.SaveToFile();
'''

makeMuonIDMC2016("",selcut, passcut)
#makeMuonIDMC2016Truth("Ubs",[fiducial + reconstructed_plus, fiducial + reconstructed_minus], [passcut_plus, passcut_minus])
