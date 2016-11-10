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

#include "Fitter.h"

#include "My_double_CB.h"

using namespace std;
using namespace RooFit;


results Fitter::fit_bjpsik_mass(RooDataSet* ds, string oFile, string cut, bool kstar)
{
  RooRealVar m( fitvar.c_str(), fitvar.c_str(), lo, hi );
  RooPlot* plot = m.frame();

  // Gaussian
  RooRealVar mean( "mean", "mean", 5281, 5200, 5350 );
  RooRealVar sigma( "sigma", "sigma", 3.0, 0, 100);
  RooGaussian gauss( "gauss", "gauss", m, mean, sigma );

  if (kstar) sigma.setVal(25.0);

  RooRealVar a1("#alpha1", "#alphaa", 1.7, 0, 3);
  RooRealVar a2("#alpha2", "#alpha2", 1.7, 0, 3);
  RooRealVar n1("n1", "n1", 5.7, 0, 15);
  RooRealVar n2("n2", "n2", 10.0, 0, 15);

  if (kstar){
    a1.setVal(1.20);
    //a1.setConstant();
    a2.setVal(1.08);
    //a2.setConstant();
    n1.setVal(8.12);
    //n1.setConstant();
    n2.setVal(1.97);
    //n2.setConstant();
  }
  
  My_double_CB cb_pdf("cb", "cb", m, mean, sigma, a1, n1, a2, n2);

  
  //exponential - DY component + background
  RooRealVar lambda("lambda", "slope", -1.4e-3, -30., 0.);
  RooExponential expo("expo", "exponential PDF", m, lambda);

  int entries = ds->numEntries();

  //Signal fraction
  RooRealVar Nsig("Nsig", "signal", entries/2, 0, entries);
  RooRealVar Nbkg("Nbkg", "background", entries/2, 0, entries);

  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(cb_pdf, expo), RooArgList(Nsig, Nbkg));

  //sum.fitTo(*ds, RooFit::Extended());
  sum.fitTo(*ds, RooFit::Range(lo, hi));

  //Make mass plot
  TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
  if (!kstar)  plot -> GetXaxis() -> SetTitle( "M(J/#psiK) [MeV]" );
  else plot->GetXaxis()->SetTitle("M(J/#psiK*) [MeV]");
  plot -> GetYaxis() -> SetTitle( "Events" );
  plot -> GetYaxis() -> SetTitleOffset( 1.5 );
  ds->plotOn( plot );
  sum.plotOn(plot, RooFit::Components("expo"), RooFit::LineColor(kRed)  , RooFit::LineStyle(kDashed));
  sum.plotOn(plot, RooFit::Components("cb"),   RooFit::LineColor(kGreen), RooFit::LineStyle(kDashed));
  sum.plotOn(plot);


  //print chi2 on plot and add tpavetext
  ostringstream sstream, sstream2;
  sstream<<"#chi^{2}/nDoF = "<<plot->chiSquare();
  sstream2<<"N_{sig} = "<<Nsig.getVal();
  TPaveText* p = new TPaveText(0.6, 0.7, 0.85, 0.9, "NDC");
  p->SetFillStyle(0);
  p->SetBorderSize(0.0);
  plot->addObject(p);
  p->AddText(cut.c_str());
  p->AddText(sstream.str().c_str());
  p->AddText(sstream2.str().c_str());
  plot->Draw();
  p->Draw();
  if (!kstar) canv->SaveAs( ("BJpsiK_"+oFile+".pdf").c_str() );
  else canv->SaveAs( ("BJpsiKst_"+oFile+".pdf").c_str() );
  canv->Delete();


  results parms;
  // return as pair with value and error of mean
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError() );
  parms["sigma"] = std::pair<double, double>(sigma.getVal() , sigma.getError());
  parms["Nsig"]  = std::pair<double, double>(Nsig.getVal()  , Nsig.getError() );
  parms["Nbkg"]  = std::pair<double, double>(Nbkg.getVal()  , Nbkg.getError() );
  parms["a1"]    = std::pair<double, double>(a1.getVal()  , a1.getError() );
  parms["a2"]    = std::pair<double, double>(a2.getVal()  , a2.getError() );
  parms["n1"]    = std::pair<double, double>(n1.getVal()  , n1.getError() );
  parms["n2"]    = std::pair<double, double>(n2.getVal()  , n2.getError() );
  parms["lambda"]= std::pair<double, double>(lambda.getVal()  , lambda.getError() );
  return parms;


}

