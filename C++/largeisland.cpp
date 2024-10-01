#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n = grid.size();
        vector<int> area(n*n, 0);
        int index = 2;  
        int max_area = 0; 
        
        // Run DFS for each cell
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    area[index] = dfs(grid, i, j, index);
                    max_area = max(max_area, area[index]);
                    index++;
                }
            }
        }

         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> indices;
                    for(auto dir: dirs){
                        int x = i + dir[0], y = j + dir[1];
                        if(x>=0 && x<n && y>=0 && y<n){
                            indices.insert(grid[x][y]);
                        }
                    }
                    
                    int total_area = 1;
                    for(auto idx: indices) total_area += area[idx];
                    max_area = max(max_area, total_area);
                }
            }
        }
        return max_area;
    }
    private:
    vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int dfs(vector<vector<int>>& grid, int i, int j, int index){
        int n = grid.size();
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j] != 1) return 0;
        grid[i][j] = index;
        int area = 1;
        for(auto dir: dirs){
            area += dfs(grid, i + dir[0], j + dir[1], index);
        }
        return area;
    }
};



int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}
