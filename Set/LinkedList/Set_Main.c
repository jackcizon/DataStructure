#include"list_set.h"


int main(int argc, char const *argv[])
{
    Set* S = New(3, "c", "1", "3.4");

    //printf("%s %d %lf", (string)S->head->data, (int*)S->head->next->data, (double*)S->head->next->next->data);

    Traverse(S);

    return 0;
}
