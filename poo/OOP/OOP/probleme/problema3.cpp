// Problema 3: Functie care imparte un vector de intregi in doi vectori:
// numere pare si numere impare, alocati dinamic.

#include <iostream>

void separa(const int *v, int n,
            int *&pare, int &nPare,
            int *&impare, int &nImpare) {
    nPare = 0;
    nImpare = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            nPare++;
        } else {
            nImpare++;
        }
    }

    pare = new int[nPare];
    impare = new int[nImpare];

    int iP = 0, iI = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            pare[iP++] = v[i];
        } else {
            impare[iI++] = v[i];
        }
    }
}

int main() {
    int n;
    std::cout << "Numarul de elemente: ";
    std::cin >> n;

    int *v = new int[n];
    std::cout << "Introduceti elementele: ";
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int *pare = nullptr;
    int *impare = nullptr;
    int nPare = 0, nImpare = 0;
    separa(v, n, pare, nPare, impare, nImpare);

    std::cout << "Numere pare (" << nPare << "): ";
    for (int i = 0; i < nPare; i++) {
        std::cout << pare[i] << ' ';
    }
    std::cout << "\nNumere impare (" << nImpare << "): ";
    for (int i = 0; i < nImpare; i++) {
        std::cout << impare[i] << ' ';
    }
    std::cout << '\n';

    delete[] v;
    delete[] pare;
    delete[] impare;
    return 0;
}
