from ROOT import *
from Jawa import *
from Utils import Bunch

f = TFile("/hepstore/sfarry/GridOutput/2973/dijet.MD.2016.root")
g = TFile("/hepstore/sfarry/GridOutput/2974/dijet.MU.2016.root")

h = TFile("/hepstore/sfarry/GridOutput/2983/dijet.dijet_udsg.MU.MC2016.root")
i = TFile("/hepstore/sfarry/GridOutput/2984/dijet.dijet_udsg.MD.MC2016.root")
jj = TFile("/hepstore/sfarry/GridOutput/2985/dijet.dijet_b.MU.MC2016.root")
k = TFile("/hepstore/sfarry/GridOutput/2986/dijet.dijet_b.MD.MC2016.root")
l = TFile("/hepstore/sfarry/GridOutput/2987/dijet.dijet_c.MU.MC2016.root")
m = TFile("/hepstore/sfarry/GridOutput/2988/dijet.dijet_c.MD.MC2016.root")

weights        = TFile("/user2/sfarry/workspaces/top/tuples/jet_tagging_weights_new.root")
pt_weights     = weights.Get('pt_weights')
eta_pt_weights = weights.Get('eta_pt_weights')

vars = [
    Bunch(name="leading_ip", var = "<jet>_leading_ip", bins = 20, lo=0, hi=0.25),
    Bunch(name="leading_ipchi2", var = "log10(<jet>_leading_ipchi2)", bins = 20, lo=-3, hi=5),
    Bunch(name="avip", var = "<jet>_avip", bins = 20, lo=0, hi=0.25),
    Bunch(name="avipchi2", var = "log10(<jet>_avipchi2)", bins = 20, lo=-3, hi=5),
    Bunch(name="pt", var = "<jet>_PT/1000.0", bins = 100, lo = 20.0, hi = 100.0),
    Bunch(name="eta", var = "<jet>_ETA", bins = 100, lo = 2.2, hi = 4.2),
    Bunch(name="eta5", var = "<jet>_ETA", bins = 5, lo = 2.2, hi = 4.2),
    Bunch(name="pt10", var = "<jet>_PT/1000.0", bins = 10, lo = 20.0, hi = 100.0),
    Bunch(name="dijet_m", var = "dijet_M", bins = 100, lo = 2000, hi = 100000)
]

vars2d = [
    ['eta5', 'pt10']
]

tag1 = TCut("j1_BDTTag == 1")
tag2 = TCut("j2_BDTTag == 1")

pi=str(TMath.Pi())

dphi = TCut("(abs(<A>_PHI - <B>_PHI) + (abs(<A>_PHI - <B>_PHI) > <pi>)*2*(<pi> - abs(<A>_PHI - <B>_PHI) )) > 2.7".replace('<pi>', pi).replace("<A>",'j1').replace("<B>",'j2'))
eta = TCut("j1_ETA > 2.2 && j1_ETA < 4.2 && j2_ETA > 2.2 && j2_ETA < 4.2")
dijetm = TCut("dijet_M > 0")
muon1 = TCut("abs(j1_leading_id) == 13")
muon2 = TCut("abs(j2_leading_id) == 13")

