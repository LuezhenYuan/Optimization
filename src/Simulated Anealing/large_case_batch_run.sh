#!/bin/bash
# This file used to run the Simulated_Annealing.out
p=0.999999
for((i=4;i<=4;i=i+1))
do

for((j=1;j<=10;j=j+1))
do
echo "1e-25 "$p" null"
echo "1e-25 "$p" null"|./Simulated_Annealing.out
done
p=$p"9"

done
