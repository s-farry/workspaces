from ROOT import TFile, TTree, TH1F, RooRealVar, RooDataSet, RooArgSet
from math import *

class Bunch:
        def __init__(self, **kwds):
                self.__dict__.update(kwds)

def get_trk_vars(t, i):
        e = t.trk_e[i]
        px = t.trk_px[i]
        py = t.trk_py[i]
        pz = t.trk_pz[i]
        pt = sqrt(px*px + py*py)
        p = sqrt(pt*pt + pz*pz)
        eta = 0
        if p - pz > 0 : eta = 0.5 * log((p+pz)/(p-pz))
        ipchi2 = t.trk_ip_chi2[i]
        pnn_mu = t.trk_pnn_mu[i]
        pnn_k  = t.trk_pnn_k[i]
        pnn_ghost = t.trk_pnn_ghost[i]
        chi2 = t.trk_chi2[i]
        return Bunch(p =p, pt=pt, eta = eta, e = e, ipchi2 = ipchi2, pnn_mu = pnn_mu,
                     pnn_k = pnn_k, pnn_ghost = pnn_ghost, chi2 = chi2)


def get_part_vars(t, part, i):
        m   = getattr(t, part+'_m')[i]
        #dtf_m = getattr(t, part+'_dtf_m')[i]
        e   = getattr(t, part+'_e')[i]
        px  = getattr(t, part+'_px')[i]
        py  = getattr(t, part+'_py')[i]
        pz  = getattr(t, part+'_pz')[i]
        pt  = sqrt(px*px + py*py)
        p   = sqrt(pt*pt + pz*pz)
        eta = 0
        if p - pz > 0 : eta = 0.5 * log((p+pz)/(p-pz))
        return Bunch(p =p, pt=pt, eta = eta, e = e, m = m)

kstarmass = 891.66
pi0mass   = 134.9766
jpsimass  = 3096.916 

f = TFile("/hepstore/sfarry/Pi0Efficiency/Pi0Efficiency.CL15.MD.Reco15aDIMUON.0.160913.00.root")
t = f.Get("data")
g = TFile("/hepstore/sfarry/Pi0Efficiency/Pi0Efficiency.CL15.MU.Reco15aDIMUON.0.160913.00.root")
u = g.Get("data")

hist      = TH1F("h", "h", 100, 5200, 5400)
hist2     = TH1F("h2", "h2", 100, 5000, 5700)
kstmass   = TH1F("kst", "kst", 100, 700, 1100)
gamma_pt  = TH1F("gamma_pt", "gamma_pt", 100, 0, 2000)



m       = RooRealVar("m", "m", 5200, 5400)
argset  = RooArgSet(m)

m2      = RooRealVar("m2", "m2", 5000, 5600)
g1pt    = RooRealVar("gamma1_pt", "gamma1_pt", 0, 20000)
g2pt    = RooRealVar("gamma2_pt", "gamma2_pt", 0, 20000)
argset2 = RooArgSet(m2, g1pt, g2pt)

ds  = RooDataSet("ds", "ds", argset)
ds2 = RooDataSet("ds2", "ds2", argset2)

counters  = [0, 0, 0, 0, 0, 0]
counters2 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

