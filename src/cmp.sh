#!/bin/bash

f1="/home/aro_a7/Desktop/GCD/tst.run/result.txt"
f2="/home/aro_a7/Desktop/GCD/tst.run/output.txt"
a=0
b=0
count_f=0
count_p=0

count=1
while read lineA
    do  
        lineB=`sed -n "$count"p $f1`
        count=`expr $count + 1`
    if ((lineA == lineB)); then
	((count_p++))
    else
	((count_f++))    
    fi
done < $f2

echo "PASSED : $count_p"
echo "FAILED : $count_f" 
