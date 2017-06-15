#include "Pythia8/Pythia.h"
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

class Decayer{
public:
  Decayer(string name);
  Decayer(const Decayer&);
  Pythia8::Pythia pythia;
  std::string m_name;
  Pythia8::Vec4 gamma(double px, double py, double pz, double m);
  boost::python::list gamma_py(double px, double py, double pz, double m);
};

Decayer::Decayer(string name) : pythia("", false) {
  m_name = name;
  pythia.readString("ProcessLevel:all = off");
  pythia.readString("Print:quiet = on");
  pythia.readString("221:oneChannel = 1 0.00031 11 22 13 -13");
  pythia.init();
}
Decayer::Decayer(const Decayer&) : pythia("", false) {
  pythia.readString("ProcessLevel:all = off");
  pythia.readString("Print:quiet = on");
  pythia.readString("221:oneChannel = 1 0.00031 11 22 13 -13");
  pythia.init();
}
// Perform the decay.
Pythia8::Vec4 Decayer::gamma(double px, double py, double pz, double m) {
  //while (true) {
    pythia.event.reset();
    pythia.event.append(221, 1, 0, 0, px, py, pz,
			sqrt(px*px + py*py + pz*pz + m*m), m);
    //std::cout<<px<<" "<<py<<" "<<pz<<" "<<m<<std::endl;
    if (pythia.next()){
      for (int prt = 0; prt < (int)pythia.event.size(); ++prt)
	if (pythia.event[prt].id() == 22) return pythia.event[prt].p();
    }
    else {
      cout<<"error in event generation"<<endl;
      return Pythia8::Vec4(0,0,0,0);
    }
    //}
  return Pythia8::Vec4(0,0,0,0);
   
}
boost::python::list Decayer::gamma_py(double px, double py, double pz, double m){
  Pythia8::Vec4 g = gamma(px,py,pz,m);
  boost::python::list ns;
  ns.append(g.px());
  ns.append(g.py());
  ns.append(g.pz());
  ns.append(g.e());
  return ns;
}


BOOST_PYTHON_MODULE(eta_decay)
{
  
    using namespace boost::python;
    //Add some vectors
    class_<Decayer>("Decayer", init<std::string>())
      .def("gamma",       &Decayer::gamma_py)
      ;
  
};


