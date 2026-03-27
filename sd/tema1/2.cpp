#include <algorithm>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>

void citire_puncte(std::vector<std::pair<int, int>> &puncte) {
    int x, y;

    std::ifstream fin("sd/input/puncte.txt");
    while (fin >> x >> y) {
        std::pair<int, int> aux(x, y);
        puncte.push_back(aux);
    }

    fin.close();
}

/*
un dreptunghi are proprietatile urmatoare:
x1,y1               x2,y1
---------------------
|                   |
|                   |
|                   |
|                   |
---------------------
x1,y2               x2,y2

if((pair[i].first == pair[j].first &&
   pair[i].second == pair[j].second) &&
   pair[i].first == pair[j].first &&
   pair[i].first == pair[j].first  )
*/ 

int main() {
    std::vector<std::pair<int, int>> puncte;
    citire_puncte(puncte);
    for (auto item : puncte) {
        std::cout << item.first << ' ' << item.second << '\n';
    }

    std::cout << "-------------------------\n";
    // std::sort(puncte.begin(), puncte.end(), [](std::pair<int, int> &a, std::pair<int, int> &b) { return a.first < b.first; });
    
    for (auto item : puncte) {
        std::cout << item.first << ' ' << item.second << '\n';
    }

    return 0;
}