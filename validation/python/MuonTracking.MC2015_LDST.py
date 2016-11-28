from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath


phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>0.1")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")
  
triggercut = TCut("tag_Hlt2SingleMuonHighPTDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonDecision_TOS ==1")
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

selcut = ptcut + phicut + triggercut + trkqual + tck + vtxcut + eta

even = TCut("eventNumber%2==0")
odd  = TCut("eventNumber%2==1")

zmumuMDf   = TFile("/hepstore/sfarry/GridOutput/1926/MuonTrackEff.Zg_mumu.MagDown.MC2015_LDST.root")
zmumuMUf   = TFile("/hepstore/sfarry/GridOutput/1927/MuonTrackEff.Zg_mumu.MagUp.MC2015_LDST.root")

t = zmumuMDf.Get("PlusTag/DecayTree")
u = zmumuMDf.Get("MinusTag/DecayTree")
v = zmumuMUf.Get("PlusTag/DecayTree")
w = zmumuMUf.Get("MinusTag/DecayTree")

zmumuMDPTagt = zmumuMDf.Get("PlusTag/DecayTree")
zmumuMDMTagt = zmumuMDf.Get("MinusTag/DecayTree")
zmumuMUPTagt = zmumuMUf.Get("PlusTag/DecayTree")
zmumuMUMTagt = zmumuMUf.Get("MinusTag/DecayTree")
zmumuMDGent  = zmumuMDf.Get("MCGenTrackEff/MCTrackEffTuple")
zmumuMUGent  = zmumuMUf.Get("MCGenTrackEff/MCTrackEffTuple")

magup   = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

selcutMU = selcut + magup
selcutMD = selcut + magdown


fiducial = TCut("muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5 && muplus_PT > 20000 && muminus_PT > 20000 && boson_M > 60000 && boson_M < 120000")

passcut_plus  = TCut("muplus_isRec == 1 && TMath::Prob(recmuplus_CHI2, recmuplus_nDoF) > 0.001 && recmuplus_SigmaP/recmuplus_P < 0.1")
passcut_minus = TCut("muminus_isRec == 1 && TMath::Prob(recmuminus_CHI2, recmuminus_nDoF) > 0.001 && recmuminus_SigmaP/recmuminus_P < 0.1")

passcutW_plus  = TCut("muplus_isRec == 1 && TMath::Prob(recmuplus_CHI2, recmuplus_nDoF) > 0.001 && recmuplus_SigmaP/recmuplus_P < 0.1")
passcutW_minus = TCut("muminus_isRec == 1 && TMath::Prob(recmuminus_CHI2, recmuminus_nDoF) > 0.001 && recmuminus_SigmaP/recmuminus_P < 0.1")


hasmutt_plus  = TCut("muplus_AssocStubPt > 20000");
hasmutt_minus = TCut("muminus_AssocStubPt > 20000");

