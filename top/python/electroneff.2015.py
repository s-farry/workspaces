from ROOT import TFile, TH1F, THStack, kYellow, kOrange, kViolet, kGreen, TCut
from PlotTools import *
from Style import *
from Utils import Bunch

from Jawa import *

SetLHCbStyle()

etrigger = TCut("tag_L0ElectronDecision_TOS == 1 && tag_Hlt1SingleElectronNoIPDecision_TOS == 1 && tag_Hlt2EWSingleElectronVHighPtDecision_TOS == 1")

dataMD2015     = TFile.Open("root://hepgrid11.ph.liv.ac.uk//dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/ElectronID.MD.2015.root")
dataMU2015     = TFile.Open("root://hepgrid11.ph.liv.ac.uk//dpm/ph.liv.ac.uk/home/lhcb/Run2Effs/ElectronID.MU.2015.root")

trktag     = TCut("tag_PT > 20000 && tag_ETA > 2.0 && tag_ETA < 4.5 && tag_CaloEcalE/tag_P > 0.2 && tag_CaloHcalE/tag_P < 0.01")
isotag     = "(tag_cpt_0.50 - tag_cpt_0.10) < 2000"
isoprobe   = "(probe_cpt_0.50 - probe_cpt_0.10) < 2000"
iso        = isotag + isoprobe
antiiso    = TCut("(tag_cpt_0.50 - tag_cpt_0.10) > 5000 && (probe_cpt_0.50 - tag_cpt_0.10) > 5000")
trkgmprobe = TCut("probe_ETA > 2.0 && probe_ETA < 4.5 && probe_PT > 10000 && (probe_cpt_0.50 - probe_cpt_0.10) < 2000")
trkgmprobe_antiiso = TCut("probe_ETA > 2.0 && probe_ETA < 4.5 && probe_PT > 10000 && (probe_cpt_0.50 - probe_cpt_0.10) > 5000")
trkeprobe = TCut("probe_ETA > 2.0 && probe_ETA < 4.5 && probe_PT > 20000 && (probe_cpt_0.50 - probe_cpt_0.10) < 2000 && probe_CaloEcalE > 10000")
trkeprobe_antiiso = TCut("probe_ETA > 2.0 && probe_ETA < 4.5 && probe_PT > 20000 && (probe_cpt_0.50 - probe_cpt_0.10) > 5000 && probe_CaloEcalE > 10000")
trkidprobe = TCut("probe_ETA > 2.0 && probe_ETA < 4.5 && probe_PT > 20000")
dphi_tp  = TCut("(tag_PHI - probe_PHI < TMath::Pi() ? abs(tag_PHI - probe_PHI) : 2*TMath::Pi() - abs(tag_PHI - probe_PHI)) > 2.7")

probeprs = TCut("probe_CaloPrsE > 50")
probehcal = TCut("probe_CaloHcalE/probe_P < 0.05 && probe_CaloHcalE > 0")
probeecal = TCut("probe_CaloEcalE/probe_P > 0.10 && probe_CaloEcalE > 0")

probeid  = probeprs + probehcal + probeecal

vars = [
    ['tag_pt'  , 'tag_PT/1000'     , 10, 20, 60],
    ['probe_pt', 'probe_PT/1000.0' , 10, 20, 60],
    ['tag_eta'  , 'tag_ETA'        , 20, 2, 4.5],
    ['probe_eta', 'probe_ETA'      , 20, 2, 4.5],
    ['probe_prs', 'probe_CaloPrsE' , 100, 0, 500],
    ['probe_hcal','probe_CaloHcalE/probe_P', 100, 0, 1],
    ['probe_ecal','probe_CaloEcalE/probe_P', 100, 0, 1]
]

epgm_trk = Template("epgm_trk")
epgm_trk.SetSelCut(etrigger + trktag + trkgmprobe + dphi_tp)
epgm_trk.AddTree(dataMD2015.Get("GammaPlusTag/DecayTree"))
epgm_trk.AddTree(dataMU2015.Get("GammaPlusTag/DecayTree"))
epgm_trk.AddVars(vars)
epgm_trk.Run()
#epgm_trk.SaveToFile()

