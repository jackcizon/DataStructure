#include"heapstring.h"


int main(int argc, char const *argv[])
{

    HeapStr* traget = NewHS("https://duckduckgo.com");
    HeapStr* match = NewHS("duckduckgo");    

    printf("index : %d",BF_Index(traget, match));

    return 0;
}
