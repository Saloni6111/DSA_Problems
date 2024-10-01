def coinChange(coins, amount):
    # Initialize a list to store the minimum number of coins for each amount
    dp = [float('inf')] * (amount + 1)
    
    # Base case: zero amount requires zero coins
    dp[0] = 0

    # Iterate over each coin
    for coin in coins:
        # Update dp array for amounts from coin to the target amount
        for x in range(coin, amount + 1):
            dp[x] = min(dp[x], dp[x - coin] + 1)

    # If dp[amount] is still infinity, it means it's not possible to form that amount
    return dp[amount] if dp[amount] != float('inf') else -1

# Example usage
if __name__ == "__main__":
    print(coinChange([1, 2, 5], 11))  # Output: 3
    print(coinChange([2], 3))         # Output: -1
    print(coinChange([1], 0))         # Output: 0
    print(coinChange([1], 2))         # Output: 2
