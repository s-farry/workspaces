import ROOT

from Style import SetLHCbStyle, SetAtlasStyle
from PlotTools import StackPlot, Plot, WJetPlot, TGraph2Hists
SetLHCbStyle()
#hack
ROOT.gStyle.SetTitleFont(132, "y")
ROOT.gStyle.SetNdivisions(4, "x")
#ROOT.gStyle.SetErrorX(0)
from math import sqrt

from collections import OrderedDict

data_colors = [ROOT.kOrange+1, ROOT.kYellow, ROOT.kAzure, ROOT.kAzure + 10]
data_styles = [1001, 1001, 1001, 1001]

#mc_colors  = [ROOT.kGreen, ROOT.kGreen, ROOT.kMagenta, ROOT.kMagenta]
mc_lcolors  = [ROOT.kBlack, ROOT.kBlack, ROOT.kBlack, ROOT.kBlack]
mc_mcolors  = [ROOT.kBlack, ROOT.kBlack, ROOT.kBlack, ROOT.kBlack]
#mc_markers = [20, 22, 20, 22]
mc_markers = [20, 24, 22, 26]



def normalise_bin_widths(hist, width):
    if ('TH1' in hist.ClassName()):
        for i in range(hist.GetNbinsX()):
            f = width/hist.GetBinWidth(i+1)
            if (f != 1.0):
                hist.SetBinContent(i+1, hist.GetBinContent(i+1)*f)
                hist.SetBinError(i+1, hist.GetBinError(i+1)*f)
    elif ('TGraph' in hist.ClassName()):
        for i in range(hist.GetN()):
            x = ROOT.Double(0.0)
            y = ROOT.Double(0.0)
            width2 = 2 * hist.GetErrorXhigh(i)
            f = width/width2
            if (f != 0):
                hist.GetPoint(i, x, y)
                hist.SetPoint(i, x, y * f)
                hist.SetPointEYhigh(i, hist.GetErrorYhigh(i) * f)
                hist.SetPointEYlow(i, hist.GetErrorYlow(i) * f)

def shift_noxerr(graph, size = 0.5):
    x = ROOT.Double(0.0)
    y = ROOT.Double(0.0)
    N = graph.GetN()
    for i in range(N):
        graph.GetPoint(i, x, y)
        if size > 0:
            shift = graph.GetErrorXhigh(i)*size
        else:
            shift = graph.GetErrorXlow(i)*size
        graph.SetPointEXlow(i,0.0)
        graph.SetPointEXhigh(i,0.0)
        graph.SetPoint(i,x+shift,y)
        graph.GetPoint(i, x, y)

def tgraph2hist(name, graph, err = False):
    x = ROOT.Double(0.0)
    y = ROOT.Double(0.0)
    N = graph.GetN()
    graph.GetPoint(0, x, y)
    low = x - graph.GetErrorXlow(0)
    graph.GetPoint(N - 1, x, y)
    hi  = x + graph.GetErrorXhigh(N-1)
    h = ROOT.TH1F(name, name, N, low, hi)
    for i in range(N):
        graph.GetPoint(i, x, y)
        h.SetBinContent(i+1,y)
    return h


properties = {
    'includeNormErr' : False,
    'labels'          :      ['ptj>10', 'ptj>20', 'ptj>40', 'ptj>60'],
    'xlabel':     '#eta'    ,
    'ylabel':     'd#sigma(Wj)/d#eta',
    'location' : "/user2/sfarry/WJet/figures",
    'logscale' : False,
    'colors'   : [data_colors[1], data_colors[0], mc_lcolors[0], mc_lcolors[1], mc_lcolors[0], mc_lcolors[1], data_colors[3], data_colors[2], mc_lcolors[2], mc_lcolors[3], mc_lcolors[2], mc_lcolors[3]],
    'styles'   : [data_styles[1], data_styles[0], 1001, 1001, 1001, 1001, data_styles[3], data_styles[2], 1001, 1001, 1001, 1001],
    'leglims'  : [0.6, 0.7, 0.9, 0.9],
}

class Plotter:
    def __init__ (self, name, data_tot, data_stat, powheg_scale, powheg_tot, mcatnlo_scale, mcatnlo_tot, xlabel, ylabel, leg = [0.66, 0.72, 0.86, 0.92], ylims = None, xlims = None):
        self.name = name
        self.data_tot = data_tot
        self.data_stat = data_stat
        self.powheg_scale = powheg_scale
        self.powheg_tot   = powheg_tot
        self.mcatnlo_scale = mcatnlo_scale
        self.mcatnlo_tot = mcatnlo_tot
        self.xlabel = xlabel
        self.ylabel = ylabel
        self.leg    = leg
        self.ylims = ylims
        self.xlims = xlims
    def plots(self):
        return [self.data_tot, self.data_stat, self.mcatnlo_tot, self.mcatnlo_scale, self.powheg_tot, self.powheg_scale]

class DiPlotter:
    def __init__ (self, name, data_tot, data_stat, powheg_scale, powheg_tot, mcatnlo_scale, mcatnlo_tot, data2_tot, data2_stat, powheg2_scale, powheg2_tot, mcatnlo2_scale, mcatnlo2_tot, xlabel, ylabel, leg = [0.66, 0.72, 0.86, 0.92], ylims = None, xlims = None):
        self.plotterA = Plotter(name, data_tot, data_stat, powheg, mcatnlo, xlabel, ylabel, leg, ylims, xlims)
        self.plotterB = Plotter(name, data2_tot, data2_stat, powheg2, mcatnlo2, xlabel, ylabel, leg, ylims, xlims)
        self.name = name
        self.xlabel = xlabel
        self.ylabel = ylabel
        self.leg    = leg
        self.ylims = ylims
        self.xlims = xlims
    def __init__ (self, name, plotterA, plotterB, leg=None):
        self.plotterA = plotterA
        self.plotterB = plotterB
        self.name = name
        self.xlabel = plotterA.xlabel
        self.ylabel = plotterA.ylabel
        if leg == None:
            self.leg    = plotterA.leg
        else:
            self.leg    = leg
        self.ylims = plotterA.ylims
        self.xlims = plotterA.xlims
    def plots(self):
        return [self.plotterA.data_tot, self.plotterA.data_stat,
                self.plotterB.data_tot, self.plotterB.data_stat, 
                self.plotterA.mcatnlo_tot, self.plotterA.powheg_tot, 
                self.plotterB.mcatnlo_tot, self.plotterB.powheg_tot,
                self.plotterA.mcatnlo_scale, self.plotterA.powheg_scale, 
                self.plotterB.mcatnlo_scale, self.plotterB.powheg_scale]


