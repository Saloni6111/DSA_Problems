import java.util.Scanner;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // Ensure that nums1 is the smaller array
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.length;
        int n = nums2.length;
        int totalLeft = (m + n + 1) / 2; // Total elements on the left side of the partition

        int left = 0;
        int right = m;

        while (left <= right) {
            int partition1 = (left + right) / 2; // Partition in nums1
            int partition2 = totalLeft - partition1; // Partition in nums2

            int maxLeft1 = (partition1 == 0) ? Integer.MIN_VALUE : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? Integer.MAX_VALUE : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? Integer.MIN_VALUE : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? Integer.MAX_VALUE : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Correct partition found
                if ((m + n) % 2 == 0) {
                    return (Math.max(maxLeft1, maxLeft2) + Math.min(minRight1, minRight2)) / 2.0;
                } else {
                    return Math.max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Move the partition to the left in nums1
                right = partition1 - 1;
            } else {
                // Move the partition to the right in nums1
                left = partition1 + 1;
            }
        }

        throw new IllegalArgumentException("Input arrays are not sorted.");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for nums1
        System.out.println("Enter the number of elements in the first array:");
        int m = scanner.nextInt();
        int[] nums1 = new int[m];
        System.out.println("Enter the elements of the first array:");
        for (int i = 0; i < m; i++) {
            nums1[i] = scanner.nextInt();
        }

        // Input for nums2
        System.out.println("Enter the number of elements in the second array:");
        int n = scanner.nextInt();
        int[] nums2 = new int[n];
        System.out.println("Enter the elements of the second array:");
        for (int i = 0; i < n; i++) {
            nums2[i] = scanner.nextInt();
        }

        // Finding the median
        Solution solution = new Solution();
        double median = solution.findMedianSortedArrays(nums1, nums2);
        System.out.println("The median is: " + median);
    }
}
