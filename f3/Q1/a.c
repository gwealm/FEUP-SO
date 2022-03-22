#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STR_SIZE 64

char* to_upper(char* str, int size) {
    char *upper = (char*)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++) {
        upper[i] = toupper((unsigned int)str[i]);
    }

    return upper;
}

char* to_lower(char* str, int size) {
    char *lower = (char*)malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++) {
        lower[i] = tolower((unsigned int)str[i]);
    }

    return lower;
}


int main(int argc, char* argv[]) {

    char* inp = argv[1];

    char* upper = to_upper(inp, strlen(inp));
    char* lower = to_lower(inp, strlen(inp));

    printf("Original string: %s\n", inp);
    printf("Upper: %s\n", upper);
    printf("Lower: %s\n", lower);

    return 0;
}
