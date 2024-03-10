#include"min_heap.h"

int main(int argc, char** argv)
{
    MinHeap *heap = createMinHeap(10);

    insert(heap, 10);
    insert(heap, 7);
    insert(heap, 11);
    insert(heap, 5);
    insert(heap, 9);
    insert(heap, 1);

    printf("the min heap's min val: %d\n", getMin(heap));
    printHeap(heap);
    int init_size = heap->size;
    int* array = heapSort(heap);
    
    for (int i = 0; i < init_size; i++)
    {
        printf("%d ", array[i]);
    }
    puts("");
    printHeap(heap);

    free(array);
    free(heap->array);
    free(heap);

    return 0;
}
