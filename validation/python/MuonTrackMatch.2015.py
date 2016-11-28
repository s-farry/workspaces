from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath

zmumurecf   = TFile("../tuples/MuonTracking.2015.root");
zmumurect   = zmumurecf.Get("Z2MuMu/DecayTree");

triggercut_plus  = TCut("muplus_Hlt2SingleMuonHighPTDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonDecision_TOS ==1")
triggercut_minus = TCut("muminus_Hlt2SingleMuonHighPTDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonDecision_TOS ==1")
  
hasMuTT_plus = TCut("muplus_MuonTT_PT > 20000 && muplus_MuonTT_DeltaR < 0.1")
hasMuTT_minus = TCut("muminus_MuonTT_PT > 20000 && muminus_MuonTT_DeltaR < 0.1")

matched_plus = TCut("muplus_MuonTT_nCommonMuonIDs/muplus_MuonTT_nMuonIDs > 0.4 && (muplus_nTTIDs > 0 ? muplus_MuonTT_nCommonTTIDs/muplus_MuonTT_nTTIDs > 0.6 : muplus_MuonTT_nTTIDs > 0)")
matched_minus = TCut("muminus_MuonTT_nCommonMuonIDs/muminus_MuonTT_nMuonIDs > 0.4 && (muminus_nTTIDs > 0 ? muminus_MuonTT_nCommonTTIDs/muminus_MuonTT_nTTIDs > 0.6 : muminus_MuonTT_nTTIDs > 0)")

loosematched_plus = TCut("muplus_MuonTT_nCommonMuonIDs/muplus_MuonTT_nMuonIDs > 0.4")
loosematched_minus = TCut("muminus_MuonTT_nCommonMuonIDs/muminus_MuonTT_nMuonIDs > 0.4")

magup = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

vtx_minus = TCut("muminus_MuonTT_VtxChi2/muminus_MuonTT_VtxNDoF < 5")
vtx_plus = TCut("muplus_MuonTT_VtxChi2/muplus_MuonTT_VtxNDoF < 5")

phicut_plus = TCut("muplus_MuonTT_DPhi > 0.1")
phicut_minus = TCut("muminus_MuonTT_DPhi > 0.1")

wplustrkqual = TCut("muplus_TRACK_PCHI2 > 0.01")
wminustrkqual = TCut("muminus_TRACK_PCHI2 > 0.01")

