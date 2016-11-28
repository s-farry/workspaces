from analysis import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath


phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>0.1")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")
  
triggercut = TCut("tag_Hlt2SingleMuonHighPTDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonDecision_TOS ==1")
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

f = TFile("../Tuples/MuonTracking2012.root")
   
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

def makeMuonTracking2012(name, selcut, passcut):
    MuonTracking2012MagUpMuPlus    = EfficiencyClass("Muon"+name+"Tracking2012MagUpMuPlus")
    MuonTracking2012MagDownMuPlus  = EfficiencyClass("Muon"+name+"Tracking2012MagDownMuPlus")
    MuonTracking2012MagUpMuMinus   = EfficiencyClass("Muon"+name+"Tracking2012MagUpMuMinus")
    MuonTracking2012MagDownMuMinus = EfficiencyClass("Muon"+name+"Tracking2012MagDownMuMinus")
    
    MuonTracking2012MagUpMuMinus.SetTree(t)
    MuonTracking2012MagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonTracking2012MagUpMuMinus.SetPassCut(passcut)
    MuonTracking2012MagUpMuMinus.AddVars(effvars + trkeffvars)
    MuonTracking2012MagUpMuMinus.Add2DVars(trk2dvars)
    MuonTracking2012MagUpMuMinus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTracking2012MagUpMuMinus.SetEffRange(70000 , 110000)
    MuonTracking2012MagUpMuMinus.MakeEntryLists()
    MuonTracking2012MagUpMuMinus.MakeHists()
    MuonTracking2012MagUpMuMinus.MakeEfficiencyGraph()
    MuonTracking2012MagUpMuMinus.SaveToFile()
    
    MuonTracking2012MagUpMuPlus.SetTree(u)
    MuonTracking2012MagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonTracking2012MagUpMuPlus.SetPassCut(passcut)
    MuonTracking2012MagUpMuPlus.AddVars(effvars + trkeffvars)
    MuonTracking2012MagUpMuPlus.Add2DVars(trk2dvars)
    MuonTracking2012MagUpMuPlus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTracking2012MagUpMuPlus.SetEffRange(70000 , 110000)
    MuonTracking2012MagUpMuPlus.MakeEntryLists()
    MuonTracking2012MagUpMuPlus.MakeHists()
    MuonTracking2012MagUpMuPlus.MakeEfficiencyGraph()
    MuonTracking2012MagUpMuPlus.SaveToFile()
    
    MuonTracking2012MagDownMuMinus.SetTree(t)
    MuonTracking2012MagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonTracking2012MagDownMuMinus.SetPassCut(passcut)
    MuonTracking2012MagDownMuMinus.AddVars(effvars + trkeffvars)
    MuonTracking2012MagDownMuMinus.Add2DVars(trk2dvars)
    MuonTracking2012MagDownMuMinus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTracking2012MagDownMuMinus.SetEffRange(70000 , 110000)
    MuonTracking2012MagDownMuMinus.MakeEntryLists()
    MuonTracking2012MagDownMuMinus.MakeHists()
    MuonTracking2012MagDownMuMinus.MakeEfficiencyGraph()
    MuonTracking2012MagDownMuMinus.SaveToFile()
    
    MuonTracking2012MagDownMuPlus.SetTree(u)
    MuonTracking2012MagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonTracking2012MagDownMuPlus.SetPassCut(passcut)
    MuonTracking2012MagDownMuPlus.AddVars(effvars + trkeffvars)
    MuonTracking2012MagDownMuPlus.Add2DVars(trk2dvars)
    MuonTracking2012MagDownMuPlus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTracking2012MagDownMuPlus.SetEffRange(70000 , 110000)
    MuonTracking2012MagDownMuPlus.MakeEntryLists()
    MuonTracking2012MagDownMuPlus.MakeHists()
    MuonTracking2012MagDownMuPlus.MakeEfficiencyGraph()
    MuonTracking2012MagDownMuPlus.SaveToFile()


    
    MuonTracking2012MagDown = EfficiencyClass("Muon"+name+"Tracking2012MagDown", MuonTracking2012MagDownMuPlus, MuonTracking2012MagDownMuMinus)
    MuonTracking2012MagDown.MakeEfficiencyGraph()
    MuonTracking2012MagDown.SaveToFile()
    
    MuonTracking2012MagUp = EfficiencyClass("Muon"+name+"Tracking2012MagUp", MuonTracking2012MagUpMuPlus, MuonTracking2012MagUpMuMinus)
    MuonTracking2012MagUp.MakeEfficiencyGraph()
    MuonTracking2012MagUp.SaveToFile()
    
    MuonTracking2012MuPlus = EfficiencyClass("Muon"+name+"Tracking2012MuPlus", MuonTracking2012MagDownMuPlus, MuonTracking2012MagUpMuPlus)
    MuonTracking2012MuPlus.MakeEfficiencyGraph()
    MuonTracking2012MuPlus.SaveToFile()

    MuonTracking2012MuMinus = EfficiencyClass("Muon"+name+"Tracking2012MuMinus", MuonTracking2012MagDownMuMinus, MuonTracking2012MagUpMuMinus)
    MuonTracking2012MuMinus.MakeEfficiencyGraph()
    MuonTracking2012MuMinus.PrintEfficiencies("ETA")
    MuonTracking2012MuMinus.SaveToFile()
    
    MuonTracking2012 = EfficiencyClass("Muon"+name+"Tracking2012", MuonTracking2012MagDown, MuonTracking2012MagUp)
    MuonTracking2012.MakeEfficiencyGraph()
    MuonTracking2012.SaveToFile()

makeMuonTracking2012("",selcut,passcut)
makeMuonTracking2012("W",selcut,passcutW)
#makeMuonTracking2012("Std",selcut,passcutStd)
#makeMuonTracking2012("PT25",selcut + pt25, passcut)
#makeMuonTracking2012("PT30",selcut + pt30, passcut)
