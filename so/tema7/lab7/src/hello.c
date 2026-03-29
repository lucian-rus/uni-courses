#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void print_message_function(void *ptr)
{
	char *message = (char *)ptr;
	printf("%s ", message);
}

int main(int argc, char *argv[])
{
	pthread_t thread1, thread2;
	char *message1 = "Hello";
	char *message2 = "world";

	pthread_create(&thread1, NULL, (void *)&print_message_function, (void *)message1);
	pthread_create(&thread2, NULL, (void *)&print_message_function, (void *)message2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	exit(0);
}
