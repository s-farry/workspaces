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
    ["mu_pt"        , "mu_pt"           , 8  , 20 , 100 ],
    ["e_pt"         , "e_pt"            , 8  , 20 , 100 ],
    ["mu_eta"       , "abs(mu_eta)"     , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    ["e_eta"        , "abs(e_eta)"      , [2.0, 2.5, 3.0, 3.5, 4.5 ]], 
    #["m_vis"        , fwd_vis_m         , 100, 0, 50],
    #["m_muj"        , fwd_muj_m         , 100, 0, 50],
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
    ["t_y"          , "abs(t_y)"     ,    10, 0, 5.0],
    ["tbar_y"       , "abs(tbar_y)" ,    10, 0, 5.0],
    ["t_pt"          , "abs(t_pt)"     ,    20, 0, 100.0],
    ["tbar_pt"       , "abs(tbar_pt)" ,    20, 0, 100.0]
    ]

vars2d = [ ['t_y', 'tbar_y'] ]

pltvars = ['ptj', 'eta', 'yj']

lhcbfwd = TCut("mu_eta > 2.0 && mu_eta < 4.5 && e_eta > 2.0 && e_eta < 4.5")
lhcbbwd = TCut("mu_eta < -2.0 && mu_eta > -4.5 && e_eta < -2.0 && e_eta > -4.5")

pt20  = TCut("mu_pt  > 20 && e_pt > 20")

fwdjet_btag = TCut("abs(fwdjet_flav) == 5")
bwdjet_btag = TCut("abs(bwdjet_flav) == 5")

fwdjet_veto = TCut("fwdjet_pt == 0")
bwdjet_veto = TCut("bwdjet_pt == 0")


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

top_sf = 0.5*bf_ww/N
ww_sf = 0.5*bf_ww/wwt.GetEntries()
wz_sf = 0.5*bf_wz/wzt.GetEntries()
ww_madgraph_sf = 0.5*bf_ww*wb_mgxsec/wwmgt.GetEntries()

fwd_vis_m = "sqrt((mu_E + e_E + fwdjet_E)^2 - (mu_px + e_px + fwdjet_px)^2 - (mu_py + e_py + fwdjet_py)^2 - (mu_pz + e_pz + fwdjet_pz)^2)"
bwd_vis_m = fwd_vis_m.replace('fwdjet', 'bwdjet')

relaunch = True

top_fiducial = TCut("abs(t_y) > 2.0 && abs(t_y) < 5.0 && abs(tbar_y) > 2.0 && abs(tbar_y) < 5.0 && t_y*tbar_y > 0 && t_pt > 10.0 && tbar_pt > 10.0")

top_fiducial_fwd = TCut("t_y > 2.0 && t_y < 5.0 && tbar_y > 2.0 && tbar_y < 5.0 && t_pt > 10.0 && tbar_pt > 10.0")

ttbar_out          = {}
ttbar_jetveto_out  = {}
ttbar_fiducial_out = {}
ttbar_fwdasy_out   = {}
ttbar_bwdasy_out   = {}

WW_out          = {}
WW_jetveto_out  = {}
WZ_out          = {}
WWb_out         = {}
WZb_out         = {}
WWb_madgraph_out          = {}

def get_templates(name, t, weights = True, selections = [fwdlhcb20, bwdlhcb20], sf = top_sf):
    fwd_pm = MWTemplate(name+"_fwd_pm", t, selections[0] + mupem)
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
    #fwd_pm.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_fwd_pm.root")

    fwd_mp = MWTemplate(name+"_fwd_mp", t, selections[0] + mumep)
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

    bwd_pm = MWTemplate(name+"_bwd_pm", t, selections[1] + mupem)
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

    bwd_mp = MWTemplate(name+"_bwd_mp", t, selections[1] + mumep)
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


    pm  = MWTemplate(name+"_pm", fwd_pm, bwd_pm)
    #pm.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_pm.root")

    mp  = MWTemplate(name+"_mp", fwd_mp, bwd_mp)
    #mp.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_mp.root")

    tot    = MWTemplate(name, pm, mp)
    tot.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_mue.root")
    return tot

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
    fiducial.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+"_mue_fiducial.root")
    return fiducial