for aa in (t, u):
        for i,e in enumerate(aa):
                if i%10000 == 0:
                        print i," entry of ",aa.GetEntries()
                        print counters

                bp0_m = e.bp0_dtf_m
                bp0_idx_psi = e.bp0_idx_psi
                bp0_idx_trk = e.bp0_idx_trk
                psi_idx_trk0 = e.psi_idx_trk0
                psi_idx_trk1 = e.psi_idx_trk1
                psi_dls      = e.psi_dls

		for j in range(len(bp0_m)):
			jpsi_idx = int(bp0_idx_psi[j])
			k_idx    = int(bp0_idx_trk[j])
			mu1_idx  = int(psi_idx_trk0[jpsi_idx])
			mu2_idx  = int(psi_idx_trk1[jpsi_idx])
			
			k = get_trk_vars(e, k_idx)
			
			mu1 = get_trk_vars(e, mu1_idx)
			mu2 = get_trk_vars(e, mu2_idx)
			jpsi = get_part_vars(e, 'psi', jpsi_idx)
			if k.pt < 250: continue
			counters[0] = counters[0] + 1
			if mu1.pt < 550 or mu2.pt < 550: continue
			counters[1] = counters[1] + 1
			if mu1.ipchi2 < 16 or mu2.ipchi2 < 16 or k.ipchi2 < 16: continue
			counters[2] = counters[2] + 1
		        if psi_dls[jpsi_idx] < 5: continue
			counters[3] = counters[3] + 1
			if abs(jpsimass - jpsi.m) > 50: continue
			counters[4] = counters[4] + 1
                        if k.pnn_k < 0.9: continue
                        counters[5] = counters[5] + 1
			hist.Fill(bp0_m[j])
			if ( bp0_m[j] > m.getMin() and bp0_m[j] < m.getMax() ):
				m.setVal(bp0_m[j])
				ds.add(argset)

	for i,e in enumerate(aa):
		if i%1000 == 0:
			print i," entry of ",aa.GetEntries()
			print counters2
		bp1_m = e.bp1_dtf_m
		bp1_idx_psi  = e.bp1_idx_psi
		bp1_idx_ksp  = e.bp1_idx_ksp
		bp1_dtf_chi2 = e.bp1_dtf_chi2
		bp1_ctau     = e.bp1_ctau
			
		psi_idx_trk0 = e.psi_idx_trk0
		psi_idx_trk1 = e.psi_idx_trk1
		psi_dls      = e.psi_dls
		ksp_idx_trk  = e.ksp_idx_trk
		ksp_idx_piz  = e.ksp_idx_piz
		piz_idx_gam0 = e.piz_idx_gam0
		piz_idx_gam1 = e.piz_idx_gam1
                
		for j in range(len(bp1_m)):
			jpsi_idx = int(bp1_idx_psi[j])
			ksp_idx  = int(bp1_idx_ksp[j])
			mu1_idx  = int(psi_idx_trk0[jpsi_idx])
			mu2_idx  = int(psi_idx_trk1[jpsi_idx])
			k_idx    = int(ksp_idx_trk[ksp_idx])
			piz_idx  = int(ksp_idx_piz[ksp_idx])
			gam1_idx = int(piz_idx_gam0[piz_idx])
			gam2_idx = int(piz_idx_gam1[piz_idx])
			
			k = get_trk_vars(aa, k_idx)
			jpsi = get_part_vars(e, 'psi', jpsi_idx)
			mu1  = get_trk_vars(e, mu1_idx)
			mu2  = get_trk_vars(e, mu2_idx)
			gam1 = get_part_vars(e, 'gam', gam1_idx)
			gam2 = get_part_vars(e, 'gam', gam2_idx)
			piz  = get_part_vars(e, 'piz', piz_idx)
			ksp  = get_part_vars(e, 'ksp', ksp_idx)
			

			
			if k.pnn_k < 0.9 or k.pt < 250: continue
			counters2[0] = counters2[0] + 1
			if (mu1.pt < 550 or mu2.pt < 550): continue
			if (mu1.pnn_mu < 0.8 or mu2.pnn_mu < 0.8): continue
			counters2[1] = counters2[1] + 1
			if (mu1.ipchi2 < 16 or mu2.ipchi2 < 16 or k.ipchi2 < 16): continue
			counters2[2] = counters2[2] + 1
			if psi_dls[jpsi_idx] < 5: continue
			counters2[3] = counters2[3] + 1
			if gam1.pt < 300 or gam2.pt < 300 : continue
			counters2[4] = counters2[4] + 1
			if abs(jpsimass - jpsi.m) > 50: continue
			counters2[5] = counters2[5] + 1
			if abs(pi0mass - piz.m) > 30 : continue
			counters2[6] = counters2[6] + 1
			if abs(kstarmass - ksp.m) > 60: continue
			counters2[7] = counters2[7] + 1
			if bp1_dtf_chi2[j] > 5: continue
			counters2[8] = counters2[8] + 1
			if bp1_ctau[j] < 0.2: continue
			counters2[9] = counters2[9] + 1
			kstmass.Fill(ksp.m)
			hist2.Fill(bp1_m[j])
                                
			if ( bp1_m[j] > m2.getMin() and bp1_m[j] < m2.getMax() ):
				m2.setVal(bp1_m[j])
                                g1pt.setVal(gam1.pt)
                                g2pt.setVal(gam2.pt)
                                gamma_pt.Fill(gam1.pt)
                                gamma_pt.Fill(gam2.pt)
				ds2.add(argset2)

oFile = TFile("bjpsik_data2015.root", "RECREATE")
ds.Write()
ds2.Write()
hist.Write()
hist2.Write()
gamma_pt.Write()
oFile.Close()
