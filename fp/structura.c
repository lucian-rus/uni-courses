#include <stdio.h>

typedef struct {
    int zi;
    int luna;
    int an;
} data;

typedef struct {
    data  data_nasterii;
    float media;
} elev;

int main() {
    elev ev = {
        .data_nasterii = {
            .zi   = 1,
            .luna = 12,
            .an   = 1998,
        },
        .media = 7.38,
    };
    printf("zi: %d\n", ev.data_nasterii.zi);
    printf("luna: %d\n", ev.data_nasterii.luna);
    printf("an: %d\n", ev.data_nasterii.an);
    printf("media: %d\n", ev.media);

    return 0;
}