from ROOT import *

c = TFile("zmumuj.root")
jecup  = TFile("zmumuj_jecup.root")
jecdwn = TFile("zmumuj_jecdown.root")
jecmcup  = TFile("zmumuj_jecmcup.root")
jecmcdwn = TFile("zmumuj_jecmcdown.root")
smear = TFile("zmumuj_smear.root")

for v in ['Jet_ETA', 'Jet_PT', 'Y', 'dPhi']:
    print '===============',v,'================'
    print '\\begin{tabular}{c c}'
    for b in range(c.Get("Data/"+v).GetXaxis().GetNbins()):
        c_val        = c.Get("Data/"+v).GetBinContent(b+1)
        jecup_val    = jecup.Get("Data/"+v).GetBinContent(b+1)
        jecdwn_val   = jecdwn.Get("Data/"+v).GetBinContent(b+1)
        jecmcup_val  = jecmcup.Get("Data/"+v).GetBinContent(b+1)
        jecmcdwn_val = jecmcdwn.Get("Data/"+v).GetBinContent(b+1)
        smear_val    = smear.Get("Data/"+v).GetBinContent(b+1)
        print c_val, ' +/- ', max(abs(jecup_val - c_val), abs(jecdwn_val - c_val)),' +/- ',max(abs(jecmcup_val - c_val), abs(jecmcdwn_val - c_val)),' +/- ',abs(smear_val - c_val)
