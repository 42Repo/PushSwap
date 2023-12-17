#!/bin/bash
i=0
max=0
for (( c=1; c<=$2; c++ ))
do
    sh=$(shuf -n $1 -i 0-100000)
    k=$(./push_swap $sh | wc -l)
    if [ $k -gt $3 ]
    then
        i=$((i+1))
        # on affiche l'input qui a fait depasser le nombre de coups
        if [ $k -gt $max ]
        then
            max=$k
            echo $sh
            echo $k
        fi
    fi
done
echo $i
