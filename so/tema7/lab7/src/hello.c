#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

// structura care ne permite sa transmitem o variabila de prioritate alaturi de mesaj
// pornirea thread-urile intr-o ordine data necesita o schema de sincronizare specifica
// in cazul de fata optam pentru o variabila care sa ne permita acest lucru
typedef struct {
    char msg[24]; // alocare static pentru ca e mai usor
    int  prio;
} context_t;

sem_t thread2_start;

void print_message_function(void *ptr) {
    // daca avem prio 2, asteptam ca semaforul sa fie setat
    if (((context_t *)ptr)->prio == 2) {
        sem_wait(&thread2_start);
    }

    printf("%s ", ((context_t *)ptr)->msg);

    // daca avem prio 1, setam semaforul
    if (((context_t *)ptr)->prio == 1) {
        sem_post(&thread2_start);
    }
}

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2;

    // numar mai mare -> prio mai mica
    context_t msg1 = {
        .prio = 1,
        .msg  = "Hello",
    };
    context_t msg2 = {
        .prio = 2,
        .msg  = "world",
    };

    // initializam cu 0 pentru ca thread2 sa nu porneasca
    sem_init(&thread2_start, 0, 0);

    // trimitem structurile prin cast la void
    pthread_create(&thread1, NULL, (void *)&print_message_function, (void *)&msg1);
    pthread_create(&thread2, NULL, (void *)&print_message_function, (void *)&msg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    exit(0);
}
