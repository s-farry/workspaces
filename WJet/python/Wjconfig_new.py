from ROOT import TFile, TTree, TCut, TF1, TMath
from Utils import GetWeightHist, GetWeightHist2D, GetMCLumi
import copy

gandir = '/hepstore/sfarry/gangadir/workspace/sfarry/LocalXML/'
dpm_loc = 'root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WZJets/'
eos_loc = 'root://eoslhcb.cern.ch///eos/lhcb/user/s/sfarry/WZJets/'

class DataObj:
    def __init__(self, name, folder="WTuple", dpm = dpm_loc):
        self.MU = TFile.Open(dpm+name.replace("<P>","MU")+".root")
        self.MD = TFile.Open(dpm+name.replace("<P>","MD")+".root")
        self.MUt = self.MU.Get(folder+"/DecayTree")
        self.MDt = self.MD.Get(folder+"/DecayTree")
    def trees(self):
        return [self.MUt, self.MDt]
    def get_tot_evts(self, a):
        if isinstance(a, TCut):
            return self.MUt.GetEntries(a.GetTitle()) + self.MDt.GetEntries(a.GetTitle())
        elif isinstance(a, str):
            return self.MUt.GetEntries(a) + self.MDt.GetEntries(a)
        else:
            print "not a valid cut type"


#W->mu(jet) 2012
wmuj    = DataObj("WMuJet.<P>.2012")
#Z->mumu(jet) Data 2012
zmumuj  = DataObj("ZMuMuJet.<P>.2012", folder="ZMuMu")
zmumuj_jec1 = TFile.Open("/user2/sfarry/WJet/tuples/ZMuMuJet.MU.2012.jecvars.root")
zmumuj_jec2 = TFile.Open("/user2/sfarry/WJet/tuples/ZMuMuJet.MD.2012.jecvars.root")
zmumuj.MUt.AddFriend(zmumuj_jec1.Get("tree"))
zmumuj.MDt.AddFriend(zmumuj_jec2.Get("tree"))
#zmumuj_eos  = DataObj("ZMuMuJet.<P>.2012", folder="ZMuMu", dpm = eos_loc)

#W->mu(jet) 2012 - TIS
#wmuj_tis = DataObj("WMuJet_TIS.<P>.2012")

#W->mu(jet) 2012 - TIS
#wmuj_mb  = DataObj("WMuJet_MinBias.<P>.2012")

#w->mu MC selection
wmuj_mc2012 = DataObj("Wmujet.Wmunujet.<P>.MC2012")
zmuj_mc2012 = DataObj("Wmujet.Z_mumujet17.<P>.MC2012")

bbbar_mc2012 = DataObj("Wmujet.bbbar.<P>.MC2012")
ccbar_mc2012 = DataObj("Wmujet.ccbar.<P>.MC2012")

wmuj_inc_mc2012 = DataObj("Wmujet.Wmunu.<P>.MC2012")

wmuj_ttbar_gg_mc2012 = DataObj("Wmujet.ttbar_gg.<P>.MC2012")
wmuj_ttbar_qqbar_mc2012 = DataObj("Wmujet.ttbar_qqbar.<P>.MC2012")
wmuj_WW_mc2012 = DataObj("Wmujet.WW.<P>.MC2012")

zmumuj_ttbar_gg_mc2012 = DataObj("Zmumujet.ttbar_gg.<P>.MC2012", folder = 'ZMuMu')
zmumuj_ttbar_qqbar_mc2012 = DataObj("Zmumujet.ttbar_qqbar.<P>.MC2012", folder='ZMuMu')
zmumuj_WW_mc2012 = DataObj("Zmumujet.WW.<P>.MC2012", folder='ZMuMu')


#wmuj_tis_mc2012 = DataObj("Wmujet.Wmunujet.<P>.MC2012")
#z->mumu MC selection
zmumuj_mc2012 = DataObj("Zmumujet.Z_mumujet17.<P>.MC2012", folder="ZMuMu")

#mc cross-sections

