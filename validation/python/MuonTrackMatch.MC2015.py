from Jawa import EfficiencyClass, EffVar
from ROOT import TFile, TCut, TTree, TMath


### Reconstructed cuts
matched_plus = TCut("muplus_MuonTT_nCommonMuonIDs/muplus_MuonTT_nMuonIDs > 0.4 && (muplus_nTTIDs > 0 ? muplus_MuonTT_nCommonTTIDs/muplus_MuonTT_nTTIDs > 0.6 : muplus_MuonTT_nTTIDs > 0)")
matched_minus = TCut("muminus_MuonTT_nCommonMuonIDs/muminus_MuonTT_nMuonIDs > 0.4 && (muminus_nTTIDs > 0 ? muminus_MuonTT_nCommonTTIDs/muminus_MuonTT_nTTIDs > 0.6 : muminus_MuonTT_nTTIDs > 0)")

trkqual = TCut("muminus_TRACK_PCHI2 > 0.001 && sqrt(muminus_PERR2)/muminus_P < 0.1 && muplus_TRACK_PCHI2 > 0.001 && sqrt(muplus_PERR2)/muplus_P < 0.1")
wtrkqual_p = TCut("muplus_TRACK_PCHI2 > 0.01")
wtrkqual_m = TCut("muminus_TRACK_PCHI2 > 0.01")

hasMuTT_plus = TCut("muplus_MuonTT_PT > 20000 && muplus_MuonTT_DeltaR < 0.1")
hasMuTT_minus = TCut("muminus_MuonTT_PT > 20000 && muminus_MuonTT_DeltaR < 0.1")


vtx_minus = TCut("muminus_MuonTT_VtxChi2/muminus_MuonTT_VtxNDoF < 5")
vtx_plus = TCut("muplus_MuonTT_VtxChi2/muplus_MuonTT_VtxNDoF < 5")

loosematched_plus = TCut("muplus_MuonTT_nCommonMuonIDs/muplus_MuonTT_nMuonIDs > 0.4")
loosematched_minus = TCut("muminus_MuonTT_nCommonMuonIDs/muminus_MuonTT_nMuonIDs > 0.4")

phicut_plus = TCut("muplus_MuonTT_DPhi > 1.0");
phicut_minus = TCut("muminus_MuonTT_DPhi > 1.0");

fiducial_rec = TCut("muplus_PT > 20000 && muminus_PT > 20000 && boson_M > 60000 && boson_M < 120000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5");
  
triggercut = TCut("tag_Hlt2SingleMuonHighPTDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonDecision_TOS ==1")

selcut_plus  = hasMuTT_plus  + vtx_plus  + phicut_plus  + fiducial_rec + trkqual
selcut_minus = hasMuTT_minus + vtx_minus + phicut_minus + fiducial_rec + trkqual

passcut_plus  = matched_plus
passcut_minus = matched_minus

###Truth Cuts



fiducial = TCut("muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5 && muplus_PT > 20000 && muminus_PT > 20000 && boson_M > 60000 && boson_M < 120000");

trkq_plus = TCut("muplus_isRec == 1 && TMath::Prob(recmuplus_CHI2, recmuplus_nDoF) > 0.001 && recmuplus_SigmaP/recmuplus_P < 0.1");
trkq_minus = TCut("muminus_isRec == 1 && TMath::Prob(recmuminus_CHI2, recmuminus_nDoF) > 0.001 && recmuminus_SigmaP/recmuminus_P < 0.1");

isRecMinus = TCut("muminus_Reconstructed == 1 && recmuminus_ISMUON == 1 && TMath::Prob(recmuminus_CHI2,recmuminus_nDoF) > 0.001")
isRecPlus  = TCut("muplus_Reconstructed == 1 && recmuplus_ISMUON == 1 && TMath::Prob(recmuplus_CHI2,recmuplus_nDoF) > 0.001")
genphicut  = TCut("(abs(muplus_PHI-muminus_PHI)<TMath::Pi() ? abs(muplus_PHI-muminus_PHI) : 2*TMath::Pi()-abs(muplus_PHI-muminus_PHI))>1.0")

