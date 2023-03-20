#include"queue.h"


#define count 3

queue(int);

queue(char);

queue(float);

queue(double);

queue(string);



void int_ops(void)
{
    int_queue* iq = int_new();

    for (size_t i = 0; i < count; i++)
    {
        int_enqueue(iq, 1);
        /* code */
    }

    int_dequeue(iq);
    int_dequeue(iq);

    int_traverse(iq);
}


void df_ops(void)
{
    float_queue* fq = float_new();
    double_queue* dq = double_new();

    for (size_t i = 0; i < count; i++)
    {
        double_enqueue(dq, 1.2);
        float_enqueue(fq, 2.3);
        /* code */
    }

    float_dequeue(fq);

    float_traverse(fq);

    double_traverse(dq);
}


void cs_ops(void)
{
    char_queue* cq = char_new();
    string_queue* sq = string_new();

    for (size_t i = 0; i < count; i++)
    {
        string_enqueue(sq, "hil");
        char_enqueue(cq, 'c');
        /* code */
    }

    string_dequeue(sq);
    string_dequeue(sq);
    string_dequeue(sq);

    string_enqueue(sq, "asm");
    string_enqueue(sq, "a");
    string_traverse(sq);

    char_traverse(cq);
}


int main(int argc, char const *argv[])
{
    int_ops();

    df_ops();

    cs_ops();

    return 0;
}