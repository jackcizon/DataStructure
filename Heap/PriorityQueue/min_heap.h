#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>


typedef struct Heap
{
    int* data;
    size_t size;
    size_t capacity;
}
Heap;

Heap* NewHeap(size_t capacity);

void Swap(int* a, int* b);

void HeapPush(Heap* H, int value);

void Heapify(Heap* H, int root);

void HeapPop(Heap* H);

void Traverse(Heap* H);
