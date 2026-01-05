#include <fstream>  // pentru citirea din fisier
#include <iostream> // pentru afisarea pe consola a ce citim din fisier

void citeste_vector_unidimensional_din_fisier(int vec[], int &n) {
    // deschidem fisierul
    std::ifstream fin("fisier_input.txt");

    // citim `n` din fisier
    fin >> n;
    // citim vectorul din fisier, element cu element
    for(int i = 0; i < n; i++) {
        fin >> vec[i];
    }

    // inchidem fisierul
    fin.close();
}

int main() {
    int n;
    int vec[100];

    // EXEMPLU DE UTILIZARE
    citeste_vector_unidimensional_din_fisier(vec, n);

    std::cout << "dimensiune vector: " << n << "\nelemente vector: ";
    for(int i = 0; i < n; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";


}
