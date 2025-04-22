#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 9999999

int primMST(int graph[MAX][MAX], int V) {
    int selected[MAX] = {0};
    int no_edge = 0;
    int total_cost = 0;

    selected[0] = 1; // Start from first vertex

    printf("Edge \tWeight\n");
    while (no_edge < V - 1) {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d\t%d\n", x, y, graph[x][y]);
        total_cost += graph[x][y];
        selected[y] = 1;
        no_edge++;
    }
    return total_cost;
}

int main() {
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (use 0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            //avoid self-loops and set INF for no edge
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    int cost = primMST(graph, V);
    printf("Minimum cost of the spanning tree = %d\n", cost);

    return 0;
}

// (1)
// 0------1
// | \    |
// |  \   |
// 4   3  2
// |    \ |
// 2------3
//    (5)


// 0 1 2 3
// 0 [0 1 4 3]
// 1 [1 0 0 2]
// 2 [4 0 0 5]
// 3 [3 2 5 0]
