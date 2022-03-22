#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int *grep(char *needle, char *haystack) {
    int line = 1, col = 1, aux = 0, pos_line = 1, pos_col = 1;
    int *arr = (int*)malloc(sizeof(int) * 2);

    for (char *c = haystack; *c; c++, col++) {
        if (*c == '\n') {
            col = 0;
            line++;
        }

        if (needle[aux] == '\0') {
            aux = 0;
            arr[0] = pos_line;
            arr[1] = pos_col;
            return arr;
        }

        if (aux == 0) {
            pos_col = col;
            pos_line = line;
        }

        if (needle[aux] == *c)
            aux++;
        else
            aux = 0;
    }

    if (needle[aux] == '\0') {
            aux = 0;
            arr[0] = pos_line;
            arr[1] = pos_col;
            return arr;
    }

    return NULL;
}

char *get_file_content(char *file_name){
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

    char *f1_content = get_file_content(argv[2]);

    char *needle = argv[1];

    int *line_col = grep(needle, f1_content);
    
    printf("[%d, %d]\n", line_col[0], line_col[1]);

    return EXIT_SUCCESS;
}