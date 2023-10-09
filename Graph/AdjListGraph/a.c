#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a macro for foreach loop
#define foreach(item, array, size) \
    for (int item##_index = 0; item##_index < size; ++item##_index) \
        for (item = array[item##_index]; item; item = NULL)

// Enum to represent the graph type
enum GraphType {
    Directed,
    Undirected
};

// Structure to represent a Node in the adjacency list
struct Node {
    int vertexId;
    struct Node* next;
};

// Structure to represent the adjacency list for a vertex
struct AdjList {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
    enum GraphType graphType;
    char** vertexNames; // Array of strings to store vertex names
};

// Function to create a new Node
struct Node* createNode(int vertexId) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertexId = vertexId;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices, graph type, and vertex names
struct Graph* createGraph(int numVertices, enum GraphType type, char** vertexNames) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    graph->graphType = type;
    graph->vertexNames = vertexNames;

    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    if (graph->graphType == Undirected) {
        // Add an edge from dest to src for undirected graphs
        newNode = createNode(src);
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
    }
}

void delEdge(struct Graph* graph, int src, int dest) {
    struct Node* currentNode = graph->array[src].head;
    struct Node* prevNode = NULL;

    while (currentNode != NULL) {
        if (currentNode->vertexId == dest) {
            if (prevNode == NULL) {
                // If the edge is the first in the list
                graph->array[src].head = currentNode->next;
            } else {
                // If the edge is not the first in the list
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
}

// Function to remove a vertex from the graph
void removeVertex(struct Graph* graph, int vertexId) {
    // Remove the vertex from the adjacency list
    struct Node* currentNode = graph->array[vertexId].head;
    struct Node* nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    graph->array[vertexId].head = NULL;

    // Clear the vertex name
    graph->vertexNames[vertexId] = NULL;

    // Remove edges to the removed vertex from other vertices
    for (int v = 0; v < graph->numVertices; ++v) {
        if (v != vertexId) {
            delEdge(graph, v, vertexId);
        }
    }
}

void freeGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        struct Node* currentNode = graph->array[v].head;
        struct Node* nextNode;

        while (currentNode != NULL) {
            nextNode = currentNode->next;
            free(currentNode);
            currentNode = nextNode;
        }
    }
    free(graph->array);

    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->vertexNames[i] != NULL) {
            //free(graph->vertexNames[i]);
            graph->vertexNames[i] = NULL; // Set to NULL after freeing
        }
    }
    //free(graph->vertexNames);

    free(graph);
}


// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    printf("Graph Type: %s\n", (graph->graphType == Directed) ? "Directed" : "Undirected");

    char* vertexName;
    foreach(vertexName, graph->vertexNames, graph->numVertices) {
        printf("Adjacency list of vertex %s: ", vertexName);
        struct Node* currentNode = graph->array[vertexName_index].head;

        while (currentNode) {
            if (graph->graphType == Undirected)
            {
            printf("<==> %s", graph->vertexNames[currentNode->vertexId]);
            }
            else
            {
                printf(" to %s,", graph->vertexNames[currentNode->vertexId]);
            }
            currentNode = currentNode->next;
        }

        printf("\n");
    }
}

int main() {
    char* vertexNames[] = {"city1", "city2", "country1", NULL};
    int numVertices = sizeof(vertexNames) / sizeof(vertexNames[0]);
    enum GraphType type = Directed;
    struct Graph* graph = createGraph(numVertices, type, vertexNames);

    // Add edges using string identifiers
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 1);

    printf("Original Graph:\n");
    printGraph(graph);

    delEdge(graph, 0, 2);
    printf("Graph after deleting edge:\n");
    printGraph(graph);

    // Remove a vertex
    removeVertex(graph, 1);
    printf("Graph after removing vertex:\n");
    printGraph(graph);

    // Clean up and free memory
    freeGraph(graph);
    return 0;
}
