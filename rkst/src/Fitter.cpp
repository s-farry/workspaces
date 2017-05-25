#include <TTree.h>
#include <TChain.h>
#include <TFile.h>
#include <TLeaf.h>
#include <TLorentzVector.h>
#include <TRegexp.h>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TStyle.h>
#include <TLine.h>
#include <TLegend.h>
#include <TText.h>
#include <TCut.h>
#include <TROOT.h>
#include <Math/SMatrix.h>
#include <Math/SVector.h>
#include <string>
#include <sstream>
#include <TPaveText.h>
#include <TParameter.h>

#include "RooFit.h"
#include "RooRealVar.h"
#include "RooBreitWigner.h"
#include "RooCBShape.h"
#include "RooFFTConvPdf.h"
#include "RooPlot.h"
#include "RooGaussian.h"
#include "RooExponential.h"
#include "RooArgSet.h"
#include "RooAddPdf.h"
#include "RooDataSet.h"
#include "RooFitResult.h"
#include "RooGenericPdf.h"
#include "RooNovosibirsk.h"
#include "RooBukinPdf.h"
#include "RooChebychev.h"
#include "RooPolynomial.h"
#include "RooSimultaneous.h"
#include "RooCategory.h"

#include "Fitter.h"

using namespace std;
using namespace RooFit;

Fitter::Fitter(){
  binned = false;
  fitbins = 100;
}


