from ROOT import TFile, TTree, TH1F, RooRealVar, RooDataSet, RooArgSet
from math import *

class Bunch:
        def __init__(self, **kwds):
                self.__dict__.update(kwds)

kstarmass = 891.66
pi0mass   = 134.9766
jpsimass  = 3096.916 

#f = TFile("/hepstore/sfarry/GridOutput/3129/BjpsiK.BJpsiK.MU.MC2016.root")
#g = TFile("/hepstore/sfarry/GridOutput/3130/BjpsiK.BJpsiK.MD.MC2016.root")
f = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/rkst/BjpsiK.BJpsiK.MU.MC2016.root")
g = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/rkst/BjpsiK.BJpsiK.MD.MC2016.root")
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
tagbrem   = RooRealVar("tagbrem", "tagbrem", 0, 20)
dR = RooRealVar("dR", "dR", 0, 100)
dRt  = RooRealVar("dRt", "dRt", 0, 100000)

argset = RooArgSet(jpsi_m, pt, eta, velomatch, dR, dRt, tagbrem)

ds  = RooDataSet("ds", "ds", argset)




#sel = TCut("tag_PT > 1000 && tag_P > 8000 && probe_PT > 1000 && probe_P > 8000 && probe_TRACK_CHI2NDOF < 1.0 && probe_CaloHcalE/probe_P < 0.1 && probe_IP_OWNPV > 0.1 && B_ENDVERTEX_CHI2/B_ENDVERTEX_NDOF < 2 && tag_MC15TuneV1_ProbNNe > 0.2 && (K_MC15TuneV1_ProbNNk*(1-K_MC15TuneV1_ProbNNp)) > 0.05 && probe_EcalClusterEt/probe_PT > 0.6 && probe_EcalClusterEt/probe_PT < 1.4 & B_FDCHI2_OWNPV > 15 && B_BPVLTFITCHI2 < 4 && B_HOP_MASS > 3500 && B_ConsB_M > 5300 && B_ConsB_M < 5500 && B_M > 4900")



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
        aa.SetBranchStatus("B_FDCHI2_OWNPV", 1)
        aa.SetBranchStatus("B_HOP_MASS", 1)
        aa.SetBranchStatus("B_ConsB_M", 1)
        aa.SetBranchStatus("B_M", 1)
        aa.SetBranchStatus("tag_BremMultiplicity",1)
        aa.SetBranchStatus("tag_*ProbNNe",1)
        aa.SetBranchStatus("K_*ProbNNk",1)
        aa.SetBranchStatus("K_*ProbNNpi",1)
        aa.SetBranchStatus("probe_EcalClusterEt",1)
        aa.SetBranchStatus("Jpsi_M",1)
        aa.SetBranchStatus("probe_VeloMatch",1)
        aa.SetBranchStatus("probe_deltaR",1)
        aa.SetBranchStatus("probe_deltaRt",1)

        for i,e in enumerate(aa):
                if i%10000 == 0:
                        print i," entry of ",aa.GetEntries()

                if e.tag_PT < 1000 or  e.probe_PT < 500: continue
                if e.probe_TRACK_CHI2NDOF > 1.0 or e.probe_CaloHcalE/e.probe_P > 0.1: continue
                if e.probe_IP_OWNPV < 0.1 or e.B_ENDVERTEX_CHI2/e.B_ENDVERTEX_NDOF > 2: continue
                if e.tag_MC15TuneV1_ProbNNe < 0.2 or (e.K_MC15TuneV1_ProbNNk*(1-e.K_MC15TuneV1_ProbNNp)) < 0.05 : continue
                if e.probe_EcalClusterEt/e.probe_PT < 0.6 or e.probe_EcalClusterEt/e.probe_PT > 1.4: continue
                if e.B_FDCHI2_OWNPV < 15 or e.B_HOP_MASS < 3500 or e.B_ConsB_M < 5300: continue
                if e.B_M < 4900 or e.B_BPVLTFITCHI2 > 4 : continue

                jpsi_m.setVal(e.Jpsi_M)
                pt.setVal(e.probe_PT)
                eta.setVal(e.probe_ETA)
                velomatch.setVal(e.probe_VeloMatch)
                dR.setVal(e.probe_deltaR)
                dRt.setVal(e.probe_deltaRt)
                tagbrem.setVal(e.tag_BremMultiplicity)
                ds.add(argset)

oFile = TFile("/user2/sfarry/workspaces/rkst/tuples/bjpsik_mc2016.root", "RECREATE")
ds.Write()
oFile.Close()