results Fitter::fit_bjpsik_mass_novosibirsk(RooDataSet* ds, string oFile, string cut, bool kstar)
{
  RooRealVar m( fitvar.c_str(), fitvar.c_str(), lo, hi );
  RooPlot* plot = m.frame();

  // Gaussian
  RooRealVar mean( "mean", "mean", 5281, 5200, 5350 );
  RooRealVar mean2( "mean2", "mean2", 5281, 5200, 5350 );
  RooRealVar sigma( "sigma", "sigma", 5.0, 0, 100);
  RooRealVar sigma2( "sigma2", "sigma2", 5.0, 0, 100);

  RooRealVar xi("xi", "xi", 0.2, 0, 2);
  RooRealVar rho1("rho1", "rho1", 0.005, 0, 1.0);
  RooRealVar rho2("rho2", "rho2", 0.005, 0, 1.0);

  if (kstar) {
    sigma.setVal(25.0);
    //sigma.setConstant();
    mean.setVal(5270);
    xi.setVal(0.12);
    //xi.setConstant();
    //xi.setVal(0.8);
    //xi.setConstant();
    //rho1.setVal(0.112);
    //rho2.setVal(0.068);
    rho1.setVal(0.15);
    rho2.setVal(0.01);
    //rho1.setConstant();
    //rho2.setConstant();
  }
  


  //RooNovosibirsk novo("novo", "novo", m, mean, sigma, tail);
  RooBukinPdf bukin("bukin", "bukin", m, mean, sigma, xi, rho1, rho2);

  RooGaussian gauss("gauss", "gauss", m, mean, sigma2);

  //exponential - DY component + background
  RooRealVar lambda("lambda", "slope", -2e-3, -1e-1, 0.);
  //lambda.setConstant();
  RooExponential expo("expo", "exponential PDF", m, lambda);

  //Set cache for FFT convolution

  int entries = ds->numEntries();

  //Signal fraction
  RooRealVar Nsig("Nsig", "signal", entries*0.8, 0, entries);
  RooRealVar Nsig2("Nsig", "signal", entries*0.4, 0, entries);
  RooRealVar Nbkg("Nbkg", "background", entries*0.2, 0, entries);

  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(bukin, expo), RooArgList(Nsig, Nbkg));

  sum.fitTo(*ds, RooFit::Extended(), RooFit::Range(lo, hi));

  //Make mass plot
  TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
  if (!kstar)  plot -> GetXaxis() -> SetTitle( "M(J/#psiK) [MeV]" );
  else plot->GetXaxis()->SetTitle("M(J/#psiK*) [MeV]");
  plot -> GetYaxis() -> SetTitleOffset( 1.5 );
  ds->plotOn( plot );
  sum.plotOn(plot, RooFit::Components("expo") , RooFit::LineColor(kRed)  , RooFit::LineStyle(kDashed));
  sum.plotOn(plot, RooFit::Components("bukin"),   RooFit::LineColor(kGreen), RooFit::LineStyle(kDashed));
  sum.plotOn(plot, RooFit::Components("gauss"),   RooFit::LineColor(kYellow), RooFit::LineStyle(kDashed));
  sum.plotOn(plot);


  //print chi2 on plot and add tpavetext
  ostringstream sstream, sstream2;
  sstream<<"#chi^{2}/nDoF = "<<plot->chiSquare();
  sstream2<<"N_{sig} = "<<Nsig.getVal();
  TPaveText* p = new TPaveText(0.6, 0.7, 0.9, 0.9, "NDC");
  p->SetFillStyle(0);
  p->SetBorderSize(0.0);
  plot->addObject(p);
  p->AddText(cut.c_str());
  p->AddText(sstream.str().c_str());
  p->AddText(sstream2.str().c_str());
  plot->Draw();
  p->Draw();
  if (!kstar) canv->SaveAs( ("BJpsiK_"+oFile+".pdf").c_str() );
  else canv->SaveAs( ("BJpsiKst_"+oFile+".pdf").c_str() );
  canv->Delete();


  results parms;
  // return as pair with value and error of mean
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError() );
  parms["sigma"] = std::pair<double, double>(sigma.getVal() , sigma.getError());
  parms["Nsig"]  = std::pair<double, double>(Nsig.getVal()  , Nsig.getError() );
  parms["Nbkg"]  = std::pair<double, double>(Nbkg.getVal()  , Nbkg.getError() );
  parms["xi"]    = std::pair<double, double>(xi.getVal()    , xi.getError()   );
  parms["rho1"]  = std::pair<double, double>(rho1.getVal()  , rho1.getError() );
  parms["rho2"]  = std::pair<double, double>(rho2.getVal()  , rho2.getError() );
  return parms;


}


