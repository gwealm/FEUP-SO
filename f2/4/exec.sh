gcc -Wall -c matrix.c

ar -rc libmatrix.a matrix.o

ar -t libmatrix.a

gcc -Wall use_matrix.c -o use_matrix.out -L. -lmatrix -lm

./use_matrix.out