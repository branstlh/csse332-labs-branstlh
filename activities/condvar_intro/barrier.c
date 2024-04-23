#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include <pthread.h>

/**
 * In this exercise, we would like to implement a barrier to make all of our
 * threads wait at a certain location in the code before they can move formward.
 * No thread can get passed the barrier until all threads reach that barrier,
 * then they can move out together in any order.
 */

#define NUM_THREADS 5

int counter;
pthread_mutex_t lock;
pthread_cond_t release;

void barrier_wait(void)
{
  pthread_mutex_lock(&lock);
  if (--counter == 0){
    pthread_cond_broadcast(&release);
  }
  while (counter != 0)
    pthread_cond_wait(&release, &lock);
  pthread_mutex_unlock(&lock);
}

void *thread_fn(void *arg)
{
  int tid = *(int*)arg;

  printf("Thread %d started ...\n", tid);

  sleep(rand()%10);

  printf("Thread %d waiting at barrier ...\n", tid);
  barrier_wait();
  printf("Thread %d left the barrier ...\n", tid);

  return NULL;
}

int main()
{
  pthread_t threads[NUM_THREADS];
  int tids[NUM_THREADS];
  int i;
  counter = NUM_THREADS;
  pthread_cond_init(&release, 0);
  pthread_mutex_init(&lock, NULL);
  
  srand(time(NULL));

  for(i = 0; i < NUM_THREADS; i++) {
    tids[i] = i;
    pthread_create(&threads[i], NULL, thread_fn, &tids[i]);

    if(i == NUM_THREADS/2)
      sleep(2);
  }

  for(i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&lock);
  
  printf("All done, goodbye...\n");
  exit(0);
}

