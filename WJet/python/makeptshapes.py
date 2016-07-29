from os import sys
from Jawa import AnalysisClass, Template
from ROOT import TFile, TTree, TH1, TCut, kRed, kYellow, kBlue, kOrange, kGreen, TF1, kMagenta, TMath, TH1F, TCanvas

from Wjconfig import *

wmupj_data2012 = Template("wmupj_data2012", datat, selcut + plus)
wmupj_data2012.AddVars(variables)
wmupj_data2012.AddVars(jetvars)
wmupj_data2012.ApplyCut()
wmupj_data2012.FillVars()
wmupj_data2012.SaveToFile()

wmumj_data2012 = Template("wmumj_data2012", datat, selcut + minus)
wmumj_data2012.AddVars(variables)
wmumj_data2012.AddVars(jetvars)
wmumj_data2012.ApplyCut()
wmumj_data2012.FillVars()
wmumj_data2012.SaveToFile()


wmupj_mc2012 = Template("wmupj_mc2012", wmujt, selcut + plus)
wmupj_mc2012.AddVars(variables)
wmupj_mc2012.AddVars(jetvars)
wmupj_mc2012.ApplyCut()
wmupj_mc2012.FillVars()
wmupj_mc2012.SaveToFile()

wmumj_mc2012 = Template("wmumj_mc2012", wmujt, selcut + minus)
wmumj_mc2012.AddVars(variables)
wmumj_mc2012.AddVars(jetvars)
wmumj_mc2012.ApplyCut()
wmumj_mc2012.FillVars()
wmumj_mc2012.SaveToFile()

wmupj20_data2012 = Template("wmupj20_data2012", datat, selcut + ptj20 + plus)
wmupj20_data2012.AddVars(variables)
wmupj20_data2012.AddVars(jetvars)
wmupj20_data2012.ApplyCut()
wmupj20_data2012.FillVars()
wmupj20_data2012.SaveToFile()

wmumj20_data2012 = Template("wmumj20_data2012", datat, selcut + ptj20 + minus)
wmumj20_data2012.AddVars(variables)
wmumj20_data2012.AddVars(jetvars)
wmumj20_data2012.ApplyCut()
wmumj20_data2012.FillVars()
wmumj20_data2012.SaveToFile()

wmupj20_mc2012 = Template("wmupj20_mc2012", wmujt, selcut + ptj20 + plus)
wmupj20_mc2012.AddVars(variables)
wmupj20_mc2012.AddVars(jetvars)
wmupj20_mc2012.ApplyCut()
wmupj20_mc2012.FillVars()
wmupj20_mc2012.SaveToFile()

wmumj20_mc2012 = Template("wmumj20_mc2012", wmujt, selcut + ptj20 + minus)
wmumj20_mc2012.AddVars(variables)
wmumj20_mc2012.AddVars(jetvars)
wmumj20_mc2012.ApplyCut()
wmumj20_mc2012.FillVars()
wmumj20_mc2012.SaveToFile()

zmumuf     = TFile("/hepstore/sfarry/ZMuMu.2012.root")
zmumumvf   = TFile("/hepstore/sfarry/ZMuMu.2012.MVA.root")
zmumudatat = zmumuf.Get("ZMuMu/DecayTree")
zmumudatat.AddFriend(zmumumvf.Get("tree"))

zmumup_data2012 = Template("zmumup_data2012", zmumudatat, selcut_zmumu_p + ptj20)
zmumup_data2012.AddVars(plusvariables)
zmumup_data2012.AddVars(jetvars)
zmumup_data2012.ApplyCut()
zmumup_data2012.FillVars()
zmumup_data2012.SaveToFile()

zmumum_data2012 = Template("zmumum_data2012", zmumudatat, selcut_zmumu_m + ptj20)
zmumum_data2012.AddVars(variables)
zmumum_data2012.AddVars(jetvars)
zmumum_data2012.ApplyCut()
zmumum_data2012.FillVars()
zmumum_data2012.SaveToFile()

zmumu_data2012 = Template("zmumu_data2012", zmumup_data2012, zmumum_data2012)
zmumu_data2012.SaveToFile()

wmup_p_data2012 = Template("zmumup_data2012", zmumudatat, selcut_zmumu_p + ptj20)
wmup_p_data2012.AddVars(plusvariables)
wmup_p_data2012.AddVars(jetvars)
wmup_p_data2012.ApplyCut()
wmup_p_data2012.FillVars()
wmup_p_data2012.SaveToFile()

wmup_m_data2012 = Template("zmumum_data2012", zmumudatat, selcut_zmumu_m + ptj20)
wmup_m_data2012.AddVars(variables)
wmup_m_data2012.AddVars(jetvars)
wmup_m_data2012.ApplyCut()
wmup_m_data2012.FillVars()
wmup_m_data2012.SaveToFile()

wmup_data2012 = Template("wmup_data2012", wmup_p_data2012, wmup_m_data2012)
wmup_data2012.SaveToFile()


zmumum_mc2012 = Template("zmumum_mc2012", zmumujetmct, selcut_zmumu + ptj20 )
zmumum_mc2012.AddVars(variables)
zmumum_mc2012.AddVars(jetvars)
zmumum_mc2012.ApplyCut()
zmumum_mc2012.FillVars()
zmumum_mc2012.SaveToFile()

zmumu_mc2012 = Template("zmumu_mc2012", zmumup_mc2012, zmumum_mc2012 + ptj20)
zmuuu_mc2012.SaveToFile()


zmup_mc2012 = Template("zmup_mc2012", zmujetmct, selcut + plus + ptj20 )
zmup_mc2012.AddVars(plusvariables)
zmup_mc2012.AddVars(jetvars)
zmup_mc2012.ApplyCut()
zmup_mc2012.FillVars()
zmup_mc2012.SaveToFile()

zmum_mc2012 = Template("zmum_mc2012", zmujetmct, selcut + minus + ptj20 )
zmum_mc2012.AddVars(variables)
zmum_mc2012.AddVars(jetvars)
zmum_mc2012.ApplyCut()
zmum_mc2012.FillVars()
zmum_mc2012.SaveToFile()

zmu_mc2012 = Template("zmu_mc2012", zmup_mc2012, zmum_mc2012 + ptj20)
zmu_mc2012.SaveToFile()

