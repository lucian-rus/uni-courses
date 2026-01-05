#include <iostream>

// vec - contine vectorul bidimensional
// n   - numarul de randuri
// m   - numarul de coloane
void afisare_vector_bidimensional(int vec[2][5], int &n, int &m) {
    // afiseaza dimensiunea vectorului
    std::cout << "numar randuri: " << n << "\n";
    std::cout << "numar coloane: " << m << "\n";

    // afiseaza elementele vectorului
    std::cout << "elementele vectorului:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << vec[i][j] << ' ';
        }
        std::cout << "\n";
    }
}

int main() {
    // date care trebuiesc afisate. pot veni si din alta functie (vezi `citire_vector_bidimensional.cpp`, unde
    // valorile care sunt afisate de functie vin dintr-o alta functie)
    int vec[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 0}};
    int n         = 2;
    int m         = 5;

    std::cout << "----- output program\n";
    // EXEMPLU DE UTILIZARE:
    afisare_vector_bidimensional(vec, n, m);

    return 0;
}