emgm_trk = Template("emgm_trk")
emgm_trk.SetSelCut(etrigger + trktag + trkgmprobe + dphi_tp)
emgm_trk.AddTree(dataMD2015.Get("GammaMinusTag/DecayTree"))
emgm_trk.AddTree(dataMU2015.Get("GammaMinusTag/DecayTree"))
emgm_trk.AddVars(vars)
emgm_trk.Run()
#emgm_trk.SaveToFile()


egm_trk = Template("egm_trk_2015", epgm_trk, emgm_trk)
egm_trk.SaveToFile("/user2/sfarry/workspaces/top/tuples/egm_trk_2015.root")

epgm_trk_antiiso = Template("epgm_trk_antiiso")
epgm_trk_antiiso.SetSelCut(etrigger + trktag + trkgmprobe_antiiso + dphi_tp)
epgm_trk_antiiso.AddTree(dataMD2015.Get("GammaPlusTag/DecayTree"))
epgm_trk_antiiso.AddTree(dataMU2015.Get("GammaPlusTag/DecayTree"))
epgm_trk_antiiso.AddVars(vars)
epgm_trk_antiiso.Run()
#epgm_trk_antiiso.SaveToFile()

emgm_trk_antiiso = Template("emgm_trk_antiiso")
emgm_trk_antiiso.SetSelCut(etrigger + trktag + trkgmprobe_antiiso + dphi_tp)
emgm_trk_antiiso.AddTree(dataMD2015.Get("GammaMinusTag/DecayTree"))
emgm_trk_antiiso.AddTree(dataMU2015.Get("GammaMinusTag/DecayTree"))
emgm_trk_antiiso.AddVars(vars)
emgm_trk_antiiso.Run()
#emgm_trk_antiiso.SaveToFile()

egm_trk_antiiso = Template("egm_trk_antiiso_2015", epgm_trk_antiiso, emgm_trk_antiiso)
egm_trk_antiiso.SaveToFile("/user2/sfarry/workspaces/top/tuples/egm_trk_antiiso_2015.root")

ep_trk = Template("ep_trk")
ep_trk.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp)
ep_trk.AddTree(dataMD2015.Get("PlusTag/DecayTree"))
ep_trk.AddTree(dataMU2015.Get("PlusTag/DecayTree"))
ep_trk.AddVars(vars)
ep_trk.Run()
#ep_trk.SaveToFile()

em_trk = Template("em_trk")
em_trk.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp)
em_trk.AddTree(dataMD2015.Get("MinusTag/DecayTree"))
em_trk.AddTree(dataMU2015.Get("MinusTag/DecayTree"))
em_trk.AddVars(vars)
em_trk.Run()
#em_trk.SaveToFile()

e_trk = Template("e_trk", ep_trk, em_trk)
e_trk.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trk_2015.root")

ep_trk_antiiso = Template("ep_trk_antiiso")
ep_trk_antiiso.SetSelCut(etrigger + trktag + trkeprobe_antiiso + dphi_tp)
ep_trk_antiiso.AddTree(dataMD2015.Get("PlusTag/DecayTree"))
ep_trk_antiiso.AddTree(dataMU2015.Get("PlusTag/DecayTree"))
ep_trk_antiiso.AddVars(vars)
ep_trk_antiiso.Run()
#ep_trk_antiiso.SaveToFile()

em_trk_antiiso = Template("em_trk_antiiso")
em_trk_antiiso.SetSelCut(etrigger + trktag + trkeprobe_antiiso + dphi_tp)
em_trk_antiiso.AddTree(dataMD2015.Get("MinusTag/DecayTree"))
em_trk_antiiso.AddTree(dataMU2015.Get("MinusTag/DecayTree"))
em_trk_antiiso.AddVars(vars)
em_trk_antiiso.Run()
#em_trk_antiiso.SaveToFile()

e_trk_antiiso = Template("e_trk_antiiso", ep_trk_antiiso, em_trk_antiiso)
e_trk_antiiso.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trk_antiiso_2015.root")

ep_trk_wid = Template("ep_trk_wid")
ep_trk_wid.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probeid)
ep_trk_wid.AddTree(dataMD2015.Get("PlusTag/DecayTree"))
ep_trk_wid.AddTree(dataMU2015.Get("PlusTag/DecayTree"))
ep_trk_wid.AddVars(vars)
ep_trk_wid.Run()
#ep_trk_wid.SaveToFile()

