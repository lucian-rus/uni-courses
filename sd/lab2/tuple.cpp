#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <tuple>

void read_from_file(std::list<std::tuple<std::string, std::string, int>> &list) {
    std::ifstream fin("Lista1.txt");

    std::string nume;
    std::string prenume;
    int         varsta;
    while (fin >> nume >> prenume >> varsta) {
        list.emplace_back(std::tuple<std::string, std::string, int>(nume, prenume, varsta));
    }
    std::cout << '\n';
}

void afisare(const std::list<std::tuple<std::string, std::string, int>> &list) {
    for (auto item : list) {
        std::cout << std::get<0>(item) << ' ';
        std::cout << std::get<1>(item) << ' ';
        std::cout << std::get<2>(item) << '\n';
    }

    std::cout << '\n';
}

void sortare(std::list<std::tuple<std::string, std::string, int>> &list) {
    list.sort([](const std::tuple<std::string, std::string, int> &tup1, const std::tuple<std::string, std::string, int> &tup2) {
        return (std::get<2>(tup1) > std::get<2>(tup2));
    });
}

int main() {
    std::list<std::tuple<std::string, std::string, int>> list;
    read_from_file(list);
    afisare(list);
    sortare(list);
    std::cout << "dupa sort:\n";
    afisare(list);

    return 0;
}