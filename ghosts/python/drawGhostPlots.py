from ROOT import *
from PlotTools import *

from Style import *
SetLHCbStyle()

class ghostvar:
	def __init__(self, name, data, mc, tex='', **kwargs):
		self.tex   = tex
		self.name  = name
		self.draw  = {}
		loc = '/user2/sfarry/workspaces/ghosts/tuples/'
		self.data  = data
                self.mc    = mc
                self.data_fake = self.data.Get('fake_'+name+"_data2015")
                self.mc_fake   = self.mc.Get('fake_'+name)
                self.data_rec  = self.data.Get('rec_'+name+"_data2015")
                self.mc_rec    = self.mc.Get('rec_'+name)
                self.data_fake_rate = self.data.Get('fake_rate_'+name+"_data2015")
                self.mc_fake_rate   = self.mc.Get('fake_rate_'+name)
		for name, val in kwargs.items():
			self.draw[name] = val

class ghostmethodvar:
	def __init__(self, name, mc, tex='', **kwargs):
		self.tex   = tex
		self.name  = name
		self.draw  = {}
		loc = '/user2/sfarry/workspaces/ghosts/tuples/'
                self.mc         = mc
                self.fake       = self.mc.Get('fake_'+name)
                self.ghost      = self.mc.Get('loose_'+name)
                self.rec        = self.mc.Get('rec_'+name)
                self.fake_rate  = self.mc.Get('fake_rate_'+name)
                self.ghost_rate = self.mc.Get('ghost_rate_'+name)
		for name, val in kwargs.items():
			self.draw[name] = val

data   = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_data2015_test.root")
mc     = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015.root")
mcldst = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015_ldst_test.root")
mcsim09b = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015_sim09b_test.root")
mcldst_noghostprob = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015_ldst.noghostprob.root")


from Utils import Bunch


variables = []
variables += [Bunch(name = 'pt', xlabel = 'p_{T} [MeV]', ShiftLegX = 0.3)]
variables += [Bunch(name = 'eta', xlabel = '#eta', rate_ylim = [0, 0.4], ShiftLegX = 0.3, ShiftLegY = -0.4)]
variables += [Bunch(name = 'ghostprob', xlabel =  'Ghost Prob.', ShiftLegY = -0.3, ShiftLegX = 0.2, logy=True)]
variables += [Bunch(name = 'chi2ndof' , xlabel =  '#chi^{2}/ndof', ShiftLegX = 0.25)]
variables += [Bunch(name = 'nveloclusters', xlabel = 'Velo Clusters', ShiftLegX=0.1, ShiftLegY=-0.4, ShiftLegY_rate = -0.2)]
variables += [Bunch(name = 'npvs', xlabel = 'PVs', ShiftLegY_rate = -0.2, ShiftLegX_rate = 0.3)]

line = TLine(2.0, 1.0, 5.0, 1.0)
line.SetLineStyle(2)
line.SetLineColor(1)

'''
files = []
files += [ghostvar('pt', data, mc, 'p_{T} [MeV]')]
files += [ghostvar('eta', data, mc, '#eta')]
files += [ghostvar('ghostprob', data, mc, 'Ghost Prob.')]
files += [ghostvar('chi2ndof' , data, mc , '#chi^{2}/ndof')]
files += [ghostvar('nveloclusters', data, mc, 'Velo Clusters', ShiftLegX=0.35, ShiftLegY=0.1)]
files += [ghostvar('npvs', data, mc, 'PVs')]

filesb = []
filesb += [ghostvar('pt', data, mcsim09b, 'p_{T} [MeV]')]
filesb += [ghostvar('eta', data, mcsim09b, '#eta')]
filesb += [ghostvar('ghostprob', data, mcsim09b, 'Ghost Prob.')]
filesb += [ghostvar('chi2ndof' , data, mcsim09b , '#chi^{2}/ndof')]
filesb += [ghostvar('nveloclusters', data, mcsim09b, 'Velo Clusters', ShiftLegX=0.35, ShiftLegY=0.1)]
filesb += [ghostvar('npvs', data, mcsim09b, 'PVs')]

files2 = []
files2 += [ghostmethodvar('pt', mcldst, 'p_{T} [MeV]')]
files2 += [ghostmethodvar('eta', mcldst, '#eta')]
files2 += [ghostmethodvar('ghostprob', mcldst, 'Ghost Prob.')]
files2 += [ghostmethodvar('chi2ndof' , mcldst , '#chi^{2}/ndof')]
#files2 += [ghostmethodvar('nveloclusters', mcldst, 'Velo Clusters')]
#files2 += [ghostmethodvar('npvs', mcldst, 'PVs')]


files3 = []
files3 += [ghostmethodvar('pt', mcldst_noghostprob, 'p_{T} [MeV]')]
files3 += [ghostmethodvar('eta', mcldst_noghostprob, '#eta')]
files3 += [ghostmethodvar('ghostprob', mcldst_noghostprob, 'Ghost Prob.')]
files3 += [ghostmethodvar('chi2ndof' , mcldst_noghostprob , '#chi^{2}/ndof')]
'''
#######################
## data v mc
#######################

