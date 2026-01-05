#include <iostream>

// vec - contine vectorul bidimensional
// n   - numarul de randuri
// m   - numarul de coloane
void citire_vector_bidimensional(int vec[100][100], int &n, int &m) {
    // citeste numarul de randuri
    std::cout << "numar de randuri: ";
    std::cin >> n;

    // citeste numarul de coloane
    std::cout << "numar de coloane: ";
    std::cin >> m;

    // citeste elementele vectorului
    std::cout << "elementele vectorului:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> vec[i][j];
        }
    }
}

// vec - contine vectorul bidimensional
// n   - numarul de randuri
// m   - numarul de coloane
void afisare_vector_bidimensional(int vec[100][100], int &n, int &m) {
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

// EXEMPLU DE UTILIZARE:
int main() {
    // date care trebuiesc afisate. pot veni si din alta functie (vezi `citire_vector_bidimensional.cpp`, unde
    // valorile care sunt afisate de functie vin dintr-o alta functie)
    int vec[100][100];
    int n;
    int m;

    std::cout << "----- input utilizator\n";
    // pentru folosire - apeleaza functia cu parametrii definiti anterior
    citire_vector_bidimensional(vec, n, m);

    std::cout << "----- output program\n";
    afisare_vector_bidimensional(vec, n, m);

    return 0;
}
