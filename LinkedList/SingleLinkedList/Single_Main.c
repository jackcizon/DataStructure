#include"single_linked_list.h"


list(int);

list(double);

list(char);

list(string);

list(float);

#define MainFunc main

#define execution() do\
{\
    MainFunc\
} while (0);


PRIVATE void int_operations(void)
{
    int_list* iL = int_new();

    int_head(iL) == NULL ?
        puts("head is null") : puts("head is not null");

    int_push(iL, 6);
    int_pop(iL);
    int_push(iL, 7);
    int_push(iL, 8);
    int_push(iL, 9);

    int_head(iL) == NULL ?
        puts("head is null") : puts("head is not null"), printf("head->data: %d\n", iL->head->data);

    int_empty(iL) == true ?
        puts("true") : puts("false");

    int_traverse(iL);
}


PRIVATE void double_operations(void)
{
    double_list* dL = double_new();
    
    double_head(dL);

    double_append(dL, 0.0);
    double_append(dL, 0.0);
    double_append(dL, 0.0);

    double_size(dL) == dL->size ?
        printf("\ndouble size: %d\n", dL->size) : puts(""),puts("not equal");

    double_traverse(dL);
}


PRIVATE void char_operations(void)
{
    char_list* cL = char_new();

    char_append(cL, 'c');
    char_head(cL) == NULL ?
        puts(""),puts("char head is null") : puts(""),puts("char head is not null");

    char_append(cL, 'o');
    char_append(cL, 'v');
    char_push(cL, ' ');
    char_push(cL, 'I');
    char_append(cL, 'e');
    char_insert(cL, 3, 'L');
    char_insert(cL, 0, '0');
    char_insert(cL, 0, '0');
    char_remove(cL, '0');
    char_append(cL, ' ');
    char_append(cL, 'C');
    char_delete(cL, 0);
    char_delete(cL, 2);
    char_push(cL, '\n');
    char_append(cL, '\n');

    char_traverse(cL);
}


PRIVATE void string_operations(void)
{
    string_list* sL = string_new();

    string_append(sL, "whatis");
    string_append(sL, "myip");
    string_append(sL, ".com");
    string_append(sL, "\n\n");
    string_push(sL, "www.");
    string_insert(sL, 0, "https:");
    string_insert(sL, 1, "//");
    string_insert(sL, 6, "\nnslookup duckduckgo.com");
    string_push(sL, "\n");
    string_push(sL, "find you ip address ?");
    string_push(sL, "\n");

    string_get(sL, 0);
    system("");
    printf("%d\n",(string_index(sL, "//")));
    string_pop(sL);

    string_search(sL, "//") == true ?
        puts("found") : puts("not found");

    string_traverse(sL);
}



void MainFunc(void)
{
    int_operations();

    double_operations();    

    char_operations();
    
    string_operations();
}
