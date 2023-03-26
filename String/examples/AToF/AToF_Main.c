#include"heapstring.h"
#include"atof.h"
#include<stdlib.h>


int main(int argc, char const *argv[])
{
    HeapStr* HS = NewHS("  -12345.67");

    printf("f: %lf\n", _atof(HS));

    free(HS);

    puts("all sexcutions success!");

    return 0;
}
