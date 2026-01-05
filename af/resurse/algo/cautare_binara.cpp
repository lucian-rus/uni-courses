#include <iostream>

// vec - contine vectorul unidimensional 
// n   - numarul de elemente din vector
// element_cautat - elementul din sir pe care il cautam
// functia returneaza pozitia in caz ca gaseste elementul. in caz contrar, returneaza -1
int cautare_binara_returneaza_pozitia(int vec[], int n, int element_cautat) {
    int st = 0;
    int dr = n - 1;

    // initializam cu -1 care e o valoare incorecta (-1 nu poate fi index pentru vector)
    int pozitie = -1;
    while (st <= dr) {
        // calculam mijlocul
        int m = st + (dr - st) / 2;

        // daca am gasit elementul cautat, salvam pozitia si oprim cautarea
        if (vec[m] == element_cautat) {
            pozitie = m;
            break;
        }

        // daca nu am gasit elementul, continuam
        if (vec[m] < element_cautat) {
            st = m + 1;
        }
        else {
            dr = m - 1;
        }
    }

    // returnam pozitia gasita
    return pozitie;
}

// vec - contine vectorul unidimensional 
// n   - numarul de elemente din vector
// element_cautat - elementul din sir pe care il cautam
// functia returneaza true in caz ca gaseste elementul. in caz contrar, returneaza false
bool cautare_binara_elementul_exista(int vec[], int n, int element_cautat) {
    int st = 0;
    int dr = n - 1;

    while (st <= dr) {
        int m = st + (dr - st) / 2;

        // singura diferenta fata de cautarea de pozitie e conditia de oprire si ce returneaza
        if (vec[m] == element_cautat) {
            return true;
        }
        
        if (vec[m] < element_cautat) {
            st = m + 1;
        }
        else {
            dr = m - 1;
        }
    }

    return false;
}

// EXEMPLU DE UTILIZARE
int main() {
    int vec[8] = {1, 4, 5, 7, 9, 11, 15, 18};
    int n      = 8;

    std::cout << "pozitie pentru " << 11 << " " << cautare_binara_returneaza_pozitia(vec, n, 11) << "\n";
    std::cout << "pozitie pentru " << 6 << " " << cautare_binara_returneaza_pozitia(vec, n, 6) << "\n";
    std::cout << "pozitie pentru " << 13 << " " << cautare_binara_returneaza_pozitia(vec, n, 13) << "\n";

    std::cout << "exista " << 6 << " " << cautare_binara_elementul_exista(vec, n, 6) << "\n";
    std::cout << "exista " << 11 << " " << cautare_binara_elementul_exista(vec, n, 11) << "\n";

    return 0;
}
