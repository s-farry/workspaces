from os import sys
from Utils import *
from Jawa import Template
from ROOT import TCut, TTree, TFile, TMath, Double, TH1F, TMath
from array import *
from Style import *
SetLHCbStyle()

def GetTH1F(graph, name, minus = False):
    x = Double(0.0)
    y = Double(0.0)
    graph.GetPoint(0,x,y)
    minx = x - graph.GetErrorXlow(0)
    graph.GetPoint(graph.GetN() - 1, x, y)
    maxx = x + graph.GetErrorXhigh(graph.GetN() - 1)
    bins = graph.GetN()
    h = TH1F(name,name, bins, minx, maxx)
    for i in range(bins):
        x1 = Double(0.0)
        y1 = Double(0.0)
        graph.GetPoint(i,x1,y1)
        if (minus):
            h.SetBinContent(i+1, 1 - y1)
        else:
            h.SetBinContent(i+1, y1)
        h.SetBinError(i+1, max(graph.GetErrorYhigh(i),graph.GetErrorYlow(i)))
    return h

def GetBins(graph):
    x = Double(0.0)
    y = Double(0.0)
    graph.GetPoint(0,x,y)
    minx = x - graph.GetErrorXlow(0)
    graph.GetPoint(graph.GetN() - 1, x, y)
    maxx = x + graph.GetErrorXhigh(graph.GetN() - 1)
    nbins = graph.GetN()
    bins = [minx]
    for i in range(1, nbins):
        x2 = Double(0.0)
        y2 = Double(0.0)
        graph.GetPoint(i,x2,y2)
        lowx = x2 - graph.GetErrorXlow(i)
        bins = bins + [lowx]
    bins = bins + [maxx]
    binarray = array('d',bins)
    return binarray
    

def GetEffCorr(graph, name):
    if ('TGraph' in graph.ClassName()):
        bins = GetBins(graph)
        h = TH1F(name,name, len(bins) - 1, bins)
        for i in range(len(bins)-1):
            x1 = Double(0.0)
            y1 = Double(0.0)
            graph.GetPoint(i,x1,y1)
            h.SetBinContent(i+1, 1/y1)
            h.SetBinError(i+1, max(graph.GetErrorYhigh(i),graph.GetErrorYlow(i))/(pow(y1,2)))
        return h
    elif ('TH1' in graph.ClassName() or 'TH2' in graph.ClassName()):
        hist = graph.Clone(name)
        for i in range(hist.GetXaxis().GetNbins()):
            for j in range(hist.GetYaxis().GetNbins()):
                eff = hist.GetBinContent(i+1, j+1)
                if (eff > 0 and TMath.IsNaN(eff) == 0): hist.SetBinContent(i+1, j+1, 1/eff)
                else: hist.SetBinContent(i+1,j+1,1)
        return hist

trkf    = TFile("../tuples/MuonWTracking2015.root")
idf     = TFile("../tuples/MuonID2015.root")
trgf    = TFile("../tuples/MuonTrigger2015.root")

trketaeff   = trkf.Get("ETA/EfficiencyGraph")
idetaeff    = idf.Get("ETA/EfficiencyGraph")
trgetaeff   = trgf.Get("ETA/EfficiencyGraph")

trketa11eff   = trkf.Get("ETA11/EfficiencyGraph")
ideta11eff    = idf.Get("ETA11/EfficiencyGraph")
trgeta11eff   = trgf.Get("ETA11/EfficiencyGraph")

trketa12eff   = trkf.Get("ETA12/EfficiencyGraph")
ideta12eff    = idf.Get("ETA12/EfficiencyGraph")
trgeta12eff   = trgf.Get("ETA12/EfficiencyGraph")

trketa13eff   = trkf.Get("ETA13/EfficiencyGraph")
ideta13eff    = idf.Get("ETA13/EfficiencyGraph")
trgeta13eff   = trgf.Get("ETA13/EfficiencyGraph")

trketa14eff   = trkf.Get("ETA13/EfficiencyGraph")
ideta14eff    = idf.Get("ETA13/EfficiencyGraph")
trgeta14eff   = trgf.Get("ETA13/EfficiencyGraph")

trketa15eff   = trkf.Get("ETA15/EfficiencyGraph")
ideta15eff    = idf.Get("ETA15/EfficiencyGraph")
trgeta15eff   = trgf.Get("ETA15/EfficiencyGraph")

