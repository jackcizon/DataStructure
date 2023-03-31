#include<stdio.h>
#include<stdlib.h>


typedef enum
{
    DIRECTED,
    UNDIRECTED
}
GraphType;


typedef struct Graph
{
    size_t size;
    int** matrix;
    GraphType type;
}
Graph;

Graph* NewGraph(size_t size, GraphType type);

void AddEdge(Graph* G, size_t src, size_t dest, size_t weight);

void DeleteEdge(Graph* G, size_t src, size_t dest);

void Traverse(Graph* G);

void Destroy(Graph* G);

int* GetAdjVertices(Graph* G, int vertex, int* count);