data_pave = TPaveText(0.5, 0.4, 0.7, 0.5, 'NDC')
data_pave.SetBorderSize(0)
data_pave.SetFillStyle(0)
data_pave.AddText('2015 Data')

mc_pave = TPaveText(0.5, 0.4, 0.7, 0.5, 'NDC')
mc_pave.SetBorderSize(0)
mc_pave.SetFillStyle(0)
mc_pave.AddText('MC2015')

for v in variables:
    # compare data and mc shapes
    o = Plot([mc.Get('fake_'+v.name), mcsim09b.Get('fake_'+v.name), data.Get('fake_'+v.name+'')])
    ymax = -1
    for p in o.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral() > ymax:
            ymax = p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral()
    o.setProp('colors', ['green', 'red', 'black'])
    o.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    o.setProp('markerstyles', [0, 0, 20] )
    o.setProp('filename', 'comp_fake_sim09b_'+v.name+'.pdf')
    o.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    o.setProp('normalised', True)
    o.setProp('ylabel', '[A.U.]')
    o.setProp('xlabel', v.xlabel)
    o.setProp('drawOpts', ['hist', 'hist', 'p1'])
    o.setProp('fillstyles', 0)
    o.setProp('ynormlims', [0, ymax])
    o.setProp('labels', ['MC2015 (Sim08h-em)', 'MC2015 (Sim09b)', '2015 EM Data'])
    if hasattr(v, 'ShiftLegX'):
	    o.ShiftLegX(v.ShiftLegX)
    if hasattr(v, 'ShiftLegY'): o.ShiftLegY(v.ShiftLegY)
    o.drawROOT()

    n = Plot([mc.Get('rec_'+v.name), mcsim09b.Get('rec_'+v.name), data.Get('rec_'+v.name+'')])
    ymax = -1
    for p in n.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral() > ymax:
            ymax = p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral()
    n.setProp('colors', ['green', 'red', 'black'])
    n.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    n.setProp('markerstyles', [0, 0, 20])
    n.setProp('filename', 'comp_rec_sim09b_'+v.name+'.pdf')
    n.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    n.setProp('normalised', True)
    n.setProp('ylabel', '[A.U.]')
    n.setProp('xlabel', v.xlabel)
    n.setProp('drawOpts', ['hist', 'hist', 'p1'])
    n.setProp('fillstyles', 0)
    n.setProp('ynormlims', [0, ymax])
    n.setProp('labels', ['MC2015 (Sim08h-em)', 'MC2015 (Sim09b)', '2015 EM Data'])
    if hasattr(v, 'ShiftLegX'): n.ShiftLegX(v.ShiftLegX)
    if hasattr(v, 'ShiftLegY'): n.ShiftLegY(v.ShiftLegY)
    n.drawROOT()

    ymax = -1.0
    m = Plot([mc.Get('fake_rate_'+v.name), mcsim09b.Get('fake_rate_'+v.name), data.Get('fake_rate_'+v.name+'')])
    for p in m.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetMaximum()*1.1 > ymax:
		ymax = p.GetMaximum()*1.1
    m.setProp('colors', ['green', 'red', 'black'])
    m.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    m.setProp('markerstyles', [20, 20, 20])
    m.setProp('filename', 'comp_rate_sim09b_'+v.name+'.pdf')
    m.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    m.setProp('ylabel', 'Ghost Rate Estimate')
    m.setProp('xlabel', v.xlabel)
    m.setProp('drawOpts', ['hist', 'hist', 'e1'])
    m.setProp('fillstyles', [0, 0, 0])
    m.setProp('ylims', [0.001, ymax])
    m.setProp('labels', ['MC2015 (Sim08h-em)', 'MC2015 (Sim09b)', '2015 EM Data'])
    m.setProp('toCompare', {2 : [0,1]})
    line.SetX1(m.plots[0].GetBinLowEdge(1))
    line.SetX2(m.plots[0].GetBinLowEdge(m.plots[0].GetNbinsX() + 1))
    m.setProp('compObjs', [line])
    m.setProp('ycomplims', [0.5, 1.49])
    if hasattr(v, 'ShiftLegX_rate'): m.ShiftLegX(v.ShiftLegX_rate)
    elif hasattr(v, 'ShiftLegX'): m.ShiftLegX(v.ShiftLegX)
    if hasattr(v, 'ShiftLegY_rate'): m.ShiftLegY(v.ShiftLegY_rate)
    elif hasattr(v, 'ShiftLegY'): m.ShiftLegY(v.ShiftLegY)
    if hasattr(v, 'rate_ylim'): m.setProp('ylims', v.rate_ylim)
    m.drawROOT()

    ymax  = -1

    l = Plot([mcsim09b.Get('rec_'+v.name), mc.Get('fake_'+v.name)])
    for p in l.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetMaximum()/p.Integral()*1.1 > ymax:
		ymax = p.GetMaximum()/p.Integral()*1.1
    l.setProp('colors', ['red', 'black', 'blue'])
    l.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    l.setProp('markerstyles', [20, 20])
    l.setProp('filename', 'all_mc2015sim09b_'+v.name+'.pdf')
    l.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    l.setProp('ylabel', '[A.U.]')
    l.setProp('xlabel', v.xlabel)
    l.setProp('drawOpts', ['he1', 'he1', 'he1'])
    l.setProp('fillstyles', [1001, 0])
    l.setProp('ynormlims', [0.0, ymax])
    l.setProp('labels', ['All Tracks', 'Fake Tracks', 'Ghost Tracks'])
    l.setProp('normalised', True)
    l.setProp('extraObjs', [mc_pave])
    if hasattr(v, 'ShiftLegX'): l.ShiftLegX(v.ShiftLegX)
    if hasattr(v, 'ShiftLegY'): l.ShiftLegY(v.ShiftLegY)
    l.drawROOT()

