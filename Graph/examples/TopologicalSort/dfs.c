#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph {
    int** matrix;
    int Vertices;
} graph;

typedef struct stack {
    int size;
    int* array;
    int count;
} stack;

stack* NewStack(int size);
void push(stack* s, int val);
int pop(stack* s);
void freeStack(stack* s);
graph* NewGraph(int Vertices);
void AddEdge(graph* g, int src, int dest);
void freeGraph(graph* g);
void dfs_recursion_util(graph* g, int start_vertex, int* visited);
void dfs_traversal_recursion(graph* g, int start_vertex);
void freeGraph(graph* g);
void dfs_traversal_stack(graph* g, int start_vertex);

int main(int argc, char const* argv[])
{
    graph* graph = NewGraph(4);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 2, 0);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 3);

    dfs_traversal_recursion(graph, 2);
    dfs_traversal_stack(graph, 2);

    // Free memory
    freeGraph(graph);

    return 0;
}


stack* NewStack(int size)
{
    stack* s = (stack*)malloc(sizeof *s);
    s->size = size;
    s->count = 0;
    s->array = (int*)malloc(size * sizeof(int));
    return s;
}

void push(stack* s, int val)
{
    if (s->count == s->size)
    {
        perror("stack is full!");
        exit(EXIT_FAILURE);
    }
    
    s->array[s->count] = val;
    s->count += 1;
}

int pop(stack* s)
{
    if (s->count == 0)
    {
        perror("stack empty!");
        exit(EXIT_FAILURE);
    }

    s->count -= 1;
    int val = s->array[s->count];
    
    return val;
}

void freeStack(stack* s)
{
    free(s->array);
    free(s);
}

graph* NewGraph(int Vertices)
{
    graph* g = (graph*)malloc(sizeof *g);
    g->Vertices = Vertices;
    g->matrix = (int**)malloc(Vertices * sizeof(int*));
    
    for (int i = 0; i < Vertices; i++)
    {
        g->matrix[i] = calloc(Vertices, sizeof(int));
    }
    
    return g;
}

void AddEdge(graph* g, int src, int dest)
{
    g->matrix[src][dest] = 1;
}

void dfs_recursion_util(graph* g, int start_vertex, int* visited)
{
    visited[start_vertex] = 1;

    printf("%d ", start_vertex);

    for (int dest = 0; dest < g->Vertices; dest++)
    {
        if (g->matrix[start_vertex][dest] && !visited[dest])
        {
            dfs_recursion_util(g, dest, visited);
        }
    }
}

void dfs_traversal_recursion(graph* g, int start_vertex)
{
    // init visited array all 0
    int* visited = (int*)calloc(g->Vertices, sizeof(int));
    dfs_recursion_util(g, start_vertex, visited);
    puts("");
}

void freeGraph(graph* g)
{
    for (int i = 0; i <g->Vertices; i++)
    {
        free(g->matrix[i]);
    }

    free(g->matrix);
    free(g);
}

void dfs_traversal_stack(graph* g, int start_vertex)
{
    // init visited array all 0
    int* visited = (int*)calloc(g->Vertices, sizeof(int));
    stack* s = NewStack(g->Vertices);

    push(s, start_vertex);

    while (s->count != 0)
    {
        int current_vertex = pop(s);
        if (!visited[current_vertex])
        {
            visited[current_vertex] = 1;
            printf("%d ", current_vertex);

            for (int dest = 0; dest < g->Vertices; dest++)
            {
                if (g->matrix[current_vertex][dest] && ! visited[dest])
                {
                    push(s, dest);
                }
            }   
        }
    }

    freeStack(s);
    free(visited);
    puts("");
}
