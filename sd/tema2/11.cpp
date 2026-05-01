#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <tuple>

using Dreptunghi = std::tuple<int, int, int, int>;

// comparator custom care sa ne aranjeze dreptunghiurile in functie de arie
struct CompCustom {
    bool operator()(const Dreptunghi &a, const Dreptunghi &b) const {
        // dreptunghi 1
        int x11 = std::get<0>(a);
        int y11 = std::get<1>(a);
        int x12 = std::get<2>(a);
        int y12 = std::get<3>(a);

        // dreptunghi 2
        int x21 = std::get<0>(b);
        int y21 = std::get<1>(b);
        int x22 = std::get<2>(b);
        int y22 = std::get<3>(b);

        int arie1 = std::abs(x12 - x11) * std::abs(y12 - y11);
        int arie2 = std::abs(x22 - x21) * std::abs(y22 - y21);

        return arie1 < arie2;
    }
};

void citire_din_fisier(std::map<Dreptunghi, int, CompCustom> &lista_drept) {
    std::ifstream fin("sd/input/dreptunghiuri.txt");

    int x1, x2, y1, y2, id;
    while (fin >> id >> x1 >> y1 >> x2 >> y2) {
        lista_drept[Dreptunghi(x1, y1, x2, y2)] = id;
    }

    fin.close();
}

// verificam daca un punct e oriunde intr-un dreptunghi. lista e deja sortata
void verifica_punct(const std::map<Dreptunghi, int, CompCustom> &lista_drept) {
    int x, y;

    std::cout << "introdu x: ";
    std::cin >> x;
    std::cout << "introdu y: ";
    std::cin >> y;

    for (auto it = lista_drept.begin(); it != lista_drept.end(); it++) {
        int x1 = std::get<0>(it->first);
        int y1 = std::get<1>(it->first);
        int x2 = std::get<2>(it->first);
        int y2 = std::get<3>(it->first);
        // std::cout << "testing " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        if (std::min(x1, x2) <= x && x <= std::max(x1, x2) && std::min(y1, y2) <= y && y <= std::max(y1, y2)) {
            std::cout << "punctul intra in dreptunghiul cu id: " << it->second << '\n';
            return;
        }
    }

    std::cout << "punctul nu se gaseste in niciun dreptunghi!\n";
}

int main(void) {
    // sortam automat pe baza custom comparatorului
    // explicatie pentru care cheile sunt definite ca fiind coordonatele si nu id-ul se gaseste si la pb12 (situatie similara)
    std::map<Dreptunghi, int, CompCustom> lista_drept;
    citire_din_fisier(lista_drept);

    verifica_punct(lista_drept);

    return 0;
}