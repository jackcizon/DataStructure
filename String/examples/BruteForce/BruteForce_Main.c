#include"heapstring.h"


int main(int argc, const string argv[])
{

    HeapStr* traget = NewHS("https://duckduckgo.com");
    HeapStr* match = NewHS("duckduckgo");    

    printf("index : %d",BF_Index(traget, match));

    free(traget);
    free(match);
    
    return 0;
}
