from PlotTools import *
from ROOT import TFile, TTree, TH1F, TH2F

from Style import *
SetLHCbStyle()

f = TFile("/user2/sfarry/WJet/tuples/unfold.root")

reco_plus    = f.Get("jet_reco_plus" )
reco_minus   = f.Get("jet_reco_minus")
true_plus    = f.Get("jet_true_plus" )
true_minus   = f.Get("jet_true_minus")
unfold_plus  = f.Get("jet_plus_unfolded" )
unfold_minus = f.Get("jet_minus_unfolded")
unfold_plus_plus  = f.Get("jet_plus_unfolded_plus" )
unfold_minus_plus = f.Get("jet_minus_unfolded_plus")
unfold_plus_minus  = f.Get("jet_plus_unfolded_minus" )
unfold_minus_minus = f.Get("jet_minus_unfolded_minus")

ptj_reco_plus     = reco_plus.ProjectionY()
ptj_true_plus     = true_plus.ProjectionY()
ptj_unfold_plus   = unfold_plus.ProjectionY()
ptj_unfold_plus_plus  = unfold_plus_plus.ProjectionY()
ptj_unfold_plus_minus = unfold_plus_minus.ProjectionY()

ptj_reco_minus     = reco_minus.ProjectionY()
ptj_true_minus     = true_minus.ProjectionY()
ptj_unfold_minus   = unfold_minus.ProjectionY()
ptj_unfold_minus_plus  = unfold_minus_plus.ProjectionY()
ptj_unfold_minus_minus = unfold_minus_minus.ProjectionY()


etaj_reco_plus     = reco_plus.ProjectionX()
etaj_true_plus     = true_plus.ProjectionX()
etaj_unfold_plus   = unfold_plus.ProjectionX()
etaj_unfold_plus_plus  = unfold_plus_plus.ProjectionX()
etaj_unfold_plus_minus = unfold_plus_minus.ProjectionX()

etaj_reco_minus     = reco_minus.ProjectionX()
etaj_true_minus     = true_minus.ProjectionX()
etaj_unfold_minus   = unfold_minus.ProjectionX()
etaj_unfold_minus_plus  = unfold_minus_plus.ProjectionX()
etaj_unfold_minus_minus = unfold_minus_minus.ProjectionX()


a = Plot([ptj_reco_plus, ptj_true_plus, ptj_unfold_plus])
a.setProp('filename','ptj_unfold_plus')
a.setProp('location', '/user2/sfarry/WJet/figures/unfolding')
a.setProp('colors', ['red', 'blue', 'green'])
a.setProp('labels', ['reco', 'truth', 'unfolded'])
a.setProp('xlabel', 'p_{T}(j)')
a.drawROOT()

a.plots = [ptj_reco_minus, ptj_true_minus, ptj_unfold_minus]
a.setProp('filename', 'ptj_unfold_minus')
a.drawROOT()

a.plots = [etaj_reco_plus, etaj_true_plus, etaj_unfold_plus]
a.setProp('filename', 'etaj_unfold_plus')
a.setProp('xlabel'  , '#eta(j)')
a.drawROOT()

a.plots = [etaj_reco_minus, etaj_true_minus, etaj_unfold_minus]
a.setProp('filename', 'etaj_unfold_minus')
a.setProp('xlabel'  , '#eta(j)')
a.drawROOT()


b = Plot([ptj_unfold_plus, ptj_unfold_plus_plus, ptj_unfold_plus_minus])
b.setProp('filename','ptj_unfold_plus_responsecomp')
b.setProp('location', '/user2/sfarry/WJet/figures/unfolding')
b.setProp('colors', ['red', 'blue', 'green'])
b.setProp('labels', ['combined response', 'plus response', 'minus response'])
b.setProp('xlabel', 'p_{T}(j)')
b.drawROOT()

b.plots = [ptj_unfold_minus, ptj_unfold_minus_plus, ptj_unfold_minus_minus]
b.setProp('filename', 'ptj_unfold_minus_responsecomp')
b.drawROOT()

b.plots = [etaj_unfold_plus, etaj_unfold_plus_plus, etaj_unfold_plus_minus]
b.setProp('filename', 'etaj_unfold_minus_responsecomp')
b.drawROOT()

b.plots = [etaj_unfold_minus, etaj_unfold_minus_plus, etaj_unfold_minus_minus]
b.setProp('filename', 'etaj_unfold_minus_responsecomp')
b.drawROOT()
