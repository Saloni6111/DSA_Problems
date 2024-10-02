/**
 * Problem Statement:
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. You want to determine the fewest number of coins that you need to make up that amount. If that amount cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.

    Write a function coinChange that returns the fewest number of coins needed to make up the given amount.

    Example 1:
    Input: coins = [1, 2, 5], amount = 11
    Output: 3
    Explanation: The minimum number of coins is 3 (11 = 5 + 5 + 1).

    Constraints:
    1 <= coins.length <= 12
    1 <= coins[i] <= 2^31 - 1
    0 <= amount <= 10^4
 */

/**
 * Approach:
 * Recursive Function:
 * The helper function recursively calculates the minimum number of coins required to make a given amount using the available coins. It starts from the current coin index (idx) and tries two things:
 * Skip the current coin and proceed to the next one => (helper(coins, idx + 1, amount, dp))
 * Use the current coin (if its value is less than or equal to the current amount) and reduce the amount accordingly, continuing with the same coin => (if coins[idx] <= amount, call helper(coins, idx, amount - coins[idx], dp)).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Time Complexity: O(n * amount),
 * Space Compleity: O(n * amount)
 */
int helper(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp)
{
    // Base cases
    if (amount == 0)
    {
        return 0; // No coins needed to make the amount 0
    }
    if (idx == coins.size())
    {
        return 1e8; // No more coins left, return a large value
    }

    // If already computed, return the memoized result
    if (dp[idx][amount] != -1)
    {
        return dp[idx][amount];
    }

    // Case 1: Skip the current coin and move to the next coin
    int minCoins = helper(coins, idx + 1, amount, dp);

    // Case 2: Use the current coin if it's less than or equal to the remaining amount
    if (coins[idx] <= amount)
    {
        minCoins = min(minCoins, 1 + helper(coins, idx, amount - coins[idx], dp));
    }

    // Store the computed result in dp and return it
    return dp[idx][amount] = minCoins;
}

int coinChangeTopDown(vector<int> &coins, int amount)
{
    int n = coins.size(); // Number of coins
    // Initialize a 2D dp array with -1 (uncomputed states)
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    // Start from the first coin and the target amount
    int ans = helper(coins, 0, amount, dp); // Top-Down code

    // If the answer is larger than possible (no solution), return -1
    return ans >= 1e8 ? -1 : ans;
}
    

int main()
{
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Fewest coins needed: " << coinChangeTopDown(coins1, amount1) << endl; // Output: 3

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Fewest coins needed: " << coinChangeTopDown(coins2, amount2) << endl; // Output: -1

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Fewest coins needed: " << coinChangeTopDown(coins3, amount3) << endl; // Output: 0

    return 0;
}
