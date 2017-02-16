
from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath, TH1
TH1.AddDirectory(False)
import copy

phicut= TCut("(abs(tag_PHI-probe_PHI)<TMath::Pi() ? abs(tag_PHI-probe_PHI) : 2*TMath::Pi()-abs(tag_PHI-probe_PHI))>2.7")
ptcut = TCut("tag_PT > 20000 && probe_PT > 20000")

triggercut  = TCut("tag_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && tag_Hlt1SingleMuonHighPTDecision_TOS == 1 && tag_L0MuonEWDecision_TOS ==1")
trkqual    = TCut("(sqrt(tag_PERR2)/tag_P) < 0.1 && (sqrt(probe_PERR2)/probe_P) < 0.1")
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

mass = TCut("boson_M > 60000 && boson_M < 120000")

selcut = ptcut + phicut + isocut + triggercut + trkqual + vtxcut + eta + mass

f = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonID.MD.2016.root')
g = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonID.MU.2016.root')

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


def makeMuonID2016(name, selcut, passcut):
    MuonID2016MagUpMuPlus    = EfficiencyClass("Muon"+name+"ID2016MagUpMuPlus")
    MuonID2016MagDownMuPlus  = EfficiencyClass("Muon"+name+"ID2016MagDownMuPlus")
    MuonID2016MagUpMuMinus   = EfficiencyClass("Muon"+name+"ID2016MagUpMuMinus")
    MuonID2016MagDownMuMinus = EfficiencyClass("Muon"+name+"ID2016MagDownMuMinus")
    
    MuonID2016MagUpMuMinus.AddTree(x)
    MuonID2016MagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonID2016MagUpMuMinus.SetPassCut(passcut)
    MuonID2016MagUpMuMinus.AddVars(effvars)
    MuonID2016MagUpMuMinus.AddVars(mupos)
    MuonID2016MagUpMuMinus.Add2DVars(eff2dvars)
    MuonID2016MagUpMuMinus.Add2DVars(mupos2d)
    MuonID2016MagUpMuMinus.Run()
    MuonID2016MagUpMuMinus.AddSystematic("PT",pt_systematic)
    MuonID2016MagUpMuMinus.AddSystematic(0.001)
    MuonID2016MagUpMuMinus.SaveToFile()
    
    MuonID2016MagUpMuPlus.AddTree(y)
    MuonID2016MagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonID2016MagUpMuPlus.SetPassCut(passcut)
    MuonID2016MagUpMuPlus.AddVars(effvars)
    MuonID2016MagUpMuPlus.AddVars(mupos)
    MuonID2016MagUpMuPlus.Add2DVars(eff2dvars)
    MuonID2016MagUpMuPlus.Add2DVars(mupos2d)
    MuonID2016MagUpMuPlus.Run()
    MuonID2016MagUpMuPlus.AddSystematic("PT",pt_systematic)
    MuonID2016MagUpMuPlus.AddSystematic(0.001)
    MuonID2016MagUpMuPlus.SaveToFile()
    
    MuonID2016MagDownMuMinus.AddTree(t)
    MuonID2016MagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonID2016MagDownMuMinus.SetPassCut(passcut)
    MuonID2016MagDownMuMinus.AddVars(effvars)
    MuonID2016MagDownMuMinus.AddVars(mupos)
    MuonID2016MagDownMuMinus.Add2DVars(eff2dvars)
    MuonID2016MagDownMuMinus.Add2DVars(mupos2d)
    MuonID2016MagDownMuMinus.Run()
    MuonID2016MagDownMuMinus.AddSystematic("PT",pt_systematic)
    MuonID2016MagDownMuMinus.AddSystematic(0.001)
    MuonID2016MagDownMuMinus.SaveToFile()
    
    MuonID2016MagDownMuPlus.AddTree(u)
    MuonID2016MagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonID2016MagDownMuPlus.SetPassCut(passcut)
    MuonID2016MagDownMuPlus.AddVars(effvars)
    MuonID2016MagDownMuPlus.AddVars(mupos)
    MuonID2016MagDownMuPlus.Add2DVars(eff2dvars)
    MuonID2016MagDownMuPlus.Add2DVars(mupos2d)
    MuonID2016MagDownMuPlus.Run()
    MuonID2016MagDownMuPlus.AddSystematic("PT",pt_systematic)
    MuonID2016MagDownMuPlus.AddSystematic(0.001)
    MuonID2016MagDownMuPlus.SaveToFile()
    
    MuonID2016MagDown = EfficiencyClass("Muon"+name+"ID2016MagDown", MuonID2016MagDownMuPlus, MuonID2016MagDownMuMinus)
    MuonID2016MagDown.MakeEfficiencyGraph()
    MuonID2016MagDown.AddSystematic("PT",pt_systematic)
    MuonID2016MagDown.AddSystematic(0.001)
    MuonID2016MagDown.SaveToFile()
    
    MuonID2016MagUp = EfficiencyClass("Muon"+name+"ID2016MagUp", MuonID2016MagUpMuPlus, MuonID2016MagUpMuMinus)
    MuonID2016MagUp.MakeEfficiencyGraph()
    MuonID2016MagUp.AddSystematic("PT",pt_systematic)
    MuonID2016MagUp.AddSystematic(0.001)
    MuonID2016MagUp.SaveToFile()
    
    MuonID2016MuPlus = EfficiencyClass("Muon"+name+"ID2016MuPlus", MuonID2016MagDownMuPlus, MuonID2016MagUpMuPlus)
    MuonID2016MuPlus.MakeEfficiencyGraph()
    MuonID2016MuPlus.AddSystematic("PT",pt_systematic)
    MuonID2016MuPlus.AddSystematic(0.001)
    MuonID2016MuPlus.SaveToFile()

    MuonID2016MuMinus = EfficiencyClass("Muon"+name+"ID2016MuMinus", MuonID2016MagDownMuMinus, MuonID2016MagUpMuMinus)
    MuonID2016MuMinus.MakeEfficiencyGraph()
    MuonID2016MuMinus.PrintEfficiencies("ETA")
    MuonID2016MuMinus.AddSystematic("PT",pt_systematic)
    MuonID2016MuMinus.AddSystematic(0.001)
    MuonID2016MuMinus.SaveToFile()
    
    MuonID2016 = EfficiencyClass("Muon"+name+"ID2016", MuonID2016MagDown, MuonID2016MagUp)
    MuonID2016.MakeEfficiencyGraph()
    MuonID2016.AddSystematic("PT",pt_systematic)
    MuonID2016.AddSystematic(0.001)
    MuonID2016.SaveToFile()

    MuonID2016_staterr = EfficiencyClass("Muon"+name+"ID2016_staterr", MuonID2016MagDown, MuonID2016MagUp)
    MuonID2016_staterr.MakeEfficiencyGraph()
    MuonID2016_staterr.SaveToFile()

    MuonID2016_systerr = EfficiencyClass("Muon"+name+"ID2016_systerr", MuonID2016MagDown, MuonID2016MagUp)
    MuonID2016_systerr.MakeEfficiencyGraph()
    MuonID2016_systerr.RemoveErrors()
    MuonID2016_systerr.AddSystematic("PT",pt_systematic)
    MuonID2016_systerr.AddSystematic(0.001)
    MuonID2016_systerr.SaveToFile()


makeMuonID2016("",selcut,passcut)
#makeMuonID2016("M1",selcut,m1passcut)
#makeMuonID2016("M2",selcut,m2passcut)
#makeMuonID2016("M3",selcut,m3passcut)
#makeMuonID2016("M4",selcut,m4passcut)
#makeMuonID2016("M5",selcut,m5passcut)
#makeMuonID2016("W",selcut + wtrkqual,passcut)
#makeMuonID2016("Ep",selcut,passcut + Ep)
#makeMuonID2016("PT25",selcut + pt25, passcut)
#makeMuonID2016("PT30",selcut + pt30, passcut)
