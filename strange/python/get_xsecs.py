from ROOT import TFile, TTree
from Jawa import *
from math import sqrt
from Utils import getpdfuncertainty

#mcatnlo

f = TFile('/user2/sfarry/workspaces/strange/tuples/zmumuj_amcatnlo_13tev.root')
t = f.Get('Zjet')

fwdcut = 'fwdjet_pt > 20 && mup_pt > 20 && mum_pt > 20 && min(mup_eta, mum_eta) > 2 && max(mum_eta, mup_eta) < 4.5 && Z_m > 60 && Z_m < 120'
bwdcut = 'fwdjet_pt > 20 && mup_pt > 20 && mum_pt > 20 && min(mup_eta, mum_eta) > -4.5 && max(mum_eta, mup_eta) < -2 && Z_m > 60 && Z_m < 120'

fwd_strange = 'abs(fwdjet_flav) == 3'
bwd_strange = 'abs(bwdjet_flav) == 3'

fwd_gluon = 'abs(fwdjet_flav) == 21'
bwd_gluon = 'abs(bwdjet_flav) == 21'

fwd_quark = 'abs(fwdjet_flav) < 6 && abs(fwdjet_flav) != 3'
bwd_quark = 'abs(bwdjet_flav) < 6 && abs(bwdjet_flav) != 3'


cut = '('+fwdcut+') || ('+bwdcut+')'

#strange

strangecut = '('+fwdcut+' && '+fwd_strange+') || ( '+bwdcut+' && '+bwd_strange+' )'
strange_xsec = GetWeightSum(t, 'w', strangecut)*0.5/f.Get('totEvts').GetVal()
strange_xsecs_scales = GetWeightSum(t, ['w1001', 'w1002', 'w1003', 'w1004', 'w1005', 'w1007', 'w1009'], strangecut) 
strange_xsecs_pdfs =  GetWeightSum(t, ['w200'+str(i) for i in range(1,10)] +
                           ['w20'+str(i) for i in range(10,100)]+['w2100'],
                           strangecut)
for i in range(len(strange_xsecs_scales)): strange_xsecs_scales[i] = strange_xsecs_scales[i]*0.5/f.Get('totEvts').GetVal()
for i in range(len(strange_xsecs_pdfs)): strange_xsecs_pdfs[i] = strange_xsecs_pdfs[i]*0.5/f.Get('totEvts').GetVal()
print strange_xsec, ' + ', max(strange_xsecs_scales) - strange_xsec, ' - ', strange_xsec - min(strange_xsecs_scales), '+/-', standard_deviation(strange_xsecs_pdfs)

#quark

quarkcut = '('+fwdcut+' && '+fwd_quark+') || ( '+bwdcut+' && '+bwd_quark+' )'
quark_xsec = GetWeightSum(t, 'w', quarkcut)*0.5/f.Get('totEvts').GetVal()
quark_xsecs_scales = GetWeightSum(t, ['w1001', 'w1002', 'w1003', 'w1004', 'w1005', 'w1007', 'w1009'], quarkcut) 
quark_xsecs_pdfs =  GetWeightSum(t, ['w200'+str(i) for i in range(1,10)] +
                           ['w20'+str(i) for i in range(10,100)]+['w2100'],
                           quarkcut)
for i in range(len(quark_xsecs_scales)): quark_xsecs_scales[i] = quark_xsecs_scales[i]*0.5/f.Get('totEvts').GetVal()
for i in range(len(quark_xsecs_pdfs)): quark_xsecs_pdfs[i] = quark_xsecs_pdfs[i]*0.5/f.Get('totEvts').GetVal()
print quark_xsec, ' + ', max(quark_xsecs_scales) - quark_xsec, ' - ', quark_xsec - min(quark_xsecs_scales), '+/-', standard_deviation(quark_xsecs_pdfs)

#gluon

gluoncut = '('+fwdcut+' && '+fwd_gluon+') || ( '+bwdcut+' && '+bwd_gluon+' )'
gluon_xsec = GetWeightSum(t, 'w', gluoncut)*0.5/f.Get('totEvts').GetVal()
gluon_xsecs_scales = GetWeightSum(t, ['w1001', 'w1002', 'w1003', 'w1004', 'w1005', 'w1007', 'w1009'], gluoncut) 
gluon_xsecs_pdfs =  GetWeightSum(t, ['w200'+str(i) for i in range(1,10)] +
                           ['w20'+str(i) for i in range(10,100)]+['w2100'],
                           gluoncut)
