j=0

NOW=`date +"%k%m"`
QUEUE=medium64
MAXJOBS=-1

#if [ $NOW -gt 1800 ] or [ $NOW -lt 900 ]; then QUEUE=all64; fi

for i in `ls -d $1/Events/*`
do
    if [[ -e ${i}/events.lhe.gz ]]  || [[ -e ${i}/events.lhe.bz2 ]]
    then
	qsub -q $QUEUE -o /scratch/sfarry -e /scratch/sfarry -v input=${i}/events.lhe,output=mumuj_$(basename $1)_amcatnlo_${j}.root,alg=mumuj,cfg=amcatnlo.cfg /user2/sfarry/workspaces/top/scripts/run_amcatnlo.sh
	j=$(($j+1))
    fi
done