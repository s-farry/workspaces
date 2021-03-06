from ROOT import TFile, TH1F, THStack, kYellow, kOrange, kViolet, kGreen, Math
from PlotTools import *
from Style import *
from Utils import Bunch

SetLHCbStyle()


data      = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev.root")
data_ss   = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev_ss.root")
data_antiiso  = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev_antiiso.root")
top       = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mc2016.root")
top_murw  = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mc2016_murw.root")
top_erw   = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mc2016_erw.root")
top_jetrw = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mc2016_jetrw.root")
wt_murw   = TFile("/user2/sfarry/workspaces/top/tuples/wt_ttbar_mc2016_murw.root")
wt_erw    = TFile("/user2/sfarry/workspaces/top/tuples/wt_ttbar_mc2016_erw.root")
wt_jetrw  = TFile("/user2/sfarry/workspaces/top/tuples/wt_ttbar_mc2016_jetrw.root")
ztautauj  = TFile("/user2/sfarry/workspaces/top/tuples/ztautauj_mc2016.root")
ztautau   = TFile("/user2/sfarry/workspaces/top/tuples/ztautau_mc2016.root")
zmumu     = TFile("/user2/sfarry/workspaces/top/tuples/zmumu_mc2016.root")
zmumuj    = TFile("/user2/sfarry/workspaces/top/tuples/zmumuj_mc2016.root")
zmumuj_data = TFile("/user2/sfarry/workspaces/top/tuples/zmumuj_data.root")

mcatnlo_predictions = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mueb_13tev_amcatnlo_predictions.root")
powheg_predictions  = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_powheg_predictions.root")
wtOttbar = powheg_predictions.Get("Wt_dr_xsec").GetVal()/mcatnlo_predictions.Get('ttbar_lp_eta_tot').GetVal()

'''
#eff1 included in reconstruction efficiency
#eff1 = TFile("/user2/sfarry/workspaces/top/tuples/jeteff.root")
eff2 = TFile("/user2/sfarry/workspaces/top/tuples/tageff.root")
eff3 = TFile("/user2/sfarry/workspaces/top/tuples/seleff.root")
eff4 = TFile("/user2/sfarry/workspaces/top/tuples/receff.root")

eff = eff2.Get('TotalEff').GetVal() * eff3.Get('TotalEff').GetVal() * eff4.Get('TotalEff').GetVal()
'''

mu_effs  = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mu_effs.root")
e_effs   = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_e_effs.root")
jet_effs = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_jet_effs.root")
sel_effs = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_sel_effs.root")

mutrkeff = mu_effs.Get('mu_trkeff_eff').GetVal()
muideff  = mu_effs.Get('mu_ideff_eff').GetVal()
mutrgeff = mu_effs.Get('mu_trgeff_eff').GetVal()
etrkeff  = e_effs.Get('e_trkeff_eff').GetVal()
eideff   = e_effs.Get('e_ideff_eff').GetVal()
jeteff   = jet_effs.Get('jet_receff_eff').GetVal()
tageff   = jet_effs.Get('jet_tageff_eff').GetVal()
seleff   = sel_effs.Get('seleff_eff').GetVal()

wt_mutrkeff = mu_effs.Get('mu_wt_trkeff_eff').GetVal()
wt_muideff  = mu_effs.Get('mu_wt_ideff_eff').GetVal()
wt_mutrgeff = mu_effs.Get('mu_wt_trgeff_eff').GetVal()
wt_etrkeff  = e_effs.Get('e_wt_trkeff_eff').GetVal()
wt_eideff   = e_effs.Get('e_wt_ideff_eff').GetVal()
wt_jeteff   = jet_effs.Get('jet_wt_receff_eff').GetVal()
wt_tageff   = jet_effs.Get('jet_wt_tageff_eff').GetVal()
#wt_seleff   = sel_effs.Get('seleff_eff').GetVal()


mutrkeff_err = mu_effs.Get('mu_trkeff_eff_err').GetVal()
muideff_err  = mu_effs.Get('mu_ideff_eff_err').GetVal()
mutrgeff_err = mu_effs.Get('mu_trgeff_eff_err').GetVal()
etrkeff_err  = e_effs.Get('e_trkeff_eff_err').GetVal()
eideff_err   = e_effs.Get('e_ideff_eff_err').GetVal()
jeteff_err   = jet_effs.Get('jet_receff_eff_err').GetVal()
tageff_err   = jet_effs.Get('jet_tageff_eff_err').GetVal()
seleff_err   = sel_effs.Get('seleff_eff_err').GetVal()

