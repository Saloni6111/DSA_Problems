import java.util.Arrays;

/**
 * Class to find the k-th largest element in an array.
 */
public class kth {

    public static int findKthLargest(int[] nums, int k) {
        // Sort the array in ascending order
        Arrays.sort(nums);
        
        // The k-th largest element is at the index nums.length - k
        return nums[nums.length - k];
    }

    
     //Main method to test the findKthLargest function.
     
    public static void main(String[] args) {
        // Test case 1
        int[] nums1 = {3, 2, 1, 5, 6, 4};
        int k1 = 2;
        System.out.println("The " + k1 + "th largest element is: " + findKthLargest(nums1, k1)); // Output: 5

        // Test case 2
        int[] nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k2 = 4;
        System.out.println("The " + k2 + "th largest element is: " + findKthLargest(nums2, k2)); // Output: 4
    }
}
