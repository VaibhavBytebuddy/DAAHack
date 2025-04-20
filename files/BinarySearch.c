#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Function to find the optimal binary search tree cost
int optimalBST(int keys[], int freq[], int n) {
    // Cost table (dp) to store the minimum cost for each subproblem
    int dp[n][n];
    
    // Initialize the cost for a single key (cost is just the frequency of the key)
    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }

    // Build the dp table for more than 1 key
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            // Try each key as the root and calculate the cost
            for (int r = i; r <= j; r++) {
                // Cost of left subtree + right subtree + total frequency in this range
                int cost = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + sum(freq, i, j);

                // Update dp table with the minimum cost
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // Return the optimal cost for the entire range (0 to n-1)
    return dp[0][n - 1];
}

// Function to calculate sum of frequencies between indices i and j
int sum(int freq[], int i, int j) {
    int total = 0;
    for (int k = i; k <= j; k++) {
        total += freq[k];
    }
    return total;
}

int main() {
    int n;

    // Input number of keys
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    // Input the keys and their corresponding frequencies
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies for each key:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    // Calculate the optimal BST cost
    int result = optimalBST(keys, freq, n);

    printf("The minimum search cost for the Optimal Binary Search Tree is: %d\n", result);

    return 0;
}
