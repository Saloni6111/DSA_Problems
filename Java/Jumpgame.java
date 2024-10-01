class JumpGame {
    public boolean canJump(int[] nums) {
        int index = 0;
        for(int i = 0; i < nums.length; i++){
            if(i > index){
                return false;
            }
            index = Math.max(index, i + nums[i]);
        }
        return index >= nums.length - 1;
    }

    public static void main(String[] args) {
        JumpGame solution = new JumpGame();
        
        // Test cases
        int[][] testCases = {
            {2, 3, 1, 1, 4},  // Expected output: true
            {3, 2, 1, 0, 4},  // Expected output: false
            {0},              // Expected output: true
            {1, 0},           // Expected output: true
            {2, 0, 0}         // Expected output: true
        };

        for (int[] testCase : testCases) {
            boolean result = solution.canJump(testCase);
            System.out.println("Input: " + java.util.Arrays.toString(testCase) + " -> Output: " + result);
        }
    }
}
