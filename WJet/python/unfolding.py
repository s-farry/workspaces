
from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas, TMath
from Style import *
from Wjconfig_new import *

SetLHCbStyle()
from PlotTools import *

f = TFile("/hepstore/sfarry/GridOutput/1171/Zmumujet.Z_mumujet17.MU.MC2012.root")
g = TFile("/hepstore/sfarry/GridOutput/1172/Zmumujet.Z_mumujet17.MD.MC2012.root")
h = TFile("/hepstore/sfarry/GridOutput/1173/Wmujet.Wmunujet.MU.MC2012.root")
i = TFile("/hepstore/sfarry/GridOutput/1174/Wmujet.Wmunujet.MD.MC2012.root")
j = TFile("/hepstore/sfarry/GridOutput/1175/Wmujet.Z_mumujet17.MU.MC2012.root")
k = TFile("/hepstore/sfarry/GridOutput/1176/Wmujet.Z_mumujet17.MD.MC2012.root")

t = f.Get("ZMuMu/DecayTree")
u = g.Get("ZMuMu/DecayTree")
v = h.Get("WTuple/DecayTree")
w = i.Get("WTuple/DecayTree")
x = j.Get("WTuple/DecayTree")
y = k.Get("WTuple/DecayTree")


reco2true_match = TCut("muminus_jet_PT > 20000 && muminus_mcjet_PT > 12500") 
true2reco_match = TCut("muminus_truejet_PT > 20000 && muminus_rectruejet_PT > 12500") 
reco2true_match_lowpt = TCut("muminus_jet_PT > 12500 && muminus_mcjet_PT > 12500") 
true2reco_match_lowpt = TCut("muminus_truejet_PT > 12500 && muminus_rectruejet_PT > 12500") 

reco2true_match_z = TCut(reco2true_match.GetTitle().replace('muminus','boson'))
true2reco_match_z = TCut(true2reco_match.GetTitle().replace('muminus', 'boson'))

unfoldvars = [
    ["ptj_reco", "muminus_jet_PT/1000.0", [12.5] + ptbins],
    ["ptj_true"  , "muminus_truejet_PT/1000.0", [12.5] + ptbins],
    ["etaj_reco", "muminus_jet_ETA", [2.0] + jetetabins + [4.5]],
    ["etaj_true", "muminus_truejet_ETA", [2.0] + jetetabins + [4.5]]
]

unfoldvars_reco = [
    ["ptj" , "muminus_jet_PT/1000.0", ptbins],
    ["etaj", "muminus_jet_ETA", jetetabins],
    ["eta" , "muminus_ETA"    , etabins],
    ["ptj_reco2true" , "muminus_mcjet_PT/1000.0", ptbins],
    ["etaj_reco2true", "muminus_mcjet_ETA", jetetabins],
]
unfoldvars_true = [
    ["ptj",  "muminus_truejet_PT/1000.0", ptbins],
    ["etaj", "muminus_truejet_ETA", jetetabins],
    ["eta" , "muminus_ETA"    , etabins],
    ["ptj_true2reco",  "muminus_rectruejet_PT/1000.0", ptbins],
    ["etaj_true2reco", "muminus_rectruejet_ETA", jetetabins]
]
unfoldvars_reco_z = [
    ["ptj",  "boson_jet_PT/1000.0", ptbins],
    ["etaj", "boson_jet_ETA", jetetabins],
    ["yz" ,  "boson_Y"    , etabins],
    ["ptj_reco2true" , "boson_mcjet_PT/1000.0", ptbins],
    ["etaj_reco2true", "boson_mcjet_ETA", jetetabins],
    ["dphi",  dPhi.replace('<A>','boson').replace('<B>', 'boson_jet'), 6, 0, TMath.Pi()]
]
unfoldvars_true_z = [
    ["ptj",  "boson_truejet_PT/1000.0", ptbins],
    ["etaj", "boson_truejet_ETA", jetetabins],
    ["yz" ,  "boson_Y"    , etabins],
    ["ptj_true2reco",  "boson_rectruejet_PT/1000.0", ptbins],
    ["etaj_true2reco", "boson_rectruejet_ETA", jetetabins],
    ["dphi",  dPhi.replace('<A>','boson').replace('<B>', 'boson_truejet'), 6, 0, TMath.Pi()]
]
unfold2dvars = [['ptj','etaj']]
unfold2dvars_response = [['ptj_reco','ptj_true'], ['etaj_reco', 'etaj_true']]


wp_unfolding = Template("wp_unfolding")
wp_unfolding.SetSelCut(selcut_base_nojet + reco2true_match_lowpt + true2reco_match_lowpt + plus)
#wp_unfolding.AddTree(wmuj_mc2012.MUt)
#wp_unfolding.AddTree(wmuj_mc2012.MDt)
wp_unfolding.AddTree(v)
wp_unfolding.AddTree(w)
wp_unfolding.AddVars(unfoldvars)
wp_unfolding.Add2DVars(unfold2dvars_response)
wp_unfolding.Run()
wp_unfolding.SaveToFile()

