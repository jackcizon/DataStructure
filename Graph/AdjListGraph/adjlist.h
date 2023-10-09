#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum GraphType {
    Directed,
    Undirected
};

struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list for a vertex
struct AdjList {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    size_t numVertices;
    struct AdjList* array;
    enum GraphType graphType;
};


struct Node* createNode(int data);
struct Graph* createGraph(size_t numVertices, enum GraphType type);
void addEdge(struct Graph* graph, int src, int dest);
void deleteEdge(struct Graph* graph, int src, int dest);
void removeVertex(struct Graph* graph, size_t vertex);
void printGraph(struct Graph* graph);
void destroyGraph(struct Graph* graph);
