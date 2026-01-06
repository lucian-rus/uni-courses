#include <iostream>

// a - numarul 1 de comparat
// b - numarul 2 de comparat
bool permutari_ciclice(int a, int b) {
    int cifre_a[10] = {0};
    int cifre_b[10] = {0};

    // ne uitam la cifrele fiecarui numar si construim doi vectori de frecventa din ele
    while (a) {
        cifre_a[a % 10]++;
        a = a / 10;
    }

    while (b) {
        cifre_b[b % 10]++;
        b = b / 10;
    }

    // daca oricare numar de cifre e diferit, numerele nu pot fi permutari ciclice
    for(int i = 0; i < 10; i++) {
        if(cifre_a[i] != cifre_b[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int a, b;
    std::cout << "introduceti numerele: ";
    std::cin >> a >> b;

    std::cout << "numerele sunt permutari ciclice: " << permutari_ciclice(a, b) << "\n";

    return 0;
}
