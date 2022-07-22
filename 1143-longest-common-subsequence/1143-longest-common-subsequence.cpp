class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoization(text1, text2, dp, m-1, n-1);
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