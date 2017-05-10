from top_config import *
from ROOT import *
from Jawa import *

from Utils import Bunch

fwd_vis_m = "sqrt((sqrt(mu_m^2 + mu_px^2 + mu_py^2 + mu_pz^2) + sqrt(e_m^2 + e_px^2 + e_py^2 + e_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (mu_px + e_px + fwdjet_px)^2 - (mu_py + e_py + fwdjet_py)^2 - (mu_pz + e_pz + fwdjet_pz)^2)"
bwd_vis_m = fwd_vis_m.replace('fwdjet', 'bwdjet')
fwd_muj_m = "sqrt((sqrt(mu_m^2 + mu_px^2 + mu_py^2 + mu_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (mu_px + fwdjet_px)^2 - (mu_py + fwdjet_py)^2 - (mu_pz + fwdjet_pz)^2)"
bwd_muj_m = fwd_muj_m.replace('fwdjet', 'bwdjet')


'''
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
'''
#seems more sensible to split them into +ve and -ve leptons

vars = [
    Bunch(name="lp_pt", var =  "<lp>_pt", nbins =  50  ,lo =  20 , hi = 100, ylims = [0, 0.01],
          py8var='lp_PT/1000.0', xlabel = 'p_{T}(l^{+}) [GeV]', ylabel = '#sigma [pb]', ynormlims = [0, 0.25] ),
    Bunch(name="lm_pt"   , var="<lm>_pt"           , nbins = 50  , lo = 20 , hi = 100, ylims = [0, 0.01],
          py8var='lm_PT/1000.0', label = 'p_{T}(l^{-}) [GeV]', ylabel = '#sigma [pb]', ynormlims = [0, 0.25]),
    Bunch(name="lp_eta" , var="abs(<lp>_eta)"    , nbins = 50, lo = 2.0, hi = 4.5, ylims = [0, 0.02],
          py8var = 'lp_ETA', xlabel = '#eta(l^{+})', ylabel = '#sigma [pb]', ynormlims = [0, 0.52]), 
    Bunch(name="lm_eta"  , var="abs(<lm>_eta)"     , nbins = 50, lo = 2.0, hi = 4.5, ylims = [0, 0.02],
          py8var = 'lm_ETA', xlabel = '#eta(l^{-})', ylabel = '#sigma [pb]', ynormlims = [0, 0.58]), 
    Bunch(name="ptj"    , var="<jet>_pt"       , nbins = 50, lo = 20, hi = 220, ylims = [0, 0.02],
          py8var = '<jet>_PT/1000.0', xlabel = 'p_{T}(j)', ylabel = '#sigma [pb]', ynormlims = [0, 0.52]),
    Bunch(name="etaj"   , var="abs(<jet>_eta)" , nbins = 50, lo = 2.2, hi = 4.2, ylims = [0, 0.02],
          py8var = '<jet>_ETA', xlabel = '#eta(j)', ylabel = '#sigma [pb]', ynormlims = [0, 0.62]), 
    Bunch(name="lp_pt10" , var = "<lp>_pt", nbins = 10 , lo = 20 , hi = 100, py8var='lp_PT/1000.0'),
    Bunch(name="lm_pt10" , var = "<lm>_pt", nbins = 10 , lo = 20 , hi = 100, py8var='lm_PT/1000.0'),
    Bunch(name="lp_eta10", var="abs(<lp>_eta)" , nbins = 10, lo = 2.0, hi = 4.5,py8var = 'lp_ETA'),
    Bunch(name="lm_eta10", var="abs(<lm>_eta)" , nbins = 10, lo = 2.0, hi = 4.5,py8var = 'lm_ETA'),
    Bunch(name="ptj10"    , var="<jet>_pt"       , nbins = 10, lo = 20, hi = 220, py8var = '<jet>_PT/1000.0'),
    Bunch(name="etaj10"   , var="abs(<jet>_eta)" , nbins = 10, lo = 2.2, hi = 4.2, py8var = '<jet>_ETA')
    ]
vars2d = [
    Bunch(var1="lp_pt", var2 =  "lp_eta"),
    Bunch(var1="lm_pt", var2 =  "lm_eta"),
    Bunch(var1="ptj", var2 =  "etaj"),
    Bunch(var1="lp_pt10", var2 =  "lp_eta10"),
    Bunch(var1="lm_pt10", var2 =  "lm_eta10"),
    Bunch(var1="ptj10", var2 =  "etaj10"),
    Bunch(var1="lp_pt10", var2 = "ptj10"),
    Bunch(var1="lm_pt10", var2 = "ptj10")
    ]

