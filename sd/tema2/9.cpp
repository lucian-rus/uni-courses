#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using Produse = std::vector<std::string>;

void citire_din_fisier(std::vector<Produse> &lista_magazine) {
    std::ifstream fin("sd/input/magazine.txt");

    int nr_mag;
    fin >> nr_mag;
    while (nr_mag--) {

        int         nr_prod;
        Produse     lista_produse;
        std::string aux;
        fin >> nr_prod;
        while (nr_prod--) {
            fin >> aux;
            lista_produse.push_back(aux);
        }

        lista_magazine.push_back(lista_produse);
    }

    fin.close();
}

void determinare_max_produse_unice(const std::vector<Produse> &lista_magazine) {
    std::unordered_map<std::string, int> map;

    // mergem de doua ori prin lista de produse a fiecarui magazin, o data pentru a creea map-ul
    for (auto mag : lista_magazine) {
        for (auto prod : mag) {
            map[prod]++;
            // std::cout << prod << ' ';
        }
        // std::cout << '\n';
    }

    int mag_max_prod       = -1;
    int poz_magazin_cautat = -1;
    // o data pentru a determina care magazin are cele mai multe produse unice
    for (int i = 0; i < lista_magazine.size(); i++) {
        int curr_cnt = 0;
        // map
        for (auto prod : lista_magazine[i]) {
            if (map[prod] == 1) {
                curr_cnt++;
            }
        }

        std::cout << "nr prod unice pt " << i << ": " << curr_cnt << '\n';

        if (curr_cnt > mag_max_prod) {
            poz_magazin_cautat = i;
            mag_max_prod       = curr_cnt;
        }
    }

    // dam +1 ca sa fie mai "human readable"
    std::cout << "magazinul cu cele mai multe produse unice este magazinul nr. " << poz_magazin_cautat + 1 << '\n';
}

int main(void) {
    std::vector<Produse> lista_magazine;
    citire_din_fisier(lista_magazine);

    determinare_max_produse_unice(lista_magazine);

    return 0;
}
