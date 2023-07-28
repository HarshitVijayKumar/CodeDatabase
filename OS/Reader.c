#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>

#define SHARED_MEM_NAME "/reader_writer_shm"
#define SEM_READER_NAME "/reader_writer_sem_reader"
#define SEM_WRITER_NAME "/reader_writer_sem_writer"

typedef struct {
    int data;
    int readers;
} SharedData;

int main() {
    int shm_fd = shm_open(SHARED_MEM_NAME, O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    SharedData *shared_data = mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_data == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    sem_t *sem_reader = sem_open(SEM_READER_NAME, 0);
    if (sem_reader == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    sem_t *sem_writer = sem_open(SEM_WRITER_NAME, 0);
    if (sem_writer == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    while (1) {
        sem_wait(sem_reader); 

        shared_data->readers++;
        if (shared_data->readers == 1) {
            sem_wait(sem_writer);
        }

        printf("Reader: Read data %d\n", shared_data->data);

        shared_data->readers--;
        if (shared_data->readers == 0) {
            sem_post(sem_writer); 
        }

        sem_post(sem_reader); 
        sleep(1);
    }

    return 0;
}