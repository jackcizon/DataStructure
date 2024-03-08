#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define NODES 6

#define UNVISITED 0  
#define CURRENT_PROCESSED 1   
#define VISITED 2  

typedef struct {
    int cost[NODES][NODES];     // [src][dest]
    int status[NODES];          // indentify the visited or unvisited
    int distance[NODES];        // current distance  
} Dijkstra;

void initDijkstra(Dijkstra *graph) {
    for (int i = 0; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            // init all nodes costs are INF
            graph->cost[i][j] = INF;
        }
        // init all nodes as unvisited,
        graph->status[i] = UNVISITED; 
        // init all distances as INF
        graph->distance[i] = INF;
    }
}

void dijkstra(Dijkstra *graph, int start_node) {
    // set start node distance to 0
    graph->distance[start_node] = 0;
    graph->status[start_node] = CURRENT_PROCESSED;

    while (1) {
        int min_distance_val = INF;
        //  status variable
        // check if the distance distance[j] of the node j
        // from the src node < min_distance_val,
        // and check the node which will be visited is not "cannot be visited" (black)
        int u = -1;

        for (int j = 0; j < NODES; j++) {
            if (min_distance_val > graph->distance[j] && graph->status[j] != VISITED) {
                u = j;
                min_distance_val = graph->distance[j];
            }
        }

        // if get min_distance
        if (u == -1) break;

        graph->status[u] = VISITED;

        for (int v = 0; v < NODES; v++) {
            // CHECK cost, then update distance
            if (graph->status[v] != VISITED && graph->cost[u][v] != INF) {
                if (graph->distance[v] > graph->distance[u] + graph->cost[u][v]) {
                    graph->distance[v] = graph->distance[u] + graph->cost[u][v];
                    // loop nodes and compare cost
                    graph->status[v] = CURRENT_PROCESSED;
                }
            }
        }
    }
}

int getShortestPath(Dijkstra *graph, int end_node) {
    if (graph->distance[end_node] == INF)
        return -1;
    else
        return graph->distance[end_node];
}

int main() {
    Dijkstra graph;
    initDijkstra(&graph);

    graph.cost[0][1] = 4;
    graph.cost[0][2] = 2;
    graph.cost[1][2] = 1;
    graph.cost[1][3] = 5;
    graph.cost[2][3] = 8;
    graph.cost[2][4] = 10;
    graph.cost[3][4] = 2;
    graph.cost[3][5] = 6;
    graph.cost[4][5] = 3;

    dijkstra(&graph, 0);

    printf(
        "The shortest path from node 0 to node 5 is: %d\n", 
        getShortestPath(&graph, 5)
    );

    return 0;
}
