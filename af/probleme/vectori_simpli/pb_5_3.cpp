#include <iostream>
#include <math.h>
#include <vector>

void citire_vector_unidimensional(std::vector<int> &vec);
void afisare_vector_unidimensional(std::vector<int> vec);
void descompunere_numar(int num, int baza, std::vector<int> &vec);

void adunare_vectori_binar(std::vector<int> &a, std::vector<int> &b) {
    // tratam cazul in care a nu e alocat
    if (a.size() == 0) {
        a.resize(b.size());
    }

    // pornim de la capete
    int index_a = a.size() - 1;
    int index_b = b.size() - 1;

    // iteram pana terminam vectorul b (vectorul care va fi intotdeauna mai mic sau egal)
    while (index_b >= 0) {
        a[index_a] = a[index_a] + b[index_b];

        // daca rezultatul adunarii e 2, incrementam numarul din stanga 
        if (a[index_a] == 2) {
            a[index_a - 1]++;
            a[index_a] = 0;
        }

        index_a--;
        index_b--;
        afisare_vector_unidimensional(a);
    }
}

void rezolvare(std::vector<int> vec) {
    std::vector<int> res;
    for (int i = 0; i < vec.size(); i++) {
        std::vector<int> temp;

        // descompunem cifra inmultita cu 10 la puterea pozitiei in numar
        descompunere_numar(vec[i] * pow(10, vec.size() - 1 - i), 2, temp);
        afisare_vector_unidimensional(temp);
        adunare_vectori_binar(res, temp);
        afisare_vector_unidimensional(res);
        std::cout << "======================================\n";
    }

    std::cout << "rezultat final:\n";
    afisare_vector_unidimensional(res);
}

int main() {
    std::vector<int> vec;
    citire_vector_unidimensional(vec);

    rezolvare(vec);

    // afisare_vector_unidimensional(vec);

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

void afisare_vector_unidimensional(std::vector<int> vec) {
    for (int val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

void descompunere_numar(int num, int baza, std::vector<int> &vec) {
    // schimbam baza
    while (num) {
        vec.push_back(num % baza);
        num = num / baza;
    }

    // vectorul trebuie inversat - mergem doar pana la jumatate si inversam in-place
    for (int i = 0; i < vec.size() / 2; i++) {
        int aux                 = vec[i];
        vec[i]                  = vec[vec.size() - 1 - i];
        vec[vec.size() - 1 - i] = aux;
    }
}