h    = ROOT.TFile("/user2/sfarry/Generators/python/Zj_8TeV_amcatnlo.root" )
i    = ROOT.TFile("/user2/sfarry/Generators/python/Zj_8TeV_powheg.root"   )

l    = ROOT.TFile("/user2/sfarry/Generators/python/Wj_8TeV_amcatnlo.root" )
mm    = ROOT.TFile("/user2/sfarry/Generators/python/Wj_8TeV_powheg.root"   )

j   = ROOT.TFile("/user2/sfarry/WJet/tuples/xsecs.root")

#ct    = ROOT.TFile("/user2/sfarry/WJet/tuples/ct-2.root")
#mmht  = ROOT.TFile("/user2/sfarry/WJet/tuples/mmht-2.root")
#nnpdf = ROOT.TFile("/user2/sfarry/WJet/tuples/nnpdf-2.root")

#ct_asym    = ROOT.TFile("/user2/sfarry/WJet/tuples/ct_asym.root")
#mmht_asym  = ROOT.TFile("/user2/sfarry/WJet/tuples/mmht_asym.root")
#nnpdf_asym = ROOT.TFile("/user2/sfarry/WJet/tuples/nnpdf_asym.root")

ratiosf   = ROOT.TFile("/user2/sfarry/WJet/tuples/Ratio.root")
asymmsf   = ROOT.TFile("/user2/sfarry/WJet/tuples/Asym.root")



details = ROOT.TPaveText(0.55,0.68,0.9,0.88, "NDC")
details.AddText("pp#rightarrowZj#rightarrow#mu^{+}#mu^{-}j (#sqrt{s} = 8 TeV)")
#details.AddText("NLO aMC@NLO + PYTHIA8")
#details.AddText("NNPDF 3.0, #alpha_{s}(M_{Z}) = 0.118")
details.AddText("#it{p}_{T}^{#it{#mu}} > 20 GeV, 2 < #it{#eta(#mu)} < 4.5")
details.AddText("#it{p}_{T}^{#it{j}}  > 20 GeV, 2.2 < #it{#eta(j)} < 4.2")
details.SetFillStyle(0)
details.SetBorderSize(0)

wpplots = []
wmplots = []
wplots = []

zplots = []



######################################
#templates to be used to make legends
#
powheg_temp = ROOT.TH1F("powheg_temp", "", 1, 0, 1)
powheg_temp.SetMarkerColor(mc_mcolors[0])
powheg_temp.SetLineColor(mc_lcolors[0])
powheg_temp.SetFillColor(0)
powheg_temp.SetMarkerStyle(mc_markers[0])
powheg_temp.SetMarkerSize(1)
amcatnlo_temp = ROOT.TH1F("amcatnlo_temp", "", 1, 0, 1)
amcatnlo_temp.SetMarkerColor(mc_mcolors[1])
amcatnlo_temp.SetLineColor(mc_lcolors[1])
amcatnlo_temp.SetFillColor(0)
amcatnlo_temp.SetMarkerStyle(mc_markers[1])
amcatnlo_temp.SetMarkerSize(1)
data_tot_temp = ROOT.TH1F("data_tot", "data_tot", 1, 0, 1)
data_tot_temp.SetFillColor(data_colors[1])
data_tot_temp.SetFillStyle(data_styles[1])
data_tot_temp.SetLineColor(0)
data_stat_temp = ROOT.TH1F("data_stat", "data_stat", 1, 0, 1)
data_stat_temp.SetFillColor(data_colors[0])
data_stat_temp.SetFillStyle(data_styles[0])
data_stat_temp.SetLineColor(0)

powheg2_temp = ROOT.TH1F("powheg2_temp", "", 1, 0, 1)
powheg2_temp.SetMarkerColor(mc_mcolors[2])
powheg2_temp.SetLineColor(mc_lcolors[2])
powheg2_temp.SetFillColor(0)
powheg2_temp.SetMarkerStyle(mc_markers[2])
powheg2_temp.SetMarkerSize(1)
amcatnlo2_temp = ROOT.TH1F("amcatnlo2_temp", "", 1, 0, 1)
amcatnlo2_temp.SetMarkerColor(mc_mcolors[3])
amcatnlo2_temp.SetLineColor(mc_lcolors[3])
amcatnlo2_temp.SetFillColor(0)
amcatnlo2_temp.SetMarkerStyle(mc_markers[3])
amcatnlo2_temp.SetMarkerSize(1)
mmht_temp = ROOT.TH1F("mmht_temp", "mmht_temp", 1, 0, 1)
mmht_temp.SetMarkerColor(mc_mcolors[3])
mmht_temp.SetLineColor(mc_lcolors[3])
mmht_temp.SetFillColor(0)
mmht_temp.SetMarkerStyle(22)
mmht_temp.SetMarkerSize(1)
nnpdf_temp = ROOT.TH1F("nnpdf_temp", "nnpdf_temp", 1, 0, 1)
nnpdf_temp.SetMarkerColor(mc_mcolors[3])
nnpdf_temp.SetLineColor(mc_lcolors[3])
nnpdf_temp.SetFillColor(0)
nnpdf_temp.SetMarkerStyle(25)
nnpdf_temp.SetMarkerSize(1)
ct_temp = ROOT.TH1F("ct_temp", "ct_temp", 1, 0, 1)
ct_temp.SetMarkerColor(mc_mcolors[3])
ct_temp.SetLineColor(mc_lcolors[3])
ct_temp.SetFillColor(0)
ct_temp.SetMarkerStyle(20)
ct_temp.SetMarkerSize(1)

data2_tot_temp = ROOT.TH1F("data2_tot", "data_tot", 1, 0, 1)
data2_tot_temp.SetFillColor(data_colors[3])
data2_tot_temp.SetFillStyle(data_styles[3])
data2_tot_temp.SetLineColor(0)
data2_stat_temp = ROOT.TH1F("data2_stat", "data_stat", 1, 0, 1)
data2_stat_temp.SetFillColor(data_colors[2])
data2_stat_temp.SetFillStyle(data_styles[2])
data2_stat_temp.SetLineColor(0)
# make legends

leg = ROOT.TLegend(0.6, 0.57, 0.9, 0.82)
#leg.SetNColumns(2)
leg.SetFillStyle(0)
leg.SetBorderSize(0)
leg.AddEntry(data_stat_temp, 'Data_{stat}', 'f')
leg.AddEntry(data_tot_temp, 'Data_{tot}', 'f')
leg.AddEntry(powheg_temp, 'POWHEG', 'p')
leg.AddEntry(amcatnlo_temp, 'aMC@NLO', 'p')


