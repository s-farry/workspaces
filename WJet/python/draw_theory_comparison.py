#!/usr/bin/env python
from ROOT import gPad
from Style import *
SetLHCbStyle()

class points:
    def __init__(self, data, color = 'red'):
        from math import sqrt
        from ROOT import gStyle, TGraphAsymmErrors
        from ROOT import kRed, kBlue, kGreen, kOrange, kMagenta, kCyan
        self.colors = {
              'black'  : (1, 14, 18),
              'red'    : (kRed, kRed - 9),
              'blue'   : (kBlue, kBlue - 9, kBlue - 10),
              'green'  : (kGreen + 3, kGreen -6),
              'orange' : (kOrange - 3, kOrange -9),
              'magenta': (kMagenta, kMagenta - 9),
              'cyan'   : (kCyan)}
        self.graphs = (TGraphAsymmErrors(len(data)),
                       TGraphAsymmErrors(len(data)),
                       TGraphAsymmErrors(len(data)),
                       TGraphAsymmErrors(len(data)))
        self.graphs[0].SetLineColor(self.colors['black'][0])
        self.graphs[1].SetLineColor(self.colors['black'][1])
        self.graphs[1].SetMarkerStyle(20)
        self.graphs[2].SetFillColor(self.colors[color][1])
        self.graphs[3].SetLineColor(self.colors[color][0])
        self.graphs[3].SetLineWidth(2)

        for (i, (x, exp, thr)) in enumerate(data):
            cmb = sqrt(exp[1]**2 + exp[2]**2)
            self.graphs[0].SetPoint(i, x, exp[0])
            self.graphs[0].SetPointError(i, 0, 0, exp[1], exp[1])
            self.graphs[1].SetPoint(i, x, exp[0])
            self.graphs[1].SetPointError(i, 0, 0, cmb, cmb)
            self.graphs[2].SetPoint(i, x, thr[0])
            self.graphs[2].SetPointError(i, 0.5, 0.5, thr[1], thr[2])
            self.graphs[3].SetPoint(i, x, thr[0])
            self.graphs[3].SetPointError(i, 0.5, 0.5, 0, 0)

    def limits(self, lim):
        for graph in self.graphs:
            graph.Draw()
            x = (graph.GetX(), graph.GetEXlow(), graph.GetEXhigh())
            y = (graph.GetY(), graph.GetEYlow(), graph.GetEYhigh())
            for i in range(0, graph.GetN()):
                if lim[1] == None or x[0][i] + x[2][i] > lim[1]: 
                    lim[1] = x[0][i] + x[2][i]
                if lim[0]  == None or x[0][i] - x[1][i] < lim[0]: 
                    lim[0]  = x[0][i] - x[1][i]
                if lim[3] == None or y[0][i] + y[2][i] > lim[3]: 
                    lim[3] = y[0][i] + y[2][i]
                if lim[2]  == None or y[0][i] - y[1][i] < lim[2]: 
                    lim[2]  = y[0][i] - y[1][i]

    def draw(self, title, data, first = True):
        lim = [None, None, None, None]
        if first:
            from ROOT import TGraph, TPaveText
            self.limits(lim)
            for datum in data: datum.limits(lim)
            if lim[2] == None or lim[3] == None:
                ydif = 0; lim[2] = 0; lim[3] = 0
            else: ydif = 0.2*(lim[3] - lim[2]); lim[2] -= ydif; lim[3] += ydif 
            self.frame = gPad.DrawFrame(-0.5, lim[2], lim[1], lim[3])
            self.frame.SetTitle('')
            self.frame.GetXaxis().SetTitle('')
            self.frame.GetYaxis().CenterTitle()
            self.frame.GetYaxis().SetTitleSize(0.05)
            self.frame.GetYaxis().SetTitle(title)
            axis = self.frame.GetXaxis()
            axis.SetTickLength(0)
            for i in range(1, axis.GetNbins() + 1): axis.SetBinLabel(i, '')
        self.graphs[2].Draw('SAME2')
        self.graphs[3].Draw('SAMEP')
        self.graphs[1].Draw('SAMEP')
        self.graphs[0].Draw('SAMEP')
        for datum in data: datum.draw('', [], False)
        if first:
            xdif = (lim[1] - lim[0])
            self.line = TGraph(2)
            self.line.SetPoint(0,  xdif / 2 + lim[0], lim[2])
            self.line.SetPoint(1,  xdif / 2 + lim[0], lim[3])
            self.line.SetLineWidth(1)
            self.line.SetLineColor(self.colors['black'][0])
            self.line.Draw('SAMEL')
            self.text = [TPaveText(0.12, 0.8, 0.47, 0.9, 'NDC'),
                         TPaveText(0.52, 0.8, 0.87, 0.9, 'NDC')]
            self.text[0].AddText('#sqrt{s} = 7 TeV LHCb data')
            self.text[1].AddText('#sqrt{s} = 8 TeV LHCb data')
            for text in self.text: 
                text.SetFillStyle(0); text.SetBorderSize(0); text.Draw()
            gPad.RedrawAxis()

# The b,c-ratios.
xsecs = points([(0, (5.80, 0.44, 0.75), (5.02, 0.69, 0.80)),
                (1, (5.62, 0.28, 0.73), (5.31, 0.52, 0.87))], 'green')
ratios = points([(3, (0.66, 0.13, 0.13), (0.74, 0.13, 0.17)),
            (4, (0.78, 0.08, 0.16), (0.77, 0.13, 0.18))], 'red')
asymm = points([(0, (-0.09, 0.08, 0.04), (-0.15, 0.04, 0.02)),
                (5, (-0.01, 0.05, 0.04), (-0.14, 0.03, 0.02))], 'green')
xsecs.draw('xsec', [ratios, asymm])
gPad.Print('test.pdf')
