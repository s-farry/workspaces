from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig_new import *

qcd_bal_plus = Template("qcdbal_plus_data2012", wmuj.trees(), selcut_base + ip + antimumjpt + plus)
qcd_bal_plus.AddVars(variables)
qcd_bal_plus.AddVars(jetvars)
qcd_bal_plus.Add2DVars(vars2d)
qcd_bal_plus.Run()
qcd_bal_plus.SaveToFile()

qcd_bal_minus = Template("qcdbal_minus_data2012")
qcd_bal_minus.SetSelCut(selcut_base + ip + antimumjpt + minus)
qcd_bal_minus.AddTree(wmuj.MUt)
qcd_bal_minus.AddTree(wmuj.MDt)
qcd_bal_minus.AddVars(variables)
qcd_bal_minus.AddVars(jetvars)
qcd_bal_minus.Add2DVars(vars2d)
qcd_bal_minus.Run()
qcd_bal_minus.SaveToFile()

qcd_bal = Template("qcdbal_data2012", qcd_bal_plus, qcd_bal_minus)
qcd_bal.SaveToFile()

qcd_hiip_plus = Template("qcd_hiip_plus_data2012")
qcd_hiip_plus.SetSelCut(selcut_base + hi_ip + plus)
qcd_hiip_plus.AddTree(wmuj.MUt)
qcd_hiip_plus.AddTree(wmuj.MDt)
qcd_hiip_plus.AddVars(variables)
qcd_hiip_plus.AddVars(jetvars)
qcd_hiip_plus.Add2DVars(vars2d)
qcd_hiip_plus.Run()
qcd_hiip_plus.SaveToFile()

qcd_hiip_minus = Template("qcd_hiip_minus_data2012")
qcd_hiip_minus.SetSelCut(selcut_base + hi_ip + minus)
qcd_hiip_minus.AddTree(wmuj.MUt)
qcd_hiip_minus.AddTree(wmuj.MDt)
qcd_hiip_minus.AddVars(variables)
qcd_hiip_minus.AddVars(jetvars)
qcd_hiip_minus.Add2DVars(vars2d)
qcd_hiip_minus.ApplyCut()
qcd_hiip_minus.FillVars()
qcd_hiip_minus.SaveToFile()

qcd_hiip = Template("qcd_hiip_data2012", qcd_hiip_plus, qcd_hiip_minus)
qcd_hiip.SaveToFile()

qcd_antiiso_plus = Template("qcd_antiiso_plus_data2012")
qcd_antiiso_plus.SetSelCut(selcut_base + antijetiso + mumjpt + plus)
qcd_antiiso_plus.AddTree(wmuj.MUt)
qcd_antiiso_plus.AddTree(wmuj.MDt)
qcd_antiiso_plus.AddVars(variables)
qcd_antiiso_plus.AddVars(jetvars)
qcd_antiiso_plus.Add2DVars(vars2d)
qcd_antiiso_plus.ApplyCut()
qcd_antiiso_plus.FillVars()
qcd_antiiso_plus.SaveToFile()

qcd_antiiso_minus = Template("qcd_antiiso_minus_data2012")
qcd_antiiso_minus.SetSelCut(selcut_base + antijetiso + mumjpt + minus)
qcd_antiiso_minus.AddTree(wmuj.MUt)
qcd_antiiso_minus.AddTree(wmuj.MDt)
qcd_antiiso_minus.AddVars(variables)
qcd_antiiso_minus.AddVars(jetvars)
qcd_antiiso_minus.Add2DVars(vars2d)
qcd_antiiso_minus.ApplyCut()
qcd_antiiso_minus.FillVars()
qcd_antiiso_minus.SaveToFile()

qcd_antiiso = Template("qcd_antiiso_data2012", qcd_antiiso_plus, qcd_antiiso_minus)
qcd_antiiso.SaveToFile()



#1 dimensional reweights

