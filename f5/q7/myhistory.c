#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main(int argc, char const *argv[]) {
    pid_t pid;
    char buffer[BUFFER_SIZE];

    if (argc != 2)
        exit(EXIT_FAILURE);

    int num_lines = atoi(argv[1]);
    sprintf(buffer, "%d", num_lines);

    if ((pid = fork()) == -1) {
        fprintf(stderr, "%s: can't fork command: %s\n", argv[0], strerror(errno));
    } else if (pid == 0) {
        char* args[] = {"tail", "-n", buffer, "history.txt", NULL};
        if (execvp("tail", args) == -1)
            perror("execvp");

        exit(EXIT_FAILURE);
    }

    if ((pid = waitpid(pid, NULL, 0)) < 0)
        fprintf(stderr, "%s: waitpid error: %s\n", argv[0], strerror(errno));

    exit(EXIT_SUCCESS);
}
