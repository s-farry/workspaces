from os import sys
from Jawa import *
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *
from math import *

def GetAcceptance(name, numerator, denominator, common):
    asymm = numerator.Clone(name)
    asymm.Divide(denominator)
    #calculate error correctly to take into account common events
    # i.e. acceptance = (a+b)/(a+c)
    #df/da = (c-b)/(a+c)^2
    #df/db = (a+c)/(a+c)^2
    #df/dc = -(a+b)/(a+c)^2
    for i in range(asymm.GetNbinsX()):
        a = common.GetBinContent(i+1)
        b = numerator.GetBinContent(i+1) - a
        c = denominator.GetBinContent(i+1) - a
        print a, b, c
        err = sqrt(pow(sqrt(a)*(c - b)/pow(a+c,2),2) + pow(sqrt(b)*(a+c)/pow(a+c,2),2)
                   + pow(sqrt(c) * (a+b)/pow(a+c,2),2))
        asymm.SetBinError(i+1, err)
    return asymm


wmupj = Template("wmupj_jmu")
wmupj.SetSelCut(selcut_base + ip + mumjpt + plus)
wmupj.AddTree(wmuj_mc2012.MUt)
wmupj.AddTree(wmuj_mc2012.MDt)
wmupj.AddVars(variables)
wmupj.AddVars(jetvars)
#wmupj.MaxEvts = 300
wmupj.Run()
#wmupj.SaveToFile()

wmumj = Template("wmumj_jmu")
wmumj.SetSelCut(selcut_base + ip + mumjpt + minus)
wmumj.AddTree(wmuj_mc2012.MUt)
wmumj.AddTree(wmuj_mc2012.MDt)
wmumj.AddVars(variables)
wmumj.AddVars(jetvars)
#wmumj.MaxEvts = 300
wmumj.Run()
#wmumj.SaveToFile()


wmupj_mu = Template("wmupj_mu")
wmupj_mu.SetSelCut(selcut_base + ip + mumjpt_nojet + plus)
wmupj_mu.AddTree(wmuj_mc2012.MUt)
wmupj_mu.AddTree(wmuj_mc2012.MDt)
wmupj_mu.AddVars(variables)
wmupj_mu.AddVars(jetvars)
#wmupj_mu.MaxEvts = 300
wmupj_mu.Run()
#wmupj.SaveToFile()

wmumj_mu = Template("wmumj_mu")
wmumj_mu.SetSelCut(selcut_base + ip + mumjpt_nojet + minus)
wmumj_mu.AddTree(wmuj_mc2012.MUt)
wmumj_mu.AddTree(wmuj_mc2012.MDt)
wmumj_mu.AddVars(variables)
wmumj_mu.AddVars(jetvars)
#wmumj_mu.MaxEvts = 300
wmumj_mu.Run()
#wmumj.SaveToFile()



wmupj_full = Template("wmupj_full")
wmupj_full.SetSelCut(selcut_base + ip + mumjpt_nojet + mumjpt + plus)
wmupj_full.AddTree(wmuj_mc2012.MUt)
wmupj_full.AddTree(wmuj_mc2012.MDt)
wmupj_full.AddVars(variables)
wmupj_full.AddVars(jetvars)
#wmupj_full.MaxEvts = 300
wmupj_full.Run()
#wmupj.SaveToFile()

wmumj_full = Template("wmumj_full")
wmumj_full.SetSelCut(selcut_base + ip + mumjpt_nojet + mumjpt + minus)
wmumj_full.AddTree(wmuj_mc2012.MUt)
wmumj_full.AddTree(wmuj_mc2012.MDt)
wmumj_full.AddVars(variables)
wmumj_full.AddVars(jetvars)
#wmumj_full.MaxEvts = 300
wmumj_full.Run()
#wmumj.SaveToFile()

p_hists = []
m_hists = []


weightF = TFile("wmuj_kfactors.root")
wmupj_nlo_corr = weightF.Get("corr_amcatnlo_wpj_etaj_ptj")
wmumj_nlo_corr = weightF.Get("corr_amcatnlo_wmj_etaj_ptj")

wmupj_nlo = Template("wmupj_nlo_jmu")
wmupj_nlo.SetSelCut(selcut_base + ip + mumjpt + plus)
wmupj_nlo.AddTree(wmuj_mc2012.MUt)
wmupj_nlo.AddTree(wmuj_mc2012.MDt)
wmupj_nlo.AddVars(variables)
wmupj_nlo.AddVars(jetvars)
wmupj_nlo.Reweight("muminus_truejet_ETA", "muminus_truejet_PT/1000.0",wmupj_nlo_corr)
wmupj_nlo.Run()

wmumj_nlo = Template("wmumj_nlo_jmu")
wmumj_nlo.SetSelCut(selcut_base + ip + mumjpt + minus)
wmumj_nlo.AddTree(wmuj_mc2012.MUt)
wmumj_nlo.AddTree(wmuj_mc2012.MDt)
wmumj_nlo.AddVars(variables)
wmumj_nlo.AddVars(jetvars)
wmumj_nlo.Reweight("muminus_truejet_ETA", "muminus_truejet_PT/1000.0",wmumj_nlo_corr)
wmumj_nlo.Run()