qcd_ptcorr_hiip           = GetWeightHist("qcd_ptcorr_hiip",          qcd_hiip.GetVar("PT").GetHist()         , qcd_bal.GetVar("PT").GetHist()      )
qcd_ptcorr_hiip_plus      = GetWeightHist("qcd_ptcorr_hiip_plus",     qcd_hiip_plus.GetVar("PT").GetHist()    , qcd_bal_plus.GetVar("PT").GetHist() )
qcd_ptcorr_hiip_minus     = GetWeightHist("qcd_ptcorr_hiip_minus",    qcd_hiip_minus.GetVar("PT").GetHist()   , qcd_bal_minus.GetVar("PT").GetHist())
qcd_ptmujcorr_antiiso        = GetWeightHist("qcd_ptmujcorr_antiiso",       qcd_antiiso.GetVar("MuJet_PT").GetHist()      , qcd_bal.GetVar("MuJet_PT").GetHist()      )
qcd_ptmujcorr_antiiso_plus   = GetWeightHist("qcd_ptmujcorr_antiiso_plus",  qcd_antiiso_plus.GetVar("MuJet_PT").GetHist() , qcd_bal_plus.GetVar("MuJet_PT").GetHist() )
qcd_ptmujcorr_antiiso_minus  = GetWeightHist("qcd_ptmujcorr_antiiso_minus", qcd_antiiso_minus.GetVar("MuJet_PT").GetHist(), qcd_bal_minus.GetVar("MuJet_PT").GetHist())

ptjrw       = []
ptjrw_plus  = []
ptjrw_minus = []


for i in range(qcd_bal.Get2DVar("Jet_PT", "MuJet_PT").GetHist().GetXaxis().GetNbins()):
    ptjrw += [GetWeightHist("qcd_mujptcorr_antiiso_ptj"+str(i), 
                            qcd_antiiso.Get2DVar("Jet_PT", "MuJet_PT").GetHist().ProjectionY("ptj"+str(i), i+1, i+1),
                            qcd_bal.GetVar("MuJet_PT").GetHist())]
    ptjrw_plus += [GetWeightHist("qcd_mujptcorr_antiiso_plus_ptj"+str(i), 
                            qcd_antiiso_plus.Get2DVar("Jet_PT", "MuJet_PT").GetHist().ProjectionY("ptj"+str(i), i+1, i+1),
                            qcd_bal_plus.GetVar("MuJet_PT").GetHist())]
    ptjrw_minus += [GetWeightHist("qcd_mujptcorr_antiiso_minus_ptj"+str(i), 
                            qcd_antiiso_minus.Get2DVar("Jet_PT", "MuJet_PT").GetHist().ProjectionY("ptj"+str(i), i+1, i+1),
                            qcd_bal_minus.GetVar("MuJet_PT").GetHist())]
#2 dimensional reweights

qcd_etaptcorr_hiip        = GetWeightHist2D("qcd_etaptcorr_hiip", qcd_hiip.Get2DVar("ETA","PT").GetHist(), qcd_bal.Get2DVar("ETA", "PT").GetHist())
qcd_etaptcorr_hiip_plus   = GetWeightHist2D("qcd_etaptcorr_hiip_plus", qcd_hiip_plus.Get2DVar("ETA","PT").GetHist(), qcd_bal_plus.Get2DVar("ETA", "PT").GetHist())
qcd_etaptcorr_hiip_minus   = GetWeightHist2D("qcd_etaptcorr_hiip_minus", qcd_hiip_minus.Get2DVar("ETA","PT").GetHist(), qcd_bal_minus.Get2DVar("ETA", "PT").GetHist())

qcd_etaptmujcorr_antiiso        = GetWeightHist2D("qcd_etaptmujcorr_antiiso"  ,  qcd_antiiso.Get2DVar("ETA","MuJet_PT").GetHist() , qcd_bal.Get2DVar("ETA", "MuJet_PT").GetHist())
qcd_etaptmujcorr_antiiso_plus   = GetWeightHist2D("qcd_etaptmujcorr_sig_plus",  qcd_antiiso_plus.Get2DVar("ETA","MuJet_PT").GetHist(),  qcd_bal_plus.Get2DVar("ETA", "MuJet_PT").GetHist())
qcd_etaptmujcorr_antiiso_minus  = GetWeightHist2D("qcd_etaptmujcorr_sig_minus", qcd_antiiso_minus.Get2DVar("ETA","MuJet_PT").GetHist(), qcd_bal_minus.Get2DVar("ETA", "MuJet_PT").GetHist())

