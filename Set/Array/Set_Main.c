#include"array_set.h"
#include<string.h>

int main(int argc, char const *argv[])
{
    int a = 1;
    Set* S = New(4, "hello", 'c', a, "!");
    
    puts(S->items[0]);

    putchar(S->items[1]);

    printf("\n%d\n", S->items[2]);

    puts(S->items[3]);

    Remove(S, &a);

    Contain(S, &a) ?
        puts("contain") : puts("not contain");

    string s = "world";

    Add(S, s);

    Contain(S, s) ?
        puts("contain") : puts("not contain");

    Destroy(S);

    puts("\n\nall executions success!");

    return 0;
}

