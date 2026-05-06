#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ITEMS 10

long buffer[ITEMS];
int  head = 0, tail = 0;

pthread_mutex_t mutex;
pthread_cond_t  thread_condition;
struct timespec delay;

// functia produce ia ca param `prod_id` care ne ajuta sa determinam din ce functie s-a apelat productia
long produce_item(int prod_id) {
    long item = random() % 256;
    printf("producing %d on id: %d\n", item, prod_id);

    return item;
}

void consume_item(long item) {
    printf("consuming %d\n", item);
}

void producer_function1(void) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if ((tail + 1) % ITEMS != head) {
            buffer[tail] = produce_item(1);
            tail         = (tail + 1) % ITEMS;
        }
        pthread_mutex_unlock(&mutex);

        pthread_cond_broadcast(&thread_condition);
        nanosleep(&delay, NULL);
    }
}

void producer_function2(void) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if ((tail + 1) % ITEMS != head) {
            buffer[tail] = produce_item(2);
            tail         = (tail + 1) % ITEMS;
        }
        pthread_mutex_unlock(&mutex);

        // facem broadcast pentru ca avem doi consumeri. refolosim, in mare, codul din exercitiul trecut
        pthread_cond_broadcast(&thread_condition);
        nanosleep(&delay, NULL);
    }
}

void consumer_function(void) {
    while (1) {
        if (head != tail) {
            consume_item(buffer[head]);
            head = (head + 1) % ITEMS;
        }
        // putem sa comentam lock/unlock pentru ca `cond_wait` o sa faca unlock apoi lock pentru noi
        pthread_cond_wait(&thread_condition, &mutex);
    }
}

int main(int argc, char *argv[]) {
    pthread_t producer;

    // 250 msec
    delay.tv_sec  = 0;
    delay.tv_nsec = 250000000;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&thread_condition, NULL);

    // avem doua functii producator, 1 si 2, replici exacte ale functiei originale
    pthread_create(&producer, NULL, (void *)&producer_function1, NULL);
    pthread_create(&producer, NULL, (void *)&producer_function2, NULL);

    // functia consumer nu sufera modificari
    consumer_function();
    // cleanup
    pthread_cond_destroy(&thread_condition);
}
