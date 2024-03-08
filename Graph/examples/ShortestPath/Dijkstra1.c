/**
 * @file Dijkstra.c
 * @brief adj list implementation 
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define INF INT_MAX
#define NODES 6
#define UNVISITED 0  // unvisited
#define CURRENT_PROCESSED 1   // current_visited
#define VISITED 2  // visited_min_cost

typedef struct Edge
{
    int dest;
    int weight;
    struct Edge* next;
} Edge;

// adj list
typedef struct Vertex
{
    Edge* head;
} Vertex;

typedef struct Graph
{
    int vertices;
    Vertex* array;
} Graph;

Graph* NewGraph(int verties);
Edge* NewEdge(int dest, int weight);
void add_edge(Graph* graph, int src, int dest, int weight);
void addEdges(Graph* graph);
void init_helper(int distance[], int status[], int nodes, int start_node);
void update_helper(int u, int v, int weight, int distance[], int status[]);
void dijkstra(Graph* graph, int start_node, int distance[], int status[]);
int getShortestPath(int distance[], int end_node);
void Free(Graph* graph);

int main(int argc, char const *argv[])
{
    Graph* graph = NewGraph(6);
    int distance[6];
    int status[6];
    addEdges(graph);
    dijkstra(graph, 0, distance, status);
    
    printf(
        "The shortest path from node 0 to node 5 is: %d\n", 
        getShortestPath(distance, 5)
    );

    Free(graph);
    
    return 0;
}

Graph* NewGraph(int vertices)
{
    Graph* graph = (Graph*)malloc(sizeof *graph);
    graph->vertices = vertices;
    graph->array = (Vertex*)malloc(graph->vertices * sizeof(Vertex));
    
    for (int i = 0; i < graph->vertices; i++)
    {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

Edge* NewEdge(int dest, int weight)
{
    Edge* edge = (Edge*)malloc(sizeof *edge);
    edge->dest = dest;
    edge->next = NULL;
    edge->weight = weight;
}

void add_edge(Graph* graph, int src, int dest, int weight)
{
    Edge* edge = NewEdge(dest, weight);
    edge->next = graph->array[src].head;
    graph->array[src].head = edge;
}

void addEdges(Graph* graph)
{
    add_edge(graph, 0, 1, 4);
    add_edge(graph, 0, 2, 2);
    add_edge(graph, 1, 2, 1);
    add_edge(graph, 1, 3, 5);
    add_edge(graph, 2, 3, 8);
    add_edge(graph, 2, 4, 10);
    add_edge(graph, 3, 4, 2);
    add_edge(graph, 3, 5, 6);
    add_edge(graph, 4, 5, 3);
}

void init_helper(int distance[], int status[], int nodes, int start_node)
{
    for (int i = 0; i < nodes; i++)
    {
        distance[i] = INF;
        status[i] = UNVISITED;
    }

    distance[start_node] = 0;
    status[start_node] = CURRENT_PROCESSED;
}

void update_helper(int u, int v, int weight, int distance[], int status[])
{
    if (distance[v] > distance[u] + weight)
    {
        distance[v] = distance[u] + weight;
        status[v] = CURRENT_PROCESSED;
    }
}

void dijkstra(Graph* graph, int start_node, int distance[], int status[])
{
    init_helper(distance, status, graph->vertices, start_node);
    int u;
    int curr_dest;
    int min_distance;

    while (true)
    {
        min_distance = INF;
        u = -1;

        for (int i = 0; i < graph->vertices; i++)
        {
            if (min_distance > distance[i] && status[i] != VISITED)
            {
                u = i;
                min_distance = distance[i];
            }
        }

        if (u == -1)
        {
            break;
        }
        
        status[u] = VISITED;
        Edge* curr = graph->array[u].head;
        while (curr)
        {
            curr_dest = curr->dest;
            update_helper(u, curr_dest, curr->weight, distance, status);
            curr = curr->next;
        }
    }
}

int getShortestPath(int distance[], int end_node)
{
    if (distance[end_node] == INF)
    {
        return -1;
    }
    else
    {
        return distance[end_node];
    }
}

void Free(Graph* graph)
{
    for (int i = 0; i < graph->vertices; ++i) {
        Edge* current = graph->array[i].head;
        while (current != NULL) {
            Edge* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->array);
    free(graph);
}
