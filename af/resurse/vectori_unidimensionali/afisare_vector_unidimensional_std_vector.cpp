#include <iostream>
#include <vector>

// optiune 1 - redimensionare
// Functia citire_vector_unidimensional citeste dimensiunea si elementele
// unui vector unidimensional de la tastatura.
// Parametru: vec - vectorul in care se citesc valorile.

void citire_vector_unidimensional(std::vector<int> &vec) {
    int n;
    std::cout << "dimensiune vector: ";
    std::cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
}

// Functia afisare_vector_unidimensional afiseaza elementele vectorului
// pe o singura linie.
// Parametru: vec - vectorul de afisat.

void afisare_vector_unidimensional(std::vector<int> vec) {
    for (int val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

// EXEMPLU DE UTILIZARE
// Functia main citeste un vector de la tastatura si il afiseaza.

int main() {
    std::vector<int> vec;
    citire_vector_unidimensional(vec);
    afisare_vector_unidimensional(vec);
    return 0;
}
