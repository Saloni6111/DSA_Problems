public class SingleNumber {
    public static int findSingleNumber(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // XOR each number with result
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {2, 2, 1};
        System.out.println("The single number is: " + findSingleNumber(nums));
    }
}
