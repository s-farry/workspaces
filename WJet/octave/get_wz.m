1;

function B = seperate_stat_wz(wp, wm, z)
  B = [
       wp(1:columns(wp),:),                   zeros(columns(wp), columns(wm) + columns(z));
       zeros(columns(wm)  , columns(wp))    , wm(1:columns(wm),:) , zeros(columns(wm), columns(z));
       zeros(columns(z)   , columns(wp) + columns(wm)), z(1:columns(z),:);
       wp(columns(wp)+1:end,:), wm(columns(wm)+1:end,:), zeros(rows(wm) - columns(wm),columns(z));
       zeros(rows(z) - columns(z), columns(wp) + columns(wm)), z(columns(z)+1:end,:)];
endfunction
function B = seperate_stat_corr(wp, wm, z)
  B = [
       wp(1:columns(wp),:),                   zeros(columns(wp), columns(wm) + columns(z));
       zeros(columns(wm)  , columns(wp))    , wm(1:columns(wm),:) , zeros(columns(wm), columns(z));
       zeros(columns(z)   , columns(wp) + columns(z)), z(1:columns(z),:);
       wp(columns(wp)+1:end,:), wm(columns(wm)+1:end,:), z(columns(z)+1:end,:)];
endfunction

function B = seperate_stat(wp, wm)
  B = [
       wp(1:columns(wp),:)                  , zeros(columns(wp), columns(wm));
       zeros(columns(wm)  , columns(wp))    , wm(1:columns(wm),:);
       wp(columns(wp)+1:end,:), wm(columns(wm)+1:end,:)];
endfunction

function B = corr_errs(A)
   B = zeros(columns(A));
   for i = 1 : columns(A)
       for j = 1 : i
           B(i, j) = sum(A(:,i).*A(:,j))/sqrt(sumsq(A(:,i))*sumsq(A(:,j)));
	   if (i != j)
	       B(j, i) = B(i, j);
	   endif
       endfor
   endfor
endfunction

function B = cov_errs(A)
   B = zeros(columns(A));
   for i = 1 : columns(A)
       for j = 1 : i
           B(i, j) = sum(A(:,i).*A(:,j));
	   if (i != j)
	       B(j, i) = B(i, j);
	   endif
       endfor
   endfor
endfunction

function printEffErr(A, B)
	 for i = 1 : columns(A)
	     fprintf("%2.3f +/- %2.3f \n", A(1, i), B(1,i))
	 endfor
endfunction

function printTGraph(A, B)
	 for i = 1 : columns(A)
	     fprintf("%2.5f  %2.5f \n", A(1, i), B(1,i))
	 endfor
endfunction

function print_jec_errs(v, bins, label, title1)
	fprintf("\\begin{tabular}{c c} \n")
	fprintf("%s & %s & %s \\\\ \n", label, title1)
	fprintf("\\hline \n")
	 for i = 1 : columns(v.xsec)
	     fprintf("%2.1f -- %2.1f & %2.2f \\\\ \n",
		     bins(i), bins(i+1), sqrt(sumsq(v.jec_errs(:,i)))*100)
	 endfor
	 fprintf("\\end{tabular} \n")
endfunction

function print_jec_errs_2(v, v2, v3, bins, label, title1, title2, title3)
	fprintf("\\begin{tabular}{c c c c} \n")
		   fprintf("%s & %s & %s & %s &s \\\\ \n", label, title1, title2, title3)
	fprintf("\\hline \n")
	for i = 1 : columns(v.xsec)
	     fprintf("%2.1f -- %2.1f & %2.2f & %2.2f & %2.2f \\\\ \n",
		     bins(i), bins(i+1), sqrt(sumsq(v.jec_errs(:,i)))*100, sqrt(sumsq(v2.jec_errs(:,i)))*100, sqrt(sumsq(v3.jec_errs(:,i)))*100)
	 endfor
	 fprintf("\\end{tabular} \n")
endfunction

function print_ratio_results(wp, wm, z, wz)
  fprintf("cswp_data = [%2.2f, %2.2f, %2.2f, %2.2f]\n",wp.totxsec,wp.totxsec_staterr, wp.totxsec_systerr, wp.totxsec_lumierr)
  fprintf("cswm_data = [%2.2f, %2.2f, %2.2f, %2.2f]\n",wm.totxsec,wm.totxsec_staterr, wm.totxsec_systerr, wm.totxsec_lumierr)
  fprintf("csz_data  = [%2.2f, %2.2f, %2.2f, %2.2f]\n",z.totxsec,z.totxsec_staterr, z.totxsec_systerr, z.totxsec_lumierr)
  fprintf("rwz_data  = [%2.2f, %2.2f, %2.2f, %2.2f]\n",wz.rwz,wz.rwz_stat_err, wz.rwz_syst_err,0.0)
  fprintf("rwpz_data = [%2.2f, %2.2f, %2.2f, %2.2f]\n",wz.rwpz,wz.rwpz_stat_err, wz.rwpz_syst_err,0.0)
  fprintf("rwmz_data = [%2.2f, %2.2f, %2.2f, %2.2f]\n",wz.rwmz,wz.rwmz_stat_err, wz.rwmz_syst_err,0.0)
  fprintf("rwpm_data = [%2.2f, %2.2f, %2.2f, %2.2f]\n",wz.rwpm,wz.rwpm_stat_err, wz.rwpm_syst_err,0.0)
  fprintf("awpm_data = [%2.3f, %2.3f, %2.3f, %2.3f]\n",wz.aw,wz.aw_stat_err, wz.aw_syst_err,0.0)
endfunction

function printXsec(v, v2, bins, label, title1, title2)
	fprintf("\\begin{tabular}{c c c} \n")
	fprintf("%s & %s & %s \\\\ \n", label, title1, title2)
	fprintf("\\hline \n")
	for i = 1 : columns(v.xsec)
	     fprintf("%2.1f -- %2.1f & %2.2f $\\pm$  %2.2f  $\\pm$ %2.2f $\\pm$ %2.2f & %2.2f $\\pm$  %2.2f  $\\pm$ %2.2f $\\pm$ %2.2f \\\\ \n",
		     bins(i), bins(i+1), v.xsec(i), v.stat_err(i)*v.xsec(i), v.syst_err(i)*v.xsec(i), v.lumi_err(i)*v.xsec(i), v2.xsec(i), v2.stat_err(i)*v2.xsec(i), v2.syst_err(i)*v2.xsec(i), v2.lumi_err(i)*v2.xsec(i) )
	 endfor
	 fprintf("\\end{tabular} \n")