mcinfo = {
    # 'Name' : [acceptance, xsec, events]
    #'WMuNu'   : [0.246382           , 9.282*1000      ,  2515968 + 2526894   ], # 42311003
    'WMuNu'   : [0.246382           , 9.282*1000      ,  2054227 + 2011317   ], # 42311003 - failed jobs
    'WTauNu'  : [0.134150           , 9.291*0.17*1000 ,  1072163 + 1062658   ], # 42300001
    'ZMuMu'   : [0.367744           , 0.9593*1000     ,  2035996 + 2014491   ], # 42112001
    'Ztautau' : [0.366538           , 0.8588*1000     ,  2031495  + 2015495  ],  # 42100000
#    'WMuJet'  : [0.239028           , 13.17*0.1063*1000   ,  2536881 + 2531103   ], # 42311011 - sim 08e 5020694 + 5013964 for sim08g - 12.30 when run standalone,  # 42100000
    'WMuJet'  : [0.239028           , 13.17*1000   ,  2536881 + 2531103   ], # 42311011 - sim 08e 5020694 + 5013964 for sim08g - 12.30 when run standalone
    'ZMuMuJet': [0.327112           , 12.54*0.03*1000     ,  2527742 + 2545494   ], #42112022 - Sim 08b
    'gg2ttbar' : [0.054             , 116.2, 509998 + 507498 ],#41900006 -Sim 08c
    'qq2ttbar' : [0.072             , 33.1, 506999 + 500499 ],#41900007 -Sim 08c
    'WW'       : [0.0807,           34.2, 107927 + 115548 ], #42021000, Sim08g
    'singletop': [0.037,            67.1, 1005832 + 1010763 ] #41900003, Sim08e
    }

#2011
#fal = TF1("fal","1000000 * (1-exp(-0.3091/x))",0,1)
#2012
fal = TF1("fal","1000000 * (1-exp(-0.3188/x))",0,1)

#luminosities
wmuLumi       = GetMCLumi("WMuNu"  , mcinfo)
wtauLumi      = GetMCLumi("WTauNu" , mcinfo)
ztautauLumi   = GetMCLumi("Ztautau", mcinfo)
zmumumcLumi   = GetMCLumi("ZMuMu"  , mcinfo)
zmumujetLumi  = GetMCLumi("ZMuMuJet"  , mcinfo)
wmujetLumi    = GetMCLumi("WMuJet"  , mcinfo)
wwLumi        = GetMCLumi("WW"  , mcinfo)
gg2ttbarLumi  = GetMCLumi("gg2ttbar",mcinfo)
qq2ttbarLumi  = GetMCLumi("qq2ttbar",mcinfo)
singletopLumi = GetMCLumi("singletop",mcinfo)

jetiso_e = "(muminus_PT/muminus_sigjet_PT) * (muminus_sigjet_jec + (muminus_sigjet_ndauts==0)*1000)"
jetpt_e  = "muminus_sigjet_PT"

#cuts
pt       = TCut("muminus_PT > 20000")
ip       = TCut("muminus_ipubs < 0.05")
hi_ip    = TCut("muminus_ipubs > 0.1")
muonVeto = TCut("muminus_nMuonsG20GeV == 0")
plus     = TCut("muminus_ID == -13")
minus    = TCut("muminus_ID == 13")
Ep       = TCut("((muminus_CaloHcalE + muminus_CaloEcalE)/muminus_P)<0.04 && muminus_InAccHcal ==1 && muminus_InAccEcal == 1")
antiEp   = TCut("((muminus_CaloHcalE + muminus_CaloEcalE)/muminus_P)>0.1 && (muminus_CaloHcalE/muminus_P) >0.03")
trkqual  = TCut("muminus_TRACK_PCHI2 > 0.01 && sqrt(muminus_PERR2)/muminus_P < 0.1")
pchi2    = TCut("muminus_TRACK_PCHI2 > 0.01")
tthits   = TCut("muminus_TRACK_nTTHits > 0")

ptj20     = TCut("muminus_jet_PT > 20000")
ptj20_p   = TCut("muplus_jet_PT > 20000")
ptj20_zmumu     = TCut("boson_jet_PT > 20000")