results Fitter::fit_bjpsik_mass_polynomial(RooDataSet* ds, string oFile, string cut, bool kstar)
{
  RooRealVar m( fitvar.c_str(), fitvar.c_str(), lo, hi );
  RooPlot* plot = m.frame();




  // Gaussian
  RooRealVar mean( "mean", "mean", 5281, 5150, 5350 );
  RooRealVar sigma( "sigma", "sigma", 8.0, 0, 100);
  RooGaussian gauss( "gauss", "gauss", m, mean, sigma );

  if (kstar) sigma.setVal(25.0);

  RooRealVar a1("#alpha1", "#alphaa", 1.6, 0, 3);
  RooRealVar a2("#alpha2", "#alpha2", 1.6, 0, 3);
  RooRealVar n1("n1", "n1", 14.0, 0, 15);
  RooRealVar n2("n2", "n2", 14.0, 0, 15);

  
  if (kstar){
    a1.setVal(1.20);
    a1.setConstant();
    a2.setVal(1.08);
    a2.setConstant();
    n1.setVal(8.12);
    n1.setConstant();
    n2.setVal(1.97);
    n2.setConstant();
  }
  
  My_double_CB cb_pdf("cb", "cb", m, mean, sigma, a1, n1, a2, n2);

  
  //exponential - DY component + background
  // Construction quadratic polynomial pdf for fitting
  RooRealVar b0("b0","b0",1.0) ;
  RooRealVar b1("b1","b1", -1e-4,-5e-4,5e-4) ;
  RooRealVar b2("b2","b2",1e-8,0,5e-8) ;
  RooPolynomial p2("p2","p2",m,RooArgList(b0,b1,b2)) ;

  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 5200);
  m.setMax("cache", 5350);

  int entries = ds->numEntries();

  //Signal fraction
  RooRealVar Nsig("Nsig", "signal", entries/2, 0, entries);
  RooRealVar Nbkg("Nbkg", "background", entries/2, 0, entries);

  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(cb_pdf, p2), RooArgList(Nsig, Nbkg));

  //sum.fitTo(*ds, RooFit::Extended());
  sum.fitTo(*ds, RooFit::Range(lo, hi));

  //Make mass plot
  TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
  if (!kstar)  plot -> GetXaxis() -> SetTitle( "M(J/#psiK) [MeV]" );
  else plot->GetXaxis()->SetTitle("M(J/#psiK*) [MeV]");
  plot -> GetYaxis() -> SetTitleOffset( 1.5 );
  plot->GetYaxis()->SetTitle("Events");
  ds->plotOn( plot );
  sum.plotOn(plot);
  sum.plotOn(plot, RooFit::Components("p2") , RooFit::LineColor(kRed)  , RooFit::LineStyle(kDashed));
  sum.plotOn(plot, RooFit::Components("cb"),   RooFit::LineColor(kGreen), RooFit::LineStyle(kDashed));


  //print chi2 on plot and add tpavetext
  ostringstream sstream;
  sstream<<"#chi^{2}/nDoF = "<<plot->chiSquare();
  ostringstream sstream2;
  sstream2<<"N_{sig} = "<<Nsig.getVal();
  TPaveText* p = new TPaveText(0.6, 0.7, 0.9, 0.9, "NDC");
  p->SetFillStyle(0);
  p->SetBorderSize(0.0);
  plot->addObject(p);
  p->AddText(cut.c_str());
  p->AddText(sstream.str().c_str());
  p->AddText(sstream2.str().c_str());
  //plot signal
  plot->Draw();
  p->Draw();
  if (!kstar) canv->SaveAs( ("BJpsiK_"+oFile+".pdf").c_str() );
  else canv->SaveAs( ("BJpsiKst_"+oFile+".pdf").c_str() );
  canv->Delete();


  results parms;
  // return as pair with value and error of mean
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError() );
  parms["sigma"] = std::pair<double, double>(sigma.getVal() , sigma.getError());
  parms["Nsig"]  = std::pair<double, double>(Nsig.getVal()  , Nsig.getError() );
  parms["Nbkg"]  = std::pair<double, double>(Nbkg.getVal()  , Nbkg.getError() );
  parms["a1"]    = std::pair<double, double>(a1.getVal()  , a1.getError() );
  parms["a2"]    = std::pair<double, double>(a2.getVal()  , a2.getError() );
  parms["n1"]    = std::pair<double, double>(n1.getVal()  , n1.getError() );
  parms["n2"]    = std::pair<double, double>(n2.getVal()  , n2.getError() );
  parms["b0"]    = std::pair<double, double>(b0.getVal()  , b0.getError() );
  parms["b1"]    = std::pair<double, double>(b1.getVal()  , b1.getError() );
  parms["b2"]    = std::pair<double, double>(b2.getVal()  , b2.getError() );
  return parms;


}


