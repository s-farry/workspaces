
from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath, TH1
TH1.AddDirectory(False)
import copy

phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>2.7")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")

triggercut  = TCut("tag_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonEWDecision_TOS ==1")
trkqual    = TCut("(sqrt(tag_PERR2)/tag_P) < 0.1 && (sqrt(probe_PERR2)/probe_P) < 0.1")
wtrkqual    = TCut("tag_TRACK_PCHI2 > 0.001 && probe_TRACK_PCHI2 > 0.01 && (sqrt(tag_PERR2)/tag_P) < 0.1 && (sqrt(probe_PERR2)/probe_P) < 0.1")
eta        = TCut("tag_ETA > 2 && tag_ETA < 4.5 && probe_ETA > 2 && probe_ETA < 4.5")
vtxcut     = TCut("boson_ENDVERTEX_CHI2/boson_ENDVERTEX_NDOF < 5")
isocut     = TCut("tag_cpt_0.50 < 2000 && probe_cpt_0.50 < 2000")
pt25 = TCut("probe_PT > 25000")
pt30 = TCut("probe_PT > 30000")
passcut = TCut("probe_isMuon == 1")
m1passcut = TCut("probe_hasMuHit_1 == 1")
m2passcut = TCut("probe_hasMuHit_2 == 1")
m3passcut = TCut("probe_hasMuHit_3 == 1")
m4passcut = TCut("probe_hasMuHit_4 == 1")
m5passcut = TCut("probe_hasMuHit_5 == 1")
Ep = TCut("((probe_CaloHcalE + probe_CaloEcalE)/probe_P)<0.04")

after_bugfix = TCut("runNumber > 162240")
mass = TCut("boson_M > 60000 && boson_M < 120000")


selcut = ptcut + phicut + isocut + triggercut + trkqual + vtxcut + eta + mass + after_bugfix

f = TFile("/hepstore/sfarry/GridOutput/2623/MuonID.MD.2015.root")
g = TFile("/hepstore/sfarry/GridOutput/2624/MuonID.MU.2015.root")

t = f.Get("PlusTag/DecayTree")
u = f.Get("MinusTag/DecayTree")
v = f.Get("PlusTagSS/DecayTree")
w = f.Get("MinusTagSS/DecayTree")

x = g.Get("PlusTag/DecayTree")
y = g.Get("MinusTag/DecayTree")
z = g.Get("PlusTagSS/DecayTree")
zz = g.Get("MinusTagSS/DecayTree")

   
magup = TCut("Polarity == 1")
magdown = TCut("Polarity == -1")

mupos = [
    ["musta_2_x", "probe_MuPosX_Extrap_2", 10, -4000, 4000],
    ["musta_2_y", "probe_MuPosY_Extrap_2", 10, -4000, 4000],
    ["musta_3_x", "probe_MuPosX_Extrap_3", 10, -4000, 4000],
    ["musta_3_y", "probe_MuPosY_Extrap_3", 10, -4000, 4000],
    ["musta_4_x", "probe_MuPosX_Extrap_4", 10, -4000, 4000],
    ["musta_4_y", "probe_MuPosY_Extrap_4", 10, -4000, 4000],
    ["musta_5_x", "probe_MuPosX_Extrap_5", 10, -4000, 4000],
    ["musta_5_y", "probe_MuPosY_Extrap_5", 10, -4000, 4000]
    ]

#mupos_plus = copy.deepcopy(mupos)
#for v in mupos_plus: v[1] = v[1].replace('minus', 'plus')

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


