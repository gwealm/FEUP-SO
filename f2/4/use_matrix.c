#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main() {
    matrix *a = matrix_new_random(2, 2, -10, 10);
    printf("Matrix A:\n");
    matrix_print(a);

    matrix *b = matrix_new_random(2, 2, -10, 10);
    printf("\nMatrix B:\n");
    matrix_print(b);

    matrix *c = matrix_new_random(4, 2, -10, 10);
    printf("\nMatrix C:\n");
    matrix_print(c);

    matrix *d = matrix_new_random(2, 3, -10, 10);
    printf("\nMatrix D:\n");
    matrix_print(d);

    matrix *apb = matrix_add(a, b);
    printf("\nMatrix A+B:\n");
    matrix_print(apb);

    matrix *amb = matrix_sub(a, b);
    printf("\nMatrix A-B:\n");
    matrix_print(amb);

    matrix *dtc = matrix_mul(d, c);
    printf("\nMatrix D×C:\n");
    matrix_print(dtc);

    matrix *ct = matrix_trans(c);
    printf("\nMatrix Cᵀ:\n");
    matrix_print(ct);

    return 0;
}