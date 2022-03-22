#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int count = 0;
    char* aux;

    for (aux = argv[1]; *aux; aux++)
        if (strstr(aux, argv[2]))
            count++;

    if (count != 0)
        printf("%s is in %s %d times\n", argv[2], argv[1], count);
    else
        printf("%s is not in %s\n", argv[2], argv[1]);

    return 0;
}