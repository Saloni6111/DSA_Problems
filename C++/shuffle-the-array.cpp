class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
       for(int i=0;i<n;i++){
        nums[i]=nums[i]<<10;
        nums[i]=nums[i]|nums[i+n];
       }
       int ptr=2*n-1;
 
      for(int i=n-1;i>=0;i--){
         int y =nums[i]&((1<<10)-1);
         int x =nums[i]>>10;
         nums[ptr]=y;
         nums[ptr-1]=x;
         ptr-=2;
       }
       return nums;
    }
};
auto init=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();