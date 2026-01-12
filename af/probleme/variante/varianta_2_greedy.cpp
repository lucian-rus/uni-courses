#include <algorithm> // Pentru std::sort
#include <fstream>
#include <iostream>
#include <vector>

// Declara structura care tine intervalele
struct Interval {
    int minim;
    int maxim;
};

// Functor pentru sortare (necesar pentru std::sort)
bool comparaIntervale(const Interval &a, const Interval &b) {
    return a.minim < b.minim;
}

void rezolva_problema() {
    int n;

    // Folosim fisierele cerute in enunt
    std::ifstream fin("/home/lucian-rus/Desktop/dev/school/resources/af/probleme/variante/examen1.txt");
    std::ofstream fout("examen2.txt");

    if (!fin.is_open()) {
        std::cerr << "Nu am putut deschide fisierul de intrare." << std::endl;
        return;
    }

    fin >> n;
    std::vector<Interval> intervale(n);

    for (int i = 0; i < n; i++) {
        fin >> intervale[i].minim >> intervale[i].maxim;
    }

    // PASUL 1: Sortare O(N log N)
    // Este crucial sa le avem in ordine crescatoare dupa inceput
    std::sort(intervale.begin(), intervale.end(), comparaIntervale);

    // PASUL 2: Greedy - Uniunea intervalelor O(N)
    long long suma_totala = 0;

    // Luam primul interval ca referinta curenta
    int start_curent = intervale[0].minim;
    int final_curent = intervale[0].maxim;

    for (int i = 1; i < n; i++) {
        // Cazul 1: Intervalul i se suprapune cu cel curent
        // Deoarece am sortat, stim sigur ca intervale[i].minim >= start_curent
        // Deci verificam doar daca incepe inainte sa se termine cel curent
        if (intervale[i].minim < final_curent) {
            // Le unim: extindem finalul la maximul dintre cele doua
            if (intervale[i].maxim > final_curent) {
                final_curent = intervale[i].maxim;
            }
        }
        // Cazul 2: Nu se suprapun (avem o pauza)
        else {
            // Adaugam lungimea intervalului completat la suma
            suma_totala += (final_curent - start_curent);

            // Incepem un nou interval curent
            start_curent = intervale[i].minim;
            final_curent = intervale[i].maxim;
        }
    }

    // Adaugam ultimul interval ramas in memorie
    suma_totala += (final_curent - start_curent);

    // Afisare in consola (debug)
    std::cout << "Suma calculata: " << suma_totala << std::endl;

    // Scriere in fisier conform cerintei
    fout << suma_totala << std::endl;
    fout << "Metoda: Greedy cu Sortare" << std::endl;

    fin.close();
    fout.close();
}

int main() {
    rezolva_problema();
    return 0;
}
