from ROOT import TFile, TH1F, TPaveText
from math import sqrt

f = TFile("../tuples/ghostrate_data2015_test.root")
g = TFile("../tuples/ghostrate_mc2015_sim09b_test.root")

h = TH1F("pull", "hist", 25, 0.5, 1.5)

h1 = f.Get("fake_rate_pt")
h2 = g.Get("fake_rate_pt")

h3 = f.Get("fake_rate_eta")
h4 = g.Get("fake_rate_eta")

for i in range(h1.GetNbinsX()):
    h.Fill((h1.GetBinContent(i+1) / h2.GetBinContent(i+1)), 1/(sqrt(pow(h1.GetBinError(i+1),2) + pow(h2.GetBinError(i+1),2))))

for i in range(h3.GetNbinsX()):
    h.Fill((h3.GetBinContent(i+1) / h4.GetBinContent(i+1)), 1/(sqrt(pow(h3.GetBinError(i+1),2) + pow(h4.GetBinError(i+1),2))))
h.Fit('gaus')
chi2 = h1.Chi2Test(h2, 'CHI2/NDF')
f = h.GetListOfFunctions()[0]
mean = f.GetParameter(1)
sigma = f.GetParameter(2)

pave = TPaveText(0.2, 0.65, 0.4, 0.85, 'NDC')
pave.SetFillStyle(0)
pave.SetBorderSize(0)
pave.AddText('#chi2/ndf = {0:.2f}'.format(chi2))
pave.AddText('mean  = {0:.3f}'.format(mean))
pave.AddText('sigma = {0:.3f}'.format(sigma))


from PlotTools import *
from Style import *

f.SetParameter(0,f.GetParameter(0)/h.Integral())
h.Scale(1/h.Integral())

SetLHCbStyle()
p = Plot([h])
h.UseCurrentStyle()
p.setProp('location', '.')
p.setProp('filename', 'test.pdf')
p.setProp('ylabel', '[A.U.]')
p.setProp('xlabel', 'ratio')
p.setProp('markerstyles', 20)
p.setProp('drawOpts', 'e1')
p.setProp('extraObjs', [ pave ] )
p.drawROOT()
