#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 1024
int main() {
    int pipefd[ 2 ];
    pid_t pid;
    char buffer[BUFFER_SIZE];
    if (pipe(pipefd) == -1 ) {
        perror( "pipe" );
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0 ) {
        perror( "fork" );
        exit(EXIT_FAILURE);
    } else if (pid == 0 ) {
        close(pipefd[ 1 ]); 
        read(pipefd[ 0 ], buffer, BUFFER_SIZE);
        printf( "Child received: %s\n" , buffer);
        close(pipefd[ 0 ]); 
    } else {
        close(pipefd[ 0 ]);
        strcpy(buffer, "Operating Systems Lab" );
        write(pipefd[ 1 ], buffer, strlen(buffer) + 1 );
        close(pipefd[ 1 ]);
    }
    return 0 ;
}