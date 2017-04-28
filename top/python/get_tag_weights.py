from ROOT import *
from Jawa import *

f = TFile("/user2/sfarry/workspaces/top/tuples/j_untagged_unw.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/b_j_untagged.root")
oF = TFile("/user2/sfarry/workspaces/top/tuples/jet_tagging_weights_new.root", "RECREATE")

pt_weights  = GetWeightHist("pt_weights", g.Get("pt"), f.Get("pt"))
eta_weights = GetWeightHist("eta_weights", g.Get("eta"), f.Get("eta"))
eta_pt_weights = GetWeightHist2D("eta_pt_weights", g.Get("eta5_pt10"), f.Get("eta5_pt10"))

pt_weights.Write()
eta_weights.Write()
eta_pt_weights.Write()

oF.Close()
