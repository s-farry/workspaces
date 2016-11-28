from PlotTools import *
from ROOT import TFile, TTree, TH1F, TH2F
from Style import *

SetLHCbStyle()


muonid_2011 = TFile("/user2/sfarry/Efficiencies/python/MuonID2011.root")
muonid_2012 = TFile("/user2/sfarry/Efficiencies/python/MuonID2012.root")
muonid_2015 = TFile("/user2/sfarry/validation/tuples/MuonID2015.root")

muonid_mc2011 = TFile("/user2/sfarry/Efficiencies/python/MuonIDMC2011.root")
muonid_mc2012 = TFile("/user2/sfarry/Efficiencies/python/MuonIDMC2012.root")


muonhlt1_2011 = TFile("/user2/sfarry/Efficiencies/python/MuonHlt1Trigger2011.root")
muonhlt1_2012 = TFile("/user2/sfarry/Efficiencies/python/MuonHlt1Trigger2012.root")
muonhlt1_2015 = TFile("/user2/sfarry/validation/tuples/MuonHLT1Trigger2015.root")


muonhlt2_2011 = TFile("/user2/sfarry/Efficiencies/python/MuonHlt2Trigger2011.root")
muonhlt2_2012 = TFile("/user2/sfarry/Efficiencies/python/MuonHlt2Trigger2012.root")
muonhlt2_2015 = TFile("/user2/sfarry/validation/tuples/MuonHLT2Trigger2015.root")

muonl0_2011 = TFile("/user2/sfarry/Efficiencies/python/MuonL0Trigger2011.root")
muonl0_2012 = TFile("/user2/sfarry/Efficiencies/python/MuonL0Trigger2012.root")
muonl0_2015 = TFile("/user2/sfarry/validation/tuples/MuonL0Trigger2015.root")
muonl0spd_2015 = TFile("/user2/sfarry/validation/tuples/MuonL0SPDTrigger2015.root")
muonl0ew_2015 = TFile("/user2/sfarry/validation/tuples/MuonL0EWTrigger2015.root")

muontrg_2011 = TFile("/user2/sfarry/Efficiencies/python/MuonTrigger2011.root")
muontrg_2012 = TFile("/user2/sfarry/Efficiencies/python/MuonTrigger2012.root")
muontrg_2015 = TFile("/user2/sfarry/validation/tuples/MuonTrigger2015.root")

muonhlt1_mc2011 = TFile("/user2/sfarry/Efficiencies/python/MuonHlt1TriggerMC2011.root")
muonhlt1_mc2012 = TFile("/user2/sfarry/Efficiencies/python/MuonHlt1TriggerMC2012.root")


muontrk_2011 = TFile("/user2/sfarry/Efficiencies/python/MuonTracking2011.root")
muontrk_2012 = TFile("/user2/sfarry/Efficiencies/python/MuonTracking2012.root")
muontrk_2015 = TFile("/user2/sfarry/validation/tuples/MuonTracking2015.root")

toPlot = {'PT' : 'p_{T} [GeV]', 'ETA': '#eta', 'SPDHits' : 'SPD Hits'}

properties = {'location' : '/user2/sfarry/validation/figures/lorenzo',
              'normalised' : False}

#muon id mass
p = Plot([muonid_2011.Get('TotalHist'),
          muonid_2012.Get('TotalHist'),
          muonid_2015.Get('TotalHist')])
p.setProps(properties)
p.setProp('filename', 'id_mass_years')
p.setProp('xlabel', 'M_{#mu#mu} [GeV]')
p.setProp('ylabel', '[A.U.]')
p.setProp('normalised', True)
p.setProp('colors', None)
p.setProp('linecolors', ['red', 'blue', 'green'])
p.setProp('leglims', [0.2, 0.2, 0.5, 0.4])
p.setProp('labels', ['2011 Data (muon id t&p)', '2012 Data (muon id t&p)', '2015 Data (muon id t&p)'])
p.setProp('markerstyles', 0)
p.setProp('styles', 0)
p.setProp('drawOpts', 'hist')
p.drawROOT()

