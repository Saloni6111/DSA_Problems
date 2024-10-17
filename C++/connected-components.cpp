#include<iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& graph, vector<bool>& arr, int at)
{
    if (arr[at]) return;
    arr[at] = true;
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[at][i] == 1 && !arr[i]) {
            dfs(graph, arr, i);
            }
        }
}   
bool isconn(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> v(n, false);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            count += 1;
            // if (count > 1) {
            //     return false;
            // }
                dfs(graph, v, i);
        }
    }
    return count;
}
int main() {
    vector<vector<int>> g1 = {
            {0, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 1},
            {0, 0, 1, 0}
            };
    vector<vector<int>> g2 = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
        };
        
            cout << isconn(g1) << endl;
            cout << isconn(g2) << endl;
            return 0;
}