if relaunch:
    ttbar = get_templates('ttbar_mue_13tev_amcatnlo', t)
    for v in ['t_y', 'mu_eta', 'mu_pt', 'e_eta', 'e_pt']:
        ttbar_out[v] = ttbar.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_out[v+'_Scale'+str(w)] = ttbar.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_out[v+'_pdf'+str(w)] = ttbar.GetWeightHist(v, "pdf"+str(w))
        ttbar_out[v+"_alphas117"] = ttbar.GetWeightHist(v, "alphas_117")
        ttbar_out[v+"_alphas119"] = ttbar.GetWeightHist(v, "alphas_119")

    ttbar_jetveto = get_templates('ttbar_jetveto_mue_13tev_amcatnlo', t, selections = [fwdlhcb20 + fwdjet_veto, bwdlhcb20 + bwdjet_veto])
    for v in ['t_y', 'mu_eta', 'mu_pt', 'e_eta', 'e_pt']:
        ttbar_jetveto_out[v] = ttbar_jetveto.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_jetveto_out[v+'_Scale'+str(w)] = ttbar_jetveto.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_jetveto_out[v+'_pdf'+str(w)] = ttbar_jetveto.GetWeightHist(v, "pdf"+str(w))
        ttbar_jetveto_out[v+"_alphas117"] = ttbar_jetveto.GetWeightHist(v, "alphas_117")
        ttbar_jetveto_out[v+"_alphas119"] = ttbar_jetveto.GetWeightHist(v, "alphas_119")

    WW_jetveto = get_templates('WW_jetveto_mue_13tev_amcatnlo', wwt, selections = [fwdlhcb20 + fwdjet_veto, bwdlhcb20 + bwdjet_veto], sf = ww_sf)
    for v in ['t_y', 'mu_eta', 'mu_pt', 'e_eta', 'e_pt']:
        WW_jetveto_out[v] = WW_jetveto.GetWeightHist(v, "Central")
        for w in range(1,7):
            WW_jetveto_out[v+'_Scale'+str(w)] = WW_jetveto.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            WW_jetveto_out[v+'_pdf'+str(w)] = WW_jetveto.GetWeightHist(v, "pdf"+str(w))
        WW_jetveto_out[v+"_alphas117"] = WW_jetveto.GetWeightHist(v, "alphas_117")
        WW_jetveto_out[v+"_alphas119"] = WW_jetveto.GetWeightHist(v, "alphas_119")



    ttbar_fiducial = get_fiducial('ttbar', t, top_fiducial)

    for v in ['mu_eta', 't_y']:
        ttbar_fiducial_out[v] = ttbar_fiducial.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_fiducial_out[v+'_Scale'+str(w)] = ttbar_fiducial.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_fiducial_out[v+'_pdf'+str(w)] = ttbar_fiducial.GetWeightHist(v, "pdf"+str(w))
        ttbar_fiducial_out[v+"_alphas117"] = ttbar_fiducial.GetWeightHist(v, "alphas_117")
        ttbar_fiducial_out[v+"_alphas119"] = ttbar_fiducial.GetWeightHist(v, "alphas_119")

WW_fwd = MWTemplate("WW_mue_fwd", wwt, fwdlhcb20)
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

WW_bwd = MWTemplate("WW_mue_bwd", wwt, bwdlhcb20)
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


WW = MWTemplate("WW_mue", WW_fwd, WW_bwd)
WW.SaveToFile()

fwdlhcb20_mumu = TCut(fwdlhcb20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))
bwdlhcb20_mumu = TCut(bwdlhcb20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))


#ensure it's a mu e final state
mue = TCut("(mup_id == -11 && mum_id == 13) || (mup_id == -13 && mum_id == 11)")

fwdlhcb20_mumu = TCut(fwdlhcb20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))
bwdlhcb20_mumu = TCut(bwdlhcb20.GetTitle().replace('mu_','mup_').replace('e_','mum_'))

