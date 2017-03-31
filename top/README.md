Analysis Files
+++ python/top_wt_weights.py
Fill root file with histograms for pythia8, powheg and aMCatNLO for ttbar and wt at truth level. Calculate weights for NLO/LO and save file
+++ python/get_mc_samples.py
Fill root files with histograms for the reconstructed ttbar and WW samples. Reweight using NLO/LO factors for the mu, e and j in turn for ttbar. Also reweight ttbar sample to match wt
+++ python/get_ttbar_data.py
Fill root files with the data, split into fwd and bwd asymmetry and the same sign sample
+++ python/get_ttbar_mu_eff.py
Fill muon efficiency files for ttbar. Reweight in (pt, eta) of the muon using NLO/LO k-factors. Reweight in (eta, pt) using data/simulation from tag-and-probe. Write to ttbar_mu_effs.root.
+++ python/get_ttbar_e_eff.py
Fill same efficiency files for electron. Electron ID is reweighted using data/simulation but no corrections are applied to tracking. Write to ttbar_e_effs.root
+++ python/get_ttbar_jet_eff.py
Fill efficiency for jet reconstruction and tagging efficieny, reweighted to NLO
+++ python/get_ttbar_sel_eff.py
Get efficiency for ip and isolation cuts from simulation
+++ python/draw_eff_plots.py
Draw all the efficiency plots for ttbar and print out table
+++ python/get_zmumuj_comparison.py
Get jet energy scale corrections from Zmumuj
+++ python/electron_momscale.py
Get the momentum scale correction necesarry for electrons in order to calculate acceptance
+++ python/apply_jetenergy_scale.py
Apply the jet energy scale obtained from zmumuj to the ttbar sample for calculating the acceptance
+++ python/get_ttbar_acc.py
Calculate acceptance, reweight in (pt(e), pt(j)), NLO reweighting, apply jet energy scale corrections and those for electrons to get uncertainty
+++ python/get_zj_bkg.py
Get Zj background root files
+++ python/get_xsec.py
Load all data and simulation tuples, as well as efficiencies. Calculate cross-section.