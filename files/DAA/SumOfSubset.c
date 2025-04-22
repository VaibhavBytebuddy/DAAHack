#include <stdio.h>
#include <stdlib.h>

void printSubset(int subset[], int subset_size) {
    for (int i = 0; i < subset_size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// Backtracking function to find all subsets that sum up to the target
void findSubset(int arr[], int n, int target, int index, int current_sum, int subset[], int subset_size) {
    // If the current sum equals the target, print the subset
    if (current_sum == target) {
        printSubset(subset, subset_size);
        return;
    }

    // If the current sum exceeds the target or we've processed all elements, return
    if (current_sum > target || index == n) {
        return;
    }

    // Include the current element and recurse
    subset[subset_size] = arr[index];  // Include arr[index]
    findSubset(arr, n, target, index + 1, current_sum + arr[index], subset, subset_size + 1);

    // Exclude the current element and recurse
    findSubset(arr, n, target, index + 1, current_sum, subset, subset_size);
}

int main() {
    int n, target;

    // Input the number of elements and the target sum
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);

    int subset[n];  // Array to store a potential subset
    printf("Subsets with sum %d are:\n", target);

    // Call the backtracking function
    findSubset(arr, n, target, 0, 0, subset, 0);

    return 0;
}
