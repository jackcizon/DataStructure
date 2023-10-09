#include"adjlist.h"

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(size_t numVertices, enum GraphType type) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    // allocate memory to adj_list
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    graph->graphType = type;
    // init list->head
    for (size_t i = 0; i < numVertices; ++i) 
    {
        // it is similar to a chain stack
        graph->array[i].head = NULL;
        //...->(null)
        //  /\.
        //  ||
        // head
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {

    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    if (graph->graphType == Undirected) {
        // Add an edge from dest to src for undirected graphs
        newNode = createNode(src);
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
        //...->newnode->null
        //  /\.
        //  ||
        //  head
    }
}

// Function to delete an edge between two vertices
void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* currentNode = graph->array[src].head;
    struct Node* prevNode = NULL;

    while (currentNode != NULL && currentNode->data != dest) 
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) 
    {
        // if list is empty
        return;
    }
    if (prevNode == NULL) 
    {
        // edge to be deleted is the head of the list
        graph->array[src].head = currentNode->next;
    } 
    else 
    {
        prevNode->next = currentNode->next;
    }
    free(currentNode);
    if (graph->graphType == Undirected) {
        // Remove the edge from dest to src for undirected graphs
        currentNode = graph->array[dest].head;
        prevNode = NULL;

        while (currentNode != NULL && currentNode->data != src) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        if (currentNode == NULL) 
        {
            // Edge does not exist
            return;
        }
        if (prevNode == NULL) 
        {
            // Edge to be deleted is the head of the list
            graph->array[dest].head = currentNode->next;
        } 
        else 
        {
            prevNode->next = currentNode->next;
        }
        free(currentNode);
    }
}

// Function to remove a vertex and all its incident edges from the graph
void removeVertex(struct Graph* graph, size_t vertex) {
    if (vertex < 0 || vertex >= graph->numVertices) {
        // Invalid vertex index
        return;
    }

    // Free the memory for the adjacency list of the removed vertex
    struct Node* currentNode = graph->array[vertex].head;
    
    while (currentNode != NULL) {
        struct Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    // Set the head of the adjacency list for the removed vertex to NULL
    graph->array[vertex].head = NULL;

    // Remove edges to the removed vertex from other vertices' adjacency lists
    for (int v = 0; v < graph->numVertices; ++v) {
        if (v != vertex) {
            struct Node* prevNode = NULL;
            struct Node* current = graph->array[v].head;

            while (current != NULL) {
                if (current->data == vertex) {
                    if (prevNode == NULL) {
                        // The edge is at the head of the list
                        graph->array[v].head = current->next;
                    } else {
                        prevNode->next = current->next;
                    }

                    free(current);
                    break;
                }

                prevNode = current;
                current = current->next;
            }
        }
    }
}


// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    printf("Graph Type: %s\n", (graph->graphType == Directed) ? "Directed" : "Undirected");
    for (int v = 0; v < graph->numVertices; ++v) {
        struct Node* currentNode = graph->array[v].head;
        printf("Adjacency list of vertex %d: ", v);//this is vertex data, not vertex->head, and no link about v and vertex, if you wana optimize, implement foreach() to loop all vertices

        while (currentNode) {
            printf("%d -> ", currentNode->data);
            currentNode = currentNode->next;
        }

        printf("NULL\n");
    }
}


// Function to destroy the graph and free all memory
void destroyGraph(struct Graph* graph) {
    if (graph == NULL) {
        return;  // No need to destroy if the graph is NULL
    }

    for (int v = 0; v < graph->numVertices; ++v) {
        struct Node* currentNode = graph->array[v].head;
        while (currentNode != NULL) {
            struct Node* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
        graph->array[v].head = NULL; // Set the head to NULL after freeing the nodes
    }

    free(graph->array); // Free the adjacency list array
    free(graph); // Free the graph itself
}

