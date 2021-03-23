#!/bin/bash

#touch final_file.txt
g++ src/gcd.cpp -o gcd.out

input="test_run/input.txt"
output="test_run/goutput.txt"

i=0

while IFS= read -r line1 && IFS= read -r line2 <&3
do
	a=$(./gcd.out ${line1})
	b=${line2}
	(( i++ ))
	if [ "$a" == "$b" ]
	then
		tput setaf 2; echo "TEST "$i" : OK"
	else
		tput setaf 1; echo "TEST "$i" : WRONG ANSWER"
	fi

done < "$input" 3< "$output"
 


