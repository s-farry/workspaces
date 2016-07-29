
from ROOT import *
etajf = TFile('/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/efficiencyGEC_Z_0_-etaj/efficiencyGEC.root')
dphif = TFile('/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/efficiencyGEC_Z_0_-dphi/efficiencyGEC.root')
etamf = TFile('/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/efficiencyGEC_Z_0_-etam/efficiencyGEC.root')
yzf   = TFile('/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/efficiencyGEC_Z_0_-rapz/efficiencyGEC.root')
ptjf  = TFile('/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/efficiencyGEC_Z_0_-ptj/efficiencyGEC.root')


from Jawa import *

saveTH1F('/user2/sfarry/WJet/dat/wm_gec_eff_etaj.dat', etajf.Get('hCLZ'))
saveTH1F('/user2/sfarry/WJet/dat/wp_gec_eff_etaj.dat', etajf.Get('hCLZ'))
saveTH1F('/user2/sfarry/WJet/dat/zmumu_gec_eff_etaj.dat' , etajf.Get('hCLZ'))

saveTH1F('/user2/sfarry/WJet/dat/wm_gec_eff_ptj.dat', ptjf.Get('hCLZ'))
saveTH1F('/user2/sfarry/WJet/dat/wp_gec_eff_ptj.dat', ptjf.Get('hCLZ'))
saveTH1F('/user2/sfarry/WJet/dat/zmumu_gec_eff_ptj.dat' , ptjf.Get('hCLZ'))

saveTH1F('/user2/sfarry/WJet/dat/wm_gec_eff_eta.dat', etamf.Get('hCLZ'))
saveTH1F('/user2/sfarry/WJet/dat/wp_gec_eff_eta.dat', etamf.Get('hCLZ'))
saveTH1F('/user2/sfarry/WJet/dat/zmumu_gec_eff_y.dat', yzf.Get('hCLZ'))

saveTH1F('/user2/sfarry/WJet/dat/zmumu_gec_eff_dphi.dat', dphif.Get('hCLZ'))
