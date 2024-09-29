// Filename: peak-element.java

// Problem Description:
// A peak element is an element that is strictly greater than its neighbors. 
// Given an integer array, find a peak element and return its index.
// You may assume that the array contains at least one peak.
// The array may contain multiple peaks, in which case you can return the index of any peak.
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
    // Function to find the peak element index in the array
    public int findPeakElement(int[] nums) {
        int n = nums.length;

        // Edge case: If the array has only one element, return its index as the peak
        if (n == 1) return 0;

        // Binary search initialization
        int low = 0, high = n - 1;

        // Binary search to find the peak element
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If the middle element is greater than the next element, the peak lies on the left side (or is the middle element)
            if (nums[mid] > nums[mid + 1]) {
                high = mid; // Move the high pointer to mid
            } else {
                // If the middle element is smaller than the next element, the peak lies on the right side
                low = mid + 1; // Move the low pointer to mid + 1
            }
        }

        // When the loop ends, low == high and points to the peak element
        return low;
    }

    // Test Cases:
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: Peak is in the middle of the array
        int[] nums1 = {1, 2, 3, 1};
        System.out.println("Peak element index: " + solution.findPeakElement(nums1)); 
        // Expected output: 2 (nums[2] = 3 is a peak)

        // Test case 2: Peak is at the end of the array
        int[] nums2 = {1, 2, 1, 3, 5, 6, 4};
        System.out.println("Peak element index: " + solution.findPeakElement(nums2)); 
        // Expected output: 5 (nums[5] = 6 is a peak)

        // Test case 3: Single element in the array
        int[] nums3 = {1};
        System.out.println("Peak element index: " + solution.findPeakElement(nums3)); 
        // Expected output: 0 (Only one element is the peak)
    }
}
