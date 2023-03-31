#include"adjmatrix.h"

Graph* NewGraph(size_t Vertices, GraphType type)
{
    Graph* G = malloc(sizeof *G);
    G->Vertices = Vertices;
    G->Arcs = 0;
    G->type = type;
    G->matrix = malloc(Vertices * sizeof(int*));
    for (size_t i = 0; i < Vertices; i++)
    {
        G->matrix[i] = calloc(Vertices, sizeof(int));
    }
    return G;
}


void AddEdge(Graph* G, size_t src, size_t dest, size_t weight)
{
    G->matrix[src][dest] = weight;
    if(G->type == UNDIRECTED)
    {
        G->matrix[dest][src] = weight;
    }
    G->Arcs += 1;
}


void DeleteEdge(Graph* G, size_t src, size_t dest)
{
    G->matrix[src][dest] = 0;
    if(G->type == UNDIRECTED)
    {
        G->matrix[dest][src] = 0;
    }
    G->Arcs -= 1;
}


void Traverse(Graph* G)
{
    printf("    ");
    for (size_t i = 0; i < G->Vertices; i++)
    {
        printf("%4d", i);
    }
    printf("\n\n");
    
    for (size_t i = 0; i < G->Vertices; i++)
    {
        printf("%2ld: ", i);
        for (size_t j = 0; j < G->Vertices; j++)
        {
            printf("%4d", G->matrix[i][j]);
        }
        printf("\n\n");
    }
}


void Destroy(Graph* G)
{
    for (size_t i = 0; i < G->Vertices; i++)
    {
        free(G->matrix[i]);
    }
    free(G->matrix);
    free(G);
    G = NULL;
}


int* GetAdjVertices(Graph* G, int vertex, int* count)
{
    int* adjacent = malloc(G->Vertices * sizeof(int));
    *count = 0;
    for (size_t i = 0; i < G->Vertices; i++)
    {
        //check columns
        if (G->matrix[vertex][i] != 0)
        {
            adjacent[*count] = i;
            *count += 1;
        }
        else if(G->type == UNDIRECTED && G->matrix[i][vertex] != 0)
        {
            adjacent[*count] = i;
            *count += 1;
        }
    }
    adjacent = realloc(adjacent, *count * sizeof(int));
    return adjacent;
}


size_t NumVertices(Graph* G)
{
    return G->Vertices;
}


size_t NumArcs(Graph* G)
{
    return G->Arcs;
}
