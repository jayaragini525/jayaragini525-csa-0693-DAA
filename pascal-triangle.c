#include <stdio.h>
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main() {
    int rows,i,space=0,j;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);
    for (i = 0; i < rows; i++) {
        for ( space = 0; space < rows - i; space++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            int coefficient = factorial(i) / (factorial(j) * factorial(i - j));
            printf("%d ", coefficient);
        }
        printf("\n");
    }
}

