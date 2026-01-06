#include <iostream>
#include <vector>

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

void inserare_element(std::vector<int> &vec, int pozitie, int valoare) {
    if (pozitie >= 0 && pozitie < vec.size()) {
        vec.insert(vec.begin() + pozitie, valoare);
    }
} 

int main() {
    std::vector<int> vec;
    citire_vector_unidimensional(vec);

    // EXEMPLU DE UTILIZARE
    inserare_element(vec, 1, 25);
    inserare_element(vec, 3, 25);

    afisare_vector_unidimensional(vec);
    return 0;
}
