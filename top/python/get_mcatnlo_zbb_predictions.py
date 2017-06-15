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


fwdvars = [
    ["bjet1_pt"   , "bjet1_pt"      , 8  , 20 , 100 ],
    ["bjet2_pt"   , "bjet2_pt"      , 8  , 20 , 100 ],
    ["bjet1_eta"       , "abs(bjet1_eta)"   , 5, 2.2, 4.2 ], 
    ["bjet2_eta"        , "abs(bjet2_eta)"  , 5, 2.2, 4.2 ], 
    ["bb_m"         , "bbdijet_m", 5, 0, 120],
    ]

fwdvars_partons = [
    ["b_pt"   , "b_pt"      , 8  , 20 , 100 ],
    ["bbar_pt"   , "bbar_pt"      , 8  , 20 , 100 ],
    ["b_eta"       , "abs(b_eta)"   , 5, 2.2, 4.2 ], 
    ["bbar_eta"        , "abs(bbar_eta)"  , 5, 2.2, 4.2 ], 
    ["bb_m"         , "bb_m", 5, 0, 120],
    ]

fwdfid = TCut("bjet1_pt > 20 && bjet2_pt > 20 && bbdijet_m > 35 && bjet1_eta > 2.2 && bjet1_eta < 4.2 && bjet2_eta > 2.2 && bjet2_eta < 4.2")
fwdrecoiljet = TCut("fwdjet_pt > 10 && fwdjet_eta > 2.2 && fwdjet_eta < 4.2")
bwdfid = TCut("bjet1_pt > 20 && bjet2_pt > 20 && bbdijet_m > 35 && bjet1_eta < -2.2 && bjet1_eta > -4.2 && bjet2_eta < -2.2 && bjet2_eta > -4.2")
bwdrecoiljet = TCut("bwdjet_pt > 10 && bwdjet_eta < -2.2 && bwdjet_eta > -4.2")

fwdparton = TCut("b_pt > 20 && bbar_pt > 20 && bb_m > 35 && b_eta > 2.2 && b_eta < 4.2 && bbar_eta > 2.2 && bbar_eta < 4.2")
bwdparton = TCut("b_pt > 20 && bbar_pt > 20 && bb_m > 35 && b_eta < -2.2 && b_eta > -4.2 && bbar_eta < -2.2 && bbar_eta > -4.2")


ttf   = TFile.Open("/hepstore/sfarry/aMCatNLO/gZbb/Events/Zbb_amcatnlo_8tev.root")
t     = ttf.Get("tree")

N = ttf.Get('totEvts').GetVal()

#one factor of 1/2 for fwd and bwd, another for using muons and electrons
sf = 0.5/N
zbb_out           = {}
zbb_recoiljet_out = {}
zbb_partons_out   = {}

def get_templates(name, t, weights = True, selections = [fwdfid, bwdfid], sf = sf, vars2use = fwdvars ):
    fwd = MWTemplate(name+"_fwd", t, selections[0])
    fwd.AddVars(vars2use)
    #fwd.Add2DVars(vars2d)
    fwd.ApplyCut()
    if weights:
        fwd.AddWeight("Central","w1010")
        fwd.AddWeight("Scale1", "w1002")
        fwd.AddWeight("Scale2", "w1003")
        fwd.AddWeight("Scale3", "w1004")
        fwd.AddWeight("Scale4", "w1005")
        fwd.AddWeight("Scale5", "w1007")
        fwd.AddWeight("Scale6", "w1009")
        for i in range(89):
            fwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            fwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        fwd.AddWeight("alphas_117", "w1111")
        fwd.AddWeight("alphas_119", "w1112")
    fwd.FillVars()
    fwd.Scale(sf)
    fwd.ScaleAllWeights(sf)
    fwd.SaveToFile(name+"_fwd.root")

    bwd = MWTemplate(name+"_bwd", t, selections[1])
    bwd.AddVars(vars2use)
    #bwd.Add2DVars(vars2d)
    bwd.ApplyCut()
    if weights:
        bwd.AddWeight("Central","w1010")
        bwd.AddWeight("Scale1", "w1002")
        bwd.AddWeight("Scale2", "w1003")
        bwd.AddWeight("Scale3", "w1004")
        bwd.AddWeight("Scale4", "w1005")
        bwd.AddWeight("Scale5", "w1007")
        bwd.AddWeight("Scale6", "w1009")
        for i in range(89):
            bwd.AddWeight("pdf"+str(i+1), "w10"+str(i+11))
        for i in range(11):
            bwd.AddWeight("pdf"+str(i+90), "w1"+str(i+100))
        bwd.AddWeight("alphas_117", "w1111")
        bwd.AddWeight("alphas_119", "w1112")
    bwd.FillVars()
    bwd.Scale(sf)
    bwd.ScaleAllWeights(sf)
    bwd.SaveToFile(name+"_bwd.root")

    tot    = MWTemplate(name, fwd, bwd)
    tot.SaveToFile("/user2/sfarry/workspaces/top/tuples/"+name+".root")
    return tot

zbb = get_templates('zbb_8tev_amcatnlo', t)
zbb_recoiljet = get_templates('zbb_recoiljet_8tev_amcatnlo', t, selections = [fwdfid + fwdrecoiljet, bwdfid+bwdrecoiljet])
zbb_partons   = get_templates('zbb_partons_8tev_amcatnlo'  , t, selections = [fwdparton, bwdparton], vars2use = fwdvars_partons)

