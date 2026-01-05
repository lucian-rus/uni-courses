#include <fstream>  // pentru citirea din fisier
#include <iostream> // pentru afisarea pe consola a ce citim din fisier

void scrie_vector_unidimensional_in_fisier(int vec[], int &n) {
    // deschidem fisierul
    std::ofstream fout("fisier_output.txt");

    fout << "dimensiune vector: " << n << "\nelemente vector: ";
    for(int i = 0; i < n; i++) {
        fout << vec[i] << " ";
    }
    fout << "\n";

    // inchidem fisierul
    fout.close();
}

int main() {
    int n;
    int vec[100];

    // citim `n` de la tastatura
    std::cin >> n;
    // citim vectorul de la tastatura, element cu element
    for(int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    // EXEMPLU DE UTILIZARE
    scrie_vector_unidimensional_in_fisier(vec, n);
}
