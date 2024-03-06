#include"graph.h"
#include<stdbool.h>

// only undirected graph

void top_sort_util(graph* g, int vertex_src, int* visited, int* stack, int* stack_index);
void top_sort(graph* g);

int main(int argc, char const *argv[])
{
    graph* graph = NewGraph(5);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 2, 4);

    top_sort(graph);
    return 0;
}

void top_sort_util(graph* g, int vertex_src, int* visited, int* stack, int* stack_index)
{
    // set current vertex as visited
    visited[vertex_src] = 1;

    for (size_t dest = 0; dest < g->Vertices; dest++)
    {
        if (g->matrix[vertex_src][dest] && !visited[dest])
        {
            top_sort_util(g, dest, visited, stack, stack_index);
        }
    }

    stack[(*stack_index)++] = vertex_src;
}

void top_sort(graph* g)
{
    // init all vertices as unvisited
    int* visited = (int*)calloc(g->Vertices, sizeof(int));
    int* stack = (int*)calloc(g->Vertices, sizeof(int));
    int stack_index = 0;

    for (int i = 0; i < g->Vertices; i++)
    {
        if (!visited[i])
        {
            top_sort_util(g, i, visited, stack, &stack_index);
        }
    }
    
    printf("Topological Sort Order: ");
    for (int i = g->Vertices - 1; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    free(visited);
    free(stack);
}
