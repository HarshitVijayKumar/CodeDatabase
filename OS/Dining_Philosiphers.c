#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5  

pthread_mutex_t chopsticks[N];

void *philosopher(void *arg) {
    int id = *((int *)arg);
    int left = id;
    int right = (id + 1) % N;

    while (1) {
        
        sleep(rand() % 5);

        
        if (left < right) {
            pthread_mutex_lock(&chopsticks[left]);
            pthread_mutex_lock(&chopsticks[right]);
        } else {
            pthread_mutex_lock(&chopsticks[right]);
            pthread_mutex_lock(&chopsticks[left]);
        }

        
        printf("Philosopher %d is eating\n", id);
        sleep(rand() % 5);

        
        pthread_mutex_unlock(&chopsticks[left]);
        pthread_mutex_unlock(&chopsticks[right]);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t philosophers[N];
    int philosopher_ids[N];

    
    for (int i = 0; i < N; i++)
        pthread_mutex_init(&chopsticks[i], NULL);

    
    for (int i = 0; i < N; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

   
    for (int i = 0; i < N; i++)
        pthread_join(philosophers[i], NULL);

    
    for (int i = 0; i < N; i++)
        pthread_mutex_destroy(&chopsticks[i]);

    return 0;
}