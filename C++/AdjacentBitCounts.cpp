#include <iostream>
#include <cstring>
using namespace std;
#define ll long long int

// DP table where dp[n][k][last] represents the number of ways to get a bit string of length n with exactly k adjacent '1's ending in 'last' (0 or 1)
ll dp[101][101][2];

// Function to calculate the number of valid bit strings
ll ftd(int n, int k, int last) {
    // Base case: If n is 1, we can only have a single bit string
    if (n == 1) {
        return k == 0 ? 1 : 0;
    }

    // If we have already solved this subproblem, return the result
    if (dp[n][k][last] != -1) {
        return dp[n][k][last];
    }

    // Initialize the result for the current state
    ll ans = 0;

    // If the current bit is 1, we consider two possibilities:
    // 1. The previous bit was also 1 (adds to adjacent count).
    // 2. The previous bit was 0 (no adjacent 1s added).
    if (last == 1) {
        if (k > 0) {
            ans += ftd(n - 1, k - 1, 1); // Case when previous bit was 1 (k-1)
        }
        ans += ftd(n - 1, k, 0); // Case when current bit was 0 (k remains the same)
    } else {
        ans += ftd(n - 1, k, 0); // Current bit was also 0 (k stays the same)
        ans += ftd(n - 1, k, 1); // Current bit was 1 (k stays the same)
    }

    // Store the computed result in the DP table
    return dp[n][k][last] = ans;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
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
