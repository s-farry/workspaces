from top_config import *
from ROOT import *
from Jawa import *

from Utils import Bunch

fwd_vis_m = "sqrt((sqrt(mu_m^2 + mu_px^2 + mu_py^2 + mu_pz^2) + sqrt(e_m^2 + e_px^2 + e_py^2 + e_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (mu_px + e_px + fwdjet_px)^2 - (mu_py + e_py + fwdjet_py)^2 - (mu_pz + e_pz + fwdjet_pz)^2)"
bwd_vis_m = fwd_vis_m.replace('fwdjet', 'bwdjet')
fwd_muj_m = "sqrt((sqrt(mu_m^2 + mu_px^2 + mu_py^2 + mu_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (mu_px + fwdjet_px)^2 - (mu_py + fwdjet_py)^2 - (mu_pz + fwdjet_pz)^2)"
bwd_muj_m = fwd_muj_m.replace('fwdjet', 'bwdjet')

vars = [
    Bunch(name="mu_pt", var =  "mu_pt", nbins =  8  ,lo =  20 , hi = 100,
          py8var='<mu>_PT/1000.0', xlabel = 'p_{T}(#mu) [GeV]', ylabel = '[A.U.]' ),
    Bunch(name="e_pt"   , var="e_pt"           , nbins = 8  , lo = 20 , hi = 100,
          py8var='<e>_PT/1000.0', label = 'p_{T}(e) [GeV]', ylabel = '[A.U.]'),
    Bunch(name="mu_eta" , var="abs(mu_eta)"    , edges = [2.0, 2.5, 3.0, 3.5, 4.5 ],
          py8var = '<mu>_ETA', xlabel = '#eta(#mu)', ylabel = '[A.U.]'), 
    Bunch(name="e_eta"  , var="abs(e_eta)"     , edges = [2.0, 2.5, 3.0, 3.5, 4.5 ],
          py8var = '<e>_ETA', xlabel = '#eta(e)', ylabel = '[A.U.]'), 
    Bunch(name="ptj"    , var="<jet>_pt"       , nbins = 5, lo = 20, hi = 220,
          py8var = '<jet>_PT/1000.0', xlabel = 'p_{T}(j)', ylabel = '[A.U.]'),
    #Bunch(name="m_vis"  , var="<vis_m>"        , nbins = 100, 0, 50],
    #Bunch(name="m_muj"  , var="<muj_m>"        , nbins = 100, 0, 50],
    Bunch(name="etaj"   , var="abs(<jet>_eta)" , edges = [2.2, 2.7, 3.2, 3.7, 4.2],
          py8var = '<jet>_ETA', xlabel = '#eta(j)', ylabel = '[A.U.]'), 
    ]

lhcbfwd = TCut("mu_eta > 2.0 && mu_eta < 4.5 && e_eta > 2.0 && e_eta < 4.5")
lhcbbwd = TCut("mu_eta < -2.0 && mu_eta > -4.5 && e_eta < -2.0 && e_eta > -4.5")

pt20  = TCut("mu_pt  > 20 && e_pt > 20")

fwdjet_btag = TCut("abs(fwdjet_flav) == 5")
bwdjet_btag = TCut("abs(bwdjet_flav) == 5")

fwdjetpt10 = TCut("fwdjet_pt > 10")
fwdjetpt20 = TCut("fwdjet_pt > 20")

bwdjetpt10 = TCut("bwdjet_pt > 10")
bwdjetpt20 = TCut("bwdjet_pt > 20")

bwdjet20 = pt20 + lhcbbwd + bwdjetpt20 + bwdjet_btag
fwdjet20 = pt20 + lhcbfwd + fwdjetpt20 + fwdjet_btag
bwdjet20_nobtag = pt20 + lhcbbwd + bwdjetpt20
fwdjet20_nobtag = pt20 + lhcbfwd + fwdjetpt20




wtf = TFile("/hepstore/sfarry/powheg_v1/ST_wtch_DR/mue_Wt_powheg_13tev.root")
wtt = wtf.Get("ttbar")
#wt_tot_xsec = 36.625
#wt_acc = wtt.GetEntries(fwdjet20.GetTitle())/float(wtt.GetEntries())
#wt_fid_xsec = wt_acc * wt_tot_xsec * bf

wtdsf = TFile("/hepstore/sfarry/powheg_v1/ST_wtch_DS/mue_Wt_powheg_ds_13tev.root")
wtdst = wtdsf.Get("ttbar")
#wtds_tot_xsec = 34.8215
#wtds_acc = wtdst.GetEntries(fwdjet20.GetTitle())/float(wtdst.GetEntries())
#wtds_fid_xsec = wtds_acc * wtds_tot_xsec * bf

wt_fwd = Template("wt_fwd", wtt, fwdjet20)
for v in vars: 
    if hasattr(v, 'edges'):
        wt_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.edges])
    else:
        wt_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
wt_fwd.ApplyCut()
wt_fwd.Run()
wt_fwd.SaveToFile()

wt_bwd = Template("wt_bwd", wtt, bwdjet20)
for v in vars: 
    if hasattr(v, 'edges'):
        wt_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.edges])
    else:
        wt_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
wt_bwd.ApplyCut()
wt_bwd.Run()
wt_bwd.SaveToFile()


wt = Template("wt", wt_fwd, wt_bwd)
wt.SaveToFile()

tt_qq_evts = qq2ttbar_mc2016.MU.Get('TotEvts').GetVal() + qq2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_qq_xsec = 9.966e-8*1e9
tt_qq_acc  = 10000.0/106462.0
tt_qq_scale = tt_qq_xsec * tt_qq_acc /tt_qq_evts

