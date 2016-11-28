from top_config import *
from ROOT import *
from Jawa import *
from math import sqrt

selection         = TCut("min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5 && mu_PT > 20000 && e_PT > 20000 && mu_cpt_0.50 < 5000 && e_cpt_0.50 < 5000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
selection_antiiso = TCut("mu_cpt_0.50 > 5000 && e_cpt_0.50 > 5000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
selection_noiso   = TCut("mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04 && min(mu_ETA,e_ETA) > 2.0 && max(mu_ETA,e_ETA) < 4.5 && mu_PT > 20000 && e_PT > 20000")


mupem_fwdasy = TCut("mu_ID == -13 && mu_ETA > e_ETA")
mupem_bwdasy = TCut("mu_ID == -13 && mu_ETA < e_ETA")

mumep_fwdasy = TCut("mu_ID == 13 && mu_ETA < e_ETA")
mumep_bwdasy = TCut("mu_ID == 13 && mu_ETA > e_ETA")

jet = TCut("ttbar_jet_PT > 20000 && ttbar_jet_BDTTag == 1")
jet_notag = TCut("ttbar_jet_PT > 20000")


vars = [
    ["mu_pt"        , "mu_PT/1000.0"           , 10  , 20 , 80 ],
    ["e_pt"         , "e_PT/1000.0"            , 10  , 20 , 80 ],
    ["mu_eta"       , "mu_ETA"     , 10, 2, 4.5], 
    ["e_eta"        , "e_ETA"      , 10, 2, 4.5], 
    ["ptj"          , "ttbar_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "ttbar_jet_ETA"   , 10, 2.2, 4.2 ],
    ["iso"          , "max(mu_cpt_0.50, e_cpt_0.50)/1000.0", 20, 0, 50]
    ]

ttbar_mupem_fwd = Template("ttbar_mupem_fwd")
ttbar_mupem_fwd.SetSelCut(trigger + selection + jet + mupem_fwdasy)
ttbar_mupem_fwd.AddTrees(ttbar_2016.trees())
ttbar_mupem_fwd.AddTrees(ttbar_2015.trees())
ttbar_mupem_fwd.AddVars(vars)
ttbar_mupem_fwd.Run()
ttbar_mupem_fwd.SaveToFile()

ttbar_mupem_bwd = Template("ttbar_mupem_bwd")
ttbar_mupem_bwd.SetSelCut(trigger + selection + jet + mupem_bwdasy)
ttbar_mupem_bwd.AddTrees(ttbar_2016.trees())
ttbar_mupem_bwd.AddTrees(ttbar_2015.trees())
ttbar_mupem_bwd.AddVars(vars)
ttbar_mupem_bwd.Run()
ttbar_mupem_bwd.SaveToFile()

ttbar_mumep_fwd = Template("ttbar_mumep_fwd")
ttbar_mumep_fwd.SetSelCut(trigger + selection + jet + mumep_fwdasy)
ttbar_mumep_fwd.AddTrees(ttbar_2016.trees())
ttbar_mumep_fwd.AddTrees(ttbar_2015.trees())
ttbar_mumep_fwd.AddVars(vars)
ttbar_mumep_fwd.Run()
ttbar_mumep_fwd.SaveToFile()

ttbar_mumep_bwd = Template("ttbar_mumep_bwd")
ttbar_mumep_bwd.SetSelCut(trigger + selection + jet + mumep_bwdasy)
ttbar_mumep_bwd.AddTrees(ttbar_2016.trees())
ttbar_mumep_bwd.AddTrees(ttbar_2015.trees())
ttbar_mumep_bwd.AddVars(vars)
ttbar_mumep_bwd.Run()
ttbar_mumep_bwd.SaveToFile()

ttbar_fwd = Template("ttbar_fwd", ttbar_mupem_fwd, ttbar_mumep_fwd)
ttbar_fwd.SaveToFile()
ttbar_bwd = Template("ttbar_bwd", ttbar_mupem_bwd, ttbar_mumep_bwd)
ttbar_bwd.SaveToFile()

ttbar_comb = Template("ttbar_data13tev_comb", ttbar_fwd, ttbar_bwd)
ttbar_comb.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev_comb.root")

ttbar =  Template("ttbar")
ttbar.SetSelCut(trigger + selection + jet)
ttbar.AddTrees(ttbar_2016.trees())
ttbar.AddTrees(ttbar_2015.trees())
ttbar.AddVars(vars)
ttbar.Run()
ttbar.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev.root")

ttbar_ss = Template("ttbar_ss")
ttbar_ss.SetSelCut(trigger + selection + jet)
ttbar_ss.AddTrees(ttbar_2016.trees_ss())
ttbar_ss.AddTrees(ttbar_2015.trees_ss())
ttbar_ss.AddVars(vars)
ttbar_ss.Run()
ttbar_ss.SaveToFile()

ttbar_antiiso_ss = Template("ttbar_antiiso_ss")
ttbar_antiiso_ss.SetSelCut(trigger + selection_antiiso + jet)
ttbar_antiiso_ss.AddTrees(ttbar_2016.trees_ss())
ttbar_antiiso_ss.AddTrees(ttbar_2015.trees_ss())
ttbar_antiiso_ss.AddVars(vars)
ttbar_antiiso_ss.Run()
ttbar_antiiso_ss.SaveToFile()

ttbar_antiiso = Template("ttbar_antiiso")
ttbar_antiiso.SetSelCut(trigger + selection_antiiso + jet)
ttbar_antiiso.AddTrees(ttbar_2016.trees())
ttbar_antiiso.AddTrees(ttbar_2015.trees())
ttbar_antiiso.AddVars(vars)
ttbar_antiiso.Run()
ttbar_antiiso.SaveToFile()


ttbar_noiso = Template("ttbar_noiso")
ttbar_noiso.SetSelCut(trigger + selection_noiso + jet)
ttbar_noiso.AddTrees(ttbar_2016.trees())
ttbar_noiso.AddTrees(ttbar_2015.trees())
ttbar_noiso.AddVars(vars)
ttbar_noiso.Run()
ttbar_noiso.SaveToFile()


ttbar_noiso_ss = Template("ttbar_noiso_notag_ss")
ttbar_noiso_ss.SetSelCut(trigger + selection_noiso + jet)
ttbar_noiso_ss.AddTrees(ttbar_2016.trees_ss())
ttbar_noiso_ss.AddTrees(ttbar_2015.trees_ss())
ttbar_noiso_ss.AddVars(vars)
ttbar_noiso_ss.Run()
ttbar_noiso_ss.SaveToFile()

ttbar_noiso_notag = Template("ttbar_noiso_notag")
ttbar_noiso_notag.SetSelCut(trigger + selection_noiso + jet_notag)
ttbar_noiso_notag.AddTrees(ttbar_2016.trees())
ttbar_noiso_notag.AddTrees(ttbar_2015.trees())
ttbar_noiso_notag.AddVars(vars)
ttbar_noiso_notag.Run()
ttbar_noiso_notag.SaveToFile()


ttbar_noiso_notag_ss = Template("ttbar_noiso_notag_ss")
ttbar_noiso_notag_ss.SetSelCut(trigger + selection_noiso + jet_notag)
ttbar_noiso_notag_ss.AddTrees(ttbar_2016.trees_ss())
ttbar_noiso_notag_ss.AddTrees(ttbar_2015.trees_ss())
ttbar_noiso_notag_ss.AddVars(vars)
ttbar_noiso_notag_ss.Run()
ttbar_noiso_notag_ss.SaveToFile()


fwd_etaj = ttbar_fwd.GetVar('etaj').GetHist()
bwd_etaj = ttbar_bwd.GetVar('etaj').GetHist()

asymm = fwd_etaj.GetAsymmetry(bwd_etaj)

fwdevts = float(ttbar_fwd.GetEvts())
bwdevts = float(ttbar_bwd.GetEvts())

asy = (fwdevts - bwdevts) / (fwdevts + bwdevts)
asy_err = sqrt(pow(2*bwdevts*sqrt(fwdevts),2) + pow(2*fwdevts*sqrt(bwdevts),2)) / pow(fwdevts + bwdevts,2)

print asy, '+/-', asy_err

