# Poll the sft.cern.ch installation.
ls /cvmfs/sft.cern.ch
# Set path to GCC libraries.
#export LD_LIBRARY_PATH=/cvmfs/lhcb.cern.ch/lib/lcg/external/gcc/4.8.1/x86_64-slc6-gcc48-opt/lib:$LD_LIBRARY_PATH
#export LD_LIBRARY_PATH=/cvmfs/lhcb.cern.ch/lib/lcg/external/gcc/4.8.1/x86_64-slc6-gcc48-opt/lib64:$LD_LIBRARY_PATH
# Set path to ROOT libraries.
export LD_LIBRARY_PATH=/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.06.00-a82d7/x86_64-slc6-gcc48-opt/lib:$LD_LIBRARY_PATH
# Set path to LHAPDF.
export LD_LIBRARY_PATH=/cvmfs/sft.cern.ch/lcg/external/MCGenerators_lcgcmt67b/lhapdf6/6.1.4/x86_64-slc6-gcc48-opt/lib:$LD_LIBRARY_PATH
# Set path to fast jet
export LD_LIBRARY_PATH=/cvmfs/sft.cern.ch/lcg/external/fastjet/3.0.3/x86_64-slc6-gcc48-opt/lib/:$LD_LIBRARY_PATH
# Set path to pythia
export LD_LIBRARY_PATH=/cvmfs/sft.cern.ch/lcg/external/MCGenerators_lcgcmt67b/pythia8/205/x86_64-slc6-gcc48-opt/lib:$LD_LIBRARY_PATH
export LHAPATH=${PWD}/LHAPDF
# Set path to Pythia XML data.
export PYTHIA8DATA=/cvmfs/sft.cern.ch/lcg/external/MCGenerators_lcgcmt67b/pythia8/205/x86_64-slc6-gcc48-opt/share/Pythia8/xmldoc
if [ -e events.lhe.bz2 ]; then bunzip2 events.lhe.bz2; mv amcatnlo.cfg pythia.cfg; fi
if [ -e pwgevents.lhe.bz2 ];  then bunzip2 pwgevents.lhe.bz2; mv pwgevents.lhe events.lhe; mv powheg.cfg pythia.cfg; fi
./zmumuj pythia.cfg events.lhe pythia.root
