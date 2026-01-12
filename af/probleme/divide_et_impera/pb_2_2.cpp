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

int main() {
    std::vector<int> vec;
    citire_vector_unidimensional(vec);

    int x;
    std::cin >> x;

    int stop  = vec.size();
    int start = vec.size() / 2;
    for (int i = start; i < stop; i++) {
        if (vec[i] != i) {
            if (vec[i] > i) {
                stop = start;
                start = start - (start / 2);
            }
            else {
                start = start;
                start = start - (start / 2);
            }
        }
        else {
            std::cout << i << ' ' << vec[i] << '\n';
        }
    }

    return 0;
}
