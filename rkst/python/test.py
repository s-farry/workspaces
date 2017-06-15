from ROOT import TFile, TTree, TCut
from Jawa import *
from PlotTools import *
from Utils import Bunch

f = TFile("/hepstore/sfarry/GridOutput/3129/BjpsiK.BJpsiK.MU.MC2016.root")
g = TFile("/hepstore/sfarry/GridOutput/3130/BjpsiK.BJpsiK.MD.MC2016.root")
t = f.Get("BJpsiKDT/DecayTree")
u = g.Get("BJpsiKDT/DecayTree")
v = f.Get("BJpsiKDT_tp/DecayTree")
w = g.Get("BJpsiKDT_tp/DecayTree")
x = f.Get("BJpsiK/TrueTree")
y = g.Get("BJpsiK/TrueTree")

true_lp_pt   = TCut("lp_PT > 500")
true_rec_lp  = TCut("lp_rec_PT > 0")
true_stub_lp = TCut("lp_stub_PT > 0")

true_lm_pt   = TCut("lm_PT > 500")
true_rec_lm  = TCut("lm_rec_PT > 0")
true_stub_lm = TCut("lm_stub_PT > 0")

passcut = TCut("probe_deltaR < 0.02 && probe_deltaRt < 500 && probe_VeloMatch > 0.7")
failcut = TCut("probe_deltaR > 0.02 || probe_deltaRt > 500 || probe_VeloMatch < 0.7")

dt_bunches = [
    Bunch(name='jpsi_m', var='Jpsi_M', bins = 100, lo = 2500, hi = 3500),
    Bunch(name='b_m'   , var='B_M', bins = 100, lo = 4500, hi = 5500),
    Bunch(name='b_dtf_m'   , var='B_ConsB_M', bins = 100, lo = 5000, hi = 5500),
    Bunch(name='ep_pt' , var='ep_PT', bins = 100, lo = 0, hi = 10000),
    Bunch(name='em_pt' , var='em_PT', bins = 100, lo = 0, hi = 10000),
    Bunch(name='ep_p' , var='ep_P', bins = 100, lo = 0, hi = 80000),
    Bunch(name='em_p' , var='em_P', bins = 100, lo = 0, hi = 80000),
    Bunch(name='jpsi_vtxchi2' , var='Jpsi_ENDVERTEX_CHI2/Jpsi_ENDVERTEX_NDOF', bins = 100, lo = 0, hi = 1),
    Bunch(name='b_vtxchi2'    , var='B_ENDVERTEX_CHI2/B_ENDVERTEX_NDOF', bins = 100, lo = 0, hi = 5),
    Bunch(name='ep_CaloHcalEP'    , var='ep_CaloHcalE/ep_P', bins = 100, lo = 0, hi = 0.5),
    Bunch(name='em_CaloHcalEP'    , var='em_CaloHcalE/em_P', bins = 100, lo = 0, hi = 0.5),
    Bunch(name='ep_BremMultiplicity' , var='ep_BremMultiplicity', bins = 5, lo = -0.5, hi = 4.5),
    Bunch(name='em_BremMultiplicity' , var='em_BremMultiplicity', bins = 5, lo = -0.5, hi = 4.5),
    Bunch(name='b_hop_mass', var='B_HOP_MASS', bins = 100, lo = 0, hi = 15000),
    Bunch(name='b_dira', var='B_DIRA_OWNPV', bins = 100, lo = 0.95, hi = 1),
    Bunch(name='b_fdchi2', var='B_FDCHI2_OWNPV', bins = 100, lo = 0, hi = 100),
    Bunch(name='b_bpvltime', var='B_BPVLTIME', bins = 100, lo = 0, hi = 0.01),
    Bunch(name='b_bpvlfitchi2', var='B_BPVLTFITCHI2', bins = 100, lo = 0, hi = 10),
    ]
true_bunches = [
    Bunch(name='e_pt' , var='<l>_PT', bins = 100, lo = 0, hi = 10000),
    Bunch(name='e_p' , var='<l>_P', bins = 100, lo = 0, hi = 80000),
    Bunch(name='dR' , var='<l>_stub_deltaR', bins = 100, lo = 0, hi = 0.02),
    Bunch(name='dRt' , var='<l>_stub_Long2CalodRt', bins = 100, lo = 0, hi = 1000),
    Bunch(name='RE'  , var='(<l>_stub_CaloE/cosh(lp_stub_ETA))/<l>_stub_PT', bins = 100, lo = 0, hi = 1.5),
    Bunch(name='nCommonVelo' , var='<l>_stub_nCommonVeloHits/<l>_stub_nVeloHits', bins = 50, lo = 0, hi = 1),
    Bunch(name='B_m' , var='llK_<tag>_rec_M', bins = 100, lo = 4500, hi = 5500),
    Bunch(name='jpsi_m' , var='ll_<tag>_rec_M', bins = 100, lo = 2500, hi = 3500)
    ]

