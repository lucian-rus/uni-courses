#include <iostream>

// vec - contine vectorul unidimensional 
// n   - numarul de elemente din vector
void citire_vector_unidimensional(int vec[], int &n) {
    // citeste dimensiunea vectorului
    std::cout << "dimensiunea vectorului: ";
    std::cin >> n;

    // citeste elementele vectorului
    std::cout << "elementele vectorului: ";
    for(int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
}

// vec - contine vectorul unidimensional 
// n   - numarul de elemente din vector
void afisare_vector_unidimensional(int vec[], int &n) {
    // afiseaza dimensiunea vectorului
    std::cout << "dimensiunea vectorului: " << n << "\n";
    
    // afiseaza elementele vectorului
    std::cout << "elementele vectorului: ";
    for(int i = 0; i < n; i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << "\n";  
}

// EXEMPLU DE UTILIZARE:
int main() {
    // declara vectorul si dimensiunea lui unde e necesar
    // dimensiunea e 100 in mod arbitrar. ne asiguram ca vectorul suporta max 100 de valori
    int vec[100];
    int n;

    std::cout << "----- input utilizator\n";
    // pentru folosire - apeleaza functia cu parametrii definiti anterior
    citire_vector_unidimensional(vec, n);

    std::cout << "----- output program\n";
    afisare_vector_unidimensional(vec, n);

    return 0;
}
