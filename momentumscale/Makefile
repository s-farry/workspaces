CXXFLAGS = -g -O0 -ansi -W -Wall -std=c++11 -ftemplate-depth=3000
ROOTLIBS = -lCore -lRIO -lNet -lHist -lTree -lMatrix -lThread -lMathCore -lPhysics -lPyROOT -lMinuit -lMinuit2 -lRooFit -lGpad
ROOUNFOLDLIBS = -lRooUnfold
PYTHON_VERSION = 2.7

#boost                                                                                                                                                 
BOOST_INC = /cvmfs/sft.cern.ch/lcg/external/Boost/1.53.0_python2.7/x86_64-slc6-gcc48-opt/include
BOOST_LIB = /cvmfs/sft.cern.ch/lcg/external/Boost/1.53.0_python2.7/x86_64-slc6-gcc48-opt//lib
BOOSTLIBS = -lboost_python

RM = rm -f # rm command                                                                                                                                
ROOTLIBDIR = /afs/cern.ch/sw/lcg/app/releases/ROOT/6.04.00/x86_64-slc6-gcc48-opt/root/lib
ROOTINCDIR = /afs/cern.ch/sw/lcg/app/releases/ROOT/6.04.00/x86_64-slc6-gcc48-opt/root/include
PYTHON_CPP_FLAGS = -I/cvmfs/lhcb.cern.ch/lib/lcg/releases/LCG_79/Python/2.7.9.p1/x86_64-slc6-gcc48-opt/include/python2.7
ROOUNFOLDSYS = /user2/kdreimanis/workspace/RooUnfold-master/RooUnfold-master

all	: Wouter_modified.o curvbias.o fitZ0.o fitJpsi.o fitZ0truth.o fitBjpsiK.o Fitter.so calibration get_mc_expectation My_double_CB.so
clean	: ${RM} Wouter_modified.o

bin/%.so	: src/%.cpp
	g++ $(CXXFLAGS) -shared -fPIC $^ -DWITHPYTHON  -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -I$(ROOTSYS)/include -L$(ROOTSYS)/lib $(ROOTLIBS) -L$(BOOST_LIB) $(BOOSTLIBS) $(PYTHON_CPP_FLAGS) -o $@
bin/%.o	: src/%.cpp
	g++ $(CXXFLAGS) -Isrc/ -I/usr/include -I$(ROOTSYS)/include -I$(ROOUNFOLDSYS)/src -L$(ROOTSYS)/lib $(ROOTLIBS) -l:Fitter.so -L. -lDoubleCB $< -o $@
bin/%	: src/%.cpp
	g++ $(CXXFLAGS) -Isrc/ -I/usr/include -I$(ROOTSYS)/include -I$(ROOUNFOLDSYS)/src -L$(ROOTSYS)/lib $(ROOTLIBS) $< -o $@
libDoubleCB.so	: src/DictOutput.cxx src/My_double_CB.cxx
	g++ $(CXXFLAGS) -shared -fPIC $^ -DWITHPYTHON  -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -I$(ROOTSYS)/include -L$(ROOTSYS)/lib $(ROOTLIBS) -L$(BOOST_LIB) $(BOOSTLIBS) $(PYTHON_CPP_FLAGS) -o $@
