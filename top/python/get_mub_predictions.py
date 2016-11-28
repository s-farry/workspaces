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
    Bunch(name="mu_eta"  , var = "abs(<mu>_eta)" , edges = [2.0, 2.5, 3.0, 3.5, 4.5]), 
    Bunch(name="etaj"    , var = "<jet>_eta"      , edges = [2.2, 2.7, 3.2, 3.7, 4.2]),
    Bunch(name="ptj"     , var = "<jet>_pt"       , bins = 5, lo = 20, hi = 220),
    Bunch(name="ptmuj"   , var = ptmuj ,    bins = 4, lo = 20, hi = 100.0),
    Bunch(name='t_y'   , var = 't_y',     bins = 10, lo = 0, hi = 5.0),
    Bunch(name='tbar_y', var = 'tbar_y', bins = 10, lo = 0, hi = 5.0),
    Bunch(name='t_pt'  , var = 't_pt',    bins = 10, lo = 0, hi = 100.0),
    Bunch(name='tbar_pt' , var = 'tbar_pt',    bins = 10, lo = 0, hi = 100.0),
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

top_fid = TCut("t_y > 2.0 && t_y < 5.0 && t_pt > 10")
antitop_fid = TCut("tbar_y > 2.0 && tbar_y < 5.0 && tbar_pt > 10")


ttf   = TFile.Open("/hepstore/sfarry/aMC@NLO/ttbar/Events/mumuj_ttbar_amcatnlo_13tev.root")
t     = ttf.Get("ttbar")

wtf   = TFile.Open("/hepstore/sfarry/powheg_v1/ST_wtch_DR/mumu_Wt_powheg_13tev.root")
u     = wtf.Get("ttbar")

N = ttf.Get('totEvts').GetVal()
#N = t.GetEntries()

sf = 0.5/N

#ntuple only contains events where there is at least muon, account for this when doing fiducial
B = (0.108 + 0.108 - 0.108*0.108)


relaunch = True

ttbar_plus_out          = {}
ttbar_minus_out         = {}

top_fiducial_out        = {}
antitop_fiducial_out    = {}


