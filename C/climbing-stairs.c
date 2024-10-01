// Description: You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Example:
// Input: n = 3
// Output: 3 (There are three ways: 1 step + 1 step + 1 step, 1 step + 2 steps, 2 steps + 1 step)

#include <stdio.h>

int climbStairs(int n) {
    if(n < 0)
        return 0; // No way to climb negative steps
    if (n == 0)
        return 1; // 1 way to climb zero step which is by staying on ground
    if (n == 1)
        return 1; // 1 way to climb one step
    if (n == 2)
        return 2; // 2 ways to climb two steps

    int prev2 = 1;  
    int prev1 = 2; 
    int curr;
    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1; // Return the total ways
}

int main() {
    int n;
    //Takes input from the user
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    //Stores the number of ways
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
    // Test case 6: n = 5
    // Expected output: 8 (1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1, 1+2+2, 2+1+2, 2+2+1)