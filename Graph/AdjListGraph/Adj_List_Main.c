#include"adjlist.h"


int main(int argc, char const *argv[])
{
    size_t V = 5;
    bool Directed = true;

    Graph* G = NewGraph(V, Directed);

    AddEdge(G, 0, 1, 10);
    AddEdge(G, 0, 4, 20);
    AddEdge(G, 1, 2, 30);
    AddEdge(G, 1, 3, 40);
    AddEdge(G, 1, 4, 50);
    AddEdge(G, 2, 3, 60);
    AddEdge(G, 3, 4, 70);
    DeleteEdge(G, 1, 2);
    DeleteVertex(G, 3);

    DFSTraversal(G);

    //FreeGraph(G);
    //may be cycle , and jump into a cycle, and re-free,
    free(G);

    return 0;
}
