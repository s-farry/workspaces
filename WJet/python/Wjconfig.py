from ROOT import TFile, TTree, TCut
from Utils import GetWeightHist, GetMCLumi
import copy

#W->mujet MC2012
wmujf     = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.Wmunujet.MC2012.root")
wmujt     = wmujf.Get("WTuple/DecayTree")
wmujmvf     = TFile("/user2/sfarry/WTau/tuples/WMu.Wmunujet.MC2012.MVA.root")
wmujmvt     = wmujmvf.Get("tree")
wmujt.AddFriend(wmujmvt)

#Z->mumu(jet) Data 2012
zmumuf     = TFile("/hepstore/sfarry/ZMuMu.2012.root")
zmumumvf   = TFile("/hepstore/sfarry/ZMuMu.2012.MVA.root")
zmumudatat = zmumuf.Get("ZMuMu/DecayTree")
zmumudatat.AddFriend(zmumumvf.Get("tree"))

#Get pt reweighting factors

zmumu_data2012f = TFile("zmumu_data2012.root")
zmumu_data2012pt  = zmumu_data2012f.Get("PT")

wmupj_mc2012f = TFile("wmupj_mc2012.root")
wmumj_mc2012f = TFile("wmumj_mc2012.root")

wmupj_mc2012pt = wmupj_mc2012f.Get("PT")
wmumj_mc2012pt = wmumj_mc2012f.Get("PT")

#zmupj_mc2012f = TFile("zmupj_mc2012.root")
#zmumj_mc2012f = TFile("zmumj_mc2012.root")

#zmupj_mc2012 = zmupj_mc2012f.Get("PT")
#zmumj_mc2012 = zmumj_mc2012f.Get("PT")

wmupj_ptrw = GetWeightHist("wmupj_ptrw", wmupj_mc2012pt, zmumu_data2012pt)
wmumj_ptrw = GetWeightHist("wmumj_ptrw", wmumj_mc2012pt, zmumu_data2012pt)


qcdip_mj_data2012f    = TFile("qcdip_mj_data2012.root")
qcdip_pj_data2012f    = TFile("qcdip_pj_data2012.root")
qcdunbal_mj_data2012f = TFile("qcdunbal_mj_data2012.root")
qcdunbal_pj_data2012f = TFile("qcdunbal_pj_data2012.root")
qcdantiiso_mj_data2012f = TFile("qcdantiiso_mj_data2012.root")
qcdantiiso_pj_data2012f = TFile("qcdantiiso_pj_data2012.root")

qcd_mj_rw = GetWeightHist("qcd_mj_rw", qcdantiiso_mj_data2012f.Get("MuCone_PT"), qcdunbal_mj_data2012f.Get("MuCone_PT"))
qcd_pj_rw = GetWeightHist("qcd_pj_rw", qcdantiiso_pj_data2012f.Get("MuCone_PT"), qcdunbal_pj_data2012f.Get("MuCone_PT"))


#zmupj_ptrw = GetWeightHist("zmupj_ptrw", zmupj_mc2012, zmumu_data2012)
#zmumj_ptrw = GetWeightHist("zmumj_ptrw", zmumj_mc2012, zmumu_data2012)


#data
dataf   = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.2012.root")
datat   = dataf.Get("WTuple/DecayTree")
datamvf = TFile("/user2/sfarry/WTau/tuples/WMu.2012.MVA.root")
datamvt = datamvf.Get("tree")
datat.AddFriend(datamvt)

#minbias
mbf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.MinBias2012.root")
mbt = mbf.Get("WTuple/DecayTree")
mbmvf  = TFile("/user2/sfarry/WTau/tuples/WMu.MinBias2012.MVA.root")
mbmvt  = mbmvf.Get("tree")
mbt.AddFriend(mbmvt)

#minbias 2011
mb11f = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.MinBias2011.root")
mb11t = mb11f.Get("WTuple/DecayTree")
#mb11mvf  = TFile("/user2/sfarry/WTau/tuples/WMu.MinBias2011.MVA.root")
#mb11mvt  = mbmvf.Get("tree")
#mb11t.AddFriend(mbmvt)

