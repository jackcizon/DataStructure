#include"abstract.h"

int main(int argc, char const *argv[])
{
    array* n = new();


    n->methods.add(n, "hello");
    n->methods.add(n, "world");

    float i = 9.0;

    n->methods.add(n, &i);

    for (int i = 0; i < total(n); i++)
        printf("%s ", get(n, i));    

    printf("\ntotal:%d\n", total(n));

    return 0;
}