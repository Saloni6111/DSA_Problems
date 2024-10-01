public class MoveZeroes {
    public static void moveZeroes(int[] nums) {
        int nonZeroIndex = 0;

        // Traverse the array and move all non-zero elements to the front
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex] = nums[i];
                nonZeroIndex++;
            }
        }

        // After placing all non-zero elements, fill the rest with zeroes
        for (int i = nonZeroIndex; i < nums.length; i++) {
            nums[i] = 0;
        }
    }

    public static void main(String[] args) {
        int[] nums = {0, 1, 0, 3, 12};
        moveZeroes(nums);
        
        // Output the result
        for (int num : nums) {
            System.out.print(num + " ");
        }
    }
}
