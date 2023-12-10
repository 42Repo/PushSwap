#!/bin/bash
i=0
for (( c=1; c<=$2; c++ ))
do
    sh=$(shuf -n $1 -i 0-100000)
    k=$(./push_swap $sh | wc -l)
    if [ $k -gt $3 ]
    then
        i=$((i+1))
        echo $k
        # on affiche l'input qui a fait depasser le nombre de coups
        echo $sh
    fi
done
echo $i
