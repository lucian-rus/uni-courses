#include <iostream>

int cel_mai_mare_divizor_comun(int a, int b) {
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;

    // putem returna oricare dintre numere
    return a;
}

// Functia cel_mai_mic_multiplu_comun calculeaza cel mai mic multiplu comun
// dintre cele doua numere a si b, folosind cel mai mare divizor comun.
// Returneaza cel mai mic multiplu comun.

int cel_mai_mic_multiplu_comun(int a, int b) {
    return ((a * b) / cel_mai_mare_divizor_comun(a, b));
}

// EXEMPLU DE UTILIZARE
// Functia main citeste doua numere de la tastatura si afiseaza
// cel mai mic multiplu comun al acestora.

int main() {
    int x, y;
    std::cin >> x >> y;

    std::cout << cel_mai_mic_multiplu_comun(x, y) << "\n";

    return 0;
}
