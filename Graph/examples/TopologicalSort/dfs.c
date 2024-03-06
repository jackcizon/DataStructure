#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// for undirected graph

typedef struct graph {
    int** matrix;
    int Vertices;
} graph;

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

void DFS(graph* g, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int dest = 0; dest < g->Vertices; dest++) {
        if (g->matrix[vertex][dest] && !visited[dest]) {
            DFS(g, dest, visited);
        }
    }
}

void dfs_traversal(graph* g) {
    bool* visited = (bool*)calloc(g->Vertices, sizeof(bool));

    printf("DFS traversal: ");
    for (int i = 0; i < g->Vertices; i++) {
        if (!visited[i]) {
            DFS(g, i, visited);
        }
    }
    
    free(visited);
}

int main(int argc, char const *argv[]) {
    graph* graph = NewGraph(5);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 2, 4);

    dfs_traversal(graph);
    
    // Free memory
    for (int i = 0; i < graph->Vertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
    
    return 0;
}
