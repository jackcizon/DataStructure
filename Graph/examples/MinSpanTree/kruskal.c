#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct DisjointSet
{
    int* parent;
    int* rank;
} DisjointSet;

typedef struct Edge
{
    int cost;
    char n1;
    char n2;
} Edge;

typedef struct Graph
{
    Edge* edges;
    int total_edges;
} Graph;

DisjointSet* NewUnion(int vertexno);
int Find(DisjointSet* uf, int val);
void Unite(DisjointSet* uf, int n1, int n2);
int IsSame(DisjointSet* uf, int n1, int n2);
Graph* NewGraph(int size);
void add_edge(Graph* g, int cost, char c1, char c2);
void AddEdges(Graph* graph);
int compare_edges(const void* a, const void* b);
void kruskal(Graph* g);
void FreeGraph(Graph* graph);

int main(int argc, char const *argv[])
{
    Graph* graph = NewGraph(8);

    AddEdges(graph);

    kruskal(graph);

    FreeGraph(graph);
    return 0;
}

// init a disjoint set 
DisjointSet *NewUnion(int vertexno)
{
    DisjointSet *uf = (DisjointSet *)malloc(sizeof *uf);

    // init parent array
    uf->parent = (int*)calloc(vertexno, sizeof(int));
    //init rank array
    uf->rank = (int*)calloc(vertexno, sizeof(int));

    for (int i = 0; i < vertexno; i++)
    {
        // set parent to i
        uf->parent[i] = i;
        // init rank to 0
        uf->rank[i] = 0;
    }

    return uf;
}

// return root of val, every uf's root is parent[i]
int Find(DisjointSet *uf, int val)
{
    if (uf->parent[val] != val)
    {
        uf->parent[val] = Find(uf, uf->parent[val]);
    }

    return uf->parent[val];
}

void Unite(DisjointSet *uf, int n1, int n2)
{
    int root_n1 = Find(uf, n1);
    int root_n2 = Find(uf, n2);

    // is same root, then no need to unite them
    if (root_n1 == root_n2)
    {
        return;
    }

    if (uf->rank[root_n1] < uf->rank[root_n2])
    {
        uf->parent[root_n1] = root_n2;
    }
    else
    {
        uf->parent[root_n2] = root_n1;
        if (uf->rank[root_n1] == uf->rank[root_n2])
        {
            uf->rank[root_n1] += 1;
        }
    }
}

// checks if two nodes are already connected within the Disjoint Set structure. 
// If they are, it indicates that forming an edge between these two nodes would create a cycle, 
// which is generally undesirable in certain algorithms like 
// Kruskal's algorithm for finding minimum spanning trees.
int IsSame(DisjointSet *uf, int n1, int n2)
{
    return Find(uf, n1) == Find(uf, n2);
}

Graph *NewGraph(int size)
{
    Graph *g = (Graph *)malloc(sizeof *g);
    g->total_edges = 0;
    // consider the worst case scenario
    g->edges = (Edge *)malloc(size * size * sizeof(Edge));
    return g;
}

void add_edge(Graph *g, int cost, char c1, char c2)
{
    // unsorted cost array
    g->edges[g->total_edges].cost = cost;
    g->edges[g->total_edges].n1 = c1;
    g->edges[g->total_edges].n2 = c2;
    g->total_edges += 1;
}

void AddEdges(Graph* graph)
{
    add_edge(graph, 3, 'D', 'A');
    add_edge(graph, 3, 'C', 'A');
    add_edge(graph, 2, 'B', 'A');
    add_edge(graph, 2, 'A', 'B');
    add_edge(graph, 4, 'C', 'B');
    add_edge(graph, 3, 'E', 'B');
    add_edge(graph, 3, 'A', 'C');
    add_edge(graph, 5, 'D', 'C');
    add_edge(graph, 1, 'E', 'C');
    add_edge(graph, 4, 'B', 'C');
    add_edge(graph, 3, 'A', 'D');
    add_edge(graph, 5, 'C', 'D');
    add_edge(graph, 7, 'F', 'D');
    add_edge(graph, 8, 'F', 'E');
    add_edge(graph, 1, 'C', 'E');
    add_edge(graph, 3, 'B', 'E');
    add_edge(graph, 9, 'G', 'F');
    add_edge(graph, 8, 'E', 'F');
    add_edge(graph, 7, 'D', 'F');
    add_edge(graph, 9, 'F', 'G');
}

int compare_edges(const void *a, const void *b)
{
    return ((Edge *)a)->cost - ((Edge *)b)->cost;
}

void kruskal(Graph *g)
{
    DisjointSet *uf = NewUnion(g->total_edges);
    int total_cost = 0;
    Edge *MST = (Edge *)malloc(g->total_edges * sizeof *MST);
    int MST_size = 0;

    // sorted cost array
    qsort(g->edges, g->total_edges, sizeof(Edge), compare_edges);

    // loop all sorted edges and check if have cycles 
    for (int i = 0; i < g->total_edges; i++)
    {
        Edge e = g->edges[i];
        int n1 = e.n1 - 'A';
        int n2 = e.n2 - 'A';

        // check cycles
        if (!IsSame(uf, n1, n2))
        {
            total_cost += e.cost;
            // unite disjoint sets
            Unite(uf, n1, n2);
            // record in MST array
            MST[MST_size++] = e;
        }
    }

    printf("Minimum spanning tree:\n");
    for (int i = 0; i < MST_size; i++)
    {
        Edge edge = MST[i];
        printf("(%c, %c, %d)\n", edge.n1, edge.n2, edge.cost);
    }
    printf("Total cost: %d\n", total_cost);
}

void FreeGraph(Graph* graph)
{
    free(graph->edges);
    free(graph);
}
