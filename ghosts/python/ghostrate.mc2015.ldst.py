from math import sqrt, log

def get_vars(ivars, name, i):
        e = ivars.var(name.replace("<v>", "e"), i)
        px = ivars.var(name.replace("<v>", "px"), i)
        py = ivars.var(name.replace("<v>", "py"), i)
        pz = ivars.var(name.replace("<v>", "pz"), i)
        pt = sqrt(px*px + py*py)
        p = sqrt(pt*pt + pz*pz)
	eta = 0
	if (p -px) > 0: eta = 0.5 * log((p+pz)/(p-pz))
        return [p, pt, eta, e]

from variables import *
from ROOT import *

TH1.AddDirectory(False)

dpm = 'root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/ghostrate/'

f = TFile.Open(dpm+"GhostRate.30000000.LDST.MD.MC2015.root")
g = TFile.Open(dpm+"GhostRate.30000000.LDST.MU.MC2015.root")
#f = TFile.Open(dpm+"GhostRate.30000000.LDST.MD.MC2015.NoGhostProb.root")
#g = TFile.Open(dpm+"GhostRate.30000000.LDST.MU.MC2015.NoGhostProb.root")
t = f.Get("GhostRate/EFTree")
u = g.Get("GhostRate/EFTree")

class ghostvar:
	def __init__(self, name, bins, lo, hi, tex=''):
		self.tex   = tex
		self.name  = name
		self.rec   = TH1F("rec_"+name, "rec_"+name, bins  , lo, hi)
		self.ghost = TH1F("ghost_"+name,"ghost_"+name,  bins  , lo, hi)
		self.loose = TH1F("loose_"+name, "loose_"+name,bins, lo, hi)
		self.fake  = TH1F("fake_"+name,"fake_"+name, bins , lo, hi)
		self.fake_nowgt  = TH1F("fake_"+name+"_nowgt","fake_"+name+"_nowgt", bins , lo, hi)

	def process(self):
		self.ghost_rate = self.ghost.Clone("ghost_rate_"+self.name)
		self.ghost_rate.Divide(self.rec)
		self.fake_rate = self.fake.Clone("fake_rate_"+self.name)
		self.fake_rate.Divide(self.rec)
		self.loose_rate = self.loose.Clone("fake_rate_"+self.name)
		self.loose_rate.Divide(self.rec)

	def save(self, filename=""):
		#if filename=="": filename=self.name
		#outputFile = TFile(filename+".root", "RECREATE")
		self.rec.Write()
		self.ghost.Write()
		self.loose.Write()
		self.fake.Write()
		self.fake_nowgt.Write()
		self.ghost_rate.Write()
		self.loose_rate.Write()
		self.fake_rate.Write()
		#outputFile.Close()

pt       = ghostvar('pt'        , 100, 0, 1000, 'p_{T} [GeV]')
eta      = ghostvar('eta'       , 100, 2.0, 5.0, '#eta')
chi2ndof = ghostvar('chi2ndof'  , 100, 0, 5, '#chi^{2}/ndof.')
ghostprob = ghostvar('ghostprob', 100, 0, 0.4, 'Ghost Probability')
history   = ghostvar('history'  , 21, -0.5, 20.5, 'Track History')
nveloclus = ghostvar('nveloclusters', 50, 0, 3000, 'Velo Clusters')
npvs2     = ghostvar('npvs',  6, -0.5, 5.5, 'PVs')

nentries = 0
nvelofwdtracks = 0

for tree in [t,u]:
	v = IVariables()
	v.init(tree)
	for i in range(tree.GetEntries()):
		#if i > 100000: break
		if i%10000 == 0 : print "Entry ",i," of ",tree.GetEntries()
		tree.GetEntry(i)
		nvelotracks = v.varI('nVeloTracks')
		nvelofwd    = v.varI("nVeloFwdTracks")
		nvelotracks = v.var('nVeloTracks',0)
		if v.varI("e_tot") > 0: 
			nentries+= 1
			nvelofwdtracks += nvelofwd
		for j in range(v.varI("e_tot")):
			if (v.var('type',j) == 3.0):
				p_val, pt_val, eta_val, e_val = get_vars(v, "<v>", j)
				if p_val < 2000: continue
				chi2ndof_val  = v.var("chi2",j)/v.var("nDoF",j)
				ghostprob_val = v.var("ghostprob",j)
				history_val   = v.var("history", j)
				nveloclus_val = v.var("nveloclus_val", j)
				if v.var('faketrack',j) == 0:
					pt.rec.Fill(pt_val)
					eta.rec.Fill(eta_val)
					chi2ndof.rec.Fill(chi2ndof_val)
					ghostprob.rec.Fill(ghostprob_val)
					history.rec.Fill(history_val)
					nveloclus.Fill(nveloclus_val)
					nvelotracks = v.var('nVeloTracks',0)
					if v.var('rec2gen_e',j) == 0:
						pt.ghost.Fill(pt_val)
						eta.ghost.Fill(eta_val)
						chi2ndof.ghost.Fill(chi2ndof_val)
						ghostprob.ghost.Fill(ghostprob_val)
						history.ghost.Fill(history_val)
						nveloclus.ghost.Fill(nveloclus_val)
					if v.var('rec2gen_e_loose',j) == 0:
						pt.loose.Fill(pt_val)
						eta.loose.Fill(eta_val)
						chi2ndof.loose.Fill(chi2ndof_val)
						ghostprob.loose.Fill(ghostprob_val)
						history.loose.Fill(history_val)
						nveloclus.ghost.Fill(nveloclus_val)
				else:
					pt.fake.Fill(pt_val, nvelofwd)
					eta.fake.Fill(eta_val, nvelofwd)
					chi2ndof.fake.Fill(chi2ndof_val, nvelofwd)
					ghostprob.fake.Fill(ghostprob_val, nvelofwd)
					history.fake.Fill(history_val, nvelofwd)
					nveloclus.fake.Fill(nveloclus_val, nvelofwd)

					pt.fake_nowgt.Fill(pt_val)
					eta.fake_nowgt.Fill(eta_val)
					chi2ndof.fake_nowgt.Fill(chi2ndof_val)
					ghostprob.fake_nowgt.Fill(ghostprob_val)
					history.fake_nowgt.Fill(history_val)
					nveloclus.fake_nowgt.Fill(nveloclus_val)

pt.process()
eta.process()
chi2ndof.process()
ghostprob.process()
history.process()
nveloclus.process()


#save everything in an output file

outputFile = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015_ldst.root", "RECREATE")
pt.save()
eta.save()
chi2ndof.save()
ghostprob.save()
history.save()
nveloclus.save()
outputFile.Close()
