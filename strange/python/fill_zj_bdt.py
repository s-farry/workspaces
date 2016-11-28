
from ROOT import TFile, TTree, TCut
from strange_config import *
from Jawa import *
from Utils import Bunch

zj_sel  = TCut("muminus_PT > 20000 && muplus_PT > 20000 && boson_jet_PT > 20000 && min(muminus_ETA, muplus_ETA) > 2.0 && max(muminus_ETA, muplus_ETA) < 4.5 && boson_M > 60000 && boson_M < 120000")
jet_sel = TCut("jet_PT > 20000 && jet_ETA > 2.2 && jet_ETA < 4.2")
zj_kaonmult  = TCut("boson_jet_kaonmult > 0")
jet_kaonmult = TCut("jet_kaonmult > 0")

plots = [
    Bunch(name='ptj', xlabel='p_{T}^{j} [GeV]', ylabel='[A.U.]', var='<jet>_PT/1000.0', nbins=100, lo = 20, hi = 100),
    Bunch(name='ptj25', xlabel='p_{T}^{j} [GeV]', ylabel='[A.U.]', var='<jet>_PT/1000.0', nbins=25, lo = 20, hi = 70),
    Bunch(name='ptj40', xlabel='p_{T}^{j} [GeV]', ylabel='[A.U.]', var='<jet>_PT/1000.0', nbins=40, lo = 20, hi = 100),
    Bunch(name='ptj10', xlabel='p_{T}^{j} [GeV]', ylabel='[A.U.]', var='<jet>_PT/1000.0', nbins=10, lo = 10, hi = 100),
    Bunch(name='etaj',  xlabel='#eta^{j}', ylabel='[A.U.]', var='<jet>_ETA', nbins=50, lo = 2.2, hi = 4.2),
    Bunch(name='etaj10',  xlabel='#eta^{j}', ylabel='[A.U.]', var='<jet>_ETA', nbins=10, lo = 2.2, hi = 4.2),
    Bunch(name='etaj5', xlabel='#eta^{j}', ylabel='[A.U.]', var='<jet>_ETA', nbins=5 , lo = 2.2, hi = 4.2),
    Bunch(name='kaonpt', xlabel='#sum p_{T}(kaon) [GeV]', ylabel='[A.U.]', var='<jet>_kaonpt/1000.0', nbins = 100, lo = 0, hi = 30, ynormlims = [0, 0.1]),
    Bunch(name='pionpt', xlabel='#sum p_{T}(pion) [GeV]', ylabel='[A.U.]', var='<jet>_pionpt/1000.0', nbins = 100, lo = 0, hi = 30, ynormlims = [0, 0.03]),
    Bunch(name='maxkaonpt', xlabel='p_{T}^{max.}(kaon) [GeV[', ylabel='[A.U.]', var='<jet>_maxkaonpt/1000.0', nbins = 100, lo = 0, hi = 30, ynormlims = [0, 0.12]),
    Bunch(name='maxkaonptr', xlabel='p_{T}^{max.}(kaon)/p_{T}^{j}', ylabel='[A.U.]', var='<jet>_maxkaonpt/<jet>_PT', nbins = 100, lo = 0, hi = 1, ynormlims = [0, 0.1]),
    Bunch(name='maxpionpt', xlabel='p_{T}^{max.}(pion) [GeV[', ylabel='[A.U.]', var='<jet>_maxpionpt/1000.0', nbins = 100, lo = 0, hi = 30, ynormlims=[0, 0.11]),
    Bunch(name='maxpionptr', xlabel='p_{T}^{max.}(pion)/p_{T}^{j}', ylabel='[A.U.]', var='<jet>_maxpionpt/<jet>_PT', nbins = 100, lo = 0, hi = 1, ynormlims = [0, 0.05]),
    Bunch(name='kaonmult', xlabel='Kaon Multiplicity', ylabel='[A.U.]', var='<jet>_kaonmult', nbins = 11, lo = -0.5, hi = 10.5),
    Bunch(name='kaoncmult', xlabel='Charged Kaon Multiplicity', ylabel='[A.U.]', var='<jet>_kaoncmult', nbins = 11, lo = -0.5, hi = 10.5),
    Bunch(name='pionmult', xlabel='Pion Multiplicity', ylabel='[A.U.]', var='<jet>_pionmult', nbins = 16, lo = -0.5, hi = 15.5, shiftlegx=0.2),
    Bunch(name='pioncmult', xlabel='Charged Pion Multiplicity', ylabel='[A.U.]', var='<jet>_pioncmult', nbins = 16, lo = -0.5, hi = 15.5, ylims = [0, 0.04], shiftlegx=0.2),
    Bunch(name='mj', xlabel='Jet Mass [GeV]', ylabel='[A.U.]', var='<jet>_M/1000.0', nbins = 100, lo = 0, hi = 20, ynormlims=[0, 0.07]),
    Bunch(name='wj', xlabel='Jet Width', ylabel='[A.U.]', var='<jet>_width', nbins = 100, lo = 0, hi = 0.5, shiftlegx = 0.2, ynormlims = [0, 0.05]),
    Bunch(name='multj', xlabel='Jet Multiplicity', ylabel='[A.U.]', var='<jet>_ndauts', nbins=41, lo = -0.5, hi=40.5, shiftlegx = 0.2),
    Bunch(name='jet_cpf', xlabel='Jet CPF', ylabel='[A.U.]', var='<jet>_cpf', nbins=100, lo=0, hi=1, shiftlegx=-0.3, shiftlegy=0, ynormlims=[0, 0.025]),
    Bunch(name='kaon_dr', xlabel='#Delta R(jet, kaon)', var='<jet>_K_dR', ylabel='[A.U.]', nbins=100, lo=0, hi=0.5),
    Bunch(name='pion_dr', xlabel='#Delta R(jet, pion)', var='<jet>_pi_dR', ylabel='[A.U.]', nbins=100, lo = 0, hi = 0.5),
    Bunch(name='strange_bdt',   xlabel='strange bdt', var='bdt_strange', ylabel='[A.U.]', nbins=50, lo = -1, hi = 1, ynormlims = [0, 0.07], shiftlegx = 0.2),
    Bunch(name='gluon_bdt',   xlabel='gluon bdt', var='bdt_gluon', ylabel='[A.U.]', nbins=50, lo = -1, hi = 1, ynormlims = [0, 0.07]),
    Bunch(name='strange_bdt20',   xlabel='strange bdt', var='bdt_strange', ylabel='[A.U.]', nbins=20, lo = -1, hi = 1, ynormlims = [0, 0.07]),
    Bunch(name='gluon_bdt20',   xlabel='gluon bdt', var='bdt_gluon', ylabel='[A.U.]', nbins=20, lo = -1, hi = 1, ynormlims = [0, 0.2]),
    Bunch(name='strange_bdt15',   xlabel='strange bdt', var='bdt_strange', ylabel='[A.U.]', nbins=15, lo = -1, hi = 1, ynormlims = [0, 0.07]),
    Bunch(name='gluon_bdt15',   xlabel='gluon bdt', var='bdt_gluon', ylabel='[A.U.]', nbins=15, lo = -1, hi = 1, ynormlims = [0, 0.25]),
    Bunch(name='strange_bdt10',   xlabel='strange bdt', var='bdt_strange', ylabel='[A.U.]', nbins=10, lo = -1, hi = 1, ynormlims = [0, 0.3]),
    Bunch(name='gluon_bdt10',   xlabel='gluon bdt', var='bdt_gluon', ylabel='[A.U.]', nbins=10, lo = -1, hi = 1, ynormlims = [0, 0.07]),
    Bunch(name='charge', xlabel='jet charge', var='<jet>_charge', ylabel='[A.U.]', nbins=100, lo = -1, hi = 1, ynormlims = [0, 0.05]),
    Bunch(name='leadingid', xlabel='leading id', var='abs(<jet>_leading_id)', ylabel='[A.U.]', nbins=100, lo = 0, hi = 400, shiftlegx=0.2)
    ]





