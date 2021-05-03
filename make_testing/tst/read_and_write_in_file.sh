#!/bin/bash

input="test_run/input.txt"
output="test_run/goutput.txt"

i=0
count=0

while IFS= read -r line1 && IFS= read -r line2 <&3
do
	a=$(./bin/gcd.out ${line1})
	b=${line2}
	(( i++ ))
	if [ "$a" == "$b" ]
	then
		tput setaf 2; echo "TEST "$i": OK"
		(( count++ ))
	else
		tput setaf 1; echo "TEST "$i": WRONG ANSWER"
	fi

done < "$input" 3< "$output"
tput setaf 3; echo $count "/" $i
