#include"heap_str.h"
#include<stdlib.h>
#include<signal.h>


void segfault_handler(int signal)
{
    printf("Caught signal %d: Segmentation fault\n", signal);
    exit(EXIT_FAILURE);
}


int main(int argc, const string argv[])
{
    HeapStr* HS1 = NewHS("Hello");

    HeapStr* HS2 = NewHS("World");

    printf("get HS1 %d data: %c\n", 2, Get(HS1, 2));

    printf("compare result :%d\n", Compare(HS1, HS2));

    Equal(HS1, HS2) == true ?
        puts("equal.") : puts("not equal");

    Concat(HS1, HS2);

    printf("SubStr : %s\n", SubStr(HS1, 0, Length(HS1))->str);

    
    HeapStr* copy1 = NewHS("");

    Copy(HS2, copy1);

    Set(copy1, 1, '@');

    puts("copy1 str :");
    Echo(copy1);

    HeapStr* copy2 = NewHS("this will be erased");

    Copy(HS1, copy2);

    puts("copy2 str :");
    Echo(copy2);

    Delete(HS1, 5, 7);

    Insert(HS1, 2, " insert section ");
    
    Echo(HS1);
    Echo(HS2);

    free(HS1);
    free(HS2);
    free(copy1);
    free(copy2);

    puts("all executions success!");

    return 0;
}
