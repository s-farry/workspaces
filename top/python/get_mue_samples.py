from top_config import *
from ROOT import *
from Jawa import *
from math import sqrt

selection         = TCut("mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
selection_antiiso = TCut("mu_cpt_0.50 > 5000 && e_cpt_0.50 > 5000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
selection_noiso   = TCut("mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")


mupem_fwdasy = TCut("mu_ID == -13 && mu_ETA > e_ETA")
mupem_bwdasy = TCut("mu_ID == -13 && mu_ETA < e_ETA")

mumep_fwdasy = TCut("mu_ID == 13 && mu_ETA < e_ETA")
mumep_bwdasy = TCut("mu_ID == 13 && mu_ETA > e_ETA")

jet = TCut("ttbar_jet_PT > 20000 && ttbar_jet_BDTTag == 1")


mvis = "sqrt((mu_E + e_E + ttbar_jet_E)^2 - (mu_PX + e_PX + ttbar_jet_PX)^2 - (mu_PY + e_PY + ttbar_jet_PY)^2 - (mu_PZ + e_PZ + ttbar_jet_PZ)^2)"

mvis_true = "sqrt((lp_E + lm_E + ttbar_jet_E)^2 - (lp_PX + lm_PX + ttbar_jet_PX)^2 - (lp_PY + lm_PY + ttbar_jet_PY)^2 - (lp_PZ + lm_PZ + ttbar_jet_PZ)^2)"

fid = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000 && ttbar_jet_PT > 20000 && abs(ttbar_jet_flavour) == 5")
fid_notag = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000 && ttbar_jet_PT > 20000")
fid_nojet = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000")



tt_qq_evts = qq2ttbar_mc2016.MU.Get('TotEvts').GetVal() + qq2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_qq_xsec = 9.966e-8*1e9
tt_qq_acc  = 10000.0/106462.0
tt_qq_scale = tt_qq_xsec * tt_qq_acc /tt_qq_evts

tt_gg_evts = gg2ttbar_mc2016.MU.Get('TotEvts').GetVal() + gg2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_gg_xsec = 5.826e-7*1e9
tt_gg_acc  = 10000.0/156045.0
tt_gg_scale = tt_gg_xsec * tt_gg_acc /tt_gg_evts

ww_py8_evts = ww_mc2016.MU.Get('TotEvts').GetVal() + ww_mc2016.MD.Get('TotEvts').GetVal()
#ww_py8_xsec = 3.176e-9 * 1e12 # in fb
ww_py8_xsec = 3.176e-9 * 1e9 # in pb
ww_py8_acc = 10000.0/30719.0
ww_scale = ww_py8_xsec * ww_py8_acc / ww_py8_evts


mupem = TCut("lp_ID == -13 && lm_ID == 11" )
mumep = TCut("lp_ID == -11  && lm_ID == 13")

mupemvars = [
    ["mu_pt"        , "lp_PT/1000.0"           , 80  , 20 , 100 ],
    ["e_pt"         , "lm_PT/1000.0"            , 80  , 20 , 100 ],
    ["mu_eta"       , "abs(lp_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(lm_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , 10, 2.2, 4.2 ],
#    ["mvis"         , mvis_true              , 20, 0, 100]
    ]

mumepvars = [
    ["mu_pt"        , "lm_PT/1000.0"           , 80  , 20 , 100 ],
    ["e_pt"         , "lp_PT/1000.0"            , 80  , 20 , 100 ],
    ["mu_eta"       , "abs(lm_ETA)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(lp_ETA)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000.0"       , 5, 20, 220],
    ["etaj"         , "ttbar_jet_ETA"   , 10, 2.2, 4.2 ],
#    ["mvis"         , mvis_true              , 20, 0, 100]
    ]

# get LO from pythia
ww_py8_mupem = Template("ww_py8_mupem")
ww_py8_mupem.SetSelCut(fid_nojet + mupem)
ww_py8_mupem.AddTrees([ww_mc2016.MU.Get("MCGenTrackEff/MCTrackEffTuple"), ww_mc2016.MD.Get("MCGenTrackEff/MCTrackEffTuple")])
ww_py8_mupem.AddVars(mupemvars)
ww_py8_mupem.Run()
ww_py8_mupem.Scale(ww_scale)

ww_py8_mumep = Template("ww_py8_mumep")
ww_py8_mumep.SetSelCut(fid_nojet + mumep)
ww_py8_mumep.AddTrees([ww_mc2016.MU.Get("MCGenTrackEff/MCTrackEffTuple"), ww_mc2016.MD.Get("MCGenTrackEff/MCTrackEffTuple")])
ww_py8_mumep.AddVars(mumepvars)
ww_py8_mumep.Run()
ww_py8_mumep.Scale(ww_scale)

ww_py8 = Template("ww_mue_py8", ww_py8_mupem, ww_py8_mumep)
ww_py8.SaveToFile()

# get LO from pythia
qq2ttbar_py8_mupem = Template("qq2ttbar_py8_mupem")
qq2ttbar_py8_mupem.SetSelCut(fid_nojet + mupem)
qq2ttbar_py8_mupem.AddTrees([qq2ttbar_mc2016.MU.Get("MCGenTrackEff/MCTrackEffTuple"), qq2ttbar_mc2016.MD.Get("MCGenTrackEff/MCTrackEffTuple")])
qq2ttbar_py8_mupem.AddVars(mupemvars)
qq2ttbar_py8_mupem.Run()
qq2ttbar_py8_mupem.Scale(tt_qq_scale)

qq2ttbar_py8_mumep = Template("qq2ttbar_py8_mumep")
qq2ttbar_py8_mumep.SetSelCut(fid_nojet + mumep)
qq2ttbar_py8_mumep.AddTrees([qq2ttbar_mc2016.MU.Get("MCGenTrackEff/MCTrackEffTuple"), qq2ttbar_mc2016.MD.Get("MCGenTrackEff/MCTrackEffTuple")])
qq2ttbar_py8_mumep.AddVars(mumepvars)
qq2ttbar_py8_mumep.Run()
qq2ttbar_py8_mumep.Scale(tt_qq_scale)

qq2ttbar_py8 = Template("qq2ttbar_mue_py8", qq2ttbar_py8_mupem, qq2ttbar_py8_mumep)
qq2ttbar_py8.SaveToFile()

# get LO from pythia
gg2ttbar_py8_mupem = Template("gg2ttbar_py8_mupem")
gg2ttbar_py8_mupem.SetSelCut(fid_nojet + mupem)
gg2ttbar_py8_mupem.AddTrees([gg2ttbar_mc2016.MU.Get("MCGenTrackEff/MCTrackEffTuple"), gg2ttbar_mc2016.MD.Get("MCGenTrackEff/MCTrackEffTuple")])
gg2ttbar_py8_mupem.AddVars(mupemvars)
gg2ttbar_py8_mupem.Run()
gg2ttbar_py8_mupem.Scale(tt_gg_scale)

gg2ttbar_py8_mumep = Template("gg2ttbar_py8_mumep")
gg2ttbar_py8_mumep.SetSelCut(fid_nojet + mumep)
gg2ttbar_py8_mumep.AddTrees([gg2ttbar_mc2016.MU.Get("MCGenTrackEff/MCTrackEffTuple"), gg2ttbar_mc2016.MD.Get("MCGenTrackEff/MCTrackEffTuple")])
gg2ttbar_py8_mumep.AddVars(mumepvars)
gg2ttbar_py8_mumep.Run()
gg2ttbar_py8_mumep.Scale(tt_gg_scale)

gg2ttbar_py8 = Template("gg2ttbar_mue_py8", gg2ttbar_py8_mupem, gg2ttbar_py8_mumep)
gg2ttbar_py8.SaveToFile()

ttbar_py8 = Template("ttbar_mue_py8", qq2ttbar_py8, gg2ttbar_py8 )
ttbar_py8.SaveToFile()