'''
qcd_etajcorr_hiip        = GetWeightHist2D("qcd_etajcorr_hiip", qcd_hiip.Get2DVar("Jet_ETA","PT").GetHist(), qcd_bal.Get2DVar("Jet_ETA", "PT").GetHist())
qcd_etajcorr_hiip_plus   = GetWeightHist2D("qcd_etajcorr_hiip_plus", qcd_hiip_plus.Get2DVar("Jet_ETA","PT").GetHist(), qcd_bal_plus.Get2DVar("Jet_ETA", "PT").GetHist())
qcd_etajcorr_hiip_minus   = GetWeightHist2D("qcd_etajcorr_hiip_minus", qcd_hiip_minus.Get2DVar("Jet_ETA","PT").GetHist(), qcd_bal_minus.Get2DVar("Jet_ETA", "PT").GetHist())

#qcd_etajcorr_antiiso         = GetWeightHist2D("qcd_etajcorr_antiiso", qcd_antiiso.Get2DVar("Jet_ETA","PT").GetHist(), qcd_bal.Get2DVar("Jet_ETA", "PT").GetHist())
#qcd_etajcorr_antiiso_plus    = GetWeightHist2D("qcd_etajcorr_antiiso_plus", qcd_antiiso_plus.Get2DVar("Jet_ETA","PT").GetHist(), qcd_bal_plus.Get2DVar("Jet_ETA", "PT").GetHist())
#qcd_etajcorr_antiiso_minus   = GetWeightHist2D("qcd_etajcorr_antiiso_minus", qcd_antiiso_minus.Get2DVar("Jet_ETA","PT").GetHist(), qcd_bal_minus.Get2DVar("Jet_ETA", "PT").GetHist())

qcd_ptjcorr_hiip         = GetWeightHist2D("qcd_ptjcorr_hiip", qcd_hiip.Get2DVar("Jet_PT","PT").GetHist(), qcd_bal.Get2DVar("Jet_PT", "PT").GetHist())
qcd_ptjcorr_hiip_plus    = GetWeightHist2D("qcd_ptjcorr_hiip_plus", qcd_hiip_plus.Get2DVar("Jet_PT","PT").GetHist(), qcd_bal_plus.Get2DVar("Jet_PT", "PT").GetHist())
qcd_ptjcorr_hiip_minus   = GetWeightHist2D("qcd_ptjcorr_hiip_minus", qcd_hiip_minus.Get2DVar("Jet_PT","PT").GetHist(), qcd_bal_minus.Get2DVar("Jet_PT", "PT").GetHist())

#qcd_ptjcorr_antiiso         = GetWeightHist2D("qcd_ptjcorr_antiiso", qcd_antiiso.Get2DVar("Jet_PT","PT").GetHist(), qcd_bal.Get2DVar("Jet_PT", "PT").GetHist())
#qcd_ptjcorr_antiiso_plus    = GetWeightHist2D("qcd_ptjcorr_antiiso_plus", qcd_antiiso_plus.Get2DVar("Jet_PT","PT").GetHist(), qcd_bal_plus.Get2DVar("Jet_PT", "PT").GetHist())
#qcd_ptjcorr_antiiso_minus   = GetWeightHist2D("qcd_ptjcorr_antiiso_minus", qcd_antiiso_minus.Get2DVar("Jet_PT","PT").GetHist(), qcd_bal_minus.Get2DVar("Jet_PT", "PT").GetHist())

qcd_ptjcorr_sig         = GetWeightHist2D("qcd_ptjcorr_sig", qcd_sig.Get2DVar("Jet_PT","MuJet_PT").GetHist(), qcd_bal.Get2DVar("Jet_PT", "MuJet_PT").GetHist())
qcd_ptjcorr_sig_plus    = GetWeightHist2D("qcd_ptjcorr_sig_plus", qcd_sig_plus.Get2DVar("Jet_PT","MuJet_PT").GetHist(), qcd_bal_plus.Get2DVar("Jet_PT", "MuJet_PT").GetHist())
qcd_ptjcorr_sig_minus   = GetWeightHist2D("qcd_ptjcorr_sig_minus", qcd_sig_minus.Get2DVar("Jet_PT","MuJet_PT").GetHist(), qcd_bal_minus.Get2DVar("Jet_PT", "MuJet_PT").GetHist())

#qcd_etajcorr_sig         = GetWeightHist2D("qcd_etajcorr_sig", qcd_sig.Get2DVar("Jet_ETA","MuJet_PT").GetHist(), qcd_bal.Get2DVar("Jet_ETA", "MuJet_PT").GetHist())
#qcd_etajcorr_sig_plus    = GetWeightHist2D("qcd_etajcorr_sig_plus", qcd_sig_plus.Get2DVar("Jet_ETA","MuJet_PT").GetHist(), qcd_bal_plus.Get2DVar("Jet_ETA", "MuJet_PT").GetHist())
#qcd_etajcorr_sig_minus  = GetWeightHist2D("qcd_etajcorr_sig_minus", qcd_sig_minus.Get2DVar("Jet_ETA","MuJet_PT").GetHist(), qcd_bal_minus.Get2DVar("Jet_ETA", "MuJet_PT").GetHist())



qcd_etacorr_hiip        = GetWeightHist2D("qcd_etacorr_hiip", qcd_hiip.Get2DVar("ETA","PT").GetHist(), qcd_bal.Get2DVar("ETA", "PT").GetHist())
qcd_etacorr_hiip_plus   = GetWeightHist2D("qcd_etacorr_hiip_plus", qcd_hiip_plus.Get2DVar("ETA","PT").GetHist(), qcd_bal_plus.Get2DVar("ETA", "PT").GetHist())
qcd_etacorr_hiip_minus   = GetWeightHist2D("qcd_etacorr_hiip_minus", qcd_hiip_minus.Get2DVar("ETA","PT").GetHist(), qcd_bal_minus.Get2DVar("ETA", "PT").GetHist())

#qcd_etacorr_antiiso        = GetWeightHist2D("qcd_etacorr_antiiso", qcd_antiiso.Get2DVar("ETA","PT").GetHist(), qcd_bal.Get2DVar("ETA", "PT").GetHist())
#qcd_etacorr_antiiso_plus   = GetWeightHist2D("qcd_etacorr_antiiso_plus", qcd_antiiso_plus.Get2DVar("ETA","PT").GetHist(), qcd_bal_plus.Get2DVar("ETA", "PT").GetHist())
#qcd_etacorr_antiiso_minus   = GetWeightHist2D("qcd_etacorr_antiiso_minus", qcd_antiiso_minus.Get2DVar("ETA","PT").GetHist(), qcd_bal_minus.Get2DVar("ETA", "PT").GetHist())


qcd_corr_jetiso           = GetWeightHist("qcd_corr_jetiso",          qcd_hiip.GetVar("PT").GetHist()         , qcd_bal.GetVar("PT").GetHist()      )
qcd_corr_jetiso_plus      = GetWeightHist("qcd_corr_jetiso_plus",     qcd_hiip_plus.GetVar("PT").GetHist()    , qcd_bal_plus.GetVar("PT").GetHist() )
qcd_corr_jetiso_minus     = GetWeightHist("qcd_corr_jetiso_minus",    qcd_hiip_minus.GetVar("PT").GetHist()   , qcd_bal_minus.GetVar("PT").GetHist())

qcd_etajcorr_jetiso        = GetWeightHist2D("qcd_etajcorr_jetiso", qcd_hiip.Get2DVar("Jet_ETA","JetIso").GetHist(), qcd_bal.Get2DVar("Jet_ETA", "JetIso").GetHist())
qcd_etajcorr_jetiso_plus   = GetWeightHist2D("qcd_etajcorr_jetiso_plus", qcd_hiip_plus.Get2DVar("Jet_ETA","JetIso").GetHist(), qcd_bal_plus.Get2DVar("Jet_ETA", "JetIso").GetHist())
qcd_etajcorr_jetiso_minus  = GetWeightHist2D("qcd_etajcorr_jetiso_minus", qcd_hiip_minus.Get2DVar("Jet_ETA","JetIso").GetHist(), qcd_bal_minus.Get2DVar("Jet_ETA", "JetIso").GetHist())

qcd_ptjcorr_jetiso         = GetWeightHist2D("qcd_ptjcorr_jetiso", qcd_hiip.Get2DVar("Jet_PT","JetIso").GetHist(), qcd_bal.Get2DVar("Jet_PT", "JetIso").GetHist())
qcd_ptjcorr_jetiso_plus    = GetWeightHist2D("qcd_ptjcorr_jetiso_plus", qcd_hiip_plus.Get2DVar("Jet_PT","JetIso").GetHist(), qcd_bal_plus.Get2DVar("Jet_PT", "JetIso").GetHist())
qcd_ptjcorr_jetiso_minus   = GetWeightHist2D("qcd_ptjcorr_jetiso_minus", qcd_hiip_minus.Get2DVar("Jet_PT","JetIso").GetHist(), qcd_bal_minus.Get2DVar("Jet_PT", "JetIso").GetHist())

qcd_ptjcorr_sig         = GetWeightHist2D("qcd_ptjcorr_sig", qcd_sig.Get2DVar("Jet_PT","MuJet_PT").GetHist(), qcd_bal.Get2DVar("Jet_PT", "MuJet_PT").GetHist())
qcd_ptjcorr_sig_plus    = GetWeightHist2D("qcd_ptjcorr_sig_plus", qcd_sig_plus.Get2DVar("Jet_PT","MuJet_PT").GetHist(), qcd_bal_plus.Get2DVar("Jet_PT", "MuJet_PT").GetHist())
qcd_ptjcorr_sig_minus   = GetWeightHist2D("qcd_ptjcorr_sig_minus", qcd_sig_minus.Get2DVar("Jet_PT","MuJet_PT").GetHist(), qcd_bal_minus.Get2DVar("Jet_PT", "MuJet_PT").GetHist())


qcd_etacorr_jetiso         = GetWeightHist2D("qcd_etacorr_jetiso", qcd_hiip.Get2DVar("ETA","JetIso").GetHist(), qcd_bal.Get2DVar("ETA", "JetIso").GetHist())
qcd_etacorr_jetiso_plus    = GetWeightHist2D("qcd_etacorr_jetiso_plus", qcd_hiip_plus.Get2DVar("ETA","JetIso").GetHist(), qcd_bal_plus.Get2DVar("ETA", "JetIso").GetHist())
qcd_etacorr_jetiso_minus   = GetWeightHist2D("qcd_etacorr_jetiso_minus", qcd_hiip_minus.Get2DVar("ETA","JetIso").GetHist(), qcd_bal_minus.Get2DVar("ETA", "JetIso").GetHist())


#corrections only meaningful at large values
#for i in range(jetiso_corr.GetXaxis().FindBin(0.8) + 1):
#    jetiso_corr.SetBinContent(i, 1.0)
'''
outputF = TFile("qcd_corr.root", "RECREATE")
qcd_ptcorr_hiip.Write("qcd_ptcorr_hiip")
qcd_ptcorr_hiip_plus.Write("qcd_ptcorr_hiip_plus")
qcd_ptcorr_hiip_minus.Write("qcd_ptcorr_hiip_minus")
qcd_ptmujcorr_antiiso.Write("qcd_ptmujcorr_antiiso")
qcd_ptmujcorr_antiiso_plus.Write("qcd_ptmujcorr_antiiso_plus")
qcd_ptmujcorr_antiiso_minus.Write("qcd_ptmujcorr_antiiso_minus")


