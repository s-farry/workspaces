from top_config import *
from ROOT import *
from Jawa import *

selection = TCut("mu_cpt_0.50 < 2000 && e_cpt_0.50 < 2000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
selection_antiiso = TCut("mu_cpt_0.50 > 2000 && e_cpt_0.50 > 2000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")

#zmumu_selection = TCut("muplus_cpt_0.50 < 2000 && muminus_cpt_0.50 < 2000 && muplus_IP_OWNPV < 0.04 && muminus_IP_OWNPV < 0.04")
zmumu_selection = TCut('boson_M > 60000 && boson_M < 120000 && muplus_PT > 20000 && muminus_PT > 20000 && min(muplus_ETA, muminus_ETA) > 2.0 && max(muplus_ETA, muminus_ETA) < 4.5')


mupem_fwdasy = TCut("mu_ID == -13 && mu_ETA > e_ETA")
mupem_bwdasy = TCut("mu_ID == -13 && mu_ETA < e_ETA")

mumep_fwdasy = TCut("mu_ID == 13 && mu_ETA < e_ETA")
mumep_bwdasy = TCut("mu_ID == 13 && mu_ETA > e_ETA")

jet_notag       = TCut("ttbar_jet_PT > 20000")
zmumu_jet_notag = TCut("boson_jet_PT > 20000")

jet       = TCut("ttbar_jet_PT > 20000 && ttbar_jet_BDTTag == 1")
zmumu_jet = TCut("boson_jet_PT > 20000 && boson_jet_BDTTag == 1")

vars = [
    ["mu_pt"        , "mu_PT/1000.0"           , 8  , 20 , 100 ],
    ["e_pt"         , "e_PT/1000.0"            , 8  , 20 , 100 ],
    ["mu_eta"       , "mu_ETA"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "e_ETA"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]

zvars = [
    ["mup_pt"       , "muplus_PT/1000.0"           , 8  , 20 , 100 ],
    ["mum_pt"       , "muminus_PT/1000.0"            , 8  , 20 , 100 ],
    ["mup_eta"      , "muplus_ETA"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["mum_eta"      , "muminus_ETA"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "boson_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "boson_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ]
    ]

#zmumuj_data = Template("zmumuj_data")
#zmumuj_data.SetSelCut(zmumu_selection + zmumu_jet)
#zmumuj_data.AddTrees(zmumuj_2016.trees())
#zmumuj_data.AddTrees(zmumuj_2015.trees())
#zmumuj_data.AddVars(vars)
#zmumuj_data.Run()
#zmumuj_data.SaveToFile()

zmumu_xsec = 1.693e-6*1e9 # in pb
zmumu_acc  = 10000.0/26298.0
zmumu_evts = zmumu_mc2015.MU.Get("TotEvts").GetVal() + zmumu_mc2015.MD.Get("TotEvts").GetVal()
zmumu_sf   = zmumu_xsec * zmumu_acc / zmumu_evts

zmumuj_xsec = 2.263e-6*1e9 # in pb
zmumuj_acc  = 10000.0/30454.0
zmumuj_evts = zmumuj_mc2015.MU.Get("TotEvts").GetVal() + zmumuj_mc2015.MD.Get("TotEvts").GetVal()
zmumuj_sf   = zmumuj_xsec * zmumuj_acc / zmumuj_evts

ztautau_xsec = 1.689e-6*1e9 # in pb
ztautau_acc  = 10000.0/26554.0
ztautau_evts = ztautau_mc2016.MU.Get("TotEvts").GetVal() + ztautau_mc2016.MD.Get("TotEvts").GetVal()
ztautau_sf   = ztautau_xsec * ztautau_acc / ztautau_evts

zmumu_mc2015_t = Template("zmumu_mc2015")
zmumu_mc2015_t.SetSelCut(zmumu_selection)
zmumu_mc2015_t.AddTrees(zmumu_mc2015.trees())
zmumu_mc2015_t.AddVars(zvars)
zmumu_mc2015_t.Run()
zmumu_mc2015_t.Scale(zmumu_sf)
zmumu_mc2015_t.SaveToFile("/user2/sfarry/workspaces/top/tuples/zmumu_mc2015.root")

ztautau_mc2016_t = Template("ztautau_mc2016")
ztautau_mc2016_t.SetSelCut(selection)
ztautau_mc2016_t.AddTrees(ztautau_mc2016.trees())
ztautau_mc2016_t.AddVars(vars)
ztautau_mc2016_t.Run()
ztautau_mc2016_t.Scale(ztautau_sf)
ztautau_mc2016_t.SaveToFile("/user2/sfarry/workspaces/top/tuples/ztautau_mc2016.root")

zmumuj_mc2015_t = Template("zmumuj_mc2015")
zmumuj_mc2015_t.SetSelCut(zmumu_selection + zmumu_jet_notag)
zmumuj_mc2015_t.AddTrees(zmumuj_mc2015.trees())
zmumuj_mc2015_t.AddVars(zvars)
zmumuj_mc2015_t.Run()
zmumuj_mc2015_t.Scale(zmumuj_sf)
zmumuj_mc2015_t.SaveToFile()

ztautauj_mc2016_t = Template("ztautauj_mc2016")
ztautauj_mc2016_t.SetSelCut(selection + jet_notag)
ztautauj_mc2016_t.AddTrees(ztautau_mc2016.trees())
ztautauj_mc2016_t.AddVars(vars)
ztautauj_mc2016_t.Run()
ztautauj_mc2016_t.Scale(ztautau_sf)
ztautauj_mc2016_t.SaveToFile("/user2/sfarry/workspaces/top/tuples/ztautauj_mc2016.root")

#Nztautauj = zmumuj_data.GetEvts() * (ztautauj.GetNormEvts() / zmumuj.GetNormEvts())
Nztautauj_mc = ztautau_mc2016_t.GetNormEvts()
