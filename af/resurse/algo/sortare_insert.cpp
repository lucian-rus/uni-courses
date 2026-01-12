#include <iostream>
#include <vector>

void citire_vector_unidimensional(std::vector<int> &vec);
void afisare_vector_unidimensional(std::vector<int> vec);

// complexitate algo o(n*n)
// vec - vectorul de intrare
void sortare_insert(std::vector<int> &vec) {
    for (int i = 1; i < vec.size(); ++i) {
        int k = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > k) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = k;
    }
}

int main() {
    std::vector<int> vec;
    citire_vector_unidimensional(vec);
    sortare_insert(vec);
    afisare_vector_unidimensional(vec);

    return 0;
}

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
