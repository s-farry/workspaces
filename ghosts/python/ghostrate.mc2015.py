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

f = TFile.Open(dpm+"GhostRate.30000000.MD.MC2015.Sim08h.root")
g = TFile.Open(dpm+"GhostRate.30000000.MU.MC2015.Sim08h.root")
#f = TFile.Open("/hepstore/sfarry/GridOutput/2837/GhostRate.30000000.MU.MC2015.Sim08h.root")
#g = TFile.Open("/hepstore/sfarry/GridOutput/2836/GhostRate.30000000.MD.MC2015.Sim08h.root")
t = f.Get("GhostRate/EFTree")
u = g.Get("GhostRate/EFTree")


pvweights = [1.030102, 1.440807, 0.7916086, 0.7023022,
	     0.6943015, 0.6775274, 0.694775]

class ghostvar:
	def __init__(self, name, bins, lo, hi, tex=''):
		self.tex   = tex
		self.name  = name
		self.rec   = TH1D("rec_"+name, "rec_"+name, bins  , lo, hi)
		self.rec_nowgt   = TH1D("rec_"+name+"_nowgt", "rec_"+name, bins  , lo, hi)
		self.fake  = TH1D("fake_"+name,"fake_"+name, bins , lo, hi)
		self.fake_nowgt = TH1D("fake_"+name+"_nowgt", "fake_"+name+"_nowgt", bins, lo, hi)
		self.rec.Sumw2()
		self.rec_nowgt.Sumw2()
		self.fake.Sumw2()
		self.fake_nowgt.Sumw2()

	def process(self):
		self.fake_rate = self.fake.Clone("fake_rate_"+self.name)
		self.fake_rate.Divide(self.rec)

	def save(self, filename=""):
		self.rec.Write()
		self.rec_nowgt.Write()
		self.fake.Write()
		self.fake_nowgt.Write()
		self.fake_rate.Write()

pt        = ghostvar('pt'        , 50, 0, 1000, 'p_{T} [GeV]')
eta       = ghostvar('eta'       , 50, 2.0, 5.0, '#eta')
chi2ndof  = ghostvar('chi2ndof'  , 50, 0, 5, '#chi^{2}/ndof.')
ghostprob = ghostvar('ghostprob', 50, 0, 0.4, 'Ghost Probability')
history2  = ghostvar('history'  , 21, -0.5, 20.5, 'Track History')
nveloclus = ghostvar('nveloclusters', 50, 0, 3000, 'Velo Clusters')
npvs2     = ghostvar('npvs',  6, -0.5, 5.5, 'PVs')

npvs_hist      = TH1D("npvs_hist", "npvs_hist", 6, -0.5, 5.5)
nveloclus_hist = TH1D("nveloclus_hist", "nveloclus_hist", 100, 0, 3000)

nentries       = 0
nvelofwdtracks = 0

