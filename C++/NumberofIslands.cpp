#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] == 1 || grid[i][j] == '0') {
            return;
        }
        visited[i][j] = 1;

        dfs(grid, i + 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j - 1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    cnt++;
                    dfs(grid, i, j, visited);
                }
            }
        }

        return cnt;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution solution;
    cout << solution.numIslands(grid) << endl;

    return 0;
}
