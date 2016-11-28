#import everything from ROOT
from ROOT import *

#open up file
f = TFile("/hepstore/sfarry/GridOutput/1001/Jpsi.2015.root")
#get tree from file
t = f.Get("JpsiTuple/DecayTree")

#turn of all the branches to speed up loop
t.SetBranchStatus("*",0)
#only turn back on what we need
t.SetBranchStatus("J_psi_1S_M",1)

#initialise histogram
#h = TH1F("Jpsi_M", "Mass of Jpsi", 100, 3010, 3170)
#h.SetYTitle("Events")
#h.SetXTitle("M_{#mu#mu}")

x     = RooRealVar("J_psi_1S_M", "M", 3010, 3170)
mean  = RooRealVar("mean", "mean of gaussian", 3100, 3010, 3170)
sigma = RooRealVar("sigma", "width of gaussian", 100, 0, 1000)
alpha = RooRealVar("alpha", "alpha", 1, 0, 2)
n     = RooRealVar("n",  "n", 1, 0.1, 20.0)
s     = RooRealVar("s",   "s", -0.0001,-100, 100.0)
Nsig  = RooRealVar("Nsig", "Nsig", 10000, 0, 500000)
Nbkg  = RooRealVar("Nbkg", "Nbkg", 10000, 0, 500000)


cb = RooCBShape("cbshape", "cbshape", x, mean, sigma, alpha, n)
expo = RooExponential("bkg", "bkg", x, s)
model = RooAddPdf("model", "mass model", RooArgList(cb,expo), RooArgList(Nsig, Nbkg))
xframe = x.frame(RooFit.Title("Gaussian p.d.f."))

ds = RooDataSet("ds", "ds", RooArgSet(x), RooFit.Import(t))

model.fitTo(ds)

#mean.Print()

#make a canvas
c = TCanvas("c1")
#draw
ds.plotOn(xframe)
model.plotOn(xframe)
xframe.Draw()
#save
c.Print("Jpsi_M.pdf")
