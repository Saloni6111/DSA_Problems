/**
 *  Problem:- Adjacent Bit Counts
 *  Link: https://www.spoj.com/problems/GNYR09F/
*/

/**
 * Explaination:-
 *
 * State Representation: We will define a dynamic programming (DP) state dp[n][k][last]:
 * n: The current length of the bit string.
 * k: The remaining adjacent bit count to satisfy.
 * last: The last bit of the string (either 0 or 1)
 *
 * Base Cases:
 * If n == 1 and k == 0, there is only one valid bit string (either "0" or "1"), but no adjacent pairs can exist for n == 1.
 * If k > 0 when n == 1, it's impossible to satisfy, so return 0 in that case.
 *
 * Recursive-Calls:
 * If the current bit is 1, the previous bit could either be 1 (which would contribute to the adjacent bit count) or 0.
 * If the current bit is 0, the previous bit could either be 0 or 1 (but no adjacent bit count is added).
 */

#include <iostream>
#include <cstring> // For memset
using namespace std;
#define ll long long int

// DP table where dp[n][k][last] represents the number of ways to get a bit string of length n with exactly k adjacent '1's ending in 'last' (0 or 1)
ll dp[1001][101][2];

/**
 * Time complexity: (N*K*2) => (N*K)
 * Space complexity: (N*K*2) => (N*K)
 */

// Function to calculate the number of valid bit strings
ll ftd(int n, int k, int last){ // function-of-top-down
    // Base case: If n is 1, we can only have a single bit string
    if (n == 1)
    {
        // If we want 0 adjacent pairs, it's valid if k == 0
        if (k == 0){
            return 1;
        }
        return 0;
    }

    // If we have already solved this subproblem, return the result
    if (dp[n][k][last] != -1){
        return dp[n][k][last];
    }
        

    // Initialize the result for the current state
    ll ans = 0;

    // If the current bit is 1, we consider two possibilities:
    // 1. The previous bit was also 1 (adds to adjacent count).
    // 2. The previous bit was 0 (no adjacent 1s added).
    if (last == 1)
    {
        // We can only decrement k if we place a '1' next to another '1'.
        if (k > 0)
        {
            ans += ftd(n - 1, k - 1, 1); // Case when previous bit was 1 (k-1)
        }
        ans += ftd(n - 1, k, 0); // Case when current bit was 0 (k remains the same)
    }
    // If the last bit is 0, we can append a '0' or '1' to the previous part of the string.
    else
    {
        ans += ftd(n - 1, k, 0); // Current bit was also 0 (k stays the same)
        ans += ftd(n - 1, k, 1); // Current bit was 1 (k stays the same)
    }

    // Store the computed result in the DP table
    return dp[n][k][last] = ans;
}

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        int number_of_test_case, n, k;
        cin >> number_of_test_case >> n >> k;

        // Initialize DP table with -1 for unsolved subproblems
        memset(dp, -1, sizeof(dp));

        // Calculate the number of bit strings of length n with exactly k adjacent pairs
        ll result = ftd(n, k, 0) + ftd(n, k, 1);

        // Output the result in the required format
        cout << number_of_test_case << " " << result << "\n";
    }

    return 0;
}
