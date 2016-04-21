#!/bin/bash
# This is used to get the iteration times, when the system remaining in the final stage.
for((i=1;i<=3;i=i+1))
do

for((j=1;j<=10;j=j+1))
do

file="result_tmp/Simulated_Path_"$i"_"$j".txt"
m=$(tail -3 $file|head -n1)
len=$(wc -l $file|awk -F' ' '{print $1}')
str="tac \$file|awk 'BEGIN{i=0;} {if(\$0~/"$m"/){i=i+1;} else if(i>0){print i;exit;} }'"
echo "scale=5;"$(eval $str)" / "$len|bc
#eval $str
done
done