lhcbfwd = TCut("mu_eta > 2.0 && mu_eta < 4.5 && e_eta > 2.0 && e_eta < 4.5")
lhcbbwd = TCut("mu_eta < -2.0 && mu_eta > -4.5 && e_eta < -2.0 && e_eta > -4.5")

lhcbfwd_powheg = TCut("mup_eta > 2.0 && mup_eta < 4.5 && mum_eta > 2.0 && mum_eta < 4.5")
lhcbbwd_powheg = TCut("mup_eta < -2.0 && mup_eta > -4.5 && mum_eta < -2.0 && mum_eta > -4.5")

pt20  = TCut("mu_pt  > 20 && e_pt > 20")
pt20_powheg = TCut("mup_pt > 20 && mum_pt > 20")

fwdjet_btag = TCut("abs(fwdjet_flav) == 5")
bwdjet_btag = TCut("abs(bwdjet_flav) == 5")

fwdjetpt10 = TCut("fwdjet_pt > 10")
fwdjetpt20 = TCut("fwdjet_pt > 20")

bwdjetpt10 = TCut("bwdjet_pt > 10")
bwdjetpt20 = TCut("bwdjet_pt > 20")

bwdjet20 = pt20 + lhcbbwd + bwdjetpt20 + bwdjet_btag
fwdjet20 = pt20 + lhcbfwd + fwdjetpt20 + fwdjet_btag

fwdjet20_powheg = pt20_powheg + lhcbfwd_powheg + fwdjetpt20 + fwdjet_btag
bwdjet20_powheg = pt20_powheg + lhcbbwd_powheg + bwdjetpt20 + bwdjet_btag

bwdjet20_nobtag = pt20 + lhcbbwd + bwdjetpt20
fwdjet20_nobtag = pt20 + lhcbfwd + fwdjetpt20



mupem = TCut("mu_id == -13 && e_id == 11")
mumep = TCut("e_id == -11 && mu_id == 13")

wtf = TFile("/hepstore/sfarry/powheg_v1/ST_wtch_DR/mue_Wt_powheg_13tev.root")
wtt = wtf.Get("ttbar")
wt_tot_xsec = 36.625
#wt_acc = wtt.GetEntries(fwdjet20.GetTitle())/float(wtt.GetEntries())
#wt_fid_xsec = wt_acc * wt_tot_xsec * bf

wtdsf = TFile("/hepstore/sfarry/powheg_v1/ST_wtch_DS/mue_Wt_powheg_ds_13tev.root")
wtdst = wtdsf.Get("ttbar")
wtds_tot_xsec = 34.8215
#wtds_acc = wtdst.GetEntries(fwdjet20.GetTitle())/float(wtdst.GetEntries())
#wtds_fid_xsec = wtds_acc * wtds_tot_xsec * bf

bf_wt = pow(2*0.1080,2)
wt_mupem_fwd = Template("wt_powheg_mupem_fwd", wtt, fwdjet20 + mupem)
for v in vars: 
    var = v.var.replace('<jet>', 'fwdjet')
    var = var.replace('<lp>','mu')
    var = var.replace('<lm>','e')
    if hasattr(v, 'edges'):
        wt_mupem_fwd.AddVar([v.name, var, v.edges])
    else:
        wt_mupem_fwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    wt_mupem_fwd.Add2DVar(v.var1, v.var2)
wt_mupem_fwd.ApplyCut()
wt_mupem_fwd.Run()
wt_mupem_fwd.Scale(wt_tot_xsec * bf_wt / wtt.GetEntries())

wt_mupem_bwd = Template("wt_powheg_mupem_bwd", wtt, bwdjet20 + mupem)
for v in vars: 
    var = v.var.replace('<jet>', 'bwdjet')
    var = var.replace('<lp>','mu')
    var = var.replace('<lm>','e')
    if hasattr(v, 'edges'):
        wt_mupem_bwd.AddVar([v.name, var, v.edges])
    else:
        wt_mupem_bwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    wt_mupem_bwd.Add2DVar(v.var1, v.var2)
wt_mupem_bwd.ApplyCut()
wt_mupem_bwd.Run()
wt_mupem_bwd.Scale(wt_tot_xsec * bf_wt / wtt.GetEntries())


wt_mupem = Template("wt_powheg_mupem", wt_mupem_fwd, wt_mupem_bwd)

