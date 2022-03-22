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

char* get_file_content(char *file_name){
    FILE *file;
    char *text;
    long numbytes;

    file = fopen(file_name, "r");

    if (!file) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0L, SEEK_END);
    numbytes = ftell(file);
    fseek(file, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));

    fread(text, sizeof(char), numbytes, file);

    if (!text)
        return NULL;

    return text;
}

int main(int argc, char* argv[]) {
    char *text;

    if (strcmp(argv[1],"-u") == 0) {
        text = get_file_content(argv[2]);
        text = to_upper(text, strlen(text));
    } else if (strcmp(argv[1], "-l") == 0) {
        text = get_file_content(argv[2]);
        text = to_lower(text, strlen(text));
    } else {
        text = get_file_content(argv[1]);
    }

    if (text)
        printf("%s\n", text);

    return EXIT_SUCCESS;
}