endfunction



function printCorr(v)
	fprintf("\\begin{bmatrix}\n")
	for j = 1 : columns(v)
		  for i = 1 : rows(v)
			    fprintf("%2.3f &", v(i, j))
		  endfor
		  fprintf("\\\\ \n")
	 endfor
	 fprintf("\\end{bmatrix} \n")
endfunction
		  
function printZXsec(v, bins, label, title1)
	fprintf("\\begin{tabular}{c c } \n")
	fprintf("%s & %s \\\\ \n", label, title1)
	fprintf("\\hline \n")
	for i = 1 : columns(v.xsec)
	     fprintf("%2.1f -- %2.1f & %2.2f $\\pm$  %2.2f  $\\pm$ %2.2f $\\pm$ %2.2f \\\\ \n",
		     bins(i), bins(i+1), v.xsec(i), v.stat_err(i)*v.xsec(i), v.syst_err(i)*v.xsec(i), v.lumi_err(i)*v.xsec(i) )
	 endfor
	 fprintf("\\end{tabular} \n")
endfunction

function printTotXsec(v, title)
		  fprintf("%2.2f \\pm  %2.2f  \\pm %2.2f  \\pm %2.2f \n", v.totxsec, v.totxsec_staterr, v.totxsec_systerr, v.totxsec_lumierr)
endfunction

function printRatios(v)
		  fprintf("\\begin{eqnarray*}\n")
		  fprintf("A_{W^{\\pm}} &=& %2.3f \\pm  %2.3f  \\pm %2.3f \\\\ \n", v.aw, v.aw_stat_err, v.aw_syst_err )
		  fprintf("R_{WZ} &=& %2.2f \\pm  %2.2f  \\pm %2.2f \\\\ \n", v.rwz, v.rwz_stat_err, v.rwz_syst_err )
		  fprintf("R_{W^{+}Z} &=& %2.2f \\pm  %2.2f  \\pm %2.2f \\\\ \n", v.rwpz, v.rwpz_stat_err, v.rwpz_syst_err )
		  fprintf("R_{W^{-}Z} &=& %2.2f \\pm  %2.2f  \\pm %2.2f \\\\ \n", v.rwmz, v.rwmz_stat_err, v.rwmz_syst_err )
		  fprintf("R_{W^{\\pm}} &=& %2.2f \\pm  %2.2f  \\pm %2.2f \\\\ \n", v.rwpm, v.rwpm_stat_err, v.rwpm_syst_err )
		  fprintf("\\end{eqnarray*}\n")
endfunction

function printTotSystematics(v1, v2, v3, r, title1, title2,title3, title4, title5)
	fprintf("\\begin{tabular}{c c c c } \n")
	fprintf("Source & %s & %s & %s & %s & %s \\\\ \n", title1, title2, title3, title4, title5)
	fprintf("\\hline \n")
	fprintf("Statistical & %1.1f & %1.1f & %1.1f  & %1.1f & %1.1f \\\\ \n", v1.totxsec_staterr*100/v1.totxsec , v2.totxsec_staterr*100/v2.totxsec, v3.totxsec_staterr*100/v3.totxsec, r.rwz_stat_err*100/r.rwz, r.rwpm_stat_err*100/r.rwpm)
	fprintf("\\hline \n")
	fprintf("Muon reconstruction & %1.1f & %1.1f & %1.1f  & %1.1f & %1.1f \\\\ \n", v1.totxsec_muonrec_eff_err*100/v1.totxsec , v2.totxsec_muonrec_eff_err*100/v2.totxsec, v3.totxsec_muonrec_eff_err*100/v3.totxsec, r.rwz_muonrec_err*100/r.rwz, r.rwpm_muonrec_err*100/r.rwpm)
	fprintf("Jet reconstruction & %1.1f & %1.1f & %1.1f & %1.1f & %1.1f  \\\\ \n"   ,
		v1.totxsec_jetrec_eff_err*100/v1.totxsec , v2.totxsec_jetrec_eff_err*100/v2.totxsec, v3.totxsec_jetrec_eff_err*100/v3.totxsec,
		r.rwz_jetrec_err*100/r.rwz, r.rwpm_jetrec_err*100/r.rwpm)
	fprintf("Selection & %1.1f & %1.1f & %1.1f & %1.1f & %1.1f  \\\\ \n"   ,
		v1.totxsec_sel_eff_err*100/v1.totxsec , v2.totxsec_sel_eff_err*100/v2.totxsec, v3.totxsec_sel_eff_err*100/v3.totxsec,
		r.rwz_sel_eff_err*100/r.rwz, r.rwpm_sel_eff_err*100/r.rwpm)
	fprintf("GEC. & %1.1f & %1.1f & %1.1f & %1.1f & %1.1f  \\\\ \n"    ,
		v1.totxsec_gec_eff_err*100/v1.totxsec , v2.totxsec_gec_eff_err*100/v2.totxsec, v3.totxsec_gec_eff_err*100/v3.totxsec,
		r.rwz_gec_eff_err*100/r.rwz, r.rwpm_gec_eff_err*100/r.rwpm)
	fprintf("Purity & %1.1f & %1.1f & %1.1f & %1.1f & %1.1f  \\\\ \n"      ,
		v1.totxsec_rho_err*100/v1.totxsec , v2.totxsec_rho_err*100/v2.totxsec, v3.totxsec_rho_err*100/v3.totxsec,
		r.rwz_rho_err*100/r.rwz, r.rwpm_rho_err*100/r.rwpm)
	fprintf("Acceptance & %1.1f & %1.1f & %1.1f & %1.1f & %1.1f  \\\\ \n"  ,
		v1.totxsec_A_err*100/v1.totxsec , v2.totxsec_A_err*100/v2.totxsec, v3.totxsec_A_err*100/v3.totxsec,
		r.rwz_A_err*100/r.rwz, r.rwpm_A_err*100/r.rwpm)
	fprintf("Unfolding & %1.1f & %1.1f & %1.1f & %1.1f & %1.1f  \\\\ \n"   ,
		v1.totxsec_U_err*100/v1.totxsec , v2.totxsec_U_err*100/v2.totxsec, v3.totxsec_U_err*100/v3.totxsec,
		r.rwz_U_err*100/r.rwz, r.rwpm_U_err*100/r.rwpm)
	fprintf("JEC   & %1.1f & %1.1f & %1.1f & %1.1f & %1.1f  \\\\ \n"         ,
		v1.totxsec_jec_err*100/v1.totxsec , v2.totxsec_jec_err*100/v2.totxsec, v3.totxsec_jec_err*100/v3.totxsec,
		r.rwz_jec_err*100/r.rwz, r.rwpm_jec_err*100/r.rwpm)
	fprintf("\\hline \n ")
	fprintf("Systematic & %1.1f & %1.1f & %1.1f & %1.1f & %1.1f  \\\\ \n"         ,
		v1.totxsec_systerr*100/v1.totxsec , v2.totxsec_systerr*100/v2.totxsec, v3.totxsec_systerr*100/v3.totxsec,
		r.rwz_syst_err*100/r.rwz, r.rwpm_syst_err*100/r.rwpm )
	fprintf("\\hline \n")
	fprintf("Luminosity & %1.1f & %1.1f & %1.1f & - & -  \\\\ \n"         ,
		v1.totxsec_lumierr*100/v1.totxsec , v2.totxsec_lumierr*100/v2.totxsec, v3.totxsec_lumierr*100/v3.totxsec )
	 fprintf("\\end{tabular} \n")
