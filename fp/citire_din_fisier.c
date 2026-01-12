#include <stdio.h>
#include <stdlib.h>

void citire_din_fisier(int ***a, int *n, int *m) {
    FILE *file = fopen("input.in", "r");

    fscanf(file, "%d", n);
    fscanf(file, "%d", m);

    a = malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        a[i] = malloc(*m * sizeof(int));
        for (int j = 0; j < *m; j++) {
            fscanf(file, "%d", a[i][j]);
        }
    }

    fclose(file);
}

void afisare_matrice(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void eliberare_memorie(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    a = NULL;
}

int main() {
    int ***a;
    int   n, m;

    citire_din_fisier(a, &n, &m);
    // afisare_matrice(a, n, m);
    // eliberare_memorie(a, n, m);

    return 0;
}
