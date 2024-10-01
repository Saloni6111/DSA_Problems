def maxProfit(prices):
    max_profit = 0

    for i in range(1, len(prices)):
        # If the price has increased, add the difference to the profit
        if prices[i] > prices[i - 1]:
            max_profit += prices[i] - prices[i - 1]

    return max_profit

# Example usage:
prices = [7, 1, 5, 3, 6, 4]
print(maxProfit(prices))  # Output: 7
