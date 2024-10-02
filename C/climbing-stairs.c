#include <stdio.h>

// Function to calculate the number of distinct ways to climb to the top
int climbStairs(int n) {
    // Special cases for n = 0, 1, and 2
    if (n == 0)
        return 1; // 1 way to stay at the ground
    if (n == 1)
        return 1; // 1 way to climb one step
    if (n == 2)
        return 2; // 2 ways: (1+1), (2)

    // Variables to store previous two values (base cases)
    int prev2 = 1;  // Number of ways to climb to the (n-2)th step
    int prev1 = 2;  // Number of ways to climb to the (n-1)th step
    int curr;       // To store the number of ways to climb to the nth step

    // Iteratively calculate the number of ways for each step from 3 to n
    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2; // Current step is the sum of the previous two
        prev2 = prev1;        // Update prev2 to be the (n-1)th step
        prev1 = curr;         // Update prev1 to be the nth step
    }

    return prev1; // Return the total number of ways to reach the nth step
}

int main() {
    int n;
    // Takes input from the user
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    
    // Stores the number of ways to climb the given number of steps
    int ways = climbStairs(n);
    printf("%d\n", ways);
    
    return 0;
}

// Test Cases
    // Test case 1: n = 0
    // Expected output: 1 (1 way to stay at the ground)
    
    // Test case 2: n = 1
    // Expected output: 1 (1 way to climb one step)
    
    // Test case 3: n = 2
    // Expected output: 2 (1 step + 1 step, 2 steps)
    
    // Test case 4: n = 3
    // Expected output: 3 (1+1+1, 1+2, 2+1)
    
    // Test case 5: n = 5
    // Expected output: 8 (1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1, 1+2+2, 2+1+2, 2+2+1)
