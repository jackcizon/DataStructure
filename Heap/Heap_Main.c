#include"min_heap.h"

int main(int argc, char** argv)
{
    Heap* H = NewHeap(5);

    int arr[] = {1, 2, 4, 2, -1};

    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        HeapPush(H, arr[i]);
    }
    

    HeapPush(H, 10);
    HeapPush(H, 1);
    HeapPush(H, 7);
    HeapPush(H, 4);
    HeapPush(H, 9);

    HeapPop(H);

    Traverse(H);    

    return 0;
}
