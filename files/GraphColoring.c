#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to print colors assigned to vertices
void printColors(int color[], int V) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

// Function to assign colors
void graphColoring(int graph[MAX][MAX], int V) {
    int result[V];

    // Initialize all vertices as unassigned (-1)
    for (int i = 0; i < V; i++)
        result[i] = -1;

    // Assign the first color to the first vertex
    result[0] = 0;

    // A temporary array to store available colors
    bool available[V];
    for (int i = 0; i < V; i++)
        available[i] = false;

    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++) {
        // Mark colors of adjacent vertices as unavailable
        for (int i = 0; i < V; i++) {
            if (graph[u][i] == 1 && result[i] != -1)
                available[result[i]] = true;
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (available[cr] == false)
                break;
        }

        result[u] = cr;  // Assign the found color

        // Reset the available array for the next iteration
        for (int i = 0; i < V; i++)
            available[i] = false;
    }

    printColors(result, V);
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nGraph Coloring Result:\n");
    graphColoring(graph, V);

    return 0;
}

// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 1 1 1
// 1 0 1 0
// 1 1 0 1
// 1 0 1 0