wt_mumep_fwd = Template("wt_powheg_mumep_fwd", wtt, fwdjet20 + mumep)
for v in vars: 
    var = v.var.replace('<jet>', 'fwdjet')
    var = var.replace('<lp>','e')
    var = var.replace('<lm>','mu')
    if hasattr(v, 'edges'):
        wt_mumep_fwd.AddVar([v.name, var, v.edges])
    else:
        wt_mumep_fwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    wt_mumep_fwd.Add2DVar(v.var1, v.var2)
wt_mumep_fwd.ApplyCut()
wt_mumep_fwd.Run()
wt_mumep_fwd.Scale(wt_tot_xsec * bf_wt / wtt.GetEntries())

wt_mumep_bwd = Template("wt_powheg_mumep_bwd", wtt, bwdjet20 + mumep)
for v in vars: 
    var = v.var.replace('<jet>', 'bwdjet')
    var = var.replace('<lp>','e')
    var = var.replace('<lm>','mu')
    if hasattr(v, 'edges'):
        wt_mumep_bwd.AddVar([v.name, var, v.edges])
    else:
        wt_mumep_bwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    wt_mumep_bwd.Add2DVar(v.var1, v.var2)
wt_mumep_bwd.ApplyCut()
wt_mumep_bwd.Run()
wt_mumep_bwd.Scale(wt_tot_xsec * bf_wt / wtt.GetEntries())


wt_mumep = Template("wt_powheg_mumep", wt_mumep_fwd, wt_mumep_bwd)

wt = Template("wt_powheg", wt_mupem, wt_mumep)
wt.SaveToFile("/user2/sfarry/workspaces/top/tuples/wt_powheg.root")

amcatnlo_f = TFile.Open("/hepstore/sfarry/aMCatNLO/ttbar/Events/ttbar.root")
amcatnlo_t = amcatnlo_f.Get("ttbar")
bf_ww = pow(2*0.1080,2)
amcatnlo_scale = 0.5*bf_ww/amcatnlo_t.GetEntries()

#powheg_f   = TFile.Open("/user2/sfarry/external/powheg/POWHEG-BOX-V2/hvq/run_1/muej_powheg_13tev.root")
powheg_f   = TFile.Open("/hepstore/sfarry/Powheg/ttbar/muej_powheg_13tev.root")
powheg_t   = powheg_f.Get("ttbar")
powheg_scale = 0.5*2/powheg_t.GetEntries()

ttbar_powheg_fwd = Template("ttbar_powheg_fwd", powheg_t, fwdjet20_powheg)
for v in vars: 
    var = v.var.replace('<jet>', 'fwdjet')
    var = var.replace('<lp>','mup')
    var = var.replace('<lm>','mum')
    if hasattr(v, 'edges'):
        ttbar_powheg_fwd.AddVar([v.name, var, v.edges])
    else:
        ttbar_powheg_fwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    ttbar_powheg_fwd.Add2DVar(v.var1, v.var2)
ttbar_powheg_fwd.Reweight("w0")
ttbar_powheg_fwd.ApplyCut()
ttbar_powheg_fwd.Run()
ttbar_powheg_fwd.Scale(powheg_scale)

ttbar_powheg_bwd = Template("ttbar_powheg_bwd", powheg_t, bwdjet20_powheg)
for v in vars: 
    var = v.var.replace('<jet>', 'bwdjet')
    var = var.replace('<lp>','mup')
    var = var.replace('<lm>','mum')
    if hasattr(v, 'edges'):
        ttbar_powheg_bwd.AddVar([v.name, var, v.edges])
    else:
        ttbar_powheg_bwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    ttbar_powheg_bwd.Add2DVar(v.var1, v.var2)
ttbar_powheg_bwd.Reweight("w0")
ttbar_powheg_bwd.ApplyCut()
ttbar_powheg_bwd.Run()
ttbar_powheg_bwd.Scale(powheg_scale)

ttbar_powheg = Template("ttbar_powheg_mupem", ttbar_powheg_fwd, ttbar_powheg_bwd)
ttbar_powheg.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_powheg.root")

ttbar_amcatnlo_mupem_fwd = Template("ttbar_amcatnlo_mupem_fwd", amcatnlo_t, fwdjet20 + mupem)
for v in vars: 
    var = v.var.replace('<jet>', 'fwdjet')
    var = var.replace('<lp>','mu')
    var = var.replace('<lm>','e')
    if hasattr(v, 'edges'):
        ttbar_amcatnlo_mupem_fwd.AddVar([v.name, var, v.edges])
    else:
        ttbar_amcatnlo_mupem_fwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    ttbar_amcatnlo_mupem_fwd.Add2DVar(v.var1, v.var2)