zjetvars = [
    ['BDT', 'BDT', 50, -1, 1],
    ['ptj', 'boson_jet_PT/1000', 50, 20,70],
    ['ptj10', 'boson_jet_PT/1000', 10, 20,70],
    ['etaj', 'boson_jet_ETA', 50, 2.2,4.2],
    ['etaj5', 'boson_jet_ETA', 5, 2.2,4.2]
]
jetvars = [
    ['BDT', 'BDT', 50, -1, 1],
    ['ptj', 'jet_PT/1000', 50, 20,70],
    ['ptj10', 'jet_PT/1000', 10, 20,70],
    ['etaj', 'jet_ETA', 50, 2.2,4.2],
    ['etaj5', 'jet_ETA', 5, 2.2,4.2]
]

vars2d = [
    ['ptj10', 'etaj5'],
    ['ptj40', 'etaj10'],
    ['strange_bdt', 'etaj5'],
    ['gluon_bdt', 'etaj5'],
    ['strange_bdt10', 'gluon_bdt10'],
    ['strange_bdt20', 'gluon_bdt20'],
    ['multj', 'wj'],
    ['multj', 'mj'],
    ['wj', 'mj']
]

# get weight file
inF = TFile("/user2/sfarry/workspaces/strange/tuples/dijet2zj_weights.root")
ptj_weights = inF.Get('ptj_weights')
ptj_etaj_weights = inF.Get('ptj_etaj_weights')

