from ROOT import *


f = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_ss.root")

h = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13teV_amcatnlo_predictions.root")

i = TFile("/user2/sfarry/workspaces/top/tuples/ztautau_mc2016.root")
j = TFile("/user2/sfarry/workspaces/top/tuples/zmumu_mc2015.root")
k = TFile("/user2/sfarry/workspaces/top/tuples/zmumuj_data.root")


eff1 = TFile("/user2/sfarry/workspaces/top/tuples/jeteff.root")
eff2 = TFile("/user2/sfarry/workspaces/top/tuples/tageff.root")
eff3 = TFile("/user2/sfarry/workspaces/top/tuples/seleff.root")
eff4 = TFile("/user2/sfarry/workspaces/top/tuples/receff.root")

eff = eff1.Get('TotalEff').GetVal() * eff2.Get('TotalEff').GetVal() * eff3.Get('TotalEff').GetVal() * eff4.Get('TotalEff').GetVal()


L = 1665.865

Nevts = f.Get('TotEvts').GetVal()
Nqcd  = g.Get('TotEvts').GetVal()
Nzj   = k.Get('TotEvts').GetVal()*i.Get('NormEvts').GetVal()/j.Get('NormEvts').GetVal()
Nwt   = (Nevts - (Nqcd + Nzj))*h.Get('Wt_dr_xsec').GetVal()/h.Get('etaj_tot').GetVal()

Nsig  = Nevts - Nqcd - Nzj - Nwt

print "Number of selected events: ", Nevts
print "Same sign background     : ", Nqcd
print "Z+jets background        : ", Nzj
print "Wt background            : ", Nwt
print "Signal Events            : ", Nsig
print "Lumi                     : ",L
print "Efficiency               : ",eff
print "Cross-section            : ",Nsig / (eff * L)