trketa20eff   = trkf.Get("ETA20/EfficiencyGraph")
ideta20eff    = idf.Get("ETA20/EfficiencyGraph")
trgeta20eff   = trgf.Get("ETA20/EfficiencyGraph")

trkpteff   = trkf.Get("PT/EfficiencyGraph")
idpteff    = idf.Get("PT/EfficiencyGraph")
trgpteff   = trgf.Get("PT/EfficiencyGraph")

trketapteff   = trkf.Get("ETA_PT/EffGraph2D")
idetapteff    = idf.Get("ETA_PT/EffGraph2D")
trgetapteff   = trgf.Get("ETA_PT/EffGraph2D")

trketaphieff   = trkf.Get("ETA_PHI/EffGraph2D")
idetaphieff    = idf.Get("ETA_PHI/EffGraph2D")
trgetaphieff   = trgf.Get("ETA_PHI/EffGraph2D")

f = TFile("../tuples/ZMuMu.MuonTT.2015.root")
t = f.Get("Z2MuMu/DecayTree")

triggercut = TCut("(muplus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonEWDecision_TOS ==1) || (muminus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonEWDecision_TOS ==1)")
trkqual    = TCut("muplus_TRACK_PCHI2 > 0.01 && (sqrt(muplus_PERR2)/muplus_P) < 0.1 && muminus_TRACK_PCHI2 > 0.01 && (sqrt(muminus_PERR2)/muminus_P) < 0.1")
fiducial      = TCut("muminus_PT > 20000 && muplus_PT > 20000 && Z0_M > 60000 && Z0_M < 120000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muminus_ETA > 2 && muminus_ETA < 4.5")

selcut =  triggercut + fiducial + trkqual

trgetacorr = GetEffCorr(trgetaeff, "triggereff")
trketacorr = GetEffCorr(trketaeff, "trkeff")
idetacorr  = GetEffCorr(idetaeff, "ideff")
'''
trgeta11corr = GetEffCorr(trgeta11eff, "triggereta11eff")
trketa11corr = GetEffCorr(trketa11eff, "trketa11eff")
ideta11corr  = GetEffCorr(ideta11eff, "ideta11eff")

trgeta12corr = GetEffCorr(trgeta12eff, "triggereta12eff")
trketa12corr = GetEffCorr(trketa12eff, "trketa12eff")
ideta12corr  = GetEffCorr(ideta12eff, "ideta12eff")

trgeta13corr = GetEffCorr(trgeta13eff, "triggereta13eff")
trketa13corr = GetEffCorr(trketa13eff, "trketa13eff")
ideta13corr  = GetEffCorr(ideta13eff, "ideta13eff")

trgeta14corr = GetEffCorr(trgeta14eff, "triggereta14eff")
trketa14corr = GetEffCorr(trketa14eff, "trketa14eff")
ideta14corr  = GetEffCorr(ideta14eff, "ideta14eff")

trgeta15corr = GetEffCorr(trgeta15eff, "triggereta15eff")
trketa15corr = GetEffCorr(trketa15eff, "trketa15eff")
ideta15corr  = GetEffCorr(ideta15eff, "ideta15eff")

trgeta20corr = GetEffCorr(trgeta20eff, "triggereta20eff")
trketa20corr = GetEffCorr(trketa20eff, "trketa20eff")
ideta20corr  = GetEffCorr(ideta20eff, "ideta20eff")

trgptcorr  = GetEffCorr(trgpteff, "triggerpteff")
trkptcorr  = GetEffCorr(trkpteff, "trkpteff")
idptcorr   = GetEffCorr(idpteff, "idpteff")

trgetaptcorr = GetEffCorr(trgetapteff,    "triggeretapteff")
trketaptcorr = GetEffCorr(trketapteff,  "trketapteff")
idetaptcorr  = GetEffCorr(idetapteff,     "idetapteff")

trgetaphicorr = GetEffCorr(trgetaphieff, "triggeretaphieff")
trketaphicorr = GetEffCorr(trketaphieff, "trketaphieff")
idetaphicorr  = GetEffCorr(idetaphieff, "idetaphieff")
'''
PtBins  = [0 ,2.2 , 3.4,4.6,5.8,7.2,8.7,10.5,12.8,15.4,19,24.5,34,63,270]
#for i in range(len(PtBins)): PtBins[i] = PtBins[i] * 1000
RapBins = [2 ,2.125 , 2.25,2.375,2.5,2.625,2.75,2.875,3,3.125,3.25,3.375,3.5,3.625,3.75,3.875,4,4.25,4.5]
PhiBins=  [0 ,0.01 , 0.02,0.03 , 0.05,0.07,0.1,0.15,0.2,0.3,0.4,0.6,0.8,1.2,2,4]