make_weights = True

'''
zmumuj_data2012_t = Template("zmumuj_data2012")
zmumuj_data2012_t.SetSelCut(zj_sel )
zmumuj_data2012_t.AddTrees(zmumuj_2012.trees())
for p in plots:
    zmumuj_data2012_t.AddVar([p.name, p.var.replace('<jet>','boson_jet'), p.nbins, p.lo, p.hi])
zmumuj_data2012_t.Run()
zmumuj_data2012_t.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_data2012.root")

zmumuj_mc2012_t = Template("zmumuj_mc2012")
zmumuj_mc2012_t.SetSelCut(zj_sel )
zmumuj_mc2012_t.AddTrees(zmumuj_mc2012.trees())
for p in plots:
    zmumuj_mc2012_t.AddVar([p.name, p.var.replace('<jet>','boson_jet'), p.nbins, p.lo, p.hi])
zmumuj_mc2012_t.Add2DVars(vars2d)
zmumuj_mc2012_t.Run()
zmumuj_mc2012_t.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2012.root")

#ff = TFile("/hepstore/sfarry/GridOutput/2192/Zmumujet.Z_mumujet17.MU.MC2015.root")
#tt = ff.Get("ZMuMu/DecayTree")
#ff2 = TFile("/hepstore/sfarry/GridOutput/2192/Zmumujet.Z_mumujet17.MU.MC2015.MVA.root")
#tt.AddFriend(ff2.Get("tree"))
#gg = TFile("/hepstore/sfarry/GridOutput/2193/Zmumujet.Z_mumujet17.MD.MC2015.root")
#uu = gg.Get("ZMuMu/DecayTree")
#gg2 = TFile("/hepstore/sfarry/GridOutput/2193/Zmumujet.Z_mumujet17.MD.MC2015.MVA.root")
#uu.AddFriend(gg2.Get("tree"))

zmumuj_hf_mc2012_t = Template("zmumuj_hf_mc2012")
zmumuj_hf_mc2012_t.SetSelCut(zj_sel  + zj_hftag)
zmumuj_hf_mc2012_t.AddTrees(zmumuj_mc2012.trees())
for p in plots:
    zmumuj_hf_mc2012_t.AddVar([p.name, p.var.replace('<jet>','boson_jet'), p.nbins, p.lo, p.hi])
zmumuj_hf_mc2012_t.Add2DVars(vars2d)
zmumuj_hf_mc2012_t.Run()
zmumuj_hf_mc2012_t.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_hf_mc2012.root")

zmumuj_mc2015_t = Template("zmumuj_mc2015")
zmumuj_mc2015_t.SetSelCut(zj_sel )
zmumuj_mc2015_t.AddTrees(zmumuj_mc2015.trees())
for p in plots:
    zmumuj_mc2015_t.AddVar([p.name, p.var.replace('<jet>','boson_jet'), p.nbins, p.lo, p.hi])
zmumuj_mc2015_t.Add2DVars(vars2d)
zmumuj_mc2015_t.Run()
zmumuj_mc2015_t.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015.root")

zmumuj_hf_mc2015_t = Template("zmumuj_hf_mc2015")
zmumuj_hf_mc2015_t.SetSelCut(zj_sel  + zj_hftag)
zmumuj_hf_mc2015_t.AddTrees(zmumuj_mc2015.trees())
for p in plots:
    zmumuj_hf_mc2015_t.AddVar([p.name, p.var.replace('<jet>','boson_jet'), p.nbins, p.lo, p.hi])
zmumuj_hf_mc2015_t.Add2DVars(vars2d)
zmumuj_hf_mc2015_t.Run()
zmumuj_hf_mc2015_t.SaveToFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_hf_mc2015.root")

#get shapes from others
dijet_mc2015 = Template("dijet_mc2015")
dijet_mc2015.SetSelCut(jet_sel )
#dijet_mc2015.AddTrees(jet_pt10_15.trees())
#dijet_mc2015.AddTrees(jet_pt15_20.trees())
dijet_mc2015.AddTrees(jet_pt20_50.trees())
dijet_mc2015.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015.Add2DVars(vars2d)
if not make_weights: dijet_mc2015.Reweight('jet_PT/1000.0', ptj_weights)
dijet_mc2015.Run()
dijet_mc2015.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015.root")
'''
###################
# strange
###################

