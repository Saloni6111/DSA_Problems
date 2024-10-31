#include <stdio.h>

// Function to find the length of the longest increasing subsequence
int lengthOfLIS(int arr[], int n) {
    int dp[n];  // dp[i] will store the length of LIS ending at arr[i]
    int maxLength = 1; // Minimum LIS length is 1 (each element itself)

    // Initialize each dp[i] to 1 (each element is an increasing subsequence)
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    // Compute LIS for each element
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) { // Check if arr[i] can extend LIS ending at arr[j]
                dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : (dp[j] + 1);
            }
        }
        maxLength = (maxLength > dp[i]) ? maxLength : dp[i];
    }

    return maxLength;
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of Longest Increasing Subsequence: %d\n", lengthOfLIS(arr, n));

    return 0;
}
