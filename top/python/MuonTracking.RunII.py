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

f = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonTracking_WLine.MD.2016.root')
g = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonTracking_WLine.MU.2016.root')
h = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonTracking_WLine.MD.2015.root')
i = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonTracking_WLine.MU.2015.root')

t = f.Get("PlusTag/DecayTree")
u = f.Get("MinusTag/DecayTree")
v = g.Get("PlusTag/DecayTree")
w = g.Get("MinusTag/DecayTree")

tt = h.Get("PlusTag/DecayTree")
uu = h.Get("MinusTag/DecayTree")
vv = i.Get("PlusTag/DecayTree")
ww = i.Get("MinusTag/DecayTree")

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

def makeMuonTrackingRunII(name, selcut, passcut):
    MuonTrackingRunIIMagUpMuPlus    = EfficiencyClass("Muon"+name+"TrackingRunIIMagUpMuPlus")
    MuonTrackingRunIIMagDownMuPlus  = EfficiencyClass("Muon"+name+"TrackingRunIIMagDownMuPlus")
    MuonTrackingRunIIMagUpMuMinus   = EfficiencyClass("Muon"+name+"TrackingRunIIMagUpMuMinus")
    MuonTrackingRunIIMagDownMuMinus = EfficiencyClass("Muon"+name+"TrackingRunIIMagDownMuMinus")
    
    MuonTrackingRunIIMagUpMuMinus.AddTree(v)
    MuonTrackingRunIIMagUpMuMinus.AddTree(vv)
    MuonTrackingRunIIMagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonTrackingRunIIMagUpMuMinus.SetPassCut(passcut)
    MuonTrackingRunIIMagUpMuMinus.AddVars(effvars + trkeffvars)
    MuonTrackingRunIIMagUpMuMinus.Add2DVars(trk2dvars)
    MuonTrackingRunIIMagUpMuMinus.Run()
    MuonTrackingRunIIMagUpMuMinus.SaveToFile()
    
    MuonTrackingRunIIMagUpMuPlus.AddTree(w)
    MuonTrackingRunIIMagUpMuPlus.AddTree(ww)
    MuonTrackingRunIIMagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonTrackingRunIIMagUpMuPlus.SetPassCut(passcut)
    MuonTrackingRunIIMagUpMuPlus.AddVars(effvars + trkeffvars)
    MuonTrackingRunIIMagUpMuPlus.Add2DVars(trk2dvars)
    MuonTrackingRunIIMagUpMuPlus.Run()
    MuonTrackingRunIIMagUpMuPlus.SaveToFile()
    
    MuonTrackingRunIIMagDownMuMinus.AddTree(t)
    MuonTrackingRunIIMagDownMuMinus.AddTree(tt)
    MuonTrackingRunIIMagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonTrackingRunIIMagDownMuMinus.SetPassCut(passcut)
    MuonTrackingRunIIMagDownMuMinus.AddVars(effvars + trkeffvars)
    MuonTrackingRunIIMagDownMuMinus.Add2DVars(trk2dvars)
    MuonTrackingRunIIMagDownMuMinus.Run()
    MuonTrackingRunIIMagDownMuMinus.SaveToFile()
    
    MuonTrackingRunIIMagDownMuPlus.AddTree(u)
    MuonTrackingRunIIMagDownMuPlus.AddTree(uu)
    MuonTrackingRunIIMagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonTrackingRunIIMagDownMuPlus.SetPassCut(passcut)
    MuonTrackingRunIIMagDownMuPlus.AddVars(effvars + trkeffvars)
    MuonTrackingRunIIMagDownMuPlus.Add2DVars(trk2dvars)
    MuonTrackingRunIIMagDownMuPlus.Run()
    MuonTrackingRunIIMagDownMuPlus.SaveToFile()


    
    MuonTrackingRunIIMagDown = EfficiencyClass("Muon"+name+"TrackingRunIIMagDown", MuonTrackingRunIIMagDownMuPlus, MuonTrackingRunIIMagDownMuMinus)
    MuonTrackingRunIIMagDown.MakeEfficiencyGraph()
    MuonTrackingRunIIMagDown.SaveToFile()
    
    MuonTrackingRunIIMagUp = EfficiencyClass("Muon"+name+"TrackingRunIIMagUp", MuonTrackingRunIIMagUpMuPlus, MuonTrackingRunIIMagUpMuMinus)
    MuonTrackingRunIIMagUp.MakeEfficiencyGraph()
    MuonTrackingRunIIMagUp.SaveToFile()
    
    MuonTrackingRunIIMuPlus = EfficiencyClass("Muon"+name+"TrackingRunIIMuPlus", MuonTrackingRunIIMagDownMuPlus, MuonTrackingRunIIMagUpMuPlus)
    MuonTrackingRunIIMuPlus.MakeEfficiencyGraph()
    MuonTrackingRunIIMuPlus.SaveToFile()

    MuonTrackingRunIIMuMinus = EfficiencyClass("Muon"+name+"TrackingRunIIMuMinus", MuonTrackingRunIIMagDownMuMinus, MuonTrackingRunIIMagUpMuMinus)
    MuonTrackingRunIIMuMinus.MakeEfficiencyGraph()
    MuonTrackingRunIIMuMinus.PrintEfficiencies("ETA")
    MuonTrackingRunIIMuMinus.SaveToFile()
    
    MuonTrackingRunII = EfficiencyClass("Muon"+name+"TrackingRunII", MuonTrackingRunIIMagDown, MuonTrackingRunIIMagUp)
    MuonTrackingRunII.MakeEfficiencyGraph()
    MuonTrackingRunII.SaveToFile()

makeMuonTrackingRunII("",selcut,passcut)
#makeMuonTrackingRunII("W",selcut,passcutW)
