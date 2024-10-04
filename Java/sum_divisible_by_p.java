import java.util.HashMap;

public class sum_divisible_by_p {
    public static int minSubarray(int[] arr, int divisor) {
        long totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        int remainder = (int)(totalSum % divisor);
        
        // If the remainder is 0, the total sum is already divisible by divisor
        if (remainder == 0) return 0;

        // HashMap to store moduli of prefix sums and their indices
        HashMap<Integer, Integer> prefixModMap = new HashMap<>();
        prefixModMap.put(0, -1);
        
        long cumulativeSum = 0;
        int minLength = arr.length;
        
        for (int i = 0; i < arr.length; ++i) {
            cumulativeSum += arr[i];
            int currentMod = (int)(cumulativeSum % divisor);
            
            // Calculate the modulus we're looking for to find a subarray that, when removed, makes the sum divisible by divisor
            int targetMod = (currentMod - remainder + divisor) % divisor;

            // If the target modulus exists in the map, we found a subarray
            if (prefixModMap.containsKey(targetMod)) {
                minLength = Math.min(minLength, i - prefixModMap.get(targetMod));
            }
            prefixModMap.put(currentMod, i);
        }
        return minLength == arr.length ? -1 : minLength;
    }

    public static void main(String args[]){
        int ans = minSubarray(new int[]{3, 1, 4, 2}, 6);
        System.out.println(ans);
    }
}

/*
Demo Outputs:
Input: nums = [3,1,4,2], p = 6
Output: 1

Input: nums = [6,3,5,2], p = 9
Output: 2

Input: nums = [1,2,3], p = 3
Output: 0
*/