ttbar_amcatnlo_mupem_fwd.Reweight("w1010")
ttbar_amcatnlo_mupem_fwd.ApplyCut()
ttbar_amcatnlo_mupem_fwd.Run()
ttbar_amcatnlo_mupem_fwd.Scale(amcatnlo_scale)

ttbar_amcatnlo_mupem_bwd = Template("ttbar_amcatnlo_mupem_bwd", amcatnlo_t, bwdjet20 + mupem)
for v in vars: 
    var = v.var.replace('<jet>', 'bwdjet')
    var = var.replace('<lp>','mu')
    var = var.replace('<lm>','e')
    if hasattr(v, 'edges'):
        ttbar_amcatnlo_mupem_bwd.AddVar([v.name, var, v.edges])
    else:
        ttbar_amcatnlo_mupem_bwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    ttbar_amcatnlo_mupem_bwd.Add2DVar(v.var1, v.var2)
ttbar_amcatnlo_mupem_bwd.Reweight("w1010")
ttbar_amcatnlo_mupem_bwd.ApplyCut()
ttbar_amcatnlo_mupem_bwd.Run()
ttbar_amcatnlo_mupem_bwd.Scale(amcatnlo_scale)


ttbar_amcatnlo_mupem = Template("ttbar_amcatnlo_mupem", ttbar_amcatnlo_mupem_fwd, ttbar_amcatnlo_mupem_bwd)

ttbar_amcatnlo_mumep_fwd = Template("ttbar_amcatnlo_mumep_fwd", amcatnlo_t, fwdjet20 + mumep)
for v in vars: 
    var = v.var.replace('<jet>', 'fwdjet')
    var = var.replace('<lp>','e')
    var = var.replace('<lm>','mu')
    if hasattr(v, 'edges'):
        ttbar_amcatnlo_mumep_fwd.AddVar([v.name, var, v.edges])
    else:
        ttbar_amcatnlo_mumep_fwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    ttbar_amcatnlo_mumep_fwd.Add2DVar(v.var1, v.var2)
ttbar_amcatnlo_mumep_fwd.Reweight("w1010")
ttbar_amcatnlo_mumep_fwd.ApplyCut()
ttbar_amcatnlo_mumep_fwd.Run()
ttbar_amcatnlo_mumep_fwd.Scale(amcatnlo_scale)

ttbar_amcatnlo_mumep_bwd = Template("ttbar_amcatnlo_mumep_bwd", amcatnlo_t, bwdjet20 + mumep)
for v in vars: 
    var = v.var.replace('<jet>', 'bwdjet')
    var = var.replace('<lp>','e')
    var = var.replace('<lm>','mu')
    if hasattr(v, 'edges'):
        ttbar_amcatnlo_mumep_bwd.AddVar([v.name, var, v.edges])
    else:
        ttbar_amcatnlo_mumep_bwd.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    ttbar_amcatnlo_mumep_bwd.Add2DVar(v.var1, v.var2)
ttbar_amcatnlo_mumep_bwd.Reweight("w1010")
ttbar_amcatnlo_mumep_bwd.ApplyCut()
ttbar_amcatnlo_mumep_bwd.Run()
ttbar_amcatnlo_mumep_bwd.Scale(amcatnlo_scale)


ttbar_amcatnlo_mumep = Template("ttbar_amcatnlo_mumep", ttbar_amcatnlo_mumep_fwd, ttbar_amcatnlo_mumep_bwd)

ttbar_amcatnlo = Template("ttbar_amcatnlo", ttbar_amcatnlo_mupem, ttbar_amcatnlo_mumep)
ttbar_amcatnlo.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_amcatnlo.root")

tt_qq_evts = qq2ttbar_mc2016.MU.Get('TotEvts').GetVal() + qq2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_qq_xsec = 9.966e-8*1e9
tt_qq_acc  = 10000.0/106462.0
tt_qq_scale = tt_qq_xsec * tt_qq_acc /tt_qq_evts

tt_gg_evts = gg2ttbar_mc2016.MU.Get('TotEvts').GetVal() + gg2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_gg_xsec = 5.826e-7*1e9
tt_gg_acc  = 10000.0/156045.0
tt_gg_scale = tt_gg_xsec * tt_gg_acc /tt_gg_evts