em_trk_wid = Template("em_trk_wid")
em_trk_wid.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probeid)
em_trk_wid.AddTree(dataMD2015.Get("MinusTag/DecayTree"))
em_trk_wid.AddTree(dataMU2015.Get("MinusTag/DecayTree"))
em_trk_wid.AddVars(vars)
em_trk_wid.Run()
#em_trk_wid.SaveToFile()

e_trk_wid = Template("e_trk_wid", ep_trk_wid, em_trk_wid)
e_trk_wid.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_trk_wid_2015.root")


ep_prs = Template("ep_prs")
ep_prs.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probeecal + probehcal)
ep_prs.AddTree(dataMD2015.Get("PlusTag/DecayTree"))
ep_prs.AddTree(dataMU2015.Get("PlusTag/DecayTree"))
ep_prs.AddVars(vars)
ep_prs.Run()
#ep_prs.SaveToFile()

em_prs = Template("em_prs")
em_prs.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probeecal+probehcal)
em_prs.AddTree(dataMD2015.Get("MinusTag/DecayTree"))
em_prs.AddTree(dataMU2015.Get("MinusTag/DecayTree"))
em_prs.AddVars(vars)
em_prs.Run()
#em_prs.SaveToFile()

e_prs = Template("e_prs", ep_prs, em_prs)
e_prs.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_prs_2015.root")

ep_hcal = Template("ep_hcal")
ep_hcal.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probeecal + probeprs)
ep_hcal.AddTree(dataMD2015.Get("PlusTag/DecayTree"))
ep_hcal.AddTree(dataMU2015.Get("PlusTag/DecayTree"))
ep_hcal.AddVars(vars)
ep_hcal.Run()
ep_hcal.SaveToFile()

em_hcal = Template("em_hcal")
em_hcal.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probeecal+probeprs)
em_hcal.AddTree(dataMD2015.Get("MinusTag/DecayTree"))
em_hcal.AddTree(dataMU2015.Get("MinusTag/DecayTree"))
em_hcal.AddVars(vars)
em_hcal.Run()
em_hcal.SaveToFile()

e_hcal = Template("e_hcal", ep_hcal, em_hcal)
e_hcal.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_hcal_2015.root")


ep_ecal = Template("ep_ecal")
ep_ecal.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probehcal + probeprs)
ep_ecal.AddTree(dataMD2015.Get("PlusTag/DecayTree"))
ep_ecal.AddTree(dataMU2015.Get("PlusTag/DecayTree"))
ep_ecal.AddVars(vars)
ep_ecal.Run()
#ep_ecal.SaveToFile()

em_ecal = Template("em_ecal")
em_ecal.SetSelCut(etrigger + trktag + trkeprobe + dphi_tp + probehcal+probeprs)
em_ecal.AddTree(dataMD2015.Get("MinusTag/DecayTree"))
em_ecal.AddTree(dataMU2015.Get("MinusTag/DecayTree"))
em_ecal.AddVars(vars)
em_ecal.Run()
#em_ecal.SaveToFile()

e_ecal = Template("e_ecal", ep_ecal, em_ecal)
e_ecal.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ecal_2015.root")


ep_ideff = EfficiencyClass("ep_ideff")
ep_ideff.SetSelectionCut(etrigger + trktag + trkidprobe + dphi_tp)
ep_ideff.SetPassCut(probeecal + probehcal + probeprs)
ep_ideff.AddTree(dataMD2015.Get("MinusTag/DecayTree"))
ep_ideff.AddTree(dataMU2015.Get("MinusTag/DecayTree"))
ep_ideff.AddVars(vars)
ep_ideff.Run()
#ep_ideff.SaveToFile()

em_ideff = EfficiencyClass("em_ideff")
em_ideff.SetSelectionCut(etrigger + trktag + trkidprobe + dphi_tp)
em_ideff.SetPassCut(probeecal + probehcal + probeprs)
em_ideff.AddTree(dataMD2015.Get("PlusTag/DecayTree"))
em_ideff.AddTree(dataMU2015.Get("PlusTag/DecayTree"))
em_ideff.AddVars(vars)
em_ideff.Run()
#em_ideff.SaveToFile()

e_ideff = EfficiencyClass("e_ideff", ep_ideff, em_ideff)
e_ideff.MakeEfficiencyGraph()
e_ideff.SaveToFile("/user2/sfarry/workspaces/top/tuples/e_ideff_2015.root")