'''
etabins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
etabins11 = [2.0 , 2.125, 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 3.75, 4.0 , 4.25, 4.5]
etabins12 = [2.0 , 2.125, 2.25 , 2.375, 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 3.75, 4.0 , 4.25, 4.5]
etabins13 = [2.0 , 2.08, 2.165, 2.25 , 2.375, 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 3.75, 4.0 , 4.25, 4.5]
etabins2 = [2.0 , 2.25 , 2.5 , 2.75 , 2.875, 3.00 , 3.1225, 3.25 , 3.375, 3.5 , 4.0 , 4.5]
tckbins = [3500000.0, 4600000.0, 4800000.0, 5700000.0, 5900000.0, 6000000.0, 7100000.0, 7300000.0, 7400000.0,
           7500000.0, 7600000.0, 7700000.0, 7900000.0, 7929912.0, 8000000.0]
effvars = [
    ["ETA", "probe_ETA", 10 , 2 , 4.5 ],
    ["ETA5", "probe_ETA", 5 , 2 , 4.5 ],
    ["ETA11", "probe_ETA", etabins11 ],
    ["ETA12", "probe_ETA", etabins12 ],
    ["ETA13", "probe_ETA", etabins13 ],
    ["ETA8", "probe_ETA", etabins ],
    ["ETA20", "probe_ETA", 20 , 2 , 4.5 ],
    ["PT", "probe_PT", 10 , 20000 , 70000],
    ["PT5", "probe_PT", 5 , 20000 , 70000],
    ["P", "probe_P", 8 , 100000 , 500000],
    ["PHI", "probe_PHI", 10 , -TMath.Pi() , TMath.Pi()],
    ["PHI5", "probe_PHI", 5 , -TMath.Pi() , TMath.Pi()],
    ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
    ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
    ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
    ["TCK", "OdinTCK", tckbins, "I"],
    ["SPDHits", "nSPDHits", 20 , 0 , 1000, "I"]
    ]
eff2dvars = [
    ["ETA_PHI", "ETA5","PHI5"],
    ["ETA_PT" , "ETA5","PT5"]
    ]

pluseffvars = [
  ["ETA", "muplus_ETA", 10 , 2 , 4.5 ],
  ["ETA5", "muplus_ETA", 5 , 2 , 4.5 ],
  ["PT", "muplus_PT",10 , 20000 , 70000 ],
  ["PT5", "muplus_PT", 5 , 20000 , 70000 ],
  ["ETA8", "muplus_ETA", etabins ],
  ["ETA11", "muplus_ETA", etabins11 ],
  ["ETA12", "muplus_ETA", etabins12 ],
  ["ETA13", "muplus_ETA", etabins13 ],
  ["ETA20", "muplus_ETA", 20 , 2 , 4.5 ],
  ["P", "muplus_P", 10, 0, 500000],
  ["Y", "boson_Y", 10, 2, 4.5],
  ["PHI", "muplus_PHI", 10 , -TMath.Pi() , TMath.Pi() ],
  ["PHI5", "muplus_PHI", 5 , -TMath.Pi() , TMath.Pi() ],
  ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
  ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
  ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
  ["SPDHits", "nSPDHits", 20 , 0 , 1000 , "I"]
]
minuseffvars = [
  ["ETA", "muminus_ETA", 10 , 2 , 4.5 ],
  ["ETA5", "muminus_ETA", 5 , 2 , 4.5 ],
  ["ETA8", "muminus_ETA", etabins ],
  ["ETA11", "muminus_ETA", etabins11 ],
  ["ETA12", "muminus_ETA", etabins12 ],
  ["ETA13", "muminus_ETA", etabins13 ],
  ["ETA20", "muminus_ETA", 20 , 2 , 4.5 ],
  ["PT", "muminus_PT",10 , 20000 , 70000 ],
  ["PT5", "muminus_PT",5  , 20000 , 70000 ],
  ["P", "muminus_P", 10, 0, 500000],
  ["Y", "boson_Y", 10, 2, 4.5],
  ["PHI", "muminus_PHI", 10 , -TMath.Pi() , TMath.Pi() ],
  ["PHI5", "muminus_PHI", 5 , -TMath.Pi() , TMath.Pi() ],
  ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
  ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
  ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
  ["SPDHits", "nSPDHits", 20 , 0 , 1000 , "I"]
]
'''
from effbins_config import *

