#include <iostream>


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


int main() {
    // date care trebuiesc afisate. pot veni si din alta functie (vezi `citire_vector_unidimensional.cpp`, unde
    // valorile care sunt afisate de functie vin dintr-o alta functie)
    int vec[5] = {1, 2, 3, 4, 5};
    int n = 5;

    std::cout << "----- output program\n";
    // EXEMPLU DE UTILIZARE:
    afisare_vector_unidimensional(vec, n);

    return 0;
}
