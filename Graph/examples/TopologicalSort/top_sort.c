#include"graph.h"
#include<stdbool.h>

// only directed graph
/**
 * @brief Output: 5 4 2 3 1 0
 * @details Explanation: 
 * The first vertex in topological sorting is always a vertex 
 * with an in-degree of 0 (a vertex with no incoming edges).  
 * A topological sorting of the following graph is ¡°5 4 2 3 1 0¡±.
 */

void top_sort_util(graph* g, int vertex_src, int* visited, int* stack, int* stack_top);
void top_sort(graph* g);

int main(int argc, char const *argv[])
{
    graph* graph = NewGraph(6);
    AddEdge(graph, 5, 2);
    AddEdge(graph, 5, 0);
    AddEdge(graph, 4, 0);
    AddEdge(graph, 4, 1);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 1);

    top_sort(graph);
    
    FreeGraph(graph);
    return 0;
}

void top_sort_util(graph* g, int vertex_src, int* visited, int* stack, int* stack_top)
{
    // set current vertex as visited
    visited[vertex_src] = 1;

    for (int dest = 0; dest < g->Vertices; dest++)
    {
        // top_util(0) => no out-degree, push into stack
        // top_util(1) => no out-degree, ~
        // top_util(2) => has in-degree => top_sort(3)
        // since '1' has been visited and pushed into stack, so '3' do not have in-degree, ~
        // then push '2'
        // top_util(4), since '0' has been visited and pushed into stack, ~
        // top_util(5), since '2', '0' are already visited, no more recursion call, ~
        if (g->matrix[vertex_src][dest] && !visited[dest])
        {
            top_sort_util(g, dest, visited, stack, stack_top);
        }
    }

    // push vertex into stack
    stack[(*stack_top)] = vertex_src;
    (*stack_top) += 1;
}

void top_sort(graph* g)
{
    // init all vertices as unvisited
    int* visited = (int*)calloc(g->Vertices, sizeof(int));
    int* stack = (int*)calloc(g->Vertices, sizeof(int));
    int stack_top = 0;

    // start from vertex 0, loop
    for (int vertex = 0; vertex < g->Vertices; vertex++)
    {
        if (!visited[vertex])
        {
            top_sort_util(g, vertex, visited, stack, &stack_top);
        }
    }
    
    printf("Topological Sort Order: ");
    // pop stack values
    for (int i = g->Vertices - 1; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    free(visited);
    free(stack);
    puts("");
}
