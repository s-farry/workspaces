from top_config import *

from Jawa import Template

zmumu_selection = TCut('boson_M > 60000 && boson_M < 120000 && muplus_PT > 20000 && muminus_PT > 20000 && min(muplus_ETA, muminus_ETA) > 2.0 && max(muplus_ETA, muminus_ETA) < 4.5')



zvars = [
    ["m"            , "boson_M/1000.0",            [60, 70, 80, 85, 87, 89, 91, 93, 98, 105, 120, 150]],
    ["mup_pt"       , "muplus_PT/1000.0"           , 10  , 20 , 100 ],
    ["mum_pt"       , "muminus_PT/1000.0"            , 10  , 20 , 100 ],
    ["mup_eta"      , "muplus_ETA"     , 10, 2, 4.5], 
    ["mum_eta"      , "muminus_ETA"      , 10, 2, 4.5], 
    #['dphi'         , dPhi.replace('<A>', 'muplus').replace('<B>', 'muminus'), 10, 0, TMath.Pi()],
    ["ptj"          , "boson_jet_PT/1000"       , 15, 20, 170],
    ["etaj"         , "boson_jet_ETA"   , 10, 2.2, 4.2 ]
    ]

fwd = TCut("muplus_ETA < muminus_ETA")
bwd = TCut("muplus_ETA > muminus_ETA")

zmumu_fwd_data = Template("zmumu_fwd_data")
zmumu_fwd_data.SetSelCut(ztrigger + zmumu_selection + fwd)
zmumu_fwd_data.AddTrees(zmumuj_2016.trees())
zmumu_fwd_data.AddTrees(zmumuj_2015.trees())
zmumu_fwd_data.AddVars(zvars)
zmumu_fwd_data.Run()

zmumu_bwd_data = Template("zmumu_bwd_data")
zmumu_bwd_data.SetSelCut(ztrigger + zmumu_selection + bwd)
zmumu_bwd_data.AddTrees(zmumuj_2016.trees())
zmumu_bwd_data.AddTrees(zmumuj_2015.trees())
zmumu_bwd_data.AddVars(zvars)
zmumu_bwd_data.Run()

zmumu_fwd_mc2016_t = Template("zmumu_fwd_mc2016")
zmumu_fwd_mc2016_t.SetSelCut(zmumu_selection + fwd)
zmumu_fwd_mc2016_t.AddTrees(zmumu_mc2016.trees())
zmumu_fwd_mc2016_t.AddVars(zvars)
zmumu_fwd_mc2016_t.Run()

zmumu_bwd_mc2016_t = Template("zmumu_bwd_mc2016")
zmumu_bwd_mc2016_t.SetSelCut(zmumu_selection + bwd)
zmumu_bwd_mc2016_t.AddTrees(zmumu_mc2016.trees())
zmumu_bwd_mc2016_t.AddVars(zvars)
zmumu_bwd_mc2016_t.Run()

from PlotTools import *
from Style import *
SetLHCbStyle()

for v in zvars:
    data_asymm = zmumu_fwd_data.GetVar(v[0]).GetHist().GetAsymmetry(zmumu_bwd_data.GetVar(v[0]).GetHist())
    mc_asymm   = zmumu_fwd_mc2016_t.GetVar(v[0]).GetHist().GetAsymmetry(zmumu_bwd_mc2016_t.GetVar(v[0]).GetHist())
    a = Plot([data_asymm, mc_asymm, data_asymm])
    a.forceStyle()
    a.setProp('location', '/user2/sfarry/workspaces/top/figures')
    a.setProp('filename', 'zmumu_afb_'+v[0]+'.pdf')
    a.setProp('colors', ['black', 'blue', 'black'])
    a.setProp('labels', ['Run-II data', 'MC2016'])
    a.setProp('markerstyles', [20,0, 20])
    a.setProp('drawOpts', ['e1', 'h', 'e1'])
    a.setProp('fillstyles', [0, 0, 0])
    a.setProp('leglims', [0.2, 0.3, 0.6, 0.5])
    a.setProp('xlabel', 'M_{#mu#mu} [GeV]')
    a.ShiftLegY(0.3)
    a.ShiftLegX(-0.03)
    a.setProp('normalised', True)
    a.setProp('ylabel', 'Asymmetry')
    a.setProp('ylims', [-0.5, 0.5])
    a.drawROOT()

