#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    for (int i = 0; i < 4; i++)
        fork();

    printf("Pid: %d\n", getpid());
    
    return EXIT_SUCCESS;
}