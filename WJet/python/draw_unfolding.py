
from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas, TMath
from PlotTools import *
from Style import *
from Wjconfig_new import *

SetLHCbStyle()

truthvars = [
    ["true_etaj_diff", "(muminus_truejet_ETA - muminus_rectruejet_ETA)", 100, -0.1, 0.1],
    ["true_pt_diff"  , "(muminus_truejet_PT - muminus_rectruejet_PT)", 100, -20000, 20000],
    ["rec_etaj_diff" , "(muminus_jet_ETA - muminus_mcjet_ETA)", 100, -0.1, 0.1],
    ["rec_pt_diff"   , "(muminus_jet_PT - muminus_mcjet_PT)", 100, -20000, 20000],
    ['truejet_eta'   , "(muminus_truejet_ETA)", 50, 2.2, 4.2],
    ['jet_eta'       , "(muminus_jet_ETA)", 50, 2.2, 4.2]
]

ztruthvars = [
    ["true_etaj_diff", "(boson_truejet_ETA - boson_rectruejet_ETA)", 100, -0.1, 0.1],
    ["true_pt_diff"  , "(boson_truejet_PT - boson_rectruejet_PT)", 100, -0.5, 0.5],
    ["rec_etaj_diff" , "(boson_jet_ETA - boson_mcjet_ETA)", 100, -0.1, 0.1],
    ["rec_pt_diff"   , "(boson_jet_PT - boson_mcjet_PT)", 100, 20000, 20000],
    ['truejet_eta'   , "(boson_truejet_ETA)", 50, 2.2, 4.2],
    ['jet_eta'       , "(boson_jet_ETA)", 50, 2.2, 4.2]
]

truthvars2d = [['true_etaj_diff', 'truejet_eta'], ['rec_etaj_diff', 'jet_eta']]


wmup_rec2true = Template("wmup_rec2true")
wmup_rec2true.SetSelCut(selcut_base_nojet + TCut("muminus_jet_PT > 12500 && muminus_mcjet_PT > 12500") + plus )
wmup_rec2true.AddTree(wmuj_mc2012.MUt)
wmup_rec2true.AddTree(wmuj_mc2012.MDt)
wmup_rec2true.AddVars(truthvars)
wmup_rec2true.Add2DVars(truthvars2d)
wmup_rec2true.Run()

wmum_rec2true = Template("wmum_rec2true")
wmum_rec2true.SetSelCut(selcut_base_nojet + TCut("muminus_jet_PT > 12500 && muminus_mcjet_PT > 12500") + minus )
wmum_rec2true.AddTree(wmuj_mc2012.MUt)
wmum_rec2true.AddTree(wmuj_mc2012.MDt)
wmum_rec2true.AddVars(truthvars)
wmum_rec2true.Add2DVars(truthvars2d)
wmum_rec2true.Run()

zmumu_rec2true = Template("zmumu_rec2true")
zmumu_rec2true.SetSelCut(selcut_zmumu_nojet + TCut("boson_jet_PT > 12500 && boson_mcjet_PT > 12500") )
zmumu_rec2true.AddTree(zmumuj_mc2012.MUt)
zmumu_rec2true.AddTree(zmumuj_mc2012.MDt)
zmumu_rec2true.AddVars(ztruthvars)
zmumu_rec2true.Add2DVars(truthvars2d)
zmumu_rec2true.Run()


wmup_true2rec = Template("wmup_true2rec")
wmup_true2rec.SetSelCut(selcut_base_nojet + TCut("muminus_truejet_PT > 12500 && muminus_rectruejet_PT > 12500") + plus )
wmup_true2rec.AddTree(wmuj_mc2012.MUt)
wmup_true2rec.AddTree(wmuj_mc2012.MDt)
wmup_true2rec.AddVars(truthvars)
wmup_true2rec.Add2DVars(truthvars2d)
wmup_true2rec.Run()

