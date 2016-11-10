from os import sys
import copy
from Jawa import *
from ROOT import TCut, TTree, TFile, TMath, TH1F, TF1, TH1, TParameter
from Utils import GetWeightHist, GetSpreadGraph, GetPDFGraph, asymm_details, ratio_details, details
from math import sqrt

def getpdfuncertainty(central, pdfsets):
    sumsq = 0
    for pdf in pdfsets:
        sumsq = sumsq + pow(central - pdf,2)
    return sqrt(sumsq / (len(pdfsets) - 1))



TH1.AddDirectory(False)
dpm = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/"

fwd_vis_m = "sqrt((sqrt(mu_m^2 + mu_px^2 + mu_py^2 + mu_pz^2) + sqrt(e_m^2 + e_px^2 + e_py^2 + e_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (mu_px + e_px + fwdjet_px)^2 - (mu_py + e_py + fwdjet_py)^2 - (mu_pz + e_pz + fwdjet_pz)^2)"
bwd_vis_m = fwd_vis_m.replace('fwdjet', 'bwdjet')
fwd_muj_m = "sqrt((sqrt(mu_m^2 + mu_px^2 + mu_py^2 + mu_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (mu_px + fwdjet_px)^2 - (mu_py + fwdjet_py)^2 - (mu_pz + fwdjet_pz)^2)"
bwd_muj_m = fwd_muj_m.replace('fwdjet', 'bwdjet')

