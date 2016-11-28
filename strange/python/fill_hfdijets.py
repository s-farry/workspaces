
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

##################
# b jets
##################

zmumuj_quark = TFile("/user2/sfarry/workspaces/strange/tuples/zmumuj_mc2015_quark.root")
quark_weights = zmumuj_quark.Get("ptj")
quark_weights.Scale(1/quark_weights.Integral())
quark_weights2d = zmumuj_quark.Get("ptj_etaj")
quark_weights2d.Scale(1/quark_weights2d.Integral())

dibjet_mc2015_beauty_unw = Template("dibjet_mc2015_beauty_unw")
dibjet_mc2015_beauty_unw.SetSelCut(jet_sel  + truth_btag)
dibjet_mc2015_beauty_unw.AddTrees(jet_pt20_50.trees())
dibjet_mc2015_beauty_unw.AddTrees(jet_pt50.trees())
for p in plots:
    dibjet_mc2015_beauty_unw.AddVar([p.name, p.var.replace('<jet>','jet'), p.nbins, p.lo, p.hi])
dibjet_mc2015_beauty_unw.Add2DVars(vars2d)
dibjet_mc2015_beauty_unw.Run()
dibjet_mc2015_beauty_unw.SaveToFile("/user2/sfarry/workspaces/strange/tuples/dijet_mc2015_beauty_unw.root")
