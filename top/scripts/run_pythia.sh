source /cvmfs/lhcb.cern.ch/lib/LbLogin.sh
export ROOTSYS=/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.06.00-a82d7/x86_64-slc6-gcc48-opt
source $ROOTSYS/bin/thisroot.sh
/user2/sfarry/workspaces/strange/${alg} /user2/sfarry/workspaces/strange/cfg/${cfg} /user2/sfarry/workspaces/strange/tuples/${output} ${nevents} ${seed}