results Fitter::fit_z0_mass(RooDataSet* ds, string oFile, string cut){
  RooRealVar m( fitvar.c_str(), fitvar.c_str(), lo, hi );
  RooPlot* plot = m.frame();

  // Breit Wigner - Z Lineshape
  RooRealVar m0( "m0", "m0", 0 );
  RooRealVar width( "width", "width", 3500, 0, 5000 );
  RooBreitWigner bw( "gauss", "gauss", m, m0, width );

  // Crystal-Ball - Detector response + FSR
  RooRealVar mean( "mean", "mean", 90300, 70000, 110000 );
  RooRealVar sigma( "sigma", "sigma", 1500, 0, 5000);
  RooRealVar alpha( "alpha", "alpha", 2.2, 0.01, 5 );
  RooRealVar n( "n", "n", 0.48, 0.01, 80 );
  RooCBShape cb( "cb", "cb", m, mean, sigma, alpha, n );

  //exponential - DY component + background
  RooRealVar lambda("lambda", "slope", -1e-6, -30., 0.);
  RooExponential expo("expo", "exponential PDF", m, lambda);

  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 50500);
  m.setMax("cache", 129500);

  //convolve PDFs
  RooFFTConvPdf pdf( "pdf", "pdf", m, cb, bw );

  //Background fraction
  RooRealVar s("s", "signal", 0.8, 0, 1);

  RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(pdf, expo), RooArgList(s));

  //sum.fitTo(*ds, RooFit::Extended());
  sum.fitTo(*ds, RooFit::Range(lo, hi));

  //Make mass plot
  TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
  plot -> GetXaxis() -> SetTitle( "M_{#mu#mu} [GeV]" );
  plot -> GetYaxis() -> SetTitleOffset( 1.5 );
  ds->plotOn( plot );
  sum.plotOn(plot);


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
  canv->SaveAs( ("BWxCB_"+oFile+".pdf").c_str() );
  canv->Delete();


  results parms;
  // return as pair with value and error of mean
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError());
  parms["sigma"] = std::pair<double, double>(sigma.getVal() , sigma.getError());
  return parms;

}


results Fitter::fit_jpsi_mass(RooDataSet* ds, string oFile, string cut ){
  RooRealVar m(fitvar.c_str(), fitvar.c_str(), lo, hi );
  RooPlot* plot = m.frame();

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
  RooRealVar sigma1("sigma1","",6.,5,20);
  RooFormulaVar sigma2("sigma2","25.7+1.0*sigma1",RooArgSet(sigma1));
  RooRealVar n("n","",1.);
  RooFormulaVar a2("a2","2.066+0.0085*sigma2-0.00011*sigma2*sigma2",RooArgSet(sigma2));
  RooFormulaVar a1("a1","2.066+0.0085*sigma1-0.00011*sigma1*sigma1",RooArgSet(sigma1));
  RooCBShape sig2("CB2","",m,mean,sigma2,a2,n);
  RooCBShape sig1("CB1","",m,mean,sigma1,a1,n);

  RooRealVar fr("fr","",0.96);
  RooAddPdf sig("sig","sig", RooArgList(sig1,sig2),RooArgList(fr));

  RooRealVar taub("taub","taub",-0.0001, -1.,1.); 
  RooExponential bkg("bkg","exp",m,taub);

  int Ntot = ds->numEntries();

  RooRealVar Nsig("Nsig","",Ntot/2.,0.,Ntot);
  RooRealVar Nbkg("Nbkg","",Ntot/2.,0.,Ntot);
  
  RooAddPdf model("model","model", RooArgList(sig,bkg),RooArgList(Nsig,Nbkg));


  //Set cache for FFT convolution
  m.setBins(10000, "cache");
  m.setMin("cache", 2500);
  m.setMax("cache", 3500);

  //RooFFTConvPdf pdf( "pdf", "pdf", m, novo, bw );

  //Signal fraction
  RooRealVar s("s", "signal", 0.65, 0, 1);
  //RooRealVar s2("s2", "signal 2", 0.1, 0, 1);

  //RooChebychev
  //RooRealVar a0("a0", "a0", -0.1,  0., 1.);
  //RooRealVar a1("a1", "a1", -0.23);
  //RooRealVar a2("a2", "a2",  1.26);
  //RooChebychev bkg("bkg", "bkg", m, RooArgList(a0,a1,a2));

  //RooAddPdf sum("sum", "crystal ball + gaussian + expo", RooArgList(cb, bkg), RooArgList(s));

  //sum.fitTo(*ds);
  model.fitTo(*ds, RooFit::Range(lo, hi));

  //Make mass plot
  TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
  plot -> GetXaxis() -> SetTitle( "M_{#mu#mu} [GeV]" );
  plot -> GetYaxis() -> SetTitleOffset( 1.5 );
  ds->plotOn( plot );
  model.plotOn(plot);
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
  canv->SaveAs( ("jpsi_M_"+oFile+".pdf").c_str() );

  // return as pair with value and error of mean


  results parms;
  // return as pair with value and error of mean
  parms["mean"]  = std::pair<double, double>(mean.getVal()  , mean.getError());
  parms["sigma"] = std::pair<double, double>(sigma1.getVal() , sigma1.getError());
  return parms;

}