wp_unfolding_reco = Template("wp_unfolding_reco")
wp_unfolding_reco.SetSelCut(selcut_base_nojet + reco2true_match + plus)
#wp_unfolding_reco.AddTree(wmuj_mc2012.MUt)
#wp_unfolding_reco.AddTree(wmuj_mc2012.MDt)
wp_unfolding_reco.AddTree(v)
wp_unfolding_reco.AddTree(w)
wp_unfolding_reco.AddVars(unfoldvars_reco)
#wp_unfolding_reco.Add2DVars(unfold2dvars)
wp_unfolding_reco.Run()
wp_unfolding_reco.SaveToFile()

wp_unfolding_true = Template("wp_unfolding_true")
wp_unfolding_true.SetSelCut(selcut_base_nojet + true2reco_match + plus)
#wp_unfolding_true.AddTree(wmuj_mc2012.MUt)
#wp_unfolding_true.AddTree(wmuj_mc2012.MDt)
wp_unfolding_true.AddTree(v)
wp_unfolding_true.AddTree(w)
wp_unfolding_true.AddVars(unfoldvars_true)
#wp_unfolding_true.Add2DVars(unfold2dvars)
wp_unfolding_true.Run()
wp_unfolding_true.SaveToFile()


wm_unfolding_reco = Template("wm_unfolding_reco")
wm_unfolding_reco.SetSelCut(selcut_base_nojet + reco2true_match + minus)
wm_unfolding_reco.AddTree(wmuj_mc2012.MUt)
wm_unfolding_reco.AddTree(wmuj_mc2012.MDt)
wm_unfolding_reco.AddVars(unfoldvars_reco)
#wm_unfolding_reco.Add2DVars(unfold2dvars)
wm_unfolding_reco.Run()
wm_unfolding_reco.SaveToFile()

wm_unfolding_true = Template("wm_unfolding_true")
wm_unfolding_true.SetSelCut(selcut_base_nojet + true2reco_match + minus)
#wm_unfolding_true.AddTree(wmuj_mc2012.MUt)
#wm_unfolding_true.AddTree(wmuj_mc2012.MDt)
wm_unfolding_true.AddTree(v)
wm_unfolding_true.AddTree(w)
wm_unfolding_true.AddVars(unfoldvars_true)
#wm_unfolding_true.Add2DVars(unfold2dvars)
wm_unfolding_true.Run()
wm_unfolding_true.SaveToFile()

z_unfolding_reco = Template("z_unfolding_reco")
z_unfolding_reco.SetSelCut(selcut_zmumu_nojet + reco2true_match_z)
#z_unfolding_reco.AddTree(zmumuj_mc2012.MUt)
#z_unfolding_reco.AddTree(zmumuj_mc2012.MDt)
z_unfolding_reco.AddTree(t)
z_unfolding_reco.AddTree(u)
z_unfolding_reco.AddVars(unfoldvars_reco_z)
#z_unfolding_reco.Add2DVars(unfold2dvars)
z_unfolding_reco.Run()
z_unfolding_reco.SaveToFile()

z_unfolding_true = Template("z_unfolding_true")
z_unfolding_true.SetSelCut(selcut_zmumu_nojet + true2reco_match_z)
#z_unfolding_true.AddTree(zmumuj_mc2012.MUt)
#z_unfolding_true.AddTree(zmumuj_mc2012.MDt)
z_unfolding_true.AddTree(t)
z_unfolding_true.AddTree(u)
z_unfolding_true.AddVars(unfoldvars_true_z)
#z_unfolding_true.Add2DVars(unfold2dvars)
z_unfolding_true.Run()
z_unfolding_true.SaveToFile()