endfunction

function printRatioSystematics(v, title1)
	fprintf("\\begin{tabular}{c c c c c c} \n")
	fprintf("Source & \\rwpz & \\rwmz \\ rwpm")
	fprintf("Muon reconstruction & %1.1f & %1.1f & %1.1f \\\\ \n"   ,
		v1.totxsec_muonrec_eff_err*100/v1.totxsec , v2.totxsec_muonrec_eff_err*100/v2.totxsec, v3.totxsec_muonrec_eff_err*100/v3.totxsec)
	fprintf("Jet reconstruction & %1.1f & %1.1f & %1.1f \\\\ \n"   ,
		v1.totxsec_jetrec_eff_err*100/v1.totxsec , v2.totxsec_jetrec_eff_err*100/v2.totxsec, v3.totxsec_jetrec_eff_err*100/v3.totxsec)
	fprintf("Selection & %1.1f & %1.1f & %1.1f \\\\ \n"   ,
		v1.totxsec_sel_eff_err*100/v1.totxsec , v2.totxsec_sel_eff_err*100/v2.totxsec, v3.totxsec_sel_eff_err*100/v3.totxsec)
	fprintf("GEC. & %1.1f & %1.1f & %1.1f \\\\ \n"    ,
		v1.totxsec_gec_eff_err*100/v1.totxsec , v2.totxsec_gec_eff_err*100/v2.totxsec, v3.totxsec_gec_eff_err*100/v3.totxsec)
	fprintf("Purity & %1.1f & %1.1f & %1.1f \\\\ \n"      ,
		v1.totxsec_rho_err*100/v1.totxsec , v2.totxsec_rho_err*100/v2.totxsec, v3.totxsec_rho_err*100/v3.totxsec)
	fprintf("Acceptance & %1.1f & %1.1f & %1.1f \\\\ \n"  ,
		v1.totxsec_A_err*100/v1.totxsec , v2.totxsec_A_err*100/v2.totxsec, v3.totxsec_A_err*100/v3.totxsec)
	fprintf("Unfolding & %1.1f & %1.1f & %1.1f \\\\ \n"   ,
		v1.totxsec_U_err*100/v1.totxsec , v2.totxsec_U_err*100/v2.totxsec, v3.totxsec_U_err*100/v3.totxsec)
	fprintf("JEC   & %1.1f & %1.1f & %1.1f \\\\ \n"         ,
		v1.totxsec_jec_err*100/v1.totxsec , v2.totxsec_jec_err*100/v2.totxsec, v3.totxsec_jec_err*100/v3.totxsec)
	fprintf("Total & %1.1f & %1.1f & %1.1f \\\\ \n"         ,
		v1.totxsec_systerr*100/v1.totxsec , v2.totxsec_systerr*100/v2.totxsec, v3.totxsec_systerr*100/v3.totxsec )
	fprintf("\\hline \n")
	 fprintf("\\end{tabular} \n")
endfunction

