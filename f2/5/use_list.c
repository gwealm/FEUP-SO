#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    list *l = list_new_random(10, 10);
    printf("List l:\n");
    list_print(l);
    printf("List size: %d\n", list_size(l));

    list_add_first(100, l);
    printf("\nAdd 100 to start\n");
    list_print(l);
    printf("List size: %d\n", list_size(l));

    list_add_last(100, l);
    printf("\nAdd 100 to end\n");
    list_print(l);
    printf("List size: %d\n", list_size(l));

    list_remove_first(l);
    printf("\nRemove first element\n");
    list_print(l);
    printf("List size: %d\n", list_size(l));

    list_remove_last(l);
    printf("\nRemove last element\n");
    list_print(l);
    printf("List size: %d\n", list_size(l));

    return 0;    /* code */
    return 0;
}
