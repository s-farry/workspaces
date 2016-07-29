from ROOT import *
from Jawa import *

wmf   = TFile.Open("/hepstore/sfarry/aMC@NLO/Wmumj/Events/pythia.root")
wmt   = wmf.Get("Wjet")
wpf   = TFile.Open("/hepstore/sfarry/aMC@NLO/Wmupj/Events/pythia.root")
wpt   = wpf.Get("Wjet")

kin = "mu_pt > 20 && fwdjet_pt > 20 && acos(mu_pz/mu_p) < 0.3"
gausscut = "mu_pt > 17 && acos(mu_pz/mu_p) < 0.3"

unbal = "mu_pt > 20 && fwdjet_pt > 20 && mu_eta > 2 && mu_eta < 4.5 && sqrt(pow(mu_px + fwdjet_px,2) + pow(mu_py + fwdjet_py,2)) > 20"

mcatnlo_xsec_p = GetWeightSum(wpt, "w", kin )/wpt.GetEntries()
mcatnlo_xsec_m = GetWeightSum(wmt, "w", kin )/wmt.GetEntries()

mcatnlo_xsec = mcatnlo_xsec_p + mcatnlo_xsec_m
py8_tot_xsec = 1.23e-5 * 1e-3 / 1e-12 # pythia given in mb, x 1e-3 = barns, / 1e-12 = picobarns 

py8f = TFile.Open("/user2/sfarry/Generators/test.root")
py8t = py8f.Get('Wjet')

plus = 'mu_id == -13'
minus = 'mu_id == 13'

py8_frac_plus = float(py8t.GetEntries(plus))/py8t.GetEntries()
py8_frac_minus = 1 - py8_frac_plus

py8_acc     = float(py8t.GetEntries(gausscut))/py8t.GetEntries()
py8_scale   = float(py8t.GetEntries(kin))/py8t.GetEntries(gausscut)

py8_acc_plus   = float(py8t.GetEntries(gausscut + '&&' + plus))/py8t.GetEntries(plus)
py8_scale_plus = float(py8t.GetEntries(kin + '&&' + plus))/py8t.GetEntries(gausscut + '&&' + plus)

py8_acc_minus   = float(py8t.GetEntries(gausscut + '&&' + minus))/py8t.GetEntries(minus)
py8_scale_minus = float(py8t.GetEntries(kin + '&&' + minus))/py8t.GetEntries(gausscut + '&&' + minus)


py8_xsec_p = py8_tot_xsec * py8_frac_plus * py8_acc_plus * py8_scale_plus
py8_xsec_m = py8_tot_xsec * py8_frac_minus * py8_acc_minus * py8_scale_minus

py8_xsec = py8_xsec_p + py8_xsec_m
