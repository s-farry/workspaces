
import copy
from ROOT import *
import Jawa

from PlotTools import *
from Style import SetLHCbStyle

SetLHCbStyle()

f = TFile("../tuples/ZMuMu.2015.root")
t = f.Get("ZMuMu/DecayTree")

z2012f = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/ZMuMu.2012.root")
z2012t = z2012f.Get("ZMuMu/DecayTree")

mass = TCut("Z0_M > 60000 && Z0_M < 120000")
eta  = TCut("min(muplus_ETA, muminus_ETA) > 2.0 && max(muplus_ETA, muminus_ETA) < 4.5")
pt   = TCut("min(muplus_PT, muminus_PT) > 20000")

selcut = mass + eta + pt
selcut2012 = TCut((mass + eta + pt).GetTitle().replace('Z0','boson'))

trigger_plus   = TCut("muplus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonEWDecision_TOS ==1")
trigger_minus = TCut("muminus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonEWDecision_TOS ==1")

trigger_dimuon = TCut("("+trigger_plus.GetTitle() + ") || (" + trigger_minus.GetTitle() + ")")

trigger2012_plus   = TCut("muplus_Hlt2SingleMuonHighPTDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonDecision_TOS ==1")
trigger2012_minus = TCut("muminus_Hlt2SingleMuonHighPTDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonDecision_TOS ==1")

trigger2012_dimuon = TCut("("+trigger2012_plus.GetTitle() + ") || (" + trigger2012_minus.GetTitle() + ")")

plus_vars = [
    ["ETA", "muplus_ETA"    , 100 , 2 , 4.5 ],
    ["PT", "muplus_PT/1000" , 100 , 20 , 70],
    ["PHI", "muplus_PHI"    , 100 , -TMath.Pi() , TMath.Pi()],
    ["SPDHits", "nSPDHits"  , 100 , 0 , 1000],
    ["GhostProb", "muplus_TRACK_GhostProb", 100 , 0 , 0.5],
    ["trackchi2", "muplus_TRACK_CHI2NDOF", 100 , 0 , 5]
    ]

minus_vars = copy.deepcopy(plus_vars)
for v in minus_vars: v[1] = v[1].replace('plus','minus')

z_plus = Jawa.Template("z_plus")
z_plus.SetSelCut(selcut + trigger_dimuon)
z_plus.AddTree(t)
z_plus.AddVars(plus_vars)
z_plus.Run()
z_plus.SaveToFile()

z_minus = Jawa.Template("z_minus")
z_minus.SetSelCut(selcut + trigger_dimuon)
z_minus.AddTree(t)
z_minus.AddVars(minus_vars)
z_minus.Run()
z_minus.SaveToFile()

z = Jawa.Template("z", z_plus, z_minus)
z.SaveToFile()


z2012_plus = Jawa.Template("z2012_plus")
z2012_plus.SetSelCut(selcut2012 + trigger2012_dimuon)
z2012_plus.AddTree(z2012t)
z2012_plus.AddVars(plus_vars)
z2012_plus.Run()
z2012_plus.SaveToFile()

z2012_minus = Jawa.Template("z2012_minus")
z2012_minus.SetSelCut(selcut2012 + trigger2012_dimuon)
z2012_minus.AddTree(z2012t)
z2012_minus.AddVars(minus_vars)
z2012_minus.Run()
z2012_minus.SaveToFile()

z2012 = Jawa.Template("z2012", z2012_plus, z2012_minus)
z2012.SaveToFile()

properties = {
    'includeNormErr' : False,
    'labels'          :      ['2015 Data'],
    'xlabel':     'p_{T} [GeV]'    ,
    'ylabel':     'Trigger Efficiency',
    'location' : "/user2/sfarry/validation/figures/zmumu2015",
    'logscale' : False,
    'colors'   : ['black', 'red', 'blue', 'green'],
    'leglims'  : [0.15, 0.2, 0.65, 0.40],
    'drawOpts' : ['p','p']
}

vars2015 = {
    "SPDHits" : "SPD Hits",
    "GhostProb" : "Ghost Probability"
    }
vars2012 = {
    "trackchi2" : "#chi^{2}/ndof",
    }


for v in vars2015.keys():
    b = Plot([z.GetVar(v).GetHist()])
    b.plots[0].SetMarkerStyle(20)
    b.setProps(properties)
    b.properties['filename']=v+'_plot'
    b.properties['xlabel'] = vars2015[v]
    b.properties['ylabel'] = 'Events'
    b.properties['normalised'] = False
    if v == 'GhostProb' : b.properties['logscale'] = True
    b.ShiftLegX(0.4)
    b.ShiftLegY(0.5)
    b.drawROOT()


for v in vars2012.keys():
    print v
    b = Plot([z2012.GetVar(v).GetHist(), z.GetVar(v).GetHist()])
    b.plots[0].SetMarkerStyle(20)
    b.setProps(properties)
    b.properties['filename']=v+'_plot'
    b.properties['xlabel'] = vars2012[v]
    b.properties['ylabel'] = 'Events'
    b.properties['colors'] = ['red', 'black']
    b.properties['labels'] = ['2012 Data', '2015 Data']
    b.properties['drawOpts'] = ['hist', 'ep']
    b.properties['markerstyles'] = [1, 20]
    b.properties['normalised'] = True
    if v == 'GhostProb' : b.setProp('logscale', True)
    b.ShiftLegX(0.4)
    b.ShiftLegY(0.5)
    b.drawROOT()
