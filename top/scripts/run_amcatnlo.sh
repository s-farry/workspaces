source /cvmfs/lhcb.cern.ch/lib/LbLogin.sh
source /cvmfs/sft.cern.ch/lcg/releases/gcc/4.9.3/x86_64-slc6-gcc49-opt/setup.sh
export ROOTSYS=/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.06.00-a82d7/x86_64-slc6-gcc48-opt
source $ROOTSYS/bin/thisroot.sh
#if [ -e ${input}.gz ]; then gunzip ${input}.gz; fi;
if [ -e ${input}.bz2 ]; then
    echo f=/scratch/sfarry/$(basename ${input%/*})_$(basename $input).lhe
    echo cp ${input}.bz2 ${f}.bz2
    echo bunzip2 ${f}.bz2
    echo /user2/sfarry/workspaces/top/${alg} /user2/sfarry/workspaces/top/cfg/${cfg} ${f} ${input%/*}/${output}
    echo rm ${f}
    f=/scratch/sfarry/$(basename ${input%/*})_$(basename $input).lhe
    cp ${input}.bz2 ${f}.bz2
    bunzip2 ${f}.bz2
    /user2/sfarry/workspaces/top/${alg} /user2/sfarry/workspaces/top/cfg/${cfg} ${f} ${input%/*}/${output}
    rm ${f}
fi