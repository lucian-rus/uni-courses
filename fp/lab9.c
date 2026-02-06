#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int capat_min;
    int capat_max;
} interval_t;

int gaseste_interval_for(interval_t *intervale, int n, int target) {
    int len_min = INT32_MAX;
    int ret = - 1;

    for (size_t i = 0; i < n; i++) {
        if (intervale[i].capat_min <= target && target <= intervale[i].capat_max) {
            if (len_min > (intervale[i].capat_max - intervale[i].capat_min)) {
                len_min = (intervale[i].capat_max - intervale[i].capat_min);
                ret = i;
            }
        }
    }

    return ret;
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

    interval_t *intervale = NULL;
    intervale             = (interval_t *)malloc(n * sizeof(interval_t));

    int target = 8;
    for (size_t i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &intervale[i].capat_min, &intervale[i].capat_max);
        printf("%d %d\n", intervale[i].capat_min, intervale[i].capat_max);
    }

    printf("--------------------\n");
    printf("%d\n", gaseste_interval_for(intervale, n, target));

    fclose(fin);
    free(intervale);

    return 0;
}
