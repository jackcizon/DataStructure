#include"single_circular_linked_list.h"

circular(int);

circular(char);

circular(float);

circular(double);

circular(string);



void ic_ops(void)
{
    int_circular* ic = int_new();
    char_circular* cc = char_new();

    int_append(ic, 2);
    int_append(ic, 1);
    int_push(ic, 3);

    int_push(ic, 4);
    int_push(ic, 5);
    int_push(ic, 6);
    int_push(ic, 7);
    int_remove(ic, 4) == true ?
        puts("can remove") : puts("can not remove");


    int_insert(ic, 4, 55555);


    printf("head->data:%d\n", int_head(ic)->data);
    printf("tail->data:%d\n", int_tail(ic)->data);

    printf("\nget data index 4:%d\n", int_get(ic, 4));

    int_search(ic, 55555) == true ?
        puts("find 55555") : puts("not found");

    int_delete(ic, 0);

    printf("\nsize:%ld\n", int_size(ic));

    int_delete(ic, 4);

    int_push(ic, 999000);
    int_append(ic, 300);

    int_pop(ic);

    int_traverse(ic); 

    for (size_t i = 0; i < 5; i++)
    {
        char_append(cc, 'a');
        /* code */
    }

    char_traverse(cc);
}


void fd_ops(void)
{
    double_circular* dc = double_new();
    float_circular* fc = float_new();
    for (size_t i = 0; i < 4; i++)
    {
        float_push(fc, 4.1);
        /* code */
        double_insert(dc, i, 4.6);   
    }

    float_traverse(fc);

    double_traverse(dc);    
}


void s_ops(void)
{
    string_circular* sc = string_new();

    for (size_t i = 0; i < 6; i++)
    {
        string_append(sc, "as");
        /* code */
    }

    for (size_t i = 5; i < 1; i--)
    {
        string_delete(sc, i);
        /* code */
    }
    
    string_traverse(sc);
}


int main(int argc, char const *argv[])
{
    ic_ops();

    fd_ops();

    s_ops();
    

    return 0;
}