ptmcj20 = TCut("muminus_truejet_PT > 20000")
ptmcj20_zmumu = TCut("boson_truejet_PT > 20000")

trigger = TCut("muminus_Hlt2SingleMuonHighPTDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonDecision_TOS ==1")


tis   = TCut("muminus_L0Global_TIS==1 && muminus_Hlt1Global_TIS==1 && muminus_Hlt2Global_TIS==1")
dif   = TCut("dif_mu_pt > 20000")
zmumu   = TCut("muminus_PT > 20000 && muplus_PT > 20000 && muplus_ETA > 2.0 && muplus_ETA < 4.5 && muminus_ETA > 2.0 && muminus_ETA < 4.5 && boson_M > 60000 && boson_M < 120000")

badruns = TCut("abs(boson_OWNPV_Z) < 300 && (runNumber < 126125 || runNumber > 126160)")
badruns_mu = TCut("abs(muminus_OWNPV_Z) < 300 && (runNumber < 126125 || runNumber > 126160)")

#pt balance for jets
#mupjpt     = TCut("sqrt( (muplus_jet_PX + muplus_PX)^2  + (muplus_jet_PY + muplus_PY)^2 )  > 20000")
#mumjpt     = TCut("sqrt( (muminus_jet_PX + muminus_PX)^2 + (muminus_jet_PY + muminus_PY)^2 ) > 20000")
#antimumjpt    = TCut("sqrt( (muminus_jet_PX + (muminus_sigjet_PX/(muminus_sigjet_jec + (muminus_sigjet_ndauts==0)*1000)))^2 + (muminus_jet_PY + (muminus_sigjet_PY/(muminus_sigjet_jec + (muminus_sigjet_ndauts==0)*1000)))^2) < 20000")
#mumjpt    = TCut("sqrt( (muminus_jet_PX + (muminus_sigjet_PX/(muminus_sigjet_jec + (muminus_sigjet_ndauts==0)*1000)))^2 + (muminus_jet_PY + (muminus_sigjet_PY/(muminus_sigjet_jec + (muminus_sigjet_ndauts==0)*1000)))^2) > 20000")
#mumjpt_nojet    = TCut("sqrt( (muminus_jet_PX + muminus_PX)^2 + (muminus_jet_PY + muminus_PY)^2) > 20000")

antimumjpt = TCut("sqrt( (muminus_jet_PX + muminus_sigjet_PX)^2 + (muminus_jet_PY + muminus_sigjet_PY)^2) < 20000")
antimumjpt_nojet = TCut("sqrt( (muminus_jet_PX + muminus_PX)^2 + (muminus_jet_PY + muminus_PY)^2) < 20000")
mumjpt     = TCut("sqrt( (muminus_jet_PX + muminus_sigjet_PX)^2 + (muminus_jet_PY + muminus_sigjet_PY)^2) > 20000")
mupjpt     = TCut("sqrt( (muplus_jet_PX + muplus_sigjet_PX)^2 + (muplus_jet_PY + muplus_sigjet_PY)^2) > 20000")
mumjpt_nojet    = TCut("sqrt( (muminus_jet_PX + muminus_PX)^2 + (muminus_jet_PY + muminus_PY)^2) > 20000")
mupjpt_nojet    = TCut("sqrt( (muplus_jet_PX + muplus_PX)^2 + (muplus_jet_PY + muplus_PY)^2) > 20000")
mumjpt_true     = TCut("sqrt( (muminus_truejet_PX + muminus_sigjet_PX)^2 + (muminus_truejet_PY + muminus_sigjet_PY)^2) > 20000")

#anti isolated
antiiso    = TCut("muminus_cpt_0.50 > 5000")
antijetiso = TCut("(muminus_PT/muminus_sigjet_PT) < 0.8")

