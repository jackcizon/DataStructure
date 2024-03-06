#include"graph.h"

graph* NewGraph(int Vertices) {
    graph* g = (graph*)malloc(sizeof *g);
    g->Vertices = Vertices;
    g->matrix = (int**)malloc(Vertices * sizeof(int*));
    for (int i = 0; i < Vertices; i++) {
        g->matrix[i] = calloc(Vertices, sizeof(int));
    }
    return g;
}

void AddEdge(graph* g, int src, int dest) {
    g->matrix[src][dest] = 1;
    g->matrix[dest][src] = 1;
}
