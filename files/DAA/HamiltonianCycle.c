#include <stdio.h>
#include <stdbool.h>

#define V 5  // You can change the number of vertices here

bool isSafe(int v, int graph[V][V], int path[], int pos) {
    // Check if current vertex is adjacent to previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        // If last vertex is connected to the first, then cycle exists
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

bool isHamiltonianCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // Start from vertex 0

    if (!hamCycleUtil(graph, path, 1)) {
        return false;
    }

    // Print the path
    printf("Hamiltonian Cycle exists: ");
    for (int i = 0; i < V; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]); // Back to starting point

    return true;
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix (5x5):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    if (!isHamiltonianCycle(graph))
        printf("No Hamiltonian Cycle exists.\n");

    return 0;
}


// Enter the adjacency matrix (5x5):
// 0 1 1 0 1
// 1 0 1 1 1
// 1 1 0 1 0
// 0 1 1 0 1
// 1 1 0 1 0
