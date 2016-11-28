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

fwd_vis_m = "sqrt((sqrt(mu_m^2 + mu_px^2 + mu_py^2 + mu_pz^2) + sqrt(e_m^2 + e_px^2 + e_py^2 + e_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (mu_px + e_px + fwdjet_px)^2 - (mu_py + e_py + fwdjet_py)^2 - (mu_pz + e_pz + fwdjet_pz)^2)"
bwd_vis_m = fwd_vis_m.replace('fwdjet', 'bwdjet')
fwd_muj_m = "sqrt((sqrt(mu_m^2 + mu_px^2 + mu_py^2 + mu_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (mu_px + fwdjet_px)^2 - (mu_py + fwdjet_py)^2 - (mu_pz + fwdjet_pz)^2)"
bwd_muj_m = fwd_muj_m.replace('fwdjet', 'bwdjet')


ws = {}
ws["Central"] = "w1010"
ws["Scale1"] =  "w1002"
ws["Scale2"] =  "w1003"
ws["Scale3"] =  "w1004"
ws["Scale4"] =  "w1005"
ws["Scale5"] =  "w1007"
ws["Scale6"] =  "w1009"
for i in range(89):
    ws["pdf"+str(i+1)] = "w10"+str(i+11)
for i in range(11):
    ws["pdf"+str(i+90)] = "w1"+str(i+100)
ws["alphas_117"]   =  "w1111"
ws["alphas_119"]   =  "w1112"


variables = [
    Bunch(name="mu_pt"        , var="<mu>_pt"           , bins = 8  , lo = 20 , hi = 100 ),
    Bunch(name="e_pt"         , var="<e>_pt"            , bins = 8  , lo = 20 , hi = 100 ),
    Bunch(name="mu_eta"       , var="abs(<mu>_eta)"     , edges = [2.0, 2.5, 3.0, 3.5, 4.5 ]), 
    Bunch(name="e_eta"        , var="abs(<e>_eta)"      , edges = [2.0, 2.5, 3.0, 3.5, 4.5 ]), 
    Bunch(name="ptj"          , var="<jet>_pt"       , bins = 5, lo = 20, hi = 220),
    #Bunch(name="m_vis"        , var=fwd_vis_m         , bins = 100, lo = 0, hi = 50),
    #Bunch(name="m_muj"        , var=fwd_muj_m         , bins = 100, lo = 0, hi = 50),
    Bunch(name="etaj"         , var="abs(<jet>_eta)"   , edges = [2.2, 2.7, 3.2, 3.7, 4.2] ),
    Bunch(name="t_y"          , var="abs(t_y)"     ,    bins = 10, lo = 0, hi = 5.0),
    Bunch(name="tbar_y"       , var="abs(tbar_y)" ,    bins = 10, lo = 0, hi = 5.0),
    Bunch(name="t_pt"          ,var= "abs(t_pt)"     ,    bins = 20, lo = 0, hi = 100.0),
    Bunch(name="tbar_pt"       ,var= "abs(tbar_pt)"  ,    bins = 20, lo = 0, hi = 100.0)
    ]

fwdvars = [
    ["mu_pt"        , "mu_pt"           , 8  , 20 , 100 ],
    ["e_pt"         , "e_pt"            , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(mu_eta)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(e_eta)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "fwdjet_pt"       , 5, 20, 220],
    #["m_vis"        , fwd_vis_m         , 100, 0, 50],
    #["m_muj"        , fwd_muj_m         , 100, 0, 50],
    ["etaj"         , "abs(fwdjet_eta)"   , [2.2, 2.7, 3.2, 3.7, 4.2] ],
    ["t_y"          , "abs(t_y)"     ,    10, 0, 5.0],
    ["tbar_y"       , "abs(tbar_y)" ,    10, 0, 5.0],
    ["t_pt"          , "abs(t_pt)"     ,    20, 0, 100.0],
    ["tbar_pt"       , "abs(tbar_pt)" ,    20, 0, 100.0]
    ]
