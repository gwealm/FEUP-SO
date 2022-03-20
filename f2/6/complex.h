/* definition of new type complex */
typedef struct {
    double x;
    double y;
} complex;

/* definition of the complex API */
complex complex_new(double x, double y);

char* complex_print(complex z) ;
complex complex_add(complex z, complex w);
complex complex_sub(complex z, complex w);
complex complex_mul(complex z, complex w);
complex complex_div(complex z, complex w);
complex complex_conj(complex z);
double complex_mod(complex z);
double complex_arg(complex z);
double complex_re(complex z);
double complex_im(complex z);