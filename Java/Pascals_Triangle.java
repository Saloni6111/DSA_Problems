import java.util.*;
public class Pascals_Triangle {
	// Function to calculate nCr (binomial coefficient)
	public static int nCr(int n, int r) {
        long res = 1;
        // calculating nCr:
        for (int i = 0; i < r; i++) {
            res = res * (n - i); // Multiply by (n-i) (numerator part)
            res = res / (i + 1); // Divide by (i+1) (denominator part)
        }
        return (int) res;
    }
	
	public static List<List<Integer>> pascalTriangle(int n) {
        List<List<Integer>> ans = new ArrayList<>(); // 2D vector to store the entire Pascal's Triangle

        // Store the entire Pascal's triangle:
        for (int row = 1; row <= n; row++) {
            List<Integer> tempLst = new ArrayList<>(); 
            for (int col = 1; col <= row; col++) {
                tempLst.add(nCr(row - 1, col - 1)); // Push the binomial coefficient C(row-1, col-1)
            }
            ans.add(tempLst);
        }
        return ans;
    }
	
	public static void main(String[] args) {
        int n = 5;
        List<List<Integer>> ans = pascalTriangle(n);
        for (List<Integer> it : ans) {
            for (int ele : it) {
                System.out.print(ele + " ");
            }
            System.out.println();
        }
    }

}
