j=0
for i in `ls -d $1/Events/*`
do
    if [ -e ${i}/events.lhe.gz ]
    then
	qsub -q medium64 -o /scratch/sfarry -e /scratch/sfarry -v input=${i}/events.lhe,output=zmumuj_amcatnlo_${j}.root /user2/sfarry/workspaces/strange/scripts/run_amcatnlo.sh
	j=$(($j+1))
    fi
done