#include <stdio.h>

#define MAX 100

// Function to get the maximum value in the knapsack
int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    // Build the dp array
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: no items or no capacity
            } else if (weights[i - 1] <= w) {
                // Item can be included
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ?
                           values[i - 1] + dp[i - 1][w - weights[i - 1]] : dp[i - 1][w];
            } else {
                // Item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Maximum value that can be obtained
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50; // Capacity of knapsack
    int n = sizeof(values) / sizeof(values[0]);

    printf("Maximum value in Knapsack: %d\n", knapsack(W, weights, values, n));

    return 0;
}
