#include <stdio.h>
#include <string.h>

// Function to find length of LCS
int LCS_Length(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int L[m+1][n+1];

    // Build L[m+1][n+1] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0; // Base case
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = 1 + L[i - 1][j - 1]; // Match found
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? 
                           L[i - 1][j] : L[i][j - 1]; // Max of top or left
        }
    }

    return L[m][n]; // Length of LCS
}

int main() {
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    int length = LCS_Length(X, Y);
    printf("Length of Longest Common Subsequence is: %d\n", length);

    return 0;
}
