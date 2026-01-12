#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

void citire_cartiere(std::vector<std::vector<int>> &cartiere) {
    int nr_cartiere;
    int nr_strazi;
    // Folosim fisierele cerute in enunt
    std::ifstream fin("/home/lucian-rus/Desktop/dev/school/resources/af/probleme/variante/examen1.txt");

    fin >> nr_cartiere;
    fin >> nr_strazi;

    cartiere.resize(nr_cartiere);
    for (int i = 0; i < nr_cartiere; i++) {
        for (int j = 0; j < nr_strazi; j++) {
            int aux;
            fin >> aux;

            cartiere[i].push_back(aux);
        }
    }

    fin.close();
}

void afisare_cartiere(std::vector<std::vector<int>> &cartiere) {
    for (auto cartier : cartiere) {
        for (auto strada : cartier) {
            std::cout << strada << ' ';
        }
        std::cout << '\n';
    }
}

void afisare_strazi_populate(std::vector<std::vector<int>> &cartiere) {
    for (int i = 0; i < cartiere.size(); i++) {
        for (int j = 0; j < cartiere[i].size(); j++) {
            if (cartiere[i][j] > 500) {
                std::cout << i << " - " << j << " - " << cartiere[i][j] << '\n';
            }
        }
    }
}

bool functie_sortare(int a, int b) {
    return a > b;
}

void sortare_cartiere(std::vector<std::vector<int>> &cartiere) {
    for (auto &cartier : cartiere) {
        std::sort(cartier.begin(), cartier.end(), functie_sortare);
    }
}

void calculeaza_populatie(std::vector<std::vector<int>> &cartiere) {
    int val_maxim   = -1;
    int idx_pop_max = -1;

    for (int i = 0; i < cartiere.size(); i++) {
        int curent = 0;
        for (int j = 0; j < cartiere[i].size(); j++) {
            if (cartiere[i][j] != -1) {
                curent += cartiere[i][j];
            }
        }

        if (curent > val_maxim) {
            val_maxim   = curent;
            idx_pop_max = i;
        }
    }

    std::cout << "pop maxima in cartier: " << idx_pop_max << " val: " << val_maxim << '\n';
}

// rezolvarea nu este una foarte optima, deoarece parcurgem sirurile de foarte multe ori
// mare parte din rezolvare se poate face chiar cand se face citirea datelor din fisier
// rezolvarea s-a facut in aceasta maniera doar pentru modularizarea problemei
int main() {
    std::vector<std::vector<int>> cartiere;

    citire_cartiere(cartiere);
    afisare_cartiere(cartiere);
    std::cout << "========================================\n";
    // rezolva a)
    afisare_strazi_populate(cartiere);
    std::cout << "========================================\n";

    // facem clona ca sa putem pastra datele originale
    std::vector<std::vector<int>> cartiere_copie = cartiere;
    // rezolva b)
    sortare_cartiere(cartiere_copie);
    afisare_cartiere(cartiere_copie);
    std::cout << "========================================\n";

    // rezolva c)
    calculeaza_populatie(cartiere);
    std::cout << "========================================\n";

    // pentru problema extra, avem nevoie de structuri
    
    return 0;
}
