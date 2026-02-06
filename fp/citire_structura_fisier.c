#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char  model[31];
    char  combustibil;
    float putere;
} Autoturism;

int main() {
    FILE *f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int n;

    fscanf(f, "%d", &n);

    Autoturism *autoturism = (Autoturism *)malloc(n * sizeof(Autoturism));

    for (int i = 0; i < n; i++) {
        fscanf(f, "%s %c %f", autoturism[i].model, &autoturism[i].combustibil, &autoturism[i].putere);
    }

    for (int i = 0; i < n; i++) {
        printf("(%s, %s, %.2f)\n", autoturism[i].model, autoturism[i].combustibil, autoturism[i].putere);
    }

    fclose(f);
}
