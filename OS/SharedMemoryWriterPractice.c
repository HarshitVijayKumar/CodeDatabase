#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
    key_t key;
    int shmid;

    key = 2002;
    shmid = shmget(key,1024,0666|IPC_CREAT);

    char *str;
    str = (char *)shmat(shmid,(void*)0,0);

    printf("Write Data : ");
    fgets(str,30,stdin);

    printf("Written the data : %s\n",str);
    shmdt(str);
    return 0;
}