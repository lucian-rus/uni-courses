1. `#include <iostream>` trebuie inclus la inceput de fisier pentru a avea acces la `std::cin` si `std::cout`
2. `int main()` reprezinta functia de intrare si e esentiala functionarii programului
3. `#include <fstream>` trebuie inclus la inceput de fisier daca avem de-a face cu fisiere
4. putem sa adaugam oricate include-uri avem nevoie. daca avem nevoie sa citim de la tastatura dar trebuie sa scriem in fisier, putem include atat `iostream` cat si `fstream`
5. parcurgerea vectorilor unidimensionali e ilustrata in `vizualizari/parcurgere_vector_unidimensional`
6. parcurgerea vectorilor bidimensionali e ilustrata in `vizualizari/parcurgere_vector_bidimensional`
7. fiecare problema trebuie sparta in probleme mai mici, in asa fel incat rezolvarea acestora sa fie cat mai facila
8. problemele de algoritmica sunt si probleme de "limba romana". mare parte dein rezolvarea problemei consta in analizarea libajului folosit in problema

### exemplu problema
Se citeste un vector de n numere intregi ordonat descrescator din fisier. Se citeste un al doilea vector de m numere intregi din consola. Folosind cautarea binara sa se determine care elemente din al doilea vector apar in primul si pe ce poziții. Rezultatul se va scrie in fisier.

problema data se poate sparge in mai multe probleme mici:
* Se citeste un vector de n numere intregi ordonat descrescator din fisier  
    -> trebuie sa citim toate datele din fisier <br>
    -> trebuie sa citim dimensiunea `n` a vectorului 1 <br>
    -> trebuie sa citim vectorul 1 `vec1`

* Se citeste un al doilea vector de m numere intregi din consola.
    -> trebuie sa citim toate datele de la consola <br>
    -> trebuie sa citim dimensiunea `m` a vectorului 2 <br>
    -> trebuie sa citim vectorul 2 `vec2`

* Folosind cautarea binara sa se determine care elemente din al doilea vector apar in primul si pe ce poziții.
    -> `vec2` trebuie parcurs si, pentru fiecare element din acesta, trebuie facuta cautare binara in `vec1`
    -> daca elementul exista, salvam pozitia acestuia

* Rezultatul se va scrie in fisier.
    -> numarul si pozitia se scriu in fisier