receff   = mutrkeff*muideff*etrkeff*eideff*jeteff
receff_err = receff*sqrt(pow(mutrkeff_err/mutrkeff,2) + pow(muideff_err/muideff,2) + pow(mutrgeff_err/mutrgeff,2) + pow(etrkeff_err/etrkeff,2) + pow(eideff_err/eideff,2) + pow(jeteff_err/jeteff,2))

totaleff = receff*tageff*seleff
totaleff_err = totaleff * sqrt(pow(receff_err/receff,2) + pow(tageff_err/tageff,2) + pow(seleff_err/seleff,2))

totaleff_wt = wt_mutrkeff*wt_muideff*wt_etrkeff*wt_eideff*wt_jeteff*wt_tageff*seleff

#L = 1665.865
L = 1929.528
L_err = L * 0.039

Nevts = data.Get('TotEvts').GetVal()
Nqcd  = data_ss.Get('TotEvts').GetVal()
Nzj   = zmumuj_data.Get('TotEvts').GetVal()*ztautauj.Get('NormEvts').GetVal()/zmumuj.Get('NormEvts').GetVal()
#Nwt   = (Nevts - (Nqcd + Nzj))*(wtOttbar/(1+wtOttbar))
Nwt   = powheg_predictions.Get("Wt_dr_xsec").GetVal() * L * totaleff_wt
Nsig  = Nevts - Nqcd - Nzj - Nwt
Nbkg = Nqcd + Nzj + Nwt

acc   = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_acc.root")
A     = acc.Get('acc').GetVal()
A_err = acc.Get('acc_err').GetVal()

xsec = Nsig * A / (totaleff * L )

from math import floor
#poisson uncertainties
alpha = 1 - 0.68268942
Nwt_err_lo  = Nwt - Math.gamma_quantile(alpha/2.0, floor(Nwt),1)
Nzj_err_lo  = Nzj - Math.gamma_quantile(alpha/2.0, floor(Nzj),1)
Nqcd_err_lo = Nqcd - Math.gamma_quantile(alpha/2.0, floor(Nqcd),1)
Nbkg_err_lo = Nbkg - Math.gamma_quantile(alpha/2.0, floor(Nbkg),1)
Nwt_err_hi  = Math.gamma_quantile_c(alpha/2.0, floor(Nwt)+1,1) - Nwt
Nzj_err_hi  = Math.gamma_quantile_c(alpha/2.0, floor(Nzj)+1,1) - Nzj
Nqcd_err_hi = Math.gamma_quantile_c(alpha/2.0, floor(Nqcd)+1,1) - Nqcd
Nbkg_err_hi = Math.gamma_quantile_c(alpha/2.0, floor(Nbkg)+1,1) - Nbkg

stat_err = xsec / sqrt(Nevts)
syst_err = xsec * sqrt(pow(totaleff_err / totaleff, 2) + pow(A_err / A, 2) + pow(Nbkg_err_hi/(Nevts - Nbkg),2))
lumi_err = xsec * 0.039


print "Number of selected events: %f +/- %f" %(Nevts, sqrt(Nevts))
print "Same sign background     : %f + %f - %f" %(Nqcd, Nqcd_err_hi, Nqcd_err_lo)
print "Z+jets background        : %f + %f - %f" %(Nzj, Nzj_err_hi, Nzj_err_lo)
print "Wt background            : %f + %f - %f" %(Nwt, Nwt_err_hi, Nwt_err_lo)
print "Background Events        : %f + %f - %f" %(Nbkg, Nbkg_err_hi, Nbkg_err_lo)
print "Lumi                     : %f +/- %f" %(L, L_err)
print "Efficiency               : %f +/- %f" %(totaleff, totaleff_err)
print "Cross-section            : %f +/- %f +/- %f +/- %f" % (xsec, stat_err, syst_err, lumi_err)

