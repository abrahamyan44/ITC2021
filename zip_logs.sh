#!/bin/bash

# NOTE: script compresses not only files with ".log" ending, but also ".log.(number)"

main ()
    {
    cd /var/log  

    ls -a /var/log | grep -E '.*\.log\.?[1-9]?$' | tar cvf ~/logs.tar  -T -; 

    bzip2 ~/logs.tar 

    cd -
}

main 
