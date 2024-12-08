#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 256

int main() {
    int pipe_fd[2]; 
    pid_t child1, child2;
    char buffer[MAXLINE];
    printf("parent process start\n");
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    child1 = fork();
    if (child1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0) {
        close(pipe_fd[0]); 
        printf("input string: ");
        fgets(buffer, MAXLINE, stdin); 
        buffer[strcspn(buffer, "\n")] = '\0'; 

        if (write(pipe_fd[1], buffer, strlen(buffer) + 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(pipe_fd[1]); 
        exit(EXIT_SUCCESS);
    }

    child2 = fork();
    if (child2 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child2 == 0) {
        close(pipe_fd[1]); 

        if (read(pipe_fd[0], buffer, MAXLINE) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = toupper((unsigned char)buffer[i]);
        }

        printf("%s\n", buffer);

        close(pipe_fd[0]);
        exit(EXIT_SUCCESS);
    }

    close(pipe_fd[0]); 
    close(pipe_fd[1]); 

    wait(NULL);
    wait(NULL);

    return 0;
}

