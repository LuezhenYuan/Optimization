#!/bin/bash
# This file used to run the Simulated_Annealing.out many times and save the file to ../result_tmp
i=1
j=1
p=0.999
mkdir result_tmp

for((i=1;i<=3;i=i+1))
do

for((j=1;j<=10;j=j+1))
do
file="result_tmp/Simulated_Path_"$i"_"$j".txt"
echo "1e-25 "$p" "$file
echo "1e-25 "$p" "$file|./Simulated_Annealing_TSP.out

done

p=$p"9"

done

i=4
for((j=1;j<=10;j=j+1))
do
echo "1e-25 "$p" null"
echo "1e-25 "$p" null"|./Simulated_Annealing_TSP.out
done

