from ROOT import TFile, TH1F, THStack, kYellow, kOrange, kViolet, kGreen, TCut, TGraphAsymmErrors, TCanvas
from PlotTools import *
from Style import *
from Utils import Bunch

from Jawa import *

SetLHCbStyle()

etrigger = TCut("tag_L0ElectronDecision_TOS == 1 && tag_Hlt1SingleElectronNoIPDecision_TOS == 1 && tag_Hlt2EWSingleElectronVHighPtDecision_TOS == 1")
etrigger_nohlt = TCut("tag_L0ElectronDecision_TOS == 1 && tag_Hlt1SingleElectronNoIPDecision_TOS == 1")

dataMD2016     = TFile("/hepstore/sfarry/GridOutput/2679/ElectronID.MD.2016.root")
dataMU2016     = TFile("/hepstore/sfarry/GridOutput/2680/ElectronID.MU.2016.root")
dataMD2015     = TFile.Open("root://hepgrid11.ph.liv.ac.uk//dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/ElectronID.MD.2015.root")
dataMU2015     = TFile.Open("root://hepgrid11.ph.liv.ac.uk//dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/ElectronID.MU.2015.root")

MDMC2016     = TFile.Open("root://hepgrid11.ph.liv.ac.uk//dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/ElectronID.Zg_ee.MD.MC2016.root")
MUMC2016     = TFile.Open("root://hepgrid11.ph.liv.ac.uk//dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/ElectronID.Zg_ee.MU.MC2016.root")

trktag   = TCut("tag_PT > 20000 && tag_ETA > 2.0 && tag_ETA < 4.5 && tag_CaloEcalE/tag_P > 0.2 && tag_CaloHcalE/tag_P < 0.01")
isotag = TCut("(tag_cpt_0.50 - tag_cpt_0.10) < 2000")
isoprobe = TCut("(probe_cpt_0.50 - probe_cpt_0.10) < 2000")
iso = isotag + isoprobe
antiiso = TCut("(tag_cpt_0.50 - tag_cpt_0.10) > 5000 && (probe_cpt_0.50 - tag_cpt_0.10) > 5000")
trkgmprobe = TCut("probe_ETA > 2.0 && probe_ETA < 4.0 && probe_PT > 10000 && (probe_cpt_0.50 - probe_cpt_0.10) < 2000")
trkgmprobe_antiiso = TCut("probe_ETA > 2.0 && probe_ETA < 4.0 && probe_PT > 10000 && (probe_cpt_0.50 - probe_cpt_0.10) > 5000")
trkeprobe = TCut("probe_ETA > 2.0 && probe_ETA < 4.0 && probe_PT > 20000 && (probe_cpt_0.50 - probe_cpt_0.10) < 2000 && probe_CaloEcalE/cosh(probe_ETA) > 10000")
trkeprobe_antiiso = TCut("probe_ETA > 2.0 && probe_ETA < 4.0 && probe_PT > 20000 && (probe_cpt_0.50 - probe_cpt_0.10) > 5000 && probe_CaloEcalE/cosh(probe_ETA) > 10000")
trkidprobe = TCut("probe_ETA > 2.0 && probe_ETA < 4.5 && probe_PT > 20000")
dphi_tp  = TCut("(tag_PHI - probe_PHI < TMath::Pi() ? abs(tag_PHI - probe_PHI) : 2*TMath::Pi() - abs(tag_PHI - probe_PHI)) > 2.7")

probeprs = TCut("probe_CaloPrsE > 50")
probehcal = TCut("probe_CaloHcalE/probe_P < 0.05 && probe_CaloHcalE > 0")
probeecal = TCut("probe_CaloEcalE/probe_P > 0.10 && probe_CaloEcalE > 0")

probeid  = probeprs + probehcal + probeecal

lo = 0.98
hi = 1.02
n  = 20

variations = [ lo + x*(hi -lo)/n for x in range(n+1) ]


vars = [
    ['tag_pt'  , 'tag_PT/1000'     , 25, 20, 70],
    ['probe_pt', 'probe_PT/1000.0' , 25, 20, 70]]

for v in variations:
    vars += [
        ['tag_pt_'+str(v)  , 'tag_PT*('+str(v)+')/1000'     , 25, 20, 70],
        ['probe_pt_'+str(v), 'probe_PT*('+str(v)+')/1000.0' , 25, 20, 70],
        ]

zee_data = Template("zee_data")
zee_data.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probeid)
zee_data.AddTree(dataMD2016.Get("PlusTag/DecayTree"))
zee_data.AddTree(dataMU2016.Get("PlusTag/DecayTree"))
zee_data.AddTree(dataMD2015.Get("PlusTag/DecayTree"))
zee_data.AddTree(dataMU2015.Get("PlusTag/DecayTree"))
zee_data.AddVars(vars)
zee_data.Run()

zee_data_ss = Template("zee_data_ss")
zee_data_ss.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probeid)
zee_data_ss.AddTree(dataMD2016.Get("PlusTagSS/DecayTree"))
zee_data_ss.AddTree(dataMU2016.Get("PlusTagSS/DecayTree"))
zee_data_ss.AddTree(dataMD2015.Get("PlusTagSS/DecayTree"))
zee_data_ss.AddTree(dataMU2015.Get("PlusTagSS/DecayTree"))
zee_data_ss.AddVars(vars)
zee_data_ss.Run()

zee_mc2016 = Template("zee_mc2016")
zee_mc2016.SetSelCut(etrigger_nohlt + trktag + trkeprobe + dphi_tp + probeid)
zee_mc2016.AddTree(MDMC2016.Get("PlusTag/DecayTree"))
zee_mc2016.AddTree(MUMC2016.Get("PlusTag/DecayTree"))
zee_mc2016.AddVars(vars)
zee_mc2016.Run()

h = TH1F("h", "h", n+1, lo, hi)

h1 = zee_data.GetVar('tag_pt').GetHist()
h1.Add(zee_data_ss.GetVar('tag_pt').GetHist(),-1)
h2 = zee_data.GetVar('probe_pt').GetHist()
h2.Add(zee_data_ss.GetVar('probe_pt').GetHist(),-1)
h1.Add(h2)

c = TCanvas()
h1.Draw()

for i,v in enumerate(variations):
    h3 = zee_mc2016.GetVar('tag_pt_'+str(v)).GetHist()
    h3.Add(zee_mc2016.GetVar('probe_pt_'+str(v)).GetHist())
    h3.Scale(h1.Integral() / h3.Integral())
    h.SetBinContent(i+1, h1.Chi2Test(h3, "CHI2/NDF"))
    if v < 1:
        h3.SetLineColor(2)
    else:
        h3.SetLineColor(4)
    h3.Draw("same")

from PlotTools import *
from Style import *
SetLHCbStyle()
a = Plot([h])
a.setProp('location', '/user2/sfarry/workspaces/top/figures')
a.setProp('filename', 'electron_momscale.pdf')
a.setProp('drawOpts', 'h')
a.setProp('fillstyles', 0)
a.setProp('ylabel', '#chi^{2} / nDoF')
a.setProp('xlabel', 'k')
a.drawROOT()
