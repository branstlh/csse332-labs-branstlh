/* Copyright 2016 Rose-Hulman Institute of Technology

   Here is some code that factors in a super dumb way.  We won't be
   attempting to improve the algorithm in this case (though that would be
   the correct thing to do).

   Modify the code so that it starts the specified number of threads and
   splits the computation among them.  You can be sure the max allowed 
   number of threads is 50.  Be sure your threads actually run in parallel.

   Your threads should each just print the factors they find, they don't
   need to communicate the factors to the original thread.

   ALSO - be sure to compile this code with -pthread or just used the 
   Makefile provided.

*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

void *checkFactors(void *checks){
  int threads = ((long long unsigned int*)checks)[0];
  int number = ((long long unsigned int*)checks)[1];
  long long unsigned int total = ((long long unsigned int*)checks)[2];
  for(long long unsigned int i = number + 1; i <= total/2; i+=threads){
    if (i != 1) {
      printf("thread %d testing %llu\n", number + 1, i);
      if (total % i == 0) {
        printf("%llu is a factor\n", i);
      }
    }
  }
  pthread_exit(NULL);
}

int main(void) {
  /* you can ignore the linter warning about this */
  unsigned long long int target, i, start = 0;
  int numThreads;
  printf("Give a number to factor.\n");
  scanf("%llu", &target);

  printf("How man threads should I create?\n");
  scanf("%d", &numThreads);
  if (numThreads > 50 || numThreads < 1) {
    printf("Bad number of threads!\n");
    return 0;
  }

  pthread_t threads[numThreads];
  long long unsigned int args[numThreads][3];
  for (int j = 0; j < numThreads; j++) {
    args[j][0] = numThreads;
    args[j][1] = j;
    args[j][2] = target;
    printf("running thread\n");
    pthread_create(&threads[j], NULL, checkFactors, (void*)&args[j]);
  }
 
  // for (i = 2; i <= target/2; i = i + 1) {
    // /* You'll want to keep this testing line in.  Otherwise it goes so
       // fast it can be hard to detect your code is running in
       // parallel. Also test with a large number (i.e. > 3000) */
    // printf("testing %llu\n", i);
    // if (target % i == 0) {
      // printf("%llu is a factor\n", i);
    // }
  // }
  for (int j = 0; j < numThreads; j++){
    pthread_join(threads[j], NULL);
  }
  return 0;
}

