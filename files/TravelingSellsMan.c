#include <stdio.h>
#include <stdbool.h>

#define MAX 10
#define INF 9999

int tspNearestNeighbor(int graph[MAX][MAX], int n) {
    bool visited[MAX] = {false};
    int cost = 0;
    int count = 0;
    int currentCity = 0;

    visited[currentCity] = true;
    printf("Path: %d ", currentCity);

    while (count < n - 1) {
        int nearest = -1;
        int minDist = INF;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[currentCity][i] < minDist) {
                minDist = graph[currentCity][i];
                nearest = i;
            }
        }

        if (nearest == -1) break;

        visited[nearest] = true;
        cost += minDist;
        currentCity = nearest;
        count++;

        printf("-> %d ", currentCity);
    }

    // Return to starting city
    cost += graph[currentCity][0];
    printf("-> 0\n");

    return cost;
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int totalCost = tspNearestNeighbor(graph, n);
    printf("Total cost of tour: %d\n", totalCost);

    return 0;
}


// Enter number of cities: 4
// Enter distance matrix:
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
