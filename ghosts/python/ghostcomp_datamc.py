from ROOT import *
from PlotTools import *

from Style import *
SetLHCbStyle()

class ghostvar:
	def __init__(self, name, data, mc, tex=''):
		self.tex   = tex
		self.name  = name
		loc = '/user2/sfarry/EnergyFlow/eflow/tuples/'
		self.data  = data
                self.mc    = mc
                self.data_fake = self.data.Get('fake_'+name+'_data2015')
                self.mc_fake   = self.mc.Get('fake_'+name+'_mc2015')
                self.data_rec  = self.data.Get('rec_'+name+'_data2015')
                self.mc_rec    = self.mc.Get('rec_'+name+'_mc2015')
                self.data_fake_rate = self.data.Get('fake_rate_'+name+'_data2015')
                self.mc_fake_rate   = self.mc.Get('fake_rate_'+name+'_mc2015')

data = TFile("../tuples/ghostrate_data2015.root")
mc   = TFile("../tuples/ghostrate_mc2015.root")

files = []
files += [ghostvar('pt', data, mc, 'p_{T} [GeV]')]
files += [ghostvar('eta', data, mc, '#eta')]
files += [ghostvar('ghostprob', data, mc, 'Ghost Prob.')]
files += [ghostvar('chi2ndof' , data, mc , '#chi^{2}/ndof')]
files += [ghostvar('nveloclusters', data, mc, 'Velo Clusters')]
files += [ghostvar('npvs', data, mc, 'PVs')]

for v in files:
    o = Plot([v.data_fake, v.mc_fake])
    ymax = -1
    for p in o.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral() > ymax:
            ymax = p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral()
    o.setProp('colors', ['red', 'black'])
    o.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    if v.name=='chi2ndof': o.ShiftLegX(0.3)
    o.setProp('markerstyles', [0, 20])
    o.setProp('filename', 'ghostdist_datamc_'+v.name)
    o.setProp('location', '/user2/sfarry/EnergyFlow/eflow/figures/ghostrate/comp')
    o.setProp('normalised', True)
    o.setProp('ylabel', '[A.U.]')
    o.setProp('xlabel', v.tex)
    o.setProp('drawOpts', ['h', 'p1'])
    o.setProp('fillstyles', 0)
    o.setProp('ynormlims', [0, ymax])
    o.setProp('labels', ['MC2015 (Sim08-em)', '2015 EM Data'])
    o.drawROOT()

    n = Plot([v.data_rec, v.mc_rec])
    ymax = -1
    for p in n.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral() > ymax:
            ymax = p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral()
    n.setProp('colors', ['red', 'black'])
    n.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    if v.name=='chi2ndof': n.ShiftLegX(0.3)
    n.setProp('markerstyles', [0, 20])
    n.setProp('filename', 'recdist_datamc_'+v.name)
    n.setProp('location', '/user2/sfarry/EnergyFlow/eflow/figures/ghostrate/comp')
    n.setProp('normalised', True)
    n.setProp('ylabel', '[A.U.]')
    n.setProp('xlabel', v.tex)
    n.setProp('drawOpts', ['h', 'p1'])
    n.setProp('fillstyles', 0)
    print ymax
    n.setProp('ynormlims', [0, ymax])
    n.setProp('labels', ['MC2015 (Sim08-em)', '2015 EM Data'])
    n.drawROOT()

    ymax = 1.0
    m = Plot([v.mc_fake_rate, v.data_fake_rate])
    for p in m.plots:
        p.UseCurrentStyle()
    if ymax == -1 or p.GetMaximum()*1.1 > ymax:
        ymax = p.GetMaximum()*1.1
    m.setProp('colors', ['red', 'black'])
    m.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    if v.name=='chi2ndof': 
	    m.ShiftLegX(-0.1)
	    m.ShiftLegY(0.1)
    m.setProp('markerstyles', [0, 20])
    m.setProp('filename', 'ghostrate_datamc_'+v.name)
    m.setProp('location', '/user2/sfarry/EnergyFlow/eflow/figures/ghostrate/comp')
    m.setProp('ylabel', 'Ghost Rate')
    m.setProp('xlabel', v.tex)
    m.setProp('drawOpts', ['e2', 'e1'])
    m.setProp('fillstyles', [1001, 0])
    m.setProp('ylims', [0.001, ymax])
    m.setProp('labels', ['MC2015 (Sim08-em)', '2015 EM Data'])
    m.setProp('toCompare', {1 : [0]})
    m.setProp('ycomplims', [0.5, 1.49])
    m.drawROOT()