for i in range(qcd_bal.GetVar("Jet_PT").GetHist().GetXaxis().GetNbins()):
    ptjrw[i].Write("qcd_mujptcorr_antiiso_ptj"+str(i))
    ptjrw_plus[i].Write("qcd_mujptcorr_antiiso_plus_ptj"+str(i))
    ptjrw_minus[i].Write("qcd_mujptcorr_antiiso_minus_ptj"+str(i))

#qcd_corr_sig.Write("qcd_corr_sig")
#qcd_corr_sig_plus.Write("qcd_corr_sig_plus")
#qcd_corr_sig_minus.Write("qcd_corr_sig_minus")
#qcd_corr_antiep.Write("qcd_corr_antiep")
#qcd_corr_antiep_plus.Write("qcd_corr_antiep_plus")
#qcd_corr_antiep_minus.Write("qcd_corr_antiep_minus")
qcd_etaptcorr_hiip.Write("qcd_ptetacorr_hiip")
qcd_etaptcorr_hiip_plus.Write("qcd_ptetacorr_hiip_plus")
qcd_etaptcorr_hiip_minus.Write("qcd_ptetacorr_hiip_minus")
#qcd_etacorr_antiiso.Write("qcd_etacorr_antiiso")
#qcd_etacorr_antiiso_plus.Write("qcd_etacorr_antiiso_plus")
#qcd_etacorr_antiiso_minus.Write("qcd_etacorr_antiiso_minus")
#qcd_etacorr_antiep.Write("qcd_etacorr_antiep")
#qcd_etacorr_antiep_plus.Write("qcd_etacorr_antiep_plus")
#qcd_etacorr_antiep_minus.Write("qcd_etacorr_antiep_minus")
#qcd_etajcorr_hiip.Write("qcd_etajcorr_hiip")
#qcd_etajcorr_hiip_plus.Write("qcd_etajcorr_hiip_plus")
#qcd_etajcorr_hiip_minus.Write("qcd_etajcorr_hiip_minus")
#qcd_etajcorr_antiiso.Write("qcd_etajcorr_antiiso")
#qcd_etajcorr_antiiso_plus.Write("qcd_etajcorr_antiiso_plus")
#qcd_etajcorr_antiiso_minus.Write("qcd_etajcorr_antiiso_minus")
#qcd_etajcorr_sig.Write("qcd_etajcorr_sig")
#qcd_etajcorr_sig_plus.Write("qcd_etajcorr_sig_plus")
#qcd_etajcorr_sig_minus.Write("qcd_etajcorr_sig_minus")
#qcd_etacorr_sig.Write("qcd_etacorr_sig")
#qcd_etacorr_sig_plus.Write("qcd_etacorr_sig_plus")
#qcd_etacorr_sig_minus.Write("qcd_etacorr_sig_minus")
qcd_etaptmujcorr_antiiso.Write("qcd_etaptmujptcorr_antiiso")
qcd_etaptmujcorr_antiiso_plus.Write("qcd_etaptmujcorr_antiiso_plus")
qcd_etaptmujcorr_antiiso_minus.Write("qcd_etaptmujcorr_antiiso_minus")
#qcd_ptjcorr_antiiso.Write("qcd_ptjcorr_antiiso")
#qcd_ptjcorr_antiiso_plus.Write("qcd_ptjcorr_antiiso_plus")
#qcd_ptjcorr_antiiso_minus.Write("qcd_ptjcorr_antiiso_minus")
#qcd_ptjcorr_sig.Write("qcd_ptjcorr_sig")
#qcd_ptjcorr_sig_plus.Write("qcd_ptjcorr_sig_plus")
#qcd_ptjcorr_sig_minus.Write("qcd_ptjcorr_sig_minus")

