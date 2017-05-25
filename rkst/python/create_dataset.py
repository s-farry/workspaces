from ROOT import TFile, TTree, TH1F, RooRealVar, RooDataSet, RooArgSet
from math import *

class Bunch:
        def __init__(self, **kwds):
                self.__dict__.update(kwds)

kstarmass = 891.66
pi0mass   = 134.9766
jpsimass  = 3096.916 

f = TFile("/hepstore/sfarry/GridOutput/3066/BjpsiK.BJpsiK.MU.MC2016.root")
g = TFile("/hepstore/sfarry/GridOutput/3067/BjpsiK.BJpsiK.MD.MC2016.root")
t = f.Get("BJpsiKDT/DecayTree")
u = g.Get("BJpsiKDT/DecayTree")
v = f.Get("BJpsiKDT_tp/DecayTree")
w = g.Get("BJpsiKDT_tp/DecayTree")
x = f.Get("BJpsiK/TrueTree")
y = g.Get("BJpsiK/TrueTree")



jpsi_m    = RooRealVar("jpsi_m", "jpsi_m", 0, 10000)
pt        = RooRealVar("pt", "pt", 0, 20000)
eta       = RooRealVar("eta", "eta", 2.0, 4.5)
velomatch = RooRealVar("velomatch", "velomatch", 0, 1)
dR = RooRealVar("dR", "dR", 0, 100)
dRt  = RooRealVar("dRt", "dRt", 0, 100000)

argset = RooArgSet(jpsi_m, pt, eta, velomatch, dR, dRt)

ds  = RooDataSet("ds", "ds", argset)




for aa in (v, w):
        aa.SetBranchStatus("*", 0)
        aa.SetBranchStatus("tag_PT", 1)
        aa.SetBranchStatus("probe_PT", 1)
        aa.SetBranchStatus("probe_ETA", 1)
        aa.SetBranchStatus("probe_P", 1)
        aa.SetBranchStatus("probe_TRACK_CHI2NDOF", 1)
        aa.SetBranchStatus("probe_CaloHcalE", 1)
        aa.SetBranchStatus("probe_IP_OWNPV", 1)
        aa.SetBranchStatus("B_ENDVERTEX*", 1)
        aa.SetBranchStatus("tag_ProbNNe",1)
        aa.SetBranchStatus("K_ProbNNk",1)
        aa.SetBranchStatus("K_ProbNNpi",1)
        aa.SetBranchStatus("probe_EcalClusterEt",1)
        aa.SetBranchStatus("Jpsi_M",1)
        aa.SetBranchStatus("probe_VeloMatch",1)
        aa.SetBranchStatus("probe_deltaR",1)
        aa.SetBranchStatus("probe_deltaRt",1)

        for i,e in enumerate(aa):
                if i%10000 == 0:
                        print i," entry of ",aa.GetEntries()

                if e.tag_PT < 500 or  e.probe_PT < 500: continue
                if e.probe_TRACK_CHI2NDOF > 1.0 or e.probe_CaloHcalE/e.probe_P > 0.1: continue
                if e.probe_IP_OWNPV < 0.1 or e.B_ENDVERTEX_CHI2/e.B_ENDVERTEX_NDOF > 2: continue
                if e.tag_ProbNNe < 0.2 or (e.K_ProbNNk*(1-e.K_ProbNNp)) < 0.05 : continue
                if e.probe_EcalClusterEt/e.probe_PT < 0.6 or e.probe_EcalClusterEt/e.probe_PT > 1.4: continue

                jpsi_m.setVal(e.Jpsi_M)
                pt.setVal(e.probe_PT)
                eta.setVal(e.probe_ETA)
                velomatch.setVal(e.probe_VeloMatch)
                dR.setVal(e.probe_deltaR)
                dRt.setVal(e.probe_deltaRt)
                ds.add(argset)

oFile = TFile("/user2/sfarry/workspaces/rkst/tuples/bjpsik_mc2016.root", "RECREATE")
ds.Write()
oFile.Close()
