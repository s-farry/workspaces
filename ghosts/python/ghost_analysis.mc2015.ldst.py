from math import sqrt, log
from ROOT import *

def get_lorentz(ivars, name, i):
        e = ivars.var(name.replace("<v>", "e"), i)
        px = ivars.var(name.replace("<v>", "px"), i)
        py = ivars.var(name.replace("<v>", "py"), i)
        pz = ivars.var(name.replace("<v>", "pz"), i)
        return TLorentzVector(px,py,pz,e)

from variables import *
from ROOT import *

TH1.AddDirectory(False)

dpm = 'root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/ghostrate/'

f = TFile.Open(dpm+"GhostRate.30000000.LDST.MD.MC2015.root")
g = TFile.Open(dpm+"GhostRate.30000000.LDST.MU.MC2015.root")
t = f.Get("GhostRate/EFTree")
u = g.Get("GhostRate/EFTree")

h = TH1F("h", "h", 100, 0, 5.0)
h2 = TH1F("h2", "h2", 100, 0, 5.0)

for tree in [t,u]:
	v = IVariables()
	v.init(tree)
	for i in range(tree.GetEntries()):
		if i > 50000: break
		if i%100 == 0 : print "Entry ",i," of ",tree.GetEntries()
		tree.GetEntry(i)
		for j in range(v.varI("e_tot")):
			if (v.var('type',j) != 3.0): continue
			track1 = get_lorentz(v, "<v>", j)
			if track1.P() < 2000: continue
			#if   v.var('faketrack', j ) == 0 and v.var('rec2gen_e_loose') == 1:
					#real track
			if v.var('faketrack', j ) == 0 and v.var('rec2gen_e_loose', j) == 0:
				#ghost
				dR = 0.0
				n  = 0
				for k in range(v.varI("e_tot")):
					#take only real tracks
					if j==k or v.var('faketrack', k) != 0 or v.var('rec2gen_e_loose', k) == 0: continue
					track2 = get_lorentz(v, "<v>", k)
					dR += track1.DeltaR(track2)
					n = n+1
				if n > 0: h.Fill(dR/n)
			elif v.var('faketrack', j) == 1:
				dR = 0.0
				n  = 0
				for k in range(v.varI("e_tot")):
					#take only real tracks
					if j==k or v.var('faketrack', k) != 0 or v.var('rec2gen_e_loose', k) == 0: continue
					track2 = get_lorentz(v, "<v>", k)
					dR += track1.DeltaR(track2)
					n = n+1
				#fake
				if n>0: h2.Fill(dR/n)


