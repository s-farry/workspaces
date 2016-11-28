
import copy
from Jawa import *
from ROOT import *
import Jawa

from PlotTools import *
from Style import SetLHCbStyle

SetLHCbStyle()

f = TFile("../tuples/ZMuMu.2015.root")
t = f.Get("ZMuMu/DecayTree")

mass = TCut("Z0_M > 60000 && Z0_M < 120000")
eta  = TCut("min(muplus_ETA, muminus_ETA) > 2.0 && max(muplus_ETA, muminus_ETA) < 4.5")
pt   = TCut("min(muplus_PT, muminus_PT) > 20000")

selcut = mass + eta + pt

trigger_plus   = TCut("muplus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonEWDecision_TOS ==1")
trigger_minus = TCut("muminus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonEWDecision_TOS ==1")

trigger_dimuon = TCut("("+trigger_plus.GetTitle() + ") || (" + trigger_minus.GetTitle() + ")")

plus_vars = [
    ["ETA", "muplus_ETA", 5 , 2 , 4.5 ],
    ["PT", "muplus_PT/1000", 5 , 20 , 70],
    ["PHI", "muplus_PHI", 6 , -TMath.Pi() , TMath.Pi()],
    ["SPDHits", "nSPDHits", 20 , 0 , 1000, "I"],
    ["GhostProb", "muplus_TRACK_GhostProb", 20 , 0 , 0.5],
    ]

minus_vars = copy.deepcopy(plus_vars)
for v in minus_vars: v[1] = v[1].replace('plus','minus')

p = EfficiencyClass("plus")
p.AddTree(t)
p.SetSelectionCut(selcut + trigger_minus)
p.SetPassCut(trigger_plus)
p.AddVars(plus_vars)
p.SetPltRange("Z0_M" , 50 , 60000 , 120000)
p.MakeEntryLists()
p.MakeHists()
p.MakeEfficiencyGraph()


m = EfficiencyClass("minus")
m.AddTree(t)
m.SetSelectionCut(selcut + trigger_plus)
m.SetPassCut(trigger_minus)
m.AddVars(minus_vars)
m.SetPltRange("Z0_M" , 50 , 60000 , 120000)
m.MakeEntryLists()
m.MakeHists()
m.MakeEfficiencyGraph()

tot = EfficiencyClass("zmumu_2015validation_triggereff", p, m)
tot.MakeEfficiencyGraph()
tot.SaveToFile()


z = Jawa.Template("z")
z.Verbose = True
z.SetSelCut(selcut + trigger_dimuon)
z.AddTree(t)
z.AddVar(["SPDHits", "nSPDHits", 31, 0, 620])
z.Run()
z.SaveToFile()

properties = {
    'includeNormErr' : False,
    'labels'          :      ['2015 Validation Data', '2012 Data'],
    'xlabel':     'p_{T} [GeV]'    ,
    'ylabel':     'Trigger Efficiency',
    'location' : ".",
    'logscale' : False,
    'colors'   : ['black', 'red', 'blue', 'green'],
    'leglims'  : [0.15, 0.2, 0.65, 0.40],
    'drawOpts' : ['p','p']
}


g = TFile("/user2/sfarry/Efficiencies/python/MuonTrigger2012.root")

a = Plot([tot.GetVar("PT").GetEffGraph(), g.Get("PT/EfficiencyGraph")])
a.plots[0].SetMarkerStyle(20)
a.plots[1].SetMarkerStyle(20)
a.setProps(properties)
a.properties['filename'] = 'pt'
a.drawROOT()

a.plots[0] = tot.GetVar("ETA").GetEffGraph()
a.plots[0].SetMarkerStyle(20)
a.plots[1] = g.Get("ETA/EfficiencyGraph")
a.plots[1].SetMarkerStyle(20)
a.properties['filename'] = 'eta'
a.properties['xlabel'] = '#eta'
a.drawROOT()


b = Plot([z.GetVar("SPDHits").GetHist()])
b.plots[0].SetMarkerStyle(20)
b.setProps(properties)
b.properties['filename']='spdhits'
b.properties['xlabel'] = 'SPD Hits'
b.properties['ylabel'] = '[A.U.]'
b.properties['normalised'] = True
b.ShiftLegX(0.4)
b.ShiftLegY(0.5)
b.drawROOT()
