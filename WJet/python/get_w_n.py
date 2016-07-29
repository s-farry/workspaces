from ROOT import TFile, TH1F

def save_dat_file(name, var):
    f = TFile("/afs/cern.ch/work/s/simone/EW/Analysis/WJ/jobs/jobs/analysis_W_0_"+name+"-"+var+"/analysis_"+name+"_"+var+".root")
    print f.GetName()
    Ntot = f.Get("hCand")
    Nsig = f.Get("hCand_BkgW")
    g = open('/user2/sfarry/WJet/dat/'+name.replace('W','w')+'_n_'+var.replace('etam','eta')+'.dat', 'w')
    for i in range(Ntot.GetNbinsX()):
        if i > 0: g.write(" ")
        g.write(str(Ntot.GetBinContent(i+1)))
    g.write("\n")
    for i in range(Nsig.GetNbinsX()):
        if i > 0: g.write(" ")
        g.write(str(Nsig.GetBinContent(i+1)))
    g.write("\n")
    for i in range(Nsig.GetNbinsX()):
        if i > 0: g.write(" ")
        g.write(str(Nsig.GetBinContent(i+1)*0.03))
    g.write("\n")
    g.close()
    h = open('/user2/sfarry/WJet/dat/'+name.replace('W','w')+'_sel_eff_'+var.replace('etam','eta')+'.dat', 'w')
    j = open('/user2/sfarry/WJet/dat/'+name.replace('W','w')+'_sel_eff_errs'+var.replace('etam','eta')+'.dat', 'w')
    e_sel = f.Get('hESel')
    for i in range(e_sel.GetNbinsX()):
        if i > 0:
            h.write(" ")
            j.write(" ")
        h.write(str(e_sel.GetBinContent(i+1)))
        j.write(str(e_sel.GetBinContent(i+1)*0.02))
    h.close()
    j.close()

    
#save_dat_file('Wm', 'etam')
#save_dat_file('Wp', 'etam')
#save_dat_file('Wm', 'etaj')
#save_dat_file('Wp', 'etaj')
#save_dat_file('Wm', 'ptj')
#save_dat_file('Wp', 'ptj')
