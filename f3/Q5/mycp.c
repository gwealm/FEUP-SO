#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int count_sep(char *str, char sep) {
    int count = 0;

    if (sep == '*') {
        while (str[count] != '\0')
            count++;
    } else {
        for (int i = 0; i < strlen(str); i++)
            if (str[i] == sep)
                count++;
    }
    
    count++;

    return count;
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

    if (!strcmp(argv[1], "-c")) {
        char *file_content = get_file_content(argv[2]);
        printf("%d\n", count_sep(file_content, '*'));

    } else if (!strcmp(argv[1], "-w")) {
        char *file_content = get_file_content(argv[2]);
        printf("%d\n", count_sep(file_content, ' '));
    } else if (!strcmp(argv[1], "-l")) {
        char *file_content = get_file_content(argv[2]);
        printf("%d\n", count_sep(file_content, '\n'));

    } else if (argc == 2) {
        char *file_content = get_file_content(argv[1]);
        printf("%d\n", count_sep(file_content, '*'));

    } else {
        fprintf(stderr, "Requires arguments!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}