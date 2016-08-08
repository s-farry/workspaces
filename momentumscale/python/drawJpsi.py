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
h = TH1F("Jpsi_M", "Mass of Jpsi", 100, 3010, 3170)
h.SetYTitle("Events")
h.SetXTitle("M_{#mu#mu}")


#loop over tree and fill
for evt in t:
    h.Fill(evt.J_psi_1S_M)

#make a canvas
c = TCanvas("c1")
#draw
h.Draw()
#save
c.Print("Jpsi_M.pdf")
