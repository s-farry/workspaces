from ROOT import TFile, TTree
from Jawa import *
from math import sqrt

f = TFile('/user2/sfarry/workspaces/strange/tuples/zmumuj_amcatnlo.root')

t = f.Get('Zjet')

fwdcut = 'fwdjet_pt > 20 && mup_pt > 20 && mum_pt > 20 && min(mup_eta, mum_eta) > 2 && max(mum_eta, mup_eta) < 4.5'
bwdcut = 'bwdjet_pt > 20 && mup_pt > 20 && mum_pt > 20 && min(mup_eta, mum_eta) > -4.5 && max(mum_eta, mup_eta) < -2'

cut = '('+fwdcut+') || ('+bwdcut+')'

xsec = GetWeightSum(t, 'w', cut)*0.5/t.GetEntries()

xsecs_scales = GetWeightSum(t, ['w1001', 'w1002', 'w1003', 'w1004', 'w1005', 'w1007', 'w1009'], cut) 

xsecs_pdfs =  GetWeightSum(t, ['w200'+str(i) for i in range(1,10)] +
                           ['w20'+str(i) for i in range(10,100)]+['w2100'],
                           cut)

for i in range(len(xsecs_scales)): xsecs_scales[i] = xsecs_scales[i]*0.5/t.GetEntries()
for i in range(len(xsecs_pdfs)): xsecs_pdfs[i] = xsecs_pdfs[i]*0.5/t.GetEntries()

print xsec, ' + ', max(xsecs_scales) - xsec, ' - ', xsec - min(xsecs_scales), '+/-', standard_deviation(xsecs_pdfs), '+/-', xsec/sqrt(t.GetEntries(cut)), '(stat.)'