print "Powheg                   : %f + %f -%f + %f -%f +/- %f" % (powheg_predictions.Get('ttbar_etaj_tot').GetVal(),
                                                                  powheg_predictions.Get('ttbar_etaj_scaleerr_hi').GetVal(),
                                                                  powheg_predictions.Get('ttbar_etaj_scaleerr_lo').GetVal(),
                                                                  powheg_predictions.Get('ttbar_etaj_alphaserr_hi').GetVal(),
                                                                  powheg_predictions.Get('ttbar_etaj_alphaserr_lo').GetVal(),
                                                                  powheg_predictions.Get('ttbar_etaj_pdferr').GetVal())

print "aMCatNLO                 : %f + %f -%f + %f -%f +/- %f" % (mcatnlo_predictions.Get('ttbar_lp_eta_tot').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_lp_eta_scaleerr_hi').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_lp_eta_scaleerr_lo').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_lp_eta_alphaserr_hi').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_lp_eta_alphaserr_lo').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_lp_eta_pdferr').GetVal())


print "significance: %f +/- %f "%(xsec - mcatnlo_predictions.Get('ttbar_lp_eta_tot').GetVal(), sqrt(stat_err**2 + syst_err**2 + lumi_err**2 + mcatnlo_predictions.Get('ttbar_lp_eta_toterr_lo').GetVal()**2))

Af = mcatnlo_predictions.Get('ttbar_ty_acc_tot').GetVal()
Af_errhi = mcatnlo_predictions.Get('ttbar_ty_acc_tot_errhi').GetVal()
Af_errlo = mcatnlo_predictions.Get('ttbar_ty_acc_tot_errhi').GetVal()
print "Top Fiducial Cross-section   : %f +/- %f +/- %f +/- %f + %f - %f" % (xsec*Af, stat_err*Af, syst_err*Af,
                                                                            lumi_err*Af, xsec * Af_errhi, xsec * Af_errlo)

print "aMCatNLO                 : %f + %f -%f + %f -%f +/- %f" % (mcatnlo_predictions.Get('ttbar_t_y_tot').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_t_y_scaleerr_hi').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_t_y_scaleerr_lo').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_t_y_alphaserr_hi').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_t_y_alphaserr_lo').GetVal(),
                                                                  mcatnlo_predictions.Get('ttbar_t_y_pdferr').GetVal())
print "Powheg                   : %f + %f -%f + %f -%f +/- %f" % (powheg_predictions.Get('ttbar_ty_tot').GetVal(),
                                                                  powheg_predictions.Get('ttbar_ty_scaleerr_hi').GetVal(),
                                                                  powheg_predictions.Get('ttbar_ty_scaleerr_lo').GetVal(),
                                                                  powheg_predictions.Get('ttbar_ty_alphaserr_hi').GetVal(),
                                                                  powheg_predictions.Get('ttbar_ty_alphaserr_lo').GetVal(),
                                                                  powheg_predictions.Get('ttbar_ty_pdferr').GetVal())


print "------------------------------------"
print "       Efficiencies                 "
print "------------------------------------"
print '''
muon tracking & {mutrack:.3f} $\pm$ {mutrackerr:.3f} \\\\
electron tracking & {etrack:.3f} $\pm$ {etrackerr:.3f}\\\\
muon id & {muonid:.3f} $\pm$ {muoniderr:.3f}\\\\
electron id & {electronid:.3f}$\pm$ {electroniderr:.3f} \\\\
trigger & {trigger:.3f}$\pm$ {triggererr:.3f} \\\\
jet reconstruction & {jetrec:.3f} $\pm$ {jetrecerr:.3f}\\\\
\hline
reconstruction & {rec:.3f} $\pm$ {recerr:.3f} \\\\
\hline
selection & {sel:.3f} $\pm$ {selerr:.3f}  \\\\
\hline
jet tagging & {jettag:.3f} $\pm$ {jettagerr:.3f}\\\\
\hline
total & {total:.3f} $\pm$ {totalerr:.3f}
'''.format(mutrack = mutrkeff, etrack = etrkeff, muonid = muideff, electronid = eideff, trigger = mutrgeff, rec = receff, jetrec = jeteff, jettag = tageff, sel = seleff,total= totaleff, mutrackerr = mutrkeff_err, etrackerr = etrkeff_err,muoniderr=muideff_err, electroniderr = eideff_err, triggererr = mutrgeff_err, recerr = receff_err, jetrecerr = jeteff_err, jettagerr = tageff_err, selerr = seleff_err, totalerr = totaleff_err)
print "------------------------------------"