results Fitter::fit_jpsi_mass(RooDataSet* ds, string pass, string oFile, string cut ){
  RooRealVar m(fitvar.c_str(), fitvar.c_str(), lo, hi );
  RooPlot* plot = m.frame();

  RooDataSet* ds_pass = (RooDataSet*)ds->reduce(pass.c_str());
  RooDataSet* ds_fail = (RooDataSet*)ds->reduce(("!("+pass+")").c_str());

  
  RooCategory tagCat("tagCat", "Tagging Category");
  tagCat.defineType("Total");
  tagCat.defineType("Pass");
  tagCat.defineType("Fail");
  RooDataSet combData("combData", "combined data", m, Index(tagCat), Import("Total", *ds),
		      Import("Pass", *ds_pass), Import("Fail", *ds_fail));

  /*
  // Gaussian
  //RooRealVar m0( "m0", "m0", 0 );
  //RooRealVar width( "width", "width", 5, 0, 5000 );
  //RooGaussian gauss( "gauss", "gauss", m, m0, width );

  // Crystal-Ball
  RooRealVar mean( "mean", "mean", 3096, 2700, 3300 );
  RooRealVar sigma( "sigma", "sigma", 16, 0, 1000);
  RooRealVar alpha( "alpha", "alpha", 10, 0.01, 20 );
  RooRealVar n( "n", "n", 3, 0.1, 80 );
  RooCBShape cb( "cb", "cb", m, mean, sigma, alpha, n );
  

  RooRealVar gauss_sigma( "gauss_sigma", "gauss_sigma", 30, 0, 2000);
  RooRealVar gauss_mean( "gauss_mean", "gauss_mean", 3096, 2700, 3300);
  RooGaussian gauss( "gauss", "gauss", m, mean, gauss_sigma );

  //RooBreitWigner bw( "bw", "bw", m, mean2, sigma2 );

  RooRealVar width("width", "width", 30, 0, 1000);
  RooRealVar peak("peak", "peak", 3096, 2700, 3300);
  RooRealVar tail("tail", "tail", 0.2, -5,5);

  RooNovosibirsk novo("novo", "novo", m, mean, width, tail);

  //exponential - combinatorics + background
  RooRealVar lambda("lambda", "slope", -10e-4, -30., 30.);
  RooExponential expo("expo", "exponential PDF", m, lambda);

  //power law
  RooRealVar plIndex("plIndx", "Power Law Index", 0.1, -1000, 10);
  RooGenericPdf spec("spec", "pow(@0,@1)", RooArgList(m, plIndex));
  */
  //code stolen from 2015 analysis
  
  RooRealVar mean("mean","",3096.0,2700,3300);
  RooRealVar sigma1("sigma1","",100.,5,300);
  RooRealVar n("n","",1.);
  RooRealVar a1("a1","",2., 1., 3.);
  //RooCBShape sig("CB1","",m,mean,sigma1,a1,n);
  RooGaussian sig("gauss", "", m, mean, sigma1);

  RooRealVar taub("taub","taub",-0.0001, -1.,1.); 
  RooExponential bkg("bkg","exp",m,taub);

  int Ntot = ds->numEntries();
  int Npass = ds_pass->numEntries();
  int Nfail = ds_fail->numEntries();

  RooRealVar Nsig_tot("Nsig_tot","",Ntot/2.,0.,Ntot);
  RooRealVar Nbkg_tot("Nbkg_tot","",Ntot/2.,0.,Ntot);

  RooRealVar eff("eff", "", 0.9, 0, 1);
  RooRealVar eff2("eff2", "", 0.1, 0, 1);

  RooFormulaVar Nsig_pass("Nsig_pass","@0*@1",RooArgList(Nsig_tot, eff));
  RooFormulaVar Nbkg_pass("Nbkg_pass","@0*@1", RooArgList(Nbkg_tot, eff2));


  RooFormulaVar Nsig_fail("Nsig_fail", "@0*(1-@1)", RooArgList(Nsig_tot, eff));
  RooFormulaVar Nbkg_fail("Nbkg_fail", "@0*(1-@1)", RooArgList(Nbkg_tot, eff2));
  
  RooAddPdf tot_model("tot_model","totmodel", RooArgList(sig,bkg),RooArgList(Nsig_tot,Nbkg_tot));
  RooAddPdf pass_model("pass_model","passmodel", RooArgList(sig,bkg),RooArgList(Nsig_pass,Nbkg_pass));
  RooAddPdf fail_model("fail_model","failmodel", RooArgList(sig,bkg),RooArgList(Nsig_fail,Nbkg_fail));

  RooSimultaneous simPdf("simPdf", "simPdf", tagCat);
  simPdf.addPdf(tot_model , "Total" );
  simPdf.addPdf(pass_model, "Pass"  );
  simPdf.addPdf(fail_model, "Fail"  );

  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 2500);
  m.setMax("cache", 3500);

  //RooFFTConvPdf pdf( "pdf", "pdf", m, novo, bw );

  //Signal fraction
  RooRealVar s("s", "signal", 0.6, 0, 1);
  //RooRealVar s2("s2", "signal 2", 0.1, 0, 1);

  //RooChebychev
  //RooRealVar a0("a0", "a0", -0.1,  0., 1.);
  //RooRealVar a1("a1", "a1", -0.23);
  //RooRealVar a2("a2", "a2",  1.26);
  //RooChebychev bkg("bkg", "bkg", m, RooArgList(a0,a1,a2));

  //RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(cb, bkg), RooArgList(s));

  //sum.fitTo(*ds);
  simPdf.fitTo(combData, RooFit::Range(lo, hi));

  //Make mass plot
  TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
  plot -> GetXaxis() -> SetTitle( "M_{ee} [GeV]" );
  plot -> GetYaxis() -> SetTitleOffset( 1.5 );
  ds->plotOn( plot, RooFit::MarkerColor(kBlack), RooFit::LineColor(kBlack) );
  tot_model.plotOn(plot, RooFit::LineColor(kBlack));
  ds_pass->plotOn( plot, RooFit::MarkerColor(kRed), RooFit::LineColor(kRed) );
  pass_model.plotOn(plot, RooFit::LineColor(kRed));
  ds_fail->plotOn( plot, RooFit::MarkerColor(kBlue), RooFit::LineColor(kBlue) );
  fail_model.plotOn(plot, RooFit::LineColor(kBlue));
  //model.plotOn(plot, RooFit::Components("bkg"), RooFit::LineColor(6));
  //model.plotOn(plot, RooFit::Components("cb"), RooFit::LineColor(2));
  //sum.plotOn(plot, RooFit::Components("novo"), RooFit::LineColor(8));
  
  //print chi2 on plot and add tpavetext
  ostringstream sstream;
  sstream<<"#chi^{2}/nDoF = "<<plot->chiSquare();
  TPaveText* p = new TPaveText(0.15, 0.7, 0.5, 0.9, "NDC");
  p->SetFillStyle(0);
  p->SetBorderSize(0.0);
  plot->addObject(p);
  p->AddText(cut.c_str());
  p->AddText(sstream.str().c_str());
  plot->Draw();
  p->Draw();
  canv->SaveAs( (location+"/jpsi_M_"+oFile+".pdf").c_str() );

  // return as pair with value and error of mean


  results parms;
  // return as pair with value and error of mean
  parms["Ntot"]  = std::pair<double, double>(Nsig_tot.getVal()  , Nsig_tot.getError());
  parms["eff"] = std::pair<double, double>(eff.getVal()  , eff.getError());
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError());
  parms["sigma"] = std::pair<double, double>(sigma1.getVal() , sigma1.getError());
  return parms;

}

