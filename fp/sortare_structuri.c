#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[31];
    int  varsta;
} persoana_t;

void sortare_persoane(persoana_t *pers_list, int n) {
    persoana_t aux;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (pers_list[i].varsta < pers_list[j].varsta) {
                aux.varsta = pers_list[i].varsta;
                strncpy(aux.nume, pers_list[i].nume, 31);

                pers_list[i].varsta = pers_list[j].varsta;
                strncpy(pers_list[i].nume, pers_list[j].nume, 31);

                pers_list[j].varsta = aux.varsta;
                strncpy(pers_list[j].nume, aux.nume, 31);
            }

            if (pers_list[i].varsta == pers_list[j].varsta) {
                if (strcmp(pers_list[i].nume, pers_list[j].nume) < 0) {
                    aux.varsta = pers_list[i].varsta;
                    strncpy(aux.nume, pers_list[i].nume, 31);

                    pers_list[i].varsta = pers_list[j].varsta;
                    strncpy(pers_list[i].nume, pers_list[j].nume, 31);

                    pers_list[j].varsta = aux.varsta;
                    strncpy(pers_list[j].nume, aux.nume, 31);
                }
            }
        }
    }
}

int main() {
    FILE *fin = fopen("input", "r");
    int   n;

    if (fin == NULL) {
        printf("Eroare fisier!\n");
        return 1;
    }

    /* citire */
    fscanf(fin, "%d", &n);
    printf("%d\n", n);

    persoana_t *pers_list = NULL;
    pers_list             = malloc(n * sizeof(persoana_t));

    for (size_t i = 0; i < n; i++) {
        fscanf(fin, "%s %d", &pers_list[i].nume, &pers_list[i].varsta);
        printf("%s %d\n", pers_list[i].nume, pers_list[i].varsta);
    }

    printf("--------------------\n");
    sortare_persoane(pers_list, n);

    for (size_t i = 0; i < n; i++) {
        printf("%s are %d ani\n", pers_list[i].nume, pers_list[i].varsta);
    }

    free(pers_list);
    fclose(fin);

    return 0;
}