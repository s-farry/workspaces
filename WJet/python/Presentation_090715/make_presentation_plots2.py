from os import sys
from Jawa import Template
import copy

from Style import SetLHCbStyle
from PlotTools import Plot, MeVtoGeV
#hack
import ROOT
wmupj_data = ROOT.TFile("/user2/sfarry/WJet/python/wmupj.root")
wmumj_data = ROOT.TFile("/user2/sfarry/WJet/python/wmumj.root")
effs  = ROOT.TFile("/user2/sfarry/WJet/tuples/effs.root")
wmup_jeteff  = ROOT.TFile("/user2/sfarry/WJet/python/wmup_jeteff.root")
wmum_jeteff  = ROOT.TFile("/user2/sfarry/WJet/python/wmum_jeteff.root")
zmumu_jeteff = ROOT.TFile("/user2/sfarry/WJet/python/zmumu_jeteff.root")
ROOT.gStyle.Reset()
SetLHCbStyle()
ROOT.gStyle.SetTitleFont(132, "xyz")
ROOT.gStyle.SetLabelFont(132, "xyz")

properties = {
    'includeNormErr' : False,
    'labels'          :      ['ptj>10', 'ptj>20', 'ptj>40', 'ptj>60'],
    'xlabel':     '#eta'    ,
    'ylabel':     '[A.U.]',
    'location' : ".",
    'normalised' : False,
    'logscale' : False,
    'colors' : "None",
    'leglims'  : [0.2, 0.7, 0.5, 0.9],
    'markerstyles' : 20
}
'''
a = Plot([wmupj_data.Get("Data/JetIso"), wmumj_data.Get("Data/JetIso")])
a.plots[1].SetMarkerStyle(20)
a.plots[0].SetLineWidth(2)
a.setProps(properties)
a.properties['labels'] = ['W^{+}j#rightarrow#mu^{+} (2012 Data)', 'W^{-}j#rightarrow#mu^{-}j (2012 Data)']
a.properties['ylabel'] = 'Events'
a.properties['xlabel'] = 'p_{T}(#mu) / p_{T}(j_{#mu})'
a.properties['linecolors'] = ['red', 'black']
a.properties['drawOpts'] = ['h', 'epl']
a.properties['filename']   = "wmu_jetiso"
a.drawROOT()
'''
b = Plot([effs.Get("wp_etaj"), effs.Get("wm_etaj"), effs.Get("z_etaj")])
b.setProps(properties)
b.properties['labels'] = ['W^{+}j#rightarrow#mu^{+} (2012 Data)', 'W^{-}j#rightarrow#mu^{-}j (2012 Data)', 'Z#rightarrow#mu^{+}#mu^{-} (2012 Data)']
b.properties['ylabel'] = 'Muon Rec. Efficiency'
b.properties['xlabel'] = '#eta^{j}'
b.properties['linecolors'] = ['red', 'black', 'blue']
b.properties['drawOpts'] = ['p1', 'p1', 'p1']
b.properties['filename']   = "effs_etaj"
b.properties['ylims'] = [0.6, 0.93]
b.drawROOT()

c = Plot([effs.Get("wp_ptj"), effs.Get("wm_ptj"), effs.Get("z_ptj")])
#for p in c.plots: MeVtoGeV(p)
for p in c.plots:
    p.GetXaxis().SetLimits(p.GetXaxis().GetBinLowEdge(1)/1000.0, p.GetXaxis().GetBinUpEdge(p.GetXaxis().GetNbins())/1000.0)
c.setProps(properties)
c.properties['labels'] = ['W^{+}j#rightarrow#mu^{+} (2012 Data)', 'W^{-}j#rightarrow#mu^{-}j (2012 Data)', 'Z#rightarrow#mu^{+}#mu^{-} (2012 Data)']
c.properties['ylabel'] = 'Muon Rec. Efficiency'
c.properties['xlabel'] = 'p_{T}^{j} [GeV]'
c.properties['linecolors'] = ['red', 'black', 'blue']
c.properties['drawOpts'] = ['p1', 'p1', 'p1']
c.properties['filename']   = "effs_ptj"
c.properties['ylims'] = [0.6, 0.93]
c.drawROOT()

d = Plot([effs.Get("wp_eta"), effs.Get("wm_eta"), effs.Get("z_y")])
d.setProps(properties)
d.properties['labels'] = ['W^{+}j#rightarrow#mu^{+} (2012 Data)', 'W^{-}j#rightarrow#mu^{-}j (2012 Data)', 'Z#rightarrow#mu^{+}#mu^{-} (2012 Data)']
d.properties['ylabel'] = 'Muon Rec. Efficiency'
d.properties['xlabel'] = '#eta^{#mu}, y^{Z}'
d.properties['linecolors'] = ['red', 'black', 'blue']
d.properties['drawOpts'] = ['p1', 'p1', 'p1']
d.properties['filename']   = "effs_eta"
d.properties['ylims'] = [0.6, 0.93]
d.ShiftLegX(-0.4)
d.drawROOT()

dd = Plot([effs.Get("z_dphi")])
dd.setProps(properties)
dd.properties['labels'] = ['Z#rightarrow#mu^{+}#mu^{-} (2012 Data)']
dd.properties['ylabel'] = 'Muon Rec. Efficiency'
dd.properties['xlabel'] = '#Delta#phi [rad.]'
dd.properties['linecolors'] = ['blue']
dd.properties['drawOpts'] = ['p1']
dd.properties['filename']   = "effs_dphi"
dd.properties['ylims'] = [0.6, 0.93]
dd.ShiftLegX(0.2)
dd.ShiftLegY(-0.3)
dd.drawROOT()

