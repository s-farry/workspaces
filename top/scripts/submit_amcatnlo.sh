j=0

NOW=`date +"%k%m"`
QUEUE=medium64
if [[ $NOW -gt 1800 || $NOW -lt 900 ]]; then QUEUE=all64; fi

for i in `ls -d $1/Events/*`
do
    if [ -e ${i}/events.lhe.gz ]
    then
	qsub -q $QUEUE -o /scratch/sfarry -e /scratch/sfarry -v input=${i}/events.lhe,output=mue_$(basename $1)_amcatnlo_${j}.root,alg=muej,cfg=amcatnlo.cfg /user2/sfarry/workspaces/top/scripts/run_amcatnlo.sh
	j=$(($j+1))
    fi
done