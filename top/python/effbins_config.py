from ROOT import TMath

etabins = [2.0 , 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 4.0 , 4.5]
etabins11 = [2.0 , 2.125, 2.25 , 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 3.75, 4.0 , 4.25, 4.5]
etabins12 = [2.0 , 2.125, 2.25 , 2.375, 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 3.75, 4.0 , 4.25, 4.5]
etabins13 = [2.0 , 2.08, 2.165, 2.25 , 2.375, 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 3.75, 4.0 , 4.25, 4.5]
etabins14 = [2.0 , 2.08, 2.165, 2.25 , 2.33, 2.41, 2.5 , 2.75 , 3.00 , 3.25 , 3.5 , 3.75, 4.0 , 4.25, 4.5]
etabins15 = [2.0 , 2.08, 2.165, 2.25 , 2.33, 2.41, 2.5 , 2.625, 2.75 , 3.00 , 3.25 , 3.5 , 3.75, 4.0 , 4.25, 4.5]
etabins2 = [2.0 , 2.25 , 2.5 , 2.75 , 2.875, 3.00 , 3.1225, 3.25 , 3.375, 3.5 , 4.0 , 4.5]
etaref  = [2.134, 2.384, 2.634, 2.884, 3.134, 3.384, 3.634, 4.134, 4.50]
tckbins = [3500000.0, 4600000.0, 4800000.0, 5700000.0, 5900000.0, 6000000.0, 7100000.0, 7300000.0, 7400000.0,
           7500000.0, 7600000.0, 7700000.0, 7900000.0, 7929912.0, 8000000.0]

varsdict = {
    "eta"   : ["ETA"  , "<p>_ETA", 10 , 2 , 4.5 ],
    "eta5"  : ["ETA5" , "<p>_ETA", 5 , 2 , 4.5 ],
    "eta8"  : ["ETA8" , "<p>_ETA", etabins ],
    "eta11" : ["ETA11", "<p>_ETA", etabins11 ],
    "eta12" : ["ETA12", "<p>_ETA", etabins12 ],
    "eta13" : ["ETA13", "<p>_ETA", etabins13 ],
    "eta14" : ["ETA14", "<p>_ETA", etabins14 ],
    "eta15" : ["ETA15", "<p>_ETA", etabins15],
    "eta_ref" : ["ETAREF", "<p>_ETA", etaref],
    "pt"    : ["PT"   , "<p>_PT/1000.0" , 10 , 20 , 70],
    "pt5"   : ["PT5"  , "<p>_PT/1000.0" , 5 , 20 , 70],
    "p"     : ["P"    , "<p>_P"  , 8 , 100000 , 500000],
    "phi"   : ["PHI"  , "<p>_PHI", 10 , -TMath.Pi() , TMath.Pi()],
    "phi5"  : ["PHI5" , "<p>_PHI", 5 , -TMath.Pi() , TMath.Pi()],
    "velo"  : ["VeloClusters", "nVeloClusters", 8 , 0 , 4000 , "I"],
    "itclu" :  ["ITClusters", "nITClusters", 8 , 0 , 2000 , "I"],
    "pvs"   :  ["PVs", "nPVs", 6 , -0.5 , 5.5 , "I"],
    "tck"   :  ["TCK", "OdinTCK", tckbins, "I"],
    "spd"   :  ["SPDHits", "nSPDHits", 20 , 0 , 1000, "I"],
    "mass"  :  ["M", "boson_M", 60, 60000, 120000]
}


def GetVars(variables, probe):
    effs = []
    for v in variables:
        var = list(varsdict[v])
        var[1] = var[1].replace('<p>', probe)
        effs = effs + [var]
    return effs

stdvars = [ 'eta', 'eta8', 'eta13', 'pt', 'phi', 'spd' ]
trkvars = [ 'eta5', 'pt5', 'phi5' ]
trgvars = [ 'tck' ]

effvars = GetVars(stdvars, 'probe')

eff2dvars = [
    ["ETA","PHI"],
    ["ETA","PT"],
    ]

trk2dvars = [
    ["ETA_PHI", "ETA5","PHI5"],
    ["ETA_PT" , "ETA","PT"],
    ]

effvars = GetVars(stdvars + ['eta_ref'], 'probe')
pluseffvars = GetVars(stdvars + ['eta_ref'], 'muplus')
minuseffvars = GetVars(stdvars + ['eta_ref'], 'muminus')

trkeffvars = GetVars(trkvars, 'probe')
trkpluseffvars = GetVars(trkvars, 'muplus')
trkminuseffvars = GetVars(trkvars, 'muminus')

trgeffvars = GetVars(trgvars, 'probe')
trgpluseffvars = GetVars(trgvars, 'muplus')
trgminuseffvars = GetVars(trgvars, 'muminus')