for v in ('ptj', 'etaj'):
    p = Plot([wp_unfolding_reco.GetVar(v).GetHist(), wp_unfolding_true.GetVar(v).GetHist()])
    #if v == 'etaj' :
    #    p.plots = [wp_unfolding_reco.Get2DVar('ptj','etaj').GetHist().ProjectionY("wp_etaj_reco_etarange",2,5),
    #               wp_unfolding_true.Get2DVar('ptj','etaj').GetHist().ProjectionY("wp_etaj_true_etarange",2,5)]
    p.setProp('filename','wp_unfolding_'+v)
    p.setProp('colors',  ['black','red'])
    p.setProp('labels',  ['Reco', 'True'])
    p.setProp('markerstyles', 20)
    p.drawROOT()

    m = Plot([wm_unfolding_reco.GetVar(v).GetHist(), wm_unfolding_true.GetVar(v).GetHist()])
    #if v == 'etaj' :
    #    m.plots = [wm_unfolding_reco.Get2DVar('ptj','etaj').GetHist().ProjectionY("wm_etaj_reco_etarange",2,5),
    #               wm_unfolding_true.Get2DVar('ptj','etaj').GetHist().ProjectionY("wm_etaj_true_etarange",2,5)]
    m.setProp('filename','wm_unfolding_'+v)
    m.setProp('colors',  ['black','red'])
    m.setProp('labels',  ['Reco', 'True'])
    m.setProp('markerstyles', 20)
    m.drawROOT()

    z = Plot([z_unfolding_reco.GetVar(v).GetHist(), z_unfolding_true.GetVar(v).GetHist()])
    #if v == 'etaj' :
    #    z.plots = [z_unfolding_reco.Get2DVar('ptj','etaj').GetHist().ProjectionY("z_etaj_reco_etarange",2,5),
    #               z_unfolding_true.Get2DVar('ptj','etaj').GetHist().ProjectionY("z_etaj_true_etarange",2,5)]
    z.setProp('filename','z_unfolding_'+v)
    z.setProp('colors',  ['black','red'])
    z.setProp('labels',  ['Reco', 'True'])
    z.setProp('markerstyles', 20)
    z.drawROOT()

    p_ratio = p.plots[1].Clone()
    p_ratio.Divide(p.plots[0])
    m_ratio = m.plots[1].Clone()
    m_ratio.Divide(m.plots[0])
    z_ratio = z.plots[1].Clone()
    z_ratio.Divide(z.plots[0])

    #saveTH1F("/user2/sfarry/WJet/dat/wp_unf_"+v+".dat", p_ratio)
    #saveTH1F("/user2/sfarry/WJet/dat/wm_unf_"+v+".dat", m_ratio)
    #saveTH1F("/user2/sfarry/WJet/dat/zmumu_unf_"+v+".dat", z_ratio)

    r = Plot([p_ratio, m_ratio, z_ratio])
    r.setProp('filename','ratio_unfolding_'+v)
    r.setProp('colors',  ['black','red', 'green'])
    r.setProp('labels',  ['W+', 'W-', 'Z'])
    r.setProp('markerstyles', 20)
    r.setProp('leglims', [0.4, 0.2, 0.7, 0.5])
    if v=='etaj' : r.setProp('xlabel','#eta^{j}')
    elif v == 'ptj' : r.setProp('xlabel', 'p_{T}(j) [GeV]')
    r.setProp('ylabel', 'Correction Factor')
    r.drawROOT()


         

for v in ['eta']:
    p = Plot([wp_unfolding_reco.GetVar(v).GetHist(), wp_unfolding_true.GetVar(v).GetHist()])
    p.setProp('filename','wp_unfolding_'+v)
    p.setProp('colors',  ['black','red'])
    p.setProp('labels',  ['Reco', 'True'])
    p.setProp('markerstyles', 20)
    p.drawROOT()

    m = Plot([wm_unfolding_reco.GetVar(v).GetHist(), wm_unfolding_true.GetVar(v).GetHist()])
    m.setProp('filename','wm_unfolding_'+v)
    m.setProp('colors',  ['black','red'])
    m.setProp('labels',  ['Reco', 'True'])
    m.setProp('markerstyles', 20)
    m.drawROOT()

    p_ratio = p.plots[1].Clone()
    p_ratio.Divide(p.plots[0])
    m_ratio = m.plots[1].Clone()
    m_ratio.Divide(m.plots[0])

    #saveTH1F("/user2/sfarry/WJet/dat/wp_unf_"+v+".dat", p_ratio)
    #saveTH1F("/user2/sfarry/WJet/dat/wm_unf_"+v+".dat", m_ratio)

    r = Plot([p_ratio, m_ratio])
    r.setProp('filename','ratio_unfolding_'+v)
    r.setProp('colors',  ['black','red'])
    r.setProp('labels',  ['W+', 'W-'])
    r.setProp('markerstyles', 20)
    r.drawROOT()


              

for v in ('yz', 'dphi'):
    z = Plot([z_unfolding_reco.GetVar(v).GetHist(), z_unfolding_true.GetVar(v).GetHist()])
    z.setProp('filename','z_unfolding_'+v)
    z.setProp('colors',  ['black','red'])
    z.setProp('labels',  ['Reco', 'True'])
    z.setProp('markerstyles', 20)
    z.drawROOT()

    z_ratio = z.plots[1].Clone()
    z_ratio.Divide(z.plots[0])

    #saveTH1F("/user2/sfarry/WJet/dat/zmumu_unf_"+v+".dat", z_ratio)

    r = Plot([z_ratio])
    r.setProp('filename','ratio_unfolding_'+v)
    r.setProp('colors',  ['green'])
    r.setProp('labels',  ['Z'])
    r.setProp('markerstyles', 20)
    r.drawROOT()
