#include "LHEF.h"
#include <iomanip>
#include <TH2F.h>
#include <TCanvas.h>

std::pair<double, double> mom(std::vector<double> pup){
  double pt = sqrt(pup.at(0)*pup.at(0) + pup.at(1)*pup.at(1));
  double p  = sqrt(pt*pt + pup.at(2)*pup.at(2));
  double eta = 0.5 * log( (p + pup.at(2)) / ( p - pup.at(2) ));
  
  return std::pair<double, double>(pt, eta);
}

void flip(std::vector<double>& pup){
  pup.at(2) = - pup.at(2);
}

int main(int argc, char ** argv) {
  // Create Reader and Writer object
  std::string output = "";
  std::string input  = "";
  int maxEvts = -1;
  if (argc >= 3){
    input  = argv[1];
    output = argv[2];
  }
  else{
    std::cout<<"usage error"<<std::endl;
    return 0;
  }

  if (argc >= 4){
    maxEvts = atoi(argv[3]);
    std::cout<<"set max events to "<<maxEvts<<std::endl;
  }

  //std::iostream ios;
  std::stringstream ios;

  //LHEF::Reader reader(std::cin);
  //LHEF::Writer writer(std::cout);
  LHEF::Reader reader(input  );
  LHEF::Writer iwriter( ios );

  // Copy header and init blocks and write them out.
  //  if ( reader.outsideBlock.length() ) std::cerr << reader.outsideBlock;
  iwriter.headerBlock() << reader.outsideBlock;
  iwriter.headerBlock() << reader.headerBlock;
  iwriter.initComments() << reader.initComments;
  iwriter.heprup = reader.heprup;
  iwriter.init();
  long ntot = 0, npass = 0;

  while ( reader.readEvent() ) {
    std::vector<long>& ids = reader.hepeup.IDUP;
    std::vector<int>& status = reader.hepeup.ISTUP;
    std::vector<std::pair<int, int> >& mothers = reader.hepeup.MOTHUP;
    std::vector<std::pair<int, int> >& colours = reader.hepeup.ICOLUP;
    std::vector<double>& spins = reader.hepeup.SPINUP;
    std::vector<double>& lifetimes = reader.hepeup.VTIMUP;
    std::vector< std::vector<double> >& pup = reader.hepeup.PUP;
    int n = ids.size();

    double eta1 = -999.0;
    double eta2 = -999.0;
    double pt1  = 0.0;
    double pt2  = 0.0;

    bool pass = false;

    for ( int i = 0 ; i < n ; ++i){
      std::pair<double, double> pteta = mom(pup.at(i));
      if ( ids.at(i) == 11 || ids.at(i) == 13 ) {
	pt1  = pteta.first;
	eta1 = pteta.second;
      }
      if ( ids.at(i) == -11 || ids.at(i) == -13 ) {
	pt2  = pteta.first;
	eta2 = pteta.second;
      }
    }
    if (pt1 > 15 && pt2 > 15){
      if (eta1 > 1.0 && eta1 < 6.0 && eta2 > 1.0 && eta2 < 6.0) pass = true;
      if (eta1 < -1.0 && eta1 > -6.0 && eta2 < -1.0 && eta2 > -6.0){


	//one does not simply flip the z's in an event...
	for ( int i = 0 ; i < n ; ++i) {
	  flip(pup.at(i));
	}
	long id1 = ids.at(0);
	long id2 = ids.at(1);
	ids.at(0) = id2;
	ids.at(1) = id1;

	int status1 = status.at(0);
	int status2 = status.at(1);
	status.at(0) = status2;
	status.at(1) = status1;
	
	std::pair<int, int> mothers1 = mothers.at(0);
	std::pair<int, int> mothers2 = mothers.at(1);
	mothers.at(0) = mothers2;
	mothers.at(1) = mothers1;
	
	std::pair<int, int> colours1 = colours.at(0);
	std::pair<int, int> colours2 = colours.at(1);
	colours.at(0) = colours2;
	colours.at(1) = colours1;

	double spin1 = spins.at(0);
	double spin2 = spins.at(1);
	spins.at(0) = spin2;
	spins.at(1) = spin1;

	double lifetime1 = lifetimes.at(0);
	double lifetime2 = lifetimes.at(1);
	lifetimes.at(0) = lifetime2;
	lifetimes.at(1) = lifetime1;

	std::vector<double> pup1 = pup.at(0);
	std::vector<double> pup2 = pup.at(1);
	pup.at(0) = pup2;
	pup.at(1) = pup1;
	pass = true;
      }
    }
    ++ntot;
    if (pass) {
      ++npass;
      iwriter.eventComments() << reader.eventComments;
      iwriter.hepeup = reader.hepeup;
      iwriter.hepeup.heprup = &iwriter.heprup;
      iwriter.writeEvent();
    }
  }

  //rewind stream for input
  ios.seekg(0, std::ios::beg);

  LHEF::Reader ireader( ios  );
  LHEF::Writer writer(output );

  writer.headerBlock() << ireader.outsideBlock;
  writer.headerBlock() << ireader.headerBlock;
  writer.initComments() << ireader.initComments;
  writer.heprup = ireader.heprup;
  writer.init();
  
  while ( ireader.readEvent() ) {
    writer.eventComments() << ireader.eventComments;
    writer.hepeup = ireader.hepeup;
    double& weight = writer.hepeup.XWGTUP;
    weight = weight * 0.5 * double(npass)/ntot;
    std::vector<LHEF::Weight>& namedweights = writer.hepeup.namedweights;
    std::vector<std::pair<double, const LHEF::WeightInfo*> >& weights      = writer.hepeup.weights;
    for (auto& w : weights) w.first = w.first * 0.5 * double(npass) / ntot;
    for (auto& nw : namedweights){
      std::vector<double>& ws = nw.weights;
      for (unsigned int i = 0 ; i < ws.size(); ++i) ws.at(i) = ws.at(i) * 0.5 * double(npass) / ntot;
    }
    writer.hepeup.heprup = &writer.heprup;
    writer.writeEvent();
  }

  //TCanvas c1;
  //hist->Draw("colz");
  //c1.Print("test.pdf");
  
  std::cerr << "kept "<<npass<<" events out of "<<ntot<< std::endl;
}
