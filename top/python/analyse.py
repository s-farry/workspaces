#import what we will need
from ROOT import *

#open root file and get ttree
f = TFile("/hepstore/sfarry/aMCatNLO/ttbar/Events/llj_ttbar_amcatnlo_13tev.root")
t = f.Get("ttbar")
evts = f.Get("totEvts").GetVal()

#two separate histograms for muplus and muminus

h1 = TH1F("lp_eta", "lp_eta", 100, -5.0, 5.0)
h2 = TH1F("lm_eta", "lm_eta", 100, -5.0, 5.0)

maxEvts = 100000

#loop over events and fill histogram
for i,e in enumerate(t):
    if i > maxEvts and maxEvts != -1: break
    if i%1000 == 0:
        print "Entry {0} of {1}".format(i,evts)
    if e.jet_pt > 20 and abs(e.jet_flav) == 5:
        if e.lp_pt > 20:
            h1.Fill(e.lp_eta, e.w1010 / evts)
        if e.lm_pt > 20:
            h2.Fill(e.lm_eta, e.w1010 / evts)


c1 = TCanvas("c1")
h1.SetYTitle('#sigma [pb]')
h1.SetXTitle('#eta (mu)')
h1.Draw()
h2.SetLineColor(2)
h2.Draw("same")
c1.Print("test.pdf")
