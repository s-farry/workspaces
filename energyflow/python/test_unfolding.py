### testing script - rather messy
def trim_outer(h):
        edges = []
        n = h.GetNbinsX()
        for i in range(n+1):
                edges += [ h.GetBinLowEdge(i+1) ]
        h2 = TH1F(h.GetTitle()+'_trim', h.GetName()+'_trim', n-2, array('d', edges[1:-1]))
        h2.SetBinContent(0, h.GetBinContent(0)+h.GetBinContent(1))
        for i in range((n-2)+1):
                  h2.SetBinContent(i+1, h.GetBinContent(i+2))
        h.SetBinContent((n-2)+1, h.GetBinContent(n) + h.GetBinContent(n+1))
        return h2


def get_vars(ivars, name, i):
        e = ivars.var(name.replace("<v>", "e"), i)
        px = ivars.var(name.replace("<v>", "px"), i)
        py = ivars.var(name.replace("<v>", "py"), i)
        pz = ivars.var(name.replace("<v>", "pz"), i)
        pt = sqrt(px*px + py*py)
        p = sqrt(pt*pt + pz*pz)
	eta = -100
	if (p-pz > 0 and p+pz > 0):
		eta = 0.5 * log((p+pz)/(p-pz))
        return [p, pt, eta, e]

from ROOT import gROOT
gROOT.LoadMacro( "/user2/sfarry/workspaces/WJet/RooUnfold/libRooUnfold.so" )
from variables import *
from ROOT import TFile, TH1F, RooUnfoldResponse, RooUnfoldBayes, TCanvas
from math import sqrt, log
from array import array

#f = TFile("/hepstore/kdreimanis/forSteve/eflow/EnergyFlow_MC2015_Sim08EM.root")
f = TFile("/scratch/kdreiman/eflow/sim09b_bt_1M.root")
t = f.Get("EventTuple/EventTuple")
t.SetBranchStatus("*",0)
t.SetBranchStatus("rec_c*",1)
t.SetBranchStatus("rec2gen_c*",1)

v = IVariables()
v.init(t)

etabins = [ 0, 2.0, 2.125, 2.25, 2.375, 2.5, 2.625, 2.75, 2.875, 3.0, 3.125, 3.25, 3.375, 3.5, 3.625, 3.75, 3.875, 4.0, 4.125, 4.25, 4.375, 4.5, 10.0]

#res.UseOverflow(True)

#h = TH1F("eta", "eta", 10 , 1.9, 4.9)

rec  = TH1F("rec" , "e" , 22 , array('d', etabins))
true = TH1F("true" , "e" , 22 , array('d', etabins))
res = RooUnfoldResponse( rec, true )

for i in range(t.GetEntries()):
    if i%1000 == 0: print i
    if i > 100000: continue
    t.GetEntry(i)
    for k in range(v.varI("rec_ce_tot")):
	    if v.var('rec_ctracktype',k) == 3:
		    p, pt, eta, e = get_vars(v, "rec_c<v>", k)
		    if v.var('rec2gen_ce',k) > 0:
			    gp, gpt, geta, ge = get_vars(v, "rec2gen_c<v>", k)
                            if i%2 == 0:
                                    rec.Fill(eta)
                                    true.Fill(geta)
                            else:
                                    res.Fill(eta, geta)
                    else:
                            if i%2 == 0:
                                    rec.Fill(eta)
                            else:
                                    res.Fake(eta)

bayes = RooUnfoldBayes( res, rec, 3 )
unfold = bayes.Hreco()

from PlotTools import *
from Style import *
SetLHCbStyle()

a = Plot([trim_outer(rec), trim_outer(true), trim_outer(unfold)])
for p in a.plots: p.UseCurrentStyle()
a.setProp('forcestyle', True)
a.setProp('filename', 'test_unfolding.pdf')
a.setProp('location', '.')
a.setProp('labels', ['rec', 'true', 'unfolded'])
a.setProp('colors', ['black', 'red', 'blue'])
a.setProp('drawOpts', ['e1', 'h', 'h'])
a.setProp('markerstyles', [20, 0, 0])
a.setProp('fillstyles', [0, 0, 0])
a.setProp('toCompare', { 1 : [ 2 ] })
a.setProp('leglims', [0.6, 0.4, 0.9, 0.6])
a.setProp('ycomplims', [0.9, 1.1])
a.drawROOT()




 