hastruemutt_plus = TCut("muplus_AssocStubPt > 20000 && muplus_AssocStubCharge == 1")
hastruemutt_minus = TCut("muminus_AssocStubPt > 20000 && muminus_AssocStubCharge == -1")

inAcc_plustag = TCut("recmuplus_ETA > 2 && recmuplus_ETA < 4.5 && muminus_AssocStubEta > 2 && muminus_AssocStubEta < 4.5");
inAcc_minustag = TCut("recmuminus_ETA > 2 && recmuminus_ETA < 4.5 && muplus_AssocStubEta > 2 && muplus_AssocStubEta < 4.5");

ptcut_plustag = TCut("recmuplus_PT > 20000 && muminus_AssocStubPt > 20000");
ptcut_minustag = TCut("recmuminus_PT > 20000 && muplus_AssocStubPt > 20000");

vtx_plustag = TCut("(plustag_VERTEX_CHI2/plustag_VERTEX_NDOF) < 5");
vtx_minustag = TCut("(minustag_VERTEX_CHI2/minustag_VERTEX_NDOF) < 5");

gencut_plustag =  isRecPlus  + genphicut + ptcut_plustag  + vtx_plustag  + inAcc_plustag
gencut_minustag = isRecMinus + genphicut + ptcut_minustag + vtx_minustag + inAcc_minustag

isTrackMatch_plus = TCut("(muplus_AssocStub_nCommonMuonHits/muplus_AssocStub_nMuonHits) > 0.4 && (recmuplus_nTTHits > 0 ? (muplus_AssocStub_nCommonTTHits/muplus_AssocStub_nTTHits) > 0.6 : muplus_AssocStub_nTTHits > 0)")
isTrackMatch_minus = TCut("(muminus_AssocStub_nCommonMuonHits/muminus_AssocStub_nMuonHits) > 0.4 && (recmuminus_nTTHits > 0 ? (muminus_AssocStub_nCommonTTHits/muminus_AssocStub_nTTHits) > 0.6 : muminus_AssocStub_nTTHits > 0)")

selcut_ubsplus  = fiducial + trkq_plus  + hastruemutt_plus
selcut_ubsminus = fiducial + trkq_minus + hastruemutt_minus

selcut_genplus  = fiducial + gencut_minustag + trkq_plus  + hastruemutt_plus
selcut_genminus = fiducial + gencut_plustag  + trkq_minus + hastruemutt_minus

passcut_genplus = isTrackMatch_plus
passcut_genminus = isTrackMatch_minus

zmumuMDf   = TFile("/user2/sfarry/Simulation/tuples/MuonTrackEff.Zg_mumu.MagDown.MC2015.Sim09.root")
zmumuMUf   = TFile("/user2/sfarry/Simulation/tuples/MuonTrackEff.Zg_mumu.MagUp.MC2015.Sim09.root")
t = zmumuMDf.Get("Z2MuMu/DecayTree")
u = zmumuMUf.Get("Z2MuMu/DecayTree")

zmumuMDGent  = zmumuMDf.Get("MCGenTrackEff/MCTrackEffTuple")
zmumuMUGent  = zmumuMUf.Get("MCGenTrackEff/MCTrackEffTuple")
   
magup = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

etabins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]

eff2dvars = [
    ["ETA","PHI"],
    ["ETA","PT"]
    ]

pluseffvars = [
  ["ETA", "muplus_ETA", 10 , 2 , 4.5 ],
  ["PT", "muplus_PT",10 , 20000 , 70000 ],
  ["ETA8", "muplus_ETA", etabins ],
  ["P", "muplus_P", 10, 0, 500000],
  ["Y", "boson_Y", 10, 2, 4.5],
  ["PHI", "muplus_PHI", 10 , -TMath.Pi() , TMath.Pi() ],
  ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
  ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
  ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
  ["SPDHits", "nSPDHits", 20 , 0 , 1000 , "I"]
]
minuseffvars = [
  ["ETA", "muminus_ETA", 10 , 2 , 4.5 ],
  ["ETA8", "muminus_ETA", etabins ],
  ["PT", "muminus_PT",10 , 20000 , 70000 ],
  ["P", "muminus_P", 10, 0, 500000],
  ["Y", "boson_Y", 10, 2, 4.5],
  ["PHI", "muminus_PHI", 10 , -TMath.Pi() , TMath.Pi() ],
  ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
  ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
  ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
  ["SPDHits", "nSPDHits", 20 , 0 , 1000 , "I"]
]