#qcd_corr_jetiso.Write("qcd_corr_jetiso")
#qcd_corr_jetiso_plus.Write("qcd_corr_jetiso_plus")
#qcd_corr_jetiso_minus.Write("qcd_corr_jetiso_minus")
#qcd_etacorr_jetiso.Write("qcd_etacorr_jetiso")
#qcd_etacorr_jetiso_plus.Write("qcd_etacorr_jetiso_plus")
#qcd_etacorr_jetiso_minus.Write("qcd_etacorr_jetiso_minus")
#qcd_etajcorr_jetiso.Write("qcd_etajcorr_jetiso")
#qcd_etajcorr_jetiso_plus.Write("qcd_etajcorr_jetiso_plus")
#qcd_etajcorr_jetiso_minus.Write("qcd_etajcorr_jetiso_minus")
#qcd_ptjcorr_jetiso.Write("qcd_ptjcorr_jetiso")
#qcd_ptjcorr_jetiso_plus.Write("qcd_ptjcorr_jetiso_plus")
#qcd_ptjcorr_jetiso_minus.Write("qcd_ptjcorr_jetiso_minus")
outputF.Close()

'''
qcd_bal_hiipcorr = Template("qcdbal_hiipcorr_data2012")
qcd_bal_hiipcorr.AddTree(wmuj.MUt)
qcd_bal_hiipcorr.AddTree(wmuj.MDt)
qcd_bal_hiipcorr.SetSelCut(selcut + antimumjpt)
qcd_bal_hiipcorr.AddVars(variables)
qcd_bal_hiipcorr.AddVars(jetvars)
qcd_bal_hiipcorr.Add2DVars(vars2d)
qcd_bal_hiipcorr.Reweight("muminus_PT", qcd_corr_hiip)
qcd_bal_hiipcorr.ApplyCut()
qcd_bal_hiipcorr.FillVars()
qcd_bal_hiipcorr.SaveToFile()

qcd_bal_antiisocorr = Template("qcdbal_antiisocorr_data2012")
qcd_bal_antiisocorr.AddTree(wmuj.MUt)
qcd_bal_antiisocorr.AddTree(wmuj.MDt)
qcd_bal_antiisocorr.SetSelCut(selcut + antimumjpt)
qcd_bal_antiisocorr.AddVars(variables)
qcd_bal_antiisocorr.AddVars(jetvars)
qcd_bal_antiisocorr.Add2DVars(vars2d)
qcd_bal_antiisocorr.Reweight("muminus_PT", qcd_corr_antiiso)
qcd_bal_antiisocorr.ApplyCut()
qcd_bal_antiisocorr.FillVars()
qcd_bal_antiisocorr.SaveToFile()

qcd_bal_antiisocorr_eta = Template("qcdbal_antiisocorr_eta_data2012")
qcd_bal_antiisocorr_eta.AddTree(wmuj.MUt)
qcd_bal_antiisocorr_eta.AddTree(wmuj.MDt)
qcd_bal_antiisocorr_eta.SetSelCut(selcut + antimumjpt)
qcd_bal_antiisocorr_eta.AddVars(variables)
qcd_bal_antiisocorr_eta.AddVars(jetvars)
qcd_bal_antiisocorr_eta.Add2DVars(vars2d)
qcd_bal_antiisocorr_eta.Reweight("muminus_ETA", "muminus_PT", qcd_etacorr_antiiso)
qcd_bal_antiisocorr_eta.ApplyCut()
qcd_bal_antiisocorr_eta.FillVars()
qcd_bal_antiisocorr_eta.SaveToFile()
'''

