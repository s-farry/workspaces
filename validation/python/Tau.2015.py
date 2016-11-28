
import copy
from Jawa import *
from ROOT import *
import Jawa

from PlotTools import *
from Style import SetLHCbStyle

SetLHCbStyle()

f = TFile("../tuples/SingleTau.2015validation_charm.root")
f = TFile("../tuples/SingleTau.2015_charm.root")
t = f.Get("tau2prong/DecayTree")
u = f.Get("tau3prong/DecayTree")

trigger_2prong   = TCut("tauminus_Hlt2EWSingleTauHighPt2ProngDecision_TOS")
trigger_3prong   = TCut("tauminus_Hlt2EWSingleTauHighPt3ProngDecision_TOS")

vars_tau = [
    ["PT", "tauminus_PT/1000", 20, 0, 40],
    ["ETA", "tauminus_ETA", 20, 2, 4.5],
    ["M"  , "tauminus_M/1000.0", 20, 1, 4],
    ["iso"  , "tauminus_cpt_0.50/1000.0", 50, 0, 20]
]
vars_2prong = [
    ["PTpi", "piminus_PT/1000", 20 , 0 , 10 ],
    ["PTpi0", "pi0_PT/1000", 5 , 0 , 10],
    ["IPCHI2pi", "log10(piminus_MINIPCHI2)", 9 , -3 , 5]
    ]
vars_3prong = [
    ["PTmin"  , "min(piminus_PT, min(piminus0_PT, piplus_PT))/1000", 30 , 0 , 30],
    ["PTmax"  , "max(piminus_PT, max(piminus0_PT, piplus_PT))/1000", 30 , 0 , 30],
    ["FDCHI2" , "tauminus_FDCHI2"     , 20, 0, 10],
    ["VtxChi2",  "tauminus_VCHI2NDOF" , 20, 0, 10],
    ["FDT"    , "tauminus_FDT"        , 20, 0.5, 5.5],
    ["MCorr" , "tauminus_MCORR/1000", 20, 1.2, 2]
    ]

tau2 = Jawa.Template("tau2")
tau2.SetSelCut(trigger_2prong)
tau2.AddTree(t)
tau2.AddVars(vars_tau + vars_2prong)
tau2.Run()
tau2.SaveToFile()


tau3 = Jawa.Template("tau3")
tau3.SetSelCut(trigger_3prong)
tau3.AddTree(u)
tau3.AddVars(vars_tau + vars_3prong)
tau3.Run()
tau3.SaveToFile()


properties = {
    'includeNormErr' : False,
    'labels'          :      ['2015 Data', '2012 Data'],
    'xlabel':     'p_{T} [GeV]'    ,
    'ylabel':     'Trigger Efficiency',
    'location' : "/user2/sfarry/validation/figures/tau",
    'logscale' : False,
    'fillstyles'   : 0,
    #'colors'       : None,
    'linecolors'   : ['black', 'red'],
    'leglims'  : [0.65, 0.6, 0.95, 0.8],
    'drawOpts' : ['hist','p1']
}


for v in vars_tau:
    a = Plot([tau2.GetVar(v[0]).GetHist(), tau3.GetVar(v[0]).GetHist()])
    a.setProps(properties)
    a.properties['xlabel'] = v[0]
    a.properties['ylabel'] = '[A.U.]'
    a.properties['normalised'] = True
    a.properties['filename'] = 'tau_'+v[0]
    a.properties['labels'] = ['#tau->#pi#pi^{0}','#tau->3#pi']
    a.drawROOT()

for v in vars_2prong:
    a = Plot([tau2.GetVar(v[0]).GetHist()])
    a.setProps(properties)
    a.properties['xlabel'] = v[0]
    a.properties['ylabel'] = '[A.U.]'
    a.properties['normalised'] = True
    a.properties['filename'] = 'tau_'+v[0]
    a.properties['labels'] = ['#tau->#pi#pi^{0}']
    a.drawROOT()

for v in vars_3prong:
    a = Plot([tau3.GetVar(v[0]).GetHist()])
    a.setProps(properties)
    a.properties['xlabel'] = v[0]
    a.properties['ylabel'] = '[A.U.]'
    a.properties['normalised'] = True
    a.properties['filename'] = 'tau_'+v[0]
    a.properties['labels'] = ['#tau->3#pi']
    a.drawROOT()
