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

ws = {}
ws["Central"] = "w0"
ws["Scale1"] =  "w301"
ws["Scale2"] =  "w302"
ws["Scale3"] =  "w303"
ws["Scale4"] =  "w304"
ws["Scale5"] =  "w305"
ws["Scale6"] =  "w306"
for i in range(100):
    ws["pdf"+str(i+1)] = "w"+str(i+1)
ws["alphas_117"]   =  "w201"
ws["alphas_119"]   =  "w202"

TH1.AddDirectory(False)
dpm = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/electroweak/"

fwd_vis_m = "sqrt((sqrt(<mu>_m^2 + <mu>_px^2 + <mu>_py^2 + <mu>_pz^2) + sqrt(<e>_m^2 + <e>_px^2 + <e>_py^2 + <e>_pz^2) + sqrt(<jet>_m^2 + <jet>_px^2 + <jet>_py^2 +<jet>_pz^2))^2 - (<mu>_px + <e>_px + <jet>_px)^2 - (<mu>_py + <e>_py + <jet>_py)^2 - (<mu>_pz + <e>_pz + <jet>_pz)^2)"
bwd_vis_m = fwd_vis_m.replace('fwdjet', 'bwdjet')
fwd_muj_m = "sqrt((sqrt(<mu>_m^2 + <mu>_px^2 + <mu>_py^2 + <mu>_pz^2) + sqrt(fwdjet_m^2 + fwdjet_px^2 + fwdjet_py^2 +fwdjet_pz^2))^2 - (<mu>_px + fwdjet_px)^2 - (<mu>_py + fwdjet_py)^2 - (<mu>_pz + fwdjet_pz)^2)"
bwd_muj_m = fwd_muj_m.replace('fwdjet', 'bwdjet')

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
'''
bwdvars = [
    ["mu_pt"        , "mu_pt"           , 8  , 20 , 100 ],
    ["e_pt"         , "e_pt"            , 8  , 20 , 100 ],
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
'''


vars2d = [ ['t_y', 'tbar_y'] ]

pltvars = ['ptj', 'eta', 'yj', 'etaj']

lhcbfwd = TCut("mup_eta > 2.0 && mup_eta < 4.5 && mum_eta > 2.0 && mum_eta < 4.5")
lhcbbwd = TCut("mup_eta < -2.0 && mup_eta > -4.5 && mum_eta < -2.0 && mum_eta > -4.5")

pt20  = TCut("mup_pt  > 20 && mum_pt > 20")

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

mupem = TCut("mup_id == -11 && mum_id == 11")
mumep = TCut("mup_id == 11  && mum_id == -11")

#ttf   = TFile.Open("/hepstore/sfarry/aMC@NLO/ttbar/Events/mue_ttbar_amcatnlo_pdf_as.root")
ttf   = TFile.Open("/user2/sfarry/external/powheg/POWHEG-BOX-V2/hvq/run_1/muej_powheg_13tev.root")
t     = ttf.Get("ttbar")

#N = ttf.Get('totEvts').GetVal()
N = t.GetEntries()
#correct by enforced branching ratio of W to e
bf_ww = pow(0.1080,2)
bf_wt = pow(2*0.1080,2)
#include factor of two because cross-section is given for enforced ee branching ratio and we want mue
#factor of 0.5 is because we include fwd and bwd events
sf = 0.5*2/N

fwd_vis_m = "sqrt((mu_E + e_E + fwdjet_E)^2 - (mu_px + e_px + fwdjet_px)^2 - (mu_py + e_py + fwdjet_py)^2 - (mu_pz + e_pz + fwdjet_pz)^2)"
bwd_vis_m = fwd_vis_m.replace('fwdjet', 'bwdjet')

top_fiducial = TCut("abs(t_y) > 2.0 && abs(t_y) < 5.0 && abs(tbar_y) > 2.0 && abs(tbar_y) < 5.0 && t_y*tbar_y > 0 && t_pt > 10.0 && tbar_pt > 10.0")

top_fiducial_fwd = TCut("t_y > 2.0 && t_y < 5.0 && tbar_y > 2.0 && tbar_y < 5.0 && t_pt > 10.0 && tbar_pt > 10.0")

ttbar_out          = {}
ttbar_fiducial_out = {}
ttbar_fwdasy_out   = {}
ttbar_bwdasy_out   = {}