pt_plus      = TCut(pt.GetTitle().replace("minus","plus"))
trigger_plus = TCut(trigger.GetTitle().replace("minus","plus"))
tthits_plus  = TCut(tthits.GetTitle().replace("minus","plus"))
trkqual_plus   = TCut(trkqual.GetTitle().replace("minus","plus"))
pchi2_plus   = TCut(pchi2.GetTitle().replace("minus","plus"))
Ep_plus      = TCut(Ep.GetTitle().replace("minus","plus"))
ip_plus      = TCut(ip.GetTitle().replace("minus","plus"))
muonVeto_plus   = TCut(muonVeto.GetTitle().replace("minus","plus"))
zmass        = TCut("boson_M > 60000 && boson_M < 120000")

ztrigger = TCut("("+trigger.GetTitle() + ") || ( " + trigger_plus.GetTitle() + ")")
select_runs = TCut("abs(boson_OWNPV_Z) < 300 && ( runNumber < 126125 || runNumber > 126160)")
zdimutrigger = TCut("boson_L0DiMuonDecision_TOS == 1 && boson_Hlt1DiMuonHighMassDecision_TOS == 1 && boson_Hlt2DiMuonZDecision_TOS == 1")

selcut_zmumu   = zmumu + ztrigger + trkqual + trkqual_plus + ptj20_zmumu
selcut_zmumu_nojet   = zmumu + ztrigger + trkqual + trkqual_plus

selcut_base    = (pt + muonVeto + trigger + Ep + trkqual + tthits + ptj20)
selcut_base_noveto  = (pt + trigger + Ep + trkqual + tthits + ptj20)
selcut_zmumu_base_m = zmumu + trigger + trkqual + ptj20 + tthits + Ep + muonVeto
selcut_zmumu_base_p = zmumu + trigger_plus + trkqual_plus + ptj20_p + tthits_plus + Ep_plus + muonVeto_plus
selcut_zmumu_base_nojet_m = zmumu + trigger + trkqual
selcut_zmumu_base_nojet_p = zmumu + trigger_plus + trkqual_plus
selcut_base_nojet   = (pt + muonVeto + trigger + Ep + trkqual + tthits)
selcut_base_nojetnoveto   = (pt + trigger + Ep + trkqual + tthits)
selcut_mcbase  = (pt + muonVeto + trigger + Ep + trkqual + tthits + ptmcj20)

selcut         = selcut_base + ip + mumjpt
selcut_nomujet = selcut_base + ip + mumjpt_nojet
selcut_zmumu_m = selcut_zmumu_base_m + ip + mumjpt
selcut_zmumu_p = selcut_zmumu_base_p + ip_plus + mupjpt

selcut_zmumu_nojet_m = selcut_zmumu_base_nojet_m + ip + mumjpt
selcut_zmumu_nojet_p = selcut_zmumu_base_nojet_p + ip_plus + mupjpt


#selcut_zmumu_p = TCut(selcut.GetTitle().replace("minus","plus")) + zmumu

selcut_tis     = (pt + muonVeto + antiEp + trkqual + tthits + ptj20 + ip + tis)
selcut_mb      = (pt + muonVeto + antiEp + trkqual + tthits + ptj20 + ip)
selcut_mb_noep = (pt + muonVeto + antiEp + trkqual + tthits + ptj20 + ip)
selcut_dif     = (pt + muonVeto + antiEp + trkqual + tthits + ptj20 + ip + tis + dif)
selcut_mb_dif  = (pt + muonVeto + antiEp + trkqual + tthits + ptj20 + ip + dif)

selcut_nojet = (pt + muonVeto + trigger + Ep + trkqual + tthits + ip)

selcut_plus = TCut(selcut.GetTitle().replace('minus','plus'))

ptbins = [20, 25, 30, 40, 50,100]
etabins = [2, 2.5, 3.0, 3.5, 4.5]
eta8bins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
jetetabins = [2.2, 2.7, 3.2, 3.7, 4.2]

