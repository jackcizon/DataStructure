#include"adjmatrix.h"


int main(int argc, char const *argv[])
{
    Graph* G = NewGraph(4, UNDIRECTED);

    AddEdge(G, 0, 1, 10);
    AddEdge(G, 0, 2, 20);
    AddEdge(G, 1, 2, 30);
    AddEdge(G, 2, 3, 40);
    AddEdge(G, 3, 1, 50);

    DeleteEdge(G, 0, 1);

    puts("adjmatrix : ");
    Traverse(G);

    int count = 0;
    puts("adjvertices : ");
    int* adjacent = GetAdjVertices(G, 2, &count);
    for (size_t i = 0; i < count; i++)
    {
        printf("(%d, 2) ", adjacent[i]);
        if(G->type == UNDIRECTED)
        {
            printf("(2, %d) ", adjacent[i]);
        }
    puts("");
    }

    Destroy(G);

    puts("all executions success!");

    return 0;
}