leg_pdf = ROOT.TLegend(0.5, 0.62, 0.9, 0.87)
leg_pdf.SetFillStyle(0)
leg_pdf.SetBorderSize(0)
leg_pdf.AddEntry(data_stat_temp, 'Data_{stat}', 'f')
leg_pdf.AddEntry(data_tot_temp, 'Data_{tot}', 'f')
leg_pdf.AddEntry(ct_temp, 'CT14', 'p')
leg_pdf.AddEntry(mmht_temp, 'MMHT14', 'p')
leg_pdf.AddEntry(nnpdf_temp, 'NNPDF30', 'p')

lhcb = ROOT.TPaveText(0.5, 0.85, 0.85, 0.91, "NDC")
lhcb.AddText("LHCb, #sqrt{s} = 8 TeV")
lhcb.SetFillStyle(0)
lhcb.SetBorderSize(0)

leg_shiftleft = ROOT.TLegend(0.2, 0.57, 0.5, 0.82)
leg_shiftleft.SetFillStyle(0)
leg_shiftleft.SetBorderSize(0)
leg_shiftleft.AddEntry(data_stat_temp, 'Data_{stat}', 'f')
leg_shiftleft.AddEntry(data_tot_temp, 'Data_{tot}', 'f')
leg_shiftleft.AddEntry(powheg_temp, 'POWHEG', 'p')
leg_shiftleft.AddEntry(amcatnlo_temp, 'aMC@NLO', 'p')
lhcb_shiftleft = ROOT.TPaveText(0.2, 0.8, 0.5, 0.9, "NDC")
lhcb_shiftleft.AddText("LHCb, #sqrt{s} = 8 TeV")
lhcb_shiftleft.SetFillStyle(0)
lhcb_shiftleft.SetBorderSize(0)

leg_a = ROOT.TLegend(0.58, 0.71 + 0.06, 0.95, 0.89 + 0.04, "LHCb, #it{W^{+}j}, #sqrt{s} = 8 TeV")
leg_a.SetNColumns(2)
leg_a.SetFillStyle(0)
#leg_a.SetBorderSize(1)
#leg_a.SetLegendTitle('W+')
leg_a.AddEntry(data_stat_temp, 'Data_{stat}', 'f')
leg_a.AddEntry(powheg_temp, 'POWHEG', 'p')
leg_a.AddEntry(data_tot_temp, 'Data_{tot}', 'f')
leg_a.AddEntry(amcatnlo_temp, 'aMC@NLO', 'p')
leg_a.SetTextSize(0.035)
header = leg_a.GetListOfPrimitives().First()
header.SetTextAlign(22)
header.SetTextSize(0.035)
#header.SetTextColor(ROOT.kOrange)

leg_b = ROOT.TLegend(0.58, 0.62, 0.95, 0.77, "LHCb, #it{W^{-}j}, #sqrt{s} = 8 TeV")
leg_b.SetNColumns(2)
leg_b.SetFillStyle(0)
#leg_b.SetBorderSize(1)
#leg_b.SetLegendTitle('W-')
leg_b.AddEntry(data2_stat_temp, 'Data_{stat}', 'f')
leg_b.AddEntry(powheg2_temp, 'POWHEG', 'p')
leg_b.AddEntry(data2_tot_temp, 'Data_{tot}', 'f')
leg_b.AddEntry(amcatnlo2_temp, 'aMC@NLO', 'p')
leg_b.SetTextSize(0.035)
header = leg_b.GetListOfPrimitives().First()
header.SetTextAlign(22)
header.SetTextSize(0.035)
header.SetFillColor(ROOT.kAzure)
#header.SetTextColor(ROOT.kBlue)

newleg_a = ROOT.TLegend(0.52, 0.71 + 0.06, 0.9, 0.89 + 0.04, "LHCb, #sqrt{s} = 8 TeV")
newleg_a.SetNColumns(2)
newleg_a.SetFillStyle(0)
#leg_a.SetBorderSize(1)
#leg_a.SetLegendTitle('W+')
newleg_a.AddEntry(None, '#it{W^{+}j}', '' )
newleg_a.AddEntry(data_tot_temp, 'Data', 'f')
newleg_a.AddEntry(powheg_temp, 'POWHEG', 'p')
newleg_a.AddEntry(amcatnlo_temp, 'aMC@NLO', 'p')
newleg_a.SetTextSize(0.035)
header = newleg_a.GetListOfPrimitives().First()
header.SetTextAlign(22)
header.SetTextSize(0.035)
#header.SetTextColor(ROOT.kOrange)

newleg_b = ROOT.TLegend(0.52, 0.62 + 0.035, 0.9, 0.77)
newleg_b.SetNColumns(2)
newleg_b.SetFillStyle(0)
#leg_b.SetBorderSize(1)
#leg_b.SetLegendTitle('W-')
newleg_b.AddEntry(None, '#it{W^{-}j}', '')
newleg_b.AddEntry(data2_tot_temp, 'Data', 'f')
newleg_b.AddEntry(powheg2_temp, 'POWHEG', 'p')
newleg_b.AddEntry(amcatnlo2_temp, 'aMC@NLO', 'p')
newleg_b.SetTextSize(0.035)
#header = newleg_b.GetListOfPrimitives().First()
#header.SetTextAlign(22)
#header.SetTextSize(0.035)
#header.SetFillColor(ROOT.kAzure)
#header.SetTextColor(ROOT.kBlue)

wj_leg = ROOT.TLegend(0.62, 0.62 + 0.06, 0.9, 0.89 + 0.04, "LHCb, #sqrt{s} = 8 TeV")
wj_leg.SetNColumns(2)
wj_leg.SetFillStyle(0)
#leg_a.SetBorderSize(1)
#leg_a.SetLegendTitle('W+')
wj_leg.AddEntry(data_tot_temp, ' ', 'f')
wj_leg.AddEntry(None, 'Data (#it{W^{#scale[1.2]{#plus}}j})', '')
wj_leg.AddEntry(data2_tot_temp, ' ', 'f')
wj_leg.AddEntry(None, 'Data (#it{W^{#scale[1.2]{#minus}}j})', '')
wj_leg.AddEntry(powheg_temp, ' ', 'p')
wj_leg.AddEntry(powheg2_temp, 'POWHEG', 'p')
wj_leg.AddEntry(amcatnlo_temp, ' ', 'p')
wj_leg.AddEntry(amcatnlo2_temp, 'aMC@NLO', 'p')

wj_leg.SetTextSize(0.035)
header = wj_leg.GetListOfPrimitives().First()
header.SetTextAlign(22)
header.SetTextSize(0.035)
#header.SetTextColor(ROOT.kOrange)


