#include	<stdlib.h>
#include 	<pthread.h>
#include 	<stdio.h>

#define 	ITEMS 	10

long 		buffer[ITEMS];
int 		head = 0, tail = 0;

pthread_mutex_t mutex;
struct timespec delay;


long produce_item(void)
{
	long item = random() % 256;
	printf("producing %d\n", item);

	return item;
}

void consume_item(long item)
{
	printf("consuming %d\n", item);
}

void producer_function(void)
{
	while (1) {
		pthread_mutex_lock(&mutex);
		if ((tail + 1) % ITEMS != head) {
			buffer[tail] = produce_item();
			tail = (tail + 1) % ITEMS;
		}
		pthread_mutex_unlock(&mutex);

		nanosleep(&delay, NULL);
	}
}

void consumer_function(void)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (head != tail) {
			consume_item(buffer[head]);
			head = (head + 1) % ITEMS;
		}
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char *argv[])
{
	pthread_t producer;

	// 250 msec
	delay.tv_sec = 0;
	delay.tv_nsec = 250000000;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&producer, NULL, (void *)&producer_function, NULL);

	consumer_function();
}
