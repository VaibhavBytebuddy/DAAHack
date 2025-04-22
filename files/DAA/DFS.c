#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 7

typedef struct Edge {
    int dest;
    int wt;
    struct Edge* next;
} Edge;

// Create a new edge node
Edge* createEdge(int dest, int wt) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->wt = wt;
    newEdge->next = NULL;
    return newEdge;
}

// Add edge to the adjacency list
void addEdge(Edge* graph[], int src, int dest, int wt) {
    Edge* newNode = createEdge(dest, wt);
    newNode->next = graph[src];
    graph[src] = newNode;
}

// Create the graph
void createGraph(Edge* graph[]) {
    for (int i = 0; i < V; i++)
        graph[i] = NULL;

    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);

    addEdge(graph, 1, 0, 1);
    addEdge(graph, 1, 3, 1);

    addEdge(graph, 2, 0, 1);
    addEdge(graph, 2, 4, 1);

    addEdge(graph, 3, 1, 1);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 3, 5, 1);

    addEdge(graph, 4, 2, 1);
    addEdge(graph, 4, 3, 1);
    addEdge(graph, 4, 5, 1);

    addEdge(graph, 5, 3, 1);
    addEdge(graph, 5, 4, 1);
    addEdge(graph, 5, 6, 1);

    addEdge(graph, 6, 5, 1);
}

// DFS function
void dfs(Edge* graph[], int curr, bool visited[]) {
    printf("%d ", curr);
    visited[curr] = true;

    Edge* temp = graph[curr];
    while (temp != NULL) {
        if (!visited[temp->dest]) {
            dfs(graph, temp->dest, visited);
        }
        temp = temp->next;
    }
}

int main() {
    Edge* graph[V];
    bool visited[V] = {false};

    createGraph(graph);

    printf("DFS Traversal:\n");
    dfs(graph, 0, visited);

    return 0;
}