tt_gg_evts = gg2ttbar_mc2016.MU.Get('TotEvts').GetVal() + gg2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_gg_xsec = 5.826e-7*1e9
tt_gg_acc  = 10000.0/156045.0
tt_gg_scale = tt_gg_xsec * tt_gg_acc /tt_gg_evts

ttf   = TFile.Open("/hepstore/sfarry/aMC@NLO/ttbar/Events/ttbar.root")
t     = ttf.Get("ttbar")

ttbar_fwd = Template("ttbar_fwd", t, fwdjet20)
for v in vars: 
    if hasattr(v, 'edges'):
        ttbar_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.edges])
    else:
        ttbar_fwd.AddVar([v.name, v.var.replace('<jet>', 'fwdjet'), v.nbins, v.lo, v.hi])
ttbar_fwd.ApplyCut()
ttbar_fwd.Run()
ttbar_fwd.SaveToFile()

ttbar_bwd = Template("ttbar_bwd", t, bwdjet20)
for v in vars: 
    if hasattr(v, 'edges'):
        ttbar_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.edges])
    else:
        ttbar_bwd.AddVar([v.name, v.var.replace('<jet>', 'bwdjet'), v.nbins, v.lo, v.hi])
ttbar_bwd.ApplyCut()
ttbar_bwd.Run()
ttbar_bwd.SaveToFile()

ttbar = Template("ttbar", ttbar_fwd, ttbar_bwd)
ttbar.SaveToFile()


fid = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000 && ttbar_jet_PT > 20000 && abs(ttbar_jet_flavour) == 5")
mupem = TCut("lp_ID == -13 && lm_ID == 11" )
mumep = TCut("lp_ID == -11  && lm_ID == 13")


ttbar_py8_mupem = Template("ttbar_py8_mupem")
ttbar_py8_mupem.SetSelCut( fid + mupem )
ttbar_py8_mupem.AddTrees(qq2ttbar_mc2016.true_trees())
ttbar_py8_mupem.AddTrees(gg2ttbar_mc2016.true_trees())
for v in vars: 
    var = v.py8var.replace('<jet>', 'ttbar_jet')
    var = var.replace('<mu>','lm')
    var = var.replace('<e>', 'lp')
    if hasattr(v, 'edges'):
        ttbar_py8_mupem.AddVar([v.name, var, v.edges])
    else:
        ttbar_py8_mupem.AddVar([v.name, var, v.nbins, v.lo, v.hi])
ttbar_py8_mupem.Run()
ttbar_py8_mupem.SaveToFile()

ttbar_py8_mumep = Template("ttbar_py8_mumep")
ttbar_py8_mumep.SetSelCut( fid + mumep )
ttbar_py8_mumep.AddTrees(qq2ttbar_mc2016.true_trees())
ttbar_py8_mumep.AddTrees(gg2ttbar_mc2016.true_trees())
for v in vars: 
    var = v.py8var.replace('<jet>', 'ttbar_jet')
    var = var.replace('<mu>','lm')
    var = var.replace('<e>', 'lp')
    if hasattr(v, 'edges'):
        ttbar_py8_mumep.AddVar([v.name, var, v.edges])
    else:
        ttbar_py8_mumep.AddVar([v.name, var, v.nbins, v.lo, v.hi])
ttbar_py8_mumep.Run()
ttbar_py8_mumep.SaveToFile()

ttbar_py8 = Template('ttbar_py8', ttbar_py8_mumep, ttbar_py8_mupem)
ttbar_py8.SaveToFile()

from Style import *
SetLHCbStyle()

for b in vars:
    p = Plot([wt.GetVar(b.name).GetHist(), ttbar.GetVar(b.name).GetHist(), ttbar_py8.GetVar(b.name).GetHist()])
    for plot in p.plots: plot.UseCurrentStyle()
    p.setProp('labels', ['Wt (Powheg)', 't#bar{t} (aMC@NLO)', 'ttbar (Pythia 8)'])
    p.setProp('colors', ['red', 'blue', 'green'])
    p.setProp('location', '/user2/sfarry/workspaces/top/figures')
    p.setProp('filename', 'wt_top_'+b.name+'.pdf')
    p.setProp('normalised', True)
    p.setProp('ylabel', '[A.U.]')
    p.setProp('leglims', [0.6, 0.7, 0.9, 0.9])
    p.setProp('markerstyles', 20)
    if hasattr(b, 'xlabel'): p.setProp('xlabel', b.xlabel)
    if hasattr(b, 'ylabel'): p.setProp('ylabel', b.ylabel)
    if hasattr(b, 'shiftlegx'): p.ShiftLegX(b.shiftlegx)
    if hasattr(b, 'shiftlegy'): p.ShiftLegX(b.shiftlegy)
    p.drawROOT()


f = TFile("top_weights.root", "RECREATE")

for b in vars:
    wth = wt.GetVar(b.name).GetHist()
    tth = ttbar.GetVar(b.name).GetHist()
    tth_py8 = ttbar_py8.GetVar(b.name).GetHist()

    wth.Scale(1/wth.Integral())
    tth.Scale(1/tth.Integral())
    tth_py8.Scale(1/tth_py8.Integral())
    
    sf_wt = tth_py8.Clone('sf_wt_'+b.name )
    sf_wt.Divide(wth)

    sf_tt = tth_py8.Clone('sf_tt_'+b.name )
    sf_tt.Divide(tth)

    sf_wt.Write()
    sf_tt.Write()

f.Close()
    
