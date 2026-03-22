#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

typedef struct _Fractie {
    int numitor;
    int numarator;

    void reductie(void) {

    };

    float aduna(struct _Fractie f) {
    }

    float scade(struct _Fractie f) {
    }

    float inmulteste(struct _Fractie f) {
        numarator *= f.numarator;
        numitor *= f.numitor;
    }

    float imparte(struct _Fractie f) {
        numarator *= f.numitor;
        numitor *= f.numarator;
    }

    float compara(struct _Fractie f) {
    }

    float tofloat(void) {
        return (float)((float)numarator / (float)numitor);
    };
} Fractie_t;

void citire_fractii(std::vector<Fractie_t> &fractii) {
    std::ifstream fin("fractii.txt");

    int numarator;
    int numitor;
    while (fin >> numarator >> numitor) {
        Fractie_t f;
        f.numarator = numarator;
        f.numitor   = numitor;
        fractii.push_back(f);
    }

    fin.close();
}

void afisare_fractii(const std::vector<Fractie_t> &fractii) {
    for (Fractie_t f : fractii) {
        std::cout << f.numarator << '/' << f.numitor << ' ';
    }
    std::cout << '\n';

    // afisare calcul
    for (Fractie_t f : fractii) {
        std::cout << f.tofloat() << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<Fractie_t> fractii;
    citire_fractii(fractii);
    afisare_fractii(fractii);

    // sortare eficienta
    std::sort(fractii.begin(), fractii.end(), [](Fractie_t &f1, Fractie_t &f2) { return ((f1.tofloat() - f2.tofloat()) > 0); });
    afisare_fractii(fractii);

    return 0;
}