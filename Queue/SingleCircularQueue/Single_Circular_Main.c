#include"single_circular_queue.h"


queue(int);


int main(int argc, char const *argv[])
{
    int_queue* iq = int_new();

    int_enqueue(iq, 0);

    int_dequeue(iq);

    int_enqueue(iq, 3);

    int_traverse(iq);

    return 0;
}
