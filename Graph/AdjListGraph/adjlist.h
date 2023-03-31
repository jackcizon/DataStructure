#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int Dest;
    size_t weight;
    struct Node* Next;
}
Node;

typedef struct AdjList
{
    char Label;
    Node *Head;
} AdjList;

typedef struct Graph
{
    size_t V;
    AdjList* List;
    bool Directed;
} Graph;


Node* NewNode(int Dest, size_t weight);

Graph* NewGraph(size_t V, bool Directed);

void AddEdge(Graph* G, int src, int dest, size_t weight);

void DeleteEdge(Graph* G, int src, int dest);

void DeleteVertex(Graph* G, int vertex);

void DFS(Graph* G, int v, bool* visited);

void DFSTraversal(Graph* G);

void FreeGraph(Graph* G);


