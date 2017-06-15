from Jawa import Template
from ROOT import TFile, TTree, TCut, TPaveText, TLine

from top_config import *

zmumu_mc2016.add_iptune()
qq2ttbar_mc2016.add_iptune()
gg2ttbar_mc2016.add_iptune()

zmumu_label = TPaveText(0.66, 0.5, 0.9, 0.6, 'NDC')
zmumu_label.SetFillStyle(0)
zmumu_label.SetBorderSize(0)
zmumu_label.AddText("Z#rightarrow#mu#mu")

ttbar_label = TPaveText(0.66, 0.5, 0.9, 0.6, 'NDC')
ttbar_label.SetFillStyle(0)
ttbar_label.SetBorderSize(0)
ttbar_label.AddText("t#bar{t}#rightarrow#mue")


zmumu_fid = TCut("muminus_ETA > 2 && muminus_ETA < 4.5 && muminus_PT > 20000 && muplus_ETA > 2 && muplus_ETA < 4.5 && muplus_PT > 20000 && boson_M > 60000 && boson_M < 120000")
ttbar_fid = TCut("mu_ETA > 2 && mu_ETA < 4.5 && mu_PT > 20000 && e_ETA > 2 && e_ETA < 4.5 && e_PT > 20000")


tt_qq_evts = qq2ttbar_mc2016.MU.Get('TotEvts').GetVal() + qq2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_qq_xsec = 9.966e-8*1e9
tt_qq_acc  = 10000.0/106462.0
tt_qq_scale = tt_qq_xsec * tt_qq_acc /tt_qq_evts

tt_gg_evts = gg2ttbar_mc2016.MU.Get('TotEvts').GetVal() + gg2ttbar_mc2016.MD.Get('TotEvts').GetVal()
tt_gg_xsec = 5.826e-7*1e9
tt_gg_acc  = 10000.0/156045.0
tt_gg_scale = tt_gg_xsec * tt_gg_acc /tt_gg_evts

data = Template("data")
data.SetSelCut(zmumu_fid)
data.AddTrees(zmumuj_2016.trees())
data.ApplyCut()
data.AddVar("mum_ipubs", "muminus_ipubs_d", 100, 0, 0.1)
data.AddVar("mup_ipubs", "muplus_ipubs_d", 100, 0, 0.1)
data.FillVars()

mc = Template("mc")
mc.SetSelCut(zmumu_fid)
mc.AddTrees(zmumu_mc2016.trees())
mc.ApplyCut()
mc.AddVar("mum_ipubs", "muminus_ipubs_d", 100, 0, 0.1)
mc.AddVar("mup_ipubs", "muplus_ipubs_d", 100, 0, 0.1)
mc.AddVar("mum_ipubs_tune", "muminus_ipubs_d_tune", 100, 0, 0.1)
mc.AddVar("mup_ipubs_tune", "muplus_ipubs_d_tune", 100, 0, 0.1)
mc.FillVars()

ttbar_mc = Template("ttbar_mc")
ttbar_mc.SetSelCut(ttbar_fid)
ttbar_mc.AddTrees(gg2ttbar_mc2016.trees(), tt_gg_scale)
ttbar_mc.AddTrees(qq2ttbar_mc2016.trees(), tt_qq_scale)
ttbar_mc.ApplyCut()
ttbar_mc.AddVar("mu_ipubs"     , "mu_ipubs_d", 100, 0, 0.1)
ttbar_mc.AddVar("e_ipubs"      , "e_ipubs_d", 100, 0, 0.1)
ttbar_mc.AddVar("mu_ipubs_tune", "mu_ipubs_d_tune", 100, 0, 0.1)
ttbar_mc.AddVar("e_ipubs_tune" , "e_ipubs_d_tune", 100, 0, 0.1)
ttbar_mc.FillVars()

'''
mwt_fwd = MWTemplate("top_eft_fwd")
mwt_fwd.AddTree(f.Get("topTuple"))
mwt_fwd.ApplyCut()
mwt_fwd.AddVar("top_rap", "abs(top_rap)", 100, 0, 5)
mwt_fwd.AddWeight("central", "w")
for i in range(24):
    mwt_fwd.AddWeight("rwgt_"+str(i+1), "rwgt_"+str(i+1))
mwt_fwd.FillVars()
mwt_fwd.SaveToFile()
'''

