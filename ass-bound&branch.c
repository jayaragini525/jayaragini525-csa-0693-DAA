#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define N 4
int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};
bool assigned[N];
int minCost = INT_MAX;
void calculateCost(int assignment[N]) {
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    if (totalCost < minCost) {
        minCost = totalCost;
    }
}
void branchAndBound(int row, int assignment[N]) {
    if (row == N) {
        calculateCost(assignment);
        return;
    }
    for (int col = 0; col < N; col++) {
        if (!assigned[col]) {
            assigned[col] = true;
            assignment[row] = col;
            branchAndBound(row + 1, assignment);
            assigned[col] = false;
        }
    }
}
int main() {
    int assignment[N];   
    for (int i = 0; i < N; i++) {
        assigned[i] = false;
    }    
    branchAndBound(0, assignment);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}
