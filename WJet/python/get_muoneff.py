from Jawa import *
from ROOT import TCut, TH1F, TGraphAsymmErrors, TFile

def get_nz(h):
    o1 = []
    o2 = []
    o3 = []
    for i in range(h.GetNbinsX()):
        o1 += [h.GetBinContent(i+1)] 
        o2 += [h.GetBinContent(i+1) * 0.991]
        o3 += [h.GetBinContent(i+1) * 0.991 * 0.003]
    return [o1]

trgf = TFile("/user2/sfarry/Efficiencies/python/MuonWTrigger2012.root")
trg  = trgf.Get("ETA8/EfficiencyGraph")
id_statf  = TFile("/user2/sfarry/Efficiencies/python/MuonWID2012_staterr.root")
id_stat   = id_statf.Get("ETA8/EfficiencyGraph")
id_systf  = TFile("/user2/sfarry/Efficiencies/python/MuonWID2012_systerr.root")
id_syst   = id_systf.Get("ETA8/EfficiencyGraph")

trkf_tp = TFile("/user2/sfarry/Efficiencies/python/MuonWTrackingCorr2012_tp.root")
trk_tp  = trkf_tp.Get("ETA8/EfficiencyGraph")
trkf_tm = TFile("/user2/sfarry/Efficiencies/python/MuonWTrackingCorr2012_tm.root")
trk_tm  = trkf_tm.Get("ETA8/EfficiencyGraph")
trkf_bstat = TFile("/user2/sfarry/Efficiencies/python/MuonWTrackingCorr2012_bstat.root")
trk_bstat  = trkf_bstat.Get("ETA8/EfficiencyGraph")
trkf_bsyst = TFile("/user2/sfarry/Efficiencies/python/MuonWTrackingCorr2012_bstat.root")
trk_bsyst  = trkf_bstat.Get("ETA8/EfficiencyGraph")



