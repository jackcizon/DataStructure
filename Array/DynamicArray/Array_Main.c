#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int main(void)
{
    int i;

    array* v = init();

    add(v, "Bonjour");
    add(v, "tout");
    add(v, "le");
    add(v, "monde");
    

    for (i = 0; i < total(v); i++)
        printf("%s ", get(v, i));
    printf("\n");

    delete(v, 3);
    delete(v, 2);
    delete(v, 1);

    set(v, 0, "Hello");
    add(v, "World");

    for (i = 0; i < total(v); i++)
        printf("%s ", get(v, i));
    printf("\n");

    _free(v);
}