pi = '3.14159265959'
dPhi  = "abs(<A>_PHI - <B>_PHI) + (abs(<A>_PHI - <B>_PHI) > <pi>)*2*(<pi> - abs(<A>_PHI - <B>_PHI) )"
phistar = "tan((<pi> - ("+dPhi+"))/2)/cosh((<A>_ETA - <B>_ETA)/2)"

effvars = [
    ["PT", "Z0_PT/1000", PtBins],
    ["mup_PT", "muplus_PT/1000", PtBins],
    ["mum_PT", "muminus_PT/1000", PtBins],
    ["Y" , "Z0_Y", RapBins],
    ["PHISTAR", phistar.replace('<A>','muplus').replace('<B>','muminus').replace('<pi>',pi), PhiBins],
    ["ETA1", "muplus_ETA", 10, 2, 4.5],
    ["SPDHits", "nSPDHits", 100, 0,1000],
    ["ETA2", "muminus_ETA", 10, 2, 4.5]
]

ZMuMu2015Rec = Template("ZMuMu2015Rec")
ZMuMu2015Rec.SetSelCut(selcut)
ZMuMu2015Rec.AddTree(t)
ZMuMu2015Rec.AddVars(effvars)
ZMuMu2015Rec.Run()
ZMuMu2015Rec.SaveToFile()

ZMuMu2015EtaCorr = Template("ZMuMu2015EtaCorr")
ZMuMu2015EtaCorr.SetSelCut(selcut)
ZMuMu2015EtaCorr.AddTree(t)
ZMuMu2015EtaCorr.AddVars(effvars)
ZMuMu2015EtaCorr.Reweight("muplus_ETA",  trketacorr )
ZMuMu2015EtaCorr.Reweight("muminus_ETA", trketacorr )
ZMuMu2015EtaCorr.Reweight("muplus_ETA",  idetacorr  )
ZMuMu2015EtaCorr.Reweight("muminus_ETA", idetacorr  )
ZMuMu2015EtaCorr.Reweight("muplus_ETA",  "muminus_ETA", trgetacorr, "a*b/(a+b -1)" ) # inverse trig eff formula
ZMuMu2015EtaCorr.Run()
ZMuMu2015EtaCorr.SaveToFile()


from PlotTools import *

to_plot = [['Y', 'Y_{Z}'], ['PT', 'p_{T} [GeV]'], ['PHISTAR', '#phi^{*}']]

properties = {
    'includeNormErr' : False,
    'labels'          :      ['ptj>10', 'ptj>20', 'ptj>40', 'ptj>60'],
    'xlabel':     '#eta'    ,
    'ylabel':     '[A.U.]',
    'location' : "../figures",
    'normalised' : False,
    'logscale' : False,
    'colors' : "None",
    'leglims'  : [0.4, 0.2, 0.9, 0.4],
    'normerrlims': [0.9, 1.1]
    
}


for p in to_plot:
    a = Plot([ZMuMuMC2015Gen.GetVar(p[0]).GetHist(), ZMuMuMC2015EtaCorr.GetVar(p[0]).GetHist(), ZMuMuMC2015Rec.GetVar(p[0]).GetHist()])
    for h in a.plots: normalise_to_min(h)
    a.setProps(properties)
    a.ShiftLegY(0.2)
    if p[0] == 'PT' or p[0] =='PHISTAR' :
        a.properties['logscale'] = True
        a.properties['logx'] = True
    if p[0] == 'PT' or p[0] == 'PHISTAR':
        a.ShiftLegX(-0.2)
    if p[0] == 'Y':
        a.ShiftLegX(-0.1)
    a.properties['labels']      = ['Truth', 'Reconstructed (Efficiency Corrected)', 'Reconstructed' ]
    a.properties['ylabel']      = 'Events'
    a.properties['xlabel']      = p[1]
    #a.properties['ylims']       = [0.8, 1.0]
    a.properties['linecolors']  = ['red', 'blue','black']
    a.properties['markerstyles'] = [0, 20, 20]
    a.properties['drawOpts']    = ['hist', 'e1','e1']
    a.properties['filename']    = "zmumumc2015_closure_"+p[0]
    a.properties['toCompare'] = [[0,1]]
    a.drawROOT()
    a.setProp('normalised', True)
    a.setProp('filename', a.getProp('filename')+'_log')
    a.drawROOT()

