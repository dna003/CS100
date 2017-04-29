#!/bin/sh 

ARRAY=(9 12 7 8 4) 

printf "Original array:"
for (( i = 0; i < 5; i++ )) do  
    printf %s " " "${ARRAY[i]}" 
done

printf "\n" 

size=${#ARRAY[@]}      #init array size to size. Note: spacing does matter! 

for (( i = 0; i < $size; i++ ))
do 
    for (( j = 0; j < $size-$i-1; j++))
    do   
         if [ ${ARRAY[j+1]} -lt ${ARRAY[j]} ]; then 
             tmp=${ARRAY[j]} 
             ARRAY[j]=${ARRAY[j+1]}
            ARRAY[j+1]=$tmp  
         fi
    done 
done 

echo ${ARRAY[@]}    #prints array 
