
from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath, TH1
TH1.AddDirectory(False)
import copy

phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>2.7")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")

triggercut  = TCut("tag_Hlt2SingleMuonHighPTDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonDecision_TOS ==1")
trkqual    = TCut("tag_TRACK_PCHI2 > 0.001 && probe_TRACK_PCHI2 > 0.001 && (sqrt(tag_PERR2)/tag_P) < 0.1 && (sqrt(probe_PERR2)/probe_P) < 0.1")
wtrkqual    = TCut("tag_TRACK_PCHI2 > 0.001 && probe_TRACK_PCHI2 > 0.01 && (sqrt(tag_PERR2)/tag_P) < 0.1 && (sqrt(probe_PERR2)/probe_P) < 0.1")
eta        = TCut("tag_ETA > 2 && tag_ETA < 4.5 && probe_ETA > 2 && probe_ETA < 4.5")
vtxcut     = TCut("boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
isocut     = TCut("tag_cpt_0.50 < 2000 && probe_cpt_0.50 < 2000")
pt25 = TCut("probe_PT > 25000")
pt30 = TCut("probe_PT > 30000")
passcut = TCut("probe_isMuon == 1")
Ep = TCut("((probe_CaloHcalE + probe_CaloEcalE)/probe_P)<0.04")

after_bugfix = TCut("runNumber > 162240")

selcut = ptcut + phicut + isocut + triggercut + trkqual + vtxcut + eta

f = TFile("/user2/sfarry/validation/tuples/MuonID.2015em.root")
t = f.Get("PlusTag/DecayTree")
u = f.Get("MinusTag/DecayTree")
v = f.Get("PlusTagSS/DecayTree")
w = f.Get("MinusTagSS/DecayTree")
   
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

selcutMU = selcut + magup
selcutMD = selcut + magdown
'''
etabins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
etabins2 = [2.0 , 2.25 , 2.5 , 2.75 , 2.875, 3.00 , 3.1225, 3.25 , 3.375, 3.5 , 4.0 , 4.5]
tckbins = [3500000.0, 4600000.0, 4800000.0, 5700000.0, 5900000.0, 6000000.0, 7100000.0, 7300000.0, 7400000.0,
           7500000.0, 7600000.0, 7700000.0, 7900000.0, 7929912.0, 8000000.0]

effvars = [
    ["ETA", "probe_ETA", 10 , 2 , 4.5 ],
    ["ETA8", "probe_ETA", etabins ],
    ["PT", "probe_PT", 10 , 20000 , 70000],
    ["P", "probe_P", 8 , 100000 , 500000],
    ["PHI", "probe_PHI", 10 , -TMath.Pi() , TMath.Pi()],
    ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
    ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
    ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
    ["TCK", "OdinTCK", tckbins, "I"],
    ["SPDHits", "nSPDHits", 20 , 0 , 1000, "I"]
    ]

eff2dvars = [
    ["ETA","PHI"],
    ["ETA","PT"],
    ]
'''
from effbins_config import *

pt_systematic = [0.001 for i in range(10)]
pt_systematic[0] = 0.01;
pt_systematic[1] = 0.003;


def makeMuonID2015em(name, selcut, passcut):
    MuonID2015emMagUpMuPlus    = EfficiencyClass("Muon"+name+"ID2015emMagUpMuPlus")
    MuonID2015emMagDownMuPlus  = EfficiencyClass("Muon"+name+"ID2015emMagDownMuPlus")
    MuonID2015emMagUpMuMinus   = EfficiencyClass("Muon"+name+"ID2015emMagUpMuMinus")
    MuonID2015emMagDownMuMinus = EfficiencyClass("Muon"+name+"ID2015emMagDownMuMinus")
    
    MuonID2015emMagUpMuMinus.AddTree(t)
    MuonID2015emMagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonID2015emMagUpMuMinus.SetPassCut(passcut)
    MuonID2015emMagUpMuMinus.AddVars(effvars)
    #MuonID2015emMagUpMuMinus.AddVars(mupos)
    MuonID2015emMagUpMuMinus.Add2DVars(eff2dvars)
    #MuonID2015emMagUpMuMinus.Add2DVars(mupos2d)
    MuonID2015emMagUpMuMinus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonID2015emMagUpMuMinus.MakeEntryLists()
    MuonID2015emMagUpMuMinus.MakeHists()
    MuonID2015emMagUpMuMinus.MakeEfficiencyGraph()
    MuonID2015emMagUpMuMinus.AddSystematic("PT",pt_systematic)
    MuonID2015emMagUpMuMinus.AddSystematic(0.001)
    MuonID2015emMagUpMuMinus.SaveToFile()
    
    MuonID2015emMagUpMuPlus.AddTree(u)
    MuonID2015emMagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonID2015emMagUpMuPlus.SetPassCut(passcut)
    MuonID2015emMagUpMuPlus.AddVars(effvars)
    #MuonID2015emMagUpMuPlus.AddVars(mupos_plus)
    MuonID2015emMagUpMuPlus.Add2DVars(eff2dvars)
    #MuonID2015emMagUpMuPlus.Add2DVars(mupos2d)
    MuonID2015emMagUpMuPlus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonID2015emMagUpMuPlus.MakeEntryLists()
    MuonID2015emMagUpMuPlus.MakeHists()
    MuonID2015emMagUpMuPlus.MakeEfficiencyGraph()
    MuonID2015emMagUpMuPlus.AddSystematic("PT",pt_systematic)
    MuonID2015emMagUpMuPlus.AddSystematic(0.001)
    MuonID2015emMagUpMuPlus.SaveToFile()
    
    MuonID2015emMagDownMuMinus.AddTree(t)
    MuonID2015emMagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonID2015emMagDownMuMinus.SetPassCut(passcut)
    MuonID2015emMagDownMuMinus.AddVars(effvars)
    #MuonID2015emMagDownMuMinus.AddVars(mupos)
    MuonID2015emMagDownMuMinus.Add2DVars(eff2dvars)
    #MuonID2015emMagDownMuMinus.Add2DVars(mupos2d)
    MuonID2015emMagDownMuMinus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonID2015emMagDownMuMinus.MakeEntryLists()
    MuonID2015emMagDownMuMinus.MakeHists()
    MuonID2015emMagDownMuMinus.MakeEfficiencyGraph()
    MuonID2015emMagDownMuMinus.AddSystematic("PT",pt_systematic)
    MuonID2015emMagDownMuMinus.AddSystematic(0.001)
    MuonID2015emMagDownMuMinus.SaveToFile()
    
    MuonID2015emMagDownMuPlus.AddTree(u)
    MuonID2015emMagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonID2015emMagDownMuPlus.SetPassCut(passcut)
    MuonID2015emMagDownMuPlus.AddVars(effvars)
    #MuonID2015emMagDownMuPlus.AddVars(mupos_plus)
    MuonID2015emMagDownMuPlus.Add2DVars(eff2dvars)
    #MuonID2015emMagDownMuPlus.Add2DVars(mupos2d)
    MuonID2015emMagDownMuPlus.SetPltRange("boson_M" , 50 , 60000 , 120000)
    MuonID2015emMagDownMuPlus.MakeEntryLists()
    MuonID2015emMagDownMuPlus.MakeHists()
    MuonID2015emMagDownMuPlus.MakeEfficiencyGraph()
    MuonID2015emMagDownMuPlus.AddSystematic("PT",pt_systematic)
    MuonID2015emMagDownMuPlus.AddSystematic(0.001)
    MuonID2015emMagDownMuPlus.SaveToFile()
    
    MuonID2015emMagDown = EfficiencyClass("Muon"+name+"ID2015emMagDown", MuonID2015emMagDownMuPlus, MuonID2015emMagDownMuMinus)
    MuonID2015emMagDown.MakeEfficiencyGraph()
    MuonID2015emMagDown.AddSystematic("PT",pt_systematic)
    MuonID2015emMagDown.AddSystematic(0.001)
    MuonID2015emMagDown.SaveToFile()
    
    MuonID2015emMagUp = EfficiencyClass("Muon"+name+"ID2015emMagUp", MuonID2015emMagUpMuPlus, MuonID2015emMagUpMuMinus)
    MuonID2015emMagUp.MakeEfficiencyGraph()
    MuonID2015emMagUp.AddSystematic("PT",pt_systematic)
    MuonID2015emMagUp.AddSystematic(0.001)
    MuonID2015emMagUp.SaveToFile()
    
    MuonID2015emMuPlus = EfficiencyClass("Muon"+name+"ID2015emMuPlus", MuonID2015emMagDownMuPlus, MuonID2015emMagUpMuPlus)
    MuonID2015emMuPlus.MakeEfficiencyGraph()
    MuonID2015emMuPlus.AddSystematic("PT",pt_systematic)
    MuonID2015emMuPlus.AddSystematic(0.001)
    MuonID2015emMuPlus.SaveToFile()

    MuonID2015emMuMinus = EfficiencyClass("Muon"+name+"ID2015emMuMinus", MuonID2015emMagDownMuMinus, MuonID2015emMagUpMuMinus)
    MuonID2015emMuMinus.MakeEfficiencyGraph()
    #MuonID2015emMuMinus.PrintEfficiencies("ETA")
    MuonID2015emMuMinus.AddSystematic("PT",pt_systematic)
    MuonID2015emMuMinus.AddSystematic(0.001)
    MuonID2015emMuMinus.SaveToFile()
    
    MuonID2015em = EfficiencyClass("Muon"+name+"ID2015em", MuonID2015emMagDown, MuonID2015emMagUp)
    MuonID2015em.MakeEfficiencyGraph()
    MuonID2015em.AddSystematic("PT",pt_systematic)
    MuonID2015em.AddSystematic(0.001)
    MuonID2015em.SaveToFile()

    MuonID2015em_staterr = EfficiencyClass("Muon"+name+"ID2015em_staterr", MuonID2015emMagDown, MuonID2015emMagUp)
    MuonID2015em_staterr.MakeEfficiencyGraph()
    MuonID2015em_staterr.SaveToFile()

    MuonID2015em_systerr = EfficiencyClass("Muon"+name+"ID2015em_systerr", MuonID2015emMagDown, MuonID2015emMagUp)
    MuonID2015em_systerr.MakeEfficiencyGraph()
    MuonID2015em_systerr.RemoveErrors()
    MuonID2015em_systerr.AddSystematic("PT",pt_systematic)
    MuonID2015em_systerr.AddSystematic(0.001)
    MuonID2015em_systerr.SaveToFile()


makeMuonID2015em("",selcut,passcut)
#makeMuonID2015em("W",selcut + wtrkqual,passcut)
#makeMuonID2015em("Ep",selcut,passcut + Ep)
#makeMuonID2015em("PT25",selcut + pt25, passcut)
#makeMuonID2015em("PT30",selcut + pt30, passcut)