TObjArray* Fitter::do_fit(RooDataSet* ds, string pass, string label){
  //mass variable
  RooRealVar m( fitvar.c_str(), fitvar.c_str(), lo, hi);
  //other variables needed to make dataset
  
  TObjArray* objs = new TObjArray();
  
  if (vars.size() != 0 && (vars.size() != los.size() || vars.size() != his.size() || vars.size() != bins.size())){
    cout<<"mismatch in 1d vars"<<endl;
    return objs;
  }
  if( vars2d.size() != 0 && (vars2d.size() != los2d.size() || vars2d.size() != his2d.size() || vars2d.size() != bins2d.size())){
    cout<<"mismatch in 2d vars"<<endl;
    return objs;
  }

  //First fit total distributions
  ostringstream s1;
  if (label != "") s1<<label<<"_tot";
  else s1<<fitvar<<"_tot";
  ostringstream label2;
  //label2<<"Total Fiducial";
  label2<<"";
  results result_tot;
  if (fitmodel == Fitter::jpsi){
    result_tot   = fit_jpsi_mass(ds, pass, s1.str(), label2.str());
  }
  
  results::iterator ir;

  for (ir = result_tot.begin() ; ir != result_tot.end() ; ++ir){
    ostringstream s1, s2;
    if (label != ""){
      s1<<fitvar<<"_"<<(*ir).first<<"_"<<label<<"_tot";
      s2<<fitvar<<"_"<<(*ir).first<<"_"<<label<<"_tot_err";
    }
    else{
      s1<<fitvar<<"_"<<(*ir).first<<"_tot";
      s2<<fitvar<<"_"<<(*ir).first<<"_tot_err";
    }
    objs->Add(new TParameter<double>(s1.str().c_str() , (*ir).second.first   ));
    objs->Add(new TParameter<double>(s2.str().c_str() , (*ir).second.second  ));
  }


  for (unsigned int i = 0 ; i < vars.size() ; ++i){
    string var = vars[i] ;
    double lo  = los[i]  ;
    double hi  = his[i]  ;
    int varbins   = bins[i];
    
    //make mass histogram
    std::map< string, TH1F*> hists1d;
    results::iterator ir;

    for (ir = result_tot.begin() ; ir != result_tot.end() ; ++ir){
      std::string hist_title = (*ir).first + "_v_"+var;
      if (label != "") hist_title += "_"+label;
      if (edges.find(i) == edges.end()){
	hists1d[(*ir).first] = new TH1F(hist_title.c_str(),hist_title.c_str(),
					varbins, lo, hi);
      }
      else{
	hists1d[(*ir).first] = new TH1F(hist_title.c_str(), hist_title.c_str(),
					varbins, edges[i]);
      }
    }


    //calculate latex version of variable if possible
    string latexvar;
    if (var.find("eta") != std::string::npos) latexvar = "#eta";
    else if (var.find("eta") != std::string::npos ) latexvar = "#phi";
    else latexvar = var;
    
    for (int j = 0 ; j < varbins ; ++j) {
      ostringstream cut;
      double binlo = lo + j*((hi - lo)/varbins);
      double binhi = lo + (j+1)*((hi-lo)/varbins);

      if (edges.find(i) != edges.end()){
	binlo = edges[i][j];
	binhi = edges[i][j+1];
      }
      
      cut  <<var<<">"<<binlo<<" && "<<var<<"<"<<binhi;
      //add dataset with specific cuts
      cout<<"-------------------------"<<endl;
      cout<<cut.str()<<endl;
      cout<<"-------------------------"<<endl;
      RooDataSet* ds_reduced = (RooDataSet*)ds->reduce(cut.str().c_str());
      cout<<"reduced from "<<ds->numEntries()<<" to "<<ds_reduced->numEntries()<<endl;
      cout<<"-------------------------"<<endl;
      //make mass histogram
      ostringstream s9;
      if (label != "") s9<<label<<"_"<<var<<"_"<<j;
      else s9<<var<<"_"<<j;
      //cut to be presented on plot
      ostringstream label3;
      label3<<binlo<<" < "<<latexvar<<" < "<<binhi;
      results result;
      if (fitmodel == Fitter::jpsi){
	result   = fit_jpsi_mass(ds_reduced   , pass, s9.str(), label3.str());
      }
      for (ir = result_tot.begin() ; ir != result_tot.end() ; ++ir){
	hists1d[(*ir).first]->SetBinContent(j+1, result[(*ir).first].first);
	hists1d[(*ir).first]->SetBinError(j+1, result[(*ir).first].second);
      }

      delete ds_reduced;
    }
    
    std::map<string, TH1F*>::iterator ih;
    for (ih = hists1d.begin() ; ih != hists1d.end() ; ++ih){
      objs->Add((*ih).second);
    }
  }
  
  for (unsigned int i = 0 ; i < vars2d.size() ; ++i){
    string var1 = vars2d[i][0] ;
    double lo1  = los2d[i][0]  ;
    double hi1  = his2d[i][0]  ;
    int bins1   = bins2d[i][0];
    string var2 = vars2d[i][1] ;
    double lo2  = los2d[i][1]  ;
    double hi2  = his2d[i][1]  ;
    int bins2   = bins2d[i][1];
    
    //vector<RooDataSet*> magup_datasets   ;
    //vector<RooDataSet*> magdown_datasets ;
    //make mass histogram


    //make mass histogram
    std::map< string, TH2F*> hists2d;
    results::iterator ir;

    for (ir = result_tot.begin() ; ir != result_tot.end() ; ++ir){
      string hist_title = (*ir).first + "_v_"+var1+"_"+var2;
      if (label != "") hist_title += "_"+label;
      if (edges2d.find(i) == edges2d.end()){
	hists2d[(*ir).first] = new TH2F(hist_title.c_str(), hist_title.c_str(),
					bins1, lo1, hi1, bins2, lo2, hi2);
      }
      else{
	hists2d[(*ir).first] = new TH2F(hist_title.c_str(), hist_title.c_str(),
					bins1, edges2d.at(i).first, bins2, edges2d.at(i).second);
      }
    }
    
    //calculate latex version of variable if possible
    string latexvar1;
    if (var1.find("ETA") != std::string::npos) latexvar1 = "#eta";
    else if (var1.find("PHI") != std::string::npos ) latexvar1 = "#phi";
    else latexvar1 = var1;
    string latexvar2;
    if (var2.find("ETA") != std::string::npos) latexvar2 = "#eta";
    else if (var2.find("PHI") != std::string::npos ) latexvar2 = "#phi";
    else latexvar2 = var1;
    
    for (int k = 0 ; k < bins1 ; ++k) {
      for (int j = 0 ; j < bins2 ; ++j) {
	ostringstream cut;
	double binlo1 = lo1 + k*((hi1 - lo1)/bins1);
	double binhi1 = lo1 + (k+1)*((hi1-lo1)/bins1);
	double binlo2 = lo2 + j*((hi2 - lo2)/bins2);
	double binhi2 = lo2 + (j+1)*((hi2-lo2)/bins2);

	if (edges2d.find(i) != edges2d.end()){
	  binlo1 = edges2d[i].first[k];
	  binhi1 = edges2d[i].first[k+1];
	  binlo2 = edges2d[i].second[j];
	  binhi2 = edges2d[i].second[j+1];
	}


	cut  <<var1<<">"<<binlo1<<" && "<<var1<<"<"<<binhi1<<" && "<<var2<<">"<<binlo2<<" && "<<var2<<"<"<<binhi2;
	//add dataset with specific cuts
	RooDataSet* ds_reduced = (RooDataSet*)ds->reduce(cut.str().c_str());

	cout<<"-------------------------"<<endl;
	cout<<cut.str()<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"reduced from "<<ds->numEntries()<<" to "<<ds_reduced->numEntries()<<endl;
	cout<<"-------------------------"<<endl;
	//make mass histogram
	ostringstream s1, s2;
	s1<<var1<<"_"<<var2<<"_"<<label<<"_"<<k<<"_"<<j;
	s2<<var1<<"_"<<var2<<"_"<<label<<"_"<<k<<"_"<<j;
	//cut to be presented on plot
	ostringstream label2;
	label2<<binlo1<<" < "<<latexvar1<<" < "<<binhi1<<" && "<<binlo2<<" < "<<latexvar2<<" < "<<binhi2;

	results result;

	if (fitmodel == Fitter::jpsi){
	  result   = fit_jpsi_mass(ds_reduced   , pass, s1.str(), label2.str());
	}
	for (ir = result_tot.begin() ; ir != result_tot.end() ; ++ir){
	  hists2d[(*ir).first]->SetBinContent(k+1, j+1, result[(*ir).first].first);
	  hists2d[(*ir).first]->SetBinError(k+1, j+1, result[(*ir).first].second);
	}

	delete ds_reduced;
      }
      
      std::map<string, TH2F*>::iterator ih;
      for (ih = hists2d.begin() ; ih != hists2d.end() ; ++ih){
	objs->Add((*ih).second);
      }
    }
  }
  return objs;
}