#mass
p = Plot([muontrg_2015.Get('TotalHist')])
p.setProps(properties)
p.setProp('filename', 'zmumu_mass_2015')
p.setProp('xlabel', 'M_{#mu#mu} [GeV]')
p.setProp('ylabel', '[A.U.]')
p.setProp('normalised', False)
p.setProp('colors', None)
p.setProp('linecolors', ['black'])
p.setProp('leglims', [0.2, 0.2, 0.5, 0.4])
p.setProp('labels', ['2015 Data'])
p.setProp('markerstyles', 20)
p.setProp('styles', 0)
p.setProp('drawOpts', 'e1')
p.ShiftLegY(0.4)
p.drawROOT()

for v in toPlot.keys():
    p = Plot([muonid_2011.Get(v+'/EfficiencyGraph'),
              muonid_2012.Get(v+'/EfficiencyGraph'),
              muonid_2015.Get(v+'/EfficiencyGraph')])
    if v == 'PT' :
        MeVtoGeV(p.plots[0])
        MeVtoGeV(p.plots[1])
    p.setProps(properties)
    p.setProp('filename', 'id_data_years_'+str(v))
    p.setProp('xlabel', toPlot[v])
    p.setProp('ylabel', 'ID Eff.')
    p.setProp('colors', ['red', 'blue', 'green'])
    p.setProp('ylims' , [0.85, 1.0])
    p.setProp('leglims', [0.2, 0.2, 0.5, 0.4])
    p.setProp('labels', ['2011 Data', '2012 Data', '2015 Data'])
    p.setProp('markerstyles', 20)
    p.drawROOT()

    mc = Plot([muonid_2012.Get(v+'/EfficiencyGraph'),
               muonid_mc2012.Get(v+'/EfficiencyGraph')])
    if v == 'PT' :
        MeVtoGeV(mc.plots[0])
        MeVtoGeV(mc.plots[1])
    mc.setProps(properties)
    mc.setProp('filename', 'data_v_mc_2012_'+str(v))
    mc.setProp('xlabel', toPlot[v])
    mc.setProp('ylabel', 'ID Eff.')
    mc.setProp('colors', ['black', 'red'])
    mc.setProp('ylims' , [0.85, 1.0])
    mc.setProp('leglims', [0.2, 0.2, 0.5, 0.4])
    mc.setProp('labels', ['2012 Data', 'MC2012'])
    mc.setProp('markerstyles', 20)
    mc.drawROOT()

    hlt1 = Plot([muonhlt1_2011.Get(v+'/EfficiencyGraph'),
                 muonhlt1_2012.Get(v+'/EfficiencyGraph'),
                 muonhlt1_2015.Get(v+'/EfficiencyGraph')])
    if v == 'PT' :
        MeVtoGeV(hlt1.plots[0])
        MeVtoGeV(hlt1.plots[1])
    hlt1.setProps(properties)
    hlt1.setProp('filename', 'hlt1_data_years_'+str(v))
    hlt1.setProp('xlabel', toPlot[v])
    hlt1.setProp('ylabel', 'HLT1 Trig. Eff.')
    hlt1.setProp('colors', ['red', 'blue', 'green'])
    hlt1.setProp('ylims' , [0.7, 1.0])
    hlt1.setProp('leglims', [0.2, 0.2, 0.5, 0.4])
    hlt1.setProp('labels', ['2011 Data', '2012 Data', '2015 Data'])
    hlt1.setProp('markerstyles', 20)
    hlt1.drawROOT()

    hlt2 = Plot([muonhlt2_2011.Get(v+'/EfficiencyGraph'),
                 muonhlt2_2012.Get(v+'/EfficiencyGraph'),
                 muonhlt2_2015.Get(v+'/EfficiencyGraph')])
    if v == 'PT' :
        MeVtoGeV(hlt2.plots[0])
        MeVtoGeV(hlt2.plots[1])
    hlt2.setProps(properties)
    hlt2.setProp('filename', 'hlt2_data_years_'+str(v))
    hlt2.setProp('xlabel', toPlot[v])
    hlt2.setProp('ylabel', 'HLT2 Trig. Eff.')
    hlt2.setProp('colors', ['red', 'blue', 'green'])
    hlt2.setProp('ylims' , [0.9, 1.05])
    hlt2.setProp('leglims', [0.2, 0.2, 0.5, 0.4])
    hlt2.setProp('labels', ['2011 Data', '2012 Data', '2015 Data'])
    hlt2.setProp('markerstyles', 20)
    hlt2.drawROOT()

    l0 = Plot([muonl0_2011.Get(v+'/EfficiencyGraph'),
               muonl0_2012.Get(v+'/EfficiencyGraph'),
               muonl0_2015.Get(v+'/EfficiencyGraph'),
               muonl0spd_2015.Get(v+'/EfficiencyGraph'),
               muonl0ew_2015.Get(v+'/EfficiencyGraph')])
    l0.setProps(properties)
    l0.setProp('filename', 'l0_data_years_'+str(v))
    l0.setProp('xlabel', toPlot[v])
    l0.setProp('ylabel', 'L0 Trig. Eff.')
    l0.setProp('colors', ['red', 'blue', 'green','orange', 'magenta'])
    l0.setProp('ylims' , [0.5, 1.0])
    l0.setProp('leglims', [0.2, 0.2, 0.6, 0.4])
    l0.setProp('labels', ['2011 Data', '2012 Data', '2015 Data (L0 Muon)', '2015 Data (L0 Muon w/SPD eff.)', '2015 Data(L0EW Muon)'])
    l0.setProp('markerstyles', 20)
    if v == 'PT' :
        MeVtoGeV(l0.plots[0])
    elif v == 'SPDHits':
        l0.plots = [l0.plots[0], l0.plots[1], l0.plots[3],l0.plots[4]]
        l0.setProp('labels', ['2011 Data', '2012 Data', '2015 Data (L0 Muon)', '2015 Data(L0EW Muon)'])
        l0.setProp('colors', ['red', 'blue', 'green', 'magenta'])
    l0.drawROOT()


    trg = Plot([muontrg_2011.Get(v+'/EfficiencyGraph'),
                 muontrg_2012.Get(v+'/EfficiencyGraph'),
                 muontrg_2015.Get(v+'/EfficiencyGraph')])
    if v == 'PT' :
        MeVtoGeV(trg.plots[0])
        MeVtoGeV(trg.plots[1])
    trg.setProps(properties)
    trg.setProp('filename', 'trg_data_years_'+str(v))
    trg.setProp('xlabel', toPlot[v])
    trg.setProp('ylabel', 'Trig. Eff.')
    trg.setProp('colors', ['red', 'blue', 'green'])
    trg.setProp('ylims' , [0.6, 0.85])
    trg.setProp('leglims', [0.2, 0.2, 0.5, 0.4])
    trg.setProp('labels', ['2011 Data', '2012 Data', '2015 Data'])
    trg.setProp('markerstyles', 20)
    trg.drawROOT()


    trk = Plot([muontrk_2011.Get(v+'/EfficiencyGraph'),
                 muontrk_2012.Get(v+'/EfficiencyGraph'),
                 muontrk_2015.Get(v+'/EfficiencyGraph')])
    if v == 'PT' :
        MeVtoGeV(trk.plots[0])
        MeVtoGeV(trk.plots[1])
    trk.setProps(properties)
    trk.setProp('filename', 'trk_data_years_'+str(v))
    trk.setProp('xlabel', toPlot[v])
    trk.setProp('ylabel', 'Tracking Eff.')
    trk.setProp('colors', ['red', 'blue', 'green'])
    trk.setProp('ylims' , [0.85, 1.01])
    trk.setProp('leglims', [0.2, 0.2, 0.5, 0.4])
    trk.setProp('labels', ['2011 Data', '2012 Data', '2015 Data'])
    trk.setProp('markerstyles', 20)
    trk.drawROOT()
