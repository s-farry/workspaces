from os import sys
import copy
from Jawa import *
from ROOT import TCut, TTree, TFile, TMath, TH1F, TF1, TH1, TParameter
from Utils import GetWeightHist, GetSpreadGraph, GetPDFGraph, asymm_details, ratio_details, details, Bunch
from math import sqrt

def getpdfuncertainty(central, pdfsets):
    sumsq = 0
    for pdf in pdfsets:
        sumsq = sumsq + pow(central - pdf,2)
    return sqrt(sumsq / (len(pdfsets) - 1))



TH1.AddDirectory(False)
dpm = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/"

ptmuj = "sqrt((<mu>_px + <jet>_px)^2 + (<mu>_py + <jet>_py)^2)"

vars = [
    Bunch(name="mu_pt"   , var = "<mu>_pt"       , bins = 8  , lo = 20 , hi = 100 ),
    Bunch(name="mu_eta" , var = "abs(<mu>_eta)" , edges = [2.0, 2.5, 3.0, 3.5, 4.5]), 
    Bunch(name="etaj"     , var = "<jet>_eta"      , edges = [2.2, 2.7, 3.2, 3.7, 4.2]),
    Bunch(name="ptj"     , var = "<jet>_pt"       , bins = 5, lo = 20, hi = 220),
    Bunch(name="ptmuj"  , var = ptmuj ,    bins = 4, lo = 20, hi = 100.0)
    ]

pltvars = ['ptj', 'eta', 'yj', 'etaj']

lhcb_plus_fwd = TCut("mup_eta > 2.0  && mup_eta < 4.5")
lhcb_plus_bwd = TCut("mup_eta < -2.0 && mup_eta > -4.5")

lhcb_minus_fwd = TCut("mum_eta > 2.0  && mum_eta < 4.5")
lhcb_minus_bwd = TCut("mum_eta < -2.0 && mum_eta > -4.5")

pt20_plus   = TCut("mup_pt > 20")
pt20_minus  = TCut("mum_pt > 20")

fwdjet_btag = TCut("abs(fwdjet_flav) == 5")
bwdjet_btag = TCut("abs(bwdjet_flav) == 5")

fwdjetpt10 = TCut("fwdjet_pt > 10")
fwdjetpt20 = TCut("fwdjet_pt > 20")

bwdjetpt10 = TCut("bwdjet_pt > 10")
bwdjetpt20 = TCut("bwdjet_pt > 20")

bwdjet20_plus = pt20_plus + lhcb_plus_bwd + bwdjetpt20 + bwdjet_btag
fwdjet20_plus = pt20_plus + lhcb_plus_fwd + fwdjetpt20 + fwdjet_btag

bwdjet20_minus = pt20_minus + lhcb_minus_bwd + bwdjetpt20 + bwdjet_btag
fwdjet20_minus = pt20_minus + lhcb_minus_fwd + fwdjetpt20 + fwdjet_btag

bwdjet20_nobtag_plus = pt20_plus + lhcb_plus_bwd + bwdjetpt20
fwdjet20_nobtag_plus = pt20_plus + lhcb_plus_fwd + fwdjetpt20

bwdjet20_nobtag_minus = pt20_minus + lhcb_minus_bwd + bwdjetpt20
fwdjet20_nobtag_minus = pt20_minus + lhcb_minus_fwd + fwdjetpt20

ttf   = TFile.Open("/hepstore/sfarry/aMC@NLO/ttbar/Events/ttbar_mumu.root")
t     = ttf.Get("ttbar")

N = ttf.Get('totEvts').GetVal()
#N = t.GetEntries()

sf = 0.5/N

relaunch = True

top_fiducial = TCut("abs(t_y) > 2.0 && abs(t_y) < 5.0 && abs(tbar_y) > 2.0 && abs(tbar_y) < 5.0 && t_y*tbar_y > 0 && t_pt > 10.0 && tbar_pt > 10.0")

