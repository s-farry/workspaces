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

def makeMuonTrigger2016(name, selcut, passcut):
    MuonTrigger2016MagUpMuPlus    = EfficiencyClass("Muon"+name+"Trigger2016MagUpMuPlus")
    MuonTrigger2016MagDownMuPlus  = EfficiencyClass("Muon"+name+"Trigger2016MagDownMuPlus")
    MuonTrigger2016MagUpMuMinus   = EfficiencyClass("Muon"+name+"Trigger2016MagUpMuMinus")
    MuonTrigger2016MagDownMuMinus = EfficiencyClass("Muon"+name+"Trigger2016MagDownMuMinus")
    
    MuonTrigger2016MagUpMuMinus.AddTree(u)
    MuonTrigger2016MagUpMuMinus.SetSelectionCut(selcut[0] + magup)
    MuonTrigger2016MagUpMuMinus.SetPassCut(passcut[0])
    MuonTrigger2016MagUpMuMinus.AddVars(minuseffvars)
    MuonTrigger2016MagUpMuMinus.AddVars(mupos)
    MuonTrigger2016MagUpMuMinus.Add2DVars(eff2dvars)
    MuonTrigger2016MagUpMuMinus.Add2DVars(mupos2d)
    MuonTrigger2016MagUpMuMinus.Run()
    MuonTrigger2016MagUpMuMinus.SaveToFile()
    
    MuonTrigger2016MagUpMuPlus.AddTree(u)
    MuonTrigger2016MagUpMuPlus.SetSelectionCut(selcut[1] + magup)
    MuonTrigger2016MagUpMuPlus.SetPassCut(passcut[1])
    MuonTrigger2016MagUpMuPlus.AddVars(pluseffvars)
    MuonTrigger2016MagUpMuPlus.AddVars(mupos_plus)
    MuonTrigger2016MagUpMuPlus.Add2DVars(eff2dvars)
    MuonTrigger2016MagUpMuPlus.Add2DVars(mupos2d)
    MuonTrigger2016MagUpMuPlus.Run()
    MuonTrigger2016MagUpMuPlus.SaveToFile()
    
    MuonTrigger2016MagDownMuMinus.AddTree(t)
    MuonTrigger2016MagDownMuMinus.SetSelectionCut(selcut[0] + magdown)
    MuonTrigger2016MagDownMuMinus.SetPassCut(passcut[0])
    MuonTrigger2016MagDownMuMinus.AddVars(minuseffvars)
    MuonTrigger2016MagDownMuMinus.AddVars(mupos)
    MuonTrigger2016MagDownMuMinus.Add2DVars(eff2dvars)
    MuonTrigger2016MagDownMuMinus.Add2DVars(mupos2d)
    MuonTrigger2016MagDownMuMinus.Run()
    MuonTrigger2016MagDownMuMinus.SaveToFile()
    
    MuonTrigger2016MagDownMuPlus.AddTree(t)
    MuonTrigger2016MagDownMuPlus.SetSelectionCut(selcut[1] + magdown)
    MuonTrigger2016MagDownMuPlus.SetPassCut(passcut[1])
    MuonTrigger2016MagDownMuPlus.AddVars(pluseffvars)
    MuonTrigger2016MagDownMuPlus.AddVars(mupos_plus)
    MuonTrigger2016MagDownMuPlus.Add2DVars(eff2dvars)
    MuonTrigger2016MagDownMuPlus.Add2DVars(mupos2d)
    MuonTrigger2016MagDownMuPlus.Run()
    MuonTrigger2016MagDownMuPlus.SaveToFile()
    
    MuonTrigger2016MagDown = EfficiencyClass("Muon"+name+"Trigger2016MagDown", MuonTrigger2016MagDownMuPlus, MuonTrigger2016MagDownMuMinus)
    MuonTrigger2016MagDown.MakeEfficiencyGraph()
    MuonTrigger2016MagDown.SaveToFile()
    
    MuonTrigger2016MagUp = EfficiencyClass("Muon"+name+"Trigger2016MagUp", MuonTrigger2016MagUpMuPlus, MuonTrigger2016MagUpMuMinus)
    MuonTrigger2016MagUp.MakeEfficiencyGraph()
    MuonTrigger2016MagUp.SaveToFile()
    
    MuonTrigger2016MuPlus = EfficiencyClass("Muon"+name+"Trigger2016MuPlus", MuonTrigger2016MagDownMuPlus, MuonTrigger2016MagUpMuPlus)
    MuonTrigger2016MuPlus.MakeEfficiencyGraph()
    MuonTrigger2016MuPlus.SaveToFile()

    MuonTrigger2016MuMinus = EfficiencyClass("Muon"+name+"Trigger2016MuMinus", MuonTrigger2016MagDownMuMinus, MuonTrigger2016MagUpMuMinus)
    MuonTrigger2016MuMinus.MakeEfficiencyGraph()
    MuonTrigger2016MuMinus.SaveToFile()
    
    MuonTrigger2016 = EfficiencyClass("Muon"+name+"Trigger2016", MuonTrigger2016MagDown, MuonTrigger2016MagUp)
    MuonTrigger2016.MakeEfficiencyGraph()
    MuonTrigger2016.SaveToFile()

makeMuonTrigger2016(""      ,[selcut_ptag, selcut_mtag]                       , [triggercut_minus, triggercut_plus])
#makeMuonTrigger2016("W"     ,[selcut_ptag + wtrkqual, selcut_mtag + wtrkqual] , [triggercut_minus, triggercut_plus])
makeMuonTrigger2016("L0EW"  ,[selcut_ptag, selcut_mtag]                       , [l0ewtriggercut_minus, l0ewtriggercut_plus])
makeMuonTrigger2016("L0"    ,[selcut_ptag+l0triggercut_plus, selcut_mtag+l0triggercut_minus],[l0triggercut_minus, l0triggercut_plus])
makeMuonTrigger2016("L0SPD"    ,[selcut_ptag, selcut_mtag ],[l0triggercut_minus, l0triggercut_plus])
makeMuonTrigger2016("HLT1"  ,[selcut_ptag + l0triggercut_minus, selcut_mtag + l0triggercut_plus],[hlt1triggercut_minus, hlt1triggercut_plus])
makeMuonTrigger2016("HLT2"  ,[selcut_ptag + l0triggercut_minus + hlt1triggercut_minus, selcut_mtag + l0triggercut_plus + hlt1triggercut_plus],  [hlt2triggercut_minus, hlt2triggercut_plus])
