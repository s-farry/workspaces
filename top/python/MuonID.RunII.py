
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
h = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonID.MD.2015.root')
i = TFile.Open('root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/MuonID.MU.2015.root')

t = f.Get("PlusTag/DecayTree")
u = f.Get("MinusTag/DecayTree")
v = f.Get("PlusTagSS/DecayTree")
w = f.Get("MinusTagSS/DecayTree")

x = g.Get("PlusTag/DecayTree")
y = g.Get("MinusTag/DecayTree")
z = g.Get("PlusTagSS/DecayTree")
zz = g.Get("MinusTagSS/DecayTree")

tt = h.Get("PlusTag/DecayTree")
uu = h.Get("MinusTag/DecayTree")
vv = h.Get("PlusTagSS/DecayTree")
ww = h.Get("MinusTagSS/DecayTree")

xx = i.Get("PlusTag/DecayTree")
yy = i.Get("MinusTag/DecayTree")
zz = i.Get("PlusTagSS/DecayTree")
zzz = i.Get("MinusTagSS/DecayTree")

   
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

pt_systematic = [0.001 for ijk in range(10)]
pt_systematic[0] = 0.01;
pt_systematic[1] = 0.003;


def makeMuonIDRunII(name, selcut, passcut):
    MuonIDRunIIMagUpMuPlus    = EfficiencyClass("Muon"+name+"IDRunIIMagUpMuPlus")
    MuonIDRunIIMagDownMuPlus  = EfficiencyClass("Muon"+name+"IDRunIIMagDownMuPlus")
    MuonIDRunIIMagUpMuMinus   = EfficiencyClass("Muon"+name+"IDRunIIMagUpMuMinus")
    MuonIDRunIIMagDownMuMinus = EfficiencyClass("Muon"+name+"IDRunIIMagDownMuMinus")
    print x, xx

    MuonIDRunIIMagUpMuMinus.AddTree(x)
    MuonIDRunIIMagUpMuMinus.AddTree(xx)
    MuonIDRunIIMagUpMuMinus.SetSelectionCut(selcut + magup)
    MuonIDRunIIMagUpMuMinus.SetPassCut(passcut)
    MuonIDRunIIMagUpMuMinus.AddVars(effvars)
    MuonIDRunIIMagUpMuMinus.AddVars(mupos)
    MuonIDRunIIMagUpMuMinus.Add2DVars(eff2dvars)
    MuonIDRunIIMagUpMuMinus.Add2DVars(mupos2d)
    MuonIDRunIIMagUpMuMinus.Run()
    MuonIDRunIIMagUpMuMinus.AddSystematic("PT",pt_systematic)
    MuonIDRunIIMagUpMuMinus.AddSystematic(0.001)
    MuonIDRunIIMagUpMuMinus.SaveToFile()
    
    MuonIDRunIIMagUpMuPlus.AddTree(y)
    MuonIDRunIIMagUpMuPlus.AddTree(yy)
    MuonIDRunIIMagUpMuPlus.SetSelectionCut(selcut + magup)
    MuonIDRunIIMagUpMuPlus.SetPassCut(passcut)
    MuonIDRunIIMagUpMuPlus.AddVars(effvars)
    MuonIDRunIIMagUpMuPlus.AddVars(mupos)
    MuonIDRunIIMagUpMuPlus.Add2DVars(eff2dvars)
    MuonIDRunIIMagUpMuPlus.Add2DVars(mupos2d)
    MuonIDRunIIMagUpMuPlus.Run()
    MuonIDRunIIMagUpMuPlus.AddSystematic("PT",pt_systematic)
    MuonIDRunIIMagUpMuPlus.AddSystematic(0.001)
    MuonIDRunIIMagUpMuPlus.SaveToFile()
    
    MuonIDRunIIMagDownMuMinus.AddTree(t)
    #MuonIDRunIIMagDownMuMinus.AddTree(tt)
    MuonIDRunIIMagDownMuMinus.SetSelectionCut(selcut + magdown)
    MuonIDRunIIMagDownMuMinus.SetPassCut(passcut)
    MuonIDRunIIMagDownMuMinus.AddVars(effvars)
    MuonIDRunIIMagDownMuMinus.AddVars(mupos)
    MuonIDRunIIMagDownMuMinus.Add2DVars(eff2dvars)
    MuonIDRunIIMagDownMuMinus.Add2DVars(mupos2d)
    MuonIDRunIIMagDownMuMinus.Run()
    MuonIDRunIIMagDownMuMinus.AddSystematic("PT",pt_systematic)
    MuonIDRunIIMagDownMuMinus.AddSystematic(0.001)
    MuonIDRunIIMagDownMuMinus.SaveToFile()
    
    MuonIDRunIIMagDownMuPlus.AddTree(u)
    ##MuonIDRunIIMagDownMuPlus.AddTree(uu)
    MuonIDRunIIMagDownMuPlus.SetSelectionCut(selcut + magdown)
    MuonIDRunIIMagDownMuPlus.SetPassCut(passcut)
    MuonIDRunIIMagDownMuPlus.AddVars(effvars)
    MuonIDRunIIMagDownMuPlus.AddVars(mupos)
    MuonIDRunIIMagDownMuPlus.Add2DVars(eff2dvars)
    MuonIDRunIIMagDownMuPlus.Add2DVars(mupos2d)
    MuonIDRunIIMagDownMuPlus.Run()
    MuonIDRunIIMagDownMuPlus.AddSystematic("PT",pt_systematic)
    MuonIDRunIIMagDownMuPlus.AddSystematic(0.001)
    MuonIDRunIIMagDownMuPlus.SaveToFile()
    
    MuonIDRunIIMagDown = EfficiencyClass("Muon"+name+"IDRunIIMagDown", MuonIDRunIIMagDownMuPlus, MuonIDRunIIMagDownMuMinus)
    MuonIDRunIIMagDown.MakeEfficiencyGraph()
    MuonIDRunIIMagDown.AddSystematic("PT",pt_systematic)
    MuonIDRunIIMagDown.AddSystematic(0.001)
    MuonIDRunIIMagDown.SaveToFile()
    
    MuonIDRunIIMagUp = EfficiencyClass("Muon"+name+"IDRunIIMagUp", MuonIDRunIIMagUpMuPlus, MuonIDRunIIMagUpMuMinus)
    MuonIDRunIIMagUp.MakeEfficiencyGraph()
    MuonIDRunIIMagUp.AddSystematic("PT",pt_systematic)
    MuonIDRunIIMagUp.AddSystematic(0.001)
    MuonIDRunIIMagUp.SaveToFile()
    
    MuonIDRunIIMuPlus = EfficiencyClass("Muon"+name+"IDRunIIMuPlus", MuonIDRunIIMagDownMuPlus, MuonIDRunIIMagUpMuPlus)
    MuonIDRunIIMuPlus.MakeEfficiencyGraph()
    MuonIDRunIIMuPlus.AddSystematic("PT",pt_systematic)
    MuonIDRunIIMuPlus.AddSystematic(0.001)
    MuonIDRunIIMuPlus.SaveToFile()

    MuonIDRunIIMuMinus = EfficiencyClass("Muon"+name+"IDRunIIMuMinus", MuonIDRunIIMagDownMuMinus, MuonIDRunIIMagUpMuMinus)
    MuonIDRunIIMuMinus.MakeEfficiencyGraph()
    MuonIDRunIIMuMinus.PrintEfficiencies("ETA")
    MuonIDRunIIMuMinus.AddSystematic("PT",pt_systematic)
    MuonIDRunIIMuMinus.AddSystematic(0.001)
    MuonIDRunIIMuMinus.SaveToFile()
    
    MuonIDRunII = EfficiencyClass("Muon"+name+"IDRunII", MuonIDRunIIMagDown, MuonIDRunIIMagUp)
    MuonIDRunII.MakeEfficiencyGraph()
    MuonIDRunII.AddSystematic("PT",pt_systematic)
    MuonIDRunII.AddSystematic(0.001)
    MuonIDRunII.SaveToFile()

    MuonIDRunII_staterr = EfficiencyClass("Muon"+name+"IDRunII_staterr", MuonIDRunIIMagDown, MuonIDRunIIMagUp)
    MuonIDRunII_staterr.MakeEfficiencyGraph()
    MuonIDRunII_staterr.SaveToFile()

    MuonIDRunII_systerr = EfficiencyClass("Muon"+name+"IDRunII_systerr", MuonIDRunIIMagDown, MuonIDRunIIMagUp)
    MuonIDRunII_systerr.MakeEfficiencyGraph()
    MuonIDRunII_systerr.RemoveErrors()
    MuonIDRunII_systerr.AddSystematic("PT",pt_systematic)
    MuonIDRunII_systerr.AddSystematic(0.001)
    MuonIDRunII_systerr.SaveToFile()

makeMuonIDRunII("",selcut,passcut)
#makeMuonIDRunII("M1",selcut,m1passcut)
#makeMuonIDRunII("M2",selcut,m2passcut)
#makeMuonIDRunII("M3",selcut,m3passcut)
#makeMuonIDRunII("M4",selcut,m4passcut)
#makeMuonIDRunII("M5",selcut,m5passcut)
#makeMuonIDRunII("W",selcut + wtrkqual,passcut)
#makeMuonIDRunII("Ep",selcut,passcut + Ep)
#makeMuonIDRunII("PT25",selcut + pt25, passcut)
#makeMuonIDRunII("PT30",selcut + pt30, passcut)
