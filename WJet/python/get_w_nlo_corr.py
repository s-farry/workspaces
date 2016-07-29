from os import sys
from Jawa import Template
from ROOT import TFile, TTree, TCut, TH1, TParameter
import copy
TH1.AddDirectory(False)


def get_correction(name, histA, histB):
    num = histA.Clone(name)
    num.Scale(1/histA.Integral())
    den = histB.Clone(name)
    den.Scale(1/histB.Integral())
    num.Divide(den)
    den.Delete()
    return num

ptbins = [20, 25, 30, 40, 50,100]
etabins = [2.2, 2.7, 3.2, 3.6, 4.2]
eta8bins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
jetetabins = [2.2, 2.6, 3.0, 3.4, 4.2]
ptjbins = [10 + 2*i for i in range(26)] + [60 + 5*j for j in range(9)]

#w_py8_f   = TFile("/hepstore/sfarry/wmuj_pythia/wmuj_pythia2.root")
w_py8_f   = TFile("/hepstore/sfarry/wmuj_pythia/pythia.root")
w_py8_t   = w_py8_f.Get("Wjet")

jetvars = [
    ["ptj",  "fwdjet_pt", ptjbins],
    ["etaj", "fwdjet_eta", etabins]
    ]

vars = [
    ["eta",  "mu_eta", etabins],
    ["pt" ,  "mu_pt", 20, 20, 80]
    ]

vars2d = [['etaj', 'ptj']]

py8fid_fwd  = TCut("mu_pt > 20 && mu_eta > 2 && mu_eta < 4.5 && fwdjet_pt > 20")
py8fid_fwd  = TCut("mu_pt > 20 && mu_eta < -2 && mu_eta > -4.5 && bwdjet_pt > 20")

wp_amcatnlo_f   = TFile.Open("/hepstore/sfarry/predictions/amcatnlo/amcatnlo.wpj.8tev.root")
wp_amcatnlo_t   = wp_amcatnlo_f.Get("Wjet")
wm_amcatnlo_f   = TFile.Open("/hepstore/sfarry/predictions/amcatnlo/amcatnlo.wmj.8tev.root")
wm_amcatnlo_t   = wm_amcatnlo_f.Get("Wjet")

wp_powheg_f   = TFile.Open("/hepstore/sfarry/predictions/powheg/powheg.wpj.8tev.root")
wp_powheg_t   = wp_amcatnlo_f.Get("Wjet")
wm_powheg_f   = TFile.Open("/hepstore/sfarry/predictions/powheg/powheg.wmj.8tev.root")
wm_powheg_t   = wm_amcatnlo_f.Get("Wjet")

plus  = TCut('mu_id == -13')
minus = TCut('mu_id == 13')


wmup_py8 = Template("wmup_py8", w_py8_t, py8fid_fwd + plus )
wmup_py8.AddVars(jetvars)
wmup_py8.AddVars(vars)
wmup_py8.Add2DVars(vars2d)
wmup_py8.Run()
wmup_py8.SaveToFile()

wmum_py8 = Template("wmum_py8", w_py8_t, py8fid_fwd + minus )
wmum_py8.AddVars(jetvars)
wmum_py8.AddVars(vars)
wmum_py8.Add2DVars(vars2d)
wmum_py8.Run()
wmum_py8.SaveToFile()

wmup_amcatnlo = Template("wmup_mcatnlo", wp_amcatnlo_t, py8fid_fwd )
wmup_amcatnlo.AddVars(jetvars)
wmup_amcatnlo.AddVars(vars)
wmup_amcatnlo.Add2DVars(vars2d)
wmup_amcatnlo.Run()
wmup_amcatnlo.SaveToFile()

wmum_amcatnlo = Template("wmum_mcatnlo", wm_amcatnlo_t, py8fid_fwd )
wmum_amcatnlo.AddVars(jetvars)
wmum_amcatnlo.AddVars(vars)
wmum_amcatnlo.Add2DVars(vars2d)
wmum_amcatnlo.Run()
wmum_amcatnlo.SaveToFile()

