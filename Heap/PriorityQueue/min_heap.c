#include"min_heap.h"

int getParent(int child)
{
    return (child - 1) / 2;
}

int getLeftChild(int parent)
{
    return parent * 2 + 1;
}

int getRightChild(int parent)
{
    return parent * 2 + 2;
}

MinHeap* createMinHeap(int capacity)
{
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(heap->capacity * sizeof(int));
    return heap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int child)
{
    int parent = getParent(child);
    while (child > 0 && heap->array[child] < heap->array[parent]) {
        swap(&heap->array[child], &heap->array[parent]);
        child = parent;
        parent = getParent(child);
    }
}

void heapifyDown(MinHeap *heap, int parent)
{
    int smallest = parent;
    int leftChild = getLeftChild(parent);
    int rightChild = getRightChild(parent);

    if (leftChild < getHeapSize(heap) && heap->array[leftChild] < heap->array[smallest])
        smallest = leftChild;
    if (rightChild < getHeapSize(heap) && heap->array[rightChild] < heap->array[smallest])
        smallest = rightChild;

    if (smallest != parent) {
        swap(&heap->array[parent], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

// push val, re-heapify up
void insert(MinHeap *heap, int value)
{
    if (getHeapSize(heap) == heap->capacity) {
        heap->capacity *= 2;
        heap->array = (int*)realloc(heap->array, heap->capacity * sizeof(int));
    }
    heap->array[getHeapSize(heap)] = value;
    heap->size++;
    // re-heapify, update min-heap Attributes
    heapifyUp(heap, getHeapSize(heap) - 1);
}

// pop val, re-heapify down
int extractMin(MinHeap *heap)
{
    if (getHeapSize(heap) == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    // the min val in min heap is locate in index 0
    int min = getMin(heap);
    heap->array[0] = heap->array[getHeapSize(heap) - 1];
    heap->size--;
    // re-heapify, update min-heap Attributes
    heapifyDown(heap, 0);

    return min;
}

int getMin(MinHeap* heap)
{
    if (getHeapSize(heap) == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    // Assume that the heap has been updated to the latest
    return heap->array[0];
}

void printHeap(MinHeap *heap)
{
    printf("Heap elements: ");
    for (int i = 0; i < getHeapSize(heap); i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int* heapSort(MinHeap* heap)
{
    int* array = (int*)calloc(getHeapSize(heap), sizeof(int));
    int init_size = getHeapSize(heap);
    
    for (int i = 0; i < init_size; i++)
    {
        array[i] = extractMin(heap);   
    }

    for (int i = 0; i < init_size; i++)
    {
        insert(heap, array[i]);
    }
    
    return array;
}

int getHeapSize(MinHeap* heap)
{
    return heap->size;
}