tp_bunches = [
    Bunch(name='jpsi_m', var='Jpsi_M', bins = 100, lo = 2500, hi = 3500),
    Bunch(name='jpsi_pt', var='Jpsi_PT', bins = 100, lo = 000, hi = 10000),
    Bunch(name='b_m'   , var='B_M', bins = 100, lo = 4500, hi = 5500),
    Bunch(name='b_dtf_m'   , var='B_ConsB_M', bins = 100, lo = 4500, hi = 5500),
    Bunch(name='tag_pt' , var='tag_PT', bins = 100, lo = 0, hi = 10000),
    Bunch(name='probe_pt' , var='probe_PT', bins = 100, lo = 0, hi = 10000),
    Bunch(name='tag_p' , var='tag_P', bins = 100, lo = 0, hi = 80000),
    Bunch(name='probe_p' , var='probe_P', bins = 100, lo = 0, hi = 80000),
    Bunch(name='tag_IP' , var='tag_IP_OWNPV', bins = 100, lo = 0, hi = 1),
    Bunch(name='probe_IP' , var='probe_IP_OWNPV', bins = 100, lo = 0, hi = 1),
    Bunch(name='jpsi_vtxchi2' , var='Jpsi_ENDVERTEX_CHI2/Jpsi_ENDVERTEX_NDOF', bins = 100, lo = 0, hi = 10),
    Bunch(name='b_vtxchi2'    , var='B_ENDVERTEX_CHI2/B_ENDVERTEX_NDOF', bins = 100, lo = 0, hi = 5),
    Bunch(name='tag_CaloHcalEP'    , var='tag_CaloHcalE/tag_P', bins = 100, lo = 0, hi = 0.5),
    Bunch(name='probe_CaloHcalEP'    , var='probe_CaloHcalE/probe_P', bins = 100, lo = 0, hi = 0.5),
    Bunch(name='probe_CaloEP'    , var='(probe_CaloHcalE+probe_CaloPrsE+probe_CaloSpdE)/probe_P', bins = 100, lo = 0, hi = 0.5),
    Bunch(name='probe_velo_chi2ndof', var='probe_velo_chi2ndof', bins = 100, lo = 0, hi = 5.0),
    Bunch(name='probe_bestCaloMatch', var='probe_bestCaloMatch', bins = 21, lo = -0.5, hi = 20.5),
    Bunch(name='probe_EcalE', var='probe_EcalClusterE', bins = 100, lo = 0, hi = 100000),
    Bunch(name='probe_EcalEt', var='probe_EcalClusterEt', bins = 100, lo = 0, hi = 5000),
    Bunch(name='probe_EcalER', var='probe_EcalClusterE/probe_PE', bins = 100, lo = 0, hi = 2),
    Bunch(name='probe_VeloMatch', var='probe_VeloMatch', bins = 100, lo = 0, hi = 1.01),
    Bunch(name='probe_MatchPt', var='probe_MatchPt', bins = 100, lo = 0, hi = 10000),
    Bunch(name='probe_dR' , var='probe_deltaR', bins = 100, lo = 0, hi = 0.02),
    Bunch(name='probe_dRt' , var='probe_deltaRt', bins = 100, lo = 0, hi = 1000),
    Bunch(name='tag_BremMultiplicity' , var='tag_BremMultiplicity', bins = 5, lo = -0.5, hi = 4.5),
    Bunch(name='probe_BremMultiplicity' , var='probe_BremMultiplicity', bins = 5, lo = -0.5, hi = 4.5),
    Bunch(name='b_hop_mass', var='B_HOP_MASS', bins = 100, lo = 0, hi = 15000),
    Bunch(name='b_dira', var='B_DIRA_OWNPV', bins = 100, lo = 0.95, hi = 1),
    Bunch(name='b_fdchi2', var='B_FDCHI2_OWNPV', bins = 100, lo = 0, hi = 100),
    Bunch(name='b_bpvltime', var='B_BPVLTIME', bins = 100, lo = 0, hi = 0.01),
    Bunch(name='b_bpvlfitchi2', var='B_BPVLTFITCHI2', bins = 100, lo = 0, hi = 10),
    ]

