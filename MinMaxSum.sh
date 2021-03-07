#!/bin/bash

# USAGE: bash homework [MODE] [INTEGER ARGUMENTS]

# The script gets parameters from command line
# The first parameter should be the name of the mode you want to run the script

# Mode "min"("max") prints the minimal(maximal) value from the array of integers passed by command line
# Mode "sum" calculate the sum of parameters 

# Saving the first argument from command line in variable mode 
mode=$1

# Saving integer arguments in inputArray by slicing the initial input
inputArray=${@:2}

# Function prints the minimal number from passed arguments 
min () {
    
    minValue=$1

    for i in "$@"
    do
        if (( $minValue > $i )); then
            minValue=$i
        fi
    done

    echo $minValue
}


# Function prints the maximal number from passed arguments 
max () {

    maxValue=$1

    for i in "$@"
    do
        if (( $i > $maxValue )); then
            maxValue=$i
        fi
    done

    echo $maxValue
}

# Function calculates and prints sum of passed arguments
sum () {   

    acc=0

    for i in "$@"
    do
        (( acc+=$i ))
    done

    echo $acc
}

# Case block checks cases and runs corresponding function or types error message in case of wrong input
case $mode in 
    
    sum) sum $inputArray;; 

    min) min $inputArray;; 
    
    max) max $inputArray;;  

    *)   echo "WRONG INPUT: The first item of the input should be the name of the function you want to run(sum, min or max)";;

esac
