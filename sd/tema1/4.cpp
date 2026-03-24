#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

typedef struct _Fractie {
    int numitor;
    int numarator;

    int cmmdc(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }

        while (a != b) {
            if (a > b) {
                a = a - b;
            }
            else {
                b = b - a;
            }
        }
        return a;
    }

    void reductie(void) {
        if (numitor == 0) {
            return;
        }

        int divizor = cmmdc(numarator, numitor);

        numarator /= divizor;
        numitor /= divizor;
    };

    void aduna(struct _Fractie f) {
        numarator = numarator * f.numitor + f.numarator * numitor;
        numitor   = numitor * f.numitor;
    }

    void scade(struct _Fractie f) {
        numarator = numarator * f.numitor - f.numarator * numitor;
        numitor   = numitor * f.numitor;
    }
    void inmulteste(struct _Fractie f) {
        numarator *= f.numarator;
        numitor *= f.numitor;
    }

    void imparte(struct _Fractie f) {
        if (f.numarator != 0) {
            numarator *= f.numitor;
            numitor *= f.numarator;
        }
    }

    float compara(struct _Fractie f) {
        return tofloat() - f.tofloat();
    }

    float tofloat(void) {
        if (numitor == 0) {
            return 0;
        }
        return (float)numarator / (float)numitor;
    };

    void print(void) {
        std::cout << numarator << '/' << numitor << '\n';
    }

    void citire(void) {
        std::ifstream fin("sd/input/fractii.txt");
        fin >> numarator >> numitor;
        fin.close();
    }

} Fractie_t;

// nu folosim functia built-in de citire pentru ca ar fi inafara scopului problemei sa facem
// tratarea inaintarii citirii in fisier
void citire_fractii(std::vector<Fractie_t> &fractii) {
    std::ifstream fin("sd/input/fractii.txt");

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

    for(Fractie_t &f: fractii) {
        f.reductie();
    }
    afisare_fractii(fractii);

    std::sort(fractii.begin(), fractii.end(), [](Fractie_t &f1, Fractie_t &f2) { return ((f1.tofloat() - f2.tofloat()) > 0); });
    afisare_fractii(fractii);

    // Fractie_t f;
    // f.numarator = 10;
    // f.numitor   = 3;

    // Fractie_t f1;
    // f1.numarator = 3;
    // f1.numitor   = 6;

    // f.aduna(f1);
    // f.scade(f1);
    // f.reductie();
    // std::cout << f.numarator << '/' << f.numitor << '\n';

    return 0;
}