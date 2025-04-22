#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Find the vertex with the minimum distance value, from the set of vertices not yet processed
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Print the final shortest distance from source
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Dijkstra algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V];   // sptSet[i] is true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0; // Distance from source to itself is 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Pick the min distance vertex not yet processed
        sptSet[u] = true; // Mark the vertex as processed

        // Update dist[v] of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if not in sptSet, there's an edge from u to v,
            // and total weight of path from src to v through u is smaller
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    // Example graph (represented as adjacency matrix)
    int graph[V][V] = {
        {0, 4, 0, 0, 8},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 2},
        {0, 0, 7, 0, 9},
        {8, 0, 2, 9, 0}
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
