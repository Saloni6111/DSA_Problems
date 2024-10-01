#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent, size;

public:
    DSU(int n) {
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int p_u = findpar(u);
        int p_v = findpar(v);
        if (p_u == p_v)
            return;
        if (rank[p_u] > rank[p_v]) {
            parent[p_v] = p_u;
        } else if (rank[p_v] > rank[p_u]) {
            parent[p_u] = p_v;
        } else {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }

    void unionbysize(int u, int v) {
        int p_u = findpar(u);
        int p_v = findpar(v);
        if (p_u == p_v)
            return;
        if (size[p_u] > size[p_v]) {
            size[p_u] += size[p_v];
            parent[p_v] = p_u;
        } else {
            size[p_v] += size[p_u];
            parent[p_u] = p_v;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        int dc[] = {1, 0, 0, -1};
        int dr[] = {0, -1, 1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int node = i * n + j;
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int next_i = i + dr[k];
                        int next_j = j + dc[k];
                        if (next_i < 0 || next_j < 0 || next_i >= n || next_j >= n)
                            continue;
                        if (grid[next_i][next_j] == 0)
                            continue;
                        int next_node = next_i * n + next_j;
                        if (dsu.findpar(node) == dsu.findpar(next_node))
                            continue;
                        dsu.unionbyrank(node, next_node);
                    }
                }
            }
        }

        int ans = 0, maxi = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n * n; i++) {
            mp[dsu.findpar(i)]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int count = 1;
                unordered_set<int> s;
                if (grid[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int next_i = i + dr[k];
                        int next_j = j + dc[k];
                        if (next_i < 0 || next_j < 0 || next_i >= n || next_j >= n)
                            continue;
                        if (grid[next_i][next_j] == 0)
                            continue;
                        int next_node = next_i * n + next_j;
                        if (s.find(dsu.findpar(next_node)) != s.end())
                            continue;
                        s.insert(dsu.findpar(next_node));
                        count += mp[dsu.findpar(next_node)];
                    }
                }
                ans = max(ans, count);
            }
        }

        for (auto it : mp)
            ans = max(ans, it.second);

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.largestIsland(grid);
    cout << result << endl;

    return 0;
}
