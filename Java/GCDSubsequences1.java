/**
 * Given an array, check if there exists a subsequence whose GCD is equal to 1.
 */

//Intuition: If the GCD of a subsequence is 1, then the GCD of the entire array is also 1.
import java.util.*;

public class GCDSubsequences1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = {3, 2, 4, 6, 8};
        System.out.println(checkSubsequenceGCD(arr));        
    }
    
    public static boolean checkSubsequenceGCD(int[] nums) {
        int gcd = gcdArray(nums);
        if(gcd == 1) {
            return true;
        }
        return false;
    }
    
    public static int gcdArray(int[] nums) {
        int arrayGcd = nums[0];
        for(int i=1; i<nums.length; i++) {
            arrayGcd = gcd(arrayGcd, Math.abs(nums[i]));
        }

        return arrayGcd;
    }
    
    public static int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        
        return gcd(b%a, a);
    }
}