qcd_bal_plus = Template("qcdbal_plus_data2012_rw", wmuj.trees(), selcut_base + ip + antimumjpt + plus)
qcd_bal_plus.AddVars(variables)
qcd_bal_plus.AddVars(jetvars)
qcd_bal_plus.Add2DVars(vars2d)
qcd_bal_plus.Reweight("muminus_ETA", "muminus_sigjet_PT", qcd_etaptmujcorr_antiiso_plus)
qcd_bal_plus.Run()
qcd_bal_plus.SaveToFile()

qcd_bal_minus = Template("qcdbal_minus_data2012_rw")
qcd_bal_minus.SetSelCut(selcut_base + ip + antimumjpt + minus)
qcd_bal_minus.AddTree(wmuj.MUt)
qcd_bal_minus.AddTree(wmuj.MDt)
qcd_bal_minus.Reweight("muminus_ETA", "muminus_sigjet_PT", qcd_etaptmujcorr_antiiso_minus)
qcd_bal_minus.AddVars(variables)
qcd_bal_minus.AddVars(jetvars)
qcd_bal_minus.Add2DVars(vars2d)
qcd_bal_minus.Run()
qcd_bal_minus.SaveToFile()

qcd_bal = Template("qcdbal_data2012_rw", qcd_bal_plus, qcd_bal_minus)
qcd_bal.SaveToFile()
