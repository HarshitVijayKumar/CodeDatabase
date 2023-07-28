#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define SHM_SIZE 1024
int main() {
    int shmid;
    pid_t pid;
    char *shmaddr;
    key_t key = ftok(".", 's');
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
    // Child process
        shmaddr = shmat(shmid, NULL, 0);
        printf("Child received: %s\n", shmaddr);
        shmdt(shmaddr);
        shmctl(shmid, IPC_RMID, NULL);
    } else {
    // Parent process
        shmaddr = shmat(shmid, NULL, 0);
        strcpy(shmaddr, "Operating Systems Lab");
        sleep(2); // Wait for the child process to read
        shmdt(shmaddr);
    }
    return 0;
}