top_fiducial_fwd = TCut("t_y > 2.0 && t_y < 5.0 && tbar_y > 2.0 && tbar_y < 5.0 && t_pt > 10.0 && tbar_pt > 10.0")

ttbar_plus_out          = {}
ttbar_minus_out         = {}

if relaunch:
    ttbar_fwd_plus = MWTemplate("ttbar_fwd_plus", t, fwdjet20_plus)
    for v in vars:
        var = v.var.replace('<jet>', 'fwdjet').replace('<mu>', 'mup')
        if hasattr(v, 'edges'):
            ttbar_fwd_plus.AddVar(v.name, var, v.edges)
        else:
            ttbar_fwd_plus.AddVar(v.name, var, v.bins, v.lo, v.hi)
    ttbar_fwd_plus.ApplyCut()
    ttbar_fwd_plus.AddWeight("Central","w1010")
    ttbar_fwd_plus.AddWeight("Scale1", "w1002")
    ttbar_fwd_plus.AddWeight("Scale2", "w1003")
    ttbar_fwd_plus.AddWeight("Scale3", "w1004")
    ttbar_fwd_plus.AddWeight("Scale4", "w1005")
    ttbar_fwd_plus.AddWeight("Scale5", "w1007")
    ttbar_fwd_plus.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_fwd_plus.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_fwd_plus.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_fwd_plus.AddWeight("alphas_117", "w1111")
    ttbar_fwd_plus.AddWeight("alphas_119", "w1112")
    ttbar_fwd_plus.FillVars()
    ttbar_fwd_plus.Scale(sf)
    ttbar_fwd_plus.ScaleAllWeights(sf)
    ttbar_fwd_plus.SaveToFile()

    ttbar_fwd_minus = MWTemplate("ttbar_fwd_minus", t, fwdjet20_minus)
    for v in vars:
        var = v.var.replace('<jet>', 'fwdjet').replace('<mu>', 'mum')
        if hasattr(v, 'edges'):
            ttbar_fwd_minus.AddVar(v.name, var, v.edges)
        else:
            ttbar_fwd_minus.AddVar(v.name, var, v.bins, v.lo, v.hi)
    # ttbar_fwd_minus.Add2DVars(vars2d)
    ttbar_fwd_minus.ApplyCut()
    ttbar_fwd_minus.AddWeight("Central","w1010")
    ttbar_fwd_minus.AddWeight("Scale1", "w1002")
    ttbar_fwd_minus.AddWeight("Scale2", "w1003")
    ttbar_fwd_minus.AddWeight("Scale3", "w1004")
    ttbar_fwd_minus.AddWeight("Scale4", "w1005")
    ttbar_fwd_minus.AddWeight("Scale5", "w1007")
    ttbar_fwd_minus.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_fwd_minus.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_fwd_minus.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_fwd_minus.AddWeight("alphas_117", "w1111")
    ttbar_fwd_minus.AddWeight("alphas_119", "w1112")
    ttbar_fwd_minus.FillVars()
    ttbar_fwd_minus.Scale(sf)
    ttbar_fwd_minus.ScaleAllWeights(sf)
    ttbar_fwd_minus.SaveToFile()


    ttbar_bwd_plus = MWTemplate("ttbar_bwd_plus", t, bwdjet20_plus)
    for v in vars:
        var = v.var.replace('<jet>', 'bwdjet').replace('<mu>', 'mup')
        if hasattr(v, 'edges'):
            ttbar_bwd_plus.AddVar(v.name, var, v.edges)
        else:
            ttbar_bwd_plus.AddVar(v.name, var, v.bins, v.lo, v.hi)
    ttbar_bwd_plus.ApplyCut()
    ttbar_bwd_plus.AddWeight("Central","w1010")
    ttbar_bwd_plus.AddWeight("Scale1", "w1002")
    ttbar_bwd_plus.AddWeight("Scale2", "w1003")
    ttbar_bwd_plus.AddWeight("Scale3", "w1004")
    ttbar_bwd_plus.AddWeight("Scale4", "w1005")
    ttbar_bwd_plus.AddWeight("Scale5", "w1007")
    ttbar_bwd_plus.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_bwd_plus.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_bwd_plus.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_bwd_plus.AddWeight("alphas_117", "w1111")
    ttbar_bwd_plus.AddWeight("alphas_119", "w1112")
    ttbar_bwd_plus.FillVars()
    ttbar_bwd_plus.Scale(sf)
    ttbar_bwd_plus.ScaleAllWeights(sf)
    ttbar_bwd_plus.SaveToFile()

    ttbar_bwd_minus = MWTemplate("ttbar_bwd_minus", t, bwdjet20_minus)
    for v in vars:
        var = v.var.replace('<jet>', 'bwdjet').replace('<mu>', 'mum')
        if hasattr(v, 'edges'):
            ttbar_bwd_minus.AddVar(v.name, var, v.edges)
        else:
            ttbar_bwd_minus.AddVar(v.name, var, v.bins, v.lo, v.hi)
    # ttbar_bwd_minus.Add2DVars(vars2d)
    ttbar_bwd_minus.ApplyCut()
    ttbar_bwd_minus.AddWeight("Central","w1010")
    ttbar_bwd_minus.AddWeight("Scale1", "w1002")
    ttbar_bwd_minus.AddWeight("Scale2", "w1003")
    ttbar_bwd_minus.AddWeight("Scale3", "w1004")
    ttbar_bwd_minus.AddWeight("Scale4", "w1005")
    ttbar_bwd_minus.AddWeight("Scale5", "w1007")
    ttbar_bwd_minus.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_bwd_minus.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_bwd_minus.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_bwd_minus.AddWeight("alphas_117", "w1111")
    ttbar_bwd_minus.AddWeight("alphas_119", "w1112")
    ttbar_bwd_minus.FillVars()
    ttbar_bwd_minus.Scale(sf)
    ttbar_bwd_minus.ScaleAllWeights(sf)
    ttbar_bwd_minus.SaveToFile()

    ttbar_plus = MWTemplate("ttbar_plus", ttbar_fwd_plus, ttbar_bwd_plus)
    #ttbar_plus.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_mub_plus.root")
    ttbar_plus.SaveToFile()

    ttbar_minus = MWTemplate("ttbar_minus", ttbar_fwd_minus, ttbar_bwd_minus)
    #ttbar_minus.SaveToFile("/user2/sfarry/workspaces/top/tuples/ttbar_mub_plus.root")
    ttbar_minus.SaveToFile()

    
    for v in vars:
        ttbar_plus_out[v.name] = ttbar_plus.GetWeightHist(v.name, "Central")
        for w in range(1,7):
            ttbar_plus_out[v.name+'_Scale'+str(w)] = ttbar_plus.GetWeightHist(v.name, "Scale"+str(w))
        for w in range(1,101):
            ttbar_plus_out[v.name+'_pdf'+str(w)] = ttbar_plus.GetWeightHist(v.name, "pdf"+str(w))
        ttbar_plus_out[v.name+"_alphas117"] = ttbar_plus.GetWeightHist(v.name, "alphas_117")
        ttbar_plus_out[v.name+"_alphas119"] = ttbar_plus.GetWeightHist(v.name, "alphas_119")

        ttbar_minus_out[v.name] = ttbar_minus.GetWeightHist(v.name, "Central")
        for w in range(1,7):
            ttbar_minus_out[v.name+'_Scale'+str(w)] = ttbar_minus.GetWeightHist(v.name, "Scale"+str(w))
        for w in range(1,101):
            ttbar_minus_out[v.name+'_pdf'+str(w)] = ttbar_minus.GetWeightHist(v.name, "pdf"+str(w))
        ttbar_minus_out[v.name+"_alphas117"] = ttbar_minus.GetWeightHist(v.name, "alphas_117")
        ttbar_minus_out[v.name+"_alphas119"] = ttbar_minus.GetWeightHist(v.name, "alphas_119")