dx_vtx = "sqrt((muminus_jet_vtx_x - boson_ENDVERTEX_X)^2 + (muminus_jet_vtx_y - boson_ENDVERTEX_Y)^2 + (muminus_jet_vtx_z - boson_ENDVERTEX_Z)^2)"
pi = '3.14159265959'
dPhi  = "abs(<A>_PHI - <B>_PHI) + (abs(<A>_PHI - <B>_PHI) > <pi>)*2*(<pi> - abs(<A>_PHI - <B>_PHI) )".replace('<pi>', pi)
#not correct - hardly worth fixing it
#dPhi2  = "(<A>_PHI - <B>_PHI + ((<A>_PHI - <B>_PHI) < 0)*2*<pi> - ((<A>_PHI - <B>_PHI) > <pi>)*2*<pi>".replace('<pi>', pi)
deltaR = "sqrt((<A>_ETA - <B>_ETA)^2 + (<dphi>)^2)".replace('<dphi>', dPhi) 
#deltaR2 = "sqrt((<A>_ETA - <B>_ETA)^2 + (<dphi>)^2)".replace('<dphi>', dPhi2) 
#variables
jetvars = [
    ["Jet_M",  "muminus_jet_M", 100 , 0, 20000],
    ["Jet_PT", "muminus_jet_PT/1000", ptbins],
    #["Jet_PT_full", "muminus_jet_PT/1000", 100,0,100],
    ["Jet_ETA", "muminus_jet_ETA", jetetabins],
    #["Jet_ETA_full", "muminus_jet_ETA", 100, 2.2, 4.2],
    #["Jet_mpt", "muminus_jet_mpt", 100 , 0, 30000],
    #["Jet_mtf", "muminus_jet_mtf", 100 , 0, 1],
    #["Jet_npoint", "muminus_jet_npoint", 21 , -0.5, 20.5],
    #["Jet_mult", "muminus_jet_ndauts", 41 , -0.5, 40.5],
    #["MJet_M",  "sqrt( (muminus_jet_PE + muminus_PE)^2 - ((muminus_jet_PX + muminus_PX)^2 + (muminus_jet_PY + muminus_PY)^2 + (muminus_jet_PZ + muminus_PZ)^2 ) )", 100, 0, 100000],
    #["MJet_PT",  "sqrt( (muminus_jet_PX + muminus_PX)^2 + (muminus_jet_PY + muminus_PY)^2 )", 100, 0, 100000],
    #["dx_vtx",  dx_vtx, 200, 0, 2],
    #["dPhi",  dPhi.replace('<A>','muminus').replace('<B>', 'muminus_jet'), 6, 0, TMath.Pi()],
    #["dR",  deltaR.replace('<A>','muminus').replace('<B>', 'muminus_jet'), 500, 0, 10],
 #   ["dRb",  deltaR2.replace('<A>','muminus').replace('<B>', 'muminus_jet'), 500, 0, 10],
    #["DiJet_PT",  "sqrt( (muminus_jet_PX + muminus_sigjet_PX)^2 + (muminus_jet_PY + muminus_sigjet_PY)^2)", 100, 0, 100000]
    ]

jetvars_zmumu = [
    ["Jet_PT" , "boson_jet_PT/1000", ptbins],
    ["Jet_ETA", "boson_jet_ETA", jetetabins],
    #["dPhi",  dPhi.replace('<A>', 'boson').replace('<B>', 'boson_jet'), 6, 0, TMath.Pi()],
    #["dR",  'min('+deltaR.replace('<A>','muminus').replace('<B>', 'boson_jet')+','+deltaR.replace('<A>','muplus').replace('<B>', 'boson_jet')+')', 500, 0, 10],
#    ["dRb",  'min('+deltaR2.replace('<A>','muminus').replace('<B>', 'boson_jet')+','+deltaR2.replace('<A>','muplus').replace('<B>', 'boson_jet')+')', 500, 0, 10]
    ]

mcjetvars = [
    ["Jet_PT", "muminus_truejet_PT/1000", ptbins],
    ["Jet_ETA", "muminus_truejet_ETA", jetetabins],
    ["ETA"    , "muminus_ETA", etabins]
    ]
mcjetvars_zmumu = [
    ["Jet_PT", "boson_truejet_PT/1000", ptbins],
    ["Jet_ETA", "boson_truejet_ETA", jetetabins],
    ["Y"    , "boson_Y", etabins],
    ["dPhi",  dPhi.replace('<A>', 'boson').replace('<B>', 'muminus_truejet'), 6, 0, TMath.Pi()],
    ]

