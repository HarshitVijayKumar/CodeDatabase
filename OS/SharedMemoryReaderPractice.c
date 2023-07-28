#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
    key_t key;
    int shmid;

    key = 2002;
    shmid = shmget(key,1024,0666|IPC_CREAT);

    char *str;
    str = shmat(shmid,(void*)0,0);

    printf("Data Receieved : %d\n",str);

    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}