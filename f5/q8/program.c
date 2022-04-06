#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#define MAX_ARGS 255
#define HISTORY_PATH "history.txt"

char *joinstr(char **s, const char *sep) {
    char *joined = NULL;
    size_t lensep = strlen(sep), sz = 0;
    int first = 1;

    while (*s) {
        size_t len = strlen(*s);

        void *tmp = realloc(joined, sz + len + (first ? 0 : lensep) + 1);

        if (!tmp) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        joined = tmp;
        if (!first) {
            strcpy(joined + sz, sep);
            sz += lensep;
        }
        strcpy(joined + sz, *s++);
        first = 0;
        sz += len;
    }

    return joined;
}

int main(int argc, char* argv[]) {
    char buf[1024];
    char* command;
    char* pathname;
    pid_t pid;
    char *args[MAX_ARGS];

    /* do this until you get a ^C or a ^D */
    for( ; ; ) {
        /* give prompt, read command and null terminate it */
        fprintf(stdout, "$ ");

        if((command = fgets(buf, sizeof(buf), stdin)) == NULL)
            break;

        command[strlen(buf) - 1] = '\0';

        char *token = strtok(command, " ");

        int i;

        for (i = 0; token != NULL; ++i) {
            if (i == 0)
                pathname = token;
            else
                token = strtok(NULL, " ");
            
            args[i] = token;
        }
        
        /* call fork and check return value */
        if((pid = fork()) == -1) {
            fprintf(stderr, "%s: can’t fork command: %s\n", argv[0], strerror(errno));
            continue;
        } else if (pid == 0) {
            if (strcmp(pathname, "exit") == 0)
                kill(0, SIGTERM);

            FILE *fp = fopen(HISTORY_PATH, "a");
            
            if (!fp) {
                perror("fopen");
                return EXIT_FAILURE;
            }

           char *str = joinstr(args, " ");

           char *aux = (char*)realloc(str, sizeof(str) + 1);
           str = aux;
           strcat(str, "\n");


           fwrite(str, sizeof(char), strlen(str), fp);

           fclose(fp);
            

            if (execvp(pathname, args) == -1)
                perror("execvp");
            
            /* if I get here "execlp" failed */
            fprintf(stderr, "%s: couldn’t exec %s: %s\n", argv[0], buf, strerror(errno));

            /* terminate with error to be caught by parent */
            exit(EXIT_FAILURE);
        }

        /* shell waits for command to finish before giving prompt again */
        if ((pid = waitpid(pid, NULL, 0)) < 0)
            fprintf(stderr, "%s: waitpid error: %s\n", argv[0], strerror(errno));
    }
    
    exit(EXIT_SUCCESS);
}