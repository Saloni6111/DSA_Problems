class UniquePath1 {
    public static void main(String[] args) {
        // Test case 1: m = 3, n = 7
        // A 3x7 grid where the task is to calculate the number of unique paths
        int m = 3, n = 7;
        System.out.println("Number of Unique Paths are: " + uniquePaths(m, n));

        // Test case 2: m = 3, n = 2
        // A 3x2 grid where the task is to calculate the number of unique paths
        m = 3; n = 2;
        System.out.println("Number of Unique Paths are: " + uniquePaths(m, n));
    }

    // Function to calculate the number of unique paths in an m x n grid
    // Movement is allowed only to the right or down
    public static int uniquePaths(int m, int n) {
        // dp array where dp[i][j] will store the number of unique paths to reach cell (i, j)
        int[][] dp = new int[m][n];

        // Fill the first column with 1 as there's only one way to reach any cell in the first column (by moving down)
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        // Fill the first row with 1 as there's only one way to reach any cell in the first row (by moving right)
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        // Fill the rest of the dp array
        // The number of ways to reach dp[i][j] is the sum of the ways to reach the cell above it (dp[i-1][j]) and the cell to its left (dp[i][j-1])
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Return the number of unique paths to reach the bottom-right cell of the grid
        return dp[m - 1][n - 1];
    }
}
