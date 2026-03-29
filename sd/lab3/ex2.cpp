#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

// folosim `using` ca alias pentru tipurile de date complexe
using concurent  = std::tuple<std::string, std::string, int>;
using competitie = std::pair<std::string, std::vector<concurent>>;

// facem citirea din fisier
void citire_liste_din_fisier(std::string path, std::vector<competitie> &v, int &numar_competitii) {
    std::ifstream fin(path);

    fin >> numar_competitii;

    concurent c;
    for (int i = 0; i < numar_competitii; i++) {
        competitie comp;
        int        n;

        fin >> comp.first;
        fin >> n;
        for (int j = 0; j < n; j++) {
            fin >> std::get<0>(c) >> std::get<1>(c) >> std::get<2>(c);
            comp.second.push_back(c);
        }

        v.push_back(comp);
    }

    fin.close();
}

void afisare_date_competitii(std::vector<competitie> &v) {
    for (auto item : v) {
        std::cout << "nume competitie: " << item.first << '\n';

        for (auto c : item.second) {
            std::cout << "  - concurent: " << std::get<0>(c) << ' ' << std::get<1>(c) << ' ' << std::get<2>(c) << '\n';
        }
    }
}

// map<candidat, lista_competitii> -> map<tuple, vector<string>>
struct custom_hash {
    std::size_t operator()(const concurent &el) const {
        return (std::hash<std::string>()(std::get<0>(el)) ^ std::hash<std::string>()(std::get<1>(el))
                ^ std::hash<int>()(std::get<2>(el)));
    }
};

// break-down pentru xor din hash
// 00001010 ^
// 00001100 =
// 00000110 (6)

void afisare_competitii_concurent(const concurent &cnc, const std::vector<std::string> &lista_competitii) {
    std::cout << "concurentul cu numele " << std::get<0>(cnc) << ", prenumele " << std::get<1>(cnc) << " si varsta "
              << std::get<2>(cnc) << " participa la:\n";

    for (auto s : lista_competitii) {
        std::cout << s << ", ";
    }
    std::cout << '\n';
}

void afisare_concurenti_mai_multe_competitii(
    std::unordered_map<concurent, std::vector<std::string>, custom_hash> &tabela_concurenti) {

    // parcurgem tabela
    for (auto cnc : tabela_concurenti) {
        // daca size-ul listei de competitii e mai mare decat 1,
        if (cnc.second.size() > 1) {
            afisare_competitii_concurent(cnc.first, cnc.second);
        }
    }
}

int main(void) {
    int                     numar_competitii;
    std::vector<competitie> competitii;

    // declaram unordered map cu custom hash-ul in semnatura
    std::unordered_map<concurent, std::vector<std::string>, custom_hash> tabela_concurenti;

    citire_liste_din_fisier("sd/lab3/ex2.txt", competitii, numar_competitii);
    afisare_date_competitii(competitii);

    for (auto comp : competitii) {
        for (auto cnc : comp.second) {
            tabela_concurenti[cnc].push_back(comp.first);
        }
    }

    afisare_concurenti_mai_multe_competitii(tabela_concurenti);

    concurent c_input;
    std::cin >> std::get<0>(c_input) >> std::get<1>(c_input) >> std::get<2>(c_input);
    afisare_competitii_concurent(c_input, tabela_concurenti[c_input]);

    return 0;
}