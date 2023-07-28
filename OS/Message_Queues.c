#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define MSG_SIZE 1024
struct message {
    long mtype;
    char mtext[MSG_SIZE];
};
int main() {
    int msqid;
    pid_t pid;
    struct message msg;
    key_t key = ftok(".", 'm');
    msqid = msgget(key, IPC_CREAT | 0666);
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
    // Child process
        msgrcv(msqid, &msg, sizeof(msg.mtext), 1, 0);
        printf("Child received: %s\n", msg.mtext);
        msgctl(msqid, IPC_RMID, NULL);
    } else {
    // Parent process
        msg.mtype = 1;
        strcpy(msg.mtext, "Operating Systems Lab");
        msgsnd(msqid, &msg, strlen(msg.mtext) + 1, 0);
    }
    return 0;
}