zmumuj_strange = TFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015_strange.root")
strange_weights = zmumuj_strange.Get("ptj")
strange_weights.Scale(1/strange_weights.Integral())
strange_weights2d = zmumuj_strange.Get("ptj_etaj")
strange_weights2d.Scale(1/strange_weights2d.Integral())

dijet_mc2015_strange_unw = Template("dijet_mc2015_strange_unw")
dijet_mc2015_strange_unw.SetSelCut(jet_sel  + truth_stag)
dijet_mc2015_strange_unw.AddTrees(jet_pt20_50.trees())
dijet_mc2015_strange_unw.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_strange_unw.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_strange_unw.Add2DVars(vars2d)
dijet_mc2015_strange_unw.Run()
dijet_mc2015_strange_unw.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_strange_unw.root")

strange_denom = dijet_mc2015_strange_unw.GetVar('ptj40').GetHist()
strange_denom.Scale(1.0/strange_denom.Integral())
strange_weights.Divide(strange_denom)

strange_denom2d = dijet_mc2015_strange_unw.Get2DVar('ptj40','etaj10').GetHist()
strange_denom2d.Scale(1.0/strange_denom2d.Integral())
strange_weights2d.Divide(strange_denom2d)


dijet_mc2015_strange = Template("dijet_mc2015_strange")
dijet_mc2015_strange.SetSelCut(jet_sel  + truth_stag)
dijet_mc2015_strange.AddTrees(jet_pt20_50.trees())
dijet_mc2015_strange.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_strange.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_strange.Add2DVars(vars2d)
dijet_mc2015_strange.Reweight('jet_PT/1000.0', strange_weights)
dijet_mc2015_strange.Run()
dijet_mc2015_strange.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_strange.root")

