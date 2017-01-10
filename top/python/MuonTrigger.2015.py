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

f = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MD.2015.root")
t = f.Get("ZMuMu/DecayTree");
g = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/ZMuMuJet.MU.2015.root")
u = g.Get("ZMuMu/DecayTree");

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
for v in mupos_plus: v[1] = v[1].replace('minus', 'plus')

mupos2d = [
    ["musta_2_x", "musta_2_y"],
    ["musta_3_x", "musta_3_y"],
    ["musta_4_x", "musta_4_y"],
    ["musta_5_x", "musta_5_y"]
]

from effbins_config import *
plusvars  = GetVars(stdvars, 'muplus')
minusvars = GetVars(stdvars, 'muminus')

def makeMuonTrigger2015(name, selcut, passcut):
    MuonTrigger2015MagUpMuPlus    = EfficiencyClass("Muon"+name+"Trigger2015MagUpMuPlus")
    MuonTrigger2015MagDownMuPlus  = EfficiencyClass("Muon"+name+"Trigger2015MagDownMuPlus")
    MuonTrigger2015MagUpMuMinus   = EfficiencyClass("Muon"+name+"Trigger2015MagUpMuMinus")
    MuonTrigger2015MagDownMuMinus = EfficiencyClass("Muon"+name+"Trigger2015MagDownMuMinus")
    
    MuonTrigger2015MagUpMuMinus.AddTree(u)
    MuonTrigger2015MagUpMuMinus.SetSelectionCut(selcut[0] + magup)
    MuonTrigger2015MagUpMuMinus.SetPassCut(passcut[0])
    MuonTrigger2015MagUpMuMinus.AddVars(minuseffvars)
    MuonTrigger2015MagUpMuMinus.AddVars(mupos)
    MuonTrigger2015MagUpMuMinus.Add2DVars(eff2dvars)
    MuonTrigger2015MagUpMuMinus.Add2DVars(mupos2d)
    MuonTrigger2015MagUpMuMinus.Run()
    MuonTrigger2015MagUpMuMinus.SaveToFile()
    
    MuonTrigger2015MagUpMuPlus.AddTree(u)
    MuonTrigger2015MagUpMuPlus.SetSelectionCut(selcut[1] + magup)
    MuonTrigger2015MagUpMuPlus.SetPassCut(passcut[1])
    MuonTrigger2015MagUpMuPlus.AddVars(pluseffvars)
    MuonTrigger2015MagUpMuPlus.AddVars(mupos_plus)
    MuonTrigger2015MagUpMuPlus.Add2DVars(eff2dvars)
    MuonTrigger2015MagUpMuPlus.Add2DVars(mupos2d)
    MuonTrigger2015MagUpMuPlus.Run()
    MuonTrigger2015MagUpMuPlus.SaveToFile()
    
    MuonTrigger2015MagDownMuMinus.AddTree(t)
    MuonTrigger2015MagDownMuMinus.SetSelectionCut(selcut[0] + magdown)
    MuonTrigger2015MagDownMuMinus.SetPassCut(passcut[0])
    MuonTrigger2015MagDownMuMinus.AddVars(minuseffvars)
    MuonTrigger2015MagDownMuMinus.AddVars(mupos)
    MuonTrigger2015MagDownMuMinus.Add2DVars(eff2dvars)
    MuonTrigger2015MagDownMuMinus.Add2DVars(mupos2d)
    MuonTrigger2015MagDownMuMinus.Run()
    MuonTrigger2015MagDownMuMinus.SaveToFile()
    
    MuonTrigger2015MagDownMuPlus.AddTree(t)
    MuonTrigger2015MagDownMuPlus.SetSelectionCut(selcut[1] + magdown)
    MuonTrigger2015MagDownMuPlus.SetPassCut(passcut[1])
    MuonTrigger2015MagDownMuPlus.AddVars(pluseffvars)
    MuonTrigger2015MagDownMuPlus.AddVars(mupos_plus)
    MuonTrigger2015MagDownMuPlus.Add2DVars(eff2dvars)
    MuonTrigger2015MagDownMuPlus.Add2DVars(mupos2d)
    MuonTrigger2015MagDownMuPlus.Run()
    MuonTrigger2015MagDownMuPlus.SaveToFile()
    
    MuonTrigger2015MagDown = EfficiencyClass("Muon"+name+"Trigger2015MagDown", MuonTrigger2015MagDownMuPlus, MuonTrigger2015MagDownMuMinus)
    MuonTrigger2015MagDown.MakeEfficiencyGraph()
    MuonTrigger2015MagDown.SaveToFile()
    
    MuonTrigger2015MagUp = EfficiencyClass("Muon"+name+"Trigger2015MagUp", MuonTrigger2015MagUpMuPlus, MuonTrigger2015MagUpMuMinus)
    MuonTrigger2015MagUp.MakeEfficiencyGraph()
    MuonTrigger2015MagUp.SaveToFile()
    
    MuonTrigger2015MuPlus = EfficiencyClass("Muon"+name+"Trigger2015MuPlus", MuonTrigger2015MagDownMuPlus, MuonTrigger2015MagUpMuPlus)
    MuonTrigger2015MuPlus.MakeEfficiencyGraph()
    MuonTrigger2015MuPlus.SaveToFile()

    MuonTrigger2015MuMinus = EfficiencyClass("Muon"+name+"Trigger2015MuMinus", MuonTrigger2015MagDownMuMinus, MuonTrigger2015MagUpMuMinus)
    MuonTrigger2015MuMinus.MakeEfficiencyGraph()
    MuonTrigger2015MuMinus.SaveToFile()
    
    MuonTrigger2015 = EfficiencyClass("Muon"+name+"Trigger2015", MuonTrigger2015MagDown, MuonTrigger2015MagUp)
    MuonTrigger2015.MakeEfficiencyGraph()
    MuonTrigger2015.SaveToFile()

makeMuonTrigger2015(""      ,[selcut_ptag, selcut_mtag]                       , [triggercut_minus, triggercut_plus])
#makeMuonTrigger2015("W"     ,[selcut_ptag + wtrkqual, selcut_mtag + wtrkqual] , [triggercut_minus, triggercut_plus])
makeMuonTrigger2015("L0EW"  ,[selcut_ptag, selcut_mtag]                       , [l0ewtriggercut_minus, l0ewtriggercut_plus])
makeMuonTrigger2015("L0"    ,[selcut_ptag+l0triggercut_plus, selcut_mtag+l0triggercut_minus],[l0triggercut_minus, l0triggercut_plus])
makeMuonTrigger2015("L0SPD"    ,[selcut_ptag, selcut_mtag ],[l0triggercut_minus, l0triggercut_plus])
makeMuonTrigger2015("HLT1"  ,[selcut_ptag + l0triggercut_minus, selcut_mtag + l0triggercut_plus],[hlt1triggercut_minus, hlt1triggercut_plus])
makeMuonTrigger2015("HLT2"  ,[selcut_ptag + l0triggercut_minus + hlt1triggercut_minus, selcut_mtag + l0triggercut_plus + hlt1triggercut_plus],  [hlt2triggercut_minus, hlt2triggercut_plus])
