#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[200][200]{};
    int maxPath, n, m;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxPath = 0, n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                maxPath = max(maxPath, solve(matrix, i, j, -1));
            }
        }
        return maxPath;
    }

    int solve(vector<vector<int>>& mat, int i, int j, int prev) {
        if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max({ solve(mat, i + 1, j, mat[i][j]),
                                    solve(mat, i - 1, j, mat[i][j]),
                                    solve(mat, i, j + 1, mat[i][j]),
                                    solve(mat, i, j - 1, mat[i][j]) });
    }
};

int main() {
    int rows, cols;
    cin >> rows;
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    Solution solution;
    int result = solution.longestIncreasingPath(matrix);
    cout << result << endl;

    return 0;
}
