#include <stdio.h>
#include <limits.h>
double sumProbabilities(double probabilities[], int start, int end)
{
 double sum = 0.0;
 int i;
 for (i = start; i <= end; i++)
 sum += probabilities[i];
 return sum;
}
double optimalBSTCost(double keys[], double probabilities[], int n)
{
 double dp[n][n];
 int i,L,r;
 for (i = 0; i < n; i++)
 dp[i][i] = probabilities[i];
 for (L = 2; L <= n; L++)
{
 for ( i = 0; i <= n - L + 1; i++) 
{
 int j = i + L - 1;
 dp[i][j] = INT_MAX;
 for (r = i; r <= j; r++)
 {
 	double cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0) + 
sumProbabilities(probabilities, i, j);
 if (cost < dp[i][j])
 dp[i][j] = cost;
 }
}
}
return dp[0][n - 1];
}
int main() 
{
 int n,i;
 printf("Enter the number of keys: ");
 scanf("%d", &n);
 double keys[n], probabilities[n];
 printf("Enter the keys and their probabilities:\n");
 for (i = 0; i < n; i++) 
{
 scanf("%lf %lf", &keys[i], &probabilities[i]);
 }
 double cost = optimalBSTCost(keys, probabilities, n);
 printf("Optimal BST cost: %lf\n", cost);
 return 0;
}