loc = '/user2/sfarry/workspaces/rkst/tuples'
trueprobe = TCut("abs(probe_TRUEID) == 11")
truetags  = TCut("abs(tag_TRUEID) == 11 && abs(K_TRUEID) == 321")

sel = TCut("tag_PT > 1000 && tag_P > 8000 && probe_PT > 1000 && probe_P > 8000 && probe_TRACK_CHI2NDOF < 1.0 && probe_CaloHcalE/probe_P < 0.1 && probe_IP_OWNPV > 0.1 && B_ENDVERTEX_CHI2/B_ENDVERTEX_NDOF < 2 && tag_MC15TuneV1_ProbNNe > 0.2 && (K_MC15TuneV1_ProbNNk*(1-K_MC15TuneV1_ProbNNp)) > 0.05 && probe_EcalClusterEt/probe_PT > 0.6 && probe_EcalClusterEt/probe_PT < 1.4 & B_FDCHI2_OWNPV > 15 && B_BPVLTFITCHI2 < 4 && B_HOP_MASS > 3500 && B_ConsB_M > 5300 && B_ConsB_M < 5500 && B_M > 4900")

decaytree = Template("decaytree")
decaytree.SetSelCut(TCut(""))
decaytree.AddTree(t)
decaytree.AddTree(u)
for p in dt_bunches:
    decaytree.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
decaytree.Run()
#decaytree.SaveToFile(loc + '/decaytree.root')

true_lp = Template("true_lp")
true_lp.SetSelCut(true_lp_pt + true_rec_lp + true_stub_lp)
true_lp.AddTree(x)
true_lp.AddTree(y)
for p in true_bunches:
    true_lp.AddVar(p.name, p.var.replace('<l>', 'lp').replace('<tag>', 'mtag'), p.bins, p.lo, p.hi)
true_lp.Run()

true_lm = Template("true_lm")
true_lm.SetSelCut(true_lm_pt + true_rec_lm + true_stub_lm)
true_lm.AddTree(x)
true_lm.AddTree(y)
for p in true_bunches:
    true_lm.AddVar(p.name, p.var.replace('<l>', 'lm').replace('<tag>', 'ptag'), p.bins, p.lo, p.hi)
true_lm.Run()

true = Template("true", true_lp, true_lm)
true.SaveToFile(loc + '/true.root')

tagprobe_true = Template("tagprobe_true")
tagprobe_true.SetSelCut(truetags + trueprobe)
tagprobe_true.AddTree(v)
tagprobe_true.AddTree(w)
for p in tp_bunches:
    tagprobe_true.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
tagprobe_true.Run()
tagprobe_true.SaveToFile(loc + '/tagprobe_true.root')


tagprobe_truetag = Template("tagprobe_truetag")
tagprobe_truetag.SetSelCut(trueprobe + truetags)
tagprobe_truetag.AddTree(v)
tagprobe_truetag.AddTree(w)
for p in tp_bunches:
    tagprobe_truetag.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
#tagprobe_truetag.Run()
#tagprobe_truetag.SaveToFile(loc + '/tagprobe_truetag.root')

tagprobe_sel = Template("tagprobe_sel")
tagprobe_sel.SetSelCut(sel)
tagprobe_sel.AddTree(v)
tagprobe_sel.AddTree(w)
for p in tp_bunches:
    tagprobe_sel.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
tagprobe_sel.Run()
tagprobe_sel.SaveToFile(loc + '/tagprobe_sel.root')

tagprobe_pass = Template("tagprobe_pass")
tagprobe_pass.SetSelCut(sel + passcut)
tagprobe_pass.AddTree(v)
tagprobe_pass.AddTree(w)
for p in tp_bunches:
    tagprobe_pass.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
#tagprobe_pass.Run()
#tagprobe_pass.SaveToFile(loc + '/tagprobe_pass.root')

tagprobe_fail = Template("tagprobe_fail")
tagprobe_fail.SetSelCut(sel + failcut)
tagprobe_fail.AddTree(v)
tagprobe_fail.AddTree(w)
for p in tp_bunches:
    tagprobe_fail.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
#tagprobe_fail.Run()
#tagprobe_fail.SaveToFile(loc + '/tagprobe_fail.root')

tagprobe_sel_truetag = Template("tagprobe_sel_truetag")
tagprobe_sel_truetag.SetSelCut(sel + truetags)
tagprobe_sel_truetag.AddTree(v)
tagprobe_sel.AddTree(w)
for p in tp_bunches:
    tagprobe_sel_truetag.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