#tis
tisf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.TIS2012.root")
tist = tisf.Get("WTuple/DecayTree")
tismvf  = TFile("/user2/sfarry/WTau/tuples/WMu.TIS2012.MVA.root")
tismvt  = tismvf.Get("tree")
tist.AddFriend(tismvt)


#zmumu data

zmumudataf     = TFile("/hepstore/sfarry/ZMuMu.2012.root")
zmumudatat = zmumudataf.Get("ZMuMu/DecayTree")

#W->mu MC2012
wmuf     = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.Wmunu.MC2012.root")
wmut     = wmuf.Get("WTuple/DecayTree")
wmumvf     = TFile("/user2/sfarry/WTau/tuples/WMu.Wmunu.MC2012.MVA.root")
wmumvt     = wmumvf.Get("tree")
wmut.AddFriend(wmumvt)

#Z->mumu (mu) MC2012
zmumuf   = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.Zg_mumu.MC2012.root")
zmumut   = zmumuf.Get("WTuple/DecayTree")
zmumumvf   = TFile("/user2/sfarry/WTau/tuples/WMu.Zg_mumu.MC2012.MVA.root")
zmumumvt   = zmumumvf.Get("tree")
zmumut.AddFriend(zmumumvt)

#Z->mumu (mumu) MC2012
zmumumcf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/ZMuMu.Zg_mumu.MC2012.root")
zmumumct = zmumumcf.Get("TupleOS/DecayTree")

#Z->mumujet (mumu) MC2012
zmumujetmcf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/ZMuMu.Z_mumujet17.MC2012.root")
zmumujetmct = zmumujetmcf.Get("ZMuMu/DecayTree")

#Z->mumujet (mu) MC2012
zmujetmcf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.Z_mumujetl17.MC2012.root")
zmujetmct = zmujetmcf.Get("WTuple/DecayTree")


#W->tau MC2012
wtauf    = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.Wtaumu.MC2012.root")
wtaut    = wtauf.Get("WTuple/DecayTree")
wtaumvf    = TFile("/user2/sfarry/WTau/tuples/WMu.Wtaumu.MC2012.MVA.root")
wtaumvt    = wtaumvf.Get("tree")
wtaut.AddFriend(wtaumvt)

#Z->tautau (mu) MC2012
ztautauf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.Z_tautau.MC2012.root")
ztautaut = ztautauf.Get("WTuple/DecayTree")
ztautaumvf = TFile("/user2/sfarry/WTau/tuples/WMu.Z_tautau.MC2012.MVA.root")
ztautaumvt = ztautaumvf.Get("tree")  
ztautaut.AddFriend(ztautaumvt)


#bbbar (mu) MC2012
bbbarf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.bbbar.MC2012.root")
bbbart = bbbarf.Get("WTuple/DecayTree")
bbbarmvf = TFile("/user2/sfarry/WTau/tuples/WMu.bbbar.MC2012.MVA.root")
bbbarmvt = bbbarmvf.Get("tree")
bbbart.AddFriend(bbbarmvt)

#ccbar (mu) MC2012
ccbarf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.ccbar.MC2012.root")
ccbart = ccbarf.Get("WTuple/DecayTree")
ccbarmvf = TFile("/user2/sfarry/WTau/tuples/WMu.ccbar.MC2012.MVA.root")
ccbarmvt = ccbarmvf.Get("tree")
ccbart.AddFriend(ccbarmvt)


#minbias (1 track pt > 15 GeV) MC2012
mbmcf = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/WMu.minbias_highpt.MinBiasMC2012.root")
mbmct = mbmcf.Get("WTuple/DecayTree")
mbmcmvf  = TFile("/user2/sfarry/WTau/tuples/WMu.minbias_highpt.MinBiasMC2012.MVA.root")
mbmcmvt  = mbmcmvf.Get("tree")
mbmct.AddFriend(mbmcmvt)


#mc cross-sections

