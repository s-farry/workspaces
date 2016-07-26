CXXFLAGS = -O0 -ansi -W -Wall -g -std=c++11
PYTHON_VERSION = 2.7
PYTHON_INCLUDE = $(PYTHONHOME)/include/python$(PYTHON_VERSION)
BOOST_ROOT=/user2/sfarry/Generators/boost_1_56_0
PYTHON_LIB = $(PYTHONHOME)/lib/
PYTHIA8 = /cvmfs/sft.cern.ch/lcg/external/MCGenerators_lcgcmt67b/pythia8/205/x86_64-slc6-gcc48-opt
FASTJET = /cvmfs/sft.cern.ch/lcg/external/fastjet/3.0.3/x86_64-slc6-gcc48-opt

ROOTLIBS = -lCore -lRIO -lNet -lHist  -lTree -lMatrix -lMathCore -lThread -lPhysics -lTMVA
FASTJETLIBS = -lfastjet -lfastjettools
# Define make targets.
all           : zmumuj
clean         : rm zmumuj

zmumuj	: src/zmumuj.cc
	g++ $(CXXFLAGS) -I./ -I/user2/sfarry/Generators/include -I/user2/sfarry/Generators/fastjet-3.0.3/install_dir/include \
	-I$(ROOTSYS)/include $< -o $@  -L$(PYTHIA8)/lib -lpythia8 -L$(FASTJET)/lib $(FASTJETLIBS) -L$(ROOTSYS)/lib $(ROOTLIBS)