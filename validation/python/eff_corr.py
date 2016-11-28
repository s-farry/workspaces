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

trkf    = TFile("../tuples/MuonTracking2015.root")
idf     = TFile("../tuples/MuonID2015.root")
trgf    = TFile("../tuples/MuonTrigger2015.root")

trketaeff   = trkf.Get("ETA/EfficiencyGraph")
idetaeff    = idf.Get("ETA/EfficiencyGraph")
trgetaeff   = trgf.Get("ETA/EfficiencyGraph")

trgetacorr = GetEffCorr(trgetaeff, "triggereff")
trketacorr = GetEffCorr(trketaeff, "trkeff")
idetacorr  = GetEffCorr(idetaeff, "ideff")

PtBins  = [0 ,2.2 , 3.4,4.6,5.8,7.2,8.7,10.5,12.8,15.4,19,24.5,34,63,270]
RapBins = [2 ,2.125 , 2.25,2.375,2.5,2.625,2.75,2.875,3,3.125,3.25,3.375,3.5,3.625,3.75,3.875,4,4.25,4.5]
PhiBins=  [0 ,0.01 , 0.02,0.03 , 0.05,0.07,0.1,0.15,0.2,0.3,0.4,0.6,0.8,1.2,2,4]

pi = '3.14159265959'
dPhi  = "abs(<A>_PHI - <B>_PHI) + (abs(<A>_PHI - <B>_PHI) > <pi>)*2*(<pi> - abs(<A>_PHI - <B>_PHI) )"
phistar = "tan((<pi> - ("+dPhi+"))/2)/cosh((<A>_ETA - <B>_ETA)/2)"

effvars = [
    ["PT", "Z0_PT/1000", PtBins],
    ["TRUEPT", "Z0_TRUEPT/1000", PtBins],
    #["FSR_PT", "Z0_FSR_PT/1000", PtBins],
    ["mup_PT", "muplus_PT/1000", PtBins],
    ["mum_PT", "muminus_PT/1000", PtBins],
    ["Y" , "Z0_Y", RapBins],
    ["PHI" , "Z0_PHI", 20, -TMath.Pi(), TMath.Pi()],
    ["PHISTAR", phistar.replace('<A>','muplus').replace('<B>','muminus').replace('<pi>',pi), PhiBins],
    ["ETA1", "muplus_ETA", 10, 2, 4.5],
    ["SPDHits", "nSPDHits", 100, 0,1000],
    ["ETA2", "muminus_ETA", 10, 2, 4.5]
]

f = TFile("../tuples/ZMuMu.2015.root")
t = f.Get("ZMuMu/DecayTree")

mass = TCut("Z0_M > 60000 && Z0_M < 120000")
eta  = TCut("min(muplus_ETA, muminus_ETA) > 2.0 && max(muplus_ETA, muminus_ETA) < 4.5")
pt   = TCut("min(muplus_PT, muminus_PT) > 20000")

selcut = mass + eta + pt

trigger_plus   = TCut("muplus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonEWDecision_TOS ==1")
trigger_minus = TCut("muminus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonEWDecision_TOS ==1")

trigger = TCut("("+trigger_plus.GetTitle() + ") || (" + trigger_minus.GetTitle() + ")")


ZMuMu2015Rec = Template("ZMuMu2015Rec", t, selcut + trigger )
ZMuMu2015Rec.AddVars(effvars)
ZMuMu2015Rec.ApplyCut()
ZMuMu2015Rec.FillVars()
ZMuMu2015Rec.SaveToFile()

ZMuMu2015EtaCorr = Template("ZMuMu2015EtaCorr")
ZMuMu2015EtaCorr.SetSelCut(selcut + trigger)
ZMuMu2015EtaCorr.AddTree(t)
ZMuMu2015EtaCorr.AddVars(effvars)
ZMuMu2015EtaCorr.Reweight("muplus_ETA",  trketacorr )
ZMuMu2015EtaCorr.Reweight("muminus_ETA", trketacorr )
ZMuMu2015EtaCorr.Reweight("muplus_ETA",  idetacorr  )
ZMuMu2015EtaCorr.Reweight("muminus_ETA", idetacorr  )
ZMuMu2015EtaCorr.Reweight("muplus_ETA",  "muminus_ETA", trgetacorr, "a*b/(a+b -1)" ) # inverse trig eff formula
ZMuMu2015EtaCorr.Run()
ZMuMu2015EtaCorr.SaveToFile()