ptj_plus  = details('ptj_plus', ttbar_plus_out['ptj'], [ttbar_plus_out['ptj_Scale'+str(i)] for i in range(1,7)], [ttbar_plus_out['ptj_pdf'+str(i)] for i in range(1,101)], [ttbar_plus_out['ptj_alphas117'], ttbar_plus_out['ptj_alphas119']])
ptj_minus  = details('ptj_minus', ttbar_minus_out['ptj'], [ttbar_minus_out['ptj_Scale'+str(i)] for i in range(1,7)], [ttbar_minus_out['ptj_pdf'+str(i)] for i in range(1,101)], [ttbar_minus_out['ptj_alphas117'], ttbar_minus_out['ptj_alphas119']])

etaj_plus  = details('etaj_plus', ttbar_plus_out['etaj'], [ttbar_plus_out['etaj_Scale'+str(i)] for i in range(1,7)], [ttbar_plus_out['etaj_pdf'+str(i)] for i in range(1,101)], [ttbar_plus_out['etaj_alphas117'], ttbar_plus_out['etaj_alphas119']])
etaj_minus  = details('etaj_minus', ttbar_minus_out['etaj'], [ttbar_minus_out['etaj_Scale'+str(i)] for i in range(1,7)], [ttbar_minus_out['etaj_pdf'+str(i)] for i in range(1,101)], [ttbar_minus_out['etaj_alphas117'], ttbar_minus_out['etaj_alphas119']])

