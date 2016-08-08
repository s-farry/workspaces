
import copy
from ROOT import *
import Jawa

from PlotTools import *
from Style import SetLHCbStyle

SetLHCbStyle()

f = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/ZMuMu.Refit.2015.root")
t = f.Get("ZMuMu/DecayTree")

mass = TCut("Z0_M > 60000 && Z0_M < 120000")
eta  = TCut("min(muplus_ETA, muminus_ETA) > 2.0 && max(muplus_ETA, muminus_ETA) < 4.5")
pt   = TCut("min(muplus_PT, muminus_PT) > 20000")
trk  = TCut("muplus_TRACK_PCHI2 > 0.01 && muminus_TRACK_PCHI2 > 0.01 && sqrt(muplus_PERR2)/muplus_P < 0.1 && sqrt(muminus_PERR2)/muminus_P < 0.1")

selcut = mass + eta + pt

trigger_plus   = TCut("muplus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonEWDecision_TOS ==1")
trigger_minus = TCut("muminus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonEWDecision_TOS ==1")

ybins = [2.0 + 0.125*i for i in range(17)] + [ 4.25, 4.50 ]

trigger_dimuon = TCut("("+trigger_plus.GetTitle() + ") || (" + trigger_minus.GetTitle() + ")")

vars = [
    ["PCHI2", "muminus_TRACK_PCHI2", 100, 0, 1],
    ["MatchChi2", "muminus_TRACK_MatchCHI2", 100, 0, 30],
    ["GhostProb", "muminus_TRACK_GhostProb", 100, 0, 1],
    ["RelPERR"  , "sqrt(muminus_PERR2)/muminus_P", 100, 0, 0.1],
    ["CHI2"  , "muminus_TRACK_CHI2NDOF", 100, 0, 6],
    ["PCHI2_refit", "muminus_Refit_PCHI2", 100, 0, 1],
    #["MatchChi2_refit", "muminus_Refit_MatchCHI2", 100, 0, 30],
    ["GhostProb_refit", "muminus_Refit_GhostProb", 100, 0, 1],
    ["RelPERR_refit"  , "sqrt(muminus_Refit_PERR2/(muminus_Refit_PT^2 + muminus_Refit_PZ^2))", 100, 0, 0.1],
    ["CHI2_refit"  , "muminus_Refit_CHI2NDOF", 100, 0, 6]
]
plusvars = [[j.replace('minus','plus') if type(j)==str else j for j in i] for i in vars]

z_minus = Jawa.Template("z_minus")
z_minus.SetSelCut(selcut + trigger_dimuon)
z_minus.AddTree(t)
z_minus.AddVars(vars)
z_minus.Run()
z_minus.SaveToFile()

z_plus = Jawa.Template("z_plus")
z_plus.SetSelCut(selcut + trigger_dimuon)
z_plus.AddTree(t)
z_plus.AddVars(plusvars)
z_plus.Run()
z_plus.SaveToFile()

z = Jawa.Template("z", z_plus, z_minus)
z.SaveToFile()

from Style import *
SetLHCbStyle()

p = Plot([z.GetVar('CHI2').GetHist(), z.GetVar('CHI2_refit').GetHist()])
p.setProp('filename', 'zmumu_chi2_refit')
p.setProp('location', '/user2/sfarry/momentumscale/figures')
p.setProp('ynormlims', [0.0,0.12])
p.setProp('normalised', True)
p.setProp('colors', ['red', 'blue', 8, ROOT.kYellow-3])
p.setProp('markerstyles', 20)
p.setProp('labels', ['Z#rightarrow#mu#mu', 'Z#rightarrow#mu#mu (Refit)'])
p.setProp('xlabel', '#chi^2/ndof.')
p.setProp('leglims', [0.5, 0.7, 0.95, 0.9])
p.setProp('ynormlabel', '[A.U.]')
p.drawROOT()

