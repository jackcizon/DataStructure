#include"adjmatrix.h"

Graph* NewGraph(size_t size, GraphType type)
{
    Graph* G = malloc(sizeof *G);
    G->size = size;
    G->type = type;
    G->matrix = malloc(size * sizeof(int*));
    for (size_t i = 0; i < size; i++)
    {
        G->matrix[i] = calloc(size, sizeof(int));
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
}


void DeleteEdge(Graph* G, size_t src, size_t dest)
{
    G->matrix[src][dest] = 0;
    if(G->type == UNDIRECTED)
    {
        G->matrix[dest][src] = 0;
    }
}


void Traverse(Graph* G)
{
    printf("    ");
    for (size_t i = 0; i < G->size; i++)
    {
        printf("%4d", i);
    }
    printf("\n\n");
    
    for (size_t i = 0; i < G->size; i++)
    {
        printf("%2ld: ", i);
        for (size_t j = 0; j < G->size; j++)
        {
            printf("%4d", G->matrix[i][j]);
        }
        printf("\n\n");
    }
}


void Destroy(Graph* G)
{
    for (size_t i = 0; i < G->size; i++)
    {
        free(G->matrix[i]);
    }
    free(G->matrix);
    free(G);
    G = NULL;
}


int* GetAdjVertices(Graph* G, int vertex, int* count)
{
    int* adjacent = malloc(G->size * sizeof(int));
    *count = 0;
    for (size_t i = 0; i < G->size; i++)
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