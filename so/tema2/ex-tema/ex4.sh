#!/bin/bash

# creeaza fisier
touch ex4.output

# itereaza si indeplineste conditiile din tema
for ((i=1; i<=100; i++)); do
    echo "linia $i: continut" >> ex4.output
done