for tree in [t,u]:
	print "initialised"
	v = IVariables()
	v.init(tree)
	for i in range(tree.GetEntries()):
		if i%10000 == 0 : print "Entry ",i," of ",tree.GetEntries()
		tree.GetEntry(i)
		nvelotracks   = v.varI('nVeloTracks')
		nvelofwd      = v.varI("nVeloFwdTracks")
		nvelotracks   = v.var('nVeloTracks',0)
		npvs_val      = v.varI('nPVs')
		nveloclus_val = v.varI('nVeloClusters')
		w = 1.0
		if v.varI("e_tot") > 0: 
			nentries+= 1
			nvelofwdtracks += nvelofwd
			npvs_hist.Fill(npvs_val)
			nveloclus_hist.Fill(nveloclus_val)
			for j in range(v.varI("e_tot")):
				if (v.var('type',j) == 3.0):
					p_val, pt_val, eta_val, e_val = get_vars(v, "<v>", j)
					if p_val < 2000: continue
					chi2ndof_val  = v.var("chi2",j)/v.var("nDoF",j)
					ghostprob_val = v.var("ghostprob",j)
					history_val   = v.var("history", j)
					if v.var('faketrack',j) == 0:
						pt.rec.Fill(pt_val, w)
						eta.rec.Fill(eta_val, w)
						chi2ndof.rec.Fill(chi2ndof_val, w)
						ghostprob.rec.Fill(ghostprob_val, w)
						history2.rec.Fill(history_val, w)
						npvs2.rec.Fill(npvs_val, w)
						nveloclus.rec.Fill(nveloclus_val, w)
						
						pt.rec_nowgt.Fill(pt_val)
						eta.rec_nowgt.Fill(eta_val)
						chi2ndof.rec_nowgt.Fill(chi2ndof_val)
						ghostprob.rec_nowgt.Fill(ghostprob_val)
						history2.rec_nowgt.Fill(history_val)
						npvs2.rec_nowgt.Fill(npvs_val)
						nveloclus.rec_nowgt.Fill(nveloclus_val)
					else:
						pt.fake.Fill(pt_val, nvelofwd*w)
						pt.fake_nowgt.Fill(pt_val)
						eta.fake.Fill(eta_val, nvelofwd*w)
						eta.fake_nowgt.Fill(eta_val)
						chi2ndof.fake.Fill(chi2ndof_val, nvelofwd*w)
						chi2ndof.fake_nowgt.Fill(chi2ndof_val)
						ghostprob.fake.Fill(ghostprob_val, nvelofwd*w)
						ghostprob.fake_nowgt.Fill(ghostprob_val)
						history2.fake.Fill(history_val, nvelofwd*w)
						history2.fake_nowgt.Fill(history_val)
						npvs2.fake.Fill(npvs_val, nvelofwd*w)
						npvs2.fake_nowgt.Fill(npvs_val)
						nveloclus.fake.Fill(nveloclus_val, nvelofwd*w)
						nveloclus.fake_nowgt.Fill(nveloclus_val)

pt.process()
eta.process()
chi2ndof.process()
ghostprob.process()
history2.process()
nveloclus.process()
npvs2.process()
'''
from PlotTools import *

from Style import *
SetLHCbStyle()

for i in [pt, eta, chi2ndof, ghostprob, history2, nveloclus, npvs2]:
	print i.name, history2
	o = Plot([i.rec, i.fake])
	ymax = -1
	for p in o.plots:
		p.UseCurrentStyle()
		if ymax == -1 or p.GetMaximum()*1.1/p.Integral() > ymax:
			ymax = p.GetMaximum()*1.1/p.Integral()
	o.setProp('colors', ['blue', 'red', 'green'])
	o.setProp('leglims', [0.2, 0.6, 0.4, 0.85])
	o.setProp('markerstyles', 20)
	o.setProp('filename', i.name+'_mc2015')
	o.setProp('normalised', True)
	o.setProp('ylabel', '[A.U.]')
	o.setProp('xlabel', i.tex)
	o.setProp('drawOpts', 'hist')
	o.setProp('fillstyles', 0)
	o.setProp('ynormlims', [0, ymax])
	o.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
	o.setProp('labels', ['All Tracks', 'Ghosts', 'Fakes'])
	o.drawROOT()

	ymax = -1
	m = Plot([i.fake_rate])
	for p in m.plots:
		p.UseCurrentStyle()
		if ymax == -1 or p.GetMaximum()*1.1 > ymax:
			ymax = p.GetMaximum()*1.1
	m.setProp('colors', ['red', 'green'])
	m.setProp('leglims', [0.2, 0.7, 0.4, 0.85])
	m.setProp('markerstyles', 20)
	m.setProp('filename', i.name+'_rate_mc2015')
	m.setProp('ylabel', 'Ghost Rate')
	m.setProp('xlabel', i.tex)
	m.setProp('drawOpts', 'hist')
	m.setProp('fillstyles', 0)
	m.setProp('location', '.')
	m.setProp('ynormlims', [0, ymax])
	m.setProp('labels', ['Ghosts', 'Fakes'])
	m.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
	m.drawROOT()
'''
outputFile = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015.root", "RECREATE")
npvs_hist.Write()
nveloclus_hist.Write()
pt.save()
eta.save()
chi2ndof.save()
ghostprob.save()
history2.save()
nveloclus.save()
npvs2.save()
outputFile.Close()