wj_leg2a = ROOT.TLegend(0.62, 0.8, 0.88, 0.93, "LHCb, #sqrt{s} = 8 TeV")
wj_leg2a.SetFillStyle(0)
#leg_a.SetBorderSize(1)
#leg_a.SetLegendTitle('W+')
wj_leg2a.AddEntry(data_tot_temp, '  Data (#it{W^{#scale[1.2]{#plus}}j})', 'f')
wj_leg2a.AddEntry(data2_tot_temp, '  Data (#it{W^{#scale[1.2]{#minus}}j})', 'f')

wj_leg2a.SetTextSize(0.035)
header = wj_leg2a.GetListOfPrimitives().First()
header.SetTextAlign(22)
header.SetTextSize(0.06)
#header.SetTextColor(ROOT.kOrange)
wj_leg2b = ROOT.TLegend(0.62, 0.70, 0.88, 0.8, "")
wj_leg2b.SetNColumns(2)
wj_leg2b.SetFillStyle(0)
#leg_a.SetBorderSize(1)
#leg_a.SetLegendTitle('W+')
wj_leg2b.AddEntry(powheg_temp, "", 'p')
wj_leg2b.AddEntry(powheg2_temp, '  POWHEG', 'p')
wj_leg2b.AddEntry(amcatnlo_temp, "", 'p')
wj_leg2b.AddEntry(amcatnlo2_temp, '  aMC@NLO', 'p')

wj_leg2b.SetTextSize(0.035)
header = wj_leg2a.GetListOfPrimitives().First()
header.SetTextAlign(22)
header.SetTextSize(0.035)
#header.SetTextColor(ROOT.kOrange)


shiftup = 0.083
shiftright = 0.1201
box = ROOT.TPave(0.5887 + shiftright,
                0.650 + shiftup,
                0.619 + shiftright,
                0.666 + shiftup, 0, "NDC")
box.SetFillColor(ROOT.kBlue)
shiftup = 0.193

box2 = ROOT.TPave(0.5887 + shiftright,
                0.649+shiftup,
                0.619 + shiftright,
                0.665+shiftup, 0, "NDC")
box2.SetFillColor(ROOT.kOrange)

width=0.0423
height = 0.005
pos1 = [0.6418+0.0215/2.0, 0.8215]
pos2 = [0.6418+0.0215/2.0, 0.865]


wj_box1 = ROOT.TPave(pos1[0] - width/2.0,
                pos1[1]-height/2.0,
                pos1[0]+width/2.0,
                pos1[1]+height/2.0, 0, "NDC")
wj_box1.SetFillColor(ROOT.kBlue)
shiftup = 0.193

wj_box2 = ROOT.TPave(pos2[0]-width/2.0,
                pos2[1]-height/2.0,
                pos2[0]+width/2.0,
                pos2[1]+height/2.0, 0, "NDC")
wj_box2.SetFillColor(ROOT.kOrange)


leg2 = ROOT.TLegend(0.63, 0.7, 0.9, 0.9)
leg2.SetFillStyle(0)
leg2.SetBorderSize(0)
leg2.AddEntry(data_stat_temp, 'Data_{stat}', 'f')
leg2.AddEntry(data_tot_temp, 'Data_{tot}', 'f')
leg2.AddEntry(powheg_temp, 'aMC@NLO_{pdf}', 'p')
#leg2.AddEntry(amcatnlo_temp, 'aMC@NLO (pdf)', 'p')


zplots.append(Plotter('etaj', j.Get('z_etaj_toterr'), j.Get('z_etaj_staterr'), i.Get('etaj_scaleerrs'), i.Get('etaj_toterrs'), h.Get('etaj_scaleerrs'), h.Get('etaj_toterrs'), 
                      '#it{#eta^{j}}', '#sigma(#it{Zj}) [pb / (0.5)]', ylims = [0.001,3.4], leg = leg))
zplots.append(Plotter('ptj' , j.Get('z_ptj_toterr') , j.Get('z_ptj_staterr') , i.Get('ptj_scaleerrs'), i.Get('ptj_toterrs'), h.Get('ptj_scaleerrs'), h.Get('ptj_toterrs'),
                      '#it{p}_{T}^{jet} [GeV]','#sigma(#it{Zj}) [pb / (5 GeV)]', leg = leg))
zplots.append(Plotter('yz'  , j.Get('z_y_toterr')  , j.Get('z_y_staterr')  , i.Get('yz_scaleerrs') , i.Get('yz_toterrs') , h.Get('yz_scaleerrs'), h.Get('yz_toterrs')
                      , '#it{y^{Z}}'    ,'#sigma(#it{Zj}) [pb / (0.5)]', ylims = [0.001, 3.8], leg = leg))
zplots.append(Plotter('dphi'  , j.Get('z_dphi_toterr')  , j.Get('z_dphi_staterr')  , i.Get('dphi_scaleerrs') , i.Get('dphi_toterrs') , h.Get('dphi_scaleerrs'), h.Get('dphi_toterrs'), '|#it{#Delta##phi}| [rad]'    ,'#sigma(#it{Zj}) [pb]', ylims = [0.001, 8], leg = leg_shiftleft))

wpplots.append(Plotter('etaj', j.Get('wp_etaj_toterr'), j.Get('wp_etaj_staterr'), mm.Get('etaj_plus_scaleerrs'),  mm.Get('etaj_plus_toterrs'), l.Get('etaj_plus_scaleerrs'), l.Get('etaj_plus_toterrs'), 
                      '#it{#eta}^{jet}', '#sigma(#it{Wj}) [pb / (0.5)]', leg = leg, ylims = [0.001,40]))
wpplots.append(Plotter('ptj' , j.Get('wp_ptj_toterr') , j.Get('wp_ptj_staterr') , mm.Get('ptj_plus_scaleerrs'), mm.Get('ptj_plus_toterrs'), l.Get('ptj_plus_scaleerrs'), l.Get('ptj_plus_toterrs'),
                      '#it{p}_{T}^{jet} [GeV]','#sigma(#it{Wj}) [pb / (5 GeV)]', leg = leg))
wpplots.append(Plotter('eta'  , j.Get('wp_eta_toterr')  , j.Get('wp_eta_staterr')  , mm.Get('eta_plus_scaleerrs') , mm.Get('eta_plus_toterrs') , l.Get('eta_plus_scaleerrs'), l.Get('eta_plus_toterrs')
                      , '#it{#eta}^{#mu}'    ,'#sigma(#it{Wj}) [pb / (0.5)]', leg = leg, ylims = [0.001, 35]))

