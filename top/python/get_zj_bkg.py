from top_config import *
from ROOT import *
from Jawa import *

selection = TCut("mu_cpt_0.50 < 2000 && e_cpt_0.50 < 2000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
selection_antiiso = TCut("mu_cpt_0.50 > 2000 && e_cpt_0.50 > 2000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")

zmumu_selection = TCut("muplus_cpt_0.50 < 2000 && muminus_cpt_0.50 < 2000 && muplus_IP_OWNPV < 0.04 && muminus_IP_OWNPV < 0.04")


mupem_fwdasy = TCut("mu_ID == -13 && mu_ETA > e_ETA")
mupem_bwdasy = TCut("mu_ID == -13 && mu_ETA < e_ETA")

mumep_fwdasy = TCut("mu_ID == 13 && mu_ETA < e_ETA")
mumep_bwdasy = TCut("mu_ID == 13 && mu_ETA > e_ETA")

jet_notag = TCut("ttbar_jet_PT > 20000")
zmumu_jet_notag = TCut("boson_jet_PT > 20000")

jet = TCut("ttbar_jet_PT > 20000 && ttbar_jet_BDTTag == 1")
zmumu_jet = TCut("boson_jet_PT > 20000 && boson_jet_BDTTag == 1")

vars = [
    ["mu_pt"        , "mu_PT/1000.0"           , 80  , 0 , 80 ],
    ["e_pt"         , "e_PT/1000.0"            , 80  , 0 , 80 ],
    ["mu_eta"       , "mu_ETA"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "e_ETA"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]

zmumuj_data = Template("zmumuj_data")
zmumuj_data.SetSelCut(zmumu_selection + zmumu_jet)
zmumuj_data.AddTrees(zmumuj_2016.trees())
zmumuj_data.AddTrees(zmumuj_2015.trees())
zmumuj_data.AddVars(vars)
zmumuj_data.Run()
zmumuj_data.SaveToFile()

zmumuj_xsec = 1.689e-6*1e9 # in pb
zmumuj_acc  = 10000.0/26554.0
zmumuj_evts = zmumuj_mc2016.MU.Get("TotEvts").GetVal() + zmumuj_mc2016.MD.Get("TotEvts").GetVal()
zmumuj_sf   = zmumuj_xsec * zmumuj_acc / zmumuj_evts

ztautauj_xsec = 1.689e-6*1e9 # in pb
ztautauj_acc  = 10000.0/26554.0
ztautauj_evts = ztautauj_mc2016.MU.Get("TotEvts").GetVal() + ztautauj_mc2016.MD.Get("TotEvts").GetVal()
ztautauj_sf   = ztautauj_xsec * ztautauj_acc / ztautauj_evts

zmumuj_mc2016 = Template("zmumuj_mc2016")
zmumuj_mc2016.SetSelCut(zmumu_selection + zmumu_jet_notag)
zmumuj_mc2016.AddTrees(zmumuj_mc2016.trees())
zmumuj_mc2016.AddVars(vars)
zmumuj_mc2016.Run()
zmumuj.Scale(zmumuj_sf)
zmumuj_mc2016.SaveToFile()

ztautauj_mc2016 = Template("ztautauj_mc2016")
ztautauj_mc2016.SetSelCut(selection + jet_notag)
ztautauj_mc2016.AddTrees(ztautauj_mc2016.trees())
ztautauj_mc2016.AddVars(vars)
ztautauj_mc2016.Run()
ztautauj.Scale(ztautauj_sf)
ztautauj_mc2016.SaveToFile()

Nztautauj = zmumuj_data.GetEvts() * (ztautauj.GetNormEvts() / zmumuj.GetNormEvts())
