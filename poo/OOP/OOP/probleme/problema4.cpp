// Problema 4: Functii sablon (template):
//  - minim dintre 3 valori
//  - alocare dinamica a unui vector
//  - maxim dintr-un vector
//  - sortare merge sort
//  - produs a doua matrici
//  - ridicare la putere a unei matrici

#include <iomanip>
#include <iostream>

template <typename T> T minim3(T a, T b, T c) {
    T m = a;
    if (b < m)
        m = b;
    if (c < m)
        m = c;
    return m;
}

template <typename T> T *alocaVector(int n) {
    return new T[n];
}

template <typename T> T maxim(const T *v, int n) {
    T m = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > m)
            m = v[i];
    }
    return m;
}

template <typename T> void interclasare(T *v, int st, int mij, int dr) {
    int n1 = mij - st + 1;
    int n2 = dr - mij;
    T  *L  = new T[n1];
    T  *R  = new T[n2];
    for (int i = 0; i < n1; i++) L[i] = v[st + i];
    for (int j = 0; j < n2; j++) R[j] = v[mij + 1 + j];

    int i = 0, j = 0, k = st;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            v[k++] = L[i++];
        else
            v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <typename T> void mergeSort(T *v, int st, int dr) {
    if (st < dr) {
        int mij = st + (dr - st) / 2;
        mergeSort(v, st, mij);
        mergeSort(v, mij + 1, dr);
        interclasare(v, st, mij, dr);
    }
}

template <typename T> T **alocaMatrice(int m, int n) {
    T **a = new T *[m];
    for (int i = 0; i < m; i++) a[i] = new T[n]();
    return a;
}

template <typename T> void elibereazaMatrice(T **a, int m) {
    for (int i = 0; i < m; i++) delete[] a[i];
    delete[] a;
}

template <typename T> T **produsMatrici(T **a, int m, int n, T **b, int p) {
    // a: m x n, b: n x p, rezultat: m x p
    T **c = alocaMatrice<T>(m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            T s = T();
            for (int k = 0; k < n; k++) {
                s += a[i][k] * b[k][j];
            }
            c[i][j] = s;
        }
    }
    return c;
}

template <typename T> T **putereMatrice(T **a, int n, int k) {
    // matrice patratica n x n, ridicata la puterea k (k >= 1)
    T **rez = alocaMatrice<T>(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) rez[i][j] = a[i][j];

    for (int e = 1; e < k; e++) {
        T **temp = produsMatrici(rez, n, n, a, n);
        elibereazaMatrice(rez, n);
        rez = temp;
    }
    return rez;
}

template <typename T> void afiseazaMatrice(T **a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(8) << a[i][j];
        }
        std::cout << '\n';
    }
}

int main() {
    std::cout << "Minimul dintre 3, 7, 2 = " << minim3(3, 7, 2) << '\n';
    std::cout << "Minimul dintre 1.5, 0.7, 2.3 = " << minim3(1.5, 0.7, 2.3) << '\n';

    int  n        = 6;
    int *v        = alocaVector<int>(n);
    int  valori[] = {5, 2, 8, 1, 9, 3};
    for (int i = 0; i < n; i++) v[i] = valori[i];

    std::cout << "Maximul vectorului = " << maxim(v, n) << '\n';

    mergeSort(v, 0, n - 1);
    std::cout << "Vector sortat: ";
    for (int i = 0; i < n; i++) std::cout << v[i] << ' ';
    std::cout << '\n';
    delete[] v;

    int **A = alocaMatrice<int>(2, 2);
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;

    int **B = alocaMatrice<int>(2, 2);
    B[0][0] = 5;
    B[0][1] = 6;
    B[1][0] = 7;
    B[1][1] = 8;

    int **C = produsMatrici(A, 2, 2, B, 2);
    std::cout << "\nProdusul A * B:\n";
    afiseazaMatrice(C, 2, 2);

    int **P = putereMatrice(A, 2, 3);
    std::cout << "\nA la puterea 3:\n";
    afiseazaMatrice(P, 2, 2);

    elibereazaMatrice(A, 2);
    elibereazaMatrice(B, 2);
    elibereazaMatrice(C, 2);
    elibereazaMatrice(P, 2);

    return 0;
}
