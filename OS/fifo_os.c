#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#define FIFO_NAME "/tmp/operating_systems_lab_fifo"
#define BUFFER_SIZE 1024
int main() {
    int fd;
    pid_t pid;
    char buffer[BUFFER_SIZE];
    mkfifo(FIFO_NAME, 0666);
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
    // Child process
        fd = open(FIFO_NAME, O_RDONLY);
        read(fd, buffer, BUFFER_SIZE);
        printf("Child received: %s\n", buffer);
        close(fd);
    } else {
    // Parent process
        fd = open(FIFO_NAME, O_WRONLY);
        strcpy(buffer, "Operating Systems Lab");
        write(fd, buffer, strlen(buffer) + 1);
        close(fd);
        unlink(FIFO_NAME);
    }
    return 0;
}