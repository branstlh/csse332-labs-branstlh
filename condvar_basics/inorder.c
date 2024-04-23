#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int next = 1;
pthread_mutex_t lock;
pthread_cond_t c;

void *thread(void *arg)
{
  int *num = (int *)arg;
  printf("%d wants to enter the critical section\n", *num);
  pthread_mutex_lock(&lock);
  while (next != *num)
    pthread_cond_wait(&c, &lock);
  next++;
  pthread_cond_broadcast(&c);
  printf("%d is finished with the critical section\n", *num);
  pthread_mutex_unlock(&lock);
  return NULL;
}

int
main(int argc, char **argv)
{
  pthread_t threads[4];
  int i;
  int nums[] = {2, 1, 4, 3};
  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&c, 0);

  for(i = 0; i < 4; ++i) {
    pthread_create(&threads[i], NULL, thread, &nums[i]);

    if(i == 2)
      sleep(3);
  }

  for(i = 0; i < 4; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("Everything finished\n");

  return 0;
}
