#include <iostream>

// num - numarul care va fi descompus
// vec - vectorul de factori primi rezultat
// numar_factori - numarul de factori rezultat
void descompunere_in_factori_primi(int num, int vec[], int &numar_factori) {
    int div = 2;

    while (num > 1) {
        if (num % div == 0) {
            while (num % div == 0) {
                vec[numar_factori++] = div;
                num = num / div;
            }
        }

        div++;
        if (num > 1 && div * div > num) {
            div = num;
        }
    }
}

int main() {
    int n;

    std::cout << "introduceti numarul: ";
    std::cin >> n;

    int factori_primi[100];
    int numar_de_factori = 0;
    descompunere_in_factori_primi(n, factori_primi, numar_de_factori);

    std::cout << "numarul se imparte in " << numar_de_factori << " factori primi: ";
    for (int i = 0; i < numar_de_factori; i++) {
        std::cout << factori_primi[i] << ' ';
    }
    std::cout << "\n";

    return 0;
}
