#!/bin/bash

# Incapsulating target file in variable
target="/etc"


# Assigning "ls -a /etc" command's output to a variable
lsOutput=$(ls -a $target)


main() {

# Count initialized with -2, because every directory contains .(itself) and ..(its parent) directory by default
count=-2

for i in $lsOutput
do
    (( count+=1 ))
done

echo $count
}

main
