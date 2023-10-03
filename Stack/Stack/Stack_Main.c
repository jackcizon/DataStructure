#include"stack.h"


stack(int);

stack(float);

stack(double);

stack(char);

stack(string);

#define count 3


void ic_stack_ops(void);
void string_ops(void);
void df_ops(void);


int main(int argc, char const *argv[])
{
    ic_stack_ops();
    puts("");
    
    string_ops();
    puts("");
    
    df_ops();
    puts("");

    puts("press enter to exit...");
    getchar();
    return 0;
}


void ic_stack_ops(void)
{
    int_stack* is = int_new();

    if(is->top == NULL)
    {
        puts("top null");
    }
    else
    {
        puts("not null");
    }

    int_push(is, 3);

    printf("top data: %d\n", is->top->data);

    if(is->top->next == NULL)
    {
        puts("next null");
    }
    else
    {
        puts("next not null");
    }

    int_push(is, 4);
    int_push(is, 5);

    int_clear(is);


    //printf("%d\n", is->top->data);

    //int_traverse(is);

    char_stack* cs = char_new();
    for (size_t i = 0; i < count; i++)
    {
        char_push(cs, 'a');
    }
    char_traverse(cs);
}

void string_ops(void)
{
    string_stack* ss = string_new();
    for (size_t i = 0; i < count; i++)
    {
        string_push(ss, "hello");
        /* code */
    }
    string_pop(ss);
    string_pop(ss);

    string_traverse(ss);
}

void df_ops(void)
{
    float_stack* fs = float_new();
    for (size_t i = 0; i < count; i++)
    {
        float_push(fs, 4.5);
    }
    float_traverse(fs);

    double_stack* ds = double_new();
    for (size_t i = 0; i < count; i++)
    {
        double_push(ds, 1.2);
        /* code */
    }

    double_pop(ds);
    double_pop(ds);
    double_traverse(ds);
}
