CXXFLAGS = -g -O0 -ansi -W -Wall -std=c++11
ROOTLIBS = -lCore -lRIO -lNet -lHist -lTree -lMatrix -lMathCore -lThread -lPhysics -lPyROOT -lMinuit -lMinuit2 
PYTHON_VERSION = 2.7
PYTHON_INCLUDE = $(PYTHONHOME)/include/python$(PYTHON_VERSION)
PYTHON_LIB = $(PYTHONHOME)/lib/
PYTHIA8 = /user2/sfarry/Generators

BOOST_INC = /usr/local/include
BOOST_LIB = /usr/local/lib
BOOSTLIBS = -lboost_python-mt
PYTHONLIBS = -lpython$(PYTHON_VERSION)

all	: fit_wmupj fit_wmumj dif add_jecerr_vars unfold
clean	: rm fit_roofit

fit_wmupj	: src/fit_wmupj.cxx
	g++ $(CXXFLAGS) -Isrc/ -I/usr/include -I$(ROOTSYS)/include $< -o $@ -L$(ROOTSYS)/lib $(ROOTLIBS) -lTMVA -lRooFit
fit_wmumj	: src/fit_wmumj.cxx
	g++ $(CXXFLAGS) -Isrc/ -I/usr/include -I$(ROOTSYS)/include $< -o $@ -L$(ROOTSYS)/lib $(ROOTLIBS) -lTMVA -lRooFit
dif	: src/EmbedDIF.cpp
	g++ $(CXXFLAGS) -Isrc/ -I/usr/include -I$(ROOTSYS)/include $< -o $@ -L$(ROOTSYS)/lib $(ROOTLIBS)
add_jecerr_vars	: src/add_jecerr_vars.cxx
	g++ $(CXXFLAGS) -Isrc/ -I/usr/include -I$(ROOTSYS)/include $< -o $@ -L$(ROOTSYS)/lib $(ROOTLIBS)
unfold : root/unfold.C
	g++ $(CXXFLAGS) -Isrc -I/usr/include -I/user2/sfarry/Jawa/include -I$(ROOTSYS)/include -I/user2/sfarry/WJet/RooUnfold/src $< -o $@ -L$(ROOTSYS)/lib $(ROOTLIBS) -L/user2/sfarry/Jawa/lib -lJawa -L/user2/sfarry/WJet/RooUnfold -lRooUnfold
