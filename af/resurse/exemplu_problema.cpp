// Se citeste un vector de n numere intregi ordonat descrescator din fisier. Se citeste un al doilea vector de m numere intregi
// din consola. Folosind cautarea binara sa se determine care elemente din al doilea vector apar in primul si pe ce poziții.
// Rezultatul se va scrie in fisier.
//  * Se citeste un vector de n numere intregi ordonat descrescator din fisier
//      -> trebuie sa citim toate datele din fisier (1)
//      -> trebuie sa citim dimensiunea `n` a vectorului 1 (2)
//      -> trebuie sa citim vectorul 1 `vec1` (3)

// * Se citeste un al doilea vector de m numere intregi din consola.
//     -> trebuie sa citim toate datele de la consola (4)
//     -> trebuie sa citim dimensiunea `m` a vectorului 2 (5)
//     -> trebuie sa citim vectorul 2 `vec2` (6)

// * Folosind cautarea binara sa se determine care elemente din al doilea vector apar in primul si pe ce poziții.
//     -> `vec2` trebuie parcurs si, pentru fiecare element din acesta, trebuie facuta cautare binara in `vec1` (7)
//     -> daca elementul exista, salvam pozitia acestuia (8)

// * Rezultatul se va scrie in fisier.
//     -> numarul si pozitia se scriu in fisier (9)

#include <fstream>  // pentru interactiunea cu fisierele
#include <iostream> // pentru interactiunea cu consola

void citeste_vector_unidimensional_din_fisier(int vec[], int &n) {
    // deschidem fisierul
    std::ifstream fin("input_exemplu_problema.txt");

    // citim `n` din fisier -> indeplineste (2)
    fin >> n;
    // citim vectorul din fisier, element cu element -> indeplineste (3)
    for (int i = 0; i < n; i++) {
        fin >> vec[i];
    }

    // inchidem fisierul
    fin.close();
}

void citire_vector_unidimensional(int vec[], int &n) {
    // citeste dimensiunea vectorului -> indeplineste (5)
    std::cout << "dimensiunea vectorului: ";
    std::cin >> n;

    // citeste elementele vectorului -> indeplineste (6)
    std::cout << "elementele vectorului: ";
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
}

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
            pozitie = m; // -> indeplineste (8)
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

int main() {
    // declaram toate variabilele de care avem nevoie - vec1, vec2, n si m
    int vec1[100];
    int vec2[100];
    int n, m;

    // *(1) -> trebuie sa citim toate datele din fisier - putem folosi `lucru_cu_fisiere/citire_date_din_fisier` ca referinta
    // * copiem functia `citeste_vector_unidimensional_din_fisier` si o aducem in fisierul asta. in cazul de fata, nu e nevoie sa
    // o modificam, asa ca ii dam direct paste deasupra functiei main
    // * din cerinta stim ca trebuie sa citim datele in vec1 si n
    // * (2) si (3) sunt indeplinite in interiorul functiei
    citeste_vector_unidimensional_din_fisier(vec1, n);

    // * (4) -> trebuie sa citim toate datele de la consola - putem folosi
    // `vectori_unidimensionali/citire_vector_unidimensional.cpp` ca referinta
    // * copiem functia `citire_vector_unidimensional` si o aducem in fisierul asta. in cazul de fata, nu e nevoie sa o modificam,
    // asa ca ii dam direct paste deasupra functiei main
    // * din cerinta stim ca trebuie sa citim datele in vec2 si m
    // * (5) si (6) sunt indeplinite in interiorul functiei
    citire_vector_unidimensional(vec2, m);

    // pentru (9)
    std::ofstream fout("output_exemplu_problema.txt");

    // * din (7) putem deduce ca avem nevoie de functia de cautare binara. o copiem din fisierul `algo/cautare_binara.cpp` si ii
    // dam paste in fisier deasupra functiei main
    // * avem nevoie de functia care returneaza pozitia (deducem asta tot din enunt)
    // * in baza cerintei, ca sa facem cautare binara pe fiecare element din vec2, trebuie sa il parcurgem si sa apelam cautarea
    // binara pentru acesta
    for (int i = 0; i < m; i++) {
        // declaram `pozitie` ca sa stocam valoarea returnata. functia e apelata cu parametrii vec1 si n, care reprezinta sirul si
        // dimensiunea in care facem cautarea si vec2[i] care reprezinta elementul curent pe care il cautam in vec1
        int pozitie = cautare_binara_returneaza_pozitia(vec1, n, vec2[i]);

        // * indata ce avem pozitia, putem direct sa printam in fisier, dar pentru asta avem nevoie sa adaptam scrierea in fisier.
        // putem folosi `lucru_cu_fisiere/scriere_date_in_fisier.cpp` ca referinta
        // * pentru ca nu avem un caz care sa se potriveasca 100% rezolvarii, e nevoie sa adaptam continutul fisierului la cazul
        // nostru specific. *luam deschiderea si inchiderea fisierului din referinta si scriem output-ul in functie de nevoie
        if (pozitie != -1) {
            fout << "element " << vec2[i] << " pozitie: " << pozitie << "\n";
        }
    }

    // inchidem fisierul
    fout.close();

    return 0;
}
