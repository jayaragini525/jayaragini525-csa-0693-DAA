#include <stdio.h>
#include <stdlib.h>
#define MAX_CONTAINERS 100
#define MAX_ITEMS 100
int containerLoader(int items[], int n, int containerCapacity) {
    int containers[MAX_CONTAINERS] = {0};
    int numContainers = 0;
    for (int i = 0; i < n; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (items[j] > items[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = items[i];
        items[i] = items[maxIndex];
        items[maxIndex] = temp;
    }
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < numContainers; j++) {
            if (containers[j] >= items[i]) {
                containers[j] -= items[i];
                break;
            }
        }
        if (j == numContainers) {
            containers[numContainers++] = containerCapacity - items[i];
        }
    }
    return numContainers;
}
int main() {
    int n, containerCapacity;
    int items[MAX_ITEMS];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }
    printf("Enter the capacity of each container: ");
    scanf("%d", &containerCapacity);
    int numContainers = containerLoader(items, n, containerCapacity);
    printf("Minimum number of containers required: %d\n", numContainers);
    return 0;
}
