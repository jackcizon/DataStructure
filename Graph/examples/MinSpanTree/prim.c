#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct MinHeap{
    int *array;
    int capacity;
    int size;
} MinHeap;

typedef struct Edge
{
    int cost;
    int n1;
    int n2;
} Edge;

typedef struct Graph
{
    Edge* edges;
    int total_edges;
} Graph;

Graph* createGraph(int numVertices);
void addEdge(Graph* g, int cost, int n1, int n2);
void primMST(Graph* graph, int start);

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


int main(int argc, char const *argv[])
{
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 2, 0, 1);
    addEdge(graph, 3, 0, 2);
    addEdge(graph, 8, 1, 2);
    addEdge(graph, 5, 1, 3);
    addEdge(graph, 7, 2, 4);
    addEdge(graph, 1, 3, 4);

    int start = 0;
    primMST(graph, start);

    return 0;
}

Graph* createGraph(int numVertices)
{
    Graph* g = (Graph*)malloc(sizeof *g);
    g->total_edges = 0;
    // consider the worst case scenario
    g->edges = (Edge *)malloc(numVertices * numVertices * sizeof(Edge));
    return g;
}

void addEdge(Graph *g, int cost, int c1, int c2)
{
    // unsorted cost array
    g->edges[g->total_edges].cost = cost;
    g->edges[g->total_edges].n1 = c1;
    g->edges[g->total_edges].n2 = c2;
    g->total_edges += 1;
}

void primMST(Graph* graph, int start) {
    int numVertices = graph->total_edges;
    int* parent = (int*)malloc(numVertices * sizeof(int)); // To store constructed MST
    int* cost = (int*)malloc(numVertices * sizeof(int)); // cost values used to pick minimum weight edge in cut
    int* inMST = (int*)malloc(numVertices * sizeof(int)); // To represent set of vertices not yet included in MST
    MinHeap* minHeap = createMinHeap(numVertices);

    // Initialize all costs as infinite and inMST[] as false
    for (int i = 0; i < numVertices; ++i) {
        cost[i] = INT_MAX;
        inMST[i] = 0;
    }

    // Insert source vertex into the heap and initialize its cost to 0
    cost[start] = 0;
    insert(minHeap, start);

    // Construct MST
    while (getHeapSize(minHeap) > 0) {
        // Extract the vertex with minimum cost value
        int u = extractMin(minHeap);

        // Add vertex u to MST
        inMST[u] = 1;

        // Update cost value and insert into the heap for all adjacent vertices of u
        for (int i = 0; i < graph->total_edges; ++i) {
            Edge edge = graph->edges[i];
            if (edge.n1 == u || edge.n2 == u) {
                int v = (edge.n1 == u) ? edge.n2 : edge.n1;
                if (!inMST[v] && edge.cost < cost[v]) {
                    cost[v] = edge.cost;
                    parent[v] = u;
                    insert(minHeap, v);
                }
            }
        }
    }

    // Print MST
    printf("Edges of MST:\n");
    int total_cost = 0;
    for (int i = 1; i < numVertices; ++i) {
        if (cost[i] == INT_MAX)
        {
            continue;
        }
        else
        {
            printf("(%d, %d) - cost: %d\n", parent[i], i, cost[i]);
            total_cost += cost[i];
        }
    }

    printf("total min cost: %d\n", total_cost);

    // Free dynamically allocated memory
    free(parent);
    free(cost);
    free(inMST);
    free(minHeap->array);
    free(minHeap);
}

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