bwdvars = [
    ["mu_pt"        , "mu_pt"           , 8  , 20 , 100 ],
    ["e_pt"         , "e_pt"            , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(mu_eta)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(e_eta)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["ptj"          , "bwdjet_pt"       , 5, 20, 220],
    #["m_vis"        , bwd_vis_m         , 100, 0, 50],
    #["m_muj"        , bwd_muj_m         , 100, 0, 50],
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
wwmgf = TFile.Open("/hepstore/sfarry/aMC@NLO/WWb_LO/Events/run_02/mumu_WWb_madgraph.root")
wzf   = TFile.Open("/hepstore/sfarry/aMC@NLO/WZ/Events/mumu_WZ_amcatnlo.root")

wwt   = wwf.Get("ttbar")
wwmgt = wwmgf.Get('ttbar')
wzt   = wzf.Get("ttbar")

#N = ttf.Get('totEvts').GetVal()
N = t.GetEntries()
#correct by enforced branching ratio of W to mu or e
bf_ww = pow(2*0.1080,2)
bf_wz = 2*0.1080*2*0.03366

wb_mgxsec = 57.052

sf = 0.5*bf_ww/N
ww_sf = 0.5*bf_ww/wwt.GetEntries()
wz_sf = 0.5*bf_wz/wzt.GetEntries()
ww_madgraph_sf = 0.5*bf_ww*wb_mgxsec/wwmgt.GetEntries()

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
WWb_out         = {}
WZb_out         = {}
WWb_madgraph_out          = {}

def get_templates(name, t, weights = True):
    fwd_pm = MWTemplate(name+"_fwd_pm", t, fwdjet20 + mupem)
    fwd_pm.AddVars(fwdvars)
    #fwd_pm.Add2DVars(vars2d)
    fwd_pm.ApplyCut()
    if weights:
        fwd_pm.AddWeight("Central","w1010")
        fwd_pm.AddWeight("Scale1", "w1002")
        fwd_pm.AddWeight("Scale2", "w1003")
        fwd_pm.AddWeight("Scale3", "w1004")
        fwd_pm.AddWeight("Scale4", "w1005")
        fwd_pm.AddWeight("Scale5", "w1007")
        fwd_pm.AddWeight("Scale6", "w1009")
        for i in range(89):
            fwd_pm.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            fwd_pm.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        fwd_pm.AddWeight("alphas_117", "w1111")
        fwd_pm.AddWeight("alphas_119", "w1112")
    fwd_pm.FillVars()
    fwd_pm.Scale(sf)
    fwd_pm.ScaleAllWeights(sf)
    fwd_pm.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_fwd_pm.root")

    fwd_mp = MWTemplate(name+"_fwd_mp", t, fwdjet20 + mumep)
    fwd_mp.AddVars(fwdvars)
    # fwd_mp.Add2DVars(vars2d)
    fwd_mp.ApplyCut()
    if weights:
        fwd_mp.AddWeight("Central","w1010")
        fwd_mp.AddWeight("Scale1", "w1002")
        fwd_mp.AddWeight("Scale2", "w1003")
        fwd_mp.AddWeight("Scale3", "w1004")
        fwd_mp.AddWeight("Scale4", "w1005")
        fwd_mp.AddWeight("Scale5", "w1007")
        fwd_mp.AddWeight("Scale6", "w1009")
        for i in range(89):
            fwd_mp.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            fwd_mp.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        fwd_mp.AddWeight("alphas_117", "w1111")
        fwd_mp.AddWeight("alphas_119", "w1112")
    fwd_mp.FillVars()
    fwd_mp.Scale(sf)
    fwd_mp.ScaleAllWeights(sf)
    fwd_mp.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_fwd_mp.root")


    bwd_pm = MWTemplate(name+"_bwd_pm", t, bwdjet20 + mupem)
    bwd_pm.AddVars(bwdvars)
    #bwd_pm.Add2DVars(vars2d)
    bwd_pm.ApplyCut()
    if weights:
        bwd_pm.AddWeight("Central","w1010")
        bwd_pm.AddWeight("Scale1", "w1002")
        bwd_pm.AddWeight("Scale2", "w1003")
        bwd_pm.AddWeight("Scale3", "w1004")
        bwd_pm.AddWeight("Scale4", "w1005")
        bwd_pm.AddWeight("Scale5", "w1007")
        bwd_pm.AddWeight("Scale6", "w1009")
        for i in range(89):
            bwd_pm.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            bwd_pm.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        bwd_pm.AddWeight("alphas_117", "w1111")
        bwd_pm.AddWeight("alphas_119", "w1112")
    bwd_pm.FillVars()
    bwd_pm.Scale(sf)
    bwd_pm.ScaleAllWeights(sf)
    bwd_pm.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_bwd_pm.root")

    bwd_mp = MWTemplate(name+"_bwd_mp", t, bwdjet20 + mumep)
    bwd_mp.AddVars(bwdvars)
    #bwd_mp.Add2DVars(vars2d)
    bwd_mp.ApplyCut()
    if weights:
        bwd_mp.AddWeight("Central","w1010")
        bwd_mp.AddWeight("Scale1", "w1002")
        bwd_mp.AddWeight("Scale2", "w1003")
        bwd_mp.AddWeight("Scale3", "w1004")
        bwd_mp.AddWeight("Scale4", "w1005")
        bwd_mp.AddWeight("Scale5", "w1007")
        bwd_mp.AddWeight("Scale6", "w1009")
        for i in range(89):
            bwd_mp.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            bwd_mp.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        bwd_mp.AddWeight("alphas_117", "w1111")
        bwd_mp.AddWeight("alphas_119", "w1112")
    bwd_mp.FillVars()
    bwd_mp.Scale(sf)
    bwd_mp.ScaleAllWeights(sf)
    bwd_mp.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_bwd_mp.root")


    pm  = MWTemplate(name+"_pm", fwd_pm, bwd_pm)
    pm.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_pm.root")

    mp  = MWTemplate(name+"_mp", fwd_mp, bwd_mp)
    mp.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_mp.root")

    tot    = MWTemplate(name, pm, mp)
    tot.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+".root")
    return tot


def get_asymmetries(name, t, weights = True):
    fwd_fwdasy = MWTemplate(name+"_fwd_fwdasy", t, fwdjet20 + fwdasy_fwdjet)
    fwd_fwdasy.AddVars(fwdvars)
    fwd_fwdasy.ApplyCut()
    if weights:
        fwd_fwdasy.AddWeight("Central","w1010")
        fwd_fwdasy.AddWeight("Scale1", "w1002")
        fwd_fwdasy.AddWeight("Scale2", "w1003")
        fwd_fwdasy.AddWeight("Scale3", "w1004")
        fwd_fwdasy.AddWeight("Scale4", "w1005")
        fwd_fwdasy.AddWeight("Scale5", "w1007")
        fwd_fwdasy.AddWeight("Scale6", "w1009")
        for i in range(89):
            fwd_fwdasy.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            fwd_fwdasy.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        fwd_fwdasy.AddWeight("alphas_117", "w1111")
        fwd_fwdasy.AddWeight("alphas_119", "w1112")
    fwd_fwdasy.FillVars()
    fwd_fwdasy.Scale(sf)
    fwd_fwdasy.ScaleAllWeights(sf)
    fwd_fwdasy.SaveToFile()

    fwd_bwdasy = MWTemplate(name+"_fwd_bwdasy", t, fwdjet20 + bwdasy_fwdjet)
    fwd_bwdasy.AddVars(fwdvars)
    fwd_bwdasy.ApplyCut()
    if weights:
        fwd_bwdasy.AddWeight("Central","w1010")
        fwd_bwdasy.AddWeight("Scale1", "w1002")
        fwd_bwdasy.AddWeight("Scale2", "w1003")
        fwd_bwdasy.AddWeight("Scale3", "w1004")
        fwd_bwdasy.AddWeight("Scale4", "w1005")
        fwd_bwdasy.AddWeight("Scale5", "w1007")
        fwd_bwdasy.AddWeight("Scale6", "w1009")
        for i in range(89):
            fwd_bwdasy.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            fwd_bwdasy.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
            fwd_bwdasy.AddWeight("alphas_117", "w1111")
            fwd_bwdasy.AddWeight("alphas_119", "w1112")
    fwd_bwdasy.FillVars()
    fwd_bwdasy.Scale(sf)
    fwd_bwdasy.ScaleAllWeights(sf)
    fwd_bwdasy.SaveToFile()


    bwd_fwdasy = MWTemplate(name+"_bwd_fwdasy", t, bwdjet20 + fwdasy_bwdjet )
    bwd_fwdasy.AddVars(fwdvars)
    bwd_fwdasy.ApplyCut()
    if weights:
        bwd_fwdasy.AddWeight("Central","w1010")
        bwd_fwdasy.AddWeight("Scale1", "w1002")
        bwd_fwdasy.AddWeight("Scale2", "w1003")
        bwd_fwdasy.AddWeight("Scale3", "w1004")
        bwd_fwdasy.AddWeight("Scale4", "w1005")
        bwd_fwdasy.AddWeight("Scale5", "w1007")
        bwd_fwdasy.AddWeight("Scale6", "w1009")
        for i in range(89):
            bwd_fwdasy.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            bwd_fwdasy.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        bwd_fwdasy.AddWeight("alphas_117", "w1111")
        bwd_fwdasy.AddWeight("alphas_119", "w1112")
    bwd_fwdasy.FillVars()
    bwd_fwdasy.Scale(sf)
    bwd_fwdasy.ScaleAllWeights(sf)
    bwd_fwdasy.SaveToFile()


    bwd_bwdasy = MWTemplate(name+"_bwd_bwdasy", t, bwdjet20 + bwdasy_bwdjet)
    bwd_bwdasy.AddVars(fwdvars)
    bwd_bwdasy.ApplyCut()
    if weights:
        bwd_bwdasy.AddWeight("Central","w1010")
        bwd_bwdasy.AddWeight("Scale1", "w1002")
        bwd_bwdasy.AddWeight("Scale2", "w1003")
        bwd_bwdasy.AddWeight("Scale3", "w1004")
        bwd_bwdasy.AddWeight("Scale4", "w1005")
        bwd_bwdasy.AddWeight("Scale5", "w1007")
        bwd_bwdasy.AddWeight("Scale6", "w1009")
        for i in range(89):
            bwd_bwdasy.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            bwd_bwdasy.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        bwd_bwdasy.AddWeight("alphas_117", "w1111")
        bwd_bwdasy.AddWeight("alphas_119", "w1112")
    bwd_bwdasy.FillVars()
    bwd_bwdasy.Scale(sf)
    bwd_bwdasy.ScaleAllWeights(sf)
    bwd_bwdasy.SaveToFile()

    fwdasy = MWTemplate(name+"_fwdasy", fwd_fwdasy, bwd_fwdasy)
    fwdasy.SaveToFile()
    bwdasy = MWTemplate(name+"_bwdasy", fwd_bwdasy, bwd_bwdasy)
    bwdasy.SaveToFile()
    return [fwdasy, bwdasy]


def get_fiducial(name, t, fidreg = None, weights = True):
    fiducial = MWTemplate(name+"_fiducial")
    if fidreg: fiducial.SetSelCut(fidreg)
    fiducial.AddTree(t)
    fiducial.AddVars(fwdvars)
    fiducial.Add2DVars(vars2d)
    fiducial.ApplyCut()
    fiducial.AddWeight("Central","w1010")
    fiducial.AddWeight("Scale1", "w1002")
    fiducial.AddWeight("Scale2", "w1003")
    fiducial.AddWeight("Scale3", "w1004")
    fiducial.AddWeight("Scale4", "w1005")
    fiducial.AddWeight("Scale5", "w1007")
    fiducial.AddWeight("Scale6", "w1009")
    for i in range(89):
        fiducial.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        fiducial.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    fiducial.AddWeight("alphas_117", "w1111")
    fiducial.AddWeight("alphas_119", "w1112")
    fiducial.FillVars()
    fiducial.Scale(1.0/N)
    fiducial.ScaleAllWeights(1.0/N)
    fiducial.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_fiducial.root")
    return fiducial

if relaunch:
    ttbar = get_templates('ttbar_mue_13tev_amcatnlo', t)
    for v in ['ptj', 'etaj', 't_y', 'mu_eta', 'mu_pt', 'e_eta', 'e_pt']:
        ttbar_out[v] = ttbar.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_out[v+'_Scale'+str(w)] = ttbar.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_out[v+'_pdf'+str(w)] = ttbar.GetWeightHist(v, "pdf"+str(w))
        ttbar_out[v+"_alphas117"] = ttbar.GetWeightHist(v, "alphas_117")
        ttbar_out[v+"_alphas119"] = ttbar.GetWeightHist(v, "alphas_119")

    ttbar_asy = get_asymmetries('ttbar_mue_13tev_amcatnlo', t)
    ttbar_fwdasy = ttbar_asy[0]
    ttbar_bwdasy = ttbar_asy[1]

    ttbar_fiducial = get_fiducial('ttbar', t, top_fiducial)

    for v in ['ptj', 'mu_eta', 'etaj', 't_y']:
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

fwdjet20_mumu = TCut(fwdjet20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))
bwdjet20_mumu = TCut(bwdjet20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))


