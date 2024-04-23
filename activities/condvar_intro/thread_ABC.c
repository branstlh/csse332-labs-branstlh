
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


//         INSTRUCTION
// Use condition variables to make  A, B, C print out in order.
// HINT: You need more than one condition variables

pthread_cond_t aDone;
pthread_cond_t bDone;
pthread_mutex_t lock;
int a = 0;
int b = 0;

void* thread_func_A(void* arg) {
    pthread_mutex_lock(&lock);
    sleep(3);

    printf("A\n");
    a = 1;
    pthread_cond_signal(&aDone);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* thread_func_B(void* arg) {
    pthread_mutex_lock(&lock);
    while (!a)
        pthread_cond_wait(&aDone, &lock);
    
    sleep(2);

    printf("B\n");
    b = 1;
    pthread_cond_signal(&bDone);
    pthread_mutex_unlock(&lock);

    return NULL;
}
void* thread_func_C(void* arg) {
    pthread_mutex_lock(&lock);
    while (!b) {
        pthread_cond_wait(&bDone, &lock);
    }
    printf("C\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t tA, tB, tC;

    pthread_cond_init(&aDone, 0);
    pthread_cond_init(&bDone, 0);
    pthread_create(&tC, NULL, thread_func_C, NULL);
    pthread_create(&tB, NULL, thread_func_B, NULL);
    pthread_create(&tA, NULL, thread_func_A, NULL);

    // join waits for the threads to finish
    pthread_join(tA, NULL);
    pthread_join(tB, NULL);
    pthread_join(tC, NULL);
    return 0;
}
