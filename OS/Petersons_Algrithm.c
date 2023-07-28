#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

int turn = 0;          
int flag[NUM_THREADS];  

void* process(void* arg) {
    int thread_id = *(int*)arg;

    flag[thread_id] = 1;       
    turn = 1 - thread_id;      
    while (flag[1 - thread_id] == 1 && turn == 1 - thread_id)
    {
        // Busy wait
    }

    printf("Process %d entered the critical section.\n", thread_id);
    printf("Process %d is exiting the critical section.\n", thread_id);

    flag[thread_id] = 0; 

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1};

    for (int i = 0; i < NUM_THREADS; i++) {
        flag[i] = 0;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, process, (void*)&thread_ids[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}