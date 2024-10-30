class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    int n; 
    void solve(vector<int>& nums,int id){
        if(id>=n){
            if(size(t)>=2)ans.push_back(t);
            return;
        }        
        if(t.empty() || nums[id]>=t.back()){
            t.push_back(nums[id]);
            solve(nums,id+1);
            t.pop_back();
        }
        if(t.empty() || nums[id]!=t.back())solve(nums,id+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=size(nums);
        solve(nums,0);
        return ans;
    }
};