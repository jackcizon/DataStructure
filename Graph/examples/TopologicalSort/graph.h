#include<stdio.h>
#include<stdlib.h>

typedef struct graph
{
    int** matrix;
    int Vertices;
} graph;

graph* NewGraph(int Vertices);
void AddEdge(graph* g, int src, int dest);
void FreeGraph(graph* g);
