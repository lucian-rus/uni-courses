#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// se putea face mai optim daca citeam caracterele direct intr-un map file
void citire_din_fisier(std::vector<char> &cuvant) {
    std::ifstream fin("sd/input/cuvant.txt");

    char c;
    while (fin >> c) {
        cuvant.push_back(c);
    }

    fin.close();
}

// din cauza constrangerilor din cerinta, optam pentru o solutie mai putin optima
// si construim map-ul in interiorul functiei
std::string palindrom(const std::vector<char> &cuvant) {
    std::unordered_map<char, int> map;

    std::string palindrom = "";
    for (char c : cuvant) {
        map[c]++;
    }

    bool singur_multiplu = false;
    char singur;
    for (auto it = map.begin(); it != map.end(); it++) {
        // daca avem un nr impar de litere -> iesim cu probleme
        if (it->second % 2 == 1) {
            // tratam cazul in care avem o singura litera care nu are pereche -> caz valid de palindrom
            if (singur_multiplu == false) {
                singur          = it->first;
                singur_multiplu = true;
            }
            else {
                return "";
            }
        }

        // >1 pentru a trata cazul cu singur caracter ramas valid
        while (it->second > 1) {
            palindrom += it->first;
            palindrom = it->first + palindrom;

            it->second = it->second - 2;
        }
    }

    // daca avem un singur element, il bagam la jumatatea cuvantului
    if (singur_multiplu == true) {
        palindrom.insert(palindrom.size() / 2, 1, singur);
    }

    return palindrom;
}

int main(void) {
    std::vector<char> cuvant;
    citire_din_fisier(cuvant);

    std::cout << "am citit: ";
    for (char c : cuvant) {
        std::cout << c;
    }

    std::cout << '\n';

    // tattt  - valid
    // tattta - valid
    // ttt    - valid
    // hello  - invalid
    std::string plndrm = palindrom(cuvant);
    if (plndrm != "") {
        std::cout << "palindrom: " << plndrm << '\n';
    }
    else {
        std::cout << "nu este palindrom!\n";
    }
}