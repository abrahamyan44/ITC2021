#!/bin/bash

input="test_run/input.txt"
output="test_run/goutput.txt"

while IFS= read -r line1 && IFS= read -r line2 <&3
do
	a=$(./bin/gcd.out ${line1})
	b=${line2}
	
	if [ "$a" == "$b" ]
	then
		echo "Hey you're lucky. The test has passed."
	else
		echo "Oops! The test failed."
	fi

done < "$input" 3< "$output"
 


