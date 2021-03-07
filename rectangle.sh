#!/bin/bash

height=$1
width=$2

SPACE=' ' # variable represents empty space in rect
VIS='#'   # variable for drawing visible border line

if  [[ -z "$height" || -z "$width" ]] ; then
    echo "WRONG INPUT: parameter(s) missing"
    exit 
fi

draw_line () {
    
    for (( i=0; $i < $1; i++ ))
    do
        echo -n "$VIS"
    done
    echo 
}

draw_empty_line () {
    
    echo -n "$VIS"
    for (( j=2; $j < $1; j++ ))
    do
        echo -n "$SPACE"
    done
    echo "$VIS"
}

draw_rect () {
    for (( h=0; $h < $height; h++ ))
    {
        if (($h == 0 || $h == ($height - 1) )); then
            draw_line $width
        else
            draw_empty_line $width
        fi
    }
}

main () {
    draw_rect
}

main
