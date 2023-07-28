#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 30

struct memory_buffer{
    long type;
    char text[MAX];
}message;

int main(){
    key_t key;
    int msgid;

    key = 2002;
    msgid = msgget(key,0666|IPC_CREAT);

    message.type = 1;
    printf("Write Data : ");
    fgets(message.text,MAX,stdin);

    msgsnd(msgid,&message,sizeof(message),0);
    printf("Data sent is : %s\n",message.text);
    return 0;
}