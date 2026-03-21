#!/bin/bash
sudo find / -type f | grep "\.conf$" > ex3.output

# tine numele dir-ului precedent
previous=""
total_sum=0

# du-te prin output de la comanda find
for file in `cat ex3.output`; do 
    # echo $file
    dir=$(sudo dirname $file)
    # ia in calcul doar daca previous si dir sunt diferite -> avem fisier nou
    if [ "$dir" != "$previous" ]; then 
        # echo $dir
        previous=$dir
        # suprima potentiale probleme cauzate de fisiere cu spatiu in nume si verifica daca numele e gol sau nu
        size=$(sudo du -s "$dir" 2>/dev/null | cut -f1)
        if [ -n "$size" ]; then
            total_sum=$((total_sum + size))
        fi
    fi
done

echo "total sum: $total_sum KB"