#######################
## mc method v truth
#######################
'''
for i in variables :
	o = Plot([mcldst.Get('rec_'+i.name), mcldst.Get('ghost_'+i.name), mcldst.Get('fake_'+i.name)])
	ymax = -1
	for p in o.plots:
		p.UseCurrentStyle()
		if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral() > ymax:
			ymax = p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral()
	o.setProp('colors', ['blue', 'red', 'green'])
	o.setProp('leglims', [0.3, 0.65, 0.7, 0.85])
	o.setProp('markerstyles', 20)
	o.setProp('filename', 'method_'+i.name+'.pdf')
	o.setProp('normalised', True)
	o.setProp('ylabel', '[A.U.]')
	o.setProp('xlabel', i.xlabel)
	o.setProp('drawOpts', 'hist')
	o.setProp('fillstyles', 0)
	o.setProp('ynormlims', [0.001, ymax])
	if hasattr(i, 'logy') and i.logy==True:
		o.setProp('logscale', True)
	#if i.name == 'ghostprob': o.setProp('logscale', True)
	o.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
	o.setProp('labels', ['MC2015 - All Tracks', 'MC2015 - Ghosts', 'MC2015 - Fakes'])
	o.drawROOT()

	ymax = -1
	m = Plot([mcldst.Get('ghost_rate_'+i.name), mcldst.Get('fake_rate_'+i.name)])
	for p in m.plots:
		p.UseCurrentStyle()
		if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1 > ymax:
			ymax = p.GetBinContent(p.GetMaximumBin())*1.1
	m.setProp('colors', ['red', 'green'])
	m.setProp('leglims', [0.3, 0.65, 0.6, 0.85])
	m.setProp('markerstyles', 20)
	m.setProp('filename', 'method_rate_'+i.name+'.pdf')
	m.setProp('ylabel', 'Ghost Rate')
	m.setProp('xlabel', i.xlabel)
	m.setProp('drawOpts', 'hist')
	m.setProp('fillstyles', 0)
        m.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
	m.setProp('ylims', [0, ymax])
	m.setProp('labels', ['MC2015 - Ghosts', 'MC2015 - Fakes'])
	m.drawROOT()

	l = Plot([i.rec, i.fake, i.ghost ])
	ymax = -1
	for p in l.plots:
		p.UseCurrentStyle()
		if ymax == -1 or p.GetMaximum()/p.Integral()*1.1 > ymax:
			ymax = p.GetMaximum()/p.Integral()*1.1
	l.setProp('colors', ['red', 'black', 'blue'])
	l.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
	if i.name=='chi2ndof': 
		l.ShiftLegX(-0.1)
		l.ShiftLegY(0.1)
	elif i.name=='pt':
		l.ShiftLegX(0.1)
	l.setProp('markerstyles', [20, 20, 20])
	l.setProp('filename', 'all_mc2015ldst_'+i.name+'.pdf')
	l.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
	l.setProp('ylabel', '[A.U.]')
	l.setProp('xlabel', i.tex)
	l.setProp('drawOpts', ['hist', 'he1', 'hist'])
	l.setProp('fillstyles', [1001, 0, 0])
	l.setProp('ynormlims', [0.0, ymax])
	l.setProp('labels', ['All Tracks', 'Fake Tracks', 'Ghost Tracks'])
	l.setProp('normalised', True)
	l.setProp('extraObjs', [mc_pave])
	for name, value in i.draw.items():
		if name=='ShiftLegX':
			l.ShiftLegX(value)
		elif name=='ShiftLegY':
			l.ShiftLegY(value)
		else:
			l.setProp(name, value)
	l.drawROOT()


#######################
## mc method v truth (no ghost prob)
#######################

for i in files3 :
	o = Plot([i.rec, i.ghost, i.fake])
	ymax = -1
	for p in o.plots:
		p.UseCurrentStyle()
		if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral() > ymax:
			ymax = p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral()
	o.setProp('colors', ['blue', 'red', 'green'])
	o.setProp('leglims', [0.3, 0.65, 0.7, 0.85])
	o.setProp('markerstyles', 20)
	o.setProp('filename', 'method_noghostprob_'+i.name+'.pdf')
	o.setProp('normalised', True)
	o.setProp('ylabel', '[A.U.]')
	o.setProp('xlabel', i.tex)
	o.setProp('drawOpts', 'hist')
	o.setProp('fillstyles', 0)
	o.setProp('ynormlims', [0, ymax])
	if i.name=='eta': o.ShiftLegX(-0.1)
	elif i.name=='chi2ndof': o.ShiftLegX(0.05)
	#if i.name == 'ghostprob': o.setProp('logscale', True)
	o.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
	o.setProp('labels', ['MC2015 - All Tracks', 'MC2015 - Ghosts', 'MC2015 - Fakes'])
	for name, value in i.draw.items():
		if name=='ShiftLegX':
			o.ShiftLegX(value)
		elif name=='ShiftLegY':
			o.ShiftLegY(value)
		else:
			o.setProp(name, value)
	o.drawROOT()

	ymax = -1
	m = Plot([i.ghost_rate, i.fake_rate])
	for p in m.plots:
		p.UseCurrentStyle()
		if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1 > ymax:
			ymax = p.GetBinContent(p.GetMaximumBin())*1.1
	m.setProp('colors', ['red', 'green'])
	m.setProp('leglims', [0.3, 0.65, 0.6, 0.85])
	m.setProp('markerstyles', 20)
	m.setProp('filename', 'method_rate_noghostprob_'+i.name+'.pdf')
	m.setProp('ylabel', 'Ghost Rate')
	m.setProp('xlabel', i.tex)
	m.setProp('drawOpts', 'hist')
	m.setProp('fillstyles', 0)
        m.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
	m.setProp('ylims', [0, ymax])
	m.setProp('labels', ['MC2015 - Ghosts', 'MC2015 - Fakes'])
	for name, value in i.draw.items():
		if name=='ShiftLegX':
			m.ShiftLegX(value)
		elif name=='ShiftLegY':
			m.ShiftLegY(value)
		else:
			m.setProp(name, value)
	m.drawROOT()
'''
