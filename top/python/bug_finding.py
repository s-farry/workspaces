from ROOT import *

f = TFile("/hepstore/hwark/GridOutput/10/ttbar.MD.2016.root")
g = TFile.Open("root://hepgrid11.ph.liv.ac.uk//dpm/ph.liv.ac.uk/home/lhcb/top/ttbar.MD.2016.root")
t = f.Get("ttbar/DecayTree")
u = g.Get("ttbar/DecayTree")

evts_m_t = [[e.eventNumber, e.ttbar_M] for e in t]
evts_m_u = [[e.eventNumber, e.ttbar_M] for e in u]

evts_t = [ a[0] for a in evts_m_t ]
evts_u = [ a[0] for a in evts_m_u ]

evts_dict_t = {}
evts_dict_u = {}

for a in evts_m_t:
    evts_dict_t[a[0]] = a[1]
for a in evts_m_u:
    evts_dict_u[a[0]] = a[1]

same_evts = [e for e in evts_t if e in evts_u]

for e in same_evts:
    print e,evts_dict_t[e],evts_dict_u[e]
