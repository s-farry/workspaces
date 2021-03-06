from ROOT import *
from PlotTools import *
from Utils import Bunch
from Style import *

SetLHCbStyle()

trk2015  = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTracking2015.root")
trk2016  = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTracking2016.root")
trkRunII = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTrackingRunII.root")

id2015  = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonID2015.root")
id2016  = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonID2016.root")
idRunII = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonIDRunII.root")

trg2015  = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTrigger2015.root")
trg2016  = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTrigger2016.root")
trgRunII = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTriggerRunII.root")

idmc2016  = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonIDMC2016.root")
trgmc2016 = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTriggerMC2016.root")
trkmc2016 = TFile("/user2/sfarry/workspaces/top/tuples/efficiencies/MuonTrackingMC2016.root")

plots = [
    Bunch(name='ETA', xlabel = '#eta', trgshiftlegx=-0.4, trgshiftlegy=-0.4, idshiftlegx=-0.2, idshiftlegy=-0.5,
          trkylims = [0.88, 1.00], idylims = [0.88, 1.00]),
    Bunch(name='PT', xlabel = 'p_{T} [GeV]', trgshiftlegx = -0.4, trkshiftlegx=-0.2, trkshiftlegy=-0.5,
          idshiftlegx=-0.2, idshiftlegy=-0.5, trkylims = [0.88, 1.01]),
    #Bunch(name='P', xlabel = 'p [GeV]', trgshiftlegx = -0.4, trkshiftlegx=-0.2, trkshiftlegy=-0.5,
    #      idshiftlegx=-0.2, idshiftlegy=-0.5, trkylims = [0.88, 1.01]),
    Bunch(name='PHI', xlabel = '#phi [rad.]', idshiftlegx=-0.2, idshiftlegy=-0.5),
    Bunch(name='SPDHits', xlabel = 'SPD Hits')
]