def get_templates(name, t, weights = True):
    fwd = MWTemplate(name+"_fwd", t, fwdjet20)
    for v in variables:
        var = v.var
        var = var.replace('<jet>', 'fwdjet')
        var = var.replace('<mu>', 'mup')
        var = var.replace('<e>', 'mum')
        if hasattr(v, 'edges'):
            fwd.AddVar(v.name, var, v.edges)
        else:
            fwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
    #fwd.Add2DVars(vars2d)
    fwd.ApplyCut()
    if weights:
        for key, val  in ws.iteritems():
            fwd.AddWeight(key, val)
    fwd.FillVars()
    fwd.Scale(sf)
    fwd.ScaleAllWeights(sf)
    fwd.SaveToFile()

    bwd = MWTemplate(name+"_bwd", t, bwdjet20 )
    for v in variables:
        var = v.var
        var = var.replace('<jet>', 'bwdjet')
        var = var.replace('<mu>', 'mup')
        var = var.replace('<e>', 'mum')
        if hasattr(v, 'edges'):
            bwd.AddVar(v.name, var, v.edges)
        else:
            bwd.AddVar(v.name, var, v.bins, v.lo, v.hi)
    #bwd.Add2DVars(vars2d)
    bwd.ApplyCut()
    if weights:
        for key, val  in ws.iteritems():
            bwd.AddWeight(key, val)
    bwd.FillVars()
    bwd.Scale(sf)
    bwd.ScaleAllWeights(sf)
    bwd.SaveToFile()

    tot    = MWTemplate(name, fwd, bwd)
    tot.SaveToFile()
    return tot


def get_asymmetries(name, t, weights = True):
    fwd_fwdasy = MWTemplate(name+"_fwd_fwdasy", t, fwdjet20 + fwdasy_fwdjet)
    fwd_fwdasy.AddVars(fwdvariables)
    fwd_fwdasy.ApplyCut()
    if weights:
        for key, val  in ws.iteritems():
            fwd_fwdasy.AddWeight(key, val)
    fwd_fwdasy.FillVars()
    fwd_fwdasy.Scale(sf)
    fwd_fwdasy.ScaleAllWeights(sf)
    fwd_fwdasy.SaveToFile()

    fwd_bwdasy = MWTemplate(name+"_fwd_bwdasy", t, fwdjet20 + bwdasy_fwdjet)
    fwd_bwdasy.AddVars(fwdvars)
    fwd_bwdasy.ApplyCut()
    if weights:
        for key, val  in ws.iteritems():
            fwd_bwdasy.AddWeight(key, val)
    fwd_bwdasy.FillVars()
    fwd_bwdasy.Scale(sf)
    fwd_bwdasy.ScaleAllWeights(sf)
    fwd_bwdasy.SaveToFile()


    bwd_fwdasy = MWTemplate(name+"_bwd_fwdasy", t, bwdjet20 + fwdasy_bwdjet )
    bwd_fwdasy.AddVars(fwdvars)
    bwd_fwdasy.ApplyCut()
    if weights:
        for key, val  in ws.iteritems():
            bwd_fwdasy.AddWeight(key, val)
    bwd_fwdasy.FillVars()
    bwd_fwdasy.Scale(sf)
    bwd_fwdasy.ScaleAllWeights(sf)
    bwd_fwdasy.SaveToFile()


    bwd_bwdasy = MWTemplate(name+"_bwd_bwdasy", t, bwdjet20 + bwdasy_bwdjet)
    bwd_bwdasy.AddVars(fwdvars)
    bwd_bwdasy.ApplyCut()
    if weights:
        for key, val  in ws.iteritems():
            bwd_bwdasy.AddWeight(key, val)
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
    for v in variables:
        if 't_' in v.var or 'tbar_' in v.var:
            if hasattr(v, 'edges'):
                fiducial.AddVar(v.name, v.var, v.edges)
            else:
                fiducial.AddVar(v.name, v.var, v.bins, v.lo, v.hi)
    fiducial.Add2DVars(vars2d)
    fiducial.ApplyCut()
    if weights:
        for key, val  in ws.iteritems():
            fiducial.AddWeight(key, val)
    fiducial.FillVars()
    fiducial.Scale(1.0/(N*bf_ww))
    fiducial.ScaleAllWeights(1.0/(N*bf_ww))
    fiducial.SaveToFile()
    return fiducial

if relaunch:
    ttbar = get_templates('ttbar_mue_13tev_powheg', t)
    for v in ['ptj', 'etaj', 't_y', 'mu_eta', 'mu_pt', 'e_eta', 'e_pt']:
        ttbar_out[v] = ttbar.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_out[v+'_Scale'+str(w)] = ttbar.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_out[v+'_pdf'+str(w)] = ttbar.GetWeightHist(v, "pdf"+str(w))
        ttbar_out[v+"_alphas117"] = ttbar.GetWeightHist(v, "alphas_117")
        ttbar_out[v+"_alphas119"] = ttbar.GetWeightHist(v, "alphas_119")

    ttbar_fiducial = get_fiducial('ttbar_powheg', t, top_fiducial)
    #ttbar_tot_fiducial = get_fiducial('ttbar_powheg_tot', t)
    for v in ['t_y']:
        ttbar_fiducial_out[v] = ttbar_fiducial.GetWeightHist(v, "Central")
        for w in range(1,7):
            ttbar_fiducial_out[v+'_Scale'+str(w)] = ttbar_fiducial.GetWeightHist(v, "Scale"+str(w))
        for w in range(1,101):
            ttbar_fiducial_out[v+'_pdf'+str(w)] = ttbar_fiducial.GetWeightHist(v, "pdf"+str(w))
        ttbar_fiducial_out[v+"_alphas117"] = ttbar_fiducial.GetWeightHist(v, "alphas_117")
        ttbar_fiducial_out[v+"_alphas119"] = ttbar_fiducial.GetWeightHist(v, "alphas_119")