def makeMuonTrackMatchMC2015Truth(name, selcut, passcut):
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
        
    MuonTrackMatchMC2015_P  = EfficiencyClass("Muon"+name+"TrackMatchMC2015_P")
    MuonTrackMatchMC2015_P.AddTree(zmumuMDGent)
    MuonTrackMatchMC2015_P.AddTree(zmumuMUGent)
    MuonTrackMatchMC2015_P.SetSelectionCut(selcutplus)
    MuonTrackMatchMC2015_P.SetPassCut(passcutplus)
    MuonTrackMatchMC2015_P.AddVars(pluseffvars)
    #MuonTrackMatchMC2015_P.SetPltRange("muplus_MuonTT_M" , 50 , 60000 , 120000);
    MuonTrackMatchMC2015_P.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrackMatchMC2015_P.MakeEntryLists()
    MuonTrackMatchMC2015_P.MakeHists()
    MuonTrackMatchMC2015_P.MakeEfficiencyGraph()

    MuonTrackMatchMC2015_M  = EfficiencyClass("Muon"+name+"TrackMatchMC2015_M")
    MuonTrackMatchMC2015_M.AddTree(zmumuMDGent)
    MuonTrackMatchMC2015_M.AddTree(zmumuMUGent)
    MuonTrackMatchMC2015_M.SetSelectionCut(selcutminus)
    MuonTrackMatchMC2015_M.SetPassCut(passcutminus)
    MuonTrackMatchMC2015_M.AddVars(minuseffvars)
    #MuonTrackMatchMC2015_M.SetPltRange("muminus_MuonTT_M" , 50 , 60000 , 120000);
    MuonTrackMatchMC2015_M.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrackMatchMC2015_M.MakeEntryLists()
    MuonTrackMatchMC2015_M.MakeHists()
    MuonTrackMatchMC2015_M.MakeEfficiencyGraph()

    MuonTrackMatchMC2015 = EfficiencyClass("Muon"+name+"TrackMatchMC2015" , MuonTrackMatchMC2015_P , MuonTrackMatchMC2015_M );
    MuonTrackMatchMC2015.MakeEfficiencyGraph();
    MuonTrackMatchMC2015.SaveToFile();

def makeMuonTrackMatchMC2015Gen(name, selcut, passcut):
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
        
    MuonTrackMatchMC2015_P  = EfficiencyClass("Muon"+name+"TrackMatchMC2015_P")
    MuonTrackMatchMC2015_P.AddTree(zmumuMDGent)
    MuonTrackMatchMC2015_P.AddTree(zmumuMUGent)
    MuonTrackMatchMC2015_P.SetSelectionCut(selcutplus)
    MuonTrackMatchMC2015_P.SetPassCut(passcutplus)
    MuonTrackMatchMC2015_P.AddVars(pluseffvars)
    #MuonTrackMatchMC2015_P.SetPltRange("muplus_MuonTT_M" , 50 , 60000 , 120000);
    MuonTrackMatchMC2015_P.SetPltRange("minustag_M" , 50 , 60000 , 120000)
    MuonTrackMatchMC2015_P.SetEffRange(70000,110000)
    MuonTrackMatchMC2015_P.MakeEntryLists()
    MuonTrackMatchMC2015_P.MakeHists()
    MuonTrackMatchMC2015_P.MakeEfficiencyGraph()

    MuonTrackMatchMC2015_M  = EfficiencyClass("Muon"+name+"TrackMatchMC2015_M")
    MuonTrackMatchMC2015_M.AddTree(zmumuMDGent)
    MuonTrackMatchMC2015_M.AddTree(zmumuMUGent)
    MuonTrackMatchMC2015_M.SetSelectionCut(selcutminus)
    MuonTrackMatchMC2015_M.SetPassCut(passcutminus)
    MuonTrackMatchMC2015_M.AddVars(minuseffvars)
    #MuonTrackMatchMC2015_M.SetPltRange("muminus_MuonTT_M" , 50 , 60000 , 120000);
    MuonTrackMatchMC2015_M.SetPltRange("plustag_M" , 50 , 60000 , 120000)
    MuonTrackMatchMC2015_M.SetEffRange(70000,110000)
    MuonTrackMatchMC2015_M.MakeEntryLists()
    MuonTrackMatchMC2015_M.MakeHists()
    MuonTrackMatchMC2015_M.MakeEfficiencyGraph()

    MuonTrackMatchMC2015 = EfficiencyClass("Muon"+name+"TrackMatchMC2015" , MuonTrackMatchMC2015_P , MuonTrackMatchMC2015_M );
    MuonTrackMatchMC2015.MakeEfficiencyGraph();
    MuonTrackMatchMC2015.SaveToFile();


