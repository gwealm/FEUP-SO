gcc -Wall -c list.c

ar -rc liblist.a list.o 

ar -t liblist.a

gcc -Wall use_list.c -o use_list.out -L. -llist -lm

./use_list.out