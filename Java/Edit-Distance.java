class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        int dp[][] = new int[n + 1][m + 1];
        
        for(int j = 0;j <= m;j++) dp[0][j] = j;
        for(int i = 1;i <= n;i++) dp[i][0] = i;
        
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                
                if(word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int insert = 1 + dp[i][j - 1];
                    int delete = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];
                    dp[i][j] = Math.min(insert, Math.min(delete, replace));
                }
            }
        }
        return dp[n][m];
    }
    public int findWays(int i, int j, String s1, String s2, int dp[][]) {
        
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1.charAt(i - 1) == s2.charAt(j - 1)) {
            return dp[i][j] = 0 + findWays(i - 1, j - 1, s1, s2, dp);
        }
        int insert = 1 + findWays(i, j - 1, s1, s2, dp);
        int delete = 1 + findWays(i - 1, j, s1, s2, dp);
        int replace = 1 + findWays(i - 1, j - 1, s1, s2, dp);
        
        return dp[i][j] = Math.min(insert, Math.min(delete, replace));
    }
}
