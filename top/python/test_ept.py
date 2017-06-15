from top_config import *
from ROOT import *
from Jawa import *
from math import sqrt

selection         = TCut("min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5 && mu_PT > 20000 && e_PT > 15000 && mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000 && mu_ipubs_d < 0.04 && e_ipubs_d < 0.04 && e_isMuonLoose == 0")
selection_antiiso = TCut("mu_cpt_0.50 > 5000 && e_cpt_0.50 > 5000 && mu_ipubs_d < 0.04 && e_ipubs_d < 0.04 && min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5  && mu_PT > 20000 && e_PT > 15000 && e_isMuonLoose == 0 ")
selection_noiso   = TCut("mu_ipubs_d < 0.04 && e_ipubs_d < 0.04 && min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5 && mu_PT > 20000 && e_PT > 15000 && e_isMuonLoose == 0")
selection_noisoip   = TCut("min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5 && mu_PT > 20000 && e_PT > 15000 && e_isMuonLoose == 0")

selection_ss         = TCut("min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5 && mu_PT > 20000 && e_PT > 15000 && mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04 && e_isMuonLoose == 0")
selection_antiiso_ss = TCut("mu_cpt_0.50 > 5000 && e_cpt_0.50 > 5000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04 && min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5  && mu_PT > 20000 && e_PT > 15000 && e_isMuonLoose == 0 ")
selection_noiso_ss  = TCut("mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04 && min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5 && mu_PT > 20000 && e_PT > 15000 && e_isMuonLoose == 0")
selection_noisoip_ss  = TCut("min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5 && mu_PT > 20000 && e_PT > 15000 && e_isMuonLoose == 0")


mupem_fwdasy = TCut("mu_ID == -13 && mu_ETA > e_ETA")
mupem_bwdasy = TCut("mu_ID == -13 && mu_ETA < e_ETA")

mumep_fwdasy = TCut("mu_ID == 13 && mu_ETA < e_ETA")
mumep_bwdasy = TCut("mu_ID == 13 && mu_ETA > e_ETA")

jet = TCut("ttbar_jet_PT > 20000 && ttbar_jet_BDTTag == 1")
jet_notag = TCut("ttbar_jet_PT > 20000")
pi = '3.14159265959'
dPhi  = "abs(<A>_PHI - <B>_PHI) + (abs(<A>_PHI - <B>_PHI) > <pi>)*2*(<pi> - abs(<A>_PHI - <B>_PHI) )".replace('<pi>', pi)
dR = "sqrt((<A>_ETA - <B>_ETA)^2 + ("+dPhi+")^2)"


f = TFile("/hepstore/sfarry/GridOutput/3034/ttbar.MD.2016.root")
g = TFile("/hepstore/sfarry/GridOutput/3035/ttbar.MU.2016.root")
t = f.Get("ttbar/DecayTree")
u = g.Get("ttbar/DecayTree")
v = f.Get("ttbar_ss/DecayTree")
w = g.Get("ttbar_ss/DecayTree")

h = TFile("/hepstore/sfarry/GridOutput/3119/ttbar.Z_tautau.MU.MC2016.root")
i = TFile("/hepstore/sfarry/GridOutput/3120/ttbar.Z_tautau.MD.MC2016.root")
x = h.Get("ttbar/DecayTree")
y = i.Get("ttbar/DecayTree")


vars = [
    ["mu_pt"        , "mu_PT/1000.0"           , 10  , 20 , 100 ],
    ["e_pt"         , "e_PT/1000.0"            , 17  , 15 , 100 ],
    ['dphi'         , dPhi.replace('<A>', 'mu').replace('<B>', 'e'), 10, 0, TMath.Pi()],
    ['dR'           , dR.replace('<A>', 'mu').replace('<B>', 'e'), 10, 0, 5.0],
    ["mu_eta"       , "mu_ETA"     , 10, 2, 4.5], 
    ["e_eta"        , "e_ETA"      , 10, 2, 4.5], 
    ["ptj"          , "ttbar_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "ttbar_jet_ETA"   , 10, 2.2, 4.2 ],
    ["iso"          , "max(mu_cpt_0.50, e_cpt_0.50)/1000.0", 20, 0, 50]
    ]

ttbar =  Template("ttbar")
ttbar.SetSelCut(trigger + selection + jet)
ttbar.AddTree(t)
ttbar.AddTree(u)
ttbar.AddVars(vars)
ttbar.Run()
#ttbar.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev.root")

ttbar_ss = Template("ttbar_ss")
ttbar_ss.SetSelCut(trigger + selection_ss + jet)
ttbar_ss.AddTree(v)
ttbar_ss.AddTree(w)
ttbar_ss.AddVars(vars)
ttbar_ss.Run()
#ttbar_ss.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev_ss.root")

ttbar_noiso = Template("ttbar_noiso")
ttbar_noiso.SetSelCut(trigger + selection_noiso + jet)
ttbar_noiso.AddTree(t)
ttbar_noiso.AddTree(u)
ttbar_noiso.AddVars(vars)
ttbar_noiso.Run()
#ttbar_noiso.SaveToFile('/user2/sfarry/workspaces/top/tuples/ttbar_data13tev_noiso.root')

ttbar_noiso_ss = Template("ttbar_noiso_ss")
ttbar_noiso_ss.SetSelCut(trigger + selection_noiso_ss + jet)
ttbar_noiso_ss.AddTree(v)
ttbar_noiso_ss.AddTree(w)
ttbar_noiso_ss.AddVars(vars)
ttbar_noiso_ss.Run()
#ttbar_noiso_ss.SaveToFile('/user2/sfarry/workspaces/top/tuples/ttbar_data13tev_noiso_ss.root')

Ztautau =  Template("Ztautau")
Ztautau.SetSelCut(trigger + selection )
Ztautau.AddTree(x)
Ztautau.AddTree(y)
Ztautau.AddVars(vars)
Ztautau.Run()
#Ztautau.SaveToFile("/user2/sfarry/workspaces/top/tuples/Ztautau_data13tev.root")