variables = [
    ["PT" ,"muminus_PT" ,25, 20000 , 70000 ],
    #["IPUbs"  ,"muminus_ipubs" ,50, 0 , 0.2],
    #["Iso", "muminus_cpt_0.50", 100, 0 , 20000],
    #["TotIso"       , "muminus_cpt_0.50 + muminus_npt_0.50"     , 60 ,     0  , 30000],
    #["IsoAsymm", "muminus_PT/sqrt((muminus_PX + muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_PY + muminus_cpy_0.50 + muminus_npy_0.50)^2)", 51 , 0 , 1.02 ],
    #["JetIso", "(muminus_PT/muminus_sigjet_PT) * (muminus_sigjet_jec + (muminus_sigjet_ndauts==0)*1000)", 21, 0, 1.05],
    ["JetPtIso", "(muminus_PT/muminus_sigjet_PT)", 21, 0, 1.05],
    ["JetEIso", "(muminus_PE/muminus_sigjet_PE)", 21, 0, 1.05],
    #["VCIso", "(muminus_PT/sqrt((muminus_cpx_0.50 + muminus_PX)^2 + (muminus_cpy_0.50 + muminus_PY)^2))", 21, 0, 1.05],
    #["PVs", "nPVs", 6, -0.5 , 5.5],
    ["ETA",     "muminus_ETA", etabins],
    ["ETA8",    "muminus_ETA", eta8bins],
    ["ETA_full",     "muminus_ETA", 100, 2, 4.5],
    #["MuJet_PT", "muminus_sigjet_PT / (muminus_sigjet_jec + (muminus_sigjet_ndauts==0)*1000)", 40,20000,100000]
    ["MuJet_PT", "muminus_sigjet_PT", 40,20000,100000]
    ]
zvars = [
    ["ETA_plus",  "muplus_ETA", eta8bins],
    ["ETA_minus", "muminus_ETA", eta8bins],
    ["PHI_plus" ,  "muplus_PHI"  , 12, -TMath.Pi(), TMath.Pi()],
    ["PHI_minus",  "muminus_PHI" , 12, -TMath.Pi(), TMath.Pi()],
    ["PT" , "boson_PT" ,10, 0 , 100000 ],
    ["Y",   "boson_Y", etabins],
    ["M",   "boson_M/1000", 100, 60, 120],
    ]


spdhits = "nSPDHits - ((runNumber > 128491 && runNumber < 131235)*8) - ((runNumber >131234)*40)"

evtvars = [
    ['SPDHits', spdhits, 120, 0, 1200]
]
difvars = [
    ["DIF_PT" ,"dif_mu_pt" ,25, 20000 , 70000 ],
    ["DIF_JetIso", "(dif_mu_pt/sqrt((muminus_sigjet_PX - muminus_PX + dif_mu_px)^2 + (muminus_sigjet_PY - muminus_sigjet_PY + dif_mu_py)^2))", 21, 0, 1.05]
    ]

vars2d = [
    ["ETA"    , "JetIso"],
#    ["PT"     , "JetIso"],
    ["Jet_ETA", "JetIso"],
    ["Jet_PT" , "JetIso"],
    ["MuJet_PT" , "JetIso"],
    ["ETA8"    , "ETA"],
    ["ETA8"    , "Jet_PT"],
    ["ETA8"    , "Jet_ETA"],
    ["Jet_PT"    , "MuJet_PT"],
#    ["PT"     , "VCIso"],
#    ["Jet_ETA", "VCIso"],
#    ["Jet_PT" , "VCIso"],
#    ["ETA"    , "PT"    ],
#    ["Jet_ETA", "PT"    ],
#    ["Jet_PT" , "PT"    ],
#    ["MJet_PT" , "JetIso"]
    ]
vars3d = [
    ['ETA_plus', 'ETA_minus', 'Jet_PT'],
    ['ETA_plus', 'ETA_minus', 'Y'],
    ['ETA_plus', 'ETA_minus', 'Jet_ETA'],
    ['ETA_plus', 'ETA_minus', 'dPhi']
]

