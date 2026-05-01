#include <fstream>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

// std::map e un ordered map la care putem da un custom comparator ca sa ne faca automat sortarea
struct CompCustom {
    bool operator()(const std::pair<float, float> &a, const std::pair<float, float> &b) const {
        // departajarea in functie de nota de la bac
        if (a.first == b.first) {
            return a.second > b.second;
        }

        return a.first > b.first;
    }
};

void citire_din_fisier(std::map<std::pair<float, float>, std::string, CompCustom> &lista_candidati) {
    std::ifstream fin("sd/input/admitere.txt");

    float       admitere, bac;
    std::string nume;

    // facem asta pentru ca desi pare neintuitiv, putem face custom comparison doar pe keys
    while (fin >> nume >> admitere >> bac) {
        lista_candidati[std::pair<float, float>(admitere, bac)] = nume;
    }

    fin.close();
}

void afisare(const std::map<std::pair<float, float>, std::string, CompCustom> &lista_candidati) {
    int n;
    std::cout << "numar de candidati sa fie afisati: ";
    std::cin >> n;

    // avem doua conditii pentru care iesim, sau ajungem la final de map sau consumam numarul cerut
    for (auto it = lista_candidati.begin(); n && it != lista_candidati.end(); it++) {
        std::cout << it->second << " cu notele: " << it->first.first << ' ' << it->first.second << '\n';
        n--;
    }
}

int main(void) {
    // implementarea initiala avea:
    // * key = string
    // * val = pair<float, float>
    // din cauza a cum functioneaza custom comparator, facand comparatii pe keys, a trebuit sa schimbam ordinea
    std::map<std::pair<float, float>, std::string, CompCustom> lista_candidati;
    citire_din_fisier(lista_candidati);
    afisare(lista_candidati);

    return 0;
}