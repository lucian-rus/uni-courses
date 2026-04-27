#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

void citire_din_fisier(std::vector<int> &v) {
    std::ifstream fin("sd/input/duplicate.txt");

    int num;
    while (fin >> num) {
        v.push_back(num);
    }

    fin.close();
}

bool distanta_maxima(const std::vector<int> &v, const int dist) {
    std::unordered_map<int, int> map;

    // mergem prin array
    for (int i = 0; i < v.size(); i++) {
        int capat = i + dist;
        if (capat > v.size()) {
            capat = v.size();
        }

        // formam "subsiruri" de max `dist` si adaugam elementele in map. daca avem mai mult de doua
        // in orice moment, returnam true
        for (int j = i; j < capat; j++) {
            std::cout << v[j] << ' ';
            map[v[j]]++;

            if (map[v[j]] > 1) {
                std::cout << '\n';
                return true;
            }
        }

        map.clear();
        std::cout << '\n';
    }

    // daca ajungem pana aici, nu am gasit nimic
    return false;
}

int main(void) {
    std::vector<int> numere;
    citire_din_fisier(numere);

    bool val = distanta_maxima(numere, 4);
    std::cout << "in distanta maxima: " << val << '\n';

    return 0;
}