mcinfo = {
    # 'Name' : [acceptance, xsec, events]
    'WMuNu'   : [0.246382           , 9.282*1000      ,  2515968 + 2526894   ], # 42311003
    'WTauNu'  : [0.134150           , 9.291*0.17*1000 ,  1072163 + 1062658   ], # 42300001
    'ZMuMu'   : [0.367744           , 0.9593*1000     ,  2035996 + 2014491   ], # 42112001
    'Ztautau' : [0.366538           , 0.8588*1000     ,  2031495  + 2015495  ],  # 42100000
    'WMuJet'  : [0.239028           , 13.17*0.1063*1000   ,  2536881 + 2531103   ], # 42311011 - sim 08e 5020694 + 5013964 for sim08g
    'ZMuMuJet': [0.327112           , 12.54*0.03*1000     ,  2527742 + 2545494   ] #42112022 - Sim 08b 
    }

#luminosities
wmuLumi     = GetMCLumi("WMuNu"  , mcinfo)
wtauLumi    = GetMCLumi("WTauNu" , mcinfo)
ztautauLumi = GetMCLumi("Ztautau", mcinfo)
zmumumcLumi = GetMCLumi("ZMuMu"  , mcinfo)
zmumujetLumi = GetMCLumi("ZMuMuJet"  , mcinfo)
wmujetLumi = GetMCLumi("WMuJet"  , mcinfo)


#cuts
pt       = TCut("muminus_PT > 20000");
ip      = TCut("muminus_ipubs < 0.05")
antiip  = TCut("muminus_ipubs > 0.1")
muonVeto = TCut("muminus_nMuonsG20GeV == 0")
plus     = TCut("muminus_ID == -13")
minus    = TCut("muminus_ID == 13")
Ep       = TCut("((muminus_CaloHcalE + muminus_CaloEcalE)/muminus_P)<0.04 && muminus_InAccHcal ==1 && muminus_InAccEcal == 1")
antiEp   = TCut("((muminus_CaloHcalE + muminus_CaloEcalE)/muminus_P)>0.1 && (muminus_CaloHcalE/muminus_P) >0.03")
trkqual  = TCut("muminus_TRACK_PCHI2 > 0.01 && sqrt(muminus_PERR2)/muminus_P < 0.1")
tthits   = TCut("muminus_TRACK_nTTHits > 0")

jet      = TCut("PFjet_mtf <0.75 && PFjet_npoint >=2 && PFjet_mpt > 1800")
svtag    = TCut("muminus_PFsigjet_svtag == 1")
nnbtag   = TCut("muminus_PFjet_nnbtag == 1")

jetDR   = TCut("sqrt(pow(muminus_ETA - PFjet_ETA,2) + pow(abs(muminus_PHI - PFjet_PHI) <TMath::Pi() ? abs(muminus_PHI - PFjet_PHI) : 2*TMath::Pi() - abs(muminus_PHI - PFjet_PHI),2)) > 2.7")
ptj10 = TCut("PFjet_PT > 10000")
ptj20 = TCut("PFjet_PT > 20000")
ptj30 = TCut("PFjet_PT > 30000")

ptmcj20 = TCut("muminus_truejet_PT > 20000")


dPhiJet = TCut("(PFjet_PHI - muminus_PHI < TMath::Pi() ? abs(PFjet_PHI - muminus_PHI) : 2*TMath::Pi() - abs(PFjet_PHI - muminus_PHI)) > 1.0")

trigger = TCut("muminus_Hlt2SingleMuonHighPTDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonDecision_TOS ==1")
zmumu = TCut("muminus_PT > 20000 && muplus_PT > 20000 && boson_M > 60000 && boson_M < 120000")

#iso
iso = TCut("(muminus_PT/sqrt((muminus_PX + muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_PY + muminus_cpy_0.50 + muminus_npy_0.50)^2)) > 0.9")
antiiso = TCut("(muminus_PT/sqrt((muminus_PX + muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_PY + muminus_cpy_0.50 + muminus_npy_0.50)^2)) < 0.85")


#zmumu
zmumu = TCut("muminus_PT > 20000 && muplus_PT > 20000 && boson_M > 60000 && boson_M < 120000")

#pt balance for jets
mupjpt     = TCut("sqrt( (PFjet_PX + muplus_PX)^2  + (PFjet_PY + muplus_PY)^2 )  > 20000")
mumjpt     = TCut("sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 ) > 20000")
antimumjpt    = TCut("sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 ) < 20000")