WZ_fwd = MWTemplate("WZ_mue_fwd", wzt, mue + fwdlhcb20_mumu)
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'fwdjet')
    var = var.replace('<mu>', 'mup')
    var = var.replace('<e>', 'mum')
    if hasattr(v, 'edges'):
        WZ_fwd.AddVar(v.name, var, v.edges)
    else:
        WZ_fwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
WZ_fwd.ApplyCut()
WZ_fwd.AddWeight("Central","w1010")
WZ_fwd.AddWeight("Scale1", "w1002")
WZ_fwd.AddWeight("Scale2", "w1003")
WZ_fwd.AddWeight("Scale3", "w1004")
WZ_fwd.AddWeight("Scale4", "w1005")
WZ_fwd.AddWeight("Scale5", "w1007")
WZ_fwd.AddWeight("Scale6", "w1009")
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

WZ_bwd = MWTemplate("WZ_mue_bwd", wzt, mue + bwdlhcb20_mumu)
for v in variables:
    var = v.var
    var = var.replace('<jet>', 'bwdjet')
    var = var.replace('<mu>', 'mup')
    var = var.replace('<e>', 'mum')
    if hasattr(v, 'edges'):
        WZ_bwd.AddVar(v.name, var, v.edges)
    else:
        WZ_bwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
WZ_bwd.ApplyCut()
WZ_bwd.AddWeight("Central","w1010")
WZ_bwd.AddWeight("Scale1", "w1002")
WZ_bwd.AddWeight("Scale2", "w1003")
WZ_bwd.AddWeight("Scale3", "w1004")
WZ_bwd.AddWeight("Scale4", "w1005")
WZ_bwd.AddWeight("Scale5", "w1007")
WZ_bwd.AddWeight("Scale6", "w1009")
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


WZ = MWTemplate("WZ_mue", WZ_fwd, WZ_bwd)
WZ.SaveToFile()

for v in ['mu_eta']:
    WW_out[v] = WW.GetWeightHist(v, "Central")
    for w in range(1,7):
        WW_out[v+'_Scale'+str(w)] = WW.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WW_out[v+'_pdf'+str(w)] = WW.GetWeightHist(v, "pdf"+str(w))
        WW_out[v+"_alphas117"]  = WW.GetWeightHist(v, "alphas_117")
    WW_out[v+"_alphas119"]    = WW.GetWeightHist(v, "alphas_119")

for v in ['mu_eta']:
    WZ_out[v] = WZ.GetWeightHist(v, "Central")
    for w in range(1,7):
        WZ_out[v+'_Scale'+str(w)] = WZ.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        WZ_out[v+'_pdf'+str(w)] = WZ.GetWeightHist(v, "pdf"+str(w))
        WZ_out[v+"_alphas117"] = WZ.GetWeightHist(v, "alphas_117")
    WZ_out[v+"_alphas119"] = WZ.GetWeightHist(v, "alphas_119")

