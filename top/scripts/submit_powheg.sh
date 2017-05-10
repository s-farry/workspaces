j=0

NOW=`date +"%k%m"`
QUEUE=medium64
if [[ $NOW -gt 1800 || $NOW -lt 900 ]]; then QUEUE=all64; fi

for i in `ls $1/pwgevents*.lhe.bz2`
do
    if [ -e $i ]
    then
	output=$(basename $i)
	input=${output%.bz2}
	output=${output%.lhe.bz2}
	qsub -q $QUEUE -o /scratch/sfarry -e /scratch/sfarry -v input=${1}/${input},output=llj_${output}.root,alg=mumuj,cfg=powheg.cfg /user2/sfarry/workspaces/top/scripts/run_amcatnlo.sh
	j=$(($j+1))
    fi
done