ptj  = details('ttbar_ptj', ttbar_out['ptj'], [ttbar_out['ptj_Scale'+str(i)] for i in range(1,7)], [ttbar_out['ptj_pdf'+str(i)] for i in range(1,101)], [ttbar_out['ptj_alphas117'], ttbar_out['ptj_alphas119']])
etaj  = details('ttbar_etaj', ttbar_out['etaj'], [ttbar_out['etaj_Scale'+str(i)] for i in range(1,7)], [ttbar_out['etaj_pdf'+str(i)] for i in range(1,101)], [ttbar_out['etaj_alphas117'], ttbar_out['etaj_alphas119']])
mu_pt  = details('ttbar_mupt', ttbar_out['mu_pt'], [ttbar_out['mu_pt_Scale'+str(i)] for i in range(1,7)], [ttbar_out['mu_pt_pdf'+str(i)] for i in range(1,101)], [ttbar_out['mu_pt_alphas117'], ttbar_out['mu_pt_alphas119']])
mu_eta  = details('tttbar_mueta', ttbar_out['mu_eta'], [ttbar_out['mu_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_out['mu_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_out['mu_eta_alphas117'], ttbar_out['mu_eta_alphas119']])
e_pt  = details('ttbar_ept', ttbar_out['e_pt'], [ttbar_out['e_pt_Scale'+str(i)] for i in range(1,7)], [ttbar_out['e_pt_pdf'+str(i)] for i in range(1,101)], [ttbar_out['e_pt_alphas117'], ttbar_out['e_pt_alphas119']])
e_eta  = details('ttbar_eeta', ttbar_out['e_eta'], [ttbar_out['e_eta_Scale'+str(i)] for i in range(1,7)], [ttbar_out['e_eta_pdf'+str(i)] for i in range(1,101)], [ttbar_out['e_eta_alphas117'], ttbar_out['e_eta_alphas119']])
#mvis  = details('m_vis', ttbar_out['m_vis'], [ttbar_out['m_vis_Scale'+str(i)] for i in range(1,7)], [ttbar_out['m_vis_pdf'+str(i)] for i in range(1,101)], [ttbar_out['m_vis_alphas117'], ttbar_out['m_vis_alphas119']])
#mmuj  = details('m_muj', ttbar_out['m_muj'], [ttbar_out['m_muj_Scale'+str(i)] for i in range(1,7)], [ttbar_out['m_muj_pdf'+str(i)] for i in range(1,101)], [ttbar_out['m_muj_alphas117'], ttbar_out['m_muj_alphas119']])

t_y_acc = ratio_details('ttbar_ty_acc', ttbar_fiducial_out['t_y'], [ttbar_fiducial_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          ttbar_out['t_y'], [ttbar_out['t_y_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [ttbar_fiducial_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [ttbar_out['t_y_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [ttbar_fiducial_out['t_y_alphas117'], ttbar_fiducial_out['t_y_alphas119']],
                          alphas2 = [ttbar_out['t_y_alphas117'], ttbar_out['t_y_alphas119']])

fwdjet20_wt = TCut(fwdjet20.GetTitle().replace('mup','mu').replace('mum','e'))

wtf = TFile("/hepstore/sfarry/powheg_v1/ST_wtch_DR/mue_Wt_powheg_13tev.root")
wtt = wtf.Get("ttbar")
wt_tot_xsec = 36.625
wt_acc = wtt.GetEntries(fwdjet20_wt.GetTitle())/float(wtt.GetEntries())
wt_fid_xsec = wt_acc * wt_tot_xsec * bf_wt

wtdsf = TFile("/hepstore/sfarry/powheg_v1/ST_wtch_DS/mue_Wt_powheg_ds_13tev.root")
wtdst = wtdsf.Get("ttbar")
wtds_tot_xsec = 34.8215
wtds_acc = wtdst.GetEntries(fwdjet20_wt.GetTitle())/float(wtdst.GetEntries())
wtds_fid_xsec = wtds_acc * wtds_tot_xsec * bf_wt

print 'wt fiducial cross-section is ',wt_fid_xsec*100,' fb (DR)'
print 'wtds fiducial cross-section is ',wtds_fid_xsec*100,' fb (DS)'

output = TFile("/user2/sfarry/workspaces/top/tuples/ttbar_13tev_powheg_predictions.root", "RECREATE")
ptj.write()
etaj.write()
mu_pt.write()
mu_eta.write()
e_pt.write()
e_eta.write()
#mvis.write()
#mmuj.write()
#ptj_asy.write()
#mu_eta_asy.write()
#etaj_asy.write()
t_y_acc.write()
TParameter(float)("Wt_dr_xsec", wt_fid_xsec).Write()
TParameter(float)("Wt_ds_xsec", wtds_fid_xsec).Write()
output.Close()