for p in plots:
    d = Plot([trk2015.Get(p.name+'/EfficiencyGraph'), trk2016.Get(p.name+'/EfficiencyGraph'), trkmc2016.Get(p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Tracking Eff.')
    d.setProp('labels', ['2015', '2016', 'MC2016'])
    d.setProp('colors', ['black', 'blue', 'red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'muontrkeff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'trkshiftlegx'): d.ShiftLegX(p.trkshiftlegx)
    if hasattr(p, 'trkshiftlegy'): d.ShiftLegY(p.trkshiftlegy)
    if hasattr(p, 'trkylims'): d.setProp('ylims', p.trkylims)
    d.drawROOT()
    

    d = Plot([id2015.Get(p.name+'/EfficiencyGraph'), id2016.Get(p.name+'/EfficiencyGraph'), idmc2016.Get(p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'ID Eff.')
    d.setProp('labels', ['2015', '2016', 'MC2016'])
    d.setProp('colors', ['black', 'blue','red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'muonideff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'idshiftlegx'): d.ShiftLegX(p.idshiftlegx)
    if hasattr(p, 'idshiftlegy'): d.ShiftLegY(p.idshiftlegy)
    if hasattr(p, 'idylims'): d.setProp('ylims', p.idylims)
    d.drawROOT()

    d = Plot([trg2015.Get(p.name+'/EfficiencyGraph'), trg2016.Get(p.name+'/EfficiencyGraph'), trgmc2016.Get(p.name+'/EfficiencyGraph')])
    d.setProp('xlabel', p.xlabel)
    d.setProp('ylabel', 'Trigger Eff.')
    d.setProp('labels', ['2015', '2016', 'MC2016'])
    d.setProp('colors', ['black', 'blue', 'red'])
    d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
    d.setProp('filename', 'muontrgeff_'+p.name+'.pdf')
    d.setProp('markerstyles', 20)
    d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
    if hasattr(p, 'trgshiftlegx'): d.ShiftLegX(p.trgshiftlegx)
    if hasattr(p, 'trgshiftlegy'): d.ShiftLegY(p.trgshiftlegy)
    if hasattr(p, 'trgylims'): d.setProp('ylims', p.trgylims)
    d.drawROOT()


id_data = idRunII.Get("ETA_PT/EffGraph2D").Clone("pt_eta_id_weights")
id_mc   = idmc2016.Get("ETA_PT/EffGraph2D")
id_data.Divide(id_mc)
trg_data = trgRunII.Get("ETA_PT/EffGraph2D").Clone("pt_eta_trg_weights")
trg_mc   = trgmc2016.Get("ETA_PT/EffGraph2D")
trg_data.Divide(trg_mc)
trk_data = trkRunII.Get("ETA_PT/EffGraph2D").Clone("pt_eta_trk_weights")
trk_mc   = trkmc2016.Get("ETA_PT/EffGraph2D")
trk_data.Divide(trk_mc)

trk_pteta_2016   = trk2016.Get("ETA_PT/EffGraph2D").Clone("pt_eta_trk_weights_2016")
trk_pteta_mc2016 = trkmc2016.Get("ETA_PT/EffGraph2D")
trk_pteta_2016.Divide(trk_pteta_mc2016)
trk_peta_2016   = trk2016.Get("ETA_P/EffGraph2D").Clone("p_eta_trk_weights_2016")
trk_peta_mc2016 = trkmc2016.Get("ETA_P/EffGraph2D")
trk_peta_2016.Divide(trk_peta_mc2016)

d = Plot([id_data])
d.setProp('ylabel', 'p_{T} [GeV]')
d.setProp('xlabel', '#eta')
#d.setProp('colors', ['black'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'muonideffsf_etapt.pdf')
d.setProp('markerstyles', 20)
#d.setProp('leglims', [0.65, 0.6, 0.95, 0.9])
#d.ShiftLegX(-0.4)
#d.setProp('ylims', [0.5, 1.5])
d.setProp('drawOpts', 'colztexterror')
d.drawROOT()

d = Plot([trg_data])
d.setProp('ylabel', 'p_{T} [GeV]')
d.setProp('xlabel', '#eta')
#d.setProp('colors', ['black'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'muontrgeffsf_etapt.pdf')
d.setProp('markerstyles', 20)
#d.setProp('leglims', [0.65, 0.6, 0.95, 0.9])
#d.ShiftLegX(-0.4)
#d.setProp('ylims', [0.5, 1.5])
d.setProp('drawOpts', 'colztexterror')
d.drawROOT()

d = Plot([trk_data])
d.setProp('ylabel', 'p_{T} [GeV]')
d.setProp('xlabel', '#eta')
#d.setProp('colors', ['black'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'muontrkeffsf_etapt.pdf')
d.setProp('markerstyles', 20)
#d.setProp('leglims', [0.65, 0.6, 0.95, 0.9])
#d.ShiftLegX(-0.4)
#d.setProp('ylims', [0.5, 1.5])
d.setProp('drawOpts', 'colztexterror')
d.drawROOT()


d = Plot([trk_peta_2016])
d.setProp('ylabel', 'p [GeV]')
d.setProp('xlabel', '#eta')
#d.setProp('colors', ['black'])
d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
d.setProp('filename', 'muontrkeffsf_etap_2016.pdf')
d.setProp('markerstyles', 20)
#d.setProp('leglims', [0.65, 0.6, 0.95, 0.9])
#d.ShiftLegX(-0.4)
#d.setProp('ylims', [0.5, 1.5])
d.setProp('drawOpts', 'colztexterror')
d.drawROOT()

f = TFile("/user2/sfarry/workspaces/top/tuples/muon_eff_weights.root", "RECREATE")
id_data.Write()
trg_data.Write()
trk_data.Write()
f.Close()

g = TFile("/user2/sfarry/workspaces/top/tuples/trk_eff_2016_weights.root", "RECREATE")
trk_pteta_2016.Write()
trk_peta_2016.Write()
f.Close()