plusvariables = copy.deepcopy(variables)
for v in plusvariables:
    v[1] = v[1].replace('minus','plus')
plusjetvars = copy.deepcopy(jetvars)
for v in plusjetvars:
    v[1] = v[1].replace('minus','plus')
zmumujetvars = copy.deepcopy(jetvars)
for v in zmumujetvars:
    v[1] = v[1].replace('muminus','boson')

#add some dif variables for tis
#dif_mu_f = TFile("/user2/sfarry/WJet/tuples/WMuJet_TIS.MU.2012.dif.root")
#dif_md_f = TFile("/user2/sfarry/WJet/tuples/WMuJet_TIS.MD.2012.dif.root")
#dif_mu_t = dif_mu_f.Get("tree")
#dif_md_t = dif_md_f.Get("tree")
#wmuj_tis.MUt.AddFriend(dif_mu_t)
#wmuj_tis.MDt.AddFriend(dif_md_t)

#add some dif variables for mb
#mbdif_mu_f = TFile("/user2/sfarry/WJet/tuples/WMuJet_MinBias.MU.2012.dif.root")
#mbdif_md_f = TFile("/user2/sfarry/WJet/tuples/WMuJet_MinBias.MD.2012.dif.root")
#mbdif_mu_t = dif_mu_f.Get("tree")
#mbdif_md_t = dif_md_f.Get("tree")
#wmuj_mb.MUt.AddFriend(mbdif_mu_t)
#wmuj_mb.MDt.AddFriend(mbdif_md_t)

'''
#zmumu will be given by a scale factor between data and MC - use jet sample
nzmumu_data = zmumudatat.GetEntries((selcut_zmumu_p + ptj20).GetTitle()) + zmumudatat.GetEntries((selcut_zmumu_m + ptj20).GetTitle())
nzmumu_mc   = zmumujetmct.GetEntries((selcut_zmumu_p + ptj20).GetTitle()) + zmumujetmct.GetEntries((selcut_zmumu_m + ptj20).GetTitle())

#any correction needed - possibly for efficiency difference between single muon
zmumu_datamc_corr = 1.0
zmumu_datamc_sf   = (float(nzmumu_data) / nzmumu_mc) * zmumu_datamc_corr

nzmup_mc = zmujetmct.GetEntries((selcut + ptj20 + plus).GetTitle())
nzmum_mc = zmujetmct.GetEntries((selcut + ptj20 + minus).GetTitle())
nwmup_mc = wmujt.GetEntries((selcut + ptj20 + plus).GetTitle())
nwmum_mc = wmujt.GetEntries((selcut + ptj20 + minus).GetTitle())
nzmup = nzmup_mc * zmumu_datamc_sf
nzmum = nzmum_mc * zmumu_datamc_sf


#w->tau and z->tautau then calculated as a fraction of z->mumu (inclusive) - separately for plus and minus
Nzmup_incl     = zmumut.GetEntries((selcut_nojet + plus).GetTitle())
Nwtaup_incl    = wtaut.GetEntries((selcut_nojet + plus).GetTitle())
Nztautaup_incl = ztautaut.GetEntries((selcut_nojet + plus).GetTitle())
Nzmum_incl     = zmumut.GetEntries((selcut_nojet + minus).GetTitle())
Nwtaum_incl    = wtaut.GetEntries((selcut_nojet + minus).GetTitle())
Nztautaum_incl = ztautaut.GetEntries((selcut_nojet + minus).GetTitle())

#wtau and ztautau as a fraction of zmumu
wtaup_frac    = (float(Nwtaup_incl) / Nzmup_incl * (zmumumcLumi / wtauLumi))
ztautaup_frac = (float(Nztautaup_incl) / Nzmup_incl * (zmumumcLumi / wtauLumi))
wtaum_frac    = (float(Nwtaum_incl) / Nzmum_incl * (zmumumcLumi / wtauLumi))
ztautaum_frac = (float(Nztautaum_incl) / Nzmum_incl * (zmumumcLumi / wtauLumi))




#deal with top and WW later
'''