probe1 = dphi + eta + tag1
probe2 = dphi + eta + tag2
probe1_notag = dphi + eta + tag1
probe2_notag = dphi + eta + tag2
trueb1 = TCut("abs(j1_mc_flavour) == 5")
trueb2 = TCut("abs(j2_mc_flavour) == 5")
truec1 = TCut("abs(j1_mc_flavour) == 4")
truec2 = TCut("abs(j2_mc_flavour) == 4")
truel1 = TCut("abs(j1_mc_flavour) != 5 && abs(j1_mc_flavour) != 6 && j1_mc_PT > 0")
truel2 = TCut("abs(j2_mc_flavour) != 5 && abs(j2_mc_flavour) != 6 && j2_mc_PT > 0")
'''
j1 = Template("j1")
j1.SetSelCut(probe2 + dijetm + muon1)
j1.AddTree(f.Get("dijet/DecayTree"))
j1.AddTree(g.Get("dijet/DecayTree"))
#j1.Reweight('j1_PT/1000.0', pt_weights)
j1.Reweight('j1_ETA', 'j1_PT/1000.0', eta_pt_weights)
for v in vars:
    j1.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
j1.Add2DVars(vars2d)
j1.Run()

j2 = Template("j2")
j2.SetSelCut(probe1 + dijetm + muon2)
j2.AddTree(f.Get("dijet/DecayTree"))
j2.AddTree(g.Get("dijet/DecayTree"))
#j2.Reweight('j2_PT/1000.0', pt_weights)
j2.Reweight('j2_ETA', 'j2_PT/1000.0', pt_weights)
for v in vars:
    j2.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
j2.Add2DVars(vars2d)
j2.Run()

j = Template("j", j1, j2)
j.SaveToFile("/user2/sfarry/workspaces/top/tuples/j_untagged.root")
'''
'''
j1_unw = Template("j1_unw")
j1_unw.SetSelCut(probe2 + dijetm + muon1)
j1_unw.AddTree(f.Get("dijet/DecayTree"))
j1_unw.AddTree(g.Get("dijet/DecayTree"))
for v in vars:
    j1_unw.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
j1_unw.Add2DVars(vars2d)
j1_unw.Run()

j2_unw = Template("j2_unw")
j2_unw.SetSelCut(probe1 + dijetm + muon2)
j2_unw.AddTree(f.Get("dijet/DecayTree"))
j2_unw.AddTree(g.Get("dijet/DecayTree"))
for v in vars:
    j2_unw.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
j2_unw.Add2DVars(vars2d)
j2_unw.Run()

j_unw = Template("j", j1_unw, j2_unw)
j_unw.SaveToFile("/user2/sfarry/workspaces/top/tuples/j_untagged_unw.root")
'''
'''
j1_tagged = Template("j1_tagged")
j1_tagged.SetSelCut(probe2 + dijetm + tag1 + muon1)
j1_tagged.AddTree(f.Get("dijet/DecayTree"))
j1_tagged.AddTree(g.Get("dijet/DecayTree"))
#j1_tagged.Reweight('j1_PT/1000.0', pt_weights)
j1_tagged.Reweight('j1_ETA', 'j1_PT/1000.0', eta_pt_weights)
for v in vars:
    j1_tagged.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
j1_tagged.Add2DVars(vars2d)
j1_tagged.Run()

j2_tagged = Template("j2_tagged")
j2_tagged.SetSelCut(probe1 + dijetm + tag2 + muon2)
j2_tagged.AddTree(f.Get("dijet/DecayTree"))
j2_tagged.AddTree(g.Get("dijet/DecayTree"))
#j2_tagged.Reweight('j2_PT/1000.0', pt_weights)
j2_tagged.Reweight('j2_ETA', 'j2_PT/1000.0', eta_pt_weights)
for v in vars:
    j2_tagged.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
j2.Add2DVars(vars2d)
j2_tagged.Run()

j_tagged = Template("j_tagged", j1_tagged, j2_tagged)
j_tagged.SaveToFile("/user2/sfarry/workspaces/top/tuples/j_tagged.root")
'''
#charm

c_j1 = Template("c_j1")
c_j1.SetSelCut(probe2_notag + dijetm + truec1)
c_j1.AddTree(l.Get("dijet/DecayTree"))
c_j1.AddTree(m.Get("dijet/DecayTree"))
for v in vars:
    c_j1.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
c_j1.Add2DVars(vars2d)
c_j1.Run()

c_j2 = Template("c_j2")
c_j2.SetSelCut(probe1_notag + dijetm + truec2)
c_j2.AddTree(l.Get("dijet/DecayTree"))
c_j2.AddTree(m.Get("dijet/DecayTree"))
for v in vars:
    c_j2.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
c_j2.Add2DVars(vars2d)
c_j2.Run()

c_j = Template("c_j", c_j1, c_j2)
c_j.SaveToFile("/user2/sfarry/workspaces/top/tuples/c_j_untagged.root")

c_j1_tagged = Template("c_j1_tagged")
c_j1_tagged.SetSelCut(probe2_notag + tag1 + dijetm + truec1)
c_j1_tagged.AddTree(l.Get("dijet/DecayTree"))
c_j1_tagged.AddTree(m.Get("dijet/DecayTree"))
for v in vars:
    c_j1_tagged.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
c_j1_tagged.Add2DVars(vars2d)
c_j1_tagged.Run()

c_j2_tagged = Template("c_j2_tagged")
c_j2_tagged.SetSelCut(probe1_notag + tag2 + dijetm + truec2)
c_j2_tagged.AddTree(l.Get("dijet/DecayTree"))
c_j2_tagged.AddTree(m.Get("dijet/DecayTree"))
for v in vars:
    c_j2_tagged.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
c_j2_tagged.Add2DVars(vars2d)
c_j2_tagged.Run()

c_j_tagged = Template("c_j_tagged", c_j1_tagged, c_j2_tagged)
c_j_tagged.SaveToFile("/user2/sfarry/workspaces/top/tuples/c_j_tagged.root")

b_j1 = Template("b_j1")
b_j1.SetSelCut(probe2_notag + dijetm + muon1 + trueb1)
b_j1.AddTree(jj.Get("dijet/DecayTree"))
b_j1.AddTree(k.Get("dijet/DecayTree"))
for v in vars:
    b_j1.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
b_j1.Add2DVars(vars2d)
b_j1.Run()

