import java.util.HashMap;

public class SingleNumber {
    public static int findSingleNumber(int[] nums) {
        HashMap<Integer, Integer> numCounts = new HashMap<>();
        
        // Count the occurrences of each number
        for (int num : nums) {
            numCounts.put(num, numCounts.getOrDefault(num, 0) + 1);
        }
        
        // Find the number that occurs only once
        for (int num : numCounts.keySet()) {
            if (numCounts.get(num) == 1) {
                return num;
            }
        }
        
        // In case there's no single number, though it's guaranteed to be one
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = {2, 2, 1};
        System.out.println("The single number is: " + findSingleNumber(nums));
    }
}
