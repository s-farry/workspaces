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
                self.data_fake = self.data.Get('fake_'+name+'_data2015')
                self.mc_fake   = self.mc.Get('fake_'+name+'_mc2015')
                self.data_rec  = self.data.Get('rec_'+name+'_data2015')
                self.mc_rec    = self.mc.Get('rec_'+name+'_mc2015')
                self.data_fake_rate = self.data.Get('fake_rate_'+name+'_data2015')
                self.mc_fake_rate   = self.mc.Get('fake_rate_'+name+'_mc2015')
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

data   = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_data2015.root")
mc     = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015.root")
mcldst = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015_ldst.root")
mcldst_noghostprob = TFile("/user2/sfarry/workspaces/ghosts/tuples/ghostrate_mc2015_ldst.noghostprob.root")

files = []
files += [ghostvar('pt', data, mc, 'p_{T} [MeV]')]
files += [ghostvar('eta', data, mc, '#eta')]
files += [ghostvar('ghostprob', data, mc, 'Ghost Prob.')]
files += [ghostvar('chi2ndof' , data, mc , '#chi^{2}/ndof')]
files += [ghostvar('nveloclusters', data, mc, 'Velo Clusters', ShiftLegX=0.35, ShiftLegY=0.1)]
files += [ghostvar('npvs', data, mc, 'PVs')]

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

#######################
## data v mc
#######################

data = TPaveText(0.5, 0.4, 0.7, 0.5, 'NDC')
data.SetBorderSize(0)
data.SetFillStyle(0)
data.AddText('2015 Data')

mc = TPaveText(0.5, 0.4, 0.7, 0.5, 'NDC')
mc.SetBorderSize(0)
mc.SetFillStyle(0)
mc.AddText('MC2015')