int main(int argc, char* argv[]){
  if (argc != 3 && argc!= 2 && argc != 1 && argc != 4) return 0;
  

  TH1::AddDirectory(false);
  gROOT->ProcessLine(".x /user2/sfarry/workspaces/WJet/root/lhcbStyle.C");

  Fitter jpsi2ee_mc2016;
  jpsi2ee_mc2016.fitvar="jpsi_m";
  jpsi2ee_mc2016.fitmodel = Fitter::jpsi;
  jpsi2ee_mc2016.lo = 2500.;
  jpsi2ee_mc2016.hi = 3500.;
  jpsi2ee_mc2016.location = "/user2/sfarry/workspaces/rkst/figures";
  jpsi2ee_mc2016.vars    = {"pt", "eta"};
  jpsi2ee_mc2016.los     =  {500, 2.0};
  jpsi2ee_mc2016.his     =  {5000, 4.5};
  jpsi2ee_mc2016.bins    = { 4, 3 };
  //alter bin edges
  double pt_edges[] = {500, 600 ,1000, 2000, 5000};
  double eta_edges[] = {2.0, 3.0, 4.0, 4.5};
  jpsi2ee_mc2016.edges[0] = pt_edges;
  jpsi2ee_mc2016.edges[1] = eta_edges;
  jpsi2ee_mc2016.vars2d   = {{"pt", "eta"}};
  jpsi2ee_mc2016.los2d    = {{500, 2.0}};
  jpsi2ee_mc2016.his2d    = {{5000, 4.5}};
  jpsi2ee_mc2016.bins2d   = {{ 4 , 3 }};
  jpsi2ee_mc2016.edges2d[0]  = {pt_edges, eta_edges};

  string input = "root://hepgrid11.ph.liv.ac.uk///dpm/ph.liv.ac.uk/home/lhcb/refit/Jpsi.2015.root";
  string output = "/user2/sfarry/workspaces/rkst/tuples/output.root";

  if (argc > 1){
    input = argv[1];
  }
  if (argc > 2){
    output = argv[2];
    jpsi2ee_mc2016.location = "figures/"+output;
    output = "/user2/sfarry/workspaces/rkst/tuples/"+output;
  }
  
  
  std::cout<<"got here"<<std::endl;
  TFile* f = TFile::Open(input.c_str(), "READ");
  RooDataSet* ds   = (RooDataSet*)f->Get("ds");
  std::cout<<"got dataset"<<std::endl;
  TObjArray *hists = 0;
  if ( ds) {
    hists = jpsi2ee_mc2016.do_fit(ds, "velomatch > 0.7 && dR < 0.02 && dRt < 500");
  }
  TFile* g = TFile::Open((output+".root").c_str(), "RECREATE");
  if (hists)hists->Write();
  //if (histsc) histsc->Write();
  g->Close();
  return 0;
}