WWb_madgraph_fwd = MWTemplate("WWb_madgraph_fwd", wwmgt, fwdjet20_mumu)
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'fwdjet')
    var = var.replace('<mu>', 'mup')
    var = var.replace('<e>', 'mum')
    if hasattr(v, 'edges'):
        WWb_madgraph_fwd.AddVar(v.name, var, v.edges)
    else:
        WWb_madgraph_fwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
WWb_madgraph_fwd.ApplyCut()
WWb_madgraph_fwd.AddWeight("alphas_119", "w1112")
WWb_madgraph_fwd.FillVars()
WWb_madgraph_fwd.Scale(ww_madgraph_sf)
WWb_madgraph_fwd.SaveToFile()

WWb_madgraph_bwd = MWTemplate("WWb_madgraph_bwd", wwmgt, bwdjet20_mumu)
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'bwdjet')
    var = var.replace('<mu>', 'mup')
    var = var.replace('<e>', 'mum')
    if hasattr(v, 'edges'):
        WWb_madgraph_bwd.AddVar(v.name, var, v.edges)
    else:
        WWb_madgraph_bwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
WWb_madgraph_bwd.ApplyCut()
WWb_madgraph_bwd.FillVars()
WWb_madgraph_bwd.Scale(ww_madgraph_sf)
WWb_madgraph_bwd.SaveToFile()

