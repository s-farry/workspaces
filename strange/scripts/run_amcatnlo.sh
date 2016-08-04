source /cvmfs/lhcb.cern.ch/lib/LbLogin.sh
export ROOTSYS=/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.06.00-a82d7/x86_64-slc6-gcc48-opt
source $ROOTSYS/bin/thisroot.sh
gunzip ${input}.gz
/user2/sfarry/workspaces/strange/zmumuj /user2/sfarry/workspaces/strange/cfg/amcatnlo.cfg ${input} ${nevents} /user2/sfarry/workspaces/strange/tuples/${output}
gzip ${input}