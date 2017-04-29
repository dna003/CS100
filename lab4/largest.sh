#!/bin/sh 

if [ "$#" -ne "3" ]; then   #note need the space after if in order to work!
    echo "Error! Please enter 3 parameters."
else 
if [ "$1" -ge "$2" ]; then                       #note also need spaces after and before the brackets!  
    if [ "$2" -ge "$3" ]; then
        echo "largest is:" $1
    else
        if [ "$3" -ge "$1" ]; then
            echo "largest is:" $3
        else
            echo "largest is:" $1 
        fi
    fi
else          
    if [ "$2" -ge "$3" ]; then
        echo "largest is:" $2
    else 
        echo "largest is:" $3
    fi
fi   
fi        
