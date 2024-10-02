import java.util.Arrays;

public class Solution {
    public void setZeroes(int[][] matrix) {
        // Step 1: Handle edge case for an empty matrix
        if (matrix == null || matrix.length == 0) {
            return;
        }

        // Step 2: Get the dimensions of the matrix
        int rows = matrix.length;
        int cols = matrix[0].length;

        // Step 3: Create a deep copy of the original matrix
        int[][] copyMatrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            copyMatrix[i] = Arrays.copyOf(matrix[i], cols);
        }

        // Step 4: Traverse the original matrix to find zeros
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    // Step 5: Mark the entire row with zeros in the copied matrix
                    for (int k = 0; k < cols; k++) {
                        copyMatrix[row][k] = 0;
                    }
                    // Step 6: Mark the entire column with zeros in the copied matrix
                    for (int k = 0; k < rows; k++) {
                        copyMatrix[k][col] = 0;
                    }
                }
            }
        }

        // Step 7: Copy the updated values back to the original matrix
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                matrix[row][col] = copyMatrix[row][col];
            }
        }
    }

    // Helper function to print the matrix
    public static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            System.out.println(Arrays.toString(row));
        }
        System.out.println();
    }

    // Test cases
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        int[][] matrix1 = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
        };
        System.out.println("Input:");
        printMatrix(matrix1);

        solution.setZeroes(matrix1);
        System.out.println("Output:");
        printMatrix(matrix1);

        // Example 2
        int[][] matrix2 = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
        };
        System.out.println("Input:");
        printMatrix(matrix2);

        solution.setZeroes(matrix2);
        System.out.println("Output:");
        printMatrix(matrix2);
    }
}
