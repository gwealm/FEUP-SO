gcc -c -Wall -fPIC -o vector.o vector.c

gcc -shared -o libvector.so vector.o

gcc -Wall use_vector.c -o use_vector -L. -lvector -lm

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

./use_vector