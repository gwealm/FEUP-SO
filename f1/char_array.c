#include <stdio.h>

/*
int main() {
    int i;
    char msg[] = "Hello World";

    for (i = 0; i < sizeof(msg) / sizeof(char); i++) {
        printf("%c <--> %c\n", msg[i], *(msg + i));
    }
}
*/

int main() {
    int i;
    int primes[] = {2, 3, 5, 7, 11};

    for (i = 0; i < sizeof(primes) / sizeof(int); i++) {
        printf("%d <--> %d\n", primes[i], *(primes + i));
    }

    printf("%ld", sizeof(char));

    return 0;
}