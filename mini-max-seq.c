#include <stdio.h>
#define MAX_ELEMENTS 100
void arrangeSequentially(int arr[], int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int n, i, arr[MAX_ELEMENTS];
    printf("Enter the number of elements (maximum %d): ", MAX_ELEMENTS);
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    arrangeSequentially(arr, n);
    printf("Sequentially arranged elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nMinimum element: %d\n", arr[0]);
    printf("Maximum element: %d\n", arr[n - 1]);
    return 0;
}

