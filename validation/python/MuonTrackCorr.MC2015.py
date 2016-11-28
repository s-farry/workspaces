from Jawa import EfficiencyClass
from ROOT import TFile, TCut, TTree, TMath

def CorrectMuonTrackingMC2015(name):
  MuonWTrackingMC2015 = EfficiencyClass("Muon"+name+"TrackingMC2015")
  MuonWTrackingMC2015.LoadFromFile()

  MuonWTrackingMC2015RW = EfficiencyClass("Muon"+name+"TrackingMC2015RW")
  MuonWTrackingMC2015RW.LoadFromFile()
  
  MuonWTrackMatchMC2015 = EfficiencyClass("Muon"+name+"TrackMatchMC2015");
  MuonWTrackMatchMC2015.LoadFromFile()
  
  MuonWTrackingMC2015Ubs = EfficiencyClass("Muon"+name+"UbsTrackingMC2015")
  MuonWTrackingMC2015Ubs.LoadFromFile()
  MuonWTrackingMC2015Bs = EfficiencyClass("Muon"+name+"BsTrackingMC2015")
  MuonWTrackingMC2015Bs.LoadFromFile()

  MuonWTrackingMC2015Bias = EfficiencyClass("Muon"+name+"TrackingMC2015Bias")
  MuonWTrackingMC2015Bias.CorrectGraphs(MuonWTrackingMC2015Ubs, MuonWTrackingMC2015Bs, "D")
  MuonWTrackingMC2015Bias.AddInvSystematic(0.20)
  #MuonWTrackingMC2015Bias.SaveToFile()

  MuonWTrackingBiasCorrMC2015 = EfficiencyClass("Muon"+name+"TrackingBiasCorrMC2015")
  MuonWTrackingBiasCorrMC2015.CorrectGraphs(MuonWTrackingMC2015, MuonWTrackingMC2015Bias, "M")
  #MuonWTrackingBiasCorrMC2015.SaveToFile()


  MuonWTrackingBiasCorrMC2015RW = EfficiencyClass("Muon"+name+"TrackingBiasCorrMC2015RW")
  MuonWTrackingBiasCorrMC2015RW.CorrectGraphs(MuonWTrackingMC2015RW, MuonWTrackingMC2015Bias, "M")

  MuonWTrackingCorrMC2015 = EfficiencyClass("Muon"+name+"TrackingCorrMC2015")
  MuonWTrackingCorrMC2015.CorrectGraphs(MuonWTrackingBiasCorrMC2015, MuonWTrackMatchMC2015,"D")
  MuonWTrackingCorrMC2015.SaveToFile()

  MuonWTrackingCorrMC2015RW = EfficiencyClass("Muon"+name+"TrackingCorrMC2015RW")
  MuonWTrackingCorrMC2015RW.CorrectGraphs(MuonWTrackingBiasCorrMC2015RW, MuonWTrackMatchMC2015,"D")
  MuonWTrackingCorrMC2015RW.SaveToFile()

CorrectMuonTrackingMC2015("")
CorrectMuonTrackingMC2015("W")
#CorrectMuonTrackingMC2015("WPT25")
#CorrectMuonTrackingMC2015("WPT30")
