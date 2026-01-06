#include <iostream>
#include <vector>

void citire_vector_unidimensional(std::vector<int> &vec);
void afisare_vector_unidimensional(std::vector<int> vec);

void sortare_bubble_crescator(std::vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size(); j++) {
            if(vec[i] < vec[j]) {
                int aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

void sortare_bubble_descrescator(std::vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec.size(); j++) {
            if(vec[i] > vec[j]) {
                int aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

int main() {
    std::vector<int> vec;
    citire_vector_unidimensional(vec);
    sortare_bubble_crescator(vec);
    afisare_vector_unidimensional(vec);
    sortare_bubble_descrescator(vec);
    afisare_vector_unidimensional(vec);
    return 0;
}

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

void afisare_vector_unidimensional(std::vector<int> vec) {
    for (int val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}