def makeMuonTrackingMC2015Truth(name, selcut, passcut):
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
        
    MuonTrackingMC2015_P  = EfficiencyClass("Muon"+name+"TrackingMC2015_P")
    MuonTrackingMC2015_P.AddTree(zmumuMDGent)
    MuonTrackingMC2015_P.AddTree(zmumuMUGent)
    MuonTrackingMC2015_P.SetSelectionCut(selcutplus)
    MuonTrackingMC2015_P.SetPassCut(passcutplus)
    MuonTrackingMC2015_P.AddVars(pluseffvars + trkpluseffvars)
    MuonTrackingMC2015_P.Add2DVars(trk2dvars)
    MuonTrackingMC2015_P.SetPltRange("boson_M" , 150 , 0 , 150000);
    #MuonTrackingMC2015_P.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrackingMC2015_P.MakeEntryLists()
    MuonTrackingMC2015_P.MakeHists()
    MuonTrackingMC2015_P.MakeEfficiencyGraph()

    MuonTrackingMC2015_M  = EfficiencyClass("Muon"+name+"TrackingMC2015_M")
    MuonTrackingMC2015_M.AddTree(zmumuMDGent)
    MuonTrackingMC2015_M.AddTree(zmumuMUGent)
    MuonTrackingMC2015_M.SetSelectionCut(selcutminus)
    MuonTrackingMC2015_M.SetPassCut(passcutminus)
    MuonTrackingMC2015_M.AddVars(minuseffvars + trkminuseffvars)
    MuonTrackingMC2015_M.Add2DVars(trk2dvars)
    MuonTrackingMC2015_M.SetPltRange("boson_M" , 150 , 0 , 150000);
    #MuonTrackingMC2015_M.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrackingMC2015_M.MakeEntryLists()
    MuonTrackingMC2015_M.MakeHists()
    MuonTrackingMC2015_M.MakeEfficiencyGraph()

    MuonTrackingMC2015 = EfficiencyClass("Muon"+name+"TrackingMC2015" , MuonTrackingMC2015_P , MuonTrackingMC2015_M );
    MuonTrackingMC2015.MakeEfficiencyGraph();
    MuonTrackingMC2015.SaveToFile();


def makeMuonTrackingMC2015(name, selcut, passcut):
    MuonTrackingMC2015 = EfficiencyClass("Muon"+name+"TrackingMC2015")
    MuonTrackingMC2015.AddTree(t)
    MuonTrackingMC2015.AddTree(u)
    MuonTrackingMC2015.AddTree(v)
    MuonTrackingMC2015.AddTree(w)
    MuonTrackingMC2015.SetSelectionCut(selcut)
    MuonTrackingMC2015.SetPassCut(passcut)
    MuonTrackingMC2015.AddVars(effvars + trkeffvars)
    MuonTrackingMC2015.Add2DVars(trk2dvars)
    MuonTrackingMC2015.SetPltRange("boson_M" , 50 , 70000 , 110000)
    MuonTrackingMC2015.MakeEntryLists()
    MuonTrackingMC2015.MakeHists()
    MuonTrackingMC2015.MakeEfficiencyGraph()
    MuonTrackingMC2015.SaveToFile()

makeMuonTrackingMC2015("", selcut, passcut)
makeMuonTrackingMC2015Truth("Ubs",[fiducial], [passcut_plus, passcut_minus])
makeMuonTrackingMC2015Truth("Bs",[fiducial + hasmutt_plus, fiducial + hasmutt_minus], [passcut_plus, passcut_minus])

makeMuonTrackingMC2015Truth("WUbs",[fiducial], [passcutW_plus, passcutW_minus])
makeMuonTrackingMC2015Truth("WBs",[fiducial + hasmutt_plus, fiducial + hasmutt_minus], [passcutW_plus, passcutW_minus])

'''makeMuonTrackingMC2015Truth("PT25Ubs",[fiducial + pt25_plus, fiducial + pt25_minus], [passcut_plus, passcut_minus])
makeMuonTrackingMC2015Truth("PT25Bs",[fiducial + hasmutt_plus + pt25_plus, fiducial + hasmutt_minus + pt25_minus], [passcut_plus, passcut_minus])

makeMuonTrackingMC2015Truth("PT30Ubs",[fiducial + pt30_plus, fiducial + pt30_minus], [passcut_plus, passcut_minus])
makeMuonTrackingMC2015Truth("PT30Bs", [fiducial + hasmutt_plus + pt30_plus, fiducial + hasmutt_minus + pt30_minus], [passcut_plus, passcut_minus])
'''
