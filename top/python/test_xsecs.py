from Jawa import GetWeightSum, GetWeightSqSum
from ROOT import TFile
from math import sqrt

fid = "lp_pt > 20 && lm_pt > 20 && lp_eta > 2.0 && lp_eta < 4.5 && lm_eta > 2.0 && lm_eta < 4.5 && fwdjet_pt > 20.0 && abs(fwdjet_flav) == 5"
fid_bwd = "lp_pt > 20 && lm_pt > 20 && lp_eta < -2.0 && lp_eta > -4.5 && lm_eta < -2.0 && lm_eta > -4.5 && bwdjet_pt > 20.0 && abs(bwdjet_flav) == 5"
#fid = "lp_pt > 20 && lm_pt > 20 && lp_eta > 2.0 && lp_eta < 4.5 && lm_eta > 2.0 && lm_eta < 4.5"
#fid_bwd = "lp_pt > 20 && lm_pt > 20 && lp_eta < -2.0 && lp_eta > -4.5 && lm_eta < -2.0 && lm_eta > -4.5"

fid_fb = "("+fid+") || ("+fid_bwd+")"

mcatnlo_f = TFile("/hepstore/sfarry/aMCatNLO/ttbar/Events/llj_ttbar_amcatnlo_13tev.root")
mcatnlo_t = mcatnlo_f.Get("ttbar")
madspinfull_f = TFile("/hepstore/sfarry/aMCatNLO/ttbar/Events/llj_ttbar_amcatnlo_13tev_madspin.root")
madspinfull_t = madspinfull_f.Get("ttbar")
madspin_f = TFile("/hepstore/sfarry/aMCatNLO/ttbar/Events/llj_ttbar_amcatnlo_13tev_madspin_filtered.root")
madspin_t = madspin_f.Get("ttbar")
powheg_f  = TFile.Open("/hepstore/sfarry/Powheg/ttbar/llj_ttbar_powheg_13tev.root")
powheg_t  = powheg_f.Get("ttbar")
powhegfull_f  = TFile.Open("/hepstore/sfarry/Powheg/ttbar/llj_ttbar_powheg_13tev_full.root")
powhegfull_t  = powhegfull_f.Get("ttbar")

madspin_corr = pow(0.1086,2)/pow(0.1111157,2)

bf_wl = 0.1086

bf_ll = ((bf_wl*2)**2)
bf_mue = 2*(bf_wl**2)

#0.5,1 - 2, 1 - 1,0.5 - 1,2 - 0.5,0.5, 2.0-2.0
scales_powheg  = [ 'w301', 'w302', 'w303', 'w304', 'w305', 'w306']
scales_mcatnlo = ['w1003', 'w1002', 'w1007', 'w1004', 'w1009', 'w1005']

# total cross-section to go to mue
# powheg includes branching fraction for ee, so multiply by 2 to get mue

tot_xsec1 = GetWeightSum(mcatnlo_t, 'w1010','') * bf_mue / mcatnlo_f.Get('totEvts').GetVal()
#tot_xsec1_scales = [xsec * bf_mue / mcatnlo_f.Get('totEvts').GetVal() for xsec in GetWeightSum(mcatnlo_t, scales_mcatnlo, '')]
tot_xsec2 = GetWeightSum(powhegfull_t, 'w0','') * 2.0 / powhegfull_f.Get('totEvts').GetVal()
#tot_xsec2_scales = [xsec * 2.0 / powhegfull_f.Get('totEvts').GetVal() for xsec in GetWeightSum(powhegfull_t, scales_powheg, '')]

#full amcatnlo has to be multiplied by mue branching fraction
#madspin has correct branching fraction applied (ish...)
#powheg has branching fraction for ee so has to be multiplied by 2
xsec1 = GetWeightSum(mcatnlo_t, 'w1010', fid_fb) * 0.5*bf_mue / mcatnlo_f.Get('totEvts').GetVal()
#xsec1_err = sqrt(GetWeightSqSum(mcatnlo_t, 'w1010', fid_fb)) * 0.5*bf_mue / mcatnlo_f.Get('totEvts').GetVal()
xsec2 = GetWeightSum(madspin_t, 'w1010', fid) *2.0 * madspin_corr / madspin_f.Get('totEvts').GetVal()
#xsec2_err = sqrt(GetWeightSqSum(madspin_t, 'w1010', fid)) *2.0*madspin_corr / madspin_f.Get('totEvts').GetVal()
xsec2b = GetWeightSum(madspinfull_t, 'w1010', fid_fb) *0.5*2.0*madspin_corr / madspinfull_f.Get('totEvts').GetVal()
#xsec2b_err = sqrt(GetWeightSqSum(madspinfull_t, 'w1010', fid_fb)) *0.5*2.0*madspin_corr / madspinfull_f.Get('totEvts').GetVal()
xsec3 = GetWeightSum(powheg_t, 'w0', fid)  * 2.0 / powheg_f.Get('totEvts').GetVal()
#xsec3_err = sqrt(GetWeightSqSum(powheg_t, 'w0', fid))  * 2.0 / powheg_f.Get('totEvts').GetVal()
xsec4 = GetWeightSum(powhegfull_t, 'w0', fid_fb) * 2.0 * 0.5 / powhegfull_f.Get('totEvts').GetVal()
#xsec4_err = sqrt(GetWeightSqSum(powhegfull_t, 'w0', fid_fb)) * 2.0 * 0.5 / powhegfull_f.Get('totEvts').GetVal()

print tot_xsec1, tot_xsec2
print xsec1,xsec2,xsec2b,xsec3,xsec4

'''

xsec1_scales = [xsec * bf_mue / mcatnlo_f.Get('totEvts').GetVal() for xsec in GetWeightSum(mcatnlo_t, scales_mcatnlo, fid)]
xsec2_scales = [xsec * 2.0  / madspin_f.Get('totEvts').GetVal() for xsec in GetWeightSum(madspin_t, scales_mcatnlo, fid)]
xsec3_scales = [xsec * 2.0 / powheg_f.Get('totEvts').GetVal() for xsec in GetWeightSum(powheg_t, scales_powheg, fid)]
xsec4_scales = [xsec * 2.0 / powhegfull_f.Get('totEvts').GetVal() for xsec in GetWeightSum(powhegfull_t, scales_powheg, fid)]

print "scale uncertainties"
print "+ %f - %f, +%f - %f, +%f -%f, +%f -%f" % (max(xsec1_scales) - xsec1, xsec1 - min(xsec1_scales),
                                                 max(xsec2_scales) - xsec2, xsec2 - min(xsec2_scales),
                                                 max(xsec3_scales) - xsec3, xsec3 - min(xsec3_scales),
                                                 max(xsec4_scales) - xsec4, xsec4 - min(xsec4_scales))
print "for total cross-section"
print "+ %f - %f, +%f - %f" % (max(tot_xsec1_scales) - tot_xsec1, tot_xsec1 - min(tot_xsec1_scales),
                               max(tot_xsec2_scales) - tot_xsec2, tot_xsec2 - min(tot_xsec2_scales))
'''
