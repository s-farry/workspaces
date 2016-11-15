from top_config import *
from ROOT import *
from Jawa import *

selection         = TCut("mu_cpt_0.50 < 2000 && e_cpt_0.50 < 2000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
selection_antiiso = TCut("mu_cpt_0.50 > 2000 && e_cpt_0.50 > 2000 && mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")
selection_noiso   = TCut("mu_IP_OWNPV < 0.04 && e_IP_OWNPV < 0.04")


mupem_fwdasy = TCut("mu_ID == -13 && mu_ETA > e_ETA")
mupem_bwdasy = TCut("mu_ID == -13 && mu_ETA < e_ETA")

mumep_fwdasy = TCut("mu_ID == 13 && mu_ETA < e_ETA")
mumep_bwdasy = TCut("mu_ID == 13 && mu_ETA > e_ETA")

jet = TCut("ttbar_jet_PT > 20000 && ttbar_jet_BDTTag == 1")

vars = [
    ["mu_pt"        , "mu_PT/1000.0"           , 80  , 0 , 80 ],
    ["e_pt"         , "e_PT/1000.0"            , 80  , 0 , 80 ],
    ["mu_eta"       , "mu_ETA"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "e_ETA"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "ttbar_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "ttbar_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["iso"          , "max(mu_cpt_0.50, e_cpt_0.50)", 25, 0, 50000]
    ]

ttbar_mupem_fwd = Template("ttbar_mupem_fwd")
ttbar_mupem_fwd.SetSelCut(selection + jet + mupem_fwdasy)
ttbar_mupem_fwd.AddTrees(ttbar_2016.trees())
ttbar_mupem_fwd.AddTrees(ttbar_2015.trees())
ttbar_mupem_fwd.AddVars(vars)
ttbar_mupem_fwd.Run()
ttbar_mupem_fwd.SaveToFile()

ttbar_mupem_bwd = Template("ttbar_mupem_bwd")
ttbar_mupem_bwd.SetSelCut(selection + jet + mupem_bwdasy)
ttbar_mupem_bwd.AddTrees(ttbar_2016.trees())
ttbar_mupem_bwd.AddTrees(ttbar_2015.trees())
ttbar_mupem_bwd.AddVars(vars)
ttbar_mupem_bwd.Run()
ttbar_mupem_bwd.SaveToFile()

ttbar_mumep_fwd = Template("ttbar_mumep_fwd")
ttbar_mumep_fwd.SetSelCut(selection + jet + mumep_fwdasy)
ttbar_mumep_fwd.AddTrees(ttbar_2016.trees())
ttbar_mumep_fwd.AddTrees(ttbar_2015.trees())
ttbar_mumep_fwd.AddVars(vars)
ttbar_mumep_fwd.Run()
ttbar_mumep_fwd.SaveToFile()

ttbar_mumep_bwd = Template("ttbar_mumep_bwd")
ttbar_mumep_bwd.SetSelCut(selection + jet + mumep_bwdasy)
ttbar_mumep_bwd.AddTrees(ttbar_2016.trees())
ttbar_mumep_bwd.AddTrees(ttbar_2015.trees())
ttbar_mumep_bwd.AddVars(vars)
ttbar_mumep_bwd.Run()
ttbar_mumep_bwd.SaveToFile()

ttbar_fwd = Template("ttbar_fwd", ttbar_mupem_fwd, ttbar_mumep_fwd)
ttbar_fwd.SaveToFile()
ttbar_bwd = Template("ttbar_bwd", ttbar_mupem_bwd, ttbar_mumep_bwd)
ttbar_bwd.SaveToFile()

ttbar = Template("ttbar_data13tev", ttbar_fwd, ttbar_bwd)
ttbar.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_data13tev.root")

ttbar_ss = Template("ttbar_ss")
ttbar_ss.SetSelCut(selection + jet)
ttbar_ss.AddTrees(ttbar_2016.trees_ss())
ttbar_ss.AddTrees(ttbar_2015.trees_ss())
ttbar_ss.AddVars(vars)
ttbar_ss.Run()
ttbar_ss.SaveToFile()

ttbar_antiiso_ss = Template("ttbar_antiiso_ss")
ttbar_antiiso_ss.SetSelCut(selection_antiiso + jet)
ttbar_antiiso_ss.AddTrees(ttbar_2016.trees_ss())
ttbar_antiiso_ss.AddTrees(ttbar_2015.trees_ss())
ttbar_antiiso_ss.AddVars(vars)
ttbar_antiiso_ss.Run()
ttbar_antiiso_ss.SaveToFile()

ttbar_antiiso = Template("ttbar_antiiso")
ttbar_antiiso.SetSelCut(selection_antiiso + jet)
ttbar_antiiso.AddTrees(ttbar_2016.trees())
ttbar_antiiso.AddTrees(ttbar_2015.trees())
ttbar_antiiso.AddVars(vars)
ttbar_antiiso.Run()
ttbar_antiiso.SaveToFile()


ttbar_noiso_ss = Template("ttbar_noiso_ss")
ttbar_noiso_ss.SetSelCut(selection_noiso + jet)
ttbar_noiso_ss.AddTrees(ttbar_2016.trees_ss())
ttbar_noiso_ss.AddTrees(ttbar_2015.trees_ss())
ttbar_noiso_ss.AddVars(vars)
ttbar_noiso_ss.Run()
ttbar_noiso_ss.SaveToFile()

fwd_etaj = ttbar_fwd.GetVar('etaj').GetHist()
bwd_etaj = ttbar_bwd.GetVar('etaj').GetHist()

asymm = fwd_etaj.GetAsymmetry(bwd_etaj)

fwdevts = float(ttbar_fwd.GetEvts())
bwdevts = float(ttbar_bwd.GetEvts())

asy = (fwdevts - bwdevts) / (fwdevts + bwdevts)
asy_err = sqrt(pow(2*bwdevts*sqrt(fwdevts),2) + pow(2*fwdevts*sqrt(bwdevts),2)) / pow(fwdevts + bwdevts,2)

print asy, '+/-', asy_err

