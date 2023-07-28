#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
void sem_wait(int semid) {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}
void sem_signal(int semid) {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = 0;
    semop(semid, &sb, 1);
}
int main() {
    int semid;
    pid_t pid;
    union semun semarg;
    struct sembuf sb;
    key_t key = ftok(".", 'x');
    semid = semget(key, 1, IPC_CREAT | 0666);
    semarg.val = 0;
    semctl(semid, 0, SETVAL, semarg);
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
    // Child process
        sem_wait(semid);
        printf("Child received: Operating Systems Lab\n");
        semctl(semid, 0, IPC_RMID, semarg);
    } else {
    // Parent process
        printf("Parent sending: Operating Systems Lab\n");
        sem_signal(semid);
    }
    return 0;
}