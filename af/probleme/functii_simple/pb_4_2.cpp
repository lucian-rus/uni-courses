#include <iostream>

// calculeaza `num` la puterea `pow`
int num_to_power(int num, int pow) {
    int result = 1;

    while (pow) {
        result = result * num;
        pow--;
    }

    return result;
}

bool numar_armstrong(int num) {
    int aux = num;

    int vec[100] = {0};
    int numar_cifre = 0;

    // spargem numarul in cifre
    while (num != 0) {
        vec[numar_cifre++] = num % 10;
        num = num / 10;
    }

    // calculam suma cifrelor din numar ridicate la numarul de cifre
    int suma = 0;
    for(int i = 0; i < numar_cifre; i++) {
        suma += num_to_power(vec[i], numar_cifre);
    }         

    // daca suma este egala cu aux, numarul este armstrong
    // aux este folosit ca backup pentru `num` care a fost distrus cand am spart numarul in cifre - proces distructiv
    if (suma == aux) {
        return true;
    }

    return false;
}

int main() {
    int n;

    std::cout << "introduceti numarul: ";
    std::cin >> n;

    std::cout << "numarul este armstrong: " << numar_armstrong(n) << "\n";

    return 0;
}
