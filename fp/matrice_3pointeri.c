#include <stdio.h>
#include <stdlib.h>

int citire_numar(int ***mat, int i, int j) {
    printf("[%d,%d]:", i, j);
    scanf("%d", &((*mat)[i][j]));

    return 0;
}

int linie_max(int **mat, int linii, int col) {
    int suma_max       = -1;
    int index_suma_max = -1;

    for (int i = 0; i < linii; i++) {
        int suma_linie_currenta = 0;

        for (int j = 0; j < col; j++) {
            suma_linie_currenta += mat[i][j];
        }

        if (suma_max < suma_linie_currenta) {
            suma_max       = suma_linie_currenta;
            index_suma_max = i;
        }
    }

    return index_suma_max;
}

int transpusa(int **mat, int *linii, int *col) {
    int **aux = NULL;

    aux = (int **)calloc(*col, sizeof(int *));
    for (int i = 0; i < *col; i++) {
        aux[i] = (int *)calloc(*linii, sizeof(int));
    }

    for (int i = 0; i < *linii; i++) {
        for (int j = 0; j < *col; j++) {
            aux[j][i] = mat[i][j];
        }
    }

    for (int i = 0; i < *linii; i++) {
        free(mat[i]);
    }

    for (int i = 0; i < *col; i++) {
        mat[i] = aux[i];
    }

    int temp = *linii;
    *linii   = *col;
    *col     = temp;

    free(aux);
    return 0;
}

int printeaza_matrice(int **mat, int linii, int col) {
    printf("---------------------\n");
    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linii, col;
    printf("linii: ");
    scanf("%d", &linii);
    printf("coloane: ");
    scanf("%d", &col);

    int **mat = NULL;

    mat = (int **)calloc(linii, sizeof(int *));
    for (int i = 0; i < linii; i++) {
        mat[i] = (int *)calloc(col, sizeof(int));
        for (int j = 0; j < col; j++) {
            citire_numar(&mat, i, j);
        }
    }

    printeaza_matrice(mat, linii, col);
    printf("suma maxima pe linia: %d\n", linie_max(mat, linii, col));
    transpusa(mat, &linii, &col);
    printeaza_matrice(mat, linii, col);

    for (int i = 0; i < col; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}