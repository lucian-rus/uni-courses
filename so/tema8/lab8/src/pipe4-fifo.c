#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define FIFO_FILE "shared_fifo"

void proces_io(void) {
    int   fifo = open(FIFO_FILE, O_WRONLY); // deschidem fifo pt scriere
    FILE *file = fopen("input.txt", "r");

    int a;
    int b;
	fscanf(file, "%d %d", &a, &b);

	// scriem numerele in fifo dupa citire
    write(fifo, &a, sizeof(int));
    write(fifo, &b, sizeof(int));

    fclose(file);

    // inchidem si redeschidem ca sa putem citi rezultatul
    close(fifo);
    fifo = open(FIFO_FILE, O_RDONLY);

    int total_sum = 0;
    read(fifo, &total_sum, sizeof(int));
    printf("suma: %d\n", total_sum);

    close(fifo);
}

void proces_calcul(void) {
    int fifo = open(FIFO_FILE, O_RDONLY);

    int number;
    int sum = 0;

    // citim numar cu numar din fifo si facem suma
    while (read(fifo, &number, sizeof(int)) > 0) {
        sum += number;
    }

    close(fifo);
    fifo = open(FIFO_FILE, O_WRONLY);
    write(fifo, &sum, sizeof(int));

    close(fifo);
}

int main() {
    mknod(FIFO_FILE, S_IFIFO | 0666, 0);

    pid_t pid = fork();
    if (pid == 0) {
        proces_calcul();
    }
    else {
        proces_io();
        wait(NULL);
    }

    return 0;
}