#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int threads_in = 0;
pthread_mutex_t lock;
pthread_cond_t c;

void *thread(void *arg)
{
	char *letter = (char *)arg;
	printf("%c wants to enter the critical section\n", *letter);
	pthread_mutex_lock(&lock);
	while (threads_in == 3)
		pthread_cond_wait(&c, &lock);
	threads_in++;
	pthread_mutex_unlock(&lock);
	printf("%c is in the critical section\n", *letter);
	sleep(1);
	pthread_mutex_lock(&lock);
	threads_in--;
	pthread_cond_broadcast(&c);
	printf("%c has left the critical section\n", *letter);
	pthread_mutex_unlock(&lock);
	return NULL;
}

int
main(int argc, char **argv)
{
	pthread_t threads[8];
	int i;
	char *letters = "abcdefgh";
	pthread_mutex_init(&lock, NULL);
	pthread_cond_init(&c, 0);

	for(i = 0; i < 8; ++i) {
		pthread_create(&threads[i], NULL, thread, &letters[i]);

		if(i == 4)
			sleep(4);
	}

	for(i = 0; i < 8; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("Everything finished...\n");

	return 0;
}
