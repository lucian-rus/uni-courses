#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

void citire_din_fisier(std::string &s1, std::string &s2) {
    std::ifstream fin("sd/input/cuvinte.txt");

    fin >> s1 >> s2;

    fin.close();
}

// din moment ce avem de folosit `unordered_set`, avem o limitare. 
// cuvintele folosite pot sa aiba doar caractere unice, de ex. `abc` si `abcd`
// `abc` si `abcc` vor fi considerate permutari. pentru a rezolva situatia, ar trebui sa folosim un `unordered_map`
// dar daca il folosim, nu mai are rost folosirea `unordered_set`-ului
bool permutare(const std::string &s1, const std::string &s2) {
    std::unordered_set<char> set;

    // construim set-ul in baza primului cuvant
    for(char c: s1) {
        set.insert(c);
    }

    // verificam daca toate caracterele se regasesc in set. daca nu, returnam false
    for(char c: s2) {
        if(set.find(c) == set.end()) {
            return false;
        }
    }

    return true;
}

int main(void) {
    std::string s1, s2;
    citire_din_fisier(s1, s2);
    std::cout << "am citit " << s1 << " si " << s2 << '\n';

    std::cout << (permutare(s1, s2) ? "este permutare\n" : "nu este permutare\n");
    return 0;
}