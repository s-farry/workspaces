from ROOT import TFile, TTree, TCut, TPaveText
from PlotTools import *
from Style import *
from Utils import Bunch
SetLHCbStyle()

plots = [
    Bunch(name='ptj', xlabel='p_{T}^{j} [GeV]', ylabel='[A.U.]', var='jet_PT/1000.0', nbins=100, lo = 10, hi = 100),
    Bunch(name='kaonpt', xlabel='#sum p_{T}(kaon) [GeV]', ylabel='[A.U.]', var='jet_kaonpt/1000.0', nbins = 100, lo = 0, hi = 30, ynormlims = [0, 0.1]),
    Bunch(name='pionpt', xlabel='#sum p_{T}(pion) [GeV]', ylabel='[A.U.]', var='jet_pionpt/1000.0', nbins = 100, lo = 0, hi = 30, ynormlims = [0, 0.1]),
    Bunch(name='maxkaonpt', xlabel='p_{T}^{max.}(kaon) [GeV[', ylabel='[A.U.]', var='jet_maxkaonpt/1000.0', nbins = 100, lo = 0, hi = 30, ynormlims = [0, 0.12]),
    Bunch(name='maxkaonptr', xlabel='p_{T}^{max.}(kaon)/p_{T}^{j}', ylabel='[A.U.]', var='jet_maxkaonpt/jet_PT', nbins = 100, lo = 0, hi = 1),
    Bunch(name='maxpionpt', xlabel='p_{T}^{max.}(pion) [GeV[', ylabel='[A.U.]', var='jet_maxpionpt/1000.0', nbins = 100, lo = 0, hi = 30, ynormlims=[0, 0.11]),
    Bunch(name='maxpionptr', xlabel='p_{T}^{max.}(pion)/p_{T}^{j}', ylabel='[A.U.]', var='jet_maxpionpt/jet_PT', nbins = 100, lo = 0, hi = 1),
    Bunch(name='kaonmult', xlabel='Kaon Multiplicity', ylabel='[A.U.]', var='jet_kaonmult', nbins = 11, lo = -0.5, hi = 10.5),
    Bunch(name='kaoncmult', xlabel='Charged Kaon Multiplicity', ylabel='[A.U.]', var='jet_kaoncmult', nbins = 11, lo = -0.5, hi = 10.5),
    Bunch(name='pionmult', xlabel='Pion Multiplicity', ylabel='[A.U.]', var='jet_pionmult', nbins = 11, lo = -0.5, hi = 10.5, shiftlegx=0.2),
    Bunch(name='pioncmult', xlabel='Charged Pion Multiplicity', ylabel='[A.U.]', var='jet_pioncmult', nbins = 11, lo = -0.5, hi = 10.5, ylims = [0, 0.04], shiftlegx=0.2),
    Bunch(name='mj', xlabel='Jet Mass [GeV]', ylabel='[A.U.]', var='jet_M/1000.0', nbins = 100, lo = 0, hi = 50),
    Bunch(name='wj', xlabel='Jet Width', ylabel='[A.U.]', var='jetw', nbins = 100, lo = 0, hi = 0.5, shiftlegx = 0.2),
    Bunch(name='multj', xlabel='Jet Multiplicity', ylabel='[A.U.]', var='jet_ndauts', nbins=41, lo = -0.5, hi=40.5),
    Bunch(name='jet_cpf', xlabel='Jet CPF', ylabel='[A.U.]', var='jet_cpf', nbins=100, lo=0, hi=1, shiftlegx=-0.3, shiftlegy=0),
    Bunch(name='kaon_dr', xlabel='#Delta R(jet, kaon)', var='jet_K_dR', ylabel='[A.U.]', nbins=100, lo=0, hi=0.5),
    Bunch(name='pion_dr', xlabel='#Delta R(jet, pion)', var='jet_pi_dR', ylabel='[A.U.]', nbins=100, lo = 0, hi = 0.5),
    Bunch(name='bdt',   xlabel='BDT', var='BDT', ylabel='[A.U.]', nbins=100, lo = -1, hi = 1, ynormlims = [0, 0.07])
    ]


f = TFile("/user2/sfarry/workspaces/strange/tuples/tmvaDVout.root")

p = Plot([f.Get('Method_BDT/BDTB/MVA_BDTB_rejBvsS'), f.Get('Method_BDT/BDT/MVA_BDT_rejBvsS'), f.Get('Method_BDT/BDTAdaBoost/MVA_BDTAdaBoost_rejBvsS')])
p.setProp('filename', 'mva_comp')
p.setProp('location', '/user2/sfarry/workspaces/strange/figures')
p.setProp('drawOpts', 'l1')
p.setProp('linecolors', ['red', 'blue', 'green'])
p.setProp('fillstyles', 0)
p.setProp('labels', ['Bagging', 'Grad', 'Adaptive'])
p.setProp('markerstyles', 20)
p.setProp('xlabel', 'Signal Efficiency')
p.setProp('ylabel', 'Background Rejection')
p.setProp('leglims', [0.2, 0.2, 0.7, 0.4])
p.drawROOT()

ptbins = [0, 10, 20, 30, 50, 100]

from Jawa import *
sig = Template('sig')
sig.SetSelCut(TCut('classID == 0'))
sig.AddTrees(jet_pt20_50.trees())
sig.AddTrees(jet_pt50.trees())
for p in plots:
    sig.AddVar([p.name, p.var, p.nbins, p.lo, p.hi])