function v = variable(a, b, L, Lerr);
	 v.type = a;
	 v.var  = b;
         v.N            = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a, '_n_', b, '.dat'));
         v.purity       = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a,'_purity_',b,'.dat'));
         v.ewk_fraction = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a,'_ewkfraction_',b,'.dat'));
         v.fake_rate    = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a,'_fakerate_',b,'.dat'));
         v.acc = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a,'_nlo_acc_',b,'.dat'));
	 #some extra modelling related uncertainties
         v.acc_model_errs = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a,'_nlo_acc_errs_',b,'.dat'));
         v.unf = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a,'_unf_',b,'.dat'));
         v.unf_model_errs = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a,'_unf_errs_',b,'.dat'));
	 v.A = v.acc(1,:);
	 v.U = v.unf(1,:);
         v.A_errs = [diag(v.acc(2,:)./v.acc(1,:)); v.acc_model_errs];
         v.U_errs = [diag(v.unf(2,:)./v.unf(1,:)); v.unf_model_errs];
         v.rho = v.purity(1,:).*(1 - v.ewk_fraction(1,:)).*(1-v.fake_rate(1,:));
         # get relative uncertainty on purity - qcd purity, simply divide, ewkfraction more effort
         v.rho_errs = [v.purity(2:end,:)./v.purity(1,:); 
			(diag(v.ewk_fraction(2,:)))./(1 -v.ewk_fraction(1,:)) ; 
		       diag(max(v.fake_rate(2:3,:))./(1-v.fake_rate(1,:)));
		       v.fake_rate(4,:)./(1-v.fake_rate(1,:))];
         # v.rho_errs = v.purity(2:end,:)./v.rho;
         v.Nsig = v.N.*v.rho;
	 # get efficienciesq
         v.gec = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/gec_eff_',b,'.dat'));
         v.sel = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a,'_sel_eff_',b,'.dat'));
         v.jet = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a, '_jet_eff_',b,'.dat') );
         v.trg_eff = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/', a, '_trg_eff_',b,'.dat') );
         v.trk_eff = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a, '_trk_eff_',b,'.dat') );
         v.id_eff  = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a, '_id_eff_',b,'.dat') );
         v.jet = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/',a, '_jet_eff_',b,'.dat') );
         v.jet_eff = v.jet(1,:);
         v.sel_eff = v.sel(1,:);
	 v.gec_eff = v.gec(1,:);
	 v.muonrec_eff = prod([v.trg_eff; v.trk_eff; v.id_eff]);
	 v.rec_eff = prod([v.trg_eff; v.trk_eff; v.id_eff; v.jet_eff]);
	 v.tot_eff = prod([v.trg_eff; v.trk_eff; v.id_eff; v.jet_eff; v.gec_eff; v.sel_eff]);
	 # get rel. error on efficiencies - list of values
	 v.trg_eff_errs = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/', a, '_trg_', b, '_matrix.dat' ));
	 v.trk_eff_errs = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/', a, '_trk_', b, '_matrix.dat' ));
	 v.id_eff_errs  = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/', a, '_id_', b, '_matrix.dat' ));
         v.jet_eff_errs = diag(max(v.jet([2,3],:))./v.jet(1,:));
         v.jec_errs     = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/', a, '_jec_errs_', b, '.dat' ));
         v.gec_eff_xtraerrs = dlmread(strcat('/user2/sfarry/workspaces/WJet/dat/', a, '_gec_efferrs_', b, '.dat' ));
	 # for the moment, ignoring the jec err from tuple
         # needs to be discussed if this should be included
         #v.jec_errs     = [diag(v.jec_errs(1,:)); v.jec_errs([3,4],:)];
         #remove statistical
         v.jec_errs     = [v.jec_errs([3,4],:)];
         v.gec_eff_errs = [diag(v.gec(2,:)./v.gec(1,:)); v.gec_eff_xtraerrs];
         v.sel_eff_errs = v.sel(2,:)./v.sel(1,:);
         v.muonrec_eff_errs = [v.trg_eff_errs;
			       v.trk_eff_errs;
			       v.id_eff_errs;
			       ];
	 v.jetrec_eff_errs = [
			      v.jet_eff_errs;
			      0.019 * ones(size(v.Nsig));
			      ];
	 
	 v.tot_eff_errs = [
			   v.muonrec_eff_errs;
			   v.jetrec_eff_errs;
			   v.sel_eff_errs;
			   v.gec_eff_errs;
			   ];
	 
	v.tot_syst_errs = [
			   v.muonrec_eff_errs;
			   v.jetrec_eff_errs;
			   v.sel_eff_errs;
			   v.gec_eff_errs;
			   v.rho_errs;
			   #v.A_errs(columns(v.N)+1,:);
			   v.A_errs;
			   v.U_errs;
			   v.jec_errs;
			   ];
	v.tot_syst_errs_nounf = [
			   v.muonrec_eff_errs;
			   v.jetrec_eff_errs;
			   v.sel_eff_errs;
			   v.gec_eff_errs;
			   v.rho_errs;
			    v.A_errs;
			    v.U_errs(1,:);
			   v.jec_errs;
			   ];

        v.muonrec_eff_err = sqrt(sumsq(v.muonrec_eff_errs));
	v.jetrec_eff_err  = sqrt(sumsq(v.jetrec_eff_errs));
	v.tot_eff_err     = sqrt(sumsq(v.tot_eff_errs));
        v.purity_err      = sqrt(sumsq(v.rho_errs));
	# as errors are in percentage, we need to multiply by xsecs to
	# get actual covariance matrix
        v.stat_err        = 1./sqrt(v.Nsig);
        v.syst_err        = sqrt(sumsq([v.tot_syst_errs]));
        v.lumi_err        = ones(size(v.Nsig))*(Lerr/L);
        v.tot_err         = sqrt(sumsq([v.syst_err;v.stat_err;v.lumi_err]));
        v.xsec            = v.Nsig.*v.A.*v.U./(v.tot_eff*L);
	v.cov             = diag(v.xsec) * cov_errs(v.tot_syst_errs) * diag(v.xsec);
	v.cov_nounf       = diag(v.xsec) * cov_errs(v.tot_syst_errs_nounf) * diag(v.xsec);
        v.corr            = corr_errs(v.tot_syst_errs);
	
        v.totxsec         = sum(v.xsec);
        v.totxsec_staterr = v.totxsec./sqrt(sum(v.Nsig));
        v.totxsec_lumierr = (Lerr/L)*v.totxsec;
        # note jacobian is just identity matrix for sum
	v.jac = ones(size(v.xsec));
	v.totxsec_systerr         = sqrt((v.jac) * v.cov_nounf * (v.jac'));
        v.totxsec_muonrec_eff_err = sqrt((v.jac) * diag(v.xsec) * cov_errs(v.muonrec_eff_errs) * diag(v.xsec) * (v.jac'));
        v.totxsec_jetrec_eff_err  = sqrt((v.jac) * diag(v.xsec) * cov_errs(v.jetrec_eff_errs)  * diag(v.xsec)  * (v.jac'));
        v.totxsec_sel_eff_err     = sqrt((v.jac) * diag(v.xsec) * cov_errs(v.sel_eff_errs) * diag(v.xsec) * (v.jac'));
        v.totxsec_gec_eff_err     = sqrt((v.jac) * diag(v.xsec) * cov_errs(v.gec_eff_errs) * diag(v.xsec) * (v.jac'));
        v.totxsec_rho_err         = sqrt((v.jac) * diag(v.xsec) * cov_errs(v.rho_errs) * diag(v.xsec) * (v.jac'));
        v.totxsec_A_err           = sqrt((v.jac) * diag(v.xsec) * cov_errs(v.A_errs) * diag(v.xsec) * (v.jac'));
        v.totxsec_U_err           = sqrt((v.jac) * diag(v.xsec) * cov_errs(v.U_errs(columns(v.xsec)+1,:)) * diag(v.xsec) * (v.jac'));
        v.totxsec_jec_err         = sqrt((v.jac) * diag(v.xsec) * cov_errs(v.jec_errs) * diag(v.xsec) * (v.jac'));
        # v.totxsec_toterr = norm([v.totxsec_staterr, v.totxsec_systerr])
endfunction

function v = asymm(v1, v2);
       v.var = v1.var;
       v.xsecs = [v1.xsec , v2.xsec];
       v.syst_errs = [
		      v1.muonrec_eff_errs, v2.muonrec_eff_errs;
		      v1.jetrec_eff_errs , v2.jetrec_eff_errs ;
		      v1.sel_eff_errs    , zeros(1, columns(v2.xsec));
		      zeros(1, columns(v1.xsec)), v2.sel_eff_errs;
		      v1.gec_eff_errs, v2.gec_eff_errs ;
		      v1.jec_errs, v2.jec_errs ;
		      seperate_stat(v1.rho_errs, v2.rho_errs);
		      seperate_stat(v1.A_errs, v2.A_errs);
		      seperate_stat(v1.U_errs, v2.U_errs);
		      ];
       v.stat_errs = diag([v1.stat_err, v2.stat_err]);
       v.xsecs_stat_cov   = diag(v.xsecs)*cov_errs(v.stat_errs)*diag(v.xsecs);
       #v.xsecs_stat_cov  = cov_errs(v.stat_errs)*diag(v.xsecs.^2);
       v.xsecs_stat_corr  = corr_errs(v.stat_errs);
       #v.xsecs_syst_cov  = cov_errs(v.syst_errs)*diag(v.xsecs.^2);
       v.xsecs_syst_cov   = diag(v.xsecs)*cov_errs(v.syst_errs)*diag(v.xsecs);
       #v.xsecs_rho_cov   = diag(v.xsecs)*cov_errs(seperate_stat(v1.rho_errs, v2.rho_errs))*diag(v.xsecs);
       uncorrelated = [v1.rho_errs, zeros(size(v1.rho_errs)); zeros(size(v2.rho_errs)), v2.rho_errs]
       v.xsecs_rho_cov    = diag(v.xsecs)*cov_errs(uncorrelated)*diag(v.xsecs);



       v.xsecs_syst_corr = corr_errs(v.syst_errs);
       v.atot = (v1.totxsec - v2.totxsec) / (v1.totxsec + v2.totxsec);
       v.rtot = v1.totxsec / v2.totxsec;
       v.a = (v1.xsec - v2.xsec) ./ (v1.xsec + v2.xsec);
       v.r = v1.xsec ./ v2.xsec;
				#v.a_syst_err = zeros(size(v.a));
				#v.r_stat_err = zeros(size(v.a));
				#v.a_stat_err = zeros(size(v.a));
				#v.r_stat_err = zeros(size(v.a));
       v.jac_a = zeros(columns(v.a), columns(v.xsecs_stat_cov));
       v.jac_r = zeros(columns(v.a), columns(v.xsecs_stat_cov));
				#fill jacobian with derivatives
       for i = 1:rows(v.jac_a)
          v.jac_a(i,i) = 2*v.xsecs(i+rows(v.jac_r))/((v.xsecs(i) + v.xsecs(i+rows(v.jac_a)))^2);
          v.jac_a(i,i+rows(v.jac_a)) = -2*v.xsecs(i)/((v.xsecs(i) + v.xsecs(i+rows(v.jac_a)))^2);
          v.jac_r(i,i) =  1/v.xsecs(i+rows(v.jac_r));
          v.jac_r(i,i+rows(v.jac_r)) = -v.xsecs(i)/(v.xsecs(i+rows(v.jac_r))^2);
     endfor
     
     v.stat_cov_a = (v.jac_a*v.xsecs_stat_cov*(v.jac_a'));
     v.stat_cov_r = (v.jac_r*v.xsecs_stat_cov*(v.jac_r'));
     v.syst_cov_a = (v.jac_a*v.xsecs_syst_cov*(v.jac_a'));
     v.syst_cov_r = (v.jac_r*v.xsecs_syst_cov*(v.jac_r'));
     v.rho_cov_a = (v.jac_a*v.xsecs_rho_cov*(v.jac_a'));
     v.rho_cov_r = (v.jac_r*v.xsecs_rho_cov*(v.jac_r'));

     v.a_syst_err = sqrt(abs(diag(v.syst_cov_a)));
     v.r_syst_err = sqrt(abs(diag(v.syst_cov_r)));
     v.a_rho_err = sqrt(abs(diag(v.rho_cov_a)));
     v.r_rho_err = sqrt(abs(diag(v.rho_cov_r)));
     v.a_stat_err = sqrt(abs(diag(v.stat_cov_a)));
     v.r_stat_err = sqrt(abs(diag(v.stat_cov_r)));
     v.a_tot_err = sqrt(v.a_syst_err.^2 + v.a_stat_err.^2);
     v.r_tot_err = sqrt(v.r_syst_err.^2 + v.r_stat_err.^2);
endfunction

function v = wzratio(wp, wm, z);
  v.xsecs = [wp.xsec , wm.xsec, z.xsec];
  v.syst_errs = [
		 wp.muonrec_eff_errs, wm.muonrec_eff_errs  , z.muonrec_eff_errs;
		 wp.jetrec_eff_errs , wm.jetrec_eff_errs   , z.jetrec_eff_errs;
		 wp.sel_eff_errs    , zeros(size(wm.xsec)) , zeros(size(z.xsec));
		 zeros(size(wp.xsec)), wm.sel_eff_errs, zeros(size(z.xsec));
		 wp.gec_eff_errs, wm.gec_eff_errs, z.gec_eff_errs;
		 wp.jec_errs, wm.jec_errs, z.jec_errs;
		 seperate_stat(wp.rho_errs, wm.rho_errs) , zeros(rows(wp.rho_errs) + columns(wm.rho_errs), columns(z.rho_errs));
		 zeros(rows(z.rho_errs), columns(wp.rho_errs) + columns(wm.rho_errs)), z.rho_errs;
		 seperate_stat_wz(wp.A_errs(1:columns(wp.xsec)+1,:), wm.A_errs(1:columns(wm.xsec)+1,:), z.A_errs(1:columns(z.xsec)+1,:));
		 seperate_stat_corr(wp.U_errs, wm.U_errs, z.U_errs)
		 ];

  v.stat_errs          = diag([wp.stat_err, wm.stat_err, z.stat_err]);
  v.xsecs_stat_cov     = diag(v.xsecs)*cov_errs(v.stat_errs)*diag(v.xsecs);
  v.xsecs_stat_corr    = corr_errs(v.stat_errs);
  v.xsecs_syst_cov     = diag(v.xsecs)*cov_errs(v.syst_errs)*diag(v.xsecs);
  v.xsecs_muonrec_cov  = diag(v.xsecs)*cov_errs([wp.muonrec_eff_errs , wm.muonrec_eff_errs, z.muonrec_eff_errs])*diag(v.xsecs);
  v.xsecs_jetrec_cov   = diag(v.xsecs)*cov_errs([wp.jetrec_eff_errs  , wm.jetrec_eff_errs, z.jetrec_eff_errs])*diag(v.xsecs);
  v.xsecs_sel_eff_cov  = diag(v.xsecs)*cov_errs([wp.sel_eff_errs, wm.sel_eff_errs, z.sel_eff_errs])*diag(v.xsecs);
  v.xsecs_gec_eff_cov  = diag(v.xsecs)*cov_errs([wp.gec_eff_errs, wm.gec_eff_errs, z.gec_eff_errs])*diag(v.xsecs);
				#rho is more complicated
  v.rho_errs = [ seperate_stat(wp.rho_errs, wm.rho_errs) , zeros(rows(wp.rho_errs) + columns(wm.rho_errs), columns(z.rho_errs));
		 zeros(rows(z.rho_errs), columns(wp.rho_errs) + columns(wm.rho_errs)), z.rho_errs;];
  v.xsecs_rho_cov   = diag(v.xsecs)*cov_errs(v.rho_errs)*diag(v.xsecs);
  v.xsecs_A_cov     = diag(v.xsecs)*cov_errs([wp.A_errs, wm.A_errs, z.A_errs])*diag(v.xsecs);
  v.xsecs_U_cov     = diag(v.xsecs)*cov_errs([wp.U_errs, wm.U_errs, z.U_errs])*diag(v.xsecs);
  v.xsecs_jec_cov   = diag(v.xsecs)*cov_errs([wp.jec_errs, wm.jec_errs, z.jec_errs])*diag(v.xsecs);
  v.xsecs_syst_corr = corr_errs(v.syst_errs);
				#calculate derived quantities
  v.aw  = (wp.totxsec - wm.totxsec) / (wp.totxsec + wm.totxsec);
  v.rwz  = (wp.totxsec + wm.totxsec) / (z.totxsec);
  v.rwpz = wp.totxsec/z.totxsec;
  v.rwmz = wm.totxsec/z.totxsec;
  v.rwpm = wp.totxsec/wm.totxsec;
				#define jacobians for each derived quantity
  v.jac_aw = zeros(size(v.xsecs));
  v.jac_wz = zeros(size(v.xsecs));
  v.jac_wpz = zeros(size(v.xsecs));
  v.jac_wmz = zeros(size(v.xsecs));
  v.jac_wpm = zeros(size(v.xsecs));
				#fill jacobian with derivatives
  for i = 1:columns(v.jac_wz)
				#differential w.r.t wp
    if (i <= size(wp.xsec)(2) )
      v.jac_aw(i) = 2*(wm.totxsec)/((wp.totxsec + wm.totxsec)^2);
      v.jac_wz(i) = v.rwz/(wp.totxsec + wm.totxsec);
      v.jac_wpz(i) = v.rwpz/(wp.totxsec);
      v.jac_wpm(i) = v.rwpm/(wp.totxsec);
				#differential w.r.t wm
    elseif (i <= size(wp.xsec)(2) + size(wm.xsec)(2))
      v.jac_aw(i)  = -2*(wp.totxsec)/((wp.totxsec + wm.totxsec)^2);
      v.jac_wz(i)  = v.rwz/(wp.totxsec + wm.totxsec);
      v.jac_wmz(i) = v.rwmz/(wm.totxsec);
      v.jac_wpm(i) = -v.rwpm/(wm.totxsec);
				#differential w.r.t z
    else
      v.jac_wz(i)  = -v.rwz/z.totxsec;
      v.jac_wpz(i) = -v.rwpz/z.totxsec;
      v.jac_wmz(i) = -v.rwmz/z.totxsec;
    endif
  endfor
  v.aw_stat_err   = sqrt(v.jac_aw*v.xsecs_stat_cov*(v.jac_aw'));
  v.aw_syst_err   = sqrt(v.jac_aw*v.xsecs_syst_cov*(v.jac_aw'));
  v.aw_tot_err    = sqrt(v.aw_syst_err.^2 + v.aw_stat_err.^2);
  
  v.rwz_stat_err  = sqrt(v.jac_wz*v.xsecs_stat_cov*(v.jac_wz'));
  v.rwz_syst_err  = sqrt(v.jac_wz*v.xsecs_syst_cov*(v.jac_wz'));
  v.rwz_tot_err   = sqrt(v.rwz_syst_err.^2 + v.rwz_stat_err.^2);
  
  v.rwpz_stat_err = sqrt(v.jac_wpz*v.xsecs_stat_cov*(v.jac_wpz'));
  v.rwpz_syst_err = sqrt(v.jac_wpz*v.xsecs_syst_cov*(v.jac_wpz'));
  v.rwpz_tot_err  = sqrt(v.rwpz_syst_err.^2 + v.rwpz_stat_err.^2);
  
  v.rwmz_stat_err = sqrt(v.jac_wmz*v.xsecs_stat_cov*(v.jac_wmz'));
  v.rwmz_syst_err = sqrt(v.jac_wmz*v.xsecs_syst_cov*(v.jac_wmz'));
  v.rwmz_tot_err  = sqrt(v.rwmz_syst_err.^2 + v.rwmz_stat_err.^2);
  
  v.rwpm_stat_err = sqrt(v.jac_wpm*v.xsecs_stat_cov*(v.jac_wpm'));
  v.rwpm_syst_err = sqrt(v.jac_wpm*v.xsecs_syst_cov*(v.jac_wpm'));
  v.rwpm_tot_err  = sqrt(v.rwpm_syst_err.^2 + v.rwpm_stat_err.^2);
  
  # break it down for table
  v.aw_muonrec_err   = sqrt(v.jac_aw*v.xsecs_muonrec_cov*(v.jac_aw'));
  v.rwz_muonrec_err  = sqrt(v.jac_wz*v.xsecs_muonrec_cov*(v.jac_wz'));
  v.rwpz_muonrec_err = sqrt(v.jac_wpz*v.xsecs_muonrec_cov*(v.jac_wpz'));
  v.rwmz_muonrec_err = sqrt(v.jac_wmz*v.xsecs_muonrec_cov*(v.jac_wmz'));
  v.rwpm_muonrec_err = sqrt(v.jac_wpm*v.xsecs_muonrec_cov*(v.jac_wpm'));

  v.aw_jetrec_err   = sqrt(v.jac_aw*v.xsecs_jetrec_cov*(v.jac_aw'));
  v.rwz_jetrec_err  = sqrt(v.jac_wz*v.xsecs_jetrec_cov*(v.jac_wz'));
  v.rwpz_jetrec_err = sqrt(v.jac_wpz*v.xsecs_jetrec_cov*(v.jac_wpz'));
  v.rwmz_jetrec_err = sqrt(v.jac_wmz*v.xsecs_jetrec_cov*(v.jac_wmz'));
  v.rwpm_jetrec_err = sqrt(v.jac_wpm*v.xsecs_jetrec_cov*(v.jac_wpm'));

  v.aw_sel_eff_err   = sqrt(v.jac_aw*v.xsecs_sel_eff_cov*(v.jac_aw'));
  v.rwz_sel_eff_err  = sqrt(v.jac_wz*v.xsecs_sel_eff_cov*(v.jac_wz'));
  v.rwpz_sel_eff_err = sqrt(v.jac_wpz*v.xsecs_sel_eff_cov*(v.jac_wpz'));
  v.rwmz_sel_eff_err = sqrt(v.jac_wmz*v.xsecs_sel_eff_cov*(v.jac_wmz'));
  v.rwpm_sel_eff_err = sqrt(v.jac_wpm*v.xsecs_sel_eff_cov*(v.jac_wpm'));

  v.aw_gec_eff_err   = sqrt(v.jac_aw*v.xsecs_gec_eff_cov*(v.jac_aw'));
  v.rwz_gec_eff_err  = sqrt(v.jac_wz*v.xsecs_gec_eff_cov*(v.jac_wz'));
  v.rwpz_gec_eff_err = sqrt(v.jac_wpz*v.xsecs_gec_eff_cov*(v.jac_wpz'));
  v.rwmz_gec_eff_err = sqrt(v.jac_wmz*v.xsecs_gec_eff_cov*(v.jac_wmz'));
  v.rwpm_gec_eff_err = sqrt(v.jac_wpm*v.xsecs_gec_eff_cov*(v.jac_wpm'));

  v.aw_rho_err   = sqrt(v.jac_aw*v.xsecs_rho_cov*(v.jac_aw'));
  v.rwz_rho_err  = sqrt(v.jac_wz*v.xsecs_rho_cov*(v.jac_wz'));
  v.rwpz_rho_err = sqrt(v.jac_wpz*v.xsecs_rho_cov*(v.jac_wpz'));
  v.rwmz_rho_err = sqrt(v.jac_wmz*v.xsecs_rho_cov*(v.jac_wmz'));
  v.rwpm_rho_err = sqrt(v.jac_wpm*v.xsecs_rho_cov*(v.jac_wpm'));

  v.aw_A_err   = sqrt(v.jac_aw*v.xsecs_A_cov*(v.jac_aw'));
  v.rwz_A_err  = sqrt(v.jac_wz*v.xsecs_A_cov*(v.jac_wz'));
  v.rwpz_A_err = sqrt(v.jac_wpz*v.xsecs_A_cov*(v.jac_wpz'));
  v.rwmz_A_err = sqrt(v.jac_wmz*v.xsecs_A_cov*(v.jac_wmz'));
  v.rwpm_A_err = sqrt(v.jac_wpm*v.xsecs_A_cov*(v.jac_wpm'));

  v.aw_U_err   = sqrt(v.jac_aw*v.xsecs_U_cov*(v.jac_aw'));
  v.rwz_U_err  = sqrt(v.jac_wz*v.xsecs_U_cov*(v.jac_wz'));
  v.rwpz_U_err = sqrt(v.jac_wpz*v.xsecs_U_cov*(v.jac_wpz'));
  v.rwmz_U_err = sqrt(v.jac_wmz*v.xsecs_U_cov*(v.jac_wmz'));
  v.rwpm_U_err = sqrt(v.jac_wpm*v.xsecs_U_cov*(v.jac_wpm'));

  v.aw_jec_err   = sqrt(v.jac_aw*v.xsecs_jec_cov*(v.jac_aw'));
  v.rwz_jec_err  = sqrt(v.jac_wz*v.xsecs_jec_cov*(v.jac_wz'));
  v.rwpz_jec_err = sqrt(v.jac_wpz*v.xsecs_jec_cov*(v.jac_wpz'));
  v.rwmz_jec_err = sqrt(v.jac_wmz*v.xsecs_jec_cov*(v.jac_wmz'));
  v.rwpm_jec_err = sqrt(v.jac_wpm*v.xsecs_jec_cov*(v.jac_wpm'));

endfunction

function savexsec(v)
	 for i = v
	 a = [i.xsec' , (i.syst_err.*i.xsec)'];
         s = [i.type "_" i.var "_systerr.oct"];
	 save("-text", s, "a");
	 b = [i.xsec' , (i.stat_err.*i.xsec)'];
	 s2 = [i.type "_" i.var "_staterr.oct"];
	 save("-text", s2, "b");
	 c = [i.xsec' , (i.tot_err.*i.xsec)'];
	 s3 = [i.type "_" i.var "_toterr.oct"];
	 save("-text", s3, "c");
	 endfor
endfunction

function saveasymm(v)
	 for i = v
	 a = [i.a' , (i.a_syst_err)];
	 s = ["w_a_" i.var "_systerr.oct"];
	 save("-text", s, "a");
	 a2 = [i.a' , (i.a_stat_err)];
         s2 = ["w_a_" i.var "_staterr.oct"];
	 save("-text", s2, "a2");
	 a3 = [i.a' , (i.a_tot_err)];
	 s3 = ["w_a_" i.var "_toterr.oct"];
	 save("-text", s3, "a3");

	 r = [i.r' , (i.r_syst_err)];
         s4 = ["w_r_" i.var "_systerr.oct"];
	 save("-text", s4, "r");
	 r2 = [i.r' , (i.r_stat_err)];
	 s5 = ["w_r_" i.var "_staterr.oct"];
	 save("-text", s5, "r2");
	 r3 = [i.r' , (i.r_tot_err)];
         s6 = ["w_r_" i.var "_toterr.oct"];
	 save("-text", s6, "r3");
	 endfor
endfunction


#######################################################
# Luminosity
#######################################################
L = 1.97794 * 1000;
Lerr = L * 0.0116;

wp_etaj = variable('wp', 'etaj', L, Lerr);
wp_eta  = variable('wp', 'eta' , L, Lerr );
wp_ptj  = variable('wp', 'ptj' , L, Lerr );
wm_etaj = variable('wm', 'etaj', L, Lerr );
wm_eta  = variable('wm', 'eta' , L, Lerr );
wm_ptj  = variable('wm', 'ptj' , L, Lerr );
w_a = asymm(wp_eta, wm_eta);
w_a_ptj = asymm(wp_ptj, wm_ptj);

z_etaj = variable('zmumu', 'etaj' , L, Lerr );
z_y    = variable('zmumu', 'y'    , L, Lerr );
z_ptj  = variable('zmumu', 'ptj'  , L, Lerr );
z_dphi = variable('zmumu', 'dphi' , L, Lerr );
#wz  = wzratio(wp_etaj, wm_etaj, z_etaj);


a = [wp_etaj.muonrec_eff' , wp_etaj.muonrec_eff_err'];
save wp_etaj_muoneff.oct a
a = [wp_eta.muonrec_eff' , wp_eta.muonrec_eff_err'];
save wp_eta_muoneff.oct a
a = [wp_ptj.muonrec_eff' , wp_ptj.muonrec_eff_err'];
save wp_ptj_muoneff.oct a

  b = [wm_etaj.muonrec_eff' , wm_etaj.muonrec_eff_err'];
save wm_etaj_muoneff.oct b
b = [wm_eta.muonrec_eff' , wm_eta.muonrec_eff_err'];
save wm_eta_muoneff.oct b
b = [wm_ptj.muonrec_eff' , wm_ptj.muonrec_eff_err'];
save wm_ptj_muoneff.oct b

c = [z_etaj.muonrec_eff' , z_etaj.muonrec_eff_err'];
save z_etaj_muoneff.oct c
c = [z_y.muonrec_eff' , z_y.muonrec_eff_err'];
save z_y_muoneff.oct c
c = [z_ptj.muonrec_eff' , z_ptj.muonrec_eff_err'];
save z_ptj_muoneff.oct c
c = [z_dphi.muonrec_eff' , z_dphi.muonrec_eff_err'];
save z_dphi_muoneff.oct c

savexsec([z_y, z_etaj, z_ptj, z_dphi, wp_eta, wp_etaj, wp_ptj, wm_eta, wm_etaj, wm_ptj]);
saveasymm([w_a]);
saveasymm([w_a_ptj]);


#printTGraph(wp_etaj.muonrec_eff, wp_etaj.muonrec_eff_err);
#printTGraph(wp_eta.muonrec_eff , wp_eta.muonrec_eff_err);
#printTGraph(wp_ptj.muonrec_eff , wp_ptj.muonrec_eff_err);

#printTGraph(wm_etaj.muonrec_eff, wm_etaj.muonrec_eff_err);
#printTGraph(wm_eta.muonrec_eff , wm_eta.muonrec_eff_err);
#printTGraph(wm_ptj.muonrec_eff , wm_ptj.muonrec_eff_err);

printXsec(wp_eta, wm_eta, [2.0, 2.5, 3.0, 3.5, 4.5], "$\\eta^{\\mu}$", "$W^{+}j$", "$W^{-}j$")
printXsec(wp_etaj, wm_etaj, [2.2, 2.7, 3.2, 3.7, 4.2], "$\\eta^{j}$", "$W^{+}j$", "$W^{-}j$")
printXsec(wp_ptj, wm_ptj, [20, 25, 30, 40, 50, 100], "$p_{\\rm T}^{j}$", "$W^{+}j$", "$W^{-}j$")

print_jec_errs_2(wp_eta, wm_eta, z_y, [2.0, 2.5, 3.0, 3.5, 4.5], "$\\eta^{\\mu}$", "$W^{+}j$", "$W^{-}j$", "zj")
print_jec_errs_2(wp_etaj, wm_etaj, z_etaj, [2.2, 2.7, 3.2, 3.7, 4.2], "$\\eta^{j}$", "$W^{+}j$", "$W^{-}j$", "zj")
print_jec_errs_2(wp_ptj, wm_ptj, z_ptj, [20, 25, 30, 40, 50, 100], "$p_{\\rm T}^{j}$", "$W^{+}j$", "$W^{-}j$", "zj")

print_jec_errs(z_ptj , [20, 25, 30, 40, 50, 100], "\\ptj [GeV]", "\\cszj")
print_jec_errs(z_etaj, [2.2, 2.7, 3.2, 3.7, 4.2], "\\etaj", "\\cszj")
print_jec_errs(z_y   , [2.0, 2.5, 3.0, 3.5, 4.5], "\\rapz", "\\cszj")
print_jec_errs(z_dphi, [0, 0.52, 1.05, 1.57, 2.09, 2.62, 3.14], "\\dphi [rad.]", "\\cszj")

#errorbar([2.25, 2.75, 3.25, 4.0],w_a.a, w_a.a_stat_err,fmt='dr');

wz  = wzratio(wp_etaj, wm_etaj, z_etaj);
printRatios(wz)

printZXsec(z_ptj , [20, 25, 30, 40, 50, 100], "\\ptj [GeV]", "\\cszj")
printZXsec(z_etaj, [2.2, 2.7, 3.2, 3.7, 4.2], "\\etaj", "\\cszj")
printZXsec(z_y   , [2.0, 2.5, 3.0, 3.5, 4.5], "\\rapz", "\\cszj")
printZXsec(z_dphi, [0, 0.52, 1.05, 1.57, 2.09, 2.62, 3.14], "\\dphi [rad.]", "\\cszj")

printTotSystematics(wp_etaj, wm_etaj, z_etaj, wz, "\\cswpj", "\\cswmj", "\\cszj", "\\ratiowz", "\\ratiow")