for i in range(len(gluon_xsecs_scales)): gluon_xsecs_scales[i] = gluon_xsecs_scales[i]*0.5/f.Get('totEvts').GetVal()
for i in range(len(gluon_xsecs_pdfs)): gluon_xsecs_pdfs[i] = gluon_xsecs_pdfs[i]*0.5/f.Get('totEvts').GetVal()
print gluon_xsec, ' + ', max(gluon_xsecs_scales) - gluon_xsec, ' - ', gluon_xsec - min(gluon_xsecs_scales), '+/-', standard_deviation(gluon_xsecs_pdfs)


#inclusive

incl_xsec         = GetWeightSum(t, 'w', cut)*0.5/f.Get('totEvts').GetVal()
incl_xsecs_scales = GetWeightSum(t, ['w1001', 'w1002', 'w1003', 'w1004', 'w1005', 'w1007', 'w1009'], cut) 
incl_xsecs_pdfs   =  GetWeightSum(t, ['w200'+str(i) for i in range(1,10)] +
                                  ['w20'+str(i) for i in range(10,100)]+['w2100'],
                                  cut)

for i in range(len(incl_xsecs_scales)): incl_xsecs_scales[i] = incl_xsecs_scales[i]*0.5/f.Get('totEvts').GetVal()
for i in range(len(incl_xsecs_pdfs)): incl_xsecs_pdfs[i] = incl_xsecs_pdfs[i]*0.5/f.Get('totEvts').GetVal()

print incl_xsec, ' + ', max(incl_xsecs_scales) - incl_xsec, ' - ', incl_xsec - min(incl_xsecs_scales), '+/-', getpdfuncertainty(incl_xsec, incl_xsecs_pdfs), '+/-', incl_xsec/sqrt(t.GetEntries(cut)), '(stat.)'



strangeratio = strange_xsec / incl_xsec
strangeratio_scales = []
strangeratio_pdfs = []
for i in range(len(incl_xsecs_scales)): strangeratio_scales += [strange_xsecs_scales[i]/incl_xsecs_scales[i]]
for i in range(len(incl_xsecs_pdfs)):   strangeratio_pdfs   += [strange_xsecs_pdfs[i]/incl_xsecs_pdfs[i]]
print 'Zs/Zj', strangeratio, ' + ', max(strangeratio_scales) - strangeratio, ' - ', strangeratio - min(strangeratio_scales), '+/-', getpdfuncertainty(strangeratio, strangeratio_pdfs)

quarkratio = quark_xsec / incl_xsec
quarkratio_scales = []
quarkratio_pdfs = []
for i in range(len(incl_xsecs_scales)): quarkratio_scales += [quark_xsecs_scales[i]/incl_xsecs_scales[i]]
for i in range(len(incl_xsecs_pdfs)):   quarkratio_pdfs   += [quark_xsecs_pdfs[i]/incl_xsecs_pdfs[i]]
print 'Zq/Zj', quarkratio, ' + ', max(quarkratio_scales) - quarkratio, ' - ', quarkratio - min(quarkratio_scales), '+/-', getpdfuncertainty(quarkratio, quarkratio_pdfs)

gluonratio = gluon_xsec / incl_xsec
gluonratio_scales = []
gluonratio_pdfs = []
for i in range(len(incl_xsecs_scales)): gluonratio_scales += [gluon_xsecs_scales[i]/incl_xsecs_scales[i]]
for i in range(len(incl_xsecs_pdfs)):   gluonratio_pdfs   += [gluon_xsecs_pdfs[i]/incl_xsecs_pdfs[i]]
print 'Zg/Zj', gluonratio, ' + ', max(gluonratio_scales) - gluonratio, ' - ', gluonratio - min(gluonratio_scales), '+/-', getpdfuncertainty(gluonratio, gluonratio_pdfs)

