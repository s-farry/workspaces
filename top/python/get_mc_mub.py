from top_config import *
from ROOT import *
from Jawa import *

selection         = mujpt + ip_wb + kin_wb + Ep

vars = [
    ["mu_pt"        , "muminus_PT/1000.0" , 8  , 20 , 100 ],
    ["mu_eta"       , "muminus_ETA"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "muminus_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "muminus_jet_ETA"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["iso"          , "mu_cpt_0.50", 25, 0, 50000]
    ]

ttbar = Template("ttbar_mub_mc2016")
ttbar.SetSelCut(selection)
ttbar.AddTrees(qq2ttbar_muj_mc2016.trees())
ttbar.AddTrees(gg2ttbar_muj_mc2016.trees())
ttbar.AddVars(vars)
ttbar.Run()
ttbar.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_mub_mc2016.root")
