from analysis import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath, TH1
TH1.AddDirectory(False)

triggercut = TCut("tag_Hlt2EWSingleMuonHighPTDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0EWMuonDecision_TOS ==1")
trkqual    = TCut("tag_TRACK_PCHI2 > 0.001 && probe_TRACK_PCHI2 > 0.001 && (sqrt(tag_PERR2)/tag_P) < 0.1 && (sqrt(probe_PERR2)/probe_P) < 0.1")
wtrkqual    = TCut("tag_TRACK_PCHI2 > 0.001 && probe_TRACK_PCHI2 > 0.01 && (sqrt(tag_PERR2)/tag_P) < 0.1 && (sqrt(probe_PERR2)/probe_P) < 0.1")
eta        = TCut("tag_ETA > 2 && tag_ETA < 4.5 && probe_ETA > 2 && probe_ETA < 4.5")
vtxcut     = TCut("boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
isocut     = TCut("tag_cpt_0.50 < 2000 && probe_cpt_0.50 < 2000")
pt         = TCut("tag_PT > 20000 && probe_PT > 20000" )
selcut     = pt + triggercut + trkqual + eta + vtxcut + isocut
probetriggercut = TCut("probe_Hlt2EWSingleMuonHighPTDecision_TOS==1 && probe_Hlt1EWSingleMuonHighPTDecision_TOS == 1 && probe_L0MuonEWDecision_TOS ==1")
probel0triggercut = TCut("probe_L0EWMuonDecision_TOS ==1")
probehlt1triggercut = TCut("probe_Hlt1EWSingleMuonHighPTDecision_TOS == 1")
pt25 = TCut("probe_PT > 25000")
pt30 = TCut("probe_PT > 30000")
   
f = TFile("../Tuples/MuonTrigger2012.root")
t = f.Get("PlusTag/DecayTree");
u = f.Get("MinusTag/DecayTree");

magup = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

selcutMU = selcut + magup
selcutMD = selcut + magdown

etabins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
etabins2 = [2.0 , 2.25 , 2.5 , 2.75 , 2.875, 3.00 , 3.1225, 3.25 , 3.375, 3.5 , 4.0 , 4.5]
tckbins = [3500000.0, 4600000.0, 4800000.0, 5700000.0, 5900000.0, 6000000.0, 7100000.0, 7300000.0, 7400000.0,
           7500000.0, 7600000.0, 7700000.0, 7900000.0, 7929912.0, 8000000.0]
'''
effvars = [
    ["ETA", "probe_ETA", 10 , 2 , 4.5 ],
    ["ETA8", "probe_ETA", etabins ],
#    ["ETAFine", "probe_ETA", etabins2 ],
    ["PT", "probe_PT", 10 , 20000 , 70000],
    ["P", "probe_P", 8 , 100000 , 500000],
    ["PHI", "probe_PHI", 10 , -TMath.Pi() , TMath.Pi()],
    ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
    ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
    ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
    ["TCK", "OdinTCK", tckbins, "I"],
    ["SPDHits", "nSPDHits", 20 , 0 , 1000, "I"],
    ["PCHI2", "probe_TRACK_PCHI2", 20, 0 , 1],
    ["CHI2NDOF", "probe_TRACK_CHI2NDOF", 12, 0 , 3]
    ]

eff2dvars = [
    ["ETA","PHI"],
    ["ETA","PT"],
    ["TCK","ETA8"],
#    ["TCK","ETAFine"]
    ]
'''
from effbins_config import *

def makeMuonTrigger2012(name, selcut, passcut):
    MuonTrigger2012MagUpMuPlus    = EfficiencyClass("Muon"+name+"Trigger2012MagUpMuPlus")
    MuonTrigger2012MagDownMuPlus  = EfficiencyClass("Muon"+name+"Trigger2012MagDownMuPlus")
    MuonTrigger2012MagUpMuMinus   = EfficiencyClass("Muon"+name+"Trigger2012MagUpMuMinus")
    MuonTrigger2012MagDownMuMinus = EfficiencyClass("Muon"+name+"Trigger2012MagDownMuMinus")
    
    MuonTrigger2012MagUpMuMinus.SetTree(t)
    MuonTrigger2012MagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonTrigger2012MagUpMuMinus.SetPassCut(passcut)
    MuonTrigger2012MagUpMuMinus.AddVars(effvars + trgeffvars)
    MuonTrigger2012MagUpMuMinus.Add2DVars(eff2dvars)
    MuonTrigger2012MagUpMuMinus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrigger2012MagUpMuMinus.MakeEntryLists()
    MuonTrigger2012MagUpMuMinus.MakeHists()
    MuonTrigger2012MagUpMuMinus.MakeEfficiencyGraph()
    MuonTrigger2012MagUpMuMinus.SaveToFile()
    
    MuonTrigger2012MagUpMuPlus.SetTree(u)
    MuonTrigger2012MagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonTrigger2012MagUpMuPlus.SetPassCut(passcut)
    MuonTrigger2012MagUpMuPlus.AddVars(effvars + trgeffvars)
    MuonTrigger2012MagUpMuPlus.Add2DVars(eff2dvars)
    MuonTrigger2012MagUpMuPlus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrigger2012MagUpMuPlus.MakeEntryLists()
    MuonTrigger2012MagUpMuPlus.MakeHists()
    MuonTrigger2012MagUpMuPlus.MakeEfficiencyGraph()
    MuonTrigger2012MagUpMuPlus.SaveToFile()
    
    MuonTrigger2012MagDownMuMinus.SetTree(t)
    MuonTrigger2012MagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonTrigger2012MagDownMuMinus.SetPassCut(passcut)
    MuonTrigger2012MagDownMuMinus.AddVars(effvars + trgeffvars)
    MuonTrigger2012MagDownMuMinus.Add2DVars(eff2dvars)
    MuonTrigger2012MagDownMuMinus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrigger2012MagDownMuMinus.MakeEntryLists()
    MuonTrigger2012MagDownMuMinus.MakeHists()
    MuonTrigger2012MagDownMuMinus.MakeEfficiencyGraph()
    MuonTrigger2012MagDownMuMinus.SaveToFile()
    
    MuonTrigger2012MagDownMuPlus.SetTree(u)
    MuonTrigger2012MagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonTrigger2012MagDownMuPlus.SetPassCut(passcut)
    MuonTrigger2012MagDownMuPlus.AddVars(effvars + trgeffvars)
    MuonTrigger2012MagDownMuPlus.Add2DVars(eff2dvars)
    MuonTrigger2012MagDownMuPlus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonTrigger2012MagDownMuPlus.MakeEntryLists()
    MuonTrigger2012MagDownMuPlus.MakeHists()
    MuonTrigger2012MagDownMuPlus.MakeEfficiencyGraph()
    MuonTrigger2012MagDownMuPlus.SaveToFile()
    
    MuonTrigger2012MagDown = EfficiencyClass("Muon"+name+"Trigger2012MagDown", MuonTrigger2012MagDownMuPlus, MuonTrigger2012MagDownMuMinus)
    MuonTrigger2012MagDown.MakeEfficiencyGraph()
    MuonTrigger2012MagDown.SaveToFile()
    
    MuonTrigger2012MagUp = EfficiencyClass("Muon"+name+"Trigger2012MagUp", MuonTrigger2012MagUpMuPlus, MuonTrigger2012MagUpMuMinus)
    MuonTrigger2012MagUp.MakeEfficiencyGraph()
    MuonTrigger2012MagUp.SaveToFile()
    
    MuonTrigger2012MuPlus = EfficiencyClass("Muon"+name+"Trigger2012MuPlus", MuonTrigger2012MagDownMuPlus, MuonTrigger2012MagUpMuPlus)
    MuonTrigger2012MuPlus.MakeEfficiencyGraph()
    MuonTrigger2012MuPlus.SaveToFile()

    MuonTrigger2012MuMinus = EfficiencyClass("Muon"+name+"Trigger2012MuMinus", MuonTrigger2012MagDownMuMinus, MuonTrigger2012MagUpMuMinus)
    MuonTrigger2012MuMinus.MakeEfficiencyGraph()
    MuonTrigger2012MuMinus.SaveToFile()
    
    MuonTrigger2012 = EfficiencyClass("Muon"+name+"Trigger2012", MuonTrigger2012MagDown, MuonTrigger2012MagUp)
    MuonTrigger2012.MakeEfficiencyGraph()
    MuonTrigger2012.SaveToFile()

makeMuonTrigger2012("",selcut,probetriggercut)
makeMuonTrigger2012("W",selcut + wtrkqual,probetriggercut)
#makeMuonTrigger2012("L0",selcut,probel0triggercut)
#makeMuonTrigger2012("Hlt1",selcut + probel0triggercut , probehlt1triggercut)
#makeMuonTrigger2012("Hlt2",selcut + probel0triggercut + probehlt1triggercut, probetriggercut)
#makeMuonTrigger2012("PT25",selcut + pt25, probetriggercut)
#makeMuonTrigger2012("PT30",selcut + pt30, probetriggercut)
