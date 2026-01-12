#include <iostream>
#include <math.h>
#include <vector>

void afisare_exemplu_a(std::vector<int> vec, int n) {
    std::vector<std::vector<int>> mat;

    int m = (int)sqrt(n);
    // atribuim matrice patratica
    mat.resize(m);
    for (int i = 0; i < mat.size(); i++) {
        mat[i].resize(m);
    }

    // for (int i = 0; i < vec.size(); i++) {
    //     mat[]
    // }
}

int main() {
    int              n;
    std::vector<int> vec;

    std::cout << "introduceti numarul: ";
    std::cin >> n;

    vec.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    afisare_exemplu_a(vec, n);

    return 0;
}
