#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int data = 0;
int readers_count=0;
sem_t readers_mutex,writers_mutex,data_mutex;

void *reader(void *arg){
    int reader_id = *((int *)arg);
    while(1){
        sem_wait(&readers_mutex);
        readers_count++;
        if(readers_count==1){
            sem_wait(&data_mutex);
        }
        sem_post(&readers_mutex);

        printf("Reader %d read data : %d\n",reader_id,data);
        sem_wait(&readers_mutex);
        readers_count--;
        if(readers_count==0){
            sem_post(&data_mutex);
        }
        sem_post(&readers_mutex);
        usleep(rand()%100000000);
    }
    pthread_exit(NULL);
}
void *writer(void*arg){
    int writer_id = *((int*)arg);
    while(1){
        sem_wait(&writers_mutex);
        sem_wait(&data_mutex);
        data++;
        printf("Writer %d wrote data : %d\n",writer_id,data);
        sem_post(&data_mutex);
        sem_post(&writers_mutex);
        usleep(rand()%10000000);
    }
    pthread_exit(NULL);
}
int main(){
    pthread_t reader_thread,writer_thread;
    int reader_id = 1;
    int writer_id = 1;

    sem_init(&readers_mutex,0,1);
    sem_init(&writers_mutex,0,1);
    sem_init(&data_mutex,0,1);

    pthread_create(&reader_thread,NULL,reader,&reader_id);
    pthread_create(&writer_thread,NULL,writer,&writer_id);

    pthread_join(reader_thread,NULL);
    pthread_join(writer_thread,NULL);

    sem_destroy(&readers_mutex);
    sem_destroy(&writers_mutex);
    sem_destroy(&data_mutex);

    return 0;
}