from Style import *
SetLHCbStyle()

from PlotTools import *
zmumu_mc = mc.GetVar('mum_ipubs').GetHist().Clone('zmumu_mc')
zmumu_mc.Add(mc.GetVar('mup_ipubs').GetHist())
zmumu_mc_tune = mc.GetVar('mum_ipubs_tune').GetHist().Clone('zmumu_mc_tune')
zmumu_mc_tune.Add(mc.GetVar('mup_ipubs_tune').GetHist())
zmumu_data = data.GetVar('mum_ipubs').GetHist().Clone('zmumu_data')
zmumu_data.Add(data.GetVar('mup_ipubs').GetHist())

p = Plot([ zmumu_mc, zmumu_mc_tune, zmumu_data ])
for pp in p.plots: pp.UseCurrentStyle()
p.setProp('forcestyle', True)
p.setProp('filename', 'zmumu_tunedip.pdf')
p.setProp('location', '/user2/sfarry/workspaces/top/figures')
p.setProp('colors', [2, 4, 1])
p.setProp('drawOpts', ['hist' for i in range(12)])
p.setProp('fillstyles', 0)
p.setProp('markerstyles', [0, 0, 20])
p.setProp('drawOpts', ['h', 'h', 'e1'])
#p.setProp('toCompare', { 1 : [2] })
p.setProp('ycomplims', [0.8, 1.15])
p.setProp('ylabel', '[A.U.]')
p.setProp('xlabel', 'ip [mm]')
p.setProp('normalised', True)
p.setProp('labels', ['MC2016', 'MC2016(tuned)', 'Data'])
p.setProp('extraObjs', [zmumu_label])
p.drawROOT()


p = Plot([ ttbar_mc.GetVar('mu_ipubs').GetHist(), ttbar_mc.GetVar('mu_ipubs_tune').GetHist() ])
for pp in p.plots: pp.UseCurrentStyle()
p.setProp('forcestyle', True)
p.setProp('filename', 'ttbar_tunedip_mu.pdf')
p.setProp('location', '/user2/sfarry/workspaces/top/figures')
p.setProp('colors', [2, 4, 1])
p.setProp('drawOpts', ['hist' for i in range(12)])
p.setProp('fillstyles', 0)
p.setProp('markerstyles', [0, 0, 20])
p.setProp('drawOpts', ['h', 'h', 'e1'])
#p.setProp('toCompare', { 1 : [2] })
p.setProp('ycomplims', [0.8, 1.15])
p.setProp('ylabel', '[A.U.]')
p.setProp('xlabel', 'muon ip [mm]')
p.setProp('normalised', True)
p.setProp('labels', ['MC2016', 'MC2016(tuned)', 'Data'])
p.setProp('extraObjs', [ttbar_label])
p.drawROOT()


p = Plot([ ttbar_mc.GetVar('e_ipubs').GetHist(), ttbar_mc.GetVar('e_ipubs_tune').GetHist() ])
for pp in p.plots: pp.UseCurrentStyle()
p.setProp('forcestyle', True)
p.setProp('filename', 'ttbar_tunedip_e.pdf')
p.setProp('location', '/user2/sfarry/workspaces/top/figures')
p.setProp('colors', [2, 4, 1])
p.setProp('drawOpts', ['hist' for i in range(12)])
p.setProp('fillstyles', 0)
p.setProp('markerstyles', [0, 0, 20])
p.setProp('drawOpts', ['h', 'h', 'e1'])
#p.setProp('toCompare', { 1 : [2] })
p.setProp('ycomplims', [0.8, 1.15])
p.setProp('ylabel', '[A.U.]')
p.setProp('xlabel', 'electron ip [mm]')
p.setProp('normalised', True)
p.setProp('labels', ['MC2016', 'MC2016(tuned)', 'Data'])
p.setProp('extraObjs', [ttbar_label])
p.drawROOT()
