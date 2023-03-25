#include"KMP.h"
#include<stdlib.h>

int main()
{
    HeapStr* target = NewHS("https://duckduckgo.com");
    HeapStr* match = NewHS("duckduckgo");

    printf("Match index: %d\n", KMPMatch(target, match));

    free(target);
    free(match);

    return 0;
}
