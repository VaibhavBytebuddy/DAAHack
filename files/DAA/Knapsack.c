#include <stdio.h>
#include <stdlib.h>

#define ITEMS 3

typedef struct {
    int index;
    double ratio;
} Item;

// Comparator for sorting in descending order by ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    else return 0;
}

int main() {
    int val[ITEMS] = {60, 100, 120};
    int weight[ITEMS] = {10, 20, 30};
    int W = 50;

    Item ratio[ITEMS];

    for (int i = 0; i < ITEMS; i++) {
        ratio[i].index = i;
        ratio[i].ratio = (double)val[i] / weight[i];
    }

    // Sort items based on ratio (descending)
    qsort(ratio, ITEMS, sizeof(Item), compare);

    int capacity = W;
    double finalVal = 0.0;

    for (int i = 0; i < ITEMS; i++) {
        int idx = ratio[i].index;
        if (capacity >= weight[idx]) {
            finalVal += val[idx];
            capacity -= weight[idx];
        } else {
            finalVal += ratio[i].ratio * capacity;
            break;
        }
    }

    printf("Final value = %.2lf\n", finalVal);

    return 0;
}
