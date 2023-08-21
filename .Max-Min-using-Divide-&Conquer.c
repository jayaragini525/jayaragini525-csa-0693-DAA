#include <stdio.h>
void findMinMax(int arr[], int left, int right, int *min, int *max) {
 if (left == right) {
 *min = *max = arr[left];
 return;
 }
 int mid = (left + right) / 2;
 int leftMin, leftMax, rightMin, rightMax;
 findMinMax(arr, left, mid, &leftMin, &leftMax);
 findMinMax(arr, mid + 1, right, &rightMin, &rightMax);
 *min = (leftMin < rightMin) ? leftMin : rightMin;
 *max = (leftMax > rightMax) ? leftMax : rightMax;
 }
int main()
{
int m,c;
printf("Enter number of elements\n");
scanf("%d", &m);
int arr[m];
printf("Enter %d integers\n", m);
for (c = 0; c < m; c++)
 scanf("%d",&arr[c]);
 int n = sizeof(arr) / sizeof(arr[0]);
 int min, max;
 findMinMax(arr, 0, n - 1, &min, &max);
  printf("Minimum element: %d\n", min);
 printf("Maximum element: %d\n", max);
 return 0;
}

