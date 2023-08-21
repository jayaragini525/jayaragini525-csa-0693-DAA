#include <stdio.h>
int linearSearch(int arr[], int n, int target, int *numComparisons) {
    for (int i = 0; i < n; i++) {
        (*numComparisons)++;
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}
int main() {
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    int numComparisons = 0;
    int result = linearSearch(arr, n, target, &numComparisons);
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found.\n");
    }
    printf("Number of comparisons: %d\n", numComparisons);
    return 0;
}
