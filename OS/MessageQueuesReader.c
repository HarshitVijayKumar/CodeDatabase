#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 30

struct message_buffer{
    long type;
    char text[MAX];
}message;

int main(){
    key_t key;
    int msgid;

    key = 2003;
    msgid = msgget(key,0666|IPC_CREAT);

    msgrcv(msgid,&message,sizeof(message),1,0);
    printf("Data Receieved is : %s\n",message.text);
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}