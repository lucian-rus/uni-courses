// Se da o bucata de hârtie de dimensiune A x B. Hartia se taie în patrate de orice
// dimensiune. Gasiți numarul minim de patrate în care poate taia.
// Exemplu 13 x 29 = 2 (13x13) + 4 (3x3) + 3 (1x1) = 9 bucați

#include <iostream>
#include <vector>

int main() {
    int latime, lungime;
    std::cin >> latime >> lungime;

    std::vector<int> laturi;
    while (lungime > 0 && latime > 0) {
        int latura_patrat;
        if (latime <= lungime) {
            latura_patrat = latime;
            lungime -= latura_patrat;
        }
        else {
            latura_patrat = lungime;
            latime -= latura_patrat;
        }

        laturi.push_back(latura_patrat);
    }

    for(auto val : laturi) {
        std::cout << val << ' ';
    }

    std::cout << '\n' << laturi.size() << '\n';

    return 0;
}
