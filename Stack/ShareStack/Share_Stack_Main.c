#include"share_stack.h"

sstack(int);


int main(int argc, char const *argv[])
{
    int_sstack* is =  int_new();

    int_push(is, 1, 3);
    int_push(is, 1, 4);
    int_pop(is, 1);
    int_push(is, 1, 5);

    int_traverse(is, 1);


    int_push(is, 2, 11);
    int_push(is, 2, 55);
    int_pop(is, 2);

    int_traverse(is, 2);

    int_empty(is) ?
        puts("empty") : puts("not empty");


    return 0;
}