wmplots.append(Plotter('etaj', j.Get('wm_etaj_toterr'), j.Get('wm_etaj_staterr'), mm.Get('etaj_minus_scaleerrs'),  mm.Get('etaj_minus_toterrs'), l.Get('etaj_minus_scaleerrs'), l.Get('etaj_minus_toterrs'), 
                      '#it{#eta}^{jet}', '#sigma(#it{Wj}) [pb / (0.5)]', leg = leg, ylims = [0.001, 30]))
wmplots.append(Plotter('ptj' , j.Get('wm_ptj_toterr') , j.Get('wm_ptj_staterr') , mm.Get('ptj_minus_scaleerrs'), mm.Get('ptj_minus_toterrs'), l.Get('ptj_minus_scaleerrs'), l.Get('ptj_minus_toterrs'),
                      '#it{p}_{T}^{jet} [GeV]','#sigma(#it{Wj}) [pb / (5 GeV)]', leg = leg))
wmplots.append(Plotter('eta'  , j.Get('wm_eta_toterr')  , j.Get('wm_eta_staterr')  , mm.Get('eta_minus_scaleerrs') , mm.Get('eta_minus_toterrs') , l.Get('eta_minus_scaleerrs'), l.Get('eta_minus_toterrs')
                      , '#it{#eta}^{#mu}'    ,'#sigma(#it{Wj}) [pb / (0.5)]', leg = leg, ylims = [0.001, 18]))

for p,m in zip(wpplots, wmplots):
#    wplots.append(DiPlotter(p.name, p,m, leg = [newleg_a, newleg_b, box, box2]))
#    wplots.append(DiPlotter(p.name, p,m, leg = [wj_leg, wj_box1, wj_box2]))
    wplots.append(DiPlotter(p.name, p,m, leg = [wj_leg2a, wj_leg2b, wj_box1, wj_box2]))

    
for p in zplots:
    binsize = 0
    if p.name == 'ptj':
        binsize = 5
    elif p.name == 'eta':
        binsize = 0.5
    elif p.name == 'etaj':
        binsize = 0.5
    if binsize > 0:
        normalise_bin_widths(p.mcatnlo_tot, binsize)
        normalise_bin_widths(p.powheg_tot, binsize)
        normalise_bin_widths(p.mcatnlo_scale, binsize)
        normalise_bin_widths(p.powheg_scale, binsize)
        normalise_bin_widths(p.data_tot, binsize)
        normalise_bin_widths(p.data_stat, binsize)
    #p.mcatnlo_tot.SetMarkerStyle(mc_markers[1])
    #p.mcatnlo_tot.SetMarkerColor(mc_mcolors[1])
    #p.powheg_tot.SetMarkerStyle(mc_markers[0])
    #p.powheg_tot.SetMarkerColor(mc_mcolors[0])
    #p.mcatnlo_scale.SetMarkerStyle(mc_markers[1])
    #p.mcatnlo_scale.SetMarkerColor(mc_mcolors[1])
    #p.powheg_scale.SetMarkerStyle(mc_markers[0])
    #p.powheg_scale.SetMarkerColor(mc_mcolors[0])
    shift_noxerr(p.mcatnlo_tot ,size = 0.3)
    shift_noxerr(p.powheg_tot  ,size = -0.3)
    shift_noxerr(p.mcatnlo_scale ,size = 0.3)
    shift_noxerr(p.powheg_scale  ,size = -0.3)
    a = Plot(p.plots())
    a.setProps(properties)
    a.properties['labels'] = ['Data, #sqrt{s} = 8 TeV (tot)', 'Data, #sqrt{s} = 8 TeV (stat)', 'aMC@NLO(tot)', 'aMC@NLO(scale)', 'Powheg', 'Powheg']
    a.properties['ylabel'] = p.ylabel
    a.properties['xlabel'] = p.xlabel
    a.properties['drawOpts'] = ['e2', 'e2', 'p1','p1', 'p1','p1']
    if (isinstance(p.leg, ROOT.TLegend)):
        a.properties['extraObjs'] += [p.leg]
        a.properties['legend'] = False
    else:
        a.properties['leglims'] = p.leg
    if p.name=='dphi':
        a.properties['extraObjs'] += [lhcb_shiftleft]
    else:
        a.properties['extraObjs'] += [lhcb]
    a.setProp('markerstyles', [0, 0, mc_markers[1], mc_markers[1], mc_markers[0], mc_markers[0]])
    a.setProp('markercolors', [0, 0, mc_mcolors[1], mc_mcolors[0], mc_mcolors[1], mc_mcolors[0]])
    a.setProp('canvas_size', [800, 800])
    a.properties['toCompare'] = {0 : [0, 1, 2 ,3, 4]}
    a.properties['normerrlims'] = [0.51,1.49]
    if p.name=='dphi':
        a.properties['normerrlims'] = [0.41, 1.59]
    a.properties['filename']   = "zj_"+p.name+"_8TeV_log"
    a.setProp("logscale", True)
    if p.name == 'dphi':
        a.ShiftLegX(-0.5)
    a.drawROOT()
    a.setProp("logscale", False)
    a.setProp("filename", a.properties['filename'].replace('_log',''))
    if p.ylims: a.properties['ylims'] = p.ylims
    if p.xlims: a.properties['xlims'] = p.xlims
    a.drawROOT()

for p in wpplots:
    binsize = 0
    if p.name == 'ptj':
        binsize = 5
    elif p.name == 'eta':
        binsize = 0.5
    elif p.name == 'etaj':
        binsize = 0.5
    if binsize > 0:
        normalise_bin_widths(p.mcatnlo_tot, binsize)
        normalise_bin_widths(p.powheg_tot, binsize)
        normalise_bin_widths(p.mcatnlo_scale, binsize)
        normalise_bin_widths(p.powheg_scale, binsize)
        normalise_bin_widths(p.data_tot, binsize)
        normalise_bin_widths(p.data_stat, binsize)
    p.mcatnlo_tot.SetMarkerStyle(mc_markers[1])
    p.mcatnlo_tot.SetMarkerColor(mc_mcolors[1])
    p.powheg_tot.SetMarkerStyle(mc_markers[0])
    p.powheg_tot.SetMarkerColor(mc_mcolors[0])
    p.mcatnlo_scale.SetMarkerStyle(mc_markers[1])
    p.mcatnlo_scale.SetMarkerColor(mc_mcolors[1])
    p.powheg_scale.SetMarkerStyle(mc_markers[0])
    p.powheg_scale.SetMarkerColor(mc_mcolors[0])
    shift_noxerr(p.mcatnlo_tot ,size = 0.3)
    shift_noxerr(p.powheg_tot  ,size = -0.3)
    shift_noxerr(p.mcatnlo_scale ,size = 0.3)
    shift_noxerr(p.powheg_scale  ,size = -0.3)
    a = Plot(p.plots())
    a.setProps(properties)
    a.properties['labels'] = ['Data, #sqrt{s} = 8 TeV (tot)', 'Data, #sqrt{s} = 8 TeV (stat)', 'aMC@NLO', 'Powheg']
    a.properties['ylabel'] = p.ylabel
    a.properties['xlabel'] = p.xlabel
    a.properties['drawOpts'] = ['e2', 'e2', 'p1','p1', 'p1', 'p1']
    if (isinstance(p.leg, ROOT.TLegend)):
        a.properties['extraObjs'] += [p.leg]
        a.properties['legend'] = False
    else:
        a.properties['leglims'] = p.leg
    a.properties['filename']   = "wpj_"+p.name+"_8TeV"
    #a.properties['extraObjs']  += [ details ]
    if p.name == 'ptj': a.properties['logscale'] = True
    if p.ylims: a.properties['ylims'] = p.ylims
    if p.xlims: a.properties['xlims'] = p.xlims
    a.drawROOT()

