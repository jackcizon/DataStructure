#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue
{
    int* array;
    int size;
    int count;
    int front; // small end
    int rear; // large end
} queue;

typedef struct graph
{
    int** matrix;
    int vertices;
} graph;

queue* NewQueue(int size);
void enqueue(queue* q, int val);
bool isFull(queue* q);
bool isEmpty(queue* q);
int dequeue(queue* q);
void freeQueue(queue* q);
void traverse_queue(queue* q);
graph* NewGraph(int vertices);
void addEdge(graph* g, int src, int dest);
void freeGraph(graph* g);
void bfs_traversal_queue(graph* g, int start_vertex);

int main(int argc, char const *argv[])
{
    graph* g = NewGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    addEdge(g, 3, 3);
 
    puts("Breadth First Traversal:");
    bfs_traversal_queue(g, 2);
    freeGraph(g);

    return 0;
}

queue* NewQueue(int size)
{
    queue* q = (queue*)malloc(sizeof *q);
    q->size = size;
    q->count = 0;
    q->array = (int*)calloc(size, sizeof(int));
    q->front = q->rear = 0;

    return q;
}

void enqueue(queue* q, int val)
{
    if (isFull(q))
    {
        perror("queue is full!");
        exit(EXIT_FAILURE);
    }

    q->array[q->rear] = val;
    q->rear += 1;
    q->count += 1;  
}

int dequeue(queue* q)
{
    if (isEmpty(q))
    {
        perror("queue is empty!");
        exit(EXIT_FAILURE);
    }

    int val = q->array[q->front];
    q->front += 1;
    q->count -= 1;

    return val;
}

bool isEmpty(queue* q)
{
    return q->count == 0 ? true : false;
}

bool isFull(queue* q)
{
    return q->count == q->size ? true : false;
}

void freeQueue(queue* q)
{
    free(q->array);
    free(q);
}

void traverse_queue(queue* q)
{
    if (isEmpty(q))
    {
        perror("queue is empty!");
        exit(EXIT_FAILURE);
    }
    
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->array[i]);
    }    
}

graph* NewGraph(int vertices)
{
    graph* g = (graph*)malloc(sizeof *g);
    g->vertices = vertices;
    g->matrix = (int**)malloc(vertices * sizeof(int*));

    for (int i = 0; i < g->vertices; i++)
    {
        g->matrix[i] = calloc(vertices, sizeof(int));
    }

    return g;
}

void addEdge(graph* g, int src, int dest)
{
    g->matrix[src][dest] = 1;
}

void freeGraph(graph* g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        free(g->matrix[i]);
    }

    free(g->matrix);
    free(g);
}

void bfs_traversal_queue(graph* g, int start_vertex)
{
    int* visited = (int*)calloc(g->vertices, sizeof(int));
    queue* q = NewQueue(g->vertices);
    
    // mark as visited and enqueue
    visited[start_vertex] = 1;
    enqueue(q, start_vertex);

    while (q->front != q->rear)
    {
        int dequeue_vertex_src = dequeue(q);
        printf("%d ", dequeue_vertex_src);    
    
        for (int dest = 0; dest < g->vertices; dest++)
        {
            if (g->matrix[dequeue_vertex_src][dest] && !visited[dest])
            {
                visited[dest] = 1;
                enqueue(q, dest);
            }
        }
    }
    
}