wmum_true2rec = Template("wmum_true2rec")
wmum_true2rec.SetSelCut(selcut_base_nojet + TCut("muminus_truejet_PT > 12500 && muminus_rectruejet_PT > 12500") + minus )
wmum_true2rec.AddTree(wmuj_mc2012.MUt)
wmum_true2rec.AddTree(wmuj_mc2012.MDt)
wmum_true2rec.AddVars(truthvars)
wmum_true2rec.Add2DVars(truthvars2d)
wmum_true2rec.Run()

zmumu_true2rec = Template("zmumu_true2rec")
zmumu_true2rec.SetSelCut(selcut_zmumu_nojet + TCut("boson_truejet_PT > 12500 && boson_rectruejet_PT > 12500") )
zmumu_true2rec.AddTree(zmumuj_mc2012.MUt)
zmumu_true2rec.AddTree(zmumuj_mc2012.MDt)
zmumu_true2rec.AddVars(ztruthvars)
zmumu_true2rec.Add2DVars(truthvars2d)
zmumu_true2rec.Run()



xlabels = ['((p^{j}_{T}(true) - p^{j}_{T}(rec.)) / p_{T}(true)',
           '((eta^{j}(true) - eta^{j}(rec.)) / eta^{j}(true)',
           '((p^{j}_{T}(rec) - p^{j}_{T}(true.)) / p_{T}(rec)',
           '((eta^{j}(rec) - eta^{j}(true.)) / eta^{j}(rec)']

for i,v in enumerate(truthvars):
    plots = []
    if i < 2:
        plots += [wmup_true2rec.GetVar(v[0]).GetHist(), wmum_true2rec.GetVar(v[0]).GetHist(), 
                 zmumu_true2rec.GetVar(v[0]).GetHist()]
    else:
        plots += [wmup_rec2true.GetVar(v[0]).GetHist(), wmum_rec2true.GetVar(v[0]).GetHist(), 
                 zmumu_rec2true.GetVar(v[0]).GetHist()]
    p = Plot(plots)
    p.setProp('colors', ['blue', 'red', 'green'])
    p.setProp('filename', v[0])
    p.setProp('normalised', True)
    p.setProp('ylabel', '[a.u.]')
    p.setProp
    p.drawROOT()

m = Plot([wmup_true2rec.Get2DVar('true_etaj_diff', 'truejet_eta').GetProfile2(),wmum_true2rec.Get2DVar('true_etaj_diff', 'truejet_eta').GetProfile2(), zmumu_true2rec.Get2DVar('true_etaj_diff', 'truejet_eta').GetProfile2()])
m.setProp('colors', ['blue', 'red', 'green'])
m.setProp('filename', 'mean_jeteta_truth2reco')
m.setProp('normalised', False)
m.setProp('ylabel', '< truth - true2reco.>')
m.setProp('xlabel', '#eta^{j} (true)')
m.setProp('ylims', [0, 0.15])
m.drawROOT()


n = Plot([wmup_rec2true.Get2DVar('rec_etaj_diff', 'jet_eta').GetProfile2(),wmum_rec2true.Get2DVar('rec_etaj_diff', 'jet_eta').GetProfile2(), zmumu_rec2true.Get2DVar('rec_etaj_diff', 'jet_eta').GetProfile2()])
n.setProp('colors', ['blue', 'red', 'green'])
n.setProp('filename', 'mean_jeteta_reco2truth')
n.setProp('normalised', False)
n.setProp('ylabel', '< reco. - reco2true>')
n.setProp('xlabel', '#eta^{j} (reco.)')
n.setProp('ylims', [-0.03, 0.022])
n.drawROOT()

o = Plot([zmumu_true2rec.Get2DVar('true_etaj_diff', 'truejet_eta').GetProfile2(), zmumu_rec2true.Get2DVar('rec_etaj_diff', 'jet_eta').GetProfile2()])
o.plots[0].Scale(-1.0)
o.setProp('colors', ['blue', 'red'])
o.setProp('filename', 'mean_jeteta_match_comparison')
o.setProp('normalised', False)
o.setProp('ylabel', '< reco. - true>')
o.setProp('xlabel', '#eta^{j}')
o.setProp('ylims', [-0.03, 0.022])
o.drawROOT()
