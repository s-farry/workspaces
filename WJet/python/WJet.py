from os import sys
from analysis import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F

from WTauConfig import *
from Wjconfig import *

variables = [
    ["PT" ,"muminus_PT" ,50, 20000 , 70000 ],
    ["IP" ,"muminus_IP_OWNPV" ,50, 0 , 0.05],
    ["IP_BDT" ,"IP_BDT" ,50, -1 , 1],
    ["IPUbs"  ,"muminus_ipubs" ,50, 0 , 0.2],
    ["Iso", "muminus_cpt_0.50", 100, 0 , 20000],
    ["TotIso"       , "muminus_cpt_0.50 + muminus_npt_0.50"     , 100 ,     0  , 20000],
    ["TotIsoVPt"    , "sqrt((muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_cpy_0.50 + muminus_npy_0.50)^2)"  , 100 ,     0  , 20000],
    ["IsoAsymm", "muminus_PT/sqrt((muminus_PX + muminus_cpx_0.50)^2 + (muminus_PY + muminus_cpy_0.50)^2)", 101 , 0 , 1.01 ],
    ["IsoMult", "muminus_cmult_0.50", 21, -0.5, 20.5],
    ["NeutIso", "muminus_npt_0.50", 100, 0 , 10000],
    ["ETA",     "muminus_ETA", 100, 2, 4.5]
    ]

jetvars = [
    ["Jet_M",  "PFjet_M", 100 , 0, 20000],
    ["Jet_PT", "PFjet_PT", 100 , 0, 100000],
    ["Jet_mpt", "PFjet_mpt", 100 , 0, 30000],
    ["Jet_mtf", "PFjet_mtf", 100 , 0, 1],
    ["Jet_npoint", "PFjet_npoint", 21 , -0.5, 20.5],
    ["Jet_mult", "PFjet_number_of_daughters", 41 , -0.5, 40.5],
    ["MuJet_M",  "sqrt( (PFjet_PE + muminus_PE)^2 - ((PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 + (PFjet_PZ + muminus_PZ)^2 ) )", 100, 0, 100000],
    ["MuJet_PT",  "sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 )", 100, 0, 100000]
    ]

variables2d = [
    ["PT","IPUbs"],
    ["PT","Iso"],
    ["Iso", "NeutIso"],
    ["PT", "ETA"]
    ]

jet        = TCut("PFjet_mtf <0.75 && PFjet_npoint >=2 && PFjet_mpt > 1800 && PFjet_PT > 20000")
jet10      = TCut("PFjet_mtf <0.75 && PFjet_npoint >=2 && PFjet_mpt > 1800 && PFjet_PT > 10000")
mupjpt     = TCut("sqrt( (PFjet_PX + muplus_PX)^2 + (PFjet_PY + muplus_PY)^2 ) > 20000")
mumjpt     = TCut("sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 ) > 20000")
taupjpt    = TCut("sqrt( (PFjet_PX + tau_mu2_px)^2 + (PFjet_PY + tau_mu2_py)^2 ) > 20000")
taumjpt    = TCut("sqrt( (PFjet_PX + tau_mu_px)^2 + (PFjet_PY + tau_mu_py)^2 ) > 20000")
antijpt    = TCut("sqrt( (PFjet_PX + muminus_PX)^2 + (PFjet_PY + muminus_PY)^2 ) < 20000")

zmumuf     = TFile("/hepstore/sfarry/ZMuMu.2012.root")
zmumumvf   = TFile("/hepstore/sfarry/ZMuMu.2012.MVA.root")
zmumudatat = zmumuf.Get("ZMuMu/DecayTree")
zmumudatat.AddFriend(zmumumvf.Get("tree"))

wpj = AnalysisClass("wpj")
wpj.SetSelCut(selcut20 + jet10 + lowip + mumjpt)
wpj.SetData("Data", datat)
wpj.AddTemplate("Zp" , zmumudatat , selcutewk20_p + jet10 + lowip + mupjpt, kYellow)
wpj.AddTemplate("Wp" , zmumudatat , selcutewk20_p + jet10 + lowip + mupjpt, kOrange)
wpj.AddTemplate("Zm" , zmumudatat , selcutewk20 + jet10 + lowip + mumjpt, kYellow)
wpj.AddTemplate("Wm" , zmumudatat , selcutewk20 + jet10 + lowip + mumjpt, kOrange)
wpj.AddVars(variables)
wpj.AddVars(jetvars)
wpj.Add2DVars(variables2d)
wpj.GetTemplate("Zp").GetVar("TotIso").SetVarName("muplus_cpt_0.50 + muplus_npt_0.50")
wpj.GetTemplate("Zp").GetVar("ETA").SetVarName("muplus_ETA")
wpj.GetTemplate("Zp").GetVar("PT").SetVarName("muplus_PT")
wpj.GetTemplate("Zp").GetVar("IsoAsymm").SetVarName("muplus_PT/sqrt((muplus_PX + muplus_cpx_0.50 + muplus_npx_0.50)^2 + (muplus_PY + muplus_cpy_0.50 + muplus_npy_0.50)^2)")
wpj.GetTemplate("Wp").GetVar("TotIso").SetVarName("muplus_cpt_0.50 + muplus_npt_0.50")
wpj.GetTemplate("Wp").GetVar("ETA").SetVarName("muplus_ETA")
wpj.GetTemplate("Wp").GetVar("PT").SetVarName("muplus_PT")
wpj.GetTemplate("Wp").GetVar("IsoAsymm").SetVarName("muplus_PT/sqrt((muplus_PX + muplus_cpx_0.50 + muplus_npx_0.50)^2 + (muplus_PY + muplus_cpy_0.50 + muplus_npy_0.50)^2)")
wpj.GetTemplate("Wp").Reweight("muplus_PT"  , wmupj_ptrw )
wpj.GetTemplate("Wm").Reweight("muminus_PT" , wmupj_ptrw )
#wpj.GetTemplate("Zp").Reweight("muplus_PT"  , zmumu2zmu_rb )
#wpj.GetTemplate("Zm").Reweight("muminus_PT", zmumu2zmu_rb )
wpj.ApplyCuts()
wpj.FillVars()
w = Template("W", wpj.GetTemplate("Wp"), wpj.GetTemplate("Wm"))
wpj.AddTemplate(w)
wpj.ToFit = ["Zp", "Wp"]
wpj.ToStack = wpj.ToFit
#wpj.TFracFit("TotIso")
wpj.MakeStacks()
wpj.SaveToFile()
