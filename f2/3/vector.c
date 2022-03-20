#include <stdlib.h>
#include <math.h>

#include "vector.h"

vector* vector_new(double x, double y, double z) {
    vector* vec = (vector*)malloc(sizeof(vector));
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return vec;

}

vector* vector_add(vector* v1, vector* v2) {
    return vector_new(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

vector* vector_sub(vector* v1, vector* v2) {
    return vector_new(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);

}
vector* vector_scale(double a, vector* v) {
    return vector_new(v->x * a, v->y * a, v->z * a);
}

vector* vector_vprod(vector* v1, vector* v2) {
    return vector_new(v1->y * v2->z - v2->y * v1->z, 
                      v2->y * v1->z - v1->x * v2->z,
                      v1->x * v2->y - v2->x * v1->y);
}

double vector_sprod(vector* v1, vector* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double vector_mod(vector* v) {
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}