e = Plot([wmup_jeteff.Get("Jet_ETA/EfficiencyGraph"), wmum_jeteff.Get("Jet_ETA/EfficiencyGraph"), zmumu_jeteff.Get("Jet_ETA/EfficiencyGraph")])
e.setProps(properties)
e.properties['labels'] = ['W^{+}j#rightarrow#mu^{+} (MC2012)', 'W^{-}j#rightarrow#mu^{-}j (MC2012)', 'Z#rightarrow#mu^{+}#mu^{-} (MC2012)']
e.properties['ylabel'] = 'Jet Rec. Efficiency'
e.properties['xlabel'] = '#eta^{j}'
e.properties['linecolors'] = ['red', 'black', 'blue']
e.properties['drawOpts'] = ['p1', 'p1', 'p1']
e.properties['filename']   = "jeteffs_etaj"
e.properties['ylims'] = [0.8, 1.0]
e.ShiftLegX(0.4)
e.ShiftLegY(-0.4)
e.drawROOT()


f = Plot([wmup_jeteff.Get("Jet_PT/EfficiencyGraph"), wmum_jeteff.Get("Jet_PT/EfficiencyGraph"), zmumu_jeteff.Get("Jet_PT/EfficiencyGraph")])
f.setProps(properties)
f.properties['labels'] = ['W^{+}j#rightarrow#mu^{+} (MC2012)', 'W^{-}j#rightarrow#mu^{-}j (MC2012)', 'Z#rightarrow#mu^{+}#mu^{-} (MC2012)']
f.properties['ylabel'] = 'Jet Rec. Efficiency'
f.properties['xlabel'] = 'p_{T}^{j}'
f.properties['linecolors'] = ['red', 'black', 'blue']
f.properties['drawOpts'] = ['p1', 'p1', 'p1']
f.properties['filename']   = "jeteffs_ptj"
f.properties['ylims'] = [0.7, 1.0]
f.ShiftLegX(0.4)
f.ShiftLegY(-0.4)
f.drawROOT()


g = Plot([wmup_jeteff.Get("ETA/EfficiencyGraph"), wmum_jeteff.Get("ETA/EfficiencyGraph"), zmumu_jeteff.Get("Y/EfficiencyGraph")])
g.setProps(properties)
g.properties['labels'] = ['W^{+}j#rightarrow#mu^{+} (MC2012)', 'W^{-}j#rightarrow#mu^{-}j (MC2012)', 'Z#rightarrow#mu^{+}#mu^{-} (MC2012)']
g.properties['ylabel'] = 'Jet Rec. Efficiency'
g.properties['xlabel'] = '#eta^{#mu}, y^{Z}'
g.properties['linecolors'] = ['red', 'black', 'blue']
g.properties['drawOpts'] = ['p1', 'p1', 'p1']
g.properties['filename']   = "jeteffs_eta"
g.properties['ylims'] = [0.8, 1.0]
g.ShiftLegY(-0.4)
g.drawROOT()



h = Plot([zmumu_jeteff.Get("dPhi/EfficiencyGraph")])
h.setProps(properties)
h.properties['labels'] = ['Z#rightarrow#mu^{+}#mu^{-} (MC2012)']
h.properties['ylabel'] = 'Jet Rec. Efficiency'
h.properties['xlabel'] = '|#Delta#phi|'
h.properties['linecolors'] = ['blue']
h.properties['drawOpts'] = ['p1']
h.properties['filename']   = "jeteffs_dphi"
h.properties['ylims'] = [0.5, 1.0]
h.ShiftLegX(0.4)
h.ShiftLegY(-0.4)
h.drawROOT()



s = ROOT.TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/efficiencySEL_Z_0/efficiencySEL.root")

i = Plot([s.Get('ETA+_MCZ/tGraph'), s.Get('ETA+_MCW/tGraph'), s.Get('ETA-_MCW/tGraph'), s.Get('ETA+/tGraph')])
i.plots[3].SetMarkerStyle(20)
i.setProps(properties)
i.properties['labels'] = ['Pseudo-Wj (MC)', 'W^{+}j(MC)', 'W^{-}j(MC)', 'Pseudo-Wj (Data)']
i.properties['ylabel'] = 'Sel. Efficiency'
i.properties['xlabel'] = '#eta^{#mu}'
i.properties['linecolors'] = ['blue', 'red', 'magenta', 'black']
i.properties['drawOpts'] = ['p1','p1','p1','p1']
i.properties['filename']   = "seleff_eta"
i.properties['ylims'] = [0, 1.3]
i.drawROOT()


j = Plot([s.Get('jETA+_MCZ/tGraph'), s.Get('jETA+_MCW/tGraph'), s.Get('jETA-_MCW/tGraph'), s.Get('jETA+/tGraph')])
j.plots[3].SetMarkerStyle(20)
j.setProps(properties)
j.properties['labels'] = ['Pseudo-Wj (MC)', 'W^{+}j(MC)', 'W^{-}j(MC)', 'Pseudo-Wj (Data)']
j.properties['ylabel'] = 'Sel. Efficiency'
j.properties['xlabel'] = '#eta^{j}'
j.properties['linecolors'] = ['blue', 'red', 'magenta', 'black']
j.properties['drawOpts'] = ['p1','p1','p1','pq']
j.properties['filename']   = "seleff_etaj"
j.properties['ylims'] = [0.5, 1.1]
j.drawROOT()
