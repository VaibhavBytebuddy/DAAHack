#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

// Comparator function to sort jobs by profit in descending order
int compare(const void* a, const void* b) {
    Job* j1 = (Job*)a;
    Job* j2 = (Job*)b;
    return j2->profit - j1->profit;
}

int main() {
    int jobsInfo[4][2] = {
        {4, 20},
        {1, 10},
        {1, 40},
        {1, 30}
    };

    int n = 4;
    Job jobs[n];

    for (int i = 0; i < n; i++) {
        jobs[i].id = i;
        jobs[i].deadline = jobsInfo[i][0];
        jobs[i].profit = jobsInfo[i][1];
    }

    // Sort jobs based on profit
    qsort(jobs, n, sizeof(Job), compare);

    int result[n]; // To store result (sequence of jobs)
    int slot[n];   // To keep track of free time slots

    for (int i = 0; i < n; i++)
        slot[i] = 0;//make slot false

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                result[j] = jobs[i].id;
                slot[j] = 1;//make slot true
                break;
            }
        }
    }

    printf("Job sequence with maximum profit:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i])
            printf("Job%d ", result[i]);
    }
    printf("\n");

    return 0;
}
