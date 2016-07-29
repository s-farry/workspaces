from ROOT import *
from math import sqrt
from Jawa import *

def save_purity(i, f):
    rho = i.Get('hRho')
    rhos0 = i.Get('hRhoS_0')
    rhos1 = i.Get('hRhoS_1')
    rhob0 = i.Get('hRhoB_0')
    rhob1 = i.Get('hRhoB_1')

    o = open(f, 'w')

    for i in range(rho.GetNbinsX()):
        o.write(str(rho.GetBinContent(i+1))+' ')
    o.write('\n')

    for i in range(rho.GetNbinsX()):
        prefix = '0 '*i
        postfix = "0 "*(rho.GetNbinsX() - (i))
        o.write(prefix+str(rho.GetBinError(i+1))+postfix)
        o.write('\n')

    for i in range(rho.GetNbinsX()):
        o.write(str(rhos0.GetBinError(i+1))+' ')
    o.write('\n')

    for i in range(rho.GetNbinsX()):
        o.write(str(rhos1.GetBinError(i+1))+' ')
    o.write('\n')

    for i in range(rho.GetNbinsX()):
        o.write(str(rhob0.GetBinError(i+1))+' ')
    o.write('\n')
    
    o.close()
    print 'saved to ', f

def save_jec(i, f):
    sig = i.Get('hSig')
    sig0 = i.Get('hSigJ_0')
    sig1 = i.Get('hSigJ_1')
    sig2 = i.Get('hSigJ_2')
    sig3 = i.Get('hSigJ_3')
    sig4 = i.Get('hSigJ_4')

    o = open(f, 'w')

    for i in range(sig.GetNbinsX()):
        o.write(str(1/sqrt(sig.GetBinContent(i+1)))+" ")
    o.write('\n')

    for i in range(sig.GetNbinsX()):
        o.write(str(max(sig0.GetBinError(i+1), sig1.GetBinError(i+1))/sig.GetBinContent(i+1))+' ')
    o.write('\n')

    for i in range(sig.GetNbinsX()):
        o.write(str(max(sig2.GetBinError(i+1), sig3.GetBinError(i+1))/sig.GetBinContent(i+1))+' ')
    o.write('\n')


    for i in range(sig.GetNbinsX()):
        o.write(str(sig4.GetBinError(i+1)/sig.GetBinContent(i+1))+' ')
    o.write('\n')
    o.close()
    print 'saved to ', f


wm_etaj_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/purity_W_0_Wm-etaj/purity_Wm_etaj.root")
wm_etam_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/purity_W_0_Wm-etam/purity_Wm_etam.root")
wm_ptj_f  = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/purity_W_0_Wm-ptj/purity_Wm_ptj.root")

wp_etaj_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/purity_W_0_Wp-etaj/purity_Wp_etaj.root")
wp_etam_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/purity_W_0_Wp-etam/purity_Wp_etam.root")
wp_ptj_f  = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/purity_W_0_Wp-ptj/purity_Wp_ptj.root")

save_purity(wp_etaj_f, '/user2/sfarry/WJet/dat/wp_purity_etaj.dat')
save_purity(wp_etam_f, '/user2/sfarry/WJet/dat/wp_purity_eta.dat')
save_purity(wp_ptj_f, '/user2/sfarry/WJet/dat/wp_purity_ptj.dat')

save_purity(wm_etaj_f, '/user2/sfarry/WJet/dat/wm_purity_etaj.dat')
save_purity(wm_etam_f, '/user2/sfarry/WJet/dat/wm_purity_eta.dat')
save_purity(wm_ptj_f, '/user2/sfarry/WJet/dat/wm_purity_ptj.dat')

wm_etaj_jec_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/jec_W_0_Wm-etaj/jec_Wm_etaj.root")
wm_etam_jec_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/jec_W_0_Wm-etam/jec_Wm_etam.root")
wm_ptj_jec_f  = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/jec_W_0_Wm-ptj/jec_Wm_ptj.root")

wp_etaj_jec_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/jec_W_0_Wp-etaj/jec_Wp_etaj.root")
wp_etam_jec_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/jec_W_0_Wp-etam/jec_Wp_etam.root")
wp_ptj_jec_f  = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/jec_W_0_Wp-ptj/jec_Wp_ptj.root")

save_jec(wp_etaj_jec_f, '/user2/sfarry/WJet/dat/wp_jec_errs_etaj.dat')
save_jec(wp_etam_jec_f, '/user2/sfarry/WJet/dat/wp_jec_errs_eta.dat')
save_jec(wp_ptj_jec_f, '/user2/sfarry/WJet/dat/wp_jec_errs_ptj.dat')

save_jec(wm_etaj_jec_f, '/user2/sfarry/WJet/dat/wm_jec_errs_etaj.dat')
save_jec(wm_etam_jec_f, '/user2/sfarry/WJet/dat/wm_jec_errs_eta.dat')
save_jec(wm_ptj_jec_f, '/user2/sfarry/WJet/dat/wm_jec_errs_ptj.dat')

wm_etaj_analysis_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/analysis_W_0_Wm-etaj/analysis_Wm_etaj.root")
wm_etam_analysis_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/analysis_W_0_Wm-etam/analysis_Wm_etam.root")
wm_ptj_analysis_f  = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/analysis_W_0_Wm-ptj/analysis_Wm_ptj.root"  )

wp_etaj_analysis_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/analysis_W_0_Wp-etaj/analysis_Wp_etaj.root")
wp_etam_analysis_f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/analysis_W_0_Wp-etam/analysis_Wp_etam.root")
wp_ptj_analysis_f  = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/analysis_W_0_Wp-ptj/analysis_Wp_ptj.root"  )

saveTH1F("/user2/sfarry/WJet/dat/wm_sel_eff_etaj.dat", wm_etaj_analysis_f.Get("hESel"))
saveTH1F("/user2/sfarry/WJet/dat/wm_sel_eff_eta.dat" , wm_etam_analysis_f.Get("hESel"))
saveTH1F("/user2/sfarry/WJet/dat/wm_sel_eff_ptj.dat" , wm_ptj_analysis_f.Get("hESel") )

saveTH1F("/user2/sfarry/WJet/dat/wp_sel_eff_etaj.dat", wp_etaj_analysis_f.Get("hESel"))
saveTH1F("/user2/sfarry/WJet/dat/wp_sel_eff_eta.dat" , wp_etam_analysis_f.Get("hESel"))
saveTH1F("/user2/sfarry/WJet/dat/wp_sel_eff_ptj.dat" , wp_ptj_analysis_f.Get("hESel") )

saveTH1F("/user2/sfarry/WJet/dat/wm_ewkfraction_etaj.dat", wm_etaj_analysis_f.Get("hBkgEW"))
saveTH1F("/user2/sfarry/WJet/dat/wm_ewkfraction_eta.dat" , wm_etam_analysis_f.Get("hBkgEW"))
saveTH1F("/user2/sfarry/WJet/dat/wm_ewkfraction_ptj.dat" , wm_ptj_analysis_f.Get("hBkgEW") )

saveTH1F("/user2/sfarry/WJet/dat/wp_ewkfraction_etaj.dat", wp_etaj_analysis_f.Get("hBkgEW"))
saveTH1F("/user2/sfarry/WJet/dat/wp_ewkfraction_eta.dat" , wp_etam_analysis_f.Get("hBkgEW"))
saveTH1F("/user2/sfarry/WJet/dat/wp_ewkfraction_ptj.dat" , wp_ptj_analysis_f.Get("hBkgEW") )

