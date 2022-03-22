#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    if (strstr(argv[1], argv[2]))
        printf("%s contains %s\n", argv[1], argv[2]);
    else
        printf("%s doesn't contain %s\n", argv[1], argv[2]);
    
    return EXIT_SUCCESS;
}
