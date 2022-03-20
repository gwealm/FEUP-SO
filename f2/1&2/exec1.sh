#!/bin/bash

gcc -Wall -c complex.c

ar -rc libcomplex.a complex.o

ar -t libcomplex.a

gcc -Wall use_complex.c -o use_complex.out -L. -lcomplex -lm

./use_complex.out