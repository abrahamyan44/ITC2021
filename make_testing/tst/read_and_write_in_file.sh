#!/bin/bash

g++ src/gcd.cpp -o bin/gcd.out

input="test_run/input.txt"
output="test_run/goutput.txt"

while IFS= read -r line1 && IFS= read -r line2 <&3
do
	a=$(./gcd.out ${line1})
	b=${line2}
	
	if [ "$a" == "$b" ]
	then
		echo "You're lucky."
	else
		echo "Oops!"
	fi

done < "$input" 3< "$output"
 


