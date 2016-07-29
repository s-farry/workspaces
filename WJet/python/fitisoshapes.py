from os import sys
from analysis import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig import *

#get reweights
wmupj = AnalysisClass("wmupj")
wmupj.SetSelCut(selcut + ptj20 + plus)
wmupj.SetData("Data", datat)
wmupj.AddTemplate("w_m", zmumudatat, selcut_zmumu_m + ptj20 + mumjpt, kYellow)
wmupj.AddTemplate("w_p", zmumudatat, selcut_zmumu_p + ptj20 + mupjpt, kYellow)
wmupj.AddTemplate("qcd", datat, selcut_ptunbal + plus + ptj20, kBlue)
#wmupj.AddTemplate("qcd_norw", datat, selcut_ptunbal + plus, kBlue)

wmupj.GetTemplate("qcd").Reweight("sqrt((muminus_PX + muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_PY + muminus_cpy_0.50 + muminus_npy_0.50)^2)", qcd_pj_rw)
wmupj.GetTemplate("w_m").Reweight("muminus_PT", wmupj_ptrw )
wmupj.GetTemplate("w_p").Reweight("muplus_PT", wmupj_ptrw )
wmupj.AddVars(variables)
wmupj.AddVars(jetvars)

#change w_p variables to pluses
for v in wmupj.GetTemplate("w_p").Vars:
    vv = wmupj.GetTemplate("w_p").GetVar(v.GetName())
    expr = vv.GetExpr().GetExpr()
    expr = expr.replace('muminus','muplus')
    vv.SetVarName(expr)

wmupj.ApplyCuts()
wmupj.FillVars()
#merge z->mumu samples to produce w sample
wp = Template("w", wmupj.GetTemplate("w_m"), wmupj.GetTemplate("w_p"))
wp.SetStyle(kYellow)
wmupj.AddTemplate(wp)

#now make 4 versions of main template and normalise to ewk shapes
wmup = Template("wmu", wp)
zmup = Template("zmu", wp)
wtaup = Template("wtau", wp)
ztautaup = Template("ztautau", wp)

wmup.SetStyle(kYellow)
zmup.SetStyle(kRed)
wtaup.SetStyle(kOrange)
ztautaup.SetStyle(kMagenta)
wmupj.AddTemplate(wmup)
wmupj.AddTemplate(zmup)
wmupj.AddTemplate(wtaup)
wmupj.AddTemplate(ztautaup)

wmupj.ToFit = ["w", "qcd"]
wmupj.TFracFit("IsoAsymm")

wmup.NormaliseToEvts(wp.GetNormEvts() - nzmup*(1 + wtaup_frac + ztautaup_frac))
zmup.NormaliseToEvts(nzmup)
wtaup.NormaliseToEvts(nzmup * wtaup_frac)
ztautaup.NormaliseToEvts(nzmup * ztautaup_frac)
wmupj.ToStack = ['qcd','ztautau', 'wtau', 'zmu', 'wmu']
wmupj.MakeStacks()
wmupj.SaveToFile()

########################################################################
#
#
# W minus
#
#
########################################################################
wmumj = AnalysisClass("wmumj")
wmumj.SetSelCut(selcut + ptj20 + minus)
wmumj.SetData("Data", datat)
wmumj.AddTemplate("w_m", zmumudatat, selcut_zmumu_m + ptj20, kYellow)
wmumj.AddTemplate("w_p", zmumudatat, selcut_zmumu_p + ptj20, kYellow)
wmumj.AddTemplate("qcd", datat, selcut_ptunbal + minus + ptj20, kBlue)
#wmumj.AddTemplate("qcd_norw", datat, selcut_ptunbal + minus, kBlue)
wmumj.GetTemplate("qcd").Reweight("sqrt((muminus_PX + muminus_cpx_0.50 + muminus_npx_0.50)^2 + (muminus_PY + muminus_cpy_0.50 + muminus_npy_0.50)^2)", qcd_pj_rw)
wmumj.GetTemplate("w_m").Reweight("muminus_PT", wmumj_ptrw )
wmumj.GetTemplate("w_p").Reweight("muplus_PT", wmumj_ptrw )
wmumj.AddVars(variables)
wmumj.AddVars(jetvars)

#change w_p variables to pluses
for v in wmumj.GetTemplate("w_p").Vars:
    vv = wmumj.GetTemplate("w_p").GetVar(v.GetName())
    expr = vv.GetExpr().GetExpr()
    expr = expr.replace('muminus','muplus')
    vv.SetVarName(expr)

wmumj.ApplyCuts()
wmumj.FillVars()
#merge z->mumu samples to produce w sample
wm = Template("w", wmumj.GetTemplate("w_m"), wmumj.GetTemplate("w_p"))
wm.SetStyle(kYellow)
wmumj.AddTemplate(wm)
#now make 4 versions of main template and normalise to ewk shapes
wmum = Template("wmu", wp)
zmum = Template("zmu", wp)
wtaum = Template("wtau", wp)
ztautaum = Template("ztautau", wp)

wmum.SetStyle(kYellow)
zmum.SetStyle(kRed)
wtaum.SetStyle(kOrange)
ztautaum.SetStyle(kMagenta)
wmumj.AddTemplate(wmum)
wmumj.AddTemplate(zmum)
wmumj.AddTemplate(wtaum)
wmumj.AddTemplate(ztautaum)
wmumj.ToFit = ["w", "qcd"]
wmumj.TFracFit("IsoAsymm")
wmum.NormaliseToEvts(wm.GetNormEvts() - nzmum*(1 + wtaum_frac + ztautaum_frac))
zmum.NormaliseToEvts(nzmum)
wtaum.NormaliseToEvts(nzmum * wtaum_frac)
ztautaum.NormaliseToEvts(nzmum * ztautaum_frac)
wmumj.ToStack = ['qcd', 'ztautau', 'wtau', 'zmu', 'wmu']
wmumj.MakeStacks()
wmumj.SaveToFile()
