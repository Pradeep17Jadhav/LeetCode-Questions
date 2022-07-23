class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(text1, text2, dp, m-1, n-1);
        
        return tabulation(text1, text2, m, n);
    }
    
    
    int tabulation(string text1, string text2, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        for(int i1 = 0; i1 <= m; i1++)
            dp[i1][0] = 0;
        
        for(int i2 = 0; i2 <= n; i2++)
            dp[0][i2] = 0;

        for(int i1 = 1; i1 <= m; i1++) {
            for(int i2 = 1; i2 <= n; i2++) {
                if(text1[i1-1] == text2[i2-1])
                    dp[i1][i2] = 1 + dp[i1-1][i2-1];
                else
                    dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
            }
        }
        
        return dp[m][n];
    }
    
    int memoization(string &a, string &b, vector<vector<int>> &dp, int i1, int i2) {
        if(i1 < 0 || i2 < 0)
            return 0;
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        
        if(a[i1] == b[i2])
            return dp[i1][i2] = 1 + memoization(a, b, dp, i1-1, i2-1);
        
        return dp[i1][i2] = max(
            memoization(a, b, dp, i1-1, i2),
            memoization(a, b, dp, i1, i2-1)
        );
    }
};