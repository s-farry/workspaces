from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()


f = TFile("/user2/sfarry/workspaces/energyflow/tuples/etagamma_2016_turbo_fit.root")
g = TFile("/user2/sfarry/workspaces/energyflow/tuples/eta_2016_turbo_fit.root")
h = TFile("/user2/sfarry/workspaces/energyflow/tuples/etagamma_py8_fit.root")
i = TFile("/user2/sfarry/workspaces/energyflow/tuples/eta_py8_fit.root")

hh = TFile("/user2/sfarry/workspaces/energyflow/tuples/photonEff_v3.root")

bf_ratio = 3.1e-4/5.8e-6

etammg_turbo_eta = f.Get("Nsig_v_gamma_eta")
etammg_turbo_pt  = f.Get("Nsig_v_gamma_pt")
etammg_py8_eta   = h.Get("N_v_gamma_eta")
etammg_py8_pt    = h.Get("N_v_gamma_pt")

Netamm_turbo = g.Get("m_Nsig_tot_tot").GetVal()
Netamm_py8   = i.Get("m_N_tot_tot").GetVal()

Netammg_turbo = f.Get("m2_Nsig_tot").GetVal()
Netammg_py8   = h.Get("m2_N_tot").GetVal()

etammg_turbo_eta.Scale( 1.0 / Netamm_turbo )
etammg_turbo_pt.Scale ( 1.0 / Netamm_turbo )
etammg_py8_eta.Scale  ( 1.0 / Netamm_py8   )
etammg_py8_pt.Scale   ( 1.0 / Netamm_py8   )

eta_eff_eta = etammg_turbo_eta.Clone("eta_eff_eta")
eta_eff_eta.Divide(etammg_py8_eta)

eta_eff_pt = etammg_turbo_pt.Clone("eta_eff_pt")
eta_eff_pt.Divide(etammg_py8_pt)

turbo_ratio = float(Netammg_turbo) / (Netamm_turbo * bf_ratio)
py8_ratio   = float(Netammg_py8)   / (Netamm_py8 * bf_ratio)

totaleff_data = turbo_ratio / py8_ratio

eta_pass_mc  = hh.Get("incl_g2rPhotons_eta")
eta_tot_mc = hh.Get("incl_genPhotons_eta")
pt_pass_mc   = hh.Get("incl_g2rPhotons_pt")
pt_tot_mc  = hh.Get("incl_genPhotons_pt")

eta_pass_mc.Sumw2()
eta_tot_mc.Sumw2()
pt_pass_mc.Sumw2()
pt_tot_mc.Sumw2()

totaleff_mc = eta_pass_mc.Integral() / eta_tot_mc.Integral()
eta_eff_mc_raw = hh.Get("eff_eta")
pt_eff_mc_raw  = hh.Get("eff_pt")
eta_eff_mc = eta_pass_mc.Clone("mc_eff_eta")
eta_eff_mc.Divide(eta_tot_mc)
pt_eff_mc = pt_pass_mc.Clone("mc_eff_pt")
pt_eff_mc.Divide(pt_tot_mc)


ratio_bjpsik =  sqrt(0.918667)
err_bjpsik = sqrt(0.0361**2+(0.918667*0.065)**2) / (2*ratio_bjpsik)

#eta_tot_eta.Scale(bf_ratio)
#eta_tot_pt.Scale(bf_ratio)

#eta_pass_eta.Scale((totaleff_mc / total_eff) * ratio_bjpsik )
#eta_pass_pt.Scale((totaleff_mc / total_eff)  * ratio_bjpsik )

#eta_eff_eta = eta_pass_eta.Clone("eta_eff_eta")
#eta_eff_pt  = eta_pass_pt.Clone("eta_eff_pt")

#eta_eff_eta.Divide(eta_tot_eta)
#eta_eff_pt.Divide(eta_tot_pt)

d = Plot([eta_eff_eta])
d.setProp('xlabel', '#eta(#gamma)')
d.setProp('ylabel', 'Rec. Eff.')
d.setProp('labels', ['2016 Turbo Data'])
d.setProp('colors', ['black'])
d.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d.setProp('filename', 'eta_eff_data_eta')
d.setProp('markerstyles', 20)
d.setProp('leglims', [0.25, 0.2, 0.6, 0.4])
d.drawROOT()

d2 = Plot([eta_eff_pt])
d2.setProp('xlabel', 'p_{T}(#gamma) [MeV]')
d2.setProp('ylabel', 'Rec. Eff.')
d2.setProp('labels', ['2016 Turbo Data'])
d2.setProp('colors', ['black'])
d2.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d2.setProp('filename', 'eta_eff_data_pt')
d2.setProp('markerstyles', 20)
d2.setProp('leglims', [0.25, 0.7, 0.5, 0.9])
d2.drawROOT()

d3 = Plot([eta_eff_mc])
d3.setProp('xlabel', '#eta(#gamma)')
d3.setProp('ylabel', 'Rec. Eff.')
d3.setProp('labels', ['MC2016 MinBias'])
d3.setProp('colors', ['black'])
d3.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d3.setProp('filename', 'eta_eff_eta_mc')
d3.setProp('markerstyles', 20)
d3.setProp('leglims', [0.25, 0.3, 0.5, 0.5])
d3.setProp('fillstyles', [0])
d3.setProp('markerstyles', 20)
d3.setProp('drawOpts', 'e1')
d3.drawROOT()

