from ROOT import *
from PlotTools import *
from Utils import Bunch, get_max
from Style import *

SetLHCbStyle()

files = [
    ['dx_magup_plus'   , 'dx_etaphitune_magup_plus.root'],
    ['dx_magup_minus'  , 'dx_etaphitune_magup_minus.root'],
    ['dx_magdown_plus' , 'dx_etaphitune_magdown_plus.root'],
    ['dx_magdown_minus', 'dx_etaphitune_magdown_minus.root'],
    ['dy_magup_plus'   , 'dy_etaphitune_magup_plus.root'],
    ['dy_magup_minus'  , 'dy_etaphitune_magup_minus.root'],
    ['dy_magdown_plus' , 'dy_etaphitune_magdown_plus.root'],
    ['dy_magdown_minus', 'dy_etaphitune_magdown_minus.root'],
    ['dx_plus'         , 'dx_etaphitune_plus.root'],
    ['dx_minus'        , 'dx_etaphitune_minus.root'],
    ['dy_plus'         , 'dy_etaphitune_plus.root'],
    ['dy_minus'        , 'dy_etaphitune_minus.root']
]

for f in files:
    rootf = TFile("/user2/sfarry/workspaces/top/tuples/"+f[1])
    
    data = rootf.Get('data')
    mc   = rootf.Get('mc')
    mcc  = rootf.Get('mc_corr')
    
    etaphi = rootf.Get(f[1].replace('.root','')+'_sigma_2D')
    
    for i in range(data.GetEntries()):
        for j in range(data.At(i).GetEntries()):
            d = Plot([data.At(i).At(j), mc.At(i).At(j), mcc.At(i).At(j), data.At(i).At(j)])
            for p in d.plots:
                p.UseCurrentStyle()
            
            chi2ndof_1 = d.plots[0].Chi2Test(d.plots[1],"CHI2/NDF")
            chi2ndof_2 = d.plots[0].Chi2Test(d.plots[2],"CHI2/NDF")
            
            etalo = etaphi.GetXaxis().GetBinLowEdge(i+1)
            etahi = etaphi.GetXaxis().GetBinLowEdge(i+2)
            philo = etaphi.GetYaxis().GetBinLowEdge(i+1)
            phihi = etaphi.GetYaxis().GetBinLowEdge(i+2)
            
            a = TPaveText(0.16, 0.6, 0.4, 0.9, 'NDC')
            a.SetFillStyle(0)
            a.AddText('#chi^{2}/nDoF')
            a.AddText('Data/MC : {0:.3f}'.format(chi2ndof_1))
            a.AddText('Data/MC : {0:.3f}'.format(chi2ndof_2))
            a.AddText('{0:.2f} < #eta < {1:.2f}'.format(etalo, etahi))
            a.AddText('{0:.2f} < #phi < {1:.2f}'.format(philo, phihi))
            a.SetBorderSize(0)

            d.setProp('xlabel', 'dx [mm]')
            d.setProp('ylabel', '[A.U.]')
            d.setProp('colors', ['black','red','blue', 'black'])
            d.setProp('location', '/user2/sfarry/workspaces/top/figures/')
            d.setProp('filename', f[0]+'_'+str(i)+'_'+str(j)+'.pdf')
            d.setProp('markerstyles', [20,0,0,0])
            d.setProp('fillstyles', [0,0,0,0])
            d.setProp('normalised', True)
            d.setProp('drawOpts', ['p1','h','h', 'p'])
            d.setProp('labels', ['2016 Data', 'MC2016', 'MC2016 Tuned'])
            d.setProp('leglims', [0.65, 0.7, 0.9, 0.9])
            d.setProp('ynormlims', [0, get_max(d.plots, norm = True)*1.1])
            d.setProp('extraObjs', [a])
            d.drawROOT()