#tagprobe_sel_truetag.Run()
#tagprobe_sel_truetag.SaveToFile(loc + '/tagprobe_sel_truetag.root')

tagprobe = Template("tagprobe")
tagprobe.SetSelCut(TCut(""))
tagprobe.AddTree(v)
tagprobe.AddTree(w)
for p in tp_bunches:
    tagprobe.AddVar(p.name, p.var, p.bins, p.lo, p.hi)
tagprobe.MaxEvts = 100000
tagprobe.Run()
tagprobe.SaveToFile(loc + '/tagprobe.root')


from Style import *
SetLHCbStyle()

for b in dt_bunches:
    d = Plot([decaytree.GetVar(b.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    if hasattr(b, 'xlabel'): d.setProp('xlabel', b.xlabel)
    d.setProp('ylabel', '[A.U.]')
    d.setProp('labels', ['Rec.'])
    d.setProp('colors', ['red'])
    d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
    d.setProp('filename', 'etrkeff_'+b.name+'_mc2016.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

include_sel = [ 'jpsi_m', 'b_m','probe_bestCaloMatch', 'probe_EcalER', 'probe_EcalE', 'probe_EcalEt', 'b_dtf_m' ]

for b in tp_bunches:
    d = Plot([tagprobe.GetVar(b.name).GetHist(), tagprobe_true.GetVar(b.name).GetHist()])
    d.forceStyle()
    d.setProp('normalised', True)
    d.setProp('ylabel', '[A.U.]')
    d.setProp('labels', ['All', 'Truth Matched'])
    d.setProp('colors', ['red', 'blue'])
    if b.name in include_sel:
        d.plots += [tagprobe_sel.GetVar(b.name).GetHist()]
        d.setProp('colors', ['red', 'blue', 'green'])
        d.setProp('labels', ['All', 'Truth Matched', 'Selected'])
    d.AutoYlims()
    d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
    d.setProp('filename', 'etrkeff_tp_'+b.name+'_mc2016.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(b, 'xlabel'): d.setProp('xlabel', b.xlabel)
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()

for b in tp_bunches:
    d = Plot([tagprobe_sel.GetVar(b.name).GetHist(), tagprobe_pass.GetVar(b.name).GetHist(), tagprobe_fail.GetVar(b.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('ylabel', 'Events')
    d.setProp('labels', ['Total', 'Pass', 'Fail'])
    d.setProp('colors', ['black', 'red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
    d.setProp('filename', 'etrkeff_tpf_'+b.name+'_mc2016.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(b, 'xlabel'): d.setProp('xlabel', b.xlabel)
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()


for b in true_bunches:
    d = Plot([true.GetVar(b.name).GetHist()])
    d.forceStyle()
    d.AutoYlims()
    d.setProp('normalised', True)
    d.setProp('ylabel', '[A.U.]')
    d.setProp('labels', ['True'])
    d.setProp('colors', ['red'])
    d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
    d.setProp('filename', 'etrkeff_true_'+b.name+'_mc2016.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(b, 'xlabel'): d.setProp('xlabel', b.xlabel)
    if hasattr(p, 'shiftlegx'): d.ShiftLegX(p.shiftlegx)
    if hasattr(p, 'shiftlegy'): d.ShiftLegY(p.shiftlegy)
    d.drawROOT()



d = Plot([tagprobe.GetVar('jpsi_m').GetHist(), tagprobe_true.GetVar('jpsi_m').GetHist()])
d.forceStyle()
d.AutoYlims()
d.setProp('normalised', False)
d.setProp('ylabel', 'Events')
d.setProp('labels', ['All', 'Truth Matched'])
d.setProp('colors', ['black', 'red'])
d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
d.setProp('filename', 'all_v_truth_mc2016.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
d.ShiftLegY(-0.3)
d.setProp('xlabel', 'M_{ee} [MeV]')
d.drawROOT()

d = Plot([tagprobe_sel.GetVar('jpsi_m').GetHist()])
d.forceStyle()
d.AutoYlims()
d.setProp('normalised', False)
d.setProp('ylabel', 'Events')
d.setProp('labels', ['Selected'])
d.setProp('colors', ['black', 'red'])
d.setProp('location', '/user2/sfarry/workspaces/rkst/figures')
d.setProp('filename', 'sel_mc2016.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
d.setProp('xlabel', 'M_{ee} [MeV]')
d.ShiftLegX(-0.4)
d.drawROOT()
