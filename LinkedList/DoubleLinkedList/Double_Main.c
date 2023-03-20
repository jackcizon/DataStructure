#include"double_linked_list.h"


list(int);

list(double);

list(char);

list(string);

list(float);



void main(void)
{
    int_list* iL = int_new();

    int_empty(iL) == true ?
        puts("true") : puts("false");

    int_size(iL) == 0 ?
        puts("true") : puts("false");

    int_head(iL) == NULL ?
        puts("null") : puts("not null");

    int_append(iL, 3);
    
    iL->head->next == NULL ?
        puts("null") : puts("not null");

    int_append(iL, 4);
    int_pop(iL);
    int_push(iL, 2);
    int_push(iL, 1);
    int_push(iL, 0);
    int_pop(iL);
    int_append(iL, 5);
    int_insert(iL, 0, -1);
    int_insert(iL, 3, 23);
    printf("size: %ld\n", int_size(iL));
    int_insert(iL, int_size(iL), 8);
    int_delete(iL, 0);
    int_delete(iL, 0);
    int_pop(iL);
    int_delete(iL, 2);
    int_remove(iL, 5);
    int_append(iL, 3);
    int_append(iL, 4);
    int_append(iL, 5);
    int_remove(iL, 23);
    int_remove(iL, 4);

    int_traverse(iL);
}