print "------------------------------------"
print "       Systematic Uncertainties     "
print "------------------------------------"
print '''
muon tracking & {mutrack:.1f} \\\\
electron tracking & {etrack:.1f} \\\\
muon id & {muonid:.1f}  \\\\
electron id & {electronid:.1f} \\\\
trigger & {trigger:.1f} \\\\
jet reconstruction & {jetrec:.1f}\\\\
jet tagging & {jettag:.1f} \\\\
selection & {sel:.1f} \\\\
background & {bkg:.1f} \\\\
acceptance & {acc:.1f} \\\\
\hline
total & {total:.1f}
'''.format(mutrack = mutrkeff_err*100/mutrkeff, etrack = etrkeff_err*100/etrkeff, muonid = muideff_err*100/muideff, electronid = eideff_err*100/eideff, trigger = mutrgeff_err*100/mutrgeff, jetrec = jeteff_err*100/jeteff, jettag = tageff_err*100/tageff, sel = seleff_err*100/seleff, bkg = Nbkg_err_hi*100/(Nevts - Nbkg), acc = A_err*100/A, total = syst_err*100/xsec)
print "------------------------------------"



lhcb = ROOT.TPaveText(0.5, 0.82, 0.85, 0.9, "NDC")
lhcb.AddText("LHCb, #sqrt{s} = 13 TeV")
lhcb.SetFillStyle(0)
lhcb.SetBorderSize(0)

variables = [
    Bunch(name='ptj'   , xlabel = '#it{p}_{T}(j) [GeV]', ylims = [0,14]),
    Bunch(name='mu_pt' , xlabel = '#it{p}_{T}(#mu) [GeV]', ylims = [0, 13]),
    Bunch(name='e_pt'  , xlabel = '#it{p}_{T}(e) [GeV]'),
    Bunch(name='etaj'  , xlabel = '#eta(j)', ylims = [0, 14]),
    Bunch(name='mu_eta', xlabel = '#eta(#mu)', ylims = [0, 19]),
    Bunch(name='e_eta' , xlabel = '#eta(e)', ylims = [0, 19]),
    Bunch(name='dphi'  , xlabel = '#Delta#phi [rad]', ylims = [0, 19])
    ]

for v in variables:
    d = data.Get(v.name)
    if v.name=='mu_pt' or v.name=='mu_eta':
        t = top_murw.Get(v.name)
        wt = wt_murw.Get(v.name)
    elif v.name=='e_pt' or v.name=='e_eta':
        t = top_erw.Get(v.name)
        wt = wt_erw.Get(v.name)
    else:
        t  = top_jetrw.Get(v.name)
        wt = wt_jetrw.Get(v.name)
    if v.name=='ptj' or v.name=='etaj':
        z = zmumuj_data.Get(v.name)
    else:
        z = ztautau.Get(v.name)
    qcd = data_antiiso.Get(v.name)

    t.Scale(Nsig / t.Integral(0, t.GetNbinsX()+1))
    wt.Scale(Nwt / wt.Integral(0, wt.GetNbinsX()+1))
    z.Scale(Nzj / z.Integral(0, z.GetNbinsX() + 1))
    qcd.Scale(Nqcd / qcd.Integral(0, qcd.GetNbinsX() + 1))

    #make it like a stack
    t.Add(wt)
    t.Add(z)
    t.Add(qcd)
    wt.Add(z)
    wt.Add(qcd)
    z.Add(qcd)

    p = Plot([d, t, wt, z, qcd, d])
    p.setProp('colors', ['black', kViolet-1, kOrange -2, kYellow-2, kGreen, 'black'])
    p.setProp('markerstyles', [20, 0, 0, 0, 0, 20])
    p.setProp('fillstyles', [0, 1001, 1001, 1001, 1001, 0])
    p.setProp('drawOpts', ['p1', 'histf','histf','histf','histf', 'p1'])
    p.setProp('labels', ['data', 't#bar{t}', 'Wt','Z+jets', 'QCD'])
    p.setProp('filename', v.name+'_result.pdf')
    p.setProp('xlabel', v.xlabel)
    p.setProp('ylabel', 'Events')
    p.setProp('leglims', [0.6, 0.5, 0.9, 0.8])
    p.setProp('extraObjs', [lhcb])
    p.setProp('location', '/user2/sfarry/workspaces/top/figures')
    if hasattr(v, 'ylims'): p.setProp('ylims', v.ylims)
    p.drawROOT()
