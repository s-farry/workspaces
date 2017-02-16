from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath, TH1
TH1.AddDirectory(False)
import copy

triggercut_plus  = TCut("muplus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonEWDecision_TOS ==1")
triggercut_minus = TCut("muminus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonEWDecision_TOS ==1")
trkqual    = TCut("muplus_TRACK_PCHI2 > 0.001 && muminus_TRACK_PCHI2 > 0.001 && (sqrt(muplus_PERR2)/muplus_P) < 0.1 && (sqrt(muminus_PERR2)/muminus_P) < 0.1")
wtrkqual    = TCut("muplus_TRACK_PCHI2 > 0.001 && muminus_TRACK_PCHI2 > 0.01 && (sqrt(muplus_PERR2)/muplus_P) < 0.1 && (sqrt(muminus_PERR2)/muminus_P) < 0.1")
eta        = TCut("muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5")
vtxcut     = TCut("boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
isocut     = TCut("muplus_cpt_0.50 < 2000 && muminus_cpt_0.50 < 2000")
pt         = TCut("muplus_PT > 20000 && muminus_PT > 20000" )
mass       = TCut("boson_M > 60000 && boson_M < 120000")
after_bugfix = TCut("runNumber > 162240")
selcut_ptag     = pt + triggercut_plus  + trkqual + eta + vtxcut + mass + after_bugfix # + isocut
selcut_mtag     = pt + triggercut_minus + trkqual + eta + vtxcut + mass + after_bugfix # + isocut
l0ewtriggercut_plus  = TCut("muplus_L0MuonEWDecision_TOS ==1")
l0triggercut_plus    = TCut("muplus_L0MuonDecision_TOS ==1")
hlt1triggercut_plus  = TCut("muplus_Hlt1SingleMuonHighPTDecision_TOS == 1")
hlt2triggercut_plus  = TCut("muplus_Hlt2EWSingleMuonVHighPtDecision_TOS == 1")
l0triggercut_minus   = TCut("muminus_L0MuonDecision_TOS ==1")
l0ewtriggercut_minus = TCut("muminus_L0MuonEWDecision_TOS ==1")
hlt1triggercut_minus = TCut("muminus_Hlt1SingleMuonHighPTDecision_TOS == 1")
hlt2triggercut_minus = TCut("muminus_Hlt2EWSingleMuonVHighPtDecision_TOS == 1")
#after_bugfix = TCut("runNumber > 162240")

f = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MD.2016.root")
t = f.Get("ZMuMu/DecayTree");
g = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MU.2016.root")
u = g.Get("ZMuMu/DecayTree");
h = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MD.2015.root")
v = h.Get("ZMuMu/DecayTree");
i = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MU.2015.root")
w = i.Get("ZMuMu/DecayTree");

magup = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

mupos = [
    ["musta_2_x", "muminus_MuPosX_Extrap_2", 10, -4000, 4000],
    ["musta_2_y", "muminus_MuPosY_Extrap_2", 10, -4000, 4000],
    ["musta_3_x", "muminus_MuPosX_Extrap_3", 10, -4000, 4000],
    ["musta_3_y", "muminus_MuPosY_Extrap_3", 10, -4000, 4000],
    ["musta_4_x", "muminus_MuPosX_Extrap_4", 10, -4000, 4000],
    ["musta_4_y", "muminus_MuPosY_Extrap_4", 10, -4000, 4000],
    ["musta_5_x", "muminus_MuPosX_Extrap_5", 10, -4000, 4000],
    ["musta_5_y", "muminus_MuPosY_Extrap_5", 10, -4000, 4000]
    ]

mupos_plus = copy.deepcopy(mupos)
for vv in mupos_plus: vv[1] = vv[1].replace('minus', 'plus')

mupos2d = [
    ["musta_2_x", "musta_2_y"],
    ["musta_3_x", "musta_3_y"],
    ["musta_4_x", "musta_4_y"],
    ["musta_5_x", "musta_5_y"]
]

from effbins_config import *
plusvars  = GetVars(stdvars, 'muplus')
minusvars = GetVars(stdvars, 'muminus')

def makeMuonTriggerRunII(name, selcut, passcut):
    MuonTriggerRunIIMagUpMuPlus    = EfficiencyClass("Muon"+name+"TriggerRunIIMagUpMuPlus")
    MuonTriggerRunIIMagDownMuPlus  = EfficiencyClass("Muon"+name+"TriggerRunIIMagDownMuPlus")
    MuonTriggerRunIIMagUpMuMinus   = EfficiencyClass("Muon"+name+"TriggerRunIIMagUpMuMinus")
    MuonTriggerRunIIMagDownMuMinus = EfficiencyClass("Muon"+name+"TriggerRunIIMagDownMuMinus")
    
    MuonTriggerRunIIMagUpMuMinus.AddTree(u)
    MuonTriggerRunIIMagUpMuMinus.AddTree(w)
    MuonTriggerRunIIMagUpMuMinus.SetSelectionCut(selcut[0] + magup)
    MuonTriggerRunIIMagUpMuMinus.SetPassCut(passcut[0])
    MuonTriggerRunIIMagUpMuMinus.AddVars(minuseffvars)
    MuonTriggerRunIIMagUpMuMinus.AddVars(mupos)
    MuonTriggerRunIIMagUpMuMinus.Add2DVars(eff2dvars)
    MuonTriggerRunIIMagUpMuMinus.Add2DVars(mupos2d)
    MuonTriggerRunIIMagUpMuMinus.Run()
    MuonTriggerRunIIMagUpMuMinus.SaveToFile()
    
    MuonTriggerRunIIMagUpMuPlus.AddTree(u)
    MuonTriggerRunIIMagUpMuPlus.AddTree(w)
    MuonTriggerRunIIMagUpMuPlus.SetSelectionCut(selcut[1] + magup)
    MuonTriggerRunIIMagUpMuPlus.SetPassCut(passcut[1])
    MuonTriggerRunIIMagUpMuPlus.AddVars(pluseffvars)
    MuonTriggerRunIIMagUpMuPlus.AddVars(mupos_plus)
    MuonTriggerRunIIMagUpMuPlus.Add2DVars(eff2dvars)
    MuonTriggerRunIIMagUpMuPlus.Add2DVars(mupos2d)
    MuonTriggerRunIIMagUpMuPlus.Run()
    MuonTriggerRunIIMagUpMuPlus.SaveToFile()
    
    MuonTriggerRunIIMagDownMuMinus.AddTree(t)
    MuonTriggerRunIIMagDownMuMinus.AddTree(v)
    MuonTriggerRunIIMagDownMuMinus.SetSelectionCut(selcut[0] + magdown)
    MuonTriggerRunIIMagDownMuMinus.SetPassCut(passcut[0])
    MuonTriggerRunIIMagDownMuMinus.AddVars(minuseffvars)
    MuonTriggerRunIIMagDownMuMinus.AddVars(mupos)
    MuonTriggerRunIIMagDownMuMinus.Add2DVars(eff2dvars)
    MuonTriggerRunIIMagDownMuMinus.Add2DVars(mupos2d)
    MuonTriggerRunIIMagDownMuMinus.Run()
    MuonTriggerRunIIMagDownMuMinus.SaveToFile()
    
    MuonTriggerRunIIMagDownMuPlus.AddTree(t)
    MuonTriggerRunIIMagDownMuPlus.AddTree(v)
    MuonTriggerRunIIMagDownMuPlus.SetSelectionCut(selcut[1] + magdown)
    MuonTriggerRunIIMagDownMuPlus.SetPassCut(passcut[1])
    MuonTriggerRunIIMagDownMuPlus.AddVars(pluseffvars)
    MuonTriggerRunIIMagDownMuPlus.AddVars(mupos_plus)
    MuonTriggerRunIIMagDownMuPlus.Add2DVars(eff2dvars)
    MuonTriggerRunIIMagDownMuPlus.Add2DVars(mupos2d)
    MuonTriggerRunIIMagDownMuPlus.Run()
    MuonTriggerRunIIMagDownMuPlus.SaveToFile()
    
    MuonTriggerRunIIMagDown = EfficiencyClass("Muon"+name+"TriggerRunIIMagDown", MuonTriggerRunIIMagDownMuPlus, MuonTriggerRunIIMagDownMuMinus)
    MuonTriggerRunIIMagDown.MakeEfficiencyGraph()
    MuonTriggerRunIIMagDown.SaveToFile()
    
    MuonTriggerRunIIMagUp = EfficiencyClass("Muon"+name+"TriggerRunIIMagUp", MuonTriggerRunIIMagUpMuPlus, MuonTriggerRunIIMagUpMuMinus)
    MuonTriggerRunIIMagUp.MakeEfficiencyGraph()
    MuonTriggerRunIIMagUp.SaveToFile()
    
    MuonTriggerRunIIMuPlus = EfficiencyClass("Muon"+name+"TriggerRunIIMuPlus", MuonTriggerRunIIMagDownMuPlus, MuonTriggerRunIIMagUpMuPlus)
    MuonTriggerRunIIMuPlus.MakeEfficiencyGraph()
    MuonTriggerRunIIMuPlus.SaveToFile()

    MuonTriggerRunIIMuMinus = EfficiencyClass("Muon"+name+"TriggerRunIIMuMinus", MuonTriggerRunIIMagDownMuMinus, MuonTriggerRunIIMagUpMuMinus)
    MuonTriggerRunIIMuMinus.MakeEfficiencyGraph()
    MuonTriggerRunIIMuMinus.SaveToFile()
    
    MuonTriggerRunII = EfficiencyClass("Muon"+name+"TriggerRunII", MuonTriggerRunIIMagDown, MuonTriggerRunIIMagUp)
    MuonTriggerRunII.MakeEfficiencyGraph()
    MuonTriggerRunII.SaveToFile()

makeMuonTriggerRunII(""      ,[selcut_ptag, selcut_mtag]                       , [triggercut_minus, triggercut_plus])
#makeMuonTriggerRunII("W"     ,[selcut_ptag + wtrkqual, selcut_mtag + wtrkqual] , [triggercut_minus, triggercut_plus])
#makeMuonTriggerRunII("L0EW"  ,[selcut_ptag, selcut_mtag]                       , [l0ewtriggercut_minus, l0ewtriggercut_plus])
#makeMuonTriggerRunII("L0"    ,[selcut_ptag+l0triggercut_plus, selcut_mtag+l0triggercut_minus],[l0triggercut_minus, l0triggercut_plus])
#makeMuonTriggerRunII("L0SPD"    ,[selcut_ptag, selcut_mtag ],[l0triggercut_minus, l0triggercut_plus])
#makeMuonTriggerRunII("HLT1"  ,[selcut_ptag + l0triggercut_minus, selcut_mtag + l0triggercut_plus],[hlt1triggercut_minus, hlt1triggercut_plus])
#makeMuonTriggerRunII("HLT2"  ,[selcut_ptag + l0triggercut_minus + hlt1triggercut_minus, selcut_mtag + l0triggercut_plus + hlt1triggercut_plus],  [hlt2triggercut_minus, hlt2triggercut_plus])
