#ifndef ADJMATRIX_H
#define ADJMATRIX_H

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
    int** matrix;
    GraphType type;
    size_t Vertices;//nodes
    size_t Arcs;//connections
}
Graph;

Graph* NewGraph(size_t Vertices, GraphType type);

void AddEdge(Graph* G, size_t src, size_t dest, size_t weight);

void DeleteEdge(Graph* G, size_t src, size_t dest);

void Traverse(Graph* G);

void Destroy(Graph* G);

int* GetAdjVertices(Graph* G, int vertex, int* count);

size_t NumVertices(Graph* G);

size_t NumArcs(Graph* G);

#endif