for p in wmplots:
    binsize = 0
    if p.name == 'ptj':
        binsize = 5
    elif p.name == 'eta':
        binsize = 0.5
    elif p.name == 'etaj':
        binsize = 0.5
    if binsize > 0:
        normalise_bin_widths(p.mcatnlo_tot, binsize)
        normalise_bin_widths(p.powheg_tot, binsize)
        normalise_bin_widths(p.mcatnlo_scale, binsize)
        normalise_bin_widths(p.powheg_scale, binsize)
        normalise_bin_widths(p.data_tot, binsize)
        normalise_bin_widths(p.data_stat, binsize)
    p.mcatnlo_tot.SetMarkerStyle(mc_markers[3])
    p.mcatnlo_tot.SetMarkerColor(mc_mcolors[3])
    p.powheg_tot.SetMarkerStyle(mc_markers[2])
    p.powheg_tot.SetMarkerColor(mc_mcolors[2])
    p.mcatnlo_scale.SetMarkerStyle(mc_markers[3])
    p.mcatnlo_scale.SetMarkerColor(mc_mcolors[3])
    p.powheg_scale.SetMarkerStyle(mc_markers[2])
    p.powheg_scale.SetMarkerColor(mc_mcolors[2])
    shift_noxerr(p.mcatnlo_tot ,size = 0.3)
    shift_noxerr(p.powheg_tot  ,size = -0.3)
    shift_noxerr(p.mcatnlo_scale ,size = 0.3)
    shift_noxerr(p.powheg_scale  ,size = -0.3)
    a = Plot(p.plots())
    a.setProps(properties)
    a.properties['labels'] = ['Data, #sqrt{s} = 8 TeV (tot)', 'Data, #sqrt{s} = 8 TeV (stat)', 'aMC@NLO', 'Powheg']
    a.properties['ylabel'] = p.ylabel
    a.properties['xlabel'] = p.xlabel
    a.properties['drawOpts'] = ['e2', 'e2', 'p1','p1', 'p1', 'p1']
    if (isinstance(p.leg, ROOT.TLegend)):
        a.properties['extraObjs'] += [p.leg]
        a.properties['legend'] = False
    else:
        a.properties['leglims'] = p.leg
    a.properties['filename']   = "wmj_"+p.name+"_8TeV"
    #a.properties['extraObjs']  += [ details ]
    if p.name == 'ptj': a.properties['logscale'] = True
    if p.ylims: a.properties['ylims'] = p.ylims
    if p.xlims: a.properties['xlims'] = p.xlims
    a.drawROOT()

for w in wplots:
    a = Plot(w.plots())
    a.setProps(properties)
    a.properties['ylabel'] = w.ylabel
    a.properties['xlabel'] = w.xlabel
    a.properties['drawOpts'] = ['e2', 'e2', 'e2','e2', 'p1','p1', 'p1', 'p1', 'p1','p1','p1', 'p1']
    if (isinstance(w.leg, ROOT.TLegend)):
        a.properties['extraObjs'] += [w.leg]
        a.properties['legend'] = False
    elif (isinstance(w.leg, list)):
        a.properties['extraObjs'] += w.leg
        a.properties['legend'] = False
    else:
        a.properties['leglims'] = w.leg
    a.properties['colors'] = [data_colors[1], data_colors[0], data_colors[3], data_colors[2], mc_lcolors[0], mc_lcolors[1], mc_lcolors[2], mc_lcolors[3], mc_lcolors[0], mc_lcolors[1], mc_lcolors[2], mc_lcolors[3]]
    a.properties['filename']   = "wj_"+w.name+"_8TeV"
    #a.properties['extraObjs']  += [ details ]
    #if w.name == 'ptj': a.properties['logscale'] = True
    if w.ylims: a.properties['ylims'] = w.ylims
    if w.xlims: a.properties['xlims'] = w.xlims
    a.properties['toCompare'] = OrderedDict([(2, [2,3,6,7,10,11]), (0, [0, 1, 4 ,5, 8, 9])])
    a.setProp('normerrlims', [0.71, 1.29])
    if w.name=='etaj': a.setProp('normerrlims', [0.61, 1.59])
    if w.name=='ptj': a.setProp('normerrlims', [0.61, 1.59])
    a.setProp('canvas_size', [600, 800])
    a.drawROOT()
    a.setProp("logscale", True)
    a.setProp("filename", a.properties['filename']+'_log')
    if w.name=='ptj' : a.setProp('ylims', [0.19, 40])
    if w.name=='etaj' : a.setProp('xticks', 404)
    a.drawROOT()
    a.setProp("logx", True)
    a.setProp("filename", a.properties['filename']+'_logx')
    a.drawROOT()


