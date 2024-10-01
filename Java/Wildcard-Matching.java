class Solution {
    public boolean isMatch(String s, String p) {
        
        int m = s.length();
        int n = p.length();
        Boolean dp[][] = new Boolean[n + 1][m + 1];
        dp[0][0] = true;
        for(int j = 1;j <= m;j++) dp[0][j] = false;
        for(int i = 1;i <= n;i++) {
            boolean flag = true;
            for(int ii = 1;ii <= i;ii++) {
                if(p.charAt(ii - 1) != '*') flag = false; 
            }
            dp[i][0] = flag;
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(p.charAt(i - 1) == s.charAt(j - 1) || p.charAt(i - 1) == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p.charAt(i - 1) == '*') {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
    public boolean checkStrings(int i, int j, String s1, String s2, Boolean dp[][]) {
        
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0) return false;
        if(j == 0 && i > 0) {
            for(int ii = 1;ii <= i;ii++) {
                if(s1.charAt(ii - 1) != '*') {
                    return false;
                }
            }
            return true;
        }
        if(s1.charAt(i - 1) == s2.charAt(j - 1) || s1.charAt(i - 1) == '?') {
            return dp[i][j] = checkStrings(i - 1, j - 1, s1, s2, dp);
        } 
        if(s1.charAt(i - 1) == '*') {
            return dp[i][j] = checkStrings(i - 1, j, s1, s2, dp) | checkStrings(i, j - 1, s1, s2, dp);
        }
        return dp[i][j] = false;
    }
}
