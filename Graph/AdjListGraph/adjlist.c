#include"adjlist.h"


Node* NewNode(int Dest, size_t weight)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->Dest = Dest;
    new_node->weight = weight;
    new_node->Next = NULL;
    return new_node;
}


Graph* NewGraph(size_t V, bool Directed)
{
    Graph* G = malloc(sizeof *G);
    G->V = V;
    G->Directed = Directed;
    G->List = malloc(sizeof(AdjList) * V);
    for (size_t i = 0; i < V; i++)
    {
        G->List[i].Label = 'A' + i;
        G->List[i].Head = NULL;
    }
    return G;
}


void AddEdge(Graph* G, int src, int dest, size_t weight)
{
    Node* new_node = NewNode(dest, weight);
    new_node->Next = G->List->Head;
    G->List[src].Head = new_node;
    if(!G->Directed)
    {
        new_node = NewNode(src, weight);
        new_node->Next = G->List[dest].Head;
        G->List[dest].Head = new_node;
    }
}


void DeleteEdge(Graph* G, int src, int dest)
{
    Node* temp = G->List[src].Head;
    Node* prev = NULL;
    while (temp != NULL)
    {
        //if found
        if (temp->Dest == dest)
        {   //if found is src.head
            if (prev == NULL)
            {
                G->List[src].Head = temp->Next;
            }
            //other location
            else
            {
                prev->Next = temp->Next;
            }
            //free
            Node* to_delete = temp;
            temp = temp->Next;
            free(to_delete);
        }
        //if not found, go next
        else
        {
            prev = temp;
            temp = temp->Next;
        }
    }
}



void DeleteVertex(Graph* G, int vertex)
{
    for (size_t i = 0; i < G->V; i++)
    {
        DeleteEdge(G, i, vertex);
    }
}


void DFS(Graph* G, int v, bool* visited)
{
    visited[v] = true;
    printf("%c ", G->List[v].Label);

    Node* adjNode = G->List[v].Head;
    while (adjNode != NULL)
    {
        int dest = adjNode->Dest;
        if (!visited[dest])
        {
            DFS(G, dest, visited);
        }
        adjNode = adjNode->Next;
    }
}

void DFSTraversal(Graph* G)
{
    bool visited[G->V];
    for (int i = 0; i < G->V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < G->V; i++)
    {
        if (!visited[i])
        {
            DFS(G, i, visited);
        }
    }
}


void FreeGraph(Graph* G)
{
    for (size_t i = 0; i < G->V; i++)
    {

        Node* temp = G->List[i].Head;
        while (temp != NULL)
        {
            Node* to_delete = temp;
            temp = temp->Next;
            free(to_delete);
        }
        G->List[i].Head = NULL;
    }
}