def get_templates(name, t, weights = True):
    fwd_plus = MWTemplate(name+"_fwd_plus", t, fwdjet20_plus)
    for v in vars:
        var = v.var.replace('<jet>', 'fwdjet').replace('<mu>', 'mup')
        if hasattr(v, 'edges'):
            fwd_plus.AddVar(v.name, var, v.edges)
        else:
            fwd_plus.AddVar(v.name, var, v.bins, v.lo, v.hi)
    fwd_plus.ApplyCut()
    if weights:
        fwd_plus.AddWeight("Central","w1010")
        fwd_plus.AddWeight("Scale1", "w1002")
        fwd_plus.AddWeight("Scale2", "w1003")
        fwd_plus.AddWeight("Scale3", "w1004")
        fwd_plus.AddWeight("Scale4", "w1005")
        fwd_plus.AddWeight("Scale5", "w1007")
        fwd_plus.AddWeight("Scale6", "w1009")
        for i in range(89):
            fwd_plus.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            fwd_plus.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        fwd_plus.AddWeight("alphas_117", "w1111")
        fwd_plus.AddWeight("alphas_119", "w1112")
        fwd_plus.FillVars()
        fwd_plus.Scale(sf)
        fwd_plus.ScaleAllWeights(sf)
        fwd_plus.SaveToFile()

    fwd_minus = MWTemplate(name+"_fwd_minus", t, fwdjet20_minus)
    for v in vars:
        var = v.var.replace('<jet>', 'fwdjet').replace('<mu>', 'mum')
        if hasattr(v, 'edges'):
            fwd_minus.AddVar(v.name, var, v.edges)
        else:
            fwd_minus.AddVar(v.name, var, v.bins, v.lo, v.hi)
    # fwd_minus.Add2DVars(vars2d)
    fwd_minus.ApplyCut()
    if weights:
        fwd_minus.AddWeight("Central","w1010")
        fwd_minus.AddWeight("Scale1", "w1002")
        fwd_minus.AddWeight("Scale2", "w1003")
        fwd_minus.AddWeight("Scale3", "w1004")
        fwd_minus.AddWeight("Scale4", "w1005")
        fwd_minus.AddWeight("Scale5", "w1007")
        fwd_minus.AddWeight("Scale6", "w1009")
        for i in range(89):
            fwd_minus.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            fwd_minus.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        fwd_minus.AddWeight("alphas_117", "w1111")
        fwd_minus.AddWeight("alphas_119", "w1112")
    fwd_minus.FillVars()
    fwd_minus.Scale(sf)
    fwd_minus.ScaleAllWeights(sf)
    fwd_minus.SaveToFile()


    bwd_plus = MWTemplate(name+"_bwd_plus", t, bwdjet20_plus)
    for v in vars:
        var = v.var.replace('<jet>', 'bwdjet').replace('<mu>', 'mup')
        if hasattr(v, 'edges'):
            bwd_plus.AddVar(v.name, var, v.edges)
        else:
            bwd_plus.AddVar(v.name, var, v.bins, v.lo, v.hi)
    bwd_plus.ApplyCut()
    if weights:
        bwd_plus.AddWeight("Central","w1010")
        bwd_plus.AddWeight("Scale1", "w1002")
        bwd_plus.AddWeight("Scale2", "w1003")
        bwd_plus.AddWeight("Scale3", "w1004")
        bwd_plus.AddWeight("Scale4", "w1005")
        bwd_plus.AddWeight("Scale5", "w1007")
        bwd_plus.AddWeight("Scale6", "w1009")
        for i in range(89):
            bwd_plus.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            bwd_plus.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        bwd_plus.AddWeight("alphas_117", "w1111")
        bwd_plus.AddWeight("alphas_119", "w1112")
    bwd_plus.FillVars()
    bwd_plus.Scale(sf)
    bwd_plus.ScaleAllWeights(sf)
    bwd_plus.SaveToFile()

    bwd_minus = MWTemplate(name+"_bwd_minus", t, bwdjet20_minus)
    for v in vars:
        var = v.var.replace('<jet>', 'bwdjet').replace('<mu>', 'mum')
        if hasattr(v, 'edges'):
            bwd_minus.AddVar(v.name, var, v.edges)
        else:
            bwd_minus.AddVar(v.name, var, v.bins, v.lo, v.hi)
    # bwd_minus.Add2DVars(vars2d)
    bwd_minus.ApplyCut()
    if weights:
        bwd_minus.AddWeight("Central","w1010")
        bwd_minus.AddWeight("Scale1", "w1002")
        bwd_minus.AddWeight("Scale2", "w1003")
        bwd_minus.AddWeight("Scale3", "w1004")
        bwd_minus.AddWeight("Scale4", "w1005")
        bwd_minus.AddWeight("Scale5", "w1007")
        bwd_minus.AddWeight("Scale6", "w1009")
        for i in range(89):
            bwd_minus.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            bwd_minus.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        bwd_minus.AddWeight("alphas_117", "w1111")
        bwd_minus.AddWeight("alphas_119", "w1112")
    bwd_minus.FillVars()
    bwd_minus.Scale(sf)
    bwd_minus.ScaleAllWeights(sf)
    bwd_minus.SaveToFile()

    plus = MWTemplate(name+"_plus", fwd_plus, bwd_plus)
    #plus.SaveToFile("/user2/sfarry/workspaces/top/tuples/mub_plus.root")
    plus.SaveToFile()

    minus = MWTemplate(name+"_minus", fwd_minus, bwd_minus)
    #minus.SaveToFile("/user2/sfarry/workspaces/top/tuples/mub_plus.root")
    minus.SaveToFile()

    return [plus, minus]


