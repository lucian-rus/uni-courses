#include <iostream>

// Functia cel_mai_mare_divizor_comun calculeaza cel mai mare divizor comun
// dintre cele doua numere a si b folosind algoritmul lui Euclid.
// Returneaza cel mai mare divizor comun.

int cel_mai_mare_divizor_comun(int a, int b) {
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;

    // putem returna oricare dintre numere
    return a;
}

// EXEMPLU DE UTILIZARE
// Functia main citeste doua numere de la tastatura si afiseaza
// cel mai mare divizor comun al acestora.

int main() {
    int x, y;
    std::cin >> x >> y;

    std::cout << cel_mai_mare_divizor_comun(x, y) << "\n";

    return 0;
}
