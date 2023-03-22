#include"stack.h"

#define Reverse void main(void)

#define BEGIN {

#define END }


stack(int);


    Reverse

BEGIN

    int_stack* S = int_new();
    int_stack* R = int_new();

    int_push(S, 0);
    int_push(S, 8);
    int_push(S, 3);

    int_traverse(S);

    int array[3] = {0};

    for(int i = 0; i < 3; i ++)
    {
        int_pop(S, &array[i]);
    }

    for(int i = 0; i < 3; i ++)
    {
        printf("%d ", array[i]);
    }
    puts("");

    for(int i = 0; i < 3; i ++)
    {
        int_push(R, array[i]);
    }

    int_traverse(R);

    free(S);

    free(R);

    puts("all executions success!");

END
