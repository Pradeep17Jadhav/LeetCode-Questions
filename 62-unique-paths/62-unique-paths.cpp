class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recursive(dp, m-1, n-1);
    }
    
    int recursive(vector<vector<int>> &dp, int row, int col) {
        if(row < 0) return 0;
        if(col < 0) return 0;
        if(row == 0 && col == 0)
            return 1;
        if(dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = recursive(dp, row-1, col) + recursive(dp, row, col-1);
    }
    
};