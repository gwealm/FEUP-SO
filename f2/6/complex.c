#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"

char complex_buf[100];

complex complex_new(double x, double y) {
    complex z;
    z.x = x;
    z.y = y;
    return z;
}

char* complex_print(complex z) {
    if (z.y == 0)
        sprintf(complex_buf, "%f", z.x);
    else if (z.x == 0)
        sprintf(complex_buf, "%fi", z.y);
    else if (z.y > 0)
        sprintf(complex_buf, "%f+%fi", z.x, z.y);
    else
        sprintf(complex_buf, "%f%fi", z.x, z.y);
    return complex_buf;
}

complex complex_add(complex z, complex w){
    complex r;
    r.x = z.x + w.x;
    r.y = z.y + w.y;
    return r;
}

complex complex_sub(complex z, complex w){
    complex r;
    r.x = z.x - w.x;
    r.y = z.y - w.y;
    return r;
}

complex complex_mul(complex z, complex w){
    complex r;
    r.x = z.x * w.x - z.y * w.y;
    r.y = z.x * w.y + z.y * w.x;
    return r;
}

complex complex_div(complex z, complex w){
    complex r;
    double d = w.x * w.x + w.y * w.y;
    r.x = (z.x * w.x + z.y * w.y) / d;
    r.y = (- z.x * w.y + z.y + w.x) / d;
    return r;
}

complex complex_conj(complex z){
    complex r;
    r.x = z.x;
    r.y = -z.y;
    return r;
}

double complex_mod(complex z){
    return sqrt(z.x * z.x + z.y * z.y);
}

double complex_arg(complex z){
    return atan2(z.y, z.x);
}

double complex_re(complex z){
    return z.x;
}

double complex_im(complex z){
    return z.y;
}