def makeMuonTrackMatchMC2015(name, selcut, passcut):
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

    MuonTrackMatchMC2015_P = EfficiencyClass("Muon"+name+"TrackMatchMC2015_P")
    MuonTrackMatchMC2015_P.AddTree(t)
    MuonTrackMatchMC2015_P.AddTree(u)
    MuonTrackMatchMC2015_P.SetSelectionCut(selcutplus)
    MuonTrackMatchMC2015_P.SetPassCut(passcutplus)
    MuonTrackMatchMC2015_P.AddVars(pluseffvars)
    #MuonTrackMatchMC2015_P.GetVar("Y").SetVar("boson_Y")
    MuonTrackMatchMC2015_P.Add2DVars(eff2dvars)
    MuonTrackMatchMC2015_P.SetPltRange("muplus_MuonTT_M" , 50 , 60000 , 120000);
    MuonTrackMatchMC2015_P.SetEffRange(70000,110000)
    #MuonTrackMatchMC2015_P.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrackMatchMC2015_P.MakeEntryLists()
    MuonTrackMatchMC2015_P.MakeHists()
    MuonTrackMatchMC2015_P.MakeEfficiencyGraph()
    MuonTrackMatchMC2015_P.SaveToFile()

    MuonTrackMatchMC2015_M = EfficiencyClass("Muon"+name+"TrackMatchMC2015_M")
    MuonTrackMatchMC2015_M.AddTree(t)
    MuonTrackMatchMC2015_M.AddTree(u)
    MuonTrackMatchMC2015_M.SetSelectionCut(selcutminus)
    MuonTrackMatchMC2015_M.SetPassCut(passcutminus)
    MuonTrackMatchMC2015_M.AddVars(minuseffvars)
    #MuonTrackMatchMC2015_M.GetVar("Y").SetVar("boson_Y")
    MuonTrackMatchMC2015_M.Add2DVars(eff2dvars)
    #MuonTrackMatchMC2015_M.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrackMatchMC2015_M.SetPltRange("muminus_MuonTT_M" , 50 , 60000 , 120000);
    MuonTrackMatchMC2015_M.SetEffRange(70000,110000)
    MuonTrackMatchMC2015_M.MakeEntryLists()
    MuonTrackMatchMC2015_M.MakeHists()
    MuonTrackMatchMC2015_M.MakeEfficiencyGraph()
    MuonTrackMatchMC2015_M.SaveToFile()

    MuonTrackMatchMC2015 = EfficiencyClass("Muon"+name+"TrackMatchMC2015" , MuonTrackMatchMC2015_P , MuonTrackMatchMC2015_M );
    MuonTrackMatchMC2015.MakeEfficiencyGraph();
    MuonTrackMatchMC2015.SaveToFile();

makeMuonTrackMatchMC2015("", [selcut_plus, selcut_minus], [passcut_plus, passcut_minus])
makeMuonTrackMatchMC2015("W", [selcut_plus + wtrkqual_p, selcut_minus + wtrkqual_m], [passcut_plus, passcut_minus])
#makeMuonTrackMatchMC2015Truth("Ubs",[selcut_ubsplus, selcut_ubsminus], [passcut_genplus, passcut_genminus])
#makeMuonTrackMatchMC2015Gen("Gen",[selcut_genplus, selcut_genminus], [passcut_genplus, passcut_genminus])

