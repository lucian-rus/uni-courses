// De-a lungul principalei străzi din orașul nostru există n plopi, pentru fiecare
// cunoscându-se înălțimea. Primarul orașului dorește ca plopii să aibă înălțimile în ordine descrescătoare.
// Pentru aceasta, este posibilă tăierea dintr-un plop a unei bucăți – este o tehnică ecologică,
// nevătămătoare, în urma căreia plopul nu are de suferit. Plopii nu pot fi înălțați în niciun fel. Determinați
// numărul minim de plopi din care se va tăia și lungimea totală minimă a bucăților tăiate

#include <algorithm>
#include <iostream>
#include <vector>

void citire_vector_unidimensional(std::vector<int> &vec, int dictionar[]) {
    int n;
    std::cout << "dimensiune vector: ";
    std::cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
        // stocam pozitia la care se gaseste pentru acces ulterior rapid
        dictionar[vec[i]] = i;
    }
}

void afisare_vector_unidimensional(std::vector<int> vec) {
    for (int val : vec) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

int main() {
    int n;

    // simulam un "dictionar"
    int dictionar[1000]        = {0};
    int dictionar_sortat[1000] = {0};

    std::vector<int> inaltimi;
    citire_vector_unidimensional(inaltimi, dictionar);

    std::vector<int> inaltimi_sortat = inaltimi;
    std::sort(inaltimi_sortat.begin(), inaltimi_sortat.end());

    for (int i = 0; i < inaltimi_sortat.size(); i++) {
        dictionar_sortat[inaltimi_sortat[i]] = i;
    }

    int suma_taieri = 0;
    for (int i = 0; i < inaltimi.size(); i++) {

    }

    afisare_vector_unidimensional(inaltimi);

    return 0;
}
