#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    if (argc != 1) {
        printf("usage: pwd\n");
        return EXIT_FAILURE;
    }

    char cwd[256];

    if (!getcwd(cwd, sizeof(cwd)))    
        return EXIT_FAILURE;
    
    printf("%s\n", cwd);

    return EXIT_SUCCESS;
}
