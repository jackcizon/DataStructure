#include"double_circular_queue.h"


queue(int);


int main(int argc, char const *argv[])
{
    int_queue* iq = int_new();

    int_enqueue(iq, 'f', 1);
    int_enqueue(iq, 'r', 2);
    int_enqueue(iq, 'f', 0);
    int_enqueue(iq, 'r', 3);

    int_dequeue(iq, 'f');
    int_dequeue(iq, 'r');

    int_traverse(iq);

    /* code */
    return 0;
}
