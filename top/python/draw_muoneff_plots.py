from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()

trk2015 = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTracking2015.root")
trk2016 = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTracking2016.root")

id2015 = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonID2015.root")
id2016 = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonID2016.root")

trg2015 = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTrigger2015.root")
trg2016 = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTrigger2016.root")

plots = [
    Bunch(name='ETA', xlabel = '#eta', trgshiftlegx=-0.4, trgshiftlegy=-0.4, idshiftlegx=-0.2, idshiftlegy=-0.5,
          trkylims = [0.88, 1.00], idylims = [0.88, 1.00]),
    Bunch(name='PT', xlabel = 'p_{T} [GeV]', trgshiftlegx = -0.4, trkshiftlegx=-0.2, trkshiftlegy=-0.5,
          idshiftlegx=-0.2, idshiftlegy=-0.5),
    Bunch(name='PHI', xlabel = '#phi [rad.]', idshiftlegx=-0.2, idshiftlegy=-0.5),
    Bunch(name='SPDHits', xlabel = 'SPD Hits')
]

for p in plots:
    d = Plot([trk2015.Get(p.name+'/EfficiencyGraph'), trk2016.Get(p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Tracking Eff.')
    d.setProp('labels', ['2015', '2016'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'muontrkeff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'trkshiftlegx'): d.ShiftLegX(p.trkshiftlegx)
    if hasattr(p, 'trkshiftlegy'): d.ShiftLegY(p.trkshiftlegy)
    if hasattr(p, 'trkylims'): d.setProp('ylims', p.trkylims)
    d.drawROOT()
    

    d = Plot([id2015.Get(p.name+'/EfficiencyGraph'), id2016.Get(p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'ID Eff.')
    d.setProp('labels', ['2015', '2016'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'muonideff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'idshiftlegx'): d.ShiftLegX(p.idshiftlegx)
    if hasattr(p, 'idshiftlegy'): d.ShiftLegY(p.idshiftlegy)
    if hasattr(p, 'idylims'): d.setProp('ylims', p.idylims)
    d.drawROOT()

    d = Plot([trg2015.Get(p.name+'/EfficiencyGraph'), trg2016.Get(p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Trigger Eff.')
    d.setProp('labels', ['2015', '2016'])
    d.setProp('colors', ['red', 'blue'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'muontrgeff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'trgshiftlegx'): d.ShiftLegX(p.trgshiftlegx)
    if hasattr(p, 'trgshiftlegy'): d.ShiftLegY(p.trgshiftlegy)
    if hasattr(p, 'trgylims'): d.setProp('ylims', p.trgylims)
    d.drawROOT()
