class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size()*grid.size();
        int *nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = -1;
        vector<int> res = {-1, -1};

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(nums[grid[i][j]-1] != 1)
                    nums[grid[i][j]-1] = 1;
                else 
                    nums[grid[i][j]-1] = 0;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] == 0) res[0] = (i+1);
            else if(nums[i] == -1) res[1] = (i+1);
        }
        if(res[0] == -1) res[0] = n;
        delete[] nums;
        return res;
    }
};