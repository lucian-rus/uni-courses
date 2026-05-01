#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void citire_fin_fisier(std::vector<std::string> &lista_cuv) {
    std::ifstream fin("sd/input/anagrame.txt");

    std::string aux;
    while (fin >> aux) {
        lista_cuv.push_back(aux);
    }

    fin.close();
}

// pentru cazul specific din exemplu, e suficient o functie de hashing minimala
int hash_calculator(const std::string &s) {
    int res_hash = 0;
    // adunam codul char-ului la un total
    for (char c : s) {
        res_hash += c;
    }

    return res_hash;
}

void anagrame(const std::vector<std::string> &lista_cuv) {
    // facem un map de liste de string in care retinem cuvintele
    std::unordered_map<int, std::vector<std::string>> map;

    for (auto cuv : lista_cuv) {
        // int-ul e dat de o functie de hashing definita de noi
        int key = hash_calculator(cuv);
        map[key].push_back(cuv);
    }

    // listam anagramele
    for (auto it = map.begin(); it != map.end(); it++) {
        for (auto cuv : it->second) {
            std::cout << cuv << ' ';
        }
        std::cout << '\n';
    }
}

int main(void) {
    std::vector<std::string> lista_cuv;
    citire_fin_fisier(lista_cuv);
    anagrame(lista_cuv);

    return 0;
}