'''
####
# powheg
####

dpm_loc = 'root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/strange/'
f = TFile.Open(dpm_loc+'Pythia.Zmumuj.8TeV.root')
t = f.Get('Zjet')

xsec = GetWeightSum(t, 'w', flavcut)*0.5/f.Get('totEvts').GetVal()

xsecs_scales = GetWeightSum(t, ['w101', 'w102', 'w103', 'w104', 'w105', 'w106'], flavcut) 

xsecs_pdfs =  GetWeightSum(t, ['w'+str(i) for i in range(1,101)],  flavcut)

for i in range(len(xsecs_scales)): xsecs_scales[i] = xsecs_scales[i]*0.5/f.Get('totEvts').GetVal()
for i in range(len(xsecs_pdfs)): xsecs_pdfs[i] = xsecs_pdfs[i]*0.5/f.Get('totEvts').GetVal()

print xsec, ' + ', max(xsecs_scales) - xsec, ' - ', xsec - min(xsecs_scales), '+/-', standard_deviation(xsecs_pdfs), '+/-', xsec/sqrt(t.GetEntries(cut)), '(stat.)'


#g = TFile('/user2/sfarry/workspaces/strange/tuples/zmumuj_amcatnlo.root')
#u = g.Get('Zjet')

incl_xsec         = GetWeightSum(t, 'w', cut)*0.5/f.Get('totEvts').GetVal()
incl_xsecs_scales = GetWeightSum(t, ['w101', 'w102', 'w103', 'w104', 'w105', 'w106'], cut) 
incl_xsecs_pdfs   =  GetWeightSum(t, ['w'+str(i) for i in range(1,101)], cut)

for i in range(len(incl_xsecs_scales)): incl_xsecs_scales[i] = incl_xsecs_scales[i]*0.5/f.Get('totEvts').GetVal()
for i in range(len(incl_xsecs_pdfs)): incl_xsecs_pdfs[i] = incl_xsecs_pdfs[i]*0.5/f.Get('totEvts').GetVal()

print incl_xsec, ' + ', max(incl_xsecs_scales) - incl_xsec, ' - ', incl_xsec - min(incl_xsecs_scales), '+/-', getpdfuncertainty(incl_xsec, incl_xsecs_pdfs), '+/-', incl_xsec/sqrt(t.GetEntries(cut)), '(stat.)'



ratio = xsec / incl_xsec

ratio_scales = []
ratio_pdfs = []

for i in range(len(incl_xsecs_scales)): ratio_scales += [xsecs_scales[i]/incl_xsecs_scales[i]]
for i in range(len(incl_xsecs_pdfs)):   ratio_pdfs   += [xsecs_pdfs[i]/incl_xsecs_pdfs[i]]

print ratio, ' + ', max(ratio_scales) - ratio, ' - ', ratio - min(ratio_scales), '+/-', getpdfuncertainty(ratio, ratio_pdfs)
'''


####
# pythia
####

f = TFile('/user2/sfarry/workspaces/strange/tuples/zmumuj_pythia_13tev.root')
#f = TFile('/user2/sfarry/workspaces/strange/tuples/zmumuj_13tev_newlabelling.root')
t = f.Get('Zjet')

strangexsec = t.GetEntries(strangecut)
quarkxsec   = t.GetEntries(quarkcut)
gluonxsec   = t.GetEntries(gluoncut)
incl_xsec         = t.GetEntries(cut)

strangeratio = float(strangexsec) / incl_xsec
quarkratio   = float(quarkxsec)   / incl_xsec
gluonratio   = float(gluonxsec)   / incl_xsec

print "default strange: ",strangeratio, "quark: ", quarkratio, "gluon: ",gluonratio

####
# pythia
####

g = TFile('/user2/sfarry/workspaces/strange/tuples/zmumuj_ct09mcs_13tev.root')
#g = TFile('/user2/sfarry/workspaces/strange/output.root')
u = g.Get('Zjet')

strangexsec = u.GetEntries(strangecut)
quarkxsec   = u.GetEntries(quarkcut)
gluonxsec   = u.GetEntries(gluoncut)
incl_xsec         = u.GetEntries(cut)

strangeratio = float(strangexsec) / incl_xsec
quarkratio   = float(quarkxsec)   / incl_xsec
gluonratio   = float(gluonxsec)   / incl_xsec

print "ct09mcs strange: ",strangeratio, "quark: ", quarkratio, "gluon: ",gluonratio



####
# pythia
####

h = TFile('/user2/sfarry/workspaces/strange/tuples/zmumuj_ct09mcs_13tev_lhcbtune.root')
#g = TFile('/user2/sfarry/workspaces/strange/output.root')
v = h.Get('Zjet')

strangexsec = v.GetEntries(strangecut)
quarkxsec   = v.GetEntries(quarkcut)
gluonxsec   = v.GetEntries(gluoncut)
incl_xsec   = v.GetEntries(cut)

strangeratio = float(strangexsec) / incl_xsec
quarkratio   = float(quarkxsec)   / incl_xsec
gluonratio   = float(gluonxsec)   / incl_xsec

print "ct09mcs (lhcb tune) strange: ",strangeratio, "quark: ", quarkratio, "gluon: ",gluonratio

