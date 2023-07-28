#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 5

pthread_mutex_t mutex;
sem_t empty, full;
pthread_t cid,pid;

int a[SIZE],counter,in,out;

void *producer(void *arg){
    int item;
    do{
        item = rand()%100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        if(counter<SIZE){
            a[in] = item;
            counter++;
            in = (in+1)%SIZE;
            printf("Producer Produced : %d\n",item);
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }while(1);
    return NULL;
}

void *consumer(void *arg){
    int item;
    do{
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        if(counter>0){
            item = a[out];
            counter--;
            out = (out+1)%SIZE;
            printf("Consumer Consumed : %d\n",item);
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(1);
    }while(1);
    return NULL;
}

void initialize_data(){
    pthread_mutex_init(&mutex,NULL);
    sem_init(&full,0,0);
    sem_init(&empty,0,SIZE);
    counter = 0;
    in = 0;
    out = 0;
}

int main(){
    initialize_data();
    pthread_create(&pid,NULL,producer,NULL);
    pthread_create(&cid,NULL,consumer,NULL);
    printf("In EXIT\n");
    sleep(5);
    pthread_cancel(pid);
    pthread_cancel(cid);
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
	return 0;
}