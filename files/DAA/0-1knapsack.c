#include <stdio.h>

// Maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0-1 Knapsack DP Function
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W]; // Maximum value that can be put in knapsack
}

int main() {
    int val[] = {60, 100, 120};   // Values (profits)
    int wt[] = {10, 20, 30};      // Weights
    int W = 50;                   // Capacity of knapsack
    int n = sizeof(val) / sizeof(val[0]);

    int maxProfit = knapsack(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", maxProfit);

    return 0;
}
