#!/bin/bash

# This script allows to create files in specified directory and redirect 
# generated errors in logs/error file. 
# Script has some bugs with catching errors, when user inputs .. or . as a filename he wants to create 


DIR="",  

create_log_files () {

    [ ! -d $HOME/logs  ] && mkdir $HOME/logs 
    touch $HOME/logs/errors $HOME/logs/errors_count

    clean_errors_file   # cleans error file in case it already exists

}

prompt_dir_name () {

    read -p "Please enter directory absolute path name(in your home directory) you want to create: " DIR 

    while ! [[ "$DIR" =~ ^$HOME/[-_[:alnum:]] ]]
    do
        read -p "Please enter valid absolute path(in your home directory): " DIR 
    done
    
    echo "Great, it seems you understand absolute path !"

}

imake_files () {

        read -p "Would you like to create new files in specified directory ?: " RESPONSE
        while true        
        do
            if [[ $RESPONSE =~ ^[y,Y].* ]]; then
                create_files                
            break;

            elif  [[ $RESPONSE =~ ^[n,N]+$ ]]; then
                echo "Ok, i will not create any file"
            break;

            else
                read -p "It seems you did not choose a valid option [Y/n] " RESPONSE 
               
            fi
        done
}

create_files () {

    echo "Lets create files ..."
    
    read -p "Please provide relative file names separated with spaces: " FILE_NAMES
    
    # FIXME Find solutioun without changing directory
    # NOTE touch "absolute path"  didn't work in errors redirecting

    cd $DIR # Go to specified directory
 
    for file in $FILE_NAMES
    do
        # FIXME could not register errors during creation of '..' and '.'  files
        touch $file 2>&1 | tr '[:lower:]' '[:upper:]'  >> $HOME/logs/errors  
    
        if [[ -f $file ]]; then
            echo "Creating new file $DIR/$file"
        else
            echo "Could not create $DIR/$file"
        fi
    done

    cd - > /dev/null # Return previous directory
}

imake_dir () {

        read -p "Would you like to create a new directory ?: " RESPONSE
        
        while true        
        do
            if [[ $RESPONSE =~ ^[y,Y].* ]]; then
                echo "Lets create directory $DIR"
                mkdir $DIR 2>&1 | tr '[:lower:]' '[:upper:]'  >> $HOME/logs/errors 
                if [[ -d "$DIR" ]]; then
                    echo "Congrats, your dir created!"
                fi
            break;

            elif  [[ $RESPONSE =~ ^[n,N]+$ ]]; then
                echo "Ok, I will not create any file"
            break;

            else
                read -p "It seems you did not choose a valid option [Y/n] " RESPONSE
            
            fi
        done
}

check_folder_exist () {
    if [ -d $DIR ]; then
        echo ‘Specified path exists !!!’
        imake_files
    else
        echo "I could not find the directory"
        imake_dir
        imake_files
    fi
}

count_error_lines () {
 
    wc -l $HOME/logs/errors | awk '{print $1}'  > $HOME/logs/errors_count
}

clean_errors_file () {

    echo > $HOME/logs/errors    
}

main () {
    
    create_log_files
    prompt_dir_name
    check_folder_exist
    count_error_lines
}

main
