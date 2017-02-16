from PlotTools import *
from ROOT import TFile
from Style import *
from Jawa import *

SetLHCbStyle()

f = TFile("/user2/sfarry/workspaces/top/tuples/e_ideff_data.root")
g = TFile("/user2/sfarry/workspaces/top/tuples/e_ideff_data_corr.root")
h = TFile("/user2/sfarry/workspaces/top/tuples/e_ideff_mc2016.root")
i = TFile("/user2/sfarry/workspaces/top/tuples/e_noiso_ideff_mc2016.root")


d = Plot([g.Get("eta_eff"), h.Get('probe_eta/EfficiencyGraph'), i.Get('probe_eta/EfficiencyGraph')])
d.setProp('xlabel', '#eta')
d.setProp('ylabel', 'Electron ID Eff.')
d.setProp('labels', ['Data (isolated)', 'MC2016(isolated)', 'MC2016'])
d.setProp('colors', ['black', 'red', 'blue'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'electronideff_eta.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.6, 0.95, 0.9])
d.ShiftLegX(-0.5)
d.setProp('ylims', [0.4, 1])
d.drawROOT()


d = Plot([g.Get("pt_eff"), h.Get('probe_pt/EfficiencyGraph'), i.Get('probe_pt/EfficiencyGraph')])
d.setProp('xlabel', 'p_{T} [GeV]')
d.setProp('ylabel', 'Electron ID Eff.')
d.setProp('labels', ['Data (isolated)', 'MC2016 (isolated)', 'MC2016'])
d.setProp('colors', ['black', 'red', 'blue'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'electronideff_pt.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.6, 0.95, 0.9])
d.ShiftLegX(-0.4)
d.setProp('ylims', [0.6, 1])
d.drawROOT()


data_pt = tgraph2hist("zee_eid_weights_pt_num", g.Get("pt_eff"))
mc_pt   = tgraph2hist("zee_eid_weights_pt_denom"  , h.Get("probe_pt/EfficiencyGraph"))
data_eta = tgraph2hist("zee_eid_weights_eta_num", g.Get("eta_eff"))
mc_eta   = tgraph2hist("zee_eid_weights_eta_denom"  , h.Get("probe_eta/EfficiencyGraph"))
data_etapt = g.Get("etapt_eff")
mc_etapt   = h.Get("probe_eta5_probe_pt5/EffGraph2D")

w_pt = GetRatioHist('zee_eid_weights_pt', data_pt, mc_pt)
w_eta = GetRatioHist('zee_eid_weights_eta', data_eta, mc_eta)
w_etapt = GetRatioHist2D('zee_eid_weights_etapt', data_etapt, mc_etapt)


d = Plot([w_pt])
d.setProp('xlabel', 'p_{T} [GeV]')
d.setProp('ylabel', 'Electron ID Eff. SF')
d.setProp('colors', ['black'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'electronideffsf_pt.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.6, 0.95, 0.9])
d.ShiftLegX(-0.4)
d.setProp('ylims', [0.5, 1.5])
d.drawROOT()

d = Plot([w_eta])
d.setProp('xlabel', '#eta')
d.setProp('ylabel', 'Electron ID Scale Factors')
d.setProp('colors', ['black'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'electronideffsf_eta.pdf')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.65, 0.6, 0.95, 0.9])
d.setProp('drawOpts', 'e1')
d.ShiftLegX(-0.4)
d.setProp('ylims', [0.5, 1.5])
d.drawROOT()

d = Plot([w_etapt])
d.setProp('xlabel', '#eta')
d.setProp('ylabel', 'p_{T} [GeV]')
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'electronideffsf_etapt.pdf')
d.setProp('drawOpts', 'colztexterror')
d.drawROOT()

gg = TFile("/user2/sfarry/workspaces/top/tuples/electron_eff_weights.root", "RECREATE")
w_pt.Write()
w_eta.Write()
w_etapt.Write()
gg.Close()