a = Plot([j.Get('w_a_eta_toterr'), j.Get('w_a_eta_staterr'), l.Get('asymm_eta_toterr'), l.Get('asymm_eta_scaleerr'), mm.Get('asymm_eta_toterr'), mm.Get('asymm_eta_scaleerr')])
a.setProps(properties)
a.plots[2].SetMarkerStyle(mc_markers[1])
a.plots[2].SetMarkerColor(mc_mcolors[3])
a.plots[3].SetMarkerStyle(mc_markers[1])
a.plots[3].SetMarkerColor(mc_mcolors[3])
a.plots[4].SetMarkerStyle(mc_markers[0])
a.plots[4].SetMarkerColor(mc_mcolors[1])
a.plots[5].SetMarkerStyle(mc_markers[0])
a.plots[5].SetMarkerColor(mc_mcolors[2])
shift_noxerr(a.plots[2] ,size = 0.3)
shift_noxerr(a.plots[3]  ,size = 0.3)
shift_noxerr(a.plots[4] ,size = -0.3)
shift_noxerr(a.plots[5]  ,size = -0.3)
#shift_noxerr(a.plots[2], size = 0.0)
#shift_noxerr(a.plots[3], size = 0.0)
a.properties['labels'] = ['Data, #sqrt{s} = 8 TeV (tot)', 'Data, #sqrt{s} = 8TeV (stat)', 'aMC@NLO', 'Powheg']
a.properties['ylabel'] = 'A(#it{Wj})'
a.properties['xlabel'] = '#it{#eta}^{#mu}'
a.properties['drawOpts'] = ['e2', 'e2', 'p1','p1','p1','p1']
a.properties['extraObjs'] += [lhcb, leg]
a.properties['legend'] = False
a.properties['filename']   = "wj_asymm_eta_8TeV"
a.properties['ylims'] = [-0.19, 0.7]
a.properties['xlims'] = [2, 4.5]
a.properties['normerrlims'] = [-0.1,0.1]
#a.properties['normerrlims'] = [0.81,1.19]
#a.properties['normerrlims'] = [-0.09,0.09]
a.properties['toCompare'] = {0 : [0, 1, 2 ,3, 4]}
a.setProp('compareAsRatio', False)
a.setProp('markerstyles', [0, 0, mc_markers[1], mc_markers[1], mc_markers[0], mc_markers[0]])
a.setProp('canvas_size', [800, 800])
#a.setProp('markercolors', [0, 0, mc_markers[1], mc_markers[1], mc_markers[0], mc_markers[0]])
a.drawROOT()


r = Plot([j.Get('w_r_eta_toterr'), j.Get('w_r_eta_staterr'),  l.Get('ratio_eta_toterr'), l.Get('ratio_eta_scaleerr'), mm.Get('ratio_eta_toterr'), mm.Get('ratio_eta_scaleerr')])
shift_noxerr(p.mcatnlo_tot ,size = -0.3)
shift_noxerr(p.powheg_tot  ,size = 0.3)
r.setProps(properties)
#shift_noxerr(r.plots[2], size = 0.0)
#shift_noxerr(r.plots[3], size = 0.0)
r.plots[2].SetMarkerStyle(mc_markers[1])
r.plots[2].SetMarkerColor(mc_mcolors[3])
r.plots[3].SetMarkerStyle(mc_markers[1])
r.plots[3].SetMarkerColor(mc_mcolors[3])
r.plots[4].SetMarkerStyle(mc_markers[0])
r.plots[4].SetMarkerColor(mc_mcolors[2])
r.plots[5].SetMarkerStyle(mc_markers[0])
r.plots[5].SetMarkerColor(mc_mcolors[2])
shift_noxerr(r.plots[2] ,size = 0.3)
shift_noxerr(r.plots[3]  ,size = 0.3)
shift_noxerr(r.plots[4] ,size = -0.3)
shift_noxerr(r.plots[5]  ,size = -0.3)
r.properties['labels'] = ['Data, #sqrt{s} = 8 TeV (tot)', 'Data, #sqrt{s} = 8 TeV (stat)', 'aMC@NLO (pdf)', 'aMC@NLO (scale)']
r.properties['ylabel'] = 'R_{#it{W}^{#pm}}'
r.properties['xlabel'] = '#it{#eta}^{#mu}'
r.properties['drawOpts'] = ['e2', 'e2', 'p1','p1','p1','p1']
r.properties['extraObjs'] += [lhcb, leg]
r.properties['legend'] = False
r.setProp('markerstyles', [0, 0, mc_markers[1], mc_markers[1], mc_markers[0], mc_markers[0]])
r.setProp('canvas_size', [800, 800])
r.properties['toCompare'] = {0 : [0, 1, 2 ,3, 4]}
r.properties['filename']   = "wj_ratio_eta_8TeV"
r.properties['ylims'] = [0.01, 3.5]
r.properties['xlims'] = [2, 4.5]
r.properties['normerrlims'] = [0.71,1.29]
r.properties['colors'] = [400, 801, 1, 1, 1, 1, 1, 1]
r.drawROOT()

a = Plot([j.Get('w_a_eta_toterr'), j.Get('w_a_eta_staterr'),  asymmsf.Get("ctSCALE"), asymmsf.Get("ctTOT"), asymmsf.Get("mmhtSCALE"), asymmsf.Get("mmhtTOT"), asymmsf.Get("nnpdfSCALE"), asymmsf.Get("nnpdfTOT")])
a.setProps(properties)
shift_noxerr(a.plots[2] ,size = -0.4)
shift_noxerr(a.plots[3] ,size = -0.4)
shift_noxerr(a.plots[4]  ,size = 0.0)
shift_noxerr(a.plots[5]  ,size = 0.0)
shift_noxerr(a.plots[6] ,size = 0.4)
shift_noxerr(a.plots[7] ,size = 0.4)
a.properties['labels'] = ['Data, #sqrt{s} = 8 TeV (tot)', 'Data, #sqrt{s} = 8TeV (stat)', 'aMC@NLO', 'Powheg']
a.properties['ylabel'] = 'A(#it{Wj})'
a.properties['xlabel'] = '#it{#eta}^{#mu}'
a.properties['drawOpts'] = ['e2', 'e2', 'p1','p1','p1','p1', 'p1', 'p1', 'p1']
a.properties['extraObjs'] += [lhcb, leg_pdf]
a.properties['legend'] = False
a.properties['filename']   = "wj_asymm_eta_fewz_8TeV"
a.properties['ylims'] = [-0.19, 0.7]
a.properties['xlims'] = [2, 4.5]
a.properties['normerrlims'] = [-0.1,0.1]
a.properties['toCompare'] = {0 : [0, 1, 2 , 3, 4, 5, 6, 7]}
a.properties['colors'] = [400, 801, 1, 1, 1, 1, 1, 1]

a.setProp('compareAsRatio', False)
a.setProp('markerstyles', [0, 0, 20, 20, 22, 22, 25, 25])
a.setProp('canvas_size', [800, 800])
a.drawROOT()