for v in ['bjet1_pt', 'bjet2_pt', 'bjet1_eta', 'bjet2_eta']:
    zbb_out[v] = zbb.GetWeightHist(v, "Central")
    for w in range(1,7):
        zbb_out[v+'_Scale'+str(w)] = zbb.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        zbb_out[v+'_pdf'+str(w)] = zbb.GetWeightHist(v, "pdf"+str(w))
    zbb_out[v+"_alphas117"] = zbb.GetWeightHist(v, "alphas_117")
    zbb_out[v+"_alphas119"] = zbb.GetWeightHist(v, "alphas_119")

    zbb_recoiljet_out[v] = zbb_recoiljet.GetWeightHist(v, "Central")
    for w in range(1,7):
        zbb_recoiljet_out[v+'_Scale'+str(w)] = zbb_recoiljet.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        zbb_recoiljet_out[v+'_pdf'+str(w)] = zbb_recoiljet.GetWeightHist(v, "pdf"+str(w))
    zbb_recoiljet_out[v+"_alphas117"] = zbb_recoiljet.GetWeightHist(v, "alphas_117")
    zbb_recoiljet_out[v+"_alphas119"] = zbb_recoiljet.GetWeightHist(v, "alphas_119")

for v in ['b_pt', 'bbar_pt', 'b_eta', 'bbar_eta']:
    zbb_partons_out[v] = zbb_partons.GetWeightHist(v, "Central")
    for w in range(1,7):
        zbb_partons_out[v+'_Scale'+str(w)] = zbb_partons.GetWeightHist(v, "Scale"+str(w))
    for w in range(1,101):
        zbb_partons_out[v+'_pdf'+str(w)] = zbb_partons.GetWeightHist(v, "pdf"+str(w))
    zbb_partons_out[v+"_alphas117"] = zbb_partons.GetWeightHist(v, "alphas_117")
    zbb_partons_out[v+"_alphas119"] = zbb_partons.GetWeightHist(v, "alphas_119")

#Get the various components
bjet1_pt  = details('bjet1_pt', zbb_out['bjet1_pt'], [zbb_out['bjet1_pt_Scale'+str(i)] for i in range(1,7)], [zbb_out['bjet1_pt_pdf'+str(i)] for i in range(1,101)], [zbb_out['bjet1_pt_alphas117'], zbb_out['bjet1_pt_alphas119']])
bjet1_eta  = details('bjet1_eta', zbb_out['bjet1_eta'], [zbb_out['bjet1_eta_Scale'+str(i)] for i in range(1,7)], [zbb_out['bjet1_eta_pdf'+str(i)] for i in range(1,101)], [zbb_out['bjet1_eta_alphas117'], zbb_out['bjet1_eta_alphas119']])
bjet2_pt  = details('bjet2_pt', zbb_out['bjet2_pt'], [zbb_out['bjet2_pt_Scale'+str(i)] for i in range(1,7)], [zbb_out['bjet2_pt_pdf'+str(i)] for i in range(1,101)], [zbb_out['bjet2_pt_alphas117'], zbb_out['bjet2_pt_alphas119']])
bjet2_eta  = details('bjet2_eta', zbb_out['bjet2_eta'], [zbb_out['bjet2_eta_Scale'+str(i)] for i in range(1,7)], [zbb_out['bjet2_eta_pdf'+str(i)] for i in range(1,101)], [zbb_out['bjet2_eta_alphas117'], zbb_out['bjet2_eta_alphas119']])

bjet1_recoiljet_eta  = details('bjet1_recoiljet_eta', zbb_recoiljet_out['bjet1_eta'], [zbb_recoiljet_out['bjet1_eta_Scale'+str(i)] for i in range(1,7)], [zbb_recoiljet_out['bjet1_eta_pdf'+str(i)] for i in range(1,101)], [zbb_recoiljet_out['bjet1_eta_alphas117'], zbb_recoiljet_out['bjet1_eta_alphas119']])

b_partons_eta  = details('b_partons_eta', zbb_partons_out['b_eta'], [zbb_partons_out['b_eta_Scale'+str(i)] for i in range(1,7)], [zbb_partons_out['b_eta_pdf'+str(i)] for i in range(1,101)], [zbb_partons_out['b_eta_alphas117'], zbb_partons_out['b_eta_alphas119']])

acc = ratio_details('acc', c1= zbb_recoiljet_out['bjet1_eta'], scales1 = [zbb_recoiljet_out['bjet1_eta_Scale'+str(i)] for i in range(1,7)],
                          c2 = zbb_out['bjet1_eta'], scales2 = [zbb_out['bjet1_eta_Scale'+str(i)] for i in range(1,7)],
                          pdfs1 = [zbb_recoiljet_out['bjet1_eta_pdf'+str(i)] for i in range(1,101)],
                          pdfs2 = [zbb_out['bjet1_eta_pdf'+str(i)] for i in range(1,101)],
                          alphas1 = [zbb_recoiljet_out['bjet1_eta_alphas117'], zbb_recoiljet_out['bjet1_eta_alphas119']],
                          alphas2 = [zbb_out['bjet1_eta_alphas117'], zbb_out['bjet1_eta_alphas119']])

output = TFile("/user2/sfarry/workspaces/top/tuples/zbb_8tev_amcatnlo_predictions.root", "RECREATE")
bjet1_pt.write()
bjet1_eta.write()
bjet2_pt.write()
bjet2_eta.write()
bjet1_recoiljet_eta.write()
b_partons_eta.write()
acc.write()
output.Close()