fid = TCut("lp_ETA > 2 && lp_ETA < 4.5 && lm_ETA > 2 && lm_ETA < 4.5 && lp_PT > 20000 && lm_PT > 20000 && ttbar_jet_PT > 20000 && abs(ttbar_jet_flavour) == 5")
mupem = TCut("lp_ID == -13 && lm_ID == 11" )
mumep = TCut("lp_ID == -11  && lm_ID == 13")


ttbar_py8_mupem = Template("ttbar_py8_mupem")
ttbar_py8_mupem.SetSelCut( fid + mupem )
ttbar_py8_mupem.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
ttbar_py8_mupem.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
for v in vars: 
    var = v.py8var.replace('<jet>', 'ttbar_jet')
    var = var.replace('<mu>','lm')
    var = var.replace('<e>', 'lp')
    if hasattr(v, 'edges'):
        ttbar_py8_mupem.AddVar([v.name, var, v.edges])
    else:
        ttbar_py8_mupem.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    ttbar_py8_mupem.Add2DVar(v.var1, v.var2)
ttbar_py8_mupem.Run()

ttbar_py8_mumep = Template("ttbar_py8_mumep")
ttbar_py8_mumep.SetSelCut( fid + mumep )
ttbar_py8_mumep.AddTrees(qq2ttbar_mc2016.true_trees(), tt_qq_scale)
ttbar_py8_mumep.AddTrees(gg2ttbar_mc2016.true_trees(), tt_gg_scale)
for v in vars: 
    var = v.py8var.replace('<jet>', 'ttbar_jet')
    var = var.replace('<mu>','lm')
    var = var.replace('<e>', 'lp')
    if hasattr(v, 'edges'):
        ttbar_py8_mumep.AddVar([v.name, var, v.edges])
    else:
        ttbar_py8_mumep.AddVar([v.name, var, v.nbins, v.lo, v.hi])
for v in vars2d:
    ttbar_py8_mumep.Add2DVar(v.var1, v.var2)
ttbar_py8_mumep.Run()

ttbar_py8 = Template('ttbar_py8', ttbar_py8_mumep, ttbar_py8_mupem)
ttbar_py8.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_py8.root")

from PlotTools import *
from Style import *
SetLHCbStyle()

for b in vars:
    p = Plot([ttbar_amcatnlo.GetVar(b.name).GetHist(), ttbar_powheg.GetVar(b.name).GetHist(), ttbar_py8.GetVar(b.name).GetHist()])
    p.AutoYlims()
    for plot in p.plots: plot.UseCurrentStyle()
    p.setProp('labels', ['t#bar{t} (aMC@NLO)', 't#bar{t} (Powheg)', 't#bar{t} (Pythia 8)'])
    p.setProp('colors', ['red', 'blue', 'black', 'green'])
    p.setProp('location', '/user2/sfarry/workspaces/top/figures')
    p.setProp('filename', 'top_gencomp_'+b.name+'.pdf')
    p.setProp('normalised', False)
    p.setProp('ylabel', '[A.U.]')
    p.setProp('leglims', [0.6, 0.6, 0.9, 0.9])
    p.setProp('markerstyles', 20)
    p.setProp('drawOpts', 'hist')
    p.setProp('fillstyles', 0)
    if hasattr(b, 'xlabel'): p.setProp('xlabel', b.xlabel)
    if hasattr(b, 'ylabel'): p.setProp('ylabel', b.ylabel)
    if hasattr(b, 'shiftlegx'): p.ShiftLegX(b.shiftlegx)
    if hasattr(b, 'shiftlegy'): p.ShiftLegX(b.shiftlegy)
    p.drawROOT()

    #p = Plot([wt.GetVar(b.name).GetHist(), ttbar_amcatnlo.GetVar(b.name).GetHist(), ttbar_powheg.GetVar(b.name).GetHist(), ttbar_py8.GetVar(b.name).GetHist()])

    p = Plot([ttbar_amcatnlo.GetVar(b.name).GetHist(), ttbar_powheg.GetVar(b.name).GetHist(), ttbar_py8.GetVar(b.name).GetHist()])
    for plot in p.plots: plot.UseCurrentStyle()
    p.AutoYlims()
    p.setProp('labels', ['t#bar{t} (aMC@NLO)', 't#bar{t} (Powheg)', 't#bar{t} (Pythia 8)'])
    p.setProp('colors', ['red', 'blue', 'black', 'green'])
    p.setProp('location', '/user2/sfarry/workspaces/top/figures')
    p.setProp('filename', 'top_gencomp_norm_'+b.name+'.pdf')
    p.setProp('normalised', True)
    p.setProp('ylabel', '[A.U.]')
    p.setProp('leglims', [0.6, 0.6, 0.9, 0.9])
    p.setProp('markerstyles', 20)
    p.setProp('drawOpts', 'hist')
    p.setProp('fillstyles', 0)
    if hasattr(b, 'xlabel'): p.setProp('xlabel', b.xlabel)
    if hasattr(b, 'ylabel'): p.setProp('ylabel', b.ylabel)
    if hasattr(b, 'shiftlegx'): p.ShiftLegX(b.shiftlegx)
    if hasattr(b, 'shiftlegy'): p.ShiftLegX(b.shiftlegy)
    p.drawROOT()


