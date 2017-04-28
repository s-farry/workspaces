#include "LHEF.h"
#include <iomanip>
#include <TH2F.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TTree.h>

std::pair<double, double> mom(std::vector<double> pup){
  double pt = sqrt(pup.at(0)*pup.at(0) + pup.at(1)*pup.at(1));
  double p  = sqrt(pt*pt + pup.at(2)*pup.at(2));
  double e  = pup.at(3);
  double rap = 0.5 * log( (e + pup.at(2)) / ( e - pup.at(2) ));
  
  return std::pair<double, double>(pt, rap);
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

  long ntot = 0;

  double pt1, pt2, rap1, rap2;
  std::map<std::string, double> weights;

  TTree* tree = new TTree("topTuple", "topTuple");
  tree->Branch("top_pt"      ,  &pt1  );
  tree->Branch("top_rap"     ,  &rap1 );
  tree->Branch("antitop_pt"  ,  &pt2  );
  tree->Branch("antitop_rap" ,  &rap2 );

  int i = 0;

  while ( reader.readEvent() ) {
    if (i%10000==0) std::cout<<"Entry "<<i<<std::endl;
    std::vector<long>& ids = reader.hepeup.IDUP;
    std::vector<int>& status = reader.hepeup.ISTUP;
    std::vector<std::pair<int, int> >& mothers = reader.hepeup.MOTHUP;
    std::vector<std::pair<int, int> >& colours = reader.hepeup.ICOLUP;
    std::vector< std::vector<double> >& pup = reader.hepeup.PUP;
    int n = ids.size();

    std::vector<LHEF::Weight>& namedweights = reader.hepeup.namedweights;
    for (auto& nw : namedweights){
      std::vector<double>& ws = nw.weights;
      if (ws.size() == 1){
	weights[nw.name] = nw.weights.at(0);
	if (i == 0 ) tree->Branch(nw.name.c_str(), &weights[nw.name]);
      }
      //for (unsigned int i = 0 ; i < ws.size(); ++i) ws.at(i) = ws.at(i) * 0.5 * double(npass) / ntot;
    }
    rap1 = -999.0;
    rap2 = -999.0;
    pt1  = -1.0;
    pt2  = -1.0;

    bool pass = false;

    for ( int i = 0 ; i < n ; ++i){
      std::pair<double, double> ptrap = mom(pup.at(i));
      if (ids.at(i) == 6 ) {
	pt1  = ptrap.first;
	rap1 = ptrap.second;
      }
      if (ids.at(i) == -6 ) {
	pt2  = ptrap.first;
	rap2 = ptrap.second;
      }
    }
    tree->Fill();
    ++i;
  }
  
  TFile outFile(output.c_str(), "RECREATE");
  tree->Write();
  outFile.Close();

}