#z_trg_eff  = geteff("ztrgc" , z.Get3DVar('etap', 'etam', 'y').GetHist(), trg, 0, "a + b - a*b")
#z_id_eff   = geteff("zidc"  , z.Get3DVar('etap', 'etam', 'y').GetHist(), id )
#z_trk_eff  = geteff("ztrkc" , z.Get3DVar('etap', 'etam', 'y').GetHist(), trk )
'''
g = TFile("/user2/sfarry/WJet/python/wmupj.root")

wp_trg_eff_eta  = geteff("wptrgc" , g.Get('w/ETA8_ETA'), trg, 0, "a")
wp_id_eff_eta   = geteff("wpidc"  , g.Get('w/ETA8_ETA'), id_stat )
wp_trk_eff_eta  = geteff("wptrkc" , g.Get('w/ETA8_ETA'), trk_tp )

wp_trg_mat_eta  = getEffErrMatrix("wptrg" , g.Get('w/ETA8_ETA'), trg, "a")
wp_id_mat_eta   = []
wp_id_mat_eta   += getEffErrMatrix("wpid1"  , g.Get('w/ETA8_ETA'), id_stat )       #uncorrelated
wp_id_mat_eta   += getEffErrMatrix("wpid2"  , g.Get('w/ETA8_ETA'), id_syst, "a", True ) #correlated

wp_trk_mat_eta = []
wp_trk_mat_eta  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_ETA'), trk_tp )
wp_trk_mat_eta  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_ETA'), trk_bsyst, "a", True )
wp_trk_mat_eta  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_ETA'), trk_bstat )
wp_trk_mat_eta  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_ETA'), trk_tm )



wp_trg_eff_etaj  = geteff("wptrgc" , g.Get('w/ETA8_Jet_ETA'), trg, 0, "a")
wp_id_eff_etaj   = geteff("wpidc"  , g.Get('w/ETA8_Jet_ETA'), id_stat )
wp_trk_eff_etaj  = geteff("wptrkc" , g.Get('w/ETA8_Jet_ETA'), trk_tp )

wp_trg_mat_etaj  = getEffErrMatrix("wptrg" , g.Get('w/ETA8_Jet_ETA'), trg, "a")
wp_id_mat_etaj   = []
wp_id_mat_etaj   += getEffErrMatrix("wpid1"  , g.Get('w/ETA8_Jet_ETA'), id_stat )       #uncorrelated
wp_id_mat_etaj   += getEffErrMatrix("wpid2"  , g.Get('w/ETA8_Jet_ETA'), id_syst, "a", True ) #correlated
wp_trk_mat_etaj = []
wp_trk_mat_etaj  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_Jet_ETA'), trk_tp )
wp_trk_mat_etaj  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_Jet_ETA'), trk_bsyst, "a", True )
wp_trk_mat_etaj  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_Jet_ETA'), trk_bstat )
wp_trk_mat_etaj  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_Jet_ETA'), trk_tm )



wp_trg_eff_ptj  = geteff("wptrgc" , g.Get('w/ETA8_Jet_PT'), trg, 0, "a")
wp_id_eff_ptj   = geteff("wpidc"  , g.Get('w/ETA8_Jet_PT'), id_stat )
wp_trk_eff_ptj  = geteff("wptrkc" , g.Get('w/ETA8_Jet_PT'), trk_tp )

wp_trg_mat_ptj  = getEffErrMatrix("wptrg" , g.Get('w/ETA8_Jet_PT'), trg, "a")
wp_id_mat_ptj   = []
wp_id_mat_ptj   += getEffErrMatrix("wpid1"  , g.Get('w/ETA8_Jet_PT'), id_stat )       #uncorrelated
wp_id_mat_ptj   += getEffErrMatrix("wpid2"  , g.Get('w/ETA8_Jet_PT'), id_syst, "a", True ) #correlated
wp_trk_mat_ptj = []
wp_trk_mat_ptj  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_Jet_PT'), trk_tp )
wp_trk_mat_ptj  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_Jet_PT'), trk_bsyst, "a", True )
wp_trk_mat_ptj  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_Jet_PT'), trk_bstat )
wp_trk_mat_ptj  += getEffErrMatrix("wptrk" , g.Get('w/ETA8_Jet_PT'), trk_tm )

saveMatrix("/user2/sfarry/WJet/dat/wp_trg_eta_matrix.dat" , wp_trg_mat_eta  )
saveMatrix("/user2/sfarry/WJet/dat/wp_trk_eta_matrix.dat" , wp_trk_mat_eta  )
saveMatrix("/user2/sfarry/WJet/dat/wp_id_eta_matrix.dat"  , wp_id_mat_eta   )

saveMatrix("/user2/sfarry/WJet/dat/wp_trg_etaj_matrix.dat", wp_trg_mat_etaj )
saveMatrix("/user2/sfarry/WJet/dat/wp_trk_etaj_matrix.dat", wp_trk_mat_etaj )
saveMatrix("/user2/sfarry/WJet/dat/wp_id_etaj_matrix.dat" , wp_id_mat_etaj  )

saveMatrix("/user2/sfarry/WJet/dat/wp_trg_ptj_matrix.dat" , wp_trg_mat_ptj  )
saveMatrix("/user2/sfarry/WJet/dat/wp_trk_ptj_matrix.dat" , wp_trk_mat_ptj  )
saveMatrix("/user2/sfarry/WJet/dat/wp_id_ptj_matrix.dat"  , wp_id_mat_ptj   )


saveTH1F("/user2/sfarry/WJet/dat/wp_trg_eff_eta.dat", wp_trg_eff_eta )
saveTH1F("/user2/sfarry/WJet/dat/wp_trk_eff_eta.dat", wp_trk_eff_eta )
saveTH1F("/user2/sfarry/WJet/dat/wp_id_eff_eta.dat" , wp_id_eff_eta  )

saveTH1F("/user2/sfarry/WJet/dat/wp_trg_eff_etaj.dat", wp_trg_eff_etaj )
saveTH1F("/user2/sfarry/WJet/dat/wp_trk_eff_etaj.dat", wp_trk_eff_etaj )
saveTH1F("/user2/sfarry/WJet/dat/wp_id_eff_etaj.dat" , wp_id_eff_etaj  )

saveTH1F("/user2/sfarry/WJet/dat/wp_trg_eff_ptj.dat", wp_trg_eff_ptj )
saveTH1F("/user2/sfarry/WJet/dat/wp_trk_eff_ptj.dat", wp_trk_eff_ptj )
saveTH1F("/user2/sfarry/WJet/dat/wp_id_eff_ptj.dat" , wp_id_eff_ptj  )
'''
i = TFile("/user2/sfarry/WJet/python/wmup_jeteff.root")
saveTGraph('/user2/sfarry/WJet/dat/wp_jet_eff_ptj.dat', i.Get("Jet_PT/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/wp_jet_eff_etaj.dat', i.Get("Jet_ETA/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/wp_jet_eff_eta.dat', i.Get("ETA/EfficiencyGraph"))
#saveTGraphErrs('/user2/sfarry/WJet/dat/wp_jet_efferrs_ptj.dat', i.Get("Jet_PT/EfficiencyGraph"))
#saveTGraphErrs('/user2/sfarry/WJet/dat/wp_jet_efferrs_etaj.dat', i.Get("Jet_ETA/EfficiencyGraph"))
#saveTGraphErrs('/user2/sfarry/WJet/dat/wp_jet_efferrs_eta.dat', i.Get("ETA/EfficiencyGraph"))


################################
# minus
###############################
h = TFile("/user2/sfarry/WJet/python/wmumj.root")
'''
wm_trg_eff_eta  = geteff("wmtrgc" , h.Get('w/ETA8_ETA'), trg, 0, "a")
wm_id_eff_eta   = geteff("wmidc"  , h.Get('w/ETA8_ETA'), id_stat )
wm_trk_eff_eta  = geteff("wmtrkc" , h.Get('w/ETA8_ETA'), trk_tp )

wm_trg_mat_eta  = getEffErrMatrix("wmtrg" , h.Get('w/ETA8_ETA'), trg, "a")
wm_id_mat_eta   = []
wm_id_mat_eta   += getEffErrMatrix("wmid1"  , h.Get('w/ETA8_ETA'), id_stat )       #uncorrelated
wm_id_mat_eta   += getEffErrMatrix("wmid2"  , h.Get('w/ETA8_ETA'), id_syst, "a", True ) #correlated

wm_trk_mat_eta = []
wm_trk_mat_eta  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_ETA'), trk_tp )
wm_trk_mat_eta  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_ETA'), trk_bsyst, "a", True )
wm_trk_mat_eta  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_ETA'), trk_bstat )
wm_trk_mat_eta  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_ETA'), trk_tm )



wm_trg_eff_etaj  = geteff("wmtrgc" , h.Get('w/ETA8_Jet_ETA'), trg, 0, "a")
wm_id_eff_etaj   = geteff("wmidc"  , h.Get('w/ETA8_Jet_ETA'), id_stat )
wm_trk_eff_etaj  = geteff("wmtrkc" , h.Get('w/ETA8_Jet_ETA'), trk_tp )

wm_trg_mat_etaj  = getEffErrMatrix("wmtrg" , h.Get('w/ETA8_Jet_ETA'), trg, "a")
wm_id_mat_etaj   = []
wm_id_mat_etaj   += getEffErrMatrix("wmid1"  , h.Get('w/ETA8_Jet_ETA'), id_stat )       #uncorrelated
wm_id_mat_etaj   += getEffErrMatrix("wmid2"  , h.Get('w/ETA8_Jet_ETA'), id_syst, "a", True ) #correlated
wm_trk_mat_etaj = []
wm_trk_mat_etaj  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_Jet_ETA'), trk_tp )
wm_trk_mat_etaj  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_Jet_ETA'), trk_bsyst, "a", True )
wm_trk_mat_etaj  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_Jet_ETA'), trk_bstat )
wm_trk_mat_etaj  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_Jet_ETA'), trk_tm )



wm_trg_eff_ptj  = geteff("wmtrgc" , h.Get('w/ETA8_Jet_PT'), trg, 0, "a")
wm_id_eff_ptj   = geteff("wmidc"  , h.Get('w/ETA8_Jet_PT'), id_stat )
wm_trk_eff_ptj  = geteff("wmtrkc" , h.Get('w/ETA8_Jet_PT'), trk_tp )

wm_trg_mat_ptj  = getEffErrMatrix("wmtrg" , h.Get('w/ETA8_Jet_PT'), trg, "a")
wm_id_mat_ptj   = []
wm_id_mat_ptj   += getEffErrMatrix("wmid1"  , h.Get('w/ETA8_Jet_PT'), id_stat )       #uncorrelated
wm_id_mat_ptj   += getEffErrMatrix("wmid2"  , h.Get('w/ETA8_Jet_PT'), id_syst, "a", True ) #correlated
wm_trk_mat_ptj = []
wm_trk_mat_ptj  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_Jet_PT'), trk_tp )
wm_trk_mat_ptj  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_Jet_PT'), trk_bsyst, "a", True )
wm_trk_mat_ptj  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_Jet_PT'), trk_bstat )
wm_trk_mat_ptj  += getEffErrMatrix("wmtrk" , h.Get('w/ETA8_Jet_PT'), trk_tm )

saveMatrix("/user2/sfarry/WJet/dat/wm_trg_eta_matrix.dat" , wm_trg_mat_eta  )
saveMatrix("/user2/sfarry/WJet/dat/wm_trk_eta_matrix.dat" , wm_trk_mat_eta  )
saveMatrix("/user2/sfarry/WJet/dat/wm_id_eta_matrix.dat"  , wm_id_mat_eta   )

saveMatrix("/user2/sfarry/WJet/dat/wm_trg_etaj_matrix.dat", wm_trg_mat_etaj )
saveMatrix("/user2/sfarry/WJet/dat/wm_trk_etaj_matrix.dat", wm_trk_mat_etaj )
saveMatrix("/user2/sfarry/WJet/dat/wm_id_etaj_matrix.dat" , wm_id_mat_etaj  )

saveMatrix("/user2/sfarry/WJet/dat/wm_trg_ptj_matrix.dat" , wm_trg_mat_ptj  )
saveMatrix("/user2/sfarry/WJet/dat/wm_trk_ptj_matrix.dat" , wm_trk_mat_ptj  )
saveMatrix("/user2/sfarry/WJet/dat/wm_id_ptj_matrix.dat"  , wm_id_mat_ptj   )


saveTH1F("/user2/sfarry/WJet/dat/wm_trg_eff_eta.dat", wm_trg_eff_eta )
saveTH1F("/user2/sfarry/WJet/dat/wm_trk_eff_eta.dat", wm_trk_eff_eta )
saveTH1F("/user2/sfarry/WJet/dat/wm_id_eff_eta.dat" , wm_id_eff_eta  )

saveTH1F("/user2/sfarry/WJet/dat/wm_trg_eff_etaj.dat", wm_trg_eff_etaj )
saveTH1F("/user2/sfarry/WJet/dat/wm_trk_eff_etaj.dat", wm_trk_eff_etaj )
saveTH1F("/user2/sfarry/WJet/dat/wm_id_eff_etaj.dat" , wm_id_eff_etaj  )

saveTH1F("/user2/sfarry/WJet/dat/wm_trg_eff_ptj.dat", wm_trg_eff_ptj )
saveTH1F("/user2/sfarry/WJet/dat/wm_trk_eff_ptj.dat", wm_trk_eff_ptj )
saveTH1F("/user2/sfarry/WJet/dat/wm_id_eff_ptj.dat" , wm_id_eff_ptj  )
'''
j = TFile("/user2/sfarry/WJet/python/wmum_jeteff.root")
saveTGraph('/user2/sfarry/WJet/dat/wm_jet_eff_ptj.dat', j.Get("Jet_PT/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/wm_jet_eff_etaj.dat', j.Get("Jet_ETA/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/wm_jet_eff_eta.dat', j.Get("ETA/EfficiencyGraph"))
#saveTGraphErrs('wm_jet_efferrs_ptj.dat', j.Get("Jet_PT/EfficiencyGraph"))
#saveTGraphErrs('wm_jet_efferrs_etaj.dat', j.Get("Jet_ETA/EfficiencyGraph"))
#saveTGraphErrs('wm_jet_efferrs_eta.dat', j.Get("ETA/EfficiencyGraph"))

'''
################################
# z -> mumu
###############################
k = TFile("/user2/sfarry/WJet/python/zmumuj.root")

zmumu_trg_eff_y  = geteff("zmumutrgc" , k.Get('Data/ETA_plus_ETA_minus_Y'), trg, 0, "a + b - a*b")
zmumu_id_eff_y   = geteff("zmumuidc"  , k.Get('Data/ETA_plus_ETA_minus_Y'), id_stat )
zmumu_trk_eff_y  = geteff("zmumutrkc" , k.Get('Data/ETA_plus_ETA_minus_Y'), trk_tp )

zmumu_trg_mat_y  = getEffErrMatrix("zmumutrg" , k.Get('Data/ETA_plus_ETA_minus_Y'), trg, "a + b - a*b")
zmumu_id_mat_y   = []
zmumu_id_mat_y   += getEffErrMatrix("zmumuid1"  , k.Get('Data/ETA_plus_ETA_minus_Y'), id_stat )       #uncorrelated
zmumu_id_mat_y   += getEffErrMatrix("zmumuid2"  , k.Get('Data/ETA_plus_ETA_minus_Y'), id_syst, "a*b", True ) #correlated

zmumu_trk_mat_y = []
zmumu_trk_mat_y  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Y'), trk_tp )
zmumu_trk_mat_y  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Y'), trk_bsyst, "a*b", True )
zmumu_trk_mat_y  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Y'), trk_bstat )
zmumu_trk_mat_y  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Y'), trk_tm )



zmumu_trg_eff_etaj  = geteff("zmumutrgc" , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), trg, 0, "a + b - a*b")
zmumu_id_eff_etaj   = geteff("zmumuidc"  , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), id_stat )
zmumu_trk_eff_etaj  = geteff("zmumutrkc" , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), trk_tp )

zmumu_trg_mat_etaj  = getEffErrMatrix("zmumutrg" , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), trg, "a + b - a*b")
zmumu_id_mat_etaj   = []
zmumu_id_mat_etaj   += getEffErrMatrix("zmumuid1"  , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), id_stat )       #uncorrelated
zmumu_id_mat_etaj   += getEffErrMatrix("zmumuid2"  , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), id_syst, "a*b", True ) #correlated
zmumu_trk_mat_etaj = []
zmumu_trk_mat_etaj  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), trk_tp )
zmumu_trk_mat_etaj  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), trk_bsyst, "a*b", True )
zmumu_trk_mat_etaj  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), trk_bstat )
zmumu_trk_mat_etaj  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Jet_ETA'), trk_tm )



zmumu_trg_eff_ptj  = geteff("zmumutrgc" , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), trg, 0, "a + b - a*b")
zmumu_id_eff_ptj   = geteff("zmumuidc"  , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), id_stat )
zmumu_trk_eff_ptj  = geteff("zmumutrkc" , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), trk_tp )

zmumu_trg_mat_ptj  = getEffErrMatrix("zmumutrg" , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), trg, "a + b - a*b")
zmumu_id_mat_ptj   = []
zmumu_id_mat_ptj   += getEffErrMatrix("zmumuid1"  , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), id_stat )       #uncorrelated
zmumu_id_mat_ptj   += getEffErrMatrix("zmumuid2"  , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), id_syst, "a*b", True ) #correlated
zmumu_trk_mat_ptj = []
zmumu_trk_mat_ptj  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), trk_tp )
zmumu_trk_mat_ptj  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), trk_bsyst, "a*b", True )
zmumu_trk_mat_ptj  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), trk_bstat )
zmumu_trk_mat_ptj  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_Jet_PT'), trk_tm )

zmumu_trg_eff_dphi  = geteff("zmumutrgc" , k.Get('Data/ETA_plus_ETA_minus_dPhi'), trg, 0, "a + b - a*b")
zmumu_id_eff_dphi   = geteff("zmumuidc"  , k.Get('Data/ETA_plus_ETA_minus_dPhi'), id_stat )
zmumu_trk_eff_dphi  = geteff("zmumutrkc" , k.Get('Data/ETA_plus_ETA_minus_dPhi'), trk_tp )

zmumu_trg_mat_dphi  = getEffErrMatrix("zmumutrg" , k.Get('Data/ETA_plus_ETA_minus_dPhi'), trg, "a + b - a*b")
zmumu_id_mat_dphi   = []
zmumu_id_mat_dphi   += getEffErrMatrix("zmumuid1"  , k.Get('Data/ETA_plus_ETA_minus_dPhi'), id_stat )       #uncorrelated
zmumu_id_mat_dphi   += getEffErrMatrix("zmumuid2"  , k.Get('Data/ETA_plus_ETA_minus_dPhi'), id_syst, "a*b", True ) #correlated
zmumu_trk_mat_dphi = []
zmumu_trk_mat_dphi  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_dPhi'), trk_tp )
zmumu_trk_mat_dphi  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_dPhi'), trk_bsyst, "a*b", True )
zmumu_trk_mat_dphi  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_dPhi'), trk_bstat )
zmumu_trk_mat_dphi  += getEffErrMatrix("zmumutrk" , k.Get('Data/ETA_plus_ETA_minus_dPhi'), trk_tm )

saveMatrix("/user2/sfarry/WJet/dat/zmumu_trg_y_matrix.dat" , zmumu_trg_mat_y  )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_trk_y_matrix.dat" , zmumu_trk_mat_y  )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_id_y_matrix.dat"  , zmumu_id_mat_y   )

saveMatrix("/user2/sfarry/WJet/dat/zmumu_trg_etaj_matrix.dat", zmumu_trg_mat_etaj )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_trk_etaj_matrix.dat", zmumu_trk_mat_etaj )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_id_etaj_matrix.dat" , zmumu_id_mat_etaj  )

saveMatrix("/user2/sfarry/WJet/dat/zmumu_trg_ptj_matrix.dat" , zmumu_trg_mat_ptj  )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_trk_ptj_matrix.dat" , zmumu_trk_mat_ptj  )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_id_ptj_matrix.dat"  , zmumu_id_mat_ptj   )

saveMatrix("/user2/sfarry/WJet/dat/zmumu_trg_dphi_matrix.dat" , zmumu_trg_mat_dphi  )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_trk_dphi_matrix.dat" , zmumu_trk_mat_dphi  )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_id_dphi_matrix.dat"  , zmumu_id_mat_dphi   )


saveMatrix("/user2/sfarry/WJet/dat/zmumu_n_y.dat"   , get_nz(k.Get("Data/Y")) )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_n_etaj.dat", get_nz(k.Get("Data/Jet_ETA")) )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_n_ptj.dat" , get_nz(k.Get("Data/Jet_PT"))  )
saveMatrix("/user2/sfarry/WJet/dat/zmumu_n_dphi.dat" , get_nz(k.Get("Data/dPhi"))  )

saveTH1F("/user2/sfarry/WJet/dat/zmumu_trg_eff_y.dat", zmumu_trg_eff_y )
saveTH1F("/user2/sfarry/WJet/dat/zmumu_trk_eff_y.dat", zmumu_trk_eff_y )
saveTH1F("/user2/sfarry/WJet/dat/zmumu_id_eff_y.dat" , zmumu_id_eff_y  )

saveTH1F("/user2/sfarry/WJet/dat/zmumu_trg_eff_etaj.dat", zmumu_trg_eff_etaj )
saveTH1F("/user2/sfarry/WJet/dat/zmumu_trk_eff_etaj.dat", zmumu_trk_eff_etaj )
saveTH1F("/user2/sfarry/WJet/dat/zmumu_id_eff_etaj.dat" , zmumu_id_eff_etaj  )

saveTH1F("/user2/sfarry/WJet/dat/zmumu_trg_eff_ptj.dat", zmumu_trg_eff_ptj )
saveTH1F("/user2/sfarry/WJet/dat/zmumu_trk_eff_ptj.dat", zmumu_trk_eff_ptj )
saveTH1F("/user2/sfarry/WJet/dat/zmumu_id_eff_ptj.dat" , zmumu_id_eff_ptj  )

saveTH1F("/user2/sfarry/WJet/dat/zmumu_trg_eff_dphi.dat", zmumu_trg_eff_dphi )
saveTH1F("/user2/sfarry/WJet/dat/zmumu_trk_eff_dphi.dat", zmumu_trk_eff_dphi )
saveTH1F("/user2/sfarry/WJet/dat/zmumu_id_eff_dphi.dat" , zmumu_id_eff_dphi  )
'''

l = TFile("/user2/sfarry/WJet/python/zmumu_jeteff.root")
saveTGraph('/user2/sfarry/WJet/dat/zmumu_jet_eff_ptj.dat', l.Get("Jet_PT/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/zmumu_jet_eff_etaj.dat', l.Get("Jet_ETA/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/zmumu_jet_eff_y.dat', l.Get("Y/EfficiencyGraph"))
saveTGraph('/user2/sfarry/WJet/dat/zmumu_jet_eff_dphi.dat', l.Get("dPhi/EfficiencyGraph"))
#saveTGraphErrs('/user2/sfarry/WJet/dat/zmumu_jet_efferrs_ptj.dat', l.Get("Jet_PT/EfficiencyGraph"))
#saveTGraphErrs('/user2/sfarry/WJet/dat/zmumu_jet_efferrs_etaj.dat', l.Get("Jet_ETA/EfficiencyGraph"))
#saveTGraphErrs('/user2/sfarry/WJet/dat/zmumu_jet_efferrs_y.dat', l.Get("Y/EfficiencyGraph"))
#saveTGraphErrs('/user2/sfarry/WJet/dat/zmumu_jet_efferrs_dphi.dat', l.Get("dPhi/EfficiencyGraph"))