def makeMuonID2015(name, selcut, passcut):
    MuonID2015MagUpMuPlus    = EfficiencyClass("Muon"+name+"ID2015MagUpMuPlus")
    MuonID2015MagDownMuPlus  = EfficiencyClass("Muon"+name+"ID2015MagDownMuPlus")
    MuonID2015MagUpMuMinus   = EfficiencyClass("Muon"+name+"ID2015MagUpMuMinus")
    MuonID2015MagDownMuMinus = EfficiencyClass("Muon"+name+"ID2015MagDownMuMinus")
    
    MuonID2015MagUpMuMinus.AddTree(x)
    MuonID2015MagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonID2015MagUpMuMinus.SetPassCut(passcut)
    MuonID2015MagUpMuMinus.AddVars(effvars)
    MuonID2015MagUpMuMinus.AddVars(mupos)
    MuonID2015MagUpMuMinus.Add2DVars(eff2dvars)
    MuonID2015MagUpMuMinus.Add2DVars(mupos2d)
    MuonID2015MagUpMuMinus.Run()
    MuonID2015MagUpMuMinus.AddSystematic("PT",pt_systematic)
    MuonID2015MagUpMuMinus.AddSystematic(0.001)
    MuonID2015MagUpMuMinus.SaveToFile()
    
    MuonID2015MagUpMuPlus.AddTree(y)
    MuonID2015MagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonID2015MagUpMuPlus.SetPassCut(passcut)
    MuonID2015MagUpMuPlus.AddVars(effvars)
    MuonID2015MagUpMuPlus.AddVars(mupos)
    MuonID2015MagUpMuPlus.Add2DVars(eff2dvars)
    MuonID2015MagUpMuPlus.Add2DVars(mupos2d)
    MuonID2015MagUpMuPlus.Run()
    MuonID2015MagUpMuPlus.AddSystematic("PT",pt_systematic)
    MuonID2015MagUpMuPlus.AddSystematic(0.001)
    MuonID2015MagUpMuPlus.SaveToFile()
    
    MuonID2015MagDownMuMinus.AddTree(t)
    MuonID2015MagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonID2015MagDownMuMinus.SetPassCut(passcut)
    MuonID2015MagDownMuMinus.AddVars(effvars)
    MuonID2015MagDownMuMinus.AddVars(mupos)
    MuonID2015MagDownMuMinus.Add2DVars(eff2dvars)
    MuonID2015MagDownMuMinus.Add2DVars(mupos2d)
    MuonID2015MagDownMuMinus.Run()
    MuonID2015MagDownMuMinus.AddSystematic("PT",pt_systematic)
    MuonID2015MagDownMuMinus.AddSystematic(0.001)
    MuonID2015MagDownMuMinus.SaveToFile()
    
    MuonID2015MagDownMuPlus.AddTree(u)
    MuonID2015MagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonID2015MagDownMuPlus.SetPassCut(passcut)
    MuonID2015MagDownMuPlus.AddVars(effvars)
    MuonID2015MagDownMuPlus.AddVars(mupos)
    MuonID2015MagDownMuPlus.Add2DVars(eff2dvars)
    MuonID2015MagDownMuPlus.Add2DVars(mupos2d)
    MuonID2015MagDownMuPlus.Run()
    MuonID2015MagDownMuPlus.AddSystematic("PT",pt_systematic)
    MuonID2015MagDownMuPlus.AddSystematic(0.001)
    MuonID2015MagDownMuPlus.SaveToFile()
    
    MuonID2015MagDown = EfficiencyClass("Muon"+name+"ID2015MagDown", MuonID2015MagDownMuPlus, MuonID2015MagDownMuMinus)
    MuonID2015MagDown.MakeEfficiencyGraph()
    MuonID2015MagDown.AddSystematic("PT",pt_systematic)
    MuonID2015MagDown.AddSystematic(0.001)
    MuonID2015MagDown.SaveToFile()
    
    MuonID2015MagUp = EfficiencyClass("Muon"+name+"ID2015MagUp", MuonID2015MagUpMuPlus, MuonID2015MagUpMuMinus)
    MuonID2015MagUp.MakeEfficiencyGraph()
    MuonID2015MagUp.AddSystematic("PT",pt_systematic)
    MuonID2015MagUp.AddSystematic(0.001)
    MuonID2015MagUp.SaveToFile()
    
    MuonID2015MuPlus = EfficiencyClass("Muon"+name+"ID2015MuPlus", MuonID2015MagDownMuPlus, MuonID2015MagUpMuPlus)
    MuonID2015MuPlus.MakeEfficiencyGraph()
    MuonID2015MuPlus.AddSystematic("PT",pt_systematic)
    MuonID2015MuPlus.AddSystematic(0.001)
    MuonID2015MuPlus.SaveToFile()

    MuonID2015MuMinus = EfficiencyClass("Muon"+name+"ID2015MuMinus", MuonID2015MagDownMuMinus, MuonID2015MagUpMuMinus)
    MuonID2015MuMinus.MakeEfficiencyGraph()
    MuonID2015MuMinus.PrintEfficiencies("ETA")
    MuonID2015MuMinus.AddSystematic("PT",pt_systematic)
    MuonID2015MuMinus.AddSystematic(0.001)
    MuonID2015MuMinus.SaveToFile()
    
    MuonID2015 = EfficiencyClass("Muon"+name+"ID2015", MuonID2015MagDown, MuonID2015MagUp)
    MuonID2015.MakeEfficiencyGraph()
    MuonID2015.AddSystematic("PT",pt_systematic)
    MuonID2015.AddSystematic(0.001)
    MuonID2015.SaveToFile()

    MuonID2015_staterr = EfficiencyClass("Muon"+name+"ID2015_staterr", MuonID2015MagDown, MuonID2015MagUp)
    MuonID2015_staterr.MakeEfficiencyGraph()
    MuonID2015_staterr.SaveToFile()

    MuonID2015_systerr = EfficiencyClass("Muon"+name+"ID2015_systerr", MuonID2015MagDown, MuonID2015MagUp)
    MuonID2015_systerr.MakeEfficiencyGraph()
    MuonID2015_systerr.RemoveErrors()
    MuonID2015_systerr.AddSystematic("PT",pt_systematic)
    MuonID2015_systerr.AddSystematic(0.001)
    MuonID2015_systerr.SaveToFile()


makeMuonID2015("",selcut,passcut)
makeMuonID2015("M1",selcut,m1passcut)
makeMuonID2015("M2",selcut,m2passcut)
makeMuonID2015("M3",selcut,m3passcut)
makeMuonID2015("M4",selcut,m4passcut)
makeMuonID2015("M5",selcut,m5passcut)
#makeMuonID2015("W",selcut + wtrkqual,passcut)
#makeMuonID2015("Ep",selcut,passcut + Ep)
#makeMuonID2015("PT25",selcut + pt25, passcut)
#makeMuonID2015("PT30",selcut + pt30, passcut)
