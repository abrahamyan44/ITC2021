#!/bin/bash

# Bash script draws nxn square in your terminal window
# The length of the square's side prompted from user
# In case of redirecting output, the promt message will apear in file
# NOT in terminal!

# Draws horizontal line like this-'****'
draw_line () {

    for ((i=0; i < $1; i++)); do
        echo -n "*"
    done
 
    echo
}

# Draws horizontal line like this-'*  *'
draw_empty_line () {
    
    SPACE=' '
    echo -n "*"

    for ((i=0; i < $1-2; i++)); do
        echo -n "${SPACE}" 
    done

    echo  "*"
}

# Calls draw_line(2 times) and draw_empty_line(n-2 times) functions to draw square
draw_square () {
   
    draw_line $1

    for (( j=0; j<$1-2; j++ )); do
        draw_empty_line $1  
    done
    
   draw_line $1
}

#FIXME: MAIN function must check input value!!!
# Main functions prompts the size of square
# and calls draw_square passing inputed value as an argument 
main () {

    echo "Please, enter the length of your square side"
    read len

    draw_square ${len}
}

main





