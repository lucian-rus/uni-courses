#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using Concurent  = std::pair<std::string, std::string>;
using Competitie = std::pair<std::string, std::vector<Concurent>>;

// fara custom hash avem eroare -> puteam scapa de asta cu un map simplu
struct ConcurentHash {
    size_t operator()(const Concurent &p) const {
        return std::hash<std::string>()(p.first) ^ (std::hash<std::string>()(p.second) << 1);
    }
};

void citire_din_fisier(std::vector<Competitie> &c) {
    std::ifstream fin("sd/input/competitii.txt");

    std::string tip_competitie;
    int         nr_candidati;

    // formam listele cat mai coerent aici
    while (fin >> tip_competitie >> nr_candidati) {
        Competitie comp;
        comp.first = tip_competitie;
        for (int i = 0; i < nr_candidati; i++) {
            Concurent conc;
            fin >> conc.first >> conc.second;

            comp.second.push_back(conc);
        }
        c.push_back(comp);
    }

    fin.close();
}

void listare_persoane_competitii_multiple(const std::vector<Competitie> &c) {
    std::unordered_map<Concurent, int, ConcurentHash> concurenti;

    for (auto comp : c) {
        for (auto conc : comp.second) {
            concurenti[conc]++;
        }
    }

    // mergem prin unordered_map si printam pe toti cei care au mai multe competitii
    for (auto it = concurenti.begin(); it != concurenti.end(); it++) {
        if (it->second > 1) {
            Concurent c = it->first;
            std::cout << c.first << ' ' << c.second << " participa la " << it->second << " competitii\n";
        }
    }
}

int main(void) {
    std::vector<Competitie> lista_competitii;
    citire_din_fisier(lista_competitii);

    std::cout << "am citit:\n";
    for (auto comp : lista_competitii) {
        std::cout << comp.first << '\n';
        for (auto conc : comp.second) {
            std::cout << conc.first << ' ' << conc.second << '\n';
        }
        std::cout << '\n';
    }

    listare_persoane_competitii_multiple(lista_competitii);

    return 0;
}