for v in files:
	
	#compare data and mc shapes
    o = Plot([v.data_fake, v.mc_fake])
    ymax = -1
    for p in o.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral() > ymax:
            ymax = p.GetBinContent(p.GetMaximumBin())*1.1/p.Integral()
    o.setProp('colors', ['red', 'black'])
    o.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    if v.name=='chi2ndof': o.ShiftLegX(0.3)
    o.setProp('markerstyles', [20, 20])
    o.setProp('filename', 'datamc_'+v.name+'.pdf')
    o.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    o.setProp('normalised', True)
    o.setProp('ylabel', '[A.U.]')
    o.setProp('xlabel', v.tex)
    o.setProp('drawOpts', ['p1', 'p1'])
    o.setProp('fillstyles', 0)
    o.setProp('ynormlims', [0, ymax])
    o.setProp('labels', ['MC2015 (Sim08-em)', '2015 EM Data'])
    for name, value in v.draw.items():
	    if name=='ShiftLegX':
		    o.ShiftLegX(value)
	    elif name=='ShiftLegY':
		    o.ShiftLegY(value)
	    else:
		    o.setProp(name, value)
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
    n.setProp('filename', 'comp_'+v.name+'.pdf')
    n.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    n.setProp('normalised', True)
    n.setProp('ylabel', '[A.U.]')
    n.setProp('xlabel', v.tex)
    n.setProp('drawOpts', ['h', 'p1'])
    n.setProp('fillstyles', 0)
    n.setProp('ynormlims', [0, ymax])
    n.setProp('labels', ['MC2015 (Sim08-em)', '2015 EM Data'])
    for name, value in v.draw.items():
	    if name=='ShiftLegX':
		    n.ShiftLegX(value)
	    elif name=='ShiftLegY':
		    n.ShiftLegY(value)
	    else:
		    n.setProp(name, value)
    n.drawROOT()

    ymax = -1.0
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
    elif v.name=='pt':
	    m.ShiftLegX(0.1)
    m.setProp('markerstyles', [20, 20])
    m.setProp('filename', 'comp_rate_'+v.name+'.pdf')
    m.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    m.setProp('ylabel', 'Ghost Rate Estimate')
    m.setProp('xlabel', v.tex)
    m.setProp('drawOpts', ['hist', 'e1'])
    m.setProp('fillstyles', [0, 0])
    m.setProp('ylims', [0.001, ymax])
    m.setProp('labels', ['MC2015 (Sim08-em)', '2015 EM Data'])
    m.setProp('toCompare', {1 : [0]})
    m.setProp('ycomplims', [0.5, 1.49])
    for name, value in v.draw.items():
	    if name=='ShiftLegX':
		    m.ShiftLegX(value)
	    elif name=='ShiftLegY':
		    m.ShiftLegY(value)
	    else:
		    m.setProp(name, value)
    m.drawROOT()

    ymax  = -1

    n = Plot([v.data_rec, v.data_fake ])
    for p in n.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetMaximum()/p.Integral()*1.1 > ymax:
		ymax = p.GetMaximum()/p.Integral()*1.1
    n.setProp('colors', ['red', 'black'])
    n.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    if v.name=='chi2ndof': 
	    n.ShiftLegX(-0.1)
	    n.ShiftLegY(0.1)
    elif v.name=='pt':
	    n.ShiftLegX(0.1)
    n.setProp('markerstyles', [20, 20])
    n.setProp('filename', 'all_data2015_'+v.name+'.pdf')
    n.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    n.setProp('ylabel', '[A.U.]')
    n.setProp('xlabel', v.tex)
    n.setProp('drawOpts', ['he1', 'he1'])
    n.setProp('fillstyles', [1001, 0])
    n.setProp('ynormlims', [0.0, ymax])
    n.setProp('labels', ['All Tracks', 'Fake Tracks'])
    n.setProp('normalised', True)
    n.setProp('extraObjs', [data])
    for name, value in v.draw.items():
	    if name=='ShiftLegX':
		    n.ShiftLegX(value)
	    elif name=='ShiftLegY':
		    n.ShiftLegY(value)
	    else:
		    n.setProp(name, value)
    n.drawROOT()

    l = Plot([v.mc_rec, v.mc_fake ])
    for p in l.plots:
        p.UseCurrentStyle()
	if ymax == -1 or p.GetMaximum()/p.Integral()*1.1 > ymax:
		ymax = p.GetMaximum()/p.Integral()*1.1
    l.setProp('colors', ['red', 'black', 'blue'])
    l.setProp('leglims', [0.25, 0.6, 0.6, 0.85])
    if v.name=='chi2ndof': 
	    l.ShiftLegX(-0.1)
	    l.ShiftLegY(0.1)
    elif v.name=='pt':
	    l.ShiftLegX(0.1)
    l.setProp('markerstyles', [20, 20])
    l.setProp('filename', 'all_mc2015_'+v.name+'.pdf')
    l.setProp('location', '/user2/sfarry/workspaces/ghosts/figures')
    l.setProp('ylabel', '[A.U.]')
    l.setProp('xlabel', v.tex)
    l.setProp('drawOpts', ['he1', 'he1', 'he1'])
    l.setProp('fillstyles', [1001, 0])
    l.setProp('ynormlims', [0.0, ymax])
    l.setProp('labels', ['All Tracks', 'Fake Tracks', 'Ghost Tracks'])
    l.setProp('normalised', True)
    l.setProp('extraObjs', [mc])
    for name, value in v.draw.items():
	    if name=='ShiftLegX':
		    l.ShiftLegX(value)
	    elif name=='ShiftLegY':
		    l.ShiftLegY(value)
	    else:
		    l.setProp(name, value)
    l.drawROOT()

#######################
## mc method v truth
#######################

for i in files2 :
	o = Plot([i.rec, i.ghost, i.fake])
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
	m.setProp('filename', 'method_rate_'+i.name+'.pdf')
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
	l.setProp('extraObjs', [mc])
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
