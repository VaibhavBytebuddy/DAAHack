#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure to represent a graph
typedef struct {
    int V, E;
    Edge* edge;
} Graph;

// Create a graph
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Find set of an element i with path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two sets by rank
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare edges by weight (used in qsort)
int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

// Kruskal's algorithm
void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];  // Store the result
    int e = 0;  // Index for result[]
    int i = 0;  // Index for sorted edges

    // Step 1: Sort edges in increasing order of weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is V-1
    while (e < V - 1 && i < graph->E) {
        // Pick the smallest edge
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn’t cause a cycle
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print result
    printf("Edges in Minimum Spanning Tree (Kruskal):\n");
    int minCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Total weight of MST: %d\n", minCost);
}

int main() {
    int V = 4;  // vertices
    int E = 5;  // edges
    Graph* graph = createGraph(V, E);

    // Add edges
    graph->edge[0] = (Edge){0, 1, 10};
    graph->edge[1] = (Edge){0, 2, 6};
    graph->edge[2] = (Edge){0, 3, 5};
    graph->edge[3] = (Edge){1, 3, 15};
    graph->edge[4] = (Edge){2, 3, 4};

    kruskalMST(graph);

    return 0;
}
