#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* get_file_content(char *file_name) {
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

int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        char* fc = get_file_content(argv[i]);
        printf("%s\n", fc);
    }
    
    return EXIT_SUCCESS;
}