dijet_mc2015_strange_etaw = Template("dijet_mc2015_strange_etaw")
dijet_mc2015_strange_etaw.SetSelCut(jet_sel  + truth_stag)
dijet_mc2015_strange_etaw.AddTrees(jet_pt20_50.trees())
dijet_mc2015_strange_etaw.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_strange_etaw.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_strange_etaw.Add2DVars(vars2d)
#dijet_mc2015_strange_etaw.Reweight('jet_PT/1000.0', strange_weights)
#dijet_mc2015_strange_etaw.Reweight('jet_ETA', strange_etaj_weights)
dijet_mc2015_strange_etaw.Reweight('jet_PT/1000.0', 'jet_ETA', strange_weights2d)
dijet_mc2015_strange_etaw.Run()
dijet_mc2015_strange_etaw.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_strange_etaw.root")


##################
# quark
##################

zmumuj_quark = TFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015_quark.root")
quark_weights = zmumuj_quark.Get("ptj")
quark_weights.Scale(1/quark_weights.Integral())
quark_weights2d = zmumuj_quark.Get("ptj_etaj")
quark_weights2d.Scale(1/quark_weights2d.Integral())

dijet_mc2015_quark_unw = Template("dijet_mc2015_quark_unw")
dijet_mc2015_quark_unw.SetSelCut(jet_sel  + truth_qtag)
dijet_mc2015_quark_unw.AddTrees(jet_pt20_50.trees())
dijet_mc2015_quark_unw.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_quark_unw.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_quark_unw.Add2DVars(vars2d)
dijet_mc2015_quark_unw.Run()
dijet_mc2015_quark_unw.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_quark_unw.root")

quark_denom = dijet_mc2015_quark_unw.GetVar('ptj40').GetHist()
quark_denom.Scale(1.0/quark_denom.Integral())
quark_weights.Divide(quark_denom)

quark_denom2d = dijet_mc2015_quark_unw.Get2DVar('ptj40','etaj10').GetHist()
quark_denom2d.Scale(1.0/quark_denom2d.Integral())
quark_weights2d.Divide(quark_denom2d)

dijet_mc2015_quark = Template("dijet_mc2015_quark")
dijet_mc2015_quark.SetSelCut(jet_sel  + truth_qtag)
dijet_mc2015_quark.AddTrees(jet_pt20_50.trees())
dijet_mc2015_quark.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_quark.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_quark.Add2DVars(vars2d)
dijet_mc2015_quark.Reweight('jet_PT/1000.0', quark_weights)
dijet_mc2015_quark.Run()
dijet_mc2015_quark.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_quark.root")

strange_etaj = dijet_mc2015_strange.GetVar("etaj").GetHist().Clone('strange_etaj')
quark_etaj = dijet_mc2015_quark.GetVar("etaj").GetHist().Clone('quark_etaj')
strange_etaj.Scale(1.0/strange_etaj.Integral())
quark_etaj.Scale(1.0/quark_etaj.Integral())
quark_etaj_weights = strange_etaj.Clone('quark_etaj_weights')
quark_etaj_weights.Divide(quark_etaj)

dijet_mc2015_quark_etaw = Template("dijet_mc2015_quark_etaw")
dijet_mc2015_quark_etaw.SetSelCut(jet_sel  + truth_qtag)
dijet_mc2015_quark_etaw.AddTrees(jet_pt20_50.trees())
dijet_mc2015_quark_etaw.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_quark_etaw.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_quark_etaw.Add2DVars(vars2d)
#dijet_mc2015_quark_etaw.Reweight('jet_PT/1000.0', quark_weights)
#dijet_mc2015_quark_etaw.Reweight('jet_ETA', quark_etaj_weights)
dijet_mc2015_quark_etaw.Reweight('jet_PT/1000.0', 'jet_ETA', quark_weights2d)
dijet_mc2015_quark_etaw.Run()
dijet_mc2015_quark_etaw.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_quark_etaw.root")


###################
# strange as quark (check differences don't come from kinematics)
##################
s_as_q_weights = dijet_mc2015_strange.Get2DVar('ptj40','etaj10').GetHist().Clone('s_as_q_weights')
s_as_q_denom   = dijet_mc2015_quark.Get2DVar('ptj40', 'etaj10', 'ptj').GetHist().Clone('s_as_q_weights')