wmupj_nlo_mu = Template("wmupj_nlo_mu")
wmupj_nlo_mu.SetSelCut(selcut_base + ip + mumjpt_nojet + plus)
wmupj_nlo_mu.AddTree(wmuj_mc2012.MUt)
wmupj_nlo_mu.AddTree(wmuj_mc2012.MDt)
wmupj_nlo_mu.AddVars(variables)
wmupj_nlo_mu.AddVars(jetvars)
wmupj_nlo_mu.Reweight("muminus_truejet_ETA", "muminus_truejet_PT/1000.0",wmupj_nlo_corr)
wmupj_nlo_mu.Run()

wmumj_nlo_mu = Template("wmumj_nlo_mu")
wmumj_nlo_mu.SetSelCut(selcut_base + ip + mumjpt_nojet + minus)
wmumj_nlo_mu.AddTree(wmuj_mc2012.MUt)
wmumj_nlo_mu.AddTree(wmuj_mc2012.MDt)
wmumj_nlo_mu.AddVars(variables)
wmumj_nlo_mu.AddVars(jetvars)
wmumj_nlo_mu.Reweight("muminus_truejet_ETA", "muminus_truejet_PT/1000.0",wmumj_nlo_corr)
wmumj_nlo_mu.Run()

wmupj_nlo_full = Template("wmupj_nlo_full")
wmupj_nlo_full.SetSelCut(selcut_base + ip + mumjpt_nojet + mumjpt + plus)
wmupj_nlo_full.AddTree(wmuj_mc2012.MUt)
wmupj_nlo_full.AddTree(wmuj_mc2012.MDt)
wmupj_nlo_full.AddVars(variables)
wmupj_nlo_full.AddVars(jetvars)
wmupj_nlo_full.Reweight("muminus_truejet_ETA", "muminus_truejet_PT/1000.0",wmupj_nlo_corr)
wmupj_nlo_full.Run()

wmumj_nlo_full = Template("wmumj_nlo_full")
wmumj_nlo_full.SetSelCut(selcut_base + ip + mumjpt_nojet + mumjpt + minus)
wmumj_nlo_full.AddTree(wmuj_mc2012.MUt)
wmumj_nlo_full.AddTree(wmuj_mc2012.MDt)
wmumj_nlo_full.AddVars(variables)
wmumj_nlo_full.AddVars(jetvars)
wmumj_nlo_full.Reweight("muminus_truejet_ETA", "muminus_truejet_PT/1000.0",wmumj_nlo_corr)
wmumj_nlo_full.Run()


p_nlo_hists = []
m_nlo_hists = []

f = TFile("wj_acc.root", "RECREATE")

for var in ['ETA', 'Jet_PT', 'Jet_ETA']:
    p = GetAcceptance(var+'wmupj_acc', wmupj_mu.GetVar(var).GetHist(),
                      wmupj.GetVar(var).GetHist(), wmupj_full.GetVar(var).GetHist())
    m = GetAcceptance(var+'wmumj_acc', wmumj_mu.GetVar(var).GetHist(),
                      wmumj.GetVar(var).GetHist(), wmumj_full.GetVar(var).GetHist())
    p_hists += [p]
    m_hists += [m]
    p.Write(var+'_acc_plus')
    m.Write(var+'_acc_minus')

    p_nlo = GetAcceptance(var+'wmupj_acc', wmupj_nlo_mu.GetVar(var).GetHist(),
                      wmupj_nlo.GetVar(var).GetHist(), wmupj_nlo_full.GetVar(var).GetHist())
    m_nlo = GetAcceptance(var+'wmumj_acc', wmumj_nlo_mu.GetVar(var).GetHist(),
                      wmumj_nlo.GetVar(var).GetHist(), wmumj_nlo_full.GetVar(var).GetHist())
    p_nlo_hists += [p_nlo]
    m_nlo_hists += [m_nlo]
    p_nlo.Write(var+'_nlo_acc_plus')
    m_nlo.Write(var+'_nlo_acc_minus')

