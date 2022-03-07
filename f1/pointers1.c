#include <stdio.h>

int main() {
    int i, j, *p, *q;
    int *ip = &i, *jp = &j, **pp = &p, **qp = &q;
    i = 5;
    p = &i;
    *p = 7;   // i = 7
    j = 3;
    p = &j;
    q = p;    // q = &j
    p = &i;
    *q = 2;   // j = 2;

    printf("i=%d\nj=%d\np=%p\nq=%p\n", i, j, p, q);
}