WWb_madgraph = MWTemplate("WWb_madgraph", WWb_madgraph_fwd, WWb_madgraph_bwd)
WWb_madgraph.SaveToFile()

#ensure it's a mu e final state
mue = TCut("(mup_id == -11 && mum_id == 13) || (mup_id == -13 && mum_id == 11)")

fwdjet20_mumu = TCut(fwdjet20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))
bwdjet20_mumu = TCut(bwdjet20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))

WZb_fwd = MWTemplate("WZb_fwd", wzt, mue + fwdjet20_mumu)
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'fwdjet')
    var = var.replace('<mu>', 'mup')
    var = var.replace('<e>', 'mum')
    if hasattr(v, 'edges'):
        WZb_fwd.AddVar(v.name, var, v.edges)
    else:
        WZb_fwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
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
WZb_fwd.Scale(wz_sf)
WZb_fwd.ScaleAllWeights(wz_sf)
WZb_fwd.SaveToFile()

WZb_bwd = MWTemplate("WZb_bwd", wzt, mue + bwdjet20_mumu)
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'bwdjet')
    var = var.replace('<mu>', 'mup')
    var = var.replace('<e>', 'mum')
    if hasattr(v, 'edges'):
        WZb_bwd.AddVar(v.name, var, v.edges)
    else:
        WZb_bwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
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
WZb_bwd.Scale(wz_sf)
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


