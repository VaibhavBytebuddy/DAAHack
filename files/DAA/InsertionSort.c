#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i]; // current element to be placed at correct position
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place the key in its correct position
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Record start time
    clock_t start = clock();

    // Call insertion sort
    insertionSort(arr, n);

    // Record end time
    clock_t end = clock();

    // Calculate time taken in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Display sorted array
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken to sort: %.6f seconds\n", time_taken);

    return 0;
}
