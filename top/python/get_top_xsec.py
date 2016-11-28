from ROOT import TFile, TH1F, THStack, kYellow, kOrange, kViolet, kGreen
from PlotTools import *
from Style import *
from Utils import Bunch

SetLHCbStyle()


data     = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev.root")
data_ss  = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_ss.root")
data_antiiso  = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_antiiso.root")
top      = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mc2016.root")
ztautauj = TFile("/user2/sfarry/workspaces/top/tuples/ztautauj_mc2016.root")
ztautau  = TFile("/user2/sfarry/workspaces/top/tuples/ztautau_mc2016.root")
zmumu    = TFile("/user2/sfarry/workspaces/top/tuples/zmumu_mc2015.root")
zmumuj_data = TFile("/user2/sfarry/workspaces/top/tuples/zmumuj_data.root")

mcatnlo_predictions = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_amcatnlo_predictions.root")
powheg_predictions  = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_powheg_predictions.root")
wtOttbar = powheg_predictions.Get("Wt_dr_xsec").GetVal()/mcatnlo_predictions.Get('etaj_tot').GetVal()

#eff1 included in reconstruction efficiency
#eff1 = TFile("/user2/sfarry/workspaces/top/tuples/jeteff.root")
eff2 = TFile("/user2/sfarry/workspaces/top/tuples/tageff.root")
eff3 = TFile("/user2/sfarry/workspaces/top/tuples/seleff.root")
eff4 = TFile("/user2/sfarry/workspaces/top/tuples/receff.root")

eff = eff2.Get('TotalEff').GetVal() * eff3.Get('TotalEff').GetVal() * eff4.Get('TotalEff').GetVal()

L = 1665.865

Nevts = data.Get('TotEvts').GetVal()
Nqcd  = data_ss.Get('TotEvts').GetVal()
Nzj   = zmumuj_data.Get('TotEvts').GetVal()*ztautau.Get('NormEvts').GetVal()/zmumu.Get('NormEvts').GetVal()
Nwt   = (Nevts - (Nqcd + Nzj))*(wtOttbar/(1+wtOttbar))

Nsig  = Nevts - Nqcd - Nzj - Nwt

print "Number of selected events: ", Nevts
print "Same sign background     : ", Nqcd
print "Z+jets background        : ", Nzj
print "Wt background            : ", Nwt
print "Signal Events            : ", Nsig
print "Lumi                     : ",L
print "Efficiency               : ",eff
print "Cross-section            : ",Nsig / (eff * L)


lhcb = ROOT.TPaveText(0.5, 0.82, 0.85, 0.9, "NDC")
lhcb.AddText("LHCb, #sqrt{s} = 13 TeV")
lhcb.SetFillStyle(0)
lhcb.SetBorderSize(0)

variables = [
    Bunch(name='ptj'   , xlabel = 'p_{T}(j)', ylims = [0,14]),
    Bunch(name='mu_pt' , xlabel = 'p_{T}(#mu)', ylims = [0, 13]),
    Bunch(name='e_pt'  , xlabel = 'p_{T}(e)'),
    Bunch(name='etaj'  , xlabel = '#eta(j)', ylims = [0, 14]),
    Bunch(name='mu_eta', xlabel = '#eta(#mu)', ylims = [0, 19]),
    Bunch(name='e_eta' , xlabel = '#eta(e)', ylims = [0, 19])
    ]

for v in variables:
    d = data.Get(v.name)
    t = top.Get(v.name)
    wt = top.Get(v.name).Clone('wt_'+v.name)
    if v.name=='ptj' or v.name=='etaj':
        z = zmumuj_data.Get(v.name)
    else:
        z = ztautau.Get(v.name)
    qcd = data_antiiso.Get(v.name)

    t.Scale(Nsig / t.Integral())
    wt.Scale(Nwt / wt.Integral())
    z.Scale(Nzj / z.Integral())
    qcd.Scale(Nqcd / qcd.Integral())

    #make it like a stack
    t.Add(wt)
    t.Add(z)
    t.Add(qcd)
    wt.Add(z)
    wt.Add(qcd)
    z.Add(qcd)

    p = Plot([d, t, wt, z, qcd, d])
    p.setProp('colors', ['black', kViolet-1, kOrange -2, kYellow-2, kGreen, 'black'])
    p.setProp('markerstyles', [20, 0, 0, 0, 0, 20])
    p.setProp('fillstyles', [0, 1001, 1001, 1001, 1001, 0])
    p.setProp('drawOpts', ['p1', 'histf','histf','histf','histf', 'p1'])
    p.setProp('labels', ['data', 't#bar{t}', 'Wt','Z+jets', 'QCD'])
    p.setProp('filename', v.name+'_result.pdf')
    p.setProp('xlabel', v.xlabel)
    p.setProp('ylabel', 'Events')
    p.setProp('leglims', [0.6, 0.5, 0.9, 0.8])
    p.setProp('extraObjs', [lhcb])
    p.setProp('location', '/user2/sfarry/workspaces/top/figures')
    if hasattr(v, 'ylims'): p.setProp('ylims', v.ylims)
    p.drawROOT()

    

