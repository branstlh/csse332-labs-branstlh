#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "log.h"

#define NUM_ITERATIONS 10

#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 8

#define BUF_SIZ 3

// we now have a plate that can hold BUF_SIZ burgers
int burgers[BUF_SIZ];

// this indicates which burger we can eat from
volatile int eating_index = -1;
// count the number of burgers cooked so far
volatile int num_burgers_cooked = 0;

static int is_empty() {
  return eating_index == -1;
}

static int is_full() {
  return eating_index == BUF_SIZ-1;
}

void cook_burger(int id) {

  // make sure plate is not full
  assert(!is_full());

  burgers[++eating_index] = 1;
  num_burgers_cooked++;

  print_red("Cook thread %d adding burger %d to the plate at %d...\n",
            id, num_burgers_cooked, eating_index);
}

void eat_burger(int id) {

  // make sure plate is not empty
  assert(!is_empty());

  burgers[--eating_index] = 0;

  print_green("Eater thread %d ate burger from position %d on plate...\n",
              id, eating_index);
}

void *cook(void *arg) {
  int i, id;

  // grab the id of the cook thread
  id = *(int*)arg;

  for(i = 0; i < NUM_ITERATIONS; i++) {
    cook_burger(id);
  }

  return NULL;
}

void *eater(void *arg) {
  int i, id;

  // grab the id of the eater thread
  id = *(int*)arg;
  for(i = 0; i < NUM_ITERATIONS; i++) {
    eat_burger(id);

    // This sleep simulates the cook doing other stuff.
    // Do NOT include this sleep statement in your condition variables/locking
    // mechanisms, it should be floating here on its own.
    sleep(1);
  }

  return NULL;
}

int main(int argc, char **argv) {
  int i;
  int consumer_ids[NUM_CONSUMERS];
  int producer_ids[NUM_PRODUCERS];

  pthread_t producers[NUM_PRODUCERS];
  pthread_t consumers[NUM_CONSUMERS];

  // create the producer threads
  for(i = 0; i < NUM_PRODUCERS; i++) {
    producer_ids[i] = i+1;
    pthread_create(&producers[i], 0, cook, &producer_ids[i]);
  }

  // create the consumer threads
  for(i = 0; i < NUM_CONSUMERS; i++) {
    consumer_ids[i] = i+1;
    pthread_create(&consumers[i], 0, eater, &consumer_ids[i]);
  }

  // join the threads
  for(i = 0; i < NUM_PRODUCERS; i++) {
    pthread_join(producers[i], 0);
  }
  for(i = 0; i < NUM_CONSUMERS; i++) {
    pthread_join(consumers[i], 0);
  }

  return 0;
}

