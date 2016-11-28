source /cvmfs/lhcb.cern.ch/lib/LbLogin.sh
export ROOTSYS=/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.06.00-a82d7/x86_64-slc6-gcc48-opt
source $ROOTSYS/bin/thisroot.sh
if [ -e ${input}.gz ]; then gunzip ${input}.gz; fi;
if [ -e ${input}.bz2 ]; then bunzip2 ${input}.bz2; fi;
/user2/sfarry/workspaces/top/${alg} /user2/sfarry/workspaces/top/cfg/${cfg} ${input} ${nevents} /user2/sfarry/workspaces/top/tuples/${output}
bzip2 ${input}