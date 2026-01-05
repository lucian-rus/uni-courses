#include <iostream>

// n - input functie. numarul care va fi verificat daca e prim sau nu
// functia returneaza `true` daca numarul este prim
// functia returneaza `false` daca numarul NU este prim
bool verificare_numar_prim(int n) {
    // 1 si 0 nu sunt numere prime
    if(n == 1 || n == 0) {
        return false;
    }

    // 2 este numar prim
    if(n == 2) {
        return true;
    }

    // daca numarul este divizibil cu 2 nu este prim
    if((n % 2) == 0) {
        return false;
    }

    // iteram pana la i*i=n (echivalent cu radical din n). incrementam i din 2 in 2 ca sa evitam numerele pare
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            // daca gasim divizor, numarul nu este prim
            return false;
        }
    }

    // daca nu am gasit nici un divizor, numarul este prim
    return true;
}

// EXEMPLU DE UTILIZARE
int main() {
    int n;

    std::cout << "numarul de verificat: ";
    std::cin >> n;

    // printam rezultatul. se poate stoca si intr-o variabila de tip bool
    std::cout << verificare_numar_prim(n) << "\n";

    return 0;
}
