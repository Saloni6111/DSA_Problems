import java.util.HashMap;

public class MajorityElement {
     public static int majorityElement(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> countMap = new HashMap<>();

        // Count occurrences of each element
        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
            // Check if the current element is the majority
            if (countMap.get(num) > n / 2) {
                return num; // Return the majority element
            }
        }

        return -1; // If no majority element is found 
    }

    public static void main(String[] args) {
        int[] nums = {3, 2, 3};
        int result = majorityElement(nums);
        System.out.println(result); // Output: 3
    }
}
