#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

void citire_din_fisier(std::vector<std::string> &v1, std::vector<std::string> &v2) {
    std::ifstream fin1("sd/lab3/ex1-1.txt");
    std::ifstream fin2("sd/lab3/ex1-1.txt");

    std::string aux;
    while (fin1 >> aux) {
        v1.push_back(aux);
    }

    while (fin2 >> aux) {
        v2.push_back(aux);
    }

    fin1.close();
    fin2.close();
}

void citire_din_fisier_modular(std::string path, std::vector<std::string> &v) {
    std::ifstream fin(path);

    std::string aux;
    while (fin >> aux) {
        v.push_back(aux);
    }

    fin.close();
}

std::vector<std::string> verificare_intersectie(std::vector<std::string> &v1, std::vector<std::string> &v2) {

    std::unordered_set<std::string> set;

    std::vector<std::string> intersectii;
    for (auto s : v1) {
        set.insert(s);
    }

    for (auto s : v2) {
        if (set.find(s) == set.end()) {
            set.insert(s);
        }
        else {
            intersectii.push_back(s);
        }
    }

    // for (auto s : intersectii) {
    //     std::cout << s << " ";
    // }
    // std::cout << '\n';
    return intersectii;
}

void afisare_in_fisier(const std::vector<std::string> &intersectii) {
    std::ofstream fout("output.txt");

    fout << "intersectia este:\n";
    for (auto s : intersectii) {
        fout << s << ", ";
    }

    fout << '\n';
    fout.close();
}

int main() {
    std::vector<std::string> v1, v2;
    citire_din_fisier_modular("sd/lab3/ex1-1.txt", v1);
    citire_din_fisier_modular("sd/lab3/ex1-2.txt", v2);

    std::vector<std::string> intersectii = verificare_intersectie(v1, v2);

    // std::cout << "in main: ";
    // for (auto s : intersectii) {
    //     std::cout << s << " ";
    // }
    // std::cout << '\n';

    afisare_in_fisier(intersectii);

    return 0;
}