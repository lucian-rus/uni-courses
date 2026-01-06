#include <iostream>

int main() {
    int vec[100];
    int n;

    // vector de frecventa
    int frq[100] = {0};
    int suma     = 0;
    int cnt_elem = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
        frq[vec[i]]++;

        // daca un element apare de mai mult de doua ori, deja a fost extras din suma. dam direct skip
        if (frq[vec[i]] > 2) {
            continue;
        }

        // daca vectorul apare de doua ori, il extragem din suma
        if (frq[vec[i]] == 2) {
            suma -= vec[i];
            cnt_elem--;
            continue;
        }

        // adaugam toate elemenetele in suma
        suma += vec[i];
        cnt_elem++;
    }

    std::cout << suma / cnt_elem << "\n";

    return 0;
}
