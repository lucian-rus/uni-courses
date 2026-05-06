#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define ITEMS 10

long buffer[ITEMS];
int  head = 0, tail = 0;

sem_t free_slots, full_slots;

pthread_mutex_t mutex;
struct timespec delay;

long produce_item(void) {
    long item = random() % 256;
    printf("producing %d\n", item);

    return item;
}

// functia ia ca param `consumer_id` ca sa ne ajute sa identificam din ce consumer a fost chemata
void consume_item(long item, int consumer_id) {
    printf("consuming %d from id: %d\n", item, consumer_id);
}

void producer_function(void) {
    while (1) {
        sem_wait(&free_slots);
        pthread_mutex_lock(&mutex);

        if ((tail + 1) % ITEMS != head) {
            buffer[tail] = produce_item();
            tail         = (tail + 1) % ITEMS;
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&full_slots);

        nanosleep(&delay, NULL);
    }
}

void consumer_function1(void) {
    while (1) {
        sem_wait(&full_slots);
        pthread_mutex_lock(&mutex);

        if (head != tail) {
            consume_item(buffer[head], 1);
            head = (head + 1) % ITEMS;
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&free_slots);
    }
}

void consumer_function2(void) {
    while (1) {
        sem_wait(&full_slots);
        pthread_mutex_lock(&mutex);

        if (head != tail) {
            consume_item(buffer[head], 2);
            head = (head + 1) % ITEMS;
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&free_slots);
    }
}

int main(int argc, char *argv[]) {
    pthread_t producer;
    // ave, nevoie de un thread pentru un consumator aditional
    pthread_t consumer_thread;

    // 250 msec
    delay.tv_sec  = 0;
    delay.tv_nsec = 250000000;

    sem_init(&free_slots, 0, ITEMS - 1);
    sem_init(&full_slots, 0, 0);

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&producer, NULL, (void *)&producer_function, NULL);

    // thread doar pentru consumer1, consumer2 ramane in main thread
    pthread_create(&consumer_thread, NULL, (void *)&consumer_function1, NULL);
    consumer_function2();
}
