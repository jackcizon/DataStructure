#include"double_circular_linked_list.h"


circular(int);

circular(char);

circular(float);

circular(double);

circular(string);


int main(int argc, char const *argv[])
{
    int_circular* ic = int_new();

    int_push(ic, 1);
    int_append(ic, 2);
    //int_append(ic, 3);
    //int_push(ic, 0);

    //int_insert(ic, 0, -1);
    //int_insert(ic, 5, 4);
    //int_insert(ic, 3, 666);  

    int_pop(ic);

    int_pop(ic);
    
    int_append(ic, 9);

    int_append(ic, 11);

    int_insert(ic, 1, 999);

    int_delete(ic, 1);

    int_delete(ic, 0);
    int_delete(ic, 0);

    int_push(ic, 888);

    int_remove(ic, 888);

    int_append(ic, 1);

    int_push(ic, 0);

    int_traverse(ic);

    puts("all operations success!");
    
    return 0;
}