fwdvars = [
    ["mu_pt"        , "mu_pt"           , 80  , 0 , 80 ],
    ["e_pt"         , "e_pt"            , 80  , 0 , 80 ],
    ["mu_eta"       , "abs(mu_eta)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(e_eta)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "fwdjet_pt"       , 5, 20, 220],
    ["m_vis"        , fwd_vis_m         , 100, 0, 50],
    ["m_muj"        , fwd_muj_m         , 100, 0, 50],
    ["etaj"         , "abs(fwdjet_eta)"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["t_y"          , "abs(t_y)"     ,    10, 0, 5.0],
    ["tbar_y"       , "abs(tbar_y)" ,    10, 0, 5.0],
    ["t_pt"          , "abs(t_pt)"     ,    20, 0, 100.0],
    ["tbar_pt"       , "abs(tbar_pt)" ,    20, 0, 100.0]
    ]
bwdvars = [
    ["mu_pt"        , "mu_pt"           , 80  , 0 , 80 ],
    ["e_pt"         , "e_pt"            , 80  , 0 , 80 ],
    ["mu_eta"       , "abs(mu_eta)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(e_eta)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "bwdjet_pt"       , 5, 20, 220],
    ["m_vis"        , bwd_vis_m         , 100, 0, 50],
    ["m_muj"        , bwd_muj_m         , 100, 0, 50],
    ["etaj"         , "abs(bwdjet_eta)"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["t_y"          , "abs(t_y)"     ,    10, 0, 5.0],
    ["tbar_y"       , "abs(tbar_y)" ,    10, 0, 5.0],
    ["t_pt"          , "abs(t_pt)"     ,    20, 0, 100.0],
    ["tbar_pt"       , "abs(tbar_pt)" ,    20, 0, 100.0]
    ]

vars2d = [ ['t_y', 'tbar_y'] ]

pltvars = ['ptj', 'eta', 'yj', 'etaj']

lhcbfwd = TCut("mu_eta > 2.0 && mu_eta < 4.5 && e_eta > 2.0 && e_eta < 4.5")
lhcbbwd = TCut("mu_eta < -2.0 && mu_eta > -4.5 && e_eta < -2.0 && e_eta > -4.5")

pt20  = TCut("mu_pt  > 20 && e_pt > 20")

fwdjet_btag = TCut("abs(fwdjet_flav) == 5")
bwdjet_btag = TCut("abs(bwdjet_flav) == 5")

fwdjetpt10 = TCut("fwdjet_pt > 10")
fwdjetpt20 = TCut("fwdjet_pt > 20")

bwdjetpt10 = TCut("bwdjet_pt > 10")
bwdjetpt20 = TCut("bwdjet_pt > 20")

bwdjet20 = pt20 + lhcbbwd + bwdjetpt20 + bwdjet_btag
fwdjet20 = pt20 + lhcbfwd + fwdjetpt20 + fwdjet_btag
bwdjet20_nobtag = pt20 + lhcbbwd + bwdjetpt20
fwdjet20_nobtag = pt20 + lhcbfwd + fwdjetpt20

mue_fwdasy = TCut("mu_eta > e_eta")
mue_bwdasy = TCut("e_eta  > mu_eta")

fwdasy_fwdjet = TCut("(mu_id == 13 && mu_eta > e_eta) || (mu_id == -13 && mu_eta < e_eta)")
fwdasy_bwdjet = TCut("(mu_id == 13 && mu_eta < e_eta) || (mu_id == -13 && mu_eta > e_eta)")
bwdasy_bwdjet = TCut("(mu_id == 13 && mu_eta > e_eta) || (mu_id == -13 && mu_eta < e_eta)")
bwdasy_fwdjet = TCut("(mu_id == 13 && mu_eta < e_eta) || (mu_id == -13 && mu_eta > e_eta)")

mupem = TCut("mu_id == -13 && e_id == 11")
mumep = TCut("mu_id == 13  && e_id == -11")

#ttf   = TFile.Open("/hepstore/sfarry/aMC@NLO/ttbar/Events/mue_ttbar_amcatnlo_pdf_as.root")
ttf   = TFile.Open("/hepstore/sfarry/aMC@NLO/ttbar/Events/ttbar.root")
t     = ttf.Get("ttbar")

wwf   = TFile.Open("/hepstore/sfarry/aMC@NLO/WW/Events/mue_WW_amcatnlo.root")
wzf   = TFile.Open("/hepstore/sfarry/aMC@NLO/WZ/Events/mue_WZ_amcatnlo.root")

wwt   = wwf.Get("ttbar")
wzt   = wzf.Get("ttbar")

#N = ttf.Get('totEvts').GetVal()
N = t.GetEntries()
#correct by enforced branching ratio of W to mu or e
bf = pow(2*0.1080,2)

sf = 0.5*bf/N
ww_sf = 0.5*bf/wwt.GetEntries()
wz_sf = 0.5*bf/wzt.GetEntries()

fwd_vis_m = "sqrt((mu_E + e_E + fwdjet_E)^2 - (mu_px + e_px + fwdjet_px)^2 - (mu_py + e_py + fwdjet_py)^2 - (mu_pz + e_pz + fwdjet_pz)^2)"
bwd_vis_m = fwd_vis_m.replace('fwdjet', 'bwdjet')

relaunch = True

top_fiducial = TCut("abs(t_y) > 2.0 && abs(t_y) < 5.0 && abs(tbar_y) > 2.0 && abs(tbar_y) < 5.0 && t_y*tbar_y > 0 && t_pt > 10.0 && tbar_pt > 10.0")

top_fiducial_fwd = TCut("t_y > 2.0 && t_y < 5.0 && tbar_y > 2.0 && tbar_y < 5.0 && t_pt > 10.0 && tbar_pt > 10.0")

ttbar_out          = {}
ttbar_fiducial_out = {}
ttbar_fwdasy_out   = {}
ttbar_bwdasy_out   = {}

WW_out          = {}
WZ_out          = {}

if relaunch:
    ttbar_fwd_pm = MWTemplate("ttbar_fwd_pm", t, fwdjet20 + mupem)
    ttbar_fwd_pm.AddVars(fwdvars)
    #ttbar_fwd_pm.Add2DVars(vars2d)
    ttbar_fwd_pm.ApplyCut()
    ttbar_fwd_pm.AddWeight("Central","w1010")
    ttbar_fwd_pm.AddWeight("Scale1", "w1002")
    ttbar_fwd_pm.AddWeight("Scale2", "w1003")
    ttbar_fwd_pm.AddWeight("Scale3", "w1004")
    ttbar_fwd_pm.AddWeight("Scale4", "w1005")
    ttbar_fwd_pm.AddWeight("Scale5", "w1007")
    ttbar_fwd_pm.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_fwd_pm.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_fwd_pm.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_fwd_pm.AddWeight("alphas_117", "w1111")
    ttbar_fwd_pm.AddWeight("alphas_119", "w1112")
    ttbar_fwd_pm.FillVars()
    ttbar_fwd_pm.Scale(sf)
    ttbar_fwd_pm.ScaleAllWeights(sf)
    ttbar_fwd_pm.SaveToFile()

    ttbar_fwd_mp = MWTemplate("ttbar_fwd_mp", t, fwdjet20 + mumep)
    ttbar_fwd_mp.AddVars(fwdvars)
    # ttbar_fwd_mp.Add2DVars(vars2d)
    ttbar_fwd_mp.ApplyCut()
    ttbar_fwd_mp.AddWeight("Central","w1010")
    ttbar_fwd_mp.AddWeight("Scale1", "w1002")
    ttbar_fwd_mp.AddWeight("Scale2", "w1003")
    ttbar_fwd_mp.AddWeight("Scale3", "w1004")
    ttbar_fwd_mp.AddWeight("Scale4", "w1005")
    ttbar_fwd_mp.AddWeight("Scale5", "w1007")
    ttbar_fwd_mp.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_fwd_mp.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_fwd_mp.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_fwd_mp.AddWeight("alphas_117", "w1111")
    ttbar_fwd_mp.AddWeight("alphas_119", "w1112")
    ttbar_fwd_mp.FillVars()
    ttbar_fwd_mp.Scale(sf)
    ttbar_fwd_mp.ScaleAllWeights(sf)
    ttbar_fwd_mp.SaveToFile()


    ttbar_bwd_pm = MWTemplate("ttbar_bwd_pm", t, bwdjet20 + mupem)
    ttbar_bwd_pm.AddVars(bwdvars)
    #ttbar_bwd_pm.Add2DVars(vars2d)
    ttbar_bwd_pm.ApplyCut()
    ttbar_bwd_pm.AddWeight("Central","w1010")
    ttbar_bwd_pm.AddWeight("Scale1", "w1002")
    ttbar_bwd_pm.AddWeight("Scale2", "w1003")
    ttbar_bwd_pm.AddWeight("Scale3", "w1004")
    ttbar_bwd_pm.AddWeight("Scale4", "w1005")
    ttbar_bwd_pm.AddWeight("Scale5", "w1007")
    ttbar_bwd_pm.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_bwd_pm.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_bwd_pm.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_bwd_pm.AddWeight("alphas_117", "w1111")
    ttbar_bwd_pm.AddWeight("alphas_119", "w1112")
    ttbar_bwd_pm.FillVars()
    ttbar_bwd_pm.Scale(sf)
    ttbar_bwd_pm.ScaleAllWeights(sf)
    ttbar_bwd_pm.SaveToFile()

    ttbar_bwd_mp = MWTemplate("ttbar_bwd_mp", t, bwdjet20 + mumep)
    ttbar_bwd_mp.AddVars(bwdvars)
    #ttbar_bwd_mp.Add2DVars(vars2d)
    ttbar_bwd_mp.ApplyCut()
    ttbar_bwd_mp.AddWeight("Central","w1010")
    ttbar_bwd_mp.AddWeight("Scale1", "w1002")
    ttbar_bwd_mp.AddWeight("Scale2", "w1003")
    ttbar_bwd_mp.AddWeight("Scale3", "w1004")
    ttbar_bwd_mp.AddWeight("Scale4", "w1005")
    ttbar_bwd_mp.AddWeight("Scale5", "w1007")
    ttbar_bwd_mp.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_bwd_mp.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_bwd_mp.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_bwd_mp.AddWeight("alphas_117", "w1111")
    ttbar_bwd_mp.AddWeight("alphas_119", "w1112")
    ttbar_bwd_mp.FillVars()
    ttbar_bwd_mp.Scale(sf)
    ttbar_bwd_mp.ScaleAllWeights(sf)
    ttbar_bwd_mp.SaveToFile()


    ttbar_pm  = MWTemplate("ttbar_13tev_amcatnlo_pm", ttbar_fwd_pm, ttbar_bwd_pm)
    ttbar_pm.SaveToFile()

    ttbar_mp  = MWTemplate("ttbar_13tev_amcatnlo_mp", ttbar_fwd_mp, ttbar_bwd_mp)
    ttbar_mp.SaveToFile()

    ttbar    = MWTemplate("ttbar_13tev_amcatnlo", ttbar_pm, ttbar_mp)
    ttbar.SaveToFile()

    for v in ['ptj', 'm_vis', 'm_muj', 'etaj', 't_y']:
        ttbar_out[v] = ttbar.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_out[v+'_Scale'+str(w)] = ttbar.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_out[v+'_pdf'+str(w)] = ttbar.GetWeightHist(v, "pdf"+str(w))
        ttbar_out[v+"_alphas117"] = ttbar.GetWeightHist(v, "alphas_117")
        ttbar_out[v+"_alphas119"] = ttbar.GetWeightHist(v, "alphas_119")

    ttbar_fwd_fwdasy = MWTemplate("ttbar_fwd_fwdasy", t, fwdjet20 + fwdasy_fwdjet)
    ttbar_fwd_fwdasy.AddVars(fwdvars)
    ttbar_fwd_fwdasy.ApplyCut()
    ttbar_fwd_fwdasy.AddWeight("Central","w1010")
    ttbar_fwd_fwdasy.AddWeight("Scale1", "w1002")
    ttbar_fwd_fwdasy.AddWeight("Scale2", "w1003")
    ttbar_fwd_fwdasy.AddWeight("Scale3", "w1004")
    ttbar_fwd_fwdasy.AddWeight("Scale4", "w1005")
    ttbar_fwd_fwdasy.AddWeight("Scale5", "w1007")
    ttbar_fwd_fwdasy.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_fwd_fwdasy.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_fwd_fwdasy.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_fwd_fwdasy.AddWeight("alphas_117", "w1111")
    ttbar_fwd_fwdasy.AddWeight("alphas_119", "w1112")
    ttbar_fwd_fwdasy.FillVars()
    ttbar_fwd_fwdasy.Scale(sf)
    ttbar_fwd_fwdasy.ScaleAllWeights(sf)
    ttbar_fwd_fwdasy.SaveToFile()

    ttbar_fwd_bwdasy = MWTemplate("ttbar_fwd_bwdasy", t, fwdjet20 + bwdasy_fwdjet)
    ttbar_fwd_bwdasy.AddVars(fwdvars)
    ttbar_fwd_bwdasy.ApplyCut()
    ttbar_fwd_bwdasy.AddWeight("Central","w1010")
    ttbar_fwd_bwdasy.AddWeight("Scale1", "w1002")
    ttbar_fwd_bwdasy.AddWeight("Scale2", "w1003")
    ttbar_fwd_bwdasy.AddWeight("Scale3", "w1004")
    ttbar_fwd_bwdasy.AddWeight("Scale4", "w1005")
    ttbar_fwd_bwdasy.AddWeight("Scale5", "w1007")
    ttbar_fwd_bwdasy.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_fwd_bwdasy.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_fwd_bwdasy.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_fwd_bwdasy.AddWeight("alphas_117", "w1111")
    ttbar_fwd_bwdasy.AddWeight("alphas_119", "w1112")
    ttbar_fwd_bwdasy.FillVars()
    ttbar_fwd_bwdasy.Scale(sf)
    ttbar_fwd_bwdasy.ScaleAllWeights(sf)
    ttbar_fwd_bwdasy.SaveToFile()


    ttbar_bwd_fwdasy = MWTemplate("ttbar_bwd_fwdasy", t, bwdjet20 + fwdasy_bwdjet )
    ttbar_bwd_fwdasy.AddVars(fwdvars)
    ttbar_bwd_fwdasy.ApplyCut()
    ttbar_bwd_fwdasy.AddWeight("Central","w1010")
    ttbar_bwd_fwdasy.AddWeight("Scale1", "w1002")
    ttbar_bwd_fwdasy.AddWeight("Scale2", "w1003")
    ttbar_bwd_fwdasy.AddWeight("Scale3", "w1004")
    ttbar_bwd_fwdasy.AddWeight("Scale4", "w1005")
    ttbar_bwd_fwdasy.AddWeight("Scale5", "w1007")
    ttbar_bwd_fwdasy.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_bwd_fwdasy.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_bwd_fwdasy.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_bwd_fwdasy.AddWeight("alphas_117", "w1111")
    ttbar_bwd_fwdasy.AddWeight("alphas_119", "w1112")
    ttbar_bwd_fwdasy.FillVars()
    ttbar_bwd_fwdasy.Scale(sf)
    ttbar_bwd_fwdasy.ScaleAllWeights(sf)
    ttbar_bwd_fwdasy.SaveToFile()


    ttbar_bwd_bwdasy = MWTemplate("ttbar_bwd_bwdasy", t, bwdjet20 + bwdasy_bwdjet)
    ttbar_bwd_bwdasy.AddVars(fwdvars)
    ttbar_bwd_bwdasy.ApplyCut()
    ttbar_bwd_bwdasy.AddWeight("Central","w1010")
    ttbar_bwd_bwdasy.AddWeight("Scale1", "w1002")
    ttbar_bwd_bwdasy.AddWeight("Scale2", "w1003")
    ttbar_bwd_bwdasy.AddWeight("Scale3", "w1004")
    ttbar_bwd_bwdasy.AddWeight("Scale4", "w1005")
    ttbar_bwd_bwdasy.AddWeight("Scale5", "w1007")
    ttbar_bwd_bwdasy.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_bwd_bwdasy.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_bwd_bwdasy.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_bwd_bwdasy.AddWeight("alphas_117", "w1111")
    ttbar_bwd_bwdasy.AddWeight("alphas_119", "w1112")
    ttbar_bwd_bwdasy.FillVars()
    ttbar_bwd_bwdasy.Scale(sf)
    ttbar_bwd_bwdasy.ScaleAllWeights(sf)
    ttbar_bwd_bwdasy.SaveToFile()

    ttbar_fwdasy = MWTemplate("ttbar_fwdasy", ttbar_fwd_fwdasy, ttbar_bwd_fwdasy)
    ttbar_fwdasy.SaveToFile()
    ttbar_bwdasy = MWTemplate("ttbar_bwdasy", ttbar_fwd_bwdasy, ttbar_bwd_bwdasy)
    ttbar_bwdasy.SaveToFile()
    
    for v in ['ptj', 'm_vis', 'm_muj', 'mu_eta', 'etaj', 't_y']:
        ttbar_fwdasy_out[v] = ttbar_fwdasy.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_fwdasy_out[v+'_Scale'+str(w)] = ttbar_fwdasy.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_fwdasy_out[v+'_pdf'+str(w)] = ttbar_fwdasy.GetWeightHist(v, "pdf"+str(w))
        ttbar_fwdasy_out[v+"_alphas117"] = ttbar_fwdasy.GetWeightHist(v, "alphas_117")
        ttbar_fwdasy_out[v+"_alphas119"] = ttbar_fwdasy.GetWeightHist(v, "alphas_119")

        ttbar_bwdasy_out[v] = ttbar_bwdasy.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_bwdasy_out[v+'_Scale'+str(w)] = ttbar_bwdasy.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_bwdasy_out[v+'_pdf'+str(w)] = ttbar_bwdasy.GetWeightHist(v, "pdf"+str(w))
        ttbar_bwdasy_out[v+"_alphas117"] = ttbar_bwdasy.GetWeightHist(v, "alphas_117")
        ttbar_bwdasy_out[v+"_alphas119"] = ttbar_bwdasy.GetWeightHist(v, "alphas_119")

    ttbar_fiducial = MWTemplate("ttbar_fiducial", t, top_fiducial)
    ttbar_fiducial.AddVars(fwdvars)
    ttbar_fiducial.Add2DVars(vars2d)
    ttbar_fiducial.ApplyCut()
    ttbar_fiducial.AddWeight("Central","w1010")
    ttbar_fiducial.AddWeight("Scale1", "w1002")
    ttbar_fiducial.AddWeight("Scale2", "w1003")
    ttbar_fiducial.AddWeight("Scale3", "w1004")
    ttbar_fiducial.AddWeight("Scale4", "w1005")
    ttbar_fiducial.AddWeight("Scale5", "w1007")
    ttbar_fiducial.AddWeight("Scale6", "w1009")
    for i in range(89):
        ttbar_fiducial.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        ttbar_fiducial.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    ttbar_fiducial.AddWeight("alphas_117", "w1111")
    ttbar_fiducial.AddWeight("alphas_119", "w1112")
    ttbar_fiducial.FillVars()
    ttbar_fiducial.Scale(sf)
    ttbar_fiducial.ScaleAllWeights(sf)
    ttbar_fiducial.SaveToFile()

    for v in ['ptj', 'm_vis', 'm_muj', 'mu_eta', 'etaj', 't_y']:
        ttbar_fiducial_out[v] = ttbar_fiducial.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_fiducial_out[v+'_Scale'+str(w)] = ttbar_fiducial.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_fiducial_out[v+'_pdf'+str(w)] = ttbar_fiducial.GetWeightHist(v, "pdf"+str(w))
        ttbar_fiducial_out[v+"_alphas117"] = ttbar_fiducial.GetWeightHist(v, "alphas_117")
        ttbar_fiducial_out[v+"_alphas119"] = ttbar_fiducial.GetWeightHist(v, "alphas_119")

WWb_fwd = MWTemplate("WWb_fwd", wwt, fwdjet20)
WWb_fwd.AddVars(fwdvars)
WWb_fwd.ApplyCut()
WWb_fwd.AddWeight("Central","w1010")
WWb_fwd.AddWeight("Scale1", "w1002")
WWb_fwd.AddWeight("Scale2", "w1003")
WWb_fwd.AddWeight("Scale3", "w1004")
WWb_fwd.AddWeight("Scale4", "w1005")
WWb_fwd.AddWeight("Scale5", "w1007")
WWb_fwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WWb_fwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WWb_fwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WWb_fwd.AddWeight("alphas_117", "w1111")
WWb_fwd.AddWeight("alphas_119", "w1112")
WWb_fwd.FillVars()
WWb_fwd.Scale(sf)
WWb_fwd.ScaleAllWeights(ww_sf)
WWb_fwd.SaveToFile()

WWb_bwd = MWTemplate("WWb_bwd", wwt, bwdjet20)
WWb_bwd.AddVars(bwdvars)
WWb_bwd.ApplyCut()
WWb_bwd.AddWeight("Central","w1010")
WWb_bwd.AddWeight("Scale1", "w1002")
WWb_bwd.AddWeight("Scale2", "w1003")
WWb_bwd.AddWeight("Scale3", "w1004")
WWb_bwd.AddWeight("Scale4", "w1005")
WWb_bwd.AddWeight("Scale5", "w1007")
WWb_bwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WWb_bwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WWb_bwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WWb_bwd.AddWeight("alphas_117", "w1111")
WWb_bwd.AddWeight("alphas_119", "w1112")
WWb_bwd.FillVars()
WWb_bwd.Scale(sf)
WWb_bwd.ScaleAllWeights(ww_sf)
WWb_bwd.SaveToFile()


WWb = MWTemplate("WWb", WWb_fwd, WWb_bwd)
WWb.SaveToFile()



WZb_fwd = MWTemplate("WZb_fwd", wzt, fwdjet20)
WZb_fwd.AddVars(fwdvars)
WZb_fwd.ApplyCut()
WZb_fwd.AddWeight("Central","w1010")
WZb_fwd.AddWeight("Scale1", "w1002")
WZb_fwd.AddWeight("Scale2", "w1003")
WZb_fwd.AddWeight("Scale3", "w1004")
WZb_fwd.AddWeight("Scale4", "w1005")
WZb_fwd.AddWeight("Scale5", "w1007")
WZb_fwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WZb_fwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WZb_fwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WZb_fwd.AddWeight("alphas_117", "w1111")
WZb_fwd.AddWeight("alphas_119", "w1112")
WZb_fwd.FillVars()
WZb_fwd.Scale(sf)
WZb_fwd.ScaleAllWeights(wz_sf)
WZb_fwd.SaveToFile()

WZb_bwd = MWTemplate("WZb_bwd", wzt, bwdjet20)
WZb_bwd.AddVars(bwdvars)
WZb_bwd.ApplyCut()
WZb_bwd.AddWeight("Central","w1010")
WZb_bwd.AddWeight("Scale1", "w1002")
WZb_bwd.AddWeight("Scale2", "w1003")
WZb_bwd.AddWeight("Scale3", "w1004")
WZb_bwd.AddWeight("Scale4", "w1005")
WZb_bwd.AddWeight("Scale5", "w1007")
WZb_bwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WZb_bwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WZb_bwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WZb_bwd.AddWeight("alphas_117", "w1111")
WZb_bwd.AddWeight("alphas_119", "w1112")
WZb_bwd.FillVars()
WZb_bwd.Scale(sf)
WZb_bwd.ScaleAllWeights(wz_sf)
WZb_bwd.SaveToFile()


WZb = MWTemplate("WZb", WZb_fwd, WZb_bwd)
WZb.SaveToFile()



WWj_fwd = MWTemplate("WWj_fwd", wwt, fwdjet20_nobtag)
WWj_fwd.AddVars(fwdvars)
WWj_fwd.ApplyCut()
WWj_fwd.AddWeight("Central","w1010")
WWj_fwd.AddWeight("Scale1", "w1002")
WWj_fwd.AddWeight("Scale2", "w1003")
WWj_fwd.AddWeight("Scale3", "w1004")
WWj_fwd.AddWeight("Scale4", "w1005")
WWj_fwd.AddWeight("Scale5", "w1007")
WWj_fwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WWj_fwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WWj_fwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WWj_fwd.AddWeight("alphas_117", "w1111")
WWj_fwd.AddWeight("alphas_119", "w1112")
WWj_fwd.FillVars()
WWj_fwd.Scale(sf)
WWj_fwd.ScaleAllWeights(ww_sf)
WWj_fwd.SaveToFile()

WWj_bwd = MWTemplate("WWj_bwd", wwt, bwdjet20_nobtag)
WWj_bwd.AddVars(bwdvars)
WWj_bwd.ApplyCut()
WWj_bwd.AddWeight("Central","w1010")
WWj_bwd.AddWeight("Scale1", "w1002")
WWj_bwd.AddWeight("Scale2", "w1003")
WWj_bwd.AddWeight("Scale3", "w1004")
WWj_bwd.AddWeight("Scale4", "w1005")
WWj_bwd.AddWeight("Scale5", "w1007")
WWj_bwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WWj_bwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WWj_bwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WWj_bwd.AddWeight("alphas_117", "w1111")
WWj_bwd.AddWeight("alphas_119", "w1112")
WWj_bwd.FillVars()
WWj_bwd.Scale(sf)
WWj_bwd.ScaleAllWeights(ww_sf)
WWj_bwd.SaveToFile()


WWj = MWTemplate("WWj", WWj_fwd, WWj_bwd)
WWj.SaveToFile()


for v in ['ptj', 'm_vis', 'm_muj', 'etaj', 't_y']:
    WW_out[v] = WWj.GetWeightHist(v, "Central")
    for w in range(1,7):
        WW_out[v+'_Scale'+str(w)] = WWj.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WW_out[v+'_pdf'+str(w)] = WWj.GetWeightHist(v, "pdf"+str(w))
        WW_out[v+"_alphas117"] = WWj.GetWeightHist(v, "alphas_117")
    WW_out[v+"_alphas119"] = WWj.GetWeightHist(v, "alphas_119")

WZj_fwd = MWTemplate("WZj_fwd", wzt, fwdjet20_nobtag)
WZj_fwd.AddVars(fwdvars)
WZj_fwd.ApplyCut()
WZj_fwd.AddWeight("Central","w1010")
WZj_fwd.AddWeight("Scale1", "w1002")
WZj_fwd.AddWeight("Scale2", "w1003")
WZj_fwd.AddWeight("Scale3", "w1004")
WZj_fwd.AddWeight("Scale4", "w1005")
WZj_fwd.AddWeight("Scale5", "w1007")
WZj_fwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WZj_fwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WZj_fwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WZj_fwd.AddWeight("alphas_117", "w1111")
WZj_fwd.AddWeight("alphas_119", "w1112")
WZj_fwd.FillVars()
WZj_fwd.Scale(sf)
WZj_fwd.ScaleAllWeights(wz_sf)
WZj_fwd.SaveToFile()

WZj_bwd = MWTemplate("WZj_bwd", wzt, bwdjet20_nobtag)
WZj_bwd.AddVars(bwdvars)
WZj_bwd.ApplyCut()
WZj_bwd.AddWeight("Central","w1010")
WZj_bwd.AddWeight("Scale1", "w1002")
WZj_bwd.AddWeight("Scale2", "w1003")
WZj_bwd.AddWeight("Scale3", "w1004")
WZj_bwd.AddWeight("Scale4", "w1005")
WZj_bwd.AddWeight("Scale5", "w1007")
WZj_bwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WZj_bwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WZj_bwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WZj_bwd.AddWeight("alphas_117", "w1111")
WZj_bwd.AddWeight("alphas_119", "w1112")
WZj_bwd.FillVars()
WZj_bwd.Scale(sf)
WZj_bwd.ScaleAllWeights(wz_sf)
WZj_bwd.SaveToFile()


WZj = MWTemplate("WZj", WZj_fwd, WZj_bwd)
WZj.SaveToFile()

for v in ['ptj', 'm_vis', 'm_muj', 'etaj', 't_y']:
    WZ_out[v] = WZj.GetWeightHist(v, "Central")
    for w in range(1,7):
        WZ_out[v+'_Scale'+str(w)] = WZj.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WZ_out[v+'_pdf'+str(w)] = WZj.GetWeightHist(v, "pdf"+str(w))
        WZ_out[v+"_alphas117"] = WZj.GetWeightHist(v, "alphas_117")
    WZ_out[v+"_alphas119"] = WZj.GetWeightHist(v, "alphas_119")


#else:
#    wpjf = TFile("Wpj_aMCatNLO_8TeV_expdists.root")
#    wmjf = TFile("Wmj_aMCatNLO_8TeV_expdists.root")
#    
#    for pv in pltvars:
#       wpj[pv] = wpjf.Get(pv+"_Central")
#        for w in range(1,7):
#            wpj[pv+'_Scale'+str(w)] = wpjf.Get(pv+"_Scale"+str(w))
#        wmj[pv] = wmjf.Get(pv+"_Central")
#        for w in range(1,7):
#            wmj[pv+'_Scale'+str(w)] = wmjf.Get(pv+"_Scale"+str(w))

#Get the various components
# first the differential histograms for each pt threshold, plus, minus and separated in pdf and scale
ptj  = details('ptj', ttbar_out['ptj'], [ttbar_out['ptj_Scale'+str(i)] for i in range(1,7)], [ttbar_out['ptj_pdf'+str(i)] for i in range(1,101)], [ttbar_out['ptj_alphas117'], ttbar_out['ptj_alphas119']])
etaj  = details('etaj', ttbar_out['etaj'], [ttbar_out['etaj_Scale'+str(i)] for i in range(1,7)], [ttbar_out['etaj_pdf'+str(i)] for i in range(1,101)], [ttbar_out['etaj_alphas117'], ttbar_out['etaj_alphas119']])
mvis  = details('m_vis', ttbar_out['m_vis'], [ttbar_out['m_vis_Scale'+str(i)] for i in range(1,7)], [ttbar_out['m_vis_pdf'+str(i)] for i in range(1,101)], [ttbar_out['m_vis_alphas117'], ttbar_out['m_vis_alphas119']])
mmuj  = details('m_muj', ttbar_out['m_muj'], [ttbar_out['m_muj_Scale'+str(i)] for i in range(1,7)], [ttbar_out['m_muj_pdf'+str(i)] for i in range(1,101)], [ttbar_out['m_muj_alphas117'], ttbar_out['m_muj_alphas119']])

ptj_asy = asymm_details('ptj_asy', ttbar_fwdasy_out['ptj'], [ttbar_fwdasy_out['ptj_Scale'+str(i)] for i in range(1,7)],
                          ttbar_bwdasy_out['ptj'], [ttbar_bwdasy_out['ptj_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fwdasy_out['ptj_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_bwdasy_out['ptj_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fwdasy_out['ptj_alphas117'], ttbar_fwdasy_out['ptj_alphas119']],
                          alphas2 = [ttbar_bwdasy_out['ptj_alphas117'], ttbar_bwdasy_out['ptj_alphas119']])

mu_eta_asy = asymm_details('mu_eta_asy', ttbar_fwdasy_out['mu_eta'], [ttbar_fwdasy_out['mu_eta_Scale'+str(i)] for i in range(1,7)],
                          ttbar_bwdasy_out['mu_eta'], [ttbar_bwdasy_out['mu_eta_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fwdasy_out['mu_eta_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_bwdasy_out['mu_eta_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fwdasy_out['mu_eta_alphas117'], ttbar_fwdasy_out['mu_eta_alphas119']],
                          alphas2 = [ttbar_bwdasy_out['mu_eta_alphas117'], ttbar_bwdasy_out['mu_eta_alphas119']])

etaj_asy = asymm_details('etaj_asy', ttbar_fwdasy_out['etaj'], [ttbar_fwdasy_out['etaj_Scale'+str(i)] for i in range(1,7)],
                          ttbar_bwdasy_out['etaj'], [ttbar_bwdasy_out['etaj_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fwdasy_out['etaj_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_bwdasy_out['etaj_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fwdasy_out['etaj_alphas117'], ttbar_fwdasy_out['etaj_alphas119']],
                          alphas2 = [ttbar_bwdasy_out['etaj_alphas117'], ttbar_bwdasy_out['etaj_alphas119']])

t_y_acc = ratio_details('t_y_acc', ttbar_fiducial_out['t_y'], [ttbar_fiducial_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          ttbar_out['t_y'], [ttbar_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fiducial_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fiducial_out['t_y_alphas117'], ttbar_fiducial_out['t_y_alphas119']],
                          alphas2 = [ttbar_out['t_y_alphas117'], ttbar_out['t_y_alphas119']])


etaj_WW  = details('etaj_WW', WW_out['etaj'], [WW_out['etaj_Scale'+str(i)] for i in range(1,7)], [WW_out['etaj_pdf'+str(i)] for i in range(1,101)], [WW_out['etaj_alphas117'], WW_out['etaj_alphas119']])
etaj_WZ  = details('etaj_WZ', WZ_out['etaj'], [WZ_out['etaj_Scale'+str(i)] for i in range(1,7)], [WZ_out['etaj_pdf'+str(i)] for i in range(1,101)], [WZ_out['etaj_alphas117'], WZ_out['etaj_alphas119']])



wtf = TFile("/user2/sfarry/external/powheg/POWHEG-BOX/ST_wtch_DR/run_1/mue_Wt_powheg_13tev.root")
wtt = wtf.Get("ttbar")
wt_tot_xsec = 36.625
wt_acc = wtt.GetEntries(fwdjet20.GetTitle())/float(wtt.GetEntries())
wt_fid_xsec = wt_acc * wt_tot_xsec * bf

wtdsf = TFile("/user2/sfarry/external/powheg/POWHEG-BOX/ST_wtch_DS/run_1/mue_Wt_powheg_ds_13tev.root")
wtdst = wtdsf.Get("ttbar")
wtds_tot_xsec = 34.8215
wtds_acc = wtdst.GetEntries(fwdjet20.GetTitle())/float(wtdst.GetEntries())
wtds_fid_xsec = wtds_acc * wtds_tot_xsec * bf

print 'wt fiducial cross-section is ',wt_fid_xsec*100,' fb (DR)'
print 'wtds fiducial cross-section is ',wtds_fid_xsec*100,' fb (DS)'

output = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13teV_amcatnlo_predictions.root", "RECREATE")
ptj.write()
etaj.write()
mvis.write()
mmuj.write()
ptj_asy.write()
mu_eta_asy.write()
etaj_asy.write()
t_y_acc.write()
etaj_WW.write()
etaj_WZ.write()
TParameter(float)("Wt_dr_xsec", wt_fid_xsec).Write()
TParameter(float)("Wt_ds_xsec", wtds_fid_xsec).Write()
output.Close()
