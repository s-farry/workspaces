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


vars = [
    ["mu_pt"        , "mu_PT/1000.0"           , 10  , 20 , 80 ],
    ["e_pt"         , "e_PT/1000.0"            , 10  , 20 , 80 ],
    ["mu_eta"       , "mu_ETA"     , 10, 2, 4.5], 
    ["e_eta"        , "e_ETA"      , 10, 2, 4.5], 
    ["ptj"          , "ttbar_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "ttbar_jet_ETA"   , 10, 2.2, 4.2 ],
    ["iso"          , "max(mu_cpt_0.50, e_cpt_0.50)", 25, 0, 50000],
#    ["mvis"         , mvis              , 20, 0, 100]
    ]

ttbar_mupem_fwd = Template("ttbar_mupem_fwd")
ttbar_mupem_fwd.SetSelCut(trigger + selection + jet + mupem_fwdasy)
ttbar_mupem_fwd.AddTree(qq2ttbar_mc2016.MUt, tt_qq_scale/tt_gg_scale)
ttbar_mupem_fwd.AddTree(qq2ttbar_mc2016.MDt, tt_qq_scale/tt_gg_scale)
ttbar_mupem_fwd.AddTrees(gg2ttbar_mc2016.trees())
ttbar_mupem_fwd.AddVars(vars)
ttbar_mupem_fwd.Run()
ttbar_mupem_fwd.SaveToFile()

ttbar_mupem_bwd = Template("ttbar_mupem_bwd")
ttbar_mupem_bwd.SetSelCut(trigger + selection + jet + mupem_bwdasy)
ttbar_mupem_bwd.AddTree(qq2ttbar_mc2016.MUt, tt_qq_scale/tt_gg_scale)
ttbar_mupem_bwd.AddTree(qq2ttbar_mc2016.MDt, tt_qq_scale/tt_gg_scale)
ttbar_mupem_bwd.AddTrees(gg2ttbar_mc2016.trees())
ttbar_mupem_bwd.AddVars(vars)
ttbar_mupem_bwd.Run()
ttbar_mupem_bwd.SaveToFile()

ttbar_mumep_fwd = Template("ttbar_mumep_fwd")
ttbar_mumep_fwd.SetSelCut(trigger + selection + jet + mumep_fwdasy)
ttbar_mumep_fwd.AddTree(qq2ttbar_mc2016.MUt, tt_qq_scale/tt_gg_scale)
ttbar_mumep_fwd.AddTree(qq2ttbar_mc2016.MDt, tt_qq_scale/tt_gg_scale)
ttbar_mumep_fwd.AddTrees(gg2ttbar_mc2016.trees())
ttbar_mumep_fwd.AddVars(vars)
ttbar_mumep_fwd.Run()
ttbar_mumep_fwd.SaveToFile()

ttbar_mumep_bwd = Template("ttbar_mumep_bwd")
ttbar_mumep_bwd.SetSelCut(trigger + selection + jet + mumep_bwdasy)
ttbar_mumep_bwd.AddTree(qq2ttbar_mc2016.MUt, tt_qq_scale/tt_gg_scale)
ttbar_mumep_bwd.AddTree(qq2ttbar_mc2016.MDt, tt_qq_scale/tt_gg_scale)
ttbar_mumep_bwd.AddTrees(gg2ttbar_mc2016.trees())
ttbar_mumep_bwd.AddVars(vars)
ttbar_mumep_bwd.Run()
ttbar_mumep_bwd.SaveToFile()

ttbar_fwd = Template("ttbar_fwd", ttbar_mupem_fwd, ttbar_mumep_fwd)
ttbar_fwd.SaveToFile()
ttbar_bwd = Template("ttbar_bwd", ttbar_mupem_bwd, ttbar_mumep_bwd)
ttbar_bwd.SaveToFile()

ttbar_comb = Template("ttbar_comb", ttbar_fwd, ttbar_bwd)
ttbar_comb.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_comb_mc2016.root")

ttbar = Template("ttbar")
ttbar.SetSelCut(trigger + selection + jet )
ttbar.AddTree(qq2ttbar_mc2016.MUt, tt_qq_scale/tt_gg_scale)
ttbar.AddTree(qq2ttbar_mc2016.MDt, tt_qq_scale/tt_gg_scale)
ttbar.AddTrees(gg2ttbar_mc2016.trees())
ttbar.AddVars(vars)
ttbar.Run()
ttbar.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_mc2016.root")

ttbar_gg_mue = Template("ttbar_gg_mue")
ttbar_gg_mue.SetSelCut(trigger + selection )
ttbar_gg_mue.AddTrees(gg2ttbar_mc2016.trees())
ttbar_gg_mue.AddVars(vars)
ttbar_gg_mue.Run()
ttbar_gg.Scale(tt_gg_scale)
ttbar_gg_mue.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_gg_mue_mc2016.root")

ttbar_qq_mue = Template("ttbar_qq_mue")
ttbar_qq_mue.SetSelCut(triqqer + selection )
ttbar_qq_mue.AddTrees(qq2ttbar_mc2016.trees())
ttbar_qq_mue.AddVars(vars)
ttbar_qq_mue.Run()
ttbar_qq.Scale(tt_qq_scale)
ttbar_qq_mue.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_qq_mue_mc2016.root")

ttbar_mue = Template("ttbar_mue", ttbar_gg_mue, ttbar_qq_mue)
ttbar_mue.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_mue_mc2016.root")

fwd_etaj = ttbar_fwd.GetVar('etaj').GetHist()
bwd_etaj = ttbar_bwd.GetVar('etaj').GetHist()

asymm = fwd_etaj.GetAsymmetry(bwd_etaj)

fwdevts = float(ttbar_fwd.GetEvts())
bwdevts = float(ttbar_bwd.GetEvts())

asy = (fwdevts - bwdevts) / (fwdevts + bwdevts)
asy_err = sqrt(pow(2*bwdevts*sqrt(fwdevts),2) + pow(2*fwdevts*sqrt(bwdevts),2)) / pow(fwdevts + bwdevts,2)

print asy, '+/-', asy_err

# get LO from pythia
ww_py8_mupem = Template("ww_py8_mupem")
ww_py8_mupem.SetSelCut(fid_notag + mupem)
ww_py8_mupem.AddTrees([ww_mc2016.MU.Get("MCGenTrackEff/MCTrackEffTuple"), ww_mc2016.MD.Get("MCGenTrackEff/MCTrackEffTuple")])
ww_py8_mupem.AddVars(mupemvars)
ww_py8_mupem.Scale(ww_scale)
ww_py8_mupem.Run()

ww_py8_mumep = Template("ww_py8_mumep")
ww_py8_mumep.SetSelCut(fid_notag + mumep)
ww_py8_mumep.AddTrees([ww_mc2016.MU.Get("MCGenTrackEff/MCTrackEffTuple"), ww_mc2016.MD.Get("MCGenTrackEff/MCTrackEffTuple")])
ww_py8_mumep.AddVars(mumepvars)
ww_py8_mumep.Scale(ww_scale)
ww_py8_mumep.Run()

ww_py8 = Template("ww_py8", ww_py8_mupem, ww_py8_mumep)
ww_py8.SaveToFile()


#get NLO prediction from mc@NLO
nlo_xsecs = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13teV_amcatnlo_predictions.root")
ww_nlo       = nlo_xsecs.Get("etaj_WW_tot")
ww_nlo_errhi = nlo_xsecs.Get("etaj_WW_toterr_hi")
ww_nlo_errlo = nlo_xsecs.Get("etaj_WW_toterr_lo")


# WW
ww = Template("ww_mc2016")
ww.SetSelCut(trigger + selection + jet)
ww.AddTree(ww_mc2016.trees())
ww.AddVars(vars)
ww.Run()
ww.Scale(ww_scale)
ww.SaveToFile()


#

#get NLO prediction


# WZ

#wz = Template("wz_mc2016")
#wz.SetSelCut(selection + jet + mupem_fwdasy)
#wz.AddTrees(wz_mc2016.trees())
#wz.AddVars(vars)
#wz.Run()
#wz.SaveToFile()

# Wt
wt_xsec = nlo_xsecs.Get("Wt_dr_xsec").GetVal()
ttbar_xsec = nlo_xsecs.Get("etaj_tot").GetVal()
wtOttbar = wt_xsec/ttbar_xsec
