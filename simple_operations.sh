#!/bin/bash
read -ra nums
case $1 in
	min)	
	    min1=${nums[0]}
	    for i in "${nums[@]}"
            do
		    if (( i < min1 ))
	            then 
			    min1=$i
	            fi
            done
	    echo "The minimum is $min1"
		;;
	max) 
	    max=${nums[0]}
	    for i in "${nums[@]}"
            do
		   if (( i > max ))
	           then
			   max=$i
	           fi
            done
	    echo "The maximum is $max"
		;;
	sum) 
	    sum=0
	    for i in "${nums[@]}"
            do 
		    (( sum+=i ))
            done
	    echo "The sum is $sum"
	    ;;
esac
