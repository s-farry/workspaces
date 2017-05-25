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
    Bunch(name="t_y"          , var="abs(t_y)"     ,    bins = 10, lo = 0, hi = 5.0),
    Bunch(name="tbar_y"       , var="abs(tbar_y)" ,    bins = 10, lo = 0, hi = 5.0),
    Bunch(name="t_pt"          ,var= "abs(t_pt)"     ,    bins = 20, lo = 0, hi = 100.0),
    Bunch(name="tbar_pt"       ,var= "abs(tbar_pt)"  ,    bins = 20, lo = 0, hi = 100.0)
    ]

fwdvars = [
    ["lp_pt"        , "lp_pt"         , 8  , 20 , 100 ],
    ["lm_pt"         , "lm_pt"        , 8  , 20 , 100 ],
    ["lp_eta"       , "abs(lp_eta)"   , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["lm_eta"        , "abs(lm_eta)"  , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["dy_ll"         , "abs(lp_eta - lm_eta)", 5, 0, 2.5],
    #["m_vis"        , fwd_vis_m         , 100, 0, 50],
    #["m_muj"        , fwd_muj_m         , 100, 0, 50],
    ["t_y"          , "abs(t_y)"      ,    10, 0, 5.0],
    ["tbar_y"       , "abs(tbar_y)"   ,    10, 0, 5.0],
    ["t_pt"          , "abs(t_pt)"    ,    20, 0, 100.0],
    ["tbar_pt"       , "abs(tbar_pt)" ,    20, 0, 100.0],
    ["pseudot_rap"   , "abs(llj_y)"   ,  10, 0, 4],
    ["pseudot_eta"   , "abs(llj_eta)" ,  5, 2.0, 4.0]
    ]
bwdvars = [
    ["lp_pt"        , "lp_pt"         , 8  , 20 , 100 ],
    ["lm_pt"         , "lm_pt"        , 8  , 20 , 100 ],
    ["lp_eta"       , "abs(lp_eta)"   , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["lm_eta"        , "abs(lm_eta)"  , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["dy_ll"         , "abs(lp_eta - lm_eta)", 5, 0, 2.5],
    ["t_y"          , "abs(t_y)"      ,    10, 0, 5.0],
    ["tbar_y"       , "abs(tbar_y)"   ,    10, 0, 5.0],
    ["t_pt"          , "abs(t_pt)"    ,    20, 0, 100.0],
    ["tbar_pt"       , "abs(tbar_pt)" ,    20, 0, 100.0],
    ["pseudot_rap"   , "abs(llj_y)"   ,  10, 0, 4],
    ["pseudot_eta"   , "abs(llj_eta)" ,  5, 2.0, 4.0]
    ]

vars2d = [ ['t_y', 'tbar_y'] ]

pltvars = ['ptj', 'eta', 'yj']

lhcbfwd = TCut("lp_eta > 2.0  && lp_eta <  4.5 && lm_eta > 2.0  && lm_eta <  4.5")
lhcbbwd = TCut("lp_eta < -2.0 && lp_eta > -4.5 && lm_eta < -2.0 && lm_eta > -4.5")

pt20  = TCut("lp_pt  > 20 && lm_pt > 20")

fwdjet_btag = TCut("abs(fwdjet_flav) == 5")
bwdjet_btag = TCut("abs(bwdjet_flav) == 5")

fwdjetpt10 = TCut("fwdjet_pt > 10")
fwdjetpt20 = TCut("fwdjet_pt > 20")

bwdjetpt10 = TCut("bwdjet_pt > 10")
bwdjetpt20 = TCut("bwdjet_pt > 20")

fwdlhcb20 = pt20 + lhcbfwd
bwdlhcb20 = pt20 + lhcbbwd

bwdjet20 = pt20 + lhcbbwd + bwdjetpt20 + bwdjet_btag
fwdjet20 = pt20 + lhcbfwd + fwdjetpt20 + fwdjet_btag
bwdlhcb20_nobtag = pt20 + lhcbbwd + bwdjetpt20
fwdjet20_nobtag = pt20 + lhcbfwd + fwdjetpt20

fwdasy = TCut("abs(lp_eta) > abs(lm_eta)")
bwdasy = TCut("abs(lm_eta) > abs(lp_eta)")

ttf   = TFile.Open("/hepstore/sfarry/aMCatNLO/ttbar/Events/llj_ttbar_amcatnlo_13tev_madspin.root")
t     = ttf.Get("ttbar")

wwf   = TFile.Open("/hepstore/sfarry/aMCatNLO/WW/Events/ll_WW_amcatnlo_13tev.root")
wwmgf = TFile.Open("/hepstore/sfarry/aMCatNLO/WWb_LO/Events/run_02/mumu_WWb_madgraph.root")
wzf   = TFile.Open("/hepstore/sfarry/aMCatNLO/WZ/Events/ll_WZ_amcatnlo_13tev.root")

wwt   = wwf.Get("ttbar")
wwmgt = wwmgf.Get('ttbar')
wzt   = wzf.Get("ttbar")

#N = ttf.Get('totEvts').GetVal()
N = t.GetEntries()
#correct by enforced branching ratio of W to mu or e
bf_ww = pow(2*0.1080,2)
bf_wz = 2*0.1080*2*0.03366
bf_ee = pow(0.1080,2)

wb_mgxsec = 57.052

#one factor of 1/2 for fwd and bwd, another for using muons and electrons
top_sf = 0.5*2.0/N
ww_sf  = 0.5*0.5*bf_ww/wwt.GetEntries()
wz_sf  = 0.5*bf_wz/wzt.GetEntries()
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

def get_templates(name, t, weights = True, selections = [fwdjet20, bwdjet20], sf = top_sf):
    fwd_fwdasy = MWTemplate(name+"_fwd_fwdasy", t, selections[0] + fwdasy)
    fwd_fwdasy.AddVars(fwdvars)
    #fwd_fwdasy.Add2DVars(vars2d)
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
    #fwd_pm.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_fwd_pm.root")

    fwd_bwdasy = MWTemplate(name+"_fwd_bwdasy", t, selections[0] + bwdasy)
    fwd_bwdasy.AddVars(fwdvars)
    # fwd_bwdasy.Add2DVars(vars2d)
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

    bwd_fwdasy = MWTemplate(name+"_bwd_fwdasy", t, selections[1] + fwdasy)
    bwd_fwdasy.AddVars(bwdvars)
    #bwd_fwdasy.Add2DVars(vars2d)
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

    bwd_bwdasy = MWTemplate(name+"_bwd_bwdasy", t, selections[1] + bwdasy)
    bwd_bwdasy.AddVars(bwdvars)
    #bwd_bwdasy.Add2DVars(vars2d)
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


    ttbar_fwdasy  = MWTemplate(name+"_fwdasy", fwd_fwdasy, bwd_fwdasy)
    #pm.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_pm.root")

    ttbar_bwdasy  = MWTemplate(name+"_bwdasy", fwd_bwdasy, bwd_bwdasy)
    #mp.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_mp.root")

    tot    = MWTemplate(name, ttbar_fwdasy, ttbar_bwdasy)
    tot.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+".root")
    return [tot, ttbar_fwdasy, ttbar_bwdasy]

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
    fiducial.Scale(1.0/(N*bf_ee))
    fiducial.ScaleAllWeights(1.0/(N*bf_ee))
    fiducial.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_fiducial.root")
    return fiducial

if relaunch:
    ttbar = get_templates('ttbar_mueb_13tev_amcatnlo', t)
    for v in ['t_y', 'lp_eta', 'lp_pt', 'lm_eta', 'lm_pt']:
        ttbar_out[v] = ttbar[0].GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_out[v+'_Scale'+str(w)] = ttbar[0].GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_out[v+'_pdf'+str(w)] = ttbar[0].GetWeightHist(v, "pdf"+str(w))
        ttbar_out[v+"_alphas117"] = ttbar[0].GetWeightHist(v, "alphas_117")
        ttbar_out[v+"_alphas119"] = ttbar[0].GetWeightHist(v, "alphas_119")

    for v in ['lm_eta', 'pseudot_rap', 'pseudot_eta']:
        ttbar_fwdasy_out[v] = ttbar[1].GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_fwdasy_out[v+'_Scale'+str(w)] = ttbar[1].GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_fwdasy_out[v+'_pdf'+str(w)] = ttbar[1].GetWeightHist(v, "pdf"+str(w))
        ttbar_fwdasy_out[v+"_alphas117"] = ttbar[1].GetWeightHist(v, "alphas_117")
        ttbar_fwdasy_out[v+"_alphas119"] = ttbar[1].GetWeightHist(v, "alphas_119")

        ttbar_bwdasy_out[v] = ttbar[2].GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_bwdasy_out[v+'_Scale'+str(w)] = ttbar[2].GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_bwdasy_out[v+'_pdf'+str(w)] = ttbar[2].GetWeightHist(v, "pdf"+str(w))
        ttbar_bwdasy_out[v+"_alphas117"] = ttbar[2].GetWeightHist(v, "alphas_117")
        ttbar_bwdasy_out[v+"_alphas119"] = ttbar[2].GetWeightHist(v, "alphas_119")

    ttbar_fiducial = get_fiducial('ttbar', t, top_fiducial)

    for v in ['lp_eta', 'lm_eta', 't_y']:
        ttbar_fiducial_out[v] = ttbar_fiducial.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_fiducial_out[v+'_Scale'+str(w)] = ttbar_fiducial.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_fiducial_out[v+'_pdf'+str(w)] = ttbar_fiducial.GetWeightHist(v, "pdf"+str(w))
        ttbar_fiducial_out[v+"_alphas117"] = ttbar_fiducial.GetWeightHist(v, "alphas_117")
        ttbar_fiducial_out[v+"_alphas119"] = ttbar_fiducial.GetWeightHist(v, "alphas_119")


WW_fwd = MWTemplate("WW_mueb_fwd", wwt, fwdjet20)
WW_fwd.AddVars(fwdvars)
WW_fwd.ApplyCut()
WW_fwd.AddWeight("Central","w1010")
WW_fwd.AddWeight("Scale1", "w1002")
WW_fwd.AddWeight("Scale2", "w1003")
WW_fwd.AddWeight("Scale3", "w1004")
WW_fwd.AddWeight("Scale4", "w1005")
WW_fwd.AddWeight("Scale5", "w1007")
WW_fwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WW_fwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WW_fwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WW_fwd.AddWeight("alphas_117", "w1111")
WW_fwd.AddWeight("alphas_119", "w1112")
WW_fwd.FillVars()
WW_fwd.Scale(ww_sf)
WW_fwd.ScaleAllWeights(ww_sf)
WW_fwd.SaveToFile()

WW_bwd = MWTemplate("WW_mueb_bwd", wwt, bwdjet20)
WW_bwd.AddVars(bwdvars)
WW_bwd.ApplyCut()
WW_bwd.AddWeight("Central","w1010")
WW_bwd.AddWeight("Scale1", "w1002")
WW_bwd.AddWeight("Scale2", "w1003")
WW_bwd.AddWeight("Scale3", "w1004")
WW_bwd.AddWeight("Scale4", "w1005")
WW_bwd.AddWeight("Scale5", "w1007")
WW_bwd.AddWeight("Scale6", "w1009")
for i in range(89):
    WW_bwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WW_bwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WW_bwd.AddWeight("alphas_117", "w1111")
WW_bwd.AddWeight("alphas_119", "w1112")
WW_bwd.FillVars()
WW_bwd.Scale(ww_sf)
WW_bwd.ScaleAllWeights(ww_sf)
WW_bwd.SaveToFile()

WW = MWTemplate("WW_mueb", WW_fwd, WW_bwd)
WW.SaveToFile()

fwdlhcb20_mumu = TCut(fwdlhcb20.GetTitle().replace('lp_','mup_').replace('lm_','mum_'))
bwdlhcb20_mumu = TCut(bwdlhcb20.GetTitle().replace('lp_','mup_').replace('lm_','mum_'))


#ensure it's a mu e final state
mue = TCut("(lp_id == -11 && lm_id == 13) || (lp_id == -13 && lm_id == 11)")

#fwdlhcb20_mumu = TCut(fwdlhcb20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))
#bwdlhcb20_mumu = TCut(bwdlhcb20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))

WZ_fwd = MWTemplate("WZ_mueb_fwd", wzt, mue + fwdlhcb20)
WZ_fwd.AddVars(fwdvars)
WZ_fwd.ApplyCut()
WZ_fwd.AddWeight("Central","w1010")
WZ_fwd.AddWeight("Scale1" , "w1002")
WZ_fwd.AddWeight("Scale2" , "w1003")
WZ_fwd.AddWeight("Scale3" , "w1004")
WZ_fwd.AddWeight("Scale4" , "w1005")
WZ_fwd.AddWeight("Scale5" , "w1007")
WZ_fwd.AddWeight("Scale6" , "w1009")
for i in range(89):
    WZ_fwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WZ_fwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WZ_fwd.AddWeight("alphas_117", "w1111")
WZ_fwd.AddWeight("alphas_119", "w1112")
WZ_fwd.FillVars()
WZ_fwd.Scale(wz_sf)
WZ_fwd.ScaleAllWeights(wz_sf)
WZ_fwd.SaveToFile()

WZ_bwd = MWTemplate("WZ_mueb_bwd", wzt, mue + bwdlhcb20)
WZ_bwd.AddVars(bwdvars)
'''
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'bwdjet')
    var = var.replace('<mu>' , 'lp')
    var = var.replace('<e>'  , 'lm')
    if hasattr(v, 'edges'):
        WZ_bwd.AddVar(v.name, var, v.edges)
    else:
        WZ_bwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
'''
WZ_bwd.ApplyCut()
WZ_bwd.AddWeight("Central","w1010")
WZ_bwd.AddWeight("Scale1" , "w1002")
WZ_bwd.AddWeight("Scale2" , "w1003")
WZ_bwd.AddWeight("Scale3" , "w1004")
WZ_bwd.AddWeight("Scale4" , "w1005")
WZ_bwd.AddWeight("Scale5" , "w1007")
WZ_bwd.AddWeight("Scale6" , "w1009")
for i in range(89):
    WZ_bwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
for i in range(11):
    WZ_bwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
WZ_bwd.AddWeight("alphas_117", "w1111")
WZ_bwd.AddWeight("alphas_119", "w1112")
WZ_bwd.FillVars()
WZ_bwd.Scale(wz_sf)
WZ_bwd.ScaleAllWeights(wz_sf)
WZ_bwd.SaveToFile()


WZ = MWTemplate("WZ_mueb", WZ_fwd, WZ_bwd)
WZ.SaveToFile()

for v in ['lp_eta']:
    WW_out[v] = WW.GetWeightHist(v, "Central")
    for w in range(1,7):
        WW_out[v+'_Scale'+str(w)] = WW.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WW_out[v+'_pdf'+str(w)] = WW.GetWeightHist(v, "pdf"+str(w))
        WW_out[v+"_alphas117"]  = WW.GetWeightHist(v, "alphas_117")
    WW_out[v+"_alphas119"]    = WW.GetWeightHist(v, "alphas_119")

for v in ['lp_eta']:
    WZ_out[v] = WZ.GetWeightHist(v, "Central")
    for w in range(1,7):
        WZ_out[v+'_Scale'+str(w)] = WZ.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WZ_out[v+'_pdf'+str(w)] = WZ.GetWeightHist(v, "pdf"+str(w))
        WZ_out[v+"_alphas117"] = WZ.GetWeightHist(v, "alphas_117")
    WZ_out[v+"_alphas119"] = WZ.GetWeightHist(v, "alphas_119")

#Get the various components
lp_pt  = details('ttbar_lp_pt', ttbar_out['lp_pt'], [ttbar_out['lp_pt_Scale'+str(i)] for i in range(1,7)], [ttbar_out['lp_pt_pdf'+str(i)] for i in range(1,101)], [ttbar_out['lp_pt_alphas117'], ttbar_out['lp_pt_alphas119']])
lp_eta  = details('ttbar_lp_eta', ttbar_out['lp_eta'], [ttbar_out['lp_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_out['lp_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_out['lp_eta_alphas117'], ttbar_out['lp_eta_alphas119']])
lm_pt  = details('ttbar_lm_pt', ttbar_out['lm_pt'], [ttbar_out['lm_pt_Scale'+str(i)] for i in range(1,7)], [ttbar_out['lm_pt_pdf'+str(i)] for i in range(1,101)], [ttbar_out['lm_pt_alphas117'], ttbar_out['lm_pt_alphas119']])
lm_eta  = details('ttbar_lm_eta', ttbar_out['lm_eta'], [ttbar_out['lm_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_out['lm_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_out['lm_eta_alphas117'], ttbar_out['lm_eta_alphas119']])

t_y_acc = ratio_details('ttbar_ty_acc', ttbar_fiducial_out['t_y'], [ttbar_fiducial_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          ttbar_out['t_y'], [ttbar_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fiducial_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fiducial_out['t_y_alphas117'], ttbar_fiducial_out['t_y_alphas119']],
                          alphas2 = [ttbar_out['t_y_alphas117'], ttbar_out['t_y_alphas119']])

t_y  = details('ttbar_t_y', ttbar_fiducial_out['t_y'], [ttbar_fiducial_out['t_y_Scale'+str(i)] for i in range(1,7)], [ttbar_fiducial_out['t_y_pdf'+str(i)] for i in range(1,101)], [ttbar_fiducial_out['t_y_alphas117'], ttbar_fiducial_out['t_y_alphas119']])

lp_eta_WW  = details('WW_lp_eta', WW_out['lp_eta'], [WW_out['lp_eta_Scale'+str(i)] for i in range(1,7)], [WW_out['lp_eta_pdf'+str(i)] for i in range(1,101)], [WW_out['lp_eta_alphas117'], WW_out['lp_eta_alphas119']])

lm_eta_asy = asymm_details('ttbar_lm_eta_asy', ttbar_fwdasy_out['lm_eta'],
                          [ttbar_fwdasy_out['lm_eta_Scale'+str(i)] for i in range(1,7)],
                          ttbar_bwdasy_out['lm_eta'], 
                          [ttbar_bwdasy_out['lm_eta_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fwdasy_out['lm_eta_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_bwdasy_out['lm_eta_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fwdasy_out['lm_eta_alphas117'],
                                     ttbar_fwdasy_out['lm_eta_alphas119']],
                          alphas2 = [ttbar_bwdasy_out['lm_eta_alphas117'],
                                     ttbar_bwdasy_out['lm_eta_alphas119']])

pseudot_rap_asy = asymm_details('ttbar_pseudot_rap_asy', ttbar_fwdasy_out['pseudot_rap'],
                          [ttbar_fwdasy_out['pseudot_rap_Scale'+str(i)] for i in range(1,7)],
                          ttbar_bwdasy_out['pseudot_rap'], 
                          [ttbar_bwdasy_out['pseudot_rap_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fwdasy_out['pseudot_rap_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_bwdasy_out['pseudot_rap_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fwdasy_out['pseudot_rap_alphas117'],
                                     ttbar_fwdasy_out['pseudot_rap_alphas119']],
                          alphas2 = [ttbar_bwdasy_out['pseudot_rap_alphas117'],
                                     ttbar_bwdasy_out['pseudot_rap_alphas119']])

pseudot_eta_asy = asymm_details('ttbar_pseudot_eta_asy', ttbar_fwdasy_out['pseudot_eta'],
                          [ttbar_fwdasy_out['pseudot_eta_Scale'+str(i)] for i in range(1,7)],
                          ttbar_bwdasy_out['pseudot_eta'], 
                          [ttbar_bwdasy_out['pseudot_eta_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fwdasy_out['pseudot_eta_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_bwdasy_out['pseudot_eta_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fwdasy_out['pseudot_eta_alphas117'],
                                     ttbar_fwdasy_out['pseudot_eta_alphas119']],
                          alphas2 = [ttbar_bwdasy_out['pseudot_eta_alphas117'],
                                     ttbar_bwdasy_out['pseudot_eta_alphas119']])

lp_eta_WZ  = details('WZ_lp_eta', WZ_out['lp_eta'], [WZ_out['lp_eta_Scale'+str(i)] for i in range(1,7)], [WZ_out['lp_eta_pdf'+str(i)] for i in range(1,101)], [WZ_out['lp_eta_alphas117'], WZ_out['lp_eta_alphas119']])

output = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_mueb_13tev_amcatnlo_predictions.root", "RECREATE")
lp_pt.write()
lp_eta.write()
lm_pt.write()
lm_eta.write()
t_y_acc.write()
t_y.write()
lp_eta_WW.write()
lp_eta_WZ.write()
lm_eta_asy.write()
pseudot_rap_asy.write()
pseudot_eta_asy.write()
output.Close()