#Get the various components
mu_pt  = details('ttbar_mupt', ttbar_out['mu_pt'], [ttbar_out['mu_pt_Scale'+str(i)] for i in range(1,7)], [ttbar_out['mu_pt_pdf'+str(i)] for i in range(1,101)], [ttbar_out['mu_pt_alphas117'], ttbar_out['mu_pt_alphas119']])
mu_eta  = details('ttbar_mueta', ttbar_out['mu_eta'], [ttbar_out['mu_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_out['mu_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_out['mu_eta_alphas117'], ttbar_out['mu_eta_alphas119']])
mu_eta_jetveto  = details('ttbar_jetveto_mueta', ttbar_jetveto_out['mu_eta'], [ttbar_jetveto_out['mu_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_jetveto_out['mu_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_jetveto_out['mu_eta_alphas117'], ttbar_jetveto_out['mu_eta_alphas119']])
e_pt  = details('ttbar_ept', ttbar_out['e_pt'], [ttbar_out['e_pt_Scale'+str(i)] for i in range(1,7)], [ttbar_out['e_pt_pdf'+str(i)] for i in range(1,101)], [ttbar_out['e_pt_alphas117'], ttbar_out['e_pt_alphas119']])
e_eta  = details('ttbar_eeta', ttbar_out['e_eta'], [ttbar_out['e_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_out['e_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_out['e_eta_alphas117'], ttbar_out['e_eta_alphas119']])

t_y_acc = ratio_details('ttbar_ty_acc', ttbar_fiducial_out['t_y'], [ttbar_fiducial_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          ttbar_out['t_y'], [ttbar_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fiducial_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fiducial_out['t_y_alphas117'], ttbar_fiducial_out['t_y_alphas119']],
                          alphas2 = [ttbar_out['t_y_alphas117'], ttbar_out['t_y_alphas119']])


mu_eta_WW  = details('WW_mu_eta', WW_out['mu_eta'], [WW_out['mu_eta_Scale'+str(i)] for i in range(1,7)], [WW_out['mu_eta_pdf'+str(i)] for i in range(1,101)], [WW_out['mu_eta_alphas117'], WW_out['mu_eta_alphas119']])

mu_eta_WW_jetveto  = details('WW_mu_eta_jetveto', WW_jetveto_out['mu_eta'], [WW_jetveto_out['mu_eta_Scale'+str(i)] for i in range(1,7)], [WW_jetveto_out['mu_eta_pdf'+str(i)] for i in range(1,101)], [WW_jetveto_out['mu_eta_alphas117'], WW_jetveto_out['mu_eta_alphas119']])
mu_eta_WW_jetveto_acc = ratio_details('mu_eta_WW_jetveto_acc',
                                      WW_jetveto_out['mu_eta'],
                                      [WW_jetveto_out['mu_eta_Scale'+str(i)] for i in range(1,7)],
                                      WW_out['mu_eta'], [WW_out['mu_eta_Scale'+str(i)] for i in range(1,7)],
                                      pdfs1 = [WW_jetveto_out['mu_eta_pdf'+str(i)] for i in range(1,101)],
                                      pdfs2 = [WW_out['mu_eta_pdf'+str(i)] for i in range(1,101)],
                                      alphas1 = [WW_jetveto_out['mu_eta_alphas117'], WW_jetveto_out['mu_eta_alphas119']],
                                      alphas2 = [WW_out['mu_eta_alphas117'], WW_out['mu_eta_alphas119']])

mu_eta_ttbar_jetveto_acc = ratio_details('mu_eta_ttbar_jetveto_acc',
                                      ttbar_jetveto_out['mu_eta'],
                                      [ttbar_jetveto_out['mu_eta_Scale'+str(i)] for i in range(1,7)],
                                      ttbar_out['mu_eta'], [ttbar_out['mu_eta_Scale'+str(i)] for i in range(1,7)],
                                      pdfs1 = [ttbar_jetveto_out['mu_eta_pdf'+str(i)] for i in range(1,101)],
                                      pdfs2 = [ttbar_out['mu_eta_pdf'+str(i)] for i in range(1,101)],
                                      alphas1 = [ttbar_jetveto_out['mu_eta_alphas117'], ttbar_jetveto_out['mu_eta_alphas119']],
                                      alphas2 = [ttbar_out['mu_eta_alphas117'], ttbar_out['mu_eta_alphas119']])




mu_eta_WZ  = details('WZ_mu_eta', WZ_out['mu_eta'], [WZ_out['mu_eta_Scale'+str(i)] for i in range(1,7)], [WZ_out['mu_eta_pdf'+str(i)] for i in range(1,101)], [WZ_out['mu_eta_alphas117'], WZ_out['mu_eta_alphas119']])

output = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_amcatnlo_mue_predictions.root", "RECREATE")
mu_pt.write()
mu_eta.write()
e_pt.write()
e_eta.write()
t_y_acc.write()
mu_eta_WW.write()
mu_eta_jetveto.write()
mu_eta_ttbar_jetveto_acc.write()
mu_eta_WW_jetveto_acc.write()
mu_eta_WZ.write()
output.Close()
