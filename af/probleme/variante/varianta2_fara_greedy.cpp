#include <fstream>
#include <iostream>
#include <vector>

// solutia functioneaza prin crearea dinamica de intervale si ajustarea lor in timpul citirii pentru optimizarea solutiei

// declara structura care tine intervalele
typedef struct {
    int maxim;
    int minim;
} interval_t;


// conditii de continere - skip
// | - - - int.min - - - capat_min - - - - capat_max - - - - - - int.max - - |
bool continut_in_interval(interval_t interval, int capat_max, int capat_min) {
    if (interval.minim <= capat_min && capat_max <= interval.maxim) {
        return true;
    }

    return false;
}

// conditii de adiacenta - update
// | - - - capat_min - - - int.min - - - - capat_max - - - - - - int.max - - |
// | - - - int.min - - - capat_min - - - - int.max - - - - - - capat_max - - |
// | - - - capat_min - - - int.min - - - - int.max - - - - - - capat_max - - |
bool adiacent_intervalului(interval_t &interval, int &capat_max, int &capat_min, int &diff) {
    if (capat_min < interval.minim && capat_max <= interval.maxim && interval.minim <= capat_max) {
        diff = abs(capat_min - interval.minim);
        interval.minim = capat_min;
        return true;
    }

    if (interval.minim <= capat_min && interval.maxim < capat_max && capat_min <= interval.maxim) {
        diff = abs(interval.maxim - capat_max);
        interval.maxim = capat_max;
        return true;
    }

    if (capat_min < interval.minim && interval.maxim < capat_max) {
        diff = abs((capat_max - capat_min) - (interval.maxim - interval.minim));
        interval.minim = capat_min;
        interval.maxim = capat_max;
        return true;
    }

    return false;
}

void citire_din_fisier() {
    int n, capat_max, capat_min;

    // variabila care stocheaza intervale
    std::vector<interval_t> intervale;

    // deschidem stream-ul pentru fisier
    std::ifstream fin("/home/lucian-rus/Desktop/dev/school/resources/af/probleme/variante/examen1.txt");
    fin >> n;

    // -5 5
    // -5 5
    // -5 8
    // -5 8, 10 13
    // -5 8, 10 15
    // -5 8, 10 15, 100 100
    int suma = 0;
    for (int i = 0; i < n; i++) {
        fin >> capat_min >> capat_max;

        bool skip = false;
        int diff = 0;
        for (auto &interval : intervale) {
            if (continut_in_interval(interval, capat_max, capat_min)) {
                skip = true;
                break;
            }

            if (adiacent_intervalului(interval, capat_max, capat_min, diff)) {
                skip = true;
                break;
            }
        }


        if (skip == true) {
            suma += diff;
            continue;
        }

        interval_t interval;
        interval.minim = capat_min;
        interval.maxim = capat_max;
        intervale.push_back(interval);

        suma += (capat_max - capat_min);
    }


    for (auto interval : intervale) {
        std:: cout << interval.minim << ' ' << interval.maxim << '\n';
    }

    std::cout << '\n' << suma << '\n';
    fin.close();
}

int main() {
    citire_din_fisier();

    return 0;
}