def get_fiducial(name, t, t_fid, tbar_fid, weights = True):
    top_fiducial = MWTemplate(name+"_fiducial", t, t_fid )
    for v in vars:
        var = v.var.replace('<jet>', 'fwdjet').replace('<mu>', 'mup')
        if hasattr(v, 'edges'):
            top_fiducial.AddVar(v.name, var, v.edges)
        else:
            top_fiducial.AddVar(v.name, var, v.bins, v.lo, v.hi)
    top_fiducial.ApplyCut()
    if weights:
        top_fiducial.AddWeight("Central","w1010")
        top_fiducial.AddWeight("Scale1", "w1002")
        top_fiducial.AddWeight("Scale2", "w1003")
        top_fiducial.AddWeight("Scale3", "w1004")
        top_fiducial.AddWeight("Scale4", "w1005")
        top_fiducial.AddWeight("Scale5", "w1007")
        top_fiducial.AddWeight("Scale6", "w1009")
        for i in range(89):
            top_fiducial.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            top_fiducial.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        top_fiducial.AddWeight("alphas_117", "w1111")
        top_fiducial.AddWeight("alphas_119", "w1112")
    top_fiducial.FillVars()
    top_fiducial.Scale(sf/B)
    top_fiducial.ScaleAllWeights(sf/B)
    top_fiducial.SaveToFile()

    antitop_fiducial = MWTemplate("top_fiducial", t, antitop_fid)
    for v in vars:
        var = v.var.replace('<jet>', 'fwdjet').replace('<mu>', 'mup')
        if hasattr(v, 'edges'):
            antitop_fiducial.AddVar(v.name, var, v.edges)
        else:
            antitop_fiducial.AddVar(v.name, var, v.bins, v.lo, v.hi)
    antitop_fiducial.ApplyCut()
    if weights:
        antitop_fiducial.AddWeight("Central","w1010")
        antitop_fiducial.AddWeight("Scale1", "w1002")
        antitop_fiducial.AddWeight("Scale2", "w1003")
        antitop_fiducial.AddWeight("Scale3", "w1004")
        antitop_fiducial.AddWeight("Scale4", "w1005")
        antitop_fiducial.AddWeight("Scale5", "w1007")
        antitop_fiducial.AddWeight("Scale6", "w1009")
        for i in range(89):
            antitop_fiducial.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            antitop_fiducial.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        antitop_fiducial.AddWeight("alphas_117", "w1111")
        antitop_fiducial.AddWeight("alphas_119", "w1112")
    antitop_fiducial.FillVars()
    antitop_fiducial.Scale(sf/B)
    antitop_fiducial.ScaleAllWeights(sf/B)
    antitop_fiducial.SaveToFile()

    return [top_fiducial, antitop_fiducial]