ptmuj_plus  = details('ptmuj_plus', ttbar_plus_out['ptmuj'], [ttbar_plus_out['ptmuj_Scale'+str(i)] for i in range(1,7)], [ttbar_plus_out['ptmuj_pdf'+str(i)] for i in range(1,101)], [ttbar_plus_out['ptmuj_alphas117'], ttbar_plus_out['ptmuj_alphas119']])
ptmuj_minus  = details('ptmuj_minus', ttbar_minus_out['ptmuj'], [ttbar_minus_out['ptmuj_Scale'+str(i)] for i in range(1,7)], [ttbar_minus_out['ptmuj_pdf'+str(i)] for i in range(1,101)], [ttbar_minus_out['ptmuj_alphas117'], ttbar_minus_out['ptmuj_alphas119']])


ptmuj_asy = asymm_details('ptmuj_asy', ttbar_plus_out['ptmuj'],
                          [ttbar_plus_out['ptmuj_Scale'+str(i)] for i in range(1,7)],
                          ttbar_minus_out['ptmuj'], 
                          [ttbar_minus_out['ptmuj_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_plus_out['ptmuj_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_minus_out['ptmuj_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_plus_out['ptmuj_alphas117'],
                                     ttbar_plus_out['ptmuj_alphas119']],
                          alphas2 = [ttbar_minus_out['ptmuj_alphas117'],
                                     ttbar_minus_out['ptmuj_alphas119']])

mu_eta_asy = asymm_details('mu_eta_asy', ttbar_plus_out['mu_eta'],
                          [ttbar_plus_out['mu_eta_Scale'+str(i)] for i in range(1,7)],
                          ttbar_minus_out['mu_eta'], 
                          [ttbar_minus_out['mu_eta_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_plus_out['mu_eta_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_minus_out['mu_eta_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_plus_out['mu_eta_alphas117'],
                                     ttbar_plus_out['mu_eta_alphas119']],
                          alphas2 = [ttbar_minus_out['mu_eta_alphas117'],
                                     ttbar_minus_out['mu_eta_alphas119']])

output = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_amcatnlo_mue_predictions.root", "RECREATE")
ptj_plus.write()
ptmuj_plus.write()
etaj_plus.write()
ptj_minus.write()
ptmuj_minus.write()
etaj_minus.write()
ptmuj_asy.write()
mu_eta_asy.write()
output.Close()