r = Plot([j.Get('w_r_eta_toterr'), j.Get('w_r_eta_staterr'),  ratiosf.Get("ctSCALE"), ratiosf.Get("ctTOT"), ratiosf.Get("mmhtSCALE"), ratiosf.Get("mmhtTOT"), ratiosf.Get("nnpdfSCALE"), ratiosf.Get("nnpdfTOT")])
shift_noxerr(r.plots[2] ,size = -0.4)
shift_noxerr(r.plots[3] ,size = -0.4)
shift_noxerr(r.plots[4]  ,size = 0.0)
shift_noxerr(r.plots[5]  ,size = 0.0)
shift_noxerr(r.plots[6] ,size = 0.4)
shift_noxerr(r.plots[7] ,size = 0.4)
r.setProps(properties)
r.properties['ylabel'] = 'R_{#it{W}^{#pm}}'
r.properties['xlabel'] = '#it{#eta}^{#mu}'
r.properties['drawOpts'] = ['e2', 'e2', 'p1','p1','p1','p1', 'p1', 'p1', 'p1']
r.properties['extraObjs'] += [lhcb, leg_pdf]
r.properties['legend'] = False
r.setProp('markerstyles', [0, 0, 20, 20, 22, 22, 25, 25])
r.setProp('canvas_size', [800, 800])
r.properties['toCompare'] = {0 : [0, 1, 2 ,3, 4, 5, 6, 7]}
r.properties['filename']   = "wj_ratio_eta_fewz_8TeV"
r.properties['ylims'] = [0.01, 3.5]
r.properties['xlims'] = [2, 4.5]
r.properties['normerrlims'] = [0.71,1.29]
r.properties['colors'] = [400, 801, 1, 1, 1, 1, 1, 1]
r.drawROOT()


#asymms versus ptj

a = Plot([j.Get('w_a_ptj_toterr'), j.Get('w_a_ptj_staterr'), l.Get('asymm_ptj_toterr'), l.Get('asymm_ptj_scaleerr'), mm.Get('asymm_ptj_toterr'), mm.Get('asymm_ptj_scaleerr')])
a.setProps(properties)
a.plots[2].SetMarkerStyle(mc_markers[1])
a.plots[2].SetMarkerColor(mc_mcolors[3])
a.plots[3].SetMarkerStyle(mc_markers[1])
a.plots[3].SetMarkerColor(mc_mcolors[3])
a.plots[4].SetMarkerStyle(mc_markers[0])
a.plots[4].SetMarkerColor(mc_mcolors[1])
a.plots[5].SetMarkerStyle(mc_markers[0])
a.plots[5].SetMarkerColor(mc_mcolors[2])
shift_noxerr(a.plots[2] ,size = 0.3)
shift_noxerr(a.plots[3]  ,size = 0.3)
shift_noxerr(a.plots[4] ,size = -0.3)
shift_noxerr(a.plots[5]  ,size = -0.3)
#shift_noxerr(a.plots[2], size = 0.0)
#shift_noxerr(a.plots[3], size = 0.0)
a.properties['labels'] = ['Data, #sqrt{s} = 8 TeV (tot)', 'Data, #sqrt{s} = 8TeV (stat)', 'aMC@NLO', 'Powheg']
a.properties['ylabel'] = 'A(#it{Wj})'
a.properties['xlabel'] = '#it{p}_{T}^{jet} [GeV]'
a.properties['drawOpts'] = ['e2', 'e2', 'p1','p1','p1','p1']
a.properties['extraObjs'] += [lhcb, leg]
a.properties['legend'] = False
a.properties['filename']   = "wj_asymm_ptj_8TeV"
a.properties['ylims'] = [0.101, 0.7]
a.properties['xlims'] = [2, 4.5]
a.properties['normerrlims'] = [-0.1,0.099]
#a.properties['normerrlims'] = [0.81,1.19]
#a.properties['normerrlims'] = [-0.09,0.09]
a.properties['toCompare'] = {0 : [0, 1, 2 ,3, 4]}
a.setProp('compareAsRatio', False)
a.setProp('markerstyles', [0, 0, mc_markers[1], mc_markers[1], mc_markers[0], mc_markers[0]])
a.setProp('canvas_size', [800, 800])
#a.setProp('markercolors', [0, 0, mc_markers[1], mc_markers[1], mc_markers[0], mc_markers[0]])
a.drawROOT()


r = Plot([j.Get('w_r_ptj_toterr'), j.Get('w_r_ptj_staterr'),  l.Get('ratio_ptj_toterr'), l.Get('ratio_ptj_scaleerr'), mm.Get('ratio_ptj_toterr'), mm.Get('ratio_ptj_scaleerr')])
shift_noxerr(p.mcatnlo_tot ,size = -0.3)
shift_noxerr(p.powheg_tot  ,size = 0.3)
r.setProps(properties)
#shift_noxerr(r.plots[2], size = 0.0)
#shift_noxerr(r.plots[3], size = 0.0)
r.plots[2].SetMarkerStyle(mc_markers[1])
r.plots[2].SetMarkerColor(mc_mcolors[3])
r.plots[3].SetMarkerStyle(mc_markers[1])
r.plots[3].SetMarkerColor(mc_mcolors[3])
r.plots[4].SetMarkerStyle(mc_markers[0])
r.plots[4].SetMarkerColor(mc_mcolors[2])
r.plots[5].SetMarkerStyle(mc_markers[0])
r.plots[5].SetMarkerColor(mc_mcolors[2])
shift_noxerr(r.plots[2] ,size = 0.3)
shift_noxerr(r.plots[3]  ,size = 0.3)
shift_noxerr(r.plots[4] ,size = -0.3)
shift_noxerr(r.plots[5]  ,size = -0.3)
r.properties['labels'] = ['Data, #sqrt{s} = 8 TeV (tot)', 'Data, #sqrt{s} = 8 TeV (stat)', 'aMC@NLO (pdf)', 'aMC@NLO (scale)']
r.properties['ylabel'] = 'R_{#it{W}^{#pm}}'
r.properties['xlabel'] = '#it{p}_{T}^{jet} [GeV]'
r.properties['drawOpts'] = ['e2', 'e2', 'p1','p1','p1','p1']
r.properties['extraObjs'] += [lhcb, leg]
r.properties['legend'] = False
r.setProp('markerstyles', [0, 0, mc_markers[1], mc_markers[1], mc_markers[0], mc_markers[0]])
r.setProp('canvas_size', [800, 800])
r.properties['toCompare'] = {0 : [0, 1, 2 ,3, 4]}
r.properties['filename']   = "wj_ratio_ptj_8TeV"
r.properties['ylims'] = [0.01, 4.5]
r.properties['xlims'] = [2, 4.5]
r.properties['normerrlims'] = [0.71,1.29]
r.properties['colors'] = [400, 801, 1, 1, 1, 1, 1, 1]
r.drawROOT()
