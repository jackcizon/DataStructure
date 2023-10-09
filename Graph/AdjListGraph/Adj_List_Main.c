#include"adjlist.h"



int main(int argc, char* argv[]) 
{
    struct Graph* graph = createGraph(5, Directed);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Original Graph:\n");
    printGraph(graph);

    // Delete an edge
    deleteEdge(graph, 1, 3);

    printf("\nGraph after deleting edge (1, 3):\n");
    printGraph(graph);

    // Remove a vertex
    removeVertex(graph, 2);

    printf("\nGraph after removing vertex 2:\n");
    printGraph(graph);

    return 0;
}
