#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 7

int stack[V];
int top = -1;

typedef struct Edge {
    int dest;
    int wt;
    struct Edge* next;
} Edge;

Edge* createEdge(int dest, int wt) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->wt = wt;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(Edge* graph[], int src, int dest, int wt) {
    Edge* newnode = createEdge(dest, wt);
    newnode->next = graph[src];
    graph[src] = newnode;
}

void createGraph(Edge* graph[]) {
    for (int i = 0; i < V; i++) {
        graph[i] = NULL;
    }

    // Only one-directional edges (DAG)
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 3, 5, 1);
    addEdge(graph, 4, 5, 1);
    addEdge(graph, 5, 6, 1);
}

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

void dfs(Edge* graph[], int curr, bool visited[]) {
    visited[curr] = true;

    Edge* temp = graph[curr];
    while (temp != NULL) {
        if (!visited[temp->dest]) {
            dfs(graph, temp->dest, visited);
        }
        temp = temp->next;
    }

    push(curr);  // After visiting all neighbors, push current node
}

void topoSort(Edge* graph[]) {
    bool visited[V] = { false };

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
        }
    }

    printf("Topological sort: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    Edge* graph[V];

    createGraph(graph);
    printf("DFS traversal using Topological Sort:\n");
    topoSort(graph);

    return 0;
}
