#!/bin/bash

# Prints odd numbers from 0 to 99

print_odds () {
    i=1

    while (( $i < 100 ));
    do
        echo "${i}"
        (( i += 2 ))
    done
}

main ()
{
    print_odds
}

main


