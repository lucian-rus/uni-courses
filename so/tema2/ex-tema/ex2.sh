#!/bin/bash

# pune arg1 in n -> comanda folosita `./ex2.sh <rang>`
n=$1

# daca avem 1 sau 0, iesim
if [ $n -le 0 ]; then
    echo 0
elif [ $n -eq 1 ]; then
    echo 1
else
    previous=0
    current=1
    
    # calculam fibonnaci
    for ((i=2; i<=n; i++)); do
        next=$((previous + current))
        previous=$current
        current=$next
    done
    
    # daca am ajuns la final, printeaza numarul
    echo $current
fi

# pseudocod folosit ca referinta
# FUNCTION Fibonacci(n)
#     IF n <= 0 THEN RETURN 0
#     IF n == 1 THEN RETURN 1
    
#     prev = 0
#     curr = 1
    
#     FOR i FROM 2 TO n
#         next = prev + curr
#         prev = curr
#         curr = next
#     ENDFOR
    
#     RETURN curr
# ENDFUNCTION