s_as_q_weights.Scale(1.0/s_as_q_weights.Integral())
s_as_q_denom.Scale(1.0/s_as_q_denom.Integral())
s_as_q_weights.Divide(s_as_q_denom)


dijet_mc2015_strange_asq = Template("dijet_mc2015_strange_asq")
dijet_mc2015_strange_asq.SetSelCut(jet_sel  + truth_stag)
dijet_mc2015_strange_asq.AddTrees(jet_pt20_50.trees())
dijet_mc2015_strange_asq.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_strange_asq.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_strange_asq.Add2DVars(vars2d)
dijet_mc2015_strange_asq.Reweight('jet_PT/1000.0', 'jet_ETA', s_as_q_weights)
dijet_mc2015_strange_asq.Run()
dijet_mc2015_strange_asq.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_strange_asq.root")


'''

####################
# gluon
###################

zmumuj_gluon = TFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015_gluon.root")
gluon_weights = zmumuj_gluon.Get("ptj")
gluon_weights.Scale(1/gluon_weights.Integral())
gluon_weights2d = zmumuj_gluon.Get("ptj_etaj")
gluon_weights2d.Scale(1/gluon_weights2d.Integral())

dijet_mc2015_gluon_unw = Template("dijet_mc2015_gluon_unw")
dijet_mc2015_gluon_unw.SetSelCut(jet_sel  + truth_gtag)
dijet_mc2015_gluon_unw.AddTrees(jet_pt20_50.trees())
dijet_mc2015_gluon_unw.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_gluon_unw.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_gluon_unw.Add2DVars(vars2d)
dijet_mc2015_gluon_unw.Run()
dijet_mc2015_gluon_unw.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_gluon_unw.root")

gluon_denom = dijet_mc2015_gluon_unw.GetVar('ptj40').GetHist()
gluon_denom.Scale(1.0/gluon_denom.Integral())
gluon_weights.Divide(gluon_denom)

gluon_denom2d = dijet_mc2015_gluon_unw.Get2DVar('ptj40','etaj10').GetHist()
gluon_denom2d.Scale(1.0/gluon_denom2d.Integral())
gluon_weights2d.Divide(gluon_denom2d)

dijet_mc2015_gluon = Template("dijet_mc2015_gluon")
dijet_mc2015_gluon.SetSelCut(jet_sel  + truth_gtag)
dijet_mc2015_gluon.AddTrees(jet_pt20_50.trees())
dijet_mc2015_gluon.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_gluon.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_gluon.Add2DVars(vars2d)
dijet_mc2015_gluon.Reweight('jet_PT/1000.0', gluon_weights)
dijet_mc2015_gluon.Run()
dijet_mc2015_gluon.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_gluon.root")

dijet_mc2015_gluon_etaw = Template("dijet_mc2015_gluon_etaw")
dijet_mc2015_gluon_etaw.SetSelCut(jet_sel  + truth_qtag)
dijet_mc2015_gluon_etaw.AddTrees(jet_pt20_50.trees())
dijet_mc2015_gluon_etaw.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_gluon_etaw.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_gluon_etaw.Add2DVars(vars2d)
#dijet_mc2015_gluon_etaw.Reweight('jet_PT/1000.0', gluon_weights)
#dijet_mc2015_gluon_etaw.Reweight('jet_ETA', gluon_etaj_weights)
dijet_mc2015_gluon_etaw.Reweight('jet_PT/1000.0', 'jet_ETA', gluon_weights2d)
dijet_mc2015_gluon_etaw.Run()
dijet_mc2015_gluon_etaw.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_gluon_etaw.root")

########################
# unmatched
#######################

dijet_mc2015_unmatched = Template("dijet_mc2015_unmatched")
dijet_mc2015_unmatched.SetSelCut(jet_sel  + truth_notag)
dijet_mc2015_unmatched.AddTrees(jet_pt20_50.trees())
dijet_mc2015_unmatched.AddTrees(jet_pt50.trees())
for p in plots:
    dijet_mc2015_unmatched.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dijet_mc2015_unmatched.Add2DVars(vars2d)
dijet_mc2015_unmatched.Run()
dijet_mc2015_unmatched.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_unmatched.root")

#make weight files
outF = TFile("/user2/sfarry/workspaces/strange/tuples/dijet2zj_weights.root", "RECREATE")
gluon_weights.Write("gluon_weights")
gluon_weights2d.Write("gluon_weights2d")
quark_weights.Write("quark_weights")
quark_weights2d.Write("quark_weights2d")
strange_weights.Write("strange_weights")
strange_weights2d.Write("strange_weights2d")
outF.Close()

'''

