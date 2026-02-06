#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capat_min;
    int capat_max;
} interval_t;

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
    intervale             = malloc(n * sizeof(interval_t));

    int len_min = 100000;
    int ret = -1;
    int target;

    scanf("%d", &target);
    for (size_t i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &intervale[i].capat_min, &intervale[i].capat_max);

        if (intervale[i].capat_min <= target && target <= intervale[i].capat_max) {
            if (len_min > (intervale[i].capat_max - intervale[i].capat_min)) {
                len_min = (intervale[i].capat_max - intervale[i].capat_min);
                ret = i;
            }
        }

        printf("%d %d\n", intervale[i].capat_min, intervale[i].capat_max);
    }

    printf("--------------------\n");
    printf("%d\n", ret);

    fclose(fin);
    free(intervale);

    return 0;
}