b_j2 = Template("b_j2")
b_j2.SetSelCut(probe1_notag + dijetm + muon2 + trueb2)
b_j2.AddTree(jj.Get("dijet/DecayTree"))
b_j2.AddTree(k.Get("dijet/DecayTree"))
for v in vars:
    b_j2.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
b_j2.Add2DVars(vars2d)
b_j2.Run()

b_j = Template("b_j", b_j1, b_j2)
b_j.SaveToFile("/user2/sfarry/workspaces/top/tuples/b_j_untagged.root")

b_j1_tagged = Template("b_j1_tagged")
b_j1_tagged.SetSelCut(probe2_notag + dijetm + tag1 + muon1 + trueb1)
b_j1_tagged.AddTree(jj.Get("dijet/DecayTree"))
b_j1_tagged.AddTree(k.Get("dijet/DecayTree"))
for v in vars:
    b_j1_tagged.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
b_j1_tagged.Add2DVars(vars2d)
b_j1_tagged.Run()

b_j2_tagged = Template("b_j2_tagged")
b_j2_tagged.SetSelCut(probe1_notag + dijetm + tag2 + muon2 + trueb2)
b_j2_tagged.AddTree(jj.Get("dijet/DecayTree"))
b_j2_tagged.AddTree(k.Get("dijet/DecayTree"))
for v in vars:
    b_j2_tagged.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
b_j2_tagged.Add2DVars(vars2d)
b_j2_tagged.Run()

b_j_tagged = Template("b_j_tagged", b_j1_tagged, b_j2_tagged)
b_j_tagged.SaveToFile("/user2/sfarry/workspaces/top/tuples/b_j_tagged.root")

l_j1 = Template("l_j1")
l_j1.SetSelCut(truel1 + dijetm)
l_j1.AddTree(h.Get("dijet/DecayTree"))
l_j1.AddTree(i.Get("dijet/DecayTree"))
for v in vars:
    l_j1.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
l_j1.Add2DVars(vars2d)
l_j1.Run()

l_j2 = Template("l_j2")
l_j2.SetSelCut(truel2 + dijetm)
l_j2.AddTree(h.Get("dijet/DecayTree"))
l_j2.AddTree(i.Get("dijet/DecayTree"))
for v in vars:
    l_j2.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
l_j2.Add2DVars(vars2d)
l_j2.Run()

l_j = Template("l_j", l_j1, l_j2)
l_j.SaveToFile("/user2/sfarry/workspaces/top/tuples/l_j_untagged.root")

l_j1_tagged = Template("l_j1_tagged")
l_j1_tagged.SetSelCut(tag1 + dijetm + truel1)
l_j1_tagged.AddTree(h.Get("dijet/DecayTree"))
l_j1_tagged.AddTree(i.Get("dijet/DecayTree"))
for v in vars:
    l_j1_tagged.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
l_j1_tagged.Add2DVars(vars2d)
l_j1_tagged.Run()

l_j2_tagged = Template("l_j2_tagged")
l_j2_tagged.SetSelCut(tag2 + dijetm + truel2)
l_j2_tagged.AddTree(h.Get("dijet/DecayTree"))
l_j2_tagged.AddTree(i.Get("dijet/DecayTree"))
for v in vars:
    l_j2_tagged.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
l_j2.Add2DVars(vars2d)
l_j2_tagged.Run()

l_j_tagged = Template("l_j_tagged", l_j1_tagged, l_j2_tagged)
l_j_tagged.SaveToFile("/user2/sfarry/workspaces/top/tuples/l_j_tagged.root")


b_j1_eff = EfficiencyClass("b_j1_eff")
b_j1_eff.SetSelectionCut(probe2_notag + dijetm + muon1 + trueb1)
b_j1_eff.AddTree(jj.Get("dijet/DecayTree"))
b_j1_eff.AddTree(k.Get("dijet/DecayTree"))
for v in vars:
    b_j1_eff.AddVar([v.name, v.var.replace('<jet>','j1'), v.bins, v.lo, v.hi])
b_j1_eff.Add2DVars(vars2d)
b_j1_eff.SetPassCut(tag1)
b_j1_eff.Run()

b_j2_eff = EfficiencyClass("b_j2_eff")
b_j2_eff.SetSelectionCut(probe1_notag + dijetm + muon2 + trueb2)
b_j2_eff.AddTree(jj.Get("dijet/DecayTree"))
b_j2_eff.AddTree(k.Get("dijet/DecayTree"))
for v in vars:
    b_j2_eff.AddVar([v.name, v.var.replace('<jet>','j2'), v.bins, v.lo, v.hi])
b_j2_eff.Add2DVars(vars2d)
b_j2_eff.SetPassCut(tag2)
b_j2_eff.Run()

b_j_eff = EfficiencyClass("b_j_eff", b_j1_eff, b_j2_eff)
b_j_eff.MakeEfficiencyGraph()
b_j_eff.SaveToFile("/user2/sfarry/workspaces/top/tuples/b_j_eff.root")
