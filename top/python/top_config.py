from ROOT import TFile, TTree, TCut

gandir = '/hepstore/sfarry/gangadir/workspace/sfarry/LocalXML/'
dpm_loc = 'root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top/'
eos_loc = 'root://eoslhcb.cern.ch///eos/lhcb/user/s/sfarry/WZJets/'
local = '/user2/sfarry/workspaces/strange/tuples/'

truth_stag = TCut("abs(jet_mc_flavour) == 3")
truth_qtag = TCut("abs(jet_mc_flavour) != 3 && abs(jet_mc_flavour) < 4")
truth_gtag = TCut("abs(jet_mc_flavour) == 21")
truth_btag = TCut("abs(jet_mc_flavour) == 5")
truth_ctag = TCut("abs(jet_mc_flavour) == 4")
truth_nostag = TCut("abs(jet_mc_flavour) != 3")
truth_inctag = TCut("abs(jet_mc_flavour) != 3 && abs(jet_mc_flavour) != 999")
truth_notag = TCut("abs(jet_mc_flavour) == 999")

ptmcj20   = TCut("jet_truejet_PT > 20000")
etamcj    = TCut("jet_truejet_ETA > 2.2 && jet_truejet_ETA < 4.2")

ptj20   = TCut("jet_PT > 20000")
etaj    = TCut("jet_ETA > 2.2 && jet_ETA < 4.2")

svtag   = TCut("jet_BDTTag == 1")

mc_stag   = TCut("abs(jet_truejet_flavour) == 3")
mc_qtag   = TCut("abs(jet_truejet_flavour) != 3 && abs(jet_truejet_flavour) < 6")
mc_gtag   = TCut("abs(jet_truejet_flavour) == 21")
mc_notag  = TCut("abs(jet_truejet_flavour) == 999")
mc_nostag = TCut("abs(jet_truejet_flavour) != 3")
mc_inctag = TCut("abs(jet_truejet_flavour) != 3 && abs(jet_truejet_flavour) != 999")

zj_hftag = TCut('(abs(boson_mcjet_flavour) == 4 || abs(boson_mcjet_flavour) == 5)')



fwdcut = 'fwdjet_pt > 20 && mup_pt > 20 && mum_pt > 20 && min(mup_eta, mum_eta) > 2 && max(mum_eta, mup_eta) < 4.5 && Z_m > 60 && Z_m < 120'
bwdcut = 'fwdjet_pt > 20 && mup_pt > 20 && mum_pt > 20 && min(mup_eta, mum_eta) > -4.5 && max(mum_eta, mup_eta) < -2 && Z_m > 60 && Z_m < 120'

fwd_flav = 'abs(fwdjet_flav) == 3'
bwd_flav = 'abs(bwdjet_flav) == 3'

class DataObj:
    def __init__(self, name, folder="ZMuMu", dpm = dpm_loc):
        print "Opening ",dpm+name.replace("<P>","MU")+".root"
        self.MU = TFile.Open(dpm+name.replace("<P>","MU")+".root")
        print "Opening ",dpm+name.replace("<P>","MD")+".root"
        self.MD = TFile.Open(dpm+name.replace("<P>","MD")+".root")
        self.MUt = self.MU.Get(folder+"/DecayTree")
        self.MDt = self.MD.Get(folder+"/DecayTree")
        self.MDt_ss = self.MD.Get(folder+'_ss/DecayTree')
        self.MUt_ss = self.MU.Get(folder+'_ss/DecayTree')
        #self.MU_bdt = TFile.Open(local+name.replace("<P>","MU")+'.MVA.root')
        #self.MUt_bdt = self.MU_bdt.Get('tree')
        #self.MDt.AddFriend(self.MDt_bdt)
        #self.MUt.AddFriend(self.MUt_bdt)
    def trees(self):
        return [self.MDt, self.MUt]
    def trees_ss(self):
        return [self.MDt_ss, self.MUt_ss]
    def get_tot_evts(self, a):
        if isinstance(a, TCut):
            return self.MUt.GetEntries(a.GetTitle()) + self.MDt.GetEntries(a.GetTitle())
        elif isinstance(a, str):
            return self.MUt.GetEntries(a) + self.MDt.GetEntries(a)
        else:
            print "not a valid cut type"

gg2ttbar_mc2016 = DataObj('ttbar.ttbar_gg.<P>.MC2016', folder='ttbar')
qq2ttbar_mc2016 = DataObj('ttbar.ttbar_qqbar.<P>.MC2016', folder='ttbar')
ww_mc2016       = DataObj('ttbar.WW_ll.<P>.MC2016', folder='ttbar')
ztautau_mc2016  = DataObj('ttbar.Z_tautau.<P>.MC2016', folder='ttbar')
ttbar_2016      = DataObj('ttbar.<P>.2016', folder='ttbar')
ttbar_2015      = DataObj('ttbar.<P>.2015', folder='ttbar')


mcjetvars = [
    ['ptj', 'jet_truejet_PT/1000', 15, 20, 80],
    ['etaj','jet_truejet_ETA', 15, 2.2, 4.2]
]

jetvars = [
    ['ptj', 'jet_PT/1000', 15, 20, 80],
    ['etaj','jet_ETA', 15, 2.2, 4.2]
]

from PlotTools import *
from Style import *
SetLHCbStyle()

