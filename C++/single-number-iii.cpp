class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long allxor;
        for(int x:nums){
            allxor^=x;
        }

        int mask =  allxor &(-allxor);
        int a=0;
        int b=0;
        for(int x:nums){
            if(mask&x){
                a^=x;
            }
            else{
                b^=x;
            }
        }
        return {a,b};
    }
};