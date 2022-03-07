#include <stdio.h>

int *a;

void g(int *x) {
    a = x;
}


void f() {
    int x = 2;
    g(&x);
}


int main() {
    f();
    printf("%d", *a);
    return 0;
}