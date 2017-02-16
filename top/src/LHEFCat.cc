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

  //LHEF::Reader reader(std::cin);
  //LHEF::Writer writer(std::cout);
  LHEF::Reader reader(input  );
  LHEF::Writer writer(output );
  // Copy header and init blocks and write them out.
  //  if ( reader.outsideBlock.length() ) std::cerr << reader.outsideBlock;
  writer.headerBlock() << reader.headerBlock<<"\ntesting this here now\n";
  writer.initComments() << reader.initComments;
  writer.heprup = reader.heprup;
  writer.init();
  long neve = 0;

  int i = 0;

  TH2F* hist = new TH2F("hist", "hist", 100, -5, 5, 100, -5, 5);

  // Read each event and write them out again.
  while ( reader.readEvent() && ( maxEvts == -1 || i < maxEvts) ) {
    ++neve;
    if ( reader.outsideBlock.length() ) std::cout << reader.outsideBlock;
    std::vector<long> ids = reader.hepeup.IDUP;
    std::vector< std::vector<double> > pup = reader.hepeup.PUP;
    int n = ids.size();

    double eta1 = -999.0;
    double eta2 = -999.0;

    for ( int i = 0 ; i < n ; ++i){
      std::pair<double, double> pteta = mom(pup.at(i));
      //if (abs(ids.at(i)) == 6)
      //std::cout<<ids.at(i)<<" "<<pteta.first<<" "<<pteta.second<<std::endl;
      if (ids.at(i) == 6) eta1 = pteta.second;
      if (ids.at(i) == -6 ) eta2 = pteta.second;
    }

      hist->Fill(eta1, eta2);
    //std::cout<<"--------------"<<std::endl;

    writer.eventComments() << reader.eventComments;
    writer.hepeup = reader.hepeup;
    writer.hepeup.heprup = &writer.heprup;
    writer.writeEvent();
    i++;
  }
  
  TCanvas c1;
  hist->Draw("colz");
  c1.Print("test.pdf");
  
  //  std::cerr << neve << " events were found." << std::endl;
}