f = TFile("/user2/sfarry/workspaces/top/tuples/top_weights.root", "RECREATE")

for b in vars:
    wth_powheg   = wt.GetVar(b.name).GetHist()
    tth_powheg   = ttbar_powheg.GetVar(b.name).GetHist()
    tth_amcatnlo = ttbar_powheg.GetVar(b.name).GetHist()
    tth_py8      = ttbar_py8.GetVar(b.name).GetHist()

    '''
    wth_powheg.Scale(1/wth_powheg.Integral())
    tth_powheg.Scale(1/tth_powheg.Integral())
    tth_amcatnlo.Scale(1/tth_amcatnlo.Integral())
    tth_py8.Scale(1/tth_py8.Integral())
    
    sf_wt_powheg = tth_py8.Clone('sf_wt_powheg_'+b.name )
    sf_wt_powheg.Divide(wth_powheg)

    sf_tt_powheg = tth_py8.Clone('sf_tt_powheg_'+b.name )
    sf_tt_powheg.Divide(tth_powheg)

    sf_tt_amcatnlo = tth_py8.Clone('sf_tt_amcatnlo_'+b.name )
    sf_tt_amcatnlo.Divide(tth_amcatnlo)
    '''

    sf_wt_powheg   = GetWeightHist('sf_wt_powheg_'+b.name, wth_powheg, tth_py8)
    sf_tt_powheg   = GetWeightHist('sf_tt_powheg_'+b.name, tth_powheg, tth_py8)
    sf_tt_amcatnlo = GetWeightHist('sf_tt_amcatnlo_'+b.name, tth_amcatnlo, tth_py8)

    sf_wt_powheg.Write()
    sf_tt_powheg.Write()
    sf_tt_amcatnlo.Write()

for b in vars2d:
    wth_powheg   = wt.Get2DVar(b.var1,b.var2).GetHist()
    tth_powheg   = ttbar_powheg.Get2DVar(b.var1,b.var2).GetHist()
    tth_amcatnlo = ttbar_amcatnlo.Get2DVar(b.var1,b.var2).GetHist()
    tth_py8      = ttbar_py8.Get2DVar(b.var1,b.var2).GetHist()

    '''
    wth_powheg.Scale(1/wth_powheg.Integral())
    tth_powheg.Scale(1/tth_powheg.Integral())
    tth_amcatnlo.Scale(1/tth_amcatnlo.Integral())
    tth_py8.Scale(1/tth_py8.Integral())
    
    sf_wt_powheg = tth_py8.Clone('sf_wt_powheg_'+b.var1+'_'+b.var2 )
    sf_wt_powheg.Divide(wth_powheg)

    sf_tt_powheg = tth_py8.Clone('sf_tt_powheg_'+b.var1+'_'+b.var2 )
    sf_tt_powheg.Divide(tth_powheg)

    sf_tt_amcatnlo = tth_py8.Clone('sf_tt_amcatnlo_'+b.var1+'_'+b.var2 )
    sf_tt_amcatnlo.Divide(tth_amcatnlo)
    '''

    sf_wt_powheg   = GetWeightHist2D('sf_wt_powheg_'+b.var1+'_'+b.var2, wth_powheg, tth_py8)
    sf_tt_powheg   = GetWeightHist2D('sf_tt_powheg_'+b.var1+'_'+b.var2, tth_powheg, tth_py8)
    sf_tt_amcatnlo = GetWeightHist2D('sf_tt_amcatnlo_'+b.var1+'_'+b.var2, tth_amcatnlo, tth_py8)

    sf_wt_powheg.Write()
    sf_tt_powheg.Write()
    sf_tt_amcatnlo.Write()

f.Close()
    
