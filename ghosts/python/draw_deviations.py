from ROOT import TFile, TH1F 
from math import sqrt

f = TFile("../tuples/ghostrate_data2015.root")
g = TFile("../tuples/ghostrate_mc2015.root")

h = TH1F("pull", "hist", 100, 0, 2)

h1 = f.Get("fake_rate_pt_data2015")
h2 = g.Get("fake_rate_pt_mc2015")

for i in range(h1.GetNbinsX()):
    h.Fill(h1.GetBinContent(i+1)/h2.GetBinContent(i+1), 1/(sqrt(pow(h1.GetBinError(i+1),2) + pow(h2.GetBinError(i+1),2))))

h.Fit('gaus')
    
chi2 = h1.Chi2Test(h2, 'WW')
