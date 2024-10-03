/*
Problem Statement:
                 We are given with an array and we need to find the largest contiguous subarray sum,
                 which can be done using Kadane’s algorithm efficiently.

Key Points:
           Kadane’s Algorithm works by iterating through the array once (O(n) time complexity), which makes it efficient.
          The algorithm maintains a running sum (current_sum) and updates the maximum sum (max_sum) when a larger subarray sum is found.               
*/

#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max_sum = INT_MIN, current_sum = 0;

    for (int i = 0; i < n; i++)
    {

        current_sum += arr[i];

        if (max_sum < current_sum)
            max_sum = current_sum;

        if (current_sum < 0)
            current_sum = 0;
    }

    printf("%d ", max_sum);

    return 0;
}