fiducial_rec = TCut("muplus_PT > 20000 && muminus_PT > 20000 && boson_M > 60000 && boson_M < 120000 && muplus_ETA > 2.0 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5 && muplus_TRACK_PCHI2 > 0.001 && muminus_TRACK_PCHI2 > 0.001 && sqrt(muplus_PERR2)/muplus_P < 0.1 && sqrt(muminus_PERR2)/muminus_P < 0.1 && muplus_cpt_0.50 < 2000 && muminus_cpt_0.50 < 2000 && boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
fiducial_LpMm = TCut("muplus_PT > 20000 && muminus_MuonTT_PT > 20000 && muminus_MuonTT_M > 70000 && muminus_MuonTT_M < 110000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muplus_TRACK_PCHI2 > 0.001 && muminus_MuonTT_ETA > 2 && muminus_MuonTT_ETA < 4.5")
fiducial_MpLm = TCut("muplus_MuonTT_PT > 20000 && muminus_PT > 20000 && muplus_MuonTT_M > 70000 && muplus_MuonTT_M < 110000 && muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_TRACK_PCHI2 > 0.001 && muplus_MuonTT_ETA > 2 && muplus_MuonTT_ETA < 4.5")

selcutptag = triggercut_plus + hasMuTT_minus + vtx_minus + phicut_minus
selcutmtag = triggercut_minus + hasMuTT_plus + vtx_plus + phicut_plus

selcut_PTag = fiducial_rec + selcutptag
selcut_MTag = fiducial_rec + selcutmtag

selcut_PTagLL = fiducial_LpMm + selcutptag
selcut_MTagLL = fiducial_MpLm + selcutmtag

pt25plus  = TCut("muplus_PT > 25000")
pt30plus  = TCut("muplus_PT > 30000")
pt25minus = TCut("muminus_PT > 25000")
pt30minus = TCut("muminus_PT > 30000")

'''
etabins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
etabins2 = [2.0 , 2.25 , 2.5 , 2.75 , 2.875, 3.00 , 3.1225, 3.25 , 3.375, 3.5 , 4.0 , 4.5]
tckbins = [3500000.0, 4600000.0, 4800000.0, 5700000.0, 5900000.0, 6000000.0, 7100000.0, 7300000.0, 7400000.0,
           7500000.0, 7600000.0, 7700000.0, 7900000.0, 7929912.0, 8000000.0]

pluseffvars = [
    ["ETA", "muplus_MuonTT_ETA", 10 , 2 , 4.5 ],
    ["ETA8", "muplus_MuonTT_ETA", etabins ],
    ["PT", "muplus_MuonTT_PT", 10 , 20000 , 70000],
    ["P", "muplus_MuonTT_P", 8 , 100000 , 500000],
    ["PHI", "muplus_MuonTT_PHI", 10 , -TMath.Pi() , TMath.Pi()],
    ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
    ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
    ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
    ["TCK", "OdinTCK", tckbins, "I"]
    ]
minuseffvars = [
    ["ETA", "muminus_MuonTT_ETA", 10 , 2 , 4.5 ],
    ["ETA8", "muminus_MuonTT_ETA", etabins ],
    ["PT", "muminus_MuonTT_PT", 10 , 20000 , 70000],
    ["P", "muminus_MuonTT_P", 8 , 100000 , 500000],
    ["PHI", "muminus_MuonTT_PHI", 10 , -TMath.Pi() , TMath.Pi()],
    ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
    ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
    ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
    ["TCK", "OdinTCK", tckbins, "I"]
    ]

eff2dvars = [
    ["ETA","PHI"],
    ["ETA","PT"]
    ]
'''
from effbins_config import *

def makeMuonTrackMatch2015(name, selcut, passcut):
    #selcut and pass cut plus is first is array
    MuonTrackMatch2015MagUpMuPlus    = EfficiencyClass("Muon"+name+"TrackMatch2015MagUpMuPlus")
    MuonTrackMatch2015MagDownMuPlus  = EfficiencyClass("Muon"+name+"TrackMatch2015MagDownMuPlus")
    MuonTrackMatch2015MagUpMuMinus   = EfficiencyClass("Muon"+name+"TrackMatch2015MagUpMuMinus")
    MuonTrackMatch2015MagDownMuMinus = EfficiencyClass("Muon"+name+"TrackMatch2015MagDownMuMinus")
  
    MuonTrackMatch2015MagUpMuMinus.AddTree(zmumurect)
    MuonTrackMatch2015MagUpMuMinus.SetSelectionCut(selcut[1] + magup )
    MuonTrackMatch2015MagUpMuMinus.SetPassCut(passcut[1])
    MuonTrackMatch2015MagUpMuMinus.AddVars(minuseffvars + trkminuseffvars)
    MuonTrackMatch2015MagUpMuMinus.Add2DVars(trk2dvars)
    MuonTrackMatch2015MagUpMuMinus.SetPltRange("muminus_MuonTT_M" , 60 , 60000 , 120000)
    MuonTrackMatch2015MagUpMuMinus.SetEffRange(70000 , 110000)
    MuonTrackMatch2015MagUpMuMinus.MakeEntryLists()
    MuonTrackMatch2015MagUpMuMinus.MakeHists();
    MuonTrackMatch2015MagUpMuMinus.MakeEfficiencyGraph();
    MuonTrackMatch2015MagUpMuMinus.SaveToFile();
  
    MuonTrackMatch2015MagUpMuPlus.AddTree(zmumurect)
    MuonTrackMatch2015MagUpMuPlus.SetSelectionCut(selcut[0] + magup )
    MuonTrackMatch2015MagUpMuPlus.SetPassCut(passcut[0])
    MuonTrackMatch2015MagUpMuPlus.AddVars(pluseffvars + trkpluseffvars)
    MuonTrackMatch2015MagUpMuPlus.Add2DVars(trk2dvars)
    MuonTrackMatch2015MagUpMuPlus.SetPltRange("muplus_MuonTT_M" , 60 , 60000 , 120000)
    MuonTrackMatch2015MagUpMuPlus.SetEffRange(70000 , 110000)
    MuonTrackMatch2015MagUpMuPlus.MakeEntryLists()
    MuonTrackMatch2015MagUpMuPlus.MakeHists();
    MuonTrackMatch2015MagUpMuPlus.MakeEfficiencyGraph();
    MuonTrackMatch2015MagUpMuPlus.SaveToFile();
  
    MuonTrackMatch2015MagDownMuMinus.AddTree(zmumurect)
    MuonTrackMatch2015MagDownMuMinus.SetSelectionCut(selcut[1] + magdown )
    MuonTrackMatch2015MagDownMuMinus.SetPassCut(passcut[1])
    MuonTrackMatch2015MagDownMuMinus.AddVars(minuseffvars + trkminuseffvars)
    MuonTrackMatch2015MagDownMuMinus.Add2DVars(trk2dvars)
    MuonTrackMatch2015MagDownMuMinus.SetPltRange("muminus_MuonTT_M" , 60 , 60000 , 120000)
    MuonTrackMatch2015MagDownMuMinus.SetEffRange(70000 , 110000)
    MuonTrackMatch2015MagDownMuMinus.MakeEntryLists()
    MuonTrackMatch2015MagDownMuMinus.MakeHists()
    MuonTrackMatch2015MagDownMuMinus.MakeEfficiencyGraph()
    MuonTrackMatch2015MagDownMuMinus.SaveToFile()
  
    MuonTrackMatch2015MagDownMuPlus.AddTree(zmumurect)
    MuonTrackMatch2015MagDownMuPlus.SetSelectionCut(selcut[0] + magdown )
    MuonTrackMatch2015MagDownMuPlus.SetPassCut(passcut[0])
    MuonTrackMatch2015MagDownMuPlus.AddVars(pluseffvars + trkpluseffvars)
    MuonTrackMatch2015MagDownMuPlus.Add2DVars(trk2dvars)
    MuonTrackMatch2015MagDownMuPlus.SetPltRange("muplus_MuonTT_M" , 60 , 60000 , 120000)
    MuonTrackMatch2015MagDownMuPlus.SetEffRange(70000 , 110000)
    MuonTrackMatch2015MagDownMuPlus.MakeEntryLists()
    MuonTrackMatch2015MagDownMuPlus.MakeHists();
    MuonTrackMatch2015MagDownMuPlus.MakeEfficiencyGraph();
    MuonTrackMatch2015MagDownMuPlus.SaveToFile();
  
    MuonTrackMatch2015MagUp = EfficiencyClass("Muon"+name+"TrackMatch2015MagUp", MuonTrackMatch2015MagUpMuPlus, MuonTrackMatch2015MagUpMuMinus )
    MuonTrackMatch2015MagUp.MakeEfficiencyGraph()
    MuonTrackMatch2015MagUp.SaveToFile()
  
    MuonTrackMatch2015MagDown = EfficiencyClass( "Muon"+name+"TrackMatch2015MagDown", MuonTrackMatch2015MagDownMuPlus, MuonTrackMatch2015MagDownMuMinus )
    MuonTrackMatch2015MagDown.MakeEfficiencyGraph()
    MuonTrackMatch2015MagDown.SaveToFile()
  
    MuonTrackMatch2015MuPlus = EfficiencyClass("Muon"+name+"TrackMatch2015MuPlus", MuonTrackMatch2015MagUpMuPlus, MuonTrackMatch2015MagDownMuPlus )
    MuonTrackMatch2015MuPlus.MakeEfficiencyGraph()
    MuonTrackMatch2015MuPlus.SaveToFile()
  
    MuonTrackMatch2015MuMinus = EfficiencyClass( "Muon"+name+"TrackMatch2015MuMinus", MuonTrackMatch2015MagUpMuMinus, MuonTrackMatch2015MagDownMuMinus )
    MuonTrackMatch2015MuMinus.MakeEfficiencyGraph()
    MuonTrackMatch2015MuMinus.SaveToFile()

    MuonTrackMatch2015 = EfficiencyClass("Muon"+name+"TrackMatch2015", MuonTrackMatch2015MagDown, MuonTrackMatch2015MagUp )
    MuonTrackMatch2015.MakeEfficiencyGraph()
    MuonTrackMatch2015.SaveToFile()

makeMuonTrackMatch2015("",[selcut_MTag, selcut_PTag], [matched_plus, matched_minus])
makeMuonTrackMatch2015("W",[selcut_MTag + wplustrkqual, selcut_PTag + wminustrkqual], [matched_plus, matched_minus])
#makeMuonTrackMatch2015("WPT25",[selcut_MTag + wplustrkqual + pt25plus, selcut_PTag + wminustrkqual + pt25minus], [matched_plus, matched_minus])
#makeMuonTrackMatch2015("WPT30",[selcut_MTag + wplustrkqual + pt30plus, selcut_PTag + wminustrkqual + pt30minus], [matched_plus, matched_minus])
#makeMuonTracking2015("PT25",selcut + pt25, passcut)
#makeMuonTracking2015("PT30",selcut + pt30, passcut)

