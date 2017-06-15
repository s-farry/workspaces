from ROOT import TFile
f = TFile("/user2/sfarry/workspaces/top/tuples/zbb_8tev_amcatnlo_predictions.root")

print "%f +/- %f (pdf) + %f - %f (scale) +%f - %f"%(f.Get("bjet1_eta_tot").GetVal(),
                                                    f.Get("bjet1_eta_pdferr").GetVal(),
                                                    f.Get("bjet1_eta_scaleerr_hi").GetVal(),
                                                    f.Get("bjet1_eta_scaleerr_lo").GetVal(),
                                                    f.Get("bjet1_eta_alphaserr_hi").GetVal(),
                                                    f.Get("bjet1_eta_alphaserr_lo").GetVal())

print "%f +/- %f (pdf) + %f - %f (scale) +%f - %f"%(f.Get("bjet1_recoiljet_eta_tot").GetVal(),
                                                    f.Get("bjet1_recoiljet_eta_pdferr").GetVal(),
                                                    f.Get("bjet1_recoiljet_eta_scaleerr_hi").GetVal(),
                                                    f.Get("bjet1_recoiljet_eta_scaleerr_lo").GetVal(),
                                                    f.Get("bjet1_recoiljet_eta_alphaserr_hi").GetVal(),
                                                    f.Get("bjet1_recoiljet_eta_alphaserr_lo").GetVal())

print "%f +/- %f (pdf) + %f - %f (scale) +%f - %f"%(f.Get("b_partons_eta_tot").GetVal(),
                                                    f.Get("b_partons_eta_pdferr").GetVal(),
                                                    f.Get("b_partons_eta_scaleerr_hi").GetVal(),
                                                    f.Get("b_partons_eta_scaleerr_lo").GetVal(),
                                                    f.Get("b_partons_eta_alphaserr_hi").GetVal(),
                                                    f.Get("b_partons_eta_alphaserr_lo").GetVal())


print "%f +/- %f (pdf) + %f - %f (scale) +%f - %f"%(f.Get("acc_tot").GetVal(),
                                                    f.Get("acc_tot_pdferr").GetVal(),
                                                    f.Get("acc_tot_scaleerr_hi").GetVal(),
                                                    f.Get("acc_tot_scaleerr_lo").GetVal(),
                                                    f.Get("acc_tot_alphaserr_hi").GetVal(),
                                                    f.Get("acc_tot_alphaserr_lo").GetVal())

g = TFile("/user2/sfarry/workspaces/top/tuples/zbbj_8tev_amcatnlo_predictions.root")

print "%f +/- %f (pdf) + %f - %f (scale) +%f - %f"%(g.Get("bjet1_eta_tot").GetVal(),
                                                    g.Get("bjet1_eta_pdferr").GetVal(),
                                                    g.Get("bjet1_eta_scaleerr_hi").GetVal(),
                                                    g.Get("bjet1_eta_scaleerr_lo").GetVal(),
                                                    g.Get("bjet1_eta_alphaserr_hi").GetVal(),
                                                    g.Get("bjet1_eta_alphaserr_lo").GetVal())

print "%f +/- %f (pdf) + %f - %f (scale) +%f - %f"%(g.Get("bjet1_recoiljet_eta_tot").GetVal(),
                                                    g.Get("bjet1_recoiljet_eta_pdferr").GetVal(),
                                                    g.Get("bjet1_recoiljet_eta_scaleerr_hi").GetVal(),
                                                    g.Get("bjet1_recoiljet_eta_scaleerr_lo").GetVal(),
                                                    g.Get("bjet1_recoiljet_eta_alphaserr_hi").GetVal(),
                                                    g.Get("bjet1_recoiljet_eta_alphaserr_lo").GetVal())

print "%f +/- %f (pdf) + %f - %f (scale) +%f - %f"%(g.Get("b_partons_eta_tot").GetVal(),
                                                    g.Get("b_partons_eta_pdferr").GetVal(),
                                                    g.Get("b_partons_eta_scaleerr_hi").GetVal(),
                                                    g.Get("b_partons_eta_scaleerr_lo").GetVal(),
                                                    g.Get("b_partons_eta_alphaserr_hi").GetVal(),
                                                    g.Get("b_partons_eta_alphaserr_lo").GetVal())


print "%f +/- %f (pdf) + %f - %f (scale) +%f - %f"%(g.Get("acc_tot").GetVal(),
                                                    g.Get("acc_tot_pdferr").GetVal(),
                                                    g.Get("acc_tot_scaleerr_hi").GetVal(),
                                                    g.Get("acc_tot_scaleerr_lo").GetVal(),
                                                    g.Get("acc_tot_alphaserr_hi").GetVal(),
                                                    g.Get("acc_tot_alphaserr_lo").GetVal())

