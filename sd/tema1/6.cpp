#include <algorithm>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>

void citire_intervale(std::vector<std::pair<int, int>> &intervale) {
    std::ifstream fin("intervale.txt");

    int first, second;
    while (fin >> first >> second) {
        intervale.push_back(std::pair<int, int>(first, second));
    }

    fin.close();
}

int determina_intervalul(std::vector<std::pair<int, int>> &intervale, const int &target) {
    // sortam intervalele in functie de primul item
    std::sort(intervale.begin(), intervale.end(),
              [](const std::pair<int, int> &a, const std::pair<int, int> &b) { return a.first < b.first; });

    int idx = -1;
    // max int32
    int minim = 2147483647;

    // complexitate worst case -> o(n)
    // nu mi-e clar cum ar trebui sa folosesc cautare binara considerand ca trebuie gasit nu doar intervalul
    // ci si cel de lungime minima, lucru care necesita parcurgerea cel putin o data a tuturor intervalelor valide
    for (int i = 0; i < intervale.size(); i++) {
        // daca numarul nostru cautat depaseste cel mai mic item din
        if (target < intervale[i].first) {
            break;
        }

        // check aditional pentru intervale care sunt mai mici decat numarul cautat
        if (target > intervale[i].second) {
            continue;
        }

        int len = intervale[i].second - intervale[i].first;
        if (len < minim) {
            minim = len;
            idx   = i;
        }
    }

    return idx;
}

int main() {
    std::vector<std::pair<int, int>> intervale;
    citire_intervale(intervale);

    int idx = determina_intervalul(intervale, 8);
    if(idx == -1) {
        std::cout << "nu s-a gasit un interval\n";
    }
    else {
        std::cout << '[' << intervale[idx].first << ", " << intervale[idx].second << "]\n";
    }

    return 0;
}