wmup_powheg = Template("wmup_mcatnlo", wp_powheg_t, py8fid_fwd )
wmup_powheg.AddVars(jetvars)
wmup_powheg.AddVars(vars)
wmup_powheg.Add2DVars(vars2d)
wmup_powheg.Run()
wmup_powheg.SaveToFile()

wmum_powheg = Template("wmum_mcatnlo", wm_powheg_t, py8fid_fwd )
wmum_powheg.AddVars(jetvars)
wmum_powheg.AddVars(vars)
wmum_powheg.Add2DVars(vars2d)
wmum_powheg.Run()
wmum_powheg.SaveToFile()

corr_amcatnlo_wpj_etaj = get_correction("corr_amcatnlo_wpj_etaj", wmup_amcatnlo.GetVar('etaj').GetHist(),  wmup_py8.GetVar('etaj').GetHist())
corr_amcatnlo_wpj_ptj  = get_correction("corr_amcatnlo_wpj_ptj" , wmup_amcatnlo.GetVar('ptj').GetHist() ,  wmup_py8.GetVar('ptj').GetHist() )
corr_amcatnlo_wpj_etaj_ptj = get_correction("corr_amcatnlo_wpj_etaj_ptj", wmup_amcatnlo.Get2DVar('etaj','ptj').GetHist(),  wmup_py8.Get2DVar('etaj','ptj').GetHist())

corr_amcatnlo_wmj_etaj = get_correction("corr_amcatnlo_wmj_etaj", wmum_amcatnlo.GetVar('etaj').GetHist(),  wmum_py8.GetVar('etaj').GetHist())
corr_amcatnlo_wmj_ptj  = get_correction("corr_amcatnlo_wmj_ptj" , wmum_amcatnlo.GetVar('ptj').GetHist() ,  wmum_py8.GetVar('ptj').GetHist() )
corr_amcatnlo_wmj_etaj_ptj = get_correction("corr_amcatnlo_wmj_etaj_ptj", wmum_amcatnlo.Get2DVar('etaj','ptj').GetHist(),  wmum_py8.Get2DVar('etaj','ptj').GetHist())

corr_powheg_wpj_etaj = get_correction("corr_powheg_wpj_etaj", wmup_powheg.GetVar('etaj').GetHist(),  wmup_py8.GetVar('etaj').GetHist())
corr_powheg_wpj_ptj  = get_correction("corr_powheg_wpj_ptj" , wmup_powheg.GetVar('ptj').GetHist() ,  wmup_py8.GetVar('ptj').GetHist() )
corr_powheg_wpj_etaj_ptj = get_correction("corr_powheg_wpj_etaj_ptj", wmup_powheg.Get2DVar('etaj','ptj').GetHist(),  wmup_py8.Get2DVar('etaj','ptj').GetHist())

corr_powheg_wmj_etaj = get_correction("corr_powheg_wmj_etaj", wmum_powheg.GetVar('etaj').GetHist(),  wmum_py8.GetVar('etaj').GetHist())
corr_powheg_wmj_ptj  = get_correction("corr_powheg_wmj_ptj" , wmum_powheg.GetVar('ptj').GetHist() ,  wmum_py8.GetVar('ptj').GetHist() )
corr_powheg_wmj_etaj_ptj = get_correction("corr_powheg_wmj_etaj_ptj", wmum_powheg.Get2DVar('etaj','ptj').GetHist(),  wmum_py8.Get2DVar('etaj','ptj').GetHist())

outputF = TFile("wmuj_kfactors.root", "RECREATE")
corr_amcatnlo_wpj_etaj.Write()
corr_amcatnlo_wpj_ptj.Write()
corr_amcatnlo_wpj_etaj_ptj.Write()
corr_amcatnlo_wmj_etaj.Write()
corr_amcatnlo_wmj_ptj.Write()
corr_amcatnlo_wmj_etaj_ptj.Write()
corr_powheg_wpj_etaj.Write()
corr_powheg_wpj_ptj.Write()
corr_powheg_wpj_etaj_ptj.Write()
corr_powheg_wmj_etaj.Write()
corr_powheg_wmj_ptj.Write()
corr_powheg_wmj_etaj_ptj.Write()
outputF.Close()