print "saving"
saveTH1F('/user2/sfarry/WJet/dat/wp_acc_eta.dat'  , p_hists[0])
saveTH1F('/user2/sfarry/WJet/dat/wm_acc_eta.dat'  , m_hists[0])
saveTH1F('/user2/sfarry/WJet/dat/wp_acc_ptj.dat'  , p_hists[1])
saveTH1F('/user2/sfarry/WJet/dat/wm_acc_ptj.dat'  , m_hists[1])
saveTH1F('/user2/sfarry/WJet/dat/wp_acc_etaj.dat' , p_hists[2])
saveTH1F('/user2/sfarry/WJet/dat/wm_acc_etaj.dat' , m_hists[2])
saveTH1F('/user2/sfarry/WJet/dat/wp_nlo_acc_eta.dat'  , p_nlo_hists[0])
saveTH1F('/user2/sfarry/WJet/dat/wm_nlo_acc_eta.dat'  , m_nlo_hists[0])
saveTH1F('/user2/sfarry/WJet/dat/wp_nlo_acc_ptj.dat'  , p_nlo_hists[1])
saveTH1F('/user2/sfarry/WJet/dat/wm_nlo_acc_ptj.dat'  , m_nlo_hists[1])
saveTH1F('/user2/sfarry/WJet/dat/wp_nlo_acc_etaj.dat' , p_nlo_hists[2])
saveTH1F('/user2/sfarry/WJet/dat/wm_nlo_acc_etaj.dat' , m_nlo_hists[2])
print "saved"

f.Close()

'''
wmuincpj_nocut = Template("wmuincpj_jmu_nocut")
wmuincpj_nocut.SetSelCut(selcut_base + ip + plus)
wmuincpj_nocut.AddTree(wmuj_inc_mc2012.MUt)
wmuincpj_nocut.AddTree(wmuj_inc_mc2012.MDt)
wmuincpj_nocut.AddVars(variables)
wmuincpj_nocut.AddVars(jetvars)
wmuincpj_nocut.Run()

wmuincpj = Template("wmuincpj_jmu")
wmuincpj.SetSelCut(selcut_base + ip + mumjpt + plus)
wmuincpj.AddTree(wmuj_inc_mc2012.MUt)
wmuincpj.AddTree(wmuj_inc_mc2012.MDt)
wmuincpj.AddVars(variables)
wmuincpj.AddVars(jetvars)
wmuincpj.Run()
#wmuincpj.SaveToFile()

wmuincmj = Template("wmuincmj_jmu")
wmuincmj.SetSelCut(selcut_base + ip + mumjpt + minus)
wmuincmj.AddTree(wmuj_inc_mc2012.MUt)
wmuincmj.AddTree(wmuj_inc_mc2012.MDt)
wmuincmj.AddVars(variables)
wmuincmj.AddVars(jetvars)
wmuincmj.Run()
#wmuincmj.SaveToFile()


wmuincpj_mu = Template("wmuincpj_mu")
wmuincpj_mu.SetSelCut(selcut_base + ip + mumjpt_nojet + plus)
wmuincpj_mu.AddTree(wmuj_inc_mc2012.MUt)
wmuincpj_mu.AddTree(wmuj_inc_mc2012.MDt)
wmuincpj_mu.AddVars(variables)
wmuincpj_mu.AddVars(jetvars)
wmuincpj_mu.Run()
#wmuincpj.SaveToFile()

wmuincmj_mu = Template("wmuincmj_mu")
wmuincmj_mu.SetSelCut(selcut_base + ip + mumjpt_nojet + minus)
wmuincmj_mu.AddTree(wmuj_inc_mc2012.MUt)
wmuincmj_mu.AddTree(wmuj_inc_mc2012.MDt)
wmuincmj_mu.AddVars(variables)
wmuincmj_mu.AddVars(jetvars)
wmuincmj_mu.Run()
#wmuincmj.SaveToFile()


wmuincpj_full = Template("wmuincpj_full")
wmuincpj_full.SetSelCut(selcut_base + ip + mumjpt_nojet + mumjpt + plus)
wmuincpj_full.AddTree(wmuj_inc_mc2012.MUt)
wmuincpj_full.AddTree(wmuj_inc_mc2012.MDt)
wmuincpj_full.AddVars(variables)
wmuincpj_full.AddVars(jetvars)
wmuincpj_full.Run()
#wmuincpj.SaveToFile()

wmuincmj_full = Template("wmuincmj_full")
wmuincmj_full.SetSelCut(selcut_base + ip + mumjpt_nojet + mumjpt + minus)
wmuincmj_full.AddTree(wmuj_inc_mc2012.MUt)
wmuincmj_full.AddTree(wmuj_inc_mc2012.MDt)
wmuincmj_full.AddVars(variables)
wmuincmj_full.AddVars(jetvars)
wmuincmj_full.Run()

p_hists = []
m_hists = []

f = TFile("wj_inc_acc.root", "RECREATE")

for var in ['ETA', 'Jet_PT', 'Jet_ETA']:
    p = GetAcceptance(var+'wmuincpj_acc', wmuincpj_mu.GetVar(var).GetHist(),
                      wmuincpj.GetVar(var).GetHist(), wmuincpj_full.GetVar(var).GetHist())
    m = GetAcceptance(var+'wmuincmj_acc', wmuincmj_mu.GetVar(var).GetHist(),
                      wmuincmj.GetVar(var).GetHist(), wmuincmj_full.GetVar(var).GetHist())
    p_hists += [p]
    m_hists += [m]
    p.Write(var+'_acc_plus')
    m.Write(var+'_acc_minus')

f.Close()
'''
