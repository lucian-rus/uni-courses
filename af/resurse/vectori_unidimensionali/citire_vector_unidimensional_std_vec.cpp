#include <iostream>
#include <vector>

// optiune 1 - redimensionare
void citire_vector_unidimensional(std::vector<int> &vec) {
    int n;
    std::cout << "dimensiune vector: ";
    std::cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
}

// optiune 2 - push_back
void citire_vector_unidimensional_2(std::vector<int> &vec) {
    int n;
    std::cout << "dimensiune vector: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int aux;
        std::cin >> aux;

        vec.push_back(aux);
    }
}

int main() {
    std::vector<int> vec;
    citire_vector_unidimensional_2(vec);

    for (int val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    return 0;
}
