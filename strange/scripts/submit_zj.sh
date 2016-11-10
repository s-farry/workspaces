for i in $(seq 1 $1); do 
    qsub -q medium64 -o /scratch/sfarry -e /scratch/sfarry -v output=zmumuj_${i}.root,nevents=${2},seed=${RANDOM},alg=zmumuj,cfg=zmumuj_lhcbtune.cfg /user2/sfarry/workspaces/strange/scripts/run_pythia.sh
done