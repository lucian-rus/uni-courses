// Problema 2: Vector de vectori alocat dinamic, vectorul k avand k elemente.
// Se calculeaza un vector cu mediile aritmetice ale celor n vectori.

#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cout << "Numarul de vectori n = ";
    std::cin >> n;

    double **v = new double*[n];
    for (int k = 0; k < n; k++) {
        v[k] = new double[k + 1];
        std::cout << "Vectorul " << k + 1 << " (" << k + 1 << " elemente): ";
        for (int j = 0; j <= k; j++) {
            std::cin >> v[k][j];
        }
    }

    double *medii = new double[n];
    for (int k = 0; k < n; k++) {
        double suma = 0;
        for (int j = 0; j <= k; j++) {
            suma += v[k][j];
        }
        medii[k] = suma / (k + 1);
    }

    std::cout << "\nMediile aritmetice:\n";
    std::cout << std::fixed << std::setprecision(2);
    for (int k = 0; k < n; k++) {
        std::cout << "media[" << k + 1 << "] = " << medii[k] << '\n';
    }

    delete[] medii;
    for (int k = 0; k < n; k++) {
        delete[] v[k];
    }
    delete[] v;

    return 0;
}
