CXXFLAGS = -g -O0 -ansi -W -Wall -std=c++11 # -ftemplate-depth=3000
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
PYTHIA8 = /cvmfs/sft.cern.ch/lcg/external/MCGenerators_lcgcmt67b/pythia8/205/x86_64-slc6-gcc48-opt

all	: Fitter.o
clean	: ${RM} Fitter.o

%.so	: src/%.cpp
	g++ $(CXXFLAGS) -shared -fPIC $^ -DWITHPYTHON  -I$(PYTHIA8)/include -I$(BOOST_INC) -I$(ROOTSYS)/include -L$(ROOTSYS)/lib $(ROOTLIBS) -L$(BOOST_LIB) $(BOOSTLIBS) -L$(PYTHIA8)/lib -lpythia8 $(PYTHON_CPP_FLAGS) -o $@
%.o	: src/%.cpp
	g++ $(CXXFLAGS) -Isrc/ -I/usr/include -I$(ROOTSYS)/include -L$(ROOTSYS)/lib $(ROOTLIBS) $< -o $@
