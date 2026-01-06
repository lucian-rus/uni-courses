/*
Gasiti un index k intr-un vector numeric unde suma primelor k elemente este egala cu produsul ultimelor n-k elemente, 
toate elementele pana la k sunt prime, iar toate elementele dupa k sunt puteri ale lui 2.
Exemplu: Pentru [7, 7, 7, 7, 3, 5, 2, 2, 1, 2, 4, 8], daca luam k=8, primele opt elemente au suma 64, 
ultimile n-k=4 elemente au produsul 64, iar acestea sunt puteri ale lui 2.
*/

#include <iostream>
#include <vector>
#include <cmath>

// Functie pentru a verifica daca un numar este prim
bool estePrim(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Functie pentru a verifica daca un numar este putere a lui 2
bool estePutereADoua(int n) {
    if (n <= 0) return false; // Puterile lui 2 sunt pozitive
    // Un numar este putere a lui 2 daca are un singur bit de 1 in reprezentarea binara
    // Trick: n & (n-1) este 0 pentru puteri ale lui 2 (si pentru 0, dar am exclus deja)
    return (n & (n - 1)) == 0;
}

int main() {
    // Citirea vectorului
    std::cout << "Introduceti numarul de elemente: ";
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    std::cout << "Introduceti elementele vectorului: ";
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    // Verificam pentru fiecare k posibil
    bool gasit = false;
    for (int k = 1; k < n; k++) {
        // Verificam conditiile pentru k

        // 1. Toate elementele pana la k sunt prime
        bool toatePrime = true;
        for (int i = 0; i < k; i++) {
            if (!estePrim(vec[i])) {
                toatePrime = false;
                break;
            }
        }
        if (!toatePrime) continue;

        // 2. Toate elementele dupa k sunt puteri ale lui 2
        bool toatePuteri = true;
        for (int i = k; i < n; i++) {
            if (!estePutereADoua(vec[i])) {
                toatePuteri = false;
                break;
            }
        }
        if (!toatePuteri) continue;

        // 3. Calculam suma primelor k elemente
        int suma = 0;
        for (int i = 0; i < k; i++) {
            suma += vec[i];
        }

        // 4. Calculam produsul ultimelor n-k elemente
        long long produs = 1; // Folosim long long pentru a evita overflow
        for (int i = k; i < n; i++) {
            produs *= vec[i];
        }

        // 5. Verificam egalitatea
        if (suma == produs) {
            std::cout << "k = " << k << std::endl;
            gasit = true;
            break; // Daca vrem doar primul k gasit, oprim aici
        }
    }

    if (!gasit) {
        std::cout << "Nu exista un k care sa indeplineasca conditiile." << std::endl;
    }

    return 0;
}