pt_plus      = TCut(pt.GetTitle().replace("minus","plus"))
trigger_plus = TCut(trigger.GetTitle().replace("minus","plus"))
tthits_plus  = TCut(tthits.GetTitle().replace("minus","plus"))
trkqual_plus   = TCut(trkqual.GetTitle().replace("minus","plus"))
Ep_plus      = TCut(Ep.GetTitle().replace("minus","plus"))
ip_plus      = TCut(ip.GetTitle().replace("minus","plus"))

selcut_base    = (pt + muonVeto + trigger + Ep + trkqual + tthits + ptj20)
selcut_mcbase  = (pt + muonVeto + trigger + Ep + trkqual + tthits + ptmcj20)
selcut         = selcut_base + ip + mumjpt
selcut_hiip    = selcut_base + antiip + mumjpt
selcut_ptunbal = selcut_base + antiip + antimumjpt
selcut_antiiso = selcut_base + ip + mumjpt + antiiso
selcut_zmumu_m = selcut + zmumu
selcut_zmumu_p = TCut(selcut.GetTitle().replace("minus","plus")) + zmumu

selcut_nojet = (pt + muonVeto + trigger + Ep + trkqual + tthits + ip)

#variables


jetvars = [
    ["Jet_M",  "PFjet_M", 100 , 0, 20000],
    ["Jet_PT", "PFjet_PT", 100 , 0, 100000],
    ["Jet_mpt", "PFjet_mpt", 100 , 0, 30000],
    ["Jet_mtf", "PFjet_mtf", 100 , 0, 1],
    ["Jet_npoint", "PFjet_npoint", 21 , -0.5, 20.5],
    ["Jet_mult", "PFjet_number_of_daughters", 41 , -0.5, 40.5],
    ["MuJet_M",  "sqrt( (PFjet_PE + muminus_PE)^2 - ((PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 + (PFjet_PZ + muminus_PZ)^2 ) )", 100, 0, 100000],
    ["MuJet_PT",  "sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 )", 100, 0, 100000]
    ]

variables = [
    ["PT" ,"muminus_PT" ,50, 20000 , 70000 ],
    ["MuCone_PT", "sqrt((muminus_PX + muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_PY + muminus_cpy_0.50 + muminus_npy_0.50)^2)", 80 , 20000 , 100000 ],
#    ["IP" ,"muminus_IP_OWNPV" ,150, 0 , 0.3],
#    ["IP_BDT" ,"IP_BDT" ,50, -1 , 1],
    ["IPUbs"  ,"muminus_ipubs" ,50, 0 , 0.2],
    ["Iso", "muminus_cpt_0.50", 100, 0 , 20000],
    ["TotIso"       , "muminus_cpt_0.50 + muminus_npt_0.50"     , 60 ,     0  , 30000],
#    ["TotIsoVPt"    , "sqrt((muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_cpy_0.50 + muminus_npy_0.50)^2)"  , 100 ,     0  , 20000],
    ["IsoAsymm", "muminus_PT/sqrt((muminus_PX + muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_PY + muminus_cpy_0.50 + muminus_npy_0.50)^2)", 51 , 0 , 1.02 ],
#    ["IsoA", "(muminus_PT - (muminus_cpt_0.50 + muminus_npt_0.50))/(muminus_PT + (muminus_cpt_0.50 + muminus_npt_0.50))", 202 , -1.01 , 1.01 ],
#    ["IsoR", "(muminus_cpt_0.50 + muminus_npt_0.50) / muminus_PT", 100 , 0 , 1 ],
#    ["Iso2Asymm", "(muminus_PT^2)/sqrt((muminus_PX + muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_PY + muminus_cpy_0.50 + muminus_npy_0.50)^2)", 101 , 0 , 50000 ],
#    ["IsoAsymm2", "muminus_PT/(muminus_PT + muminus_spt_0.50 + muminus_nspt_0.50)", 101 , 0 , 1.01 ],
#    ["IsoMult", "muminus_cmult_0.50", 21, -0.5, 20.5],
#    ["NeutIso", "muminus_npt_0.50", 100, 0 , 10000],
    ["PVs", "nPVs", 6, -0.5 , 5.5],
    ["ETA",     "muminus_ETA", 100, 2, 4.5]
    ]

plusvariables = copy.deepcopy(variables)
for v in plusvariables:
    v[1] = v[1].replace('minus','plus')



#calculate backgrounds
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
