for i in $(seq 1 $1); do 
    qsub -q medium64 -o /scratch/sfarry -e /scratch/sfarry -v output=zmumuj_${i}.root,nevents=${2},seed=${RANDOM} /user2/sfarry/workspaces/strange/scripts/run_zj.sh
done