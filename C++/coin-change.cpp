class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // cin.tie(0);
        cout.tie(0);
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;

        for(auto i:coins){
            for(int j=i;j<=amount;j++){
                dp[j]=min(dp[j],dp[j-i]+1);
            }
        }

        if(dp[amount]>amount)return -1;
        return dp[amount];
    }
};