from Style import *
from PlotTools import *
SetLHCbStyle()
'''
#plot2d = dijet_mc2015_bkg.Get2DVar("strange_bdt", "etaj5").GetHist()
#bdtplots = [plot2d.ProjectionX(str(i), i+1,i+1) for i in range(5)]


#p = Plot(bdtplots)
#p.setProp('labels', ['eta0', 'eta1', 'eta2', 'eta3','eta4'])
#p.setProp('filename', 'test4.pdf')
#p.setProp('colors', ['red', 'blue', 'green', 'yellow','black'])
#p.setProp('markerstyles', 20)
#p.setProp('normalised', True)
#p.setProp('xlabel', 'BDT')
#p.setProp('ylabel', '[A.U.]')
#p.setProp('ynormlims', [0, 0.05])
#p.drawROOT()

for p in plots:
    p2 = Plot([dijet_mc2015.GetVar(p.name).GetHist(), dijet_mc2015_strange.GetVar(p.name).GetHist(), zmumuj_mc2015_t.GetVar(p.name).GetHist()])
    p2.setProp('filename', 'sig_bkg_'+p.name)
    p2.setProp('location', '/user2/sfarry/workspaces/strange/figures')
    p2.setProp('drawOpts', 'h')
    p2.setProp('linecolors', ['black', 'red', 'blue'])
    p2.setProp('fillstyles', 0)
    p2.setProp('labels', ['dijet', 'strange', 'Zj'])
    p2.setProp('markerstyles', 20)
    p2.setProp('xlabel', p.xlabel)
    p2.setProp('ylabel', p.ylabel)
    p2.setProp('leglims', [0.45, 0.5, 0.75, 0.9])
    p2.setProp('normalised', True)
    if hasattr(p, 'shiftlegx'): p2.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): p2.ShiftLegY(p.shiftlegy)
    if hasattr(p, 'ynormlims'): p2.setProp('ynormlims', p.ynormlims)
    #p2.setProp('ynormlims', [0, 0.2])
    p2.drawROOT()
'''

for p in plots:
    p3 = Plot([dijet_mc2015_strange.GetVar(p.name).GetHist(), dijet_mc2015_quark.GetVar(p.name).GetHist(), dijet_mc2015_gluon.GetVar(p.name).GetHist(), zmumuj_mc2015_t.GetVar(p.name).GetHist()])
    p3.setProp('filename', 'dijet_flavours_'+p.name)
    p3.setProp('location', '/user2/sfarry/workspaces/strange/figures')
    p3.setProp('drawOpts', 'h')
    p3.setProp('linecolors', ['black', 'red', 'blue', 'green'])
    p3.setProp('fillstyles', 0)
    p3.setProp('labels', ['strange', 'quark', 'gluon', 'Zj'])
    p3.setProp('markerstyles', 20)
    p3.setProp('xlabel', p.xlabel)
    p3.setProp('ylabel', p.ylabel)
    p3.setProp('leglims', [0.45, 0.5, 0.75, 0.9])
    p3.setProp('normalised', True)
    if hasattr(p, 'shiftlegx'): p3.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): p3.ShiftLegY(p.shiftlegy)
    if hasattr(p, 'ynormlims'): p3.setProp('ynormlims', p.ynormlims)
    #p2.setProp('ynormlims', [0, 0.2])
    p3.drawROOT()
