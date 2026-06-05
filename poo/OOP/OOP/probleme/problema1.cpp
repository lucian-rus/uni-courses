// Problema 1: Citirea si afisarea unei matrici de valori reale,
// fiecare element aliniat la dreapta pe 8 caractere, cu 2 zecimale.

#include <iostream>
#include <iomanip>

int main() {
    int m, n;
    std::cout << "Numarul de linii: ";
    std::cin >> m;
    std::cout << "Numarul de coloane: ";
    std::cin >> n;

    double **a = new double*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new double[n];
    }

    std::cout << "Introduceti elementele matricei:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    std::cout << "\nMatricea formatata:\n";
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(8) << std::right << a[i][j];
        }
        std::cout << '\n';
    }

    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
