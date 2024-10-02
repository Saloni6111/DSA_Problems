#include <stdio.h>
#include <limits.h>

// Function to find the fewest number of coins to make up the given amount
int coinChange(int coins[], int coinsSize, int amount) {
    // Array to store the minimum number of coins required to make each amount
    int dp[amount + 1];
    
    // Initialize dp array to a large value, as we want to find the minimum
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1; // Setting to amount + 1 as it's more than the possible number of coins
    }

    dp[0] = 0;  // Base case: 0 coins are needed to make amount 0

    // Iterate over all amounts from 1 to 'amount'
    for (int i = 1; i <= amount; i++) {
        // Check for each coin if it can contribute to making the current amount
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                dp[i] = (dp[i] < 1 + dp[i - coins[j]]) ? dp[i] : 1 + dp[i - coins[j]];
            }
        }
    }

    // If dp[amount] is still larger than 'amount', it means the amount cannot be formed
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};   // Coin denominations
    int amount = 11;           // Amount to make
    int coinsSize = sizeof(coins) / sizeof(coins[0]);

    // Function call to find the fewest number of coins to make up the amount
    int result = coinChange(coins, coinsSize, amount);

    if (result == -1) {
        printf("Amount cannot be made with the given coins\n");
    } else {
        printf("Fewest number of coins needed: %d\n", result);
    }

    return 0;
}
