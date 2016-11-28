
import copy
from ROOT import *
import Jawa

from PlotTools import *
from Style import SetLHCbStyle

SetLHCbStyle()

f = TFile.Open("root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/Jpsi.2015.root")
t = f.Get("JpsiTuple/DecayTree")

#mass = TCut("Z0_M > 60000 && Z0_M < 120000")
eta  = TCut("min(muplus_ETA, muminus_ETA) > 2.0 && max(muplus_ETA, muminus_ETA) < 4.5")
pt   = TCut("min(muplus_PT, muminus_PT) > 20000")
trk  = TCut("muplus_TRACK_PCHI2 > 0.01 && muminus_TRACK_PCHI2 > 0.01 && sqrt(muplus_PERR2)/muplus_P < 0.1 && sqrt(muminus_PERR2)/muminus_P < 0.1")

selcut = eta

#trigger_plus   = TCut("muplus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muplus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muplus_L0MuonEWDecision_TOS ==1")
#trigger_minus = TCut("muminus_Hlt2EWSingleMuonVHighPtDecision_TOS==1 && muminus_Hlt1SingleMuonHighPTDecision_TOS == 1 && muminus_L0MuonEWDecision_TOS ==1")

ybins = [2.0 + 0.125*i for i in range(17)] + [ 4.25, 4.50 ]

#trigger_dimuon = TCut("("+trigger_plus.GetTitle() + ") || (" + trigger_minus.GetTitle() + ")")

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

jpsi_minus = Jawa.Template("jpsi_minus")
jpsi_minus.SetSelCut(selcut)
jpsi_minus.AddTree(t)
jpsi_minus.AddVars(vars)
jpsi_minus.MaxEvts = 250000
jpsi_minus.Run()
jpsi_minus.SaveToFile()

jpsi_plus = Jawa.Template("jpsi_plus")
jpsi_plus.SetSelCut(selcut)
jpsi_plus.AddTree(t)
jpsi_plus.AddVars(plusvars)
jpsi_plus.MaxEvts = 250000
jpsi_plus.Run()
jpsi_plus.SaveToFile()

jpsi_combined = Jawa.Template("jpsi_combined", jpsi_plus, jpsi_minus)
jpsi_combined.SaveToFile()



jpsi = Jawa.Template("jpsi")
jpsi.SetSelCut(selcut)
jpsi.AddTree(t)
jpsi.AddVars([["M", "J_psi_1S_M", 100, 3000, 3200],
              ["M_Refit", "J_psi_1S_Refit_M", 100, 3000, 3200]]
             )
jpsi.MaxEvts = 250000
jpsi.Run()
jpsi.SaveToFile()

p = Plot([jpsi_combined.GetVar('CHI2').GetHist(), jpsi_combined.GetVar('CHI2_refit').GetHist()])
p.setProp('filename', 'jpsi_chi2_refit')
p.setProp('location', '/user2/sfarry/momentumscale/figures')
p.setProp('ynormlims', [0.0,0.1])
p.setProp('normalised', True)
p.setProp('colors', ['red', 'blue', 8, ROOT.kYellow-3])
p.setProp('markerstyles', 20)
p.setProp('labels', ['J/#psi#rightarrow#mu#mu', 'J/#psi#rightarrow#mu#mu (Refit)'])
p.setProp('xlabel', '#chi^2/ndof.')
p.setProp('leglims', [0.5, 0.7, 0.95, 0.9])
p.setProp('ynormlabel', '[A.U.]')
p.drawROOT()

p = Plot([jpsi.GetVar('M').GetHist(), jpsi.GetVar('M_Refit').GetHist()])
p.setProp('filename', 'jpsi_m_refit')
p.setProp('location', '/user2/sfarry/momentumscale/figures')
p.setProp('ynormlims', [0.0,0.1])
p.setProp('normalised', False)
p.setProp('colors', ['red', 'blue'])
p.setProp('markerstyles', 20)
p.setProp('labels', ['J/#psi#rightarrow#mu#mu', 'J/#psi#rightarrow#mu#mu (Refit)'])
p.setProp('xlabel', '#chi^2/ndof.')
p.setProp('leglims', [0.6, 0.7, 0.95, 0.9])
p.drawROOT()

