from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath


phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>0.1")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")

triggercut  = TCut("tag_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonEWDecision_TOS ==1")
  
triggercut_old = TCut("tag_Hlt2SingleMuonHighPTDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonDecision_TOS ==1")
trkqual    = TCut("tag_TRACK_PCHI2 > 0.001 && (sqrt(tag_PERR2)/tag_P) < 0.1")
eta        = TCut("tag_ETA > 2 && tag_ETA < 4.5 && probe_ETA > 2 && probe_ETA < 4.5")
vtxcut     = TCut("boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
isocut     = TCut("tag_cpt_0.50 < 2000")
pt25 = TCut("probe_PT > 25000")
pt30 = TCut("probe_PT > 30000")
passcut = TCut("probe_AssocZM == 1")
passcutW = TCut("probe_AssocWM == 1")
passcutStd = TCut("probe_AssocStdM == 1")

selcut = ptcut + phicut + triggercut + trkqual + vtxcut + eta

f = TFile("../tuples/MuonTracking.2015.root")
   
t = f.Get("PlusTag/DecayTree")
u = f.Get("MinusTag/DecayTree")
   
magup = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

selcutMU = selcut + magup
selcutMD = selcut + magdown
'''
etabins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
etabins2 = [2.0 , 2.25 , 2.5 , 2.75 , 2.875, 3.00 , 3.1225, 3.25 , 3.375, 3.5 , 4.0 , 4.5]
tckbins = [3500000.0, 4600000.0, 4800000.0, 5700000.0, 5900000.0, 6000000.0, 7100000.0, 7300000.0, 7400000.0,
           7500000.0, 7600000.0, 7700000.0, 7900000.0, 7929912.0, 8000000.0]

effvars = [
    ["ETA", "probe_ETA", 10 , 2 , 4.5 ],
    ["ETA5", "probe_ETA", 5 , 2 , 4.5 ],
    ["ETA8", "probe_ETA", etabins ],
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
'''
from effbins_config import *

def makeMuonTracking2015(name, selcut, passcut):
    MuonTracking2015MagUpMuPlus    = EfficiencyClass("Muon"+name+"Tracking2015MagUpMuPlus")
    MuonTracking2015MagDownMuPlus  = EfficiencyClass("Muon"+name+"Tracking2015MagDownMuPlus")
    MuonTracking2015MagUpMuMinus   = EfficiencyClass("Muon"+name+"Tracking2015MagUpMuMinus")
    MuonTracking2015MagDownMuMinus = EfficiencyClass("Muon"+name+"Tracking2015MagDownMuMinus")
    
    MuonTracking2015MagUpMuMinus.AddTree(t)
    MuonTracking2015MagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonTracking2015MagUpMuMinus.SetPassCut(passcut)
    MuonTracking2015MagUpMuMinus.AddVars(effvars + trkeffvars)
    MuonTracking2015MagUpMuMinus.Add2DVars(trk2dvars)
    MuonTracking2015MagUpMuMinus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTracking2015MagUpMuMinus.SetEffRange(70000 , 110000)
    MuonTracking2015MagUpMuMinus.MakeEntryLists()
    MuonTracking2015MagUpMuMinus.MakeHists()
    MuonTracking2015MagUpMuMinus.MakeEfficiencyGraph()
    MuonTracking2015MagUpMuMinus.SaveToFile()
    
    MuonTracking2015MagUpMuPlus.AddTree(u)
    MuonTracking2015MagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonTracking2015MagUpMuPlus.SetPassCut(passcut)
    MuonTracking2015MagUpMuPlus.AddVars(effvars + trkeffvars)
    MuonTracking2015MagUpMuPlus.Add2DVars(trk2dvars)
    MuonTracking2015MagUpMuPlus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTracking2015MagUpMuPlus.SetEffRange(70000 , 110000)
    MuonTracking2015MagUpMuPlus.MakeEntryLists()
    MuonTracking2015MagUpMuPlus.MakeHists()
    MuonTracking2015MagUpMuPlus.MakeEfficiencyGraph()
    MuonTracking2015MagUpMuPlus.SaveToFile()
    
    MuonTracking2015MagDownMuMinus.AddTree(t)
    MuonTracking2015MagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonTracking2015MagDownMuMinus.SetPassCut(passcut)
    MuonTracking2015MagDownMuMinus.AddVars(effvars + trkeffvars)
    MuonTracking2015MagDownMuMinus.Add2DVars(trk2dvars)
    MuonTracking2015MagDownMuMinus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTracking2015MagDownMuMinus.SetEffRange(70000 , 110000)
    MuonTracking2015MagDownMuMinus.MakeEntryLists()
    MuonTracking2015MagDownMuMinus.MakeHists()
    MuonTracking2015MagDownMuMinus.MakeEfficiencyGraph()
    MuonTracking2015MagDownMuMinus.SaveToFile()
    
    MuonTracking2015MagDownMuPlus.AddTree(u)
    MuonTracking2015MagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonTracking2015MagDownMuPlus.SetPassCut(passcut)
    MuonTracking2015MagDownMuPlus.AddVars(effvars + trkeffvars)
    MuonTracking2015MagDownMuPlus.Add2DVars(trk2dvars)
    MuonTracking2015MagDownMuPlus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTracking2015MagDownMuPlus.SetEffRange(70000 , 110000)
    MuonTracking2015MagDownMuPlus.MakeEntryLists()
    MuonTracking2015MagDownMuPlus.MakeHists()
    MuonTracking2015MagDownMuPlus.MakeEfficiencyGraph()
    MuonTracking2015MagDownMuPlus.SaveToFile()


    
    MuonTracking2015MagDown = EfficiencyClass("Muon"+name+"Tracking2015MagDown", MuonTracking2015MagDownMuPlus, MuonTracking2015MagDownMuMinus)
    MuonTracking2015MagDown.MakeEfficiencyGraph()
    MuonTracking2015MagDown.SaveToFile()
    
    MuonTracking2015MagUp = EfficiencyClass("Muon"+name+"Tracking2015MagUp", MuonTracking2015MagUpMuPlus, MuonTracking2015MagUpMuMinus)
    MuonTracking2015MagUp.MakeEfficiencyGraph()
    MuonTracking2015MagUp.SaveToFile()
    
    MuonTracking2015MuPlus = EfficiencyClass("Muon"+name+"Tracking2015MuPlus", MuonTracking2015MagDownMuPlus, MuonTracking2015MagUpMuPlus)
    MuonTracking2015MuPlus.MakeEfficiencyGraph()
    MuonTracking2015MuPlus.SaveToFile()

    MuonTracking2015MuMinus = EfficiencyClass("Muon"+name+"Tracking2015MuMinus", MuonTracking2015MagDownMuMinus, MuonTracking2015MagUpMuMinus)
    MuonTracking2015MuMinus.MakeEfficiencyGraph()
    MuonTracking2015MuMinus.PrintEfficiencies("ETA")
    MuonTracking2015MuMinus.SaveToFile()
    
    MuonTracking2015 = EfficiencyClass("Muon"+name+"Tracking2015", MuonTracking2015MagDown, MuonTracking2015MagUp)
    MuonTracking2015.MakeEfficiencyGraph()
    MuonTracking2015.SaveToFile()

makeMuonTracking2015("",selcut,passcut)
makeMuonTracking2015("W",selcut,passcutW)
#makeMuonTracking2015("Std",selcut,passcutStd)
#makeMuonTracking2015("PT25",selcut + pt25, passcut)
#makeMuonTracking2015("PT30",selcut + pt30, passcut)
