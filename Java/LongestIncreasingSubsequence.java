import java.util.Arrays;

public class LongestIncreasingSubsequence {
    
    public static int lengthOfLIS(int[] nums) {
        if (nums.length == 0) return 0;

        // Array to store the lengths of longest increasing subsequences
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1); // Each element is an increasing subsequence of length 1

        int maxLength = 1; // To track the maximum length found

        // Iterate through the array
        for (int i = 1; i < nums.length; i++) {
            // Compare with all previous elements
            for (int j = 0; j < i; j++) {
                // Update dp[i] if nums[i] is greater than nums[j]
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            // Update the overall maximum length
            maxLength = Math.max(maxLength, dp[i]);
        }

        return maxLength; // Return the length of the longest increasing subsequence
    }

    public static void main(String[] args) {
        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
        int result = lengthOfLIS(nums);
        System.out.println(result); // Output: 4
    }
}
