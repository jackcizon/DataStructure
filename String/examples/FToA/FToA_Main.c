#include"ftoa.h"
#include"heapstring.h"
#include<stdlib.h>


int main(int argc, char const *argv[])
{
    HeapStr* HS = _ftoa(-123.45);

    Echo(HS);

    free(HS);

    return 0;
}