sig.AddVar(['ptj2', 'jet_PT/1000.0', ptbins])
sig.Add2DVar(['bdt', 'ptj2'])
sig.Run()
sig.SaveToFile('/user2/sfarry/workspaces/strange/tuples/sig.root')

bkg = Template('bkg')
bkg.SetSelCut(TCut('classID == 1'))
bkg.AddTree(f.Get('TrainTree'))
for p in plots:
    bkg.AddVar([p.name, p.var, p.nbins, p.lo, p.hi])
bkg.AddVar(['ptj2', 'jet_PT/1000.0', ptbins])
bkg.Add2DVar(['bdt', 'ptj2'])
bkg.Run()
bkg.SaveToFile('/user2/sfarry/workspaces/strange/tuples/bkg.root')


sig_h = sig.Get2DVar('bdt', 'ptj2').GetHist()
bkg_h = bkg.Get2DVar('bdt', 'ptj2').GetHist()
for i in range(len(ptbins) - 1):
    tt = TPaveText(0.2, 0.4, 0.45, 0.6, "NDC")
    tt.AddText(str(ptbins[i])+" < p_{T}^{j} < "+str(ptbins[i+1])+" GeV")
    tt.SetFillStyle(0)
    tt.SetBorderSize(0)
    p = Plot([sig_h.ProjectionX(sig_h.GetName()+str(i), i+1, i+1), bkg_h.ProjectionX(sig_h.GetName()+str(i), i+1, i+1)])
    p.setProp('filename', 'comp'+str(i))
    p.setProp('location', '/user2/sfarry/workspaces/strange/figures')
    p.setProp('drawOpts', 'h1')
    p.setProp('linecolors', ['red', 'blue'])
    p.setProp('fillstyles', 0)
    p.setProp('labels', ['Strange Jets', 'Light Jets'])
    p.setProp('markerstyles', 20)
    p.setProp('xlabel', 'BDT')
    p.setProp('ylabel', '[A.U.]')
    p.setProp('leglims', [0.2, 0.7, 0.5, 0.9])
    p.setProp('normalised', True)
    p.setProp('ynormlims', [0, 0.1])
    p.setProp('extraObjs', [tt])
    p.drawROOT()

print "sig", sig
p2 = Plot([sig_h.ProjectionX(sig_h.GetName()+str(i)+"2", i+1, i+1) for i in range(len(ptbins)-1)])
tt2 = TPaveText(0.15, 0.3, 0.4, 0.45, "NDC")
tt2.AddText('Strange Jets')
tt2.SetFillStyle(0)
tt2.SetBorderSize(0)
p2.setProp('filename', 'sigcomp')
p2.setProp('location', '/user2/sfarry/workspaces/strange/figures')
p2.setProp('drawOpts', 'hist')
p2.setProp('linecolors', ['red', 'blue', 'green', 'black', 'yellow'])
p2.setProp('fillstyles', 0)
p2.setProp('labels', [str(ptbins[i])+" < p_{T}^{j} < "+str(ptbins[i+1])+" GeV" for i in range(len(ptbins)-1)])
p2.setProp('markerstyles', 20)
p2.setProp('xlabel', 'BDT')
p2.setProp('ylabel', '[A.U.]')
p2.setProp('leglims', [0.15, 0.5, 0.45, 0.9])
p2.setProp('normalised', True)
p2.setProp('ynormlims', [0, 0.2])
p2.setProp('extraObjs', [tt2])
p2.drawROOT()

print "sig",sig
p2 = Plot([bkg_h.ProjectionX(bkg_h.GetName()+str(i)+"2", i+1, i+1) for i in range(len(ptbins)-1)])
tt3 = TPaveText(0.7, 0.2, 0.9, 0.35, "NDC")
tt3.AddText('Light Jets')
tt3.SetFillStyle(0)
tt3.SetBorderSize(0)
p2.setProp('filename', 'bkgcomp')
p2.setProp('location', '/user2/sfarry/workspaces/strange/figures')
p2.setProp('drawOpts', 'hist')
p2.setProp('linecolors', ['red', 'blue', 'green', 'black', 'yellow'])
p2.setProp('fillstyles', 0)
p2.setProp('labels', [str(ptbins[i])+" < p_{T}^{j} < "+str(ptbins[i+1])+" GeV" for i in range(len(ptbins)-1)])
p2.setProp('markerstyles', 20)
p2.setProp('xlabel', 'BDT')
p2.setProp('ylabel', '[A.U.]')
p2.setProp('leglims', [0.15, 0.5, 0.45, 0.9])
p2.setProp('normalised', True)
p2.setProp('ynormlims', [0, 0.2])
p2.setProp('extraObjs', [tt3])
p2.drawROOT()

for p in plots:
    p2 = Plot([sig.GetVar(p.name).GetHist(), bkg.GetVar(p.name).GetHist()])
    p2.setProp('filename', 'bdtvar_'+p.name)
    p2.setProp('location', '/user2/sfarry/workspaces/strange/figures')
    p2.setProp('drawOpts', 'h')
    p2.setProp('linecolors', ['red', 'blue'])
    p2.setProp('fillstyles', 0)
    p2.setProp('labels', ['strange', 'inclusive'])
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
