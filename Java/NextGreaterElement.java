import java.util.Arrays;
import java.util.Stack;

public class NextGreaterElement {
    
    public static int[] nextGreaterElements(int[] nums) {
        int[] result = new int[nums.length];
        Arrays.fill(result, -1);
        Stack<Integer> stack = new Stack<>();

        // First pass to find next greater elements
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[i] > nums[stack.peek()]) {
                int index = stack.pop();
                result[index] = nums[i];
            }
            stack.push(i);
        }

        // Second pass to handle circular array
        for (int i = 0; i < nums.length; i++) {
            while (!stack.isEmpty() && nums[i] > nums[stack.peek()]) {
                int index = stack.pop();
                result[index] = nums[i];
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = {4, 5, 2, 10};
        int[] result = nextGreaterElements(nums);
        System.out.println(Arrays.toString(result)); // Output: [5, 10, 10, -1]
    }
}
