#include <fstream>
#include <iostream>
#include <queue>
#include <time.h>
#include <tuple>

// declarations
using Sarcina = std::tuple<std::string, int, int>;

struct Comparator {
    bool operator()(const Sarcina &a, const Sarcina &b) {
        int prio1 = std::get<1>(a);
        int prio2 = std::get<1>(b);

        if (prio1 < prio2) {
            return true;
        }
        else if (prio1 == prio2) {
            int dur1 = std::get<2>(a);
            int dur2 = std::get<2>(b);

            return (dur1 <= dur2);
        }

        return false;
    }
};

using PrioQ = std::priority_queue<Sarcina, std::vector<Sarcina>, Comparator>;

std::string ia_nume_sarcina(const int &num) {
    if (num == 0) {
        return std::string("comanda_noua");
    }
    if (num == 1) {
        return std::string("rezolva_corespondenta");
    }
    if (num == 2) {
        return std::string("livreaza_intern");
    }
    if (num == 3) {
        return std::string("livreaza_extern");
    }

    return std::string("calculeaza_plati");
}

void generare(PrioQ &queue) {
    int nume   = rand() % 5;
    int prio   = rand() % 10;
    int durata = rand() % 10;

    Sarcina s;
    std::get<0>(s) = ia_nume_sarcina(nume);
    std::get<1>(s) = prio;
    std::get<2>(s) = durata;
    queue.push(s);
}

void generare_lista(PrioQ &queue) {
    std::srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        generare(queue);
    }
}

void afisare(PrioQ &queue) {
    int idx = 0;
    while (!queue.empty()) {
        auto item = queue.top();
        std::cout << std::get<0>(item) << ' ' << std::get<1>(item) << ' ' << std::get<2>(item) << '\n';
        queue.pop();

        if (idx < 6) {
            generare(queue);
            idx++;
        }
    }
}

int main(void) {
    PrioQ queue;

    generare_lista(queue);
    afisare(queue);

    return 0;
}
