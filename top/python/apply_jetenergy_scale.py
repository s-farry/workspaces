from os import sys
import array

if len(sys.argv) != 2: sys.exit()

from ROOT import TFile, TTree, TRandom3

leafValues = array.array("d", [0.0])
leaves     = "ptj_scaled/D"
dpm = 'root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/top'
print sys.argv[1]
print sys.argv[1].replace('dpm', dpm)

infile = TFile.Open(sys.argv[1].replace('dpm', dpm))
intree = infile.Get("MCGenTrackEff/MCTrackEffTuple")

corrf = TFile("/user2/sfarry/workspaces/top/tuples/jetenergyscale_corrections.root")
s = corrf.Get("zmumuj_jetres_smear")
m = corrf.Get("zmumuj_jetmean_offset")

outfile = TFile(sys.argv[1].replace('.root', '.jscal.root').replace('dpm', '/user2/sfarry/workspaces/top/tuples'), 'RECREATE')
outtree = TTree("tree", "jet scale tree")
bra = outtree.Branch("vars", leafValues, leaves)
intree.SetBranchStatus("*",0)
intree.SetBranchStatus("ttbar_recjet_PT", 1)

a = TRandom3()

for i,e in enumerate(intree):
    if i%10000 == 0 : print "Event {0} of {1}".format(i,intree.GetEntries())
    leafValues[0] = 0.0
    if e.ttbar_recjet_PT > 0:
        leafValues[0] = e.ttbar_recjet_PT * (1 + a.Gaus(m.GetBinContent(m.FindBin(e.ttbar_recjet_PT/1000.0)), s.GetBinContent(s.FindBin(e.ttbar_jet_PT/100.0))))
    outtree.Fill()


outtree.Write()
outfile.Close()

