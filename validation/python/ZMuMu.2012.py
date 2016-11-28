
import copy
from Jawa import *
from ROOT import *
import Jawa

from PlotTools import *
from Style import SetLHCbStyle

SetLHCbStyle()

f = TFile("../tuples/ZMuMu.2012.root")
t = f.Get("ZMuMu/DecayTree")

mass = TCut("Z0_M > 60000 && Z0_M < 120000")
eta  = TCut("min(muplus_ETA, muminus_ETA) > 2.0 && max(muplus_ETA, muminus_ETA) < 4.5")
pt   = TCut("min(muplus_PT, muminus_PT) > 20000")

selcut = mass + eta + pt

trigger_plus   = TCut("muplus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonEWDecision_TOS ==1")
trigger_minus = TCut("muminus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonEWDecision_TOS ==1")

trigger_dimuon = TCut("("+trigger_plus.GetTitle() + ") || (" + trigger_minus.GetTitle() + ")")

plus_vars = [
    ["ETA", "muplus_ETA"    , 100 , 2 , 4.5 ],
    ["PT", "muplus_PT/1000" , 100 , 20 , 70],
    ["PHI", "muplus_PHI"    , 100 , -TMath.Pi() , TMath.Pi()],
    ["SPDHits", "nSPDHits"  , 100 , 0 , 1000],
    ["GhostProb", "muplus_TRACK_GhostProb", 100 , 0 , 0.5],
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

properties = {
    'includeNormErr' : False,
    'labels'          :      ['2012 Data'],
    'xlabel':     'p_{T} [GeV]'    ,
    'ylabel':     'Trigger Efficiency',
    'location' : "/user2/sfarry/validation/figures/zmumu2015",
    'logscale' : False,
    'colors'   : ['black', 'red', 'blue', 'green'],
    'leglims'  : [0.15, 0.2, 0.65, 0.40],
    'drawOpts' : ['p','p']
}


for v in plus_vars:
    b = Plot([z.GetVar(v[0]).GetHist()])
    b.plots[0].SetMarkerStyle(20)
    b.setProps(properties)
    b.properties['filename']=v[0]+'_plot'
    b.properties['xlabel'] = v[0]
    b.properties['ylabel'] = 'Events'
    b.properties['normalised'] = False
    if v[0] == 'GhostProb' : b.properties['logscale'] = True
    b.ShiftLegX(0.4)
    b.ShiftLegY(0.5)
    b.drawROOT()
