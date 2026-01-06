#include <iostream>

// num - input functie. numarul care va fi verificat daca este palindrom
// functia returneaza `true` daca numarul este palindrom
// functia returneaza `false` daca numarul NU este palindrom
bool verifica_palindrom(int num) {
    int vec[100];
    int nr_cifre = 0;


    // extragem cifrele numarului in vectorul vec
    while (num != 0) {
        vec[nr_cifre++] = num % 10;
        num = num / 10;
    }


    // verificam daca cifrele sunt simetrice fata de centru
    for (int i = 0; i < nr_cifre / 2; i++) {
        if (vec[i] != vec[nr_cifre - 1 - i]) {
            // daca gasim o pereche diferita, nu e palindrom
            return false;
        }
    }


    // daca toate perechile sunt egale, numarul este palindrom
    return true;
}


// EXEMPLU DE UTILIZARE
int main() {
    int n;

    std::cout << "introduceti numarul: ";
    std::cin >> n;

    // afisam rezultatul. se poate stoca si intr-o variabila de tip bool
    std::cout << "este palindrom: " << verifica_palindrom(n) << "\n";

    return 0;
}