for v in ['ptj', 'etaj', 't_y']:
    WW_out[v] = WWj.GetWeightHist(v, "Central")
    for w in range(1,7):
        WW_out[v+'_Scale'+str(w)] = WWj.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WW_out[v+'_pdf'+str(w)] = WWj.GetWeightHist(v, "pdf"+str(w))
        WW_out[v+"_alphas117"] = WWj.GetWeightHist(v, "alphas_117")
    WW_out[v+"_alphas119"] = WWj.GetWeightHist(v, "alphas_119")

    WWb_out[v] = WWb.GetWeightHist(v, "Central")
    for w in range(1,7):
        WWb_out[v+'_Scale'+str(w)] = WWb.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WWb_out[v+'_pdf'+str(w)] = WWb.GetWeightHist(v, "pdf"+str(w))
        WWb_out[v+"_alphas117"] = WWb.GetWeightHist(v, "alphas_117")
    WWb_out[v+"_alphas119"] = WWb.GetWeightHist(v, "alphas_119")

#ensure it's a mu e final state
WZj_fwd = MWTemplate("WZj_fwd", wzt, mue + TCut(fwdjet20_nobtag.GetTitle().replace('mu_','mup_').replace('e_','mum_')))
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'fwdjet')
    var = var.replace('<mu>', 'mup')
    var = var.replace('<e>', 'mum')
    if hasattr(v, 'edges'):
        WZj_fwd.AddVar(v.name, var, v.edges)
    else:
        WZj_fwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
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

