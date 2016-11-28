// Stdlib header file for input and output.
#include <iostream>
#include <iomanip>
#include <iostream>
#include <sstream>

// Math libraries
#include <math.h>

// ROOT, for histogramming.
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TChain.h"

// ROOT, for interactive graphics.
#include "TVirtualPad.h"
#include "TApplication.h"

// ROOT, for saving file.
#include "TFile.h"

using namespace std;


int main(){

	TFile* outFile = new TFile("Zjet_LHC13_NLOPS.root", "RECREATE");

	//Where is my root file? I'll add a-g ntuples here
	TChain ch("/Users/rhorry/Programs/RootFiles/Zjet_events_LHC13_NN30.root");
	ch.Add("/Users/rhorry/Programs/RootFiles/Zjet_events_LHC13_NN30.root/ntuplepwhg");
 
	//Find total number of entries in ntuple - allows me to run over all events
	long nEntries = ch.GetEntries(); 

	cout << " Number of entries " << nEntries << endl;

	//W Quark parameters(before decay)
	Float_t Zpx, Zpy, Zpz, Ze;
	//Set address of parameters to that in the tree
	ch.SetBranchAddress("Zpx",&Zpx);
	ch.SetBranchAddress("Zpy",&Zpy);
	ch.SetBranchAddress("Zpz",&Zpz);
	ch.SetBranchAddress("Ze",&Ze);

	//Muon
	Float_t Muonpx, Muonpy, Muonpz, Muone, Muoneta, Muony, Muonphi, Muonpt;
	//Set address of parameters to that in the tree
	ch.SetBranchAddress("Muonpx",&Muonpx);
	ch.SetBranchAddress("Muonpy",&Muonpy);
	ch.SetBranchAddress("Muonpz",&Muonpz);
	ch.SetBranchAddress("Muone",&Muone);
	ch.SetBranchAddress("Muoneta",&Muoneta);
	ch.SetBranchAddress("Muony",&Muony);
	ch.SetBranchAddress("Muonphi",&Muonphi);
	ch.SetBranchAddress("Muonpt",&Muonpt);

	//Anti-Muon parameters
	Float_t AMuonpx, AMuonpy, AMuonpz, AMuone, AMuoneta, AMuony, AMuonphi, AMuonpt;
	//Set address of parameters to that in the tree
	ch.SetBranchAddress("AMuonpx",&AMuonpx);
	ch.SetBranchAddress("AMuonpy",&AMuonpy);
	ch.SetBranchAddress("AMuonpz",&AMuonpz);
	ch.SetBranchAddress("AMuone",&AMuone);
	ch.SetBranchAddress("AMuoneta",&AMuoneta);
	ch.SetBranchAddress("AMuony",&AMuony);
	ch.SetBranchAddress("AMuonphi",&AMuonphi);
	ch.SetBranchAddress("AMuonpt",&AMuonpt);

	//Jet 0-4
	//jet  parameters
	Float_t jete[5], jeteta[5], jety[5], jetphi[5], jetpt[5], jetpx[5], jetpy[5], jetpz[5];
	for(int ii = 0; ii < 5; ++ii){
		//
		ostringstream string;
		string << ii;
		TString num=string.str();
		ch.SetBranchAddress("jet"+num+"e",&jete[ii]);
		ch.SetBranchAddress("jet"+num+"eta",&jeteta[ii]);
		ch.SetBranchAddress("jet"+num+"y",&jety[ii]);
		ch.SetBranchAddress("jet"+num+"phi",&jetphi[ii]);
		ch.SetBranchAddress("jet"+num+"pt",&jetpt[ii]);
		//
		ch.SetBranchAddress("jet"+num+"px",&jetpx[ii]);
		ch.SetBranchAddress("jet"+num+"py",&jetpy[ii]);
		ch.SetBranchAddress("jet"+num+"pz",&jetpz[ii]);  
	}

	Float_t Type, Q2, x1, x2, flav;
	ch.SetBranchAddress("Type",&Type);
	ch.SetBranchAddress("Q2",&Q2);
	ch.SetBranchAddress("x1",&x1);
	ch.SetBranchAddress("x2",&x2);
	ch.SetBranchAddress("flav",&flav);

	//Now do the PDF weights
	Float_t PDFS[101];
	for ( unsigned int l = 1; l <= 100; ++l ){
		ostringstream string;
		string << "PDF" << l;
		ch.SetBranchAddress(string.str().c_str(),&PDFS[l]);
	}

	//Scales
	Float_t Scales[7];
	ch.SetBranchAddress("S11",&Scales[0]);
	ch.SetBranchAddress("S01",&Scales[1]);
	ch.SetBranchAddress("S10",&Scales[2]);
	ch.SetBranchAddress("S12",&Scales[3]);
	ch.SetBranchAddress("S21",&Scales[4]);
	ch.SetBranchAddress("S22",&Scales[5]);
	//ch.SetBranchAddress("S00",&Scales[6]);
	//ch.SetBranchAddress("S02",&Scales[7]);
	//ch.SetBranchAddress("S20",&Scales[8]);

	//PDFs
	int nPDFs = 100;
	TH1F* PDFZpt[nPDFs];
	for( int ij = 0; ij <= nPDFs; ij++){
	  ostringstream string;
	  string << ij;
	  TString num=string.str();
  
	  TString histoname="PDF"+num;
	  PDFZpt[ij] = new TH1F(histoname,histoname,30,2.0,5.0);
	}

	//Some variables
	int count = 0;
	double central = 0.0;

	// Now a for loop to sum over all the individual events. This gives acess to all information per event
	for(long iEntry=0; iEntry< nEntries; iEntry++) {//nEntries

		ch.GetEntry(iEntry);
		//Do Z+jets analysis
		//Lepton analysis
		central += Scales[0];
		count += 1;
	
	}//Close ntuple loop
	
		//Now print out final results and save graphs

	cout << "Num = " << nEntries << endl;

	//Central value
	double Sigma = 1.169e+03;// pb
	//Normalise
	double fac = Sigma/central;

	cout << fac << endl;
	cout << count*fac << endl;
	outFile->cd();

	/*
	for(int j=1; j<=nPDFs; ++j){
		  //write the plots
		  PDFZpt[j]->Scale( 1.0/nEntries );
		  PDFZpt[j]->Write();
	}
	*/
 
	outFile->Close();
	delete outFile;

	return 0;  
}
