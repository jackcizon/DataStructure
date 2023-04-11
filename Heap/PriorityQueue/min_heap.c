#include"min_heap.h"


Heap* NewHeap(size_t capacity)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}


void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Heapify(Heap* H, int root)
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < H->size && H->data[left] < H->data[smallest])
    {
        smallest = left;
    }
    if (right < H->size && H->data[right] < H->data[smallest])
    {
        smallest = right;
    }

    if (smallest != root) {
        Swap(&H->data[root], &H->data[smallest]);

        // Recursively heapify the affected subtree
        Heapify(H, smallest);
    }
}


void HeapPush(Heap* H, int value)
{
    if (H->size == H->capacity)
    {
        H->capacity *= 2;
        H->data = realloc(H->data, sizeof(int) * H->capacity);
    }

    H->data[H->size] = value;
    H->size += 1;

    int index = H->size - 1;
    while (index > 0 && H->data[index] < H->data[(index - 1) / 2]/*if data.index < parent(index)*/)
    {
        Swap(&H->data[index], &H->data[(index - 1) / 2]);
        //get the parent
        index = (index - 1) / 2;
    }
}


void HeapPop(Heap* H)
{
    if (H->size == 0)
    {
        fprintf(stderr, "Heap size = %d!\n", H->size);
        exit(EXIT_FAILURE);
    }

    Swap(&H->data[0], &H->data[H->size - 1]);
    H->size--;

    Heapify(H, 0);
}


void Traverse(Heap* H)
{
    for (size_t i = 0; i < H->size; i++)
    {
        printf("%d ", H->data[i]);
    }
}