import ROOT as r
from Jawa import *

from Utils import Bunch

from strange_config import *

zj_sel  = r.TCut("muminus_PT > 20000 && muplus_PT > 20000 && boson_jet_PT > 20000 && min(muminus_ETA, muplus_ETA) > 2.0 && max(muminus_ETA, muplus_ETA) < 4.5 && boson_M > 60000 && boson_M < 120000")
zj_truesel  = r.TCut("muminus_PT > 20000 && muplus_PT > 20000 && boson_truejet_PT > 20000 && min(muminus_ETA, muplus_ETA) > 2.0 && max(muminus_ETA, muplus_ETA) < 4.5 && boson_M > 60000 && boson_M < 120000")
jet_sel = r.TCut("jet_PT > 20000 && jet_ETA > 2.2 && jet_ETA < 4.2")

truth_match = r.TCut("boson_mcjet_PT > 0")


trueplots = [
    Bunch(name='ptj', xlabel='p_{T}^{j} [GeV]', ylabel='[A.U.]', var='boson_truejet_PT/1000.0', nbins=40, lo = 20, hi = 100),
    Bunch(name='etaj',  xlabel='#eta^{j}', ylabel='[A.U.]', var='boson_truejet_ETA', nbins=10, lo = 2.2, hi = 4.2),
    ]

plots = [
    Bunch(name='ptj', xlabel='p_{T}^{j} [GeV]', ylabel='[A.U.]', var='boson_jet_PT/1000.0', nbins=40, lo = 20, hi = 100),
    Bunch(name='etaj',  xlabel='#eta^{j}', ylabel='[A.U.]', var='boson_jet_ETA', nbins=10, lo = 2.2, hi = 4.2),
    Bunch(name='ptj_truth', xlabel='p_{T}^{j} [GeV]', ylabel='[A.U.]', var='boson_mcjet_PT/1000.0', nbins=40, lo = 20, hi = 100),
    Bunch(name='etaj_truth',  xlabel='#eta^{j}', ylabel='[A.U.]', var='boson_mcjet_ETA', nbins=10, lo = 2.2, hi = 4.2)
    ]

zmumuj_mc2015_t = Template("zmumuj_mc2015_truth")
zmumuj_mc2015_t.SetSelCut(zj_truesel)
zmumuj_mc2015_t.AddTrees(zmumuj_mc2015.trees())
for p in trueplots:
    zmumuj_mc2015_t.AddVar([p.name, p.var, p.nbins, p.lo, p.hi])
zmumuj_mc2015_t.Add2DVar(['ptj', 'etaj'])
zmumuj_mc2015_t.Run()
zmumuj_mc2015_t.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015_truth.root")


strange = TFile("/user2/sfarry/workspaces/strange/tuples/strangejet.root")
quark   = TFile("/user2/sfarry/workspaces/strange/tuples/quarkjet.root")
gluon   = TFile("/user2/sfarry/workspaces/strange/tuples/gluonjet.root")

outF = TFile("/user2/sfarry/workspaces/strange/tuples/zj_ptj_weights.root", "RECREATE")

strange_weights = strange.Get("ptj").Clone("strange_weights")
quark_weights   = quark.Get("ptj").Clone("quark_weights")
gluon_weights   = gluon.Get("ptj").Clone("gluon_weights")

strange_weights.Scale(1.0/strange_weights.Integral())
quark_weights.Scale(1.0/quark_weights.Integral())
gluon_weights.Scale(1.0/gluon_weights.Integral())

denom = zmumuj_mc2015_t.GetVar("ptj").GetHist().Clone("denom")
denom.Scale(1.0/denom.Integral())
strange_weights.Divide(denom)
quark_weights.Divide(denom)
gluon_weights.Divide(denom)

strange_weights2d = strange.Get("ptj_etaj").Clone("strange_weights2d")
quark_weights2d   = quark.Get("ptj_etaj").Clone("quark_weights2d")
gluon_weights2d   = gluon.Get("ptj_etaj").Clone("gluon_weights2d")

strange_weights2d.Scale(1.0/strange_weights2d.Integral())
quark_weights2d.Scale(1.0/quark_weights2d.Integral())
gluon_weights2d.Scale(1.0/gluon_weights2d.Integral())

denom2d = zmumuj_mc2015_t.Get2DVar("ptj","etaj").GetHist().Clone("denom2d")
denom2d.Scale(1.0/denom2d.Integral())
strange_weights2d.Divide(denom2d)
quark_weights2d.Divide(denom2d)
gluon_weights2d.Divide(denom2d)


strange_weights.Write()
quark_weights.Write()
gluon_weights.Write()


strange_weights2d.Write()
quark_weights2d.Write()
gluon_weights2d.Write()


zmumuj_mc2015_s = Template("zmumuj_mc2015_strange")
zmumuj_mc2015_s.SetSelCut(zj_sel + truth_match)
zmumuj_mc2015_s.AddTrees(zmumuj_mc2015.trees())
for p in plots:
    zmumuj_mc2015_s.AddVar([p.name, p.var, p.nbins, p.lo, p.hi])
zmumuj_mc2015_s.Add2DVar(['ptj', 'etaj'])
#zmumuj_mc2015_s.Reweight("boson_mcjet_PT/1000.0", strange_weights)
zmumuj_mc2015_s.Reweight("boson_mcjet_PT/1000.0", "boson_mcjet_ETA", strange_weights2d)
zmumuj_mc2015_s.Run()
zmumuj_mc2015_s.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015_strange.root")

zmumuj_mc2015_q = Template("zmumuj_mc2015_quark")
zmumuj_mc2015_q.SetSelCut(zj_sel + truth_match)
zmumuj_mc2015_q.AddTrees(zmumuj_mc2015.trees())
for p in plots:
    zmumuj_mc2015_q.AddVar([p.name, p.var, p.nbins, p.lo, p.hi])
zmumuj_mc2015_q.Add2DVar(['ptj', 'etaj'])
#zmumuj_mc2015_q.Reweight("boson_mcjet_PT/1000.0", quark_weights)
zmumuj_mc2015_q.Reweight("boson_mcjet_PT/1000.0", "boson_mcjet_ETA", quark_weights2d)
zmumuj_mc2015_q.Run()
zmumuj_mc2015_q.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015_quark.root")

zmumuj_mc2015_g = Template("zmumuj_mc2015_gluon")
zmumuj_mc2015_g.SetSelCut(zj_sel + truth_match)
zmumuj_mc2015_g.AddTrees(zmumuj_mc2015.trees())
for p in plots:
    zmumuj_mc2015_g.AddVar([p.name, p.var, p.nbins, p.lo, p.hi])
zmumuj_mc2015_g.Add2DVar(['ptj', 'etaj'])
#zmumuj_mc2015_g.Reweight("boson_mcjet_PT/1000.0", gluon_weights)
zmumuj_mc2015_g.Reweight("boson_mcjet_PT/1000.0", "boson_mcjet_ETA", gluon_weights2d)
zmumuj_mc2015_g.Run()
zmumuj_mc2015_g.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015_gluon.root")

outF.Close()