/*
TObjArray* Fitter::get_mass_v_vars(RooDataSet* dsUp, RooDataSet* dsDown){
  //mass variable
  RooRealVar m( fitvar.c_str(), fitvar.c_str(), lo, hi);
  //other variables needed to make dataset
  
  TObjArray* hists = new TObjArray();
  
  if (vars.size() != los.size() || vars.size() != his.size() || vars.size() != bins.size()){
    cout<<"mismatch in 1d vars"<<endl;
    return hists;
  }
  if( vars2d.size() != los2d.size() || vars2d.size() != his2d.size() || vars2d.size() != bins2d.size()){
    cout<<"mismatch in 2d vars"<<endl;
    return hists;
  }

  //First fit total distributions
  ostringstream s1, s2;
  s1<<fitvar<<"_tot_magup";
  s2<<fitvar<<"_tot_magdown";
  ostringstream label;
  label<<"Total Fiducial";
  results magup_result_tot, magdown_result_tot;
  if (fitmodel == Fitter::jpsi){
    magup_result_tot   = fit_jpsi_mass(dsUp   , s1.str(), label.str());
    magdown_result_tot = fit_jpsi_mass(dsDown , s2.str(), label.str());
  }
  else if (fitmodel == Fitter::bjpsik){
    magup_result_tot   = fit_bjpsik_mass(dsUp   , s1.str(), label.str());
    magdown_result_tot = fit_bjpsik_mass(dsDown , s2.str(), label.str());    
  }
  else if (fitmodel == Fitter::z0){
    magup_result_tot   = fit_z0_mass(dsUp   , s1.str(), label.str());
    magdown_result_tot = fit_z0_mass(dsDown , s2.str(), label.str());
  }
  
  ostringstream ss1, ss2, ss3, ss4, ss5, ss6, ss7, ss8;
  ss1<<fitvar<<"_magup_mass_tot";
  ss2<<fitvar<<"_magdown_mass_tot";
  ss3<<fitvar<<"_magup_sigma_tot";
  ss4<<fitvar<<"_magdown_sigma_tot";
  ss5<<fitvar<<"_magup_mass_tot_err";
  ss6<<fitvar<<"_magdown_mass_tot_err";
  ss7<<fitvar<<"_magup_sigma_tot_err";
  ss8<<fitvar<<"_magdown_sigma_tot_err";

  hists->Add(new TParameter<double>(ss1.str().c_str() , magup_result_tot.at(0).first   ));
  hists->Add(new TParameter<double>(ss2.str().c_str() , magdown_result_tot.at(0).first ));
  hists->Add(new TParameter<double>(ss3.str().c_str() , magup_result_tot.at(1).first   ));
  hists->Add(new TParameter<double>(ss4.str().c_str() , magdown_result_tot.at(1).first ));
  hists->Add(new TParameter<double>(ss5.str().c_str() , magup_result_tot.at(0).second   ));
  hists->Add(new TParameter<double>(ss6.str().c_str() , magdown_result_tot.at(0).second ));
  hists->Add(new TParameter<double>(ss7.str().c_str() , magup_result_tot.at(1).second   ));
  hists->Add(new TParameter<double>(ss8.str().c_str() , magdown_result_tot.at(1).second ));

  for (unsigned int i = 0 ; i < vars.size() ; ++i){
    string var = vars[i] ;
    double lo  = los[i]  ;
    double hi  = his[i]  ;
    int varbins   = bins[i];
    
    //make mass histogram
    TH1F* magup_hist    = new TH1F(("mass_v_"+var+"_magup").c_str()    , ("mass_v_"+var+"_magup").c_str()    , varbins, lo, hi);
    TH1F* magdown_hist  = new TH1F(("mass_v_"+var+"_magdown").c_str()  , ("mass_v_"+var+"_magdown").c_str()  , varbins, lo, hi);
    TH1F* magup_sigma   = new TH1F(("sigma_v_"+var+"_magup").c_str()   , ("sigma_v_"+var+"_magup").c_str()   , varbins, lo, hi);
    TH1F* magdown_sigma = new TH1F(("sigma_v_"+var+"_magdown").c_str() , ("sigma_v_"+var+"_magdown").c_str() , varbins, lo, hi);
    //calculate latex version of variable if possible
    string latexvar;
    if (var.find("ETA") != std::string::npos) latexvar = "#eta";
    else if (var.find("PHI") != std::string::npos ) latexvar = "#phi";
    else latexvar = var;
    
    for (int i = 0 ; i < varbins ; ++i) {
      ostringstream cutup, cutdown;
      double binlo = lo + i*((hi - lo)/varbins);
      double binhi = lo + (i+1)*((hi-lo)/varbins);
      cutup  <<var<<">"<<binlo<<" && "<<var<<"<"<<binhi;
      //add dataset with specific cuts
      RooDataSet* dsup_reduced = (RooDataSet*)dsUp->reduce(cutup.str().c_str());
      RooDataSet* dsdown_reduced = (RooDataSet*)dsDown->reduce(cutup.str().c_str());
      
      //make mass histogram
      ostringstream s9, s10;
      s9<<var<<"_magup_"<<i;
      s10<<var<<"_magdown_"<<i;
      //cut to be presented on plot
      ostringstream label;
      label<<binlo<<" < "<<latexvar<<" < "<<binhi;
      results magup_result, magdown_result;
      if (fitmodel == Fitter::jpsi){
	magup_result   = fit_jpsi_mass(dsup_reduced   , s1.str(), label.str());
	magdown_result = fit_jpsi_mass(dsdown_reduced , s2.str(), label.str());
      }
      else if (fitmodel == Fitter::z0){
	magup_result   = fit_z0_mass(dsup_reduced   , s1.str(), label.str());
	magdown_result = fit_z0_mass(dsdown_reduced , s2.str(), label.str());
      }
      
      magup_hist  ->SetBinContent(i+1, magup_result.at(0).first     );
      magup_hist  ->SetBinError  (i+1, magup_result.at(0).second    );
      magdown_hist->SetBinContent(i+1, magdown_result.at(0).first  );
      magdown_hist->SetBinError  (i+1, magdown_result.at(0).second );
      
      magup_sigma  ->SetBinContent(i+1, magup_result.at(1).first     );
      magup_sigma  ->SetBinError  (i+1, magup_result.at(1).second    );
      magdown_sigma->SetBinContent(i+1, magdown_result.at(1).first  );
      magdown_sigma->SetBinError  (i+1, magdown_result.at(1).second );
      
      delete dsup_reduced;
      delete dsdown_reduced;
      
    }
    
    TCanvas* canv = new TCanvas( "canv", "canv", 800.0, 600.0 );
    magup_hist->SetXTitle(latexvar.c_str());
    magup_hist->SetYTitle("Fitted Z0 Mass");
    magdown_hist->SetLineColor(2);
    magdown_hist->SetMarkerColor(2);
    magdown_hist->SetMarkerStyle(20);
    magup_hist->Draw("e1");
    magdown_hist->Draw("e1same");
    canv->SaveAs(("mass_v_"+var+".pdf").c_str());
    canv->Delete();


    hists->Add(magup_hist);
    hists->Add(magdown_hist);
    hists->Add(magup_sigma);
    hists->Add(magdown_sigma);
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
    TH2F* magup_hist   = new TH2F(("mass_v_"+var1+"_"+var2+"_magup").c_str()   ,
				  ("mass_v_"+var1+"_"+var2+"_magup").c_str()   , bins1, lo1, hi1, bins2, lo2, hi2);
    TH2F* magdown_hist = new TH2F(("mass_v_"+var1+"_"+var2+"_magdown").c_str() ,
				  ("mass_v_"+var1+"_"+var2+"_magdown").c_str() , bins1, lo1, hi1, bins2, lo2, hi2);
    TH2F* magup_sigma   = new TH2F(("sigma_v_"+var1+"_"+var2+"_magup").c_str()   ,
				   ("sigma_v_"+var1+"_"+var2+"_magup").c_str()   , bins1, lo1, hi1, bins2, lo2, hi2);
    TH2F* magdown_sigma = new TH2F(("sigma_v_"+var1+"_"+var2+"_magdown").c_str() ,
				   ("sigma_v_"+var1+"_"+var2+"_magdown").c_str() , bins1, lo1, hi1, bins2, lo2, hi2);
    
    //calculate latex version of variable if possible
    string latexvar1;
    if (var1.find("ETA") != std::string::npos) latexvar1 = "#eta";
    else if (var1.find("PHI") != std::string::npos ) latexvar1 = "#phi";
    else latexvar1 = var1;
    string latexvar2;
    if (var2.find("ETA") != std::string::npos) latexvar2 = "#eta";
    else if (var2.find("PHI") != std::string::npos ) latexvar2 = "#phi";
    else latexvar2 = var1;
    
    for (int i = 0 ; i < bins1 ; ++i) {
      for (int j = 0 ; j < bins2 ; ++j) {
	ostringstream cut;
	double binlo1 = lo1 + i*((hi1 - lo1)/bins1);
	double binhi1 = lo1 + (i+1)*((hi1-lo1)/bins1);
	double binlo2 = lo2 + j*((hi2 - lo2)/bins2);
	double binhi2 = lo2 + (j+1)*((hi2-lo2)/bins2);
	cut  <<var1<<">"<<binlo1<<" && "<<var1<<"<"<<binhi1<<" && "<<var2<<">"<<binlo2<<" && "<<var2<<"<"<<binhi2;
	//add dataset with specific cuts
	RooDataSet* dsup_reduced = (RooDataSet*)dsUp->reduce(cut.str().c_str());
	RooDataSet* dsdown_reduced = (RooDataSet*)dsDown->reduce(cut.str().c_str());
	//make mass histogram
	ostringstream s1, s2;
	s1<<var1<<"_"<<var2<<"_magup_"<<i<<"_"<<j;
	s2<<var1<<"_"<<var2<<"_magdown_"<<i<<"_"<<j;
	//cut to be presented on plot
	ostringstream label;
	label<<binlo1<<" < "<<latexvar1<<" < "<<binhi1<<"\n"<<binlo2<<" < "<<latexvar2<<" < "<<binhi2;

	results magup_result, magdown_result;

	if (fitmodel == Fitter::jpsi){
	  magup_result   = fit_jpsi_mass(dsup_reduced   , s1.str(), label.str());
	  magdown_result = fit_jpsi_mass(dsdown_reduced , s2.str(), label.str());
	}
	else if (fitmodel == Fitter::z0){
	  magup_result   = fit_z0_mass(dsup_reduced   , s1.str(), label.str());
	  magdown_result = fit_z0_mass(dsdown_reduced , s2.str(), label.str());
	}
	magup_hist  ->SetBinContent(i+1, j+1, magup_result.at(0).first     );
	magup_hist  ->SetBinError  (i+1, j+1, magup_result.at(0).second    );
	magdown_hist->SetBinContent(i+1, j+1, magdown_result.at(0).first  );
	magdown_hist->SetBinError  (i+1, j+1, magdown_result.at(0).second );
	
	magup_sigma  ->SetBinContent(i+1, j+1, magup_result.at(1).first     );
	magup_sigma  ->SetBinError  (i+1, j+1, magup_result.at(1).second    );
	magdown_sigma->SetBinContent(i+1, j+1, magdown_result.at(1).first  );
	magdown_sigma->SetBinError  (i+1, j+1, magdown_result.at(1).second );
	
	delete dsup_reduced;
	delete dsdown_reduced;
      }
      
      hists->Add(magup_hist);
      hists->Add(magdown_hist);
      hists->Add(magup_sigma);
      hists->Add(magdown_sigma);
    }
  }
  return hists;
}
*/
TObjArray* Fitter::get_mass_v_vars(RooDataSet* ds, string label){
  //mass variable
  RooRealVar m( fitvar.c_str(), fitvar.c_str(), lo, hi);
  //other variables needed to make dataset
  
  TObjArray* objs = new TObjArray();
  
  if (vars.size() != los.size() || vars.size() != his.size() || vars.size() != bins.size()){
    cout<<"mismatch in 1d vars"<<endl;
    return objs;
  }
  if( vars2d.size() != los2d.size() || vars2d.size() != his2d.size() || vars2d.size() != bins2d.size()){
    cout<<"mismatch in 2d vars"<<endl;
    return objs;
  }

  //First fit total distributions
  ostringstream s1;
  if (label != "") s1<<label<<"_"<<fitvar<<"_tot";
  else s1<<fitvar<<"_tot";
  ostringstream label2;
  //label2<<"Total Fiducial";
  label2<<"";
  results result_tot;
  if (fitmodel == Fitter::jpsi){
    result_tot   = fit_jpsi_mass(ds   , s1.str(), label2.str());
  }
  else if (fitmodel == Fitter::bjpsik){
    result_tot   = fit_bjpsik_mass(ds   , s1.str(), label2.str());
  }
  else if (fitmodel == Fitter::bjpsikst){
    result_tot   = fit_bjpsik_mass(ds   , s1.str(), label2.str(), true);
  }
  else if (fitmodel == Fitter::bjpsik_polynomial){
    result_tot   = fit_bjpsik_mass_polynomial(ds   , s1.str(), label2.str());
  }
  else if (fitmodel == Fitter::bjpsikst_polynomial){
    result_tot   = fit_bjpsik_mass_polynomial(ds   , s1.str(), label2.str(), true);
  }
  else if (fitmodel == Fitter::bjpsik_novosibirsk){
    result_tot   = fit_bjpsik_mass_novosibirsk(ds   , s1.str(), label2.str());
  }
  else if (fitmodel == Fitter::bjpsikst_novosibirsk){
    result_tot   = fit_bjpsik_mass_novosibirsk(ds   , s1.str(), label2.str(), true);
  }
  else if (fitmodel == Fitter::z0){
    result_tot   = fit_z0_mass(ds   , s1.str(), label2.str());
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
    if (var.find("ETA") != std::string::npos) latexvar = "#eta";
    else if (var.find("PHI") != std::string::npos ) latexvar = "#phi";
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
	result   = fit_jpsi_mass(ds_reduced   , s9.str(), label3.str());
      }
      else if (fitmodel == Fitter::z0){
	result   = fit_z0_mass(ds_reduced   , s9.str(), label3.str());
      }
      else if (fitmodel == Fitter::bjpsik){
	result   = fit_bjpsik_mass(ds_reduced   , s9.str(), label3.str());
      }
      else if (fitmodel == Fitter::bjpsikst){
	result   = fit_bjpsik_mass(ds_reduced   , s9.str(), label3.str(), true);
      }
      else if (fitmodel == Fitter::bjpsik_polynomial){
	result   = fit_bjpsik_mass_polynomial(ds_reduced   , s9.str(), label3.str());
      }
      else if (fitmodel == Fitter::bjpsikst_polynomial){
	result   = fit_bjpsik_mass_polynomial(ds_reduced   , s9.str(), label3.str(), true);
      }
      else if (fitmodel == Fitter::bjpsik_novosibirsk){
	result   = fit_bjpsik_mass_novosibirsk(ds_reduced   , s9.str(), label3.str());
      }
      else if (fitmodel == Fitter::bjpsikst_novosibirsk){
	result   = fit_bjpsik_mass_novosibirsk(ds_reduced   , s9.str(), label3.str(), true);
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
	  result   = fit_jpsi_mass(ds_reduced   , s1.str(), label2.str());
	}
	else if (fitmodel == Fitter::z0){
	  result   = fit_z0_mass(ds_reduced   , s1.str(), label2.str());
	}
	else if (fitmodel == Fitter::bjpsik){
	  result   = fit_bjpsik_mass(ds_reduced   , s1.str(), label2.str());
	}
	else if (fitmodel == Fitter::bjpsikst){
	  result   = fit_bjpsik_mass(ds_reduced   , s1.str(), label2.str(), true);
	}
	else if (fitmodel == Fitter::bjpsik_polynomial){
	  result   = fit_bjpsik_mass_polynomial(ds_reduced   , s1.str(), label2.str());
	}
	else if (fitmodel == Fitter::bjpsikst_polynomial){
	  result   = fit_bjpsik_mass_polynomial(ds_reduced   , s1.str(), label2.str(), true);
	}
	else if (fitmodel == Fitter::bjpsik_novosibirsk){
	  result   = fit_bjpsik_mass_novosibirsk(ds_reduced   , s1.str(), label2.str());
	}
	else if (fitmodel == Fitter::bjpsikst_novosibirsk){
	  result   = fit_bjpsik_mass_novosibirsk(ds_reduced   , s1.str(), label2.str(), true);
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


TObjArray* Fitter::get_mass_v_vars(TTree* t){
  
  TCut cut("");
  
  //mass variable
  RooRealVar m( fitvar.c_str(), fitvar.c_str(),lo, hi );
  
  //other variables needed to make dataset
  RooRealVar pt1("muplus_PT"   , "muplus_PT"   , 0, 1000000);
  RooRealVar pt2("muminus_PT"  , "muminus_PT"  , 0, 1000000);
  RooRealVar eta1("muplus_ETA" , "muplus_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_ETA", "muminus_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_PHI" , "muplus_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_PHI", "muminus_PHI" , -TMath::Pi(), TMath::Pi());
  RooRealVar polarity("Polarity", "Polarity", -2, 2);
    
  TFile f("temp.root","RECREATE");
  TTree* upTree   = (TTree*)t->CopyTree("Polarity > 0");
  TTree* downTree = (TTree*)t->CopyTree("Polarity < 0");
  
  cout<<"Number of entries in trees: "<<t->GetEntries()<<" "<<upTree->GetEntries()<<" "<<downTree->GetEntries()<<endl;
  
  RooDataSet* dsUp  = new RooDataSet("dsUp", "dsUp", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*upTree), RooFit::Cut(cut.GetTitle()));
  RooDataSet* dsDwn = new RooDataSet("dsDwn", "dsDwn", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*downTree), RooFit::Cut(cut.GetTitle()));
  cout<<"Number of entries in datasets: "<<dsUp->sumEntries()<<" "<<dsDwn->sumEntries()<<endl;
  TObjArray* hists = get_mass_v_vars(dsUp);
  return hists;
  
}
TObjArray* Fitter::get_mass_v_vars(TTree* t, TTree* u){
  TCut cut("");
  //mass variable
  
  RooRealVar m( "J_psi_1S_M", "J_psi_1S_M", 3020.0, 3160. );
  //other variables needed to make dataset
  RooRealVar pt1("muplus_PT"   , "muplus_PT"   , 0, 1000000);
  RooRealVar pt2("muminus_PT"  , "muminus_PT"  , 0, 1000000);
  RooRealVar eta1("muplus_ETA" , "muplus_ETA"  , 2, 4.5);
  RooRealVar eta2("muminus_ETA", "muminus_ETA" , 2, 4.5);
  RooRealVar phi1("muplus_PHI" , "muplus_PHI"  , -TMath::Pi(), TMath::Pi());
  RooRealVar phi2("muminus_PHI", "muminus_PHI" , -TMath::Pi(), TMath::Pi());
  RooRealVar polarity("Polarity", "Polarity", -2, 2);
  
  RooDataSet* dsUp  = new RooDataSet("dsUp", "dsUp", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*t), RooFit::Cut(cut.GetTitle()));
  RooDataSet* dsDwn = new RooDataSet("dsDwn", "dsDwn", RooArgSet(m, pt1, pt2, eta1, eta2, phi1, phi2), RooFit::Import(*u), RooFit::Cut(cut.GetTitle()));
  cout<<"Number of entries in datasets: "<<dsUp->sumEntries()<<" "<<dsDwn->sumEntries()<<endl;
  TObjArray* hists = get_mass_v_vars(dsUp);
  return hists;
  
}


