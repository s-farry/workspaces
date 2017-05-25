from ROOT import TFile, TTree, TH1F, RooRealVar, RooDataSet, RooArgSet
from math import *
from eta_decay import *

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
        return Bunch(p =p, pt=pt, eta = eta, e = e, px=px, py=py, pz=pz)


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
        return Bunch(p =p, pt=pt, eta = eta, e = e, m = m, px = px, py=py, pz=pz)

def get_gamma_vars(gamma):
        e   = gamma[3]
        px  = gamma[0]
        py  = gamma[1]
        pz  = gamma[2]
        pt  = sqrt(px*px + py*py)
        p   = sqrt(pt*pt + pz*pz)
        eta = 0
        if p - pz > 0 : eta = 0.5 * log((p+pz)/(p-pz))
        return Bunch(p =p, pt=pt, eta = eta, e = e, m = m, px=px,py=py,pz=pz)


kstarmass = 891.66
pi0mass   = 134.9766
jpsimass  = 3096.916 

f = TFile.Open("/user2/sfarry/workspaces/energyflow/tuples/ntuple.root")
t = f.Get("data")

hist      = TH1F("h", "h", 100, 0.5, 0.6)
hist2     = TH1F("h2", "h2", 100, 0.5, 0.6)
gamma_pt  = TH1F("gamma_pt", "gamma_pt", 100, 0, 2)
gamma_eta  = TH1F("gamma_eta", "gamma_eta", 100, 2.0, 4.5)
fakegamma_pt  = TH1F("fakegamma_pt", "fakegamma_pt", 100, 0, 2)
fakegamma_eta  = TH1F("fakegamma_eta", "fakegamma_eta", 100, 2.0, 4.5)

m         = RooRealVar("m", "m", 0.5, 0.6)
fgpt      = RooRealVar("fgpt", "fgpt", 0, 1000000)
fgeta     = RooRealVar("fgeta", "fgeta", 1.0, 6.0)
fgp       = RooRealVar("fgp", "fgp", 0, 1000000)
mu1pt     = RooRealVar("mu1pt", "mu1pt", 0, 1000000)
mu2pt     = RooRealVar("mu2pt", "mu2pt", 0, 1000000)
argset    = RooArgSet(m, fgpt, fgeta, fgp, mu1pt, mu2pt)


m2        = RooRealVar("m2", "m2", 0.5, 0.6)
gpt       = RooRealVar("gamma_pt", "gamma_pt", 0, 1000000)
geta      = RooRealVar("gamma_eta", "gamma_eta", 1.0, 6.0)
gp        = RooRealVar("gamma_p",   "gamma_p", 0, 1000000)
mu1bpt    = RooRealVar("mu1bpt", "mu1pt", 0, 1000000)
mu2bpt    = RooRealVar("mu2bpt", "mu2pt", 0, 1000000)
argset2   = RooArgSet(m2, gpt, geta, gp, mu1bpt, mu2bpt)

ds  = RooDataSet("ds", "ds", argset)
ds2 = RooDataSet("ds2", "ds2", argset2)

counters  = [0, 0, 0, 0, 0, 0]
counters2 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

decayer = Decayer("gamma")

for aa in [t]:
	for i in range(aa.GetEntries()):
		s = aa.GetEntry(i)
		if s==-1:
			print "Error reading event ",i,", skipping"
			continue
                if i%10000 == 0:
                        print i," entry of ",aa.GetEntries()

                ez0_m = aa.ez0_m
                ez0_idx_trk0 = aa.ez0_idx_trk0
                ez0_idx_trk1 = aa.ez0_idx_trk1

		for j in range(len(ez0_m)):
			ez0 = get_part_vars(aa, "ez0", j)
			fg = decayer.gamma(ez0.px, ez0.py, ez0.pz, ez0.m)
			fg_kins = get_gamma_vars(fg)
			mu1_idx  = int(ez0_idx_trk0[j])
			mu2_idx  = int(ez0_idx_trk1[j])
			mu1 = get_trk_vars(aa, mu1_idx)
			mu2 = get_trk_vars(aa, mu2_idx)
			ez0 = get_part_vars(aa, 'ez0', j)
                        counters[5] = counters[5] + 1
			hist.Fill(ez0_m[j])
			#if ( mu1.pt > 0.5 and mu1.p > 10 and mu2.pt > 0.5 and mu2.p > 10 and ez0_m[j] > m.getMin() and ez0_m[j] < m.getMax() ):
			if ( ez0_m[j] > m.getMin() and ez0_m[j] < m.getMax() ):
				m.setVal(ez0_m[j])
				fgpt.setVal(fg_kins.pt*1000)
				fgeta.setVal(fg_kins.eta)
				fgp.setVal(fg_kins.p*1000)
				mu1pt.setVal(mu1.pt*1000.0)
				mu2pt.setVal(mu2.pt*1000.0)
                                fakegamma_pt.Fill(fg_kins.pt*1000)
                                fakegamma_eta.Fill(fg_kins.eta)
				ds.add(argset)
	
	for i in range(aa.GetEntries()):
		s = aa.GetEntry(i)
		if s == -1:
			print "Error reading event ",i,", skipping"
			continue
		if i%10000 == 0:
			print i," entry of ",aa.GetEntries()
		#if i > 10000: break
		#if i > 100000: break
		ez1_m = aa.ez1_m
		ez1_idx_trk0 = aa.ez1_idx_trk0
		ez1_idx_trk1 = aa.ez1_idx_trk1
		ez1_idx_gam  = aa.ez1_idx_gam
                
		for j in range(len(ez1_m)):
			mu1_idx  = int(ez1_idx_trk0[j])
			mu2_idx  = int(ez1_idx_trk1[j])
			gam_idx  = int(ez1_idx_gam[j])
			mu1  = get_trk_vars(aa, mu1_idx)
			mu2  = get_trk_vars(aa, mu2_idx)
			gam  = get_part_vars(aa, 'gam', gam_idx)
			#print ez1_m[j]
			hist2.Fill(ez1_m[j])
			#if ( mu1.pt > 0.5 and mu1.p > 10 and mu2.pt > 0.5 and mu2.p > 10 and  ez1_m[j] > m2.getMin() and ez1_m[j] < m2.getMax() ):
			if (ez1_m[j] > m2.getMin() and ez1_m[j] < m2.getMax()):
				m2.setVal(ez1_m[j])
                                gpt.setVal(gam.pt*1000.0)
				geta.setVal(gam.eta)
				gp.setVal(gam.p*1000.0)
				mu1bpt.setVal(mu1.pt*1000.0)
				mu2bpt.setVal(mu2.pt*1000.0)
                                gamma_pt.Fill(gam.pt*100.0)
                                gamma_eta.Fill(gam.eta)
				ds2.add(argset2)
	  

oFile = TFile("/user2/sfarry/workspaces/energyflow/tuples/eta_pythia_embedded.root", "RECREATE")
ds.Write()
ds2.Write()
hist.Write()
hist2.Write()
gamma_pt.Write()
fakegamma_pt.Write()
gamma_eta.Write()
fakegamma_eta.Write()
oFile.Close()
