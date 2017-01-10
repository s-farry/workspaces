CXXFLAGS = -O0 -ansi -W -Wall -g -std=c++11
PYTHON_VERSION = 2.7
PYTHON_INCLUDE = $(PYTHONHOME)/include/python$(PYTHON_VERSION)
BOOST_INC = /cvmfs/sft.cern.ch/lcg/external/Boost/1.53.0_python2.7/x86_64-slc6-gcc48-opt/include
BOOST_LIB = /cvmfs/sft.cern.ch/lcg/external/Boost/1.53.0_python2.7/x86_64-slc6-gcc48-opt/lib
BOOSTLIBS = -lboost_python

PYTHON_LIB = $(PYTHONHOME)/lib/
PYTHIA8 = /cvmfs/sft.cern.ch/lcg/external/MCGenerators_lcgcmt67b/pythia8/205/x86_64-slc6-gcc48-opt
FASTJET = /cvmfs/sft.cern.ch/lcg/external/fastjet/3.0.3/x86_64-slc6-gcc48-opt

ROOTLIBS = -lRIO -lNet -lHist -lTree -lMatrix -lMathCore -lThread -lPhysics -lPyROOT -lMinuit -lMinuit2 -lGpad # root libraries
FASTJETLIBS = -lfastjet -lfastjettools
PYTHON_CPP_FLAGS   = -I/cvmfs/lhcb.cern.ch/lib/lcg/releases/LCG_79/Python/2.7.9.p1/x86_64-slc6-gcc48-opt/include/python2.7
# Define make targets.
all           : muej mumuj tuneipchi2
clean         : rm muej mumuj

%	: src/%.cc
	g++ $(CXXFLAGS) -I./ -I/user2/sfarry/Generators/include -I/user2/sfarry/Generators/fastjet-3.0.3/install_dir/include \
	-I$(ROOTSYS)/include $< -o $@  -L$(PYTHIA8)/lib -lpythia8 -L$(FASTJET)/lib $(FASTJETLIBS) -L$(ROOTSYS)/lib $(ROOTLIBS)
%	: src/%.cxx
	g++ $(CXXFLAGS) -I./ -I/usr/include  -I$(ROOTSYS)/include -I/user2/sfarry/Jawa/include $(PYTHON_CPP_FLAGS) -I$(BOOST_INC) $< -o $@ -L$(HOME)/Jawa/lib -lJawa -L$(BOOST_LIB) $(BOOSTLIBS)