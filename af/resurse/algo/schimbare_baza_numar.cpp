#include <iostream>
#include <vector>

void afisare_vector_unidimensional(std::vector<int> vec);

void descompunere_numar(int num, int baza, std::vector<int> &vec) {
    // schimbam baza
    while(num) {
        vec.push_back(num % baza);
        num = num / baza;
    }

    // vectorul trebuie inversat - mergem doar pana la jumatate si inversam in-place
    for(int i = 0; i < vec.size() / 2; i++) {
        int aux = vec[i];
        vec[i] = vec[vec.size() - 1 - i];
        vec[vec.size() - 1 - i] = aux;
    }
}

int main() {
    int n, b;
    std::vector<int> vec;

    std::cout << "introduceti numarul: ";
    std::cin >> n;

    std::cout << "introduceti baza: ";
    std::cin >> b;

    descompunere_numar(n, b, vec);
    afisare_vector_unidimensional(vec);
}

void afisare_vector_unidimensional(std::vector<int> vec) {
    for (int val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}