if relaunch:
    '''
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
    '''
    ttbar = get_templates('ttbar', t)
    wt    = get_templates('wt', u, weights = False)
    top_fiducials = get_fiducial('ttbar', t, top_fid, antitop_fid)
    wt_fiducials  = get_fiducial('wt', u, top_fid, antitop_fid, weights = False)

    '''
    top_fiducial = MWTemplate("top_fiducial", t, top_fid )
    for v in vars:
        var = v.var.replace('<jet>', 'fwdjet').replace('<mu>', 'mup')
        if hasattr(v, 'edges'):
            top_fiducial.AddVar(v.name, var, v.edges)
        else:
            top_fiducial.AddVar(v.name, var, v.bins, v.lo, v.hi)
    top_fiducial.ApplyCut()
    top_fiducial.AddWeight("Central","w1010")
    top_fiducial.AddWeight("Scale1", "w1002")
    top_fiducial.AddWeight("Scale2", "w1003")
    top_fiducial.AddWeight("Scale3", "w1004")
    top_fiducial.AddWeight("Scale4", "w1005")
    top_fiducial.AddWeight("Scale5", "w1007")
    top_fiducial.AddWeight("Scale6", "w1009")
    for i in range(89):
        top_fiducial.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        top_fiducial.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    top_fiducial.AddWeight("alphas_117", "w1111")
    top_fiducial.AddWeight("alphas_119", "w1112")
    top_fiducial.FillVars()
    top_fiducial.Scale(sf/B)
    top_fiducial.ScaleAllWeights(sf/B)
    top_fiducial.SaveToFile()

    antitop_fiducial = MWTemplate("top_fiducial", t, antitop_fid)
    for v in vars:
        var = v.var.replace('<jet>', 'fwdjet').replace('<mu>', 'mup')
        if hasattr(v, 'edges'):
            antitop_fiducial.AddVar(v.name, var, v.edges)
        else:
            antitop_fiducial.AddVar(v.name, var, v.bins, v.lo, v.hi)
    antitop_fiducial.ApplyCut()
    antitop_fiducial.AddWeight("Central","w1010")
    antitop_fiducial.AddWeight("Scale1", "w1002")
    antitop_fiducial.AddWeight("Scale2", "w1003")
    antitop_fiducial.AddWeight("Scale3", "w1004")
    antitop_fiducial.AddWeight("Scale4", "w1005")
    antitop_fiducial.AddWeight("Scale5", "w1007")
    antitop_fiducial.AddWeight("Scale6", "w1009")
    for i in range(89):
        antitop_fiducial.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
    for i in range(11):
        antitop_fiducial.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
    antitop_fiducial.AddWeight("alphas_117", "w1111")
    antitop_fiducial.AddWeight("alphas_119", "w1112")
    antitop_fiducial.FillVars()
    antitop_fiducial.Scale(sf/B)
    antitop_fiducial.ScaleAllWeights(sf/B)
    antitop_fiducial.SaveToFile()
    '''
    ttbar_plus  = ttbar[0]
    ttbar_minus = ttbar[1]
    top_fiducial = top_fiducials[0]
    antitop_fiducial = top_fiducials[1]

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

        top_fiducial_out[v.name] = top_fiducial.GetWeightHist(v.name, "Central")
        for w in range(1,7):
            top_fiducial_out[v.name+'_Scale'+str(w)] = top_fiducial.GetWeightHist(v.name, "Scale"+str(w))
        for w in range(1,101):
            top_fiducial_out[v.name+'_pdf'+str(w)] = top_fiducial.GetWeightHist(v.name, "pdf"+str(w))
        top_fiducial_out[v.name+"_alphas117"] = top_fiducial.GetWeightHist(v.name, "alphas_117")
        top_fiducial_out[v.name+"_alphas119"] = top_fiducial.GetWeightHist(v.name, "alphas_119")

        antitop_fiducial_out[v.name] = antitop_fiducial.GetWeightHist(v.name, "Central")
        for w in range(1,7):
            antitop_fiducial_out[v.name+'_Scale'+str(w)] = antitop_fiducial.GetWeightHist(v.name, "Scale"+str(w))
        for w in range(1,101):
            antitop_fiducial_out[v.name+'_pdf'+str(w)] = antitop_fiducial.GetWeightHist(v.name, "pdf"+str(w))
        antitop_fiducial_out[v.name+"_alphas117"] = antitop_fiducial.GetWeightHist(v.name, "alphas_117")
        antitop_fiducial_out[v.name+"_alphas119"] = antitop_fiducial.GetWeightHist(v.name, "alphas_119")




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

etaj_asy = asymm_details('etaj_asy', ttbar_plus_out['etaj'],
                          [ttbar_plus_out['etaj_Scale'+str(i)] for i in range(1,7)],
                          ttbar_minus_out['etaj'], 
                          [ttbar_minus_out['etaj_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_plus_out['etaj_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_minus_out['etaj_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_plus_out['etaj_alphas117'],
                                     ttbar_plus_out['etaj_alphas119']],
                          alphas2 = [ttbar_minus_out['etaj_alphas117'],
                                     ttbar_minus_out['etaj_alphas119']])

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




t_y_acc = ratio_details('t_y_acc', top_fiducial_out['t_y'], [top_fiducial_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          ttbar_plus_out['t_y'], [ttbar_plus_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [top_fiducial_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_plus_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [top_fiducial_out['t_y_alphas117'], top_fiducial_out['t_y_alphas119']],
                          alphas2 = [ttbar_plus_out['t_y_alphas117'], ttbar_plus_out['t_y_alphas119']])


tbar_y_acc = ratio_details('tbar_y_acc', antitop_fiducial_out['t_y'], [antitop_fiducial_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          ttbar_minus_out['t_y'], [ttbar_minus_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [antitop_fiducial_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_minus_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [antitop_fiducial_out['t_y_alphas117'], antitop_fiducial_out['t_y_alphas119']],
                          alphas2 = [ttbar_minus_out['t_y_alphas117'], ttbar_minus_out['t_y_alphas119']])


output = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_amcatnlo_mue_predictions.root", "RECREATE")
ptj_plus.write()
ptmuj_plus.write()
etaj_plus.write()
ptj_minus.write()
ptmuj_minus.write()
etaj_minus.write()
ptmuj_asy.write()
etaj_asy.write()
mu_eta_asy.write()
t_y_acc.write()
tbar_y_acc.write()
output.Close()
