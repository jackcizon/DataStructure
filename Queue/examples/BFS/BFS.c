#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define a structure for the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new queue node
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1); // You can handle this error differently if needed
    }
    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

// BFS function
void BFS(int graph[][7], int start, int vertices) {
    struct Queue* queue = createQueue();
    int visited[vertices]; // To keep track of visited vertices

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    visited[start] = 1; // Mark the starting vertex as visited
    printf("Breadth-First Traversal starting from vertex %d: ", start);

    enqueue(queue, start); // Enqueue the starting vertex

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Visit all adjacent vertices of the current vertex
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    printf("\n");
}

int main() {
    // Define an example adjacency matrix for a graph
    int graph[7][7] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0}
    };

    int vertices = 7; // Number of vertices in the graph
    int startVertex = 0; // Starting vertex for BFS

    BFS(graph, startVertex, vertices);

    return 0;
}
