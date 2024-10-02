import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SpiralMatrix {

    // Method to print the matrix in spiral order (original from first version)
    public static List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix == null || matrix.length == 0) return result;

        int top = 0;
        int bottom = matrix.length - 1;
        int left = 0;
        int right = matrix[0].length - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top row
            for (int i = left; i <= right; i++) {
                result.add(matrix[top][i]);
            }
            top++;

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                result.add(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                // Traverse from right to left across the bottom row
                for (int i = right; i >= left; i--) {
                    result.add(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                // Traverse from bottom to top along the left column
                for (int i = bottom; i >= top; i--) {
                    result.add(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }

    // Method to create a spiral pattern of '*' and '.' (from second version)
    public static void printSpiralPattern(int n) {
        char[][] matrix = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = '.';
            }
        }

        if (n % 2 == 0) {
            int l = 0, r = n - 1, t = 0, d = n - 1;
            int i = 0, j = 0;
            while (l < n / 2) {
                while (j < r) {
                    matrix[i][j] = '*';
                    j++;
                }
                while (i < d) {
                    matrix[i][j] = '*';
                    i++;
                }
                while (j > l) {
                    matrix[i][j] = '*';
                    j--;
                }
                while (i > t) {
                    matrix[i][j] = '*';
                    i--;
                }
                l += 2;
                t += 2;
                r -= 2;
                d -= 2;
                i = t;
                j = l;
            }
        } else {
            int l = 0, r = n - 1, t = 0, d = n - 1;
            int i = 0, j = 0;
            while (l < (n + 1) / 2) {
                while (j < r) {
                    matrix[i][j] = '*';
                    j++;
                }
                while (i < d) {
                    matrix[i][j] = '*';
                    i++;
                }
                while (j > l) {
                    matrix[i][j] = '*';
                    j--;
                }
                t += 2;
                while (i > t) {
                    matrix[i][j] = '*';
                    i--;
                }
                l += 2;
                r -= 2;
                d -= 2;
            }
            matrix[i][j] = '*';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Example for spiralOrder function (first version)
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        List<Integer> result = spiralOrder(matrix);
        System.out.println("Spiral order of the matrix: " + result);

        // Example for printSpiralPattern function (second version)
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of matrix for spiral pattern:");
        int n = sc.nextInt();
        printSpiralPattern(n);
        sc.close();
    }
}
