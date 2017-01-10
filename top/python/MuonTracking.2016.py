from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath


phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>0.1")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")
  

triggercut  = TCut("tag_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonEWDecision_TOS ==1")
run1triggercut  = TCut("tag_Hlt2SingleMuonHighPTDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonDecision_TOS ==1")

trkqual    = TCut("(sqrt(tag_PERR2)/tag_P) < 0.1")
eta        = TCut("tag_ETA > 2 && tag_ETA < 4.5 && probe_ETA > 2 && probe_ETA < 4.5")
vtxcut     = TCut("boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
isocut     = TCut("tag_cpt_0.50 < 2000")
pt25 = TCut("probe_PT > 25000")
pt30 = TCut("probe_PT > 30000")
passcut = TCut("probe_AssocZM == 1")
passcutW = TCut("probe_AssocWM == 1")
passcutStd = TCut("probe_AssocStdM == 1")
mass = TCut("boson_M > 70000 && boson_M < 110000")

selcut = ptcut + phicut + triggercut + trkqual + vtxcut + eta + mass

#f = TFile("/hepstore/sfarry/GridOutput/2618/MuonTracking.MU.2016.root")
#g = TFile("/hepstore/sfarry/GridOutput/2617/MuonTracking.MD.2016.root")
#f = TFile("/hepstore/sfarry/GridOutput/2641/MuonTracking_WLine.MD.2016.root")
#g = TFile("/hepstore/sfarry/GridOutput/2642/MuonTracking_WLine.MU.2016.root")

f = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonTracking_WLine.MU.2016.root')
g = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonTracking_WLine.MD.2016.root')

t = f.Get("PlusTag/DecayTree")
u = f.Get("MinusTag/DecayTree")
v = g.Get("PlusTag/DecayTree")
w = g.Get("MinusTag/DecayTree")

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

def makeMuonTracking2016(name, selcut, passcut):
    MuonTracking2016MagUpMuPlus    = EfficiencyClass("Muon"+name+"Tracking2016MagUpMuPlus")
    MuonTracking2016MagDownMuPlus  = EfficiencyClass("Muon"+name+"Tracking2016MagDownMuPlus")
    MuonTracking2016MagUpMuMinus   = EfficiencyClass("Muon"+name+"Tracking2016MagUpMuMinus")
    MuonTracking2016MagDownMuMinus = EfficiencyClass("Muon"+name+"Tracking2016MagDownMuMinus")
    
    MuonTracking2016MagUpMuMinus.AddTree(v)
    MuonTracking2016MagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonTracking2016MagUpMuMinus.SetPassCut(passcut)
    MuonTracking2016MagUpMuMinus.AddVars(effvars + trkeffvars)
    MuonTracking2016MagUpMuMinus.Add2DVars(trk2dvars)
    MuonTracking2016MagUpMuMinus.Run()
    MuonTracking2016MagUpMuMinus.SaveToFile()
    
    MuonTracking2016MagUpMuPlus.AddTree(w)
    MuonTracking2016MagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonTracking2016MagUpMuPlus.SetPassCut(passcut)
    MuonTracking2016MagUpMuPlus.AddVars(effvars + trkeffvars)
    MuonTracking2016MagUpMuPlus.Add2DVars(trk2dvars)
    MuonTracking2016MagUpMuPlus.Run()
    MuonTracking2016MagUpMuPlus.SaveToFile()
    
    MuonTracking2016MagDownMuMinus.AddTree(t)
    MuonTracking2016MagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonTracking2016MagDownMuMinus.SetPassCut(passcut)
    MuonTracking2016MagDownMuMinus.AddVars(effvars + trkeffvars)
    MuonTracking2016MagDownMuMinus.Add2DVars(trk2dvars)
    MuonTracking2016MagDownMuMinus.Run()
    MuonTracking2016MagDownMuMinus.SaveToFile()
    
    MuonTracking2016MagDownMuPlus.AddTree(u)
    MuonTracking2016MagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonTracking2016MagDownMuPlus.SetPassCut(passcut)
    MuonTracking2016MagDownMuPlus.AddVars(effvars + trkeffvars)
    MuonTracking2016MagDownMuPlus.Add2DVars(trk2dvars)
    MuonTracking2016MagDownMuPlus.Run()
    MuonTracking2016MagDownMuPlus.SaveToFile()


    
    MuonTracking2016MagDown = EfficiencyClass("Muon"+name+"Tracking2016MagDown", MuonTracking2016MagDownMuPlus, MuonTracking2016MagDownMuMinus)
    MuonTracking2016MagDown.MakeEfficiencyGraph()
    MuonTracking2016MagDown.SaveToFile()
    
    MuonTracking2016MagUp = EfficiencyClass("Muon"+name+"Tracking2016MagUp", MuonTracking2016MagUpMuPlus, MuonTracking2016MagUpMuMinus)
    MuonTracking2016MagUp.MakeEfficiencyGraph()
    MuonTracking2016MagUp.SaveToFile()
    
    MuonTracking2016MuPlus = EfficiencyClass("Muon"+name+"Tracking2016MuPlus", MuonTracking2016MagDownMuPlus, MuonTracking2016MagUpMuPlus)
    MuonTracking2016MuPlus.MakeEfficiencyGraph()
    MuonTracking2016MuPlus.SaveToFile()

    MuonTracking2016MuMinus = EfficiencyClass("Muon"+name+"Tracking2016MuMinus", MuonTracking2016MagDownMuMinus, MuonTracking2016MagUpMuMinus)
    MuonTracking2016MuMinus.MakeEfficiencyGraph()
    MuonTracking2016MuMinus.PrintEfficiencies("ETA")
    MuonTracking2016MuMinus.SaveToFile()
    
    MuonTracking2016 = EfficiencyClass("Muon"+name+"Tracking2016", MuonTracking2016MagDown, MuonTracking2016MagUp)
    MuonTracking2016.MakeEfficiencyGraph()
    MuonTracking2016.SaveToFile()

makeMuonTracking2016("",selcut,passcut)
#makeMuonTracking2016("W",selcut,passcutW)