d4 = Plot([pt_eff_mc])
d4.setProp('xlabel', 'p_{T}(#gamma) [MeV]')
d4.setProp('ylabel', 'Rec. Eff.')
d4.setProp('labels', ['MC2016 MinBias'])
d4.setProp('colors', ['black'])
d4.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d4.setProp('filename', 'eta_eff_pt_mc')
d4.setProp('fillstyles', 0)
d4.setProp('markerstyles', 20)
d4.setProp('leglims', [0.25, 0.3, 0.5, 0.5])
d4.drawROOT()

ratio_eff_eta = eta_eff_eta.Clone("ratio_eff_eta")
ratio_eff_eta.Sumw2()
ratio_eff_eta.Divide(eta_eff_mc)
ratio_eff_pt = eta_eff_pt.Clone("ratio_eff_pt")
ratio_eff_pt.Sumw2()
ratio_eff_pt.Divide(pt_eff_mc)

d5 = Plot([ratio_eff_eta])
d5.setProp('xlabel', '#eta(#gamma)')
d5.setProp('ylabel', 'Data/MC')
d5.setProp('labels', ['2016 Turbo Data'])
d5.setProp('colors', ['black'])
d5.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d5.setProp('filename', 'eta_ratio_eta')
d5.setProp('markerstyles', 20)
d5.setProp('leglims', [0.25, 0.7, 0.5, 0.9])
d5.drawROOT()

d6 = Plot([ratio_eff_pt])
d6.setProp('xlabel', 'p_{T}(#gamma) [MeV]')
d6.setProp('ylabel', 'Data/MC')
d6.setProp('labels', ['2016 Turbo Data'])
d6.setProp('colors', ['black'])
d6.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d6.setProp('filename', 'eta_ratio_pt')
d6.setProp('markerstyles', 20)
d6.setProp('leglims', [0.25, 0.7, 0.5, 0.9])
d6.drawROOT()

for i in range(etammg_turbo_eta.GetNbinsX()):
    etammg_turbo_eta.SetBinContent(i+1, etammg_turbo_eta.GetBinContent(i+1) * 0.2 / etammg_turbo_eta.GetBinWidth(i+1))
for i in range(etammg_turbo_pt.GetNbinsX()):
    etammg_turbo_pt.SetBinContent(i+1, etammg_turbo_pt.GetBinContent(i+1) * 100 / etammg_turbo_pt.GetBinWidth(i+1))
for i in range(etammg_py8_eta.GetNbinsX()):
    etammg_py8_eta.SetBinContent(i+1, etammg_py8_eta.GetBinContent(i+1) * 0.2 / etammg_py8_eta.GetBinWidth(i+1))
for i in range(etammg_py8_pt.GetNbinsX()):
    etammg_py8_pt.SetBinContent(i+1, etammg_py8_pt.GetBinContent(i+1) * 100 / eta_eff_pt.GetBinWidth(i+1))

d7 = Plot([etammg_turbo_eta])
d7.setProp('xlabel', '#eta(#gamma)')
d7.setProp('ylabel', 'N(#eta#rightarrow#mu#mu#gamma)')
d7.setProp('labels', ['2016 Turbo Data'])
d7.setProp('colors', ['black'])
d7.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d7.setProp('filename', 'etamumugamma_turbo_eta')
d7.setProp('markerstyles', 20)
d7.setProp('leglims', [0.25, 0.7, 0.5, 0.9])
d7.drawROOT()

d8 = Plot([etammg_turbo_pt])
d8.setProp('xlabel', 'p_{T}(#gamma) [MeV]')
d8.setProp('ylabel', 'N(#eta#rightarrow#mu#mu#gamma)')
d8.setProp('labels', ['2016 Turbo Data'])
d8.setProp('colors', ['black'])
d8.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d8.setProp('filename', 'etamumugamma_turbo_pt')
d8.setProp('markerstyles', 20)
d8.setProp('leglims', [0.25, 0.7, 0.5, 0.9])
d8.drawROOT()

d9 = Plot([etammg_py8_eta])
d9.setProp('xlabel', '#eta(#gamma)')
d9.setProp('ylabel', 'N(#eta#rightarrow#mu#mu#gamma)')
d9.setProp('labels', ['Pythia8'])
d9.setProp('colors', ['black'])
d9.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d9.setProp('filename', 'etamumugamma_py8_eta')
d9.setProp('markerstyles', 20)
d9.setProp('leglims', [0.25, 0.7, 0.5, 0.9])
d9.drawROOT()

d10 = Plot([etammg_py8_pt])
d10.setProp('xlabel', 'p_{T}(#gamma) [MeV]')
d10.setProp('ylabel', 'N(#eta#rightarrow#mu#mu#gamma)')
d10.setProp('labels', ['Pythia8'])
d10.setProp('colors', ['black'])
d10.setProp('location', '/user2/sfarry/workspaces/energyflow/figs')
d10.setProp('filename', 'etamumugamma_py8_pt')
d10.setProp('markerstyles', 20)
d10.setProp('leglims', [0.25, 0.7, 0.5, 0.9])
d10.drawROOT()
