#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int capacity;
    int size;
} MinHeap;

int getParent(int child);
int getLeftChild(int parent);
int getRightChild(int parent);
MinHeap* createMinHeap(int capacity);
void swap(int *a, int *b);
void heapifyUp(MinHeap *heap, int child);
void heapifyDown(MinHeap *heap, int parent);
void insert(MinHeap *heap, int value);
int extractMin(MinHeap *heap);
int getMin(MinHeap* heap);
void printHeap(MinHeap *heap);
int* heapSort(MinHeap* heap);
int getHeapSize(MinHeap* heap);