WZj_bwd = MWTemplate("WZj_bwd", wzt, mue + TCut(fwdjet20.GetTitle().replace('mu_','mup_').replace('e_','mum_')))
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'bwdjet')
    var = var.replace('<mu>', 'mup')
    var = var.replace('<e>', 'mum')
    if hasattr(v, 'edges'):
        WZj_bwd.AddVar(v.name, var, v.edges)
    else:
        WZj_bwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
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

for v in ['ptj', 'etaj', 't_y']:
    WZ_out[v] = WZj.GetWeightHist(v, "Central")
    for w in range(1,7):
        WZ_out[v+'_Scale'+str(w)] = WZj.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WZ_out[v+'_pdf'+str(w)] = WZj.GetWeightHist(v, "pdf"+str(w))
        WZ_out[v+"_alphas117"] = WZj.GetWeightHist(v, "alphas_117")
    WZ_out[v+"_alphas119"] = WZj.GetWeightHist(v, "alphas_119")

    WZb_out[v] = WZb.GetWeightHist(v, "Central")
    for w in range(1,7):
        WZb_out[v+'_Scale'+str(w)] = WZb.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WZb_out[v+'_pdf'+str(w)] = WZb.GetWeightHist(v, "pdf"+str(w))
        WZb_out[v+"_alphas117"] = WZb.GetWeightHist(v, "alphas_117")
    WZb_out[v+"_alphas119"] = WZb.GetWeightHist(v, "alphas_119")



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
ptj  = details('ttbar_ptj', ttbar_out['ptj'], [ttbar_out['ptj_Scale'+str(i)] for i in range(1,7)], [ttbar_out['ptj_pdf'+str(i)] for i in range(1,101)], [ttbar_out['ptj_alphas117'], ttbar_out['ptj_alphas119']])
etaj  = details('ttbar_etaj', ttbar_out['etaj'], [ttbar_out['etaj_Scale'+str(i)] for i in range(1,7)], [ttbar_out['etaj_pdf'+str(i)] for i in range(1,101)], [ttbar_out['etaj_alphas117'], ttbar_out['etaj_alphas119']])
mu_pt  = details('ttbar_mupt', ttbar_out['mu_pt'], [ttbar_out['mu_pt_Scale'+str(i)] for i in range(1,7)], [ttbar_out['mu_pt_pdf'+str(i)] for i in range(1,101)], [ttbar_out['mu_pt_alphas117'], ttbar_out['mu_pt_alphas119']])
mu_eta  = details('ttbar_mueta', ttbar_out['mu_eta'], [ttbar_out['mu_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_out['mu_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_out['mu_eta_alphas117'], ttbar_out['mu_eta_alphas119']])
e_pt  = details('ttbar_ept', ttbar_out['e_pt'], [ttbar_out['e_pt_Scale'+str(i)] for i in range(1,7)], [ttbar_out['e_pt_pdf'+str(i)] for i in range(1,101)], [ttbar_out['e_pt_alphas117'], ttbar_out['e_pt_alphas119']])
e_eta  = details('ttbar_eeta', ttbar_out['e_eta'], [ttbar_out['e_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_out['e_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_out['e_eta_alphas117'], ttbar_out['e_eta_alphas119']])

t_y_acc = ratio_details('ttbar_ty_acc', ttbar_fiducial_out['t_y'], [ttbar_fiducial_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          ttbar_out['t_y'], [ttbar_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fiducial_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fiducial_out['t_y_alphas117'], ttbar_fiducial_out['t_y_alphas119']],
                          alphas2 = [ttbar_out['t_y_alphas117'], ttbar_out['t_y_alphas119']])


etaj_WWj  = details('WWj_etaj', WW_out['etaj'], [WW_out['etaj_Scale'+str(i)] for i in range(1,7)], [WW_out['etaj_pdf'+str(i)] for i in range(1,101)], [WW_out['etaj_alphas117'], WW_out['etaj_alphas119']])
etaj_WZj  = details('WZj_etaj', WZ_out['etaj'], [WZ_out['etaj_Scale'+str(i)] for i in range(1,7)], [WZ_out['etaj_pdf'+str(i)] for i in range(1,101)], [WZ_out['etaj_alphas117'], WZ_out['etaj_alphas119']])

etaj_WWb  = details('WWb_etaj', WWb_out['etaj'], [WWb_out['etaj_Scale'+str(i)] for i in range(1,7)], [WWb_out['etaj_pdf'+str(i)] for i in range(1,101)], [WWb_out['etaj_alphas117'], WWb_out['etaj_alphas119']])
etaj_WZb  = details('WZb_etaj', WZb_out['etaj'], [WZb_out['etaj_Scale'+str(i)] for i in range(1,7)], [WZb_out['etaj_pdf'+str(i)] for i in range(1,101)], [WZb_out['etaj_alphas117'], WZb_out['etaj_alphas119']])

wwb_madgraph_xsec = WWb_madgraph.GetNormEvts()

output = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_amcatnlo_predictions.root", "RECREATE")
ptj.write()
etaj.write()
mu_pt.write()
mu_eta.write()
e_pt.write()
e_eta.write()
TParameter(float)("WWb_madgraph_xsec", wwb_madgraph_xsec).Write()
t_y_acc.write()
etaj_WWj.write()
etaj_WZj.write()
etaj_WWb.write()
etaj_WZb.write()
output.Close()
